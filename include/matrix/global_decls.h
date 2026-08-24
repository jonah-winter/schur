#ifndef GLOBAL_DECLS_H_
#define GLOBAL_DECLS_H_

#include <cstddef>

namespace matrix {

static constexpr size_t Dynamic = static_cast<size_t>(-1);

namespace internal {
struct uninitialized_t {
  constexpr uninitialized_t() noexcept = default;
};

static constexpr uninitialized_t uninit{};
} // namespace internal
} // namespace matrix

#endif
