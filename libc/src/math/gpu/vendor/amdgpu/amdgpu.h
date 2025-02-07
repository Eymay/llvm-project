//===-- AMDGPU specific definitions for math support ----------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_SRC_MATH_GPU_AMDGPU_H
#define LLVM_LIBC_SRC_MATH_GPU_AMDGPU_H

#include "declarations.h"
#include "platform.h"

#include "src/__support/macros/attributes.h"

namespace __llvm_libc {
namespace internal {
LIBC_INLINE float acosf(float x) { return __ocml_acos_f32(x); }
LIBC_INLINE float acoshf(float x) { return __ocml_acosh_f32(x); }
LIBC_INLINE float asinf(float x) { return __ocml_asin_f32(x); }
LIBC_INLINE float asinhf(float x) { return __ocml_asinh_f32(x); }
LIBC_INLINE float atanf(float x) { return __ocml_atan_f32(x); }
LIBC_INLINE float atanhf(float x) { return __ocml_atanh_f32(x); }
LIBC_INLINE double cos(double x) { return __ocml_cos_f64(x); }
LIBC_INLINE float cosf(float x) { return __ocml_cos_f32(x); }
LIBC_INLINE double cosh(double x) { return __ocml_cosh_f64(x); }
LIBC_INLINE float coshf(float x) { return __ocml_cosh_f32(x); }
LIBC_INLINE float expf(float x) { return __builtin_expf(x); }
LIBC_INLINE float exp2f(float x) { return __builtin_exp2f(x); }
LIBC_INLINE float exp10f(float x) { return __ocml_exp10_f32(x); }
LIBC_INLINE float expm1f(float x) { return __ocml_expm1_f32(x); }
LIBC_INLINE double fdim(double x, double y) { return __ocml_fdim_f64(x, y); }
LIBC_INLINE float fdimf(float x, float y) { return __ocml_fdim_f32(x, y); }
LIBC_INLINE double hypot(double x, double y) { return __ocml_hypot_f64(x, y); }
LIBC_INLINE float hypotf(float x, float y) { return __ocml_hypot_f32(x, y); }
LIBC_INLINE int ilogb(double x) { return __ocml_ilogb_f64(x); }
LIBC_INLINE int ilogbf(float x) { return __ocml_ilogb_f32(x); }
LIBC_INLINE double ldexp(double x, int i) { return __builtin_ldexp(x, i); }
LIBC_INLINE float ldexpf(float x, int i) { return __builtin_ldexpf(x, i); }
LIBC_INLINE long long llrint(double x) { return __builtin_rint(x); }
LIBC_INLINE long long llrintf(float x) { return __builtin_rintf(x); }
LIBC_INLINE long long llround(double x) { return __builtin_round(x); }
LIBC_INLINE long long llroundf(float x) { return __builtin_roundf(x); }
LIBC_INLINE double pow(double x, double y) { return __ocml_pow_f64(x, y); }
LIBC_INLINE float powf(float x, float y) { return __ocml_pow_f32(x, y); }
LIBC_INLINE double sin(double x) { return __ocml_sin_f64(x); }

} // namespace internal
} // namespace __llvm_libc

#endif // LLVM_LIBC_SRC_MATH_GPU_AMDGPU_H
