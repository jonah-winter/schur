#ifndef SCHUR_DIM_FUNCS_H
#define SCHUR_DIM_FUNCS_H

#include <matrix/global_decls.h>

namespace matrix {
namespace internal {
enum class ValidDimStates_
{
  INVALID_DIMS=0,
  STATIC_R_STATIC_C=1,
  DYNAMIC_R_DYNAMIC_C=2,
  DYNAMIC_R_STATIC_C=3,
  STATIC_R_DYNAMIC_C=4
};
}

constexpr internal::ValidDimStates_ valid_dims_specific_(index_t r, index_t c)
{
  using V = internal::ValidDimStates_;
  if (r >= 0 && c >= 0) return V::STATIC_R_STATIC_C;
  if (r == Dynamic && c == Dynamic) return V::DYNAMIC_R_DYNAMIC_C;
  if (r == Dynamic && c >= 0) return V::DYNAMIC_R_STATIC_C;
  if (r >= 0 && c == Dynamic) return V::STATIC_R_DYNAMIC_C;
  return V::INVALID_DIMS;
}

constexpr bool alloc_overflow_(index_t r, index_t c)
{
  return valid_dims_specific_(r, c) == internal::ValidDimStates_::STATIC_R_STATIC_C
         && SIZE_MAX / static_cast<size_t>(r) >= static_cast<size_t>(c);
}

inline size_t get_dims_(index_t r, index_t c)
{
  if (!valid_dims_(r, c)) std::__throw_logic_error("invalid rows and cols, either less than 1 or overflow");
  return r * c;
}
}

#endif //SCHUR_DIM_FUNCS_H