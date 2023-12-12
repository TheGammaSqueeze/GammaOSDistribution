/*
 * Copyright (C) 2020 The Android Open Source Project
 *
 * Licensed under the Nanache License, Version 2.0 (the "License");
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

#include <android-base/logging.h>

#include <VtsCoreUtil.h>
#include <android/hardware/wifi/1.5/IWifi.h>
#include <android/hardware/wifi/1.5/IWifiNanIface.h>
#include <android/hardware/wifi/1.5/IWifiNanIfaceEventCallback.h>
#include <gtest/gtest.h>
#include <hidl/GtestPrinter.h>
#include <hidl/ServiceManagement.h>
#include <chrono>
#include <condition_variable>
#include <mutex>

#include "wifi_hidl_call_util.h"
#include "wifi_hidl_test_utils.h"

using namespace ::android::hardware::wifi::V1_0;
using namespace ::android::hardware::wifi::V1_2;
using namespace ::android::hardware::wifi::V1_4;
using namespace ::android::hardware::wifi::V1_5;

using ::android::sp;
using ::android::hardware::Return;
using ::android::hardware::Void;

#define TIMEOUT_PERIOD 10

android::sp<android::hardware::wifi::V1_5::IWifiNanIface> getWifiNanIface_1_5(
    const std::string& instance_name) {
    return android::hardware::wifi::V1_5::IWifiNanIface::castFrom(
        getWifiNanIface(instance_name));
}

/**
 * Fixture to use for all NAN Iface HIDL interface tests.
 */
class WifiNanIfaceHidlTest : public ::testing::TestWithParam<std::string> {
   public:
    virtual void SetUp() override {
        if (!::testing::deviceSupportsFeature("android.hardware.wifi.aware"))
            GTEST_SKIP() << "Skipping this test since NAN is not supported.";
        // Make sure to start with a clean state
        stopWifi(GetInstanceName());

        iwifiNanIface = getWifiNanIface_1_5(GetInstanceName());
        ASSERT_NE(nullptr, iwifiNanIface.get());
        ASSERT_EQ(WifiStatusCode::SUCCESS,
                  HIDL_INVOKE(iwifiNanIface, registerEventCallback_1_5,
                              new WifiNanIfaceEventCallback(*this))
                      .code);
    }

    virtual void TearDown() override { stopWifi(GetInstanceName()); }

    /* Used as a mechanism to inform the test about data/event callback */
    inline void notify() {
        std::unique_lock<std::mutex> lock(mtx_);
        count_++;
        cv_.notify_one();
    }

    enum CallbackType {
        INVALID = -2,
        ANY_CALLBACK = -1,

        NOTIFY_CAPABILITIES_RESPONSE = 0,
        NOTIFY_ENABLE_RESPONSE,
        NOTIFY_CONFIG_RESPONSE,
        NOTIFY_DISABLE_RESPONSE,
        NOTIFY_START_PUBLISH_RESPONSE,
        NOTIFY_STOP_PUBLISH_RESPONSE,
        NOTIFY_START_SUBSCRIBE_RESPONSE,
        NOTIFY_STOP_SUBSCRIBE_RESPONSE,
        NOTIFY_TRANSMIT_FOLLOWUP_RESPONSE,
        NOTIFY_CREATE_DATA_INTERFACE_RESPONSE,
        NOTIFY_DELETE_DATA_INTERFACE_RESPONSE,
        NOTIFY_INITIATE_DATA_PATH_RESPONSE,
        NOTIFY_RESPOND_TO_DATA_PATH_INDICATION_RESPONSE,
        NOTIFY_TERMINATE_DATA_PATH_RESPONSE,
        NOTIFY_CAPABILITIES_RESPONSE_1_5,

