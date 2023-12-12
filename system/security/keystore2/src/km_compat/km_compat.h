/*
 * Copyright (C) 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <aidl/android/hardware/security/keymint/BnKeyMintDevice.h>
#include <aidl/android/hardware/security/keymint/BnKeyMintOperation.h>
#include <aidl/android/hardware/security/keymint/ErrorCode.h>
#include <aidl/android/hardware/security/secureclock/BnSecureClock.h>
#include <aidl/android/hardware/security/sharedsecret/BnSharedSecret.h>
#include <aidl/android/security/compat/BnKeystoreCompatService.h>
#include <keymasterV4_1/Keymaster4.h>
#include <unordered_map>
#include <variant>

#include "certificate_utils.h"

using ::aidl::android::hardware::security::keymint::AttestationKey;
using ::aidl::android::hardware::security::keymint::BeginResult;
using ::aidl::android::hardware::security::keymint::Certificate;
using ::aidl::android::hardware::security::keymint::HardwareAuthToken;
using ::aidl::android::hardware::security::keymint::KeyCharacteristics;
using ::aidl::android::hardware::security::keymint::KeyCreationResult;
using ::aidl::android::hardware::security::keymint::KeyFormat;
using ::aidl::android::hardware::security::keymint::KeyMintHardwareInfo;
using ::aidl::android::hardware::security::keymint::KeyParameter;
using ::aidl::android::hardware::security::keymint::KeyPurpose;
using KeyMintSecurityLevel = ::aidl::android::hardware::security::keymint::SecurityLevel;
using V4_0_ErrorCode = ::android::hardware::keymaster::V4_0::ErrorCode;
using ::aidl::android::hardware::security::keymint::IKeyMintDevice;
using KMV1_ErrorCode = ::aidl::android::hardware::security::keymint::ErrorCode;
using ::aidl::android::hardware::security::secureclock::ISecureClock;
using ::aidl::android::hardware::security::secureclock::TimeStampToken;
using ::aidl::android::hardware::security::sharedsecret::ISharedSecret;
using ::aidl::android::hardware::security::sharedsecret::SharedSecretParameters;
using ::aidl::android::security::compat::BnKeystoreCompatService;
using ::android::hardware::keymaster::V4_1::support::Keymaster;
using ::ndk::ScopedAStatus;

class OperationSlots {
  private:
    uint8_t mNumFreeSlots;
    std::mutex mNumFreeSlotsMutex;

  public:
    void setNumFreeSlots(uint8_t numFreeSlots);
    bool claimSlot();
    void freeSlot();
};

// An abstraction for a single operation slot.
// This contains logic to ensure that we do not free the slot multiple times,
// e.g., if we call abort twice on the same operation.
class OperationSlot {
  private:
    OperationSlots* mOperationSlots;
    bool mIsActive;

  public:
    OperationSlot(OperationSlots* slots, bool isActive)
        : mOperationSlots(slots), mIsActive(isActive) {}

    void freeSlot();
    bool hasSlot() { return mIsActive; }
};

class KeyMintDevice : public aidl::android::hardware::security::keymint::BnKeyMintDevice {
  private:
    ::android::sp<Keymaster> mDevice;
    OperationSlots mOperationSlots;

  public:
    explicit KeyMintDevice(::android::sp<Keymaster>, KeyMintSecurityLevel);
    static std::shared_ptr<KeyMintDevice> createKeyMintDevice(KeyMintSecurityLevel securityLevel);

    ScopedAStatus getHardwareInfo(KeyMintHardwareInfo* _aidl_return) override;
    ScopedAStatus addRngEntropy(const std::vector<uint8_t>& in_data) override;
    ScopedAStatus generateKey(const std::vector<KeyParameter>& in_keyParams,
                              const std::optional<AttestationKey>& in_attestationKey,
                              KeyCreationResult* out_creationResult) override;
    ScopedAStatus importKey(const std::vector<KeyParameter>& in_inKeyParams,
                            KeyFormat in_inKeyFormat, const std::vector<uint8_t>& in_inKeyData,
                            const std::optional<AttestationKey>& in_attestationKey,
                            KeyCreationResult* out_creationResult) override;
    ScopedAStatus importWrappedKey(const std::vector<uint8_t>& in_inWrappedKeyData,
                                   const std::vector<uint8_t>& in_inWrappingKeyBlob,
                                   const std::vector<uint8_t>& in_inMaskingKey,
                                   const std::vector<KeyParameter>& in_inUnwrappingParams,
                                   int64_t in_inPasswordSid, int64_t in_inBiometricSid,
                                   KeyCreationResult* out_creationResult) override;
    ScopedAStatus upgradeKey(const std::vector<uint8_t>& in_inKeyBlobToUpgrade,
                             const std::vector<KeyParameter>& in_inUpgradeParams,
                             std::vector<uint8_t>* _aidl_return) override;
    ScopedAStatus deleteKey(const std::vector<uint8_t>& in_inKeyBlob) override;
    ScopedAStatus deleteAllKeys() override;
    ScopedAStatus destroyAttestationIds() override;
    ScopedAStatus begin(KeyPurpose in_inPurpose, const std::vector<uint8_t>& in_inKeyBlob,
                        const std::vector<KeyParameter>& in_inParams,
                        const std::optional<HardwareAuthToken>& in_inAuthToken,
                        BeginResult* _aidl_return) override;
    ScopedAStatus deviceLocked(bool passwordOnly,
                               const std::optional<TimeStampToken>& timestampToken) override;
    ScopedAStatus earlyBootEnded() override;

    ScopedAStatus convertStorageKeyToEphemeral(const std::vector<uint8_t>& storageKeyBlob,
                                               std::vector<uint8_t>* ephemeralKeyBlob) override;

    ScopedAStatus
    getKeyCharacteristics(const std::vector<uint8_t>& storageKeyBlob,
                          const std::vector<uint8_t>& appId, const std::vector<uint8_t>& appData,
                          std::vector<KeyCharacteristics>* keyCharacteristics) override;

    // These are public to allow testing code to use them directly.
    // This class should not be used publicly anyway.
    std::variant<std::vector<Certificate>, KMV1_ErrorCode>
    getCertificate(const std::vector<KeyParameter>& keyParams, const std::vector<uint8_t>& keyBlob);

    void setNumFreeSlots(uint8_t numFreeSlots);

  private:
    std::optional<KMV1_ErrorCode> signCertificate(const std::vector<KeyParameter>& keyParams,
                                                  const std::vector<uint8_t>& keyBlob, X509* cert);
    KeyMintSecurityLevel securityLevel_;

    // Software-based KeyMint device used to implement ECDH.
    std::shared_ptr<IKeyMintDevice> softKeyMintDevice_;
};

class KeyMintOperation : public aidl::android::hardware::security::keymint::BnKeyMintOperation {
  public:
    KeyMintOperation(::android::sp<Keymaster> device, uint64_t operationHandle,
                     OperationSlots* slots, bool isActive)
        : mDevice(device), mOperationHandle(operationHandle), mOperationSlot(slots, isActive) {}
    ~KeyMintOperation();

    ScopedAStatus updateAad(const std::vector<uint8_t>& input,
                            const std::optional<HardwareAuthToken>& authToken,
                            const std::optional<TimeStampToken>& timestampToken) override;

    ScopedAStatus update(const std::vector<uint8_t>& input,
                         const std::optional<HardwareAuthToken>& authToken,
                         const std::optional<TimeStampToken>& timestampToken,
                         std::vector<uint8_t>* output) override;

    ScopedAStatus finish(const std::optional<std::vector<uint8_t>>& input,
                         const std::optional<std::vector<uint8_t>>& signature,
                         const std::optional<HardwareAuthToken>& authToken,
                         const std::optional<TimeStampToken>& timeStampToken,
                         const std::optional<std::vector<uint8_t>>& confirmationToken,
                         std::vector<uint8_t>* output) override;

    ScopedAStatus abort();

  private:
    /**
     * Sets mUpdateBuffer to the given value.
     * @param data
     */
    void setUpdateBuffer(std::vector<uint8_t> data);
    /**
     * If mUpdateBuffer is not empty, suffix is appended to mUpdateBuffer, and a reference to
     * mUpdateBuffer is returned. Otherwise a reference to suffix is returned.
     * @param suffix
     * @return
     */
    const std::vector<uint8_t>& getExtendedUpdateBuffer(const std::vector<uint8_t>& suffix);

    std::vector<uint8_t> mUpdateBuffer;
    ::android::sp<Keymaster> mDevice;
    uint64_t mOperationHandle;
    OperationSlot mOperationSlot;
};

