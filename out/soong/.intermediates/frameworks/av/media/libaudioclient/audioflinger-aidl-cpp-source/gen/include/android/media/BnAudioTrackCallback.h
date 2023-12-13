#pragma once

#include <binder/IInterface.h>
#include <android/media/IAudioTrackCallback.h>

namespace android {

namespace media {

class BnAudioTrackCallback : public ::android::BnInterface<IAudioTrackCallback> {
public:
  static constexpr uint32_t TRANSACTION_onCodecFormatChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnAudioTrackCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnAudioTrackCallback

}  // namespace media

}  // namespace android
