#ifndef SCHUR_MATMUL_NXN_HPP_
#define SCHUR_MATMUL_NXN_HPP_

#include <cstddef>
#include "schur/matrix/mult/neon/MatMul_SpecificDims.hpp"

namespace schur { 
namespace internal {
void mmNNxCM(const float* __restrict__ a, 
             const float* __restrict__ b, 
                   float* __restrict__ c,
             const size_t M,
             const size_t N,
             const size_t K) {
  size_t M8 = M & ~size_t(7);
  size_t N4 = N & ~size_t(3);
  const size_t mr = M - M8;
  const size_t nr = N - N4;

  for(size_t i{0}; i < M8; i+=8) {
    for(size_t j{0}; j < N4; j+=4) {
      mm84x(a+i, 
            b+j*K, 
            c+i+j*M,
            M, K, M, K);
    }
    switch(nr) {
      case 1: { mm8Nx<1>(a+i, b+N4*K, c+i+N4*M, M, K, M, K); break; };
      case 2: { mm8Nx<2>(a+i, b+N4*K, c+i+N4*M, M, K, M, K); break; };
      case 3: { mm8Nx<3>(a+i, b+N4*K, c+i+N4*M, M, K, M, K); break; };
    }
  }

  if(mr) {
    for(size_t j{0}; j < N4; j+=4) {
      switch(mr) {
        case 1: { mmN4x<1>(a + M8, b + j*K, c + M8 + j*M, M, K, M, K); break; };
        case 2: { mmN4x<2>(a + M8, b + j*K, c + M8 + j*M, M, K, M, K); break; };
        case 3: { mmN4x<3>(a + M8, b + j*K, c + M8 + j*M, M, K, M, K); break; };
        case 4: { mmN4x<4>(a + M8, b + j*K, c + M8 + j*M, M, K, M, K); break; };
        case 5: { mmN4x<5>(a + M8, b + j*K, c + M8 + j*M, M, K, M, K); break; };
        case 6: { mmN4x<6>(a + M8, b + j*K, c + M8 + j*M, M, K, M, K); break; };
        case 7: { mmN4x<7>(a + M8, b + j*K, c + M8 + j*M, M, K, M, K); break; };
      }
    }
  }

  // cleanup, guaranteed to be 7x3 or less
  for (size_t j = N4; j < N; ++j) {
    for (size_t i = M8; i < M; ++i) {
      float sum = 0.0f;
      for (size_t k = 0; k < K; ++k) {
        sum += a[i + k*M] * b[k + j*K];
      }
      c[i + j*M] = sum;
    }
  }
}
} // namespace internal 
} // namespace schur
#endif // SCHUR_MATMUL_NXN_HPP_
