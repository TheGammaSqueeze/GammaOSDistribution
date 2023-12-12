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

#include "CarTelemetryImpl.h"
#include "CarTelemetryInternalImpl.h"
#include "FakeLooperWrapper.h"
#include "LooperWrapper.h"
#include "RingBuffer.h"
#include "TelemetryServer.h"

#include <aidl/android/automotive/telemetry/internal/BnCarDataListener.h>
#include <aidl/android/automotive/telemetry/internal/CarDataInternal.h>
#include <aidl/android/automotive/telemetry/internal/ICarTelemetryInternal.h>
#include <aidl/android/frameworks/automotive/telemetry/CarData.h>
#include <aidl/android/frameworks/automotive/telemetry/ICarTelemetry.h>
#include <android-base/chrono_utils.h>
#include <android-base/logging.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <utils/Timers.h>  // for ::systemTime()

#include <unistd.h>

#include <memory>

namespace android {
namespace automotive {
namespace telemetry {

using ::aidl::android::automotive::telemetry::internal::BnCarDataListener;
using ::aidl::android::automotive::telemetry::internal::CarDataInternal;
using ::aidl::android::automotive::telemetry::internal::ICarTelemetryInternal;
using ::aidl::android::frameworks::automotive::telemetry::CarData;
using ::aidl::android::frameworks::automotive::telemetry::ICarTelemetry;
using ::ndk::ScopedAStatus;
using ::testing::_;
using ::testing::ByMove;
using ::testing::Return;

constexpr const std::chrono::nanoseconds kPushCarDataDelayNs = 1000ms;
constexpr const std::chrono::nanoseconds kAllowedErrorNs = 100ms;
const int kMaxBufferSize = 3;

// Because `ScopedAStatus` is move-only, `EXPECT_CALL().WillRepeatedly()` will not work.
inline testing::internal::ReturnAction<testing::internal::ByMoveWrapper<ScopedAStatus>> ReturnOk() {
    return testing::Return(ByMove(ScopedAStatus::ok()));
}

// Builds incoming CarData from writer clients.
CarData buildCarData(int id, const std::vector<uint8_t>& content) {
    CarData msg;
    msg.id = id;
    msg.content = content;
    return msg;
}

// Builds outgoing CarDataInternal to the CarTelemetryService.
CarDataInternal buildCarDataInternal(int id, const std::vector<uint8_t>& content) {
    CarDataInternal msg;
    msg.id = id;
    msg.content = content;
    return msg;
}

// Mock listener, behaves as CarTelemetryService.
class MockCarDataListener : public BnCarDataListener {
public:
    MOCK_METHOD(ScopedAStatus, onCarDataReceived, (const std::vector<CarDataInternal>& dataList),
                (override));
};

// The main test class. Tests using `ICarTelemetry` and `ICarTelemetryInternal` interfaces.
// Pushing data to the listener is done in the looper - always call `mFakeLooper.poll()`.
class TelemetryServerTest : public ::testing::Test {
protected:
    TelemetryServerTest() :
          mTelemetryServer(&mFakeLooper, kPushCarDataDelayNs, kMaxBufferSize),
          mMockCarDataListener(ndk::SharedRefBase::make<MockCarDataListener>()),
          mTelemetry(ndk::SharedRefBase::make<CarTelemetryImpl>(&mTelemetryServer)),
          mTelemetryInternal(
                  ndk::SharedRefBase::make<CarTelemetryInternalImpl>(&mTelemetryServer)) {}

    // Creates an expectation. This is a nice helper that accepts a std::vector, original
    // EXPECT_CALL() requires creating std::vector variable.
    testing::internal::TypedExpectation<ScopedAStatus(const std::vector<CarDataInternal>&)>&
    expectMockListenerToReceive(const std::vector<CarDataInternal>& expected) {
        return EXPECT_CALL(*mMockCarDataListener, onCarDataReceived(expected));
    }

