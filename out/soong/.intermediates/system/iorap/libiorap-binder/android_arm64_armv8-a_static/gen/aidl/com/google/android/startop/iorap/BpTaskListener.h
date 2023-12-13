#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <com/google/android/startop/iorap/ITaskListener.h>

namespace com {

namespace google {

namespace android {

namespace startop {

namespace iorap {

class BpTaskListener : public ::android::BpInterface<ITaskListener> {
public:
  explicit BpTaskListener(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpTaskListener() = default;
  ::android::binder::Status onProgress(const ::com::google::android::startop::iorap::RequestId& requestId, const ::com::google::android::startop::iorap::TaskResult& result) override;
  ::android::binder::Status onComplete(const ::com::google::android::startop::iorap::RequestId& requestId, const ::com::google::android::startop::iorap::TaskResult& result) override;
};  // class BpTaskListener

}  // namespace iorap

}  // namespace startop

}  // namespace android

}  // namespace google

}  // namespace com
