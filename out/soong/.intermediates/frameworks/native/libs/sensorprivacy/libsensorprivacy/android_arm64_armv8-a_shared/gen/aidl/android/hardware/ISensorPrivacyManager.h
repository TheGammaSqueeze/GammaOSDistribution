#pragma once

#include <android/hardware/ISensorPrivacyListener.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

class ISensorPrivacyManager : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(SensorPrivacyManager)
  virtual ::android::binder::Status supportsSensorToggle(int32_t sensor, bool* _aidl_return) = 0;
  virtual ::android::binder::Status addSensorPrivacyListener(const ::android::sp<::android::hardware::ISensorPrivacyListener>& listener) = 0;
  virtual ::android::binder::Status addIndividualSensorPrivacyListener(int32_t userId, int32_t sensor, const ::android::sp<::android::hardware::ISensorPrivacyListener>& listener) = 0;
  virtual ::android::binder::Status removeSensorPrivacyListener(const ::android::sp<::android::hardware::ISensorPrivacyListener>& listener) = 0;
  virtual ::android::binder::Status removeIndividualSensorPrivacyListener(int32_t sensor, const ::android::sp<::android::hardware::ISensorPrivacyListener>& listener) = 0;
  virtual ::android::binder::Status isSensorPrivacyEnabled(bool* _aidl_return) = 0;
  virtual ::android::binder::Status isIndividualSensorPrivacyEnabled(int32_t userId, int32_t sensor, bool* _aidl_return) = 0;
  virtual ::android::binder::Status setSensorPrivacy(bool enable) = 0;
  virtual ::android::binder::Status setIndividualSensorPrivacy(int32_t userId, int32_t source, int32_t sensor, bool enable) = 0;
  virtual ::android::binder::Status setIndividualSensorPrivacyForProfileGroup(int32_t userId, int32_t source, int32_t sensor, bool enable) = 0;
};  // class ISensorPrivacyManager

class ISensorPrivacyManagerDefault : public ISensorPrivacyManager {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status supportsSensorToggle(int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status addSensorPrivacyListener(const ::android::sp<::android::hardware::ISensorPrivacyListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status addIndividualSensorPrivacyListener(int32_t, int32_t, const ::android::sp<::android::hardware::ISensorPrivacyListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status removeSensorPrivacyListener(const ::android::sp<::android::hardware::ISensorPrivacyListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status removeIndividualSensorPrivacyListener(int32_t, const ::android::sp<::android::hardware::ISensorPrivacyListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isSensorPrivacyEnabled(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isIndividualSensorPrivacyEnabled(int32_t, int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setSensorPrivacy(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setIndividualSensorPrivacy(int32_t, int32_t, int32_t, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setIndividualSensorPrivacyForProfileGroup(int32_t, int32_t, int32_t, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ISensorPrivacyManagerDefault

}  // namespace hardware

}  // namespace android
