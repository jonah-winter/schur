#ifndef SCHUR_EVAL_HPP_
#define SCHUR_EVAL_HPP_

#include "schur/matrix/Matrix_MainClass.hpp"
#include "schur/core/Concepts.hpp"
#include "schur/matrix/mult/MatMulNxN.hpp"

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
void naive_mm(internal::Mult<L, R>& 

template<typename L, typename R>
auto eval(const internal::Mult<L, R>& ml)
  -> Matrix<
            internal::get_rows<internal::Mult<L, R>,
            internal::get_cols<internal::Mult<L, R>,
            typename internal::Mult<L, R>::val_t,
            internal::Mult<L, R>::layout()
           >{
  using Scalar = typename internal::Mult<L, R>::val_t;
  constexpr Layout  L = internal::Mult<L, R>::layout();
  constexpr msize_t M = internal::get_rows<internal::Mult<L, R>>;
  constexpr msize_t K = internal::get_cols<internal::Mult<L, R>>;
  constexpr msize_t N = internal::get_cols<L>;

  Matrix<M, N, Scalar, L> out{ml.rows(), ml.cols()};
  if constexpr(std::is_same_v<Scalar, float>) {
    Scalar* left = (Scalar*)(malloc(ml.left.size() * sizeof(Scalar)));
    Scalar* right = (Scalar*)(malloc(ml.right.size() * sizeof(Scalar)));
    ml.left_data(left);
    ml.right_data(right);
#if defined(__APPLE__) && defined(aarch64)
    internal::mmNNxCM(left, right, out.data(), ml.rows(), ml.cols(), K);
#else
    naive_mm(ml, out);
#endif // choose mult
  } else {
    if constexpr(L == Layout::ColMajor) {
      for(int j{0}; j < ml.cols(); j++) {
        for(int k{0}; k < ml.shared(); k++) {
          Scalar temp = ml.left[k, j];
          for(int i{0}; i < ml.rows(); i++) { out[i, j] += temp*ml.right[i, k]; }
        }
      }
    } else {
      
    }
  }
  return out;
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
