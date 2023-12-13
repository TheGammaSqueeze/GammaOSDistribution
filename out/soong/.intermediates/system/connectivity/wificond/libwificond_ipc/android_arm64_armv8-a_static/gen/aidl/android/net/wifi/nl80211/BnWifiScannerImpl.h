#pragma once

#include <binder/IInterface.h>
#include <android/net/wifi/nl80211/IWifiScannerImpl.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class BnWifiScannerImpl : public ::android::BnInterface<IWifiScannerImpl> {
public:
  static constexpr uint32_t TRANSACTION_getScanResults = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getPnoScanResults = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_scan = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_subscribeScanEvents = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_unsubscribeScanEvents = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_subscribePnoScanEvents = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_unsubscribePnoScanEvents = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_startPnoScan = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_stopPnoScan = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_abortScan = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  explicit BnWifiScannerImpl();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnWifiScannerImpl

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
