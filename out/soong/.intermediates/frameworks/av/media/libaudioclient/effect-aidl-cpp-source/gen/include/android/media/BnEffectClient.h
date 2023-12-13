#pragma once

#include <binder/IInterface.h>
#include <android/media/IEffectClient.h>

namespace android {

namespace media {

class BnEffectClient : public ::android::BnInterface<IEffectClient> {
public:
  static constexpr uint32_t TRANSACTION_controlStatusChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_enableStatusChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_commandExecuted = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_framesProcessed = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  explicit BnEffectClient();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnEffectClient

}  // namespace media

}  // namespace android
