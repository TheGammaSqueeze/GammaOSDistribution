#pragma once

#include <binder/IInterface.h>
#include <android/gsi/IGsiService.h>

namespace android {

namespace gsi {

class BnGsiService : public ::android::BnInterface<IGsiService> {
public:
  static constexpr uint32_t TRANSACTION_commitGsiChunkFromStream = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getInstallProgress = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_setGsiAshmem = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_commitGsiChunkFromAshmem = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_enableGsi = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_enableGsiAsync = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_isGsiEnabled = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_cancelGsiInstall = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_isGsiInstallInProgress = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_removeGsi = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_removeGsiAsync = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_disableGsi = ::android::IBinder::FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_isGsiInstalled = ::android::IBinder::FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_isGsiRunning = ::android::IBinder::FIRST_CALL_TRANSACTION + 13;
  static constexpr uint32_t TRANSACTION_getActiveDsuSlot = ::android::IBinder::FIRST_CALL_TRANSACTION + 14;
  static constexpr uint32_t TRANSACTION_getInstalledGsiImageDir = ::android::IBinder::FIRST_CALL_TRANSACTION + 15;
  static constexpr uint32_t TRANSACTION_getInstalledDsuSlots = ::android::IBinder::FIRST_CALL_TRANSACTION + 16;
  static constexpr uint32_t TRANSACTION_openInstall = ::android::IBinder::FIRST_CALL_TRANSACTION + 17;
  static constexpr uint32_t TRANSACTION_closeInstall = ::android::IBinder::FIRST_CALL_TRANSACTION + 18;
  static constexpr uint32_t TRANSACTION_createPartition = ::android::IBinder::FIRST_CALL_TRANSACTION + 19;
  static constexpr uint32_t TRANSACTION_closePartition = ::android::IBinder::FIRST_CALL_TRANSACTION + 20;
  static constexpr uint32_t TRANSACTION_zeroPartition = ::android::IBinder::FIRST_CALL_TRANSACTION + 21;
  static constexpr uint32_t TRANSACTION_openImageService = ::android::IBinder::FIRST_CALL_TRANSACTION + 22;
  static constexpr uint32_t TRANSACTION_dumpDeviceMapperDevices = ::android::IBinder::FIRST_CALL_TRANSACTION + 23;
  static constexpr uint32_t TRANSACTION_getAvbPublicKey = ::android::IBinder::FIRST_CALL_TRANSACTION + 24;
  static constexpr uint32_t TRANSACTION_suggestScratchSize = ::android::IBinder::FIRST_CALL_TRANSACTION + 25;
  explicit BnGsiService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnGsiService

}  // namespace gsi

}  // namespace android
