#ifndef SCHUR_MISC_HPP
#define SCHUR_MISC_HPP

#include "schur/core/Types.hpp"
#include "schur/matrix/Matrix_MainClass.hpp"

namespace schur {
template <typename T, index_t Rows, index_t Cols, Layout L>
constexpr index_t construct_dims_rows_(const Matrix<T, Rows, Cols, L>& other)
{
  if constexpr (Rows == Dynamic) {
    return other.rows();
  }
  else {
    return Rows;
  }
}
template <typename T, index_t Rows, index_t Cols, Layout L>
constexpr index_t construct_dims_cols_(const Matrix<T, Rows, Cols, L>& other)
{
  if constexpr (Cols == Dynamic) {
    return other.cols();
  }
  else {
    return Cols;
  }
}
template <typename Derived>
requires(internal::MatrixExpr<Derived>)
std::ostream& operator<<(std::ostream& os, const Derived& m)
{
  os << "[";
  for (size_t idx{0}; idx < m.rows(); idx++) {
    os << "[";
    for (size_t idx2{0}; idx2 < m.cols(); idx2++) {
      os << m[idx, idx2];
      if (idx2 + 1 < m.cols()) {
        os << ", ";
      } else {
        if (idx + 1 < m.rows()) {
          os << "], ";
        } else {
          os << "]";
        }
      }
    }
  }
  os << "]";
  return os;
}
} // namespace schur
#endif //SCHUR_MISC_HPP