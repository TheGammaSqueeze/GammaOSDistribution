/*
 * Copyright 2021 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <random>
#include <vector>

#include <audio_effects/effect_downmix.h>
#include <audio_utils/channels.h>
#include <audio_utils/primitives.h>
#include <audio_utils/Statistics.h>
#include <benchmark/benchmark.h>
#include <log/log.h>
#include <system/audio.h>

#include "EffectDownmix.h"

extern audio_effect_library_t AUDIO_EFFECT_LIBRARY_INFO_SYM;

static constexpr audio_channel_mask_t kChannelPositionMasks[] = {
    AUDIO_CHANNEL_OUT_FRONT_LEFT,
    AUDIO_CHANNEL_OUT_FRONT_CENTER,
    AUDIO_CHANNEL_OUT_STEREO,
    AUDIO_CHANNEL_OUT_2POINT1,
    AUDIO_CHANNEL_OUT_2POINT0POINT2,
    AUDIO_CHANNEL_OUT_QUAD, // AUDIO_CHANNEL_OUT_QUAD_BACK
    AUDIO_CHANNEL_OUT_QUAD_SIDE,
    AUDIO_CHANNEL_OUT_SURROUND,
    AUDIO_CHANNEL_OUT_2POINT1POINT2,
    AUDIO_CHANNEL_OUT_3POINT0POINT2,
    AUDIO_CHANNEL_OUT_PENTA,
    AUDIO_CHANNEL_OUT_3POINT1POINT2,
    AUDIO_CHANNEL_OUT_5POINT1, // AUDIO_CHANNEL_OUT_5POINT1_BACK
    AUDIO_CHANNEL_OUT_5POINT1_SIDE,
    AUDIO_CHANNEL_OUT_6POINT1,
    AUDIO_CHANNEL_OUT_5POINT1POINT2,
    AUDIO_CHANNEL_OUT_7POINT1,
    AUDIO_CHANNEL_OUT_5POINT1POINT4,
    AUDIO_CHANNEL_OUT_7POINT1POINT2,
    AUDIO_CHANNEL_OUT_7POINT1POINT4,
    AUDIO_CHANNEL_OUT_13POINT_360RA,
    AUDIO_CHANNEL_OUT_22POINT2,
};

static constexpr effect_uuid_t downmix_uuid = {
    0x93f04452, 0xe4fe, 0x41cc, 0x91f9, {0xe4, 0x75, 0xb6, 0xd1, 0xd6, 0x9f}};

static constexpr size_t kFrameCount = 1000;

/*
Pixel 4XL
$ adb shell /data/benchmarktest/downmix_benchmark/vendor/downmix_benchmark

--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_Downmix/0        3638 ns         3624 ns       197517 AUDIO_CHANNEL_OUT_MONO
BM_Downmix/1        4040 ns         4024 ns       178766
BM_Downmix/2        4759 ns         4740 ns       134741 AUDIO_CHANNEL_OUT_STEREO
BM_Downmix/3        6042 ns         6017 ns       129546 AUDIO_CHANNEL_OUT_2POINT1
BM_Downmix/4        6897 ns         6868 ns        96316 AUDIO_CHANNEL_OUT_2POINT0POINT2
BM_Downmix/5        2117 ns         2109 ns       331705 AUDIO_CHANNEL_OUT_QUAD
BM_Downmix/6        2097 ns         2088 ns       335421 AUDIO_CHANNEL_OUT_QUAD_SIDE
BM_Downmix/7        7291 ns         7263 ns        96256 AUDIO_CHANNEL_OUT_SURROUND
BM_Downmix/8        8246 ns         8206 ns        84318 AUDIO_CHANNEL_OUT_2POINT1POINT2
BM_Downmix/9        8341 ns         8303 ns        84298 AUDIO_CHANNEL_OUT_3POINT0POINT2
BM_Downmix/10       7549 ns         7517 ns        84293 AUDIO_CHANNEL_OUT_PENTA
BM_Downmix/11       9395 ns         9354 ns        75209 AUDIO_CHANNEL_OUT_3POINT1POINT2
BM_Downmix/12       3267 ns         3253 ns       215596 AUDIO_CHANNEL_OUT_5POINT1
BM_Downmix/13       3178 ns         3163 ns       220132 AUDIO_CHANNEL_OUT_5POINT1_SIDE
BM_Downmix/14      10245 ns        10199 ns        67486 AUDIO_CHANNEL_OUT_6POINT1
BM_Downmix/15      10975 ns        10929 ns        61359 AUDIO_CHANNEL_OUT_5POINT1POINT2
BM_Downmix/16       3796 ns         3780 ns       184728 AUDIO_CHANNEL_OUT_7POINT1
BM_Downmix/17      13562 ns        13503 ns        51823 AUDIO_CHANNEL_OUT_5POINT1POINT4
BM_Downmix/18      13573 ns        13516 ns        51800 AUDIO_CHANNEL_OUT_7POINT1POINT2
BM_Downmix/19      15502 ns        15435 ns        47147 AUDIO_CHANNEL_OUT_7POINT1POINT4
BM_Downmix/20      16693 ns        16624 ns        42109 AUDIO_CHANNEL_OUT_13POINT_360RA
BM_Downmix/21      28267 ns        28116 ns        24982 AUDIO_CHANNEL_OUT_22POINT2
*/

