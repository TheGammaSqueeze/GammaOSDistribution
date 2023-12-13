#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IIncidentAuthListener.h>

namespace android {

namespace os {

class BpIncidentAuthListener : public ::android::BpInterface<IIncidentAuthListener> {
public:
  explicit BpIncidentAuthListener(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpIncidentAuthListener() = default;
  ::android::binder::Status onReportApproved() override;
  ::android::binder::Status onReportDenied() override;
};  // class BpIncidentAuthListener

}  // namespace os

}  // namespace android
