#ifndef SCHUR_NUMBERS_HPP
#define SCHUR_NUMBERS_HPP

#include <__stddef_size_t.h>
#include <utility>

namespace schur {
template <size_t... Size>
consteval long long PowerTen_impl_(std::index_sequence<Size...>)
{
  return (1ULL * ... * ((void)Size, 10));
}

template <size_t Size>
consteval long long power10()
{
  return PowerTen_impl_(std::make_index_sequence<Size>{});
}

template <size_t Digits>
requires(Digits <= 16)
consteval long double round_pi()
{
  constexpr long double pi_temp = 3.141592653589793L;
  constexpr long double factor = power10<Digits>();
  constexpr long double scaled = pi_temp * factor;
  constexpr long double rounded_scaled = static_cast<long long>(scaled + 0.5L);
  return rounded_scaled / factor;
}

template <size_t N, typename T = double>
requires(N <= 16)
inline constinit T pi_specific = round_pi<N>();

inline constinit double pi = round_pi<16>();
} // namespace schur
#endif //SCHUR_NUMBERS_HPP
