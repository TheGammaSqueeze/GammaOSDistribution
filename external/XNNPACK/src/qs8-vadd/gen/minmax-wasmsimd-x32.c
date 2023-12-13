// Auto-generated file. Do not edit!
//   Template: src/qs8-vadd/wasmsimd.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <wasm_simd128.h>

#include <xnnpack/vadd.h>


void xnn_qs8_vadd_minmax_ukernel__wasmsimd_x32(
    size_t n,
    const int8_t* input_x,
    const int8_t* input_y,
    int8_t* output,
    const union xnn_qs8_add_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_DISABLE_TSAN
{
  const v128_t vzero_point_product = wasm_v128_load(params->wasmsimd.zero_point_product);
  const v128_t vx_multiplier = wasm_v128_load(params->wasmsimd.x_multiplier);
  const v128_t vy_multiplier = wasm_v128_load(params->wasmsimd.y_multiplier);
  const v128_t vremainder_mask = wasm_v128_load(params->wasmsimd.remainder_mask);
  const v128_t vremainder_threshold = wasm_v128_load(params->wasmsimd.remainder_threshold);
  const int32_t vshift = params->wasmsimd.shift;
  const v128_t voutput_zero_point = wasm_v128_load(params->wasmsimd.output_zero_point);
  const v128_t voutput_min = wasm_v128_load(params->wasmsimd.output_min);
  const v128_t voutput_max = wasm_v128_load(params->wasmsimd.output_max);

  for (; n >= 32 * sizeof(int8_t); n -= 32 * sizeof(int8_t)) {
    const v128_t vx01234567 = wasm_i16x8_load_8x8(input_x);
    const v128_t vy01234567 = wasm_i16x8_load_8x8(input_y);
    const v128_t vx89ABCDEF = wasm_i16x8_load_8x8(input_x + 8);
    const v128_t vy89ABCDEF = wasm_i16x8_load_8x8(input_y + 8);
    const v128_t vxGHIJKLMN = wasm_i16x8_load_8x8(input_x + 16);
    const v128_t vyGHIJKLMN = wasm_i16x8_load_8x8(input_y + 16);
    const v128_t vxOPQRSTUV = wasm_i16x8_load_8x8(input_x + 24);
    const v128_t vyOPQRSTUV = wasm_i16x8_load_8x8(input_y + 24);
    input_x += 32;
    input_y += 32;

    v128_t vacc0123 = wasm_i32x4_add(vzero_point_product, wasm_i32x4_mul(wasm_i32x4_widen_low_i16x8(vx01234567), vx_multiplier));
    v128_t vacc4567 = wasm_i32x4_add(vzero_point_product, wasm_i32x4_mul(wasm_i32x4_widen_high_i16x8(vx01234567), vx_multiplier));
    v128_t vacc89AB = wasm_i32x4_add(vzero_point_product, wasm_i32x4_mul(wasm_i32x4_widen_low_i16x8(vx89ABCDEF), vx_multiplier));
    v128_t vaccCDEF = wasm_i32x4_add(vzero_point_product, wasm_i32x4_mul(wasm_i32x4_widen_high_i16x8(vx89ABCDEF), vx_multiplier));
    v128_t vaccGHIJ = wasm_i32x4_add(vzero_point_product, wasm_i32x4_mul(wasm_i32x4_widen_low_i16x8(vxGHIJKLMN), vx_multiplier));
    v128_t vaccKLMN = wasm_i32x4_add(vzero_point_product, wasm_i32x4_mul(wasm_i32x4_widen_high_i16x8(vxGHIJKLMN), vx_multiplier));
    v128_t vaccOPQR = wasm_i32x4_add(vzero_point_product, wasm_i32x4_mul(wasm_i32x4_widen_low_i16x8(vxOPQRSTUV), vx_multiplier));
    v128_t vaccSTUV = wasm_i32x4_add(vzero_point_product, wasm_i32x4_mul(wasm_i32x4_widen_high_i16x8(vxOPQRSTUV), vx_multiplier));

    vacc0123 = wasm_i32x4_add(vacc0123, wasm_i32x4_mul(wasm_i32x4_widen_low_i16x8(vy01234567), vy_multiplier));
    vacc4567 = wasm_i32x4_add(vacc4567, wasm_i32x4_mul(wasm_i32x4_widen_high_i16x8(vy01234567), vy_multiplier));
    vacc89AB = wasm_i32x4_add(vacc89AB, wasm_i32x4_mul(wasm_i32x4_widen_low_i16x8(vy89ABCDEF), vy_multiplier));
    vaccCDEF = wasm_i32x4_add(vaccCDEF, wasm_i32x4_mul(wasm_i32x4_widen_high_i16x8(vy89ABCDEF), vy_multiplier));
    vaccGHIJ = wasm_i32x4_add(vaccGHIJ, wasm_i32x4_mul(wasm_i32x4_widen_low_i16x8(vyGHIJKLMN), vy_multiplier));
    vaccKLMN = wasm_i32x4_add(vaccKLMN, wasm_i32x4_mul(wasm_i32x4_widen_high_i16x8(vyGHIJKLMN), vy_multiplier));
    vaccOPQR = wasm_i32x4_add(vaccOPQR, wasm_i32x4_mul(wasm_i32x4_widen_low_i16x8(vyOPQRSTUV), vy_multiplier));
    vaccSTUV = wasm_i32x4_add(vaccSTUV, wasm_i32x4_mul(wasm_i32x4_widen_high_i16x8(vyOPQRSTUV), vy_multiplier));

    const v128_t vrem0123 = wasm_i32x4_add(wasm_v128_and(vacc0123, vremainder_mask), wasm_i32x4_shr(vacc0123, 31));
    const v128_t vrem4567 = wasm_i32x4_add(wasm_v128_and(vacc4567, vremainder_mask), wasm_i32x4_shr(vacc4567, 31));
    const v128_t vrem89AB = wasm_i32x4_add(wasm_v128_and(vacc89AB, vremainder_mask), wasm_i32x4_shr(vacc89AB, 31));
    const v128_t vremCDEF = wasm_i32x4_add(wasm_v128_and(vaccCDEF, vremainder_mask), wasm_i32x4_shr(vaccCDEF, 31));
    const v128_t vremGHIJ = wasm_i32x4_add(wasm_v128_and(vaccGHIJ, vremainder_mask), wasm_i32x4_shr(vaccGHIJ, 31));
    const v128_t vremKLMN = wasm_i32x4_add(wasm_v128_and(vaccKLMN, vremainder_mask), wasm_i32x4_shr(vaccKLMN, 31));
    const v128_t vremOPQR = wasm_i32x4_add(wasm_v128_and(vaccOPQR, vremainder_mask), wasm_i32x4_shr(vaccOPQR, 31));
    const v128_t vremSTUV = wasm_i32x4_add(wasm_v128_and(vaccSTUV, vremainder_mask), wasm_i32x4_shr(vaccSTUV, 31));

    vacc0123 = wasm_i32x4_sub(wasm_i32x4_shr(vacc0123, vshift), wasm_i32x4_gt(vrem0123, vremainder_threshold));
    vacc4567 = wasm_i32x4_sub(wasm_i32x4_shr(vacc4567, vshift), wasm_i32x4_gt(vrem4567, vremainder_threshold));
    vacc89AB = wasm_i32x4_sub(wasm_i32x4_shr(vacc89AB, vshift), wasm_i32x4_gt(vrem89AB, vremainder_threshold));
    vaccCDEF = wasm_i32x4_sub(wasm_i32x4_shr(vaccCDEF, vshift), wasm_i32x4_gt(vremCDEF, vremainder_threshold));
    vaccGHIJ = wasm_i32x4_sub(wasm_i32x4_shr(vaccGHIJ, vshift), wasm_i32x4_gt(vremGHIJ, vremainder_threshold));
    vaccKLMN = wasm_i32x4_sub(wasm_i32x4_shr(vaccKLMN, vshift), wasm_i32x4_gt(vremKLMN, vremainder_threshold));
    vaccOPQR = wasm_i32x4_sub(wasm_i32x4_shr(vaccOPQR, vshift), wasm_i32x4_gt(vremOPQR, vremainder_threshold));
    vaccSTUV = wasm_i32x4_sub(wasm_i32x4_shr(vaccSTUV, vshift), wasm_i32x4_gt(vremSTUV, vremainder_threshold));

    v128_t vout01234567 = wasm_i16x8_add_saturate(wasm_i16x8_narrow_i32x4(vacc0123, vacc4567), voutput_zero_point);
    v128_t vout89ABCDEF = wasm_i16x8_add_saturate(wasm_i16x8_narrow_i32x4(vacc89AB, vaccCDEF), voutput_zero_point);
    v128_t voutGHIJKLMN = wasm_i16x8_add_saturate(wasm_i16x8_narrow_i32x4(vaccGHIJ, vaccKLMN), voutput_zero_point);
    v128_t voutOPQRSTUV = wasm_i16x8_add_saturate(wasm_i16x8_narrow_i32x4(vaccOPQR, vaccSTUV), voutput_zero_point);

    v128_t vout0123456789ABCDEF = wasm_i8x16_narrow_i16x8(vout01234567, vout89ABCDEF);
    v128_t voutGHIJKLMNOPQRSTUV = wasm_i8x16_narrow_i16x8(voutGHIJKLMN, voutOPQRSTUV);

    vout0123456789ABCDEF = wasm_i8x16_max(vout0123456789ABCDEF, voutput_min);
    voutGHIJKLMNOPQRSTUV = wasm_i8x16_max(voutGHIJKLMNOPQRSTUV, voutput_min);

    vout0123456789ABCDEF = wasm_i8x16_min(vout0123456789ABCDEF, voutput_max);
    voutGHIJKLMNOPQRSTUV = wasm_i8x16_min(voutGHIJKLMNOPQRSTUV, voutput_max);

    wasm_v128_store(output, vout0123456789ABCDEF);
    wasm_v128_store(output + 16, voutGHIJKLMNOPQRSTUV);
    output += 32;
  }
  if XNN_UNLIKELY(n != 0) {
    do {
      const v128_t vx01234567 = wasm_i16x8_load_8x8(input_x);
      const v128_t vy01234567 = wasm_i16x8_load_8x8(input_y);
      input_x += 8;
      input_y += 8;

      v128_t vacc0123 = wasm_i32x4_add(vzero_point_product, wasm_i32x4_mul(wasm_i32x4_widen_low_i16x8(vx01234567), vx_multiplier));
      v128_t vacc4567 = wasm_i32x4_add(vzero_point_product, wasm_i32x4_mul(wasm_i32x4_widen_high_i16x8(vx01234567), vx_multiplier));

      vacc0123 = wasm_i32x4_add(vacc0123, wasm_i32x4_mul(wasm_i32x4_widen_low_i16x8(vy01234567), vy_multiplier));
      vacc4567 = wasm_i32x4_add(vacc4567, wasm_i32x4_mul(wasm_i32x4_widen_high_i16x8(vy01234567), vy_multiplier));

      const v128_t vrem0123 = wasm_i32x4_add(wasm_v128_and(vacc0123, vremainder_mask), wasm_i32x4_shr(vacc0123, 31));
      const v128_t vrem4567 = wasm_i32x4_add(wasm_v128_and(vacc4567, vremainder_mask), wasm_i32x4_shr(vacc4567, 31));

      vacc0123 = wasm_i32x4_sub(wasm_i32x4_shr(vacc0123, vshift), wasm_i32x4_gt(vrem0123, vremainder_threshold));
      vacc4567 = wasm_i32x4_sub(wasm_i32x4_shr(vacc4567, vshift), wasm_i32x4_gt(vrem4567, vremainder_threshold));

      v128_t vout01234567 = wasm_i16x8_add_saturate(wasm_i16x8_narrow_i32x4(vacc0123, vacc4567), voutput_zero_point);

      v128_t vout0123456701234567 = wasm_i8x16_narrow_i16x8(vout01234567, vout01234567);
      vout0123456701234567 = wasm_i8x16_max(vout0123456701234567, voutput_min);
      vout0123456701234567 = wasm_i8x16_min(vout0123456701234567, voutput_max);

      if XNN_LIKELY(n >= (8 * sizeof(int8_t))) {
        *((double*) output) = wasm_f64x2_extract_lane(vout0123456701234567, 0);
        output += 8;
        n -= 8 * sizeof(int8_t);
      } else {
        if (n & (4 * sizeof(int8_t))) {
          *((uint32_t*) output) = (uint32_t) wasm_i32x4_extract_lane(vout0123456701234567, 0);
          vout0123456701234567 = wasm_u64x2_shr(vout0123456701234567, 32);
          output += 4;
        }
        if (n & (2 * sizeof(int8_t))) {
          *((uint16_t*) output) = (uint16_t) wasm_i16x8_extract_lane(vout0123456701234567, 0);
          vout0123456701234567 = wasm_u32x4_shr(vout0123456701234567, 16);
          output += 2;
        }
        if (n & (1 * sizeof(int8_t))) {
          *output = wasm_i8x16_extract_lane(vout0123456701234567, 0);
        }
        n = 0;
      }
    } while (n != 0);
  }
}
