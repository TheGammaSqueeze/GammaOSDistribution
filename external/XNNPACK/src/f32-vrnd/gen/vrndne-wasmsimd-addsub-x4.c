// Auto-generated file. Do not edit!
//   Template: src/f32-vrnd/vrndne-wasmsimd-addsub.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <wasm_simd128.h>

#include <xnnpack/common.h>
#include <xnnpack/math.h>
#include <xnnpack/vunary.h>


void xnn_f32_vrndne_ukernel__wasmsimd_addsub_x4(
    size_t n,
    const float* x,
    float* y,
    const union xnn_f32_rnd_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_DISABLE_TSAN
{
  assert(n != 0);
  assert(n % sizeof(float) == 0);

  const v128_t vsign_mask = wasm_f32x4_splat(-0.0f);
  const v128_t vmagic_number = wasm_f32x4_splat(0x1.000000p+23f);
  for (; n >= 4 * sizeof(float); n -= 4 * sizeof(float)) {
    const v128_t vx = wasm_v128_load(x);
    x += 4;

    const v128_t vabsx = wasm_v128_andnot(vx, vsign_mask);
    const v128_t vrndmask = wasm_v128_or(vsign_mask, wasm_f32x4_le(vmagic_number, vabsx));
    const v128_t vrndabsx = wasm_f32x4_sub(wasm_f32x4_add(vabsx, vmagic_number), vmagic_number);
    const v128_t vy = wasm_v128_bitselect(vx, vrndabsx, vrndmask);

    wasm_v128_store(y, vy);
    y += 4;
  }
  if XNN_UNLIKELY(n != 0) {
    const v128_t vx = wasm_v128_load(x);

    const v128_t vabsx = wasm_v128_andnot(vx, vsign_mask);
    const v128_t vrndmask = wasm_v128_or(vsign_mask, wasm_f32x4_le(vmagic_number, vabsx));
    const v128_t vrndabsx = wasm_f32x4_sub(wasm_f32x4_add(vabsx, vmagic_number), vmagic_number);
    v128_t vy = wasm_v128_bitselect(vx, vrndabsx, vrndmask);

    if (n & (2 * sizeof(float))) {
      *((double*) y) = wasm_f64x2_extract_lane(vy, 0);
      vy = wasm_v32x4_shuffle(vy, vy, 2, 3, 2, 3);
      y += 2;
    }
    if (n & (1 * sizeof(float))) {
      *y = wasm_f32x4_extract_lane(vy, 0);
    }
  }
}
