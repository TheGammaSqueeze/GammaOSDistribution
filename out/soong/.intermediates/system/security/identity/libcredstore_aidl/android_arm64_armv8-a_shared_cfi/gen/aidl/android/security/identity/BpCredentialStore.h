#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/security/identity/ICredentialStore.h>

namespace android {

namespace security {

namespace identity {

class BpCredentialStore : public ::android::BpInterface<ICredentialStore> {
public:
  explicit BpCredentialStore(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpCredentialStore() = default;
  ::android::binder::Status getSecurityHardwareInfo(::android::security::identity::SecurityHardwareInfoParcel* _aidl_return) override;
  ::android::binder::Status createCredential(const ::std::string& credentialName, const ::std::string& docType, ::android::sp<::android::security::identity::IWritableCredential>* _aidl_return) override;
  ::android::binder::Status getCredentialByName(const ::std::string& credentialName, int32_t cipherSuite, ::android::sp<::android::security::identity::ICredential>* _aidl_return) override;
};  // class BpCredentialStore

}  // namespace identity

}  // namespace security

}  // namespace android
