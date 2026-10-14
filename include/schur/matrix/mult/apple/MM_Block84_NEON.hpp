#ifndef SCHUR_MATRIX_MULT_ALGO_HPP_
#define SCHUR_MATRIX_MULT_ALGO_HPP_

#include <cstddef>
#include <arm_neon.h>

namespace schur {
namespace internal {
inline void mm84x(const float* __restrict__ a, 
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
inline void mm8Nx(const float* __restrict__ a,
                  const float* __restrict__ b,
                        float* __restrict__ c,
                        size_t lda,
                        size_t ldb,
                        size_t ldc,
                        size_t K)
{
  float32x4_t lo[N] = {};
  float32x4_t hi[N] = {};
  for(size_t i{0}; i < N; i++) {
    lo[i] = vdupq_n_f32(0.0f);;
    hi[i] = vdupq_n_f32(0.0f);;
  }
  for(size_t k{0}; k < K; k++) {
    const float32x4_t a0 = vld1q_f32(a+k*lda);
    const float32x4_t a1 = vld1q_f32(a+k*lda+4);
#if defined(__clang__)
#  pragma clang loop unroll(full)
#elif defined(__GNUC__)
#  pragma GCC unroll 7
#endif
    for(size_t j{0}; j < N; j++) {
      lo[j] = vfmaq_n_f32(lo[j], a0, b[k+j*ldb]);
      hi[j] = vfmaq_n_f32(hi[j], a1, b[k+j*ldb]);
    }
  }
#if defined(__clang__)
#  pragma clang loop unroll(full)
#elif defined(__GNUC__)
#  pragma GCC unroll 7
#endif
  for(size_t i{0}; i < N; i++) {
    vst1q_f32(c+i*ldc,   lo[i]);
    vst1q_f32(c+i*ldc+4, hi[i]);
  }
}

template<size_t N>
requires(N >= 1 && N <= 7)
inline void mmN4x(const float* __restrict__ a,
                  const float* __restrict__ b,
                        float* __restrict__ c,
                        size_t lda,
                        size_t ldb,
                        size_t ldc,
                        size_t K)
{
  float32x4_t acc[N];
#if defined(__clang__)
#  pragma clang loop unroll(full)
#elif defined(__GNUC__)
#  pragma GCC unroll 7
#endif
  for(size_t i{0}; i < N; i++) {
    acc[i] = vdupq_n_f32(0.0f);
    for(size_t k{0}; k < K; k++) {
      const float32x4_t bv = vld1q_f32(b+k*ldb);
      acc[i] = vfmaq_n_f32(acc[i], bv, a[i+k*lda]);
    }
    c[i]        = vgetq_lane_f32(acc[i], 0);
    c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
    c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
    c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
  }
}
} // namespace internal
} // namespace schur
#endif // SCHUR_MATRIX_MULT_ALGO_HPP_
