// Auto-generated file. Do not edit!
//   Template: src/qs8-dwconv/unipass-avx512skx-mul32.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <immintrin.h>

#include <xnnpack/dwconv.h>
#include <xnnpack/intrinsics-polyfill.h>


void xnn_qs8_dwconv_minmax_ukernel_up16x9__avx512skx_mul32(
    size_t channels,
    size_t output_width,
    const int8_t** input,
    const void* weights,
    int8_t* output,
    size_t input_stride,
    size_t output_increment,
    size_t input_offset,
    const int8_t* zero,
    const union xnn_qs8_gemm_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_DISABLE_TSAN
{
  assert(channels != 0);
  assert(output_width != 0);

  const __mmask16 vblend_mask = _cvtu32_mask16(0xAAAA);
  const __m512i vmultiplier = _mm512_broadcast_i32x4(_mm_load_si128((const __m128i*) params->sse2.multiplier));
  const __m512i vrounding = _mm512_broadcast_i32x4(_mm_load_si128((const __m128i*) params->sse2.rounding));
  const __m512i vremainder_mask = _mm512_broadcast_i32x4(_mm_load_si128((const __m128i*) params->sse2.remainder_mask));
  const __m512i vremainder_threshold = _mm512_broadcast_i32x4(_mm_load_si128((const __m128i*) params->sse2.remainder_threshold));
  const __m128i vshift = _mm_load_si128((const __m128i*) params->sse2.shift);
  const __m256i voutput_zero_point = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.output_zero_point));
  const __m256i voutput_min = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.output_min));
  const __m256i voutput_max = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.output_max));

  do {
    const int8_t* i0 = input[0];
    assert(i0 != NULL);
    if XNN_UNPREDICTABLE(i0 != zero) {
      i0 = (const int8_t*) ((uintptr_t) i0 + input_offset);
    }
    const int8_t* i1 = input[1];
    assert(i1 != NULL);
    if XNN_UNPREDICTABLE(i1 != zero) {
      i1 = (const int8_t*) ((uintptr_t) i1 + input_offset);
    }
    const int8_t* i2 = input[2];
    assert(i2 != NULL);
    if XNN_UNPREDICTABLE(i2 != zero) {
      i2 = (const int8_t*) ((uintptr_t) i2 + input_offset);
    }
    const int8_t* i3 = input[3];
    assert(i3 != NULL);
    if XNN_UNPREDICTABLE(i3 != zero) {
      i3 = (const int8_t*) ((uintptr_t) i3 + input_offset);
    }
    const int8_t* i4 = input[4];
    assert(i4 != NULL);
    if XNN_UNPREDICTABLE(i4 != zero) {
      i4 = (const int8_t*) ((uintptr_t) i4 + input_offset);
    }
    const int8_t* i5 = input[5];
    assert(i5 != NULL);
    if XNN_UNPREDICTABLE(i5 != zero) {
      i5 = (const int8_t*) ((uintptr_t) i5 + input_offset);
    }
    const int8_t* i6 = input[6];
    assert(i6 != NULL);
    if XNN_UNPREDICTABLE(i6 != zero) {
      i6 = (const int8_t*) ((uintptr_t) i6 + input_offset);
    }
    const int8_t* i7 = input[7];
    assert(i7 != NULL);
    if XNN_UNPREDICTABLE(i7 != zero) {
      i7 = (const int8_t*) ((uintptr_t) i7 + input_offset);
    }
    const int8_t* i8 = input[8];
    assert(i8 != NULL);
    if XNN_UNPREDICTABLE(i8 != zero) {
      i8 = (const int8_t*) ((uintptr_t) i8 + input_offset);
    }
    input = (const int8_t**) ((uintptr_t) input + input_stride);

    size_t c = channels;
    const void* w = weights;
    for (; c >= 16; c -= 16) {
      __m512i vacc0123456789ABCDEF = _mm512_loadu_si512(w);


      const __m512i vi0x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) i0));
      const __m512i vk0x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_load_si128((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 0 * sizeof(int8_t))));
      i0 += 16;

      vacc0123456789ABCDEF = _mm512_add_epi32(vacc0123456789ABCDEF, _mm512_mullo_epi32(vi0x0123456789ABCDEF, vk0x0123456789ABCDEF));

      const __m512i vi1x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) i1));
      const __m512i vk1x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_load_si128((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 16 * sizeof(int8_t))));
      i1 += 16;

      vacc0123456789ABCDEF = _mm512_add_epi32(vacc0123456789ABCDEF, _mm512_mullo_epi32(vi1x0123456789ABCDEF, vk1x0123456789ABCDEF));

      const __m512i vi2x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) i2));
      const __m512i vk2x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_load_si128((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 32 * sizeof(int8_t))));
      i2 += 16;

      vacc0123456789ABCDEF = _mm512_add_epi32(vacc0123456789ABCDEF, _mm512_mullo_epi32(vi2x0123456789ABCDEF, vk2x0123456789ABCDEF));

      const __m512i vi3x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) i3));
      const __m512i vk3x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_load_si128((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 48 * sizeof(int8_t))));
      i3 += 16;

      vacc0123456789ABCDEF = _mm512_add_epi32(vacc0123456789ABCDEF, _mm512_mullo_epi32(vi3x0123456789ABCDEF, vk3x0123456789ABCDEF));

      const __m512i vi4x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) i4));
      const __m512i vk4x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_load_si128((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 64 * sizeof(int8_t))));
      i4 += 16;

      vacc0123456789ABCDEF = _mm512_add_epi32(vacc0123456789ABCDEF, _mm512_mullo_epi32(vi4x0123456789ABCDEF, vk4x0123456789ABCDEF));

      const __m512i vi5x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) i5));
      const __m512i vk5x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_load_si128((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 80 * sizeof(int8_t))));
      i5 += 16;

      vacc0123456789ABCDEF = _mm512_add_epi32(vacc0123456789ABCDEF, _mm512_mullo_epi32(vi5x0123456789ABCDEF, vk5x0123456789ABCDEF));

      const __m512i vi6x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) i6));
      const __m512i vk6x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_load_si128((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 96 * sizeof(int8_t))));
      i6 += 16;

      vacc0123456789ABCDEF = _mm512_add_epi32(vacc0123456789ABCDEF, _mm512_mullo_epi32(vi6x0123456789ABCDEF, vk6x0123456789ABCDEF));

      const __m512i vi7x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) i7));
      const __m512i vk7x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_load_si128((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 112 * sizeof(int8_t))));
      i7 += 16;

      vacc0123456789ABCDEF = _mm512_add_epi32(vacc0123456789ABCDEF, _mm512_mullo_epi32(vi7x0123456789ABCDEF, vk7x0123456789ABCDEF));

      const __m512i vi8x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) i8));
      const __m512i vk8x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_load_si128((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 128 * sizeof(int8_t))));
      i8 += 16;

      vacc0123456789ABCDEF = _mm512_add_epi32(vacc0123456789ABCDEF, _mm512_mullo_epi32(vi8x0123456789ABCDEF, vk8x0123456789ABCDEF));

      w = (const void*) ((uintptr_t) w + 16 * sizeof(int32_t) + 144 * sizeof(int8_t));

      const __m512i vacc13579BDF = _mm512_shuffle_epi32(vacc0123456789ABCDEF, _MM_SHUFFLE(3, 3, 1, 1));

      const __m512i vprod02468ACE = _mm512_add_epi64(_mm512_mul_epi32(vacc0123456789ABCDEF, vmultiplier), vrounding);
      const __m512i vprod13579BDF = _mm512_add_epi64(_mm512_mul_epi32(vacc13579BDF, vmultiplier), vrounding);

      const __m512i vq31prod02468ACE = _mm512_srli_epi64(vprod02468ACE, 31);
      const __m512i vq31prod13579BDF = _mm512_add_epi64(vprod13579BDF, vprod13579BDF);

      const __m512i vq31prod0123456789ABCDEF = _mm512_mask_blend_epi32(vblend_mask, vq31prod02468ACE, vq31prod13579BDF);

      const __m512i vrem0123456789ABCDEF =
        _mm512_add_epi32(_mm512_and_epi32(vq31prod0123456789ABCDEF, vremainder_mask), _mm512_srai_epi32(vq31prod0123456789ABCDEF, 31));

      vacc0123456789ABCDEF = _mm512_sra_epi32(vq31prod0123456789ABCDEF, vshift);

      const __m512i vminus_one = _mm512_set1_epi32(-1);
      vacc0123456789ABCDEF = _mm512_mask_sub_epi32(vacc0123456789ABCDEF, _mm512_cmpgt_epi32_mask(vrem0123456789ABCDEF, vremainder_threshold), vacc0123456789ABCDEF, vminus_one);

      __m256i vout012389AB4567CDEF = _mm256_adds_epi16(_mm256_packs_epi32(_mm512_castsi512_si256(vacc0123456789ABCDEF), _mm512_extracti32x8_epi32(vacc0123456789ABCDEF, 1)), voutput_zero_point);

      vout012389AB4567CDEF = _mm256_min_epi16(_mm256_max_epi16(vout012389AB4567CDEF, voutput_min), voutput_max);

      const __m128i vout012389AB = _mm256_castsi256_si128(vout012389AB4567CDEF);
      const __m128i vout4567CDEF = _mm256_extracti128_si256(vout012389AB4567CDEF, 1);
      __m128i vout0123456789ABCDEF = _mm_shuffle_epi32(_mm_packs_epi16(vout012389AB, vout4567CDEF), _MM_SHUFFLE(3, 1, 2, 0));

      _mm_storeu_si128((__m128i*) output, vout0123456789ABCDEF);
      output += 16;
    }
    if XNN_UNLIKELY(c != 0) {
      // Prepare mask for valid 8-bit elements (depends on nc).
      const __mmask16 vmask = _cvtu32_mask16((uint32_t) ((UINT32_C(1) << (c & 15)) - UINT32_C(1)));
      {
        __m512i vacc0123456789ABCDEF = _mm512_loadu_si512(w);


        const __m512i vi0x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) i0));
        const __m512i vk0x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 0 * sizeof(int8_t))));

        vacc0123456789ABCDEF = _mm512_add_epi32(vacc0123456789ABCDEF, _mm512_mullo_epi32(vi0x0123456789ABCDEF, vk0x0123456789ABCDEF));

        const __m512i vi1x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) i1));
        const __m512i vk1x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 16 * sizeof(int8_t))));

        vacc0123456789ABCDEF = _mm512_add_epi32(vacc0123456789ABCDEF, _mm512_mullo_epi32(vi1x0123456789ABCDEF, vk1x0123456789ABCDEF));

        const __m512i vi2x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) i2));
        const __m512i vk2x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 32 * sizeof(int8_t))));

        vacc0123456789ABCDEF = _mm512_add_epi32(vacc0123456789ABCDEF, _mm512_mullo_epi32(vi2x0123456789ABCDEF, vk2x0123456789ABCDEF));

        const __m512i vi3x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) i3));
        const __m512i vk3x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 48 * sizeof(int8_t))));

        vacc0123456789ABCDEF = _mm512_add_epi32(vacc0123456789ABCDEF, _mm512_mullo_epi32(vi3x0123456789ABCDEF, vk3x0123456789ABCDEF));

        const __m512i vi4x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) i4));
        const __m512i vk4x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 64 * sizeof(int8_t))));

        vacc0123456789ABCDEF = _mm512_add_epi32(vacc0123456789ABCDEF, _mm512_mullo_epi32(vi4x0123456789ABCDEF, vk4x0123456789ABCDEF));

        const __m512i vi5x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) i5));
        const __m512i vk5x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 80 * sizeof(int8_t))));

        vacc0123456789ABCDEF = _mm512_add_epi32(vacc0123456789ABCDEF, _mm512_mullo_epi32(vi5x0123456789ABCDEF, vk5x0123456789ABCDEF));

        const __m512i vi6x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) i6));
        const __m512i vk6x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 96 * sizeof(int8_t))));

        vacc0123456789ABCDEF = _mm512_add_epi32(vacc0123456789ABCDEF, _mm512_mullo_epi32(vi6x0123456789ABCDEF, vk6x0123456789ABCDEF));

        const __m512i vi7x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) i7));
        const __m512i vk7x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 112 * sizeof(int8_t))));

        vacc0123456789ABCDEF = _mm512_add_epi32(vacc0123456789ABCDEF, _mm512_mullo_epi32(vi7x0123456789ABCDEF, vk7x0123456789ABCDEF));

        const __m512i vi8x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) i8));
        const __m512i vk8x0123456789ABCDEF = _mm512_cvtepi8_epi32(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 128 * sizeof(int8_t))));

        vacc0123456789ABCDEF = _mm512_add_epi32(vacc0123456789ABCDEF, _mm512_mullo_epi32(vi8x0123456789ABCDEF, vk8x0123456789ABCDEF));


        const __m512i vacc13579BDF = _mm512_shuffle_epi32(vacc0123456789ABCDEF, _MM_SHUFFLE(3, 3, 1, 1));

        const __m512i vprod02468ACE = _mm512_add_epi64(_mm512_mul_epi32(vacc0123456789ABCDEF, vmultiplier), vrounding);
        const __m512i vprod13579BDF = _mm512_add_epi64(_mm512_mul_epi32(vacc13579BDF, vmultiplier), vrounding);

        const __m512i vq31prod02468ACE = _mm512_srli_epi64(vprod02468ACE, 31);
        const __m512i vq31prod13579BDF = _mm512_add_epi64(vprod13579BDF, vprod13579BDF);

        const __m512i vq31prod0123456789ABCDEF = _mm512_mask_blend_epi32(vblend_mask, vq31prod02468ACE, vq31prod13579BDF);

        const __m512i vrem0123456789ABCDEF = _mm512_add_epi32(_mm512_and_epi32(vq31prod0123456789ABCDEF, vremainder_mask), _mm512_srai_epi32(vq31prod0123456789ABCDEF, 31));

        vacc0123456789ABCDEF = _mm512_sra_epi32(vq31prod0123456789ABCDEF, vshift);
        vacc0123456789ABCDEF = _mm512_mask_sub_epi32(vacc0123456789ABCDEF, _mm512_cmpgt_epi32_mask(vrem0123456789ABCDEF, vremainder_threshold), vacc0123456789ABCDEF, _mm512_set1_epi32(-1));

        __m256i vout012389AB4567CDEF = _mm256_adds_epi16(_mm256_packs_epi32(_mm512_castsi512_si256(vacc0123456789ABCDEF), _mm512_extracti32x8_epi32(vacc0123456789ABCDEF, 1)), voutput_zero_point);

        vout012389AB4567CDEF = _mm256_min_epi16(_mm256_max_epi16(vout012389AB4567CDEF, voutput_min), voutput_max);

        const __m128i vout012389AB = _mm256_castsi256_si128(vout012389AB4567CDEF);
        const __m128i vout4567CDEF = _mm256_extracti128_si256(vout012389AB4567CDEF, 1);
        __m128i vout0123456789ABCDEF = _mm_shuffle_epi32(_mm_packs_epi16(vout012389AB, vout4567CDEF), _MM_SHUFFLE(3, 1, 2, 0));

        _mm_mask_storeu_epi8(output, vmask, vout0123456789ABCDEF);
        output = (int8_t*) ((uintptr_t) output + c);
      }
    }

    output = (int8_t*) ((uintptr_t) output + output_increment);
  } while (--output_width != 0);
}
