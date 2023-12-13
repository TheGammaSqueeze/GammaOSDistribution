#pragma once

#include <binder/IInterface.h>
#include <android/os/IIncidentDumpCallback.h>

namespace android {

namespace os {

class BnIncidentDumpCallback : public ::android::BnInterface<IIncidentDumpCallback> {
public:
  static constexpr uint32_t TRANSACTION_onDumpSection = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnIncidentDumpCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnIncidentDumpCallback

}  // namespace os

}  // namespace android
