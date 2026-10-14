#ifndef SCHUR_MATRIX_TRAITS_HPP_
#define SCHUR_MATRIX_TRAITS_HPP_

#include "schur/core/Types.hpp"

namespace schur {
namespace internal {
template<typename T>
struct matrix_expr_traits {};

template<msize_t R, msize_t C, typename T, Layout L>
struct matrix_expr_traits<Matrix<R, C, T, L>> 
{
  static constexpr bool contiguous = true;
  static constexpr Layout layout = L;
  using Scalar = T;

  static const T* data(const auto& x) noexcept { return x.data(); }
  static size_t rows(const auto& x) noexcept { return x.rows(); }
  static size_t cols(const auto& x) noexcept { return x.cols(); }
};

template<typename L, typename R>
struct matrix_expr_traits<AddView<L, R>>
{
  static constexpr bool contiguous = false;
  static constexpr Layout layout = L;
  static size_t rows(const auto& x) noexcept { return x.rows(); }
  static size_t cols(const auto& x) noexcept { return x.cols(); }
};
}
} // namespace schur

#endif // SCHUR_MATRIX_TRAITS_HPP_
