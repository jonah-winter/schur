#ifndef SCHUR_GENERIC_DIM_FUNCS_HPP_
#define SCHUR_GENERIC_DIM_FUNCS_HPP_

#include <cstdint>
#include <matrix/global_decls.hpp>

namespace matrix {
namespace internal {
constexpr bool valid_dims_(index_t r, index_t c) {
  if (r >= 0 && c >= 0) return true;
  if (r == Dynamic && c == Dynamic) return true;
  if (r == Dynamic && c >= 0) return true;
  if (r >= 0 && c == Dynamic) return true;
  return false;
}

constexpr bool valid_dim_(index_t dim) {
  return (dim >= 0 && dim <= SIZE_MAX) || dim == Dynamic;
}
} // namespace internal
} // namespace matrix

#endif // SCHUR_GENERIC_DIM_FUNCS_HPP_
