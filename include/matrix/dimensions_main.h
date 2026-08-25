#ifndef DIMENSIONS_H_
#define DIMENSIONS_H_

#include <cstddef>
#include <stdexcept>

#include <matrix/global_decls.h>

namespace matrix {
namespace internal {

template <index_t Rows, index_t Cols>
requires(valid_dims_(Rows, Cols))
struct Dimensions {

  // CONSTRUCTORS //
  Dimensions() = default;

  // FUNCTIONS //

  [[nodiscard]] static constexpr index_t rows() { return Rows; }

  [[nodiscard]] static constexpr index_t cols() { return Cols; }
};

template <>
struct Dimensions<Dynamic, Dynamic> {
  // STRUCT VARIABLES //
  index_t rows_;
  index_t cols_;

  // CONSTRUCTORS //
  Dimensions(index_t rows, index_t cols) : rows_{rows}, cols_{cols} {
    if (!rows) throw std::invalid_argument("cannot have 0 rows");
    if (!cols) throw std::invalid_argument("cannot have 0 cols");
  }

  // FUNCTIONS //
  [[nodiscard]] index_t rows() const { return rows_; }

  [[nodiscard]] index_t cols() const { return cols_; }
};

template <index_t Rows>
requires(valid_dim_(Rows))
struct Dimensions<Rows, Dynamic> {
  // STRUCT VARIABLES //
  index_t cols_;

  // CONSTRUCTORS //
  explicit Dimensions(index_t cols) : cols_{cols} {
    if (!cols) throw std::invalid_argument("cannot have 0 columns");
  }

  // FUNCTIONS //
  [[nodiscard]] static constexpr index_t rows() { return Rows; }

  [[nodiscard]] index_t cols() const { return cols_; }
};

template <index_t Cols>
requires(valid_dim_(Cols))
struct Dimensions<Dynamic, Cols> {
  // STRUCT VARIABLES //
  index_t rows_;

  // CONSTRUCTORS //
  explicit Dimensions(index_t rows) : rows_{rows} {
    if (!rows) throw std::invalid_argument("cannot have 0 rows");
  }

  // FUNCTIONS //
  [[nodiscard]] index_t rows() const { return rows_; }

  [[nodiscard]] static constexpr index_t cols() { return Cols; }
};
} // namespace internal
} // namespace matrix

#include <matrix/dim_funcs.h>
#endif
