#pragma once

#include <android/hardware/security/keymint/AttestationKey.h>
#include <android/hardware/security/keymint/BeginResult.h>
#include <android/hardware/security/keymint/HardwareAuthToken.h>
#include <android/hardware/security/keymint/KeyCharacteristics.h>
#include <android/hardware/security/keymint/KeyCreationResult.h>
#include <android/hardware/security/keymint/KeyFormat.h>
#include <android/hardware/security/keymint/KeyMintHardwareInfo.h>
#include <android/hardware/security/keymint/KeyParameter.h>
#include <android/hardware/security/keymint/KeyPurpose.h>
#include <android/hardware/security/secureclock/TimeStampToken.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

class IKeyMintDevice : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(KeyMintDevice)
  const int32_t VERSION = 1;
  const std::string HASH = "976674616001f714f4a4df49ee45f548de828524";
  enum  : int32_t {
    AUTH_TOKEN_MAC_LENGTH = 32,
  };
  virtual ::android::binder::Status getHardwareInfo(::android::hardware::security::keymint::KeyMintHardwareInfo* _aidl_return) = 0;
  virtual ::android::binder::Status addRngEntropy(const ::std::vector<uint8_t>& data) = 0;
  virtual ::android::binder::Status generateKey(const ::std::vector<::android::hardware::security::keymint::KeyParameter>& keyParams, const ::std::optional<::android::hardware::security::keymint::AttestationKey>& attestationKey, ::android::hardware::security::keymint::KeyCreationResult* _aidl_return) = 0;
  virtual ::android::binder::Status importKey(const ::std::vector<::android::hardware::security::keymint::KeyParameter>& keyParams, ::android::hardware::security::keymint::KeyFormat keyFormat, const ::std::vector<uint8_t>& keyData, const ::std::optional<::android::hardware::security::keymint::AttestationKey>& attestationKey, ::android::hardware::security::keymint::KeyCreationResult* _aidl_return) = 0;
  virtual ::android::binder::Status importWrappedKey(const ::std::vector<uint8_t>& wrappedKeyData, const ::std::vector<uint8_t>& wrappingKeyBlob, const ::std::vector<uint8_t>& maskingKey, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& unwrappingParams, int64_t passwordSid, int64_t biometricSid, ::android::hardware::security::keymint::KeyCreationResult* _aidl_return) = 0;
  virtual ::android::binder::Status upgradeKey(const ::std::vector<uint8_t>& keyBlobToUpgrade, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& upgradeParams, ::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status deleteKey(const ::std::vector<uint8_t>& keyBlob) = 0;
  virtual ::android::binder::Status deleteAllKeys() = 0;
  virtual ::android::binder::Status destroyAttestationIds() = 0;
  virtual ::android::binder::Status begin(::android::hardware::security::keymint::KeyPurpose purpose, const ::std::vector<uint8_t>& keyBlob, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& params, const ::std::optional<::android::hardware::security::keymint::HardwareAuthToken>& authToken, ::android::hardware::security::keymint::BeginResult* _aidl_return) = 0;
  virtual ::android::binder::Status deviceLocked(bool passwordOnly, const ::std::optional<::android::hardware::security::secureclock::TimeStampToken>& timestampToken) = 0;
  virtual ::android::binder::Status earlyBootEnded() = 0;
  virtual ::android::binder::Status convertStorageKeyToEphemeral(const ::std::vector<uint8_t>& storageKeyBlob, ::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status getKeyCharacteristics(const ::std::vector<uint8_t>& keyBlob, const ::std::vector<uint8_t>& appId, const ::std::vector<uint8_t>& appData, ::std::vector<::android::hardware::security::keymint::KeyCharacteristics>* _aidl_return) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IKeyMintDevice

class IKeyMintDeviceDefault : public IKeyMintDevice {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getHardwareInfo(::android::hardware::security::keymint::KeyMintHardwareInfo*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status addRngEntropy(const ::std::vector<uint8_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status generateKey(const ::std::vector<::android::hardware::security::keymint::KeyParameter>&, const ::std::optional<::android::hardware::security::keymint::AttestationKey>&, ::android::hardware::security::keymint::KeyCreationResult*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status importKey(const ::std::vector<::android::hardware::security::keymint::KeyParameter>&, ::android::hardware::security::keymint::KeyFormat, const ::std::vector<uint8_t>&, const ::std::optional<::android::hardware::security::keymint::AttestationKey>&, ::android::hardware::security::keymint::KeyCreationResult*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status importWrappedKey(const ::std::vector<uint8_t>&, const ::std::vector<uint8_t>&, const ::std::vector<uint8_t>&, const ::std::vector<::android::hardware::security::keymint::KeyParameter>&, int64_t, int64_t, ::android::hardware::security::keymint::KeyCreationResult*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status upgradeKey(const ::std::vector<uint8_t>&, const ::std::vector<::android::hardware::security::keymint::KeyParameter>&, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status deleteKey(const ::std::vector<uint8_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status deleteAllKeys() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status destroyAttestationIds() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status begin(::android::hardware::security::keymint::KeyPurpose, const ::std::vector<uint8_t>&, const ::std::vector<::android::hardware::security::keymint::KeyParameter>&, const ::std::optional<::android::hardware::security::keymint::HardwareAuthToken>&, ::android::hardware::security::keymint::BeginResult*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status deviceLocked(bool, const ::std::optional<::android::hardware::security::secureclock::TimeStampToken>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status earlyBootEnded() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status convertStorageKeyToEphemeral(const ::std::vector<uint8_t>&, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getKeyCharacteristics(const ::std::vector<uint8_t>&, const ::std::vector<uint8_t>&, const ::std::vector<uint8_t>&, ::std::vector<::android::hardware::security::keymint::KeyCharacteristics>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IKeyMintDeviceDefault

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
