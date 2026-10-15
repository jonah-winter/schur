#ifndef SCHUR_MATRIX_MULT_ALGO_HPP_
#define SCHUR_MATRIX_MULT_ALGO_HPP_

#include <cstddef>
#include <arm_neon.h>

namespace schur {
namespace internal {
inline void mm84x_neon(const float* __restrict__ a, 
                  const float* __restrict__ b, 
                        float* __restrict__ c,
                        size_t lda,
                        size_t ldb,
                        size_t ldc,
                        size_t K) 
{
  float32x4_t c00 = vdupq_n_f32(0.0f);
  float32x4_t c01 = vdupq_n_f32(0.0f);
  float32x4_t c02 = vdupq_n_f32(0.0f);
  float32x4_t c03 = vdupq_n_f32(0.0f);

  float32x4_t c10 = vdupq_n_f32(0.0f);
  float32x4_t c11 = vdupq_n_f32(0.0f);
  float32x4_t c12 = vdupq_n_f32(0.0f);
  float32x4_t c13 = vdupq_n_f32(0.0f);

  for(size_t k{0}; k < K; k++) {
    const float32x4_t a0 = vld1q_f32(a+k*lda);
    const float32x4_t a1 = vld1q_f32(a+k*lda+4);

    c00 = vfmaq_n_f32(c00, a0, b[k]);
    c10 = vfmaq_n_f32(c10, a1, b[k]);

    c01 = vfmaq_n_f32(c01, a0, b[k+ldb]);
    c11 = vfmaq_n_f32(c11, a1, b[k+ldb]);

    c02 = vfmaq_n_f32(c02, a0, b[k+2*ldb]);
    c12 = vfmaq_n_f32(c12, a1, b[k+2*ldb]);

    c03 = vfmaq_n_f32(c03, a0, b[k+3*ldb]);
    c13 = vfmaq_n_f32(c13, a1, b[k+3*ldb]);
  }
  vst1q_f32(c, c00);
  vst1q_f32(c+4, c10);

  vst1q_f32(c+ldc, c01);
  vst1q_f32(c+ldc+4, c11);

  vst1q_f32(c+2*ldc, c02);
  vst1q_f32(c+2*ldc+4, c12);

  vst1q_f32(c+3*ldc, c03);
  vst1q_f32(c+3*ldc+4, c13);
}

template<size_t N>
requires(N >= 1 && N <= 3)
inline void mm8Nx_neon(const float* __restrict__ a,
                  const float* __restrict__ b,
                        float* __restrict__ c,
                        size_t lda,
                        size_t ldb,
                        size_t ldc,
                        size_t K)
{
  float32x4_t lo[N];
  float32x4_t hi[N];
  for(size_t i{0}; i < N; i++) {
    lo[i] = vdupq_n_f32(0.0f);
    hi[i] = vdupq_n_f32(0.0f);
  }
  for(size_t k{0}; k < K; k++) {
    const float32x4_t a0 = vld1q_f32(a+k*lda);
    const float32x4_t a1 = vld1q_f32(a+k*lda+4);
    for(size_t j{0}; j < N; j++) {
      lo[j] = vfmaq_n_f32(lo[j], a0, b[k+j*ldb]);
      hi[j] = vfmaq_n_f32(hi[j], a1, b[k+j*ldb]);
    }
  }
  for(size_t i{0}; i < N; i++) {
    vst1q_f32(c+i*ldc,   lo[i]);
    vst1q_f32(c+i*ldc+4, hi[i]);
  }
}

template<size_t N>
requires(N >= 1 && N <= 7)
inline void mmN4x_neon(const float* __restrict__ a,
                  const float* __restrict__ b,
                        float* __restrict__ c,
                        size_t lda,
                        size_t ldb,
                        size_t ldc,
                        size_t K)
{
  float32x4_t acc[N];
  for(size_t i{0}; i < N; i++) { acc[i] = vdupq_n_f32(0.0f); }
  for(size_t k{0}; k < K; k++) {
    const float32x4_t bv = vld1q_f32(b+k*ldb);
    for(size_t i{0}; i < N; i++) {
      acc[i] = vfmaq_n_f32(acc[i], bv, a[i+k*lda]);
    }
  }
  for(size_t i{0}; i < N; i++) {
    c[i]       = vgetq_lane_f32(acc[i], 0);
    c[i+ldc]   = vgetq_lane_f32(acc[i], 1);
    c[i+2*ldc] = vgetq_lane_f32(acc[i], 2);
    c[i+3*ldc] = vgetq_lane_f32(acc[i], 3);
  }
}

inline void mmCornerx_neon(
    const float* __restrict__ a,
    const float* __restrict__ b,
          float* __restrict__ c,
    size_t M,
    size_t N,
    size_t K,
    size_t i0,
    size_t j0,
    size_t mr,
    size_t nr
    )
{
  size_t i{0};
  for(; i+4 <= mr; i+=4) {
    float32x4_t acc0 = vdupq_n_f32(0.0f);
    float32x4_t acc1 = vdupq_n_f32(0.0f);
    float32x4_t acc2 = vdupq_n_f32(0.0f);
    for(size_t k{0}; k < K; k++) {
      // i0 + i is column, k is row
      const float32x4_t av = vld1q_f32(a+i0+i+k*M);
      if(nr >= 1) {
        acc0 = vfmaq_n_f32(acc0, av, b[k+(j0)*K]);
      }
      if(nr >= 2) {
        acc1 = vfmaq_n_f32(acc1, av, b[k+(j0+1)*K]);
      }
      if(nr >= 3) {
        acc2 = vfmaq_n_f32(acc2, av, b[k+(j0+2)*K]);
      }
    }
    if(nr >= 1) {
      vst1q_f32(c+i0+i+(j0)*M, acc0);
    }
    if(nr >= 2) {
      vst1q_f32(c+i0+i+(j0+1)*M, acc1);
    }
    if(nr >= 3) {
      vst1q_f32(c+i0+i+(j0+2)*M, acc2);
    }
  }
  for(; i < mr; i++) {
    for(size_t j{0}; j < nr; j++) {
      float ac = 0.0f;
      for(size_t k{0}; k < K; k++) {
        ac += a[i0+i+k*M]
             * b[k+(j0+j)*K];
      }
      c[i0+i+(j0+j)*M] = ac;
    }
  }
}
} // namespace internal
} // namespace schur
#endif // SCHUR_MATRIX_MULT_ALGO_HPP_
