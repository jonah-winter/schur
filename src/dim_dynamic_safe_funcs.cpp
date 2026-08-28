//
// Created by Jonah Winter on 8/28/26.
//

#ifndef SCHUR_DIM_DYNAMIC_SAFE_FUNCS_H
#define SCHUR_DIM_DYNAMIC_SAFE_FUNCS_H
#include <matrix/dim_safe_funcs.hpp>

namespace matrix {
namespace internal {
bool Dimensions<Dynamic, Dynamic>::valid_dims_overflow() const {
  if (SIZE_MAX / rows_ > cols_) return true;
  return false;
}
}
}

#endif //SCHUR_DIM_DYNAMIC_SAFE_FUNCS_H
