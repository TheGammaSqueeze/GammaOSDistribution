#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <binder/app_intent_event.h>
#include <binder/app_launch_event.h>
#include <binder/dexopt_event.h>
#include <binder/job_scheduled_event.h>
#include <binder/package_event.h>
#include <binder/request_id.h>
#include <binder/system_service_event.h>
#include <binder/system_service_user_event.h>
#include <com/google/android/startop/iorap/ITaskListener.h>
#include <utils/StrongPointer.h>

namespace com {

namespace google {

namespace android {

namespace startop {

namespace iorap {

class IIorap : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Iorap)
  virtual ::android::binder::Status setTaskListener(const ::android::sp<::com::google::android::startop::iorap::ITaskListener>& listener) = 0;
  virtual ::android::binder::Status onAppLaunchEvent(const ::com::google::android::startop::iorap::RequestId& request, const ::com::google::android::startop::iorap::AppLaunchEvent& event) = 0;
  virtual ::android::binder::Status onDexOptEvent(const ::com::google::android::startop::iorap::RequestId& request, const ::com::google::android::startop::iorap::DexOptEvent& event) = 0;
  virtual ::android::binder::Status onJobScheduledEvent(const ::com::google::android::startop::iorap::RequestId& request, const ::com::google::android::startop::iorap::JobScheduledEvent& event) = 0;
  virtual ::android::binder::Status onPackageEvent(const ::com::google::android::startop::iorap::RequestId& request, const ::com::google::android::startop::iorap::PackageEvent& event) = 0;
  virtual ::android::binder::Status onAppIntentEvent(const ::com::google::android::startop::iorap::RequestId& request, const ::com::google::android::startop::iorap::AppIntentEvent& event) = 0;
  virtual ::android::binder::Status onSystemServiceEvent(const ::com::google::android::startop::iorap::RequestId& request, const ::com::google::android::startop::iorap::SystemServiceEvent& event) = 0;
  virtual ::android::binder::Status onSystemServiceUserEvent(const ::com::google::android::startop::iorap::RequestId& request, const ::com::google::android::startop::iorap::SystemServiceUserEvent& event) = 0;
};  // class IIorap

class IIorapDefault : public IIorap {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status setTaskListener(const ::android::sp<::com::google::android::startop::iorap::ITaskListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onAppLaunchEvent(const ::com::google::android::startop::iorap::RequestId&, const ::com::google::android::startop::iorap::AppLaunchEvent&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onDexOptEvent(const ::com::google::android::startop::iorap::RequestId&, const ::com::google::android::startop::iorap::DexOptEvent&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onJobScheduledEvent(const ::com::google::android::startop::iorap::RequestId&, const ::com::google::android::startop::iorap::JobScheduledEvent&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onPackageEvent(const ::com::google::android::startop::iorap::RequestId&, const ::com::google::android::startop::iorap::PackageEvent&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onAppIntentEvent(const ::com::google::android::startop::iorap::RequestId&, const ::com::google::android::startop::iorap::AppIntentEvent&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onSystemServiceEvent(const ::com::google::android::startop::iorap::RequestId&, const ::com::google::android::startop::iorap::SystemServiceEvent&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onSystemServiceUserEvent(const ::com::google::android::startop::iorap::RequestId&, const ::com::google::android::startop::iorap::SystemServiceUserEvent&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IIorapDefault

}  // namespace iorap

}  // namespace startop

}  // namespace android

}  // namespace google

}  // namespace com
