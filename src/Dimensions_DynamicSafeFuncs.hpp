#ifndef SCHUR_DIM_DYNAMIC_SAFE_FUNCS_CPP
#define SCHUR_DIM_DYNAMIC_SAFE_FUNCS_CPP

#include <schur/Generic_GlobalDeclarations.hpp>
#include <schur/dimensions/Dimensions_SafeFuncs.hpp>

namespace schur {
namespace internal {
inline bool Dimensions<Dynamic, Dynamic>::valid_dims_overflow() const {
  if (SIZE_MAX / rows_ > cols_) return true;
  return false;
}
}
}
#endif //SCHUR_DIM_DYNAMIC_SAFE_FUNCS_CPP