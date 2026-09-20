#ifndef SCHUR_MATRIX_TO_LAZY_CONSTRUCTORS_HPP_
#define SCHUR_MATRIX_TO_LAZY_CONSTRUCTORS_HPP_

#include "schur/core/Concepts.hpp"
#include "schur/matrix/Matrix_MainClass.hpp"

namespace schur {
template <typename _Scalar, index_t _Rows, index_t _Cols, Layout _Layout>
Matrix<_Scalar, _Rows, _Cols, _Layout>
::Matrix(BlockView<_Scalar, _Layout> block)
  : dims(block.rows(), block.cols()), storage(block.size())
{
  size_t r = block.rows();
  size_t c = block.cols();
  if (has_fixed_rows && _Rows != r) { throw std::invalid_argument("wrong amount of rows"); }
  if (has_fixed_cols && _Cols != c) { throw std::invalid_argument("wrong amount of cols"); }
  for (size_t i{0}; i < r; i++) {
    for (size_t z{0}; z < c; z++) {
      (*this)[i, z] = block[i, z];
    }
  }
}
} // namespace schur
#endif //SCHUR_MATRIX_TO_LAZY_CONSTRUCTORS_HPP_