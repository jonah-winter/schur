#ifndef SCHUR_TRAITS_HPP
#define SCHUR_TRAITS_HPP

#include <schur/core/Types.hpp>
#include <type_traits>

namespace schur {
namespace internal {
// TODO: Eventually expand to complex numbers
template <typename T>
struct is_valid_storage_type : std::false_type {};

template <typename T>
requires(std::is_arithmetic_v<T>)
struct is_valid_storage_type<T> : std::true_type {};

template <typename T>
inline constexpr bool is_valid_storage_type_v = is_valid_storage_type<T>::value;

// forward declaration for is_matrix
template <typename T, index_t Rows, index_t Cols, Layout L>
struct Matrix;

// is_matrix_impl preserves const
template <typename M>
struct is_matrix_impl : std::false_type {};

template <typename T, index_t Rows, index_t Cols, Layout L>
struct is_matrix_impl<Matrix<T, Rows, Cols, L>> : std::true_type {};

// just checks if its a matrix
template <typename M>
struct is_matrix : is_matrix<std::remove_cv_t<M>> {};

template <typename M>
inline constexpr bool is_matrix_v = is_matrix<M>::value;
}
} // namespace schur
#endif //SCHUR_TRAITS_HPP