static void BM_Downmix(benchmark::State& state) {
    const audio_channel_mask_t channelMask = kChannelPositionMasks[state.range(0)];
    const size_t channelCount = audio_channel_count_from_out_mask(channelMask);
    const int sampleRate = 48000;

    // Initialize input buffer with deterministic pseudo-random values
    std::minstd_rand gen(channelMask);
    std::uniform_real_distribution<> dis(-1.0f, 1.0f);
    std::vector<float> input(kFrameCount * channelCount);
    std::vector<float> output(kFrameCount * FCC_2);
    for (auto& in : input) {
        in = dis(gen);
    }
    effect_handle_t effectHandle = nullptr;
    if (int status = AUDIO_EFFECT_LIBRARY_INFO_SYM.create_effect(
            &downmix_uuid, 1, 1, &effectHandle);
        status != 0) {
        ALOGE("create_effect returned an error = %d\n", status);
        return;
    }

    effect_config_t config{};
    config.inputCfg.accessMode = EFFECT_BUFFER_ACCESS_READ;
    config.inputCfg.format = AUDIO_FORMAT_PCM_FLOAT;
    config.inputCfg.bufferProvider.getBuffer = nullptr;
    config.inputCfg.bufferProvider.releaseBuffer = nullptr;
    config.inputCfg.bufferProvider.cookie = nullptr;
    config.inputCfg.mask = EFFECT_CONFIG_ALL;

    config.outputCfg.accessMode = EFFECT_BUFFER_ACCESS_WRITE;
    config.outputCfg.format = AUDIO_FORMAT_PCM_FLOAT;
    config.outputCfg.bufferProvider.getBuffer = nullptr;
    config.outputCfg.bufferProvider.releaseBuffer = nullptr;
    config.outputCfg.bufferProvider.cookie = nullptr;
    config.outputCfg.mask = EFFECT_CONFIG_ALL;

    config.inputCfg.samplingRate = sampleRate;
    config.inputCfg.channels = channelMask;

    config.outputCfg.samplingRate = sampleRate;
    config.outputCfg.channels = AUDIO_CHANNEL_OUT_STEREO; // output always stereo

    int reply = 0;
    uint32_t replySize = sizeof(reply);
    if (int status = (*effectHandle)
            ->command(effectHandle, EFFECT_CMD_SET_CONFIG, sizeof(effect_config_t),
                    &config, &replySize, &reply);
        status != 0) {
        ALOGE("command returned an error = %d\n", status);
        return;
    }

    if (int status = (*effectHandle)
            ->command(effectHandle, EFFECT_CMD_ENABLE, 0, nullptr, &replySize, &reply);
        status != 0) {
        ALOGE("Command enable call returned error %d\n", reply);
        return;
    }

    // Run the test
    for (auto _ : state) {
        benchmark::DoNotOptimize(input.data());
        benchmark::DoNotOptimize(output.data());

        audio_buffer_t inBuffer = {.frameCount = kFrameCount, .f32 = input.data()};
        audio_buffer_t outBuffer = {.frameCount = kFrameCount, .f32 = output.data()};
        (*effectHandle)->process(effectHandle, &inBuffer, &outBuffer);

        benchmark::ClobberMemory();
    }

    state.SetComplexityN(channelCount);
    state.SetLabel(audio_channel_out_mask_to_string(channelMask));

    if (int status = AUDIO_EFFECT_LIBRARY_INFO_SYM.release_effect(effectHandle); status != 0) {
        ALOGE("release_effect returned an error = %d\n", status);
        return;
    }
}

static void DownmixArgs(benchmark::internal::Benchmark* b) {
    for (int i = 0; i < (int)std::size(kChannelPositionMasks); i++) {
        b->Args({i});
    }
}

BENCHMARK(BM_Downmix)->Apply(DownmixArgs);

BENCHMARK_MAIN();
