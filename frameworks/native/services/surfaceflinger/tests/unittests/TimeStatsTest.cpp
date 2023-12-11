/*
 * Copyright 2018 The Android Open Source Project
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

// TODO(b/129481165): remove the #pragma below and fix conversion issues
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconversion"
#pragma clang diagnostic ignored "-Wextra"

#undef LOG_TAG
#define LOG_TAG "LibSurfaceFlingerUnittests"

#include <TimeStats/TimeStats.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <log/log.h>
#include <timestatsatomsproto/TimeStatsAtomsProtoHeader.h>
#include <utils/String16.h>
#include <utils/Vector.h>

#include <chrono>
#include <random>
#include <unordered_set>

#include "libsurfaceflinger_unittest_main.h"

using namespace android::surfaceflinger;
using namespace google::protobuf;
using namespace std::chrono_literals;

namespace android {
namespace {

using testing::_;
using testing::AnyNumber;
using testing::Contains;
using testing::HasSubstr;
using testing::InSequence;
using testing::Not;
using testing::SizeIs;
using testing::StrEq;
using testing::UnorderedElementsAre;

using PowerMode = hardware::graphics::composer::V2_4::IComposerClient::PowerMode;
using SurfaceflingerStatsLayerInfo = android::surfaceflinger::SurfaceflingerStatsLayerInfo;
using SurfaceflingerStatsLayerInfoWrapper =
        android::surfaceflinger::SurfaceflingerStatsLayerInfoWrapper;

// clang-format off
#define FMT_PROTO             true
#define FMT_STRING            false
#define LAYER_ID_0            0
#define LAYER_ID_1            1
#define UID_0                 123
#define REFRESH_RATE_0        61
#define RENDER_RATE_0         31
#define REFRESH_RATE_BUCKET_0 60
#define RENDER_RATE_BUCKET_0  30
#define LAYER_ID_INVALID      -1
#define NUM_LAYERS            1
#define NUM_LAYERS_INVALID    "INVALID"

const constexpr Fps kRefreshRate0 = Fps(static_cast<float>(REFRESH_RATE_0));
const constexpr Fps kRenderRate0 = Fps(static_cast<float>(RENDER_RATE_0));
static constexpr int32_t kGameMode = TimeStatsHelper::GameModeUnsupported;

enum InputCommand : int32_t {
    ENABLE                 = 0,
    DISABLE                = 1,
    CLEAR                  = 2,
    DUMP_ALL               = 3,
    DUMP_MAXLAYERS_1       = 4,
    DUMP_MAXLAYERS_INVALID = 5,
    INPUT_COMMAND_BEGIN    = ENABLE,
    INPUT_COMMAND_END      = DUMP_MAXLAYERS_INVALID,
    INPUT_COMMAND_RANGE    = INPUT_COMMAND_END - INPUT_COMMAND_BEGIN + 1,
};

enum TimeStamp : int32_t {
    POST                   = 0,
    ACQUIRE                = 1,
    ACQUIRE_FENCE          = 2,
    LATCH                  = 3,
    DESIRED                = 4,
    PRESENT                = 5,
    PRESENT_FENCE          = 6,
    TIME_STAMP_BEGIN       = POST,
    TIME_STAMP_END         = PRESENT,
    TIME_STAMP_RANGE       = TIME_STAMP_END - TIME_STAMP_BEGIN + 1,
};

static const TimeStamp NORMAL_SEQUENCE[] = {
        TimeStamp::POST,
        TimeStamp::ACQUIRE,
        TimeStamp::LATCH,
        TimeStamp::DESIRED,
        TimeStamp::PRESENT,
};

static const TimeStamp NORMAL_SEQUENCE_2[] = {
        TimeStamp::POST,
        TimeStamp::ACQUIRE_FENCE,
        TimeStamp::LATCH,
        TimeStamp::DESIRED,
        TimeStamp::PRESENT_FENCE,
};

static const TimeStamp UNORDERED_SEQUENCE[] = {
        TimeStamp::ACQUIRE,
        TimeStamp::LATCH,
        TimeStamp::POST,
        TimeStamp::DESIRED,
        TimeStamp::PRESENT,
};

static const TimeStamp INCOMPLETE_SEQUENCE[] = {
        TimeStamp::POST,
};
// clang-format on

class TimeStatsTest : public testing::Test {
public:
    TimeStatsTest() {
        const ::testing::TestInfo* const test_info =
                ::testing::UnitTest::GetInstance()->current_test_info();
        ALOGD("**** Setting up for %s.%s\n", test_info->test_case_name(), test_info->name());
    }

    ~TimeStatsTest() {
        const ::testing::TestInfo* const test_info =
                ::testing::UnitTest::GetInstance()->current_test_info();
        ALOGD("**** Tearing down after %s.%s\n", test_info->test_case_name(), test_info->name());
    }

    std::string inputCommand(InputCommand cmd, bool useProto);

    void setTimeStamp(TimeStamp type, int32_t id, uint64_t frameNumber, nsecs_t ts,
                      TimeStats::SetFrameRateVote frameRateVote, int32_t gameMode);

    int32_t genRandomInt32(int32_t begin, int32_t end);

    template <size_t N>
    void insertTimeRecord(const TimeStamp (&sequence)[N], int32_t id, uint64_t frameNumber,
                          nsecs_t ts, TimeStats::SetFrameRateVote frameRateVote = {},
                          int32_t gameMode = kGameMode) {
        for (size_t i = 0; i < N; i++, ts += 1000000) {
            setTimeStamp(sequence[i], id, frameNumber, ts, frameRateVote, gameMode);
        }
    }

    std::mt19937 mRandomEngine = std::mt19937(std::random_device()());
    std::unique_ptr<TimeStats> mTimeStats =
            std::make_unique<impl::TimeStats>(std::nullopt, std::nullopt);
};

std::string TimeStatsTest::inputCommand(InputCommand cmd, bool useProto) {
    std::string result;
    Vector<String16> args;

    switch (cmd) {
        case InputCommand::ENABLE:
            args.push_back(String16("-enable"));
            break;
        case InputCommand::DISABLE:
            args.push_back(String16("-disable"));
            break;
        case InputCommand::CLEAR:
            args.push_back(String16("-clear"));
            break;
        case InputCommand::DUMP_ALL:
            args.push_back(String16("-dump"));
            break;
        case InputCommand::DUMP_MAXLAYERS_1:
            args.push_back(String16("-dump"));
            args.push_back(String16("-maxlayers"));
            args.push_back(String16(std::to_string(NUM_LAYERS).c_str()));
            break;
        case InputCommand::DUMP_MAXLAYERS_INVALID:
            args.push_back(String16("-dump"));
            args.push_back(String16("-maxlayers"));
            args.push_back(String16(NUM_LAYERS_INVALID));
            break;
        default:
            ALOGD("Invalid control command");
    }

    EXPECT_NO_FATAL_FAILURE(mTimeStats->parseArgs(useProto, args, result));
    return result;
}

static std::string genLayerName(int32_t layerId) {
    return (layerId < 0 ? "PopupWindow:b54fcd1#0" : "com.example.fake#") + std::to_string(layerId);
}

void TimeStatsTest::setTimeStamp(TimeStamp type, int32_t id, uint64_t frameNumber, nsecs_t ts,
                                 TimeStats::SetFrameRateVote frameRateVote, int32_t gameMode) {
    switch (type) {
        case TimeStamp::POST:
            ASSERT_NO_FATAL_FAILURE(mTimeStats->setPostTime(id, frameNumber, genLayerName(id),
                                                            UID_0, ts, gameMode));
            break;
        case TimeStamp::ACQUIRE:
            ASSERT_NO_FATAL_FAILURE(mTimeStats->setAcquireTime(id, frameNumber, ts));
            break;
        case TimeStamp::ACQUIRE_FENCE:
            ASSERT_NO_FATAL_FAILURE(
                    mTimeStats->setAcquireFence(id, frameNumber, std::make_shared<FenceTime>(ts)));
            break;
        case TimeStamp::LATCH:
            ASSERT_NO_FATAL_FAILURE(mTimeStats->setLatchTime(id, frameNumber, ts));
            break;
        case TimeStamp::DESIRED:
            ASSERT_NO_FATAL_FAILURE(mTimeStats->setDesiredTime(id, frameNumber, ts));
            break;
        case TimeStamp::PRESENT:
            ASSERT_NO_FATAL_FAILURE(mTimeStats->setPresentTime(id, frameNumber, ts, kRefreshRate0,
                                                               kRenderRate0, frameRateVote,
                                                               gameMode));
            break;
        case TimeStamp::PRESENT_FENCE:
            ASSERT_NO_FATAL_FAILURE(mTimeStats->setPresentFence(id, frameNumber,
                                                                std::make_shared<FenceTime>(ts),
                                                                kRefreshRate0, kRenderRate0,
                                                                frameRateVote, gameMode));
            break;
        default:
            ALOGD("Invalid timestamp type");
    }
}

int32_t TimeStatsTest::genRandomInt32(int32_t begin, int32_t end) {
    std::uniform_int_distribution<int32_t> distr(begin, end);
    return distr(mRandomEngine);
}

TEST_F(TimeStatsTest, disabledByDefault) {
    ASSERT_FALSE(mTimeStats->isEnabled());
}

TEST_F(TimeStatsTest, canEnableAndDisableTimeStats) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());
    ASSERT_TRUE(mTimeStats->isEnabled());

    EXPECT_TRUE(inputCommand(InputCommand::DISABLE, FMT_STRING).empty());
    ASSERT_FALSE(mTimeStats->isEnabled());
}

TEST_F(TimeStatsTest, canIncreaseGlobalStats) {
    constexpr size_t TOTAL_FRAMES = 5;
    constexpr size_t MISSED_FRAMES = 4;
    constexpr size_t CLIENT_COMPOSITION_FRAMES = 3;

    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    for (size_t i = 0; i < TOTAL_FRAMES; i++) {
        ASSERT_NO_FATAL_FAILURE(mTimeStats->incrementTotalFrames());
    }
    for (size_t i = 0; i < MISSED_FRAMES; i++) {
        ASSERT_NO_FATAL_FAILURE(mTimeStats->incrementMissedFrames());
    }
    for (size_t i = 0; i < CLIENT_COMPOSITION_FRAMES; i++) {
        ASSERT_NO_FATAL_FAILURE(mTimeStats->incrementClientCompositionFrames());
    }

    SFTimeStatsGlobalProto globalProto;
    ASSERT_TRUE(globalProto.ParseFromString(inputCommand(InputCommand::DUMP_ALL, FMT_PROTO)));

    ASSERT_TRUE(globalProto.has_total_frames());
    EXPECT_EQ(TOTAL_FRAMES, globalProto.total_frames());
    ASSERT_TRUE(globalProto.has_missed_frames());
    EXPECT_EQ(MISSED_FRAMES, globalProto.missed_frames());
    ASSERT_TRUE(globalProto.has_client_composition_frames());
    EXPECT_EQ(CLIENT_COMPOSITION_FRAMES, globalProto.client_composition_frames());
}

TEST_F(TimeStatsTest, canIncreaseLateAcquireFrames) {
    // this stat is not in the proto so verify by checking the string dump
    constexpr size_t LATE_ACQUIRE_FRAMES = 2;

    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);
    for (size_t i = 0; i < LATE_ACQUIRE_FRAMES; i++) {
        mTimeStats->incrementLatchSkipped(LAYER_ID_0, TimeStats::LatchSkipReason::LateAcquire);
    }
    insertTimeRecord(NORMAL_SEQUENCE_2, LAYER_ID_0, 2, 2000000);

    const std::string result(inputCommand(InputCommand::DUMP_ALL, FMT_STRING));
    const std::string expectedResult = "lateAcquireFrames = " + std::to_string(LATE_ACQUIRE_FRAMES);
    EXPECT_THAT(result, HasSubstr(expectedResult));
}

TEST_F(TimeStatsTest, canIncreaseBadDesiredPresent) {
    // this stat is not in the proto so verify by checking the string dump
    constexpr size_t BAD_DESIRED_PRESENT_FRAMES = 2;

    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);
    for (size_t i = 0; i < BAD_DESIRED_PRESENT_FRAMES; i++) {
        mTimeStats->incrementBadDesiredPresent(LAYER_ID_0);
    }
    insertTimeRecord(NORMAL_SEQUENCE_2, LAYER_ID_0, 2, 2000000);

    const std::string result(inputCommand(InputCommand::DUMP_ALL, FMT_STRING));
    const std::string expectedResult =
            "badDesiredPresentFrames = " + std::to_string(BAD_DESIRED_PRESENT_FRAMES);
    EXPECT_THAT(result, HasSubstr(expectedResult));
}

TEST_F(TimeStatsTest, canIncreaseJankyFramesForLayer) {
    // this stat is not in the proto so verify by checking the string dump
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::SurfaceFlingerCpuDeadlineMissed, 1, 2,
                                      3});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::SurfaceFlingerGpuDeadlineMissed, 1, 2,
                                      3});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::DisplayHAL, 1, 2, 3});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::AppDeadlineMissed, 1, 2, 3});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::SurfaceFlingerScheduling, 1, 2, 3});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::PredictionError, 1, 2, 3});
    mTimeStats->incrementJankyFrames(
            {kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0), kGameMode,
             JankType::AppDeadlineMissed | JankType::BufferStuffing, 1, 2, 3});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::None, 1, 2, 3});

    const std::string result(inputCommand(InputCommand::DUMP_ALL, FMT_STRING));
    std::string expectedResult =
            "displayRefreshRate = " + std::to_string(REFRESH_RATE_BUCKET_0) + " fps";
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "renderRate = " + std::to_string(RENDER_RATE_BUCKET_0) + " fps";
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "totalTimelineFrames = " + std::to_string(8);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "jankyFrames = " + std::to_string(7);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfLongCpuJankyFrames = " + std::to_string(1);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfLongGpuJankyFrames = " + std::to_string(1);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfUnattributedJankyFrames = " + std::to_string(1);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "appUnattributedJankyFrames = " + std::to_string(2);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfSchedulingJankyFrames = " + std::to_string(1);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfPredictionErrorJankyFrames = " + std::to_string(1);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "appBufferStuffingJankyFrames = " + std::to_string(1);
    EXPECT_THAT(result, HasSubstr(expectedResult));
}

TEST_F(TimeStatsTest, canCaptureSetFrameRateVote) {
    // this stat is not in the proto so verify by checking the string dump
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);

    const auto frameRate60 = TimeStats::SetFrameRateVote{
            .frameRate = 60.0f,
            .frameRateCompatibility = TimeStats::SetFrameRateVote::FrameRateCompatibility::Default,
            .seamlessness = TimeStats::SetFrameRateVote::Seamlessness::ShouldBeSeamless,
    };
    const auto frameRate90 = TimeStats::SetFrameRateVote{
            .frameRate = 90.0f,
            .frameRateCompatibility =
                    TimeStats::SetFrameRateVote::FrameRateCompatibility::ExactOrMultiple,
            .seamlessness = TimeStats::SetFrameRateVote::Seamlessness::NotRequired,
    };
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 2, 2000000, frameRate60);
    std::string result(inputCommand(InputCommand::DUMP_ALL, FMT_STRING));
    std::string expectedResult = "frameRate = 60.00";
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "frameRateCompatibility = Default";
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "seamlessness = ShouldBeSeamless";
    EXPECT_THAT(result, HasSubstr(expectedResult));

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 3, 3000000, frameRate90);
    result = inputCommand(InputCommand::DUMP_ALL, FMT_STRING);
    expectedResult = "frameRate = 90.00";
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "frameRateCompatibility = ExactOrMultiple";
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "seamlessness = NotRequired";
    EXPECT_THAT(result, HasSubstr(expectedResult));

    insertTimeRecord(NORMAL_SEQUENCE_2, LAYER_ID_0, 4, 4000000, frameRate60);
    result = inputCommand(InputCommand::DUMP_ALL, FMT_STRING);
    expectedResult = "frameRate = 60.00";
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "frameRateCompatibility = Default";
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "seamlessness = ShouldBeSeamless";
    EXPECT_THAT(result, HasSubstr(expectedResult));
}

TEST_F(TimeStatsTest, canCaptureSetFrameRateVoteAfterZeroForLayer) {
    // this stat is not in the proto so verify by checking the string dump
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);

    const auto frameRate90 = TimeStats::SetFrameRateVote{
            .frameRate = 90.0f,
            .frameRateCompatibility =
                    TimeStats::SetFrameRateVote::FrameRateCompatibility::ExactOrMultiple,
            .seamlessness = TimeStats::SetFrameRateVote::Seamlessness::NotRequired,
    };
    const auto frameRateDefault = TimeStats::SetFrameRateVote{
            .frameRate = 0.0f,
            .frameRateCompatibility = TimeStats::SetFrameRateVote::FrameRateCompatibility::Default,
            .seamlessness = TimeStats::SetFrameRateVote::Seamlessness::ShouldBeSeamless,
    };
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 2, 2000000, frameRate90);
    std::string result(inputCommand(InputCommand::DUMP_ALL, FMT_STRING));
    std::string expectedResult = "frameRate = 90.00";
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "frameRateCompatibility = ExactOrMultiple";
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "seamlessness = NotRequired";
    EXPECT_THAT(result, HasSubstr(expectedResult));

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 3, 3000000, frameRateDefault);
    result = inputCommand(InputCommand::DUMP_ALL, FMT_STRING);
    expectedResult = "frameRate = 90.00";
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "frameRateCompatibility = ExactOrMultiple";
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "seamlessness = NotRequired";
    EXPECT_THAT(result, HasSubstr(expectedResult));

    insertTimeRecord(NORMAL_SEQUENCE_2, LAYER_ID_0, 4, 4000000, frameRateDefault);
    result = inputCommand(InputCommand::DUMP_ALL, FMT_STRING);
    expectedResult = "frameRate = 90.00";
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "frameRateCompatibility = ExactOrMultiple";
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "seamlessness = NotRequired";
    EXPECT_THAT(result, HasSubstr(expectedResult));
}

TEST_F(TimeStatsTest, canIncreaseClientCompositionReusedFrames) {
    // this stat is not in the proto so verify by checking the string dump
    constexpr size_t CLIENT_COMPOSITION_REUSED_FRAMES = 2;

    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());
    for (size_t i = 0; i < CLIENT_COMPOSITION_REUSED_FRAMES; i++) {
        ASSERT_NO_FATAL_FAILURE(mTimeStats->incrementClientCompositionReusedFrames());
    }

    const std::string result(inputCommand(InputCommand::DUMP_ALL, FMT_STRING));
    const std::string expectedResult =
            "clientCompositionReusedFrames = " + std::to_string(CLIENT_COMPOSITION_REUSED_FRAMES);
    EXPECT_THAT(result, HasSubstr(expectedResult));
}

TEST_F(TimeStatsTest, canIncreaseRefreshRateSwitches) {
    // this stat is not in the proto so verify by checking the string dump
    constexpr size_t REFRESH_RATE_SWITCHES = 2;

    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());
    for (size_t i = 0; i < REFRESH_RATE_SWITCHES; i++) {
        ASSERT_NO_FATAL_FAILURE(mTimeStats->incrementRefreshRateSwitches());
    }

    const std::string result(inputCommand(InputCommand::DUMP_ALL, FMT_STRING));
    const std::string expectedResult =
            "refreshRateSwitches = " + std::to_string(REFRESH_RATE_SWITCHES);
    EXPECT_THAT(result, HasSubstr(expectedResult));
}

TEST_F(TimeStatsTest, canIncreaseCompositionStrategyChanges) {
    // this stat is not in the proto so verify by checking the string dump
    constexpr size_t COMPOSITION_STRATEGY_CHANGES = 2;

    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());
    for (size_t i = 0; i < COMPOSITION_STRATEGY_CHANGES; i++) {
        ASSERT_NO_FATAL_FAILURE(mTimeStats->incrementCompositionStrategyChanges());
    }

    const std::string result(inputCommand(InputCommand::DUMP_ALL, FMT_STRING));
    const std::string expectedResult =
            "compositionStrategyChanges = " + std::to_string(COMPOSITION_STRATEGY_CHANGES);
    EXPECT_THAT(result, HasSubstr(expectedResult));
}

TEST_F(TimeStatsTest, canAverageFrameDuration) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());
    mTimeStats->setPowerMode(PowerMode::ON);
    mTimeStats->recordFrameDuration(std::chrono::nanoseconds(1ms).count(),
                                    std::chrono::nanoseconds(6ms).count());
    mTimeStats->recordFrameDuration(std::chrono::nanoseconds(1ms).count(),
                                    std::chrono::nanoseconds(16ms).count());

    const std::string result(inputCommand(InputCommand::DUMP_ALL, FMT_STRING));
    EXPECT_THAT(result, HasSubstr("averageFrameDuration = 10.000 ms"));
}

TEST_F(TimeStatsTest, canAverageRenderEngineTimings) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());
    mTimeStats->recordRenderEngineDuration(std::chrono::nanoseconds(1ms).count(),
                                           std::make_shared<FenceTime>(
                                                   std::chrono::duration_cast<
                                                           std::chrono::nanoseconds>(3ms)
                                                           .count()));

    mTimeStats->recordRenderEngineDuration(std::chrono::nanoseconds(4ms).count(),
                                           std::chrono::nanoseconds(8ms).count());

    // Push a fake present fence to trigger flushing the RenderEngine timings.
    mTimeStats->setPowerMode(PowerMode::ON);
    mTimeStats->setPresentFenceGlobal(
            std::make_shared<FenceTime>(std::chrono::nanoseconds(1ms).count()));

    const std::string result(inputCommand(InputCommand::DUMP_ALL, FMT_STRING));
    EXPECT_THAT(result, HasSubstr("averageRenderEngineTiming = 3.000 ms"));
}

TEST_F(TimeStatsTest, canInsertGlobalPresentToPresent) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    ASSERT_NO_FATAL_FAILURE(
            mTimeStats->setPresentFenceGlobal(std::make_shared<FenceTime>(1000000)));
    ASSERT_NO_FATAL_FAILURE(
            mTimeStats->setPresentFenceGlobal(std::make_shared<FenceTime>(2000000)));

    ASSERT_NO_FATAL_FAILURE(mTimeStats->setPowerMode(PowerMode::ON));
    ASSERT_NO_FATAL_FAILURE(
            mTimeStats->setPresentFenceGlobal(std::make_shared<FenceTime>(3000000)));
    ASSERT_NO_FATAL_FAILURE(
            mTimeStats->setPresentFenceGlobal(std::make_shared<FenceTime>(5000000)));

    ASSERT_NO_FATAL_FAILURE(mTimeStats->setPowerMode(PowerMode::OFF));
    ASSERT_NO_FATAL_FAILURE(
            mTimeStats->setPresentFenceGlobal(std::make_shared<FenceTime>(6000000)));
    ASSERT_NO_FATAL_FAILURE(
            mTimeStats->setPresentFenceGlobal(std::make_shared<FenceTime>(8000000)));

    SFTimeStatsGlobalProto globalProto;
    ASSERT_TRUE(globalProto.ParseFromString(inputCommand(InputCommand::DUMP_ALL, FMT_PROTO)));

    ASSERT_EQ(1, globalProto.present_to_present_size());
    const SFTimeStatsHistogramBucketProto& histogramProto = globalProto.present_to_present().Get(0);
    EXPECT_EQ(1, histogramProto.frame_count());
    EXPECT_EQ(2, histogramProto.time_millis());
}

TEST_F(TimeStatsTest, canInsertGlobalFrameDuration) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    mTimeStats->setPowerMode(PowerMode::OFF);
    mTimeStats->recordFrameDuration(std::chrono::nanoseconds(1ms).count(),
                                    std::chrono::nanoseconds(5ms).count());
    mTimeStats->setPowerMode(PowerMode::ON);
    mTimeStats->recordFrameDuration(std::chrono::nanoseconds(3ms).count(),
                                    std::chrono::nanoseconds(6ms).count());

    SFTimeStatsGlobalProto globalProto;
    ASSERT_TRUE(globalProto.ParseFromString(inputCommand(InputCommand::DUMP_ALL, FMT_PROTO)));

    ASSERT_EQ(1, globalProto.frame_duration_size());
    const SFTimeStatsHistogramBucketProto& histogramProto = globalProto.frame_duration().Get(0);
    EXPECT_EQ(1, histogramProto.frame_count());
    EXPECT_EQ(3, histogramProto.time_millis());
}

TEST_F(TimeStatsTest, canInsertGlobalRenderEngineTiming) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    mTimeStats->recordRenderEngineDuration(std::chrono::nanoseconds(1ms).count(),
                                           std::make_shared<FenceTime>(
                                                   std::chrono::duration_cast<
                                                           std::chrono::nanoseconds>(3ms)
                                                           .count()));

    mTimeStats->recordRenderEngineDuration(std::chrono::nanoseconds(4ms).count(),
                                           std::chrono::nanoseconds(6ms).count());

    // First verify that flushing RenderEngine durations did not occur yet.
    SFTimeStatsGlobalProto preFlushProto;
    ASSERT_TRUE(preFlushProto.ParseFromString(inputCommand(InputCommand::DUMP_ALL, FMT_PROTO)));
    ASSERT_EQ(0, preFlushProto.render_engine_timing_size());

    // Push a fake present fence to trigger flushing the RenderEngine timings.
    mTimeStats->setPowerMode(PowerMode::ON);
    mTimeStats->setPresentFenceGlobal(
            std::make_shared<FenceTime>(std::chrono::nanoseconds(1ms).count()));

    // Now we can verify that RenderEngine durations were flushed now.
    SFTimeStatsGlobalProto postFlushProto;
    ASSERT_TRUE(postFlushProto.ParseFromString(inputCommand(InputCommand::DUMP_ALL, FMT_PROTO)));

    ASSERT_EQ(1, postFlushProto.render_engine_timing_size());
    const SFTimeStatsHistogramBucketProto& histogramProto =
            postFlushProto.render_engine_timing().Get(0);
    EXPECT_EQ(2, histogramProto.frame_count());
    EXPECT_EQ(2, histogramProto.time_millis());
}

TEST_F(TimeStatsTest, canInsertOneLayerTimeStats) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);
    insertTimeRecord(NORMAL_SEQUENCE_2, LAYER_ID_0, 2, 2000000);

    SFTimeStatsGlobalProto globalProto;
    ASSERT_TRUE(globalProto.ParseFromString(inputCommand(InputCommand::DUMP_ALL, FMT_PROTO)));

    ASSERT_EQ(1, globalProto.stats_size());
    const SFTimeStatsLayerProto& layerProto = globalProto.stats().Get(0);
    ASSERT_TRUE(layerProto.has_layer_name());
    EXPECT_EQ(genLayerName(LAYER_ID_0), layerProto.layer_name());
    ASSERT_TRUE(layerProto.has_total_frames());
    EXPECT_EQ(1, layerProto.total_frames());
    ASSERT_EQ(6, layerProto.deltas_size());
    for (const SFTimeStatsDeltaProto& deltaProto : layerProto.deltas()) {
        ASSERT_EQ(1, deltaProto.histograms_size());
        const SFTimeStatsHistogramBucketProto& histogramProto = deltaProto.histograms().Get(0);
        EXPECT_EQ(1, histogramProto.frame_count());
        if ("post2acquire" == deltaProto.delta_name()) {
            EXPECT_EQ(1, histogramProto.time_millis());
        } else if ("post2present" == deltaProto.delta_name()) {
            EXPECT_EQ(4, histogramProto.time_millis());
        } else if ("acquire2present" == deltaProto.delta_name()) {
            EXPECT_EQ(3, histogramProto.time_millis());
        } else if ("latch2present" == deltaProto.delta_name()) {
            EXPECT_EQ(2, histogramProto.time_millis());
        } else if ("desired2present" == deltaProto.delta_name()) {
            EXPECT_EQ(1, histogramProto.time_millis());
        } else if ("present2present" == deltaProto.delta_name()) {
            EXPECT_EQ(1, histogramProto.time_millis());
        } else {
            FAIL() << "Unknown delta_name: " << deltaProto.delta_name();
        }
    }
}

TEST_F(TimeStatsTest, canNotInsertInvalidLayerNameTimeStats) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_INVALID, 1, 1000000);
    insertTimeRecord(NORMAL_SEQUENCE_2, LAYER_ID_INVALID, 2, 2000000);

    SFTimeStatsGlobalProto globalProto;
    ASSERT_TRUE(globalProto.ParseFromString(inputCommand(InputCommand::DUMP_ALL, FMT_PROTO)));

    ASSERT_EQ(0, globalProto.stats_size());
}

TEST_F(TimeStatsTest, canInsertMultipleLayersTimeStats) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_1, 1, 1000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 2, 2000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_1, 2, 2000000);

    SFTimeStatsGlobalProto globalProto;
    ASSERT_TRUE(globalProto.ParseFromString(inputCommand(InputCommand::DUMP_ALL, FMT_PROTO)));

    EXPECT_EQ(2, globalProto.stats_size());
}

TEST_F(TimeStatsTest, canInsertUnorderedLayerTimeStats) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);
    insertTimeRecord(UNORDERED_SEQUENCE, LAYER_ID_0, 2, 2000000);

    SFTimeStatsGlobalProto globalProto;
    ASSERT_TRUE(globalProto.ParseFromString(inputCommand(InputCommand::DUMP_ALL, FMT_PROTO)));

    ASSERT_EQ(1, globalProto.stats_size());
    const SFTimeStatsLayerProto& layerProto = globalProto.stats().Get(0);
    ASSERT_TRUE(layerProto.has_layer_name());
    EXPECT_EQ(genLayerName(LAYER_ID_0), layerProto.layer_name());
    ASSERT_TRUE(layerProto.has_total_frames());
    EXPECT_EQ(1, layerProto.total_frames());
    ASSERT_EQ(6, layerProto.deltas_size());
    for (const SFTimeStatsDeltaProto& deltaProto : layerProto.deltas()) {
        ASSERT_EQ(1, deltaProto.histograms_size());
        const SFTimeStatsHistogramBucketProto& histogramProto = deltaProto.histograms().Get(0);
        EXPECT_EQ(1, histogramProto.frame_count());
        if ("post2acquire" == deltaProto.delta_name()) {
            EXPECT_EQ(0, histogramProto.time_millis());
        } else if ("post2present" == deltaProto.delta_name()) {
            EXPECT_EQ(2, histogramProto.time_millis());
        } else if ("acquire2present" == deltaProto.delta_name()) {
            EXPECT_EQ(2, histogramProto.time_millis());
        } else if ("latch2present" == deltaProto.delta_name()) {
            EXPECT_EQ(2, histogramProto.time_millis());
        } else if ("desired2present" == deltaProto.delta_name()) {
            EXPECT_EQ(1, histogramProto.time_millis());
        } else if ("present2present" == deltaProto.delta_name()) {
            EXPECT_EQ(1, histogramProto.time_millis());
        } else {
            FAIL() << "Unknown delta_name: " << deltaProto.delta_name();
        }
    }
}

TEST_F(TimeStatsTest, recordRefreshRateNewConfigs) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    uint32_t fpsOne = 30;
    uint32_t fpsTwo = 90;
    uint64_t millisOne = 5000;
    uint64_t millisTwo = 7000;

    mTimeStats->recordRefreshRate(fpsOne, ms2ns(millisOne));
    mTimeStats->recordRefreshRate(fpsTwo, ms2ns(millisTwo));

    SFTimeStatsGlobalProto globalProto;
    ASSERT_TRUE(globalProto.ParseFromString(inputCommand(InputCommand::DUMP_ALL, FMT_PROTO)));

    SFTimeStatsDisplayConfigBucketProto expectedBucketOne;
    SFTimeStatsDisplayConfigProto* expectedConfigOne = expectedBucketOne.mutable_config();
    expectedConfigOne->set_fps(fpsOne);
    expectedBucketOne.set_duration_millis(millisOne);

    SFTimeStatsDisplayConfigBucketProto expectedBucketTwo;
    SFTimeStatsDisplayConfigProto* expectedConfigTwo = expectedBucketTwo.mutable_config();
    expectedConfigTwo->set_fps(fpsTwo);
    expectedBucketTwo.set_duration_millis(millisTwo);

    EXPECT_THAT(globalProto.display_config_stats(), SizeIs(2));

    std::unordered_set<uint32_t> seen_fps;
    for (const auto& bucket : globalProto.display_config_stats()) {
        seen_fps.emplace(bucket.config().fps());
        if (fpsOne == bucket.config().fps()) {
            EXPECT_EQ(millisOne, bucket.duration_millis());
        } else if (fpsTwo == bucket.config().fps()) {
            EXPECT_EQ(millisTwo, bucket.duration_millis());
        } else {
            FAIL() << "Unknown fps: " << bucket.config().fps();
        }
    }
    EXPECT_THAT(seen_fps, UnorderedElementsAre(fpsOne, fpsTwo));
}

TEST_F(TimeStatsTest, recordRefreshRateUpdatesConfig) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    uint32_t fps = 30;
    uint64_t millisOne = 5000;
    uint64_t millisTwo = 7000;

    mTimeStats->recordRefreshRate(fps, ms2ns(millisOne));
    mTimeStats->recordRefreshRate(fps, ms2ns(millisTwo));

    SFTimeStatsGlobalProto globalProto;
    ASSERT_TRUE(globalProto.ParseFromString(inputCommand(InputCommand::DUMP_ALL, FMT_PROTO)));
    EXPECT_THAT(globalProto.display_config_stats(), SizeIs(1));
    EXPECT_EQ(fps, globalProto.display_config_stats().Get(0).config().fps());
    EXPECT_EQ(millisOne + millisTwo, globalProto.display_config_stats().Get(0).duration_millis());
}

TEST_F(TimeStatsTest, canRemoveTimeRecord) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);
    insertTimeRecord(INCOMPLETE_SEQUENCE, LAYER_ID_0, 2, 2000000);
    ASSERT_NO_FATAL_FAILURE(mTimeStats->removeTimeRecord(0, 2));
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 3, 3000000);

    SFTimeStatsGlobalProto globalProto;
    ASSERT_TRUE(globalProto.ParseFromString(inputCommand(InputCommand::DUMP_ALL, FMT_PROTO)));

    ASSERT_EQ(1, globalProto.stats_size());
    const SFTimeStatsLayerProto& layerProto = globalProto.stats().Get(0);
    ASSERT_TRUE(layerProto.has_total_frames());
    EXPECT_EQ(1, layerProto.total_frames());
}

TEST_F(TimeStatsTest, canRecoverFromIncompleteTimeRecordError) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    uint64_t frameNumber = 1;
    nsecs_t ts = 1000000;
    insertTimeRecord(INCOMPLETE_SEQUENCE, LAYER_ID_0, 1, 1000000);
    for (size_t i = 0; i < impl::TimeStats::MAX_NUM_TIME_RECORDS + 2; i++) {
        frameNumber++;
        ts += 1000000;
        insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, frameNumber, ts);
    }

    SFTimeStatsGlobalProto globalProto;
    ASSERT_TRUE(globalProto.ParseFromString(inputCommand(InputCommand::DUMP_ALL, FMT_PROTO)));

    ASSERT_EQ(1, globalProto.stats_size());
    const SFTimeStatsLayerProto& layerProto = globalProto.stats().Get(0);
    ASSERT_TRUE(layerProto.has_total_frames());
    EXPECT_EQ(1, layerProto.total_frames());
}

TEST_F(TimeStatsTest, layerTimeStatsOnDestroy) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 2, 2000000);
    ASSERT_NO_FATAL_FAILURE(mTimeStats->onDestroy(0));
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 3, 3000000);

    SFTimeStatsGlobalProto globalProto;
    ASSERT_TRUE(globalProto.ParseFromString(inputCommand(InputCommand::DUMP_ALL, FMT_PROTO)));

    ASSERT_EQ(1, globalProto.stats_size());
    const SFTimeStatsLayerProto& layerProto = globalProto.stats().Get(0);
    ASSERT_TRUE(layerProto.has_total_frames());
    EXPECT_EQ(1, layerProto.total_frames());
}

TEST_F(TimeStatsTest, canClearTimeStats) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    ASSERT_NO_FATAL_FAILURE(mTimeStats->incrementTotalFrames());
    ASSERT_NO_FATAL_FAILURE(mTimeStats->incrementMissedFrames());
    ASSERT_NO_FATAL_FAILURE(mTimeStats->incrementClientCompositionFrames());
    ASSERT_NO_FATAL_FAILURE(mTimeStats->setPowerMode(PowerMode::ON));

    mTimeStats->recordFrameDuration(std::chrono::nanoseconds(3ms).count(),
                                    std::chrono::nanoseconds(6ms).count());
    mTimeStats->recordRenderEngineDuration(std::chrono::nanoseconds(4ms).count(),
                                           std::chrono::nanoseconds(6ms).count());
    ASSERT_NO_FATAL_FAILURE(
            mTimeStats->setPresentFenceGlobal(std::make_shared<FenceTime>(1000000)));
    ASSERT_NO_FATAL_FAILURE(
            mTimeStats->setPresentFenceGlobal(std::make_shared<FenceTime>(2000000)));
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 2, 2000000);

    EXPECT_TRUE(inputCommand(InputCommand::CLEAR, FMT_STRING).empty());

    SFTimeStatsGlobalProto globalProto;
    ASSERT_TRUE(globalProto.ParseFromString(inputCommand(InputCommand::DUMP_ALL, FMT_PROTO)));

    EXPECT_EQ(0, globalProto.total_frames());
    EXPECT_EQ(0, globalProto.missed_frames());
    EXPECT_EQ(0, globalProto.client_composition_frames());
    EXPECT_EQ(0, globalProto.present_to_present_size());
    EXPECT_EQ(0, globalProto.frame_duration_size());
    EXPECT_EQ(0, globalProto.render_engine_timing_size());
    EXPECT_EQ(0, globalProto.stats_size());
}

TEST_F(TimeStatsTest, canClearDumpOnlyTimeStats) {
    // These stats are not in the proto so verify by checking the string dump.
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());
    ASSERT_NO_FATAL_FAILURE(mTimeStats->incrementClientCompositionReusedFrames());
    ASSERT_NO_FATAL_FAILURE(mTimeStats->incrementRefreshRateSwitches());
    ASSERT_NO_FATAL_FAILURE(mTimeStats->incrementCompositionStrategyChanges());
    mTimeStats->setPowerMode(PowerMode::ON);
    mTimeStats->recordFrameDuration(std::chrono::nanoseconds(1ms).count(),
                                    std::chrono::nanoseconds(5ms).count());
    mTimeStats->recordRenderEngineDuration(std::chrono::nanoseconds(4ms).count(),
                                           std::chrono::nanoseconds(6ms).count());
    mTimeStats->setPresentFenceGlobal(
            std::make_shared<FenceTime>(std::chrono::nanoseconds(1ms).count()));

    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::SurfaceFlingerCpuDeadlineMissed, 1, 2,
                                      3});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::SurfaceFlingerGpuDeadlineMissed, 1, 2,
                                      3});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::DisplayHAL, 1, 2, 3});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::AppDeadlineMissed, 1, 2, 3});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::SurfaceFlingerScheduling, 1, 2, 3});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::PredictionError, 1, 2, 3});
    mTimeStats->incrementJankyFrames(
            {kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0), kGameMode,
             JankType::AppDeadlineMissed | JankType::BufferStuffing, 1, 2, 3});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::None, 1, 2, 3});

    EXPECT_TRUE(inputCommand(InputCommand::CLEAR, FMT_STRING).empty());

    const std::string result(inputCommand(InputCommand::DUMP_ALL, FMT_STRING));
    EXPECT_THAT(result, HasSubstr("clientCompositionReusedFrames = 0"));
    EXPECT_THAT(result, HasSubstr("refreshRateSwitches = 0"));
    EXPECT_THAT(result, HasSubstr("compositionStrategyChanges = 0"));
    EXPECT_THAT(result, HasSubstr("averageFrameDuration = 0.000 ms"));
    EXPECT_THAT(result, HasSubstr("averageRenderEngineTiming = 0.000 ms"));
    std::string expectedResult = "totalTimelineFrames = ";
    EXPECT_THAT(result, Not(HasSubstr(expectedResult)));
    expectedResult = "jankyFrames = ";
    EXPECT_THAT(result, Not(HasSubstr(expectedResult)));
    expectedResult = "sfLongCpuJankyFrames = ";
    EXPECT_THAT(result, Not(HasSubstr(expectedResult)));
    expectedResult = "sfLongGpuJankyFrames = ";
    EXPECT_THAT(result, Not(HasSubstr(expectedResult)));
    expectedResult = "sfUnattributedJankyFrames = ";
    EXPECT_THAT(result, Not(HasSubstr(expectedResult)));
    expectedResult = "appUnattributedJankyFrames = ";
    EXPECT_THAT(result, Not(HasSubstr(expectedResult)));
    expectedResult = "sfSchedulingJankyFrames = ";
    EXPECT_THAT(result, Not(HasSubstr(expectedResult)));
    expectedResult = "sfPredictionErrorJankyFrames = ";
    EXPECT_THAT(result, Not(HasSubstr(expectedResult)));
    expectedResult = "appBufferStuffingJankyFrames = ";
    EXPECT_THAT(result, Not(HasSubstr(expectedResult)));
}

TEST_F(TimeStatsTest, canDumpWithMaxLayers) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_1, 1, 1000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 2, 2000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_1, 2, 2000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_1, 3, 2000000);

    SFTimeStatsGlobalProto globalProto;
    ASSERT_TRUE(
            globalProto.ParseFromString(inputCommand(InputCommand::DUMP_MAXLAYERS_1, FMT_PROTO)));

    ASSERT_EQ(1, globalProto.stats_size());
    const SFTimeStatsLayerProto& layerProto = globalProto.stats().Get(0);
    ASSERT_TRUE(layerProto.has_layer_name());
    EXPECT_EQ(genLayerName(LAYER_ID_1), layerProto.layer_name());
    ASSERT_TRUE(layerProto.has_total_frames());
    EXPECT_EQ(2, layerProto.total_frames());
}

TEST_F(TimeStatsTest, canDumpWithInvalidMaxLayers) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 2, 2000000);

    SFTimeStatsGlobalProto globalProto;
    ASSERT_TRUE(globalProto.ParseFromString(
            inputCommand(InputCommand::DUMP_MAXLAYERS_INVALID, FMT_PROTO)));

    ASSERT_EQ(0, globalProto.stats_size());
}

TEST_F(TimeStatsTest, noInfInAverageFPS) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 2, 1000000);

    const std::string result(inputCommand(InputCommand::DUMP_ALL, FMT_STRING));
    EXPECT_THAT(result, HasSubstr("averageFPS = 0.000"));
}

namespace {
FrameTimingHistogram buildExpectedHistogram(const std::vector<int32_t>& times,
                                            const std::vector<int32_t>& frameCounts) {
    FrameTimingHistogram histogram;
    for (int i = 0; i < times.size(); i++) {
        ALOGE("Writing time: %d", times[i]);
        histogram.add_time_millis_buckets(times[i]);
        ALOGE("Writing count: %d", frameCounts[i]);
        histogram.add_frame_counts((int64_t)frameCounts[i]);
    }
    return histogram;
}
} // namespace

MATCHER_P(HistogramEq, expected, "") {
    *result_listener << "Histograms are not equal! \n";

    if (arg.time_millis_buckets_size() != expected.time_millis_buckets_size()) {
        *result_listener << "Time millis bucket are different sizes. Expected: "
                         << expected.time_millis_buckets_size() << ". Actual "
                         << arg.time_millis_buckets_size();
        return false;
    }
    if (arg.frame_counts_size() != expected.frame_counts_size()) {
        *result_listener << "Frame counts are different sizes. Expected: "
                         << expected.frame_counts_size() << ". Actual " << arg.frame_counts_size();
        return false;
    }

    for (int i = 0; i < expected.time_millis_buckets_size(); i++) {
        if (arg.time_millis_buckets(i) != expected.time_millis_buckets(i)) {
            *result_listener << "time_millis_bucket[" << i
                             << "] is different. Expected: " << expected.time_millis_buckets(i)
                             << ". Actual: " << arg.time_millis_buckets(i);
            return false;
        }
        if (arg.frame_counts(i) != expected.frame_counts(i)) {
            *result_listener << "frame_counts[" << i
                             << "] is different. Expected: " << expected.frame_counts(i)
                             << ". Actual: " << arg.frame_counts(i);
            return false;
        }
    }
    return true;
}

TEST_F(TimeStatsTest, globalStatsCallback) {
    constexpr size_t TOTAL_FRAMES = 5;
    constexpr size_t MISSED_FRAMES = 4;
    constexpr size_t CLIENT_COMPOSITION_FRAMES = 3;
    constexpr size_t DISPLAY_EVENT_CONNECTIONS = 14;
    constexpr nsecs_t DISPLAY_DEADLINE_DELTA = 1'000'000;
    constexpr nsecs_t DISPLAY_PRESENT_JITTER = 2'000'000;
    constexpr nsecs_t APP_DEADLINE_DELTA = 3'000'000;

    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    for (size_t i = 0; i < TOTAL_FRAMES; i++) {
        mTimeStats->incrementTotalFrames();
    }
    for (size_t i = 0; i < MISSED_FRAMES; i++) {
        mTimeStats->incrementMissedFrames();
    }
    for (size_t i = 0; i < CLIENT_COMPOSITION_FRAMES; i++) {
        mTimeStats->incrementClientCompositionFrames();
    }

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);

    mTimeStats->recordDisplayEventConnectionCount(DISPLAY_EVENT_CONNECTIONS);
    mTimeStats->setPowerMode(PowerMode::ON);
    mTimeStats->recordFrameDuration(1000000, 3000000);
    mTimeStats->recordRenderEngineDuration(2000000, 4000000);
    mTimeStats->recordRenderEngineDuration(2000000, std::make_shared<FenceTime>(3000000));

    mTimeStats->setPresentFenceGlobal(std::make_shared<FenceTime>(3000000));
    mTimeStats->setPresentFenceGlobal(std::make_shared<FenceTime>(5000000));

    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::SurfaceFlingerCpuDeadlineMissed,
                                      DISPLAY_DEADLINE_DELTA, DISPLAY_PRESENT_JITTER,
                                      APP_DEADLINE_DELTA});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::SurfaceFlingerGpuDeadlineMissed,
                                      DISPLAY_DEADLINE_DELTA, DISPLAY_PRESENT_JITTER,
                                      APP_DEADLINE_DELTA});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::DisplayHAL, DISPLAY_DEADLINE_DELTA,
                                      DISPLAY_PRESENT_JITTER, APP_DEADLINE_DELTA});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::AppDeadlineMissed,
                                      DISPLAY_DEADLINE_DELTA, DISPLAY_PRESENT_JITTER,
                                      APP_DEADLINE_DELTA});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::SurfaceFlingerScheduling,
                                      DISPLAY_DEADLINE_DELTA, DISPLAY_PRESENT_JITTER,
                                      APP_DEADLINE_DELTA});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::PredictionError, DISPLAY_DEADLINE_DELTA,
                                      DISPLAY_PRESENT_JITTER, APP_DEADLINE_DELTA});
    mTimeStats->incrementJankyFrames(
            {kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0), kGameMode,
             JankType::AppDeadlineMissed | JankType::BufferStuffing, DISPLAY_DEADLINE_DELTA,
             DISPLAY_PRESENT_JITTER, APP_DEADLINE_DELTA});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::BufferStuffing, DISPLAY_DEADLINE_DELTA,
                                      DISPLAY_PRESENT_JITTER, APP_DEADLINE_DELTA});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      kGameMode, JankType::None, DISPLAY_DEADLINE_DELTA,
                                      DISPLAY_PRESENT_JITTER, APP_DEADLINE_DELTA});

    std::string pulledData;
    EXPECT_TRUE(mTimeStats->onPullAtom(10062 /*SURFACEFLINGER_STATS_GLOBAL_INFO*/, &pulledData));

    android::surfaceflinger::SurfaceflingerStatsGlobalInfoWrapper atomList;
    ASSERT_TRUE(atomList.ParseFromString(pulledData));
    ASSERT_EQ(atomList.atom_size(), 1);
    const android::surfaceflinger::SurfaceflingerStatsGlobalInfo& atom = atomList.atom(0);

    EXPECT_EQ(atom.total_frames(), TOTAL_FRAMES);
    EXPECT_EQ(atom.missed_frames(), MISSED_FRAMES);
    EXPECT_EQ(atom.client_composition_frames(), CLIENT_COMPOSITION_FRAMES);
    // Display on millis is not checked.
    EXPECT_EQ(atom.animation_millis(), 2);
    EXPECT_EQ(atom.event_connection_count(), DISPLAY_EVENT_CONNECTIONS);
    EXPECT_THAT(atom.frame_duration(), HistogramEq(buildExpectedHistogram({2}, {1})));
    EXPECT_THAT(atom.render_engine_timing(), HistogramEq(buildExpectedHistogram({1, 2}, {1, 1})));
    EXPECT_EQ(atom.total_timeline_frames(), 9);
    EXPECT_EQ(atom.total_janky_frames(), 7);
    EXPECT_EQ(atom.total_janky_frames_with_long_cpu(), 1);
    EXPECT_EQ(atom.total_janky_frames_with_long_gpu(), 1);
    EXPECT_EQ(atom.total_janky_frames_sf_unattributed(), 1);
    EXPECT_EQ(atom.total_janky_frames_app_unattributed(), 2);
    EXPECT_EQ(atom.total_janky_frames_sf_scheduling(), 1);
    EXPECT_EQ(atom.total_jank_frames_sf_prediction_error(), 1);
    EXPECT_EQ(atom.total_jank_frames_app_buffer_stuffing(), 2);
    EXPECT_EQ(atom.display_refresh_rate_bucket(), REFRESH_RATE_BUCKET_0);
    EXPECT_THAT(atom.sf_deadline_misses(), HistogramEq(buildExpectedHistogram({1}, {7})));
    EXPECT_THAT(atom.sf_prediction_errors(), HistogramEq(buildExpectedHistogram({2}, {7})));
    EXPECT_EQ(atom.render_rate_bucket(), RENDER_RATE_BUCKET_0);

    SFTimeStatsGlobalProto globalProto;
    ASSERT_TRUE(globalProto.ParseFromString(inputCommand(InputCommand::DUMP_ALL, FMT_PROTO)));

    EXPECT_EQ(0, globalProto.total_frames());
    EXPECT_EQ(0, globalProto.missed_frames());
    EXPECT_EQ(0, globalProto.client_composition_frames());
    EXPECT_EQ(0, globalProto.present_to_present_size());

    // also check dump-only stats: expect that global stats are indeed dropped but there should
    // still be stats for the layer
    const std::string result(inputCommand(InputCommand::DUMP_ALL, FMT_STRING));
    std::string expectedResult = "totalTimelineFrames = " + std::to_string(0);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "totalTimelineFrames = " + std::to_string(9);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "jankyFrames = " + std::to_string(0);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "jankyFrames = " + std::to_string(7);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfLongCpuJankyFrames = " + std::to_string(0);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfLongCpuJankyFrames = " + std::to_string(1);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfLongGpuJankyFrames = " + std::to_string(0);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfLongGpuJankyFrames = " + std::to_string(1);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfUnattributedJankyFrames = " + std::to_string(0);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfUnattributedJankyFrames = " + std::to_string(1);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "appUnattributedJankyFrames = " + std::to_string(0);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "appUnattributedJankyFrames = " + std::to_string(2);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfSchedulingJankyFrames = " + std::to_string(0);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfSchedulingJankyFrames = " + std::to_string(1);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfPredictionErrorJankyFrames = " + std::to_string(0);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfPredictionErrorJankyFrames = " + std::to_string(1);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "appBufferStuffingJankyFrames = " + std::to_string(0);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "appBufferStuffingJankyFrames = " + std::to_string(2);
    EXPECT_THAT(result, HasSubstr(expectedResult));
}