    FakeLooperWrapper mFakeLooper;
    TelemetryServer mTelemetryServer;
    std::shared_ptr<MockCarDataListener> mMockCarDataListener;
    std::shared_ptr<ICarTelemetry> mTelemetry;
    std::shared_ptr<ICarTelemetryInternal> mTelemetryInternal;
};

TEST_F(TelemetryServerTest, WriteReturnsOk) {
    std::vector<CarData> dataList = {buildCarData(101, {1})};

    auto status = mTelemetry->write(dataList);

    EXPECT_TRUE(status.isOk()) << status.getMessage();
}

TEST_F(TelemetryServerTest, SetListenerReturnsOk) {
    auto status = mTelemetryInternal->setListener(mMockCarDataListener);

    EXPECT_TRUE(status.isOk()) << status.getMessage();
}

TEST_F(TelemetryServerTest, SetListenerFailsWhenAlreadySubscribed) {
    mTelemetryInternal->setListener(mMockCarDataListener);

    auto status = mTelemetryInternal->setListener(ndk::SharedRefBase::make<MockCarDataListener>());

    EXPECT_EQ(status.getExceptionCode(), ::EX_ILLEGAL_STATE) << status.getMessage();
}

TEST_F(TelemetryServerTest, ClearListenerWorks) {
    mTelemetryInternal->setListener(mMockCarDataListener);

    mTelemetryInternal->clearListener();

    auto status = mTelemetryInternal->setListener(mMockCarDataListener);
    EXPECT_TRUE(status.isOk()) << status.getMessage();
}

TEST_F(TelemetryServerTest, ClearListenerRemovesPushMessagesFromLooper) {
    std::vector<CarData> dataList = {buildCarData(101, {1})};
    mTelemetry->write(dataList);
    mTelemetryInternal->setListener(mMockCarDataListener);
    EXPECT_NE(mFakeLooper.getNextMessageUptime(), FakeLooperWrapper::kNoScheduledMessage);

    mTelemetryInternal->clearListener();

    EXPECT_EQ(mFakeLooper.getNextMessageUptime(), FakeLooperWrapper::kNoScheduledMessage);
}

TEST_F(TelemetryServerTest, WriteSchedulesNextMessageAfterRightDelay) {
    std::vector<CarData> dataList = {buildCarData(101, {1})};
    mTelemetryInternal->setListener(mMockCarDataListener);

    mTelemetry->write(dataList);

    EXPECT_NEAR(mFakeLooper.getNextMessageUptime(), ::systemTime() + kPushCarDataDelayNs.count(),
                kAllowedErrorNs.count());
}

TEST_F(TelemetryServerTest, SetListenerSchedulesNextMessageAfterRightDelay) {
    std::vector<CarData> dataList = {buildCarData(101, {1})};
    mTelemetry->write(dataList);

    mTelemetryInternal->setListener(mMockCarDataListener);

    EXPECT_NEAR(mFakeLooper.getNextMessageUptime(), ::systemTime() + kPushCarDataDelayNs.count(),
                kAllowedErrorNs.count());
}

TEST_F(TelemetryServerTest, BuffersOnlyLimitedData) {
    mTelemetryInternal->setListener(mMockCarDataListener);
    std::vector<CarData> dataList1 = {buildCarData(10, {1, 2}), buildCarData(11, {2, 3})};
    std::vector<CarData> dataList2 = {buildCarData(101, {1, 2}), buildCarData(102, {2, 3}),
                                      buildCarData(103, {3, 4}), buildCarData(104, {4, 5})};

    mTelemetry->write(dataList1);
    mTelemetry->write(dataList2);

    // Only the last 3 CarData should be received, because kMaxBufferSize = 3.
    expectMockListenerToReceive({buildCarDataInternal(102, {2, 3})}).WillOnce(ReturnOk());
    expectMockListenerToReceive({buildCarDataInternal(103, {3, 4})}).WillOnce(ReturnOk());
    expectMockListenerToReceive({buildCarDataInternal(104, {4, 5})}).WillOnce(ReturnOk());

    mFakeLooper.poll();
    mFakeLooper.poll();
    mFakeLooper.poll();
    mFakeLooper.poll();
}

// First sets the listener, then writes CarData.
TEST_F(TelemetryServerTest, WhenListenerIsAlreadyItPushesData) {
    std::vector<CarData> dataList = {buildCarData(101, {1})};

    mTelemetryInternal->setListener(mMockCarDataListener);
    mTelemetry->write(dataList);

    expectMockListenerToReceive({buildCarDataInternal(101, {1})}).Times(1).WillOnce(ReturnOk());

    mFakeLooper.poll();
}

// First writes CarData, only then sets the listener.
TEST_F(TelemetryServerTest, WhenListenerIsSetLaterItPushesData) {
    std::vector<CarData> dataList = {buildCarData(101, {1})};

    mTelemetry->write(dataList);
    mTelemetryInternal->setListener(mMockCarDataListener);

    expectMockListenerToReceive({buildCarDataInternal(101, {1})}).Times(1).WillOnce(ReturnOk());

    mFakeLooper.poll();
}

TEST_F(TelemetryServerTest, WriteDuringPushingDataToListener) {
    std::vector<CarData> dataList = {buildCarData(101, {1}), buildCarData(102, {1})};
    std::vector<CarData> dataList2 = {buildCarData(103, {1})};
    mTelemetryInternal->setListener(mMockCarDataListener);
    mTelemetry->write(dataList);

    expectMockListenerToReceive({buildCarDataInternal(101, {1})}).WillOnce(ReturnOk());
    expectMockListenerToReceive({buildCarDataInternal(102, {1})}).WillOnce(ReturnOk());
    expectMockListenerToReceive({buildCarDataInternal(103, {1})}).WillOnce(ReturnOk());

    mFakeLooper.poll();  // sends only 1 CarData (or possibly 2 depenending on impl)
    mTelemetry->write(dataList2);
    mFakeLooper.poll();  // all the polls below send the rest of the CarData
    mFakeLooper.poll();
    mFakeLooper.poll();  // extra poll to verify there was not excess push calls
}

TEST_F(TelemetryServerTest, ClearListenerDuringPushingDataToListener) {
    std::vector<CarData> dataList = {buildCarData(101, {1})};
    mTelemetryInternal->setListener(mMockCarDataListener);
    mTelemetry->write(dataList);

    expectMockListenerToReceive({buildCarDataInternal(101, {1})}).Times(1).WillOnce(ReturnOk());

    mFakeLooper.poll();
    mTelemetry->write(dataList);
    mTelemetryInternal->clearListener();
    mFakeLooper.poll();
}

TEST_F(TelemetryServerTest, RetriesPushAgainIfListenerFails) {
    std::vector<CarData> dataList = {buildCarData(101, {1})};
    mTelemetryInternal->setListener(mMockCarDataListener);
    mTelemetry->write(dataList);

    expectMockListenerToReceive({buildCarDataInternal(101, {1})})
            .WillOnce(Return(ByMove(ScopedAStatus::fromExceptionCode(::EX_TRANSACTION_FAILED))))
            .WillOnce(ReturnOk());

    mFakeLooper.poll();  // listener returns ::EX_TRANSACTION_FAILED
    mFakeLooper.poll();
}

// Tests a corner case to make sure `TelemetryServer::mPendingCarDataInternals` variable
// is handled properly when transaction fails and clearListener() is called.
TEST_F(TelemetryServerTest, ClearListenerDuringPushingDataAndSetListenerAgain) {
    std::vector<CarData> dataList = {buildCarData(101, {1})};
    mTelemetryInternal->setListener(mMockCarDataListener);
    mTelemetry->write(dataList);

    expectMockListenerToReceive({buildCarDataInternal(101, {1})})
            .WillOnce(Return(ByMove(ScopedAStatus::fromExceptionCode(::EX_TRANSACTION_FAILED))))
            .WillOnce(ReturnOk());

    mFakeLooper.poll();  // listener returns ::EX_TRANSACTION_FAILED
    mTelemetryInternal->clearListener();
    mFakeLooper.poll();  // nothing happens
    mTelemetryInternal->setListener(mMockCarDataListener);
    mFakeLooper.poll();  // should work
}

// Directly calls pushCarDataToListeners() to make sure it can handle edge-cases.
TEST_F(TelemetryServerTest, NoListenerButMultiplePushes) {
    std::vector<CarData> dataList = {buildCarData(101, {1})};
    mTelemetry->write(dataList);

    mTelemetryServer.pushCarDataToListeners();
    mTelemetryServer.pushCarDataToListeners();
    mTelemetryServer.pushCarDataToListeners();

    EXPECT_CALL(*mMockCarDataListener, onCarDataReceived(_)).Times(0);
}

// Directly calls pushCarDataToListeners() to make sure it can handle edge-cases.
TEST_F(TelemetryServerTest, NoDataButMultiplePushes) {
    mTelemetryInternal->setListener(mMockCarDataListener);

    mTelemetryServer.pushCarDataToListeners();
    mTelemetryServer.pushCarDataToListeners();
    mTelemetryServer.pushCarDataToListeners();

    EXPECT_CALL(*mMockCarDataListener, onCarDataReceived(_)).Times(0);
}

}  // namespace telemetry
}  // namespace automotive
}  // namespace android