        EVENT_CLUSTER_EVENT,
        EVENT_DISABLED,
        EVENT_PUBLISH_TERMINATED,
        EVENT_SUBSCRIBE_TERMINATED,
        EVENT_MATCH,
        EVENT_MATCH_EXPIRED,
        EVENT_FOLLOWUP_RECEIVED,
        EVENT_TRANSMIT_FOLLOWUP,
        EVENT_DATA_PATH_REQUEST,
        EVENT_DATA_PATH_CONFIRM,
        EVENT_DATA_PATH_TERMINATED,
        EVENT_DATA_PATH_CONFIRM_1_2,
        EVENT_DATA_PATH_SCHEDULE_UPDATE
    };

    /* Test code calls this function to wait for data/event callback */
    /* Must set callbackType = INVALID before call this function */
    inline std::cv_status wait(CallbackType waitForCallbackType) {
        std::unique_lock<std::mutex> lock(mtx_);

        EXPECT_NE(INVALID, waitForCallbackType);  // can't ASSERT in a
                                                  // non-void-returning method

        std::cv_status status = std::cv_status::no_timeout;
        auto now = std::chrono::system_clock::now();
        while (count_ == 0) {
            status = cv_.wait_until(lock,
                                    now + std::chrono::seconds(TIMEOUT_PERIOD));
            if (status == std::cv_status::timeout) return status;
            if (waitForCallbackType != ANY_CALLBACK &&
                callbackType != INVALID &&
                callbackType != waitForCallbackType) {
                count_--;
            }
        }
        count_--;
        return status;
    }

