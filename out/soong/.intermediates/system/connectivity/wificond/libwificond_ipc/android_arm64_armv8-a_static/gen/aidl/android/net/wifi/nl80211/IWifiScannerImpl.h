#pragma once

#include <android/net/wifi/nl80211/IPnoScanEvent.h>
#include <android/net/wifi/nl80211/IScanEvent.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>
#include <vector>
#include <wificond/scanning/pno_settings.h>
#include <wificond/scanning/scan_result.h>
#include <wificond/scanning/single_scan_settings.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class IWifiScannerImpl : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(WifiScannerImpl)
  enum  : int32_t {
    SCAN_TYPE_LOW_SPAN = 0,
    SCAN_TYPE_LOW_POWER = 1,
    SCAN_TYPE_HIGH_ACCURACY = 2,
    SCAN_TYPE_DEFAULT = -1,
  };
  virtual ::android::binder::Status getScanResults(::std::vector<::android::net::wifi::nl80211::NativeScanResult>* _aidl_return) = 0;
  virtual ::android::binder::Status getPnoScanResults(::std::vector<::android::net::wifi::nl80211::NativeScanResult>* _aidl_return) = 0;
  virtual ::android::binder::Status scan(const ::android::net::wifi::nl80211::SingleScanSettings& scanSettings, bool* _aidl_return) = 0;
  virtual ::android::binder::Status subscribeScanEvents(const ::android::sp<::android::net::wifi::nl80211::IScanEvent>& handler) = 0;
  virtual ::android::binder::Status unsubscribeScanEvents() = 0;
  virtual ::android::binder::Status subscribePnoScanEvents(const ::android::sp<::android::net::wifi::nl80211::IPnoScanEvent>& handler) = 0;
  virtual ::android::binder::Status unsubscribePnoScanEvents() = 0;
  virtual ::android::binder::Status startPnoScan(const ::android::net::wifi::nl80211::PnoSettings& pnoSettings, bool* _aidl_return) = 0;
  virtual ::android::binder::Status stopPnoScan(bool* _aidl_return) = 0;
  virtual ::android::binder::Status abortScan() = 0;
};  // class IWifiScannerImpl

class IWifiScannerImplDefault : public IWifiScannerImpl {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getScanResults(::std::vector<::android::net::wifi::nl80211::NativeScanResult>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getPnoScanResults(::std::vector<::android::net::wifi::nl80211::NativeScanResult>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status scan(const ::android::net::wifi::nl80211::SingleScanSettings&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status subscribeScanEvents(const ::android::sp<::android::net::wifi::nl80211::IScanEvent>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unsubscribeScanEvents() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status subscribePnoScanEvents(const ::android::sp<::android::net::wifi::nl80211::IPnoScanEvent>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unsubscribePnoScanEvents() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status startPnoScan(const ::android::net::wifi::nl80211::PnoSettings&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status stopPnoScan(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status abortScan() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IWifiScannerImplDefault

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
