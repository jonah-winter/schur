#ifndef SCHUR_MATRIX_TRANSPOSE_HPP_
#define SCHUR_MATRIX_TRANSPOSE_HPP_

#include <type_traits>

#include "schur/core/Concepts.hpp"
#include "schur/matrix/Matrix_BaseClass.hpp"

namespace schur {
namespace internal {
template <MatrixExpr D>
struct Transposed : MatrixBase
  <
  Transposed<D>,
  get_cols<D>,
  get_rows<D>,
  typename std::remove_cvref_t<D>::val_t,
  std::remove_cvref_t<D>::layout()
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

  [[nodiscard]] size_t rows(this auto&& self)
  {
    return self.derived.cols();
  }

  [[nodiscard]] size_t cols(this auto&& self)
  {
    return self.derived.rows();
  }

  size_t size() const
  {
    return derived.rows() * derived.cols();
  }
};
} // namespace internal
} // namespace schur
#endif //SCHUR_MATRIX_TRANSPOSE_HPP_
