#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IIncidentCompanion.h>

namespace android {

namespace os {

class BpIncidentCompanion : public ::android::BpInterface<IIncidentCompanion> {
public:
  explicit BpIncidentCompanion(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpIncidentCompanion() = default;
  ::android::binder::Status authorizeReport(int32_t callingUid, const ::android::String16& callingPackage, const ::android::String16& receiverClass, const ::android::String16& reportId, int32_t flags, const ::android::sp<::android::os::IIncidentAuthListener>& callback) override;
  ::android::binder::Status cancelAuthorization(const ::android::sp<::android::os::IIncidentAuthListener>& callback) override;
  ::android::binder::Status sendReportReadyBroadcast(const ::android::String16& pkg, const ::android::String16& cls) override;
  ::android::binder::Status getPendingReports(::std::vector<::android::String16>* _aidl_return) override;
  ::android::binder::Status approveReport(const ::android::String16& uri) override;
  ::android::binder::Status denyReport(const ::android::String16& uri) override;
  ::android::binder::Status getIncidentReportList(const ::android::String16& pkg, const ::android::String16& cls, ::std::vector<::android::String16>* _aidl_return) override;
  ::android::binder::Status getIncidentReport(const ::android::String16& pkg, const ::android::String16& cls, const ::android::String16& id, ::android::os::IncidentManager::IncidentReport* _aidl_return) override;
  ::android::binder::Status deleteIncidentReports(const ::android::String16& pkg, const ::android::String16& cls, const ::android::String16& id) override;
  ::android::binder::Status deleteAllIncidentReports(const ::android::String16& pkg) override;
};  // class BpIncidentCompanion

}  // namespace os

}  // namespace android
