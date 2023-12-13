#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/net/wifi/nl80211/IApInterface.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class BpApInterface : public ::android::BpInterface<IApInterface> {
public:
  explicit BpApInterface(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpApInterface() = default;
  ::android::binder::Status registerCallback(const ::android::sp<::android::net::wifi::nl80211::IApInterfaceEventCallback>& callback, bool* _aidl_return) override;
  ::android::binder::Status getInterfaceName(::std::string* _aidl_return) override;
};  // class BpApInterface

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
