#pragma once

#include <android-base/unique_fd.h>
#include <android/os/IVoldListener.h>
#include <android/os/IVoldMountCallback.h>
#include <android/os/IVoldTaskListener.h>
#include <android/os/incremental/IncrementalFileSystemControlParcel.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <string>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace os {

class IVold : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Vold)
  enum  : int32_t {
    ENCRYPTION_FLAG_NO_UI = 4,
    ENCRYPTION_STATE_NONE = 1,
    ENCRYPTION_STATE_OK = 0,
    ENCRYPTION_STATE_ERROR_UNKNOWN = -1,
    ENCRYPTION_STATE_ERROR_INCOMPLETE = -2,
    ENCRYPTION_STATE_ERROR_INCONSISTENT = -3,
    ENCRYPTION_STATE_ERROR_CORRUPT = -4,
    FSTRIM_FLAG_DEEP_TRIM = 1,
    MOUNT_FLAG_PRIMARY = 1,
    MOUNT_FLAG_VISIBLE = 2,
    PARTITION_TYPE_PUBLIC = 0,
    PARTITION_TYPE_PRIVATE = 1,
    PARTITION_TYPE_MIXED = 2,
    PASSWORD_TYPE_PASSWORD = 0,
    PASSWORD_TYPE_DEFAULT = 1,
    PASSWORD_TYPE_PATTERN = 2,
    PASSWORD_TYPE_PIN = 3,
    STORAGE_FLAG_DE = 1,
    STORAGE_FLAG_CE = 2,
    REMOUNT_MODE_NONE = 0,
    REMOUNT_MODE_DEFAULT = 1,
    REMOUNT_MODE_INSTALLER = 2,
    REMOUNT_MODE_PASS_THROUGH = 3,
    REMOUNT_MODE_ANDROID_WRITABLE = 4,
    VOLUME_STATE_UNMOUNTED = 0,
    VOLUME_STATE_CHECKING = 1,
    VOLUME_STATE_MOUNTED = 2,
    VOLUME_STATE_MOUNTED_READ_ONLY = 3,
    VOLUME_STATE_FORMATTING = 4,
    VOLUME_STATE_EJECTING = 5,
    VOLUME_STATE_UNMOUNTABLE = 6,
    VOLUME_STATE_REMOVED = 7,
    VOLUME_STATE_BAD_REMOVAL = 8,
    VOLUME_TYPE_PUBLIC = 0,
    VOLUME_TYPE_PRIVATE = 1,
    VOLUME_TYPE_EMULATED = 2,
    VOLUME_TYPE_ASEC = 3,
    VOLUME_TYPE_OBB = 4,
    VOLUME_TYPE_STUB = 5,
  };
  virtual ::android::binder::Status setListener(const ::android::sp<::android::os::IVoldListener>& listener) = 0;
  virtual ::android::binder::Status abortFuse() = 0;
  virtual ::android::binder::Status monitor() = 0;
  virtual ::android::binder::Status reset() = 0;
  virtual ::android::binder::Status shutdown() = 0;
  virtual ::android::binder::Status onUserAdded(int32_t userId, int32_t userSerial) = 0;
  virtual ::android::binder::Status onUserRemoved(int32_t userId) = 0;
  virtual ::android::binder::Status onUserStarted(int32_t userId) = 0;
  virtual ::android::binder::Status onUserStopped(int32_t userId) = 0;
  virtual ::android::binder::Status addAppIds(const ::std::vector<::std::string>& packageNames, const ::std::vector<int32_t>& appIds) = 0;
  virtual ::android::binder::Status addSandboxIds(const ::std::vector<int32_t>& appIds, const ::std::vector<::std::string>& sandboxIds) = 0;
  virtual ::android::binder::Status onSecureKeyguardStateChanged(bool isShowing) = 0;
  virtual ::android::binder::Status partition(const ::std::string& diskId, int32_t partitionType, int32_t ratio) = 0;
  virtual ::android::binder::Status forgetPartition(const ::std::string& partGuid, const ::std::string& fsUuid) = 0;
  virtual ::android::binder::Status mount(const ::std::string& volId, int32_t mountFlags, int32_t mountUserId, const ::android::sp<::android::os::IVoldMountCallback>& callback) = 0;
  virtual ::android::binder::Status unmount(const ::std::string& volId) = 0;
  virtual ::android::binder::Status format(const ::std::string& volId, const ::std::string& fsType) = 0;
  virtual ::android::binder::Status benchmark(const ::std::string& volId, const ::android::sp<::android::os::IVoldTaskListener>& listener) = 0;
  virtual ::android::binder::Status moveStorage(const ::std::string& fromVolId, const ::std::string& toVolId, const ::android::sp<::android::os::IVoldTaskListener>& listener) = 0;
  virtual ::android::binder::Status remountUid(int32_t uid, int32_t remountMode) = 0;
  virtual ::android::binder::Status remountAppStorageDirs(int32_t uid, int32_t pid, const ::std::vector<::std::string>& packageNames) = 0;
  virtual ::android::binder::Status unmountAppStorageDirs(int32_t uid, int32_t pid, const ::std::vector<::std::string>& packageNames) = 0;
  virtual ::android::binder::Status setupAppDir(const ::std::string& path, int32_t appUid) = 0;
  virtual ::android::binder::Status fixupAppDir(const ::std::string& path, int32_t appUid) = 0;
  virtual ::android::binder::Status ensureAppDirsCreated(const ::std::vector<::std::string>& paths, int32_t appUid) = 0;
  virtual ::android::binder::Status createObb(const ::std::string& sourcePath, const ::std::string& sourceKey, int32_t ownerGid, ::std::string* _aidl_return) = 0;
  virtual ::android::binder::Status destroyObb(const ::std::string& volId) = 0;
  virtual ::android::binder::Status fstrim(int32_t fstrimFlags, const ::android::sp<::android::os::IVoldTaskListener>& listener) = 0;
  virtual ::android::binder::Status runIdleMaint(const ::android::sp<::android::os::IVoldTaskListener>& listener) = 0;
  virtual ::android::binder::Status abortIdleMaint(const ::android::sp<::android::os::IVoldTaskListener>& listener) = 0;
  virtual ::android::binder::Status mountAppFuse(int32_t uid, int32_t mountId, ::android::base::unique_fd* _aidl_return) = 0;
  virtual ::android::binder::Status unmountAppFuse(int32_t uid, int32_t mountId) = 0;
  virtual ::android::binder::Status fdeCheckPassword(const ::std::string& password) = 0;
  virtual ::android::binder::Status fdeRestart() = 0;
  virtual ::android::binder::Status fdeComplete(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status fdeEnable(int32_t passwordType, const ::std::string& password, int32_t encryptionFlags) = 0;
  virtual ::android::binder::Status fdeChangePassword(int32_t passwordType, const ::std::string& currentPassword, const ::std::string& password) = 0;
  virtual ::android::binder::Status fdeVerifyPassword(const ::std::string& password) = 0;
  virtual ::android::binder::Status fdeGetField(const ::std::string& key, ::std::string* _aidl_return) = 0;
  virtual ::android::binder::Status fdeSetField(const ::std::string& key, const ::std::string& value) = 0;
  virtual ::android::binder::Status fdeGetPasswordType(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status fdeGetPassword(::std::string* _aidl_return) = 0;
  virtual ::android::binder::Status fdeClearPassword() = 0;
  virtual ::android::binder::Status fbeEnable() = 0;
  virtual ::android::binder::Status mountDefaultEncrypted() = 0;
  virtual ::android::binder::Status initUser0() = 0;
  virtual ::android::binder::Status isConvertibleToFbe(bool* _aidl_return) = 0;
  virtual ::android::binder::Status mountFstab(const ::std::string& blkDevice, const ::std::string& mountPoint) = 0;
  virtual ::android::binder::Status encryptFstab(const ::std::string& blkDevice, const ::std::string& mountPoint, bool shouldFormat, const ::std::string& fsType) = 0;
  virtual ::android::binder::Status setStorageBindingSeed(const ::std::vector<uint8_t>& seed) = 0;
  virtual ::android::binder::Status createUserKey(int32_t userId, int32_t userSerial, bool ephemeral) = 0;
  virtual ::android::binder::Status destroyUserKey(int32_t userId) = 0;
  virtual ::android::binder::Status addUserKeyAuth(int32_t userId, int32_t userSerial, const ::std::string& token, const ::std::string& secret) = 0;
  virtual ::android::binder::Status clearUserKeyAuth(int32_t userId, int32_t userSerial, const ::std::string& token, const ::std::string& secret) = 0;
  virtual ::android::binder::Status fixateNewestUserKeyAuth(int32_t userId) = 0;
  virtual ::android::binder::Status getUnlockedUsers(::std::vector<int32_t>* _aidl_return) = 0;
  virtual ::android::binder::Status unlockUserKey(int32_t userId, int32_t userSerial, const ::std::string& token, const ::std::string& secret) = 0;
  virtual ::android::binder::Status lockUserKey(int32_t userId) = 0;
  virtual ::android::binder::Status prepareUserStorage(const ::std::optional<::std::string>& uuid, int32_t userId, int32_t userSerial, int32_t storageFlags) = 0;
  virtual ::android::binder::Status destroyUserStorage(const ::std::optional<::std::string>& uuid, int32_t userId, int32_t storageFlags) = 0;
  virtual ::android::binder::Status prepareSandboxForApp(const ::std::string& packageName, int32_t appId, const ::std::string& sandboxId, int32_t userId) = 0;
  virtual ::android::binder::Status destroySandboxForApp(const ::std::string& packageName, const ::std::string& sandboxId, int32_t userId) = 0;
  virtual ::android::binder::Status startCheckpoint(int32_t retry) = 0;
  virtual ::android::binder::Status needsCheckpoint(bool* _aidl_return) = 0;
  virtual ::android::binder::Status needsRollback(bool* _aidl_return) = 0;
  virtual ::android::binder::Status isCheckpointing(bool* _aidl_return) = 0;
  virtual ::android::binder::Status abortChanges(const ::std::string& device, bool retry) = 0;
  virtual ::android::binder::Status commitChanges() = 0;
  virtual ::android::binder::Status prepareCheckpoint() = 0;
  virtual ::android::binder::Status restoreCheckpoint(const ::std::string& device) = 0;
  virtual ::android::binder::Status restoreCheckpointPart(const ::std::string& device, int32_t count) = 0;
  virtual ::android::binder::Status markBootAttempt() = 0;
  virtual ::android::binder::Status supportsCheckpoint(bool* _aidl_return) = 0;
  virtual ::android::binder::Status supportsBlockCheckpoint(bool* _aidl_return) = 0;
  virtual ::android::binder::Status supportsFileCheckpoint(bool* _aidl_return) = 0;
  virtual ::android::binder::Status resetCheckpoint() = 0;
  virtual ::android::binder::Status earlyBootEnded() = 0;
  virtual ::android::binder::Status createStubVolume(const ::std::string& sourcePath, const ::std::string& mountPath, const ::std::string& fsType, const ::std::string& fsUuid, const ::std::string& fsLabel, int32_t flags, ::std::string* _aidl_return) = 0;
  virtual ::android::binder::Status destroyStubVolume(const ::std::string& volId) = 0;
  virtual ::android::binder::Status openAppFuseFile(int32_t uid, int32_t mountId, int32_t fileId, int32_t flags, ::android::base::unique_fd* _aidl_return) = 0;
  virtual ::android::binder::Status incFsEnabled(bool* _aidl_return) = 0;
  virtual ::android::binder::Status mountIncFs(const ::std::string& backingPath, const ::std::string& targetDir, int32_t flags, const ::std::string& sysfsName, ::android::os::incremental::IncrementalFileSystemControlParcel* _aidl_return) = 0;
  virtual ::android::binder::Status unmountIncFs(const ::std::string& dir) = 0;
  virtual ::android::binder::Status setIncFsMountOptions(const ::android::os::incremental::IncrementalFileSystemControlParcel& control, bool enableReadLogs, bool enableReadTimeouts, const ::std::string& sysfsName) = 0;
  virtual ::android::binder::Status bindMount(const ::std::string& sourceDir, const ::std::string& targetDir) = 0;
  virtual ::android::binder::Status destroyDsuMetadataKey(const ::std::string& dsuSlot) = 0;
};  // class IVold

class IVoldDefault : public IVold {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status setListener(const ::android::sp<::android::os::IVoldListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status abortFuse() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status monitor() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status reset() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status shutdown() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onUserAdded(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onUserRemoved(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onUserStarted(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onUserStopped(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status addAppIds(const ::std::vector<::std::string>&, const ::std::vector<int32_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status addSandboxIds(const ::std::vector<int32_t>&, const ::std::vector<::std::string>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onSecureKeyguardStateChanged(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status partition(const ::std::string&, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status forgetPartition(const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status mount(const ::std::string&, int32_t, int32_t, const ::android::sp<::android::os::IVoldMountCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unmount(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status format(const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status benchmark(const ::std::string&, const ::android::sp<::android::os::IVoldTaskListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status moveStorage(const ::std::string&, const ::std::string&, const ::android::sp<::android::os::IVoldTaskListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status remountUid(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status remountAppStorageDirs(int32_t, int32_t, const ::std::vector<::std::string>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unmountAppStorageDirs(int32_t, int32_t, const ::std::vector<::std::string>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setupAppDir(const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status fixupAppDir(const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ensureAppDirsCreated(const ::std::vector<::std::string>&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createObb(const ::std::string&, const ::std::string&, int32_t, ::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status destroyObb(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status fstrim(int32_t, const ::android::sp<::android::os::IVoldTaskListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status runIdleMaint(const ::android::sp<::android::os::IVoldTaskListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status abortIdleMaint(const ::android::sp<::android::os::IVoldTaskListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status mountAppFuse(int32_t, int32_t, ::android::base::unique_fd*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unmountAppFuse(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status fdeCheckPassword(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status fdeRestart() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status fdeComplete(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status fdeEnable(int32_t, const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status fdeChangePassword(int32_t, const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status fdeVerifyPassword(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status fdeGetField(const ::std::string&, ::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status fdeSetField(const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status fdeGetPasswordType(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status fdeGetPassword(::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status fdeClearPassword() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status fbeEnable() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status mountDefaultEncrypted() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status initUser0() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isConvertibleToFbe(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status mountFstab(const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status encryptFstab(const ::std::string&, const ::std::string&, bool, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setStorageBindingSeed(const ::std::vector<uint8_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createUserKey(int32_t, int32_t, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status destroyUserKey(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status addUserKeyAuth(int32_t, int32_t, const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status clearUserKeyAuth(int32_t, int32_t, const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status fixateNewestUserKeyAuth(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getUnlockedUsers(::std::vector<int32_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unlockUserKey(int32_t, int32_t, const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status lockUserKey(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status prepareUserStorage(const ::std::optional<::std::string>&, int32_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status destroyUserStorage(const ::std::optional<::std::string>&, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status prepareSandboxForApp(const ::std::string&, int32_t, const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status destroySandboxForApp(const ::std::string&, const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status startCheckpoint(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status needsCheckpoint(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status needsRollback(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isCheckpointing(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status abortChanges(const ::std::string&, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status commitChanges() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status prepareCheckpoint() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status restoreCheckpoint(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status restoreCheckpointPart(const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status markBootAttempt() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status supportsCheckpoint(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status supportsBlockCheckpoint(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status supportsFileCheckpoint(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status resetCheckpoint() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status earlyBootEnded() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createStubVolume(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, int32_t, ::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status destroyStubVolume(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status openAppFuseFile(int32_t, int32_t, int32_t, int32_t, ::android::base::unique_fd*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status incFsEnabled(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status mountIncFs(const ::std::string&, const ::std::string&, int32_t, const ::std::string&, ::android::os::incremental::IncrementalFileSystemControlParcel*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unmountIncFs(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setIncFsMountOptions(const ::android::os::incremental::IncrementalFileSystemControlParcel&, bool, bool, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status bindMount(const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status destroyDsuMetadataKey(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IVoldDefault

}  // namespace os

}  // namespace android
