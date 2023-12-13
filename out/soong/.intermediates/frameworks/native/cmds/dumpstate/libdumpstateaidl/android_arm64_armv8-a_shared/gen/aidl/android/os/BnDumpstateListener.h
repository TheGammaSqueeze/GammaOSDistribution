#pragma once

#include <binder/IInterface.h>
#include <android/os/IDumpstateListener.h>

namespace android {

namespace os {

class BnDumpstateListener : public ::android::BnInterface<IDumpstateListener> {
public:
  static constexpr uint32_t TRANSACTION_onProgress = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onError = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onFinished = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_onScreenshotTaken = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_onUiIntensiveBugreportDumpsFinished = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  explicit BnDumpstateListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnDumpstateListener

}  // namespace os

}  // namespace android
