#pragma once

#include <android/hardware/identity/Certificate.h>
#include <android/hardware/identity/IWritableIdentityCredential.h>
#include <android/hardware/identity/RequestNamespace.h>
#include <android/hardware/identity/SecureAccessControlProfile.h>
#include <android/hardware/keymaster/HardwareAuthToken.h>
#include <android/hardware/keymaster/VerificationToken.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace hardware {

namespace identity {

class IIdentityCredential : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(IdentityCredential)
  const int32_t VERSION = 3;
  const std::string HASH = "1b6d65bb827aecd66860e06a8806dc77a8d3382b";
  virtual ::android::binder::Status deleteCredential(::std::vector<uint8_t>* _aidl_return) __attribute__((deprecated("use deleteCredentalWithChallenge() instead."))) = 0;
  virtual ::android::binder::Status createEphemeralKeyPair(::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status setReaderEphemeralPublicKey(const ::std::vector<uint8_t>& publicKey) = 0;
  virtual ::android::binder::Status createAuthChallenge(int64_t* _aidl_return) = 0;
  virtual ::android::binder::Status startRetrieval(const ::std::vector<::android::hardware::identity::SecureAccessControlProfile>& accessControlProfiles, const ::android::hardware::keymaster::HardwareAuthToken& authToken, const ::std::vector<uint8_t>& itemsRequest, const ::std::vector<uint8_t>& signingKeyBlob, const ::std::vector<uint8_t>& sessionTranscript, const ::std::vector<uint8_t>& readerSignature, const ::std::vector<int32_t>& requestCounts) = 0;
  virtual ::android::binder::Status startRetrieveEntryValue(const ::std::string& nameSpace, const ::std::string& name, int32_t entrySize, const ::std::vector<int32_t>& accessControlProfileIds) = 0;
  virtual ::android::binder::Status retrieveEntryValue(const ::std::vector<uint8_t>& encryptedContent, ::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status finishRetrieval(::std::vector<uint8_t>* mac, ::std::vector<uint8_t>* deviceNameSpaces) = 0;
  virtual ::android::binder::Status generateSigningKeyPair(::std::vector<uint8_t>* signingKeyBlob, ::android::hardware::identity::Certificate* _aidl_return) = 0;
  virtual ::android::binder::Status setRequestedNamespaces(const ::std::vector<::android::hardware::identity::RequestNamespace>& requestNamespaces) = 0;
  virtual ::android::binder::Status setVerificationToken(const ::android::hardware::keymaster::VerificationToken& verificationToken) = 0;
  virtual ::android::binder::Status deleteCredentialWithChallenge(const ::std::vector<uint8_t>& challenge, ::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status proveOwnership(const ::std::vector<uint8_t>& challenge, ::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status updateCredential(::android::sp<::android::hardware::identity::IWritableIdentityCredential>* _aidl_return) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IIdentityCredential

class IIdentityCredentialDefault : public IIdentityCredential {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status deleteCredential(::std::vector<uint8_t>*) override __attribute__((deprecated("use deleteCredentalWithChallenge() instead."))) {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createEphemeralKeyPair(::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setReaderEphemeralPublicKey(const ::std::vector<uint8_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createAuthChallenge(int64_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status startRetrieval(const ::std::vector<::android::hardware::identity::SecureAccessControlProfile>&, const ::android::hardware::keymaster::HardwareAuthToken&, const ::std::vector<uint8_t>&, const ::std::vector<uint8_t>&, const ::std::vector<uint8_t>&, const ::std::vector<uint8_t>&, const ::std::vector<int32_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status startRetrieveEntryValue(const ::std::string&, const ::std::string&, int32_t, const ::std::vector<int32_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status retrieveEntryValue(const ::std::vector<uint8_t>&, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status finishRetrieval(::std::vector<uint8_t>*, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status generateSigningKeyPair(::std::vector<uint8_t>*, ::android::hardware::identity::Certificate*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setRequestedNamespaces(const ::std::vector<::android::hardware::identity::RequestNamespace>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setVerificationToken(const ::android::hardware::keymaster::VerificationToken&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status deleteCredentialWithChallenge(const ::std::vector<uint8_t>&, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status proveOwnership(const ::std::vector<uint8_t>&, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status updateCredential(::android::sp<::android::hardware::identity::IWritableIdentityCredential>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IIdentityCredentialDefault

}  // namespace identity

}  // namespace hardware

}  // namespace android
