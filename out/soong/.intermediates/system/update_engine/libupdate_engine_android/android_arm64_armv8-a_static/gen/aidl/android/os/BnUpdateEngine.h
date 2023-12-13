#pragma once

#include <binder/IInterface.h>
#include <android/os/IUpdateEngine.h>

namespace android {

namespace os {

class BnUpdateEngine : public ::android::BnInterface<IUpdateEngine> {
public:
  static constexpr uint32_t TRANSACTION_applyPayload = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_applyPayloadFd = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_bind = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_unbind = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_suspend = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_resume = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_cancel = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_resetStatus = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_verifyPayloadApplicable = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_allocateSpaceForPayload = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_cleanupSuccessfulUpdate = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_setPerformanceMode = ::android::IBinder::FIRST_CALL_TRANSACTION + 11;
  explicit BnUpdateEngine();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnUpdateEngine

}  // namespace os

}  // namespace android
