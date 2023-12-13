#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/incremental/IIncrementalService.h>

namespace android {

namespace os {

namespace incremental {

class BpIncrementalService : public ::android::BpInterface<IIncrementalService> {
public:
  explicit BpIncrementalService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpIncrementalService() = default;
  ::android::binder::Status openStorage(const ::std::string& path, int32_t* _aidl_return) override;
  ::android::binder::Status createStorage(const ::std::string& path, const ::android::content::pm::DataLoaderParamsParcel& params, int32_t createMode, int32_t* _aidl_return) override;
  ::android::binder::Status createLinkedStorage(const ::std::string& path, int32_t otherStorageId, int32_t createMode, int32_t* _aidl_return) override;
  ::android::binder::Status startLoading(int32_t storageId, const ::android::content::pm::DataLoaderParamsParcel& params, const ::android::sp<::android::content::pm::IDataLoaderStatusListener>& statusListener, const ::android::os::incremental::StorageHealthCheckParams& healthCheckParams, const ::android::sp<::android::os::incremental::IStorageHealthListener>& healthListener, const ::std::vector<::android::os::incremental::PerUidReadTimeouts>& perUidReadTimeouts, bool* _aidl_return) override;
  ::android::binder::Status onInstallationComplete(int32_t storageId) override;
  ::android::binder::Status makeBindMount(int32_t storageId, const ::std::string& sourcePath, const ::std::string& targetFullPath, int32_t bindType, int32_t* _aidl_return) override;
  ::android::binder::Status deleteBindMount(int32_t storageId, const ::std::string& targetFullPath, int32_t* _aidl_return) override;
  ::android::binder::Status makeDirectory(int32_t storageId, const ::std::string& path, int32_t* _aidl_return) override;
  ::android::binder::Status makeDirectories(int32_t storageId, const ::std::string& path, int32_t* _aidl_return) override;
  ::android::binder::Status makeFile(int32_t storageId, const ::std::string& path, const ::android::os::incremental::IncrementalNewFileParams& params, const ::std::optional<::std::vector<uint8_t>>& content, int32_t* _aidl_return) override;
  ::android::binder::Status makeFileFromRange(int32_t storageId, const ::std::string& targetPath, const ::std::string& sourcePath, int64_t start, int64_t end, int32_t* _aidl_return) override;
  ::android::binder::Status makeLink(int32_t sourceStorageId, const ::std::string& sourcePath, int32_t destStorageId, const ::std::string& destPath, int32_t* _aidl_return) override;
  ::android::binder::Status unlink(int32_t storageId, const ::std::string& path, int32_t* _aidl_return) override;
  ::android::binder::Status isFileFullyLoaded(int32_t storageId, const ::std::string& path, int32_t* _aidl_return) override;
  ::android::binder::Status isFullyLoaded(int32_t storageId, int32_t* _aidl_return) override;
  ::android::binder::Status getLoadingProgress(int32_t storageId, float* _aidl_return) override;
  ::android::binder::Status getMetadataByPath(int32_t storageId, const ::std::string& path, ::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status getMetadataById(int32_t storageId, const ::std::vector<uint8_t>& fileId, ::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status deleteStorage(int32_t storageId) override;
  ::android::binder::Status disallowReadLogs(int32_t storageId) override;
  ::android::binder::Status configureNativeBinaries(int32_t storageId, const ::std::string& apkFullPath, const ::std::string& libDirRelativePath, const ::std::string& abi, bool extractNativeLibs, bool* _aidl_return) override;
  ::android::binder::Status waitForNativeBinariesExtraction(int32_t storageId, bool* _aidl_return) override;
  ::android::binder::Status registerLoadingProgressListener(int32_t storageId, const ::android::sp<::android::os::incremental::IStorageLoadingProgressListener>& listener, bool* _aidl_return) override;
  ::android::binder::Status unregisterLoadingProgressListener(int32_t storageId, bool* _aidl_return) override;
  ::android::binder::Status getMetrics(int32_t storageId, ::android::os::PersistableBundle* _aidl_return) override;
};  // class BpIncrementalService

}  // namespace incremental

}  // namespace os

}  // namespace android
