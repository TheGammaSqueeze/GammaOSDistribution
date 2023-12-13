#include <android/os/IIncidentDumpCallback.h>
#include <android/os/BpIncidentDumpCallback.h>

namespace android {

namespace os {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(IncidentDumpCallback, "android.os.IIncidentDumpCallback")

}  // namespace os

}  // namespace android
#include <android/os/BpIncidentDumpCallback.h>
#include <android/os/BnIncidentDumpCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace os {

BpIncidentDumpCallback::BpIncidentDumpCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IIncidentDumpCallback>(_aidl_impl){
}

::android::binder::Status BpIncidentDumpCallback::onDumpSection(const ::android::os::ParcelFileDescriptor& fd) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(fd);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnIncidentDumpCallback::TRANSACTION_onDumpSection, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IIncidentDumpCallback::getDefaultImpl())) {
     return IIncidentDumpCallback::getDefaultImpl()->onDumpSection(fd);
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
#include <android/os/BnIncidentDumpCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace os {

BnIncidentDumpCallback::BnIncidentDumpCallback()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnIncidentDumpCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnIncidentDumpCallback::TRANSACTION_onDumpSection:
  {
    ::android::os::ParcelFileDescriptor in_fd;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_fd);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onDumpSection(in_fd));
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
