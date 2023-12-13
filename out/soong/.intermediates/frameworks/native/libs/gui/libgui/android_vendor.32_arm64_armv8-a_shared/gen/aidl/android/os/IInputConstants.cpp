#include <android/os/IInputConstants.h>
#include <android/os/BpInputConstants.h>

namespace android {

namespace os {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(InputConstants, "android.os.IInputConstants")

}  // namespace os

}  // namespace android
#include <android/os/BpInputConstants.h>
#include <android/os/BnInputConstants.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace os {

BpInputConstants::BpInputConstants(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IInputConstants>(_aidl_impl){
}

}  // namespace os

}  // namespace android
#include <android/os/BnInputConstants.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace os {

BnInputConstants::BnInputConstants()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnInputConstants::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
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
