#include <android/media/ICaptureStateListener.h>
#include <android/media/BpCaptureStateListener.h>

namespace android {

namespace media {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(CaptureStateListener, "android.media.ICaptureStateListener")

}  // namespace media

}  // namespace android
#include <android/media/BpCaptureStateListener.h>
#include <android/media/BnCaptureStateListener.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace media {

BpCaptureStateListener::BpCaptureStateListener(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<ICaptureStateListener>(_aidl_impl){
}

::android::binder::Status BpCaptureStateListener::setCaptureState(bool active) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(active);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnCaptureStateListener::TRANSACTION_setCaptureState, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && ICaptureStateListener::getDefaultImpl())) {
     return ICaptureStateListener::getDefaultImpl()->setCaptureState(active);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace media

}  // namespace android
#include <android/media/BnCaptureStateListener.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace media {

BnCaptureStateListener::BnCaptureStateListener()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnCaptureStateListener::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnCaptureStateListener::TRANSACTION_setCaptureState:
  {
    bool in_active;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_active);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(setCaptureState(in_active));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
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

}  // namespace media

}  // namespace android
