#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/IAudioRecord.h>

namespace android {

namespace media {

class BpAudioRecord : public ::android::BpInterface<IAudioRecord> {
public:
  explicit BpAudioRecord(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpAudioRecord() = default;
  ::android::binder::Status start(int32_t event, int32_t triggerSession) override;
  ::android::binder::Status stop() override;
  ::android::binder::Status getActiveMicrophones(::std::vector<::android::media::MicrophoneInfoData>* activeMicrophones) override;
  ::android::binder::Status setPreferredMicrophoneDirection(int32_t direction) override;
  ::android::binder::Status setPreferredMicrophoneFieldDimension(float zoom) override;
  ::android::binder::Status shareAudioHistory(const ::std::string& sharedAudioPackageName, int64_t sharedAudioStartMs) override;
};  // class BpAudioRecord

}  // namespace media

}  // namespace android