TEST_F(TimeStatsTest, layerStatsCallback_pullsAllAndClears) {
    constexpr size_t LATE_ACQUIRE_FRAMES = 2;
    constexpr size_t BAD_DESIRED_PRESENT_FRAMES = 3;
    constexpr nsecs_t DISPLAY_DEADLINE_DELTA = 1'000'000;
    constexpr nsecs_t DISPLAY_PRESENT_JITTER = 2'000'000;
    constexpr nsecs_t APP_DEADLINE_DELTA_2MS = 2'000'000;
    constexpr nsecs_t APP_DEADLINE_DELTA_3MS = 3'000'000;
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000, {},
                     TimeStatsHelper::GameModeStandard);
    for (size_t i = 0; i < LATE_ACQUIRE_FRAMES; i++) {
        mTimeStats->incrementLatchSkipped(LAYER_ID_0, TimeStats::LatchSkipReason::LateAcquire);
    }
    for (size_t i = 0; i < BAD_DESIRED_PRESENT_FRAMES; i++) {
        mTimeStats->incrementBadDesiredPresent(LAYER_ID_0);
    }
    const auto frameRate60 = TimeStats::SetFrameRateVote{
            .frameRate = 60.0f,
            .frameRateCompatibility =
                    TimeStats::SetFrameRateVote::FrameRateCompatibility::ExactOrMultiple,
            .seamlessness = TimeStats::SetFrameRateVote::Seamlessness::NotRequired,
    };
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 2, 2000000, frameRate60,
                     TimeStatsHelper::GameModeStandard);

    mTimeStats->incrementJankyFrames(
            {kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
             TimeStatsHelper::GameModeStandard, JankType::SurfaceFlingerCpuDeadlineMissed,
             DISPLAY_DEADLINE_DELTA, DISPLAY_PRESENT_JITTER, APP_DEADLINE_DELTA_3MS});
    mTimeStats->incrementJankyFrames(
            {kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
             TimeStatsHelper::GameModeStandard, JankType::SurfaceFlingerGpuDeadlineMissed,
             DISPLAY_DEADLINE_DELTA, DISPLAY_PRESENT_JITTER, APP_DEADLINE_DELTA_3MS});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      TimeStatsHelper::GameModeStandard, JankType::DisplayHAL,
                                      DISPLAY_DEADLINE_DELTA, DISPLAY_PRESENT_JITTER,
                                      APP_DEADLINE_DELTA_3MS});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      TimeStatsHelper::GameModeStandard,
                                      JankType::AppDeadlineMissed, DISPLAY_DEADLINE_DELTA,
                                      DISPLAY_PRESENT_JITTER, APP_DEADLINE_DELTA_3MS});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      TimeStatsHelper::GameModeStandard,
                                      JankType::SurfaceFlingerScheduling, DISPLAY_DEADLINE_DELTA,
                                      DISPLAY_PRESENT_JITTER, APP_DEADLINE_DELTA_2MS});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      TimeStatsHelper::GameModeStandard, JankType::PredictionError,
                                      DISPLAY_DEADLINE_DELTA, DISPLAY_PRESENT_JITTER,
                                      APP_DEADLINE_DELTA_2MS});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      TimeStatsHelper::GameModeStandard,
                                      JankType::AppDeadlineMissed | JankType::BufferStuffing,
                                      DISPLAY_DEADLINE_DELTA, APP_DEADLINE_DELTA_2MS,
                                      APP_DEADLINE_DELTA_2MS});
    mTimeStats->incrementJankyFrames({kRefreshRate0, kRenderRate0, UID_0, genLayerName(LAYER_ID_0),
                                      TimeStatsHelper::GameModeStandard, JankType::None,
                                      DISPLAY_DEADLINE_DELTA, DISPLAY_PRESENT_JITTER,
                                      APP_DEADLINE_DELTA_3MS});

    std::string pulledData;
    EXPECT_TRUE(mTimeStats->onPullAtom(10063 /*SURFACEFLINGER_STATS_LAYER_INFO*/, &pulledData));

    SurfaceflingerStatsLayerInfoWrapper atomList;
    ASSERT_TRUE(atomList.ParseFromString(pulledData));
    ASSERT_EQ(atomList.atom_size(), 1);
    const SurfaceflingerStatsLayerInfo& atom = atomList.atom(0);

    EXPECT_EQ(atom.layer_name(), genLayerName(LAYER_ID_0));
    EXPECT_EQ(atom.total_frames(), 1);
    EXPECT_EQ(atom.dropped_frames(), 0);
    EXPECT_THAT(atom.present_to_present(), HistogramEq(buildExpectedHistogram({1}, {1})));
    EXPECT_THAT(atom.post_to_present(), HistogramEq(buildExpectedHistogram({4}, {1})));
    EXPECT_THAT(atom.acquire_to_present(), HistogramEq(buildExpectedHistogram({3}, {1})));
    EXPECT_THAT(atom.latch_to_present(), HistogramEq(buildExpectedHistogram({2}, {1})));
    EXPECT_THAT(atom.desired_to_present(), HistogramEq(buildExpectedHistogram({1}, {1})));
    EXPECT_THAT(atom.post_to_acquire(), HistogramEq(buildExpectedHistogram({1}, {1})));
    EXPECT_EQ(atom.late_acquire_frames(), LATE_ACQUIRE_FRAMES);
    EXPECT_EQ(atom.bad_desired_present_frames(), BAD_DESIRED_PRESENT_FRAMES);
    EXPECT_EQ(atom.uid(), UID_0);
    EXPECT_EQ(atom.total_timeline_frames(), 8);
    EXPECT_EQ(atom.total_janky_frames(), 7);
    EXPECT_EQ(atom.total_janky_frames_with_long_cpu(), 1);
    EXPECT_EQ(atom.total_janky_frames_with_long_gpu(), 1);
    EXPECT_EQ(atom.total_janky_frames_sf_unattributed(), 1);
    EXPECT_EQ(atom.total_janky_frames_app_unattributed(), 2);
    EXPECT_EQ(atom.total_janky_frames_sf_scheduling(), 1);
    EXPECT_EQ(atom.total_jank_frames_sf_prediction_error(), 1);
    EXPECT_EQ(atom.total_jank_frames_app_buffer_stuffing(), 1);
    EXPECT_EQ(atom.display_refresh_rate_bucket(), REFRESH_RATE_BUCKET_0);
    EXPECT_EQ(atom.render_rate_bucket(), RENDER_RATE_BUCKET_0);
    EXPECT_THAT(atom.set_frame_rate_vote().frame_rate(), testing::FloatEq(frameRate60.frameRate));
    EXPECT_EQ((int)atom.set_frame_rate_vote().frame_rate_compatibility(),
              (int)frameRate60.frameRateCompatibility);
    EXPECT_EQ((int)atom.set_frame_rate_vote().seamlessness(), (int)frameRate60.seamlessness);
    EXPECT_THAT(atom.app_deadline_misses(), HistogramEq(buildExpectedHistogram({3, 2}, {4, 3})));
    EXPECT_EQ(atom.game_mode(), SurfaceflingerStatsLayerInfo::GAME_MODE_STANDARD);

    SFTimeStatsGlobalProto globalProto;
    ASSERT_TRUE(globalProto.ParseFromString(inputCommand(InputCommand::DUMP_ALL, FMT_PROTO)));

    EXPECT_EQ(0, globalProto.stats_size());

    // also check dump-only stats: expect that layer stats are indeed dropped but there should still
    // be global stats
    const std::string result(inputCommand(InputCommand::DUMP_ALL, FMT_STRING));
    std::string expectedResult = "totalTimelineFrames = " + std::to_string(8);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "jankyFrames = " + std::to_string(7);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfLongCpuJankyFrames = " + std::to_string(1);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfLongGpuJankyFrames = " + std::to_string(1);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfUnattributedJankyFrames = " + std::to_string(1);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "appUnattributedJankyFrames = " + std::to_string(2);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfSchedulingJankyFrames = " + std::to_string(1);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "sfPredictionErrorJankyFrames = " + std::to_string(1);
    EXPECT_THAT(result, HasSubstr(expectedResult));
    expectedResult = "appBufferStuffingJankyFrames = " + std::to_string(1);
    EXPECT_THAT(result, HasSubstr(expectedResult));

    std::string expectedMissing = "uid = " + std::to_string(UID_0);
    EXPECT_THAT(result, Not(HasSubstr(expectedMissing)));
}

