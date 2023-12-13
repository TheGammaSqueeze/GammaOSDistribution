#pragma once

#include <android/Temperature.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

namespace os {

class IThermalEventListener : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(ThermalEventListener)
  virtual ::android::binder::Status notifyThrottling(const ::android::os::Temperature& temperature) = 0;
};  // class IThermalEventListener

class IThermalEventListenerDefault : public IThermalEventListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status notifyThrottling(const ::android::os::Temperature&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IThermalEventListenerDefault

}  // namespace os

}  // namespace android
