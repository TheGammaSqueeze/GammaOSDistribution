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

#ifndef ANDROID_FRAMEWORKS_ML_NN_DRIVER_SAMPLE_AIDL_SAMPLE_DRIVER_UTILS_H
#define ANDROID_FRAMEWORKS_ML_NN_DRIVER_SAMPLE_AIDL_SAMPLE_DRIVER_UTILS_H

#include <android/binder_auto_utils.h>

#include <memory>
#include <string>

#include "SampleDriver.h"

namespace android {
namespace nn {
namespace sample_driver {

void notify(const std::shared_ptr<aidl_hal::IPreparedModelCallback>& callback,
            const aidl_hal::ErrorStatus& status,
            const std::shared_ptr<aidl_hal::IPreparedModel>& preparedModel);

ndk::ScopedAStatus prepareModelBase(
        aidl_hal::Model&& model, const SampleDriver* driver,
        aidl_hal::ExecutionPreference preference, aidl_hal::Priority priority, int64_t halDeadline,
        const std::shared_ptr<aidl_hal::IPreparedModelCallback>& callback,
        bool isFullModelSupported = true);

ndk::ScopedAStatus toAStatus(aidl_hal::ErrorStatus errorStatus);
ndk::ScopedAStatus toAStatus(aidl_hal::ErrorStatus errorStatus, const std::string& errorMessage);

}  // namespace sample_driver
}  // namespace nn
}  // namespace android

#endif  // ANDROID_FRAMEWORKS_ML_NN_DRIVER_SAMPLE_AIDL_SAMPLE_DRIVER_UTILS_H
