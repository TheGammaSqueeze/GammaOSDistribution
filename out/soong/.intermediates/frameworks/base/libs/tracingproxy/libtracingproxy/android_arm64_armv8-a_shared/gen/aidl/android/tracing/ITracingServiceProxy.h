#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

namespace tracing {

class ITracingServiceProxy : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(TracingServiceProxy)
  virtual ::android::binder::Status notifyTraceSessionEnded(bool sessionStolen) = 0;
};  // class ITracingServiceProxy

class ITracingServiceProxyDefault : public ITracingServiceProxy {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status notifyTraceSessionEnded(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ITracingServiceProxyDefault

}  // namespace tracing

}  // namespace android
