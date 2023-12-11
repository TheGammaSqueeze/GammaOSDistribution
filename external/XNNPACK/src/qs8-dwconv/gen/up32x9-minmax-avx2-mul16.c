// Auto-generated file. Do not edit!
//   Template: src/qs8-dwconv/unipass-avx2-mul16.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <immintrin.h>

#include <xnnpack/dwconv.h>


void xnn_qs8_dwconv_minmax_ukernel_up32x9__avx2_mul16(
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
    for (; c >= 32; c -= 32) {
      __m256i vacc01234567 = _mm256_loadu_si256((const __m256i*) w);
      __m256i vacc89ABCDEF = _mm256_loadu_si256((const __m256i*) ((uintptr_t) w + 8 * sizeof(int32_t)));
      __m256i vaccGHIJKLMN = _mm256_loadu_si256((const __m256i*) ((uintptr_t) w + 16 * sizeof(int32_t)));
      __m256i vaccOPQRSTUV = _mm256_loadu_si256((const __m256i*) ((uintptr_t) w + 24 * sizeof(int32_t)));


      const __m256i vi0x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) i0));
      const __m256i vk0x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 32 * sizeof(int32_t) + 0 * sizeof(int8_t))));
      const __m256i vi0xGHIJKLMNOPQRSTUV = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) (i0 + 16)));
      const __m256i vk0xGHIJKLMNOPQRSTUV = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 32 * sizeof(int32_t) + 16 * sizeof(int8_t))));
      i0 += 32;

      const __m256i vprod0x0123456789ABCDEF =  _mm256_mullo_epi16(vi0x0123456789ABCDEF, vk0x0123456789ABCDEF);
      const __m128i vprod0x89ABCDEF = _mm256_extracti128_si256(vprod0x0123456789ABCDEF, 1);
      vacc01234567 = _mm256_add_epi32(vacc01234567, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod0x0123456789ABCDEF)));
      vacc89ABCDEF = _mm256_add_epi32(vacc89ABCDEF, _mm256_cvtepi16_epi32(vprod0x89ABCDEF));
      const __m256i vprod0xGHIJKLMNOPQRSTUV =  _mm256_mullo_epi16(vi0xGHIJKLMNOPQRSTUV, vk0xGHIJKLMNOPQRSTUV);
      const __m128i vprod0xOPQRSTUV = _mm256_extracti128_si256(vprod0xGHIJKLMNOPQRSTUV, 1);
      vaccGHIJKLMN = _mm256_add_epi32(vaccGHIJKLMN, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod0xGHIJKLMNOPQRSTUV)));
      vaccOPQRSTUV = _mm256_add_epi32(vaccOPQRSTUV, _mm256_cvtepi16_epi32(vprod0xOPQRSTUV));

      const __m256i vi1x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) i1));
      const __m256i vk1x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 32 * sizeof(int32_t) + 32 * sizeof(int8_t))));
      const __m256i vi1xGHIJKLMNOPQRSTUV = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) (i1 + 16)));
      const __m256i vk1xGHIJKLMNOPQRSTUV = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 32 * sizeof(int32_t) + 48 * sizeof(int8_t))));
      i1 += 32;

      const __m256i vprod1x0123456789ABCDEF =  _mm256_mullo_epi16(vi1x0123456789ABCDEF, vk1x0123456789ABCDEF);
      const __m128i vprod1x89ABCDEF = _mm256_extracti128_si256(vprod1x0123456789ABCDEF, 1);
      vacc01234567 = _mm256_add_epi32(vacc01234567, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod1x0123456789ABCDEF)));
      vacc89ABCDEF = _mm256_add_epi32(vacc89ABCDEF, _mm256_cvtepi16_epi32(vprod1x89ABCDEF));
      const __m256i vprod1xGHIJKLMNOPQRSTUV =  _mm256_mullo_epi16(vi1xGHIJKLMNOPQRSTUV, vk1xGHIJKLMNOPQRSTUV);
      const __m128i vprod1xOPQRSTUV = _mm256_extracti128_si256(vprod1xGHIJKLMNOPQRSTUV, 1);
      vaccGHIJKLMN = _mm256_add_epi32(vaccGHIJKLMN, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod1xGHIJKLMNOPQRSTUV)));
      vaccOPQRSTUV = _mm256_add_epi32(vaccOPQRSTUV, _mm256_cvtepi16_epi32(vprod1xOPQRSTUV));

      const __m256i vi2x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) i2));
      const __m256i vk2x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 32 * sizeof(int32_t) + 64 * sizeof(int8_t))));
      const __m256i vi2xGHIJKLMNOPQRSTUV = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) (i2 + 16)));
      const __m256i vk2xGHIJKLMNOPQRSTUV = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 32 * sizeof(int32_t) + 80 * sizeof(int8_t))));
      i2 += 32;

      const __m256i vprod2x0123456789ABCDEF =  _mm256_mullo_epi16(vi2x0123456789ABCDEF, vk2x0123456789ABCDEF);
      const __m128i vprod2x89ABCDEF = _mm256_extracti128_si256(vprod2x0123456789ABCDEF, 1);
      vacc01234567 = _mm256_add_epi32(vacc01234567, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod2x0123456789ABCDEF)));
      vacc89ABCDEF = _mm256_add_epi32(vacc89ABCDEF, _mm256_cvtepi16_epi32(vprod2x89ABCDEF));
      const __m256i vprod2xGHIJKLMNOPQRSTUV =  _mm256_mullo_epi16(vi2xGHIJKLMNOPQRSTUV, vk2xGHIJKLMNOPQRSTUV);
      const __m128i vprod2xOPQRSTUV = _mm256_extracti128_si256(vprod2xGHIJKLMNOPQRSTUV, 1);
      vaccGHIJKLMN = _mm256_add_epi32(vaccGHIJKLMN, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod2xGHIJKLMNOPQRSTUV)));
      vaccOPQRSTUV = _mm256_add_epi32(vaccOPQRSTUV, _mm256_cvtepi16_epi32(vprod2xOPQRSTUV));

      const __m256i vi3x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) i3));
      const __m256i vk3x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 32 * sizeof(int32_t) + 96 * sizeof(int8_t))));
      const __m256i vi3xGHIJKLMNOPQRSTUV = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) (i3 + 16)));
      const __m256i vk3xGHIJKLMNOPQRSTUV = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 32 * sizeof(int32_t) + 112 * sizeof(int8_t))));
      i3 += 32;

      const __m256i vprod3x0123456789ABCDEF =  _mm256_mullo_epi16(vi3x0123456789ABCDEF, vk3x0123456789ABCDEF);
      const __m128i vprod3x89ABCDEF = _mm256_extracti128_si256(vprod3x0123456789ABCDEF, 1);
      vacc01234567 = _mm256_add_epi32(vacc01234567, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod3x0123456789ABCDEF)));
      vacc89ABCDEF = _mm256_add_epi32(vacc89ABCDEF, _mm256_cvtepi16_epi32(vprod3x89ABCDEF));
      const __m256i vprod3xGHIJKLMNOPQRSTUV =  _mm256_mullo_epi16(vi3xGHIJKLMNOPQRSTUV, vk3xGHIJKLMNOPQRSTUV);
      const __m128i vprod3xOPQRSTUV = _mm256_extracti128_si256(vprod3xGHIJKLMNOPQRSTUV, 1);
      vaccGHIJKLMN = _mm256_add_epi32(vaccGHIJKLMN, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod3xGHIJKLMNOPQRSTUV)));
      vaccOPQRSTUV = _mm256_add_epi32(vaccOPQRSTUV, _mm256_cvtepi16_epi32(vprod3xOPQRSTUV));

      const __m256i vi4x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) i4));
      const __m256i vk4x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 32 * sizeof(int32_t) + 128 * sizeof(int8_t))));
      const __m256i vi4xGHIJKLMNOPQRSTUV = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) (i4 + 16)));
      const __m256i vk4xGHIJKLMNOPQRSTUV = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 32 * sizeof(int32_t) + 144 * sizeof(int8_t))));
      i4 += 32;

      const __m256i vprod4x0123456789ABCDEF =  _mm256_mullo_epi16(vi4x0123456789ABCDEF, vk4x0123456789ABCDEF);
      const __m128i vprod4x89ABCDEF = _mm256_extracti128_si256(vprod4x0123456789ABCDEF, 1);
      vacc01234567 = _mm256_add_epi32(vacc01234567, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod4x0123456789ABCDEF)));
      vacc89ABCDEF = _mm256_add_epi32(vacc89ABCDEF, _mm256_cvtepi16_epi32(vprod4x89ABCDEF));
      const __m256i vprod4xGHIJKLMNOPQRSTUV =  _mm256_mullo_epi16(vi4xGHIJKLMNOPQRSTUV, vk4xGHIJKLMNOPQRSTUV);
      const __m128i vprod4xOPQRSTUV = _mm256_extracti128_si256(vprod4xGHIJKLMNOPQRSTUV, 1);
      vaccGHIJKLMN = _mm256_add_epi32(vaccGHIJKLMN, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod4xGHIJKLMNOPQRSTUV)));
      vaccOPQRSTUV = _mm256_add_epi32(vaccOPQRSTUV, _mm256_cvtepi16_epi32(vprod4xOPQRSTUV));

      const __m256i vi5x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) i5));
      const __m256i vk5x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 32 * sizeof(int32_t) + 160 * sizeof(int8_t))));
      const __m256i vi5xGHIJKLMNOPQRSTUV = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) (i5 + 16)));
      const __m256i vk5xGHIJKLMNOPQRSTUV = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 32 * sizeof(int32_t) + 176 * sizeof(int8_t))));
      i5 += 32;

      const __m256i vprod5x0123456789ABCDEF =  _mm256_mullo_epi16(vi5x0123456789ABCDEF, vk5x0123456789ABCDEF);
      const __m128i vprod5x89ABCDEF = _mm256_extracti128_si256(vprod5x0123456789ABCDEF, 1);
      vacc01234567 = _mm256_add_epi32(vacc01234567, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod5x0123456789ABCDEF)));
      vacc89ABCDEF = _mm256_add_epi32(vacc89ABCDEF, _mm256_cvtepi16_epi32(vprod5x89ABCDEF));
      const __m256i vprod5xGHIJKLMNOPQRSTUV =  _mm256_mullo_epi16(vi5xGHIJKLMNOPQRSTUV, vk5xGHIJKLMNOPQRSTUV);
      const __m128i vprod5xOPQRSTUV = _mm256_extracti128_si256(vprod5xGHIJKLMNOPQRSTUV, 1);
      vaccGHIJKLMN = _mm256_add_epi32(vaccGHIJKLMN, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod5xGHIJKLMNOPQRSTUV)));
      vaccOPQRSTUV = _mm256_add_epi32(vaccOPQRSTUV, _mm256_cvtepi16_epi32(vprod5xOPQRSTUV));

      const __m256i vi6x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) i6));
      const __m256i vk6x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 32 * sizeof(int32_t) + 192 * sizeof(int8_t))));
      const __m256i vi6xGHIJKLMNOPQRSTUV = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) (i6 + 16)));
      const __m256i vk6xGHIJKLMNOPQRSTUV = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 32 * sizeof(int32_t) + 208 * sizeof(int8_t))));
      i6 += 32;

      const __m256i vprod6x0123456789ABCDEF =  _mm256_mullo_epi16(vi6x0123456789ABCDEF, vk6x0123456789ABCDEF);
      const __m128i vprod6x89ABCDEF = _mm256_extracti128_si256(vprod6x0123456789ABCDEF, 1);
      vacc01234567 = _mm256_add_epi32(vacc01234567, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod6x0123456789ABCDEF)));
      vacc89ABCDEF = _mm256_add_epi32(vacc89ABCDEF, _mm256_cvtepi16_epi32(vprod6x89ABCDEF));
      const __m256i vprod6xGHIJKLMNOPQRSTUV =  _mm256_mullo_epi16(vi6xGHIJKLMNOPQRSTUV, vk6xGHIJKLMNOPQRSTUV);
      const __m128i vprod6xOPQRSTUV = _mm256_extracti128_si256(vprod6xGHIJKLMNOPQRSTUV, 1);
      vaccGHIJKLMN = _mm256_add_epi32(vaccGHIJKLMN, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod6xGHIJKLMNOPQRSTUV)));
      vaccOPQRSTUV = _mm256_add_epi32(vaccOPQRSTUV, _mm256_cvtepi16_epi32(vprod6xOPQRSTUV));

      const __m256i vi7x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) i7));
      const __m256i vk7x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 32 * sizeof(int32_t) + 224 * sizeof(int8_t))));
      const __m256i vi7xGHIJKLMNOPQRSTUV = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) (i7 + 16)));
      const __m256i vk7xGHIJKLMNOPQRSTUV = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 32 * sizeof(int32_t) + 240 * sizeof(int8_t))));
      i7 += 32;

      const __m256i vprod7x0123456789ABCDEF =  _mm256_mullo_epi16(vi7x0123456789ABCDEF, vk7x0123456789ABCDEF);
      const __m128i vprod7x89ABCDEF = _mm256_extracti128_si256(vprod7x0123456789ABCDEF, 1);
      vacc01234567 = _mm256_add_epi32(vacc01234567, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod7x0123456789ABCDEF)));
      vacc89ABCDEF = _mm256_add_epi32(vacc89ABCDEF, _mm256_cvtepi16_epi32(vprod7x89ABCDEF));
      const __m256i vprod7xGHIJKLMNOPQRSTUV =  _mm256_mullo_epi16(vi7xGHIJKLMNOPQRSTUV, vk7xGHIJKLMNOPQRSTUV);
      const __m128i vprod7xOPQRSTUV = _mm256_extracti128_si256(vprod7xGHIJKLMNOPQRSTUV, 1);
      vaccGHIJKLMN = _mm256_add_epi32(vaccGHIJKLMN, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod7xGHIJKLMNOPQRSTUV)));
      vaccOPQRSTUV = _mm256_add_epi32(vaccOPQRSTUV, _mm256_cvtepi16_epi32(vprod7xOPQRSTUV));

      const __m256i vi8x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) i8));
      const __m256i vk8x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 32 * sizeof(int32_t) + 256 * sizeof(int8_t))));
      const __m256i vi8xGHIJKLMNOPQRSTUV = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) (i8 + 16)));
      const __m256i vk8xGHIJKLMNOPQRSTUV = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) ((uintptr_t) w + 32 * sizeof(int32_t) + 272 * sizeof(int8_t))));
      i8 += 32;

      const __m256i vprod8x0123456789ABCDEF =  _mm256_mullo_epi16(vi8x0123456789ABCDEF, vk8x0123456789ABCDEF);
      const __m128i vprod8x89ABCDEF = _mm256_extracti128_si256(vprod8x0123456789ABCDEF, 1);
      vacc01234567 = _mm256_add_epi32(vacc01234567, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod8x0123456789ABCDEF)));
      vacc89ABCDEF = _mm256_add_epi32(vacc89ABCDEF, _mm256_cvtepi16_epi32(vprod8x89ABCDEF));
      const __m256i vprod8xGHIJKLMNOPQRSTUV =  _mm256_mullo_epi16(vi8xGHIJKLMNOPQRSTUV, vk8xGHIJKLMNOPQRSTUV);
      const __m128i vprod8xOPQRSTUV = _mm256_extracti128_si256(vprod8xGHIJKLMNOPQRSTUV, 1);
      vaccGHIJKLMN = _mm256_add_epi32(vaccGHIJKLMN, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod8xGHIJKLMNOPQRSTUV)));
      vaccOPQRSTUV = _mm256_add_epi32(vaccOPQRSTUV, _mm256_cvtepi16_epi32(vprod8xOPQRSTUV));

      w = (const void*) ((uintptr_t) w + 32 * sizeof(int32_t) + 288 * sizeof(int8_t));

      const __m256i vmultiplier = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.multiplier));
      const __m256i vrounding = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.rounding));

      const __m256i vacc1357 = _mm256_shuffle_epi32(vacc01234567, _MM_SHUFFLE(3, 3, 1, 1));
      const __m256i vacc9BDF = _mm256_shuffle_epi32(vacc89ABCDEF, _MM_SHUFFLE(3, 3, 1, 1));
      const __m256i vaccHJLN = _mm256_shuffle_epi32(vaccGHIJKLMN, _MM_SHUFFLE(3, 3, 1, 1));
      const __m256i vaccPRTV = _mm256_shuffle_epi32(vaccOPQRSTUV, _MM_SHUFFLE(3, 3, 1, 1));

      const __m256i vprod0246 = _mm256_add_epi64(_mm256_mul_epi32(vacc01234567, vmultiplier), vrounding);
      const __m256i vprod1357 = _mm256_add_epi64(_mm256_mul_epi32(vacc1357, vmultiplier), vrounding);
      const __m256i vprod8ACE = _mm256_add_epi64(_mm256_mul_epi32(vacc89ABCDEF, vmultiplier), vrounding);
      const __m256i vprod9BDF = _mm256_add_epi64(_mm256_mul_epi32(vacc9BDF, vmultiplier), vrounding);
      const __m256i vprodGIKM = _mm256_add_epi64(_mm256_mul_epi32(vaccGHIJKLMN, vmultiplier), vrounding);
      const __m256i vprodHJLN = _mm256_add_epi64(_mm256_mul_epi32(vaccHJLN, vmultiplier), vrounding);
      const __m256i vprodOQSU = _mm256_add_epi64(_mm256_mul_epi32(vaccOPQRSTUV, vmultiplier), vrounding);
      const __m256i vprodPRTV = _mm256_add_epi64(_mm256_mul_epi32(vaccPRTV, vmultiplier), vrounding);

      const __m256i vq31prod0246 = _mm256_srli_epi64(vprod0246, 31);
      const __m256i vq31prod1357 = _mm256_add_epi64(vprod1357, vprod1357);
      const __m256i vq31prod8ACE = _mm256_srli_epi64(vprod8ACE, 31);
      const __m256i vq31prod9BDF = _mm256_add_epi64(vprod9BDF, vprod9BDF);
      const __m256i vq31prodGIKM = _mm256_srli_epi64(vprodGIKM, 31);
      const __m256i vq31prodHJLN = _mm256_add_epi64(vprodHJLN, vprodHJLN);
      const __m256i vq31prodOQSU = _mm256_srli_epi64(vprodOQSU, 31);
      const __m256i vq31prodPRTV = _mm256_add_epi64(vprodPRTV, vprodPRTV);

      const __m256i vq31prod01234567 = _mm256_blend_epi16(vq31prod0246, vq31prod1357, 0xCC);
      const __m256i vq31prod89ABCDEF = _mm256_blend_epi16(vq31prod8ACE, vq31prod9BDF, 0xCC);
      const __m256i vq31prodGHIJKLMN = _mm256_blend_epi16(vq31prodGIKM, vq31prodHJLN, 0xCC);
      const __m256i vq31prodOPQRSTUV = _mm256_blend_epi16(vq31prodOQSU, vq31prodPRTV, 0xCC);

      const __m256i vremainder_mask = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.remainder_mask));
      const __m256i vrem01234567 =
        _mm256_add_epi32(_mm256_and_si256(vq31prod01234567, vremainder_mask), _mm256_cmpgt_epi32(_mm256_setzero_si256(), vq31prod01234567));
      const __m256i vrem89ABCDEF =
        _mm256_add_epi32(_mm256_and_si256(vq31prod89ABCDEF, vremainder_mask), _mm256_cmpgt_epi32(_mm256_setzero_si256(), vq31prod89ABCDEF));
      const __m256i vremGHIJKLMN =
        _mm256_add_epi32(_mm256_and_si256(vq31prodGHIJKLMN, vremainder_mask), _mm256_cmpgt_epi32(_mm256_setzero_si256(), vq31prodGHIJKLMN));
      const __m256i vremOPQRSTUV =
        _mm256_add_epi32(_mm256_and_si256(vq31prodOPQRSTUV, vremainder_mask), _mm256_cmpgt_epi32(_mm256_setzero_si256(), vq31prodOPQRSTUV));

      const __m256i vremainder_threshold = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.remainder_threshold));
      const __m128i vshift = _mm_load_si128((const __m128i*) params->sse2.shift);
      vacc01234567 =
        _mm256_sub_epi32(_mm256_sra_epi32(vq31prod01234567, vshift), _mm256_cmpgt_epi32(vrem01234567, vremainder_threshold));
      vacc89ABCDEF =
        _mm256_sub_epi32(_mm256_sra_epi32(vq31prod89ABCDEF, vshift), _mm256_cmpgt_epi32(vrem89ABCDEF, vremainder_threshold));
      vaccGHIJKLMN =
        _mm256_sub_epi32(_mm256_sra_epi32(vq31prodGHIJKLMN, vshift), _mm256_cmpgt_epi32(vremGHIJKLMN, vremainder_threshold));
      vaccOPQRSTUV =
        _mm256_sub_epi32(_mm256_sra_epi32(vq31prodOPQRSTUV, vshift), _mm256_cmpgt_epi32(vremOPQRSTUV, vremainder_threshold));

      const __m256i voutput_zero_point = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.output_zero_point));
      __m256i vout012389AB4567CDEF = _mm256_adds_epi16(_mm256_packs_epi32(vacc01234567, vacc89ABCDEF), voutput_zero_point);
      __m256i voutGHIJOPQRKLMNSTUV = _mm256_adds_epi16(_mm256_packs_epi32(vaccGHIJKLMN, vaccOPQRSTUV), voutput_zero_point);

      const __m256i voutput_min = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.output_min));
      const __m256i voutput_max = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.output_max));
      vout012389AB4567CDEF = _mm256_min_epi16(_mm256_max_epi16(vout012389AB4567CDEF, voutput_min), voutput_max);
      voutGHIJOPQRKLMNSTUV = _mm256_min_epi16(_mm256_max_epi16(voutGHIJOPQRKLMNSTUV, voutput_min), voutput_max);

      __m128i vout0123456789ABCDEF = _mm_shuffle_epi32(_mm_packs_epi16(_mm256_castsi256_si128(vout012389AB4567CDEF), _mm256_extracti128_si256(vout012389AB4567CDEF, 1)), _MM_SHUFFLE(3, 1, 2, 0));
      __m128i voutGHIJKLMNOPQRSTUV = _mm_shuffle_epi32(_mm_packs_epi16(_mm256_castsi256_si128(voutGHIJOPQRKLMNSTUV), _mm256_extracti128_si256(voutGHIJOPQRKLMNSTUV, 1)), _MM_SHUFFLE(3, 1, 2, 0));

      _mm_storeu_si128((__m128i*) output, vout0123456789ABCDEF);
      _mm_storeu_si128((__m128i*) (output + 16), voutGHIJKLMNOPQRSTUV);
      output += 32;
    }
    if XNN_UNLIKELY(c != 0) {
      const int8_t* k = (const int8_t*) ((uintptr_t) w + 32 * sizeof(int32_t));
      do {
        __m256i vacc01234567 = _mm256_loadu_si256((const __m256i*) w);
        __m256i vacc89ABCDEF = _mm256_loadu_si256((const __m256i*) ((uintptr_t) w + 8 * sizeof(int32_t)));


        const __m256i vi0x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) i0));
        const __m256i vk0x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) k));
        i0 += 16;

        const __m256i vprod0x0123456789ABCDEF = _mm256_mullo_epi16(vi0x0123456789ABCDEF, vk0x0123456789ABCDEF);
        const __m128i vprod0x89ABCDEF = _mm256_extracti128_si256(vprod0x0123456789ABCDEF, 1);
        vacc01234567 = _mm256_add_epi32(vacc01234567, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod0x0123456789ABCDEF)));
        vacc89ABCDEF = _mm256_add_epi32(vacc89ABCDEF, _mm256_cvtepi16_epi32(vprod0x89ABCDEF));

        const __m256i vi1x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) i1));
        const __m256i vk1x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) (k + 32)));
        i1 += 16;

        const __m256i vprod1x0123456789ABCDEF = _mm256_mullo_epi16(vi1x0123456789ABCDEF, vk1x0123456789ABCDEF);
        const __m128i vprod1x89ABCDEF = _mm256_extracti128_si256(vprod1x0123456789ABCDEF, 1);
        vacc01234567 = _mm256_add_epi32(vacc01234567, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod1x0123456789ABCDEF)));
        vacc89ABCDEF = _mm256_add_epi32(vacc89ABCDEF, _mm256_cvtepi16_epi32(vprod1x89ABCDEF));

        const __m256i vi2x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) i2));
        const __m256i vk2x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) (k + 64)));
        i2 += 16;

        const __m256i vprod2x0123456789ABCDEF = _mm256_mullo_epi16(vi2x0123456789ABCDEF, vk2x0123456789ABCDEF);
        const __m128i vprod2x89ABCDEF = _mm256_extracti128_si256(vprod2x0123456789ABCDEF, 1);
        vacc01234567 = _mm256_add_epi32(vacc01234567, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod2x0123456789ABCDEF)));
        vacc89ABCDEF = _mm256_add_epi32(vacc89ABCDEF, _mm256_cvtepi16_epi32(vprod2x89ABCDEF));

        const __m256i vi3x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) i3));
        const __m256i vk3x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) (k + 96)));
        i3 += 16;

        const __m256i vprod3x0123456789ABCDEF = _mm256_mullo_epi16(vi3x0123456789ABCDEF, vk3x0123456789ABCDEF);
        const __m128i vprod3x89ABCDEF = _mm256_extracti128_si256(vprod3x0123456789ABCDEF, 1);
        vacc01234567 = _mm256_add_epi32(vacc01234567, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod3x0123456789ABCDEF)));
        vacc89ABCDEF = _mm256_add_epi32(vacc89ABCDEF, _mm256_cvtepi16_epi32(vprod3x89ABCDEF));

        const __m256i vi4x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) i4));
        const __m256i vk4x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) (k + 128)));
        i4 += 16;

        const __m256i vprod4x0123456789ABCDEF = _mm256_mullo_epi16(vi4x0123456789ABCDEF, vk4x0123456789ABCDEF);
        const __m128i vprod4x89ABCDEF = _mm256_extracti128_si256(vprod4x0123456789ABCDEF, 1);
        vacc01234567 = _mm256_add_epi32(vacc01234567, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod4x0123456789ABCDEF)));
        vacc89ABCDEF = _mm256_add_epi32(vacc89ABCDEF, _mm256_cvtepi16_epi32(vprod4x89ABCDEF));

        const __m256i vi5x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) i5));
        const __m256i vk5x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) (k + 160)));
        i5 += 16;

        const __m256i vprod5x0123456789ABCDEF = _mm256_mullo_epi16(vi5x0123456789ABCDEF, vk5x0123456789ABCDEF);
        const __m128i vprod5x89ABCDEF = _mm256_extracti128_si256(vprod5x0123456789ABCDEF, 1);
        vacc01234567 = _mm256_add_epi32(vacc01234567, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod5x0123456789ABCDEF)));
        vacc89ABCDEF = _mm256_add_epi32(vacc89ABCDEF, _mm256_cvtepi16_epi32(vprod5x89ABCDEF));

        const __m256i vi6x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) i6));
        const __m256i vk6x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) (k + 192)));
        i6 += 16;

        const __m256i vprod6x0123456789ABCDEF = _mm256_mullo_epi16(vi6x0123456789ABCDEF, vk6x0123456789ABCDEF);
        const __m128i vprod6x89ABCDEF = _mm256_extracti128_si256(vprod6x0123456789ABCDEF, 1);
        vacc01234567 = _mm256_add_epi32(vacc01234567, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod6x0123456789ABCDEF)));
        vacc89ABCDEF = _mm256_add_epi32(vacc89ABCDEF, _mm256_cvtepi16_epi32(vprod6x89ABCDEF));

        const __m256i vi7x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) i7));
        const __m256i vk7x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) (k + 224)));
        i7 += 16;

        const __m256i vprod7x0123456789ABCDEF = _mm256_mullo_epi16(vi7x0123456789ABCDEF, vk7x0123456789ABCDEF);
        const __m128i vprod7x89ABCDEF = _mm256_extracti128_si256(vprod7x0123456789ABCDEF, 1);
        vacc01234567 = _mm256_add_epi32(vacc01234567, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod7x0123456789ABCDEF)));
        vacc89ABCDEF = _mm256_add_epi32(vacc89ABCDEF, _mm256_cvtepi16_epi32(vprod7x89ABCDEF));

        const __m256i vi8x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) i8));
        const __m256i vk8x0123456789ABCDEF = _mm256_cvtepi8_epi16(_mm_loadu_si128((const __m128i*) (k + 256)));
        i8 += 16;

        const __m256i vprod8x0123456789ABCDEF = _mm256_mullo_epi16(vi8x0123456789ABCDEF, vk8x0123456789ABCDEF);
        const __m128i vprod8x89ABCDEF = _mm256_extracti128_si256(vprod8x0123456789ABCDEF, 1);
        vacc01234567 = _mm256_add_epi32(vacc01234567, _mm256_cvtepi16_epi32(_mm256_castsi256_si128(vprod8x0123456789ABCDEF)));
        vacc89ABCDEF = _mm256_add_epi32(vacc89ABCDEF, _mm256_cvtepi16_epi32(vprod8x89ABCDEF));

        w = (const void*) ((uintptr_t) w + 16 * sizeof(int32_t));
        k += 16;

        const __m256i vmultiplier = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.multiplier));
        const __m256i vrounding = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.rounding));

        const __m256i vacc1357 = _mm256_shuffle_epi32(vacc01234567, _MM_SHUFFLE(3, 3, 1, 1));
        const __m256i vacc9BDF = _mm256_shuffle_epi32(vacc89ABCDEF, _MM_SHUFFLE(3, 3, 1, 1));

        const __m256i vprod0246 = _mm256_add_epi64(_mm256_mul_epi32(vacc01234567, vmultiplier), vrounding);
        const __m256i vprod1357 = _mm256_add_epi64(_mm256_mul_epi32(vacc1357, vmultiplier), vrounding);
        const __m256i vprod8ACE = _mm256_add_epi64(_mm256_mul_epi32(vacc89ABCDEF, vmultiplier), vrounding);
        const __m256i vprod9BDF = _mm256_add_epi64(_mm256_mul_epi32(vacc9BDF, vmultiplier), vrounding);

        const __m256i vq31prod0246 = _mm256_srli_epi64(vprod0246, 31);
        const __m256i vq31prod1357 = _mm256_add_epi64(vprod1357, vprod1357);
        const __m256i vq31prod8ACE = _mm256_srli_epi64(vprod8ACE, 31);
        const __m256i vq31prod9BDF = _mm256_add_epi64(vprod9BDF, vprod9BDF);

        const __m256i vq31prod01234567 = _mm256_blend_epi16(vq31prod0246, vq31prod1357, 0xCC);
        const __m256i vq31prod89ABCDEF = _mm256_blend_epi16(vq31prod8ACE, vq31prod9BDF, 0xCC);

        const __m256i vremainder_mask = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.remainder_mask));
        const __m256i vrem01234567 =
          _mm256_add_epi32(_mm256_and_si256(vq31prod01234567, vremainder_mask), _mm256_cmpgt_epi32(_mm256_setzero_si256(), vq31prod01234567));
        const __m256i vrem89ABCDEF =
          _mm256_add_epi32(_mm256_and_si256(vq31prod89ABCDEF, vremainder_mask), _mm256_cmpgt_epi32(_mm256_setzero_si256(), vq31prod89ABCDEF));

        const __m256i vremainder_threshold = _mm256_broadcastsi128_si256(_mm_load_si128((const __m128i*) params->sse2.remainder_threshold));
        const __m128i vshift = _mm_load_si128((const __m128i*) params->sse2.shift);
        vacc01234567 =
          _mm256_sub_epi32(_mm256_sra_epi32(vq31prod01234567, vshift), _mm256_cmpgt_epi32(vrem01234567, vremainder_threshold));
        vacc89ABCDEF =
          _mm256_sub_epi32(_mm256_sra_epi32(vq31prod89ABCDEF, vshift), _mm256_cmpgt_epi32(vrem89ABCDEF, vremainder_threshold));

        const __m128i voutput_zero_point = _mm_load_si128((const __m128i*) params->sse2.output_zero_point);
        __m128i vout01234567 = _mm_adds_epi16(_mm_packs_epi32(_mm256_castsi256_si128(vacc01234567), _mm256_extracti128_si256(vacc01234567, 1)), voutput_zero_point);
        __m128i vout89ABCDEF = _mm_adds_epi16(_mm_packs_epi32(_mm256_castsi256_si128(vacc89ABCDEF), _mm256_extracti128_si256(vacc89ABCDEF, 1)), voutput_zero_point);

        const __m128i voutput_min = _mm_load_si128((const __m128i*) params->sse2.output_min);
        const __m128i voutput_max = _mm_load_si128((const __m128i*) params->sse2.output_max);
        vout01234567 = _mm_min_epi16(_mm_max_epi16(vout01234567, voutput_min), voutput_max);
        vout89ABCDEF = _mm_min_epi16(_mm_max_epi16(vout89ABCDEF, voutput_min), voutput_max);

        __m128i vout0123456789ABCDEF = _mm_packs_epi16(vout01234567, vout89ABCDEF);

        if XNN_LIKELY(c >= 16) {
          _mm_storeu_si128((__m128i*) output, vout0123456789ABCDEF);
          output += 16;
          c -= 16;
        } else {
          if (c & 8) {
            _mm_storel_epi64((__m128i*) output, vout0123456789ABCDEF);
            vout0123456789ABCDEF = _mm_unpackhi_epi64(vout0123456789ABCDEF, vout0123456789ABCDEF);
            output += 8;
          }
          if (c & 4) {
            *((uint32_t*) output) = (uint32_t) _mm_cvtsi128_si32(vout0123456789ABCDEF);
            vout0123456789ABCDEF = _mm_srli_epi64(vout0123456789ABCDEF, 32);
            output += 4;
          }
          if (c & 2) {
            *((uint16_t*) output) = (uint16_t) _mm_extract_epi16(vout0123456789ABCDEF, 0);
            vout0123456789ABCDEF = _mm_srli_epi32(vout0123456789ABCDEF, 16);
            output += 2;
          }
          if (c & 1) {
            *output = (int8_t) _mm_extract_epi8(vout0123456789ABCDEF, 0);
            output += 1;
          }
          c = 0;
        }
      } while (c != 0);
    }

    output = (int8_t*) ((uintptr_t) output + output_increment);
  } while (--output_width != 0);
}
