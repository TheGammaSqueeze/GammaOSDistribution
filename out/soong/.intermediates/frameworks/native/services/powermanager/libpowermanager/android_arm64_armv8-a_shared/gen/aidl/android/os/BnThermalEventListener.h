#pragma once

#include <binder/IInterface.h>
#include <android/os/IThermalEventListener.h>

namespace android {

namespace os {

class BnThermalEventListener : public ::android::BnInterface<IThermalEventListener> {
public:
  static constexpr uint32_t TRANSACTION_notifyThrottling = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnThermalEventListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnThermalEventListener

}  // namespace os

}  // namespace android
