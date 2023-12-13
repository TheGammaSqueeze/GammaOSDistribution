#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/net/wifi/nl80211/IClientInterface.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class BpClientInterface : public ::android::BpInterface<IClientInterface> {
public:
  explicit BpClientInterface(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpClientInterface() = default;
  ::android::binder::Status getPacketCounters(::std::vector<int32_t>* _aidl_return) override;
  ::android::binder::Status signalPoll(::std::vector<int32_t>* _aidl_return) override;
  ::android::binder::Status getMacAddress(::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status getInterfaceName(::std::string* _aidl_return) override;
  ::android::binder::Status getWifiScannerImpl(::android::sp<::android::net::wifi::nl80211::IWifiScannerImpl>* _aidl_return) override;
  ::android::binder::Status SendMgmtFrame(const ::std::vector<uint8_t>& frame, const ::android::sp<::android::net::wifi::nl80211::ISendMgmtFrameEvent>& callback, int32_t mcs) override;
};  // class BpClientInterface

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
