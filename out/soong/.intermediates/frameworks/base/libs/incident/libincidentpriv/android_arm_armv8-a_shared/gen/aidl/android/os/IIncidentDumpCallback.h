#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/ParcelFileDescriptor.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

namespace os {

class IIncidentDumpCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(IncidentDumpCallback)
  virtual ::android::binder::Status onDumpSection(const ::android::os::ParcelFileDescriptor& fd) = 0;
};  // class IIncidentDumpCallback

class IIncidentDumpCallbackDefault : public IIncidentDumpCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onDumpSection(const ::android::os::ParcelFileDescriptor&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IIncidentDumpCallbackDefault

}  // namespace os

}  // namespace android
