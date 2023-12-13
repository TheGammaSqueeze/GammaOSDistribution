#pragma once

#include <android/hardware/power/Boost.h>
#include <android/hardware/power/Mode.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

namespace power {

class IPower : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Power)
  const int32_t VERSION = 1;
  const std::string HASH = "d5bbe80a8c4df49931e8453f3138820e82dc525c";
  virtual ::android::binder::Status setMode(::android::hardware::power::Mode type, bool enabled) = 0;
  virtual ::android::binder::Status isModeSupported(::android::hardware::power::Mode type, bool* _aidl_return) = 0;
  virtual ::android::binder::Status setBoost(::android::hardware::power::Boost type, int32_t durationMs) = 0;
  virtual ::android::binder::Status isBoostSupported(::android::hardware::power::Boost type, bool* _aidl_return) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IPower

class IPowerDefault : public IPower {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status setMode(::android::hardware::power::Mode, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isModeSupported(::android::hardware::power::Mode, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setBoost(::android::hardware::power::Boost, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isBoostSupported(::android::hardware::power::Boost, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IPowerDefault

}  // namespace power

}  // namespace hardware

}  // namespace android
