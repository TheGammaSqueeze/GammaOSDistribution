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

#include "km_compat.h"

#include "km_compat_type_conversion.h"
#include <AndroidKeyMintDevice.h>
#include <aidl/android/hardware/security/keymint/Algorithm.h>
#include <aidl/android/hardware/security/keymint/Digest.h>
#include <aidl/android/hardware/security/keymint/ErrorCode.h>
#include <aidl/android/hardware/security/keymint/KeyParameterValue.h>
#include <aidl/android/hardware/security/keymint/PaddingMode.h>
#include <aidl/android/system/keystore2/ResponseCode.h>
#include <android-base/logging.h>
#include <android/hidl/manager/1.2/IServiceManager.h>
#include <binder/IServiceManager.h>
#include <hardware/keymaster_defs.h>
#include <keymasterV4_1/Keymaster.h>
#include <keymasterV4_1/Keymaster3.h>
#include <keymasterV4_1/Keymaster4.h>

#include <chrono>

#include "certificate_utils.h"

using ::aidl::android::hardware::security::keymint::Algorithm;
using ::aidl::android::hardware::security::keymint::CreateKeyMintDevice;
using ::aidl::android::hardware::security::keymint::Digest;
using ::aidl::android::hardware::security::keymint::KeyParameterValue;
using ::aidl::android::hardware::security::keymint::PaddingMode;
using ::aidl::android::hardware::security::keymint::Tag;
using ::aidl::android::system::keystore2::ResponseCode;
using ::android::hardware::hidl_vec;
using ::android::hardware::keymaster::V4_0::TagType;
using ::android::hidl::manager::V1_2::IServiceManager;
using V4_0_HardwareAuthToken = ::android::hardware::keymaster::V4_0::HardwareAuthToken;
using V4_0_HmacSharingParameters = ::android::hardware::keymaster::V4_0::HmacSharingParameters;
using V4_0_KeyCharacteristics = ::android::hardware::keymaster::V4_0::KeyCharacteristics;
using V4_0_KeyFormat = ::android::hardware::keymaster::V4_0::KeyFormat;
using V4_0_KeyParameter = ::android::hardware::keymaster::V4_0::KeyParameter;
using V4_0_VerificationToken = ::android::hardware::keymaster::V4_0::VerificationToken;
namespace V4_0 = ::android::hardware::keymaster::V4_0;
namespace V4_1 = ::android::hardware::keymaster::V4_1;
namespace KMV1 = ::aidl::android::hardware::security::keymint;

using namespace std::chrono_literals;
using std::chrono::duration_cast;

static const KMV1::Tag KM_TAG_FBE_ICE = static_cast<KMV1::Tag>((7 << 28) | 16201);

// Utility functions

// Returns true if this parameter may be passed to attestKey.
bool isAttestationParameter(const KMV1::KeyParameter& param) {
    switch (param.tag) {
    case Tag::APPLICATION_ID:
    case Tag::APPLICATION_DATA:
    case Tag::ATTESTATION_CHALLENGE:
    case Tag::ATTESTATION_APPLICATION_ID:
    case Tag::ATTESTATION_ID_BRAND:
    case Tag::ATTESTATION_ID_DEVICE:
    case Tag::ATTESTATION_ID_PRODUCT:
    case Tag::ATTESTATION_ID_SERIAL:
    case Tag::ATTESTATION_ID_IMEI:
    case Tag::ATTESTATION_ID_MEID:
    case Tag::ATTESTATION_ID_MANUFACTURER:
    case Tag::ATTESTATION_ID_MODEL:
    case Tag::CERTIFICATE_SERIAL:
    case Tag::CERTIFICATE_SUBJECT:
    case Tag::CERTIFICATE_NOT_BEFORE:
    case Tag::CERTIFICATE_NOT_AFTER:
    case Tag::INCLUDE_UNIQUE_ID:
    case Tag::DEVICE_UNIQUE_ATTESTATION:
        return true;
    default:
        return false;
    }
}

// Returns true if this parameter may be passed to generate/importKey.
bool isKeyCreationParameter(const KMV1::KeyParameter& param) {
    switch (param.tag) {
    case Tag::APPLICATION_ID:
    case Tag::APPLICATION_DATA:
    case Tag::CERTIFICATE_SERIAL:
    case Tag::CERTIFICATE_SUBJECT:
    case Tag::CERTIFICATE_NOT_BEFORE:
    case Tag::CERTIFICATE_NOT_AFTER:
    case Tag::PURPOSE:
    case Tag::ALGORITHM:
    case Tag::KEY_SIZE:
    case Tag::BLOCK_MODE:
    case Tag::DIGEST:
    case Tag::PADDING:
    case Tag::CALLER_NONCE:
    case Tag::MIN_MAC_LENGTH:
    case Tag::EC_CURVE:
    case Tag::RSA_PUBLIC_EXPONENT:
    case Tag::RSA_OAEP_MGF_DIGEST:
    case Tag::BOOTLOADER_ONLY:
    case Tag::ROLLBACK_RESISTANCE:
    case Tag::EARLY_BOOT_ONLY:
    case Tag::ACTIVE_DATETIME:
    case Tag::ORIGINATION_EXPIRE_DATETIME:
    case Tag::USAGE_EXPIRE_DATETIME:
    case Tag::MIN_SECONDS_BETWEEN_OPS:
    case Tag::MAX_USES_PER_BOOT:
    case Tag::USAGE_COUNT_LIMIT:
    case Tag::USER_ID:
    case Tag::USER_SECURE_ID:
    case Tag::NO_AUTH_REQUIRED:
    case Tag::USER_AUTH_TYPE:
    case Tag::AUTH_TIMEOUT:
    case Tag::ALLOW_WHILE_ON_BODY:
    case Tag::TRUSTED_USER_PRESENCE_REQUIRED:
    case Tag::TRUSTED_CONFIRMATION_REQUIRED:
    case Tag::UNLOCKED_DEVICE_REQUIRED:
    case Tag::CREATION_DATETIME:
    case Tag::UNIQUE_ID:
    case Tag::IDENTITY_CREDENTIAL_KEY:
    case Tag::STORAGE_KEY:
    case Tag::MAC_LENGTH:
        return true;
    default:
        return false;
    }
}

// Size of prefix for blobs, see keyBlobPrefix().
//
const size_t kKeyBlobPrefixSize = 8;

// Magic used in blob prefix, see keyBlobPrefix().
//
const uint8_t kKeyBlobMagic[7] = {'p', 'K', 'M', 'b', 'l', 'o', 'b'};

// Prefixes a keyblob returned by e.g. generateKey() with information on whether it
// originated from the real underlying KeyMaster HAL or from soft-KeyMint.
//
// When dealing with a keyblob, use prefixedKeyBlobRemovePrefix() to remove the
// prefix and prefixedKeyBlobIsSoftKeyMint() to determine its origin.
//
// Note how the prefix itself has a magic marker ("pKMblob") which can be used
// to identify if a blob has a prefix at all (it's assumed that any valid blob
// from KeyMint or KeyMaster HALs never starts with the magic). This is needed
// because blobs persisted to disk prior to using this code will not have the
// prefix and in that case we want prefixedKeyBlobRemovePrefix() to still work.
//
std::vector<uint8_t> keyBlobPrefix(const std::vector<uint8_t>& blob, bool isSoftKeyMint) {
    std::vector<uint8_t> result;
    result.reserve(blob.size() + kKeyBlobPrefixSize);
    result.insert(result.begin(), kKeyBlobMagic, kKeyBlobMagic + sizeof kKeyBlobMagic);
    result.push_back(isSoftKeyMint ? 1 : 0);
    std::copy(blob.begin(), blob.end(), std::back_inserter(result));
    return result;
}

