#pragma once

#include <binder/IInterface.h>
#include <android/media/IEffect.h>

namespace android {

namespace media {

class BnEffect : public ::android::BnInterface<IEffect> {
public:
  static constexpr uint32_t TRANSACTION_enable = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_disable = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_command = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_disconnect = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_getCblk = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  explicit BnEffect();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnEffect

}  // namespace media

}  // namespace android
