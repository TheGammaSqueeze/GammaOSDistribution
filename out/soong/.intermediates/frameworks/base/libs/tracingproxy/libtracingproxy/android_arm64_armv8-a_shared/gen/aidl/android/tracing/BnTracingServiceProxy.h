#pragma once

#include <binder/IInterface.h>
#include <android/tracing/ITracingServiceProxy.h>

namespace android {

namespace tracing {

class BnTracingServiceProxy : public ::android::BnInterface<ITracingServiceProxy> {
public:
  static constexpr uint32_t TRANSACTION_notifyTraceSessionEnded = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnTracingServiceProxy();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnTracingServiceProxy

}  // namespace tracing

}  // namespace android
