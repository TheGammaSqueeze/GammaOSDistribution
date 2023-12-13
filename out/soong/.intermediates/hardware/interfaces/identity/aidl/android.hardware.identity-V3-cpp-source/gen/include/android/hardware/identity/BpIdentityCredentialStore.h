#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/identity/IIdentityCredentialStore.h>

namespace android {

namespace hardware {

namespace identity {

class BpIdentityCredentialStore : public ::android::BpInterface<IIdentityCredentialStore> {
public:
  explicit BpIdentityCredentialStore(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpIdentityCredentialStore() = default;
  ::android::binder::Status getHardwareInformation(::android::hardware::identity::HardwareInformation* _aidl_return) override;
  ::android::binder::Status createCredential(const ::std::string& docType, bool testCredential, ::android::sp<::android::hardware::identity::IWritableIdentityCredential>* _aidl_return) override;
  ::android::binder::Status getCredential(::android::hardware::identity::CipherSuite cipherSuite, const ::std::vector<uint8_t>& credentialData, ::android::sp<::android::hardware::identity::IIdentityCredential>* _aidl_return) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpIdentityCredentialStore

}  // namespace identity

}  // namespace hardware

}  // namespace android
