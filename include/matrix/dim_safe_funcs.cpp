#ifndef SCHUR_DIM_FUNCS_H
#define SCHUR_DIM_FUNCS_H

#include <matrix/dimensions_decl_internal.hpp>
#include <matrix/generic_dim_funcs.hpp>
#include <matrix/global_decls.hpp>

namespace matrix {
namespace internal {
enum class ValidDimStates_ {
  INVALID_DIMS = 0,
  STATIC_R_STATIC_C = 1,
  DYNAMIC_R_DYNAMIC_C = 2,
  DYNAMIC_R_STATIC_C = 3,
  STATIC_R_DYNAMIC_C = 4
};
} // namespace internal

constexpr internal::ValidDimStates_ valid_dims_specific_(index_t r, index_t c) {
  using V = internal::ValidDimStates_;
  if (r >= 0 && c >= 0) return V::STATIC_R_STATIC_C;
  if (r == Dynamic && c == Dynamic) return V::DYNAMIC_R_DYNAMIC_C;
  if (r == Dynamic && c >= 0) return V::DYNAMIC_R_STATIC_C;
  if (r >= 0 && c == Dynamic) return V::STATIC_R_DYNAMIC_C;
  return V::INVALID_DIMS;
}

template <index_t Rows, index_t Cols>
  requires(internal::valid_dims_(Rows, Cols))
bool internal::Dimensions<Rows, Cols>::valid_dims_overflow() const {
  if (SIZE_MAX / Rows > Cols) return true;
  return false;
}

bool internal::Dimensions<Dynamic, Dynamic>::valid_dims_overflow() const {
  if (SIZE_MAX / rows_ > cols_) return true;
  return false;
}

template <index_t Rows>
  requires(internal::valid_dim_(Rows))
bool internal::Dimensions<Rows, Dynamic>::valid_dims_overflow() const {
  if (SIZE_MAX / Rows > cols_) return true;
  return false;
}

template <index_t Cols>
  requires(internal::valid_dim_(Cols))
bool internal::Dimensions<Dynamic, Cols>::valid_dims_overflow() const {
  if (SIZE_MAX / rows_ > Cols) return true;
  return false;
}

inline size_t get_dims_(index_t r, index_t c) {
  if (!internal::valid_dims_(r, c))
    std::__throw_logic_error(
        "invalid rows and cols, either less than 0 or overflow");
  return r * c;
}
} // namespace matrix

#endif // SCHUR_DIM_FUNCS_H
