#ifndef STORAGE_UNSAFE_FUNCS_CPP
#define STORAGE_UNSAFE_FUNCS_CPP

#include <schur/Generic_GlobalDeclarations.hpp>
#include <schur/storage/Storage_DeclarationInternal.hpp>

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
} // namespace Matrix
} // namespace Matrix

#endif // STORAGE_UNSAFE_FUNCS_CPP
