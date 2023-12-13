#pragma once

#include <android/hardware/vibrator/IVibrator.h>
#include <android/hardware/vibrator/IVibratorCallback.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace hardware {

namespace vibrator {

class IVibratorManager : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(VibratorManager)
  const int32_t VERSION = 2;
  const std::string HASH = "ea8742d6993e1a82917da38b9938e537aa7fcb54";
  enum  : int32_t {
    CAP_SYNC = 1,
    CAP_PREPARE_ON = 2,
    CAP_PREPARE_PERFORM = 4,
    CAP_PREPARE_COMPOSE = 8,
    CAP_MIXED_TRIGGER_ON = 16,
    CAP_MIXED_TRIGGER_PERFORM = 32,
    CAP_MIXED_TRIGGER_COMPOSE = 64,
    CAP_TRIGGER_CALLBACK = 128,
  };
  virtual ::android::binder::Status getCapabilities(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getVibratorIds(::std::vector<int32_t>* _aidl_return) = 0;
  virtual ::android::binder::Status getVibrator(int32_t vibratorId, ::android::sp<::android::hardware::vibrator::IVibrator>* _aidl_return) = 0;
  virtual ::android::binder::Status prepareSynced(const ::std::vector<int32_t>& vibratorIds) = 0;
  virtual ::android::binder::Status triggerSynced(const ::android::sp<::android::hardware::vibrator::IVibratorCallback>& callback) = 0;
  virtual ::android::binder::Status cancelSynced() = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IVibratorManager

class IVibratorManagerDefault : public IVibratorManager {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getCapabilities(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getVibratorIds(::std::vector<int32_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getVibrator(int32_t, ::android::sp<::android::hardware::vibrator::IVibrator>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status prepareSynced(const ::std::vector<int32_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status triggerSynced(const ::android::sp<::android::hardware::vibrator::IVibratorCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status cancelSynced() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IVibratorManagerDefault

}  // namespace vibrator

}  // namespace hardware

}  // namespace android
