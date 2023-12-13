#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace os {

class IUpdateEngineStableCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(UpdateEngineStableCallback)
  const int32_t VERSION = 1;
  const std::string HASH = "526043ea6cb098d53a9c3e778420e64c4e864d8c";
  virtual ::android::binder::Status onStatusUpdate(int32_t status_code, float percentage) = 0;
  virtual ::android::binder::Status onPayloadApplicationComplete(int32_t error_code) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IUpdateEngineStableCallback

class IUpdateEngineStableCallbackDefault : public IUpdateEngineStableCallback {
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
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IUpdateEngineStableCallbackDefault

}  // namespace os

}  // namespace android
