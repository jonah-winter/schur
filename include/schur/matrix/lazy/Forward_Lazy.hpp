#ifndef SCHUR_FORWARD_HPP_
#define SCHUR_FORWARD_HPP_

#include "schur/core/Types.hpp"

namespace schur {
template <msize_t Rows, msize_t Cols, typename Scalar, Layout L>
struct Matrix;
namespace internal {
template <MatrixExpr L, MatrixExpr R>
requires(SameDims<std::remove_cvref_t<L>, std::remove_cvref_t<R>>
      && std::same_as<typename std::remove_cvref_t<L>::val_t, typename std::remove_cvref_t<R>::val_t>
      && std::same_as<typename std::remove_cvref_t<L>::layout(), typename std::remove_cvref_t<R>::layout()>)
struct AddView;

template <MatrixExpr L, MatrixExpr R>
requires(SameDims<std::remove_cvref_t<L>, std::remove_cvref_t<R>>
      && std::same_as<typename std::remove_cvref_t<L>::val_t, typename std::remove_cvref_t<R>::val_t>
      && std::same_as<typename std::remove_cvref_t<L>::layout(), typename std::remove_cvref_t<R>::layout()>)
struct SubtView;

template <typename Scalar, Layout L>
struct BlockView;

template <MatrixExpr D>
struct Transposed;

template <MatrixExpr L, MatrixExpr R>
requires((get_cols<L> == Dynamic || get_cols<L> == get_rows<R>)
      && (get_rows<R> == Dynamic || get_cols<L> == get_rows<R>)
      && std::same_as<typename std::remove_cvref_t<L>::val_t, typename std::remove_cvref_t<R>::val_t>
      && std::same_as<typename std::remove_cvref_t<L>::layout(), typename std::remove_cvref_t<R>::layout()>)
struct Mult;
} // namespace internal
} // namespace schur

#endif //SCHUR_FORWARD_HPP_