TEST_F(TimeStatsTest, layerStatsCallback_multipleGameModes) {
    constexpr size_t LATE_ACQUIRE_FRAMES = 2;
    constexpr size_t BAD_DESIRED_PRESENT_FRAMES = 3;
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000, {},
                     TimeStatsHelper::GameModeStandard);
    for (size_t i = 0; i < LATE_ACQUIRE_FRAMES; i++) {
        mTimeStats->incrementLatchSkipped(LAYER_ID_0, TimeStats::LatchSkipReason::LateAcquire);
    }
    for (size_t i = 0; i < BAD_DESIRED_PRESENT_FRAMES; i++) {
        mTimeStats->incrementBadDesiredPresent(LAYER_ID_0);
    }
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 2, 2000000, {},
                     TimeStatsHelper::GameModeStandard);

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 3, 3000000, {},
                     TimeStatsHelper::GameModePerformance);

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 4, 4000000, {}, TimeStatsHelper::GameModeBattery);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 5, 4000000, {}, TimeStatsHelper::GameModeBattery);

    std::string pulledData;
    EXPECT_TRUE(mTimeStats->onPullAtom(10063 /*SURFACEFLINGER_STATS_LAYER_INFO*/, &pulledData));

    SurfaceflingerStatsLayerInfoWrapper atomList;
    ASSERT_TRUE(atomList.ParseFromString(pulledData));
    // The first time record is never uploaded to stats.
    ASSERT_EQ(atomList.atom_size(), 3);
    // Layers are ordered based on the hash in LayerStatsKey. For this test, the order happens to
    // be: 0 - Battery 1 - Performance 2 - Standard
    const SurfaceflingerStatsLayerInfo& atom0 = atomList.atom(0);

    EXPECT_EQ(atom0.layer_name(), genLayerName(LAYER_ID_0));
    EXPECT_EQ(atom0.total_frames(), 2);
    EXPECT_EQ(atom0.dropped_frames(), 0);
    EXPECT_THAT(atom0.present_to_present(), HistogramEq(buildExpectedHistogram({0, 1}, {1, 1})));
    EXPECT_THAT(atom0.post_to_present(), HistogramEq(buildExpectedHistogram({4}, {2})));
    EXPECT_THAT(atom0.acquire_to_present(), HistogramEq(buildExpectedHistogram({3}, {2})));
    EXPECT_THAT(atom0.latch_to_present(), HistogramEq(buildExpectedHistogram({2}, {2})));
    EXPECT_THAT(atom0.desired_to_present(), HistogramEq(buildExpectedHistogram({1}, {2})));
    EXPECT_THAT(atom0.post_to_acquire(), HistogramEq(buildExpectedHistogram({1}, {2})));
    EXPECT_EQ(atom0.late_acquire_frames(), 0);
    EXPECT_EQ(atom0.bad_desired_present_frames(), 0);
    EXPECT_EQ(atom0.uid(), UID_0);
    EXPECT_EQ(atom0.display_refresh_rate_bucket(), REFRESH_RATE_BUCKET_0);
    EXPECT_EQ(atom0.render_rate_bucket(), RENDER_RATE_BUCKET_0);
    EXPECT_EQ(atom0.game_mode(), SurfaceflingerStatsLayerInfo::GAME_MODE_BATTERY);

    const SurfaceflingerStatsLayerInfo& atom1 = atomList.atom(1);

    EXPECT_EQ(atom1.layer_name(), genLayerName(LAYER_ID_0));
    EXPECT_EQ(atom1.total_frames(), 1);
    EXPECT_EQ(atom1.dropped_frames(), 0);
    EXPECT_THAT(atom1.present_to_present(), HistogramEq(buildExpectedHistogram({1}, {1})));
    EXPECT_THAT(atom1.post_to_present(), HistogramEq(buildExpectedHistogram({4}, {1})));
    EXPECT_THAT(atom1.acquire_to_present(), HistogramEq(buildExpectedHistogram({3}, {1})));
    EXPECT_THAT(atom1.latch_to_present(), HistogramEq(buildExpectedHistogram({2}, {1})));
    EXPECT_THAT(atom1.desired_to_present(), HistogramEq(buildExpectedHistogram({1}, {1})));
    EXPECT_THAT(atom1.post_to_acquire(), HistogramEq(buildExpectedHistogram({1}, {1})));
    EXPECT_EQ(atom1.late_acquire_frames(), 0);
    EXPECT_EQ(atom1.bad_desired_present_frames(), 0);
    EXPECT_EQ(atom1.uid(), UID_0);
    EXPECT_EQ(atom1.display_refresh_rate_bucket(), REFRESH_RATE_BUCKET_0);
    EXPECT_EQ(atom1.render_rate_bucket(), RENDER_RATE_BUCKET_0);
    EXPECT_EQ(atom1.game_mode(), SurfaceflingerStatsLayerInfo::GAME_MODE_PERFORMANCE);

    const SurfaceflingerStatsLayerInfo& atom2 = atomList.atom(2);

    EXPECT_EQ(atom2.layer_name(), genLayerName(LAYER_ID_0));
    EXPECT_EQ(atom2.total_frames(), 1);
    EXPECT_EQ(atom2.dropped_frames(), 0);
    EXPECT_THAT(atom2.present_to_present(), HistogramEq(buildExpectedHistogram({1}, {1})));
    EXPECT_THAT(atom2.post_to_present(), HistogramEq(buildExpectedHistogram({4}, {1})));
    EXPECT_THAT(atom2.acquire_to_present(), HistogramEq(buildExpectedHistogram({3}, {1})));
    EXPECT_THAT(atom2.latch_to_present(), HistogramEq(buildExpectedHistogram({2}, {1})));
    EXPECT_THAT(atom2.desired_to_present(), HistogramEq(buildExpectedHistogram({1}, {1})));
    EXPECT_THAT(atom2.post_to_acquire(), HistogramEq(buildExpectedHistogram({1}, {1})));
    EXPECT_EQ(atom2.late_acquire_frames(), LATE_ACQUIRE_FRAMES);
    EXPECT_EQ(atom2.bad_desired_present_frames(), BAD_DESIRED_PRESENT_FRAMES);
    EXPECT_EQ(atom2.uid(), UID_0);
    EXPECT_EQ(atom2.display_refresh_rate_bucket(), REFRESH_RATE_BUCKET_0);
    EXPECT_EQ(atom2.render_rate_bucket(), RENDER_RATE_BUCKET_0);
    EXPECT_EQ(atom2.game_mode(), SurfaceflingerStatsLayerInfo::GAME_MODE_STANDARD);
}

