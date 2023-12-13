/*
 * Copyright (c) 2022, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CPP_WATCHDOG_SERVER_TESTS_MOCKVEHICLE_H_
#define CPP_WATCHDOG_SERVER_TESTS_MOCKVEHICLE_H_

#include <android/hardware/automotive/vehicle/2.0/IVehicle.h>
#include <gmock/gmock.h>
#include <utils/StrongPointer.h>

namespace android {
namespace automotive {
namespace watchdog {

class MockVehicle final : public android::hardware::automotive::vehicle::V2_0::IVehicle {
public:
    MockVehicle() {}

    MOCK_METHOD(android::hardware::Return<void>, getAllPropConfigs, (getAllPropConfigs_cb),
                (override));
    MOCK_METHOD(android::hardware::Return<void>, getPropConfigs,
                (const android::hardware::hidl_vec<int32_t>&, getPropConfigs_cb), (override));
    MOCK_METHOD(android::hardware::Return<void>, get,
                (const android::hardware::automotive::vehicle::V2_0::VehiclePropValue&, get_cb),
                (override));
    MOCK_METHOD(
            android::hardware::Return<::android::hardware::automotive::vehicle::V2_0::StatusCode>,
            set, (const android::hardware::automotive::vehicle::V2_0::VehiclePropValue&),
            (override));
    MOCK_METHOD(android::hardware::Return<android::hardware::automotive::vehicle::V2_0::StatusCode>,
                subscribe,
                (const android::sp<android::hardware::automotive::vehicle::V2_0::IVehicleCallback>&,
                 const android::hardware::hidl_vec<
                         android::hardware::automotive::vehicle::V2_0::SubscribeOptions>&),
                (override));
    MOCK_METHOD(android::hardware::Return<android::hardware::automotive::vehicle::V2_0::StatusCode>,
                unsubscribe,
                (const android::sp<android::hardware::automotive::vehicle::V2_0::IVehicleCallback>&,
                 int32_t),
                (override));
    MOCK_METHOD(android::hardware::Return<void>, debugDump, (debugDump_cb _hidl_cb), (override));
    MOCK_METHOD(android::hardware::Return<bool>, linkToDeath,
                (const ::android::sp<::android::hardware::hidl_death_recipient>&, uint64_t),
                (override));
    MOCK_METHOD(android::hardware::Return<bool>, unlinkToDeath,
                (const ::android::sp<::android::hardware::hidl_death_recipient>&), (override));
};

}  // namespace watchdog
}  // namespace automotive
}  // namespace android

#endif  // CPP_WATCHDOG_SERVER_TESTS_MOCKVEHICLE_H_
