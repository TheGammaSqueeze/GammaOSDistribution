#pragma once

#include <android/binder_interface_utils.h>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT
#include <android/binder_parcel_platform.h>
#include <android/binder_ibinder_platform.h>
#include <aidl/android/hardware/security/keymint/KeyParameter.h>
#include <aidl/android/system/keystore2/AuthenticatorSpec.h>
#include <aidl/android/system/keystore2/CreateOperationResponse.h>
#include <aidl/android/system/keystore2/EphemeralStorageKeyResponse.h>
#include <aidl/android/system/keystore2/KeyDescriptor.h>
#include <aidl/android/system/keystore2/KeyMetadata.h>

namespace aidl {
namespace android {
namespace system {
namespace keystore2 {
class IKeystoreSecurityLevel : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IKeystoreSecurityLevel();
  virtual ~IKeystoreSecurityLevel();

  enum : int32_t { KEY_FLAG_AUTH_BOUND_WITHOUT_CRYPTOGRAPHIC_LSKF_BINDING = 1 };
  static const int32_t version = 1;
  static inline const std::string hash = "19e8b65277839bad0ab335c781e3c652324920ce";
  static constexpr uint32_t TRANSACTION_createOperation = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_generateKey = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_importKey = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_importWrappedKey = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_convertStorageKeyToEphemeral = FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_deleteKey = FIRST_CALL_TRANSACTION + 5;

  static std::shared_ptr<IKeystoreSecurityLevel> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IKeystoreSecurityLevel>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IKeystoreSecurityLevel>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IKeystoreSecurityLevel>& impl);
  static const std::shared_ptr<IKeystoreSecurityLevel>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus createOperation(const ::aidl::android::system::keystore2::KeyDescriptor& in_key, const std::vector<::aidl::android::hardware::security::keymint::KeyParameter>& in_operationParameters, bool in_forced, ::aidl::android::system::keystore2::CreateOperationResponse* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus generateKey(const ::aidl::android::system::keystore2::KeyDescriptor& in_key, const std::optional<::aidl::android::system::keystore2::KeyDescriptor>& in_attestationKey, const std::vector<::aidl::android::hardware::security::keymint::KeyParameter>& in_params, int32_t in_flags, const std::vector<uint8_t>& in_entropy, ::aidl::android::system::keystore2::KeyMetadata* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus importKey(const ::aidl::android::system::keystore2::KeyDescriptor& in_key, const std::optional<::aidl::android::system::keystore2::KeyDescriptor>& in_attestationKey, const std::vector<::aidl::android::hardware::security::keymint::KeyParameter>& in_params, int32_t in_flags, const std::vector<uint8_t>& in_keyData, ::aidl::android::system::keystore2::KeyMetadata* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus importWrappedKey(const ::aidl::android::system::keystore2::KeyDescriptor& in_key, const ::aidl::android::system::keystore2::KeyDescriptor& in_wrappingKey, const std::optional<std::vector<uint8_t>>& in_maskingKey, const std::vector<::aidl::android::hardware::security::keymint::KeyParameter>& in_params, const std::vector<::aidl::android::system::keystore2::AuthenticatorSpec>& in_authenticators, ::aidl::android::system::keystore2::KeyMetadata* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus convertStorageKeyToEphemeral(const ::aidl::android::system::keystore2::KeyDescriptor& in_storageKey, ::aidl::android::system::keystore2::EphemeralStorageKeyResponse* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus deleteKey(const ::aidl::android::system::keystore2::KeyDescriptor& in_key) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IKeystoreSecurityLevel> default_impl;
};
class IKeystoreSecurityLevelDefault : public IKeystoreSecurityLevel {
public:
  ::ndk::ScopedAStatus createOperation(const ::aidl::android::system::keystore2::KeyDescriptor& in_key, const std::vector<::aidl::android::hardware::security::keymint::KeyParameter>& in_operationParameters, bool in_forced, ::aidl::android::system::keystore2::CreateOperationResponse* _aidl_return) override;
  ::ndk::ScopedAStatus generateKey(const ::aidl::android::system::keystore2::KeyDescriptor& in_key, const std::optional<::aidl::android::system::keystore2::KeyDescriptor>& in_attestationKey, const std::vector<::aidl::android::hardware::security::keymint::KeyParameter>& in_params, int32_t in_flags, const std::vector<uint8_t>& in_entropy, ::aidl::android::system::keystore2::KeyMetadata* _aidl_return) override;
  ::ndk::ScopedAStatus importKey(const ::aidl::android::system::keystore2::KeyDescriptor& in_key, const std::optional<::aidl::android::system::keystore2::KeyDescriptor>& in_attestationKey, const std::vector<::aidl::android::hardware::security::keymint::KeyParameter>& in_params, int32_t in_flags, const std::vector<uint8_t>& in_keyData, ::aidl::android::system::keystore2::KeyMetadata* _aidl_return) override;
  ::ndk::ScopedAStatus importWrappedKey(const ::aidl::android::system::keystore2::KeyDescriptor& in_key, const ::aidl::android::system::keystore2::KeyDescriptor& in_wrappingKey, const std::optional<std::vector<uint8_t>>& in_maskingKey, const std::vector<::aidl::android::hardware::security::keymint::KeyParameter>& in_params, const std::vector<::aidl::android::system::keystore2::AuthenticatorSpec>& in_authenticators, ::aidl::android::system::keystore2::KeyMetadata* _aidl_return) override;
  ::ndk::ScopedAStatus convertStorageKeyToEphemeral(const ::aidl::android::system::keystore2::KeyDescriptor& in_storageKey, ::aidl::android::system::keystore2::EphemeralStorageKeyResponse* _aidl_return) override;
  ::ndk::ScopedAStatus deleteKey(const ::aidl::android::system::keystore2::KeyDescriptor& in_key) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace keystore2
}  // namespace system
}  // namespace android
}  // namespace aidl
