#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/IEffectClient.h>

namespace android {

namespace media {

class BpEffectClient : public ::android::BpInterface<IEffectClient> {
public:
  explicit BpEffectClient(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpEffectClient() = default;
  ::android::binder::Status controlStatusChanged(bool controlGranted) override;
  ::android::binder::Status enableStatusChanged(bool enabled) override;
  ::android::binder::Status commandExecuted(int32_t cmdCode, const ::std::vector<uint8_t>& cmdData, const ::std::vector<uint8_t>& replyData) override;
  ::android::binder::Status framesProcessed(int32_t frames) override;
};  // class BpEffectClient

}  // namespace media

}  // namespace android
