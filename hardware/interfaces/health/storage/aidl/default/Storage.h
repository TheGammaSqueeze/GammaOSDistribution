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

#pragma once

#include <aidl/android/hardware/health/storage/BnStorage.h>

namespace aidl::android::hardware::health::storage {

class Storage : public BnStorage {
    ndk::ScopedAStatus garbageCollect(
            int64_t timeout_seconds,
            const std::shared_ptr<IGarbageCollectCallback>& callback) override;
    binder_status_t dump(int fd, const char** args, uint32_t num_args) override;
};

}  // namespace aidl::android::hardware::health::storage
