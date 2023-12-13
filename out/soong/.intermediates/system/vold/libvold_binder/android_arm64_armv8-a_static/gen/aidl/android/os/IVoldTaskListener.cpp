#include <android/os/IVoldTaskListener.h>
#include <android/os/BpVoldTaskListener.h>

namespace android {

namespace os {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(VoldTaskListener, "android.os.IVoldTaskListener")

}  // namespace os

}  // namespace android
#include <android/os/BpVoldTaskListener.h>
#include <android/os/BnVoldTaskListener.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace os {

BpVoldTaskListener::BpVoldTaskListener(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IVoldTaskListener>(_aidl_impl){
}

::android::binder::Status BpVoldTaskListener::onStatus(int32_t status, const ::android::os::PersistableBundle& extras) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(status);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(extras);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnVoldTaskListener::TRANSACTION_onStatus, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IVoldTaskListener::getDefaultImpl())) {
     return IVoldTaskListener::getDefaultImpl()->onStatus(status, extras);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpVoldTaskListener::onFinished(int32_t status, const ::android::os::PersistableBundle& extras) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(status);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(extras);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnVoldTaskListener::TRANSACTION_onFinished, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IVoldTaskListener::getDefaultImpl())) {
     return IVoldTaskListener::getDefaultImpl()->onFinished(status, extras);
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
#include <android/os/BnVoldTaskListener.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace os {

BnVoldTaskListener::BnVoldTaskListener()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnVoldTaskListener::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnVoldTaskListener::TRANSACTION_onStatus:
  {
    int32_t in_status;
    ::android::os::PersistableBundle in_extras;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_status);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_extras);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onStatus(in_status, in_extras));
  }
  break;
  case BnVoldTaskListener::TRANSACTION_onFinished:
  {
    int32_t in_status;
    ::android::os::PersistableBundle in_extras;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_status);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_extras);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onFinished(in_status, in_extras));
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
