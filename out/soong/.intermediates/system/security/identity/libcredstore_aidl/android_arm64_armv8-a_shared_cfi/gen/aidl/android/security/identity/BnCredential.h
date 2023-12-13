#pragma once

#include <binder/IInterface.h>
#include <android/security/identity/ICredential.h>

namespace android {

namespace security {

namespace identity {

class BnCredential : public ::android::BnInterface<ICredential> {
public:
  static constexpr uint32_t TRANSACTION_createEphemeralKeyPair = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_setReaderEphemeralPublicKey = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_deleteCredential = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_deleteWithChallenge = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_proveOwnership = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_getCredentialKeyCertificateChain = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_selectAuthKey = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_getEntries = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_setAvailableAuthenticationKeys = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_getAuthKeysNeedingCertification = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_storeStaticAuthenticationData = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_storeStaticAuthenticationDataWithExpiration = ::android::IBinder::FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_getAuthenticationDataUsageCount = ::android::IBinder::FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_update = ::android::IBinder::FIRST_CALL_TRANSACTION + 13;
  explicit BnCredential();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCredential

}  // namespace identity

}  // namespace security

}  // namespace android
