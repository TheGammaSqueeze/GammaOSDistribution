#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace os {

class IIncidentReportStatusListener : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(IncidentReportStatusListener)
  enum  : int32_t {
    STATUS_STARTING = 1,
    STATUS_FINISHED = 2,
  };
  virtual ::android::binder::Status onReportStarted() = 0;
  virtual ::android::binder::Status onReportSectionStatus(int32_t section, int32_t status) = 0;
  virtual ::android::binder::Status onReportFinished() = 0;
  virtual ::android::binder::Status onReportFailed() = 0;
};  // class IIncidentReportStatusListener

class IIncidentReportStatusListenerDefault : public IIncidentReportStatusListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onReportStarted() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onReportSectionStatus(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onReportFinished() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onReportFailed() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IIncidentReportStatusListenerDefault

}  // namespace os

}  // namespace android
