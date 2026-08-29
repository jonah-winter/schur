#ifndef STORAGE_UNSAFE_FUNCS
#define STORAGE_UNSAFE_FUNCS

#include <schur/matrix/global_decls.hpp>
#include <schur/storage/storage_decl_internal.hpp>

namespace schur {
namespace internal {
template <storage_t T>
auto& Storage<T>::operator[](this auto&& self, size_t i) {
  return self.data_[i];
}
} // namespace matrix
} // namespace matrix

#endif // STORAGE_UNSAFE_FUNCS
