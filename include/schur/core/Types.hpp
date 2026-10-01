#ifndef SCHUR_TYPES_HPP_
#define SCHUR_TYPES_HPP_

#include <cstddef>
#include <cstdint>

namespace schur {
#if SCHUR_FREESTANDING == 0
using index_t = std::ptrdiff_t;
using msize_t = std::int32_t;
using size_t  = std::size_t;
#else
using index_t = ptrdiff_t;
using msize_t = int32_t;
#endif

static constexpr msize_t Dynamic = -1;

namespace internal {
struct MatrixExprTag {};

struct MainMatrixTag {};

struct NonMainMatrixTag {};
}

enum class Layout {
  ColMajor = 0,
  RowMajor = 1
};
} // namespace schur
#endif //SCHUR_TYPES_HPP_