TEST_F(TimeStatsTest, layerStatsCallback_pullsMultipleLayers) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 2, 2000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_1, 1, 2000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_1, 2, 3000000);

    std::string pulledData;
    EXPECT_TRUE(mTimeStats->onPullAtom(10063 /*SURFACEFLINGER_STATS_LAYER_INFO*/, &pulledData));

    SurfaceflingerStatsLayerInfoWrapper atomList;
    ASSERT_TRUE(atomList.ParseFromString(pulledData));
    ASSERT_EQ(atomList.atom_size(), 2);
    std::vector<std::string> actualLayerNames = {atomList.atom(0).layer_name(),
                                                 atomList.atom(1).layer_name()};
    EXPECT_THAT(actualLayerNames,
                UnorderedElementsAre(genLayerName(LAYER_ID_0), genLayerName(LAYER_ID_1)));
}

TEST_F(TimeStatsTest, layerStatsCallback_pullsMultipleBuckets) {
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 2, 2000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 3, 4000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 4, 5000000);

    // Now make sure that TimeStats flushes global stats to set the callback.
    mTimeStats->setPowerMode(PowerMode::ON);
    mTimeStats->setPresentFenceGlobal(std::make_shared<FenceTime>(3000000));
    mTimeStats->setPresentFenceGlobal(std::make_shared<FenceTime>(5000000));

    std::string pulledData;
    EXPECT_TRUE(mTimeStats->onPullAtom(10063 /*SURFACEFLINGER_STATS_LAYER_INFO*/, &pulledData));

    SurfaceflingerStatsLayerInfoWrapper atomList;
    ASSERT_TRUE(atomList.ParseFromString(pulledData));
    ASSERT_EQ(atomList.atom_size(), 1);
    const SurfaceflingerStatsLayerInfo& atom = atomList.atom(0);
    EXPECT_THAT(atom.present_to_present(), HistogramEq(buildExpectedHistogram({1, 2}, {2, 1})));
}

