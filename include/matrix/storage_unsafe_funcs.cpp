#ifndef STORAGE_UNSAFE_FUNCS_CPP_
#define STORAGE_UNSAFE_FUNCS_CPP_

#include <matrix/global_decls.hpp>
#include <matrix/storage_decl_internal.hpp>

namespace matrix {
namespace internal {
template <storage_t T>
T& Storage<T>::operator[](size_t i) {
  return data_[i];
}

template <storage_t T>
const T& Storage<T>::operator[](size_t i) const {
  return data_[i];
}
}
}

#endif // STORAGE_UNSAFE_FUNCS_CPP_
