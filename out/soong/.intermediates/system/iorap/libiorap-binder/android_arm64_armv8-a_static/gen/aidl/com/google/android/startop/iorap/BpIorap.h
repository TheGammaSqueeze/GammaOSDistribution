#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <com/google/android/startop/iorap/IIorap.h>

namespace com {

namespace google {

namespace android {

namespace startop {

namespace iorap {

class BpIorap : public ::android::BpInterface<IIorap> {
public:
  explicit BpIorap(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpIorap() = default;
  ::android::binder::Status setTaskListener(const ::android::sp<::com::google::android::startop::iorap::ITaskListener>& listener) override;
  ::android::binder::Status onAppLaunchEvent(const ::com::google::android::startop::iorap::RequestId& request, const ::com::google::android::startop::iorap::AppLaunchEvent& event) override;
  ::android::binder::Status onDexOptEvent(const ::com::google::android::startop::iorap::RequestId& request, const ::com::google::android::startop::iorap::DexOptEvent& event) override;
  ::android::binder::Status onJobScheduledEvent(const ::com::google::android::startop::iorap::RequestId& request, const ::com::google::android::startop::iorap::JobScheduledEvent& event) override;
  ::android::binder::Status onPackageEvent(const ::com::google::android::startop::iorap::RequestId& request, const ::com::google::android::startop::iorap::PackageEvent& event) override;
  ::android::binder::Status onAppIntentEvent(const ::com::google::android::startop::iorap::RequestId& request, const ::com::google::android::startop::iorap::AppIntentEvent& event) override;
  ::android::binder::Status onSystemServiceEvent(const ::com::google::android::startop::iorap::RequestId& request, const ::com::google::android::startop::iorap::SystemServiceEvent& event) override;
  ::android::binder::Status onSystemServiceUserEvent(const ::com::google::android::startop::iorap::RequestId& request, const ::com::google::android::startop::iorap::SystemServiceUserEvent& event) override;
};  // class BpIorap

}  // namespace iorap

}  // namespace startop

}  // namespace android

}  // namespace google

}  // namespace com