// Helper for prefixedKeyBlobRemovePrefix() and prefixedKeyBlobIsSoftKeyMint().
//
// First bool is whether there's a valid prefix. If there is, the second bool is
// the |isSoftKeyMint| value of the prefix
//
std::pair<bool, bool> prefixedKeyBlobParsePrefix(const std::vector<uint8_t>& prefixedBlob) {
    // Having a unprefixed blob is not that uncommon, for example all devices
    // upgrading to keystore2 (so e.g. upgrading to Android 12) will have
    // unprefixed blobs. So don't spew warnings/errors in this case...
    if (prefixedBlob.size() < kKeyBlobPrefixSize) {
        return std::make_pair(false, false);
    }
    if (std::memcmp(prefixedBlob.data(), kKeyBlobMagic, sizeof kKeyBlobMagic) != 0) {
        return std::make_pair(false, false);
    }
    if (prefixedBlob[kKeyBlobPrefixSize - 1] != 0 && prefixedBlob[kKeyBlobPrefixSize - 1] != 1) {
        return std::make_pair(false, false);
    }
    bool isSoftKeyMint = (prefixedBlob[kKeyBlobPrefixSize - 1] == 1);
    return std::make_pair(true, isSoftKeyMint);
}

// Removes the prefix from a blob. If there's no prefix, returns the passed-in blob.
//
std::vector<uint8_t> prefixedKeyBlobRemovePrefix(const std::vector<uint8_t>& prefixedBlob) {
    auto parsed = prefixedKeyBlobParsePrefix(prefixedBlob);
    if (!parsed.first) {
        // Not actually prefixed, blob was probably persisted to disk prior to the
        // prefixing code being introduced.
        return prefixedBlob;
    }
    return std::vector<uint8_t>(prefixedBlob.begin() + kKeyBlobPrefixSize, prefixedBlob.end());
}

// Returns true if the blob's origin is soft-KeyMint, false otherwise or if there
// is no prefix on the passed-in blob.
//
bool prefixedKeyBlobIsSoftKeyMint(const std::vector<uint8_t>& prefixedBlob) {
    auto parsed = prefixedKeyBlobParsePrefix(prefixedBlob);
    return parsed.second;
}

// Inspects the given blob for prefixes.
// Returns the blob stripped of the prefix if present. The boolean argument is true if the blob was
// a software blob.
std::pair<std::vector<uint8_t>, bool>
dissectPrefixedKeyBlob(const std::vector<uint8_t>& prefixedBlob) {
    auto [hasPrefix, isSoftware] = prefixedKeyBlobParsePrefix(prefixedBlob);
    if (!hasPrefix) {
        // Not actually prefixed, blob was probably persisted to disk prior to the
        // prefixing code being introduced.
        return {prefixedBlob, false};
    }
    return {std::vector<uint8_t>(prefixedBlob.begin() + kKeyBlobPrefixSize, prefixedBlob.end()),
            isSoftware};
}

/*
 * Returns true if the parameter is not understood by KM 4.1 and older but can be enforced by
 * Keystore. These parameters need to be included in the returned KeyCharacteristics, but will not
 * be passed to the legacy backend.
 */
bool isNewAndKeystoreEnforceable(const KMV1::KeyParameter& param) {
    switch (param.tag) {
    case KMV1::Tag::MAX_BOOT_LEVEL:
        return true;
    case KMV1::Tag::USAGE_COUNT_LIMIT:
        return true;
    default:
        return false;
    }
}

std::vector<KMV1::KeyParameter>
extractGenerationParams(const std::vector<KMV1::KeyParameter>& params) {
    std::vector<KMV1::KeyParameter> result;
    std::copy_if(params.begin(), params.end(), std::back_inserter(result), isKeyCreationParameter);
    return result;
}

std::vector<KMV1::KeyParameter>
extractAttestationParams(const std::vector<KMV1::KeyParameter>& params) {
    std::vector<KMV1::KeyParameter> result;
    std::copy_if(params.begin(), params.end(), std::back_inserter(result), isAttestationParameter);
    return result;
}

std::vector<KMV1::KeyParameter>
extractNewAndKeystoreEnforceableParams(const std::vector<KMV1::KeyParameter>& params) {
    std::vector<KMV1::KeyParameter> result;
    std::copy_if(params.begin(), params.end(), std::back_inserter(result),
                 isNewAndKeystoreEnforceable);
    return result;
}

ScopedAStatus convertErrorCode(KMV1::ErrorCode result) {
    if (result == KMV1::ErrorCode::OK) {
        return ScopedAStatus::ok();
    }
    return ScopedAStatus::fromServiceSpecificError(static_cast<int32_t>(result));
}

// Converts a V4 error code into a ScopedAStatus
ScopedAStatus convertErrorCode(V4_0_ErrorCode result) {
    return convertErrorCode(convert(result));
}

static KMV1::ErrorCode toErrorCode(const ScopedAStatus& status) {
    if (status.getExceptionCode() == EX_SERVICE_SPECIFIC) {
        return static_cast<KMV1::ErrorCode>(status.getServiceSpecificError());
    } else {
        return KMV1::ErrorCode::UNKNOWN_ERROR;
    }
}

static std::vector<V4_0::KeyParameter>
convertKeyParametersToLegacy(const std::vector<KeyParameter>& kps) {
    std::vector<V4_0::KeyParameter> legacyKps;
    legacyKps.reserve(kps.size());
    for (const auto& kp : kps) {
        auto p = convertKeyParameterToLegacy(kp);
        if (p.tag != V4_0::Tag::INVALID) {
            legacyKps.push_back(std::move(p));
        }
    }
    return legacyKps;
}

static std::vector<KeyParameter>
convertKeyParametersFromLegacy(const std::vector<V4_0_KeyParameter>& legacyKps) {
    std::vector<KeyParameter> kps(legacyKps.size());
    std::transform(legacyKps.begin(), legacyKps.end(), kps.begin(), convertKeyParameterFromLegacy);
    return kps;
}

static std::vector<KeyCharacteristics>
processLegacyCharacteristics(KeyMintSecurityLevel securityLevel,
                             const std::vector<KeyParameter>& genParams,
                             const V4_0_KeyCharacteristics& legacyKc, bool kmEnforcedOnly = false) {

    KeyCharacteristics kmEnforced{securityLevel, convertKeyParametersFromLegacy(
                                                     securityLevel == KeyMintSecurityLevel::SOFTWARE
                                                         ? legacyKc.softwareEnforced
                                                         : legacyKc.hardwareEnforced)};

    if (securityLevel == KeyMintSecurityLevel::SOFTWARE && legacyKc.hardwareEnforced.size() > 0) {
        LOG(WARNING) << "Unexpected hardware enforced parameters.";
    }

    if (kmEnforcedOnly) {
        return {kmEnforced};
    }

    KeyCharacteristics keystoreEnforced{KeyMintSecurityLevel::KEYSTORE, {}};

    if (securityLevel != KeyMintSecurityLevel::SOFTWARE) {
        // Don't include these tags on software backends, else they'd end up duplicated
        // across both the keystore-enforced and software keymaster-enforced tags.
        keystoreEnforced.authorizations = convertKeyParametersFromLegacy(legacyKc.softwareEnforced);
    }

    // Add all parameters that we know can be enforced by keystore but not by the legacy backend.
    auto unsupported_requested = extractNewAndKeystoreEnforceableParams(genParams);
    keystoreEnforced.authorizations.insert(keystoreEnforced.authorizations.end(),
                                           std::begin(unsupported_requested),
                                           std::end(unsupported_requested));

    return {kmEnforced, keystoreEnforced};
}

static V4_0_KeyFormat convertKeyFormatToLegacy(const KeyFormat& kf) {
    return static_cast<V4_0_KeyFormat>(kf);
}

static V4_0_HardwareAuthToken convertAuthTokenToLegacy(const std::optional<HardwareAuthToken>& at) {
    if (!at) return {};

    V4_0_HardwareAuthToken legacyAt;
    legacyAt.challenge = at->challenge;
    legacyAt.userId = at->userId;
    legacyAt.authenticatorId = at->authenticatorId;
    legacyAt.authenticatorType =
        static_cast<::android::hardware::keymaster::V4_0::HardwareAuthenticatorType>(
            at->authenticatorType);
    legacyAt.timestamp = at->timestamp.milliSeconds;
    legacyAt.mac = at->mac;
    return legacyAt;
}

static V4_0_VerificationToken
convertTimestampTokenToLegacy(const std::optional<TimeStampToken>& tst) {
    if (!tst) return {};

    V4_0_VerificationToken legacyVt;
    legacyVt.challenge = tst->challenge;
    legacyVt.timestamp = tst->timestamp.milliSeconds;
    // Legacy verification tokens were always minted by TEE.
    legacyVt.securityLevel = V4_0::SecurityLevel::TRUSTED_ENVIRONMENT;
    legacyVt.mac = tst->mac;
    return legacyVt;
}

