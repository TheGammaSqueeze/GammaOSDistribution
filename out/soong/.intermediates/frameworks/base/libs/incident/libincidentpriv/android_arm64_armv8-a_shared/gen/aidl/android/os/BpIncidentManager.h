#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IIncidentManager.h>

namespace android {

namespace os {

class BpIncidentManager : public ::android::BpInterface<IIncidentManager> {
public:
  explicit BpIncidentManager(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpIncidentManager() = default;
  ::android::binder::Status reportIncident(const ::android::os::IncidentReportArgs& args) override;
  ::android::binder::Status reportIncidentToStream(const ::android::os::IncidentReportArgs& args, const ::android::sp<::android::os::IIncidentReportStatusListener>& listener, ::android::base::unique_fd stream) override;
  ::android::binder::Status reportIncidentToDumpstate(::android::base::unique_fd stream, const ::android::sp<::android::os::IIncidentReportStatusListener>& listener) override;
  ::android::binder::Status registerSection(int32_t id, const ::android::String16& name, const ::android::sp<::android::os::IIncidentDumpCallback>& callback) override;
  ::android::binder::Status unregisterSection(int32_t id) override;
  ::android::binder::Status systemRunning() override;
  ::android::binder::Status getIncidentReportList(const ::android::String16& pkg, const ::android::String16& cls, ::std::vector<::android::String16>* _aidl_return) override;
  ::android::binder::Status getIncidentReport(const ::android::String16& pkg, const ::android::String16& cls, const ::android::String16& id, ::android::os::IncidentManager::IncidentReport* _aidl_return) override;
  ::android::binder::Status deleteIncidentReports(const ::android::String16& pkg, const ::android::String16& cls, const ::android::String16& id) override;
  ::android::binder::Status deleteAllIncidentReports(const ::android::String16& pkg) override;
};  // class BpIncidentManager

}  // namespace os

}  // namespace android
