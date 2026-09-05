#ifndef DIMENSIONS_DECL_INTERNAL_HPP
#define DIMENSIONS_DECL_INTERNAL_HPP

#include <stdexcept>

#include <schur/core/Types.hpp>
#include <schur/dimensions/Generic_DimFuncs.hpp>

namespace schur {
namespace internal {

template <index_t Rows, index_t Cols>
  requires(valid_dims_(Rows, Cols))
struct Dimensions {
  static constexpr bool has_fixed_rows = true;
  static constexpr bool has_fixed_cols = true;
  static constexpr index_t static_rows = Rows;
  static constexpr index_t static_cols = Cols;

  // CONSTRUCTORS //
  Dimensions() = default;
  Dimensions(size_t rows, size_t cols) {}
  template <index_t R, index_t C>
  Dimensions(const Dimensions<R, C>& other);

  template <index_t R, index_t C>
  Dimensions operator=(const Dimensions<R, C>& other);

  // FUNCTIONS //
  [[nodiscard]] static constexpr index_t rows() { return Rows; }
  [[nodiscard]] static constexpr index_t cols() { return Cols; }
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
    if (rows < 0) throw std::invalid_argument("cannot have 0 rows");
    if (cols < 0) throw std::invalid_argument("cannot have 0 cols");
  }

  Dimensions() : rows_{0}, cols_{0} {}

  // FUNCTIONS //
  [[nodiscard]] auto rows(this auto&& self) { return self.rows_; }
  [[nodiscard]] auto cols(this auto&& self) { return self.cols_; }
  bool valid_dims_overflow() const;
};

template <index_t Rows>
  requires(valid_dim_(Rows))
struct Dimensions<Rows, Dynamic> {
  // STRUCT VARIABLES //
  static constexpr bool has_fixed_rows = true;
  static constexpr bool has_fixed_cols = false;
  static constexpr index_t static_rows = Rows;
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

  // FUNCTIONS //
  [[nodiscard]] static constexpr index_t rows() { return Rows; }
  [[nodiscard]] auto& cols(this auto&& self) { return self.cols_; }
  // this is for Matrix initialization
  [[nodiscard]] static size_t size(size_t dim) { return Rows * dim; }
  bool valid_dims_overflow() const;
};

template <index_t Cols>
  requires(valid_dim_(Cols))
struct Dimensions<Dynamic, Cols> {
  // STRUCT VARIABLES //
  static constexpr bool has_fixed_rows = false;
  static constexpr bool has_fixed_cols = true;
  static constexpr index_t static_rows = Dynamic;
  static constexpr index_t static_cols = Cols;

  index_t rows_;

  // CONSTRUCTORS //
  Dimensions() : rows_{1} {}

  explicit Dimensions(index_t rows) : rows_{rows} {
    if (rows < 0) throw std::invalid_argument("cannot have 0 rows");
  }

  Dimensions(index_t rows, index_t cols) : rows_{rows} {
    if (rows < 0) throw std::invalid_argument("cannot have 0 rows");
  }

  // FUNCTIONS //
  [[nodiscard]] auto& rows(this auto&& self) { return self.rows_; }
  [[nodiscard]] static constexpr index_t cols() { return Cols; }
  // this is for Matrix initialization, not to be used
  [[nodiscard]] static size_t size(size_t dim) { return dim * Cols; }
  bool valid_dims_overflow() const;
};
} // namespace internal
} // namespace Matrix
#endif // DIMENSIONS_DECL_INTERNAL_HPP