#pragma once

#include <binder/IInterface.h>
#include <android/hardware/camera2/ICameraDeviceCallbacks.h>

namespace android {

namespace hardware {

namespace camera2 {

class BnCameraDeviceCallbacks : public ::android::BnInterface<ICameraDeviceCallbacks> {
public:
  static constexpr uint32_t TRANSACTION_onDeviceError = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onDeviceIdle = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onCaptureStarted = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_onResultReceived = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_onPrepared = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_onRepeatingRequestError = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_onRequestQueueEmpty = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  explicit BnCameraDeviceCallbacks();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCameraDeviceCallbacks

}  // namespace camera2

}  // namespace hardware

}  // namespace android
