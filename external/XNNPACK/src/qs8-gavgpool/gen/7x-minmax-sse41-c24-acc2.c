// Auto-generated file. Do not edit!
//   Template: src/qs8-gavgpool/unipass-sse.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <smmintrin.h>

#include <xnnpack/gavgpool.h>


void xnn_qs8_gavgpool_minmax_ukernel_7x__sse41_c24_acc2(
    size_t rows,
    size_t channels,
    const int8_t* input,
    size_t input_stride,
    const int8_t* zero,
    int8_t* output,
    const union xnn_qs8_avgpool_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_DISABLE_TSAN
{
  assert(rows != 0);
  assert(rows <= 7);
  assert(channels != 0);

  const int8_t* i0 = input;
  const int8_t* i1 = (const int8_t*) ((uintptr_t) i0 + input_stride);
  if XNN_UNPREDICTABLE(rows < 2) {
    i1 = zero;
  }
  const int8_t* i2 = (const int8_t*) ((uintptr_t) i1 + input_stride);
  if XNN_UNPREDICTABLE(rows <= 2) {
    i2 = zero;
  }
  const int8_t* i3 = (const int8_t*) ((uintptr_t) i2 + input_stride);
  if XNN_UNPREDICTABLE(rows < 4) {
    i3 = zero;
  }
  const int8_t* i4 = (const int8_t*) ((uintptr_t) i3 + input_stride);
  if XNN_UNPREDICTABLE(rows <= 4) {
    i4 = zero;
  }
  const int8_t* i5 = (const int8_t*) ((uintptr_t) i4 + input_stride);
  if XNN_UNPREDICTABLE(rows < 6) {
    i5 = zero;
  }
  const int8_t* i6 = (const int8_t*) ((uintptr_t) i5 + input_stride);
  if XNN_UNPREDICTABLE(rows <= 6) {
    i6 = zero;
  }

  const __m128i vbias = _mm_load_si128((const __m128i*) params->sse2.bias);
  const __m128i vmultiplier = _mm_load_si128((const __m128i*) params->sse2.multiplier);
  const __m128i vrounding = _mm_load_si128((const __m128i*) params->sse2.rounding);
  const __m128i vshift = _mm_loadl_epi64((const __m128i*) params->sse2.shift);
  while (channels >= 24) {
    const __m128i vxi0x01234567 = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) i0));
    const __m128i vxi0x89ABCDEF = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) (i0 + 8)));
    const __m128i vxi0xGHIJKLMN = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) (i0 + 16)));
    i0 += 24;
    const __m128i vxi1x01234567 = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) i1));
    const __m128i vxi1x89ABCDEF = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) (i1 + 8)));
    const __m128i vxi1xGHIJKLMN = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) (i1 + 16)));
    i1 += 24;
    const __m128i vxi2x01234567 = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) i2));
    const __m128i vxi2x89ABCDEF = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) (i2 + 8)));
    const __m128i vxi2xGHIJKLMN = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) (i2 + 16)));
    i2 += 24;
    const __m128i vxi3x01234567 = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) i3));
    const __m128i vxi3x89ABCDEF = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) (i3 + 8)));
    const __m128i vxi3xGHIJKLMN = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) (i3 + 16)));
    i3 += 24;
    const __m128i vxi4x01234567 = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) i4));
    const __m128i vxi4x89ABCDEF = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) (i4 + 8)));
    const __m128i vxi4xGHIJKLMN = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) (i4 + 16)));
    i4 += 24;
    const __m128i vxi5x01234567 = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) i5));
    const __m128i vxi5x89ABCDEF = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) (i5 + 8)));
    const __m128i vxi5xGHIJKLMN = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) (i5 + 16)));
    i5 += 24;
    const __m128i vxi6x01234567 = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) i6));
    const __m128i vxi6x89ABCDEF = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) (i6 + 8)));
    const __m128i vxi6xGHIJKLMN = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) (i6 + 16)));
    i6 += 24;


    __m128i vacc0x01234567 = _mm_add_epi16(vxi0x01234567, vxi1x01234567);
    __m128i vacc0x89ABCDEF = _mm_add_epi16(vxi0x89ABCDEF, vxi1x89ABCDEF);
    __m128i vacc0xGHIJKLMN = _mm_add_epi16(vxi0xGHIJKLMN, vxi1xGHIJKLMN);
    __m128i vacc1x01234567 = _mm_add_epi16(vxi2x01234567, vxi3x01234567);
    __m128i vacc1x89ABCDEF = _mm_add_epi16(vxi2x89ABCDEF, vxi3x89ABCDEF);
    __m128i vacc1xGHIJKLMN = _mm_add_epi16(vxi2xGHIJKLMN, vxi3xGHIJKLMN);

    vacc0x01234567 = _mm_add_epi16(vacc0x01234567, vxi4x01234567);
    vacc0x89ABCDEF = _mm_add_epi16(vacc0x89ABCDEF, vxi4x89ABCDEF);
    vacc0xGHIJKLMN = _mm_add_epi16(vacc0xGHIJKLMN, vxi4xGHIJKLMN);
    vacc1x01234567 = _mm_add_epi16(vacc1x01234567, vxi5x01234567);
    vacc1x89ABCDEF = _mm_add_epi16(vacc1x89ABCDEF, vxi5x89ABCDEF);
    vacc1xGHIJKLMN = _mm_add_epi16(vacc1xGHIJKLMN, vxi5xGHIJKLMN);
    vacc0x01234567 = _mm_add_epi16(vacc0x01234567, vxi6x01234567);
    vacc0x89ABCDEF = _mm_add_epi16(vacc0x89ABCDEF, vxi6x89ABCDEF);
    vacc0xGHIJKLMN = _mm_add_epi16(vacc0xGHIJKLMN, vxi6xGHIJKLMN);

    // Add up all accumulators to vacc0x0123456789ABCDEFGHIJKLMN
    vacc0x01234567 = _mm_add_epi16(vacc0x01234567, vacc1x01234567);
    vacc0x89ABCDEF = _mm_add_epi16(vacc0x89ABCDEF, vacc1x89ABCDEF);
    vacc0xGHIJKLMN = _mm_add_epi16(vacc0xGHIJKLMN, vacc1xGHIJKLMN);

    const __m128i vacc0123 = _mm_add_epi32(vbias, _mm_cvtepi16_epi32(vacc0x01234567));
    const __m128i vacc4567 = _mm_add_epi32(vbias, _mm_unpackhi_epi16(vacc0x01234567, _mm_cmpgt_epi16(_mm_setzero_si128(), vacc0x01234567)));
    const __m128i vacc89AB = _mm_add_epi32(vbias, _mm_cvtepi16_epi32(vacc0x89ABCDEF));
    const __m128i vaccCDEF = _mm_add_epi32(vbias, _mm_unpackhi_epi16(vacc0x89ABCDEF, _mm_cmpgt_epi16(_mm_setzero_si128(), vacc0x89ABCDEF)));
    const __m128i vaccGHIJ = _mm_add_epi32(vbias, _mm_cvtepi16_epi32(vacc0xGHIJKLMN));
    const __m128i vaccKLMN = _mm_add_epi32(vbias, _mm_unpackhi_epi16(vacc0xGHIJKLMN, _mm_cmpgt_epi16(_mm_setzero_si128(), vacc0xGHIJKLMN)));

    const __m128i vabsacc0123 = _mm_abs_epi32(vacc0123);
    const __m128i vabsacc4567 = _mm_abs_epi32(vacc4567);
    const __m128i vabsacc89AB = _mm_abs_epi32(vacc89AB);
    const __m128i vabsaccCDEF = _mm_abs_epi32(vaccCDEF);
    const __m128i vabsaccGHIJ = _mm_abs_epi32(vaccGHIJ);
    const __m128i vabsaccKLMN = _mm_abs_epi32(vaccKLMN);

    const __m128i vabsacc13 = _mm_shuffle_epi32(vabsacc0123, _MM_SHUFFLE(3, 3, 1, 1));
    const __m128i vabsacc57 = _mm_shuffle_epi32(vabsacc4567, _MM_SHUFFLE(3, 3, 1, 1));
    const __m128i vabsacc9B = _mm_shuffle_epi32(vabsacc89AB, _MM_SHUFFLE(3, 3, 1, 1));
    const __m128i vabsaccDF = _mm_shuffle_epi32(vabsaccCDEF, _MM_SHUFFLE(3, 3, 1, 1));
    const __m128i vabsaccHJ = _mm_shuffle_epi32(vabsaccGHIJ, _MM_SHUFFLE(3, 3, 1, 1));
    const __m128i vabsaccLN = _mm_shuffle_epi32(vabsaccKLMN, _MM_SHUFFLE(3, 3, 1, 1));

    const __m128i vabsprod02 = _mm_mul_epu32(vabsacc0123, vmultiplier);
    const __m128i vabsprod13 = _mm_mul_epu32(vabsacc13, vmultiplier);
    const __m128i vabsprod46 = _mm_mul_epu32(vabsacc4567, vmultiplier);
    const __m128i vabsprod57 = _mm_mul_epu32(vabsacc57, vmultiplier);
    const __m128i vabsprod8A = _mm_mul_epu32(vabsacc89AB, vmultiplier);
    const __m128i vabsprod9B = _mm_mul_epu32(vabsacc9B, vmultiplier);
    const __m128i vabsprodCE = _mm_mul_epu32(vabsaccCDEF, vmultiplier);
    const __m128i vabsprodDF = _mm_mul_epu32(vabsaccDF, vmultiplier);
    const __m128i vabsprodGI = _mm_mul_epu32(vabsaccGHIJ, vmultiplier);
    const __m128i vabsprodHJ = _mm_mul_epu32(vabsaccHJ, vmultiplier);
    const __m128i vabsprodKM = _mm_mul_epu32(vabsaccKLMN, vmultiplier);
    const __m128i vabsprodLN = _mm_mul_epu32(vabsaccLN, vmultiplier);

    const __m128i vabsout02 = _mm_srl_epi64(_mm_add_epi64(vabsprod02, vrounding), vshift);
    const __m128i vabsout13 = _mm_srl_epi64(_mm_add_epi64(vabsprod13, vrounding), vshift);
    const __m128i vabsout46 = _mm_srl_epi64(_mm_add_epi64(vabsprod46, vrounding), vshift);
    const __m128i vabsout57 = _mm_srl_epi64(_mm_add_epi64(vabsprod57, vrounding), vshift);
    const __m128i vabsout8A = _mm_srl_epi64(_mm_add_epi64(vabsprod8A, vrounding), vshift);
    const __m128i vabsout9B = _mm_srl_epi64(_mm_add_epi64(vabsprod9B, vrounding), vshift);
    const __m128i vabsoutCE = _mm_srl_epi64(_mm_add_epi64(vabsprodCE, vrounding), vshift);
    const __m128i vabsoutDF = _mm_srl_epi64(_mm_add_epi64(vabsprodDF, vrounding), vshift);
    const __m128i vabsoutGI = _mm_srl_epi64(_mm_add_epi64(vabsprodGI, vrounding), vshift);
    const __m128i vabsoutHJ = _mm_srl_epi64(_mm_add_epi64(vabsprodHJ, vrounding), vshift);
    const __m128i vabsoutKM = _mm_srl_epi64(_mm_add_epi64(vabsprodKM, vrounding), vshift);
    const __m128i vabsoutLN = _mm_srl_epi64(_mm_add_epi64(vabsprodLN, vrounding), vshift);

    const __m128i vabsout0123 = _mm_blend_epi16(vabsout02, _mm_shuffle_epi32(vabsout13, _MM_SHUFFLE(2, 2, 0, 0)), 0xCC);
    const __m128i vabsout4567 = _mm_blend_epi16(vabsout46, _mm_shuffle_epi32(vabsout57, _MM_SHUFFLE(2, 2, 0, 0)), 0xCC);
    const __m128i vabsout89AB = _mm_blend_epi16(vabsout8A, _mm_shuffle_epi32(vabsout9B, _MM_SHUFFLE(2, 2, 0, 0)), 0xCC);
    const __m128i vabsoutCDEF = _mm_blend_epi16(vabsoutCE, _mm_shuffle_epi32(vabsoutDF, _MM_SHUFFLE(2, 2, 0, 0)), 0xCC);
    const __m128i vabsoutGHIJ = _mm_blend_epi16(vabsoutGI, _mm_shuffle_epi32(vabsoutHJ, _MM_SHUFFLE(2, 2, 0, 0)), 0xCC);
    const __m128i vabsoutKLMN = _mm_blend_epi16(vabsoutKM, _mm_shuffle_epi32(vabsoutLN, _MM_SHUFFLE(2, 2, 0, 0)), 0xCC);

    const __m128i vout0123 = _mm_sign_epi32(vabsout0123, vacc0123);
    const __m128i vout4567 = _mm_sign_epi32(vabsout4567, vacc4567);
    const __m128i vout89AB = _mm_sign_epi32(vabsout89AB, vacc89AB);
    const __m128i voutCDEF = _mm_sign_epi32(vabsoutCDEF, vaccCDEF);
    const __m128i voutGHIJ = _mm_sign_epi32(vabsoutGHIJ, vaccGHIJ);
    const __m128i voutKLMN = _mm_sign_epi32(vabsoutKLMN, vaccKLMN);

    const __m128i voutput_zero_point = _mm_load_si128((const __m128i*) params->sse2.output_zero_point);
    __m128i vout01234567 = _mm_adds_epi16(_mm_packs_epi32(vout0123, vout4567), voutput_zero_point);
    __m128i vout89ABCDEF = _mm_adds_epi16(_mm_packs_epi32(vout89AB, voutCDEF), voutput_zero_point);
    __m128i voutGHIJKLMN = _mm_adds_epi16(_mm_packs_epi32(voutGHIJ, voutKLMN), voutput_zero_point);

    const __m128i voutput_min = _mm_load_si128((const __m128i*) params->sse2.output_min);
    const __m128i voutput_max = _mm_load_si128((const __m128i*) params->sse2.output_max);
    vout01234567 = _mm_min_epi16(_mm_max_epi16(vout01234567, voutput_min), voutput_max);
    vout89ABCDEF = _mm_min_epi16(_mm_max_epi16(vout89ABCDEF, voutput_min), voutput_max);
    voutGHIJKLMN = _mm_min_epi16(_mm_max_epi16(voutGHIJKLMN, voutput_min), voutput_max);

    __m128i vout0123456789ABCDEF = _mm_packs_epi16(vout01234567, vout89ABCDEF);
    __m128i voutGHIJKLMNGHIJKLMN = _mm_packs_epi16(voutGHIJKLMN, voutGHIJKLMN);

    _mm_storeu_si128((__m128i*) output, vout0123456789ABCDEF);
    _mm_storel_epi64((__m128i*) (output + 16), voutGHIJKLMNGHIJKLMN);
    output += 24;

    channels -= 24;
  }
  if XNN_UNLIKELY(channels != 0) {
    do {
      const __m128i vxi0x01234567 = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) i0));
      i0 += 8;
      const __m128i vxi1x01234567 = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) i1));
      i1 += 8;
      const __m128i vxi2x01234567 = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) i2));
      i2 += 8;
      const __m128i vxi3x01234567 = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) i3));
      i3 += 8;
      const __m128i vxi4x01234567 = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) i4));
      i4 += 8;
      const __m128i vxi5x01234567 = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) i5));
      i5 += 8;
      const __m128i vxi6x01234567 = _mm_cvtepi8_epi16(_mm_loadl_epi64((const __m128i*) i6));
      i6 += 8;


      __m128i vacc0x01234567 = _mm_add_epi16(vxi0x01234567, vxi1x01234567);
      __m128i vacc1x01234567 = _mm_add_epi16(vxi2x01234567, vxi3x01234567);

      vacc0x01234567 = _mm_add_epi16(vacc0x01234567, vxi4x01234567);
      vacc1x01234567 = _mm_add_epi16(vacc1x01234567, vxi5x01234567);
      vacc0x01234567 = _mm_add_epi16(vacc0x01234567, vxi6x01234567);

      // Add up all accumulators to vacc0x01234567
      vacc0x01234567 = _mm_add_epi16(vacc0x01234567, vacc1x01234567);

      const __m128i vacc0123 = _mm_add_epi32(vbias, _mm_cvtepi16_epi32(vacc0x01234567));
      const __m128i vacc4567 = _mm_add_epi32(vbias, _mm_unpackhi_epi16(vacc0x01234567, _mm_cmpgt_epi16(_mm_setzero_si128(), vacc0x01234567)));

      const __m128i vabsacc0123 = _mm_abs_epi32(vacc0123);
      const __m128i vabsacc4567 = _mm_abs_epi32(vacc4567);

      const __m128i vabsacc13 = _mm_shuffle_epi32(vabsacc0123, _MM_SHUFFLE(3, 3, 1, 1));
      const __m128i vabsacc57 = _mm_shuffle_epi32(vabsacc4567, _MM_SHUFFLE(3, 3, 1, 1));

      const __m128i vabsprod02 = _mm_mul_epu32(vabsacc0123, vmultiplier);
      const __m128i vabsprod13 = _mm_mul_epu32(vabsacc13, vmultiplier);
      const __m128i vabsprod46 = _mm_mul_epu32(vabsacc4567, vmultiplier);
      const __m128i vabsprod57 = _mm_mul_epu32(vabsacc57, vmultiplier);

      const __m128i vabsout02 = _mm_srl_epi64(_mm_add_epi64(vabsprod02, vrounding), vshift);
      const __m128i vabsout13 = _mm_srl_epi64(_mm_add_epi64(vabsprod13, vrounding), vshift);
      const __m128i vabsout46 = _mm_srl_epi64(_mm_add_epi64(vabsprod46, vrounding), vshift);
      const __m128i vabsout57 = _mm_srl_epi64(_mm_add_epi64(vabsprod57, vrounding), vshift);

      const __m128i vabsout0123 = _mm_blend_epi16(vabsout02, _mm_shuffle_epi32(vabsout13, _MM_SHUFFLE(2, 2, 0, 0)), 0xCC);
      const __m128i vabsout4567 = _mm_blend_epi16(vabsout46, _mm_shuffle_epi32(vabsout57, _MM_SHUFFLE(2, 2, 0, 0)), 0xCC);

      const __m128i vout0123 = _mm_sign_epi32(vabsout0123, vacc0123);
      const __m128i vout4567 = _mm_sign_epi32(vabsout4567, vacc4567);

      const __m128i voutput_zero_point = _mm_load_si128((const __m128i*) params->sse2.output_zero_point);
      __m128i vout01234567 = _mm_adds_epi16(_mm_packs_epi32(vout0123, vout4567), voutput_zero_point);

      const __m128i voutput_min = _mm_load_si128((const __m128i*) params->sse2.output_min);
      const __m128i voutput_max = _mm_load_si128((const __m128i*) params->sse2.output_max);
      vout01234567 = _mm_min_epi16(_mm_max_epi16(vout01234567, voutput_min), voutput_max);

      __m128i vout0123456701234567 = _mm_packs_epi16(vout01234567, vout01234567);

      if XNN_LIKELY(channels >= 8) {
        _mm_storel_epi64((__m128i*) output, vout0123456701234567);
        output += 8;
        channels -= 8;
      } else {
        if (channels & 4) {
          *((uint32_t*) output) = (uint32_t) _mm_cvtsi128_si32(vout0123456701234567);
          vout0123456701234567 = _mm_srli_epi64(vout0123456701234567, 32);
          output += 4;
        }
        if (channels & 2) {
          *((uint16_t*) output) = (uint16_t) _mm_extract_epi16(vout0123456701234567, 0);
          vout0123456701234567 = _mm_srli_epi32(vout0123456701234567, 16);
          output += 2;
        }
        if (channels & 1) {
          *output = (int8_t) _mm_extract_epi8(vout0123456701234567, 0);
          output += 1;
        }
        channels = 0;
      }
    } while (channels != 0);
  }
}
