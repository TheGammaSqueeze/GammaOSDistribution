#include <com/android/internal/net/IOemNetd.h>
#include <com/android/internal/net/BpOemNetd.h>

namespace com {

namespace android {

namespace internal {

namespace net {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(OemNetd, "com.android.internal.net.IOemNetd")

}  // namespace net

}  // namespace internal

}  // namespace android

}  // namespace com
#include <com/android/internal/net/BpOemNetd.h>
#include <com/android/internal/net/BnOemNetd.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace com {

namespace android {

namespace internal {

namespace net {

BpOemNetd::BpOemNetd(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IOemNetd>(_aidl_impl){
}

::android::binder::Status BpOemNetd::isAlive(bool* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnOemNetd::TRANSACTION_isAlive, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IOemNetd::getDefaultImpl())) {
     return IOemNetd::getDefaultImpl()->isAlive(_aidl_return);
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
  _aidl_ret_status = _aidl_reply.readBool(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpOemNetd::registerOemUnsolicitedEventListener(const ::android::sp<::com::android::internal::net::IOemNetdUnsolicitedEventListener>& listener) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeStrongBinder(::com::android::internal::net::IOemNetdUnsolicitedEventListener::asBinder(listener));
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnOemNetd::TRANSACTION_registerOemUnsolicitedEventListener, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IOemNetd::getDefaultImpl())) {
     return IOemNetd::getDefaultImpl()->registerOemUnsolicitedEventListener(listener);
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

}  // namespace net

}  // namespace internal

}  // namespace android

}  // namespace com
#include <com/android/internal/net/BnOemNetd.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace com {

namespace android {

namespace internal {

namespace net {

BnOemNetd::BnOemNetd()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnOemNetd::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnOemNetd::TRANSACTION_isAlive:
  {
    bool _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    ::android::binder::Status _aidl_status(isAlive(&_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeBool(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnOemNetd::TRANSACTION_registerOemUnsolicitedEventListener:
  {
    ::android::sp<::com::android::internal::net::IOemNetdUnsolicitedEventListener> in_listener;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readStrongBinder(&in_listener);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(registerOemUnsolicitedEventListener(in_listener));
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

}  // namespace net

}  // namespace internal

}  // namespace android

}  // namespace com
