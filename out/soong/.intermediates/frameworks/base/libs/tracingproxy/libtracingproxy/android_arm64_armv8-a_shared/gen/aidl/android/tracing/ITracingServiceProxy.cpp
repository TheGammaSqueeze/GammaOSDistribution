#include <android/tracing/ITracingServiceProxy.h>
#include <android/tracing/BpTracingServiceProxy.h>

namespace android {

namespace tracing {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(TracingServiceProxy, "android.tracing.ITracingServiceProxy")

}  // namespace tracing

}  // namespace android
#include <android/tracing/BpTracingServiceProxy.h>
#include <android/tracing/BnTracingServiceProxy.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace tracing {

BpTracingServiceProxy::BpTracingServiceProxy(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<ITracingServiceProxy>(_aidl_impl){
}

::android::binder::Status BpTracingServiceProxy::notifyTraceSessionEnded(bool sessionStolen) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(sessionStolen);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnTracingServiceProxy::TRANSACTION_notifyTraceSessionEnded, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && ITracingServiceProxy::getDefaultImpl())) {
     return ITracingServiceProxy::getDefaultImpl()->notifyTraceSessionEnded(sessionStolen);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace tracing

}  // namespace android
#include <android/tracing/BnTracingServiceProxy.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace tracing {

BnTracingServiceProxy::BnTracingServiceProxy()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnTracingServiceProxy::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnTracingServiceProxy::TRANSACTION_notifyTraceSessionEnded:
  {
    bool in_sessionStolen;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_sessionStolen);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(notifyTraceSessionEnded(in_sessionStolen));
  }
  break;
  default:
  {
    _aidl_ret_status = ::android::BBinder::onTransact(_aidl_code, _aidl_data, _aidl_reply, _aidl_flags);
  }
  break;
  }
  if (_aidl_ret_status == ::android::UNEXPECTED_NULL) {
    _aidl_ret_status = ::android::binder::Status::fromExceptionCode(::android::binder::Status::EX_NULL_POINTER).writeToParcel(_aidl_reply);
  }
  return _aidl_ret_status;
}

}  // namespace tracing

}  // namespace android
