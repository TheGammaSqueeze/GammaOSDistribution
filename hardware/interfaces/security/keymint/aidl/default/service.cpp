/*
 * Copyright 2020, The Android Open Source Project
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

#define LOG_TAG "android.hardware.security.keymint-service"

#include <android-base/logging.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>

#include <AndroidKeyMintDevice.h>
#include <AndroidRemotelyProvisionedComponentDevice.h>
#include <AndroidSecureClock.h>
#include <AndroidSharedSecret.h>
#include <keymaster/soft_keymaster_logger.h>

using aidl::android::hardware::security::keymint::AndroidKeyMintDevice;
using aidl::android::hardware::security::keymint::AndroidRemotelyProvisionedComponentDevice;
using aidl::android::hardware::security::keymint::SecurityLevel;
using aidl::android::hardware::security::secureclock::AndroidSecureClock;
using aidl::android::hardware::security::sharedsecret::AndroidSharedSecret;

template <typename T, class... Args>
std::shared_ptr<T> addService(Args&&... args) {
    std::shared_ptr<T> ser = ndk::SharedRefBase::make<T>(std::forward<Args>(args)...);
    auto instanceName = std::string(T::descriptor) + "/default";
    LOG(INFO) << "adding keymint service instance: " << instanceName;
    binder_status_t status =
            AServiceManager_addService(ser->asBinder().get(), instanceName.c_str());
    CHECK(status == STATUS_OK);
    return ser;
}

int main() {
    // Zero threads seems like a useless pool, but below we'll join this thread to it, increasing
    // the pool size to 1.
    ABinderProcess_setThreadPoolMaxThreadCount(0);
    // Add Keymint Service
    std::shared_ptr<AndroidKeyMintDevice> keyMint =
            addService<AndroidKeyMintDevice>(SecurityLevel::SOFTWARE);
    // Add Secure Clock Service
    addService<AndroidSecureClock>(keyMint);
    // Add Shared Secret Service
    addService<AndroidSharedSecret>(keyMint);
    // Add Remotely Provisioned Component Service
    addService<AndroidRemotelyProvisionedComponentDevice>(keyMint);
    ABinderProcess_joinThreadPool();
    return EXIT_FAILURE;  // should not reach
}
