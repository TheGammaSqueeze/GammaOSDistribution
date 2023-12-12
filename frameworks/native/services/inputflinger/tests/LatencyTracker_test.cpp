/*
 * Copyright (C) 2021 The Android Open Source Project
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

#include "../dispatcher/LatencyTracker.h"

#include <binder/Binder.h>
#include <gtest/gtest.h>
#include <inttypes.h>
#include <log/log.h>

#define TAG "LatencyTracker_test"

using android::inputdispatcher::InputEventTimeline;
using android::inputdispatcher::LatencyTracker;

namespace android::inputdispatcher {

InputEventTimeline getTestTimeline() {
    InputEventTimeline t(
            /*isDown*/ true,
            /*eventTime*/ 2,
            /*readTime*/ 3);
    ConnectionTimeline expectedCT(/*deliveryTime*/ 6, /* consumeTime*/ 7, /*finishTime*/ 8);
    std::array<nsecs_t, GraphicsTimeline::SIZE> graphicsTimeline;
    graphicsTimeline[GraphicsTimeline::GPU_COMPLETED_TIME] = 9;
    graphicsTimeline[GraphicsTimeline::PRESENT_TIME] = 10;
    expectedCT.setGraphicsTimeline(std::move(graphicsTimeline));
    t.connectionTimelines.emplace(new BBinder(), std::move(expectedCT));
    return t;
}

// --- LatencyTrackerTest ---
class LatencyTrackerTest : public testing::Test, public InputEventTimelineProcessor {
protected:
    std::unique_ptr<LatencyTracker> mTracker;
    sp<IBinder> connection1;
    sp<IBinder> connection2;

    void SetUp() override {
        connection1 = new BBinder();
        connection2 = new BBinder();

        mTracker = std::make_unique<LatencyTracker>(this);
    }
    void TearDown() override {}

    void assertReceivedTimeline(const InputEventTimeline& timeline);
    /**
     * Timelines can be received in any order (order is not guaranteed). So if we are expecting more
     * than 1 timeline, use this function to check that the set of received timelines matches
     * what we expected.
     */
    void assertReceivedTimelines(const std::vector<InputEventTimeline>& timelines);

private:
    void processTimeline(const InputEventTimeline& timeline) override {
        mReceivedTimelines.push_back(timeline);
    }
    std::deque<InputEventTimeline> mReceivedTimelines;
};

void LatencyTrackerTest::assertReceivedTimeline(const InputEventTimeline& timeline) {
    mTracker->reportNow();
    ASSERT_FALSE(mReceivedTimelines.empty());
    const InputEventTimeline& t = mReceivedTimelines.front();
    ASSERT_EQ(timeline, t);
    mReceivedTimelines.pop_front();
}

/**
 * We are essentially comparing two multisets, but without constructing them.
 * This comparison is inefficient, but it avoids having to construct a set, and also avoids the
 * declaration of copy constructor for ConnectionTimeline.
 * We ensure that collections A and B have the same size, that for every element in A, there is an
 * equal element in B, and for every element in B there is an equal element in A.
 */
void LatencyTrackerTest::assertReceivedTimelines(const std::vector<InputEventTimeline>& timelines) {
    mTracker->reportNow();
    ASSERT_EQ(timelines.size(), mReceivedTimelines.size());
    for (const InputEventTimeline& expectedTimeline : timelines) {
        bool found = false;
        for (const InputEventTimeline& receivedTimeline : mReceivedTimelines) {
            if (receivedTimeline == expectedTimeline) {
                found = true;
                break;
            }
        }
        ASSERT_TRUE(found) << "Could not find expected timeline with eventTime="
                           << expectedTimeline.eventTime;
    }
    for (const InputEventTimeline& receivedTimeline : mReceivedTimelines) {
        bool found = false;
        for (const InputEventTimeline& expectedTimeline : timelines) {
            if (receivedTimeline == expectedTimeline) {
                found = true;
                break;
            }
        }
        ASSERT_TRUE(found) << "Could not find received timeline with eventTime="
                           << receivedTimeline.eventTime;
    }
    mReceivedTimelines.clear();
}

