#include <com/android/internal/net/IOemNetdUnsolicitedEventListener.h>
#include <com/android/internal/net/BpOemNetdUnsolicitedEventListener.h>

namespace com {

namespace android {

namespace internal {

namespace net {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(OemNetdUnsolicitedEventListener, "com.android.internal.net.IOemNetdUnsolicitedEventListener")

}  // namespace net

}  // namespace internal

}  // namespace android

}  // namespace com
#include <com/android/internal/net/BpOemNetdUnsolicitedEventListener.h>
#include <com/android/internal/net/BnOemNetdUnsolicitedEventListener.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace com {

namespace android {

namespace internal {

namespace net {

BpOemNetdUnsolicitedEventListener::BpOemNetdUnsolicitedEventListener(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IOemNetdUnsolicitedEventListener>(_aidl_impl){
}

::android::binder::Status BpOemNetdUnsolicitedEventListener::onRegistered() {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnOemNetdUnsolicitedEventListener::TRANSACTION_onRegistered, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IOemNetdUnsolicitedEventListener::getDefaultImpl())) {
     return IOemNetdUnsolicitedEventListener::getDefaultImpl()->onRegistered();
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace net

}  // namespace internal

}  // namespace android

}  // namespace com
#include <com/android/internal/net/BnOemNetdUnsolicitedEventListener.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace com {

namespace android {

namespace internal {

namespace net {

BnOemNetdUnsolicitedEventListener::BnOemNetdUnsolicitedEventListener()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnOemNetdUnsolicitedEventListener::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnOemNetdUnsolicitedEventListener::TRANSACTION_onRegistered:
  {
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    ::android::binder::Status _aidl_status(onRegistered());
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
