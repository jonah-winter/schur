#ifndef SCHUR_DIM_DYNAMIC_SAFE_FUNCS_CPP
#define SCHUR_DIM_DYNAMIC_SAFE_FUNCS_CPP

#include "schur/core/Types.hpp"
#include "schur/dimensions/Dimensions_DeclarationInternal.hpp"

namespace schur {
namespace internal {
inline bool Dimensions<Dynamic, Dynamic>::valid_dims_overflow() const {
  if (rows_ == 0 || cols_ <= SIZE_MAX / rows_) return true;
  return false;
}
} // namespace internal
} // namespace schur
#endif //SCHUR_DIM_DYNAMIC_SAFE_FUNCS_CPP
