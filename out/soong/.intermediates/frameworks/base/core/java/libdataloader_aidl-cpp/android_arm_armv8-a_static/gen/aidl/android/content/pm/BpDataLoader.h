#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/content/pm/IDataLoader.h>

namespace android {

namespace content {

namespace pm {

class BpDataLoader : public ::android::BpInterface<IDataLoader> {
public:
  explicit BpDataLoader(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpDataLoader() = default;
  ::android::binder::Status create(int32_t id, const ::android::content::pm::DataLoaderParamsParcel& params, const ::android::content::pm::FileSystemControlParcel& control, const ::android::sp<::android::content::pm::IDataLoaderStatusListener>& listener) override;
  ::android::binder::Status start(int32_t id) override;
  ::android::binder::Status stop(int32_t id) override;
  ::android::binder::Status destroy(int32_t id) override;
  ::android::binder::Status prepareImage(int32_t id, const ::std::vector<::android::content::pm::InstallationFileParcel>& addedFiles, const ::std::vector<::std::string>& removedFiles) override;
};  // class BpDataLoader

}  // namespace pm

}  // namespace content

}  // namespace android
