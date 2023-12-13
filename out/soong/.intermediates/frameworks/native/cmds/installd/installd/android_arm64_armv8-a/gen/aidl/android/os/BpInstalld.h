#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IInstalld.h>

namespace android {

namespace os {

class BpInstalld : public ::android::BpInterface<IInstalld> {
public:
  explicit BpInstalld(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpInstalld() = default;
  ::android::binder::Status createUserData(const ::std::optional<::std::string>& uuid, int32_t userId, int32_t userSerial, int32_t flags) override;
  ::android::binder::Status destroyUserData(const ::std::optional<::std::string>& uuid, int32_t userId, int32_t flags) override;
  ::android::binder::Status createAppData(const ::android::os::CreateAppDataArgs& args, ::android::os::CreateAppDataResult* _aidl_return) override;
  ::android::binder::Status createAppDataBatched(const ::std::vector<::android::os::CreateAppDataArgs>& args, ::std::vector<::android::os::CreateAppDataResult>* _aidl_return) override;
  ::android::binder::Status restoreconAppData(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t userId, int32_t flags, int32_t appId, const ::std::string& seInfo) override;
  ::android::binder::Status migrateAppData(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t userId, int32_t flags) override;
  ::android::binder::Status clearAppData(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t userId, int32_t flags, int64_t ceDataInode) override;
  ::android::binder::Status destroyAppData(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t userId, int32_t flags, int64_t ceDataInode) override;
  ::android::binder::Status fixupAppData(const ::std::optional<::std::string>& uuid, int32_t flags) override;
  ::android::binder::Status getAppSize(const ::std::optional<::std::string>& uuid, const ::std::vector<::std::string>& packageNames, int32_t userId, int32_t flags, int32_t appId, const ::std::vector<int64_t>& ceDataInodes, const ::std::vector<::std::string>& codePaths, ::std::vector<int64_t>* _aidl_return) override;
  ::android::binder::Status getUserSize(const ::std::optional<::std::string>& uuid, int32_t userId, int32_t flags, const ::std::vector<int32_t>& appIds, ::std::vector<int64_t>* _aidl_return) override;
  ::android::binder::Status getExternalSize(const ::std::optional<::std::string>& uuid, int32_t userId, int32_t flags, const ::std::vector<int32_t>& appIds, ::std::vector<int64_t>* _aidl_return) override;
  ::android::binder::Status getAppCrates(const ::std::optional<::std::string>& uuid, const ::std::vector<::std::string>& packageNames, int32_t userId, ::std::optional<::std::vector<::std::optional<::android::os::storage::CrateMetadata>>>* _aidl_return) override;
  ::android::binder::Status getUserCrates(const ::std::optional<::std::string>& uuid, int32_t userId, ::std::optional<::std::vector<::std::optional<::android::os::storage::CrateMetadata>>>* _aidl_return) override;
  ::android::binder::Status setAppQuota(const ::std::optional<::std::string>& uuid, int32_t userId, int32_t appId, int64_t cacheQuota) override;
  ::android::binder::Status moveCompleteApp(const ::std::optional<::std::string>& fromUuid, const ::std::optional<::std::string>& toUuid, const ::std::string& packageName, int32_t appId, const ::std::string& seInfo, int32_t targetSdkVersion, const ::std::string& fromCodePath) override;
  ::android::binder::Status dexopt(const ::std::string& apkPath, int32_t uid, const ::std::optional<::std::string>& packageName, const ::std::string& instructionSet, int32_t dexoptNeeded, const ::std::optional<::std::string>& outputPath, int32_t dexFlags, const ::std::string& compilerFilter, const ::std::optional<::std::string>& uuid, const ::std::optional<::std::string>& sharedLibraries, const ::std::optional<::std::string>& seInfo, bool downgrade, int32_t targetSdkVersion, const ::std::optional<::std::string>& profileName, const ::std::optional<::std::string>& dexMetadataPath, const ::std::optional<::std::string>& compilationReason) override;
  ::android::binder::Status compileLayouts(const ::std::string& apkPath, const ::std::string& packageName, const ::std::string& outDexFile, int32_t uid, bool* _aidl_return) override;
  ::android::binder::Status rmdex(const ::std::string& codePath, const ::std::string& instructionSet) override;
  ::android::binder::Status mergeProfiles(int32_t uid, const ::std::string& packageName, const ::std::string& profileName, int32_t* _aidl_return) override;
  ::android::binder::Status dumpProfiles(int32_t uid, const ::std::string& packageName, const ::std::string& profileName, const ::std::string& codePath, bool* _aidl_return) override;
  ::android::binder::Status copySystemProfile(const ::std::string& systemProfile, int32_t uid, const ::std::string& packageName, const ::std::string& profileName, bool* _aidl_return) override;
  ::android::binder::Status clearAppProfiles(const ::std::string& packageName, const ::std::string& profileName) override;
  ::android::binder::Status destroyAppProfiles(const ::std::string& packageName) override;
  ::android::binder::Status createProfileSnapshot(int32_t appId, const ::std::string& packageName, const ::std::string& profileName, const ::std::string& classpath, bool* _aidl_return) override;
  ::android::binder::Status destroyProfileSnapshot(const ::std::string& packageName, const ::std::string& profileName) override;
  ::android::binder::Status rmPackageDir(const ::std::string& packageDir) override;
  ::android::binder::Status freeCache(const ::std::optional<::std::string>& uuid, int64_t targetFreeBytes, int64_t cacheReservedBytes, int32_t flags) override;
  ::android::binder::Status linkNativeLibraryDirectory(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, const ::std::string& nativeLibPath32, int32_t userId) override;
  ::android::binder::Status createOatDir(const ::std::string& oatDir, const ::std::string& instructionSet) override;
  ::android::binder::Status linkFile(const ::std::string& relativePath, const ::std::string& fromBase, const ::std::string& toBase) override;
  ::android::binder::Status moveAb(const ::std::string& apkPath, const ::std::string& instructionSet, const ::std::string& outputPath) override;
  ::android::binder::Status deleteOdex(const ::std::string& apkPath, const ::std::string& instructionSet, const ::std::optional<::std::string>& outputPath, int64_t* _aidl_return) override;
  ::android::binder::Status installApkVerity(const ::std::string& filePath, ::android::base::unique_fd verityInput, int32_t contentSize) override;
  ::android::binder::Status assertFsverityRootHashMatches(const ::std::string& filePath, const ::std::vector<uint8_t>& expectedHash) override;
  ::android::binder::Status reconcileSecondaryDexFile(const ::std::string& dexPath, const ::std::string& pkgName, int32_t uid, const ::std::vector<::std::string>& isas, const ::std::optional<::std::string>& volume_uuid, int32_t storage_flag, bool* _aidl_return) override;
  ::android::binder::Status hashSecondaryDexFile(const ::std::string& dexPath, const ::std::string& pkgName, int32_t uid, const ::std::optional<::std::string>& volumeUuid, int32_t storageFlag, ::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status invalidateMounts() override;
  ::android::binder::Status isQuotaSupported(const ::std::optional<::std::string>& uuid, bool* _aidl_return) override;
  ::android::binder::Status prepareAppProfile(const ::std::string& packageName, int32_t userId, int32_t appId, const ::std::string& profileName, const ::std::string& codePath, const ::std::optional<::std::string>& dexMetadata, bool* _aidl_return) override;
  ::android::binder::Status snapshotAppData(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t userId, int32_t snapshotId, int32_t storageFlags, int64_t* _aidl_return) override;
  ::android::binder::Status restoreAppDataSnapshot(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t appId, const ::std::string& seInfo, int32_t user, int32_t snapshotId, int32_t storageflags) override;
  ::android::binder::Status destroyAppDataSnapshot(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t userId, int64_t ceSnapshotInode, int32_t snapshotId, int32_t storageFlags) override;
  ::android::binder::Status destroyCeSnapshotsNotSpecified(const ::std::optional<::std::string>& uuid, int32_t userId, const ::std::vector<int32_t>& retainSnapshotIds) override;
  ::android::binder::Status tryMountDataMirror(const ::std::optional<::std::string>& volumeUuid) override;
  ::android::binder::Status onPrivateVolumeRemoved(const ::std::optional<::std::string>& volumeUuid) override;
  ::android::binder::Status migrateLegacyObbData() override;
};  // class BpInstalld

}  // namespace os

}  // namespace android
