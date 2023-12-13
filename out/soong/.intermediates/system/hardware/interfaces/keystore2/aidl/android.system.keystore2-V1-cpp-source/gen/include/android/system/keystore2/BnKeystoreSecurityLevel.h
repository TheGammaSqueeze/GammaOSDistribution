#pragma once

#include <binder/IInterface.h>
#include <android/system/keystore2/IKeystoreSecurityLevel.h>

namespace android {

namespace system {

namespace keystore2 {

class BnKeystoreSecurityLevel : public ::android::BnInterface<IKeystoreSecurityLevel> {
public:
  static constexpr uint32_t TRANSACTION_createOperation = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_generateKey = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_importKey = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_importWrappedKey = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_convertStorageKeyToEphemeral = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_deleteKey = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_getInterfaceVersion = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777214;
  static constexpr uint32_t TRANSACTION_getInterfaceHash = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777213;
  explicit BnKeystoreSecurityLevel();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
  int32_t getInterfaceVersion() final;
  std::string getInterfaceHash();
};  // class BnKeystoreSecurityLevel

}  // namespace keystore2

}  // namespace system

}  // namespace android
