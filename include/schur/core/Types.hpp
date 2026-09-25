#ifndef SCHUR_TYPES_HPP_
#define SCHUR_TYPES_HPP_

#include <cstddef>
#include <cstdint>

namespace schur {
using index_t = std::ptrdiff_t;
using msize_t = int32_t;
using size_t = std::size_t;

static constexpr msize_t Dynamic = -1;

namespace internal {
struct MatrixExprTag {};
struct MainMatrixTag {};
struct NonMainMatrixTag {};
}

enum class Layout
{
  ColMajor = 0,
  RowMajor = 1
};
} // namespace schur
#endif //SCHUR_TYPES_HPP_
