#ifndef SCHUR_MATRIX_BASE_CLASS_HPP
#define SCHUR_MATRIX_BASE_CLASS_HPP

namespace schur {
namespace internal {
struct MatrixExprTag {};

template <typename Derived, typename T, index_t Rows, index_t Cols, Layout = Layout::ColMajor>
struct MatrixBase
{
  using matrix_expr_tag = MatrixExprTag;
  //using this_t = std::remove_cvref_t<decltype(*this)>;

  // [[nodiscard]] Derived& derived();
  // [[nodiscard]] const Derived& derived() const;
  [[nodiscard]] size_t rows(this auto&& self);
  [[nodiscard]] size_t cols(this auto&& self);
  [[nodiscard]] size_t size(this auto&& self);
  [[nodiscard]] T* data(this auto&& self);

  void init(this auto&& self);
  void init(this auto&& self, index_t start, index_t end);
  void init(this auto&& self, T val);
  void init(this auto&& self, index_t start, index_t end, T val);
protected:
  MatrixBase() = default;
}; // end of matrix struct
} // namespace internal
} // namespace schur
#endif //SCHUR_MATRIX_BASE_CLASS_HPP
