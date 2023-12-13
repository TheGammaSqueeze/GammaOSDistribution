#include <android/net/wifi/nl80211/IInterfaceEventCallback.h>
#include <android/net/wifi/nl80211/BpInterfaceEventCallback.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(InterfaceEventCallback, "android.net.wifi.nl80211.IInterfaceEventCallback")

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
#include <android/net/wifi/nl80211/BpInterfaceEventCallback.h>
#include <android/net/wifi/nl80211/BnInterfaceEventCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

BpInterfaceEventCallback::BpInterfaceEventCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IInterfaceEventCallback>(_aidl_impl){
}

::android::binder::Status BpInterfaceEventCallback::OnClientInterfaceReady(const ::android::sp<::android::net::wifi::nl80211::IClientInterface>& network_interface) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeStrongBinder(::android::net::wifi::nl80211::IClientInterface::asBinder(network_interface));
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnInterfaceEventCallback::TRANSACTION_OnClientInterfaceReady, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IInterfaceEventCallback::getDefaultImpl())) {
     return IInterfaceEventCallback::getDefaultImpl()->OnClientInterfaceReady(network_interface);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpInterfaceEventCallback::OnApInterfaceReady(const ::android::sp<::android::net::wifi::nl80211::IApInterface>& network_interface) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeStrongBinder(::android::net::wifi::nl80211::IApInterface::asBinder(network_interface));
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnInterfaceEventCallback::TRANSACTION_OnApInterfaceReady, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IInterfaceEventCallback::getDefaultImpl())) {
     return IInterfaceEventCallback::getDefaultImpl()->OnApInterfaceReady(network_interface);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpInterfaceEventCallback::OnClientTorndownEvent(const ::android::sp<::android::net::wifi::nl80211::IClientInterface>& network_interface) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeStrongBinder(::android::net::wifi::nl80211::IClientInterface::asBinder(network_interface));
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnInterfaceEventCallback::TRANSACTION_OnClientTorndownEvent, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IInterfaceEventCallback::getDefaultImpl())) {
     return IInterfaceEventCallback::getDefaultImpl()->OnClientTorndownEvent(network_interface);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpInterfaceEventCallback::OnApTorndownEvent(const ::android::sp<::android::net::wifi::nl80211::IApInterface>& network_interface) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeStrongBinder(::android::net::wifi::nl80211::IApInterface::asBinder(network_interface));
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnInterfaceEventCallback::TRANSACTION_OnApTorndownEvent, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IInterfaceEventCallback::getDefaultImpl())) {
     return IInterfaceEventCallback::getDefaultImpl()->OnApTorndownEvent(network_interface);
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
#include <android/net/wifi/nl80211/BnInterfaceEventCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

BnInterfaceEventCallback::BnInterfaceEventCallback()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnInterfaceEventCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnInterfaceEventCallback::TRANSACTION_OnClientInterfaceReady:
  {
    ::android::sp<::android::net::wifi::nl80211::IClientInterface> in_network_interface;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readStrongBinder(&in_network_interface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(OnClientInterfaceReady(in_network_interface));
  }
  break;
  case BnInterfaceEventCallback::TRANSACTION_OnApInterfaceReady:
  {
    ::android::sp<::android::net::wifi::nl80211::IApInterface> in_network_interface;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readStrongBinder(&in_network_interface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(OnApInterfaceReady(in_network_interface));
  }
  break;
  case BnInterfaceEventCallback::TRANSACTION_OnClientTorndownEvent:
  {
    ::android::sp<::android::net::wifi::nl80211::IClientInterface> in_network_interface;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readStrongBinder(&in_network_interface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(OnClientTorndownEvent(in_network_interface));
  }
  break;
  case BnInterfaceEventCallback::TRANSACTION_OnApTorndownEvent:
  {
    ::android::sp<::android::net::wifi::nl80211::IApInterface> in_network_interface;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readStrongBinder(&in_network_interface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(OnApTorndownEvent(in_network_interface));
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