class SharedSecret : public aidl::android::hardware::security::sharedsecret::BnSharedSecret {
  private:
    ::android::sp<Keymaster> mDevice;

  public:
    SharedSecret(::android::sp<Keymaster> device) : mDevice(device) {}
    static std::shared_ptr<SharedSecret> createSharedSecret(KeyMintSecurityLevel securityLevel);

    virtual ScopedAStatus getSharedSecretParameters(SharedSecretParameters* _aidl_return) override;
    virtual ScopedAStatus computeSharedSecret(const std::vector<SharedSecretParameters>& in_params,
                                              std::vector<uint8_t>* _aidl_return) override;
};

class SecureClock : public aidl::android::hardware::security::secureclock::BnSecureClock {
  private:
    ::android::sp<Keymaster> mDevice;

  public:
    SecureClock(::android::sp<Keymaster> device) : mDevice(device) {}
    static std::shared_ptr<SecureClock> createSecureClock(KeyMintSecurityLevel securityLevel);

    ScopedAStatus generateTimeStamp(int64_t in_challenge, TimeStampToken* _aidl_return) override;
};

class KeystoreCompatService : public BnKeystoreCompatService {
  private:
    std::unordered_map<KeyMintSecurityLevel, std::shared_ptr<IKeyMintDevice>> mDeviceCache;
    std::unordered_map<KeyMintSecurityLevel, std::shared_ptr<ISharedSecret>> mSharedSecretCache;
    std::shared_ptr<ISecureClock> mSecureClock;

  public:
    KeystoreCompatService() {}
    ScopedAStatus getKeyMintDevice(KeyMintSecurityLevel in_securityLevel,
                                   std::shared_ptr<IKeyMintDevice>* _aidl_return) override;
    ScopedAStatus getSharedSecret(KeyMintSecurityLevel in_securityLevel,
                                  std::shared_ptr<ISharedSecret>* _aidl_return) override;
    ScopedAStatus getSecureClock(std::shared_ptr<ISecureClock>* _aidl_return) override;
};
