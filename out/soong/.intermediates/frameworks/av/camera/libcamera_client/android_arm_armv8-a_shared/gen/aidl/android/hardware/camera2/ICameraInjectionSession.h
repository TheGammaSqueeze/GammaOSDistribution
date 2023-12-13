#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

namespace camera2 {

class ICameraInjectionSession : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(CameraInjectionSession)
  virtual ::android::binder::Status stopInjection() = 0;
};  // class ICameraInjectionSession

class ICameraInjectionSessionDefault : public ICameraInjectionSession {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status stopInjection() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICameraInjectionSessionDefault

}  // namespace camera2

}  // namespace hardware

}  // namespace android
