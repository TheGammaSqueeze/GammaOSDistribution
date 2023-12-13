#include <android/net/wifi/nl80211/IApInterfaceEventCallback.h>
#include <android/net/wifi/nl80211/BpApInterfaceEventCallback.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(ApInterfaceEventCallback, "android.net.wifi.nl80211.IApInterfaceEventCallback")

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
#include <android/net/wifi/nl80211/BpApInterfaceEventCallback.h>
#include <android/net/wifi/nl80211/BnApInterfaceEventCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

BpApInterfaceEventCallback::BpApInterfaceEventCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IApInterfaceEventCallback>(_aidl_impl){
}

::android::binder::Status BpApInterfaceEventCallback::onConnectedClientsChanged(const ::android::net::wifi::nl80211::NativeWifiClient& client, bool isConnected) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(client);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(isConnected);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnApInterfaceEventCallback::TRANSACTION_onConnectedClientsChanged, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IApInterfaceEventCallback::getDefaultImpl())) {
     return IApInterfaceEventCallback::getDefaultImpl()->onConnectedClientsChanged(client, isConnected);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpApInterfaceEventCallback::onSoftApChannelSwitched(int32_t frequency, int32_t bandwidth) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(frequency);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(bandwidth);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnApInterfaceEventCallback::TRANSACTION_onSoftApChannelSwitched, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IApInterfaceEventCallback::getDefaultImpl())) {
     return IApInterfaceEventCallback::getDefaultImpl()->onSoftApChannelSwitched(frequency, bandwidth);
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
#include <android/net/wifi/nl80211/BnApInterfaceEventCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

BnApInterfaceEventCallback::BnApInterfaceEventCallback()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnApInterfaceEventCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnApInterfaceEventCallback::TRANSACTION_onConnectedClientsChanged:
  {
    ::android::net::wifi::nl80211::NativeWifiClient in_client;
    bool in_isConnected;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_client);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_isConnected);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onConnectedClientsChanged(in_client, in_isConnected));
  }
  break;
  case BnApInterfaceEventCallback::TRANSACTION_onSoftApChannelSwitched:
  {
    int32_t in_frequency;
    int32_t in_bandwidth;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_frequency);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_bandwidth);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onSoftApChannelSwitched(in_frequency, in_bandwidth));
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
