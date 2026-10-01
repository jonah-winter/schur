#ifndef SCHUR_FIXED_HPP
#define SCHUR_FIXED_HPP

#include "schur/core/Types.hpp"

namespace schur {
namespace internal {
template<typename T, size_t N>
struct FixedStorage {
private:
  T data_[N]{};
public:
  constexpr FixedStorage() = default;
  constexpr FixedStorage(const size_t n) {}
  constexpr auto& operator[](this auto&& self, index_t i) { return self.data_[i]; }
  constexpr auto* data(this auto&& self)  { return self.data_; }
  constexpr auto* begin(this auto&& self)  { return self.data_; }
  constexpr auto* end(this auto&& self)   { return self.data_ + N; }
  constexpr size_t size() const     { return N; }
  constexpr size_t capacity() const { return N; }
};
} // namespace internal
} // namespace schur

#endif //SCHUR_FIXED_HPP