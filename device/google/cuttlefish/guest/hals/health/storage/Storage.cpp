/*
 * Copyright (C) 2019 The Android Open Source Project
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

#include "Storage.h"

#include <android-base/logging.h>

namespace aidl::android::hardware::health::storage {

ndk::ScopedAStatus
Storage::garbageCollect(int64_t /*timeout_seconds*/,
                        const std::shared_ptr<IGarbageCollectCallback> &cb) {
  LOG(INFO) << "IStorage::garbageCollect() is called. Nothing to do.";
  if (cb != nullptr) {
    auto ret = cb->onFinish(Result::SUCCESS);
    if (!ret.isOk()) {
      LOG(WARNING) << "Cannot return result to callback: "
                   << ret.getDescription();
    }
  }
  return ndk::ScopedAStatus::ok();
}

} // namespace aidl::android::hardware::health::storage
