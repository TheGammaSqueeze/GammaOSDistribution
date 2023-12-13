#pragma once

#include <android/hardware/security/keymint/DeviceInfo.h>
#include <android/hardware/security/keymint/MacedPublicKey.h>
#include <android/hardware/security/keymint/ProtectedData.h>
#include <android/hardware/security/keymint/RpcHardwareInfo.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

class IRemotelyProvisionedComponent : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(RemotelyProvisionedComponent)
  const int32_t VERSION = 1;
  const std::string HASH = "976674616001f714f4a4df49ee45f548de828524";
  enum  : int32_t {
    STATUS_FAILED = 1,
    STATUS_INVALID_MAC = 2,
    STATUS_PRODUCTION_KEY_IN_TEST_REQUEST = 3,
    STATUS_TEST_KEY_IN_PRODUCTION_REQUEST = 4,
    STATUS_INVALID_EEK = 5,
  };
  virtual ::android::binder::Status getHardwareInfo(::android::hardware::security::keymint::RpcHardwareInfo* _aidl_return) = 0;
  virtual ::android::binder::Status generateEcdsaP256KeyPair(bool testMode, ::android::hardware::security::keymint::MacedPublicKey* macedPublicKey, ::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status generateCertificateRequest(bool testMode, const ::std::vector<::android::hardware::security::keymint::MacedPublicKey>& keysToSign, const ::std::vector<uint8_t>& endpointEncryptionCertChain, const ::std::vector<uint8_t>& challenge, ::android::hardware::security::keymint::DeviceInfo* deviceInfo, ::android::hardware::security::keymint::ProtectedData* protectedData, ::std::vector<uint8_t>* _aidl_return) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IRemotelyProvisionedComponent

class IRemotelyProvisionedComponentDefault : public IRemotelyProvisionedComponent {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getHardwareInfo(::android::hardware::security::keymint::RpcHardwareInfo*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status generateEcdsaP256KeyPair(bool, ::android::hardware::security::keymint::MacedPublicKey*, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status generateCertificateRequest(bool, const ::std::vector<::android::hardware::security::keymint::MacedPublicKey>&, const ::std::vector<uint8_t>&, const ::std::vector<uint8_t>&, ::android::hardware::security::keymint::DeviceInfo*, ::android::hardware::security::keymint::ProtectedData*, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IRemotelyProvisionedComponentDefault

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
