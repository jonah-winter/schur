#ifndef SCHUR_DIM_DYNAMIC_SAFE_FUNCS
#define SCHUR_DIM_DYNAMIC_SAFE_FUNCS
#include <schur/dimensions/dim_safe_funcs.hpp>

namespace schur {
namespace internal {
bool Dimensions<Dynamic, Dynamic>::valid_dims_overflow() const {
  if (SIZE_MAX / rows_ > cols_) return true;
  return false;
}
}
}

#endif //SCHUR_DIM_DYNAMIC_SAFE_FUNCS