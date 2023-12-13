#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/net/wifi/nl80211/IInterfaceEventCallback.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class BpInterfaceEventCallback : public ::android::BpInterface<IInterfaceEventCallback> {
public:
  explicit BpInterfaceEventCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpInterfaceEventCallback() = default;
  ::android::binder::Status OnClientInterfaceReady(const ::android::sp<::android::net::wifi::nl80211::IClientInterface>& network_interface) override;
  ::android::binder::Status OnApInterfaceReady(const ::android::sp<::android::net::wifi::nl80211::IApInterface>& network_interface) override;
  ::android::binder::Status OnClientTorndownEvent(const ::android::sp<::android::net::wifi::nl80211::IClientInterface>& network_interface) override;
  ::android::binder::Status OnApTorndownEvent(const ::android::sp<::android::net::wifi::nl80211::IApInterface>& network_interface) override;
};  // class BpInterfaceEventCallback

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
