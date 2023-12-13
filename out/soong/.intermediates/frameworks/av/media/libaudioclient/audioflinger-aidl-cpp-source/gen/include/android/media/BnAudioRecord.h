#pragma once

#include <binder/IInterface.h>
#include <android/media/IAudioRecord.h>

namespace android {

namespace media {

class BnAudioRecord : public ::android::BnInterface<IAudioRecord> {
public:
  static constexpr uint32_t TRANSACTION_start = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_stop = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getActiveMicrophones = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_setPreferredMicrophoneDirection = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_setPreferredMicrophoneFieldDimension = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_shareAudioHistory = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  explicit BnAudioRecord();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnAudioRecord

}  // namespace media

}  // namespace android
