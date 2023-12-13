#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/ISensorPrivacyManager.h>

namespace android {

namespace hardware {

class BpSensorPrivacyManager : public ::android::BpInterface<ISensorPrivacyManager> {
public:
  explicit BpSensorPrivacyManager(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpSensorPrivacyManager() = default;
  ::android::binder::Status supportsSensorToggle(int32_t sensor, bool* _aidl_return) override;
  ::android::binder::Status addSensorPrivacyListener(const ::android::sp<::android::hardware::ISensorPrivacyListener>& listener) override;
  ::android::binder::Status addIndividualSensorPrivacyListener(int32_t userId, int32_t sensor, const ::android::sp<::android::hardware::ISensorPrivacyListener>& listener) override;
  ::android::binder::Status removeSensorPrivacyListener(const ::android::sp<::android::hardware::ISensorPrivacyListener>& listener) override;
  ::android::binder::Status removeIndividualSensorPrivacyListener(int32_t sensor, const ::android::sp<::android::hardware::ISensorPrivacyListener>& listener) override;
  ::android::binder::Status isSensorPrivacyEnabled(bool* _aidl_return) override;
  ::android::binder::Status isIndividualSensorPrivacyEnabled(int32_t userId, int32_t sensor, bool* _aidl_return) override;
  ::android::binder::Status setSensorPrivacy(bool enable) override;
  ::android::binder::Status setIndividualSensorPrivacy(int32_t userId, int32_t source, int32_t sensor, bool enable) override;
  ::android::binder::Status setIndividualSensorPrivacyForProfileGroup(int32_t userId, int32_t source, int32_t sensor, bool enable) override;
};  // class BpSensorPrivacyManager

}  // namespace hardware

}  // namespace android
