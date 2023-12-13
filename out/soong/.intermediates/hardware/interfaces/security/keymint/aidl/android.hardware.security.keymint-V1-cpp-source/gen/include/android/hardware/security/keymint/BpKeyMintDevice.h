#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/security/keymint/IKeyMintDevice.h>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

class BpKeyMintDevice : public ::android::BpInterface<IKeyMintDevice> {
public:
  explicit BpKeyMintDevice(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpKeyMintDevice() = default;
  ::android::binder::Status getHardwareInfo(::android::hardware::security::keymint::KeyMintHardwareInfo* _aidl_return) override;
  ::android::binder::Status addRngEntropy(const ::std::vector<uint8_t>& data) override;
  ::android::binder::Status generateKey(const ::std::vector<::android::hardware::security::keymint::KeyParameter>& keyParams, const ::std::optional<::android::hardware::security::keymint::AttestationKey>& attestationKey, ::android::hardware::security::keymint::KeyCreationResult* _aidl_return) override;
  ::android::binder::Status importKey(const ::std::vector<::android::hardware::security::keymint::KeyParameter>& keyParams, ::android::hardware::security::keymint::KeyFormat keyFormat, const ::std::vector<uint8_t>& keyData, const ::std::optional<::android::hardware::security::keymint::AttestationKey>& attestationKey, ::android::hardware::security::keymint::KeyCreationResult* _aidl_return) override;
  ::android::binder::Status importWrappedKey(const ::std::vector<uint8_t>& wrappedKeyData, const ::std::vector<uint8_t>& wrappingKeyBlob, const ::std::vector<uint8_t>& maskingKey, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& unwrappingParams, int64_t passwordSid, int64_t biometricSid, ::android::hardware::security::keymint::KeyCreationResult* _aidl_return) override;
  ::android::binder::Status upgradeKey(const ::std::vector<uint8_t>& keyBlobToUpgrade, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& upgradeParams, ::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status deleteKey(const ::std::vector<uint8_t>& keyBlob) override;
  ::android::binder::Status deleteAllKeys() override;
  ::android::binder::Status destroyAttestationIds() override;
  ::android::binder::Status begin(::android::hardware::security::keymint::KeyPurpose purpose, const ::std::vector<uint8_t>& keyBlob, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& params, const ::std::optional<::android::hardware::security::keymint::HardwareAuthToken>& authToken, ::android::hardware::security::keymint::BeginResult* _aidl_return) override;
  ::android::binder::Status deviceLocked(bool passwordOnly, const ::std::optional<::android::hardware::security::secureclock::TimeStampToken>& timestampToken) override;
  ::android::binder::Status earlyBootEnded() override;
  ::android::binder::Status convertStorageKeyToEphemeral(const ::std::vector<uint8_t>& storageKeyBlob, ::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status getKeyCharacteristics(const ::std::vector<uint8_t>& keyBlob, const ::std::vector<uint8_t>& appId, const ::std::vector<uint8_t>& appData, ::std::vector<::android::hardware::security::keymint::KeyCharacteristics>* _aidl_return) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpKeyMintDevice

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
