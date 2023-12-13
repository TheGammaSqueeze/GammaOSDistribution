#pragma once

#include <binder/IInterface.h>
#include <android/security/identity/ICredentialStore.h>

namespace android {

namespace security {

namespace identity {

class BnCredentialStore : public ::android::BnInterface<ICredentialStore> {
public:
  static constexpr uint32_t TRANSACTION_getSecurityHardwareInfo = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_createCredential = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getCredentialByName = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  explicit BnCredentialStore();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCredentialStore

}  // namespace identity

}  // namespace security

}  // namespace android
