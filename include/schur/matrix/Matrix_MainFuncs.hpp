#ifndef SCHUR_MATRIX_MAIN_FUNCS_HPP_
#define SCHUR_MATRIX_MAIN_FUNCS_HPP_

#include <schur/matrix/Matrix_MainClass.hpp>

namespace schur {
template <msize_t Rows, msize_t Cols, typename Scalar, Layout L>
auto& Matrix<Rows, Cols, Scalar, L>::at(this auto&& self, index_t r, index_t c)
{
  if (r > self.dims.rows() || r < 0) { throw std::out_of_range("row index is out of bounds"); }
  if (c > self.dims.cols() || c < 0) { throw std::out_of_range("col index is out of bounds"); }
  // TODO: negative index access, instance here

  if constexpr (L == Layout::ColMajor) {
    return self.storage.at(c * self.rows() + r);
  } else {
    return self.storage.at(r * self.cols() + c);
  }
}

// template <msize_t Rows, msize_t Cols, typename Scalar, Layout L>
// BlockView<T, L> Matrix<Rows, Cols, Scalar, L>::block(size_t start_rows, size_t start_cols, size_t rows, size_t cols)
// {
//   return BlockView<T, L>(this, start_rows, start_cols, rows, cols);
// }

template <msize_t Rows, msize_t Cols, typename Scalar, Layout L>
auto& Matrix<Rows, Cols, Scalar, L>::operator[](this auto&& self, index_t i)
{
  if (i < 0) throw std::out_of_range("out of bounds access");
  // TODO: negative index access, instance here
  return self.storage[i];
}

template <msize_t Rows, msize_t Cols, typename Scalar, Layout L>
auto& Matrix<Rows, Cols, Scalar, L>::operator[](this auto&& self, index_t r, index_t c)
{
  if (r < 0 || c < 0) throw std::out_of_range("out of bounds access");
  // TODO: negative index access, instance here
  if constexpr (L == Layout::ColMajor) {
    return self.storage[c * self.dims.rows() + r];
  } else {
    return self.storage[r * self.dims.cols() + c];
  }
}
} // namespace schur
#endif //SCHUR_MATRIX_MAIN_FUNCS_HPP_