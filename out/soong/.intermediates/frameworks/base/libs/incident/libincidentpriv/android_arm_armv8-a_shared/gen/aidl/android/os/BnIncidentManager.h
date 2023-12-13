#pragma once

#include <binder/IInterface.h>
#include <android/os/IIncidentManager.h>

namespace android {

namespace os {

class BnIncidentManager : public ::android::BnInterface<IIncidentManager> {
public:
  static constexpr uint32_t TRANSACTION_reportIncident = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_reportIncidentToStream = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_reportIncidentToDumpstate = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_registerSection = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_unregisterSection = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_systemRunning = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_getIncidentReportList = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_getIncidentReport = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_deleteIncidentReports = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_deleteAllIncidentReports = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  explicit BnIncidentManager();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnIncidentManager

}  // namespace os

}  // namespace android
