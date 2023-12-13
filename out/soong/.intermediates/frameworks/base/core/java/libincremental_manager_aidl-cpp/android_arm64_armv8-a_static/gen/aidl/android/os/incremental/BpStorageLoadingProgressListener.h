#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/incremental/IStorageLoadingProgressListener.h>

namespace android {

namespace os {

namespace incremental {

class BpStorageLoadingProgressListener : public ::android::BpInterface<IStorageLoadingProgressListener> {
public:
  explicit BpStorageLoadingProgressListener(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpStorageLoadingProgressListener() = default;
  ::android::binder::Status onStorageLoadingProgressChanged(int32_t storageId, float progress) override;
};  // class BpStorageLoadingProgressListener

}  // namespace incremental

}  // namespace os

}  // namespace android
