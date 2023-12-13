#pragma once

#include <android/hardware/security/keymint/KeyParameter.h>
#include <android/system/keystore2/AuthenticatorSpec.h>
#include <android/system/keystore2/CreateOperationResponse.h>
#include <android/system/keystore2/EphemeralStorageKeyResponse.h>
#include <android/system/keystore2/KeyDescriptor.h>
#include <android/system/keystore2/KeyMetadata.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace system {

namespace keystore2 {

class IKeystoreSecurityLevel : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(KeystoreSecurityLevel)
  const int32_t VERSION = 1;
  const std::string HASH = "19e8b65277839bad0ab335c781e3c652324920ce";
  enum  : int32_t {
    KEY_FLAG_AUTH_BOUND_WITHOUT_CRYPTOGRAPHIC_LSKF_BINDING = 1,
  };
  virtual ::android::binder::Status createOperation(const ::android::system::keystore2::KeyDescriptor& key, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& operationParameters, bool forced, ::android::system::keystore2::CreateOperationResponse* _aidl_return) = 0;
  virtual ::android::binder::Status generateKey(const ::android::system::keystore2::KeyDescriptor& key, const ::std::optional<::android::system::keystore2::KeyDescriptor>& attestationKey, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& params, int32_t flags, const ::std::vector<uint8_t>& entropy, ::android::system::keystore2::KeyMetadata* _aidl_return) = 0;
  virtual ::android::binder::Status importKey(const ::android::system::keystore2::KeyDescriptor& key, const ::std::optional<::android::system::keystore2::KeyDescriptor>& attestationKey, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& params, int32_t flags, const ::std::vector<uint8_t>& keyData, ::android::system::keystore2::KeyMetadata* _aidl_return) = 0;
  virtual ::android::binder::Status importWrappedKey(const ::android::system::keystore2::KeyDescriptor& key, const ::android::system::keystore2::KeyDescriptor& wrappingKey, const ::std::optional<::std::vector<uint8_t>>& maskingKey, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& params, const ::std::vector<::android::system::keystore2::AuthenticatorSpec>& authenticators, ::android::system::keystore2::KeyMetadata* _aidl_return) = 0;
  virtual ::android::binder::Status convertStorageKeyToEphemeral(const ::android::system::keystore2::KeyDescriptor& storageKey, ::android::system::keystore2::EphemeralStorageKeyResponse* _aidl_return) = 0;
  virtual ::android::binder::Status deleteKey(const ::android::system::keystore2::KeyDescriptor& key) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IKeystoreSecurityLevel

class IKeystoreSecurityLevelDefault : public IKeystoreSecurityLevel {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status createOperation(const ::android::system::keystore2::KeyDescriptor&, const ::std::vector<::android::hardware::security::keymint::KeyParameter>&, bool, ::android::system::keystore2::CreateOperationResponse*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status generateKey(const ::android::system::keystore2::KeyDescriptor&, const ::std::optional<::android::system::keystore2::KeyDescriptor>&, const ::std::vector<::android::hardware::security::keymint::KeyParameter>&, int32_t, const ::std::vector<uint8_t>&, ::android::system::keystore2::KeyMetadata*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status importKey(const ::android::system::keystore2::KeyDescriptor&, const ::std::optional<::android::system::keystore2::KeyDescriptor>&, const ::std::vector<::android::hardware::security::keymint::KeyParameter>&, int32_t, const ::std::vector<uint8_t>&, ::android::system::keystore2::KeyMetadata*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status importWrappedKey(const ::android::system::keystore2::KeyDescriptor&, const ::android::system::keystore2::KeyDescriptor&, const ::std::optional<::std::vector<uint8_t>>&, const ::std::vector<::android::hardware::security::keymint::KeyParameter>&, const ::std::vector<::android::system::keystore2::AuthenticatorSpec>&, ::android::system::keystore2::KeyMetadata*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status convertStorageKeyToEphemeral(const ::android::system::keystore2::KeyDescriptor&, ::android::system::keystore2::EphemeralStorageKeyResponse*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status deleteKey(const ::android::system::keystore2::KeyDescriptor&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IKeystoreSecurityLevelDefault

}  // namespace keystore2

}  // namespace system

}  // namespace android
