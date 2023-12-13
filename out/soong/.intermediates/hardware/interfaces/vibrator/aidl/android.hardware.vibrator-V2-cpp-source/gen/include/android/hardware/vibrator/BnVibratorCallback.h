#pragma once

#include <binder/IInterface.h>
#include <android/hardware/vibrator/IVibratorCallback.h>

namespace android {

namespace hardware {

namespace vibrator {

class BnVibratorCallback : public ::android::BnInterface<IVibratorCallback> {
public:
  static constexpr uint32_t TRANSACTION_onComplete = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getInterfaceVersion = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777214;
  static constexpr uint32_t TRANSACTION_getInterfaceHash = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777213;
  explicit BnVibratorCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
  int32_t getInterfaceVersion() final;
  std::string getInterfaceHash();
};  // class BnVibratorCallback

}  // namespace vibrator

}  // namespace hardware

}  // namespace android
