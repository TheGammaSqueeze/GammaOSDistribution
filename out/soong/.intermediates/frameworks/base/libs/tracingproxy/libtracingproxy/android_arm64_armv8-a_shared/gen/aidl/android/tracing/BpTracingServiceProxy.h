#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/tracing/ITracingServiceProxy.h>

namespace android {

namespace tracing {

class BpTracingServiceProxy : public ::android::BpInterface<ITracingServiceProxy> {
public:
  explicit BpTracingServiceProxy(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpTracingServiceProxy() = default;
  ::android::binder::Status notifyTraceSessionEnded(bool sessionStolen) override;
};  // class BpTracingServiceProxy

}  // namespace tracing

}  // namespace android
