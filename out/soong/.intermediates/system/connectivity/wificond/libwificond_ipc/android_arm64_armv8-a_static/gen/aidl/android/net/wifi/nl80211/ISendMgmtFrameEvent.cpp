#include <android/net/wifi/nl80211/ISendMgmtFrameEvent.h>
#include <android/net/wifi/nl80211/BpSendMgmtFrameEvent.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(SendMgmtFrameEvent, "android.net.wifi.nl80211.ISendMgmtFrameEvent")

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
#include <android/net/wifi/nl80211/BpSendMgmtFrameEvent.h>
#include <android/net/wifi/nl80211/BnSendMgmtFrameEvent.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

BpSendMgmtFrameEvent::BpSendMgmtFrameEvent(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<ISendMgmtFrameEvent>(_aidl_impl){
}

::android::binder::Status BpSendMgmtFrameEvent::OnAck(int32_t elapsedTimeMs) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(elapsedTimeMs);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnSendMgmtFrameEvent::TRANSACTION_OnAck, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && ISendMgmtFrameEvent::getDefaultImpl())) {
     return ISendMgmtFrameEvent::getDefaultImpl()->OnAck(elapsedTimeMs);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpSendMgmtFrameEvent::OnFailure(int32_t reason) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(reason);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnSendMgmtFrameEvent::TRANSACTION_OnFailure, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && ISendMgmtFrameEvent::getDefaultImpl())) {
     return ISendMgmtFrameEvent::getDefaultImpl()->OnFailure(reason);
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
#include <android/net/wifi/nl80211/BnSendMgmtFrameEvent.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

BnSendMgmtFrameEvent::BnSendMgmtFrameEvent()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnSendMgmtFrameEvent::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnSendMgmtFrameEvent::TRANSACTION_OnAck:
  {
    int32_t in_elapsedTimeMs;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_elapsedTimeMs);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(OnAck(in_elapsedTimeMs));
  }
  break;
  case BnSendMgmtFrameEvent::TRANSACTION_OnFailure:
  {
    int32_t in_reason;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_reason);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(OnFailure(in_reason));
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
