#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/security/identity/ICredentialStoreFactory.h>

namespace android {

namespace security {

namespace identity {

class BpCredentialStoreFactory : public ::android::BpInterface<ICredentialStoreFactory> {
public:
  explicit BpCredentialStoreFactory(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpCredentialStoreFactory() = default;
  ::android::binder::Status getCredentialStore(int32_t credentialStoreType, ::android::sp<::android::security::identity::ICredentialStore>* _aidl_return) override;
};  // class BpCredentialStoreFactory

}  // namespace identity

}  // namespace security

}  // namespace android
