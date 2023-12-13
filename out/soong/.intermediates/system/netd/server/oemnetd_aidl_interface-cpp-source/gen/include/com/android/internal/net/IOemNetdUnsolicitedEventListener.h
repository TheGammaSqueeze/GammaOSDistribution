#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace com {

namespace android {

namespace internal {

namespace net {

class IOemNetdUnsolicitedEventListener : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(OemNetdUnsolicitedEventListener)
  virtual ::android::binder::Status onRegistered() = 0;
};  // class IOemNetdUnsolicitedEventListener

class IOemNetdUnsolicitedEventListenerDefault : public IOemNetdUnsolicitedEventListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onRegistered() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IOemNetdUnsolicitedEventListenerDefault

}  // namespace net

}  // namespace internal

}  // namespace android

}  // namespace com
