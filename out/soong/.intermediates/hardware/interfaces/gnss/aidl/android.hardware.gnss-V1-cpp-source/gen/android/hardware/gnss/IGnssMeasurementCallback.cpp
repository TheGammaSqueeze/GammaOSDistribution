#include <android/hardware/gnss/IGnssMeasurementCallback.h>
#include <android/hardware/gnss/BpGnssMeasurementCallback.h>

namespace android {

namespace hardware {

namespace gnss {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(GnssMeasurementCallback, "android.hardware.gnss.IGnssMeasurementCallback")

}  // namespace gnss

}  // namespace hardware

}  // namespace android
#include <android/hardware/gnss/BpGnssMeasurementCallback.h>
#include <android/hardware/gnss/BnGnssMeasurementCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace hardware {

namespace gnss {

BpGnssMeasurementCallback::BpGnssMeasurementCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IGnssMeasurementCallback>(_aidl_impl){
}

::android::binder::Status BpGnssMeasurementCallback::gnssMeasurementCb(const ::android::hardware::gnss::GnssData& data) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(data);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnGnssMeasurementCallback::TRANSACTION_gnssMeasurementCb, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IGnssMeasurementCallback::getDefaultImpl())) {
     return IGnssMeasurementCallback::getDefaultImpl()->gnssMeasurementCb(data);
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

int32_t BpGnssMeasurementCallback::getInterfaceVersion() {
  if (cached_version_ == -1) {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnGnssMeasurementCallback::TRANSACTION_getInterfaceVersion, data, &reply);
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

std::string BpGnssMeasurementCallback::getInterfaceHash() {
  std::lock_guard<std::mutex> lockGuard(cached_hash_mutex_);
  if (cached_hash_ == "-1") {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnGnssMeasurementCallback::TRANSACTION_getInterfaceHash, data, &reply);
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
#include <android/hardware/gnss/BnGnssMeasurementCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace hardware {

namespace gnss {

BnGnssMeasurementCallback::BnGnssMeasurementCallback()
{
  ::android::internal::Stability::markVintf(this);
}

::android::status_t BnGnssMeasurementCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnGnssMeasurementCallback::TRANSACTION_gnssMeasurementCb:
  {
    ::android::hardware::gnss::GnssData in_data;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_data);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(gnssMeasurementCb(in_data));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnGnssMeasurementCallback::TRANSACTION_getInterfaceVersion:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeInt32(IGnssMeasurementCallback::VERSION);
  }
  break;
  case BnGnssMeasurementCallback::TRANSACTION_getInterfaceHash:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeUtf8AsUtf16(IGnssMeasurementCallback::HASH);
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

int32_t BnGnssMeasurementCallback::getInterfaceVersion() {
  return IGnssMeasurementCallback::VERSION;
}

std::string BnGnssMeasurementCallback::getInterfaceHash() {
  return IGnssMeasurementCallback::HASH;
}

}  // namespace gnss

}  // namespace hardware

}  // namespace android
