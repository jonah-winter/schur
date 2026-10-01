#ifndef SCHUR_MATRIX_MULT_ALGO_HPP_
#define SCHUR_MATRIX_MULT_ALGO_HPP_

#include <arm_neon.h>

namespace schur {
namespace internal {
inline void mm84x(const float* __restrict__ a, 
                  const float* __restrict__ b, 
                        float* __restrict__ c) 
{
  float32x4_t c00 = vdupq_n_f32(0.0f);
  float32x4_t c01 = vdupq_n_f32(0.0f);
  float32x4_t c02 = vdupq_n_f32(0.0f);
  float32x4_t c03 = vdupq_n_f32(0.0f);

  float32x4_t c10 = vdupq_n_f32(0.0f);
  float32x4_t c11 = vdupq_n_f32(0.0f);
  float32x4_t c12 = vdupq_n_f32(0.0f);
  float32x4_t c13 = vdupq_n_f32(0.0f);

#if defined(__clang__)
#  pragma clang loop unroll(full)
#elif defined(__GNUC__)
#  pragma GCC unroll 8
#endif
  for(int k{0}; k < 8; k++) {
    const float32x4_t a0 = vld1q_f32(a+k*8);
    const float32x4_t a1 = vld1q_f32(a+k*8+4);

    c00 = vfmaq_n_f32(c00, a0, b[k]);
    c10 = vfmaq_n_f32(c10, a1, b[k]);

    c01 = vfmaq_n_f32(c01, a0, b[k+8]);
    c11 = vfmaq_n_f32(c11, a1, b[k+8]);

    c02 = vfmaq_n_f32(c02, a0, b[k+16]);
    c12 = vfmaq_n_f32(c12, a1, b[k+16]);

    c03 = vfmaq_n_f32(c03, a0, b[k+24]);
    c13 = vfmaq_n_f32(c13, a1, b[k+24]);
  }
  vst1q_f32(c, c00);
  vst1q_f32(c+4, c10);

  vst1q_f32(c+8, c01);
  vst1q_f32(c+12, c11);

  vst1q_f32(c+16, c02);
  vst1q_f32(c+20, c12);

  vst1q_f32(c+24, c03);
  vst1q_f32(c+28, c13);
}

template<size_t N>
requires(N <= 7)
inline void mm8Nx(const float* __restrict__ a,
                  const float* __restrict__ b,
                        float* __restrict__ c)
{
  float32x4_t lo[N] = {};
  float32x4_t hi[N] = {};
  for(size_t i{0}; i < N; i++) {
    lo[i] = vdupq_n_f32(0.0f);;
    hi[i] = vdupq_n_f32(0.0f);;
  }
#if defined(__clang__)
#  pragma clang loop unroll(full)
#elif defined(__GNUC__)
#  pragma GCC unroll 8
#endif
  for(size_t k{0}; k < 8; k++) {
    const float32x4_t a0 = vld1q_f32(a+k*8);
    const float32x4_t a1 = vld1q_f32(a+k*8+4);
#if defined(__clang__)
#  pragma clang loop unroll(full)
#elif defined(__GNUC__)
#  pragma GCC unroll 7
#endif
    for(size_t j{0}; j < N; j++) {
      lo[j] = vfmaq_n_f32(lo[j], a0, b[k*N+j]);
      hi[j] = vfmaq_n_f32(hi[j], a1, b[k*N+j]);
    }
  }
#if defined(__clang__)
#  pragma clang loop unroll(full)
#elif defined(__GNUC__)
#  pragma GCC unroll 7
#endif
  for(size_t i{0}; i < N; i++) {
    vst1q_f32(c+i*8,   lo[i]);
    vst1q_f32(c+i*8+4, hi[i]);
  }
}

template<size_t N>
requires(N <= 3)
inline void mmN4x(const float* __restrict__ a,
                  const float* __restrict__ b,
                        float* __restrict__ c)
{
#if defined(__clang__)
#  pragma clang loop unroll(full)
#elif defined(__GNUC__)
#  pragma GCC unroll 3
#endif
  for(size_t i{0}; i < N; i++) {
    float32x4_t ac = vdupq_n_f32(0.0f);
#if defined(__clang__)
#  pragma clang loop unroll(full)
#elif defined(__GNUC__)
#  pragma GCC unroll 8
#endif
    for(size_t j{0}; j < 8; j++) {
      const float32x4_t bld = vld1q_f32(b+j*4);
      ac = vfmaq_n_f32(ac, bld, a[i*8+j]);
    }
    vst1q_f32(c+i*4, ac);
  }
}
} // namespace internal
} // namespace schur
#endif // SCHUR_MATRIX_MULT_ALGO_HPP_
