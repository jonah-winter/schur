#ifndef SCHUR_MATRIX_MULT_ALGO_HPP_
#define SCHUR_MATRIX_MULT_ALGO_HPP_

#include <arm_neon.h>
#include "schur/core/Types.hpp"

namespace schur {
namespace internal {
inline void mm88x(float* a, float* b, float* c, 
                  float ar, float ac, 
                  float br, float bc, 
                  const Layout l) {

}
} // namespace internal
} // namespace schur
#endif // SCHUR_MATRIX_MULT_ALGO_HPP_
