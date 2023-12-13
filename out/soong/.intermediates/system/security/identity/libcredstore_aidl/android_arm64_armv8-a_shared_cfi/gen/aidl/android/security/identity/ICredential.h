#pragma once

#include <android/security/identity/AuthKeyParcel.h>
#include <android/security/identity/GetEntriesResultParcel.h>
#include <android/security/identity/IWritableCredential.h>
#include <android/security/identity/RequestNamespaceParcel.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace security {

namespace identity {

class ICredential : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Credential)
  enum  : int32_t {
    STATUS_OK = 0,
    STATUS_NO_SUCH_ENTRY = 1,
    STATUS_NOT_REQUESTED = 2,
    STATUS_NOT_IN_REQUEST_MESSAGE = 3,
    STATUS_USER_AUTHENTICATION_FAILED = 4,
    STATUS_READER_AUTHENTICATION_FAILED = 5,
    STATUS_NO_ACCESS_CONTROL_PROFILES = 6,
  };
  virtual ::android::binder::Status createEphemeralKeyPair(::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status setReaderEphemeralPublicKey(const ::std::vector<uint8_t>& publicKey) = 0;
  virtual ::android::binder::Status deleteCredential(::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status deleteWithChallenge(const ::std::vector<uint8_t>& challenge, ::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status proveOwnership(const ::std::vector<uint8_t>& challenge, ::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status getCredentialKeyCertificateChain(::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status selectAuthKey(bool allowUsingExhaustedKeys, bool allowUsingExpiredKeys, int64_t* _aidl_return) = 0;
  virtual ::android::binder::Status getEntries(const ::std::vector<uint8_t>& requestMessage, const ::std::vector<::android::security::identity::RequestNamespaceParcel>& requestNamespaces, const ::std::vector<uint8_t>& sessionTranscript, const ::std::vector<uint8_t>& readerSignature, bool allowUsingExhaustedKeys, bool allowUsingExpiredKeys, ::android::security::identity::GetEntriesResultParcel* _aidl_return) = 0;
  virtual ::android::binder::Status setAvailableAuthenticationKeys(int32_t keyCount, int32_t maxUsesPerKey) = 0;
  virtual ::android::binder::Status getAuthKeysNeedingCertification(::std::vector<::android::security::identity::AuthKeyParcel>* _aidl_return) = 0;
  virtual ::android::binder::Status storeStaticAuthenticationData(const ::android::security::identity::AuthKeyParcel& authenticationKey, const ::std::vector<uint8_t>& staticAuthData) = 0;
  virtual ::android::binder::Status storeStaticAuthenticationDataWithExpiration(const ::android::security::identity::AuthKeyParcel& authenticationKey, int64_t expirationDateMillisSinceEpoch, const ::std::vector<uint8_t>& staticAuthData) = 0;
  virtual ::android::binder::Status getAuthenticationDataUsageCount(::std::vector<int32_t>* _aidl_return) = 0;
  virtual ::android::binder::Status update(::android::sp<::android::security::identity::IWritableCredential>* _aidl_return) = 0;
};  // class ICredential

class ICredentialDefault : public ICredential {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status createEphemeralKeyPair(::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setReaderEphemeralPublicKey(const ::std::vector<uint8_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status deleteCredential(::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status deleteWithChallenge(const ::std::vector<uint8_t>&, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status proveOwnership(const ::std::vector<uint8_t>&, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCredentialKeyCertificateChain(::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status selectAuthKey(bool, bool, int64_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getEntries(const ::std::vector<uint8_t>&, const ::std::vector<::android::security::identity::RequestNamespaceParcel>&, const ::std::vector<uint8_t>&, const ::std::vector<uint8_t>&, bool, bool, ::android::security::identity::GetEntriesResultParcel*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setAvailableAuthenticationKeys(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getAuthKeysNeedingCertification(::std::vector<::android::security::identity::AuthKeyParcel>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status storeStaticAuthenticationData(const ::android::security::identity::AuthKeyParcel&, const ::std::vector<uint8_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status storeStaticAuthenticationDataWithExpiration(const ::android::security::identity::AuthKeyParcel&, int64_t, const ::std::vector<uint8_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getAuthenticationDataUsageCount(::std::vector<int32_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status update(::android::sp<::android::security::identity::IWritableCredential>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICredentialDefault

}  // namespace identity

}  // namespace security

}  // namespace android
