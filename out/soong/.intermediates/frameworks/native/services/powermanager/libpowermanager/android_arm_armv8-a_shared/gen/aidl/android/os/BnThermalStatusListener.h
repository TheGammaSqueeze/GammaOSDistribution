#pragma once

#include <binder/IInterface.h>
#include <android/os/IThermalStatusListener.h>

namespace android {

namespace os {

class BnThermalStatusListener : public ::android::BnInterface<IThermalStatusListener> {
public:
  static constexpr uint32_t TRANSACTION_onStatusChange = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnThermalStatusListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnThermalStatusListener

}  // namespace os

}  // namespace android
