#pragma once

#include <binder/IInterface.h>
#include <android/hardware/security/keymint/IRemotelyProvisionedComponent.h>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

class BnRemotelyProvisionedComponent : public ::android::BnInterface<IRemotelyProvisionedComponent> {
public:
  static constexpr uint32_t TRANSACTION_getHardwareInfo = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_generateEcdsaP256KeyPair = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_generateCertificateRequest = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_getInterfaceVersion = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777214;
  static constexpr uint32_t TRANSACTION_getInterfaceHash = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777213;
  explicit BnRemotelyProvisionedComponent();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
  int32_t getInterfaceVersion() final;
  std::string getInterfaceHash();
};  // class BnRemotelyProvisionedComponent

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
