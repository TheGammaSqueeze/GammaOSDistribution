#pragma once

#include <android/hardware/power/WorkDuration.h>
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

class IPowerHintSession : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(PowerHintSession)
  const int32_t VERSION = 2;
  const std::string HASH = "ef4f5ed58e39693f25c1f8fdcfe7b958c6b800bc";
  virtual ::android::binder::Status updateTargetWorkDuration(int64_t targetDurationNanos) = 0;
  virtual ::android::binder::Status reportActualWorkDuration(const ::std::vector<::android::hardware::power::WorkDuration>& durations) = 0;
  virtual ::android::binder::Status pause() = 0;
  virtual ::android::binder::Status resume() = 0;
  virtual ::android::binder::Status close() = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IPowerHintSession

class IPowerHintSessionDefault : public IPowerHintSession {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status updateTargetWorkDuration(int64_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status reportActualWorkDuration(const ::std::vector<::android::hardware::power::WorkDuration>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status pause() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status resume() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status close() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IPowerHintSessionDefault

}  // namespace power

}  // namespace hardware

}  // namespace android
