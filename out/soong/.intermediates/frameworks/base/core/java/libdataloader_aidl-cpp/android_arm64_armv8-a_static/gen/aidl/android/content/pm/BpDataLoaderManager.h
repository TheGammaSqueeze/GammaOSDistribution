#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/content/pm/IDataLoaderManager.h>

namespace android {

namespace content {

namespace pm {

class BpDataLoaderManager : public ::android::BpInterface<IDataLoaderManager> {
public:
  explicit BpDataLoaderManager(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpDataLoaderManager() = default;
  ::android::binder::Status bindToDataLoader(int32_t id, const ::android::content::pm::DataLoaderParamsParcel& params, int64_t bindDelayMs, const ::android::sp<::android::content::pm::IDataLoaderStatusListener>& listener, bool* _aidl_return) override;
  ::android::binder::Status getDataLoader(int32_t dataLoaderId, ::android::sp<::android::content::pm::IDataLoader>* _aidl_return) override;
  ::android::binder::Status unbindFromDataLoader(int32_t dataLoaderId) override;
};  // class BpDataLoaderManager

}  // namespace pm

}  // namespace content

}  // namespace android
