#include <android/hardware/gnss/IGnssPsdsCallback.h>
#include <android/hardware/gnss/BpGnssPsdsCallback.h>

namespace android {

namespace hardware {

namespace gnss {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(GnssPsdsCallback, "android.hardware.gnss.IGnssPsdsCallback")

}  // namespace gnss

}  // namespace hardware

}  // namespace android
#include <android/hardware/gnss/BpGnssPsdsCallback.h>
#include <android/hardware/gnss/BnGnssPsdsCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace hardware {

namespace gnss {

BpGnssPsdsCallback::BpGnssPsdsCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IGnssPsdsCallback>(_aidl_impl){
}

::android::binder::Status BpGnssPsdsCallback::downloadRequestCb(::android::hardware::gnss::PsdsType psdsType) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(static_cast<int32_t>(psdsType));
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnGnssPsdsCallback::TRANSACTION_downloadRequestCb, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IGnssPsdsCallback::getDefaultImpl())) {
     return IGnssPsdsCallback::getDefaultImpl()->downloadRequestCb(psdsType);
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

int32_t BpGnssPsdsCallback::getInterfaceVersion() {
  if (cached_version_ == -1) {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnGnssPsdsCallback::TRANSACTION_getInterfaceVersion, data, &reply);
    if (err == ::android::OK) {
      ::android::binder::Status _aidl_status;
      err = _aidl_status.readFromParcel(reply);
      if (err == ::android::OK && _aidl_status.isOk()) {
        cached_version_ = reply.readInt32();
      }
    }
  }
  return cached_version_;
}

std::string BpGnssPsdsCallback::getInterfaceHash() {
  std::lock_guard<std::mutex> lockGuard(cached_hash_mutex_);
  if (cached_hash_ == "-1") {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnGnssPsdsCallback::TRANSACTION_getInterfaceHash, data, &reply);
    if (err == ::android::OK) {
      ::android::binder::Status _aidl_status;
      err = _aidl_status.readFromParcel(reply);
      if (err == ::android::OK && _aidl_status.isOk()) {
        reply.readUtf8FromUtf16(&cached_hash_);
      }
    }
  }
  return cached_hash_;
}

}  // namespace gnss

}  // namespace hardware

}  // namespace android
#include <android/hardware/gnss/BnGnssPsdsCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace hardware {

namespace gnss {

BnGnssPsdsCallback::BnGnssPsdsCallback()
{
  ::android::internal::Stability::markVintf(this);
}

::android::status_t BnGnssPsdsCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnGnssPsdsCallback::TRANSACTION_downloadRequestCb:
  {
    ::android::hardware::gnss::PsdsType in_psdsType;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(reinterpret_cast<int32_t *>(&in_psdsType));
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(downloadRequestCb(in_psdsType));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnGnssPsdsCallback::TRANSACTION_getInterfaceVersion:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeInt32(IGnssPsdsCallback::VERSION);
  }
  break;
  case BnGnssPsdsCallback::TRANSACTION_getInterfaceHash:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeUtf8AsUtf16(IGnssPsdsCallback::HASH);
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

int32_t BnGnssPsdsCallback::getInterfaceVersion() {
  return IGnssPsdsCallback::VERSION;
}

std::string BnGnssPsdsCallback::getInterfaceHash() {
  return IGnssPsdsCallback::HASH;
}

}  // namespace gnss

}  // namespace hardware

}  // namespace android
