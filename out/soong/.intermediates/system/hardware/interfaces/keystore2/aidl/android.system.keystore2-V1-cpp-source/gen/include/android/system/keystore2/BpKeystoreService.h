#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/system/keystore2/IKeystoreService.h>

namespace android {

namespace system {

namespace keystore2 {

class BpKeystoreService : public ::android::BpInterface<IKeystoreService> {
public:
  explicit BpKeystoreService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpKeystoreService() = default;
  ::android::binder::Status getSecurityLevel(::android::hardware::security::keymint::SecurityLevel securityLevel, ::android::sp<::android::system::keystore2::IKeystoreSecurityLevel>* _aidl_return) override;
  ::android::binder::Status getKeyEntry(const ::android::system::keystore2::KeyDescriptor& key, ::android::system::keystore2::KeyEntryResponse* _aidl_return) override;
  ::android::binder::Status updateSubcomponent(const ::android::system::keystore2::KeyDescriptor& key, const ::std::optional<::std::vector<uint8_t>>& publicCert, const ::std::optional<::std::vector<uint8_t>>& certificateChain) override;
  ::android::binder::Status listEntries(::android::system::keystore2::Domain domain, int64_t nspace, ::std::vector<::android::system::keystore2::KeyDescriptor>* _aidl_return) override;
  ::android::binder::Status deleteKey(const ::android::system::keystore2::KeyDescriptor& key) override;
  ::android::binder::Status grant(const ::android::system::keystore2::KeyDescriptor& key, int32_t granteeUid, int32_t accessVector, ::android::system::keystore2::KeyDescriptor* _aidl_return) override;
  ::android::binder::Status ungrant(const ::android::system::keystore2::KeyDescriptor& key, int32_t granteeUid) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpKeystoreService

}  // namespace keystore2

}  // namespace system

}  // namespace android
