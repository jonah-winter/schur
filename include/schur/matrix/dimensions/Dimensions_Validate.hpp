#ifndef SCHUR_DIM_SAFE_FUNCS_HPP_
#define SCHUR_DIM_SAFE_FUNCS_HPP_

#include "schur/core/Types.hpp"
#include "schur/matrix/dimensions/Generic_DimFuncs.hpp"
#include "schur/matrix/dimensions/Dimensions_DeclarationInternal.hpp"

namespace schur {
namespace internal {
enum class _ValidDimStates {
  INVALID_DIMS = 0,
  STATIC_R_STATIC_C = 1,
  DYNAMIC_R_DYNAMIC_C = 2,
  DYNAMIC_R_STATIC_C = 3,
  STATIC_R_DYNAMIC_C = 4
};
} // namespace internal

constexpr internal::_ValidDimStates valid_dims_specific(index_t r, index_t c) {
  using V = internal::_ValidDimStates;
  if (r >= 0 && c >= 0) return V::STATIC_R_STATIC_C;
  if (r == Dynamic && c == Dynamic) return V::DYNAMIC_R_DYNAMIC_C;
  if (r == Dynamic && c >= 0) return V::DYNAMIC_R_STATIC_C;
  if (r >= 0 && c == Dynamic) return V::STATIC_R_DYNAMIC_C;
  return V::INVALID_DIMS;
}

template <index_t _Rows, index_t _Cols>
  requires(internal::valid_dims(_Rows, _Cols))
bool internal::Dimensions<_Rows, _Cols>::valid_dims_overflow() const {
  if (_Rows == 0 || _Cols <= SIZE_MAX / _Rows) return true;
  return false;
}

template <index_t _Rows>
  requires(internal::valid_dim(_Rows))
bool internal::Dimensions<_Rows, Dynamic>::valid_dims_overflow() const {
  if (_Rows == 0 || cols_ <= SIZE_MAX / _Rows) return true;
  return false;
}

template <index_t _Cols>
  requires(internal::valid_dim(_Cols))
bool internal::Dimensions<Dynamic, _Cols>::valid_dims_overflow() const {
  if (rows_ == 0 || _Cols <= SIZE_MAX / rows_) return true;
  return false;
}

inline size_t calculate_dims(index_t r, index_t c) {
  if (!internal::valid_dims(r, c)) {
    throw std::logic_error("invalid rows and cols, either less than 0 or overflow");
  }
  return r * c;
}
} // namespace schur
#endif // SCHUR_DIM_SAFE_FUNCS_HPP_