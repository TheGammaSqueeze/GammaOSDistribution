#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

namespace vibrator {

class IVibratorCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(VibratorCallback)
  const int32_t VERSION = 2;
  const std::string HASH = "ea8742d6993e1a82917da38b9938e537aa7fcb54";
  virtual ::android::binder::Status onComplete() = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IVibratorCallback

class IVibratorCallbackDefault : public IVibratorCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onComplete() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IVibratorCallbackDefault

}  // namespace vibrator

}  // namespace hardware

}  // namespace android
