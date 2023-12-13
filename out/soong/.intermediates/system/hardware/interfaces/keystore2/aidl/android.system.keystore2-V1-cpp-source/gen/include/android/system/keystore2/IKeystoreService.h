#pragma once

#include <android/hardware/security/keymint/SecurityLevel.h>
#include <android/system/keystore2/Domain.h>
#include <android/system/keystore2/IKeystoreSecurityLevel.h>
#include <android/system/keystore2/KeyDescriptor.h>
#include <android/system/keystore2/KeyEntryResponse.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace system {

namespace keystore2 {

class IKeystoreService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(KeystoreService)
  const int32_t VERSION = 1;
  const std::string HASH = "19e8b65277839bad0ab335c781e3c652324920ce";
  virtual ::android::binder::Status getSecurityLevel(::android::hardware::security::keymint::SecurityLevel securityLevel, ::android::sp<::android::system::keystore2::IKeystoreSecurityLevel>* _aidl_return) = 0;
  virtual ::android::binder::Status getKeyEntry(const ::android::system::keystore2::KeyDescriptor& key, ::android::system::keystore2::KeyEntryResponse* _aidl_return) = 0;
  virtual ::android::binder::Status updateSubcomponent(const ::android::system::keystore2::KeyDescriptor& key, const ::std::optional<::std::vector<uint8_t>>& publicCert, const ::std::optional<::std::vector<uint8_t>>& certificateChain) = 0;
  virtual ::android::binder::Status listEntries(::android::system::keystore2::Domain domain, int64_t nspace, ::std::vector<::android::system::keystore2::KeyDescriptor>* _aidl_return) = 0;
  virtual ::android::binder::Status deleteKey(const ::android::system::keystore2::KeyDescriptor& key) = 0;
  virtual ::android::binder::Status grant(const ::android::system::keystore2::KeyDescriptor& key, int32_t granteeUid, int32_t accessVector, ::android::system::keystore2::KeyDescriptor* _aidl_return) = 0;
  virtual ::android::binder::Status ungrant(const ::android::system::keystore2::KeyDescriptor& key, int32_t granteeUid) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IKeystoreService

class IKeystoreServiceDefault : public IKeystoreService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getSecurityLevel(::android::hardware::security::keymint::SecurityLevel, ::android::sp<::android::system::keystore2::IKeystoreSecurityLevel>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getKeyEntry(const ::android::system::keystore2::KeyDescriptor&, ::android::system::keystore2::KeyEntryResponse*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status updateSubcomponent(const ::android::system::keystore2::KeyDescriptor&, const ::std::optional<::std::vector<uint8_t>>&, const ::std::optional<::std::vector<uint8_t>>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status listEntries(::android::system::keystore2::Domain, int64_t, ::std::vector<::android::system::keystore2::KeyDescriptor>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status deleteKey(const ::android::system::keystore2::KeyDescriptor&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status grant(const ::android::system::keystore2::KeyDescriptor&, int32_t, int32_t, ::android::system::keystore2::KeyDescriptor*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ungrant(const ::android::system::keystore2::KeyDescriptor&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IKeystoreServiceDefault

}  // namespace keystore2

}  // namespace system

}  // namespace android
