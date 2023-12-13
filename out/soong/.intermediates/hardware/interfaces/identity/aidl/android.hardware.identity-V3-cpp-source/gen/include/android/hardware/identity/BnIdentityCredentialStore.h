#pragma once

#include <binder/IInterface.h>
#include <android/hardware/identity/IIdentityCredentialStore.h>

namespace android {

namespace hardware {

namespace identity {

class BnIdentityCredentialStore : public ::android::BnInterface<IIdentityCredentialStore> {
public:
  static constexpr uint32_t TRANSACTION_getHardwareInformation = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_createCredential = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getCredential = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_getInterfaceVersion = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777214;
  static constexpr uint32_t TRANSACTION_getInterfaceHash = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777213;
  explicit BnIdentityCredentialStore();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
  int32_t getInterfaceVersion() final;
  std::string getInterfaceHash();
};  // class BnIdentityCredentialStore

}  // namespace identity

}  // namespace hardware

}  // namespace android
