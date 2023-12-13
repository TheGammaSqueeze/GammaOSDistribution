#pragma once

#include <binder/IInterface.h>
#include <android/os/IExternalVibrationController.h>

namespace android {

namespace os {

class BnExternalVibrationController : public ::android::BnInterface<IExternalVibrationController> {
public:
  static constexpr uint32_t TRANSACTION_mute = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_unmute = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnExternalVibrationController();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnExternalVibrationController

}  // namespace os

}  // namespace android