static V4_0_HmacSharingParameters
convertSharedSecretParameterToLegacy(const SharedSecretParameters& ssp) {
    V4_0_HmacSharingParameters legacyHsp;
    legacyHsp.seed = ssp.seed;
    std::copy(ssp.nonce.begin(), ssp.nonce.end(), legacyHsp.nonce.data());
    return legacyHsp;
}

static std::vector<V4_0_HmacSharingParameters>
convertSharedSecretParametersToLegacy(const std::vector<SharedSecretParameters>& legacySsps) {
    std::vector<V4_0_HmacSharingParameters> ssps(legacySsps.size());
    std::transform(legacySsps.begin(), legacySsps.end(), ssps.begin(),
                   convertSharedSecretParameterToLegacy);
    return ssps;
}

void OperationSlots::setNumFreeSlots(uint8_t numFreeSlots) {
    std::lock_guard<std::mutex> lock(mNumFreeSlotsMutex);
    mNumFreeSlots = numFreeSlots;
}

bool OperationSlots::claimSlot() {
    std::lock_guard<std::mutex> lock(mNumFreeSlotsMutex);
    if (mNumFreeSlots > 0) {
        mNumFreeSlots--;
        return true;
    }
    return false;
}

void OperationSlots::freeSlot() {
    std::lock_guard<std::mutex> lock(mNumFreeSlotsMutex);
    mNumFreeSlots++;
}

void OperationSlot::freeSlot() {
    if (mIsActive) {
        mOperationSlots->freeSlot();
        mIsActive = false;
    }
}

// KeyMintDevice implementation

ScopedAStatus KeyMintDevice::getHardwareInfo(KeyMintHardwareInfo* _aidl_return) {
    auto result = mDevice->halVersion();
    _aidl_return->versionNumber = result.majorVersion * 10 + result.minorVersion;
    securityLevel_ = convert(result.securityLevel);
    _aidl_return->securityLevel = securityLevel_;
    _aidl_return->keyMintName = result.keymasterName;
    _aidl_return->keyMintAuthorName = result.authorName;
    _aidl_return->timestampTokenRequired = securityLevel_ == KMV1::SecurityLevel::STRONGBOX;
    return ScopedAStatus::ok();
}

ScopedAStatus KeyMintDevice::addRngEntropy(const std::vector<uint8_t>& in_data) {
    auto result = mDevice->addRngEntropy(in_data);
    if (!result.isOk()) {
        LOG(ERROR) << __func__ << " transaction failed. " << result.description();
        return convertErrorCode(KMV1::ErrorCode::UNKNOWN_ERROR);
    }
    return convertErrorCode(result);
}

ScopedAStatus KeyMintDevice::generateKey(const std::vector<KeyParameter>& inKeyParams,
                                         const std::optional<AttestationKey>& in_attestationKey,
                                         KeyCreationResult* out_creationResult) {

    // Since KeyMaster doesn't support ECDH, route all key creation requests to
    // soft-KeyMint if and only an ECDH key is requested.
    //
    // For this to work we'll need to also route begin() and deleteKey() calls to
    // soft-KM. In order to do that, we'll prefix all keyblobs with whether it was
    // created by the real underlying KeyMaster HAL or whether it was created by
    // soft-KeyMint.
    //
    // See keyBlobPrefix() for more discussion.
    //
    for (const auto& keyParam : inKeyParams) {
        if (keyParam.tag == Tag::PURPOSE &&
            keyParam.value.get<KeyParameterValue::Tag::keyPurpose>() == KeyPurpose::AGREE_KEY) {
            auto ret =
                softKeyMintDevice_->generateKey(inKeyParams, in_attestationKey, out_creationResult);
            if (ret.isOk()) {
                out_creationResult->keyBlob = keyBlobPrefix(out_creationResult->keyBlob, true);
            }
            return ret;
        }
    }

    auto legacyKeyGenParams = convertKeyParametersToLegacy(extractGenerationParams(inKeyParams));
    KMV1::ErrorCode errorCode;

    for (const auto& keyParam : inKeyParams) {
        if((int32_t)keyParam.tag==(int32_t)KM_TAG_FBE_ICE) {
            android::hardware::keymaster::V4_0::KeyParameter param1;
            param1.tag = static_cast<::android::hardware::keymaster::V4_0::Tag>
			(android::hardware::keymaster::V4_0::KM_TAG_FBE_ICE);
            param1.f.boolValue = true;
            legacyKeyGenParams.push_back(param1);
            break;
        }
    }

    auto result = mDevice->generateKey(
        legacyKeyGenParams, [&](V4_0_ErrorCode error, const hidl_vec<uint8_t>& keyBlob,
                                const V4_0_KeyCharacteristics& keyCharacteristics) {
            errorCode = convert(error);
            out_creationResult->keyBlob = keyBlobPrefix(keyBlob, false);
            out_creationResult->keyCharacteristics =
                processLegacyCharacteristics(securityLevel_, inKeyParams, keyCharacteristics);
        });
    if (!result.isOk()) {
        LOG(ERROR) << __func__ << " transaction failed. " << result.description();
        return convertErrorCode(KMV1::ErrorCode::UNKNOWN_ERROR);
    }
    if (errorCode == KMV1::ErrorCode::OK) {
        auto cert = getCertificate(inKeyParams, out_creationResult->keyBlob);
        if (std::holds_alternative<KMV1::ErrorCode>(cert)) {
            auto code = std::get<KMV1::ErrorCode>(cert);
            // We return OK in successful cases that do not generate a certificate.
            if (code != KMV1::ErrorCode::OK) {
                errorCode = code;
                deleteKey(out_creationResult->keyBlob);
            }
        } else {
            out_creationResult->certificateChain = std::get<std::vector<Certificate>>(cert);
        }
    }
    return convertErrorCode(errorCode);
}

ScopedAStatus KeyMintDevice::importKey(const std::vector<KeyParameter>& inKeyParams,
                                       KeyFormat in_inKeyFormat,
                                       const std::vector<uint8_t>& in_inKeyData,
                                       const std::optional<AttestationKey>& /* in_attestationKey */,
                                       KeyCreationResult* out_creationResult) {
    auto legacyKeyGENParams = convertKeyParametersToLegacy(extractGenerationParams(inKeyParams));
    auto legacyKeyFormat = convertKeyFormatToLegacy(in_inKeyFormat);
    KMV1::ErrorCode errorCode;
    auto result = mDevice->importKey(legacyKeyGENParams, legacyKeyFormat, in_inKeyData,
                                     [&](V4_0_ErrorCode error, const hidl_vec<uint8_t>& keyBlob,
                                         const V4_0_KeyCharacteristics& keyCharacteristics) {
                                         errorCode = convert(error);
                                         out_creationResult->keyBlob =
                                             keyBlobPrefix(keyBlob, false);
                                         out_creationResult->keyCharacteristics =
                                             processLegacyCharacteristics(
                                                 securityLevel_, inKeyParams, keyCharacteristics);
                                     });
    if (!result.isOk()) {
        LOG(ERROR) << __func__ << " transaction failed. " << result.description();
        return convertErrorCode(KMV1::ErrorCode::UNKNOWN_ERROR);
    }
    if (errorCode == KMV1::ErrorCode::OK) {
        auto cert = getCertificate(inKeyParams, out_creationResult->keyBlob);
        if (std::holds_alternative<KMV1::ErrorCode>(cert)) {
            auto code = std::get<KMV1::ErrorCode>(cert);
            // We return OK in successful cases that do not generate a certificate.
            if (code != KMV1::ErrorCode::OK) {
                errorCode = code;
                deleteKey(out_creationResult->keyBlob);
            }
        } else {
            out_creationResult->certificateChain = std::get<std::vector<Certificate>>(cert);
        }
    }
    return convertErrorCode(errorCode);
}

