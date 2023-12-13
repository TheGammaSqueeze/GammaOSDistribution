#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/net/wifi/nl80211/IWificondEventCallback.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class BpWificondEventCallback : public ::android::BpInterface<IWificondEventCallback> {
public:
  explicit BpWificondEventCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpWificondEventCallback() = default;
  ::android::binder::Status OnRegDomainChanged(const ::std::string& countryCode) override;
};  // class BpWificondEventCallback

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
