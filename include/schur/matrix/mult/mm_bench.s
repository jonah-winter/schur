	.arch armv8.7-a
	.build_version macos,  26, 0
; GNU C++23 (Homebrew GCC 16.1.0) version 16.1.0 (aarch64-apple-darwin25)
;	compiled by GNU C version 16.1.0, GMP version 6.3.0, MPFR version 4.2.2, MPC version 1.4.1, isl version isl-0.28-GMP

; GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
; options passed: -fPIC -mcpu=apple-m5 -mmacosx-version-min=26.0.0 -mlittle-endian -mabi=lp64 -O3 -std=c++23
	.text
	.align	2
	.p2align 5,,15
	.globl __ZN5schur8internal7mmNNxCMEPKfS2_Pfmmm
__ZN5schur8internal7mmNNxCMEPKfS2_Pfmmm:
LFB4658:
	stp	x29, x30, [sp, -128]!	;,,,
LCFI0:
	mov	x29, sp	;,
	mov	x10, x2	; c, c
	mov	x7, x4	; N, N
	mov	x11, x0	; a, a
; ../mult/apple/MM_NxN_NEON.hpp:17:   size_t N4 = N & ~size_t(3);
	and	x14, x4, -4	; N4, N,
; ../mult/apple/MM_NxN_NEON.hpp:15:              const size_t K) {
	stp	x19, x20, [sp, 16]	;,,
; ../mult/apple/MM_NxN_NEON.hpp:18:   const size_t mr = M - M8;
	and	x2, x3, 7	; mr, M,
; ../mult/apple/MM_NxN_NEON.hpp:15:              const size_t K) {
	stp	x21, x22, [sp, 32]	;,,
LCFI1:
; ../mult/apple/MM_NxN_NEON.hpp:21:   for(size_t i{0}; i < M8; i+=8) {
	ands	x22, x3, -8	; M8, M,
; ../mult/apple/MM_NxN_NEON.hpp:15:              const size_t K) {
	stp	x23, x24, [sp, 48]	;,,
LCFI2:
	mov	x24, x1	; b, b
	stp	x25, x26, [sp, 64]	;,,
LCFI3:
; ../mult/apple/MM_NxN_NEON.hpp:21:   for(size_t i{0}; i < M8; i+=8) {
	beq	L2		;,
	mul	x0, x14, x5	; _879, N4, K
; ../mult/apple/MM_Block84_NEON.hpp:46:   vst1q_f32(c+ldc, c01);
	lsl	x6, x3, 2	; _1571, M,
; ../mult/apple/MM_NxN_NEON.hpp:19:   const size_t nr = N - N4;
	and	x23, x4, 3	; nr, N,
; ../mult/apple/MM_NxN_NEON.hpp:31:       case 3: { mm8Nx<3>(a+i, b+N4*K, c+i+N4*M, M, K, M, K); break; };
	mul	x25, x3, x14	; _33, M, N4
	stp	x27, x28, [sp, 80]	;,,
LCFI4:
; ../mult/apple/MM_Block84_NEON.hpp:47:   vst1q_f32(c+ldc+4, c11);
	add	x17, x6, 16	; _218, _1571,
	add	x8, x5, x5, lsl 1	; _556, K, K,
	mov	x30, x11	; ivtmp.365, a
	lsl	x15, x3, 4	; _1220, M,
; ../mult/apple/MM_NxN_NEON.hpp:31:       case 3: { mm8Nx<3>(a+i, b+N4*K, c+i+N4*M, M, K, M, K); break; };
	add	x27, x1, x0, lsl 2	; _2016, b, _879,
	add	x21, x5, x0	; _628, K, _879
	lsl	x16, x5, 4	; _1123, K,
	add	x19, x25, x3, lsl 1	; _402, _33, M,
	lsl	x0, x5, 2	; _1598, K,
	lsl	x9, x5, 3	; _565, K,
	add	x21, x1, x21, lsl 2	; _625, b, _628,
; ../mult/apple/MM_NxN_NEON.hpp:21:   for(size_t i{0}; i < M8; i+=8) {
	mov	x20, 0	; i,
	stp	x2, x11, [sp, 104]	; mr, a,
	add	x4, x27, x5, lsl 2	; _599, _2016, K,
	mov	x2, x3	; M, M
	add	x19, x10, x19, lsl 2	; ivtmp.364, c, _402,
	add	x1, x10, x25, lsl 2	; ivtmp.362, c, _33,
	str	x10, [sp, 120]	; c, %sfp
	.p2align 5,,15
L3:
; ../mult/apple/MM_NxN_NEON.hpp:22:     for(size_t j{0}; j < N4; j+=4) {
	cbz	x14, L18	; N4,
	sub	x12, x1, x25, lsl 2	; ivtmp.346, ivtmp.362, _33,
; ../mult/apple/MM_NxN_NEON.hpp:22:     for(size_t j{0}; j < N4; j+=4) {
	mov	x13, 0	; j,
; ../mult/apple/MM_NxN_NEON.hpp:22:     for(size_t j{0}; j < N4; j+=4) {
	mov	x28, x24	; ivtmp.350, b
	add	x10, x24, x5, lsl 2	; ivtmp.351, b, K,
	str	x25, [sp, 96]	; _33, %sfp
	sub	x11, x19, x25, lsl 2	; ivtmp.348, ivtmp.364, _33,
	.p2align 5,,15
L6:
; ../mult/apple/MM_Block84_NEON.hpp:25:   float32x4_t c13 = vdupq_n_f32(0.0f);
	movi	v31.4s, 0	;
; ../mult/apple/MM_Block84_NEON.hpp:27:   for(size_t k{0}; k < K; k++) {
	cbz	x5, L76	; K,
; ../mult/apple/MM_Block84_NEON.hpp:20:   float32x4_t c03 = vdupq_n_f32(0.0f);
	mov	v30.16b, v31.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:24:   float32x4_t c12 = vdupq_n_f32(0.0f);
	mov	v29.16b, v31.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:27:   for(size_t k{0}; k < K; k++) {
	mov	x3, x28	; ivtmp.335, ivtmp.350
; ../mult/apple/MM_Block84_NEON.hpp:19:   float32x4_t c02 = vdupq_n_f32(0.0f);
	mov	v28.16b, v31.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:23:   float32x4_t c11 = vdupq_n_f32(0.0f);
	mov	v27.16b, v31.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:27:   for(size_t k{0}; k < K; k++) {
	mov	x25, x30	; ivtmp.334, ivtmp.365
; ../mult/apple/MM_Block84_NEON.hpp:18:   float32x4_t c01 = vdupq_n_f32(0.0f);
	mov	v26.16b, v31.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:22:   float32x4_t c10 = vdupq_n_f32(0.0f);
	mov	v25.16b, v31.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:17:   float32x4_t c00 = vdupq_n_f32(0.0f);
	mov	v24.16b, v31.16b	;,
	.p2align 5,,15
L5:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldp	q23, q22, [x25]	;,,* ivtmp.334
; ../mult/apple/MM_Block84_NEON.hpp:27:   for(size_t k{0}; k < K; k++) {
	add	x25, x25, x6	; ivtmp.334, ivtmp.334, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v2.4s}, [x3]	;, MEM[(const float *)_570]
; ../mult/apple/MM_Block84_NEON.hpp:34:     c01 = vfmaq_n_f32(c01, a0, b[k+ldb]);
	ldr	s1, [x3, x5, lsl 2]	;, MEM[(const float *)_570 + K_138(D) * 4]
; ../mult/apple/MM_Block84_NEON.hpp:37:     c02 = vfmaq_n_f32(c02, a0, b[k+2*ldb]);
	ldr	s0, [x3, x9]	;, MEM[(const float *)_570 + _565 * 1]
; ../mult/apple/MM_Block84_NEON.hpp:40:     c03 = vfmaq_n_f32(c03, a0, b[k+3*ldb]);
	ldr	s21, [x3, x8, lsl 2]	;, MEM[(const float *)_570 + _556 * 1]
; ../mult/apple/MM_Block84_NEON.hpp:27:   for(size_t k{0}; k < K; k++) {
	add	x3, x3, 4	; ivtmp.335, ivtmp.335,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v26.4s, v23.4s, v1.s[0]	;,,
	fmla	v24.4s, v23.4s, v2.4s	;,,
	fmla	v28.4s, v23.4s, v0.s[0]	;,,
	fmla	v25.4s, v22.4s, v2.4s	;,,
	fmla	v27.4s, v22.4s, v1.s[0]	;,,
	fmla	v29.4s, v22.4s, v0.s[0]	;,,
	fmla	v30.4s, v23.4s, v21.s[0]	;,,
	fmla	v31.4s, v22.4s, v21.s[0]	;,,
; ../mult/apple/MM_Block84_NEON.hpp:27:   for(size_t k{0}; k < K; k++) {
	cmp	x10, x3	; ivtmp.351, ivtmp.335
	bne	L5		;,
L4:
; ../mult/apple/MM_NxN_NEON.hpp:22:     for(size_t j{0}; j < N4; j+=4) {
	add	x13, x13, 4	; j, j,
; ../mult/apple/MM_NxN_NEON.hpp:22:     for(size_t j{0}; j < N4; j+=4) {
	add	x28, x28, x16	; ivtmp.350, ivtmp.350, _1123
	add	x10, x10, x16	; ivtmp.351, ivtmp.351, _1123
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:21864:   __builtin_aarch64_st1v4sf ((__builtin_aarch64_simd_sf *) __a, __b);
	stp	q24, q25, [x12]	;,,* ivtmp.346
	str	q26, [x12, x6]	;, MEM <__Float32x4_t> [(float * {ref-all})_425 + _215 * 1]
	str	q27, [x12, x17]	;, MEM <__Float32x4_t> [(float * {ref-all})_425 + _218 * 1]
; ../mult/apple/MM_NxN_NEON.hpp:22:     for(size_t j{0}; j < N4; j+=4) {
	add	x12, x12, x15	; ivtmp.346, ivtmp.346, _1220
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:21864:   __builtin_aarch64_st1v4sf ((__builtin_aarch64_simd_sf *) __a, __b);
	stp	q28, q29, [x11]	;,,* ivtmp.348
	str	q30, [x11, x6]	;, MEM <__Float32x4_t> [(float * {ref-all})_422 + _215 * 1]
	str	q31, [x11, x17]	;, MEM <__Float32x4_t> [(float * {ref-all})_422 + _218 * 1]
; ../mult/apple/MM_NxN_NEON.hpp:22:     for(size_t j{0}; j < N4; j+=4) {
	add	x11, x11, x15	; ivtmp.348, ivtmp.348, _1220
	cmp	x14, x13	; N4, j
	bhi	L6		;,
	ldr	x25, [sp, 96]	; _33, %sfp
L18:
; ../mult/apple/MM_NxN_NEON.hpp:28:     switch(nr) {
	cmp	x23, 2	; nr,
	beq	L7		;,
	cmp	x23, 3	; nr,
	beq	L8		;,
	cmp	x23, 1	; nr,
	bne	L9		;,
; ../mult/apple/MM_Block84_NEON.hpp:72:   for(size_t k{0}; k < K; k++) {
	movi	v24.4s, 0	;
	cbz	x5, L77	; K,
	mov	v23.16b, v24.16b	;,
	mov	x10, x27	; ivtmp.309, _2016
	mov	x3, x30	; ivtmp.308, ivtmp.365
	.p2align 5,,15
L11:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldp	q21, q22, [x3]	;,,* ivtmp.308
; ../mult/apple/MM_Block84_NEON.hpp:72:   for(size_t k{0}; k < K; k++) {
	add	x3, x3, x6	; ivtmp.308, ivtmp.308, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v2.4s}, [x10], 4	;, MEM[(const float *)_630]
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v23.4s, v21.4s, v2.4s	;,,
	fmla	v24.4s, v22.4s, v2.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:72:   for(size_t k{0}; k < K; k++) {
	cmp	x21, x10	; _625, ivtmp.309
	bne	L11		;,
L10:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:21864:   __builtin_aarch64_st1v4sf ((__builtin_aarch64_simd_sf *) __a, __b);
	stp	q23, q24, [x1]	;,,* ivtmp.362
L9:
; ../mult/apple/MM_NxN_NEON.hpp:21:   for(size_t i{0}; i < M8; i+=8) {
	add	x20, x20, 8	; i, i,
; ../mult/apple/MM_NxN_NEON.hpp:21:   for(size_t i{0}; i < M8; i+=8) {
	add	x1, x1, 32	; ivtmp.362, ivtmp.362,
	add	x19, x19, 32	; ivtmp.364, ivtmp.364,
	add	x30, x30, 32	; ivtmp.365, ivtmp.365,
	cmp	x22, x20	; M8, i
	bhi	L3		;,
; ../mult/apple/MM_NxN_NEON.hpp:35:   if(mr) {
	mov	x3, x2	; M, M
	ldp	x2, x11, [sp, 104]	; mr, a,
	ldp	x27, x28, [sp, 80]	;,,
LCFI5:
	ldr	x10, [sp, 120]	; c, %sfp
	cbz	x2, L22	; mr,
; ../mult/apple/MM_NxN_NEON.hpp:36:     for(size_t j{0}; j < N4; j+=4) {
	cbz	x14, L22	; N4,
L20:
	add	x1, x3, x22	; _1186, M, M8
; ../mult/apple/MM_NxN_NEON.hpp:43:         case 6: { mmN4x<6>(a + M8, b + j*K, c + M8 + j*M, M, K, M, K); break; };
	add	x17, x11, x22, lsl 2	; _1978, a, M8,
; ../mult/apple/MM_NxN_NEON.hpp:36:     for(size_t j{0}; j < N4; j+=4) {
	mov	x20, 0	; j,
	add	x4, x3, x1	; _1165, M, _1186
	add	x9, x10, x22, lsl 2	; ivtmp.298, c, M8,
	mov	x13, x24	; ivtmp.302, b
	add	x8, x3, x4	; _1126, M, _1165
	add	x1, x10, x1, lsl 2	; ivtmp.299, c, _1186,
	add	x4, x10, x4, lsl 2	; ivtmp.300, c, _1165,
	add	x8, x10, x8, lsl 2	; ivtmp.301, c, _1126,
L70:
; ../mult/apple/MM_NxN_NEON.hpp:37:       switch(mr) {
	cmp	x2, 5	; mr,
	beq	L23		;,
	bhi	L24		;,
	cmp	x2, 3	; mr,
	beq	L25		;,
	cmp	x2, 4	; mr,
	beq	L26		;,
	cmp	x2, 2	; mr,
	bne	L145		;,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cbz	x5, L146	; K,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v1.4s, 0	;
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x12, 0	; k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x21, x17	; ivtmp.189, _1978
	mov	x19, x13	; ivtmp.188, ivtmp.302
L37:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v5.4s}, [x21]	;, *_1007
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x12, x12, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.189, ivtmp.189, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q0, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_2101]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.188, ivtmp.188, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v1.4s, v0.4s, v5.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x5, x12	; K, k
	bne	L37		;,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v27.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	str	s1, [x9]	;, MEM[(float *)_756]
	add	x23, x17, 4	; ivtmp.183, _1978,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x21, 0	; k,
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.182, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v1.s}[1], [x1]	;,, MEM[(float *)_772]
	st1	{v1.s}[2], [x4]	;,, MEM[(float *)_784]
	st1	{v1.s}[3], [x8]	;,, MEM[(float *)_795]
L39:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v25.4s}, [x23]	;, *_1050
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, x6	; ivtmp.183, ivtmp.183, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q26, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_2077]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.182, ivtmp.182, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v27.4s, v26.4s, v25.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x12, x21	; k, k
	bne	L39		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	fmov	s28, s27	;,
	dup	s29, v27.s[1]	;,,
	dup	s30, v27.s[2]	;,,
	dup	s31, v27.s[3]	;,,
L38:
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s28, [x9, 4]	;, MEM[(float *)_986 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s29, [x1, 4]	;, MEM[(float *)_944 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s30, [x4, 4]	;, MEM[(float *)_901 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s31, [x8, 4]	;, MEM[(float *)_870 + 4B]
L36:
; ../mult/apple/MM_NxN_NEON.hpp:36:     for(size_t j{0}; j < N4; j+=4) {
	add	x20, x20, 4	; j, j,
; ../mult/apple/MM_NxN_NEON.hpp:36:     for(size_t j{0}; j < N4; j+=4) {
	add	x9, x9, x15	; ivtmp.298, ivtmp.298, _1220
	add	x1, x1, x15	; ivtmp.299, ivtmp.299, _1220
	add	x4, x4, x15	; ivtmp.300, ivtmp.300, _1220
	add	x8, x8, x15	; ivtmp.301, ivtmp.301, _1220
	add	x13, x13, x16	; ivtmp.302, ivtmp.302, _1123
	cmp	x14, x20	; N4, j
	bhi	L70		;,
L22:
; ../mult/apple/MM_NxN_NEON.hpp:50:   for (size_t j = N4; j < N; ++j) {
	cmp	x7, x14	; N, N4
	bls	L1		;,
	cmp	x3, x22	; M, M8
	bls	L1		;,
L21:
	mul	x1, x3, x14	; ivtmp.122_1562, M, N4
	add	x12, x14, 1	; N4, N4,
; ../mult/apple/MM_NxN_NEON.hpp:53:       for (size_t k = 0; k < K; ++k) {
	mov	x8, x22	; i, M8
	madd	x4, x14, x0, x0	; _1659, N4, _1598, _1598
	add	x11, x11, x22, lsl 2	; ivtmp.116, a, M8,
	add	x10, x10, x1, lsl 2	; ivtmp.123, c, ivtmp.122_1562,
	mov	x1, x22	; i, M8
	madd	x14, x14, x0, x24	; ivtmp.124, N4, _1598, b
	add	x4, x24, x4	; ivtmp.126, b, _1659
	mov	x9, x11	; ivtmp.116, ivtmp.116
	cbz	x5, L75	; K,
	.p2align 5,,15
L73:
; ../mult/apple/MM_NxN_NEON.hpp:52:       float sum = 0.0f;
	movi	v17.2s, #0	;
; ../mult/apple/MM_NxN_NEON.hpp:53:       for (size_t k = 0; k < K; ++k) {
	mov	x2, x14	; ivtmp.109, ivtmp.124
	mov	x1, x9	; ivtmp.108, ivtmp.116
	.p2align 5,,15
L72:
; ../mult/apple/MM_NxN_NEON.hpp:54:         sum += a[i + k*M] * b[k + j*K];
	ldr	s16, [x1]	;, MEM[(const float *)_1503]
; ../mult/apple/MM_NxN_NEON.hpp:53:       for (size_t k = 0; k < K; ++k) {
	add	x1, x1, x6	; ivtmp.108, ivtmp.108, _1571
; ../mult/apple/MM_NxN_NEON.hpp:54:         sum += a[i + k*M] * b[k + j*K];
	ldr	s7, [x2], 4	;, MEM[(const float *)_1509]
	fmadd	s17, s16, s7, s17	;,,,
; ../mult/apple/MM_NxN_NEON.hpp:53:       for (size_t k = 0; k < K; ++k) {
	cmp	x2, x4	; ivtmp.109, ivtmp.126
	bne	L72		;,
; ../mult/apple/MM_NxN_NEON.hpp:56:       c[i + j*M] = sum;
	str	s17, [x10, x8, lsl 2]	;, MEM[(float *)_1041 + i_942 * 4]
; ../mult/apple/MM_NxN_NEON.hpp:51:     for (size_t i = M8; i < M; ++i) {
	add	x8, x8, 1	; i, i,
; ../mult/apple/MM_NxN_NEON.hpp:51:     for (size_t i = M8; i < M; ++i) {
	add	x9, x9, 4	; ivtmp.116, ivtmp.116,
	cmp	x3, x8	; M, i
	bne	L73		;,
L74:
; ../mult/apple/MM_NxN_NEON.hpp:50:   for (size_t j = N4; j < N; ++j) {
	add	x10, x10, x6	; ivtmp.123, ivtmp.123, _1571
	add	x14, x14, x0	; ivtmp.124, ivtmp.124, _1598
	add	x4, x4, x0	; ivtmp.126, ivtmp.126, _1598
	cmp	x7, x12	; N, N4
	beq	L1		;,
	add	x12, x12, 1	; N4, N4,
; ../mult/apple/MM_NxN_NEON.hpp:53:       for (size_t k = 0; k < K; ++k) {
	mov	x9, x11	; ivtmp.116, ivtmp.116
	mov	x8, x22	; i, M8
	mov	x1, x22	; i, M8
	cbnz	x5, L73	; K,
L75:
; ../mult/apple/MM_NxN_NEON.hpp:51:     for (size_t i = M8; i < M; ++i) {
	add	x2, x1, 1	; i, i,
; ../mult/apple/MM_NxN_NEON.hpp:56:       c[i + j*M] = sum;
	str	wzr, [x10, x1, lsl 2]	;, MEM[(float *)_800 + i_602 * 4]
; ../mult/apple/MM_NxN_NEON.hpp:51:     for (size_t i = M8; i < M; ++i) {
	add	x1, x1, 2	; i, i,
; ../mult/apple/MM_NxN_NEON.hpp:51:     for (size_t i = M8; i < M; ++i) {
	cmp	x3, x2	; M, i
	beq	L74		;,
; ../mult/apple/MM_NxN_NEON.hpp:56:       c[i + j*M] = sum;
	str	wzr, [x10, x2, lsl 2]	;, MEM[(float *)_1467 + i_821 * 4]
; ../mult/apple/MM_NxN_NEON.hpp:51:     for (size_t i = M8; i < M; ++i) {
	cmp	x1, x3	; i, M
	bne	L75		;,
	b	L74		;
	.p2align 2,,3
L76:
LCFI6:
; ../mult/apple/MM_Block84_NEON.hpp:20:   float32x4_t c03 = vdupq_n_f32(0.0f);
	mov	v30.16b, v31.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:24:   float32x4_t c12 = vdupq_n_f32(0.0f);
	mov	v29.16b, v31.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:19:   float32x4_t c02 = vdupq_n_f32(0.0f);
	mov	v28.16b, v31.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:23:   float32x4_t c11 = vdupq_n_f32(0.0f);
	mov	v27.16b, v31.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:18:   float32x4_t c01 = vdupq_n_f32(0.0f);
	mov	v26.16b, v31.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:22:   float32x4_t c10 = vdupq_n_f32(0.0f);
	mov	v25.16b, v31.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:17:   float32x4_t c00 = vdupq_n_f32(0.0f);
	mov	v24.16b, v31.16b	;,
	b	L4		;
L7:
; ../mult/apple/MM_Block84_NEON.hpp:67:   float32x4_t hi[N] = {};
	movi	v20.4s, 0	;
; ../mult/apple/MM_Block84_NEON.hpp:72:   for(size_t k{0}; k < K; k++) {
	cbz	x5, L78	; K,
; ../mult/apple/MM_Block84_NEON.hpp:67:   float32x4_t hi[N] = {};
	mov	v19.16b, v20.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:66:   float32x4_t lo[N] = {};
	mov	v18.16b, v20.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:72:   for(size_t k{0}; k < K; k++) {
	mov	x3, x27	; ivtmp.316, _2016
; ../mult/apple/MM_Block84_NEON.hpp:66:   float32x4_t lo[N] = {};
	mov	v17.16b, v20.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:72:   for(size_t k{0}; k < K; k++) {
	mov	x10, x30	; ivtmp.315, ivtmp.365
	.p2align 5,,15
L13:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldp	q16, q7, [x10]	;,,* ivtmp.315
; ../mult/apple/MM_Block84_NEON.hpp:72:   for(size_t k{0}; k < K; k++) {
	add	x10, x10, x6	; ivtmp.315, ivtmp.315, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v3.4s}, [x3]	;, *_1905
; ../mult/apple/MM_Block84_NEON.hpp:81:       lo[j] = vfmaq_n_f32(lo[j], a0, b[k+j*ldb]);
	ldr	s6, [x0, x3]	;, *_1924
; ../mult/apple/MM_Block84_NEON.hpp:72:   for(size_t k{0}; k < K; k++) {
	add	x3, x3, 4	; ivtmp.316, ivtmp.316,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v18.4s, v16.4s, v6.s[0]	;,,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v17.4s, v16.4s, v3.4s	;,,
	fmla	v19.4s, v7.4s, v3.4s	;,,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v20.4s, v7.4s, v6.s[0]	;,,
; ../mult/apple/MM_Block84_NEON.hpp:72:   for(size_t k{0}; k < K; k++) {
	cmp	x4, x3	; _599, ivtmp.316
	bne	L13		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:21864:   __builtin_aarch64_st1v4sf ((__builtin_aarch64_simd_sf *) __a, __b);
	stp	q17, q19, [x1]	;,,* ivtmp.362
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:21864:   __builtin_aarch64_st1v4sf ((__builtin_aarch64_simd_sf *) __a, __b);
	str	q18, [x1, x6]	;, MEM <__Float32x4_t> [(float * {ref-all})_395 + _215 * 1]
	str	q20, [x1, x17]	;, MEM <__Float32x4_t> [(float * {ref-all})_395 + _218 * 1]
; ../mult/apple/MM_NxN_NEON.hpp:30:       case 2: { mm8Nx<2>(a+i, b+N4*K, c+i+N4*M, M, K, M, K); break; };
	b	L9		;
L8:
; ../mult/apple/MM_Block84_NEON.hpp:67:   float32x4_t hi[N] = {};
	movi	v5.4s, 0	;
; ../mult/apple/MM_Block84_NEON.hpp:72:   for(size_t k{0}; k < K; k++) {
	cbz	x5, L79	; K,
; ../mult/apple/MM_Block84_NEON.hpp:67:   float32x4_t hi[N] = {};
	mov	v4.16b, v5.16b	;,
	mov	v31.16b, v5.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:72:   for(size_t k{0}; k < K; k++) {
	mov	x3, x27	; ivtmp.325, _2016
; ../mult/apple/MM_Block84_NEON.hpp:66:   float32x4_t lo[N] = {};
	mov	v30.16b, v5.16b	;,
	mov	v29.16b, v5.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:72:   for(size_t k{0}; k < K; k++) {
	mov	x10, x30	; ivtmp.324, ivtmp.365
; ../mult/apple/MM_Block84_NEON.hpp:66:   float32x4_t lo[N] = {};
	mov	v28.16b, v5.16b	;,
	.p2align 5,,15
L15:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldp	q27, q26, [x10]	;,,* ivtmp.324
	add	x11, x0, x3	; _603, _1598, ivtmp.325
; ../mult/apple/MM_Block84_NEON.hpp:72:   for(size_t k{0}; k < K; k++) {
	add	x10, x10, x6	; ivtmp.324, ivtmp.324, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v1.4s}, [x3]	;, *_1982
; ../mult/apple/MM_Block84_NEON.hpp:81:       lo[j] = vfmaq_n_f32(lo[j], a0, b[k+j*ldb]);
	ldr	s0, [x0, x3]	;, *_2001
; ../mult/apple/MM_Block84_NEON.hpp:72:   for(size_t k{0}; k < K; k++) {
	add	x3, x3, 4	; ivtmp.325, ivtmp.325,
; ../mult/apple/MM_Block84_NEON.hpp:81:       lo[j] = vfmaq_n_f32(lo[j], a0, b[k+j*ldb]);
	ldr	s25, [x0, x11]	;, *_2020
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v29.4s, v27.4s, v0.s[0]	;,,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v28.4s, v27.4s, v1.4s	;,,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v30.4s, v27.4s, v25.s[0]	;,,
	fmla	v5.4s, v26.4s, v25.s[0]	;,,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v31.4s, v26.4s, v1.4s	;,,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v4.4s, v26.4s, v0.s[0]	;,,
; ../mult/apple/MM_Block84_NEON.hpp:72:   for(size_t k{0}; k < K; k++) {
	cmp	x4, x3	; _599, ivtmp.325
	bne	L15		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:21864:   __builtin_aarch64_st1v4sf ((__builtin_aarch64_simd_sf *) __a, __b);
	stp	q28, q31, [x1]	;,,* ivtmp.362
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:21864:   __builtin_aarch64_st1v4sf ((__builtin_aarch64_simd_sf *) __a, __b);
	str	q29, [x1, x6]	;, MEM <__Float32x4_t> [(float * {ref-all})_394 + _215 * 1]
	str	q4, [x1, x17]	;, MEM <__Float32x4_t> [(float * {ref-all})_394 + _218 * 1]
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:21864:   __builtin_aarch64_st1v4sf ((__builtin_aarch64_simd_sf *) __a, __b);
	stp	q30, q5, [x19]	;,,* ivtmp.364
; ../mult/apple/MM_NxN_NEON.hpp:31:       case 3: { mm8Nx<3>(a+i, b+N4*K, c+i+N4*M, M, K, M, K); break; };
	b	L9		;
L2:
LCFI7:
; ../mult/apple/MM_NxN_NEON.hpp:35:   if(mr) {
	cbz	x2, L1	; mr,
	lsl	x6, x3, 2	; _1571, M,
; ../mult/apple/MM_NxN_NEON.hpp:36:     for(size_t j{0}; j < N4; j+=4) {
	cbnz	x14, L147	; N4,
	lsl	x0, x5, 2	; _1598, K,
; ../mult/apple/MM_NxN_NEON.hpp:50:   for (size_t j = N4; j < N; ++j) {
	cbnz	x4, L21	; N,
L1:
; ../mult/apple/MM_NxN_NEON.hpp:59: }
	ldp	x19, x20, [sp, 16]	;,,
	ldp	x21, x22, [sp, 32]	;,,
	ldp	x23, x24, [sp, 48]	;,,
	ldp	x25, x26, [sp, 64]	;,,
	ldp	x29, x30, [sp], 128	;,,,
LCFI8:
	ret	
L24:
LCFI9:
; ../mult/apple/MM_NxN_NEON.hpp:37:       switch(mr) {
	cmp	x2, 6	; mr,
	beq	L148		;,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cbz	x5, L149	; K,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v27.4s, 0	;
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x19, 0	; k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, x17	; ivtmp.168, _1978
	mov	x21, x13	; ivtmp.167, ivtmp.302
L62:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v23.4s}, [x23]	;, *_158
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, x6	; ivtmp.168, ivtmp.168, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q24, [x21]	;, MEM <__Float32x4_t> [(float * {ref-all})_1935]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x0	; ivtmp.167, ivtmp.167, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v27.4s, v24.4s, v23.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x5, x19	; K, k
	bne	L62		;,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v22.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	str	s27, [x9]	;, MEM[(float *)_722]
	mov	x12, x19	; _558, k
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 4	; ivtmp.162, _1978,
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.161, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v27.s}[1], [x1]	;,, MEM[(float *)_1057]
	st1	{v27.s}[2], [x4]	;,, MEM[(float *)_818]
	st1	{v27.s}[3], [x8]	;,, MEM[(float *)_1514]
L64:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v20.4s}, [x21]	;, *_715
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.162, ivtmp.162, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q21, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_1885]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.161, ivtmp.161, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v22.4s, v21.4s, v20.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x12, x23	; _558, k
	bne	L64		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x19, x1, 4	; tmp949, ivtmp.299,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v19.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x26, x4, 4	; tmp950, ivtmp.300,
	str	s22, [x9, 4]	;, MEM[(float *)_722 + 4B]
	add	x25, x8, 4	; tmp951, ivtmp.301,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 8	; ivtmp.156, _1978,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v22.s}[1], [x19]	;,, MEM[(float *)_1057 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.155, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v22.s}[2], [x26]	;,, MEM[(float *)_818 + 4B]
	st1	{v22.s}[3], [x25]	;,, MEM[(float *)_1514 + 4B]
L65:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v17.4s}, [x21]	;, *_758
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.156, ivtmp.156, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q18, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_1863]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.155, ivtmp.155, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v19.4s, v18.4s, v17.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x23, x12	; k, _558
	bne	L65		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x19, x1, 8	; tmp958, ivtmp.299,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v16.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x26, x4, 8	; tmp959, ivtmp.300,
	str	s19, [x9, 8]	;, MEM[(float *)_722 + 8B]
	add	x25, x8, 8	; tmp960, ivtmp.301,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 12	; ivtmp.150, _1978,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v19.s}[1], [x19]	;,, MEM[(float *)_1057 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.149, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v19.s}[2], [x26]	;,, MEM[(float *)_818 + 8B]
	st1	{v19.s}[3], [x25]	;,, MEM[(float *)_1514 + 8B]
L66:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v6.4s}, [x21]	;, *_801
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.150, ivtmp.150, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q7, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_1813]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.149, ivtmp.149, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v16.4s, v7.4s, v6.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x23, x12	; k, _558
	bne	L66		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x19, x1, 12	; tmp967, ivtmp.299,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v5.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x26, x4, 12	; tmp968, ivtmp.300,
	str	s16, [x9, 12]	;, MEM[(float *)_722 + 12B]
	add	x25, x8, 12	; tmp969, ivtmp.301,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 16	; ivtmp.144, _1978,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v16.s}[1], [x19]	;,, MEM[(float *)_1057 + 12B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.143, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v16.s}[2], [x26]	;,, MEM[(float *)_818 + 12B]
	st1	{v16.s}[3], [x25]	;,, MEM[(float *)_1514 + 12B]
L67:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v3.4s}, [x21]	;, *_844
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.144, ivtmp.144, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q4, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_1777]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.143, ivtmp.143, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v5.4s, v4.4s, v3.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x23, x12	; k, _558
	bne	L67		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x19, x1, 16	; tmp976, ivtmp.299,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v2.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x26, x4, 16	; tmp977, ivtmp.300,
	str	s5, [x9, 16]	;, MEM[(float *)_722 + 16B]
	add	x25, x8, 16	; tmp978, ivtmp.301,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 20	; ivtmp.138, _1978,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v5.s}[1], [x19]	;,, MEM[(float *)_1057 + 16B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.137, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v5.s}[2], [x26]	;,, MEM[(float *)_818 + 16B]
	st1	{v5.s}[3], [x25]	;,, MEM[(float *)_1514 + 16B]
L68:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v0.4s}, [x21]	;, *_887
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.138, ivtmp.138, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q1, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_1743]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.137, ivtmp.137, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v2.4s, v1.4s, v0.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x12, x23	; _558, k
	bne	L68		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x19, x1, 20	; tmp985, ivtmp.299,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v27.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x26, x4, 20	; tmp986, ivtmp.300,
	str	s2, [x9, 20]	;, MEM[(float *)_722 + 20B]
	add	x25, x8, 20	; tmp987, ivtmp.301,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 24	; ivtmp.132, _1978,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v2.s}[1], [x19]	;,, MEM[(float *)_1057 + 20B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.131, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v2.s}[2], [x26]	;,, MEM[(float *)_818 + 20B]
	st1	{v2.s}[3], [x25]	;,, MEM[(float *)_1514 + 20B]
L69:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v25.4s}, [x21]	;, *_930
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.132, ivtmp.132, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q26, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_1703]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.131, ivtmp.131, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v27.4s, v26.4s, v25.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x23, x12	; k, _558
	bne	L69		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	fmov	s30, s27	;,
	dup	s31, v27.s[1]	;,,
	dup	s28, v27.s[2]	;,,
	dup	s29, v27.s[3]	;,,
L63:
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s30, [x9, 24]	;, MEM[(float *)_980 + 24B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s31, [x1, 24]	;, MEM[(float *)_929 + 24B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s28, [x4, 24]	;, MEM[(float *)_886 + 24B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s29, [x8, 24]	;, MEM[(float *)_864 + 24B]
; ../mult/apple/MM_NxN_NEON.hpp:44:         case 7: { mmN4x<7>(a + M8, b + j*K, c + M8 + j*M, M, K, M, K); break; };
	b	L36		;
L148:
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cbz	x5, L150	; K,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v27.4s, 0	;
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x19, 0	; k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, x17	; ivtmp.293, _1978
	mov	x21, x13	; ivtmp.292, ivtmp.302
L55:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v25.4s}, [x23]	;, *_1609
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, x6	; ivtmp.293, ivtmp.293, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q26, [x21]	;, MEM <__Float32x4_t> [(float * {ref-all})_1227]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x0	; ivtmp.292, ivtmp.292, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v27.4s, v26.4s, v25.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x5, x19	; K, k
	bne	L55		;,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v20.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	str	s27, [x9]	;, MEM[(float *)_1979]
	mov	x12, x19	; _614, k
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 4	; ivtmp.287, _1978,
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.286, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v27.s}[1], [x1]	;,, MEM[(float *)_1589]
	st1	{v27.s}[2], [x4]	;,, MEM[(float *)_1638]
	st1	{v27.s}[3], [x8]	;,, MEM[(float *)_1660]
L57:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v18.4s}, [x21]	;, *_1652
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.287, ivtmp.287, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q19, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_1252]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.286, ivtmp.286, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v20.4s, v19.4s, v18.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x23, x12	; k, _614
	bne	L57		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x19, x1, 4	; tmp904, ivtmp.299,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v17.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x26, x4, 4	; tmp905, ivtmp.300,
	str	s20, [x9, 4]	;, MEM[(float *)_1979 + 4B]
	add	x25, x8, 4	; tmp906, ivtmp.301,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 8	; ivtmp.281, _1978,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v20.s}[1], [x19]	;,, MEM[(float *)_1589 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.280, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v20.s}[2], [x26]	;,, MEM[(float *)_1638 + 4B]
	st1	{v20.s}[3], [x25]	;,, MEM[(float *)_1660 + 4B]
L58:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v7.4s}, [x21]	;, *_1695
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.281, ivtmp.281, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q16, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_1288]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.280, ivtmp.280, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v17.4s, v16.4s, v7.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x23, x12	; k, _614
	bne	L58		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x19, x1, 8	; tmp913, ivtmp.299,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v6.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x26, x4, 8	; tmp914, ivtmp.300,
	str	s17, [x9, 8]	;, MEM[(float *)_1979 + 8B]
	add	x25, x8, 8	; tmp915, ivtmp.301,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 12	; ivtmp.275, _1978,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v17.s}[1], [x19]	;,, MEM[(float *)_1589 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.274, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v17.s}[2], [x26]	;,, MEM[(float *)_1638 + 8B]
	st1	{v17.s}[3], [x25]	;,, MEM[(float *)_1660 + 8B]
L59:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v4.4s}, [x21]	;, *_1738
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.275, ivtmp.275, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q5, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_1331]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.274, ivtmp.274, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v6.4s, v5.4s, v4.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x23, x12	; k, _614
	bne	L59		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x19, x1, 12	; tmp922, ivtmp.299,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v3.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x26, x4, 12	; tmp923, ivtmp.300,
	str	s6, [x9, 12]	;, MEM[(float *)_1979 + 12B]
	add	x25, x8, 12	; tmp924, ivtmp.301,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 16	; ivtmp.269, _1978,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v6.s}[1], [x19]	;,, MEM[(float *)_1589 + 12B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.268, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v6.s}[2], [x26]	;,, MEM[(float *)_1638 + 12B]
	st1	{v6.s}[3], [x25]	;,, MEM[(float *)_1660 + 12B]
L60:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v0.4s}, [x21]	;, *_1781
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.269, ivtmp.269, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q1, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_1374]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.268, ivtmp.268, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v3.4s, v1.4s, v0.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x23, x12	; k, _614
	bne	L60		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x19, x1, 16	; tmp931, ivtmp.299,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v2.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x26, x4, 16	; tmp932, ivtmp.300,
	str	s3, [x9, 16]	;, MEM[(float *)_1979 + 16B]
	add	x25, x8, 16	; tmp933, ivtmp.301,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 20	; ivtmp.263, _1978,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v3.s}[1], [x19]	;,, MEM[(float *)_1589 + 16B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.262, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v3.s}[2], [x26]	;,, MEM[(float *)_1638 + 16B]
	st1	{v3.s}[3], [x25]	;,, MEM[(float *)_1660 + 16B]
L61:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v30.4s}, [x21]	;, *_1824
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.263, ivtmp.263, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q31, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_1403]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.262, ivtmp.262, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v2.4s, v31.4s, v30.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x23, x12	; k, _614
	bne	L61		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	fmov	s21, s2	;,
	dup	s22, v2.s[1]	;,,
	dup	s23, v2.s[2]	;,,
	dup	s24, v2.s[3]	;,,
L56:
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s21, [x9, 20]	;, MEM[(float *)_1006 + 20B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s22, [x1, 20]	;, MEM[(float *)_971 + 20B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s23, [x4, 20]	;, MEM[(float *)_924 + 20B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s24, [x8, 20]	;, MEM[(float *)_885 + 20B]
; ../mult/apple/MM_NxN_NEON.hpp:43:         case 6: { mmN4x<6>(a + M8, b + j*K, c + M8 + j*M, M, K, M, K); break; };
	b	L36		;
L145:
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cbz	x5, L80	; K,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v20.4s, 0	;
	cmp	x3, 1	; M,
	bne	L151		;,
	add	x21, x11, x0	; _2012, a, _1598
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x19, x17	; ivtmp.173, _1978
	mov	x12, x13	; ivtmp.172, ivtmp.302
L35:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v18.4s}, [x19], 4	;, MEM[(const float *)_1994]
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q19, [x12]	;, MEM <__Float32x4_t> [(float * {ref-all})_1993]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x12, x12, x0	; ivtmp.172, ivtmp.172, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v20.4s, v19.4s, v18.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x19, x21	; ivtmp.173, _2012
	bne	L35		;,
L34:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	fmov	s21, s20	;,
	dup	s22, v20.s[1]	;,,
	dup	s23, v20.s[2]	;,,
	dup	s24, v20.s[3]	;,,
L31:
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s21, [x9]	;, MEM[(float *)_1105]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s22, [x1]	;, MEM[(float *)_1019]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s23, [x4]	;, MEM[(float *)_883]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s24, [x8]	;, MEM[(float *)_763]
	b	L36		;
L23:
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cbz	x5, L152	; K,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v31.4s, 0	;
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x19, 0	; k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, x17	; ivtmp.258, _1978
	mov	x21, x13	; ivtmp.257, ivtmp.302
L49:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v29.4s}, [x23]	;, *_1394
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, x6	; ivtmp.258, ivtmp.258, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q30, [x21]	;, MEM <__Float32x4_t> [(float * {ref-all})_1444]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x0	; ivtmp.257, ivtmp.257, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v31.4s, v30.4s, v29.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x5, x19	; K, k
	bne	L49		;,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v28.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	str	s31, [x9]	;, MEM[(float *)_452]
	mov	x12, x19	; _1627, k
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 4	; ivtmp.252, _1978,
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.251, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v31.s}[1], [x1]	;,, MEM[(float *)_528]
	st1	{v31.s}[2], [x4]	;,, MEM[(float *)_578]
	st1	{v31.s}[3], [x8]	;,, MEM[(float *)_922]
L51:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v26.4s}, [x21]	;, *_1437
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.252, ivtmp.252, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q27, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_1814]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.251, ivtmp.251, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v28.4s, v27.4s, v26.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x12, x23	; _1627, k
	bne	L51		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x19, x1, 4	; tmp868, ivtmp.299,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v25.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x26, x4, 4	; tmp869, ivtmp.300,
	str	s28, [x9, 4]	;, MEM[(float *)_452 + 4B]
	add	x25, x8, 4	; tmp870, ivtmp.301,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 8	; ivtmp.246, _1978,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v28.s}[1], [x19]	;,, MEM[(float *)_528 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.245, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v28.s}[2], [x26]	;,, MEM[(float *)_578 + 4B]
	st1	{v28.s}[3], [x25]	;,, MEM[(float *)_922 + 4B]
L52:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v4.4s}, [x21]	;, *_1480
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.246, ivtmp.246, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q5, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_517]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.245, ivtmp.245, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v25.4s, v5.4s, v4.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x12, x23	; _1627, k
	bne	L52		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x19, x1, 8	; tmp877, ivtmp.299,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v1.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x26, x4, 8	; tmp878, ivtmp.300,
	str	s25, [x9, 8]	;, MEM[(float *)_452 + 8B]
	add	x25, x8, 8	; tmp879, ivtmp.301,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 12	; ivtmp.240, _1978,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v25.s}[1], [x19]	;,, MEM[(float *)_528 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.239, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v25.s}[2], [x26]	;,, MEM[(float *)_578 + 8B]
	st1	{v25.s}[3], [x25]	;,, MEM[(float *)_922 + 8B]
L53:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v3.4s}, [x21]	;, *_1523
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.240, ivtmp.240, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q0, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_2402]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.239, ivtmp.239, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v1.4s, v0.4s, v3.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x12, x23	; _1627, k
	bne	L53		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x19, x1, 12	; tmp886, ivtmp.299,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v16.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x26, x4, 12	; tmp887, ivtmp.300,
	str	s1, [x9, 12]	;, MEM[(float *)_452 + 12B]
	add	x25, x8, 12	; tmp888, ivtmp.301,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 16	; ivtmp.234, _1978,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v1.s}[1], [x19]	;,, MEM[(float *)_528 + 12B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.233, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v1.s}[2], [x26]	;,, MEM[(float *)_578 + 12B]
	st1	{v1.s}[3], [x25]	;,, MEM[(float *)_922 + 12B]
L54:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v6.4s}, [x21]	;, *_1566
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.234, ivtmp.234, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q7, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_2267]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.233, ivtmp.233, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v16.4s, v7.4s, v6.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x12, x23	; _1627, k
	bne	L54		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	fmov	s17, s16	;,
	dup	s18, v16.s[1]	;,,
	dup	s19, v16.s[2]	;,,
	dup	s20, v16.s[3]	;,,
L50:
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s17, [x9, 16]	;, MEM[(float *)_1001 + 16B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s18, [x1, 16]	;, MEM[(float *)_967 + 16B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s19, [x4, 16]	;, MEM[(float *)_923 + 16B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s20, [x8, 16]	;, MEM[(float *)_884 + 16B]
; ../mult/apple/MM_NxN_NEON.hpp:42:         case 5: { mmN4x<5>(a + M8, b + j*K, c + M8 + j*M, M, K, M, K); break; };
	b	L36		;
L26:
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cbz	x5, L153	; K,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v4.4s, 0	;
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x19, 0	; k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, x17	; ivtmp.229, _1978
	mov	x21, x13	; ivtmp.228, ivtmp.302
L44:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v2.4s}, [x23]	;, *_1222
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, x6	; ivtmp.229, ivtmp.229, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q3, [x21]	;, MEM <__Float32x4_t> [(float * {ref-all})_2242]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x0	; ivtmp.228, ivtmp.228, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v4.4s, v3.4s, v2.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x5, x19	; K, k
	bne	L44		;,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v1.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	str	s4, [x9]	;, MEM[(float *)_102]
	mov	x12, x19	; _632, k
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 4	; ivtmp.223, _1978,
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.222, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v4.s}[1], [x1]	;,, MEM[(float *)_106]
	st1	{v4.s}[2], [x4]	;,, MEM[(float *)_108]
	st1	{v4.s}[3], [x8]	;,, MEM[(float *)_113]
L46:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v17.4s}, [x21]	;, *_1265
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.223, ivtmp.223, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q0, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_2226]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.222, ivtmp.222, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v1.4s, v0.4s, v17.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x12, x23	; _632, k
	bne	L46		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x19, x1, 4	; tmp841, ivtmp.299,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v16.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x26, x4, 4	; tmp842, ivtmp.300,
	str	s1, [x9, 4]	;, MEM[(float *)_102 + 4B]
	add	x25, x8, 4	; tmp843, ivtmp.301,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 8	; ivtmp.217, _1978,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v1.s}[1], [x19]	;,, MEM[(float *)_106 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.216, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v1.s}[2], [x26]	;,, MEM[(float *)_108 + 4B]
	st1	{v1.s}[3], [x25]	;,, MEM[(float *)_113 + 4B]
L47:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v6.4s}, [x21]	;, *_1308
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.217, ivtmp.217, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q7, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_2201]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.216, ivtmp.216, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v16.4s, v7.4s, v6.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x23, x12	; k, _632
	bne	L47		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x19, x1, 8	; tmp850, ivtmp.299,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v20.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x26, x4, 8	; tmp851, ivtmp.300,
	str	s16, [x9, 8]	;, MEM[(float *)_102 + 8B]
	add	x25, x8, 8	; tmp852, ivtmp.301,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 12	; ivtmp.211, _1978,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v16.s}[1], [x19]	;,, MEM[(float *)_106 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.210, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v16.s}[2], [x26]	;,, MEM[(float *)_108 + 8B]
	st1	{v16.s}[3], [x25]	;,, MEM[(float *)_113 + 8B]
L48:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v18.4s}, [x21]	;, *_1351
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.211, ivtmp.211, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q19, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_2184]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.210, ivtmp.210, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v20.4s, v19.4s, v18.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x23, x12	; k, _632
	bne	L48		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	fmov	s21, s20	;,
	dup	s22, v20.s[1]	;,,
	dup	s23, v20.s[2]	;,,
	dup	s24, v20.s[3]	;,,
L45:
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s21, [x9, 12]	;, MEM[(float *)_1000 + 12B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s22, [x1, 12]	;, MEM[(float *)_956 + 12B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s23, [x4, 12]	;, MEM[(float *)_913 + 12B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s24, [x8, 12]	;, MEM[(float *)_881 + 12B]
; ../mult/apple/MM_NxN_NEON.hpp:41:         case 4: { mmN4x<4>(a + M8, b + j*K, c + M8 + j*M, M, K, M, K); break; };
	b	L36		;
L25:
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cbz	x5, L154	; K,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v5.4s, 0	;
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x12, 0	; k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x21, x17	; ivtmp.206, _1978
	mov	x19, x13	; ivtmp.205, ivtmp.302
L40:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v3.4s}, [x21]	;, *_1093
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x12, x12, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.206, ivtmp.206, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q4, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_2159]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.205, ivtmp.205, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v5.4s, v4.4s, v3.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x5, x12	; K, k
	bne	L40		;,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v2.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	str	s5, [x9]	;, MEM[(float *)_291]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 4	; ivtmp.200, _1978,
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.199, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v5.s}[1], [x1]	;,, MEM[(float *)_293]
	st1	{v5.s}[2], [x4]	;,, MEM[(float *)_296]
	st1	{v5.s}[3], [x8]	;,, MEM[(float *)_313]
L42:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v0.4s}, [x21]	;, *_1136
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.200, ivtmp.200, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q1, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_2143]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.199, ivtmp.199, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v2.4s, v1.4s, v0.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x12, x23	; _664, k
	bne	L42		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x19, x1, 4	; tmp823, ivtmp.299,
