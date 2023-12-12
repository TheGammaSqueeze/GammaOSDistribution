#pragma once

#include <binder/IInterface.h>
#include <android/os/IVold.h>

namespace android {

namespace os {

class BnVold : public ::android::BnInterface<IVold> {
public:
  static constexpr uint32_t TRANSACTION_setListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_abortFuse = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_monitor = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_reset = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_shutdown = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_onUserAdded = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_onUserRemoved = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_onUserStarted = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_onUserStopped = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_addAppIds = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_addSandboxIds = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_onSecureKeyguardStateChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_partition = ::android::IBinder::FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_forgetPartition = ::android::IBinder::FIRST_CALL_TRANSACTION + 13;
  static constexpr uint32_t TRANSACTION_mount = ::android::IBinder::FIRST_CALL_TRANSACTION + 14;
  static constexpr uint32_t TRANSACTION_unmount = ::android::IBinder::FIRST_CALL_TRANSACTION + 15;
  static constexpr uint32_t TRANSACTION_format = ::android::IBinder::FIRST_CALL_TRANSACTION + 16;
  static constexpr uint32_t TRANSACTION_benchmark = ::android::IBinder::FIRST_CALL_TRANSACTION + 17;
  static constexpr uint32_t TRANSACTION_moveStorage = ::android::IBinder::FIRST_CALL_TRANSACTION + 18;
  static constexpr uint32_t TRANSACTION_remountUid = ::android::IBinder::FIRST_CALL_TRANSACTION + 19;
  static constexpr uint32_t TRANSACTION_remountAppStorageDirs = ::android::IBinder::FIRST_CALL_TRANSACTION + 20;
  static constexpr uint32_t TRANSACTION_unmountAppStorageDirs = ::android::IBinder::FIRST_CALL_TRANSACTION + 21;
  static constexpr uint32_t TRANSACTION_setupAppDir = ::android::IBinder::FIRST_CALL_TRANSACTION + 22;
  static constexpr uint32_t TRANSACTION_fixupAppDir = ::android::IBinder::FIRST_CALL_TRANSACTION + 23;
  static constexpr uint32_t TRANSACTION_ensureAppDirsCreated = ::android::IBinder::FIRST_CALL_TRANSACTION + 24;
  static constexpr uint32_t TRANSACTION_createObb = ::android::IBinder::FIRST_CALL_TRANSACTION + 25;
  static constexpr uint32_t TRANSACTION_destroyObb = ::android::IBinder::FIRST_CALL_TRANSACTION + 26;
  static constexpr uint32_t TRANSACTION_fstrim = ::android::IBinder::FIRST_CALL_TRANSACTION + 27;
  static constexpr uint32_t TRANSACTION_runIdleMaint = ::android::IBinder::FIRST_CALL_TRANSACTION + 28;
  static constexpr uint32_t TRANSACTION_abortIdleMaint = ::android::IBinder::FIRST_CALL_TRANSACTION + 29;
  static constexpr uint32_t TRANSACTION_mountAppFuse = ::android::IBinder::FIRST_CALL_TRANSACTION + 30;
  static constexpr uint32_t TRANSACTION_unmountAppFuse = ::android::IBinder::FIRST_CALL_TRANSACTION + 31;
  static constexpr uint32_t TRANSACTION_fdeCheckPassword = ::android::IBinder::FIRST_CALL_TRANSACTION + 32;
  static constexpr uint32_t TRANSACTION_fdeRestart = ::android::IBinder::FIRST_CALL_TRANSACTION + 33;
  static constexpr uint32_t TRANSACTION_fdeComplete = ::android::IBinder::FIRST_CALL_TRANSACTION + 34;
  static constexpr uint32_t TRANSACTION_fdeEnable = ::android::IBinder::FIRST_CALL_TRANSACTION + 35;
  static constexpr uint32_t TRANSACTION_fdeChangePassword = ::android::IBinder::FIRST_CALL_TRANSACTION + 36;
  static constexpr uint32_t TRANSACTION_fdeVerifyPassword = ::android::IBinder::FIRST_CALL_TRANSACTION + 37;
  static constexpr uint32_t TRANSACTION_fdeGetField = ::android::IBinder::FIRST_CALL_TRANSACTION + 38;
  static constexpr uint32_t TRANSACTION_fdeSetField = ::android::IBinder::FIRST_CALL_TRANSACTION + 39;
  static constexpr uint32_t TRANSACTION_fdeGetPasswordType = ::android::IBinder::FIRST_CALL_TRANSACTION + 40;
  static constexpr uint32_t TRANSACTION_fdeGetPassword = ::android::IBinder::FIRST_CALL_TRANSACTION + 41;
  static constexpr uint32_t TRANSACTION_fdeClearPassword = ::android::IBinder::FIRST_CALL_TRANSACTION + 42;
  static constexpr uint32_t TRANSACTION_fbeEnable = ::android::IBinder::FIRST_CALL_TRANSACTION + 43;
  static constexpr uint32_t TRANSACTION_mountDefaultEncrypted = ::android::IBinder::FIRST_CALL_TRANSACTION + 44;
  static constexpr uint32_t TRANSACTION_initUser0 = ::android::IBinder::FIRST_CALL_TRANSACTION + 45;
  static constexpr uint32_t TRANSACTION_isConvertibleToFbe = ::android::IBinder::FIRST_CALL_TRANSACTION + 46;
  static constexpr uint32_t TRANSACTION_mountFstab = ::android::IBinder::FIRST_CALL_TRANSACTION + 47;
  static constexpr uint32_t TRANSACTION_encryptFstab = ::android::IBinder::FIRST_CALL_TRANSACTION + 48;
  static constexpr uint32_t TRANSACTION_setStorageBindingSeed = ::android::IBinder::FIRST_CALL_TRANSACTION + 49;
  static constexpr uint32_t TRANSACTION_createUserKey = ::android::IBinder::FIRST_CALL_TRANSACTION + 50;
  static constexpr uint32_t TRANSACTION_destroyUserKey = ::android::IBinder::FIRST_CALL_TRANSACTION + 51;
  static constexpr uint32_t TRANSACTION_addUserKeyAuth = ::android::IBinder::FIRST_CALL_TRANSACTION + 52;
  static constexpr uint32_t TRANSACTION_clearUserKeyAuth = ::android::IBinder::FIRST_CALL_TRANSACTION + 53;
  static constexpr uint32_t TRANSACTION_fixateNewestUserKeyAuth = ::android::IBinder::FIRST_CALL_TRANSACTION + 54;
  static constexpr uint32_t TRANSACTION_getUnlockedUsers = ::android::IBinder::FIRST_CALL_TRANSACTION + 55;
  static constexpr uint32_t TRANSACTION_unlockUserKey = ::android::IBinder::FIRST_CALL_TRANSACTION + 56;
  static constexpr uint32_t TRANSACTION_lockUserKey = ::android::IBinder::FIRST_CALL_TRANSACTION + 57;
  static constexpr uint32_t TRANSACTION_prepareUserStorage = ::android::IBinder::FIRST_CALL_TRANSACTION + 58;
  static constexpr uint32_t TRANSACTION_destroyUserStorage = ::android::IBinder::FIRST_CALL_TRANSACTION + 59;
  static constexpr uint32_t TRANSACTION_prepareSandboxForApp = ::android::IBinder::FIRST_CALL_TRANSACTION + 60;
  static constexpr uint32_t TRANSACTION_destroySandboxForApp = ::android::IBinder::FIRST_CALL_TRANSACTION + 61;
  static constexpr uint32_t TRANSACTION_startCheckpoint = ::android::IBinder::FIRST_CALL_TRANSACTION + 62;
  static constexpr uint32_t TRANSACTION_needsCheckpoint = ::android::IBinder::FIRST_CALL_TRANSACTION + 63;
  static constexpr uint32_t TRANSACTION_needsRollback = ::android::IBinder::FIRST_CALL_TRANSACTION + 64;
  static constexpr uint32_t TRANSACTION_isCheckpointing = ::android::IBinder::FIRST_CALL_TRANSACTION + 65;
  static constexpr uint32_t TRANSACTION_abortChanges = ::android::IBinder::FIRST_CALL_TRANSACTION + 66;
  static constexpr uint32_t TRANSACTION_commitChanges = ::android::IBinder::FIRST_CALL_TRANSACTION + 67;
  static constexpr uint32_t TRANSACTION_prepareCheckpoint = ::android::IBinder::FIRST_CALL_TRANSACTION + 68;
  static constexpr uint32_t TRANSACTION_restoreCheckpoint = ::android::IBinder::FIRST_CALL_TRANSACTION + 69;
  static constexpr uint32_t TRANSACTION_restoreCheckpointPart = ::android::IBinder::FIRST_CALL_TRANSACTION + 70;
  static constexpr uint32_t TRANSACTION_markBootAttempt = ::android::IBinder::FIRST_CALL_TRANSACTION + 71;
  static constexpr uint32_t TRANSACTION_supportsCheckpoint = ::android::IBinder::FIRST_CALL_TRANSACTION + 72;
  static constexpr uint32_t TRANSACTION_supportsBlockCheckpoint = ::android::IBinder::FIRST_CALL_TRANSACTION + 73;
  static constexpr uint32_t TRANSACTION_supportsFileCheckpoint = ::android::IBinder::FIRST_CALL_TRANSACTION + 74;
  static constexpr uint32_t TRANSACTION_resetCheckpoint = ::android::IBinder::FIRST_CALL_TRANSACTION + 75;
  static constexpr uint32_t TRANSACTION_earlyBootEnded = ::android::IBinder::FIRST_CALL_TRANSACTION + 76;
  static constexpr uint32_t TRANSACTION_createStubVolume = ::android::IBinder::FIRST_CALL_TRANSACTION + 77;
  static constexpr uint32_t TRANSACTION_destroyStubVolume = ::android::IBinder::FIRST_CALL_TRANSACTION + 78;
  static constexpr uint32_t TRANSACTION_openAppFuseFile = ::android::IBinder::FIRST_CALL_TRANSACTION + 79;
  static constexpr uint32_t TRANSACTION_incFsEnabled = ::android::IBinder::FIRST_CALL_TRANSACTION + 80;
  static constexpr uint32_t TRANSACTION_mountIncFs = ::android::IBinder::FIRST_CALL_TRANSACTION + 81;
  static constexpr uint32_t TRANSACTION_unmountIncFs = ::android::IBinder::FIRST_CALL_TRANSACTION + 82;
  static constexpr uint32_t TRANSACTION_setIncFsMountOptions = ::android::IBinder::FIRST_CALL_TRANSACTION + 83;
  static constexpr uint32_t TRANSACTION_bindMount = ::android::IBinder::FIRST_CALL_TRANSACTION + 84;
  static constexpr uint32_t TRANSACTION_destroyDsuMetadataKey = ::android::IBinder::FIRST_CALL_TRANSACTION + 85;
  explicit BnVold();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnVold

}  // namespace os

}  // namespace android
