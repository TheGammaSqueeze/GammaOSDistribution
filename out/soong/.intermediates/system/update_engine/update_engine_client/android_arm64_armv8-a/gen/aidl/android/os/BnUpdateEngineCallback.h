#pragma once

#include <binder/IInterface.h>
#include <android/os/IUpdateEngineCallback.h>

namespace android {

namespace os {

class BnUpdateEngineCallback : public ::android::BnInterface<IUpdateEngineCallback> {
public:
  static constexpr uint32_t TRANSACTION_onStatusUpdate = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onPayloadApplicationComplete = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnUpdateEngineCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnUpdateEngineCallback

}  // namespace os

}  // namespace android
