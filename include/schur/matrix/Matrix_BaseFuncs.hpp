#ifndef MATRIX_BASE_FUNCS_HPP
#define MATRIX_BASE_FUNCS_HPP

#include <schur/matrix/Matrix_BaseClass.hpp>

namespace schur {
namespace internal {
template<typename T, index_t Rows, index_t Cols, Layout L>
[[nodiscard]] auto& MatrixBase<T, Rows, Cols, L>::
row_ref(this auto&& self)
{
  return self.dims.row_ref();
}

template<typename T, index_t Rows, index_t Cols, Layout L>
[[nodiscard]] auto& MatrixBase<T, Rows, Cols, L>::
col_ref(this auto&& self)
{
  return self.dims.col_ref();
}

template<typename T, index_t Rows, index_t Cols, Layout L>
[[nodiscard]] auto MatrixBase<T, Rows, Cols, L>::
rows(this auto&& self)
{
  return self.dims.rows();
}

template<typename T, index_t Rows, index_t Cols, Layout L>
[[nodiscard]] auto MatrixBase<T, Rows, Cols, L>::
cols(this auto&& self)
{
  return self.dims.cols();
}

template <typename T, index_t Rows, index_t Cols, Layout L>
auto& MatrixBase<T, Rows, Cols, L>::
operator[](this auto&& self, size_t i) {
  return self.storage[i];
}

template <typename T, index_t Rows, index_t Cols, Layout L>
auto& MatrixBase<T, Rows, Cols, L>::
operator[](this auto&& self, size_t r, size_t c) {
  if constexpr (L == Layout::ColMajor) {
    return self.storage[c * self.rows() + r];
  } else {
    return self.storage[r * self.cols() + c];
  }
}
} // namespace internal
} // namespace schur

#endif