    class WifiNanIfaceEventCallback
        : public ::android::hardware::wifi::V1_5::IWifiNanIfaceEventCallback {
        WifiNanIfaceHidlTest& parent_;

       public:
        WifiNanIfaceEventCallback(WifiNanIfaceHidlTest& parent)
            : parent_(parent){};

        virtual ~WifiNanIfaceEventCallback() = default;

        Return<void> notifyCapabilitiesResponse(
            uint16_t id, const WifiNanStatus& status,
            const ::android::hardware::wifi::V1_0::NanCapabilities&
                capabilities) override {
            parent_.callbackType = NOTIFY_CAPABILITIES_RESPONSE;

            parent_.id = id;
            parent_.status = status;
            parent_.capabilities = capabilities;

            parent_.notify();
            return Void();
        }

        Return<void> notifyCapabilitiesResponse_1_5(
            uint16_t id, const WifiNanStatus& status,
            const ::android::hardware::wifi::V1_5::NanCapabilities&
                capabilities) override {
            parent_.callbackType = NOTIFY_CAPABILITIES_RESPONSE_1_5;

            parent_.id = id;
            parent_.status = status;
            parent_.capabilities_1_5 = capabilities;

            parent_.notify();
            return Void();
        }

        Return<void> notifyEnableResponse(
            uint16_t id, const WifiNanStatus& status) override {
            parent_.callbackType = NOTIFY_ENABLE_RESPONSE;

            parent_.id = id;
            parent_.status = status;

            parent_.notify();
            return Void();
        }

        Return<void> notifyConfigResponse(
            uint16_t id, const WifiNanStatus& status) override {
            parent_.callbackType = NOTIFY_CONFIG_RESPONSE;

            parent_.id = id;
            parent_.status = status;

            parent_.notify();
            return Void();
        }

        Return<void> notifyDisableResponse(
            uint16_t id, const WifiNanStatus& status) override {
            parent_.callbackType = NOTIFY_DISABLE_RESPONSE;

            parent_.id = id;
            parent_.status = status;

            parent_.notify();
            return Void();
        }

        Return<void> notifyStartPublishResponse(uint16_t id,
                                                const WifiNanStatus& status,
                                                uint8_t sessionId) override {
            parent_.callbackType = NOTIFY_START_PUBLISH_RESPONSE;

            parent_.id = id;
            parent_.status = status;
            parent_.sessionId = sessionId;

            parent_.notify();
            return Void();
        }

        Return<void> notifyStopPublishResponse(
            uint16_t id, const WifiNanStatus& status) override {
            parent_.callbackType = NOTIFY_STOP_PUBLISH_RESPONSE;

            parent_.id = id;
            parent_.status = status;

            parent_.notify();
            return Void();
        }

        Return<void> notifyStartSubscribeResponse(uint16_t id,
                                                  const WifiNanStatus& status,
                                                  uint8_t sessionId) override {
            parent_.callbackType = NOTIFY_START_SUBSCRIBE_RESPONSE;

            parent_.id = id;
            parent_.status = status;
            parent_.sessionId = sessionId;

            parent_.notify();
            return Void();
        }

        Return<void> notifyStopSubscribeResponse(
            uint16_t id, const WifiNanStatus& status) override {
            parent_.callbackType = NOTIFY_STOP_SUBSCRIBE_RESPONSE;

            parent_.id = id;
            parent_.status = status;

            parent_.notify();
            return Void();
        }

        Return<void> notifyTransmitFollowupResponse(
            uint16_t id, const WifiNanStatus& status) override {
            parent_.callbackType = NOTIFY_TRANSMIT_FOLLOWUP_RESPONSE;

            parent_.id = id;
            parent_.status = status;

            parent_.notify();
            return Void();
        }

        Return<void> notifyCreateDataInterfaceResponse(
            uint16_t id, const WifiNanStatus& status) override {
            parent_.callbackType = NOTIFY_CREATE_DATA_INTERFACE_RESPONSE;

            parent_.id = id;
            parent_.status = status;

            parent_.notify();
            return Void();
        }

        Return<void> notifyDeleteDataInterfaceResponse(
            uint16_t id, const WifiNanStatus& status) override {
            parent_.callbackType = NOTIFY_DELETE_DATA_INTERFACE_RESPONSE;

            parent_.id = id;
            parent_.status = status;

            parent_.notify();
            return Void();
        }

        Return<void> notifyInitiateDataPathResponse(
            uint16_t id, const WifiNanStatus& status,
            uint32_t ndpInstanceId) override {
            parent_.callbackType = NOTIFY_INITIATE_DATA_PATH_RESPONSE;

            parent_.id = id;
            parent_.status = status;
            parent_.ndpInstanceId = ndpInstanceId;

            parent_.notify();
            return Void();
        }

        Return<void> notifyRespondToDataPathIndicationResponse(
            uint16_t id, const WifiNanStatus& status) override {
            parent_.callbackType =
                NOTIFY_RESPOND_TO_DATA_PATH_INDICATION_RESPONSE;

            parent_.id = id;
            parent_.status = status;

            parent_.notify();
            return Void();
        }

        Return<void> notifyTerminateDataPathResponse(
            uint16_t id, const WifiNanStatus& status) override {
            parent_.callbackType = NOTIFY_TERMINATE_DATA_PATH_RESPONSE;

            parent_.id = id;
            parent_.status = status;

            parent_.notify();
            return Void();
        }

        Return<void> eventClusterEvent(
            const NanClusterEventInd& event) override {
            parent_.callbackType = EVENT_CLUSTER_EVENT;

            parent_.nanClusterEventInd = event;

            parent_.notify();
            return Void();
        }

        Return<void> eventDisabled(const WifiNanStatus& status) override {
            parent_.callbackType = EVENT_DISABLED;

            parent_.status = status;

            parent_.notify();
            return Void();
        }

        Return<void> eventPublishTerminated(
            uint8_t sessionId, const WifiNanStatus& status) override {
            parent_.callbackType = EVENT_PUBLISH_TERMINATED;

            parent_.sessionId = sessionId;
            parent_.status = status;

            parent_.notify();
            return Void();
        }

        Return<void> eventSubscribeTerminated(
            uint8_t sessionId, const WifiNanStatus& status) override {
            parent_.callbackType = EVENT_SUBSCRIBE_TERMINATED;

            parent_.sessionId = sessionId;
            parent_.status = status;

            parent_.notify();
            return Void();
        }

        Return<void> eventMatch(const NanMatchInd& event) override {
            parent_.callbackType = EVENT_MATCH;

            parent_.nanMatchInd = event;

            parent_.notify();
            return Void();
        }

        Return<void> eventMatchExpired(uint8_t discoverySessionId,
                                       uint32_t peerId) override {
            parent_.callbackType = EVENT_MATCH_EXPIRED;

            parent_.sessionId = discoverySessionId;
            parent_.peerId = peerId;

            parent_.notify();
            return Void();
        }

        Return<void> eventFollowupReceived(
            const NanFollowupReceivedInd& event) override {
            parent_.callbackType = EVENT_FOLLOWUP_RECEIVED;

            parent_.nanFollowupReceivedInd = event;

            parent_.notify();
            return Void();
        }

        Return<void> eventTransmitFollowup(
            uint16_t id, const WifiNanStatus& status) override {
            parent_.callbackType = EVENT_TRANSMIT_FOLLOWUP;

            parent_.id = id;
            parent_.status = status;

            parent_.notify();
            return Void();
        }

        Return<void> eventDataPathRequest(
            const NanDataPathRequestInd& event) override {
            parent_.callbackType = EVENT_DATA_PATH_REQUEST;

            parent_.nanDataPathRequestInd = event;

            parent_.notify();
            return Void();
        }

        Return<void> eventDataPathConfirm(
            const ::android::hardware::wifi::V1_0::NanDataPathConfirmInd& event)
            override {
            parent_.callbackType = EVENT_DATA_PATH_CONFIRM;

            parent_.nanDataPathConfirmInd = event;

            parent_.notify();
            return Void();
        }

        Return<void> eventDataPathTerminated(uint32_t ndpInstanceId) override {
            parent_.callbackType = EVENT_DATA_PATH_TERMINATED;

            parent_.ndpInstanceId = ndpInstanceId;

            parent_.notify();
            return Void();
        }

        Return<void> eventDataPathConfirm_1_2(
            const ::android::hardware::wifi::V1_2::NanDataPathConfirmInd& event)
            override {
            parent_.callbackType = EVENT_DATA_PATH_CONFIRM_1_2;

            parent_.nanDataPathConfirmInd_1_2 = event;

            parent_.notify();
            return Void();
        }

        Return<void> eventDataPathScheduleUpdate(
            const NanDataPathScheduleUpdateInd& event) override {
            parent_.callbackType = EVENT_DATA_PATH_SCHEDULE_UPDATE;

            parent_.nanDataPathScheduleUpdateInd = event;

            parent_.notify();
            return Void();
        }
    };

