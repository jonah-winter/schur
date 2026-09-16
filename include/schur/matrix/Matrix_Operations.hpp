#ifndef SCHUR_MATRIX_OPERATIONS_HPP
#define SCHUR_MATRIX_OPERATIONS_HPP

#include <schur/core/Concepts.hpp>
#include <schur/matrix/Matrix_MainClass.hpp>

namespace schur {
// template <typename T, index_t Rows, index_t Cols, Layout L>
// BlockView<T, L> Matrix<T, Rows, Cols, L>::block(size_t start_rows, size_t start_cols, size_t rows, size_t cols)
// {
//   return BlockView<T, L>(this, start_rows, start_cols, rows, cols);
// }
template <internal::MatrixExpr D>
[[nodiscard]] auto block(D&& d, size_t start_rows, size_t start_cols, size_t rows, size_t cols) -> BlockView<typename std::remove_cvref_t<D>::val_t, d.layout()>
{
  return BlockView<typename std::remove_cvref_t<D>::val_t, d.layout()>(&d, start_rows, start_cols, rows, cols);
}

template <internal::MatrixExpr L, internal::MatrixExpr R>
[[nodiscard]] auto operator+(L&& lhs, R&& rhs) -> internal::AddView<internal::operand_t<L>, internal::operand_t<R>>
{
  return internal::AddView<
    internal::operand_t<L>,
    internal::operand_t<R>
    >(
      std::forward<L>(lhs),
      std::forward<R>(rhs)
      );
}

template <internal::MatrixExpr L, internal::MatrixExpr R>
[[nodiscard]] auto operator-(L&& lhs, R&& rhs) -> internal::SubtView<internal::operand_t<L>, internal::operand_t<R>>
{
  return internal::SubtView<
    internal::operand_t<L>,
    internal::operand_t<R>
    >(
      std::forward<L>(lhs),
      std::forward<R>(rhs)
      );
}

template <internal::MatrixExpr D>
[[nodiscard]] auto transpose(D&& d) -> internal::Transposed<internal::operand_t<D>>
{
  return internal::Transposed<
    internal::operand_t<D>
    >(
      std::forward<D>(d)
    );
}

template <internal::MatrixExpr L, internal::MatrixExpr R>
[[nodiscard]] auto operator*(L&& lhs, R&& rhs) -> internal::Mult<internal::operand_t<L>, internal::operand_t<R>>
{
  return internal::Mult<
    internal::operand_t<L>,
    internal::operand_t<R>
    >(
      std::forward<L>(lhs),
      std::forward<R>(rhs)
    );
}
} // namespace schur
#endif //SCHUR_MATRIX_OPERATIONS_HPP