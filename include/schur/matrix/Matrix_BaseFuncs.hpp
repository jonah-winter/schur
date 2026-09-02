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
constexpr T& MatrixBase<Derived, T, Rows, Cols, L>::
 operator[](this auto&& self, index_t i) {
  return self.begin()[i];
}

template <typename Derived, typename T, index_t Rows, index_t Cols, Layout L>
constexpr auto& MatrixBase<Derived, T, Rows, Cols, L>::
operator[](this auto&& self, index_t r, index_t c) {
  if constexpr (L == Layout::ColMajor) {
    return self.begin()[c * self.rows() + r];
  } else {
    return self.begin()[r * self.cols() + c];
  }
}

template <typename Derived, typename T, index_t Rows, index_t Cols, Layout L>
size_t MatrixBase<Derived, T, Rows, Cols, L>::size(this auto&& self)
{
  return self.dims.rows() * self.dims.cols();
}

template<typename Derived, typename T, index_t Rows, index_t Cols, Layout L>
auto& MatrixBase<Derived, T, Rows, Cols,  L>
::at(this auto &&self, index_t r, index_t c)
{
  if (r > self.dims.rows() || r < 0) { throw std::out_of_range("row index is out of bounds"); }
  if (c > self.dims.cols() || r < 0) { throw std::out_of_range("col index is out of bounds"); }
  if constexpr (L == Layout::ColMajor) {
    return self.storage.at(c * self.dims.rows() + r);
  } else {
    return self.storage.at(r * self.dims.cols() + c);
  }
}
} // namespace internal
} // namespace schur
#endif // MATRIX_BASE_FUNCS_HPP
