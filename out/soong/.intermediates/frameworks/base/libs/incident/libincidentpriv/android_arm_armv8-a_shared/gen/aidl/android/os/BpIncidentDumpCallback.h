#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IIncidentDumpCallback.h>

namespace android {

namespace os {

class BpIncidentDumpCallback : public ::android::BpInterface<IIncidentDumpCallback> {
public:
  explicit BpIncidentDumpCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpIncidentDumpCallback() = default;
  ::android::binder::Status onDumpSection(const ::android::os::ParcelFileDescriptor& fd) override;
};  // class BpIncidentDumpCallback

}  // namespace os

}  // namespace android
