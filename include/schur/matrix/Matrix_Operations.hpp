#ifndef SCHUR_MATRIX_OPERATIONS_HPP
#define SCHUR_MATRIX_OPERATIONS_HPP

#include <schur/core/Concepts.hpp>
#include <schur/matrix/Matrix_MainClass.hpp>

namespace schur {
// TODO: make this not be a member function
template <typename T, index_t Rows, index_t Cols, Layout L>
BlockView<T, L> Matrix<T, Rows, Cols, L>::block(size_t start_rows, size_t start_cols, size_t rows, size_t cols)
{
  return BlockView<T, L>(this, start_rows, start_cols, rows, cols);
}

template <typename L, typename R>
requires(
  internal::MatrixExpr<std::remove_cvref_t<L>> &&
  internal::MatrixExpr<std::remove_cvref_t<R>>
  )
auto operator+(L&& lhs, R&& rhs) -> internal::AddView<internal::operand_t<L>, internal::operand_t<R>>
{
  return internal::AddView<
    internal::operand_t<L>,
    internal::operand_t<R>>(
      std::forward<L>(lhs),
      std::forward<R>(rhs)
      );
}
} // namespace schur
#endif //SCHUR_MATRIX_OPERATIONS_HPP