#pragma once

#include <binder/IInterface.h>
#include <android/os/IIncidentAuthListener.h>

namespace android {

namespace os {

class BnIncidentAuthListener : public ::android::BnInterface<IIncidentAuthListener> {
public:
  static constexpr uint32_t TRANSACTION_onReportApproved = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onReportDenied = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnIncidentAuthListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnIncidentAuthListener

}  // namespace os

}  // namespace android
