#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <aaudio/IAAudioService.h>

namespace aaudio {

class BpAAudioService : public ::android::BpInterface<IAAudioService> {
public:
  explicit BpAAudioService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpAAudioService() = default;
  ::android::binder::Status registerClient(const ::android::sp<::aaudio::IAAudioClient>& client) override;
  ::android::binder::Status openStream(const ::aaudio::StreamRequest& request, ::aaudio::StreamParameters* paramsOut, int32_t* _aidl_return) override;
  ::android::binder::Status closeStream(int32_t streamHandle, int32_t* _aidl_return) override;
  ::android::binder::Status getStreamDescription(int32_t streamHandle, ::aaudio::Endpoint* endpoint, int32_t* _aidl_return) override;
  ::android::binder::Status startStream(int32_t streamHandle, int32_t* _aidl_return) override;
  ::android::binder::Status pauseStream(int32_t streamHandle, int32_t* _aidl_return) override;
  ::android::binder::Status stopStream(int32_t streamHandle, int32_t* _aidl_return) override;
  ::android::binder::Status flushStream(int32_t streamHandle, int32_t* _aidl_return) override;
  ::android::binder::Status registerAudioThread(int32_t streamHandle, int32_t clientThreadId, int64_t periodNanoseconds, int32_t* _aidl_return) override;
  ::android::binder::Status unregisterAudioThread(int32_t streamHandle, int32_t clientThreadId, int32_t* _aidl_return) override;
};  // class BpAAudioService

}  // namespace aaudio