   private:
    // synchronization objects
    std::mutex mtx_;
    std::condition_variable cv_;
    int count_ = 0;

   protected:
    android::sp<::android::hardware::wifi::V1_5::IWifiNanIface> iwifiNanIface;

    // Data from IWifiNanIfaceEventCallback callbacks: this is the collection of
    // all arguments to all callbacks. They are set by the callback
    // (notifications or events) and can be retrieved by tests.
    CallbackType callbackType;
    uint16_t id;
    WifiNanStatus status;
    uint8_t sessionId;
    uint32_t ndpInstanceId;
    NanClusterEventInd nanClusterEventInd;
    NanMatchInd nanMatchInd;
    uint32_t peerId;
    NanFollowupReceivedInd nanFollowupReceivedInd;
    NanDataPathRequestInd nanDataPathRequestInd;
    ::android::hardware::wifi::V1_0::NanCapabilities capabilities;
    ::android::hardware::wifi::V1_5::NanCapabilities capabilities_1_5;
    ::android::hardware::wifi::V1_0::NanDataPathConfirmInd
        nanDataPathConfirmInd;
    ::android::hardware::wifi::V1_2::NanDataPathConfirmInd
        nanDataPathConfirmInd_1_2;
    NanDataPathScheduleUpdateInd nanDataPathScheduleUpdateInd;

    std::string GetInstanceName() { return GetParam(); }
};

