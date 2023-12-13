#pragma once

#include <binder/IInterface.h>
#include <android/hardware/camera2/ICameraInjectionSession.h>

namespace android {

namespace hardware {

namespace camera2 {

class BnCameraInjectionSession : public ::android::BnInterface<ICameraInjectionSession> {
public:
  static constexpr uint32_t TRANSACTION_stopInjection = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnCameraInjectionSession();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCameraInjectionSession

}  // namespace camera2

}  // namespace hardware

}  // namespace android
