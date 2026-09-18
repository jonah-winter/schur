#ifndef SCHUR_MATRIX_TRANSPOSE_HPP
#define SCHUR_MATRIX_TRANSPOSE_HPP

#include <type_traits>

#include "schur/core/Concepts.hpp"
#include "schur/matrix/Matrix_BaseClass.hpp"

namespace schur {
namespace internal {
template <MatrixExpr D>
struct Transposed : MatrixBase
  <
  Transposed<D>,
  typename std::remove_cvref_t<D>::val_t,
  get_cols<D>,
  get_rows<D>
  >
{
  using derived_t = operand_t<D>;
  using val_t     = typename std::remove_cvref_t<D>::val_t;
  using dims_t    = Dimensions<std::remove_cvref_t<D>::dims_t::static_cols, std::remove_cvref_t<D>::dims_t::static_rows>;

  derived_t derived;

  Transposed(D&& d) : derived(std::forward<D>(d)) {}

  auto operator[](this auto&& self, index_t r, index_t c) {
    return self.derived[c, r];
  }

  size_t rows() const
  {
    return derived.cols();
  }

  size_t cols() const
  {
    return derived.rows();
  }

  size_t size() const
  {
    return derived.rows() * derived.cols();
  }
};
} // namespace internal
} // namespace schur
#endif //SCHUR_MATRIX_TRANSPOSE_HPP
