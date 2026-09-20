#ifndef MATRIX_BASE_FUNCS_HPP_
#define MATRIX_BASE_FUNCS_HPP_

#include "schur/matrix/Matrix_BaseClass.hpp"

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

template <typename _Derived, typename _Scalar, index_t _Rows, index_t _Cols, Layout _Layout>
[[nodiscard]] size_t MatrixBase<_Derived, _Scalar, _Rows, _Cols, _Layout>::
rows(this auto&& self)
{
  return self.dims.rows();
}

template <typename _Derived, typename _Scalar, index_t _Rows, index_t _Cols, Layout _Layout>
[[nodiscard]] size_t MatrixBase<_Derived, _Scalar, _Rows, _Cols, _Layout>::
cols(this auto&& self)
{
  return self.dims.cols();
}


template <typename _Derived, typename _Scalar, index_t _Rows, index_t _Cols, Layout _Layout>
[[nodiscard]] size_t MatrixBase<_Derived, _Scalar, _Rows, _Cols, _Layout>::size(this auto&& self)
{
  return self.dims.rows() * self.dims.cols();
}

template <typename _Derived, typename _Scalar, index_t _Rows, index_t _Cols, Layout _Layout>
[[nodiscard]] _Scalar* MatrixBase<_Derived, _Scalar, _Rows, _Cols, _Layout>::data(this auto&& self)
{
  return self.storage.data();
}

template <typename _Derived, typename _Scalar, index_t _Rows, index_t _Cols, Layout _Layout>
void MatrixBase<_Derived, _Scalar, _Rows, _Cols, _Layout>::init(this auto&& self)
{
  self.storage.init();
}

template <typename _Derived, typename _Scalar, index_t _Rows, index_t _Cols, Layout _Layout>
void MatrixBase<_Derived, _Scalar, _Rows, _Cols, _Layout>::init(this auto&& self, index_t start, index_t end)
{
  self.storage.init(start, end);
}

template <typename Derived, typename T, index_t Rows, index_t Cols, Layout _Layout>
void MatrixBase<Derived, T, Rows, Cols, _Layout>::init(this auto&& self, T val)
{
  self.storage.init(val);
}

template <typename Derived, typename T, index_t Rows, index_t Cols, Layout _Layout>
void MatrixBase<Derived, T, Rows, Cols, _Layout>::init(this auto&& self, index_t start, index_t end, T val)
{
  self.storage.init(start, end, val);
}
} // namespace internal
} // namespace schur
#endif // MATRIX_BASE_FUNCS_HPP_
