#ifndef SCHUR_MATRIX_TO_LAZY_CONSTRUCTORS_HPP_
#define SCHUR_MATRIX_TO_LAZY_CONSTRUCTORS_HPP_

#include "schur/core/Concepts.hpp"
#include "schur/matrix/Matrix_MainClass.hpp"
#include "schur/matrix/eval.hpp"

namespace schur {
template <msize_t Rows, msize_t Cols, typename Scalar, Layout L>
Matrix<Rows, Cols, Scalar, L>
::Matrix(BlockView<Scalar, L> block)
  : dims(block.rows(), block.cols()), storage(block.size())
{
  size_t r = block.rows();
  size_t c = block.cols();
  if (has_fixed_rows && Rows != r) { throw std::invalid_argument("wrong amount of rows"); }
  if (has_fixed_cols && Cols != c) { throw std::invalid_argument("wrong amount of cols"); }
  for (size_t i{0}; i < r; i++) {
    for (size_t z{0}; z < c; z++) {
      (*this)[i, z] = block[i, z];
    }
  }
}

template <msize_t Rows, msize_t Cols, typename Scalar, Layout L>
template <internal::MatrixExpr Derived>
Matrix<Rows, Cols, Scalar, L>
::Matrix(const Derived& other) 
{
  *this = eval(other);
}
} // namespace schur
#endif //SCHUR_MATRIX_TO_LAZY_CONSTRUCTORS_HPP_
