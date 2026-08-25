#ifndef GLOBAL_DECLS_H_
#define GLOBAL_DECLS_H_

#include <cstddef>

namespace matrix {
using index_t = std::ptrdiff_t;

static constexpr index_t Dynamic = -1;

namespace internal {
// cannot be in dimensions struct because its used as a requirement
constexpr bool valid_dims_(index_t r, index_t c)
{
  if (r >= 0 && c >= 0) return true;
  if (r == Dynamic && c == Dynamic) return true;
  if (r == Dynamic && c >= 0) return true;
  if (r >= 0 && c == Dynamic) return true;
  return false;
}
constexpr bool valid_dim_(index_t dim)
{
  return (dim >= 0 && dim <= SIZE_MAX) || dim == Dynamic;
}
} // namespace internal
} // namespace matrix

#endif