/*
 * Create:
 * Ensures that an instance of the IWifiNanIface proxy object is
 * successfully created.
 */
TEST_P(WifiNanIfaceHidlTest, Create) {
    // The creation of a proxy object is tested as part of SetUp method.
}

/*
 * enableRequest_1_5InvalidArgs: validate that fails with invalid arguments
 */
TEST_P(WifiNanIfaceHidlTest, enableRequest_1_5InvalidArgs) {
    uint16_t inputCmdId = 10;
    callbackType = INVALID;
    ::android::hardware::wifi::V1_4::NanEnableRequest nanEnableRequest = {};
    ::android::hardware::wifi::V1_5::NanConfigRequestSupplemental
        nanConfigRequestSupp = {};
    const auto& halStatus =
        HIDL_INVOKE(iwifiNanIface, enableRequest_1_5, inputCmdId,
                    nanEnableRequest, nanConfigRequestSupp);
    if (halStatus.code != WifiStatusCode::ERROR_NOT_SUPPORTED) {
        ASSERT_EQ(WifiStatusCode::SUCCESS, halStatus.code);

        // wait for a callback
        ASSERT_EQ(std::cv_status::no_timeout, wait(NOTIFY_ENABLE_RESPONSE));
        ASSERT_EQ(NOTIFY_ENABLE_RESPONSE, callbackType);
        ASSERT_EQ(id, inputCmdId);
        ASSERT_EQ(status.status, NanStatusType::INVALID_ARGS);
    }
}

/*
 * enableRequest_1_5ShimInvalidArgs: validate that fails with invalid arguments
 * to the shim
 */
TEST_P(WifiNanIfaceHidlTest, enableRequest_1_5ShimInvalidArgs) {
    uint16_t inputCmdId = 10;
    ::android::hardware::wifi::V1_4::NanEnableRequest nanEnableRequest = {};
    nanEnableRequest.configParams.numberOfPublishServiceIdsInBeacon =
        128;  // must be <= 127
    ::android::hardware::wifi::V1_5::NanConfigRequestSupplemental
        nanConfigRequestSupp = {};
    const auto& halStatus =
        HIDL_INVOKE(iwifiNanIface, enableRequest_1_5, inputCmdId,
                    nanEnableRequest, nanConfigRequestSupp);
    if (halStatus.code != WifiStatusCode::ERROR_NOT_SUPPORTED) {
        ASSERT_EQ(WifiStatusCode::ERROR_INVALID_ARGS, halStatus.code);
    }
}

/*
 * configRequest_1_5InvalidArgs: validate that fails with invalid arguments
 */
TEST_P(WifiNanIfaceHidlTest, configRequest_1_5InvalidArgs) {
    uint16_t inputCmdId = 10;
    callbackType = INVALID;
    ::android::hardware::wifi::V1_4::NanConfigRequest nanConfigRequest = {};
    ::android::hardware::wifi::V1_5::NanConfigRequestSupplemental
        nanConfigRequestSupp = {};
    const auto& halStatus =
        HIDL_INVOKE(iwifiNanIface, configRequest_1_5, inputCmdId,
                    nanConfigRequest, nanConfigRequestSupp);

    if (halStatus.code != WifiStatusCode::ERROR_NOT_SUPPORTED) {
        ASSERT_EQ(WifiStatusCode::SUCCESS, halStatus.code);

        // wait for a callback
        ASSERT_EQ(std::cv_status::no_timeout, wait(NOTIFY_CONFIG_RESPONSE));
        ASSERT_EQ(NOTIFY_CONFIG_RESPONSE, callbackType);
        ASSERT_EQ(id, inputCmdId);
        ASSERT_EQ(status.status, NanStatusType::INVALID_ARGS);
    }
}

/*
 * configRequest_1_5ShimInvalidArgs: validate that fails with invalid arguments
 * to the shim
 */