ScopedAStatus
KeyMintDevice::importWrappedKey(const std::vector<uint8_t>& in_inWrappedKeyData,
                                const std::vector<uint8_t>& in_inPrefixedWrappingKeyBlob,
                                const std::vector<uint8_t>& in_inMaskingKey,
                                const std::vector<KeyParameter>& in_inUnwrappingParams,
                                int64_t in_inPasswordSid, int64_t in_inBiometricSid,
                                KeyCreationResult* out_creationResult) {
    const std::vector<uint8_t>& wrappingKeyBlob =
        prefixedKeyBlobRemovePrefix(in_inPrefixedWrappingKeyBlob);
    if (prefixedKeyBlobIsSoftKeyMint(in_inPrefixedWrappingKeyBlob)) {
        return softKeyMintDevice_->importWrappedKey(
            in_inWrappedKeyData, wrappingKeyBlob, in_inMaskingKey, in_inUnwrappingParams,
            in_inPasswordSid, in_inBiometricSid, out_creationResult);
    }

    auto legacyUnwrappingParams = convertKeyParametersToLegacy(in_inUnwrappingParams);
    KMV1::ErrorCode errorCode;
    auto result = mDevice->importWrappedKey(
        in_inWrappedKeyData, wrappingKeyBlob, in_inMaskingKey, legacyUnwrappingParams,
        in_inPasswordSid, in_inBiometricSid,
        [&](V4_0_ErrorCode error, const hidl_vec<uint8_t>& keyBlob,
            const V4_0_KeyCharacteristics& keyCharacteristics) {
            errorCode = convert(error);
            out_creationResult->keyBlob = keyBlobPrefix(keyBlob, false);
            out_creationResult->keyCharacteristics =
                processLegacyCharacteristics(securityLevel_, {}, keyCharacteristics);
        });
    if (!result.isOk()) {
        LOG(ERROR) << __func__ << " transaction failed. " << result.description();
        return convertErrorCode(KMV1::ErrorCode::UNKNOWN_ERROR);
    }
    return convertErrorCode(errorCode);
}

ScopedAStatus KeyMintDevice::upgradeKey(const std::vector<uint8_t>& in_inKeyBlobToUpgrade,
                                        const std::vector<KeyParameter>& in_inUpgradeParams,
                                        std::vector<uint8_t>* _aidl_return) {
    auto legacyUpgradeParams = convertKeyParametersToLegacy(in_inUpgradeParams);
    V4_0_ErrorCode errorCode;

    auto result =
        mDevice->upgradeKey(prefixedKeyBlobRemovePrefix(in_inKeyBlobToUpgrade), legacyUpgradeParams,
                            [&](V4_0_ErrorCode error, const hidl_vec<uint8_t>& upgradedKeyBlob) {
                                errorCode = error;
                                *_aidl_return = keyBlobPrefix(upgradedKeyBlob, false);
                            });
    if (!result.isOk()) {
        LOG(ERROR) << __func__ << " transaction failed. " << result.description();
        return convertErrorCode(KMV1::ErrorCode::UNKNOWN_ERROR);
    }
    return convertErrorCode(errorCode);
}

ScopedAStatus KeyMintDevice::deleteKey(const std::vector<uint8_t>& prefixedKeyBlob) {
    const std::vector<uint8_t>& keyBlob = prefixedKeyBlobRemovePrefix(prefixedKeyBlob);
    if (prefixedKeyBlobIsSoftKeyMint(prefixedKeyBlob)) {
        return softKeyMintDevice_->deleteKey(keyBlob);
    }

    auto result = mDevice->deleteKey(keyBlob);
    if (!result.isOk()) {
        LOG(ERROR) << __func__ << " transaction failed. " << result.description();
        return convertErrorCode(KMV1::ErrorCode::UNKNOWN_ERROR);
    }
    return convertErrorCode(result);
}

ScopedAStatus KeyMintDevice::deleteAllKeys() {
    auto result = mDevice->deleteAllKeys();
    if (!result.isOk()) {
        LOG(ERROR) << __func__ << " transaction failed. " << result.description();
        return convertErrorCode(KMV1::ErrorCode::UNKNOWN_ERROR);
    }
    return convertErrorCode(result);
}

// We're not implementing this.
ScopedAStatus KeyMintDevice::destroyAttestationIds() {
    return ScopedAStatus::fromServiceSpecificError(
        static_cast<int32_t>(V4_0_ErrorCode::UNIMPLEMENTED));
}

ScopedAStatus KeyMintDevice::begin(KeyPurpose in_inPurpose,
                                   const std::vector<uint8_t>& prefixedKeyBlob,
                                   const std::vector<KeyParameter>& in_inParams,
                                   const std::optional<HardwareAuthToken>& in_inAuthToken,
                                   BeginResult* _aidl_return) {
    if (!mOperationSlots.claimSlot()) {
        return convertErrorCode(V4_0_ErrorCode::TOO_MANY_OPERATIONS);
    }

    const std::vector<uint8_t>& in_inKeyBlob = prefixedKeyBlobRemovePrefix(prefixedKeyBlob);
    if (prefixedKeyBlobIsSoftKeyMint(prefixedKeyBlob)) {
        return softKeyMintDevice_->begin(in_inPurpose, in_inKeyBlob, in_inParams, in_inAuthToken,
                                         _aidl_return);
    }

    auto legacyPurpose =
        static_cast<::android::hardware::keymaster::V4_0::KeyPurpose>(in_inPurpose);
    auto legacyParams = convertKeyParametersToLegacy(in_inParams);
    auto legacyAuthToken = convertAuthTokenToLegacy(in_inAuthToken);
    KMV1::ErrorCode errorCode;
    auto result = mDevice->begin(
        legacyPurpose, in_inKeyBlob, legacyParams, legacyAuthToken,
        [&](V4_0_ErrorCode error, const hidl_vec<V4_0_KeyParameter>& outParams,
            uint64_t operationHandle) {
            errorCode = convert(error);
            _aidl_return->challenge = operationHandle;
            _aidl_return->params = convertKeyParametersFromLegacy(outParams);
            _aidl_return->operation = ndk::SharedRefBase::make<KeyMintOperation>(
                mDevice, operationHandle, &mOperationSlots, error == V4_0_ErrorCode::OK);
        });
    if (!result.isOk()) {
        LOG(ERROR) << __func__ << " transaction failed. " << result.description();
        errorCode = KMV1::ErrorCode::UNKNOWN_ERROR;
    }
    if (errorCode != KMV1::ErrorCode::OK) {
        mOperationSlots.freeSlot();
    }
    return convertErrorCode(errorCode);
}

ScopedAStatus KeyMintDevice::deviceLocked(bool passwordOnly,
                                          const std::optional<TimeStampToken>& timestampToken) {
    V4_0_VerificationToken token;
    if (timestampToken.has_value()) {
        token = convertTimestampTokenToLegacy(timestampToken.value());
    }
    auto ret = mDevice->deviceLocked(passwordOnly, token);
    if (!ret.isOk()) {
        return convertErrorCode(KMV1::ErrorCode::UNKNOWN_ERROR);
    } else {
        return convertErrorCode(KMV1::ErrorCode::OK);
    }
}

ScopedAStatus KeyMintDevice::earlyBootEnded() {
    auto ret = mDevice->earlyBootEnded();
    if (!ret.isOk()) {
        return convertErrorCode(KMV1::ErrorCode::UNKNOWN_ERROR);
    } else {
        return convertErrorCode(KMV1::ErrorCode::OK);
    }
}

ScopedAStatus
KeyMintDevice::convertStorageKeyToEphemeral(const std::vector<uint8_t>& prefixedStorageKeyBlob,
                                            std::vector<uint8_t>* ephemeralKeyBlob) {
    KMV1::ErrorCode km_error;

    /*
     * Wrapped storage keys cannot be emulated (and they don't need to, because if a platform
     * supports wrapped storage keys, then the legacy backend will support it too. So error out
     * if the wrapped storage key given is a soft keymint key.
     */
    if (prefixedKeyBlobIsSoftKeyMint(prefixedStorageKeyBlob)) {
        return convertErrorCode(KMV1::ErrorCode::UNIMPLEMENTED);
    }

    const std::vector<uint8_t>& storageKeyBlob =
        prefixedKeyBlobRemovePrefix(prefixedStorageKeyBlob);

    auto hidlCb = [&](V4_0_ErrorCode ret, const hidl_vec<uint8_t>& exportedKeyBlob) {
        km_error = convert(ret);
        if (km_error != KMV1::ErrorCode::OK) return;
        /*
         * This must return the blob without the prefix since it will be used directly
         * as a storage encryption key. But this is alright, since this wrapped ephemeral
         * key shouldn't/won't ever be used with keymint.
         */
        *ephemeralKeyBlob = exportedKeyBlob;
    };

    auto ret = mDevice->exportKey(V4_0_KeyFormat::RAW, storageKeyBlob, {}, {}, hidlCb);
    if (!ret.isOk()) {
        LOG(ERROR) << __func__ << " export_key failed: " << ret.description();
        return convertErrorCode(KMV1::ErrorCode::UNKNOWN_ERROR);
    }
    if (km_error != KMV1::ErrorCode::OK)
        LOG(ERROR) << __func__ << " export_key failed, code " << int32_t(km_error);

    return convertErrorCode(km_error);
}

