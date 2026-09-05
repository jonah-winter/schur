#ifndef SCHUR_GENERIC_DIM_FUNCS_HPP
#define SCHUR_GENERIC_DIM_FUNCS_HPP

#include <cstdint>
#include <initializer_list>
#include <schur/core/Types.hpp>

namespace schur {
namespace internal {
constexpr bool valid_dims_(index_t r, index_t c) {
  if (r >= 0 && c >= 0) return true;
  if (r == Dynamic && c == Dynamic) return true;
  if (r == Dynamic && c >= 0) return true;
  if (r >= 0 && c == Dynamic) return true;
  return false;
}

template <typename Container>
index_t validate_list_cols(Container& list)
{
  if (list.size()) {
    return list.begin()->size();
  }
  return 0;
}

template <typename T>
index_t validate_list_cols(std::initializer_list<std::initializer_list<T>> list)
{
  if (list.size()) {
    return list.begin()->size();
  }
  return 0;
}

constexpr bool valid_dim_(index_t dim) {
  return (dim >= 0 && dim <= SIZE_MAX) || dim == Dynamic;
}

constexpr auto construct_rows(index_t rows, size_t r)
{
  return ((rows == -1) ? r : rows);
}

constexpr auto construct_cols(index_t cols, size_t c)
{
  return ((cols == -1) ? c : cols);
}
} // namespace internal
} // namespace Matrix

#endif // SCHUR_GENERIC_DIM_FUNCS_HPP
