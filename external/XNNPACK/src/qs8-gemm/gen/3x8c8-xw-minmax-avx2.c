// Auto-generated file. Do not edit!
//   Template: src/qs8-gemm/MRx8c8-avx2.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <immintrin.h>

#include <xnnpack/gemm.h>
#include <xnnpack/intrinsics-polyfill.h>
#include <xnnpack/math.h>


void xnn_qs8_gemm_xw_minmax_ukernel_3x8c8__avx2(
    size_t mr,
    size_t nc,
    size_t kc,
    const int8_t* restrict a,
    size_t a_stride,
    const void* restrict w,
    int8_t* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    const union xnn_qs8_gemm_xw_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_DISABLE_TSAN
{
  assert(mr != 0);
  assert(mr <= 3);
  assert(nc != 0);
  assert(kc != 0);
  assert(kc % sizeof(int8_t) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);

  kc = round_up_po2(kc, 8);
  const int8_t* a0 = a;
  int8_t* c0 = c;
  const int8_t* a1 = (const int8_t*) ((uintptr_t) a0 + a_stride);
  int8_t* c1 = (int8_t*) ((uintptr_t) c0 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 2) {
    a1 = a0;
    c1 = c0;
  }
  const int8_t* a2 = (const int8_t*) ((uintptr_t) a1 + a_stride);
  int8_t* c2 = (int8_t*) ((uintptr_t) c1 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 2) {
    a2 = a1;
    c2 = c1;
  }

  do {
    const __m128i vbias0x0 = _mm_loadu_si32(w);
    const __m128i vbias0x1 = _mm_loadu_si32((const void*) ((uintptr_t) w + sizeof(int32_t)));
    __m256i vacc0x01 = _mm256_inserti128_si256(_mm256_castsi128_si256(vbias0x0), vbias0x1, 1);
    const __m128i vbias0x2 = _mm_loadu_si32((const void*) ((uintptr_t) w + 2 * sizeof(int32_t)));
    const __m128i vbias0x3 = _mm_loadu_si32((const void*) ((uintptr_t) w + 3 * sizeof(int32_t)));
    __m256i vacc0x23 = _mm256_inserti128_si256(_mm256_castsi128_si256(vbias0x2), vbias0x3, 1);
    const __m128i vbias0x4 = _mm_loadu_si32((const void*) ((uintptr_t) w + 4 * sizeof(int32_t)));
    const __m128i vbias0x5 = _mm_loadu_si32((const void*) ((uintptr_t) w + 5 * sizeof(int32_t)));
    __m256i vacc0x45 = _mm256_inserti128_si256(_mm256_castsi128_si256(vbias0x4), vbias0x5, 1);
    const __m128i vbias0x6 = _mm_loadu_si32((const void*) ((uintptr_t) w + 6 * sizeof(int32_t)));
    const __m128i vbias0x7 = _mm_loadu_si32((const void*) ((uintptr_t) w + 7 * sizeof(int32_t)));
    __m256i vacc0x67 = _mm256_inserti128_si256(_mm256_castsi128_si256(vbias0x6), vbias0x7, 1);
    __m256i vacc1x01 = vacc0x01;
    __m256i vacc1x23 = vacc0x23;
    __m256i vacc1x45 = vacc0x45;
    __m256i vacc1x67 = vacc0x67;
    __m256i vacc2x01 = vacc0x01;
    __m256i vacc2x23 = vacc0x23;
    __m256i vacc2x45 = vacc0x45;
    __m256i vacc2x67 = vacc0x67;
    w = (const void*) ((uintptr_t) w + 8 * sizeof(int32_t));

    size_t k = 0;
    while (k < kc) {
      const __m128i va0 = _mm_broadcastq_epi64(_mm_loadl_epi64((const __m128i*) a0));
      const __m256i vxa0 = _mm256_cvtepi8_epi16(va0);
      a0 += 8;
      const __m128i va1 = _mm_broadcastq_epi64(_mm_loadl_epi64((const __m128i*) a1));
      const __m256i vxa1 = _mm256_cvtepi8_epi16(va1);
      a1 += 8;
      const __m128i va2 = _mm_broadcastq_epi64(_mm_loadl_epi64((const __m128i*) a2));
      const __m256i vxa2 = _mm256_cvtepi8_epi16(va2);
      a2 += 8;

      const __m256i vxb01 = _mm256_load_si256((const __m256i*) w);

      vacc0x01 = _mm256_add_epi32(vacc0x01, _mm256_madd_epi16(vxa0, vxb01));
      vacc1x01 = _mm256_add_epi32(vacc1x01, _mm256_madd_epi16(vxa1, vxb01));
      vacc2x01 = _mm256_add_epi32(vacc2x01, _mm256_madd_epi16(vxa2, vxb01));
      const __m256i vxb23 = _mm256_load_si256((const __m256i*) ((uintptr_t) w + 16 * sizeof(int16_t)));

      vacc0x23 = _mm256_add_epi32(vacc0x23, _mm256_madd_epi16(vxa0, vxb23));
      vacc1x23 = _mm256_add_epi32(vacc1x23, _mm256_madd_epi16(vxa1, vxb23));
      vacc2x23 = _mm256_add_epi32(vacc2x23, _mm256_madd_epi16(vxa2, vxb23));
      const __m256i vxb45 = _mm256_load_si256((const __m256i*) ((uintptr_t) w + 32 * sizeof(int16_t)));

      vacc0x45 = _mm256_add_epi32(vacc0x45, _mm256_madd_epi16(vxa0, vxb45));
      vacc1x45 = _mm256_add_epi32(vacc1x45, _mm256_madd_epi16(vxa1, vxb45));
      vacc2x45 = _mm256_add_epi32(vacc2x45, _mm256_madd_epi16(vxa2, vxb45));
      const __m256i vxb67 = _mm256_load_si256((const __m256i*) ((uintptr_t) w + 48 * sizeof(int16_t)));

      vacc0x67 = _mm256_add_epi32(vacc0x67, _mm256_madd_epi16(vxa0, vxb67));
      vacc1x67 = _mm256_add_epi32(vacc1x67, _mm256_madd_epi16(vxa1, vxb67));
      vacc2x67 = _mm256_add_epi32(vacc2x67, _mm256_madd_epi16(vxa2, vxb67));

      w = (const void*) ((uintptr_t) w + 64 * sizeof(int16_t));
      k += 8 * sizeof(int8_t);
    }

    const __m256i vacc0x0213 = _mm256_hadd_epi32(vacc0x01, vacc0x23);
    const __m256i vacc0x4657 = _mm256_hadd_epi32(vacc0x45, vacc0x67);
    const __m256i vacc1x0213 = _mm256_hadd_epi32(vacc1x01, vacc1x23);
    const __m256i vacc1x4657 = _mm256_hadd_epi32(vacc1x45, vacc1x67);
    const __m256i vacc2x0213 = _mm256_hadd_epi32(vacc2x01, vacc2x23);
    const __m256i vacc2x4657 = _mm256_hadd_epi32(vacc2x45, vacc2x67);

    const __m256i vacc0x02461357 = _mm256_hadd_epi32(vacc0x0213, vacc0x4657);
    const __m256i vacc1x02461357 = _mm256_hadd_epi32(vacc1x0213, vacc1x4657);
    const __m256i vacc2x02461357 = _mm256_hadd_epi32(vacc2x0213, vacc2x4657);

    const __m256i vpermute_mask = _mm256_set_epi32(7, 3, 6, 2, 5, 1, 4, 0);
    __m256i vacc0x01234567 = _mm256_permutevar8x32_epi32(vacc0x02461357, vpermute_mask);
    __m256i vacc1x01234567 = _mm256_permutevar8x32_epi32(vacc1x02461357, vpermute_mask);
    __m256i vacc2x01234567 = _mm256_permutevar8x32_epi32(vacc2x02461357, vpermute_mask);

    const __m256i vmultiplier = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.multiplier));
    const __m256i vrounding = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.rounding));

    const __m256i vacc0x11335577 = _mm256_shuffle_epi32(vacc0x01234567, _MM_SHUFFLE(3, 3, 1, 1));
    const __m256i vacc1x11335577 = _mm256_shuffle_epi32(vacc1x01234567, _MM_SHUFFLE(3, 3, 1, 1));
    const __m256i vacc2x11335577 = _mm256_shuffle_epi32(vacc2x01234567, _MM_SHUFFLE(3, 3, 1, 1));

    const __m256i vprod0x0246 = _mm256_add_epi64(_mm256_mul_epi32(vacc0x01234567, vmultiplier), vrounding);
    const __m256i vprod1x0246 = _mm256_add_epi64(_mm256_mul_epi32(vacc1x01234567, vmultiplier), vrounding);
    const __m256i vprod2x0246 = _mm256_add_epi64(_mm256_mul_epi32(vacc2x01234567, vmultiplier), vrounding);

    const __m256i vprod0x1357 = _mm256_add_epi64(_mm256_mul_epi32(vacc0x11335577, vmultiplier), vrounding);
    const __m256i vprod1x1357 = _mm256_add_epi64(_mm256_mul_epi32(vacc1x11335577, vmultiplier), vrounding);
    const __m256i vprod2x1357 = _mm256_add_epi64(_mm256_mul_epi32(vacc2x11335577, vmultiplier), vrounding);

    const __m256i vq31prod0x0246 = _mm256_srli_epi64(vprod0x0246, 31);
    const __m256i vq31prod0x1357 = _mm256_add_epi64(vprod0x1357, vprod0x1357);
    const __m256i vq31prod1x0246 = _mm256_srli_epi64(vprod1x0246, 31);
    const __m256i vq31prod1x1357 = _mm256_add_epi64(vprod1x1357, vprod1x1357);
    const __m256i vq31prod2x0246 = _mm256_srli_epi64(vprod2x0246, 31);
    const __m256i vq31prod2x1357 = _mm256_add_epi64(vprod2x1357, vprod2x1357);

    const __m256i vq31prod0x01234567 = _mm256_blend_epi16(vq31prod0x0246, vq31prod0x1357, 0xCC);
    const __m256i vq31prod1x01234567 = _mm256_blend_epi16(vq31prod1x0246, vq31prod1x1357, 0xCC);
    const __m256i vq31prod2x01234567 = _mm256_blend_epi16(vq31prod2x0246, vq31prod2x1357, 0xCC);

    const __m256i vremainder_mask = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.remainder_mask));
    const __m256i vrem0x01234567 =
      _mm256_add_epi32(_mm256_and_si256(vq31prod0x01234567, vremainder_mask), _mm256_cmpgt_epi32(_mm256_setzero_si256(), vq31prod0x01234567));
    const __m256i vrem1x01234567 =
      _mm256_add_epi32(_mm256_and_si256(vq31prod1x01234567, vremainder_mask), _mm256_cmpgt_epi32(_mm256_setzero_si256(), vq31prod1x01234567));
    const __m256i vrem2x01234567 =
      _mm256_add_epi32(_mm256_and_si256(vq31prod2x01234567, vremainder_mask), _mm256_cmpgt_epi32(_mm256_setzero_si256(), vq31prod2x01234567));

    const __m256i vremainder_threshold = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.remainder_threshold));
    const __m128i vshift = _mm_load_si128((const __m128i*) params->sse2.shift);
    vacc0x01234567 =
      _mm256_sub_epi32(_mm256_sra_epi32(vq31prod0x01234567, vshift), _mm256_cmpgt_epi32(vrem0x01234567, vremainder_threshold));
    vacc1x01234567 =
      _mm256_sub_epi32(_mm256_sra_epi32(vq31prod1x01234567, vshift), _mm256_cmpgt_epi32(vrem1x01234567, vremainder_threshold));
    vacc2x01234567 =
      _mm256_sub_epi32(_mm256_sra_epi32(vq31prod2x01234567, vshift), _mm256_cmpgt_epi32(vrem2x01234567, vremainder_threshold));

    const __m256i voutput_zero_point = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.output_zero_point));
    __m256i vacc01x01234567 = _mm256_adds_epi16(_mm256_packs_epi32(vacc0x01234567, vacc1x01234567), voutput_zero_point);
    __m256i vacc22x01234567 = _mm256_adds_epi16(_mm256_packs_epi32(vacc2x01234567, vacc2x01234567), voutput_zero_point);

    vacc01x01234567 = _mm256_permute4x64_epi64(vacc01x01234567, _MM_SHUFFLE(3, 1, 2, 0));
    vacc22x01234567 = _mm256_permute4x64_epi64(vacc22x01234567, _MM_SHUFFLE(3, 1, 2, 0));

    const __m256i voutput_min = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.output_min));
    const __m256i voutput_max = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.output_max));
    vacc01x01234567 = _mm256_min_epi16(_mm256_max_epi16(vacc01x01234567, voutput_min), voutput_max);
    vacc22x01234567 = _mm256_min_epi16(_mm256_max_epi16(vacc22x01234567, voutput_min), voutput_max);

    __m256i vout = _mm256_packs_epi16(vacc01x01234567, vacc22x01234567);
    __m128i vout_lo = _mm256_castsi256_si128(vout);
    __m128i vout_hi = _mm256_extracti128_si256(vout, 1);

    if (nc >= 8) {
      _mm_storel_epi64((__m128i*) c0, vout_lo);
      _mm_storel_epi64((__m128i*) c1, vout_hi);
      _mm_storeh_pi((__m64*) c2, _mm_castsi128_ps(vout_lo));

      c0 = (int8_t*) ((uintptr_t) c0 + cn_stride);
      c1 = (int8_t*) ((uintptr_t) c1 + cn_stride);
      c2 = (int8_t*) ((uintptr_t) c2 + cn_stride);

      a0 = (const int8_t*) ((uintptr_t) a0 - kc);
      a1 = (const int8_t*) ((uintptr_t) a1 - kc);
      a2 = (const int8_t*) ((uintptr_t) a2 - kc);

      nc -= 8;
    } else {
      if (nc & 4) {
        _mm_storeu_si32(c0, vout_lo);
        _mm_storeu_si32(c1, vout_hi);
        *((uint32_t*) c2) = (uint32_t) _mm_extract_epi32(vout_lo, 2);

        c0 += 4;
        c1 += 4;
        c2 += 4;

        vout_lo = _mm_srli_epi64(vout_lo, 32);
        vout_hi = _mm_srli_epi64(vout_hi, 32);
      }
      if (nc & 2) {
        *((uint16_t*) c0) = (uint16_t) _mm_extract_epi16(vout_lo, 0);
        *((uint16_t*) c1) = (uint16_t) _mm_extract_epi16(vout_hi, 0);
        *((uint16_t*) c2) = (uint16_t) _mm_extract_epi16(vout_lo, 4);

        c0 += 2;
        c1 += 2;
        c2 += 2;

        vout_lo = _mm_srli_epi32(vout_lo, 16);
        vout_hi = _mm_srli_epi32(vout_hi, 16);
      }
      if (nc & 1) {
        *c0 = (int8_t) _mm_extract_epi8(vout_lo, 0);
        *c1 = (uint8_t) _mm_extract_epi8(vout_hi, 0);
        *c2 = (uint8_t) _mm_extract_epi8(vout_lo, 8);
      }

      nc = 0;
    }
  } while (nc != 0);
}
