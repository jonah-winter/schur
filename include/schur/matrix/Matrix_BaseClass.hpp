#ifndef SCHUR_MATRIX_BASE_CLASS_HPP
#define SCHUR_MATRIX_BASE_CLASS_HPP

#include <schur/dimensions/Dimensions_Include.hpp>
#include <schur/storage/Storage_Include.hpp>
#include <schur/Generic_GlobalDeclarations.hpp>

namespace schur {
namespace internal {
enum class Layout
{
  ColMajor = 0,
  RowMajor = 1
};

struct MatrixExprTag {};

template <typename Derived, typename T, index_t Rows, index_t Cols, Layout = Layout::ColMajor>
struct MatrixBase
{
  using matrix_expr_tag = MatrixExprTag;

  // [[nodiscard]] Derived& derived();
  // [[nodiscard]] const Derived& derived() const;
  [[nodiscard]] size_t rows(this auto&& self);
  [[nodiscard]] size_t cols(this auto&& self);
  [[nodiscard]] size_t size(this auto&& self);
  [[nodiscard]] constexpr auto& operator[](this auto&& self, index_t r, index_t c);
  [[nodiscard]] auto& at(this auto&& self, index_t r, index_t c);
protected:
  MatrixBase() = default;
private:
  [[nodiscard]] constexpr T& operator[](this auto&& self, index_t i);
}; // end of matrix struct
} // namespace internal
} // namespace schur
#endif //SCHUR_MATRIX_BASE_CLASS_HPP
