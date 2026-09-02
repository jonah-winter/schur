#ifndef SCHUR_MATRIX_BLOCK_HPP
#define SCHUR_MATRIX_BLOCK_HPP

#include <schur/matrix/Matrix_BaseClass.hpp>
#include <schur/matrix/Matrix_MainClass.hpp>

namespace schur {
template <typename T, internal::Layout L>
struct BlockView : internal::MatrixBase<BlockView<T, L>, T, -1, -1, L>
{
  using Base = internal::MatrixBase<BlockView, T, -1, -1, L>;
  using matrix_expr_tag = Base::matrix_expr_tag;
private:
  size_t rows_;
  size_t cols_;
  T* data_;
  size_t row_stride_;
  size_t col_stride_;

  auto& operator[](this auto&& self, index_t i);
public:
  template <index_t Rows, index_t Cols>
  BlockView(Matrix<T, Rows, Cols, L>* m, size_t start_rows, size_t start_cols, size_t rows, size_t cols);
  auto& operator[](this auto&& self, index_t r, index_t c);
  auto& at(this auto&& self, index_t r, index_t c);
  size_t rows() const { return rows_; }
  size_t cols() const { return cols_; }
  size_t size() const { return rows_ * cols_; }
  T* data() { return data_; }
};

template <typename T, internal::Layout L>
auto& BlockView<T, L>::operator[](this auto&& self, index_t r, index_t c) {
  return self.data_[r * self.row_stride_ + c * self.col_stride_];
}

template <typename T, internal::Layout L>
auto& BlockView<T, L>::at(this auto&& self, index_t r, index_t c)
{
  if (r > self.dims.rows() || r < 0) { throw std::out_of_range("row index is out of bounds"); }
  if (c > self.dims.cols() || c < 0) { throw std::out_of_range("col index is out of bounds"); }

  if constexpr (L == internal::Layout::ColMajor) {
    return self.storage.at(c * self.rows() + r);
  } else {
    return self.storage.at(r * self.cols() + c);
  }
}

template <typename T, internal::Layout L>
auto& BlockView<T, L>::operator[](this auto&& self, index_t i) {
  return self.data_[i];
}

template <typename T, internal::Layout L>
template <index_t Rows, index_t Cols>
BlockView<T, L>::BlockView(Matrix<T, Rows, Cols, L>* m, size_t start_rows, size_t start_cols, size_t rows, size_t cols)
  : rows_(rows), cols_(cols), data_()
{
  if constexpr (L == internal::Layout::RowMajor) {
    row_stride_ = m->cols();
    col_stride_ = 1;
  } else {
    row_stride_ = 1;
    col_stride_ = m->rows();
  }

  if (start_rows + rows > Rows) throw std::out_of_range("rows are out of bounds");
  if (start_cols + cols > Cols) throw std::out_of_range("Cols are out of bounds");
}
} // namespace schur
#endif //SCHUR_MATRIX_BLOCK_HPP
