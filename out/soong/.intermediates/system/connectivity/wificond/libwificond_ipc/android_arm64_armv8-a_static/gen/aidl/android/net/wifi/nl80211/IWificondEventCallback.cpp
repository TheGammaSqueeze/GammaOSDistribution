#include <android/net/wifi/nl80211/IWificondEventCallback.h>
#include <android/net/wifi/nl80211/BpWificondEventCallback.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(WificondEventCallback, "android.net.wifi.nl80211.IWificondEventCallback")

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
#include <android/net/wifi/nl80211/BpWificondEventCallback.h>
#include <android/net/wifi/nl80211/BnWificondEventCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

BpWificondEventCallback::BpWificondEventCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IWificondEventCallback>(_aidl_impl){
}

::android::binder::Status BpWificondEventCallback::OnRegDomainChanged(const ::std::string& countryCode) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(countryCode);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnWificondEventCallback::TRANSACTION_OnRegDomainChanged, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IWificondEventCallback::getDefaultImpl())) {
     return IWificondEventCallback::getDefaultImpl()->OnRegDomainChanged(countryCode);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
#include <android/net/wifi/nl80211/BnWificondEventCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

BnWificondEventCallback::BnWificondEventCallback()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnWificondEventCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnWificondEventCallback::TRANSACTION_OnRegDomainChanged:
  {
    ::std::string in_countryCode;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_countryCode);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(OnRegDomainChanged(in_countryCode));
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

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
