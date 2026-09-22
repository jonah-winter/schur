#ifndef SCHUR_NUMBERS_HPP
#define SCHUR_NUMBERS_HPP

#include <__stddef_size_t.h>
#include <utility>

namespace schur {
template <size_t... _Size>
constexpr long long _PowerTen_impl(std::index_sequence<_Size...>)
{
  return (1ULL * ... * (_Size, 10));
}

template <size_t _Size>
constexpr long long power10()
{
  return _PowerTen_impl(std::make_index_sequence<_Size>{});
}

template <size_t _Digits>
constexpr long double round_pi()
{
  constexpr long double pi_temp = 3.141592653589793L;
  constexpr long double factor = power10<_Digits>();
  constexpr long double scaled = pi_temp * factor;
  constexpr long double rounded_scaled = static_cast<long long>(scaled + 0.5L);
  return rounded_scaled / factor;
}

template <size_t N = 16, typename T = double>
requires(N <= 16)
inline constexpr T pi = round_pi<N>();
} // namespace schur
#endif //SCHUR_NUMBERS_HPP