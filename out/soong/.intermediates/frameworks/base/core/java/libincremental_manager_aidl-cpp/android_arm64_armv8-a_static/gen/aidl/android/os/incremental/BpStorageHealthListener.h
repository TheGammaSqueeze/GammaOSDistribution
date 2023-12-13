#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/incremental/IStorageHealthListener.h>

namespace android {

namespace os {

namespace incremental {

class BpStorageHealthListener : public ::android::BpInterface<IStorageHealthListener> {
public:
  explicit BpStorageHealthListener(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpStorageHealthListener() = default;
  ::android::binder::Status onHealthStatus(int32_t storageId, int32_t status) override;
};  // class BpStorageHealthListener

}  // namespace incremental

}  // namespace os

}  // namespace android
