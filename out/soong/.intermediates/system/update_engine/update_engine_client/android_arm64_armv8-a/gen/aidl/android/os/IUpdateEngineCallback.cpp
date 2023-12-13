#include <android/os/IUpdateEngineCallback.h>
#include <android/os/BpUpdateEngineCallback.h>

namespace android {

namespace os {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(UpdateEngineCallback, "android.os.IUpdateEngineCallback")

}  // namespace os

}  // namespace android
#include <android/os/BpUpdateEngineCallback.h>
#include <android/os/BnUpdateEngineCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace os {

BpUpdateEngineCallback::BpUpdateEngineCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IUpdateEngineCallback>(_aidl_impl){
}

::android::binder::Status BpUpdateEngineCallback::onStatusUpdate(int32_t status_code, float percentage) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(status_code);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeFloat(percentage);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnUpdateEngineCallback::TRANSACTION_onStatusUpdate, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IUpdateEngineCallback::getDefaultImpl())) {
     return IUpdateEngineCallback::getDefaultImpl()->onStatusUpdate(status_code, percentage);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpUpdateEngineCallback::onPayloadApplicationComplete(int32_t error_code) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(error_code);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnUpdateEngineCallback::TRANSACTION_onPayloadApplicationComplete, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IUpdateEngineCallback::getDefaultImpl())) {
     return IUpdateEngineCallback::getDefaultImpl()->onPayloadApplicationComplete(error_code);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace os

}  // namespace android
#include <android/os/BnUpdateEngineCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace os {

BnUpdateEngineCallback::BnUpdateEngineCallback()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnUpdateEngineCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnUpdateEngineCallback::TRANSACTION_onStatusUpdate:
  {
    int32_t in_status_code;
    float in_percentage;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_status_code);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readFloat(&in_percentage);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onStatusUpdate(in_status_code, in_percentage));
  }
  break;
  case BnUpdateEngineCallback::TRANSACTION_onPayloadApplicationComplete:
  {
    int32_t in_error_code;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_error_code);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onPayloadApplicationComplete(in_error_code));
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

}  // namespace os

}  // namespace android
