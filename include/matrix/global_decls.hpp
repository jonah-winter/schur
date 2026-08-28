#ifndef GLOBAL_DECLS_H_
#define GLOBAL_DECLS_H_

#include <cstddef>

namespace matrix {
using index_t = std::ptrdiff_t;

static constexpr index_t Dynamic = -1;

namespace internal {
// TODO: Eventually expand to complex numbers
template<typename T>
struct is_valid_storage_type : std::false_type {};

template<typename T>
requires(std::is_arithmetic_v<T>)
struct is_valid_storage_type<T> : std::true_type {};

template<typename T>
inline constexpr bool is_valid_storage_type_v = is_valid_storage_type<T>::value;

template<typename T>
concept storage_t = is_valid_storage_type_v<T>;
} // namespace internal
} // namespace matrix

#endif