#pragma once

#include <binder/IInterface.h>
#include <android/media/IAudioFlingerClient.h>

namespace android {

namespace media {

class BnAudioFlingerClient : public ::android::BnInterface<IAudioFlingerClient> {
public:
  static constexpr uint32_t TRANSACTION_ioConfigChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnAudioFlingerClient();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnAudioFlingerClient

}  // namespace media

}  // namespace android
