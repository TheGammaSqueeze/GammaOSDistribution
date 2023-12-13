#include <android/hardware/gnss/IGnssPowerIndicationCallback.h>
#include <android/hardware/gnss/BpGnssPowerIndicationCallback.h>

namespace android {

namespace hardware {

namespace gnss {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(GnssPowerIndicationCallback, "android.hardware.gnss.IGnssPowerIndicationCallback")

}  // namespace gnss

}  // namespace hardware

}  // namespace android
#include <android/hardware/gnss/BpGnssPowerIndicationCallback.h>
#include <android/hardware/gnss/BnGnssPowerIndicationCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace hardware {

namespace gnss {

BpGnssPowerIndicationCallback::BpGnssPowerIndicationCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IGnssPowerIndicationCallback>(_aidl_impl){
}

::android::binder::Status BpGnssPowerIndicationCallback::setCapabilitiesCb(int32_t capabilities) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(capabilities);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnGnssPowerIndicationCallback::TRANSACTION_setCapabilitiesCb, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IGnssPowerIndicationCallback::getDefaultImpl())) {
     return IGnssPowerIndicationCallback::getDefaultImpl()->setCapabilitiesCb(capabilities);
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

::android::binder::Status BpGnssPowerIndicationCallback::gnssPowerStatsCb(const ::android::hardware::gnss::GnssPowerStats& gnssPowerStats) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(gnssPowerStats);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnGnssPowerIndicationCallback::TRANSACTION_gnssPowerStatsCb, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IGnssPowerIndicationCallback::getDefaultImpl())) {
     return IGnssPowerIndicationCallback::getDefaultImpl()->gnssPowerStatsCb(gnssPowerStats);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

int32_t BpGnssPowerIndicationCallback::getInterfaceVersion() {
  if (cached_version_ == -1) {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnGnssPowerIndicationCallback::TRANSACTION_getInterfaceVersion, data, &reply);
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

std::string BpGnssPowerIndicationCallback::getInterfaceHash() {
  std::lock_guard<std::mutex> lockGuard(cached_hash_mutex_);
  if (cached_hash_ == "-1") {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnGnssPowerIndicationCallback::TRANSACTION_getInterfaceHash, data, &reply);
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
#include <android/hardware/gnss/BnGnssPowerIndicationCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace hardware {

namespace gnss {

BnGnssPowerIndicationCallback::BnGnssPowerIndicationCallback()
{
  ::android::internal::Stability::markVintf(this);
}

::android::status_t BnGnssPowerIndicationCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnGnssPowerIndicationCallback::TRANSACTION_setCapabilitiesCb:
  {
    int32_t in_capabilities;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_capabilities);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(setCapabilitiesCb(in_capabilities));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnGnssPowerIndicationCallback::TRANSACTION_gnssPowerStatsCb:
  {
    ::android::hardware::gnss::GnssPowerStats in_gnssPowerStats;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_gnssPowerStats);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(gnssPowerStatsCb(in_gnssPowerStats));
  }
  break;
  case BnGnssPowerIndicationCallback::TRANSACTION_getInterfaceVersion:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeInt32(IGnssPowerIndicationCallback::VERSION);
  }
  break;
  case BnGnssPowerIndicationCallback::TRANSACTION_getInterfaceHash:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeUtf8AsUtf16(IGnssPowerIndicationCallback::HASH);
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

int32_t BnGnssPowerIndicationCallback::getInterfaceVersion() {
  return IGnssPowerIndicationCallback::VERSION;
}

std::string BnGnssPowerIndicationCallback::getInterfaceHash() {
  return IGnssPowerIndicationCallback::HASH;
}

}  // namespace gnss

}  // namespace hardware

}  // namespace android