ScopedAStatus KeyMintDevice::getKeyCharacteristics(
    const std::vector<uint8_t>& prefixedKeyBlob, const std::vector<uint8_t>& appId,
    const std::vector<uint8_t>& appData, std::vector<KeyCharacteristics>* keyCharacteristics) {
    auto [strippedKeyBlob, isSoftware] = dissectPrefixedKeyBlob(prefixedKeyBlob);
    if (isSoftware) {
        return softKeyMintDevice_->getKeyCharacteristics(strippedKeyBlob, appId, appData,
                                                         keyCharacteristics);
    } else {
        KMV1::ErrorCode km_error;
        auto ret = mDevice->getKeyCharacteristics(
            strippedKeyBlob, appId, appData,
            [&](V4_0_ErrorCode errorCode, const V4_0_KeyCharacteristics& v40KeyCharacteristics) {
                km_error = convert(errorCode);
                *keyCharacteristics =
                    processLegacyCharacteristics(securityLevel_, {} /* getParams */,
                                                 v40KeyCharacteristics, true /* kmEnforcedOnly */);
            });

        if (!ret.isOk()) {
            LOG(ERROR) << __func__ << " getKeyCharacteristics failed: " << ret.description();
            return convertErrorCode(KMV1::ErrorCode::UNKNOWN_ERROR);
        }
        if (km_error != KMV1::ErrorCode::OK) {
            LOG(ERROR) << __func__
                       << " getKeyCharacteristics failed with code: " << toString(km_error);
        }

        return convertErrorCode(km_error);
    }
}

ScopedAStatus KeyMintOperation::updateAad(const std::vector<uint8_t>& input,
                                          const std::optional<HardwareAuthToken>& optAuthToken,
                                          const std::optional<TimeStampToken>& optTimeStampToken) {
    V4_0_HardwareAuthToken authToken = convertAuthTokenToLegacy(optAuthToken);
    V4_0_VerificationToken verificationToken = convertTimestampTokenToLegacy(optTimeStampToken);

    KMV1::ErrorCode errorCode;
    auto result = mDevice->update(
        mOperationHandle, {V4_0::makeKeyParameter(V4_0::TAG_ASSOCIATED_DATA, input)}, {}, authToken,
        verificationToken,
        [&](V4_0_ErrorCode error, auto, auto, auto) { errorCode = convert(error); });

    if (!result.isOk()) {
        LOG(ERROR) << __func__ << " transaction failed. " << result.description();
        errorCode = KMV1::ErrorCode::UNKNOWN_ERROR;
    }
    if (errorCode != KMV1::ErrorCode::OK) mOperationSlot.freeSlot();

    return convertErrorCode(errorCode);
}

void KeyMintOperation::setUpdateBuffer(std::vector<uint8_t> data) {
    mUpdateBuffer = std::move(data);
}

const std::vector<uint8_t>&
KeyMintOperation::getExtendedUpdateBuffer(const std::vector<uint8_t>& suffix) {
    if (mUpdateBuffer.empty()) {
        return suffix;
    } else {
        mUpdateBuffer.insert(mUpdateBuffer.end(), suffix.begin(), suffix.end());
        return mUpdateBuffer;
    }
}

ScopedAStatus KeyMintOperation::update(const std::vector<uint8_t>& input_raw,
                                       const std::optional<HardwareAuthToken>& optAuthToken,
                                       const std::optional<TimeStampToken>& optTimeStampToken,
                                       std::vector<uint8_t>* out_output) {
    V4_0_HardwareAuthToken authToken = convertAuthTokenToLegacy(optAuthToken);
    V4_0_VerificationToken verificationToken = convertTimestampTokenToLegacy(optTimeStampToken);

    size_t inputPos = 0;
    *out_output = {};
    KMV1::ErrorCode errorCode = KMV1::ErrorCode::OK;
    auto input = getExtendedUpdateBuffer(input_raw);

    while (inputPos < input.size() && errorCode == KMV1::ErrorCode::OK) {
        uint32_t consumed = 0;
        auto result =
            mDevice->update(mOperationHandle, {} /* inParams */,
                            {input.begin() + inputPos, input.end()}, authToken, verificationToken,
                            [&](V4_0_ErrorCode error, uint32_t inputConsumed, auto /* outParams */,
                                const hidl_vec<uint8_t>& output) {
                                errorCode = convert(error);
                                out_output->insert(out_output->end(), output.begin(), output.end());
                                consumed = inputConsumed;
                            });

        if (!result.isOk()) {
            LOG(ERROR) << __func__ << " transaction failed. " << result.description();
            errorCode = KMV1::ErrorCode::UNKNOWN_ERROR;
        }

        if (errorCode == KMV1::ErrorCode::OK && consumed == 0) {
            // Some very old KM implementations do not buffer sub blocks in certain block modes,
            // instead, the simply return consumed == 0. So we buffer the input here in the
            // hope that we complete the bock in a future call to update.
            setUpdateBuffer({input.begin() + inputPos, input.end()});
            return convertErrorCode(errorCode);
        }
        inputPos += consumed;
    }

    if (errorCode != KMV1::ErrorCode::OK) mOperationSlot.freeSlot();

    return convertErrorCode(errorCode);
}

ScopedAStatus
KeyMintOperation::finish(const std::optional<std::vector<uint8_t>>& in_input,
                         const std::optional<std::vector<uint8_t>>& in_signature,
                         const std::optional<HardwareAuthToken>& in_authToken,
                         const std::optional<TimeStampToken>& in_timeStampToken,
                         const std::optional<std::vector<uint8_t>>& in_confirmationToken,
                         std::vector<uint8_t>* out_output) {
    auto input_raw = in_input.value_or(std::vector<uint8_t>());
    auto input = getExtendedUpdateBuffer(input_raw);
    auto signature = in_signature.value_or(std::vector<uint8_t>());
    V4_0_HardwareAuthToken authToken = convertAuthTokenToLegacy(in_authToken);
    V4_0_VerificationToken verificationToken = convertTimestampTokenToLegacy(in_timeStampToken);

    std::vector<V4_0_KeyParameter> inParams;
    if (in_confirmationToken) {
        inParams.push_back(makeKeyParameter(V4_0::TAG_CONFIRMATION_TOKEN, *in_confirmationToken));
    }

    KMV1::ErrorCode errorCode;
    auto result = mDevice->finish(
        mOperationHandle, inParams, input, signature, authToken, verificationToken,
        [&](V4_0_ErrorCode error, auto /* outParams */, const hidl_vec<uint8_t>& output) {
            errorCode = convert(error);
            *out_output = output;
        });

    mOperationSlot.freeSlot();
    if (!result.isOk()) {
        LOG(ERROR) << __func__ << " transaction failed. " << result.description();
        errorCode = KMV1::ErrorCode::UNKNOWN_ERROR;
    }
    return convertErrorCode(errorCode);
}

ScopedAStatus KeyMintOperation::abort() {
    auto result = mDevice->abort(mOperationHandle);
    mOperationSlot.freeSlot();
    if (!result.isOk()) {
        LOG(ERROR) << __func__ << " transaction failed. " << result.description();
        return convertErrorCode(KMV1::ErrorCode::UNKNOWN_ERROR);
    }
    return convertErrorCode(result);
}

KeyMintOperation::~KeyMintOperation() {
    if (mOperationSlot.hasSlot()) {
        auto error = abort();
        if (!error.isOk()) {
            LOG(WARNING) << "Error calling abort in ~KeyMintOperation: " << error.getMessage();
        }
    }
}

// SecureClock implementation

