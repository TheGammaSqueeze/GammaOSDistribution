/*
 * Copyright (C) 2021 The Android Open Source Project
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

package android.hardware.security.keymint;

import android.hardware.security.keymint.Certificate;
import android.hardware.security.keymint.KeyCharacteristics;

/**
 * This structure is returned when a new key is created with generateKey(), importKey() or
 * importWrappedKey().
 * @hide
 */
@VintfStability
parcelable KeyCreationResult {
    /**
     * `keyBlob` is an descriptor of the generated/imported key key.
     */
    byte[] keyBlob;

    /**
     * `keyCharacteristics` is a description of the generated key in the form of authorization lists
     * associated with security levels.  The rules that IKeyMintDevice implementations must use for
     * deciding whether a given tag from `keyParams` argument to the generation/import method should
     * be returned in `keyCharacteristics` are:
     *
     * - If the semantics of the tag are fully enforced by the IKeyMintDevice, without any
     *   assistance from components running at other security levels, it should be included in an
     *   entry with the SecurityLevel of the IKeyMintDevice.
     * - If the semantics of the tag are fully enforced, but with the assistance of components
     *   running at another SecurityLevel, it should be included in an entry with the minimum
     *   SecurityLevel of the involved components.  For example if a StrongBox IKeyMintDevice relies
     *   on a TEE to validate biometric authentication, biometric authentication tags go in an entry
     *   with SecurityLevel::TRUSTED_ENVIRONMENT.
     * - If the semantics are not enforced by KeyMint at all, SecurityLevel::KEYSTORE is used to
     *   indicate that Keystore should enforce.  Note that in Keymaster (predecessor to KeyMint),
     *   these tags would have been in SecurityLevel::SOFTWARE.
     */
    KeyCharacteristics[] keyCharacteristics;

    /**
     * If the generated/imported key is an asymmetric key, `certificateChain` will contain a chain
     * of one or more certificates.
     *
     * There are a few variations in what is contained in `certificateChain`, depending on whether
     * the caller requested attestation, whether they provided an attestation key (via the
     * `attestationKey` parameter of `generateKey()`, `importKey()` or `importWrappedKey()`), and in
     * the non-attestation case, whether the key can self-sign.
     *
     * 1.  Asymmetric key attestation with factory key.  If Tag::ATTESTATION_CHALLENGE is provided
     *     and the `attestationKey` parameter on the generate/import call is null, the returned
     *     certificate chain must contain an attestation certificate signed with a factory-
     *     provisioned attestation key, and the full certificate chain for that factory-provisioned
     *     attestation key.  Tag::ATTESTATION_APPLICATION_ID must also be provided when the
     *     ATTESTATION_CHALLENGE is provided, otherwise ATTESTATION_APPLICATION_ID_MISSING will be
     *     returned.  KeyMint implementations are not required to support factory-provisioned
     *     attestation keys.
     *
     * 2.  Asymmetric key attestation with caller-provided key.  If Tag::ATTESTATION_CHALLENGE is
     *     provided and the `attestationKey` parameter on the generate/import call is non-null and
     *     contains the key blob of a key with KeyPurpose::ATTEST_KEY, the returned certificate
     *     chain must contain only an attestation certificate signed with the specified key.  The
     *     caller must know the certificate chain for the provided key.  Tag::
     *     ATTESTATION_APPLICATION_ID must also be provided when the ATTESTATION_CHALLENGE is
     *     provided, otherwise ATTESTATION_APPLICATION_ID_MISSING will be returned.
     *
     * 3.  Asymmetric key non-attestation with signing key.  If Tag::ATTESTATION_CHALLENGE is not
     *     provided and the generated/imported key has KeyPurpose::SIGN, then the returned
     *     certificate chain must contain only a single self-signed certificate with no attestation
     *     extension.  Tag::ATTESTATION_APPLICATION_ID will be ignored if provided.
     *
     * 4.  Asymmetric key non-attestation with non-signing key.  If TAG::ATTESTATION_CHALLENGE is
     *     not provided and the generated/imported key does not have KeyPurpose::SIGN, then the
     *     returned certificate chain must contain only a single certificate with an empty signature
     *     and no attestation extension.  Tag::ATTESTATION_APPLICATION_ID will be ignored if
     *     provided.
     *
     * 5.  Symmetric key.  If the generated/imported key is symmetric, the certificate chain must
     *     return empty, any Tag::ATTESTATION_CHALLENGE or Tag::ATTESTATION_APPLICATION_ID inputs,
     *     if provided, are ignored.
     *
     * In all cases except the symmetric key, the contents of certificate chain must be DER-encoded
     * X.509 certificates ordered such that each certificate is signed by the subsequent one, up to
     * the root which must be self-signed (or contain a fake signature in the case of case 4 above).
     * The first certificate in the chain signs the public key info of the newly-generated or
     * newly-imported key pair.  In the attestation cases (1 and 2 above), the first certificate
     * must also satisfy some other requirements:
     *
     * o It must have the serial number provided in Tag::CERTIFICATE_SERIAL, or default to 1 if the
     *   tag is not provided.
     *
     * o It must have the subject provided in Tag::CERTIFICATE_SUBJECT, or default to CN="Android
     *   Keystore Key", if the tag is not provided.
     *
     * o It must contain the notBefore and notAfter date-times specified in
     *   Tag::CERTIFICATE_NOT_BEFORE and Tag::CERTIFICATE_NOT_AFTER, respectively.
     *
     * o It must contain a Key Usage extension with:
     *
     *    - the digitalSignature bit set iff the attested key has KeyPurpose::SIGN,
     *    - the dataEncipherment bit set iff the attested key has KeyPurpose::DECRYPT,
     *    - the keyEncipherment bit set iff the attested key has KeyPurpose::WRAP_KEY,
     *    - the keyAgreement bit set iff the attested key has KeyPurpose::AGREE_KEY, and
     *    - the keyCertSignBit set iff the attested key has KeyPurpose::ATTEST_KEY.
     *
     * o it must contain a KeyDescription attestation extension with OID 1.3.6.1.4.1.11129.2.1.17.
     *
     * The KeyDescription content is defined by the following ASN.1 schema, which is mostly a
     * straightforward translation of the KeyMint tag/value parameter lists to ASN.1.
     *
     * KeyDescription ::= SEQUENCE {
     *     attestationVersion         INTEGER, # Value 100
     *     attestationSecurityLevel   SecurityLevel, # See below
     *     keyMintVersion             INTEGER, # Value 100
     *     keymintSecurityLevel       SecurityLevel, # See below
     *     attestationChallenge       OCTET_STRING, # Tag::ATTESTATION_CHALLENGE from attestParams
     *     uniqueId                   OCTET_STRING, # Empty unless key has Tag::INCLUDE_UNIQUE_ID
     *     softwareEnforced           AuthorizationList, # See below
     *     hardwareEnforced           AuthorizationList, # See below
     * }
     *
     * SecurityLevel ::= ENUMERATED {
     *     Software                   (0),
     *     TrustedEnvironment         (1),
     *     StrongBox                  (2),
     * }
     *
     * RootOfTrust ::= SEQUENCE {
     *     verifiedBootKey            OCTET_STRING,
     *     deviceLocked               BOOLEAN,
     *     verifiedBootState          VerifiedBootState,
     *     # verifiedBootHash must contain 32-byte value that represents the state of all binaries
     *     # or other components validated by verified boot.  Updating any verified binary or
     *     # component must cause this value to change.
     *     verifiedBootHash           OCTET_STRING,
     * }
     *
     * VerifiedBootState ::= ENUMERATED {
     *     Verified                   (0),
     *     SelfSigned                 (1),
     *     Unverified                 (2),
     *     Failed                     (3),
     * }
     *
     * AuthorizationList ::= SEQUENCE {
     *     purpose                    [1] EXPLICIT SET OF INTEGER OPTIONAL,
     *     algorithm                  [2] EXPLICIT INTEGER OPTIONAL,
     *     keySize                    [3] EXPLICIT INTEGER OPTIONAL,
     *     digest                     [5] EXPLICIT SET OF INTEGER OPTIONAL,
     *     padding                    [6] EXPLICIT SET OF INTEGER OPTIONAL,
     *     ecCurve                    [10] EXPLICIT INTEGER OPTIONAL,
     *     rsaPublicExponent          [200] EXPLICIT INTEGER OPTIONAL,
     *     mgfDigest                  [203] EXPLICIT SET OF INTEGER OPTIONAL,
     *     rollbackResistance         [303] EXPLICIT NULL OPTIONAL,
     *     earlyBootOnly              [305] EXPLICIT NULL OPTIONAL,
     *     activeDateTime             [400] EXPLICIT INTEGER OPTIONAL,
     *     originationExpireDateTime  [401] EXPLICIT INTEGER OPTIONAL,
     *     usageExpireDateTime        [402] EXPLICIT INTEGER OPTIONAL,
     *     usageCountLimit            [405] EXPLICIT INTEGER OPTIONAL,
     *     noAuthRequired             [503] EXPLICIT NULL OPTIONAL,
     *     userAuthType               [504] EXPLICIT INTEGER OPTIONAL,
     *     authTimeout                [505] EXPLICIT INTEGER OPTIONAL,
     *     allowWhileOnBody           [506] EXPLICIT NULL OPTIONAL,
     *     trustedUserPresenceReq     [507] EXPLICIT NULL OPTIONAL,
     *     trustedConfirmationReq     [508] EXPLICIT NULL OPTIONAL,
     *     unlockedDeviceReq          [509] EXPLICIT NULL OPTIONAL,
     *     creationDateTime           [701] EXPLICIT INTEGER OPTIONAL,
     *     origin                     [702] EXPLICIT INTEGER OPTIONAL,
     *     rootOfTrust                [704] EXPLICIT RootOfTrust OPTIONAL,
     *     osVersion                  [705] EXPLICIT INTEGER OPTIONAL,
     *     osPatchLevel               [706] EXPLICIT INTEGER OPTIONAL,
     *     attestationApplicationId   [709] EXPLICIT OCTET_STRING OPTIONAL,
     *     attestationIdBrand         [710] EXPLICIT OCTET_STRING OPTIONAL,
     *     attestationIdDevice        [711] EXPLICIT OCTET_STRING OPTIONAL,
     *     attestationIdProduct       [712] EXPLICIT OCTET_STRING OPTIONAL,
     *     attestationIdSerial        [713] EXPLICIT OCTET_STRING OPTIONAL,
     *     attestationIdImei          [714] EXPLICIT OCTET_STRING OPTIONAL,
     *     attestationIdMeid          [715] EXPLICIT OCTET_STRING OPTIONAL,
     *     attestationIdManufacturer  [716] EXPLICIT OCTET_STRING OPTIONAL,
     *     attestationIdModel         [717] EXPLICIT OCTET_STRING OPTIONAL,
     *     vendorPatchLevel           [718] EXPLICIT INTEGER OPTIONAL,
     *     bootPatchLevel             [719] EXPLICIT INTEGER OPTIONAL,
     *     deviceUniqueAttestation    [720] EXPLICIT NULL OPTIONAL,
     * }
     */
    Certificate[] certificateChain;
}
