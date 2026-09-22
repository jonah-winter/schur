#ifndef SCHUR_RANGE_HPP
#define SCHUR_RANGE_HPP

#include <utility>
#include <vector>
#include <ostream>

namespace schur {
namespace internal {
template <size_t _Start, size_t _Stop, size_t _Step>
requires(_Stop >= _Start)
class _IndexSequence
{
  template <size_t... Is>
  static constexpr auto _CustomIndexSequence_impl(std::index_sequence<Is...>)
  {
    return std::integer_sequence<size_t, (_Start + _Step * Is)...>{};
  }

public:
  static constexpr auto make_custom_index_sequence()
  {
    return _CustomIndexSequence_impl(std::make_index_sequence<(_Stop - _Start + _Step - 1) / _Step>{});
  }
};

template <size_t _Start, size_t _Stop, size_t _Step>
requires(_Stop >= _Start)
class _PrivateRangeType
{
public:
  static constexpr size_t N = (_Stop - _Start + _Step - 1) / _Step;
private:
  template <size_t... _Is>
  constexpr auto _ToArray_impl(std::index_sequence<_Is...>)
  {
    return std::array<size_t, sizeof...(_Is)>{ _Is... };
  }

  template <size_t _Length>
  constexpr auto make_range()
  {
    return _ToArray_impl(_IndexSequence<_Start, _Stop, _Step>::make_custom_index_sequence());
  }
public:
  std::array<size_t, N> list = make_range<N>();
  consteval _PrivateRangeType() {}
  template <typename T>
  requires(std::is_arithmetic_v<T>)
  constexpr operator std::vector<T>() const
  {
    std::vector<T> _vec;
    for (int i{0}; i < list.size(); i++) {
      _vec.push_back(list[i]);
    }
    return _vec;
  }

  template <typename T>
  requires(std::is_arithmetic_v<T>)
  constexpr operator std::array<T, N>() const { return list; }

  constexpr size_t* begin() { return list.data(); }
  constexpr size_t* end() { return list.data() + N; }
  constexpr const size_t* begin() const { return list.data(); }
  constexpr const size_t* end() const { return list.data() + N; }
  constexpr size_t size() const { return N; }
};

template <size_t _Start, size_t _Stop, size_t _Step>
requires(_Stop >= _Start)
class range_impl
{
public:
  static constexpr size_t N = (_Stop - _Start + _Step - 1) / _Step;
private:
  _PrivateRangeType<_Start, _Stop, _Step> internalRange;
public:
  consteval range_impl() {}

  template <typename T>
  requires(std::is_arithmetic_v<T>)
  constexpr operator std::vector<T>() const
  { return static_cast<std::vector<T>>(internalRange); }

  template <typename T>
  requires(std::is_arithmetic_v<T>)
  constexpr operator std::array<T, N>() const { return internalRange.list; }

  constexpr size_t* begin() { return internalRange.list.data(); }
  constexpr size_t* end() { return internalRange.list.data() + N; }
  constexpr const size_t* begin() const { return internalRange.list.data(); }
  constexpr const size_t* end() const { return internalRange.list.data() + N; }
  constexpr size_t size() const { return N; }
  constexpr size_t operator[](size_t i) { return internalRange.list.data()[i]; }
  constexpr const size_t operator[](size_t i) const { return internalRange.list.data()[i]; }
  friend std::ostream& operator<<(std::ostream& os, const range_impl& r) {
    os << '[';
    for (size_t i{0}; i < N; i++) {
      os << r[i];
      if (i + 1 < N) { os << ", "; }
    }
    os << ']';
    return os;
  }
};

template <size_t _Arg1, size_t... _Arg2>
struct range_dispatch;

template <size_t _Stop>
struct range_dispatch<_Stop> { using type = range_impl<0, _Stop, 1>; };

template <size_t _Start, size_t _Stop>
struct range_dispatch<_Start, _Stop> { using type = range_impl<_Start, _Stop, 1>; };

template <size_t _Start, size_t _Stop, size_t _Step>
struct range_dispatch<_Start, _Stop, _Step> { using type = range_impl<_Start, _Stop, _Step>; };
} // namespace internal

template <size_t... _Args>
using range = internal::range_dispatch<_Args...>::type;
} // namespace schur
#endif //SCHUR_RANGE_HPP