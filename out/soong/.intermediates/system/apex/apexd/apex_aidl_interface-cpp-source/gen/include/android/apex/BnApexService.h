#pragma once

#include <binder/IInterface.h>
#include <android/apex/IApexService.h>

namespace android {

namespace apex {

class BnApexService : public ::android::BnInterface<IApexService> {
public:
  static constexpr uint32_t TRANSACTION_submitStagedSession = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_markStagedSessionReady = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_markStagedSessionSuccessful = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_getSessions = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_getStagedSessionInfo = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_getActivePackages = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_getAllPackages = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_abortStagedSession = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_revertActiveSessions = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_snapshotCeData = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_restoreCeData = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_destroyDeSnapshots = ::android::IBinder::FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_destroyCeSnapshots = ::android::IBinder::FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_destroyCeSnapshotsNotSpecified = ::android::IBinder::FIRST_CALL_TRANSACTION + 13;
  static constexpr uint32_t TRANSACTION_unstagePackages = ::android::IBinder::FIRST_CALL_TRANSACTION + 14;
  static constexpr uint32_t TRANSACTION_getActivePackage = ::android::IBinder::FIRST_CALL_TRANSACTION + 15;
  static constexpr uint32_t TRANSACTION_activatePackage = ::android::IBinder::FIRST_CALL_TRANSACTION + 16;
  static constexpr uint32_t TRANSACTION_deactivatePackage = ::android::IBinder::FIRST_CALL_TRANSACTION + 17;
  static constexpr uint32_t TRANSACTION_preinstallPackages = ::android::IBinder::FIRST_CALL_TRANSACTION + 18;
  static constexpr uint32_t TRANSACTION_postinstallPackages = ::android::IBinder::FIRST_CALL_TRANSACTION + 19;
  static constexpr uint32_t TRANSACTION_stagePackages = ::android::IBinder::FIRST_CALL_TRANSACTION + 20;
  static constexpr uint32_t TRANSACTION_resumeRevertIfNeeded = ::android::IBinder::FIRST_CALL_TRANSACTION + 21;
  static constexpr uint32_t TRANSACTION_remountPackages = ::android::IBinder::FIRST_CALL_TRANSACTION + 22;
  static constexpr uint32_t TRANSACTION_recollectPreinstalledData = ::android::IBinder::FIRST_CALL_TRANSACTION + 23;
  static constexpr uint32_t TRANSACTION_recollectDataApex = ::android::IBinder::FIRST_CALL_TRANSACTION + 24;
  static constexpr uint32_t TRANSACTION_markBootCompleted = ::android::IBinder::FIRST_CALL_TRANSACTION + 25;
  static constexpr uint32_t TRANSACTION_calculateSizeForCompressedApex = ::android::IBinder::FIRST_CALL_TRANSACTION + 26;
  static constexpr uint32_t TRANSACTION_reserveSpaceForCompressedApex = ::android::IBinder::FIRST_CALL_TRANSACTION + 27;
  static constexpr uint32_t TRANSACTION_installAndActivatePackage = ::android::IBinder::FIRST_CALL_TRANSACTION + 28;
  explicit BnApexService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnApexService

}  // namespace apex

}  // namespace android
