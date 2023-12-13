#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/net/wifi/nl80211/IWificond.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class BpWificond : public ::android::BpInterface<IWificond> {
public:
  explicit BpWificond(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpWificond() = default;
  ::android::binder::Status createApInterface(const ::std::string& iface_name, ::android::sp<::android::net::wifi::nl80211::IApInterface>* _aidl_return) override;
  ::android::binder::Status createClientInterface(const ::std::string& iface_name, ::android::sp<::android::net::wifi::nl80211::IClientInterface>* _aidl_return) override;
  ::android::binder::Status tearDownApInterface(const ::std::string& iface_name, bool* _aidl_return) override;
  ::android::binder::Status tearDownClientInterface(const ::std::string& iface_name, bool* _aidl_return) override;
  ::android::binder::Status tearDownInterfaces() override;
  ::android::binder::Status GetClientInterfaces(::std::vector<::android::sp<::android::IBinder>>* _aidl_return) override;
  ::android::binder::Status GetApInterfaces(::std::vector<::android::sp<::android::IBinder>>* _aidl_return) override;
  ::android::binder::Status getAvailable2gChannels(::std::optional<::std::vector<int32_t>>* _aidl_return) override;
  ::android::binder::Status getAvailable5gNonDFSChannels(::std::optional<::std::vector<int32_t>>* _aidl_return) override;
  ::android::binder::Status getAvailableDFSChannels(::std::optional<::std::vector<int32_t>>* _aidl_return) override;
  ::android::binder::Status getAvailable6gChannels(::std::optional<::std::vector<int32_t>>* _aidl_return) override;
  ::android::binder::Status getAvailable60gChannels(::std::optional<::std::vector<int32_t>>* _aidl_return) override;
  ::android::binder::Status RegisterCallback(const ::android::sp<::android::net::wifi::nl80211::IInterfaceEventCallback>& callback) override;
  ::android::binder::Status UnregisterCallback(const ::android::sp<::android::net::wifi::nl80211::IInterfaceEventCallback>& callback) override;
  ::android::binder::Status registerWificondEventCallback(const ::android::sp<::android::net::wifi::nl80211::IWificondEventCallback>& callback) override;
  ::android::binder::Status unregisterWificondEventCallback(const ::android::sp<::android::net::wifi::nl80211::IWificondEventCallback>& callback) override;
  ::android::binder::Status getDeviceWiphyCapabilities(const ::std::string& iface_name, ::std::optional<::android::net::wifi::nl80211::DeviceWiphyCapabilities>* _aidl_return) override;
};  // class BpWificond

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
