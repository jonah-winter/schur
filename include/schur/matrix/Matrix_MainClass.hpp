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
template <msize_t Rows, msize_t Cols, typename Scalar,
          Layout L = Layout::ColMajor>
struct Matrix : internal::MatrixBase<Matrix<Rows, Cols, Scalar, L>, Scalar, Rows, Cols, L>
{
  using Base = internal::MatrixBase<Matrix, Scalar, Rows, Cols, L>;
  using dims_t = internal::Dimensions<Rows, Cols>;
  using val_t  = Scalar;

  friend Base;
  template <typename OS, msize_t OR, msize_t OC, Layout OL>
  friend struct Matrix;
private:
  dims_t dims;
  internal::Storage<Scalar> storage;
  static constexpr bool has_fixed_rows = dims_t::has_fixed_rows;
  static constexpr bool has_fixed_cols = dims_t::has_fixed_cols;

public:
  Matrix()
    : dims(Rows, Cols), storage(Rows * Cols) {}
  Matrix(size_t r, size_t c)
    : dims(r, c), storage(r * c) {}
  explicit Matrix(size_t dim)
    : dims(dim), storage(internal::Dimensions<Rows, Cols>::size(dim)) {}
  Matrix(std::initializer_list<std::initializer_list<Scalar>> list);
  Matrix(std::vector<std::vector<Scalar>> list);
  template <size_t arrRows, size_t arrCols>
  Matrix(std::array<std::array<Scalar, arrCols>, arrRows> arr);
  Matrix(const Matrix& other)
    : storage(other.storage), dims(construct_dims_rows(other), construct_dims_cols(other)) {}
  Matrix(Matrix&&) noexcept = default;
  Matrix(BlockView<Scalar, L> block);

  template <msize_t OR, msize_t OC>
  requires((OR == Rows || OR == Dynamic) && (OC == Cols || OC == Dynamic))
  Matrix(const Matrix<OR, OC, Scalar, L>& other);

  Matrix& operator=(const Matrix& other);
  Matrix& operator=(Matrix&&) = default;

  template <msize_t OR, msize_t OC>
  requires((OR == Rows || OR == Dynamic || Rows == Dynamic) && (OC == Cols || OC == Dynamic || Cols == Dynamic))
  Matrix& operator=(const Matrix<OR, OC, Scalar, L>& other);

  [[nodiscard]] Scalar* begin() { return storage.data(); }
  [[nodiscard]] Scalar* end()   { return storage.data() + (*this).size(); }
  [[nodiscard]] auto& at(this auto&& self, index_t r, index_t c);
  [[nodiscard]] auto& operator[](this auto&& self, index_t r, index_t c);
  //BlockView<T, L> block(size_t start_rows, size_t start_cols, size_t rows, size_t cols);
private:
  auto& operator[](this auto&& self, index_t i);
};
} // namespace schur
#endif //SCHUR_MATRIX_MAIN_CLASS_HPP_