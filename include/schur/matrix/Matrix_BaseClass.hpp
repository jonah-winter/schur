#ifndef SCHUR_MATRIX_BASE_CLASS_HPP_
#define SCHUR_MATRIX_BASE_CLASS_HPP_

#include "schur/core/Types.hpp"

namespace schur {
namespace internal {
struct MatrixExprTag {};
template <typename Derived, typename Scalar, msize_t Rows, msize_t Cols, Layout L = Layout::ColMajor>
struct MatrixBase
{
  using matrix_expr_tag = MatrixExprTag;
  //using this_t = std::remove_cvref_t<decltype(*this)>;

  // [[nodiscard]] Derived& derived();
  // [[nodiscard]] const Derived& derived() const;
  [[nodiscard]] size_t rows(this auto&& self);
  [[nodiscard]] size_t cols(this auto&& self);
  [[nodiscard]] size_t size(this auto&& self);
  [[nodiscard]] Scalar* data(this auto&& self);
  [[nodiscard]] constexpr Layout layout() { return L; }

  void init(this auto&& self);
  void init(this auto&& self, msize_t start, msize_t end);
  void init(this auto&& self, Scalar val);
  void init(this auto&& self, msize_t start, msize_t end, Scalar val);
protected:
  MatrixBase() = default;
}; // end of matrix struct
} // namespace internal
} // namespace schur
#endif //SCHUR_MATRIX_BASE_CLASS_HPP_