; ../mult/apple/MM_Block84_NEON.hpp:113:     acc[i] = vdupq_n_f32(0.0f);
	movi	v27.4s, 0	;
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	add	x26, x4, 4	; tmp824, ivtmp.300,
	str	s2, [x9, 4]	;, MEM[(float *)_291 + 4B]
	add	x25, x8, 4	; tmp825, ivtmp.301,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x23, 0	; k,
	add	x21, x17, 8	; ivtmp.194, _1978,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v2.s}[1], [x19]	;,, MEM[(float *)_293 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	mov	x19, x13	; ivtmp.193, ivtmp.302
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	st1	{v2.s}[2], [x26]	;,, MEM[(float *)_296 + 4B]
	st1	{v2.s}[3], [x25]	;,, MEM[(float *)_313 + 4B]
L43:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v25.4s}, [x21]	;, *_1179
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x23, x23, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, x6	; ivtmp.194, ivtmp.194, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q26, [x19]	;, MEM <__Float32x4_t> [(float * {ref-all})_2118]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x0	; ivtmp.193, ivtmp.193, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v27.4s, v26.4s, v25.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x12, x23	; _664, k
	bne	L43		;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:2704:   return __aarch64_vget_lane_any (__a, __b);
	fmov	s28, s27	;,
	dup	s29, v27.s[1]	;,,
	dup	s30, v27.s[2]	;,,
	dup	s31, v27.s[3]	;,,
