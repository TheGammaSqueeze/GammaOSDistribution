#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

namespace camera2 {

class ICameraInjectionCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(CameraInjectionCallback)
  enum  : int32_t {
    ERROR_INJECTION_INVALID_ERROR = -1,
    ERROR_INJECTION_SESSION = 0,
    ERROR_INJECTION_SERVICE = 1,
    ERROR_INJECTION_UNSUPPORTED = 2,
  };
  virtual ::android::binder::Status onInjectionError(int32_t errorCode) = 0;
};  // class ICameraInjectionCallback

class ICameraInjectionCallbackDefault : public ICameraInjectionCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onInjectionError(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICameraInjectionCallbackDefault

}  // namespace camera2

}  // namespace hardware

}  // namespace android
