#ifndef SCHUR_MATRIX_MAIN_CLASS_HPP
#define SCHUR_MATRIX_MAIN_CLASS_HPP

#include <schur/matrix/Matrix_BaseClass.hpp>

namespace schur {
template <typename T, index_t Rows, index_t Cols,
          internal::Layout L = internal::Layout::ColMajor>
struct Matrix : public internal::MatrixBase<T, Rows, Cols, L>
{
  using Base = internal::MatrixBase<T, Rows, Cols, L>;
  
};
}

#endif //SCHUR_MATRIX_MAIN_CLASS_HPP
