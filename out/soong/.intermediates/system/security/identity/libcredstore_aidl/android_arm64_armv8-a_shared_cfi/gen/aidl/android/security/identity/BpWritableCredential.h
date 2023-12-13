#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/security/identity/IWritableCredential.h>

namespace android {

namespace security {

namespace identity {

class BpWritableCredential : public ::android::BpInterface<IWritableCredential> {
public:
  explicit BpWritableCredential(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpWritableCredential() = default;
  ::android::binder::Status getCredentialKeyCertificateChain(const ::std::vector<uint8_t>& challenge, ::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status personalize(const ::std::vector<::android::security::identity::AccessControlProfileParcel>& accessControlProfiles, const ::std::vector<::android::security::identity::EntryNamespaceParcel>& entryNamespaces, int64_t secureUserId, ::std::vector<uint8_t>* _aidl_return) override;
};  // class BpWritableCredential

}  // namespace identity

}  // namespace security

}  // namespace android
