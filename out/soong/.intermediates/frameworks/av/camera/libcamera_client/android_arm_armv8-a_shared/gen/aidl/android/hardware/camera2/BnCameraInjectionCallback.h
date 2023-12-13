#pragma once

#include <binder/IInterface.h>
#include <android/hardware/camera2/ICameraInjectionCallback.h>

namespace android {

namespace hardware {

namespace camera2 {

class BnCameraInjectionCallback : public ::android::BnInterface<ICameraInjectionCallback> {
public:
  static constexpr uint32_t TRANSACTION_onInjectionError = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnCameraInjectionCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCameraInjectionCallback

}  // namespace camera2

}  // namespace hardware

}  // namespace android
