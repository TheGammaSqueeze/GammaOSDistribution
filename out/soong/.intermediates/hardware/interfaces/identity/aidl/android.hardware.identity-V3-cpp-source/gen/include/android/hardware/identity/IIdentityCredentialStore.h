#pragma once

#include <android/hardware/identity/CipherSuite.h>
#include <android/hardware/identity/HardwareInformation.h>
#include <android/hardware/identity/IIdentityCredential.h>
#include <android/hardware/identity/IWritableIdentityCredential.h>
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

class IIdentityCredentialStore : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(IdentityCredentialStore)
  const int32_t VERSION = 3;
  const std::string HASH = "1b6d65bb827aecd66860e06a8806dc77a8d3382b";
  enum  : int32_t {
    STATUS_OK = 0,
    STATUS_FAILED = 1,
    STATUS_CIPHER_SUITE_NOT_SUPPORTED = 2,
    STATUS_INVALID_DATA = 3,
    STATUS_INVALID_AUTH_TOKEN = 4,
    STATUS_INVALID_ITEMS_REQUEST_MESSAGE = 5,
    STATUS_READER_SIGNATURE_CHECK_FAILED = 6,
    STATUS_EPHEMERAL_PUBLIC_KEY_NOT_FOUND = 7,
    STATUS_USER_AUTHENTICATION_FAILED = 8,
    STATUS_READER_AUTHENTICATION_FAILED = 9,
    STATUS_NO_ACCESS_CONTROL_PROFILES = 10,
    STATUS_NOT_IN_REQUEST_MESSAGE = 11,
    STATUS_SESSION_TRANSCRIPT_MISMATCH = 12,
  };
  virtual ::android::binder::Status getHardwareInformation(::android::hardware::identity::HardwareInformation* _aidl_return) = 0;
  virtual ::android::binder::Status createCredential(const ::std::string& docType, bool testCredential, ::android::sp<::android::hardware::identity::IWritableIdentityCredential>* _aidl_return) = 0;
  virtual ::android::binder::Status getCredential(::android::hardware::identity::CipherSuite cipherSuite, const ::std::vector<uint8_t>& credentialData, ::android::sp<::android::hardware::identity::IIdentityCredential>* _aidl_return) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IIdentityCredentialStore

class IIdentityCredentialStoreDefault : public IIdentityCredentialStore {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getHardwareInformation(::android::hardware::identity::HardwareInformation*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createCredential(const ::std::string&, bool, ::android::sp<::android::hardware::identity::IWritableIdentityCredential>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCredential(::android::hardware::identity::CipherSuite, const ::std::vector<uint8_t>&, ::android::sp<::android::hardware::identity::IIdentityCredential>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IIdentityCredentialStoreDefault

}  // namespace identity

}  // namespace hardware

}  // namespace android
