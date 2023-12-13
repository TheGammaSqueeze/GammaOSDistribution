#pragma once

#include <android/net/wifi/nl80211/IApInterface.h>
#include <android/net/wifi/nl80211/IClientInterface.h>
#include <android/net/wifi/nl80211/IInterfaceEventCallback.h>
#include <android/net/wifi/nl80211/IWificondEventCallback.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <string>
#include <utils/StrongPointer.h>
#include <vector>
#include <wificond/device_wiphy_capabilities.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class IWificond : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Wificond)
  virtual ::android::binder::Status createApInterface(const ::std::string& iface_name, ::android::sp<::android::net::wifi::nl80211::IApInterface>* _aidl_return) = 0;
  virtual ::android::binder::Status createClientInterface(const ::std::string& iface_name, ::android::sp<::android::net::wifi::nl80211::IClientInterface>* _aidl_return) = 0;
  virtual ::android::binder::Status tearDownApInterface(const ::std::string& iface_name, bool* _aidl_return) = 0;
  virtual ::android::binder::Status tearDownClientInterface(const ::std::string& iface_name, bool* _aidl_return) = 0;
  virtual ::android::binder::Status tearDownInterfaces() = 0;
  virtual ::android::binder::Status GetClientInterfaces(::std::vector<::android::sp<::android::IBinder>>* _aidl_return) = 0;
  virtual ::android::binder::Status GetApInterfaces(::std::vector<::android::sp<::android::IBinder>>* _aidl_return) = 0;
  virtual ::android::binder::Status getAvailable2gChannels(::std::optional<::std::vector<int32_t>>* _aidl_return) = 0;
  virtual ::android::binder::Status getAvailable5gNonDFSChannels(::std::optional<::std::vector<int32_t>>* _aidl_return) = 0;
  virtual ::android::binder::Status getAvailableDFSChannels(::std::optional<::std::vector<int32_t>>* _aidl_return) = 0;
  virtual ::android::binder::Status getAvailable6gChannels(::std::optional<::std::vector<int32_t>>* _aidl_return) = 0;
  virtual ::android::binder::Status getAvailable60gChannels(::std::optional<::std::vector<int32_t>>* _aidl_return) = 0;
  virtual ::android::binder::Status RegisterCallback(const ::android::sp<::android::net::wifi::nl80211::IInterfaceEventCallback>& callback) = 0;
  virtual ::android::binder::Status UnregisterCallback(const ::android::sp<::android::net::wifi::nl80211::IInterfaceEventCallback>& callback) = 0;
  virtual ::android::binder::Status registerWificondEventCallback(const ::android::sp<::android::net::wifi::nl80211::IWificondEventCallback>& callback) = 0;
  virtual ::android::binder::Status unregisterWificondEventCallback(const ::android::sp<::android::net::wifi::nl80211::IWificondEventCallback>& callback) = 0;
  virtual ::android::binder::Status getDeviceWiphyCapabilities(const ::std::string& iface_name, ::std::optional<::android::net::wifi::nl80211::DeviceWiphyCapabilities>* _aidl_return) = 0;
};  // class IWificond

class IWificondDefault : public IWificond {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status createApInterface(const ::std::string&, ::android::sp<::android::net::wifi::nl80211::IApInterface>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createClientInterface(const ::std::string&, ::android::sp<::android::net::wifi::nl80211::IClientInterface>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tearDownApInterface(const ::std::string&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tearDownClientInterface(const ::std::string&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tearDownInterfaces() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status GetClientInterfaces(::std::vector<::android::sp<::android::IBinder>>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status GetApInterfaces(::std::vector<::android::sp<::android::IBinder>>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getAvailable2gChannels(::std::optional<::std::vector<int32_t>>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getAvailable5gNonDFSChannels(::std::optional<::std::vector<int32_t>>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getAvailableDFSChannels(::std::optional<::std::vector<int32_t>>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getAvailable6gChannels(::std::optional<::std::vector<int32_t>>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getAvailable60gChannels(::std::optional<::std::vector<int32_t>>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status RegisterCallback(const ::android::sp<::android::net::wifi::nl80211::IInterfaceEventCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status UnregisterCallback(const ::android::sp<::android::net::wifi::nl80211::IInterfaceEventCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status registerWificondEventCallback(const ::android::sp<::android::net::wifi::nl80211::IWificondEventCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unregisterWificondEventCallback(const ::android::sp<::android::net::wifi::nl80211::IWificondEventCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getDeviceWiphyCapabilities(const ::std::string&, ::std::optional<::android::net::wifi::nl80211::DeviceWiphyCapabilities>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IWificondDefault

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
