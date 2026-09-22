#ifndef MATRIX_BASE_FUNCS_HPP_
#define MATRIX_BASE_FUNCS_HPP_

#include "schur/matrix/Matrix_BaseClass.hpp"

namespace schur {
namespace internal {
//template <typename Derived, typename T, msize_t Rows, msize_t Cols, Layout L>
//[[nodiscard]] Derived& MatrixBase<Derived, T, Rows, Cols, L>::derived()
//{
//  return static_cast<Derived&>(*this);
//}
//
//template <typename Derived, typename T, msize_t Rows, msize_t Cols, Layout L>
//[[nodiscard]] const Derived& MatrixBase<Derived, T, Rows, Cols, L>::derived() const
//{
//  return static_cast<const Derived&>(*this);
//}

template <typename Derived, typename Scalar, msize_t Rows, msize_t Cols, Layout L>
[[nodiscard]] size_t MatrixBase<Derived, Scalar, Rows, Cols, L>::
rows(this auto&& self)
{
  return self.dims.rows();
}

template <typename Derived, typename Scalar, msize_t Rows, msize_t Cols, Layout L>
[[nodiscard]] size_t MatrixBase<Derived, Scalar, Rows, Cols, L>::
cols(this auto&& self)
{
  return self.dims.cols();
}


template <typename Derived, typename Scalar, msize_t Rows, msize_t Cols, Layout L>
[[nodiscard]] size_t MatrixBase<Derived, Scalar, Rows, Cols, L>::size(this auto&& self)
{
  return self.dims.rows() * self.dims.cols();
}

template <typename Derived, typename Scalar, msize_t Rows, msize_t Cols, Layout L>
[[nodiscard]] Scalar* MatrixBase<Derived, Scalar, Rows, Cols, L>::data(this auto&& self)
{
  return self.storage.data();
}

template <typename Derived, typename Scalar, msize_t Rows, msize_t Cols, Layout L>
void MatrixBase<Derived, Scalar, Rows, Cols, L>::init(this auto&& self)
{
  self.storage.init();
}

template <typename Derived, typename Scalar, msize_t Rows, msize_t Cols, Layout L>
void MatrixBase<Derived, Scalar, Rows, Cols, L>::init(this auto&& self, msize_t start, msize_t end)
{
  self.storage.init(start, end);
}

template <typename Derived, typename Scalar, msize_t Rows, msize_t Cols, Layout L>
void MatrixBase<Derived, Scalar, Rows, Cols, L>::init(this auto&& self, Scalar val)
{
  self.storage.init(val);
}

template <typename Derived, typename Scalar, msize_t Rows, msize_t Cols, Layout L>
void MatrixBase<Derived, Scalar, Rows, Cols, L>::init(this auto&& self, msize_t start, msize_t end, Scalar val)
{
  self.storage.init(start, end, val);
}
} // namespace internal
} // namespace schur
#endif // MATRIX_BASE_FUNCS_HPP_
