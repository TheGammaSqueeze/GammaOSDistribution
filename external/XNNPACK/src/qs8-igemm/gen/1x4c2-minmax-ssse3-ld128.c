// Auto-generated file. Do not edit!
//   Template: src/qs8-igemm/MRx4c2-sse.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <tmmintrin.h>

#include <xnnpack/igemm.h>
#include <xnnpack/math.h>


void xnn_qs8_igemm_minmax_ukernel_1x4c2__ssse3_ld128(
    size_t mr,
    size_t nc,
    size_t kc,
    size_t ks,
    const int8_t** restrict a,
    const void* restrict w,
    int8_t* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    size_t a_offset,
    const int8_t* zero,
    const union xnn_qs8_gemm_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_DISABLE_TSAN
{
  assert(mr != 0);
  assert(mr <= 1);
  assert(nc != 0);
  assert(kc != 0);
  assert(ks != 0);
  assert(ks % (1 * sizeof(void*)) == 0);
  assert(a_offset % sizeof(int8_t) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);

  kc = round_up_po2(kc, 2);
  int8_t* c0 = c;

  do {
    __m128i vacc0x0123 = _mm_loadu_si128((const __m128i*) w);
    w = (const void*) ((uintptr_t) w + 4 * sizeof(int32_t));

    size_t p = ks;
    do {
      const int8_t* restrict a0 = a[0];
      if XNN_UNPREDICTABLE(a0 != zero) {
        a0 = (const int8_t*) ((uintptr_t) a0 + a_offset);
      }
      a += 1;

      size_t k = kc;
      while (k >= 8 * sizeof(int8_t)) {
        const __m128i va0 = _mm_loadl_epi64((const __m128i*) a0);
        const __m128i vxa0 = _mm_unpacklo_epi8(va0, _mm_cmpgt_epi8(_mm_setzero_si128(), va0));
        a0 += 8;

        const __m128i vb01 = _mm_loadu_si128((const __m128i*) w);
        const __m128i vsb01 = _mm_cmpgt_epi8(_mm_setzero_si128(), vb01);
        const __m128i vxb0 = _mm_unpacklo_epi8(vb01, vsb01);
        const __m128i vxb1 = _mm_unpackhi_epi8(vb01, vsb01);

        vacc0x0123 = _mm_add_epi32(vacc0x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa0, _MM_SHUFFLE(0, 0, 0, 0)), vxb0));

        vacc0x0123 = _mm_add_epi32(vacc0x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa0, _MM_SHUFFLE(1, 1, 1, 1)), vxb1));
        const __m128i vb23 = _mm_loadu_si128((const __m128i*) ((uintptr_t) w + 16));
        const __m128i vsb23 = _mm_cmpgt_epi8(_mm_setzero_si128(), vb23);
        const __m128i vxb2 = _mm_unpacklo_epi8(vb23, vsb23);
        const __m128i vxb3 = _mm_unpackhi_epi8(vb23, vsb23);

        vacc0x0123 = _mm_add_epi32(vacc0x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa0, _MM_SHUFFLE(2, 2, 2, 2)), vxb2));

        vacc0x0123 = _mm_add_epi32(vacc0x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa0, _MM_SHUFFLE(3, 3, 3, 3)), vxb3));

        w = (const void*) ((uintptr_t) w + 32);
        k -= 8 * sizeof(int8_t);
      }
      if (k != 0) {
        const __m128i va0 = _mm_loadl_epi64((const __m128i*) a0);
        const __m128i vxa0 = _mm_unpacklo_epi8(va0, _mm_cmpgt_epi8(_mm_setzero_si128(), va0));
        a0 = (const int8_t*) ((uintptr_t) a0 + k);

        const __m128i vb0 = _mm_loadl_epi64((const __m128i*) w);
        w = (const void*) ((uintptr_t) w + 8);
        const __m128i vxb0 = _mm_unpacklo_epi8(vb0, _mm_cmpgt_epi8(_mm_setzero_si128(), vb0));

        vacc0x0123 = _mm_add_epi32(vacc0x0123,
          _mm_madd_epi16(_mm_shuffle_epi32(vxa0, _MM_SHUFFLE(0, 0, 0, 0)), vxb0));

        if (k > 2 * sizeof(int8_t)) {
          const __m128i vb1 = _mm_loadl_epi64((const __m128i*) w);
          w = (const void*) ((uintptr_t) w + 8);
          const __m128i vxb1 = _mm_unpacklo_epi8(vb1, _mm_cmpgt_epi8(_mm_setzero_si128(), vb1));

          vacc0x0123 = _mm_add_epi32(vacc0x0123,
            _mm_madd_epi16(_mm_shuffle_epi32(vxa0, _MM_SHUFFLE(1, 1, 1, 1)), vxb1));

          if (k > 4 * sizeof(int8_t)) {
            const __m128i vb2 = _mm_loadl_epi64((const __m128i*) w);
            w = (const void*) ((uintptr_t) w + 8);
            const __m128i vxb2 = _mm_unpacklo_epi8(vb2, _mm_cmpgt_epi8(_mm_setzero_si128(), vb2));

            vacc0x0123 = _mm_add_epi32(vacc0x0123,
              _mm_madd_epi16(_mm_shuffle_epi32(vxa0, _MM_SHUFFLE(2, 2, 2, 2)), vxb2));
          }
        }
      }
      p -= 1 * sizeof(void*);
    } while (p != 0);

    const __m128i vmultiplier = _mm_load_si128((const __m128i*) params->sse2.multiplier);
    const __m128i vrounding = _mm_load_si128((const __m128i*) params->sse2.rounding);

    const __m128i vnmask0x0123 = _mm_cmpgt_epi32(_mm_setzero_si128(), vacc0x0123);

    const __m128i vabsacc0x0123 = _mm_abs_epi32(vacc0x0123);

    const __m128i vabsacc0x1133 = _mm_shuffle_epi32(vabsacc0x0123, _MM_SHUFFLE(3, 3, 1, 1));

    const __m128i vabsprod0x02 = _mm_mul_epu32(vabsacc0x0123, vmultiplier);

    const __m128i vnmask0x02 = _mm_shuffle_epi32(vnmask0x0123, _MM_SHUFFLE(2, 2, 0, 0));

    const __m128i vprod0x02 = _mm_sub_epi64(_mm_xor_si128(vabsprod0x02, vnmask0x02), vnmask0x02);

    const __m128i vq31prod0x02 = _mm_srli_epi64(_mm_add_epi64(vprod0x02, vrounding), 31);

    const __m128i vabsprod0x13 = _mm_mul_epu32(vabsacc0x1133, vmultiplier);

    const __m128i vnmask0x13 = _mm_shuffle_epi32(vnmask0x0123, _MM_SHUFFLE(3, 3, 1, 1));

    const __m128i vprod0x13 = _mm_sub_epi64(_mm_xor_si128(vabsprod0x13, vnmask0x13), vnmask0x13);

    const __m128i vq31prod0x13 = _mm_srli_epi64(_mm_add_epi64(vprod0x13, vrounding), 31);

    const __m128i vq31prod0x0213 = _mm_castps_si128(_mm_shuffle_ps(
        _mm_castsi128_ps(vq31prod0x02), _mm_castsi128_ps(vq31prod0x13), _MM_SHUFFLE(2, 0, 2, 0)));

    const __m128i vq31prod0x0123 = _mm_shuffle_epi32(vq31prod0x0213, _MM_SHUFFLE(3, 1, 2, 0));

    const __m128i vremainder_mask = _mm_load_si128((const __m128i*) params->sse2.remainder_mask);
    const __m128i vrem0x0123 =
      _mm_add_epi32(_mm_and_si128(vq31prod0x0123, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prod0x0123));

    const __m128i vremainder_threshold = _mm_load_si128((const __m128i*) params->sse2.remainder_threshold);
    const __m128i vshift = _mm_load_si128((const __m128i*) params->sse2.shift);
    vacc0x0123 =
      _mm_sub_epi32(_mm_sra_epi32(vq31prod0x0123, vshift), _mm_cmpgt_epi32(vrem0x0123, vremainder_threshold));

    const __m128i voutput_zero_point = _mm_load_si128((const __m128i*) params->sse2.output_zero_point);
    __m128i vacc00x0123 = _mm_adds_epi16(_mm_packs_epi32(vacc0x0123, vacc0x0123), voutput_zero_point);

    const __m128i voutput_min = _mm_load_si128((const __m128i*) params->sse2.output_min);
    const __m128i voutput_max = _mm_load_si128((const __m128i*) params->sse2.output_max);
    vacc00x0123 = _mm_min_epi16(_mm_max_epi16(vacc00x0123, voutput_min), voutput_max);

    __m128i vout = _mm_packs_epi16(vacc00x0123, vacc00x0123);

    if (nc >= 4) {
      *((uint32_t*) c0) = (uint32_t) _mm_cvtsi128_si32(vout);
      c0 = (int8_t*) ((uintptr_t) c0 + cn_stride);

      a = (const int8_t**restrict) ((uintptr_t) a - ks);

      nc -= 4;
    } else {
      if (nc & 2) {
        *((uint16_t*) c0) = (uint16_t) _mm_extract_epi16(vout, 0);
        c0 += 2;
        vout = _mm_srli_epi32(vout, 16);
      }
      if (nc & 1) {
        *((int8_t*) c0) = (int8_t) _mm_cvtsi128_si32(vout);
      }

      nc = 0;
    }
  } while (nc != 0);
}
