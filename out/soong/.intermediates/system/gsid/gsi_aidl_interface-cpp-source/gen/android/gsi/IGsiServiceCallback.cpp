#include <android/gsi/IGsiServiceCallback.h>
#include <android/gsi/BpGsiServiceCallback.h>

namespace android {

namespace gsi {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(GsiServiceCallback, "android.gsi.IGsiServiceCallback")

}  // namespace gsi

}  // namespace android
#include <android/gsi/BpGsiServiceCallback.h>
#include <android/gsi/BnGsiServiceCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace gsi {

BpGsiServiceCallback::BpGsiServiceCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IGsiServiceCallback>(_aidl_impl){
}

::android::binder::Status BpGsiServiceCallback::onResult(int32_t result) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(result);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnGsiServiceCallback::TRANSACTION_onResult, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IGsiServiceCallback::getDefaultImpl())) {
     return IGsiServiceCallback::getDefaultImpl()->onResult(result);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace gsi

}  // namespace android
#include <android/gsi/BnGsiServiceCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace gsi {

BnGsiServiceCallback::BnGsiServiceCallback()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnGsiServiceCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnGsiServiceCallback::TRANSACTION_onResult:
  {
    int32_t in_result;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_result);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onResult(in_result));
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

}  // namespace gsi

}  // namespace android
