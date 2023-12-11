// Auto-generated file. Do not edit!
//   Template: src/qs8-dwconv/unipass-sse-mul16.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <emmintrin.h>

#include <xnnpack/dwconv.h>


void xnn_qs8_dwconv_minmax_ukernel_up16x9__sse2_mul16(
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
      __m128i vacc0123 = _mm_loadu_si128((const __m128i*) w);
      __m128i vacc4567 = _mm_loadu_si128((const __m128i*) ((uintptr_t) w + 4 * sizeof(int32_t)));
      __m128i vacc89AB = _mm_loadu_si128((const __m128i*) ((uintptr_t) w + 8 * sizeof(int32_t)));
      __m128i vaccCDEF = _mm_loadu_si128((const __m128i*) ((uintptr_t) w + 12 * sizeof(int32_t)));


      const __m128i vi0x01234567 = _mm_loadl_epi64((const __m128i*) i0);
      const __m128i vk0x01234567 = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 0 * sizeof(int8_t)));
      const __m128i vi0x89ABCDEF = _mm_loadl_epi64((const __m128i*) (i0 + 8));
      const __m128i vk0x89ABCDEF = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 8 * sizeof(int8_t)));
      i0 += 16;

      const __m128i vxi0x01234567 = _mm_unpacklo_epi8(vi0x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vi0x01234567));
      const __m128i vxk0x01234567 = _mm_unpacklo_epi8(vk0x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vk0x01234567));
      const __m128i vxi0x89ABCDEF = _mm_unpacklo_epi8(vi0x89ABCDEF, _mm_cmpgt_epi8(_mm_setzero_si128(), vi0x89ABCDEF));
      const __m128i vxk0x89ABCDEF = _mm_unpacklo_epi8(vk0x89ABCDEF, _mm_cmpgt_epi8(_mm_setzero_si128(), vk0x89ABCDEF));

      const __m128i vp0x01234567lo = _mm_mullo_epi16(vxi0x01234567, vxk0x01234567);
      const __m128i vp0x01234567hi = _mm_mulhi_epi16(vxi0x01234567, vxk0x01234567);
      const __m128i vp0x89ABCDEFlo = _mm_mullo_epi16(vxi0x89ABCDEF, vxk0x89ABCDEF);
      const __m128i vp0x89ABCDEFhi = _mm_mulhi_epi16(vxi0x89ABCDEF, vxk0x89ABCDEF);

      vacc0123 = _mm_add_epi32(vacc0123, _mm_unpacklo_epi16(vp0x01234567lo, vp0x01234567hi));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_unpackhi_epi16(vp0x01234567lo, vp0x01234567hi));
      vacc89AB = _mm_add_epi32(vacc89AB, _mm_unpacklo_epi16(vp0x89ABCDEFlo, vp0x89ABCDEFhi));
      vaccCDEF = _mm_add_epi32(vaccCDEF, _mm_unpackhi_epi16(vp0x89ABCDEFlo, vp0x89ABCDEFhi));

      const __m128i vi1x01234567 = _mm_loadl_epi64((const __m128i*) i1);
      const __m128i vk1x01234567 = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 16 * sizeof(int8_t)));
      const __m128i vi1x89ABCDEF = _mm_loadl_epi64((const __m128i*) (i1 + 8));
      const __m128i vk1x89ABCDEF = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 24 * sizeof(int8_t)));
      i1 += 16;

      const __m128i vxi1x01234567 = _mm_unpacklo_epi8(vi1x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vi1x01234567));
      const __m128i vxk1x01234567 = _mm_unpacklo_epi8(vk1x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vk1x01234567));
      const __m128i vxi1x89ABCDEF = _mm_unpacklo_epi8(vi1x89ABCDEF, _mm_cmpgt_epi8(_mm_setzero_si128(), vi1x89ABCDEF));
      const __m128i vxk1x89ABCDEF = _mm_unpacklo_epi8(vk1x89ABCDEF, _mm_cmpgt_epi8(_mm_setzero_si128(), vk1x89ABCDEF));

      const __m128i vp1x01234567lo = _mm_mullo_epi16(vxi1x01234567, vxk1x01234567);
      const __m128i vp1x01234567hi = _mm_mulhi_epi16(vxi1x01234567, vxk1x01234567);
      const __m128i vp1x89ABCDEFlo = _mm_mullo_epi16(vxi1x89ABCDEF, vxk1x89ABCDEF);
      const __m128i vp1x89ABCDEFhi = _mm_mulhi_epi16(vxi1x89ABCDEF, vxk1x89ABCDEF);

      vacc0123 = _mm_add_epi32(vacc0123, _mm_unpacklo_epi16(vp1x01234567lo, vp1x01234567hi));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_unpackhi_epi16(vp1x01234567lo, vp1x01234567hi));
      vacc89AB = _mm_add_epi32(vacc89AB, _mm_unpacklo_epi16(vp1x89ABCDEFlo, vp1x89ABCDEFhi));
      vaccCDEF = _mm_add_epi32(vaccCDEF, _mm_unpackhi_epi16(vp1x89ABCDEFlo, vp1x89ABCDEFhi));

      const __m128i vi2x01234567 = _mm_loadl_epi64((const __m128i*) i2);
      const __m128i vk2x01234567 = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 32 * sizeof(int8_t)));
      const __m128i vi2x89ABCDEF = _mm_loadl_epi64((const __m128i*) (i2 + 8));
      const __m128i vk2x89ABCDEF = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 40 * sizeof(int8_t)));
      i2 += 16;

      const __m128i vxi2x01234567 = _mm_unpacklo_epi8(vi2x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vi2x01234567));
      const __m128i vxk2x01234567 = _mm_unpacklo_epi8(vk2x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vk2x01234567));
      const __m128i vxi2x89ABCDEF = _mm_unpacklo_epi8(vi2x89ABCDEF, _mm_cmpgt_epi8(_mm_setzero_si128(), vi2x89ABCDEF));
      const __m128i vxk2x89ABCDEF = _mm_unpacklo_epi8(vk2x89ABCDEF, _mm_cmpgt_epi8(_mm_setzero_si128(), vk2x89ABCDEF));

      const __m128i vp2x01234567lo = _mm_mullo_epi16(vxi2x01234567, vxk2x01234567);
      const __m128i vp2x01234567hi = _mm_mulhi_epi16(vxi2x01234567, vxk2x01234567);
      const __m128i vp2x89ABCDEFlo = _mm_mullo_epi16(vxi2x89ABCDEF, vxk2x89ABCDEF);
      const __m128i vp2x89ABCDEFhi = _mm_mulhi_epi16(vxi2x89ABCDEF, vxk2x89ABCDEF);

      vacc0123 = _mm_add_epi32(vacc0123, _mm_unpacklo_epi16(vp2x01234567lo, vp2x01234567hi));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_unpackhi_epi16(vp2x01234567lo, vp2x01234567hi));
      vacc89AB = _mm_add_epi32(vacc89AB, _mm_unpacklo_epi16(vp2x89ABCDEFlo, vp2x89ABCDEFhi));
      vaccCDEF = _mm_add_epi32(vaccCDEF, _mm_unpackhi_epi16(vp2x89ABCDEFlo, vp2x89ABCDEFhi));

      const __m128i vi3x01234567 = _mm_loadl_epi64((const __m128i*) i3);
      const __m128i vk3x01234567 = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 48 * sizeof(int8_t)));
      const __m128i vi3x89ABCDEF = _mm_loadl_epi64((const __m128i*) (i3 + 8));
      const __m128i vk3x89ABCDEF = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 56 * sizeof(int8_t)));
      i3 += 16;

      const __m128i vxi3x01234567 = _mm_unpacklo_epi8(vi3x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vi3x01234567));
      const __m128i vxk3x01234567 = _mm_unpacklo_epi8(vk3x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vk3x01234567));
      const __m128i vxi3x89ABCDEF = _mm_unpacklo_epi8(vi3x89ABCDEF, _mm_cmpgt_epi8(_mm_setzero_si128(), vi3x89ABCDEF));
      const __m128i vxk3x89ABCDEF = _mm_unpacklo_epi8(vk3x89ABCDEF, _mm_cmpgt_epi8(_mm_setzero_si128(), vk3x89ABCDEF));

      const __m128i vp3x01234567lo = _mm_mullo_epi16(vxi3x01234567, vxk3x01234567);
      const __m128i vp3x01234567hi = _mm_mulhi_epi16(vxi3x01234567, vxk3x01234567);
      const __m128i vp3x89ABCDEFlo = _mm_mullo_epi16(vxi3x89ABCDEF, vxk3x89ABCDEF);
      const __m128i vp3x89ABCDEFhi = _mm_mulhi_epi16(vxi3x89ABCDEF, vxk3x89ABCDEF);

      vacc0123 = _mm_add_epi32(vacc0123, _mm_unpacklo_epi16(vp3x01234567lo, vp3x01234567hi));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_unpackhi_epi16(vp3x01234567lo, vp3x01234567hi));
      vacc89AB = _mm_add_epi32(vacc89AB, _mm_unpacklo_epi16(vp3x89ABCDEFlo, vp3x89ABCDEFhi));
      vaccCDEF = _mm_add_epi32(vaccCDEF, _mm_unpackhi_epi16(vp3x89ABCDEFlo, vp3x89ABCDEFhi));

      const __m128i vi4x01234567 = _mm_loadl_epi64((const __m128i*) i4);
      const __m128i vk4x01234567 = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 64 * sizeof(int8_t)));
      const __m128i vi4x89ABCDEF = _mm_loadl_epi64((const __m128i*) (i4 + 8));
      const __m128i vk4x89ABCDEF = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 72 * sizeof(int8_t)));
      i4 += 16;

      const __m128i vxi4x01234567 = _mm_unpacklo_epi8(vi4x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vi4x01234567));
      const __m128i vxk4x01234567 = _mm_unpacklo_epi8(vk4x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vk4x01234567));
      const __m128i vxi4x89ABCDEF = _mm_unpacklo_epi8(vi4x89ABCDEF, _mm_cmpgt_epi8(_mm_setzero_si128(), vi4x89ABCDEF));
      const __m128i vxk4x89ABCDEF = _mm_unpacklo_epi8(vk4x89ABCDEF, _mm_cmpgt_epi8(_mm_setzero_si128(), vk4x89ABCDEF));

      const __m128i vp4x01234567lo = _mm_mullo_epi16(vxi4x01234567, vxk4x01234567);
      const __m128i vp4x01234567hi = _mm_mulhi_epi16(vxi4x01234567, vxk4x01234567);
      const __m128i vp4x89ABCDEFlo = _mm_mullo_epi16(vxi4x89ABCDEF, vxk4x89ABCDEF);
      const __m128i vp4x89ABCDEFhi = _mm_mulhi_epi16(vxi4x89ABCDEF, vxk4x89ABCDEF);

      vacc0123 = _mm_add_epi32(vacc0123, _mm_unpacklo_epi16(vp4x01234567lo, vp4x01234567hi));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_unpackhi_epi16(vp4x01234567lo, vp4x01234567hi));
      vacc89AB = _mm_add_epi32(vacc89AB, _mm_unpacklo_epi16(vp4x89ABCDEFlo, vp4x89ABCDEFhi));
      vaccCDEF = _mm_add_epi32(vaccCDEF, _mm_unpackhi_epi16(vp4x89ABCDEFlo, vp4x89ABCDEFhi));

      const __m128i vi5x01234567 = _mm_loadl_epi64((const __m128i*) i5);
      const __m128i vk5x01234567 = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 80 * sizeof(int8_t)));
      const __m128i vi5x89ABCDEF = _mm_loadl_epi64((const __m128i*) (i5 + 8));
      const __m128i vk5x89ABCDEF = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 88 * sizeof(int8_t)));
      i5 += 16;

      const __m128i vxi5x01234567 = _mm_unpacklo_epi8(vi5x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vi5x01234567));
      const __m128i vxk5x01234567 = _mm_unpacklo_epi8(vk5x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vk5x01234567));
      const __m128i vxi5x89ABCDEF = _mm_unpacklo_epi8(vi5x89ABCDEF, _mm_cmpgt_epi8(_mm_setzero_si128(), vi5x89ABCDEF));
      const __m128i vxk5x89ABCDEF = _mm_unpacklo_epi8(vk5x89ABCDEF, _mm_cmpgt_epi8(_mm_setzero_si128(), vk5x89ABCDEF));

      const __m128i vp5x01234567lo = _mm_mullo_epi16(vxi5x01234567, vxk5x01234567);
      const __m128i vp5x01234567hi = _mm_mulhi_epi16(vxi5x01234567, vxk5x01234567);
      const __m128i vp5x89ABCDEFlo = _mm_mullo_epi16(vxi5x89ABCDEF, vxk5x89ABCDEF);
      const __m128i vp5x89ABCDEFhi = _mm_mulhi_epi16(vxi5x89ABCDEF, vxk5x89ABCDEF);

      vacc0123 = _mm_add_epi32(vacc0123, _mm_unpacklo_epi16(vp5x01234567lo, vp5x01234567hi));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_unpackhi_epi16(vp5x01234567lo, vp5x01234567hi));
      vacc89AB = _mm_add_epi32(vacc89AB, _mm_unpacklo_epi16(vp5x89ABCDEFlo, vp5x89ABCDEFhi));
      vaccCDEF = _mm_add_epi32(vaccCDEF, _mm_unpackhi_epi16(vp5x89ABCDEFlo, vp5x89ABCDEFhi));

      const __m128i vi6x01234567 = _mm_loadl_epi64((const __m128i*) i6);
      const __m128i vk6x01234567 = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 96 * sizeof(int8_t)));
      const __m128i vi6x89ABCDEF = _mm_loadl_epi64((const __m128i*) (i6 + 8));
      const __m128i vk6x89ABCDEF = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 104 * sizeof(int8_t)));
      i6 += 16;

      const __m128i vxi6x01234567 = _mm_unpacklo_epi8(vi6x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vi6x01234567));
      const __m128i vxk6x01234567 = _mm_unpacklo_epi8(vk6x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vk6x01234567));
      const __m128i vxi6x89ABCDEF = _mm_unpacklo_epi8(vi6x89ABCDEF, _mm_cmpgt_epi8(_mm_setzero_si128(), vi6x89ABCDEF));
      const __m128i vxk6x89ABCDEF = _mm_unpacklo_epi8(vk6x89ABCDEF, _mm_cmpgt_epi8(_mm_setzero_si128(), vk6x89ABCDEF));

      const __m128i vp6x01234567lo = _mm_mullo_epi16(vxi6x01234567, vxk6x01234567);
      const __m128i vp6x01234567hi = _mm_mulhi_epi16(vxi6x01234567, vxk6x01234567);
      const __m128i vp6x89ABCDEFlo = _mm_mullo_epi16(vxi6x89ABCDEF, vxk6x89ABCDEF);
      const __m128i vp6x89ABCDEFhi = _mm_mulhi_epi16(vxi6x89ABCDEF, vxk6x89ABCDEF);

      vacc0123 = _mm_add_epi32(vacc0123, _mm_unpacklo_epi16(vp6x01234567lo, vp6x01234567hi));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_unpackhi_epi16(vp6x01234567lo, vp6x01234567hi));
      vacc89AB = _mm_add_epi32(vacc89AB, _mm_unpacklo_epi16(vp6x89ABCDEFlo, vp6x89ABCDEFhi));
      vaccCDEF = _mm_add_epi32(vaccCDEF, _mm_unpackhi_epi16(vp6x89ABCDEFlo, vp6x89ABCDEFhi));

      const __m128i vi7x01234567 = _mm_loadl_epi64((const __m128i*) i7);
      const __m128i vk7x01234567 = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 112 * sizeof(int8_t)));
      const __m128i vi7x89ABCDEF = _mm_loadl_epi64((const __m128i*) (i7 + 8));
      const __m128i vk7x89ABCDEF = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 120 * sizeof(int8_t)));
      i7 += 16;

      const __m128i vxi7x01234567 = _mm_unpacklo_epi8(vi7x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vi7x01234567));
      const __m128i vxk7x01234567 = _mm_unpacklo_epi8(vk7x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vk7x01234567));
      const __m128i vxi7x89ABCDEF = _mm_unpacklo_epi8(vi7x89ABCDEF, _mm_cmpgt_epi8(_mm_setzero_si128(), vi7x89ABCDEF));
      const __m128i vxk7x89ABCDEF = _mm_unpacklo_epi8(vk7x89ABCDEF, _mm_cmpgt_epi8(_mm_setzero_si128(), vk7x89ABCDEF));

      const __m128i vp7x01234567lo = _mm_mullo_epi16(vxi7x01234567, vxk7x01234567);
      const __m128i vp7x01234567hi = _mm_mulhi_epi16(vxi7x01234567, vxk7x01234567);
      const __m128i vp7x89ABCDEFlo = _mm_mullo_epi16(vxi7x89ABCDEF, vxk7x89ABCDEF);
      const __m128i vp7x89ABCDEFhi = _mm_mulhi_epi16(vxi7x89ABCDEF, vxk7x89ABCDEF);

      vacc0123 = _mm_add_epi32(vacc0123, _mm_unpacklo_epi16(vp7x01234567lo, vp7x01234567hi));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_unpackhi_epi16(vp7x01234567lo, vp7x01234567hi));
      vacc89AB = _mm_add_epi32(vacc89AB, _mm_unpacklo_epi16(vp7x89ABCDEFlo, vp7x89ABCDEFhi));
      vaccCDEF = _mm_add_epi32(vaccCDEF, _mm_unpackhi_epi16(vp7x89ABCDEFlo, vp7x89ABCDEFhi));

      const __m128i vi8x01234567 = _mm_loadl_epi64((const __m128i*) i8);
      const __m128i vk8x01234567 = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 128 * sizeof(int8_t)));
      const __m128i vi8x89ABCDEF = _mm_loadl_epi64((const __m128i*) (i8 + 8));
      const __m128i vk8x89ABCDEF = _mm_loadl_epi64((const __m128i*) ((uintptr_t) w + 16 * sizeof(int32_t) + 136 * sizeof(int8_t)));
      i8 += 16;

      const __m128i vxi8x01234567 = _mm_unpacklo_epi8(vi8x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vi8x01234567));
      const __m128i vxk8x01234567 = _mm_unpacklo_epi8(vk8x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vk8x01234567));
      const __m128i vxi8x89ABCDEF = _mm_unpacklo_epi8(vi8x89ABCDEF, _mm_cmpgt_epi8(_mm_setzero_si128(), vi8x89ABCDEF));
      const __m128i vxk8x89ABCDEF = _mm_unpacklo_epi8(vk8x89ABCDEF, _mm_cmpgt_epi8(_mm_setzero_si128(), vk8x89ABCDEF));

      const __m128i vp8x01234567lo = _mm_mullo_epi16(vxi8x01234567, vxk8x01234567);
      const __m128i vp8x01234567hi = _mm_mulhi_epi16(vxi8x01234567, vxk8x01234567);
      const __m128i vp8x89ABCDEFlo = _mm_mullo_epi16(vxi8x89ABCDEF, vxk8x89ABCDEF);
      const __m128i vp8x89ABCDEFhi = _mm_mulhi_epi16(vxi8x89ABCDEF, vxk8x89ABCDEF);

      vacc0123 = _mm_add_epi32(vacc0123, _mm_unpacklo_epi16(vp8x01234567lo, vp8x01234567hi));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_unpackhi_epi16(vp8x01234567lo, vp8x01234567hi));
      vacc89AB = _mm_add_epi32(vacc89AB, _mm_unpacklo_epi16(vp8x89ABCDEFlo, vp8x89ABCDEFhi));
      vaccCDEF = _mm_add_epi32(vaccCDEF, _mm_unpackhi_epi16(vp8x89ABCDEFlo, vp8x89ABCDEFhi));

      w = (const void*) ((uintptr_t) w + 16 * sizeof(int32_t) + 144 * sizeof(int8_t));

      const __m128i vmultiplier = _mm_load_si128((const __m128i*) params->sse2.multiplier);
      const __m128i vrounding = _mm_load_si128((const __m128i*) params->sse2.rounding);

      const __m128i vnmask0123 = _mm_cmpgt_epi32(_mm_setzero_si128(), vacc0123);
      const __m128i vnmask4567 = _mm_cmpgt_epi32(_mm_setzero_si128(), vacc4567);
      const __m128i vnmask89AB = _mm_cmpgt_epi32(_mm_setzero_si128(), vacc89AB);
      const __m128i vnmaskCDEF = _mm_cmpgt_epi32(_mm_setzero_si128(), vaccCDEF);

      const __m128i vabsacc0123 = _mm_sub_epi32(_mm_xor_si128(vacc0123, vnmask0123), vnmask0123);
      const __m128i vabsacc4567 = _mm_sub_epi32(_mm_xor_si128(vacc4567, vnmask4567), vnmask4567);
      const __m128i vabsacc89AB = _mm_sub_epi32(_mm_xor_si128(vacc89AB, vnmask89AB), vnmask89AB);
      const __m128i vabsaccCDEF = _mm_sub_epi32(_mm_xor_si128(vaccCDEF, vnmaskCDEF), vnmaskCDEF);

      const __m128i vabsacc13 = _mm_shuffle_epi32(vabsacc0123, _MM_SHUFFLE(3, 3, 1, 1));
      const __m128i vabsprod02 = _mm_mul_epu32(vabsacc0123, vmultiplier);
      const __m128i vabsprod13 = _mm_mul_epu32(vabsacc13, vmultiplier);
      const __m128i vabsacc57 = _mm_shuffle_epi32(vabsacc4567, _MM_SHUFFLE(3, 3, 1, 1));
      const __m128i vabsprod46 = _mm_mul_epu32(vabsacc4567, vmultiplier);
      const __m128i vabsprod57 = _mm_mul_epu32(vabsacc57, vmultiplier);
      const __m128i vabsacc9B = _mm_shuffle_epi32(vabsacc89AB, _MM_SHUFFLE(3, 3, 1, 1));
      const __m128i vabsprod8A = _mm_mul_epu32(vabsacc89AB, vmultiplier);
      const __m128i vabsprod9B = _mm_mul_epu32(vabsacc9B, vmultiplier);
      const __m128i vabsaccDF = _mm_shuffle_epi32(vabsaccCDEF, _MM_SHUFFLE(3, 3, 1, 1));
      const __m128i vabsprodCE = _mm_mul_epu32(vabsaccCDEF, vmultiplier);
      const __m128i vabsprodDF = _mm_mul_epu32(vabsaccDF, vmultiplier);

      const __m128i vnmask02 = _mm_shuffle_epi32(vnmask0123, _MM_SHUFFLE(2, 2, 0, 0));
      const __m128i vnmask13 = _mm_shuffle_epi32(vnmask0123, _MM_SHUFFLE(3, 3, 1, 1));
      const __m128i vnmask46 = _mm_shuffle_epi32(vnmask4567, _MM_SHUFFLE(2, 2, 0, 0));
      const __m128i vnmask57 = _mm_shuffle_epi32(vnmask4567, _MM_SHUFFLE(3, 3, 1, 1));
      const __m128i vnmask8A = _mm_shuffle_epi32(vnmask89AB, _MM_SHUFFLE(2, 2, 0, 0));
      const __m128i vnmask9B = _mm_shuffle_epi32(vnmask89AB, _MM_SHUFFLE(3, 3, 1, 1));
      const __m128i vnmaskCE = _mm_shuffle_epi32(vnmaskCDEF, _MM_SHUFFLE(2, 2, 0, 0));
      const __m128i vnmaskDF = _mm_shuffle_epi32(vnmaskCDEF, _MM_SHUFFLE(3, 3, 1, 1));

      const __m128i vprod02 = _mm_sub_epi64(_mm_xor_si128(vabsprod02, vnmask02), vnmask02);
      const __m128i vprod13 = _mm_sub_epi64(_mm_xor_si128(vabsprod13, vnmask13), vnmask13);
      const __m128i vprod46 = _mm_sub_epi64(_mm_xor_si128(vabsprod46, vnmask46), vnmask46);
      const __m128i vprod57 = _mm_sub_epi64(_mm_xor_si128(vabsprod57, vnmask57), vnmask57);
      const __m128i vprod8A = _mm_sub_epi64(_mm_xor_si128(vabsprod8A, vnmask8A), vnmask8A);
      const __m128i vprod9B = _mm_sub_epi64(_mm_xor_si128(vabsprod9B, vnmask9B), vnmask9B);
      const __m128i vprodCE = _mm_sub_epi64(_mm_xor_si128(vabsprodCE, vnmaskCE), vnmaskCE);
      const __m128i vprodDF = _mm_sub_epi64(_mm_xor_si128(vabsprodDF, vnmaskDF), vnmaskDF);

      const __m128i vq31prod02 = _mm_srli_epi64(_mm_add_epi64(vprod02, vrounding), 31);
      const __m128i vq31prod13 = _mm_srli_epi64(_mm_add_epi64(vprod13, vrounding), 31);
      const __m128i vq31prod46 = _mm_srli_epi64(_mm_add_epi64(vprod46, vrounding), 31);
      const __m128i vq31prod57 = _mm_srli_epi64(_mm_add_epi64(vprod57, vrounding), 31);
      const __m128i vq31prod8A = _mm_srli_epi64(_mm_add_epi64(vprod8A, vrounding), 31);
      const __m128i vq31prod9B = _mm_srli_epi64(_mm_add_epi64(vprod9B, vrounding), 31);
      const __m128i vq31prodCE = _mm_srli_epi64(_mm_add_epi64(vprodCE, vrounding), 31);
      const __m128i vq31prodDF = _mm_srli_epi64(_mm_add_epi64(vprodDF, vrounding), 31);

      const __m128i vq31prod0213 = _mm_castps_si128(_mm_shuffle_ps(
          _mm_castsi128_ps(vq31prod02), _mm_castsi128_ps(vq31prod13), _MM_SHUFFLE(2, 0, 2, 0)));
      const __m128i vq31prod4657 = _mm_castps_si128(_mm_shuffle_ps(
          _mm_castsi128_ps(vq31prod46), _mm_castsi128_ps(vq31prod57), _MM_SHUFFLE(2, 0, 2, 0)));
      const __m128i vq31prod8A9B = _mm_castps_si128(_mm_shuffle_ps(
          _mm_castsi128_ps(vq31prod8A), _mm_castsi128_ps(vq31prod9B), _MM_SHUFFLE(2, 0, 2, 0)));
      const __m128i vq31prodCEDF = _mm_castps_si128(_mm_shuffle_ps(
          _mm_castsi128_ps(vq31prodCE), _mm_castsi128_ps(vq31prodDF), _MM_SHUFFLE(2, 0, 2, 0)));

      const __m128i vq31prod0123 = _mm_shuffle_epi32(vq31prod0213, _MM_SHUFFLE(3, 1, 2, 0));
      const __m128i vq31prod4567 = _mm_shuffle_epi32(vq31prod4657, _MM_SHUFFLE(3, 1, 2, 0));
      const __m128i vq31prod89AB = _mm_shuffle_epi32(vq31prod8A9B, _MM_SHUFFLE(3, 1, 2, 0));
      const __m128i vq31prodCDEF = _mm_shuffle_epi32(vq31prodCEDF, _MM_SHUFFLE(3, 1, 2, 0));

      const __m128i vremainder_mask = _mm_load_si128((const __m128i*) params->sse2.remainder_mask);
      const __m128i vrem0123 =
        _mm_add_epi32(_mm_and_si128(vq31prod0123, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prod0123));
      const __m128i vrem4567 =
        _mm_add_epi32(_mm_and_si128(vq31prod4567, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prod4567));
      const __m128i vrem89AB =
        _mm_add_epi32(_mm_and_si128(vq31prod89AB, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prod89AB));
      const __m128i vremCDEF =
        _mm_add_epi32(_mm_and_si128(vq31prodCDEF, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prodCDEF));

      const __m128i vremainder_threshold = _mm_load_si128((const __m128i*) params->sse2.remainder_threshold);
      const __m128i vshift = _mm_load_si128((const __m128i*) params->sse2.shift);
      vacc0123 =
        _mm_sub_epi32(_mm_sra_epi32(vq31prod0123, vshift), _mm_cmpgt_epi32(vrem0123, vremainder_threshold));
      vacc4567 =
        _mm_sub_epi32(_mm_sra_epi32(vq31prod4567, vshift), _mm_cmpgt_epi32(vrem4567, vremainder_threshold));
      vacc89AB =
        _mm_sub_epi32(_mm_sra_epi32(vq31prod89AB, vshift), _mm_cmpgt_epi32(vrem89AB, vremainder_threshold));
      vaccCDEF =
        _mm_sub_epi32(_mm_sra_epi32(vq31prodCDEF, vshift), _mm_cmpgt_epi32(vremCDEF, vremainder_threshold));

      const __m128i voutput_zero_point = _mm_load_si128((const __m128i*) params->sse2.output_zero_point);
      __m128i vout01234567 = _mm_adds_epi16(_mm_packs_epi32(vacc0123, vacc4567), voutput_zero_point);
      __m128i vout89ABCDEF = _mm_adds_epi16(_mm_packs_epi32(vacc89AB, vaccCDEF), voutput_zero_point);

      const __m128i voutput_min = _mm_load_si128((const __m128i*) params->sse2.output_min);
      const __m128i voutput_max = _mm_load_si128((const __m128i*) params->sse2.output_max);
      vout01234567 = _mm_min_epi16(_mm_max_epi16(vout01234567, voutput_min), voutput_max);
      vout89ABCDEF = _mm_min_epi16(_mm_max_epi16(vout89ABCDEF, voutput_min), voutput_max);

      __m128i vout0123456789ABCDEF = _mm_packs_epi16(vout01234567, vout89ABCDEF);

      _mm_storeu_si128((__m128i*) output, vout0123456789ABCDEF);
      output += 16;
    }
    if XNN_UNLIKELY(c != 0) {
      const int8_t* k = (const int8_t*) ((uintptr_t) w + 16 * sizeof(int32_t));
      do {
        __m128i vacc0123 = _mm_loadu_si128((const __m128i*) w);
        __m128i vacc4567 = _mm_loadu_si128((const __m128i*) ((uintptr_t) w + 4 * sizeof(int32_t)));


        const __m128i vi0x01234567 = _mm_loadl_epi64((const __m128i*) i0);
        const __m128i vk0x01234567 = _mm_loadl_epi64((const __m128i*) k);
        i0 += 8;

        const __m128i vxi0x01234567 = _mm_unpacklo_epi8(vi0x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vi0x01234567));
        const __m128i vxk0x01234567 = _mm_unpacklo_epi8(vk0x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vk0x01234567));

        const __m128i vp0x01234567lo = _mm_mullo_epi16(vxi0x01234567, vxk0x01234567);
        const __m128i vp0x01234567hi = _mm_mulhi_epi16(vxi0x01234567, vxk0x01234567);

        vacc0123 = _mm_add_epi32(vacc0123, _mm_unpacklo_epi16(vp0x01234567lo, vp0x01234567hi));
        vacc4567 = _mm_add_epi32(vacc4567, _mm_unpackhi_epi16(vp0x01234567lo, vp0x01234567hi));

        const __m128i vi1x01234567 = _mm_loadl_epi64((const __m128i*) i1);
        const __m128i vk1x01234567 = _mm_loadl_epi64((const __m128i*) (k + 16));
        i1 += 8;

        const __m128i vxi1x01234567 = _mm_unpacklo_epi8(vi1x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vi1x01234567));
        const __m128i vxk1x01234567 = _mm_unpacklo_epi8(vk1x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vk1x01234567));

        const __m128i vp1x01234567lo = _mm_mullo_epi16(vxi1x01234567, vxk1x01234567);
        const __m128i vp1x01234567hi = _mm_mulhi_epi16(vxi1x01234567, vxk1x01234567);

        vacc0123 = _mm_add_epi32(vacc0123, _mm_unpacklo_epi16(vp1x01234567lo, vp1x01234567hi));
        vacc4567 = _mm_add_epi32(vacc4567, _mm_unpackhi_epi16(vp1x01234567lo, vp1x01234567hi));

        const __m128i vi2x01234567 = _mm_loadl_epi64((const __m128i*) i2);
        const __m128i vk2x01234567 = _mm_loadl_epi64((const __m128i*) (k + 32));
        i2 += 8;

        const __m128i vxi2x01234567 = _mm_unpacklo_epi8(vi2x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vi2x01234567));
        const __m128i vxk2x01234567 = _mm_unpacklo_epi8(vk2x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vk2x01234567));

        const __m128i vp2x01234567lo = _mm_mullo_epi16(vxi2x01234567, vxk2x01234567);
        const __m128i vp2x01234567hi = _mm_mulhi_epi16(vxi2x01234567, vxk2x01234567);

        vacc0123 = _mm_add_epi32(vacc0123, _mm_unpacklo_epi16(vp2x01234567lo, vp2x01234567hi));
        vacc4567 = _mm_add_epi32(vacc4567, _mm_unpackhi_epi16(vp2x01234567lo, vp2x01234567hi));

        const __m128i vi3x01234567 = _mm_loadl_epi64((const __m128i*) i3);
        const __m128i vk3x01234567 = _mm_loadl_epi64((const __m128i*) (k + 48));
        i3 += 8;

        const __m128i vxi3x01234567 = _mm_unpacklo_epi8(vi3x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vi3x01234567));
        const __m128i vxk3x01234567 = _mm_unpacklo_epi8(vk3x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vk3x01234567));

        const __m128i vp3x01234567lo = _mm_mullo_epi16(vxi3x01234567, vxk3x01234567);
        const __m128i vp3x01234567hi = _mm_mulhi_epi16(vxi3x01234567, vxk3x01234567);

        vacc0123 = _mm_add_epi32(vacc0123, _mm_unpacklo_epi16(vp3x01234567lo, vp3x01234567hi));
        vacc4567 = _mm_add_epi32(vacc4567, _mm_unpackhi_epi16(vp3x01234567lo, vp3x01234567hi));

        const __m128i vi4x01234567 = _mm_loadl_epi64((const __m128i*) i4);
        const __m128i vk4x01234567 = _mm_loadl_epi64((const __m128i*) (k + 64));
        i4 += 8;

        const __m128i vxi4x01234567 = _mm_unpacklo_epi8(vi4x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vi4x01234567));
        const __m128i vxk4x01234567 = _mm_unpacklo_epi8(vk4x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vk4x01234567));

        const __m128i vp4x01234567lo = _mm_mullo_epi16(vxi4x01234567, vxk4x01234567);
        const __m128i vp4x01234567hi = _mm_mulhi_epi16(vxi4x01234567, vxk4x01234567);

        vacc0123 = _mm_add_epi32(vacc0123, _mm_unpacklo_epi16(vp4x01234567lo, vp4x01234567hi));
        vacc4567 = _mm_add_epi32(vacc4567, _mm_unpackhi_epi16(vp4x01234567lo, vp4x01234567hi));

        const __m128i vi5x01234567 = _mm_loadl_epi64((const __m128i*) i5);
        const __m128i vk5x01234567 = _mm_loadl_epi64((const __m128i*) (k + 80));
        i5 += 8;

        const __m128i vxi5x01234567 = _mm_unpacklo_epi8(vi5x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vi5x01234567));
        const __m128i vxk5x01234567 = _mm_unpacklo_epi8(vk5x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vk5x01234567));

        const __m128i vp5x01234567lo = _mm_mullo_epi16(vxi5x01234567, vxk5x01234567);
        const __m128i vp5x01234567hi = _mm_mulhi_epi16(vxi5x01234567, vxk5x01234567);

        vacc0123 = _mm_add_epi32(vacc0123, _mm_unpacklo_epi16(vp5x01234567lo, vp5x01234567hi));
        vacc4567 = _mm_add_epi32(vacc4567, _mm_unpackhi_epi16(vp5x01234567lo, vp5x01234567hi));

        const __m128i vi6x01234567 = _mm_loadl_epi64((const __m128i*) i6);
        const __m128i vk6x01234567 = _mm_loadl_epi64((const __m128i*) (k + 96));
        i6 += 8;

        const __m128i vxi6x01234567 = _mm_unpacklo_epi8(vi6x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vi6x01234567));
        const __m128i vxk6x01234567 = _mm_unpacklo_epi8(vk6x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vk6x01234567));

        const __m128i vp6x01234567lo = _mm_mullo_epi16(vxi6x01234567, vxk6x01234567);
        const __m128i vp6x01234567hi = _mm_mulhi_epi16(vxi6x01234567, vxk6x01234567);

        vacc0123 = _mm_add_epi32(vacc0123, _mm_unpacklo_epi16(vp6x01234567lo, vp6x01234567hi));
        vacc4567 = _mm_add_epi32(vacc4567, _mm_unpackhi_epi16(vp6x01234567lo, vp6x01234567hi));

        const __m128i vi7x01234567 = _mm_loadl_epi64((const __m128i*) i7);
        const __m128i vk7x01234567 = _mm_loadl_epi64((const __m128i*) (k + 112));
        i7 += 8;

        const __m128i vxi7x01234567 = _mm_unpacklo_epi8(vi7x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vi7x01234567));
        const __m128i vxk7x01234567 = _mm_unpacklo_epi8(vk7x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vk7x01234567));

        const __m128i vp7x01234567lo = _mm_mullo_epi16(vxi7x01234567, vxk7x01234567);
        const __m128i vp7x01234567hi = _mm_mulhi_epi16(vxi7x01234567, vxk7x01234567);

        vacc0123 = _mm_add_epi32(vacc0123, _mm_unpacklo_epi16(vp7x01234567lo, vp7x01234567hi));
        vacc4567 = _mm_add_epi32(vacc4567, _mm_unpackhi_epi16(vp7x01234567lo, vp7x01234567hi));

        const __m128i vi8x01234567 = _mm_loadl_epi64((const __m128i*) i8);
        const __m128i vk8x01234567 = _mm_loadl_epi64((const __m128i*) (k + 128));
        i8 += 8;

        const __m128i vxi8x01234567 = _mm_unpacklo_epi8(vi8x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vi8x01234567));
        const __m128i vxk8x01234567 = _mm_unpacklo_epi8(vk8x01234567, _mm_cmpgt_epi8(_mm_setzero_si128(), vk8x01234567));

        const __m128i vp8x01234567lo = _mm_mullo_epi16(vxi8x01234567, vxk8x01234567);
        const __m128i vp8x01234567hi = _mm_mulhi_epi16(vxi8x01234567, vxk8x01234567);

        vacc0123 = _mm_add_epi32(vacc0123, _mm_unpacklo_epi16(vp8x01234567lo, vp8x01234567hi));
        vacc4567 = _mm_add_epi32(vacc4567, _mm_unpackhi_epi16(vp8x01234567lo, vp8x01234567hi));

        w = (const void*) ((uintptr_t) w + 8 * sizeof(int32_t));
        k += 8;

        const __m128i vmultiplier = _mm_load_si128((const __m128i*) params->sse2.multiplier);
        const __m128i vrounding = _mm_load_si128((const __m128i*) params->sse2.rounding);

        const __m128i vnmask0123 = _mm_cmpgt_epi32(_mm_setzero_si128(), vacc0123);
        const __m128i vnmask4567 = _mm_cmpgt_epi32(_mm_setzero_si128(), vacc4567);

        const __m128i vabsacc0123 = _mm_sub_epi32(_mm_xor_si128(vacc0123, vnmask0123), vnmask0123);
        const __m128i vabsacc4567 = _mm_sub_epi32(_mm_xor_si128(vacc4567, vnmask4567), vnmask4567);

        const __m128i vabsacc13 = _mm_shuffle_epi32(vabsacc0123, _MM_SHUFFLE(3, 3, 1, 1));
        const __m128i vabsacc57 = _mm_shuffle_epi32(vabsacc4567, _MM_SHUFFLE(3, 3, 1, 1));

        const __m128i vabsprod02 = _mm_mul_epu32(vabsacc0123, vmultiplier);
        const __m128i vabsprod13 = _mm_mul_epu32(vabsacc13, vmultiplier);
        const __m128i vabsprod46 = _mm_mul_epu32(vabsacc4567, vmultiplier);
        const __m128i vabsprod57 = _mm_mul_epu32(vabsacc57, vmultiplier);

        const __m128i vnmask02 = _mm_shuffle_epi32(vnmask0123, _MM_SHUFFLE(2, 2, 0, 0));
        const __m128i vnmask13 = _mm_shuffle_epi32(vnmask0123, _MM_SHUFFLE(3, 3, 1, 1));
        const __m128i vnmask46 = _mm_shuffle_epi32(vnmask4567, _MM_SHUFFLE(2, 2, 0, 0));
        const __m128i vnmask57 = _mm_shuffle_epi32(vnmask4567, _MM_SHUFFLE(3, 3, 1, 1));

        const __m128i vprod02 = _mm_sub_epi64(_mm_xor_si128(vabsprod02, vnmask02), vnmask02);
        const __m128i vprod13 = _mm_sub_epi64(_mm_xor_si128(vabsprod13, vnmask13), vnmask13);
        const __m128i vprod46 = _mm_sub_epi64(_mm_xor_si128(vabsprod46, vnmask46), vnmask46);
        const __m128i vprod57 = _mm_sub_epi64(_mm_xor_si128(vabsprod57, vnmask57), vnmask57);

        const __m128i vq31prod02 = _mm_srli_epi64(_mm_add_epi64(vprod02, vrounding), 31);
        const __m128i vq31prod13 = _mm_srli_epi64(_mm_add_epi64(vprod13, vrounding), 31);
        const __m128i vq31prod46 = _mm_srli_epi64(_mm_add_epi64(vprod46, vrounding), 31);
        const __m128i vq31prod57 = _mm_srli_epi64(_mm_add_epi64(vprod57, vrounding), 31);

        const __m128i vq31prod0213 = _mm_castps_si128(_mm_shuffle_ps(
            _mm_castsi128_ps(vq31prod02), _mm_castsi128_ps(vq31prod13), _MM_SHUFFLE(2, 0, 2, 0)));
        const __m128i vq31prod4657 = _mm_castps_si128(_mm_shuffle_ps(
            _mm_castsi128_ps(vq31prod46), _mm_castsi128_ps(vq31prod57), _MM_SHUFFLE(2, 0, 2, 0)));

        const __m128i vq31prod0123 = _mm_shuffle_epi32(vq31prod0213, _MM_SHUFFLE(3, 1, 2, 0));
        const __m128i vq31prod4567 = _mm_shuffle_epi32(vq31prod4657, _MM_SHUFFLE(3, 1, 2, 0));

        const __m128i vremainder_mask = _mm_load_si128((const __m128i*) params->sse2.remainder_mask);
        const __m128i vrem0123 =
          _mm_add_epi32(_mm_and_si128(vq31prod0123, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prod0123));
        const __m128i vrem4567 =
          _mm_add_epi32(_mm_and_si128(vq31prod4567, vremainder_mask), _mm_cmpgt_epi32(_mm_setzero_si128(), vq31prod4567));

        const __m128i vremainder_threshold = _mm_load_si128((const __m128i*) params->sse2.remainder_threshold);
        const __m128i vshift = _mm_load_si128((const __m128i*) params->sse2.shift);
        vacc0123 =
          _mm_sub_epi32(_mm_sra_epi32(vq31prod0123, vshift), _mm_cmpgt_epi32(vrem0123, vremainder_threshold));
        vacc4567 =
          _mm_sub_epi32(_mm_sra_epi32(vq31prod4567, vshift), _mm_cmpgt_epi32(vrem4567, vremainder_threshold));

        const __m128i voutput_zero_point = _mm_load_si128((const __m128i*) params->sse2.output_zero_point);
        __m128i vout01234567 = _mm_adds_epi16(_mm_packs_epi32(vacc0123, vacc4567), voutput_zero_point);

        const __m128i voutput_min = _mm_load_si128((const __m128i*) params->sse2.output_min);
        const __m128i voutput_max = _mm_load_si128((const __m128i*) params->sse2.output_max);
        vout01234567 = _mm_min_epi16(_mm_max_epi16(vout01234567, voutput_min), voutput_max);

        __m128i vout0123456701234567 = _mm_packs_epi16(vout01234567, vout01234567);

        if XNN_LIKELY(c >= 8) {
          _mm_storel_epi64((__m128i*) output, vout0123456701234567);
          output += 8;
          c -= 8;
        } else {
          if (c & 4) {
            *((uint32_t*) output) = (uint32_t) _mm_cvtsi128_si32(vout0123456701234567);
            vout0123456701234567 = _mm_srli_epi64(vout0123456701234567, 32);
            output += 4;
          }
          if (c & 2) {
            *((uint16_t*) output) = (uint16_t) _mm_extract_epi16(vout0123456701234567, 0);
            vout0123456701234567 = _mm_srli_epi32(vout0123456701234567, 16);
            output += 2;
          }
          if (c & 1) {
            *output = (int32_t) _mm_cvtsi128_si32(vout0123456701234567);
            output += 1;
          }
          c = 0;
        }
      } while (c != 0);
    }

    output = (int8_t*) ((uintptr_t) output + output_increment);
  } while (--output_width != 0);
}
