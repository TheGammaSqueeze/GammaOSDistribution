#pragma once

#include <android/content/pm/DataLoaderParamsParcel.h>
#include <android/content/pm/IDataLoaderStatusListener.h>
#include <android/os/incremental/IStorageHealthListener.h>
#include <android/os/incremental/IStorageLoadingProgressListener.h>
#include <android/os/incremental/IncrementalNewFileParams.h>
#include <android/os/incremental/PerUidReadTimeouts.h>
#include <android/os/incremental/StorageHealthCheckParams.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/PersistableBundle.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <string>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace os {

namespace incremental {

class IIncrementalService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(IncrementalService)
  enum  : int32_t {
    CREATE_MODE_TEMPORARY_BIND = 1,
    CREATE_MODE_PERMANENT_BIND = 2,
    CREATE_MODE_CREATE = 4,
    CREATE_MODE_OPEN_EXISTING = 8,
    BIND_TEMPORARY = 0,
    BIND_PERMANENT = 1,
  };
  static const ::std::string& METRICS_MILLIS_SINCE_OLDEST_PENDING_READ();
  static const ::std::string& METRICS_READ_LOGS_ENABLED();
  static const ::std::string& METRICS_STORAGE_HEALTH_STATUS_CODE();
  static const ::std::string& METRICS_DATA_LOADER_STATUS_CODE();
  static const ::std::string& METRICS_MILLIS_SINCE_LAST_DATA_LOADER_BIND();
  static const ::std::string& METRICS_DATA_LOADER_BIND_DELAY_MILLIS();
  static const ::std::string& METRICS_TOTAL_DELAYED_READS();
  static const ::std::string& METRICS_TOTAL_DELAYED_READS_MILLIS();
  static const ::std::string& METRICS_TOTAL_FAILED_READS();
  static const ::std::string& METRICS_LAST_READ_ERROR_UID();
  static const ::std::string& METRICS_MILLIS_SINCE_LAST_READ_ERROR();
  static const ::std::string& METRICS_LAST_READ_ERROR_NUMBER();
  virtual ::android::binder::Status openStorage(const ::std::string& path, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status createStorage(const ::std::string& path, const ::android::content::pm::DataLoaderParamsParcel& params, int32_t createMode, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status createLinkedStorage(const ::std::string& path, int32_t otherStorageId, int32_t createMode, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status startLoading(int32_t storageId, const ::android::content::pm::DataLoaderParamsParcel& params, const ::android::sp<::android::content::pm::IDataLoaderStatusListener>& statusListener, const ::android::os::incremental::StorageHealthCheckParams& healthCheckParams, const ::android::sp<::android::os::incremental::IStorageHealthListener>& healthListener, const ::std::vector<::android::os::incremental::PerUidReadTimeouts>& perUidReadTimeouts, bool* _aidl_return) = 0;
  virtual ::android::binder::Status onInstallationComplete(int32_t storageId) = 0;
  virtual ::android::binder::Status makeBindMount(int32_t storageId, const ::std::string& sourcePath, const ::std::string& targetFullPath, int32_t bindType, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status deleteBindMount(int32_t storageId, const ::std::string& targetFullPath, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status makeDirectory(int32_t storageId, const ::std::string& path, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status makeDirectories(int32_t storageId, const ::std::string& path, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status makeFile(int32_t storageId, const ::std::string& path, const ::android::os::incremental::IncrementalNewFileParams& params, const ::std::optional<::std::vector<uint8_t>>& content, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status makeFileFromRange(int32_t storageId, const ::std::string& targetPath, const ::std::string& sourcePath, int64_t start, int64_t end, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status makeLink(int32_t sourceStorageId, const ::std::string& sourcePath, int32_t destStorageId, const ::std::string& destPath, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status unlink(int32_t storageId, const ::std::string& path, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status isFileFullyLoaded(int32_t storageId, const ::std::string& path, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status isFullyLoaded(int32_t storageId, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getLoadingProgress(int32_t storageId, float* _aidl_return) = 0;
  virtual ::android::binder::Status getMetadataByPath(int32_t storageId, const ::std::string& path, ::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status getMetadataById(int32_t storageId, const ::std::vector<uint8_t>& fileId, ::std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::android::binder::Status deleteStorage(int32_t storageId) = 0;
  virtual ::android::binder::Status disallowReadLogs(int32_t storageId) = 0;
  virtual ::android::binder::Status configureNativeBinaries(int32_t storageId, const ::std::string& apkFullPath, const ::std::string& libDirRelativePath, const ::std::string& abi, bool extractNativeLibs, bool* _aidl_return) = 0;
  virtual ::android::binder::Status waitForNativeBinariesExtraction(int32_t storageId, bool* _aidl_return) = 0;
  virtual ::android::binder::Status registerLoadingProgressListener(int32_t storageId, const ::android::sp<::android::os::incremental::IStorageLoadingProgressListener>& listener, bool* _aidl_return) = 0;
  virtual ::android::binder::Status unregisterLoadingProgressListener(int32_t storageId, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getMetrics(int32_t storageId, ::android::os::PersistableBundle* _aidl_return) = 0;
};  // class IIncrementalService

class IIncrementalServiceDefault : public IIncrementalService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status openStorage(const ::std::string&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createStorage(const ::std::string&, const ::android::content::pm::DataLoaderParamsParcel&, int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createLinkedStorage(const ::std::string&, int32_t, int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status startLoading(int32_t, const ::android::content::pm::DataLoaderParamsParcel&, const ::android::sp<::android::content::pm::IDataLoaderStatusListener>&, const ::android::os::incremental::StorageHealthCheckParams&, const ::android::sp<::android::os::incremental::IStorageHealthListener>&, const ::std::vector<::android::os::incremental::PerUidReadTimeouts>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onInstallationComplete(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status makeBindMount(int32_t, const ::std::string&, const ::std::string&, int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status deleteBindMount(int32_t, const ::std::string&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status makeDirectory(int32_t, const ::std::string&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status makeDirectories(int32_t, const ::std::string&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status makeFile(int32_t, const ::std::string&, const ::android::os::incremental::IncrementalNewFileParams&, const ::std::optional<::std::vector<uint8_t>>&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status makeFileFromRange(int32_t, const ::std::string&, const ::std::string&, int64_t, int64_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status makeLink(int32_t, const ::std::string&, int32_t, const ::std::string&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unlink(int32_t, const ::std::string&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isFileFullyLoaded(int32_t, const ::std::string&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isFullyLoaded(int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getLoadingProgress(int32_t, float*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getMetadataByPath(int32_t, const ::std::string&, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getMetadataById(int32_t, const ::std::vector<uint8_t>&, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status deleteStorage(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status disallowReadLogs(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status configureNativeBinaries(int32_t, const ::std::string&, const ::std::string&, const ::std::string&, bool, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status waitForNativeBinariesExtraction(int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status registerLoadingProgressListener(int32_t, const ::android::sp<::android::os::incremental::IStorageLoadingProgressListener>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unregisterLoadingProgressListener(int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getMetrics(int32_t, ::android::os::PersistableBundle*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IIncrementalServiceDefault

}  // namespace incremental

}  // namespace os

}  // namespace android
