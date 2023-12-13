#pragma once

#include <binder/IInterface.h>
#include <android/security/identity/IWritableCredential.h>

namespace android {

namespace security {

namespace identity {

class BnWritableCredential : public ::android::BnInterface<IWritableCredential> {
public:
  static constexpr uint32_t TRANSACTION_getCredentialKeyCertificateChain = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_personalize = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnWritableCredential();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnWritableCredential

}  // namespace identity

}  // namespace security

}  // namespace android