ScopedAStatus SecureClock::generateTimeStamp(int64_t in_challenge, TimeStampToken* _aidl_return) {
    KMV1::ErrorCode errorCode;
    auto result = mDevice->verifyAuthorization(
        in_challenge, {}, V4_0_HardwareAuthToken(),
        [&](V4_0_ErrorCode error, const V4_0_VerificationToken& token) {
            errorCode = convert(error);
            _aidl_return->challenge = token.challenge;
            _aidl_return->timestamp.milliSeconds = token.timestamp;
            _aidl_return->mac = token.mac;
        });
    if (!result.isOk()) {
        LOG(ERROR) << __func__ << " transaction failed. " << result.description();
        errorCode = KMV1::ErrorCode::UNKNOWN_ERROR;
    }
    return convertErrorCode(errorCode);
}

// SharedSecret implementation

ScopedAStatus SharedSecret::getSharedSecretParameters(SharedSecretParameters* _aidl_return) {
    KMV1::ErrorCode errorCode;
    auto result = mDevice->getHmacSharingParameters(
        [&](V4_0_ErrorCode error, const V4_0_HmacSharingParameters& params) {
            errorCode = convert(error);
            _aidl_return->seed = params.seed;
            std::copy(params.nonce.data(), params.nonce.data() + params.nonce.elementCount(),
                      std::back_inserter(_aidl_return->nonce));
        });
    if (!result.isOk()) {
        LOG(ERROR) << __func__ << " transaction failed. " << result.description();
        errorCode = KMV1::ErrorCode::UNKNOWN_ERROR;
    }
    return convertErrorCode(errorCode);
}

ScopedAStatus
SharedSecret::computeSharedSecret(const std::vector<SharedSecretParameters>& in_params,
                                  std::vector<uint8_t>* _aidl_return) {
    KMV1::ErrorCode errorCode;
    auto legacyParams = convertSharedSecretParametersToLegacy(in_params);
    auto result = mDevice->computeSharedHmac(
        legacyParams, [&](V4_0_ErrorCode error, const hidl_vec<uint8_t>& sharingCheck) {
            errorCode = convert(error);
            *_aidl_return = sharingCheck;
        });
    if (!result.isOk()) {
        LOG(ERROR) << __func__ << " transaction failed. " << result.description();
        errorCode = KMV1::ErrorCode::UNKNOWN_ERROR;
    }
    return convertErrorCode(errorCode);
}

// Certificate implementation

template <KMV1::Tag tag, KMV1::TagType type>
static auto getParam(const std::vector<KeyParameter>& keyParams, KMV1::TypedTag<type, tag> ttag)
    -> decltype(authorizationValue(ttag, KeyParameter())) {
    for (const auto& p : keyParams) {

        if (auto v = authorizationValue(ttag, p)) {
            return v;
        }
    }
    return {};
}

template <typename T>
static bool containsParam(const std::vector<KeyParameter>& keyParams, T ttag) {
    return static_cast<bool>(getParam(keyParams, ttag));
}

// Prefer the smallest.
// If no options are found, return the first.
template <typename T>
static typename KMV1::TypedTag2ValueType<T>::type
getMaximum(const std::vector<KeyParameter>& keyParams, T tag,
           std::vector<typename KMV1::TypedTag2ValueType<T>::type> sortedOptions) {
    auto bestSoFar = sortedOptions.end();
    for (const KeyParameter& kp : keyParams) {
        if (auto value = authorizationValue(tag, kp)) {
            auto candidate = std::find(sortedOptions.begin(), sortedOptions.end(), *value);
            // sortedOptions is sorted from best to worst. `std::distance(first, last)` counts the
            // hops from `first` to `last`. So a better `candidate` yields a positive distance to
            // `bestSoFar`.
            if (std::distance(candidate, bestSoFar) > 0) {
                bestSoFar = candidate;
            }
        }
    }
    if (bestSoFar == sortedOptions.end()) {
        return sortedOptions[0];
    }
    return *bestSoFar;
}

static std::variant<keystore::X509_Ptr, KMV1::ErrorCode>
makeCert(::android::sp<Keymaster> mDevice, const std::vector<KeyParameter>& keyParams,
         const std::vector<uint8_t>& keyBlob) {
    // Start generating the certificate.
    // Get public key for makeCert.
    KMV1::ErrorCode errorCode;
    std::vector<uint8_t> key;
    static std::vector<uint8_t> empty_vector;
    auto unwrapBlob = [&](auto b) -> const std::vector<uint8_t>& {
        if (b)
            return *b;
        else
            return empty_vector;
    };
    auto result = mDevice->exportKey(
        V4_0_KeyFormat::X509, keyBlob, unwrapBlob(getParam(keyParams, KMV1::TAG_APPLICATION_ID)),
        unwrapBlob(getParam(keyParams, KMV1::TAG_APPLICATION_DATA)),
        [&](V4_0_ErrorCode error, const hidl_vec<uint8_t>& keyMaterial) {
            errorCode = convert(error);
            key = keyMaterial;
        });
    if (!result.isOk()) {
        LOG(ERROR) << __func__ << " exportKey transaction failed. " << result.description();
        return KMV1::ErrorCode::UNKNOWN_ERROR;
    }
    if (errorCode != KMV1::ErrorCode::OK) {
        return errorCode;
    }
    // Get pkey for makeCert.
    CBS cbs;
    CBS_init(&cbs, key.data(), key.size());
    auto pkey = EVP_parse_public_key(&cbs);

    // makeCert
    std::optional<std::reference_wrapper<const std::vector<uint8_t>>> subject;
    if (auto blob = getParam(keyParams, KMV1::TAG_CERTIFICATE_SUBJECT)) {
        subject = *blob;
    }

    std::optional<std::reference_wrapper<const std::vector<uint8_t>>> serial;
    if (auto blob = getParam(keyParams, KMV1::TAG_CERTIFICATE_SERIAL)) {
        serial = *blob;
    }

    int64_t activation;
    if (auto date = getParam(keyParams, KMV1::TAG_CERTIFICATE_NOT_BEFORE)) {
        activation = static_cast<int64_t>(*date);
    } else {
        return KMV1::ErrorCode::MISSING_NOT_BEFORE;
    }

    int64_t expiration;
    if (auto date = getParam(keyParams, KMV1::TAG_CERTIFICATE_NOT_AFTER)) {
        expiration = static_cast<int64_t>(*date);
    } else {
        return KMV1::ErrorCode::MISSING_NOT_AFTER;
    }

    auto certOrError = keystore::makeCert(
        pkey, serial, subject, activation, expiration, false /* intentionally left blank */,
        std::nullopt /* intentionally left blank */, std::nullopt /* intentionally left blank */);
    if (std::holds_alternative<keystore::CertUtilsError>(certOrError)) {
        LOG(ERROR) << __func__ << ": Failed to make certificate";
        return KMV1::ErrorCode::UNKNOWN_ERROR;
    }
    return std::move(std::get<keystore::X509_Ptr>(certOrError));
}

static std::variant<keystore::Algo, KMV1::ErrorCode> getKeystoreAlgorithm(Algorithm algorithm) {
    switch (algorithm) {
    case Algorithm::RSA:
        return keystore::Algo::RSA;
    case Algorithm::EC:
        return keystore::Algo::ECDSA;
    default:
        LOG(ERROR) << __func__ << ": This should not be called with symmetric algorithm.";
        return KMV1::ErrorCode::UNKNOWN_ERROR;
    }
}

static std::variant<keystore::Padding, KMV1::ErrorCode> getKeystorePadding(PaddingMode padding) {
    switch (padding) {
    case PaddingMode::RSA_PKCS1_1_5_SIGN:
        return keystore::Padding::PKCS1_5;
    case PaddingMode::RSA_PSS:
        return keystore::Padding::PSS;
    default:
        return keystore::Padding::Ignored;
    }
}

static std::variant<keystore::Digest, KMV1::ErrorCode> getKeystoreDigest(Digest digest) {
    switch (digest) {
    case Digest::SHA1:
        return keystore::Digest::SHA1;
    case Digest::SHA_2_224:
        return keystore::Digest::SHA224;
    case Digest::SHA_2_256:
    case Digest::NONE:
        return keystore::Digest::SHA256;
    case Digest::SHA_2_384:
        return keystore::Digest::SHA384;
    case Digest::SHA_2_512:
        return keystore::Digest::SHA512;
    default:
        LOG(ERROR) << __func__ << ": Unknown digest.";
        return KMV1::ErrorCode::UNKNOWN_ERROR;
    }
}

