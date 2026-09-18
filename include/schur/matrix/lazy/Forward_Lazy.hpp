#ifndef SCHUR_FORWARD_HPP
#define SCHUR_FORWARD_HPP

#include "schur/core/Types.hpp"

namespace schur {
template <typename T, index_t Rows, index_t Cols, Layout L>
struct Matrix;
namespace internal {
template <MatrixExpr L, MatrixExpr R>
requires(SameDims<std::remove_cvref_t<L>, std::remove_cvref_t<R>>
      && std::same_as<typename std::remove_cvref_t<L>::val_t, typename std::remove_cvref_t<R>::val_t>)
struct AddView;

template <MatrixExpr L, MatrixExpr R>
requires(SameDims<std::remove_cvref_t<L>, std::remove_cvref_t<R>>
      && std::same_as<typename std::remove_cvref_t<L>::val_t, typename std::remove_cvref_t<R>::val_t>)
struct SubtView;

template <typename T, Layout L>
struct BlockView;

template <MatrixExpr D>
struct Transposed;

template <MatrixExpr L, MatrixExpr R>
requires((get_cols<L> == Dynamic || get_cols<L> == get_rows<R>)
      && (get_rows<R> == Dynamic || get_cols<L> == get_rows<R>)
      && std::same_as<typename std::remove_cvref_t<L>::val_t, typename std::remove_cvref_t<R>::val_t>)
struct Mult;
} // namespace internal
} // namespace schur

#endif //SCHUR_FORWARD_HPP
