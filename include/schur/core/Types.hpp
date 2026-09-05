#ifndef SCHUR_TYPES_HPP
#define SCHUR_TYPES_HPP

#include <cstddef>

namespace schur {
using index_t = std::ptrdiff_t;

static constexpr index_t Dynamic = -1;

enum class Layout
{
  ColMajor = 0,
  RowMajor = 1
};
} // namespace schur
#endif //SCHUR_TYPES_HPP