std::optional<KMV1::ErrorCode>
KeyMintDevice::signCertificate(const std::vector<KeyParameter>& keyParams,
                               const std::vector<uint8_t>& prefixedKeyBlob, X509* cert) {

    auto algorithm = getParam(keyParams, KMV1::TAG_ALGORITHM);
    auto algoOrError = getKeystoreAlgorithm(*algorithm);
    if (std::holds_alternative<KMV1::ErrorCode>(algoOrError)) {
        return std::get<KMV1::ErrorCode>(algoOrError);
    }
    auto algo = std::get<keystore::Algo>(algoOrError);
    auto origPadding = getMaximum(keyParams, KMV1::TAG_PADDING,
                                  {PaddingMode::RSA_PSS, PaddingMode::RSA_PKCS1_1_5_SIGN});
    auto paddingOrError = getKeystorePadding(origPadding);
    if (std::holds_alternative<KMV1::ErrorCode>(paddingOrError)) {
        return std::get<KMV1::ErrorCode>(paddingOrError);
    }
    auto padding = std::get<keystore::Padding>(paddingOrError);
    auto origDigest = getMaximum(keyParams, KMV1::TAG_DIGEST,
                                 {Digest::SHA_2_256, Digest::SHA_2_512, Digest::SHA_2_384,
                                  Digest::SHA_2_224, Digest::SHA1, Digest::NONE});
    auto digestOrError = getKeystoreDigest(origDigest);
    if (std::holds_alternative<KMV1::ErrorCode>(digestOrError)) {
        return std::get<KMV1::ErrorCode>(digestOrError);
    }
    auto digest = std::get<keystore::Digest>(digestOrError);

    KMV1::ErrorCode errorCode = KMV1::ErrorCode::OK;
    auto error = keystore::signCertWith(
        &*cert,
        [&](const uint8_t* data, size_t len) {
            std::vector<uint8_t> dataVec(data, data + len);
            std::vector<KeyParameter> kps = {
                KMV1::makeKeyParameter(KMV1::TAG_DIGEST, origDigest),
            };
            if (algorithm == KMV1::Algorithm::RSA) {
                kps.push_back(KMV1::makeKeyParameter(KMV1::TAG_PADDING, origPadding));
            }
            BeginResult beginResult;
            auto error =
                begin(KeyPurpose::SIGN, prefixedKeyBlob, kps, HardwareAuthToken(), &beginResult);
            if (!error.isOk()) {
                errorCode = toErrorCode(error);
                return std::vector<uint8_t>();
            }

            std::vector<uint8_t> result;
            error = beginResult.operation->finish(dataVec,                     //
                                                  {} /* signature */,          //
                                                  {} /* authToken */,          //
                                                  {} /* timestampToken */,     //
                                                  {} /* confirmationToken */,  //
                                                  &result);
            if (!error.isOk()) {
                errorCode = toErrorCode(error);
                return std::vector<uint8_t>();
            }
            return result;
        },
        algo, padding, digest);
    if (error) {
        LOG(ERROR) << __func__
                   << ": signCertWith failed. (Callback diagnosed: " << toString(errorCode) << ")";
        return KMV1::ErrorCode::UNKNOWN_ERROR;
    }
    if (errorCode != KMV1::ErrorCode::OK) {
        return errorCode;
    }
    return std::nullopt;
}

std::variant<std::vector<Certificate>, KMV1::ErrorCode>
KeyMintDevice::getCertificate(const std::vector<KeyParameter>& keyParams,
                              const std::vector<uint8_t>& prefixedKeyBlob) {
    const std::vector<uint8_t>& keyBlob = prefixedKeyBlobRemovePrefix(prefixedKeyBlob);

    // There are no certificates for symmetric keys.
    auto algorithm = getParam(keyParams, KMV1::TAG_ALGORITHM);
    if (!algorithm) {
        LOG(ERROR) << __func__ << ": Unable to determine key algorithm.";
        return KMV1::ErrorCode::UNKNOWN_ERROR;
    }
    switch (*algorithm) {
    case Algorithm::RSA:
    case Algorithm::EC:
        break;
    default:
        return KMV1::ErrorCode::OK;
    }

    // If attestation was requested, call and use attestKey.
    if (containsParam(keyParams, KMV1::TAG_ATTESTATION_CHALLENGE)) {
        auto legacyParams = convertKeyParametersToLegacy(extractAttestationParams(keyParams));
        std::vector<Certificate> certs;
        KMV1::ErrorCode errorCode = KMV1::ErrorCode::OK;
        auto result = mDevice->attestKey(
            keyBlob, legacyParams,
            [&](V4_0::ErrorCode error, const hidl_vec<hidl_vec<uint8_t>>& certChain) {
                errorCode = convert(error);
                for (const auto& cert : certChain) {
                    Certificate certificate;
                    certificate.encodedCertificate = cert;
                    certs.push_back(certificate);
                }
            });
        if (!result.isOk()) {
            LOG(ERROR) << __func__ << ": Call to attestKey failed.";
            return KMV1::ErrorCode::UNKNOWN_ERROR;
        }
        if (errorCode != KMV1::ErrorCode::OK) {
            return errorCode;
        }
        return certs;
    }

    // makeCert
    auto certOrError = makeCert(mDevice, keyParams, keyBlob);
    if (std::holds_alternative<KMV1::ErrorCode>(certOrError)) {
        return std::get<KMV1::ErrorCode>(certOrError);
    }
    auto cert = std::move(std::get<keystore::X509_Ptr>(certOrError));

    // setIssuer
    auto error = keystore::setIssuer(&*cert, &*cert, false);
    if (error) {
        LOG(ERROR) << __func__ << ": Set issuer failed.";
        return KMV1::ErrorCode::UNKNOWN_ERROR;
    }

    // Signing
    auto canSelfSign =
        std::find_if(keyParams.begin(), keyParams.end(), [&](const KeyParameter& kp) {
            if (auto v = KMV1::authorizationValue(KMV1::TAG_PURPOSE, kp)) {
                return *v == KeyPurpose::SIGN;
            }
            return false;
        }) != keyParams.end();
    auto noAuthRequired = containsParam(keyParams, KMV1::TAG_NO_AUTH_REQUIRED);
    // If we cannot sign because of purpose or authorization requirement,
    if (!(canSelfSign && noAuthRequired)
        // or if self signing fails for any other reason,
        || signCertificate(keyParams, keyBlob, &*cert).has_value()) {
        // we sign with ephemeral key.
        keystore::EVP_PKEY_CTX_Ptr pkey_ctx(EVP_PKEY_CTX_new_id(EVP_PKEY_EC, NULL));
        EVP_PKEY_keygen_init(pkey_ctx.get());
        EVP_PKEY_CTX_set_ec_paramgen_curve_nid(pkey_ctx.get(), NID_X9_62_prime256v1);
        EVP_PKEY* pkey_ptr = nullptr;
        EVP_PKEY_keygen(pkey_ctx.get(), &pkey_ptr);
        error = keystore::signCert(&*cert, pkey_ptr);
        if (error) {
            LOG(ERROR) << __func__ << ": signCert failed.";
            return KMV1::ErrorCode::UNKNOWN_ERROR;
        }
    }

    // encodeCert
    auto encodedCertOrError = keystore::encodeCert(&*cert);
    if (std::holds_alternative<keystore::CertUtilsError>(encodedCertOrError)) {
        LOG(ERROR) << __func__ << ": encodeCert failed.";
        return KMV1::ErrorCode::UNKNOWN_ERROR;
    }

    Certificate certificate{.encodedCertificate =
                                std::get<std::vector<uint8_t>>(encodedCertOrError)};
    std::vector certificates = {certificate};
    return certificates;
}

// Code to find the Keymaster devices (copied from existing code).

// Copied from system/security/keystore/include/keystore/keymaster_types.h.

// Changing this namespace alias will change the keymaster version.
namespace keymasterNs = ::android::hardware::keymaster::V4_1;

using keymasterNs::SecurityLevel;

// Copied from system/security/keystore/KeyStore.h.

using ::android::sp;
using keymasterNs::support::Keymaster;

