#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <binder/request_id.h>
#include <binder/task_result.h>
#include <utils/StrongPointer.h>

namespace com {

namespace google {

namespace android {

namespace startop {

namespace iorap {

class ITaskListener : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(TaskListener)
  virtual ::android::binder::Status onProgress(const ::com::google::android::startop::iorap::RequestId& requestId, const ::com::google::android::startop::iorap::TaskResult& result) = 0;
  virtual ::android::binder::Status onComplete(const ::com::google::android::startop::iorap::RequestId& requestId, const ::com::google::android::startop::iorap::TaskResult& result) = 0;
};  // class ITaskListener

class ITaskListenerDefault : public ITaskListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onProgress(const ::com::google::android::startop::iorap::RequestId&, const ::com::google::android::startop::iorap::TaskResult&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onComplete(const ::com::google::android::startop::iorap::RequestId&, const ::com::google::android::startop::iorap::TaskResult&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ITaskListenerDefault

}  // namespace iorap

}  // namespace startop

}  // namespace android

}  // namespace google

}  // namespace com
