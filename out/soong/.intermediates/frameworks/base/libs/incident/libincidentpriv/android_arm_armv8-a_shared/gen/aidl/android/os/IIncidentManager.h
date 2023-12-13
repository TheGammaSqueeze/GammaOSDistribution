#pragma once

#include <android-base/unique_fd.h>
#include <android/os/IIncidentDumpCallback.h>
#include <android/os/IIncidentReportStatusListener.h>
#include <android/os/IncidentManager.h>
#include <android/os/IncidentReportArgs.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace os {

class IIncidentManager : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(IncidentManager)
  virtual ::android::binder::Status reportIncident(const ::android::os::IncidentReportArgs& args) = 0;
  virtual ::android::binder::Status reportIncidentToStream(const ::android::os::IncidentReportArgs& args, const ::android::sp<::android::os::IIncidentReportStatusListener>& listener, ::android::base::unique_fd stream) = 0;
  virtual ::android::binder::Status reportIncidentToDumpstate(::android::base::unique_fd stream, const ::android::sp<::android::os::IIncidentReportStatusListener>& listener) = 0;
  virtual ::android::binder::Status registerSection(int32_t id, const ::android::String16& name, const ::android::sp<::android::os::IIncidentDumpCallback>& callback) = 0;
  virtual ::android::binder::Status unregisterSection(int32_t id) = 0;
  virtual ::android::binder::Status systemRunning() = 0;
  virtual ::android::binder::Status getIncidentReportList(const ::android::String16& pkg, const ::android::String16& cls, ::std::vector<::android::String16>* _aidl_return) = 0;
  virtual ::android::binder::Status getIncidentReport(const ::android::String16& pkg, const ::android::String16& cls, const ::android::String16& id, ::android::os::IncidentManager::IncidentReport* _aidl_return) = 0;
  virtual ::android::binder::Status deleteIncidentReports(const ::android::String16& pkg, const ::android::String16& cls, const ::android::String16& id) = 0;
  virtual ::android::binder::Status deleteAllIncidentReports(const ::android::String16& pkg) = 0;
};  // class IIncidentManager

class IIncidentManagerDefault : public IIncidentManager {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status reportIncident(const ::android::os::IncidentReportArgs&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status reportIncidentToStream(const ::android::os::IncidentReportArgs&, const ::android::sp<::android::os::IIncidentReportStatusListener>&, ::android::base::unique_fd) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status reportIncidentToDumpstate(::android::base::unique_fd, const ::android::sp<::android::os::IIncidentReportStatusListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status registerSection(int32_t, const ::android::String16&, const ::android::sp<::android::os::IIncidentDumpCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unregisterSection(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status systemRunning() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getIncidentReportList(const ::android::String16&, const ::android::String16&, ::std::vector<::android::String16>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getIncidentReport(const ::android::String16&, const ::android::String16&, const ::android::String16&, ::android::os::IncidentManager::IncidentReport*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status deleteIncidentReports(const ::android::String16&, const ::android::String16&, const ::android::String16&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status deleteAllIncidentReports(const ::android::String16&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IIncidentManagerDefault

}  // namespace os

}  // namespace android
