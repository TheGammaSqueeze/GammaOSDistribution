#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/net/wifi/nl80211/IApInterfaceEventCallback.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class BpApInterfaceEventCallback : public ::android::BpInterface<IApInterfaceEventCallback> {
public:
  explicit BpApInterfaceEventCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpApInterfaceEventCallback() = default;
  ::android::binder::Status onConnectedClientsChanged(const ::android::net::wifi::nl80211::NativeWifiClient& client, bool isConnected) override;
  ::android::binder::Status onSoftApChannelSwitched(int32_t frequency, int32_t bandwidth) override;
};  // class BpApInterfaceEventCallback

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
