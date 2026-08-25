#ifndef DIMENSIONS_H_
#define DIMENSIONS_H_

#include <cstddef>
#include <stdexcept>

#include <matrix/global_decls.h>

namespace matrix {
namespace internal {

template <size_t Rows, size_t Cols>
  requires(Rows != 0 && Cols != 0)
struct Dimensions {

  // CONSTRUCTORS //
  Dimensions() = default;

  // FUNCTIONS //

  [[nodiscard]] static constexpr size_t rows() { return Rows; }

  [[nodiscard]] static constexpr size_t cols() { return Cols; }
};

template <>
struct Dimensions<Dynamic, Dynamic> {
  // STRUCT VARIABLES //
  size_t rows_;
  size_t cols_;

  // CONSTRUCTORS //
  Dimensions(size_t rows, size_t cols) : rows_{rows}, cols_{cols} {
    if (!rows) throw std::invalid_argument("cannot have 0 rows");
    if (!cols) throw std::invalid_argument("cannot have 0 cols");
  }

  // FUNCTIONS //
  [[nodiscard]] size_t rows() const { return rows_; }

  [[nodiscard]] size_t cols() const { return cols_; }
};

template <size_t Rows>
  requires(Rows != 0)
struct Dimensions<Rows, Dynamic> {
  // STRUCT VARIABLES //
  size_t cols_;

  // CONSTRUCTORS //
  explicit Dimensions(size_t cols) : cols_{cols} {
    if (!cols) throw std::invalid_argument("cannot have 0 columns");
  }

  // FUNCTIONS //
  [[nodiscard]] static constexpr size_t rows() { return Rows; }

  [[nodiscard]] size_t cols() const { return cols_; }
};

template <size_t Cols>
  requires(Cols != 0)
struct Dimensions<Dynamic, Cols> {
  // STRUCT VARIABLES //
  size_t rows_;

  // CONSTRUCTORS //
  explicit Dimensions(size_t rows) : rows_{rows} {
    if (!rows) throw std::invalid_argument("cannot have 0 rows");
  }

  // FUNCTIONS //
  [[nodiscard]] size_t rows() const { return rows_; }

  [[nodiscard]] static constexpr size_t cols() { return Cols; }
};
} // namespace internal
} // namespace matrix

#endif
