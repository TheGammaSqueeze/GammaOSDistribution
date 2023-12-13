#pragma once

#include <binder/IInterface.h>
#include <android/os/IInputFlinger.h>

namespace android {

namespace os {

class BnInputFlinger : public ::android::BnInterface<IInputFlinger> {
public:
  static constexpr uint32_t TRANSACTION_createInputChannel = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_removeInputChannel = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_setFocusedWindow = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  explicit BnInputFlinger();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnInputFlinger

}  // namespace os

}  // namespace android
