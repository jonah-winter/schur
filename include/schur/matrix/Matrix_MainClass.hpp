#ifndef SCHUR_MATRIX_MAIN_CLASS_HPP
#define SCHUR_MATRIX_MAIN_CLASS_HPP

#include <vector>

#include <schur/matrix/lazy/Forward_Lazy.hpp>
#include <schur/matrix/Matrix_BaseClass.hpp>
#include <schur/matrix/Matrix_Block.hpp>

namespace schur {
template <typename T, index_t Rows, index_t Cols,
          Layout L = Layout::ColMajor>
struct Matrix : public internal::MatrixBase<Matrix<T, Rows, Cols, L>, T, Rows, Cols, L>
{
  using Base = internal::MatrixBase<Matrix, T, Rows, Cols, L>;
  using dims_t = internal::Dimensions<Rows, Cols>;
  using val_t  = T;
  friend Base;
  template <typename OtherT, index_t OtherRows, index_t OtherCols, Layout OtherL>
  friend struct Matrix;
private:
  dims_t dims;
  internal::Storage<T> storage;
  static constexpr bool has_fixed_rows = dims_t::has_fixed_rows;
  static constexpr bool has_fixed_cols = dims_t::has_fixed_cols;

public:
  Matrix()
    : dims(Rows, Cols), storage(Rows * Cols) {}
  Matrix(size_t r, size_t c)
    : dims(r, c), storage(r * c) {}
  explicit Matrix(size_t dim)
    : dims(dim), storage(internal::Dimensions<Rows, Cols>::size(dim)) {}
  Matrix(std::initializer_list<std::initializer_list<T>> list);
  Matrix(std::vector<std::vector<T>> list);
  template <size_t arrRows, size_t arrCols>
  Matrix(std::array<std::array<T, arrCols>, arrRows> arr);
  //Matrix(BlockView<T, L> block);
  Matrix(const Matrix&) = default;
  Matrix(Matrix&&) noexcept = default;

  template <index_t R, index_t C>
  requires((R == Rows || R == Dynamic) && (C == Cols || C == Dynamic))
  Matrix(const Matrix<T, R, C, L>& other);

  Matrix& operator=(const Matrix&) = default;
  Matrix& operator=(Matrix&&) = default;
  template <index_t R, index_t C>
  requires((R == Rows || R == Dynamic) && (C == Cols || C == Dynamic))
  Matrix<T, Rows, Cols, L> operator=(const Matrix<T, R, C, L>& other);

  [[nodiscard]] T* begin() { return storage.data(); }
  [[nodiscard]] T* end()   { return storage.data() + (*this).size(); }
  [[nodiscard]] auto& at(this auto&& self, index_t r, index_t c);
  [[nodiscard]] auto& operator[](this auto&& self, index_t r, index_t c);
  BlockView<T, L> block(size_t start_rows, size_t start_cols, size_t rows, size_t cols);
private:
  auto& operator[](this auto&& self, index_t i);
};
}

#endif //SCHUR_MATRIX_MAIN_CLASS_HPP