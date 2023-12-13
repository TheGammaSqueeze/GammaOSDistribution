#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/security/identity/ICredential.h>

namespace android {

namespace security {

namespace identity {

class BpCredential : public ::android::BpInterface<ICredential> {
public:
  explicit BpCredential(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpCredential() = default;
  ::android::binder::Status createEphemeralKeyPair(::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status setReaderEphemeralPublicKey(const ::std::vector<uint8_t>& publicKey) override;
  ::android::binder::Status deleteCredential(::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status deleteWithChallenge(const ::std::vector<uint8_t>& challenge, ::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status proveOwnership(const ::std::vector<uint8_t>& challenge, ::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status getCredentialKeyCertificateChain(::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status selectAuthKey(bool allowUsingExhaustedKeys, bool allowUsingExpiredKeys, int64_t* _aidl_return) override;
  ::android::binder::Status getEntries(const ::std::vector<uint8_t>& requestMessage, const ::std::vector<::android::security::identity::RequestNamespaceParcel>& requestNamespaces, const ::std::vector<uint8_t>& sessionTranscript, const ::std::vector<uint8_t>& readerSignature, bool allowUsingExhaustedKeys, bool allowUsingExpiredKeys, ::android::security::identity::GetEntriesResultParcel* _aidl_return) override;
  ::android::binder::Status setAvailableAuthenticationKeys(int32_t keyCount, int32_t maxUsesPerKey) override;
  ::android::binder::Status getAuthKeysNeedingCertification(::std::vector<::android::security::identity::AuthKeyParcel>* _aidl_return) override;
  ::android::binder::Status storeStaticAuthenticationData(const ::android::security::identity::AuthKeyParcel& authenticationKey, const ::std::vector<uint8_t>& staticAuthData) override;
  ::android::binder::Status storeStaticAuthenticationDataWithExpiration(const ::android::security::identity::AuthKeyParcel& authenticationKey, int64_t expirationDateMillisSinceEpoch, const ::std::vector<uint8_t>& staticAuthData) override;
  ::android::binder::Status getAuthenticationDataUsageCount(::std::vector<int32_t>* _aidl_return) override;
  ::android::binder::Status update(::android::sp<::android::security::identity::IWritableCredential>* _aidl_return) override;
};  // class BpCredential

}  // namespace identity

}  // namespace security

}  // namespace android
