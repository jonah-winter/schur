#ifndef SCHUR_EVAL_HPP_
#define SCHUR_EVAL_HPP_

#include "schur/matrix/Matrix_MainClass.hpp"
#include "schur/core/Concepts.hpp"
#if defined(__APPLE__)
#  if defined(__ARM_NEON)
#    include "schur/matrix/mult/apple/MM_NxN_NEON.hpp"
#  endif // arm neon
#endif // apple

namespace schur {
namespace internal {
template<typename M>
struct contains_mult {
  static constexpr bool value = false;
};
template<typename L, typename R>
struct contains_mult<Mult<L, R>> {
  static constexpr bool value = true;
};
template<NonMatrixMatrixExpr M>
struct contains_mult<M> {
  static constexpr bool value = contains_mult<typename M::L>::value || contains_mult<typename M::R>::value;
};
template<typename D>
struct contains_mult<Transposed<D>> {
  static constexpr bool value = contains_mult<D>::value;
};
}

template<typename L, typename R>
void naive_mm(
    const internal::Mult<L, R>& ml,
    Matrix<
        internal::get_rows<internal::Mult<L, R>>,
        internal::get_cols<internal::Mult<L, R>>,
        typename internal::Mult<L, R>::val_t,
        internal::Mult<L, R>::layout()
          >* out)
{
  using Scalar = std::remove_cvref_t<decltype(ml)>::val_t;
  constexpr Layout layout = internal::Mult<L, R>::layout();
  if constexpr(layout == Layout::ColMajor) {
    for(int j{0}; j < ml.cols(); j++) {
      for(int k{0}; k < ml.shared(); k++) {
        Scalar temp = ml.left[k, j];
        for(int i{0}; i < ml.rows(); i++) { (*out)[i, j] += temp*ml.right[i, k]; }
      }
    }
  } else {
    for(int i{0}; i < ml.rows(); i++) {
      for(int k{0}; k < ml.shared(); k++) {
        Scalar temp = ml.left[i, k];
        for(int j{0}; j < ml.cols(); j++) {
          (*out)[i, j] += temp*ml.right[k, j];
        }
      }
    }
  }
}

template<typename L, typename R>
auto eval(const internal::Mult<L, R>& ml)
  -> Matrix<
            internal::get_rows<internal::Mult<L, R>>,
            internal::get_cols<internal::Mult<L, R>>,
            typename internal::Mult<L, R>::val_t,
            internal::Mult<L, R>::layout()
           >{
  using Scalar = typename internal::Mult<L, R>::val_t;
  constexpr Layout layout = internal::Mult<L, R>::layout();
  constexpr msize_t M = internal::get_rows<internal::Mult<L, R>>;
  constexpr msize_t K = internal::get_cols<internal::Mult<L, R>>;
  constexpr msize_t N = internal::get_cols<L>;

  Matrix<M, N, Scalar, layout> temp{ml.rows(), ml.cols()};
  Matrix<M, N, Scalar, layout>* out{&temp};
  if constexpr(std::is_same_v<Scalar, float>) {
    Scalar* left = (Scalar*)(malloc(ml.left.size() * sizeof(Scalar)));
    Scalar* right = (Scalar*)(malloc(ml.right.size() * sizeof(Scalar)));
    ml.left_data(left);
    ml.right_data(right);
#if defined(__APPLE__) && defined(__ARM_NEON)
    internal::mmNNxCM_neon(left, right, out->data(), ml.rows(), ml.cols(), K);
#else
    naive_mm(ml, out);
#endif // choose mult
  } else {
    naive_mm(ml, out);
  }
  return *out;
}

template<internal::NonMatrixMatrixExpr M>
auto eval(const M& m)
{
  Matrix<internal::get_rows<M>, internal::get_cols<M>, typename M::val_t, M::layout()> t{m.rows(), m.cols()};
  for(msize_t i{0}; i < m.rows(); i++) { 
    for(msize_t j{0}; j < m.cols(); j++) { t[i, j] = m[i, j]; } 
  }
  return t;
}

template<msize_t Rows, msize_t Cols, typename Scalar, Layout L>
auto eval(const Matrix<Rows, Cols, Scalar, L>& m) { return m; }
} // namespace schur
#endif // SCHUR_EVAL_HPP_
