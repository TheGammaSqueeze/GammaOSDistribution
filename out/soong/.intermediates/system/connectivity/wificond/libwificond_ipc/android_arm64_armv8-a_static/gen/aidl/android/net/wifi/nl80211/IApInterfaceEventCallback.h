#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <wificond/client/native_wifi_client.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class IApInterfaceEventCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(ApInterfaceEventCallback)
  enum  : int32_t {
    BANDWIDTH_INVALID = 0,
    BANDWIDTH_20_NOHT = 1,
    BANDWIDTH_20 = 2,
    BANDWIDTH_40 = 3,
    BANDWIDTH_80 = 4,
    BANDWIDTH_80P80 = 5,
    BANDWIDTH_160 = 6,
  };
  virtual ::android::binder::Status onConnectedClientsChanged(const ::android::net::wifi::nl80211::NativeWifiClient& client, bool isConnected) = 0;
  virtual ::android::binder::Status onSoftApChannelSwitched(int32_t frequency, int32_t bandwidth) = 0;
};  // class IApInterfaceEventCallback

class IApInterfaceEventCallbackDefault : public IApInterfaceEventCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onConnectedClientsChanged(const ::android::net::wifi::nl80211::NativeWifiClient&, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onSoftApChannelSwitched(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IApInterfaceEventCallbackDefault

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
