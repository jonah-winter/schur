#ifndef SCHUR_MATRIX_BASE_CLASS_HPP_
#define SCHUR_MATRIX_BASE_CLASS_HPP_

#include "schur/core/Types.hpp"

namespace schur {
namespace internal {
template<MatrixExpr D>
struct Transposed;

template<typename Derived, msize_t Rows, msize_t Cols, typename Scalar, Layout L>
struct MatrixBase {
  using matrix_expr_tag = MatrixExprTag;
  using main_matrix_tag = NonMainMatrixTag;

  Derived& derived() {
    return *static_cast<Derived*>(this);
  }
  const Derived& derived() const {
    return *static_cast<const Derived*>(this);
  }
  //using this_t = std::remove_cvref_t<decltype(*this)>;

  // [[nodiscard]] Derived& derived();
  // [[nodiscard]] const Derived& derived() const;
  [[nodiscard]] size_t rows(this auto&& self);

  [[nodiscard]] size_t cols(this auto&& self);

  [[nodiscard]] size_t size(this auto&& self);

  [[nodiscard]] Scalar* data(this auto&& self);

  [[nodiscard]] static consteval Layout layout() { return L; }

  void init(this auto&& self);

  void init(this auto&& self, msize_t start, msize_t end);

  void init(this auto&& self, Scalar val);

  void init(this auto&& self, msize_t start, msize_t end, Scalar val);

  [[nodiscard]] auto transpose(this auto&& self)
    requires(MatrixExpr<operand_t<Derived> >);
  
  void eval_to(Scalar* out) const {
    for(int i{0}; i < derived().rows(); i++) { 
      for(int j{0}; j < derived().cols(); j++) {
        out[j*derived().rows()+i] = derived()[i, j];
      }
    }
  }

  Transpose<Derived> transpose() const {
    return 
  }
protected:
  MatrixBase() = default;
}; // end of matrix struct
} // namespace internal
} // namespace schur
#endif //SCHUR_MATRIX_BASE_CLASS_HPP_
