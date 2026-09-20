#ifndef DIMENSIONS_DECL_INTERNAL_HPP_
#define DIMENSIONS_DECL_INTERNAL_HPP_

#include <stdexcept>

#include "schur/core/Types.hpp"
#include "schur/matrix/dimensions/Generic_DimFuncs.hpp"

namespace schur {
namespace internal {
// no move constructors because it doesnt own anything that would take a long time to copy
template <index_t _Rows, index_t _Cols>
  requires(valid_dims(_Rows, _Cols))
struct Dimensions {
  static constexpr bool has_fixed_rows = true;
  static constexpr bool has_fixed_cols = true;
  static constexpr index_t static_rows = _Rows;
  static constexpr index_t static_cols = _Cols;

  // CONSTRUCTORS //
  Dimensions() = default;
  // these two are valid but nothing will happen
  Dimensions(size_t rows, size_t cols) {}
  template <index_t R, index_t C>
  Dimensions(const Dimensions<R, C>& other) {}

  template <index_t R, index_t C>
  Dimensions operator=(const Dimensions<R, C>& other) { return *this; }

  // FUNCTIONS //
  [[nodiscard]] static constexpr index_t rows() { return _Rows; }
  [[nodiscard]] static constexpr index_t cols() { return _Cols; }
  bool valid_dims_overflow() const;
};

template <>
struct Dimensions<Dynamic, Dynamic> {
  // STRUCT VARIABLES //
  static constexpr bool has_fixed_rows = false;
  static constexpr bool has_fixed_cols = false;
  static constexpr index_t static_rows = Dynamic;
  static constexpr index_t static_cols = Dynamic;

  index_t rows_;
  index_t cols_;

  // CONSTRUCTORS //
  Dimensions(index_t rows, index_t cols) : rows_{rows}, cols_{cols} {
    if (rows < 0) throw std::invalid_argument("cannot have less than 0 rows");
    if (cols < 0) throw std::invalid_argument("cannot have less than 0 cols");
  }

  template <index_t R, index_t C>
  Dimensions(const Dimensions<R, C>& other);

  template <index_t R, index_t C>
  Dimensions operator=(const Dimensions<R, C>& other);

  Dimensions() : rows_{0}, cols_{0} {}

  // FUNCTIONS //
  [[nodiscard]] auto rows(this auto&& self) { return self.rows_; }
  [[nodiscard]] auto cols(this auto&& self) { return self.cols_; }
  bool valid_dims_overflow() const;
};

template <index_t _Rows>
  requires(valid_dim(_Rows))
struct Dimensions<_Rows, Dynamic> {
  // STRUCT VARIABLES //
  static constexpr bool has_fixed_rows = true;
  static constexpr bool has_fixed_cols = false;
  static constexpr index_t static_rows = _Rows;
  static constexpr index_t static_cols = Dynamic;

  index_t cols_;

  // CONSTRUCTORS //
  Dimensions() : cols_{1} {}

  explicit Dimensions(index_t cols) : cols_{cols} {
    if (cols < 0) throw std::invalid_argument("cannot have 0 columns");
  }

  Dimensions(index_t rows, index_t cols) : cols_{cols} {
    if (cols < 0) throw std::invalid_argument("cannot have 0 cols");
  }

  template <index_t R, index_t C>
  Dimensions(const Dimensions<R, C>& other);

  template <index_t R, index_t C>
  Dimensions operator=(const Dimensions<R, C>& other);

  // FUNCTIONS //
  [[nodiscard]] static constexpr index_t rows() { return _Rows; }
  [[nodiscard]] auto& cols(this auto&& self) { return self.cols_; }
  // this is for Matrix initialization
  [[nodiscard]] static size_t size(size_t dim) { return _Rows * dim; }
  bool valid_dims_overflow() const;
};

template <index_t _Cols>
  requires(valid_dim(_Cols))
struct Dimensions<Dynamic, _Cols> {
  // STRUCT VARIABLES //
  static constexpr bool has_fixed_rows = false;
  static constexpr bool has_fixed_cols = true;
  static constexpr index_t static_rows = Dynamic;
  static constexpr index_t static_cols = _Cols;

  index_t rows_;

  // CONSTRUCTORS //
  Dimensions() : rows_{1} {}

  explicit Dimensions(index_t rows) : rows_{rows} {
    if (rows < 0) throw std::invalid_argument("cannot have 0 rows");
  }

  Dimensions(index_t rows, index_t cols) : rows_{rows} {
    if (rows < 0) throw std::invalid_argument("cannot have 0 rows");
  }

  template <index_t R, index_t C>
  Dimensions(const Dimensions<R, C>& other);

  template <index_t R, index_t C>
  Dimensions operator=(const Dimensions<R, C>& other);

  // FUNCTIONS //
  [[nodiscard]] auto& rows(this auto&& self) { return self.rows_; }
  [[nodiscard]] static constexpr index_t cols() { return _Cols; }
  // this is for Matrix initialization, not to be used
  [[nodiscard]] static size_t size(size_t dim) { return dim * _Cols; }
  bool valid_dims_overflow() const;
};
} // namespace internal
} // namespace Matrix
#endif // DIMENSIONS_DECL_INTERNAL_HPP_