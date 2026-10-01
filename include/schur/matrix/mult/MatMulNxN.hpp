#ifndef SCHUR_MATMUL_NXN_HPP_
#define SCHUR_MATMUL_NXN_HPP_

#include <cstddef>
#if defined(__APPLE__)
#  if defined(__aarch64__)
#    include "schur/matrix/lazy/mult/neon/MatMul_SpecificDims.hpp"
#  elif
#  endif // defined(__aarch64__)
#endif // defined(__APPLE__)

namespace schur { 
namespace internal {
void mmNNx(const float* __restrict__ a, 
           const float* __restrict__ b, 
                 float* __restrict__ c,
           const size_t M,
           const size_t N,
           const size_t K) {
  for(size_t i{0}; i < M; i++) {
    
  }
}
} // namespace internal 
} // namespace schur
#endif // SCHUR_MATMUL_NXN_HPP_
