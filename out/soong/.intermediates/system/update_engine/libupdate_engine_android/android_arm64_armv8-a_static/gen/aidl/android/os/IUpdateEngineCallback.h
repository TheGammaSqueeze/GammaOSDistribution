#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace os {

class IUpdateEngineCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(UpdateEngineCallback)
  virtual ::android::binder::Status onStatusUpdate(int32_t status_code, float percentage) = 0;
  virtual ::android::binder::Status onPayloadApplicationComplete(int32_t error_code) = 0;
};  // class IUpdateEngineCallback

class IUpdateEngineCallbackDefault : public IUpdateEngineCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onStatusUpdate(int32_t, float) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onPayloadApplicationComplete(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IUpdateEngineCallbackDefault

}  // namespace os

}  // namespace android
