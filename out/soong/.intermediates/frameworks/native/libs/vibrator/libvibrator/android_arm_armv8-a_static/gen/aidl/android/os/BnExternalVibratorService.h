#pragma once

#include <binder/IInterface.h>
#include <android/os/IExternalVibratorService.h>

namespace android {

namespace os {

class BnExternalVibratorService : public ::android::BnInterface<IExternalVibratorService> {
public:
  static constexpr uint32_t TRANSACTION_onExternalVibrationStart = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onExternalVibrationStop = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnExternalVibratorService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnExternalVibratorService

}  // namespace os

}  // namespace android
