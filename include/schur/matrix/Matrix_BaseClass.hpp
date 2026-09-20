#ifndef SCHUR_MATRIX_BASE_CLASS_HPP_
#define SCHUR_MATRIX_BASE_CLASS_HPP_

#include "schur/core/Types.hpp"

namespace schur {
namespace internal {
struct MatrixExprTag {};
template <typename _Derived, typename _Scalar, index_t _Rows, index_t _Cols, Layout _Layout = Layout::ColMajor>
struct MatrixBase
{
  using matrix_expr_tag = MatrixExprTag;
  using Derived = _Derived;
  //using this_t = std::remove_cvref_t<decltype(*this)>;

  // [[nodiscard]] Derived& derived();
  // [[nodiscard]] const Derived& derived() const;
  [[nodiscard]] size_t rows(this auto&& self);
  [[nodiscard]] size_t cols(this auto&& self);
  [[nodiscard]] size_t size(this auto&& self);
  [[nodiscard]] _Scalar* data(this auto&& self);
  [[nodiscard]] constexpr Layout layout() { return _Layout; }

  void init(this auto&& self);
  void init(this auto&& self, index_t start, index_t end);
  void init(this auto&& self, _Scalar val);
  void init(this auto&& self, index_t start, index_t end, _Scalar val);
protected:
  MatrixBase() = default;
}; // end of matrix struct
} // namespace internal
} // namespace schur
#endif //SCHUR_MATRIX_BASE_CLASS_HPP_
