#ifndef SCHUR_MATRIX_MULT_MAIN_HPP
#define SCHUR_MATRIX_MULT_MAIN_HPP

#include <concepts>
#include "schur/core/Concepts.hpp"
#include "schur/matrix/Matrix_BaseClass.hpp"

namespace schur {
namespace internal {
template <MatrixExpr L, MatrixExpr R>
requires((get_cols<L> == Dynamic || get_cols<L> == get_rows<R>)
      && (get_rows<R> == Dynamic || get_cols<L> == get_rows<R>)
      && std::same_as<typename std::remove_cvref_t<L>::val_t, typename std::remove_cvref_t<R>::val_t>)
struct Mult : MatrixBase
  <
    Mult<L, R>,
    typename std::remove_cvref_t<L>::val_t,
    get_rows<L>,
    get_cols<R>
  >
{
  using left_t  = operand_t<L>;
  using right_t = operand_t<R>;
  using val_t   = typename std::remove_cvref_t<L>::val_t;
  using dims_t  = typename std::remove_cvref_t<L>::dims_t;

  left_t left;
  right_t right;

  Mult(L&& l, R&& r) : left(std::forward<L>(l)), right(std::forward<R>(r)) {}

  auto operator[](this auto&& self, index_t r, index_t c) {
    val_t total{0};
    for (index_t i{0}; i < self.rows(); i++) {
      total += self.left[r, i] * self.right[i, c];
    }
    return total;
  }

  size_t rows() const
  {
    return left.rows();
  }

  size_t cols() const
  {
    return left.cols();
  }

  size_t size() const
  {
    return left.rows() * left.cols();
  }
};
} // namespace internal
} // namespace schur
#endif //SCHUR_MATRIX_MULT_MAIN_HPP