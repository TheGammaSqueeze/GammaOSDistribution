#pragma once

#include <android/hardware/power/Boost.h>
#include <android/hardware/power/IPowerHintSession.h>
#include <android/hardware/power/Mode.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace hardware {

namespace power {

class IPower : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Power)
  const int32_t VERSION = 2;
  const std::string HASH = "ef4f5ed58e39693f25c1f8fdcfe7b958c6b800bc";
  virtual ::android::binder::Status setMode(::android::hardware::power::Mode type, bool enabled) = 0;
  virtual ::android::binder::Status isModeSupported(::android::hardware::power::Mode type, bool* _aidl_return) = 0;
  virtual ::android::binder::Status setBoost(::android::hardware::power::Boost type, int32_t durationMs) = 0;
  virtual ::android::binder::Status isBoostSupported(::android::hardware::power::Boost type, bool* _aidl_return) = 0;
  virtual ::android::binder::Status createHintSession(int32_t tgid, int32_t uid, const ::std::vector<int32_t>& threadIds, int64_t durationNanos, ::android::sp<::android::hardware::power::IPowerHintSession>* _aidl_return) = 0;
  virtual ::android::binder::Status getHintSessionPreferredRate(int64_t* _aidl_return) = 0;
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
  ::android::binder::Status createHintSession(int32_t, int32_t, const ::std::vector<int32_t>&, int64_t, ::android::sp<::android::hardware::power::IPowerHintSession>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getHintSessionPreferredRate(int64_t*) override {
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
