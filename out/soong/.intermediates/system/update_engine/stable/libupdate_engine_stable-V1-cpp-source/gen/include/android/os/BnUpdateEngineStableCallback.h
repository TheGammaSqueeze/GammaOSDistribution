#pragma once

#include <binder/IInterface.h>
#include <android/os/IUpdateEngineStableCallback.h>

namespace android {

namespace os {

class BnUpdateEngineStableCallback : public ::android::BnInterface<IUpdateEngineStableCallback> {
public:
  static constexpr uint32_t TRANSACTION_onStatusUpdate = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onPayloadApplicationComplete = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getInterfaceVersion = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777214;
  static constexpr uint32_t TRANSACTION_getInterfaceHash = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777213;
  explicit BnUpdateEngineStableCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
  int32_t getInterfaceVersion() final;
  std::string getInterfaceHash();
};  // class BnUpdateEngineStableCallback

}  // namespace os

}  // namespace android
