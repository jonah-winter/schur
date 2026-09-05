#ifndef SCHUR_CONCEPTS_HPP
#define SCHUR_CONCEPTS_HPP

#include <schur/core/Types.hpp>
#include <schur/core/Traits.hpp>

namespace schur {
namespace internal {
template <typename T>
concept storage_t = is_valid_storage_type_v<T>;

// MatrixExpr is any type derived from MatrixBase, MatrixType is specifically the main matrix type
template <typename M>
concept MatrixExpr = requires { typename M::matrix_expr_tag; };

template <typename M>
concept MatrixType = is_matrix<std::remove_cvref_t<M>>::value;

template <typename M>
struct operand_storage
{
  using type = M;
};

template <typename M>
struct operand_storage<M&>
{
  using type = M&;
};

template <typename M>
struct operand_storage<M&&>
{
  using type = M;
};

template <typename M>
using operand_t = typename operand_storage<M>::type;

template <typename M>
inline constexpr index_t get_rows = std::remove_cvref_t<M>::dims_t::static_rows;

template <typename M>
inline constexpr index_t get_cols = std::remove_cvref_t<M>::dims_t::static_cols;

template <typename L, typename R>
concept SameDims =
     (get_rows<L> == Dynamic
  ||  get_rows<R> == Dynamic
  ||  get_rows<L> == get_rows<R>)
  &&
     (get_cols<L> == Dynamic
  ||  get_cols<R> == Dynamic
  ||  get_cols<L> == get_cols<R>);
} // namespace internal
} // namespace schur
#endif //SCHUR_CONCEPTS_HPP
