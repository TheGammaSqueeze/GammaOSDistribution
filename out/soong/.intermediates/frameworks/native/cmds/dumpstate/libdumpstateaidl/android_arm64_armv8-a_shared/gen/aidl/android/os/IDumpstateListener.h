#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace os {

class IDumpstateListener : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(DumpstateListener)
  enum  : int32_t {
    BUGREPORT_ERROR_INVALID_INPUT = 1,
    BUGREPORT_ERROR_RUNTIME_ERROR = 2,
    BUGREPORT_ERROR_USER_DENIED_CONSENT = 3,
    BUGREPORT_ERROR_USER_CONSENT_TIMED_OUT = 4,
    BUGREPORT_ERROR_ANOTHER_REPORT_IN_PROGRESS = 5,
  };
  virtual ::android::binder::Status onProgress(int32_t progress) = 0;
  virtual ::android::binder::Status onError(int32_t errorCode) = 0;
  virtual ::android::binder::Status onFinished() = 0;
  virtual ::android::binder::Status onScreenshotTaken(bool success) = 0;
  virtual ::android::binder::Status onUiIntensiveBugreportDumpsFinished() = 0;
};  // class IDumpstateListener

class IDumpstateListenerDefault : public IDumpstateListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onProgress(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onError(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onFinished() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onScreenshotTaken(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onUiIntensiveBugreportDumpsFinished() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IDumpstateListenerDefault

}  // namespace os

}  // namespace android