/**
 * Ensure that calling 'trackListener' in isolation only creates an inputflinger timeline, without
 * any additional ConnectionTimeline's.
 */
TEST_F(LatencyTrackerTest, TrackListener_DoesNotTriggerReporting) {
    mTracker->trackListener(1 /*inputEventId*/, false /*isDown*/, 2 /*eventTime*/, 3 /*readTime*/);
    assertReceivedTimeline(InputEventTimeline{false, 2, 3});
}

/**
 * A single call to trackFinishedEvent should not cause a timeline to be reported.
 */
TEST_F(LatencyTrackerTest, TrackFinishedEvent_DoesNotTriggerReporting) {
    mTracker->trackFinishedEvent(1 /*inputEventId*/, connection1, 2 /*deliveryTime*/,
                                 3 /*consumeTime*/, 4 /*finishTime*/);
    assertReceivedTimelines({});
}

/**
 * A single call to trackGraphicsLatency should not cause a timeline to be reported.
 */
TEST_F(LatencyTrackerTest, TrackGraphicsLatency_DoesNotTriggerReporting) {
    std::array<nsecs_t, GraphicsTimeline::SIZE> graphicsTimeline;
    graphicsTimeline[GraphicsTimeline::GPU_COMPLETED_TIME] = 2;
    graphicsTimeline[GraphicsTimeline::PRESENT_TIME] = 3;
    mTracker->trackGraphicsLatency(1 /*inputEventId*/, connection2, graphicsTimeline);
    assertReceivedTimelines({});
}

TEST_F(LatencyTrackerTest, TrackAllParameters_ReportsFullTimeline) {
    constexpr int32_t inputEventId = 1;
    InputEventTimeline expected = getTestTimeline();

    const auto& [connectionToken, expectedCT] = *expected.connectionTimelines.begin();

    mTracker->trackListener(inputEventId, expected.isDown, expected.eventTime, expected.readTime);
    mTracker->trackFinishedEvent(inputEventId, connectionToken, expectedCT.deliveryTime,
                                 expectedCT.consumeTime, expectedCT.finishTime);
    mTracker->trackGraphicsLatency(inputEventId, connectionToken, expectedCT.graphicsTimeline);

    assertReceivedTimeline(expected);
}

