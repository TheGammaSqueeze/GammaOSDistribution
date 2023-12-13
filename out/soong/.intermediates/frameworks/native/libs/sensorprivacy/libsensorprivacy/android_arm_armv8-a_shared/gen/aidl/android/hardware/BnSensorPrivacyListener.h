#pragma once

#include <binder/IInterface.h>
#include <android/hardware/ISensorPrivacyListener.h>

namespace android {

namespace hardware {

class BnSensorPrivacyListener : public ::android::BnInterface<ISensorPrivacyListener> {
public:
  static constexpr uint32_t TRANSACTION_onSensorPrivacyChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnSensorPrivacyListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnSensorPrivacyListener

}  // namespace hardware

}  // namespace android
