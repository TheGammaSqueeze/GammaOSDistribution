#pragma once

#include <android/net/wifi/nl80211/IApInterface.h>
#include <android/net/wifi/nl80211/IClientInterface.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class IInterfaceEventCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(InterfaceEventCallback)
  virtual ::android::binder::Status OnClientInterfaceReady(const ::android::sp<::android::net::wifi::nl80211::IClientInterface>& network_interface) = 0;
  virtual ::android::binder::Status OnApInterfaceReady(const ::android::sp<::android::net::wifi::nl80211::IApInterface>& network_interface) = 0;
  virtual ::android::binder::Status OnClientTorndownEvent(const ::android::sp<::android::net::wifi::nl80211::IClientInterface>& network_interface) = 0;
  virtual ::android::binder::Status OnApTorndownEvent(const ::android::sp<::android::net::wifi::nl80211::IApInterface>& network_interface) = 0;
};  // class IInterfaceEventCallback

class IInterfaceEventCallbackDefault : public IInterfaceEventCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status OnClientInterfaceReady(const ::android::sp<::android::net::wifi::nl80211::IClientInterface>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnApInterfaceReady(const ::android::sp<::android::net::wifi::nl80211::IApInterface>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnClientTorndownEvent(const ::android::sp<::android::net::wifi::nl80211::IClientInterface>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnApTorndownEvent(const ::android::sp<::android::net::wifi::nl80211::IApInterface>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IInterfaceEventCallbackDefault

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
