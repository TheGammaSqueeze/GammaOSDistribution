#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/incremental/IIncrementalServiceConnector.h>

namespace android {

namespace os {

namespace incremental {

class BpIncrementalServiceConnector : public ::android::BpInterface<IIncrementalServiceConnector> {
public:
  explicit BpIncrementalServiceConnector(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpIncrementalServiceConnector() = default;
  ::android::binder::Status setStorageParams(bool enableReadLogs, int32_t* _aidl_return) override;
};  // class BpIncrementalServiceConnector

}  // namespace incremental

}  // namespace os

}  // namespace android
