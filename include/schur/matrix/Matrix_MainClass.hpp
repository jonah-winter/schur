#ifndef SCHUR_MATRIX_MAIN_CLASS_HPP
#define SCHUR_MATRIX_MAIN_CLASS_HPP

#include <vector>

#include <schur/matrix/Matrix_BaseClass.hpp>

namespace schur {
// forward declarations
template <typename T, internal::Layout L>
struct BlockView;

template <typename T, index_t Rows, index_t Cols,
          internal::Layout L = internal::Layout::ColMajor>
struct Matrix : public internal::MatrixBase<Matrix<T, Rows, Cols, L>, T, Rows, Cols, L>
{
  using Base = internal::MatrixBase<Matrix, T, Rows, Cols, L>;

private:
  internal::Dimensions<Rows, Cols> dims;
  internal::Storage<T> storage;
  static constexpr bool has_fixed_rows = decltype(dims)::has_fixed_rows;
  static constexpr bool has_fixed_cols = decltype(dims)::has_fixed_cols;

public:
  Matrix()
    : dims(Rows, Cols), storage(Rows * Cols) {}
  Matrix(size_t r, size_t c)
    : dims(r, c), storage(r * c) {}
  explicit Matrix(size_t dim)
    : dims(dim), storage(internal::Dimensions<Rows, Cols>::size(dim)) {}
  Matrix(std::initializer_list<std::initializer_list<T>> list);
  Matrix(std::vector<std::vector<T>> list);
  template <size_t arrRows, size_t arrCols>
  Matrix(std::array<std::array<T, arrCols>, arrRows> arr);
  Matrix(BlockView<T, L> block);

  [[nodiscard]] T* begin()    { return storage.data(); }
  [[nodiscard]] T* end()      { return storage.data() + size(); }
  [[nodiscard]] size_t rows() { return dims.rows(); }
  [[nodiscard]] size_t cols() { return dims.cols(); }
  [[nodiscard]] size_t size() { return dims.rows() * dims.cols(); }
  [[nodiscard]] auto& at(this auto&& self, index_t r, index_t c);
  [[nodiscard]] auto& operator[](this auto&& self, index_t r, index_t c);
  BlockView<T, L> block(size_t start_rows, size_t start_cols, size_t rows, size_t cols);
private:
  auto& operator[](this auto&& self, index_t i);
};
}

#endif //SCHUR_MATRIX_MAIN_CLASS_HPP