L41:
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s28, [x9, 8]	;, MEM[(float *)_991 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s29, [x1, 8]	;, MEM[(float *)_950 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s30, [x4, 8]	;, MEM[(float *)_907 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s31, [x8, 8]	;, MEM[(float *)_880 + 8B]
; ../mult/apple/MM_NxN_NEON.hpp:40:         case 3: { mmN4x<3>(a + M8, b + j*K, c + M8 + j*M, M, K, M, K); break; };
	b	L36		;
L77:
LCFI10:
; ../mult/apple/MM_Block84_NEON.hpp:72:   for(size_t k{0}; k < K; k++) {
	mov	v23.16b, v24.16b	;,
	b	L10		;
L79:
; ../mult/apple/MM_Block84_NEON.hpp:67:   float32x4_t hi[N] = {};
	mov	v31.16b, v5.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:66:   float32x4_t lo[N] = {};
	mov	v28.16b, v5.16b	;,
	mov	v29.16b, v5.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:67:   float32x4_t hi[N] = {};
	mov	v4.16b, v5.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:66:   float32x4_t lo[N] = {};
	mov	v30.16b, v5.16b	;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:21864:   __builtin_aarch64_st1v4sf ((__builtin_aarch64_simd_sf *) __a, __b);
	stp	q28, q31, [x1]	;,,* ivtmp.362
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:21864:   __builtin_aarch64_st1v4sf ((__builtin_aarch64_simd_sf *) __a, __b);
	str	q29, [x1, x6]	;, MEM <__Float32x4_t> [(float * {ref-all})_394 + _215 * 1]
	str	q4, [x1, x17]	;, MEM <__Float32x4_t> [(float * {ref-all})_394 + _218 * 1]
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:21864:   __builtin_aarch64_st1v4sf ((__builtin_aarch64_simd_sf *) __a, __b);
	stp	q30, q5, [x19]	;,,* ivtmp.364
	b	L9		;
L78:
; ../mult/apple/MM_Block84_NEON.hpp:67:   float32x4_t hi[N] = {};
	mov	v19.16b, v20.16b	;,
; ../mult/apple/MM_Block84_NEON.hpp:66:   float32x4_t lo[N] = {};
	mov	v17.16b, v20.16b	;,
	mov	v18.16b, v20.16b	;,
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:21864:   __builtin_aarch64_st1v4sf ((__builtin_aarch64_simd_sf *) __a, __b);
	stp	q17, q19, [x1]	;,,* ivtmp.362
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:21864:   __builtin_aarch64_st1v4sf ((__builtin_aarch64_simd_sf *) __a, __b);
	str	q18, [x1, x6]	;, MEM <__Float32x4_t> [(float * {ref-all})_395 + _215 * 1]
	str	q20, [x1, x17]	;, MEM <__Float32x4_t> [(float * {ref-all})_395 + _218 * 1]
	b	L9		;
L151:
LCFI11:
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x21, 0	; k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	mov	x19, x17	; ivtmp.178, _1978
	mov	x12, x13	; ivtmp.177, ivtmp.302
L33:
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:10570:   return (float32x4_t) {__a, __a, __a, __a};
	ld1r	{v2.4s}, [x19]	;, MEM[(const float *)_2060]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x21, x21, 1	; k, k,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x19, x19, x6	; ivtmp.178, ivtmp.178, _1571
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:12296:   return __builtin_aarch64_ld1v4sf ((const __builtin_aarch64_simd_sf *) __a);
	ldr	q3, [x12]	;, MEM <__Float32x4_t> [(float * {ref-all})_2051]
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	add	x12, x12, x0	; ivtmp.177, ivtmp.177, _1598
; /opt/homebrew/Cellar/gcc/16.1.0/lib/gcc/current/gcc/aarch64-apple-darwin25/16/include/arm_neon.h:11667:   return __builtin_aarch64_fmav4sf (__b, vdupq_n_f32 (__c), __a);
	fmla	v20.4s, v3.4s, v2.4s	;,,
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	cmp	x5, x21	; K, k
	bne	L33		;,
	b	L34		;
L154:
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	movi	v31.2s, #0	;
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	wzr, [x9]	;, MEM[(float *)_224]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s31, [x1]	;, MEM[(float *)_228]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	fmov	s30, s31	;,
	fmov	s29, s31	;,
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s31, [x4]	;, MEM[(float *)_231]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	fmov	s28, s31	;,
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s31, [x8]	;, MEM[(float *)_234]
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s31, [x9, 4]	;, MEM[(float *)_224 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s31, [x1, 4]	; tmp61, MEM[(float *)_228 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s31, [x4, 4]	; tmp60, MEM[(float *)_231 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s31, [x8, 4]	; tmp60, MEM[(float *)_234 + 4B]
	b	L41		;
L153:
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	movi	v24.2s, #0	;
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	wzr, [x9]	;, MEM[(float *)_30]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s24, [x1]	;, MEM[(float *)_35]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	fmov	s23, s24	;,
	fmov	s22, s24	;,
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s24, [x4]	;, MEM[(float *)_48]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	fmov	s21, s24	;,
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s24, [x8]	;, MEM[(float *)_57]
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s24, [x9, 4]	;, MEM[(float *)_30 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s24, [x1, 4]	; tmp54, MEM[(float *)_35 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s24, [x4, 4]	; tmp53, MEM[(float *)_48 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s24, [x8, 4]	; tmp53, MEM[(float *)_57 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s24, [x9, 8]	; tmp53, MEM[(float *)_30 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s24, [x1, 8]	; tmp53, MEM[(float *)_35 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s24, [x4, 8]	; tmp53, MEM[(float *)_48 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s24, [x8, 8]	; tmp53, MEM[(float *)_57 + 8B]
	b	L45		;
L152:
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	movi	v20.2s, #0	;
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	wzr, [x9]	;, MEM[(float *)_2393]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s20, [x1]	;, MEM[(float *)_2391]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	fmov	s19, s20	;,
	fmov	s18, s20	;,
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s20, [x4]	;, MEM[(float *)_2389]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	fmov	s17, s20	;,
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s20, [x8]	;, MEM[(float *)_2387]
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s20, [x9, 4]	;, MEM[(float *)_2393 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s20, [x1, 4]	; tmp50, MEM[(float *)_2391 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s20, [x4, 4]	; tmp49, MEM[(float *)_2389 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s20, [x8, 4]	; tmp49, MEM[(float *)_2387 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s20, [x9, 8]	; tmp49, MEM[(float *)_2393 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s20, [x1, 8]	; tmp49, MEM[(float *)_2391 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s20, [x4, 8]	; tmp49, MEM[(float *)_2389 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s20, [x8, 8]	; tmp49, MEM[(float *)_2387 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s20, [x9, 12]	; tmp49, MEM[(float *)_2393 + 12B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s20, [x1, 12]	; tmp49, MEM[(float *)_2391 + 12B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s20, [x4, 12]	; tmp49, MEM[(float *)_2389 + 12B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s20, [x8, 12]	; tmp49, MEM[(float *)_2387 + 12B]
	b	L50		;
L80:
; ../mult/apple/MM_Block84_NEON.hpp:114:     for(size_t k{0}; k < K; k++) {
	movi	v24.2s, #0	;
	fmov	s23, s24	;,
	fmov	s22, s24	;,
	fmov	s21, s24	;,
	b	L31		;
L150:
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	movi	v24.2s, #0	;
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	wzr, [x9]	;, MEM[(float *)_2064]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s24, [x1]	;, MEM[(float *)_998]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	fmov	s23, s24	;,
	fmov	s22, s24	;,
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s24, [x4]	;, MEM[(float *)_724]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	fmov	s21, s24	;,
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s24, [x8]	;, MEM[(float *)_2036]
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s24, [x9, 4]	;, MEM[(float *)_2064 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s24, [x1, 4]	; tmp54, MEM[(float *)_998 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s24, [x4, 4]	; tmp53, MEM[(float *)_724 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s24, [x8, 4]	; tmp53, MEM[(float *)_2036 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s24, [x9, 8]	; tmp53, MEM[(float *)_2064 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s24, [x1, 8]	; tmp53, MEM[(float *)_998 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s24, [x4, 8]	; tmp53, MEM[(float *)_724 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s24, [x8, 8]	; tmp53, MEM[(float *)_2036 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s24, [x9, 12]	; tmp53, MEM[(float *)_2064 + 12B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s24, [x1, 12]	; tmp53, MEM[(float *)_998 + 12B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s24, [x4, 12]	; tmp53, MEM[(float *)_724 + 12B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s24, [x8, 12]	; tmp53, MEM[(float *)_2036 + 12B]
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s24, [x9, 16]	; tmp53, MEM[(float *)_2064 + 16B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s24, [x1, 16]	; tmp53, MEM[(float *)_998 + 16B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s24, [x4, 16]	; tmp53, MEM[(float *)_724 + 16B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s24, [x8, 16]	; tmp53, MEM[(float *)_2036 + 16B]
	b	L56		;
L149:
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	movi	v29.2s, #0	;
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	wzr, [x9]	;, MEM[(float *)_1875]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s29, [x1]	;, MEM[(float *)_1820]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	fmov	s28, s29	;,
	fmov	s31, s29	;,
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s29, [x4]	;, MEM[(float *)_1786]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	fmov	s30, s29	;,
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s29, [x8]	;, MEM[(float *)_1745]
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s29, [x9, 4]	;, MEM[(float *)_1875 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s29, [x1, 4]	; tmp60, MEM[(float *)_1820 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s29, [x4, 4]	; tmp60, MEM[(float *)_1786 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s29, [x8, 4]	; tmp60, MEM[(float *)_1745 + 4B]
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s29, [x9, 8]	; tmp60, MEM[(float *)_1875 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s29, [x1, 8]	; tmp60, MEM[(float *)_1820 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s29, [x4, 8]	; tmp60, MEM[(float *)_1786 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s29, [x8, 8]	; tmp60, MEM[(float *)_1745 + 8B]
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s29, [x9, 12]	; tmp60, MEM[(float *)_1875 + 12B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s29, [x1, 12]	; tmp60, MEM[(float *)_1820 + 12B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s29, [x4, 12]	; tmp60, MEM[(float *)_1786 + 12B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s29, [x8, 12]	; tmp60, MEM[(float *)_1745 + 12B]
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s29, [x9, 16]	; tmp60, MEM[(float *)_1875 + 16B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s29, [x1, 16]	; tmp60, MEM[(float *)_1820 + 16B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s29, [x4, 16]	; tmp60, MEM[(float *)_1786 + 16B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s29, [x8, 16]	; tmp60, MEM[(float *)_1745 + 16B]
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s29, [x9, 20]	; tmp60, MEM[(float *)_1875 + 20B]
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s29, [x1, 20]	; tmp60, MEM[(float *)_1820 + 20B]
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s29, [x4, 20]	; tmp60, MEM[(float *)_1786 + 20B]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s29, [x8, 20]	; tmp60, MEM[(float *)_1745 + 20B]
	b	L63		;
L146:
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	movi	v31.2s, #0	;
; ../mult/apple/MM_Block84_NEON.hpp:118:     c[i]        = vgetq_lane_f32(acc[i], 0);
	str	s31, [x9]	;, MEM[(float *)_563]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	fmov	s30, s31	;,
	fmov	s29, s31	;,
; ../mult/apple/MM_Block84_NEON.hpp:119:     c[i+ldc]    = vgetq_lane_f32(acc[i], 1);
	str	s31, [x1]	;, MEM[(float *)_692]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	fmov	s28, s31	;,
; ../mult/apple/MM_Block84_NEON.hpp:120:     c[i+2*ldc]  = vgetq_lane_f32(acc[i], 2);
	str	s31, [x4]	;, MEM[(float *)_707]
; ../mult/apple/MM_Block84_NEON.hpp:121:     c[i+3*ldc]  = vgetq_lane_f32(acc[i], 3);
	str	s31, [x8]	;, MEM[(float *)_709]
	b	L38		;
L147:
	lsl	x15, x3, 4	; _1220, M,
	lsl	x16, x5, 4	; _1123, K,
	lsl	x0, x5, 2	; _1598, K,
	b	L20		;
LFE4658:
	.section __TEXT,__text_startup,regular,pure_instructions
	.align	2
	.p2align 5,,15
	.globl _main
_main:
LFB4659:
; mm_bench.cpp:21: }
	mov	w0, 0	;,
	ret	
LFE4659:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x3
	.ascii "zR\0"
	.uleb128 0x1
	.sleb128 -8
	.uleb128 0x1e
	.uleb128 0x1
	.byte	0x10
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB4658-.
	.set L$set$2,LFE4658-LFB4658
	.quad L$set$2
	.uleb128 0
	.byte	0x4
	.set L$set$3,LCFI0-LFB4658
	.long L$set$3
	.byte	0xe
	.uleb128 0x80
	.byte	0x9d
	.uleb128 0x10
	.byte	0x9e
	.uleb128 0xf
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0x93
	.uleb128 0xe
	.byte	0x94
	.uleb128 0xd
	.byte	0x95
	.uleb128 0xc
	.byte	0x96
	.uleb128 0xb
	.byte	0x4
	.set L$set$5,LCFI2-LCFI1
	.long L$set$5
	.byte	0x97
	.uleb128 0xa
	.byte	0x98
	.uleb128 0x9
	.byte	0x4
	.set L$set$6,LCFI3-LCFI2
	.long L$set$6
	.byte	0x99
	.uleb128 0x8
	.byte	0x9a
	.uleb128 0x7
	.byte	0x4
	.set L$set$7,LCFI4-LCFI3
	.long L$set$7
	.byte	0x9c
	.uleb128 0x5
	.byte	0x9b
	.uleb128 0x6
	.byte	0x4
	.set L$set$8,LCFI5-LCFI4
	.long L$set$8
	.byte	0xdc
	.byte	0xdb
	.byte	0x4
	.set L$set$9,LCFI6-LCFI5
	.long L$set$9
	.byte	0x9b
	.uleb128 0x6
	.byte	0x9c
	.uleb128 0x5
	.byte	0x4
	.set L$set$10,LCFI7-LCFI6
	.long L$set$10
	.byte	0xdb
	.byte	0xdc
	.byte	0x4
	.set L$set$11,LCFI8-LCFI7
	.long L$set$11
	.byte	0xa
	.byte	0xde
	.byte	0xdd
	.byte	0xd9
	.byte	0xda
	.byte	0xd7
	.byte	0xd8
	.byte	0xd5
	.byte	0xd6
	.byte	0xd3
	.byte	0xd4
	.byte	0xe
	.uleb128 0
	.byte	0x4
	.set L$set$12,LCFI9-LCFI8
	.long L$set$12
	.byte	0xb
	.byte	0x4
	.set L$set$13,LCFI10-LCFI9
	.long L$set$13
	.byte	0x9b
	.uleb128 0x6
	.byte	0x9c
	.uleb128 0x5
	.byte	0x4
	.set L$set$14,LCFI11-LCFI10
	.long L$set$14
	.byte	0xdb
	.byte	0xdc
	.align	3
LEFDE1:
LSFDE3:
	.set L$set$15,LEFDE3-LASFDE3
	.long L$set$15
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB4659-.
	.set L$set$16,LFE4659-LFB4659
	.quad L$set$16
	.uleb128 0
	.align	3
LEFDE3:
	.ident	"GCC: (Homebrew GCC 16.1.0) 16.1.0"
	.subsections_via_symbols
