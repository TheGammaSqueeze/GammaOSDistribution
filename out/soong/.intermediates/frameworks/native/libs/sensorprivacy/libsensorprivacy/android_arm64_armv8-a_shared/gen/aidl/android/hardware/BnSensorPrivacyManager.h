#pragma once

#include <binder/IInterface.h>
#include <android/hardware/ISensorPrivacyManager.h>

namespace android {

namespace hardware {

class BnSensorPrivacyManager : public ::android::BnInterface<ISensorPrivacyManager> {
public:
  static constexpr uint32_t TRANSACTION_supportsSensorToggle = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_addSensorPrivacyListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_addIndividualSensorPrivacyListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_removeSensorPrivacyListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_removeIndividualSensorPrivacyListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_isSensorPrivacyEnabled = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_isIndividualSensorPrivacyEnabled = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_setSensorPrivacy = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_setIndividualSensorPrivacy = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_setIndividualSensorPrivacyForProfileGroup = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  explicit BnSensorPrivacyManager();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnSensorPrivacyManager

}  // namespace hardware

}  // namespace android
