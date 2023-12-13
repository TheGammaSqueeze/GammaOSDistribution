#pragma once

#include <android/content/pm/DataLoaderParamsParcel.h>
#include <android/content/pm/FileSystemControlParcel.h>
#include <android/content/pm/IDataLoaderStatusListener.h>
#include <android/content/pm/InstallationFileParcel.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace content {

namespace pm {

class IDataLoader : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(DataLoader)
  virtual ::android::binder::Status create(int32_t id, const ::android::content::pm::DataLoaderParamsParcel& params, const ::android::content::pm::FileSystemControlParcel& control, const ::android::sp<::android::content::pm::IDataLoaderStatusListener>& listener) = 0;
  virtual ::android::binder::Status start(int32_t id) = 0;
  virtual ::android::binder::Status stop(int32_t id) = 0;
  virtual ::android::binder::Status destroy(int32_t id) = 0;
  virtual ::android::binder::Status prepareImage(int32_t id, const ::std::vector<::android::content::pm::InstallationFileParcel>& addedFiles, const ::std::vector<::std::string>& removedFiles) = 0;
};  // class IDataLoader

class IDataLoaderDefault : public IDataLoader {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status create(int32_t, const ::android::content::pm::DataLoaderParamsParcel&, const ::android::content::pm::FileSystemControlParcel&, const ::android::sp<::android::content::pm::IDataLoaderStatusListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status start(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status stop(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status destroy(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status prepareImage(int32_t, const ::std::vector<::android::content::pm::InstallationFileParcel>&, const ::std::vector<::std::string>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IDataLoaderDefault

}  // namespace pm

}  // namespace content

}  // namespace android
