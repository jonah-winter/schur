#ifndef SCHUR_MATRIX_MAIN_CLASS_HPP_
#define SCHUR_MATRIX_MAIN_CLASS_HPP_

#include <vector>

#include "schur/matrix/lazy/Forward_Lazy.hpp"
// #include "schur/matrix/dimensions/Dimensions_Include.hpp"
// #include "schur/matrix/storage/Storage_Include.hpp"
#include "schur/matrix/Matrix_BaseClass.hpp"
#include "lazy/Matrix_Block.hpp"
//#include "schur/matrix/mult/Matrix_MultMain.hpp"
#include "schur/matrix/misc.hpp"

namespace schur {
template <typename _Scalar, index_t _Rows, index_t _Cols,
          Layout _Layout = Layout::ColMajor>
struct Matrix : public internal::MatrixBase<Matrix<_Scalar, _Rows, _Cols, _Layout>, _Scalar, _Rows, _Cols, _Layout>
{
  using Base = internal::MatrixBase<Matrix, _Scalar, _Rows, _Cols, _Layout>;
  using dims_t = internal::Dimensions<_Rows, _Cols>;
  using val_t  = _Scalar;

  friend Base;
  template <typename OtherT, index_t OtherRows, index_t OtherCols, Layout OtherL>
  friend struct Matrix;
private:
  dims_t dims;
  internal::Storage<_Scalar> storage;
  static constexpr bool has_fixed_rows = dims_t::has_fixed_rows;
  static constexpr bool has_fixed_cols = dims_t::has_fixed_cols;

public:
  Matrix()
    : dims(_Rows, _Cols), storage(_Rows * _Cols) {}
  Matrix(size_t r, size_t c)
    : dims(r, c), storage(r * c) {}
  explicit Matrix(size_t dim)
    : dims(dim), storage(internal::Dimensions<_Rows, _Cols>::size(dim)) {}
  Matrix(std::initializer_list<std::initializer_list<_Scalar>> list);
  Matrix(std::vector<std::vector<_Scalar>> list);
  template <size_t arrRows, size_t arrCols>
  Matrix(std::array<std::array<_Scalar, arrCols>, arrRows> arr);
  Matrix(const Matrix& other)
    : storage{other.storage}, dims{construct_dims_rows_(other), construct_dims_cols_(other)} {}
  Matrix(Matrix&&) noexcept = default;

  template <index_t R, index_t C>
  requires((R == _Rows || R == Dynamic) && (C == _Cols || C == Dynamic))
  Matrix(const Matrix<_Scalar, R, C, _Layout>& other);

  Matrix& operator=(const Matrix<_Scalar, _Rows, _Cols, _Layout>& other);
  Matrix& operator=(Matrix&&) = default;

  template <index_t R, index_t C>
  requires((R == _Rows || R == Dynamic || _Rows == Dynamic) && (C == _Cols || C == Dynamic || _Cols == Dynamic))
  Matrix& operator=(const Matrix<_Scalar, R, C, _Layout>& other);

  // Lazy constructors
  Matrix(BlockView<_Scalar, _Layout> block);

  [[nodiscard]] _Scalar* begin() { return storage.data(); }
  [[nodiscard]] _Scalar* end()   { return storage.data() + (*this).size(); }
  [[nodiscard]] auto& at(this auto&& self, index_t r, index_t c);
  [[nodiscard]] auto& operator[](this auto&& self, index_t r, index_t c);
  //BlockView<T, L> block(size_t start_rows, size_t start_cols, size_t rows, size_t cols);
private:
  auto& operator[](this auto&& self, index_t i);
};
} // namespace schur
#endif //SCHUR_MATRIX_MAIN_CLASS_HPP_