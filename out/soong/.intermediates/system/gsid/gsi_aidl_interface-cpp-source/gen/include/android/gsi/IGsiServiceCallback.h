#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace gsi {

class IGsiServiceCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(GsiServiceCallback)
  virtual ::android::binder::Status onResult(int32_t result) = 0;
};  // class IGsiServiceCallback

class IGsiServiceCallbackDefault : public IGsiServiceCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onResult(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IGsiServiceCallbackDefault

}  // namespace gsi

}  // namespace android
