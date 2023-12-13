#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/net/wifi/nl80211/IWifiScannerImpl.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class BpWifiScannerImpl : public ::android::BpInterface<IWifiScannerImpl> {
public:
  explicit BpWifiScannerImpl(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpWifiScannerImpl() = default;
  ::android::binder::Status getScanResults(::std::vector<::android::net::wifi::nl80211::NativeScanResult>* _aidl_return) override;
  ::android::binder::Status getPnoScanResults(::std::vector<::android::net::wifi::nl80211::NativeScanResult>* _aidl_return) override;
  ::android::binder::Status scan(const ::android::net::wifi::nl80211::SingleScanSettings& scanSettings, bool* _aidl_return) override;
  ::android::binder::Status subscribeScanEvents(const ::android::sp<::android::net::wifi::nl80211::IScanEvent>& handler) override;
  ::android::binder::Status unsubscribeScanEvents() override;
  ::android::binder::Status subscribePnoScanEvents(const ::android::sp<::android::net::wifi::nl80211::IPnoScanEvent>& handler) override;
  ::android::binder::Status unsubscribePnoScanEvents() override;
  ::android::binder::Status startPnoScan(const ::android::net::wifi::nl80211::PnoSettings& pnoSettings, bool* _aidl_return) override;
  ::android::binder::Status stopPnoScan(bool* _aidl_return) override;
  ::android::binder::Status abortScan() override;
};  // class BpWifiScannerImpl

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
