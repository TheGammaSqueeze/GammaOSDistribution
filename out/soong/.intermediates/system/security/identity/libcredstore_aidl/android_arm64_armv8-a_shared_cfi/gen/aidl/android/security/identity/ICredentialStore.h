#pragma once

#include <android/security/identity/ICredential.h>
#include <android/security/identity/IWritableCredential.h>
#include <android/security/identity/SecurityHardwareInfoParcel.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <utils/StrongPointer.h>

namespace android {

namespace security {

namespace identity {

class ICredentialStore : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(CredentialStore)
  enum  : int32_t {
    ERROR_NONE = 0,
    ERROR_GENERIC = 1,
    ERROR_ALREADY_PERSONALIZED = 2,
    ERROR_NO_SUCH_CREDENTIAL = 3,
    ERROR_CIPHER_SUITE_NOT_SUPPORTED = 4,
    ERROR_EPHEMERAL_PUBLIC_KEY_NOT_FOUND = 5,
    ERROR_NO_AUTHENTICATION_KEY_AVAILABLE = 6,
    ERROR_INVALID_READER_SIGNATURE = 7,
    ERROR_DOCUMENT_TYPE_NOT_SUPPORTED = 8,
    ERROR_AUTHENTICATION_KEY_NOT_FOUND = 9,
    ERROR_INVALID_ITEMS_REQUEST_MESSAGE = 10,
    ERROR_SESSION_TRANSCRIPT_MISMATCH = 11,
    ERROR_NOT_SUPPORTED = 12,
  };
  virtual ::android::binder::Status getSecurityHardwareInfo(::android::security::identity::SecurityHardwareInfoParcel* _aidl_return) = 0;
  virtual ::android::binder::Status createCredential(const ::std::string& credentialName, const ::std::string& docType, ::android::sp<::android::security::identity::IWritableCredential>* _aidl_return) = 0;
  virtual ::android::binder::Status getCredentialByName(const ::std::string& credentialName, int32_t cipherSuite, ::android::sp<::android::security::identity::ICredential>* _aidl_return) = 0;
};  // class ICredentialStore

class ICredentialStoreDefault : public ICredentialStore {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getSecurityHardwareInfo(::android::security::identity::SecurityHardwareInfoParcel*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createCredential(const ::std::string&, const ::std::string&, ::android::sp<::android::security::identity::IWritableCredential>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCredentialByName(const ::std::string&, int32_t, ::android::sp<::android::security::identity::ICredential>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICredentialStoreDefault

}  // namespace identity

}  // namespace security

}  // namespace android
