#ifndef SCHUR_MATMUL_NXN_HPP_
#define SCHUR_MATMUL_NXN_HPP_

#include <cstddef>
#include "schur/matrix/mult/apple/MM_Block84_NEON.hpp"

namespace schur { 
namespace internal {
inline void mmNNxCM_neon(const float* __restrict__ a, 
             const float* __restrict__ b, 
                   float* __restrict__ c,
             const size_t M,
             const size_t N,
             const size_t K) {
  if(M == 0 || N == 0) { return; }
  if(K == 0) [[unlikely]] {
    for(size_t j{0}; j < N; j++) {
      for(size_t i{0}; i < M; i++) {
        c[i+j*M] = 0.0f;
      }
    }
    return;
  }
  size_t M8 = M & ~size_t(7);
  size_t N4 = N & ~size_t(3);
  const size_t mr = M - M8;
  const size_t nr = N - N4;

  for(size_t i{0}; i < M8; i+=8) {
    for(size_t j{0}; j < N4; j+=4) {
      mm84x_neon(a+i, 
            b+j*K, 
            c+i+j*M,
            M, K, M, K);
    }
    switch(nr) {
      case 1: { mm8Nx_neon<1>(a+i, b+N4*K, c+i+N4*M, M, K, M, K); break; };
      case 2: { mm8Nx_neon<2>(a+i, b+N4*K, c+i+N4*M, M, K, M, K); break; };
      case 3: { mm8Nx_neon<3>(a+i, b+N4*K, c+i+N4*M, M, K, M, K); break; };
    }
  }

  switch(mr) {
    case 1: { 
      for(size_t j{0}; j < N4; j+=4) { 
        mmN4x_neon<1>(a + M8, 
                 b + j*K, 
                 c + M8 + j*M, 
                 M, K, M, K); 
      } break; 
    };
    case 2: { 
      for(size_t j{0}; j < N4; j+=4) {
        mmN4x_neon<2>(a + M8, 
                 b + j*K, 
                 c + M8 + j*M,
                 M, K, M, K); 
      } break; 
    };
    case 3: { 
      for(size_t j{0}; j < N4; j+=4) {
        mmN4x_neon<3>(a + M8, 
                 b + j*K, 
                 c + M8 + j*M,
                 M, K, M, K); 
      } break; 
    };
    case 4: { 
      for(size_t j{0}; j < N4; j+=4) {
        mmN4x_neon<4>(a + M8, 
                 b + j*K, 
                 c + M8 + j*M,
                 M, K, M, K); 
      } break; 
    };
    case 5: { 
      for(size_t j{0}; j < N4; j+=4) {
        mmN4x_neon<5>(a + M8, 
                 b + j*K, 
                 c + M8 + j*M,
                 M, K, M, K); 
      } break; 
    };
    case 6: { 
      for(size_t j{0}; j < N4; j+=4) {
        mmN4x_neon<6>(a + M8, 
                 b + j*K, 
                 c + M8 + j*M,
                 M, K, M, K); 
      } break; 
    };
    case 7: { 
      for(size_t j{0}; j < N4; j+=4) {
        mmN4x_neon<7>(a + M8, 
                 b + j*K, 
                 c + M8 + j*M,
                 M, K, M, K); 
      } break; 
    };
  }
  if(mr != 0 && nr != 0) { mmCornerx_neon(a, b, c, M, K, M, M8, N4, mr, nr); }
}
} // namespace internal 
} // namespace schur
#endif // SCHUR_MATMUL_NXN_HPP_