TEST_P(WifiNanIfaceHidlTest, configRequest_1_5ShimInvalidArgs) {
    uint16_t inputCmdId = 10;
    ::android::hardware::wifi::V1_4::NanConfigRequest nanConfigRequest = {};
    nanConfigRequest.numberOfPublishServiceIdsInBeacon = 128;  // must be <= 127
    ::android::hardware::wifi::V1_5::NanConfigRequestSupplemental
        nanConfigRequestSupp = {};
    const auto& halStatus =
        HIDL_INVOKE(iwifiNanIface, configRequest_1_5, inputCmdId,
                    nanConfigRequest, nanConfigRequestSupp);
    if (halStatus.code != WifiStatusCode::ERROR_NOT_SUPPORTED) {
        ASSERT_EQ(WifiStatusCode::ERROR_INVALID_ARGS, halStatus.code);
    }
}

/*
 * getCapabilitiesRequest: validate that returns capabilities.
 */
TEST_P(WifiNanIfaceHidlTest, getCapabilitiesRequest_1_5) {
    uint16_t inputCmdId = 10;
    callbackType = INVALID;
    const auto& halStatus =
        HIDL_INVOKE(iwifiNanIface, getCapabilitiesRequest_1_5, inputCmdId).code;
    ASSERT_EQ(WifiStatusCode::SUCCESS, halStatus);
    // wait for a callback
    ASSERT_EQ(std::cv_status::no_timeout,
              wait(NOTIFY_CAPABILITIES_RESPONSE_1_5));
    ASSERT_EQ(NOTIFY_CAPABILITIES_RESPONSE_1_5, callbackType);
    ASSERT_EQ(id, inputCmdId);

    // check for reasonable capability values
    EXPECT_GT(capabilities_1_5.V1_0.maxConcurrentClusters, (unsigned int)0);
    EXPECT_GT(capabilities_1_5.V1_0.maxPublishes, (unsigned int)0);
    EXPECT_GT(capabilities_1_5.V1_0.maxSubscribes, (unsigned int)0);
    EXPECT_EQ(capabilities_1_5.V1_0.maxServiceNameLen, (unsigned int)255);
    EXPECT_EQ(capabilities_1_5.V1_0.maxMatchFilterLen, (unsigned int)255);
    EXPECT_GT(capabilities_1_5.V1_0.maxTotalMatchFilterLen, (unsigned int)255);
    EXPECT_EQ(capabilities_1_5.V1_0.maxServiceSpecificInfoLen,
              (unsigned int)255);
    EXPECT_GE(capabilities_1_5.V1_0.maxExtendedServiceSpecificInfoLen,
              (unsigned int)255);
    EXPECT_GT(capabilities_1_5.V1_0.maxNdiInterfaces, (unsigned int)0);
    EXPECT_GT(capabilities_1_5.V1_0.maxNdpSessions, (unsigned int)0);
    EXPECT_GT(capabilities_1_5.V1_0.maxAppInfoLen, (unsigned int)0);
    EXPECT_GT(capabilities_1_5.V1_0.maxQueuedTransmitFollowupMsgs,
              (unsigned int)0);
    EXPECT_GT(capabilities_1_5.V1_0.maxSubscribeInterfaceAddresses,
              (unsigned int)0);
    EXPECT_NE(capabilities_1_5.V1_0.supportedCipherSuites, (unsigned int)0);
    EXPECT_TRUE(capabilities_1_5.instantCommunicationModeSupportFlag ||
                !capabilities_1_5.instantCommunicationModeSupportFlag);
}

GTEST_ALLOW_UNINSTANTIATED_PARAMETERIZED_TEST(WifiNanIfaceHidlTest);
INSTANTIATE_TEST_SUITE_P(
    PerInstance, WifiNanIfaceHidlTest,
    testing::ValuesIn(android::hardware::getAllHalInstanceNames(
        ::android::hardware::wifi::V1_5::IWifi::descriptor)),
    android::hardware::PrintInstanceNameToString);
