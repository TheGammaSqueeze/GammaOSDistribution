#include <android/hardware/camera2/ICameraInjectionSession.h>
#include <android/hardware/camera2/BpCameraInjectionSession.h>

namespace android {

namespace hardware {

namespace camera2 {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(CameraInjectionSession, "android.hardware.camera2.ICameraInjectionSession")

}  // namespace camera2

}  // namespace hardware

}  // namespace android
#include <android/hardware/camera2/BpCameraInjectionSession.h>
#include <android/hardware/camera2/BnCameraInjectionSession.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace hardware {

namespace camera2 {

BpCameraInjectionSession::BpCameraInjectionSession(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<ICameraInjectionSession>(_aidl_impl){
}

::android::binder::Status BpCameraInjectionSession::stopInjection() {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnCameraInjectionSession::TRANSACTION_stopInjection, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && ICameraInjectionSession::getDefaultImpl())) {
     return ICameraInjectionSession::getDefaultImpl()->stopInjection();
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace camera2

}  // namespace hardware

}  // namespace android
#include <android/hardware/camera2/BnCameraInjectionSession.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace hardware {

namespace camera2 {

BnCameraInjectionSession::BnCameraInjectionSession()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnCameraInjectionSession::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnCameraInjectionSession::TRANSACTION_stopInjection:
  {
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    ::android::binder::Status _aidl_status(stopInjection());
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

}  // namespace camera2

}  // namespace hardware

}  // namespace android
