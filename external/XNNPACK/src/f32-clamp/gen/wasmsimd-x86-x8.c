// Auto-generated file. Do not edit!
//   Template: src/f32-clamp/wasmsimd.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <wasm_simd128.h>

#include <xnnpack/clamp.h>
#include <xnnpack/common.h>


void xnn_f32_clamp_ukernel__wasmsimd_x86_x8(
    size_t n,
    const float* x,
    float* y,
    const union xnn_f32_minmax_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_DISABLE_TSAN
{
  assert(n != 0);
  assert(n % sizeof(float) == 0);
  assert(x != NULL);
  assert(y != NULL);

  const v128_t vy_min = wasm_v32x4_load_splat(&params->scalar.min);
  const v128_t vy_max = wasm_v32x4_load_splat(&params->scalar.max);

  for (; n >= 8 * sizeof(float); n -= 8 * sizeof(float)) {
    v128_t vacc0123 = wasm_v128_load(x);
    v128_t vacc4567 = wasm_v128_load(x + 4);
    x += 8;

    const v128_t vmaskmin0123 = wasm_f32x4_lt(vacc0123, vy_min);
    const v128_t vmaskmin4567 = wasm_f32x4_lt(vacc4567, vy_min);

    const v128_t vmaskmax0123 = wasm_f32x4_le(vy_max, vacc0123);
    vacc0123 = wasm_v128_bitselect(vy_min, vacc0123, vmaskmin0123);
    const v128_t vmaskmax4567 = wasm_f32x4_le(vy_max, vacc4567);
    vacc4567 = wasm_v128_bitselect(vy_min, vacc4567, vmaskmin4567);

    vacc0123 = wasm_v128_bitselect(vy_max, vacc0123, vmaskmax0123);
    vacc4567 = wasm_v128_bitselect(vy_max, vacc4567, vmaskmax4567);

    wasm_v128_store(y, vacc0123);
    wasm_v128_store(y + 4, vacc4567);
    y += 8;
  }
  for (; n >= 4 * sizeof(float); n -= 4 * sizeof(float)) {
    v128_t vacc = wasm_v128_load(x);
    x += 4;

    const v128_t vmaskmin = wasm_f32x4_lt(vacc, vy_min);
    const v128_t vmaskmax = wasm_f32x4_le(vy_max, vacc);
    vacc = wasm_v128_bitselect(vy_min, vacc, vmaskmin);
    vacc = wasm_v128_bitselect(vy_max, vacc, vmaskmax);

    wasm_v128_store(y, vacc);
    y += 4;
  }
  if XNN_UNLIKELY(n != 0) {
    v128_t vacc = wasm_v128_load(x);

    const v128_t vmaskmin = wasm_f32x4_lt(vacc, vy_min);
    const v128_t vmaskmax = wasm_f32x4_le(vy_max, vacc);
    vacc = wasm_v128_bitselect(vy_min, vacc, vmaskmin);
    vacc = wasm_v128_bitselect(vy_max, vacc, vmaskmax);

    if (n & (2 * sizeof(float))) {
      *((double*) y) = wasm_f64x2_extract_lane(vacc, 0);
      vacc = wasm_v32x4_shuffle(vacc, vacc, 2, 3, 2, 3);
      y += 2;
    }
    if (n & (1 * sizeof(float))) {
      *y = wasm_f32x4_extract_lane(vacc, 0);
    }
  }
}
