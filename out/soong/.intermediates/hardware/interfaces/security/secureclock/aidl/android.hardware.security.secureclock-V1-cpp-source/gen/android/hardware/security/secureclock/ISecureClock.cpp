#include <android/hardware/security/secureclock/ISecureClock.h>
#include <android/hardware/security/secureclock/BpSecureClock.h>

namespace android {

namespace hardware {

namespace security {

namespace secureclock {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(SecureClock, "android.hardware.security.secureclock.ISecureClock")

const ::android::String16& ISecureClock::TIME_STAMP_MAC_LABEL() {
  static const ::android::String16 value(::android::String16("Auth Verification"));
  return value;
}

}  // namespace secureclock

}  // namespace security

}  // namespace hardware

}  // namespace android
#include <android/hardware/security/secureclock/BpSecureClock.h>
#include <android/hardware/security/secureclock/BnSecureClock.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace hardware {

namespace security {

namespace secureclock {

BpSecureClock::BpSecureClock(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<ISecureClock>(_aidl_impl){
}

::android::binder::Status BpSecureClock::generateTimeStamp(int64_t challenge, ::android::hardware::security::secureclock::TimeStampToken* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt64(challenge);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnSecureClock::TRANSACTION_generateTimeStamp, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && ISecureClock::getDefaultImpl())) {
     return ISecureClock::getDefaultImpl()->generateTimeStamp(challenge, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readParcelable(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

int32_t BpSecureClock::getInterfaceVersion() {
  if (cached_version_ == -1) {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnSecureClock::TRANSACTION_getInterfaceVersion, data, &reply);
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

std::string BpSecureClock::getInterfaceHash() {
  std::lock_guard<std::mutex> lockGuard(cached_hash_mutex_);
  if (cached_hash_ == "-1") {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnSecureClock::TRANSACTION_getInterfaceHash, data, &reply);
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

}  // namespace secureclock

}  // namespace security

}  // namespace hardware

}  // namespace android
#include <android/hardware/security/secureclock/BnSecureClock.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace hardware {

namespace security {

namespace secureclock {

BnSecureClock::BnSecureClock()
{
  ::android::internal::Stability::markVintf(this);
}

::android::status_t BnSecureClock::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnSecureClock::TRANSACTION_generateTimeStamp:
  {
    int64_t in_challenge;
    ::android::hardware::security::secureclock::TimeStampToken _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_challenge);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(generateTimeStamp(in_challenge, &_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeParcelable(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnSecureClock::TRANSACTION_getInterfaceVersion:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeInt32(ISecureClock::VERSION);
  }
  break;
  case BnSecureClock::TRANSACTION_getInterfaceHash:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeUtf8AsUtf16(ISecureClock::HASH);
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

int32_t BnSecureClock::getInterfaceVersion() {
  return ISecureClock::VERSION;
}

std::string BnSecureClock::getInterfaceHash() {
  return ISecureClock::HASH;
}

}  // namespace secureclock

}  // namespace security

}  // namespace hardware

}  // namespace android
