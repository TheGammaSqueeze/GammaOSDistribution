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

#define LOG_TAG "Gnss-main"

#include <android-base/logging.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>
#include <hidl/HidlSupport.h>
#include <hidl/HidlTransportSupport.h>
#include <log/log.h>
#include <pthread.h>
#include "Gnss.h"
#include "GnssHidlHal.h"

using aidl::android::hardware::gnss::Gnss;
using aidl::android::hardware::gnss::GnssHidlHal;
using ::android::OK;
using ::android::sp;
using ::android::hardware::configureRpcThreadpool;
using ::android::hardware::joinRpcThreadpool;
using ::android::hardware::gnss::V2_1::IGnss;

int main() {
    ABinderProcess_setThreadPoolMaxThreadCount(1);
    ABinderProcess_startThreadPool();

    std::shared_ptr<Gnss> gnssAidl = ndk::SharedRefBase::make<Gnss>();
    const std::string instance = std::string() + Gnss::descriptor + "/default";
    binder_status_t status =
            AServiceManager_addService(gnssAidl->asBinder().get(), instance.c_str());
    CHECK(status == STATUS_OK);

    sp<IGnss> gnss = new GnssHidlHal(gnssAidl);
    configureRpcThreadpool(1, true /* will join */);
    if (gnss->registerAsService() != OK) {
        ALOGE("Could not register gnss 2.1 service.");
        return 0;
    }

    joinRpcThreadpool();
    ABinderProcess_joinThreadPool();

    return EXIT_FAILURE;  // should not reach
}
