#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

namespace os {

class IIncidentAuthListener : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(IncidentAuthListener)
  virtual ::android::binder::Status onReportApproved() = 0;
  virtual ::android::binder::Status onReportDenied() = 0;
};  // class IIncidentAuthListener

class IIncidentAuthListenerDefault : public IIncidentAuthListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onReportApproved() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onReportDenied() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IIncidentAuthListenerDefault

}  // namespace os

}  // namespace android
