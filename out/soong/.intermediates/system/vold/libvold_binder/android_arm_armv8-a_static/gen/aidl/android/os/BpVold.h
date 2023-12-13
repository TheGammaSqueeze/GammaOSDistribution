#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IVold.h>

namespace android {

namespace os {

class BpVold : public ::android::BpInterface<IVold> {
public:
  explicit BpVold(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpVold() = default;
  ::android::binder::Status setListener(const ::android::sp<::android::os::IVoldListener>& listener) override;
  ::android::binder::Status abortFuse() override;
  ::android::binder::Status monitor() override;
  ::android::binder::Status reset() override;
  ::android::binder::Status shutdown() override;
  ::android::binder::Status onUserAdded(int32_t userId, int32_t userSerial) override;
  ::android::binder::Status onUserRemoved(int32_t userId) override;
  ::android::binder::Status onUserStarted(int32_t userId) override;
  ::android::binder::Status onUserStopped(int32_t userId) override;
  ::android::binder::Status addAppIds(const ::std::vector<::std::string>& packageNames, const ::std::vector<int32_t>& appIds) override;
  ::android::binder::Status addSandboxIds(const ::std::vector<int32_t>& appIds, const ::std::vector<::std::string>& sandboxIds) override;
  ::android::binder::Status onSecureKeyguardStateChanged(bool isShowing) override;
  ::android::binder::Status partition(const ::std::string& diskId, int32_t partitionType, int32_t ratio) override;
  ::android::binder::Status forgetPartition(const ::std::string& partGuid, const ::std::string& fsUuid) override;
  ::android::binder::Status mount(const ::std::string& volId, int32_t mountFlags, int32_t mountUserId, const ::android::sp<::android::os::IVoldMountCallback>& callback) override;
  ::android::binder::Status unmount(const ::std::string& volId) override;
  ::android::binder::Status format(const ::std::string& volId, const ::std::string& fsType) override;
  ::android::binder::Status benchmark(const ::std::string& volId, const ::android::sp<::android::os::IVoldTaskListener>& listener) override;
  ::android::binder::Status moveStorage(const ::std::string& fromVolId, const ::std::string& toVolId, const ::android::sp<::android::os::IVoldTaskListener>& listener) override;
  ::android::binder::Status remountUid(int32_t uid, int32_t remountMode) override;
  ::android::binder::Status remountAppStorageDirs(int32_t uid, int32_t pid, const ::std::vector<::std::string>& packageNames) override;
  ::android::binder::Status unmountAppStorageDirs(int32_t uid, int32_t pid, const ::std::vector<::std::string>& packageNames) override;
  ::android::binder::Status setupAppDir(const ::std::string& path, int32_t appUid) override;
  ::android::binder::Status fixupAppDir(const ::std::string& path, int32_t appUid) override;
  ::android::binder::Status ensureAppDirsCreated(const ::std::vector<::std::string>& paths, int32_t appUid) override;
  ::android::binder::Status createObb(const ::std::string& sourcePath, const ::std::string& sourceKey, int32_t ownerGid, ::std::string* _aidl_return) override;
  ::android::binder::Status destroyObb(const ::std::string& volId) override;
  ::android::binder::Status fstrim(int32_t fstrimFlags, const ::android::sp<::android::os::IVoldTaskListener>& listener) override;
  ::android::binder::Status runIdleMaint(const ::android::sp<::android::os::IVoldTaskListener>& listener) override;
  ::android::binder::Status abortIdleMaint(const ::android::sp<::android::os::IVoldTaskListener>& listener) override;
  ::android::binder::Status mountAppFuse(int32_t uid, int32_t mountId, ::android::base::unique_fd* _aidl_return) override;
  ::android::binder::Status unmountAppFuse(int32_t uid, int32_t mountId) override;
  ::android::binder::Status fdeCheckPassword(const ::std::string& password) override;
  ::android::binder::Status fdeRestart() override;
  ::android::binder::Status fdeComplete(int32_t* _aidl_return) override;
  ::android::binder::Status fdeEnable(int32_t passwordType, const ::std::string& password, int32_t encryptionFlags) override;
  ::android::binder::Status fdeChangePassword(int32_t passwordType, const ::std::string& currentPassword, const ::std::string& password) override;
  ::android::binder::Status fdeVerifyPassword(const ::std::string& password) override;
  ::android::binder::Status fdeGetField(const ::std::string& key, ::std::string* _aidl_return) override;
  ::android::binder::Status fdeSetField(const ::std::string& key, const ::std::string& value) override;
  ::android::binder::Status fdeGetPasswordType(int32_t* _aidl_return) override;
  ::android::binder::Status fdeGetPassword(::std::string* _aidl_return) override;
  ::android::binder::Status fdeClearPassword() override;
  ::android::binder::Status fbeEnable() override;
  ::android::binder::Status mountDefaultEncrypted() override;
  ::android::binder::Status initUser0() override;
  ::android::binder::Status isConvertibleToFbe(bool* _aidl_return) override;
  ::android::binder::Status mountFstab(const ::std::string& blkDevice, const ::std::string& mountPoint) override;
  ::android::binder::Status encryptFstab(const ::std::string& blkDevice, const ::std::string& mountPoint, bool shouldFormat, const ::std::string& fsType) override;
  ::android::binder::Status setStorageBindingSeed(const ::std::vector<uint8_t>& seed) override;
  ::android::binder::Status createUserKey(int32_t userId, int32_t userSerial, bool ephemeral) override;
  ::android::binder::Status destroyUserKey(int32_t userId) override;
  ::android::binder::Status addUserKeyAuth(int32_t userId, int32_t userSerial, const ::std::string& token, const ::std::string& secret) override;
  ::android::binder::Status clearUserKeyAuth(int32_t userId, int32_t userSerial, const ::std::string& token, const ::std::string& secret) override;
  ::android::binder::Status fixateNewestUserKeyAuth(int32_t userId) override;
  ::android::binder::Status getUnlockedUsers(::std::vector<int32_t>* _aidl_return) override;
  ::android::binder::Status unlockUserKey(int32_t userId, int32_t userSerial, const ::std::string& token, const ::std::string& secret) override;
  ::android::binder::Status lockUserKey(int32_t userId) override;
  ::android::binder::Status prepareUserStorage(const ::std::optional<::std::string>& uuid, int32_t userId, int32_t userSerial, int32_t storageFlags) override;
  ::android::binder::Status destroyUserStorage(const ::std::optional<::std::string>& uuid, int32_t userId, int32_t storageFlags) override;
  ::android::binder::Status prepareSandboxForApp(const ::std::string& packageName, int32_t appId, const ::std::string& sandboxId, int32_t userId) override;
  ::android::binder::Status destroySandboxForApp(const ::std::string& packageName, const ::std::string& sandboxId, int32_t userId) override;
  ::android::binder::Status startCheckpoint(int32_t retry) override;
  ::android::binder::Status needsCheckpoint(bool* _aidl_return) override;
  ::android::binder::Status needsRollback(bool* _aidl_return) override;
  ::android::binder::Status isCheckpointing(bool* _aidl_return) override;
  ::android::binder::Status abortChanges(const ::std::string& device, bool retry) override;
  ::android::binder::Status commitChanges() override;
  ::android::binder::Status prepareCheckpoint() override;
  ::android::binder::Status restoreCheckpoint(const ::std::string& device) override;
  ::android::binder::Status restoreCheckpointPart(const ::std::string& device, int32_t count) override;
  ::android::binder::Status markBootAttempt() override;
  ::android::binder::Status supportsCheckpoint(bool* _aidl_return) override;
  ::android::binder::Status supportsBlockCheckpoint(bool* _aidl_return) override;
  ::android::binder::Status supportsFileCheckpoint(bool* _aidl_return) override;
  ::android::binder::Status resetCheckpoint() override;
  ::android::binder::Status earlyBootEnded() override;
  ::android::binder::Status createStubVolume(const ::std::string& sourcePath, const ::std::string& mountPath, const ::std::string& fsType, const ::std::string& fsUuid, const ::std::string& fsLabel, int32_t flags, ::std::string* _aidl_return) override;
  ::android::binder::Status destroyStubVolume(const ::std::string& volId) override;
  ::android::binder::Status openAppFuseFile(int32_t uid, int32_t mountId, int32_t fileId, int32_t flags, ::android::base::unique_fd* _aidl_return) override;
  ::android::binder::Status incFsEnabled(bool* _aidl_return) override;
  ::android::binder::Status mountIncFs(const ::std::string& backingPath, const ::std::string& targetDir, int32_t flags, const ::std::string& sysfsName, ::android::os::incremental::IncrementalFileSystemControlParcel* _aidl_return) override;
  ::android::binder::Status unmountIncFs(const ::std::string& dir) override;
  ::android::binder::Status setIncFsMountOptions(const ::android::os::incremental::IncrementalFileSystemControlParcel& control, bool enableReadLogs, bool enableReadTimeouts, const ::std::string& sysfsName) override;
  ::android::binder::Status bindMount(const ::std::string& sourceDir, const ::std::string& targetDir) override;
  ::android::binder::Status destroyDsuMetadataKey(const ::std::string& dsuSlot) override;
};  // class BpVold

}  // namespace os

}  // namespace android
