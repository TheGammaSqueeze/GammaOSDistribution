#pragma once

#include <android/security/identity/ICredentialStore.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace security {

namespace identity {

class ICredentialStoreFactory : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(CredentialStoreFactory)
  enum  : int32_t {
    CREDENTIAL_STORE_TYPE_DEFAULT = 0,
    CREDENTIAL_STORE_TYPE_DIRECT_ACCESS = 1,
  };
  virtual ::android::binder::Status getCredentialStore(int32_t credentialStoreType, ::android::sp<::android::security::identity::ICredentialStore>* _aidl_return) = 0;
};  // class ICredentialStoreFactory

class ICredentialStoreFactoryDefault : public ICredentialStoreFactory {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getCredentialStore(int32_t, ::android::sp<::android::security::identity::ICredentialStore>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICredentialStoreFactoryDefault

}  // namespace identity

}  // namespace security

}  // namespace android
