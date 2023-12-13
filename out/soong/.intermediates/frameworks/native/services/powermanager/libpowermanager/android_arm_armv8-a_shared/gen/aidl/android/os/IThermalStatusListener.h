#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace os {

class IThermalStatusListener : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(ThermalStatusListener)
  virtual ::android::binder::Status onStatusChange(int32_t status) = 0;
};  // class IThermalStatusListener

class IThermalStatusListenerDefault : public IThermalStatusListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onStatusChange(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IThermalStatusListenerDefault

}  // namespace os

}  // namespace android
