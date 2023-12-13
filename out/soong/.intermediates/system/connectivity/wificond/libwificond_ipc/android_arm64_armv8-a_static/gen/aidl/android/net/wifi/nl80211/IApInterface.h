#pragma once

#include <android/net/wifi/nl80211/IApInterfaceEventCallback.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <string>
#include <utils/StrongPointer.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class IApInterface : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(ApInterface)
  enum  : int32_t {
    ENCRYPTION_TYPE_NONE = 0,
    ENCRYPTION_TYPE_WPA = 1,
    ENCRYPTION_TYPE_WPA2 = 2,
  };
  virtual ::android::binder::Status registerCallback(const ::android::sp<::android::net::wifi::nl80211::IApInterfaceEventCallback>& callback, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getInterfaceName(::std::string* _aidl_return) = 0;
};  // class IApInterface

class IApInterfaceDefault : public IApInterface {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status registerCallback(const ::android::sp<::android::net::wifi::nl80211::IApInterfaceEventCallback>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getInterfaceName(::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IApInterfaceDefault

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