template <typename T, size_t count> class Devices : public std::array<T, count> {
  public:
    T& operator[](SecurityLevel secLevel) {
        static_assert(uint32_t(SecurityLevel::SOFTWARE) == 0 &&
                          uint32_t(SecurityLevel::TRUSTED_ENVIRONMENT) == 1 &&
                          uint32_t(SecurityLevel::STRONGBOX) == 2,
                      "Numeric values of security levels have changed");
        return std::array<T, count>::at(static_cast<uint32_t>(secLevel));
    }
    T operator[](SecurityLevel secLevel) const {
        if (static_cast<uint32_t>(secLevel) > static_cast<uint32_t>(SecurityLevel::STRONGBOX)) {
            LOG(ERROR) << "Invalid security level requested";
            return {};
        }
        return (*const_cast<Devices*>(this))[secLevel];
    }
};

using KeymasterDevices = Devices<sp<Keymaster>, 3>;

// Copied from system/security/keystore/keystore_main.cpp.

using ::android::hardware::hidl_string;
using keymasterNs::support::Keymaster3;
using keymasterNs::support::Keymaster4;

template <typename Wrapper>
KeymasterDevices enumerateKeymasterDevices(IServiceManager* serviceManager) {
    KeymasterDevices result;
    serviceManager->listManifestByInterface(
        Wrapper::WrappedIKeymasterDevice::descriptor, [&](const hidl_vec<hidl_string>& names) {
            auto try_get_device = [&](const auto& name, bool fail_silent) {
                auto device = Wrapper::WrappedIKeymasterDevice::getService(name);
                if (fail_silent && !device) return;
                CHECK(device) << "Failed to get service for \""
                              << Wrapper::WrappedIKeymasterDevice::descriptor
                              << "\" with interface name \"" << name << "\"";

                sp<Keymaster> kmDevice(new Wrapper(device, name));
                auto halVersion = kmDevice->halVersion();
                SecurityLevel securityLevel = halVersion.securityLevel;
                LOG(INFO) << "found " << Wrapper::WrappedIKeymasterDevice::descriptor
                          << " with interface name " << name << " and seclevel "
                          << toString(securityLevel);
                CHECK(static_cast<uint32_t>(securityLevel) < result.size())
                    << "Security level of \"" << Wrapper::WrappedIKeymasterDevice::descriptor
                    << "\" with interface name \"" << name << "\" out of range";
                auto& deviceSlot = result[securityLevel];
                if (deviceSlot) {
                    if (!fail_silent) {
                        LOG(WARNING) << "Implementation of \""
                                     << Wrapper::WrappedIKeymasterDevice::descriptor
                                     << "\" with interface name \"" << name
                                     << "\" and security level: " << toString(securityLevel)
                                     << " Masked by other implementation of Keymaster";
                    }
                } else {
                    deviceSlot = kmDevice;
                }
            };
            bool has_default = false;
            for (auto& n : names) {
                try_get_device(n, false);
                if (n == "default") has_default = true;
            }
            // Make sure that we always check the default device. If we enumerate only what is
            // known to hwservicemanager, we miss a possible passthrough HAL.
            if (!has_default) {
                try_get_device("default", true /* fail_silent */);
            }
        });
    return result;
}

KeymasterDevices initializeKeymasters() {
    auto serviceManager = IServiceManager::getService();
    CHECK(serviceManager.get()) << "Failed to get ServiceManager";
    auto result = enumerateKeymasterDevices<Keymaster4>(serviceManager.get());
    auto softKeymaster = result[SecurityLevel::SOFTWARE];
    if ((!result[SecurityLevel::TRUSTED_ENVIRONMENT]) && (!result[SecurityLevel::STRONGBOX])) {
        result = enumerateKeymasterDevices<Keymaster3>(serviceManager.get());
    }
    if (softKeymaster) result[SecurityLevel::SOFTWARE] = softKeymaster;
    if (result[SecurityLevel::SOFTWARE] && !result[SecurityLevel::TRUSTED_ENVIRONMENT]) {
        LOG(WARNING) << "No secure Keymaster implementation found, but device offers insecure"
                        " Keymaster HAL. Using as default.";
        result[SecurityLevel::TRUSTED_ENVIRONMENT] = result[SecurityLevel::SOFTWARE];
        result[SecurityLevel::SOFTWARE] = nullptr;
    }
    // The software bit was removed since we do not need it.
    return result;
}

void KeyMintDevice::setNumFreeSlots(uint8_t numFreeSlots) {
    mOperationSlots.setNumFreeSlots(numFreeSlots);
}

// Constructors and helpers.

KeyMintDevice::KeyMintDevice(sp<Keymaster> device, KeyMintSecurityLevel securityLevel)
    : mDevice(device), securityLevel_(securityLevel) {
    if (securityLevel == KeyMintSecurityLevel::STRONGBOX) {
        setNumFreeSlots(3);
    } else {
        setNumFreeSlots(15);
    }

    softKeyMintDevice_.reset(CreateKeyMintDevice(KeyMintSecurityLevel::SOFTWARE));
}

sp<Keymaster> getDevice(KeyMintSecurityLevel securityLevel) {
    static std::mutex mutex;
    static sp<Keymaster> teeDevice;
    static sp<Keymaster> sbDevice;
    std::lock_guard<std::mutex> lock(mutex);
    if (!teeDevice) {
        auto devices = initializeKeymasters();
        teeDevice = devices[V4_0::SecurityLevel::TRUSTED_ENVIRONMENT];
        sbDevice = devices[V4_0::SecurityLevel::STRONGBOX];
    }
    switch (securityLevel) {
    case KeyMintSecurityLevel::TRUSTED_ENVIRONMENT:
        return teeDevice;
    case KeyMintSecurityLevel::STRONGBOX:
        return sbDevice;
    default:
        return {};
    }
}

std::shared_ptr<KeyMintDevice>
KeyMintDevice::createKeyMintDevice(KeyMintSecurityLevel securityLevel) {
    if (auto dev = getDevice(securityLevel)) {
        return ndk::SharedRefBase::make<KeyMintDevice>(std::move(dev), securityLevel);
    }
    return {};
}

std::shared_ptr<SharedSecret> SharedSecret::createSharedSecret(KeyMintSecurityLevel securityLevel) {
    auto device = getDevice(securityLevel);
    if (!device) {
        return {};
    }
    return ndk::SharedRefBase::make<SharedSecret>(std::move(device));
}

std::shared_ptr<SecureClock> SecureClock::createSecureClock(KeyMintSecurityLevel securityLevel) {
    auto device = getDevice(securityLevel);
    if (!device) {
        return {};
    }
    return ndk::SharedRefBase::make<SecureClock>(std::move(device));
}

ScopedAStatus
KeystoreCompatService::getKeyMintDevice(KeyMintSecurityLevel in_securityLevel,
                                        std::shared_ptr<IKeyMintDevice>* _aidl_return) {
    auto i = mDeviceCache.find(in_securityLevel);
    if (i == mDeviceCache.end()) {
        auto device = KeyMintDevice::createKeyMintDevice(in_securityLevel);
        if (!device) {
            return ScopedAStatus::fromStatus(STATUS_NAME_NOT_FOUND);
        }
        i = mDeviceCache.insert(i, {in_securityLevel, std::move(device)});
    }
    *_aidl_return = i->second;
    return ScopedAStatus::ok();
}

ScopedAStatus KeystoreCompatService::getSharedSecret(KeyMintSecurityLevel in_securityLevel,
                                                     std::shared_ptr<ISharedSecret>* _aidl_return) {
    auto i = mSharedSecretCache.find(in_securityLevel);
    if (i == mSharedSecretCache.end()) {
        auto secret = SharedSecret::createSharedSecret(in_securityLevel);
        if (!secret) {
            return ScopedAStatus::fromStatus(STATUS_NAME_NOT_FOUND);
        }
        i = mSharedSecretCache.insert(i, {in_securityLevel, std::move(secret)});
    }
    *_aidl_return = i->second;
    return ScopedAStatus::ok();
}

ScopedAStatus KeystoreCompatService::getSecureClock(std::shared_ptr<ISecureClock>* _aidl_return) {
    if (!mSecureClock) {
        // The legacy verification service was always provided by the TEE variant.
        auto clock = SecureClock::createSecureClock(KeyMintSecurityLevel::TRUSTED_ENVIRONMENT);
        if (!clock) {
            return ScopedAStatus::fromStatus(STATUS_NAME_NOT_FOUND);
        }
        mSecureClock = std::move(clock);
    }
    *_aidl_return = mSecureClock;
    return ScopedAStatus::ok();
}
