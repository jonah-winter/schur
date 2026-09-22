#ifndef MATRIX_BASE_FUNCS_HPP_
#define MATRIX_BASE_FUNCS_HPP_

#include "schur/matrix/Matrix_BaseClass.hpp"

namespace schur {
namespace internal {
//template <typename Derived, msize_t Rows, msize_t Cols, typename Scalar, Layout L>
//[[nodiscard]] Derived& MatrixBase<Derived, Rows, Cols, Scalar, L>::derived()
//{
//  return static_cast<Derived&>(*this);
//}
//
//template <typename Derived, msize_t Rows, msize_t Cols, typename Scalar, Layout L>
//[[nodiscard]] const Derived& MatrixBase<Derived, Rows, Cols, Scalar, L>::derived() const
//{
//  return static_cast<const Derived&>(*this);
//}

template <typename Derived, msize_t Rows, msize_t Cols, typename Scalar, Layout L>
[[nodiscard]] size_t MatrixBase<Derived, Rows, Cols, Scalar, L>::
rows(this auto&& self)
{
  return self.dims.rows();
}

template <typename Derived, msize_t Rows, msize_t Cols, typename Scalar, Layout L>
[[nodiscard]] size_t MatrixBase<Derived, Rows, Cols, Scalar, L>::
cols(this auto&& self)
{
  return self.dims.cols();
}


template <typename Derived, msize_t Rows, msize_t Cols, typename Scalar, Layout L>
[[nodiscard]] size_t MatrixBase<Derived, Rows, Cols, Scalar, L>::size(this auto&& self)
{
  return self.dims.rows() * self.dims.cols();
}

template <typename Derived, msize_t Rows, msize_t Cols, typename Scalar, Layout L>
[[nodiscard]] Scalar* MatrixBase<Derived, Rows, Cols, Scalar, L>::data(this auto&& self)
{
  return self.storage.data();
}

template <typename Derived, msize_t Rows, msize_t Cols, typename Scalar, Layout L>
void MatrixBase<Derived, Rows, Cols, Scalar, L>::init(this auto&& self)
{
  self.storage.init();
}

template <typename Derived, msize_t Rows, msize_t Cols, typename Scalar, Layout L>
void MatrixBase<Derived, Rows, Cols, Scalar, L>::init(this auto&& self, msize_t start, msize_t end)
{
  self.storage.init(start, end);
}

template <typename Derived, msize_t Rows, msize_t Cols, typename Scalar, Layout L>
void MatrixBase<Derived, Rows, Cols, Scalar, L>::init(this auto&& self, Scalar val)
{
  self.storage.init(val);
}

template <typename Derived, msize_t Rows, msize_t Cols, typename Scalar, Layout L>
void MatrixBase<Derived, Rows, Cols, Scalar, L>::init(this auto&& self, msize_t start, msize_t end, Scalar val)
{
  self.storage.init(start, end, val);
}
} // namespace internal
} // namespace schur
#endif // MATRIX_BASE_FUNCS_HPP_
