#ifndef DIMENSIONS_DECL_INTERNAL_HPP_
#define DIMENSIONS_DECL_INTERNAL_HPP_

#include <stdexcept>

#include "schur/core/Types.hpp"
#include "schur/matrix/dimensions/Generic_DimFuncs.hpp"

namespace schur {
namespace internal {
// no move constructors because it doesnt own anything that would take a long time to copy
template <msize_t Rows, msize_t Cols>
  requires(valid_dims(Rows, Cols))
struct Dimensions {
  static constexpr bool has_fixed_rows = true;
  static constexpr bool has_fixed_cols = true;
  static constexpr msize_t static_rows = Rows;
  static constexpr msize_t static_cols = Cols;

  // CONSTRUCTORS //
  Dimensions() = default;
  // these two are valid but nothing will happen
  Dimensions(size_t rows, size_t cols) {}
  template <msize_t R, msize_t C>
  Dimensions(const Dimensions<R, C>& other) {}

  template <msize_t R, msize_t C>
  Dimensions operator=(const Dimensions<R, C>& other) { return *this; }

  // FUNCTIONS //
  [[nodiscard]] static constexpr msize_t rows() { return Rows; }
  [[nodiscard]] static constexpr msize_t cols() { return Cols; }
  bool valid_dims_overflow() const;
};

template <>
struct Dimensions<Dynamic, Dynamic> {
  // STRUCT VARIABLES //
  static constexpr bool has_fixed_rows = false;
  static constexpr bool has_fixed_cols = false;
  static constexpr msize_t static_rows = Dynamic;
  static constexpr msize_t static_cols = Dynamic;

  size_t rows_;
  size_t cols_;

  // CONSTRUCTORS //
  Dimensions(size_t rows, size_t cols) : rows_{rows}, cols_{cols} {
    if (rows < 0) throw std::invalid_argument("cannot have less than 0 rows");
    if (cols < 0) throw std::invalid_argument("cannot have less than 0 cols");
  }

  template <msize_t R, msize_t C>
  Dimensions(const Dimensions<R, C>& other);

  template <msize_t R, msize_t C>
  Dimensions operator=(const Dimensions<R, C>& other);

  Dimensions() : rows_{0}, cols_{0} {}

  // FUNCTIONS //
  [[nodiscard]] auto rows(this auto&& self) { return self.rows_; }
  [[nodiscard]] auto cols(this auto&& self) { return self.cols_; }
  bool valid_dims_overflow() const;
};

template <msize_t Rows>
  requires(valid_dim(Rows))
struct Dimensions<Rows, Dynamic> {
  // STRUCT VARIABLES //
  static constexpr bool has_fixed_rows = true;
  static constexpr bool has_fixed_cols = false;
  static constexpr msize_t static_rows = Rows;
  static constexpr msize_t static_cols = Dynamic;

  size_t cols_;

  // CONSTRUCTORS //
  Dimensions() : cols_{1} {}

  explicit Dimensions(size_t cols) : cols_{cols} {
    if (cols < 0) throw std::invalid_argument("cannot have 0 columns");
  }

  Dimensions(size_t rows, size_t cols) : cols_{cols} {
    if (cols < 0) throw std::invalid_argument("cannot have 0 cols");
  }

  template <msize_t R, msize_t C>
  Dimensions(const Dimensions<R, C>& other);

  template <msize_t R, msize_t C>
  Dimensions operator=(const Dimensions<R, C>& other);

  // FUNCTIONS //
  [[nodiscard]] static constexpr msize_t rows() { return Rows; }
  [[nodiscard]] auto& cols(this auto&& self) { return self.cols_; }
  // this is for Matrix initialization
  [[nodiscard]] static size_t size(size_t dim) { return Rows * dim; }
  bool valid_dims_overflow() const;
};

template <msize_t Cols>
  requires(valid_dim(Cols))
struct Dimensions<Dynamic, Cols> {
  // STRUCT VARIABLES //
  static constexpr bool has_fixed_rows = false;
  static constexpr bool has_fixed_cols = true;
  static constexpr msize_t static_rows = Dynamic;
  static constexpr msize_t static_cols = Cols;

  size_t rows_;

  // CONSTRUCTORS //
  Dimensions() : rows_{0} {}

  explicit Dimensions(size_t rows) : rows_{rows} {
    if (rows < 0) throw std::invalid_argument("cannot have negative rows");
  }

  Dimensions(size_t rows, size_t cols) : rows_{rows} {
    if (rows < 0) throw std::invalid_argument("cannot have negative rows");
  }

  template <msize_t R, msize_t C>
  Dimensions(const Dimensions<R, C>& other);

  template <msize_t R, msize_t C>
  Dimensions operator=(const Dimensions<R, C>& other);

  // FUNCTIONS //
  [[nodiscard]] auto& rows(this auto&& self) { return self.rows_; }
  [[nodiscard]] static constexpr msize_t cols() { return Cols; }
  // this is for Matrix initialization, not to be used
  [[nodiscard]] static size_t size(size_t dim) { return dim * Cols; }
  bool valid_dims_overflow() const;
};
} // namespace internal
} // namespace Matrix
#endif // DIMENSIONS_DECL_INTERNAL_HPP_