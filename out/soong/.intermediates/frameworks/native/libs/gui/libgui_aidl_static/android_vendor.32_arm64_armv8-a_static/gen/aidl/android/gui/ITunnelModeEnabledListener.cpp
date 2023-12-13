#include <android/gui/ITunnelModeEnabledListener.h>
#include <android/gui/BpTunnelModeEnabledListener.h>

namespace android {

namespace gui {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(TunnelModeEnabledListener, "android.gui.ITunnelModeEnabledListener")

}  // namespace gui

}  // namespace android
#include <android/gui/BpTunnelModeEnabledListener.h>
#include <android/gui/BnTunnelModeEnabledListener.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace gui {

BpTunnelModeEnabledListener::BpTunnelModeEnabledListener(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<ITunnelModeEnabledListener>(_aidl_impl){
}

::android::binder::Status BpTunnelModeEnabledListener::onTunnelModeEnabledChanged(bool enabled) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(enabled);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnTunnelModeEnabledListener::TRANSACTION_onTunnelModeEnabledChanged, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && ITunnelModeEnabledListener::getDefaultImpl())) {
     return ITunnelModeEnabledListener::getDefaultImpl()->onTunnelModeEnabledChanged(enabled);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace gui

}  // namespace android
#include <android/gui/BnTunnelModeEnabledListener.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace gui {

BnTunnelModeEnabledListener::BnTunnelModeEnabledListener()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnTunnelModeEnabledListener::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnTunnelModeEnabledListener::TRANSACTION_onTunnelModeEnabledChanged:
  {
    bool in_enabled;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_enabled);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onTunnelModeEnabledChanged(in_enabled));
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

}  // namespace gui

}  // namespace android
