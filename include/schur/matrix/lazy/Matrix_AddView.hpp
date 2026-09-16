#ifndef SCHUR_MATRIX_ADDVIEW_HPP
#define SCHUR_MATRIX_ADDVIEW_HPP

#include "schur/matrix/Matrix_BaseClass.hpp"
#include "schur/core/Concepts.hpp"

namespace schur {
namespace internal {
template <MatrixExpr L, MatrixExpr R>
requires(
      SameDims<std::remove_cvref_t<L>, std::remove_cvref_t<R>>
      && std::same_as<typename std::remove_cvref_t<L>::val_t, typename std::remove_cvref_t<R>::val_t>)
struct AddView : MatrixBase
  <
    AddView<L, R>,
    typename std::remove_cvref_t<L>::val_t,
    get_rows<L>,
    get_cols<L>
  >
{
  using left_t  = operand_t<L>;
  using right_t = operand_t<R>;
  using val_t   = typename std::remove_cvref_t<L>::val_t;
  using dims_t  = typename std::remove_cvref_t<L>::dims_t;

  left_t left;
  right_t right;

  AddView(L&& l, R&& r) : left(std::forward<L>(l)), right(std::forward<R>(r)) {}

  auto operator[](this auto&& self, index_t r, index_t c) {
    return self.left[r, c] + self.right[r, c];
  }

  size_t rows() const
  {
    return left.rows();
  }

  size_t cols() const
  {
    return left.cols();
  }
};
} // namespace schur
} // namespace internal
#endif //SCHUR_MATRIX_ADDVIEW_HPP