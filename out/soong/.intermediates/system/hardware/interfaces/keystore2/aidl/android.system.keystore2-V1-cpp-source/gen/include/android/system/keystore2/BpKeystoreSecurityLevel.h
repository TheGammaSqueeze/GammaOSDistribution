#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/system/keystore2/IKeystoreSecurityLevel.h>

namespace android {

namespace system {

namespace keystore2 {

class BpKeystoreSecurityLevel : public ::android::BpInterface<IKeystoreSecurityLevel> {
public:
  explicit BpKeystoreSecurityLevel(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpKeystoreSecurityLevel() = default;
  ::android::binder::Status createOperation(const ::android::system::keystore2::KeyDescriptor& key, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& operationParameters, bool forced, ::android::system::keystore2::CreateOperationResponse* _aidl_return) override;
  ::android::binder::Status generateKey(const ::android::system::keystore2::KeyDescriptor& key, const ::std::optional<::android::system::keystore2::KeyDescriptor>& attestationKey, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& params, int32_t flags, const ::std::vector<uint8_t>& entropy, ::android::system::keystore2::KeyMetadata* _aidl_return) override;
  ::android::binder::Status importKey(const ::android::system::keystore2::KeyDescriptor& key, const ::std::optional<::android::system::keystore2::KeyDescriptor>& attestationKey, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& params, int32_t flags, const ::std::vector<uint8_t>& keyData, ::android::system::keystore2::KeyMetadata* _aidl_return) override;
  ::android::binder::Status importWrappedKey(const ::android::system::keystore2::KeyDescriptor& key, const ::android::system::keystore2::KeyDescriptor& wrappingKey, const ::std::optional<::std::vector<uint8_t>>& maskingKey, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& params, const ::std::vector<::android::system::keystore2::AuthenticatorSpec>& authenticators, ::android::system::keystore2::KeyMetadata* _aidl_return) override;
  ::android::binder::Status convertStorageKeyToEphemeral(const ::android::system::keystore2::KeyDescriptor& storageKey, ::android::system::keystore2::EphemeralStorageKeyResponse* _aidl_return) override;
  ::android::binder::Status deleteKey(const ::android::system::keystore2::KeyDescriptor& key) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpKeystoreSecurityLevel

}  // namespace keystore2

}  // namespace system

}  // namespace android