TEST_F(LatencyTrackerTest, MultipleEvents_AreReportedConsistently) {
    constexpr int32_t inputEventId1 = 1;
    InputEventTimeline timeline1(
            /*isDown*/ true,
            /*eventTime*/ 2,
            /*readTime*/ 3);
    timeline1.connectionTimelines.emplace(connection1,
                                          ConnectionTimeline(/*deliveryTime*/ 6, /*consumeTime*/ 7,
                                                             /*finishTime*/ 8));
    ConnectionTimeline& connectionTimeline1 = timeline1.connectionTimelines.begin()->second;
    std::array<nsecs_t, GraphicsTimeline::SIZE> graphicsTimeline1;
    graphicsTimeline1[GraphicsTimeline::GPU_COMPLETED_TIME] = 9;
    graphicsTimeline1[GraphicsTimeline::PRESENT_TIME] = 10;
    connectionTimeline1.setGraphicsTimeline(std::move(graphicsTimeline1));

    constexpr int32_t inputEventId2 = 10;
    InputEventTimeline timeline2(
            /*isDown*/ false,
            /*eventTime*/ 20,
            /*readTime*/ 30);
    timeline2.connectionTimelines.emplace(connection2,
                                          ConnectionTimeline(/*deliveryTime*/ 60,
                                                             /*consumeTime*/ 70,
                                                             /*finishTime*/ 80));
    ConnectionTimeline& connectionTimeline2 = timeline2.connectionTimelines.begin()->second;
    std::array<nsecs_t, GraphicsTimeline::SIZE> graphicsTimeline2;
    graphicsTimeline2[GraphicsTimeline::GPU_COMPLETED_TIME] = 90;
    graphicsTimeline2[GraphicsTimeline::PRESENT_TIME] = 100;
    connectionTimeline2.setGraphicsTimeline(std::move(graphicsTimeline2));

    // Start processing first event
    mTracker->trackListener(inputEventId1, timeline1.isDown, timeline1.eventTime,
                            timeline1.readTime);
    // Start processing second event
    mTracker->trackListener(inputEventId2, timeline2.isDown, timeline2.eventTime,
                            timeline2.readTime);
    mTracker->trackFinishedEvent(inputEventId1, connection1, connectionTimeline1.deliveryTime,
                                 connectionTimeline1.consumeTime, connectionTimeline1.finishTime);

    mTracker->trackFinishedEvent(inputEventId2, connection2, connectionTimeline2.deliveryTime,
                                 connectionTimeline2.consumeTime, connectionTimeline2.finishTime);
    mTracker->trackGraphicsLatency(inputEventId1, connection1,
                                   connectionTimeline1.graphicsTimeline);
    mTracker->trackGraphicsLatency(inputEventId2, connection2,
                                   connectionTimeline2.graphicsTimeline);
    // Now both events should be completed
    assertReceivedTimelines({timeline1, timeline2});
}

/**
 * Check that LatencyTracker consistently tracks events even if there are many incomplete events.
 */
TEST_F(LatencyTrackerTest, IncompleteEvents_AreHandledConsistently) {
    InputEventTimeline timeline = getTestTimeline();
    std::vector<InputEventTimeline> expectedTimelines;
    const ConnectionTimeline& expectedCT = timeline.connectionTimelines.begin()->second;
    const sp<IBinder>& token = timeline.connectionTimelines.begin()->first;

    for (size_t i = 1; i <= 100; i++) {
        mTracker->trackListener(i /*inputEventId*/, timeline.isDown, timeline.eventTime,
                                timeline.readTime);
        expectedTimelines.push_back(
                InputEventTimeline{timeline.isDown, timeline.eventTime, timeline.readTime});
    }
    // Now, complete the first event that was sent.
    mTracker->trackFinishedEvent(1 /*inputEventId*/, token, expectedCT.deliveryTime,
                                 expectedCT.consumeTime, expectedCT.finishTime);
    mTracker->trackGraphicsLatency(1 /*inputEventId*/, token, expectedCT.graphicsTimeline);

    expectedTimelines[0].connectionTimelines.emplace(token, std::move(expectedCT));
    assertReceivedTimelines(expectedTimelines);
}

/**
 * For simplicity of the implementation, LatencyTracker only starts tracking an event when
 * 'trackListener' is invoked.
 * Both 'trackFinishedEvent' and 'trackGraphicsLatency' should not start a new event.
 * If they are received before 'trackListener' (which should not be possible), they are ignored.
 */
TEST_F(LatencyTrackerTest, EventsAreTracked_WhenTrackListenerIsCalledFirst) {
    constexpr int32_t inputEventId = 1;
    InputEventTimeline expected = getTestTimeline();
    const ConnectionTimeline& expectedCT = expected.connectionTimelines.begin()->second;
    mTracker->trackFinishedEvent(inputEventId, connection1, expectedCT.deliveryTime,
                                 expectedCT.consumeTime, expectedCT.finishTime);
    mTracker->trackGraphicsLatency(inputEventId, connection1, expectedCT.graphicsTimeline);

    mTracker->trackListener(inputEventId, expected.isDown, expected.eventTime, expected.readTime);
    assertReceivedTimeline(
            InputEventTimeline{expected.isDown, expected.eventTime, expected.readTime});
}

} // namespace android::inputdispatcher
