#pragma once

#include <binder/IInterface.h>
#include <android/os/IIncidentReportStatusListener.h>

namespace android {

namespace os {

class BnIncidentReportStatusListener : public ::android::BnInterface<IIncidentReportStatusListener> {
public:
  static constexpr uint32_t TRANSACTION_onReportStarted = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onReportSectionStatus = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onReportFinished = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_onReportFailed = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  explicit BnIncidentReportStatusListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnIncidentReportStatusListener

}  // namespace os

}  // namespace android
