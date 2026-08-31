#ifndef MATRIX_BASE_CONSTRUCTORS_HPP
#define MATRIX_BASE_CONSTRUCTORS_HPP

#include <cassert>

#include <schur/Generic_GlobalDeclarations.hpp>
#include <schur/matrix/Matrix_BaseClass.hpp>
#include <schur/dimensions/Generic_DimFuncs.hpp>

namespace schur {
namespace internal {
template <typename T, index_t Rows, index_t Cols, Layout L>
MatrixBase<T, Rows, Cols, L>
::MatrixBase(std::initializer_list<std::initializer_list<T>> list)
  : dims(list.size(), validate_list_cols(list)), storage(list.size() * validate_list_cols(list))
{
  size_t r = list.size();
  size_t c = list.begin()->size();
  if (has_fixed_rows && Rows != r) { throw std::invalid_argument("wrong amount of rows"); }
  if (has_fixed_cols && Cols != c) { throw std::invalid_argument("wrong amount of cols"); }

  for (size_t i{0}; i < r; i++) {
    for (size_t z{0}; z < c; z++) {
      if (list.begin()[i].size() != dims.cols()) throw std::logic_error("varying column sizes");
      (*this)[i, z] = list.begin()[i].begin()[z];
    }
  }
}

template <typename T, index_t Rows, index_t Cols, Layout L>
MatrixBase<T, Rows, Cols, L>
::MatrixBase(std::vector<std::vector<T>> list)
  : dims(list.size(), validate_list_cols(list)), storage(list.size() * validate_list_cols(list))
{
  size_t r = list.size();
  size_t c = list.begin()->size();
  if (has_fixed_rows && Rows != r) { throw std::invalid_argument("wrong amount of rows"); }
  if (has_fixed_cols && Cols != c) { throw std::invalid_argument("wrong amount of cols"); }

  if (list.size() != dims.rows()) throw std::logic_error("wrong amount of rows");
  for (size_t i{0}; i < r; i++) {
    for (size_t z{0}; z < c; z++) {
      if (list[i].size() != dims.cols()) throw std::logic_error("varying or incorrect column sizes");
      (*this)[i, z] = list[i][z];
    }
  }
}

template <typename T, index_t Rows, index_t Cols, Layout L>
template <size_t arrRows, size_t arrCols>
MatrixBase<T, Rows, Cols, L>
::MatrixBase(std::array<std::array<T, arrCols>, arrRows> list)
  : dims(Rows, Cols), storage(Rows * Cols)
{
  if constexpr (has_fixed_rows) static_assert(Rows == arrRows);
  if constexpr (has_fixed_cols) static_assert(Cols == arrCols);

  if (list.size() != dims.rows()) throw std::logic_error("wrong amount of rows");
  if (validate_list_cols(list) != dims.cols()) throw std::logic_error("wrong amount or varying cols");
  for (size_t i{0}; i < arrRows; i++) {
    for (size_t z{0}; z < arrCols; z++) {
      (*this)[i, z] = list[i][z];
    }
  }
}

// template <typename T, index_t Rows, index_t Cols, Layout L>
// template <size_t arrRows, size_t arrCols>
// MatrixBase<T, Rows, Cols, L>
// ::MatrixBase(T list[arrRows][arrCols])
//   : dims(Rows, Cols), storage(Rows * Cols)
// {
//   if constexpr (has_fixed_rows) static_assert(Rows == arrRows);
//   if constexpr (has_fixed_cols) static_assert(Cols == arrCols);
//
//   if (list.size() != dims.rows()) throw std::logic_error("wrong amount of rows");
//   if (list[0].size() != dims.cols()) throw std::logic_error("wrong amoune or varying cols");
//   for (size_t i{0}; i < arrRows; i++) {
//     for (size_t z{0}; z < arrCols; z++) {
//       (*this)[i, z] = list[i][z];
//     }
//   }
// }
} // namespace internal
} // namespace matrix
#endif // MATRIX_BASE_CONSTRUCTORS_HPP