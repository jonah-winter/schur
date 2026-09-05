#ifndef SCHUR_FORWARD_HPP
#define SCHUR_FORWARD_HPP

#include <schur/core/Types.hpp>

namespace schur {
template <typename T, index_t Rows, index_t Cols, Layout L>
struct Matrix;
namespace internal {
template <typename L, typename R>
requires(MatrixExpr<std::remove_cvref_t<L>> && MatrixExpr<std::remove_cvref_t<R>>
      && SameDims<std::remove_cvref_t<L>, std::remove_cvref_t<R>>
      && std::same_as<typename std::remove_cvref_t<L>::val_t, typename std::remove_cvref_t<R>::val_t>)
struct AddView;

template <typename T, Layout L>
struct BlockView;
} // namespace internal
} // namespace schur

#endif //SCHUR_FORWARD_HPP
