#pragma once

#include <binder/IInterface.h>
#include <android/security/identity/ICredentialStoreFactory.h>

namespace android {

namespace security {

namespace identity {

class BnCredentialStoreFactory : public ::android::BnInterface<ICredentialStoreFactory> {
public:
  static constexpr uint32_t TRANSACTION_getCredentialStore = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnCredentialStoreFactory();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCredentialStoreFactory

}  // namespace identity

}  // namespace security

}  // namespace android
