#pragma once

#include <android/os/IIncidentAuthListener.h>
#include <android/os/IncidentManager.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace os {

class IIncidentCompanion : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(IncidentCompanion)
  virtual ::android::binder::Status authorizeReport(int32_t callingUid, const ::android::String16& callingPackage, const ::android::String16& receiverClass, const ::android::String16& reportId, int32_t flags, const ::android::sp<::android::os::IIncidentAuthListener>& callback) = 0;
  virtual ::android::binder::Status cancelAuthorization(const ::android::sp<::android::os::IIncidentAuthListener>& callback) = 0;
  virtual ::android::binder::Status sendReportReadyBroadcast(const ::android::String16& pkg, const ::android::String16& cls) = 0;
  virtual ::android::binder::Status getPendingReports(::std::vector<::android::String16>* _aidl_return) = 0;
  virtual ::android::binder::Status approveReport(const ::android::String16& uri) = 0;
  virtual ::android::binder::Status denyReport(const ::android::String16& uri) = 0;
  virtual ::android::binder::Status getIncidentReportList(const ::android::String16& pkg, const ::android::String16& cls, ::std::vector<::android::String16>* _aidl_return) = 0;
  virtual ::android::binder::Status getIncidentReport(const ::android::String16& pkg, const ::android::String16& cls, const ::android::String16& id, ::android::os::IncidentManager::IncidentReport* _aidl_return) = 0;
  virtual ::android::binder::Status deleteIncidentReports(const ::android::String16& pkg, const ::android::String16& cls, const ::android::String16& id) = 0;
  virtual ::android::binder::Status deleteAllIncidentReports(const ::android::String16& pkg) = 0;
};  // class IIncidentCompanion

class IIncidentCompanionDefault : public IIncidentCompanion {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status authorizeReport(int32_t, const ::android::String16&, const ::android::String16&, const ::android::String16&, int32_t, const ::android::sp<::android::os::IIncidentAuthListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status cancelAuthorization(const ::android::sp<::android::os::IIncidentAuthListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status sendReportReadyBroadcast(const ::android::String16&, const ::android::String16&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getPendingReports(::std::vector<::android::String16>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status approveReport(const ::android::String16&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status denyReport(const ::android::String16&) override {
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
};  // class IIncidentCompanionDefault

}  // namespace os

}  // namespace android
