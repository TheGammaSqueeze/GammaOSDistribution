#pragma once

#include <android/hardware/identity/Certificate.h>
#include <android/hardware/identity/SecureAccessControlProfile.h>
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

class IWritableIdentityCredential : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(WritableIdentityCredential)
  const int32_t VERSION = 3;
  const std::string HASH = "1b6d65bb827aecd66860e06a8806dc77a8d3382b";
  virtual ::android::binder::Status getAttestationCertificate(const ::std::vector<uint8_t>& attestationApplicationId, const ::std::vector<uint8_t>& attestationChallenge, ::std::vector<::android::hardware::identity::Certificate>* _aidl_return) = 0;
  virtual ::android::binder::Status startPersonalization(int32_t accessControlProfileCount, const ::std::vector<int32_t>& entryCounts) = 0;
  virtual ::android::binder::Status addAccessControlProfile(int32_t id, const ::android::hardware::identity::Certificate& readerCertificate, bool userAuthenticationRequired, int64_t timeoutMillis, int64_t secureUserId, ::android::hardware::identity::SecureAccessControlProfile* _aidl_return) = 0;
  virtual ::android::binder::Status beginAddEntry(const ::std::vector<int32_t>& accessControlProfileIds, const ::std::string& nameSpace, const ::std::string& name, int32_t entrySize) = 0;
  virtual ::android::binder::Status addEntryValue(const ::std::vector<uint8_t>& content, ::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status finishAddingEntries(::std::vector<uint8_t>* credentialData, ::std::vector<uint8_t>* proofOfProvisioningSignature) = 0;
  virtual ::android::binder::Status setExpectedProofOfProvisioningSize(int32_t expectedProofOfProvisioningSize) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IWritableIdentityCredential

class IWritableIdentityCredentialDefault : public IWritableIdentityCredential {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getAttestationCertificate(const ::std::vector<uint8_t>&, const ::std::vector<uint8_t>&, ::std::vector<::android::hardware::identity::Certificate>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status startPersonalization(int32_t, const ::std::vector<int32_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status addAccessControlProfile(int32_t, const ::android::hardware::identity::Certificate&, bool, int64_t, int64_t, ::android::hardware::identity::SecureAccessControlProfile*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status beginAddEntry(const ::std::vector<int32_t>&, const ::std::string&, const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status addEntryValue(const ::std::vector<uint8_t>&, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status finishAddingEntries(::std::vector<uint8_t>*, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setExpectedProofOfProvisioningSize(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IWritableIdentityCredentialDefault

}  // namespace identity

}  // namespace hardware

}  // namespace android
