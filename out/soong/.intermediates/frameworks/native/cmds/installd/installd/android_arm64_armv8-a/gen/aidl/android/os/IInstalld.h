#pragma once

#include <android-base/unique_fd.h>
#include <android/os/CreateAppDataArgs.h>
#include <android/os/CreateAppDataResult.h>
#include <android/os/storage/CrateMetadata.h>
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

class IInstalld : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Installd)
  enum  : int32_t {
    FLAG_STORAGE_DE = 1,
    FLAG_STORAGE_CE = 2,
    FLAG_STORAGE_EXTERNAL = 4,
    FLAG_CLEAR_CACHE_ONLY = 16,
    FLAG_CLEAR_CODE_CACHE_ONLY = 32,
    FLAG_FREE_CACHE_V2 = 256,
    FLAG_FREE_CACHE_V2_DEFY_QUOTA = 512,
    FLAG_FREE_CACHE_NOOP = 1024,
    FLAG_USE_QUOTA = 4096,
    FLAG_FORCE = 8192,
    FLAG_CLEAR_APP_DATA_KEEP_ART_PROFILES = 131072,
  };
  virtual ::android::binder::Status createUserData(const ::std::optional<::std::string>& uuid, int32_t userId, int32_t userSerial, int32_t flags) = 0;
  virtual ::android::binder::Status destroyUserData(const ::std::optional<::std::string>& uuid, int32_t userId, int32_t flags) = 0;
  virtual ::android::binder::Status createAppData(const ::android::os::CreateAppDataArgs& args, ::android::os::CreateAppDataResult* _aidl_return) = 0;
  virtual ::android::binder::Status createAppDataBatched(const ::std::vector<::android::os::CreateAppDataArgs>& args, ::std::vector<::android::os::CreateAppDataResult>* _aidl_return) = 0;
  virtual ::android::binder::Status restoreconAppData(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t userId, int32_t flags, int32_t appId, const ::std::string& seInfo) = 0;
  virtual ::android::binder::Status migrateAppData(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t userId, int32_t flags) = 0;
  virtual ::android::binder::Status clearAppData(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t userId, int32_t flags, int64_t ceDataInode) = 0;
  virtual ::android::binder::Status destroyAppData(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t userId, int32_t flags, int64_t ceDataInode) = 0;
  virtual ::android::binder::Status fixupAppData(const ::std::optional<::std::string>& uuid, int32_t flags) = 0;
  virtual ::android::binder::Status getAppSize(const ::std::optional<::std::string>& uuid, const ::std::vector<::std::string>& packageNames, int32_t userId, int32_t flags, int32_t appId, const ::std::vector<int64_t>& ceDataInodes, const ::std::vector<::std::string>& codePaths, ::std::vector<int64_t>* _aidl_return) = 0;
  virtual ::android::binder::Status getUserSize(const ::std::optional<::std::string>& uuid, int32_t userId, int32_t flags, const ::std::vector<int32_t>& appIds, ::std::vector<int64_t>* _aidl_return) = 0;
  virtual ::android::binder::Status getExternalSize(const ::std::optional<::std::string>& uuid, int32_t userId, int32_t flags, const ::std::vector<int32_t>& appIds, ::std::vector<int64_t>* _aidl_return) = 0;
  virtual ::android::binder::Status getAppCrates(const ::std::optional<::std::string>& uuid, const ::std::vector<::std::string>& packageNames, int32_t userId, ::std::optional<::std::vector<::std::optional<::android::os::storage::CrateMetadata>>>* _aidl_return) = 0;
  virtual ::android::binder::Status getUserCrates(const ::std::optional<::std::string>& uuid, int32_t userId, ::std::optional<::std::vector<::std::optional<::android::os::storage::CrateMetadata>>>* _aidl_return) = 0;
  virtual ::android::binder::Status setAppQuota(const ::std::optional<::std::string>& uuid, int32_t userId, int32_t appId, int64_t cacheQuota) = 0;
  virtual ::android::binder::Status moveCompleteApp(const ::std::optional<::std::string>& fromUuid, const ::std::optional<::std::string>& toUuid, const ::std::string& packageName, int32_t appId, const ::std::string& seInfo, int32_t targetSdkVersion, const ::std::string& fromCodePath) = 0;
  virtual ::android::binder::Status dexopt(const ::std::string& apkPath, int32_t uid, const ::std::optional<::std::string>& packageName, const ::std::string& instructionSet, int32_t dexoptNeeded, const ::std::optional<::std::string>& outputPath, int32_t dexFlags, const ::std::string& compilerFilter, const ::std::optional<::std::string>& uuid, const ::std::optional<::std::string>& sharedLibraries, const ::std::optional<::std::string>& seInfo, bool downgrade, int32_t targetSdkVersion, const ::std::optional<::std::string>& profileName, const ::std::optional<::std::string>& dexMetadataPath, const ::std::optional<::std::string>& compilationReason) = 0;
  virtual ::android::binder::Status compileLayouts(const ::std::string& apkPath, const ::std::string& packageName, const ::std::string& outDexFile, int32_t uid, bool* _aidl_return) = 0;
  virtual ::android::binder::Status rmdex(const ::std::string& codePath, const ::std::string& instructionSet) = 0;
  virtual ::android::binder::Status mergeProfiles(int32_t uid, const ::std::string& packageName, const ::std::string& profileName, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status dumpProfiles(int32_t uid, const ::std::string& packageName, const ::std::string& profileName, const ::std::string& codePath, bool* _aidl_return) = 0;
  virtual ::android::binder::Status copySystemProfile(const ::std::string& systemProfile, int32_t uid, const ::std::string& packageName, const ::std::string& profileName, bool* _aidl_return) = 0;
  virtual ::android::binder::Status clearAppProfiles(const ::std::string& packageName, const ::std::string& profileName) = 0;
  virtual ::android::binder::Status destroyAppProfiles(const ::std::string& packageName) = 0;
  virtual ::android::binder::Status createProfileSnapshot(int32_t appId, const ::std::string& packageName, const ::std::string& profileName, const ::std::string& classpath, bool* _aidl_return) = 0;
  virtual ::android::binder::Status destroyProfileSnapshot(const ::std::string& packageName, const ::std::string& profileName) = 0;
  virtual ::android::binder::Status rmPackageDir(const ::std::string& packageDir) = 0;
  virtual ::android::binder::Status freeCache(const ::std::optional<::std::string>& uuid, int64_t targetFreeBytes, int64_t cacheReservedBytes, int32_t flags) = 0;
  virtual ::android::binder::Status linkNativeLibraryDirectory(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, const ::std::string& nativeLibPath32, int32_t userId) = 0;
  virtual ::android::binder::Status createOatDir(const ::std::string& oatDir, const ::std::string& instructionSet) = 0;
  virtual ::android::binder::Status linkFile(const ::std::string& relativePath, const ::std::string& fromBase, const ::std::string& toBase) = 0;
  virtual ::android::binder::Status moveAb(const ::std::string& apkPath, const ::std::string& instructionSet, const ::std::string& outputPath) = 0;
  virtual ::android::binder::Status deleteOdex(const ::std::string& apkPath, const ::std::string& instructionSet, const ::std::optional<::std::string>& outputPath, int64_t* _aidl_return) = 0;
  virtual ::android::binder::Status installApkVerity(const ::std::string& filePath, ::android::base::unique_fd verityInput, int32_t contentSize) = 0;
  virtual ::android::binder::Status assertFsverityRootHashMatches(const ::std::string& filePath, const ::std::vector<uint8_t>& expectedHash) = 0;
  virtual ::android::binder::Status reconcileSecondaryDexFile(const ::std::string& dexPath, const ::std::string& pkgName, int32_t uid, const ::std::vector<::std::string>& isas, const ::std::optional<::std::string>& volume_uuid, int32_t storage_flag, bool* _aidl_return) = 0;
  virtual ::android::binder::Status hashSecondaryDexFile(const ::std::string& dexPath, const ::std::string& pkgName, int32_t uid, const ::std::optional<::std::string>& volumeUuid, int32_t storageFlag, ::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status invalidateMounts() = 0;
  virtual ::android::binder::Status isQuotaSupported(const ::std::optional<::std::string>& uuid, bool* _aidl_return) = 0;
  virtual ::android::binder::Status prepareAppProfile(const ::std::string& packageName, int32_t userId, int32_t appId, const ::std::string& profileName, const ::std::string& codePath, const ::std::optional<::std::string>& dexMetadata, bool* _aidl_return) = 0;
  virtual ::android::binder::Status snapshotAppData(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t userId, int32_t snapshotId, int32_t storageFlags, int64_t* _aidl_return) = 0;
  virtual ::android::binder::Status restoreAppDataSnapshot(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t appId, const ::std::string& seInfo, int32_t user, int32_t snapshotId, int32_t storageflags) = 0;
  virtual ::android::binder::Status destroyAppDataSnapshot(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t userId, int64_t ceSnapshotInode, int32_t snapshotId, int32_t storageFlags) = 0;
  virtual ::android::binder::Status destroyCeSnapshotsNotSpecified(const ::std::optional<::std::string>& uuid, int32_t userId, const ::std::vector<int32_t>& retainSnapshotIds) = 0;
  virtual ::android::binder::Status tryMountDataMirror(const ::std::optional<::std::string>& volumeUuid) = 0;
  virtual ::android::binder::Status onPrivateVolumeRemoved(const ::std::optional<::std::string>& volumeUuid) = 0;
  virtual ::android::binder::Status migrateLegacyObbData() = 0;
};  // class IInstalld

class IInstalldDefault : public IInstalld {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status createUserData(const ::std::optional<::std::string>&, int32_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status destroyUserData(const ::std::optional<::std::string>&, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createAppData(const ::android::os::CreateAppDataArgs&, ::android::os::CreateAppDataResult*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createAppDataBatched(const ::std::vector<::android::os::CreateAppDataArgs>&, ::std::vector<::android::os::CreateAppDataResult>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status restoreconAppData(const ::std::optional<::std::string>&, const ::std::string&, int32_t, int32_t, int32_t, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status migrateAppData(const ::std::optional<::std::string>&, const ::std::string&, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status clearAppData(const ::std::optional<::std::string>&, const ::std::string&, int32_t, int32_t, int64_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status destroyAppData(const ::std::optional<::std::string>&, const ::std::string&, int32_t, int32_t, int64_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status fixupAppData(const ::std::optional<::std::string>&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getAppSize(const ::std::optional<::std::string>&, const ::std::vector<::std::string>&, int32_t, int32_t, int32_t, const ::std::vector<int64_t>&, const ::std::vector<::std::string>&, ::std::vector<int64_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getUserSize(const ::std::optional<::std::string>&, int32_t, int32_t, const ::std::vector<int32_t>&, ::std::vector<int64_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getExternalSize(const ::std::optional<::std::string>&, int32_t, int32_t, const ::std::vector<int32_t>&, ::std::vector<int64_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getAppCrates(const ::std::optional<::std::string>&, const ::std::vector<::std::string>&, int32_t, ::std::optional<::std::vector<::std::optional<::android::os::storage::CrateMetadata>>>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getUserCrates(const ::std::optional<::std::string>&, int32_t, ::std::optional<::std::vector<::std::optional<::android::os::storage::CrateMetadata>>>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setAppQuota(const ::std::optional<::std::string>&, int32_t, int32_t, int64_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status moveCompleteApp(const ::std::optional<::std::string>&, const ::std::optional<::std::string>&, const ::std::string&, int32_t, const ::std::string&, int32_t, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status dexopt(const ::std::string&, int32_t, const ::std::optional<::std::string>&, const ::std::string&, int32_t, const ::std::optional<::std::string>&, int32_t, const ::std::string&, const ::std::optional<::std::string>&, const ::std::optional<::std::string>&, const ::std::optional<::std::string>&, bool, int32_t, const ::std::optional<::std::string>&, const ::std::optional<::std::string>&, const ::std::optional<::std::string>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status compileLayouts(const ::std::string&, const ::std::string&, const ::std::string&, int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status rmdex(const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status mergeProfiles(int32_t, const ::std::string&, const ::std::string&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status dumpProfiles(int32_t, const ::std::string&, const ::std::string&, const ::std::string&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status copySystemProfile(const ::std::string&, int32_t, const ::std::string&, const ::std::string&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status clearAppProfiles(const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status destroyAppProfiles(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createProfileSnapshot(int32_t, const ::std::string&, const ::std::string&, const ::std::string&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status destroyProfileSnapshot(const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status rmPackageDir(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status freeCache(const ::std::optional<::std::string>&, int64_t, int64_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status linkNativeLibraryDirectory(const ::std::optional<::std::string>&, const ::std::string&, const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createOatDir(const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status linkFile(const ::std::string&, const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status moveAb(const ::std::string&, const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status deleteOdex(const ::std::string&, const ::std::string&, const ::std::optional<::std::string>&, int64_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status installApkVerity(const ::std::string&, ::android::base::unique_fd, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status assertFsverityRootHashMatches(const ::std::string&, const ::std::vector<uint8_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status reconcileSecondaryDexFile(const ::std::string&, const ::std::string&, int32_t, const ::std::vector<::std::string>&, const ::std::optional<::std::string>&, int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status hashSecondaryDexFile(const ::std::string&, const ::std::string&, int32_t, const ::std::optional<::std::string>&, int32_t, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status invalidateMounts() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isQuotaSupported(const ::std::optional<::std::string>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status prepareAppProfile(const ::std::string&, int32_t, int32_t, const ::std::string&, const ::std::string&, const ::std::optional<::std::string>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status snapshotAppData(const ::std::optional<::std::string>&, const ::std::string&, int32_t, int32_t, int32_t, int64_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status restoreAppDataSnapshot(const ::std::optional<::std::string>&, const ::std::string&, int32_t, const ::std::string&, int32_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status destroyAppDataSnapshot(const ::std::optional<::std::string>&, const ::std::string&, int32_t, int64_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status destroyCeSnapshotsNotSpecified(const ::std::optional<::std::string>&, int32_t, const ::std::vector<int32_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tryMountDataMirror(const ::std::optional<::std::string>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onPrivateVolumeRemoved(const ::std::optional<::std::string>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status migrateLegacyObbData() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IInstalldDefault

}  // namespace os

}  // namespace android
