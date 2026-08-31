#ifndef SCHUR_MATRIX_BASE_CLASS_HPP
#define SCHUR_MATRIX_BASE_CLASS_HPP

#include <vector>

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

template <typename T, index_t Rows, index_t Cols, Layout = Layout::ColMajor>
struct MatrixBase
{
  using matrix_expr_tag = MatrixExprTag;

  Dimensions<Rows, Cols> dims;
  static constexpr bool has_fixed_rows = decltype(dims)::has_fixed_rows;
  static constexpr bool has_fixed_cols = decltype(dims)::has_fixed_cols;
  Storage<T> storage;

  MatrixBase()
    : dims(Rows, Cols), storage(Rows * Cols) {}
  MatrixBase(size_t r, size_t c)
    : dims(r, c), storage(r * c) {}
  explicit MatrixBase(size_t dim)
    : dims(dim), storage(Dimensions<Rows, Cols>::size(dim)) {}
  MatrixBase(std::initializer_list<std::initializer_list<T>> list);
  MatrixBase(std::vector<std::vector<T>> list);
  template<size_t arrRows, size_t arrCols>
  MatrixBase(std::array<std::array<T, arrCols>, arrRows> arr);

  // template<size_t arrRows, size_t arrCols>
  // MatrixBase(T list[arrRows][arrCols]);

  [[nodiscard]] auto rows(this auto&& self);
  [[nodiscard]] auto cols(this auto&& self);

  [[nodiscard]] auto& operator[](this auto&& self, size_t r, size_t c);

  [[nodiscard]] size_t size() const;
private:
  [[nodiscard]] auto& operator[](this auto&& self, size_t i);
  [[nodiscard]] auto& row_ref(this auto&& self);
  [[nodiscard]] auto& col_ref(this auto&& self);
}; // end of matrix struct
} // namespace internal
} // namespace schur
#endif //SCHUR_MATRIX_BASE_CLASS_HPP