TEST_F(TimeStatsTest, layerStatsCallback_limitsHistogramBuckets) {
    mTimeStats = std::make_unique<impl::TimeStats>(std::nullopt, 1);
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 2, 2000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 3, 4000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 4, 5000000);

    std::string pulledData;
    EXPECT_TRUE(mTimeStats->onPullAtom(10063 /*SURFACEFLINGER_STATS_LAYER_INFO*/, &pulledData));

    SurfaceflingerStatsLayerInfoWrapper atomList;
    ASSERT_TRUE(atomList.ParseFromString(pulledData));
    ASSERT_EQ(atomList.atom_size(), 1);
    const SurfaceflingerStatsLayerInfo& atom = atomList.atom(0);
    EXPECT_THAT(atom.present_to_present(), HistogramEq(buildExpectedHistogram({1}, {2})));
}

TEST_F(TimeStatsTest, layerStatsCallback_limitsLayers) {
    mTimeStats = std::make_unique<impl::TimeStats>(1, std::nullopt);
    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 2, 2000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_1, 1, 2000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_1, 2, 3000000);
    insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_1, 4, 5000000);

    std::string pulledData;
    EXPECT_TRUE(mTimeStats->onPullAtom(10063 /*SURFACEFLINGER_STATS_LAYER_INFO*/, &pulledData));

    SurfaceflingerStatsLayerInfoWrapper atomList;
    ASSERT_TRUE(atomList.ParseFromString(pulledData));
    ASSERT_EQ(atomList.atom_size(), 1);
    EXPECT_EQ(atomList.atom(0).layer_name(), genLayerName(LAYER_ID_1));
}

