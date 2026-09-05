#ifndef MATRIX_BASE_FUNCS_HPP
#define MATRIX_BASE_FUNCS_HPP

#include <schur/matrix/Matrix_BaseClass.hpp>

namespace schur {
namespace internal {
//template <typename Derived, typename T, index_t Rows, index_t Cols, Layout L>
//[[nodiscard]] Derived& MatrixBase<Derived, T, Rows, Cols, L>::derived()
//{
//  return static_cast<Derived&>(*this);
//}
//
//template <typename Derived, typename T, index_t Rows, index_t Cols, Layout L>
//[[nodiscard]] const Derived& MatrixBase<Derived, T, Rows, Cols, L>::derived() const
//{
//  return static_cast<const Derived&>(*this);
//}

template <typename Derived, typename T, index_t Rows, index_t Cols, Layout L>
[[nodiscard]] size_t MatrixBase<Derived, T, Rows, Cols, L>::
rows(this auto&& self)
{
  return self.dims.rows();
}

template <typename Derived, typename T, index_t Rows, index_t Cols, Layout L>
[[nodiscard]] size_t MatrixBase<Derived, T, Rows, Cols, L>::
cols(this auto&& self)
{
  return self.dims.cols();
}


template <typename Derived, typename T, index_t Rows, index_t Cols, Layout L>
[[nodiscard]] size_t MatrixBase<Derived, T, Rows, Cols, L>::size(this auto&& self)
{
  return self.dims.rows() * self.dims.cols();
}

template <typename Derived, typename T, index_t Rows, index_t Cols, Layout L>
[[nodiscard]] T* MatrixBase<Derived, T, Rows, Cols, L>::data(this auto&& self)
{
  return self.storage.data();
}

template <typename Derived, typename T, index_t Rows, index_t Cols, Layout L>
void MatrixBase<Derived, T, Rows, Cols, L>::init(this auto&& self)
{
  self.storage.init();
}

template <typename Derived, typename T, index_t Rows, index_t Cols, Layout L>
void MatrixBase<Derived, T, Rows, Cols, L>::init(this auto&& self, index_t start, index_t end)
{
  self.storage.init(start, end);
}

template <typename Derived, typename T, index_t Rows, index_t Cols, Layout L>
void MatrixBase<Derived, T, Rows, Cols, L>::init(this auto&& self, T val)
{
  self.storage.init(val);
}

template <typename Derived, typename T, index_t Rows, index_t Cols, Layout L>
void MatrixBase<Derived, T, Rows, Cols, L>::init(this auto&& self, index_t start, index_t end, T val)
{
  self.storage.init(start, end, val);
}
} // namespace internal
} // namespace schur
#endif // MATRIX_BASE_FUNCS_HPP
