#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <com/android/internal/net/IOemNetdUnsolicitedEventListener.h>
#include <utils/StrongPointer.h>

namespace com {

namespace android {

namespace internal {

namespace net {

class IOemNetd : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(OemNetd)
  virtual ::android::binder::Status isAlive(bool* _aidl_return) = 0;
  virtual ::android::binder::Status registerOemUnsolicitedEventListener(const ::android::sp<::com::android::internal::net::IOemNetdUnsolicitedEventListener>& listener) = 0;
};  // class IOemNetd

class IOemNetdDefault : public IOemNetd {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status isAlive(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status registerOemUnsolicitedEventListener(const ::android::sp<::com::android::internal::net::IOemNetdUnsolicitedEventListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IOemNetdDefault

}  // namespace net

}  // namespace internal

}  // namespace android

}  // namespace com
