#ifndef SCHUR_MISC_HPP_
#define SCHUR_MISC_HPP_

#include <iostream>

#include "schur/core/Types.hpp"
#include "schur/matrix/Matrix_MainClass.hpp"

namespace schur {
template <msize_t Rows, msize_t Cols, typename Scalar, Layout L>
constexpr msize_t construct_dims_rows(const Matrix<Rows, Cols, Scalar, L>& other)
{
  if constexpr (Rows == Dynamic) {
    return other.rows();
  }
  else {
    return Rows;
  }
}
template <msize_t Rows, msize_t Cols, typename Scalar, Layout L>
constexpr msize_t construct_dims_cols(const Matrix<Rows, Cols, Scalar, L>& other)
{
  if constexpr (Cols == Dynamic) {
    return other.cols();
  }
  else {
    return Cols;
  }
}

// print for matrix
template <internal::MatrixExpr Derived>
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

template <internal::MatrixExpr Derived>
requires(internal::QuaternionType<typename Derived::val_t>)
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
#endif //SCHUR_MISC_HPP_