TEST_F(TimeStatsTest, canSurviveMonkey) {
    if (g_noSlowTests) {
        GTEST_SKIP();
    }

    EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

    for (size_t i = 0; i < 10000000; ++i) {
        const int32_t layerId = genRandomInt32(-1, 10);
        const int32_t frameNumber = genRandomInt32(1, 10);
        switch (genRandomInt32(0, 100)) {
            case 0:
                ALOGV("removeTimeRecord");
                ASSERT_NO_FATAL_FAILURE(mTimeStats->removeTimeRecord(layerId, frameNumber));
                continue;
            case 1:
                ALOGV("onDestroy");
                ASSERT_NO_FATAL_FAILURE(mTimeStats->onDestroy(layerId));
                continue;
        }
        TimeStamp type = static_cast<TimeStamp>(genRandomInt32(TIME_STAMP_BEGIN, TIME_STAMP_END));
        const int32_t ts = genRandomInt32(1, 1000000000);
        ALOGV("type[%d], layerId[%d], frameNumber[%d], ts[%d]", type, layerId, frameNumber, ts);
        setTimeStamp(type, layerId, frameNumber, ts, {}, kGameMode);
    }
}

TEST_F(TimeStatsTest, refreshRateIsClampedToNearestBucket) {
    // this stat is not in the proto so verify by checking the string dump
    const auto verifyRefreshRateBucket = [&](Fps fps, int32_t bucket) {
        EXPECT_TRUE(inputCommand(InputCommand::CLEAR, FMT_STRING).empty());
        EXPECT_TRUE(inputCommand(InputCommand::ENABLE, FMT_STRING).empty());

        insertTimeRecord(NORMAL_SEQUENCE, LAYER_ID_0, 1, 1000000);
        mTimeStats->incrementJankyFrames({fps, std::nullopt, UID_0, genLayerName(LAYER_ID_0),
                                          kGameMode, JankType::None, 0, 0, 0});
        const std::string result(inputCommand(InputCommand::DUMP_ALL, FMT_STRING));
        std::string expectedResult = "displayRefreshRate = " + std::to_string(bucket) + " fps";
        EXPECT_THAT(result, HasSubstr(expectedResult)) << "failed for " << fps;
    };

    verifyRefreshRateBucket(Fps(91.f), 90);
    verifyRefreshRateBucket(Fps(89.f), 90);

    verifyRefreshRateBucket(Fps(61.f), 60);
    verifyRefreshRateBucket(Fps(59.f), 60);

    verifyRefreshRateBucket(Fps(31.f), 30);
    verifyRefreshRateBucket(Fps(29.f), 30);
}

} // namespace
} // namespace android

// TODO(b/129481165): remove the #pragma below and fix conversion issues
#pragma clang diagnostic pop // ignored "-Wconversion -Wextra"
