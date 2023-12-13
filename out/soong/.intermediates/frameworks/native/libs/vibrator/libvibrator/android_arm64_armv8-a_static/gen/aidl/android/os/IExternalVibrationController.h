#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

namespace os {

class IExternalVibrationController : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(ExternalVibrationController)
  virtual ::android::binder::Status mute(bool* _aidl_return) = 0;
  virtual ::android::binder::Status unmute(bool* _aidl_return) = 0;
};  // class IExternalVibrationController

class IExternalVibrationControllerDefault : public IExternalVibrationController {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status mute(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unmute(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IExternalVibrationControllerDefault

}  // namespace os

}  // namespace android
