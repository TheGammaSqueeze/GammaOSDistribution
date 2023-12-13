#pragma once

#include <binder/IInterface.h>
#include <android/hardware/ICameraServiceListener.h>

namespace android {

namespace hardware {

class BnCameraServiceListener : public ::android::BnInterface<ICameraServiceListener> {
public:
  static constexpr uint32_t TRANSACTION_onStatusChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onPhysicalCameraStatusChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onTorchStatusChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_onCameraAccessPrioritiesChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_onCameraOpened = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_onCameraClosed = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  explicit BnCameraServiceListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCameraServiceListener

}  // namespace hardware

}  // namespace android
