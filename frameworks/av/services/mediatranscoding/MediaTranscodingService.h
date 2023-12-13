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

#ifndef ANDROID_MEDIA_TRANSCODING_SERVICE_H
#define ANDROID_MEDIA_TRANSCODING_SERVICE_H

#include <aidl/android/media/BnMediaTranscodingService.h>
#include <binder/IServiceManager.h>

namespace android {

using Status = ::ndk::ScopedAStatus;
using ::aidl::android::media::BnMediaTranscodingService;
using ::aidl::android::media::ITranscodingClient;
using ::aidl::android::media::ITranscodingClientCallback;
using ::aidl::android::media::TranscodingRequestParcel;
using ::aidl::android::media::TranscodingSessionParcel;
class TranscodingClientManager;
class TranscodingLogger;
class TranscodingSessionController;
class UidPolicyInterface;
class ResourcePolicyInterface;
class ThermalPolicyInterface;

class MediaTranscodingService : public BnMediaTranscodingService {
public:
    static constexpr int32_t kInvalidSessionId = -1;
    static constexpr int32_t kInvalidClientId = -1;

    MediaTranscodingService();
    virtual ~MediaTranscodingService();

    static void instantiate();

    static const char* getServiceName() { return "media.transcoding"; }

    Status registerClient(const std::shared_ptr<ITranscodingClientCallback>& in_callback,
                          const std::string& in_clientName, const std::string& in_opPackageName,
                          std::shared_ptr<ITranscodingClient>* _aidl_return) override;

    Status getNumOfClients(int32_t* _aidl_return) override;

    virtual inline binder_status_t dump(int /*fd*/, const char** /*args*/, uint32_t /*numArgs*/);

private:
    friend class MediaTranscodingServiceTest;

    mutable std::mutex mServiceLock;

    std::shared_ptr<UidPolicyInterface> mUidPolicy;
    std::shared_ptr<ResourcePolicyInterface> mResourcePolicy;
    std::shared_ptr<ThermalPolicyInterface> mThermalPolicy;
    std::shared_ptr<TranscodingLogger> mLogger;
    std::shared_ptr<TranscodingSessionController> mSessionController;
    std::shared_ptr<TranscodingClientManager> mClientManager;
};

}  // namespace android

#endif  // ANDROID_MEDIA_TRANSCODING_SERVICE_H
