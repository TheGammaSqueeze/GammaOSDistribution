#pragma once

#include <binder/IInterface.h>
#include <android/hardware/ICameraServiceProxy.h>

namespace android {

namespace hardware {

class BnCameraServiceProxy : public ::android::BnInterface<ICameraServiceProxy> {
public:
  static constexpr uint32_t TRANSACTION_pingForUserUpdate = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_notifyCameraState = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getRotateAndCropOverride = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  explicit BnCameraServiceProxy();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCameraServiceProxy

}  // namespace hardware

}  // namespace android
