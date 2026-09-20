#ifndef STORAGE_UNSAFE_FUNCS_HPP_
#define STORAGE_UNSAFE_FUNCS_HPP_

#include "schur/matrix/storage/Storage_DeclarationInternal.hpp"

namespace schur {
namespace internal {
template <storage_t T>
auto& Storage<T>::operator[](this auto&& self, index_t i) {
  return self.data_[i];
}

template <storage_t T>
auto& Storage<T>::data(this auto&& self)
{
  return self.data_;
}
} // namespace internal
} // namespace schur

#endif // STORAGE_UNSAFE_FUNCS_HPP_
