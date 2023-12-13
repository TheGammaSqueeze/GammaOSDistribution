#pragma once

#include <android/net/wifi/nl80211/ISendMgmtFrameEvent.h>
#include <android/net/wifi/nl80211/IWifiScannerImpl.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <string>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class IClientInterface : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(ClientInterface)
  virtual ::android::binder::Status getPacketCounters(::std::vector<int32_t>* _aidl_return) = 0;
  virtual ::android::binder::Status signalPoll(::std::vector<int32_t>* _aidl_return) = 0;
  virtual ::android::binder::Status getMacAddress(::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status getInterfaceName(::std::string* _aidl_return) = 0;
  virtual ::android::binder::Status getWifiScannerImpl(::android::sp<::android::net::wifi::nl80211::IWifiScannerImpl>* _aidl_return) = 0;
  virtual ::android::binder::Status SendMgmtFrame(const ::std::vector<uint8_t>& frame, const ::android::sp<::android::net::wifi::nl80211::ISendMgmtFrameEvent>& callback, int32_t mcs) = 0;
};  // class IClientInterface

class IClientInterfaceDefault : public IClientInterface {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getPacketCounters(::std::vector<int32_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status signalPoll(::std::vector<int32_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getMacAddress(::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getInterfaceName(::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getWifiScannerImpl(::android::sp<::android::net::wifi::nl80211::IWifiScannerImpl>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status SendMgmtFrame(const ::std::vector<uint8_t>&, const ::android::sp<::android::net::wifi::nl80211::ISendMgmtFrameEvent>&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IClientInterfaceDefault

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
