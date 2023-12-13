#pragma once

#include <android/security/identity/AccessControlProfileParcel.h>
#include <android/security/identity/EntryNamespaceParcel.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace security {

namespace identity {

class IWritableCredential : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(WritableCredential)
  virtual ::android::binder::Status getCredentialKeyCertificateChain(const ::std::vector<uint8_t>& challenge, ::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status personalize(const ::std::vector<::android::security::identity::AccessControlProfileParcel>& accessControlProfiles, const ::std::vector<::android::security::identity::EntryNamespaceParcel>& entryNamespaces, int64_t secureUserId, ::std::vector<uint8_t>* _aidl_return) = 0;
};  // class IWritableCredential

class IWritableCredentialDefault : public IWritableCredential {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getCredentialKeyCertificateChain(const ::std::vector<uint8_t>&, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status personalize(const ::std::vector<::android::security::identity::AccessControlProfileParcel>&, const ::std::vector<::android::security::identity::EntryNamespaceParcel>&, int64_t, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IWritableCredentialDefault

}  // namespace identity

}  // namespace security

}  // namespace android
