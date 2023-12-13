#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <string>
#include <utils/StrongPointer.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class IWificondEventCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(WificondEventCallback)
  virtual ::android::binder::Status OnRegDomainChanged(const ::std::string& countryCode) = 0;
};  // class IWificondEventCallback

class IWificondEventCallbackDefault : public IWificondEventCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status OnRegDomainChanged(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IWificondEventCallbackDefault

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
