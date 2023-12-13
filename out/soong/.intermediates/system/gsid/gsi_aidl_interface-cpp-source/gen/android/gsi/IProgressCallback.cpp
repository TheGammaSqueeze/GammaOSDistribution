#include <android/gsi/IProgressCallback.h>
#include <android/gsi/BpProgressCallback.h>

namespace android {

namespace gsi {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(ProgressCallback, "android.gsi.IProgressCallback")

}  // namespace gsi

}  // namespace android
#include <android/gsi/BpProgressCallback.h>
#include <android/gsi/BnProgressCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace gsi {

BpProgressCallback::BpProgressCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IProgressCallback>(_aidl_impl){
}

::android::binder::Status BpProgressCallback::onProgress(int64_t current, int64_t total) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt64(current);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt64(total);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnProgressCallback::TRANSACTION_onProgress, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IProgressCallback::getDefaultImpl())) {
     return IProgressCallback::getDefaultImpl()->onProgress(current, total);
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

}  // namespace gsi

}  // namespace android
#include <android/gsi/BnProgressCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace gsi {

BnProgressCallback::BnProgressCallback()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnProgressCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnProgressCallback::TRANSACTION_onProgress:
  {
    int64_t in_current;
    int64_t in_total;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_current);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_total);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onProgress(in_current, in_total));
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

}  // namespace gsi

}  // namespace android
