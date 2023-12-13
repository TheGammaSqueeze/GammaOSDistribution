#include <android/system/suspend/ISuspendCallback.h>
#include <android/system/suspend/BpSuspendCallback.h>

namespace android {

namespace system {

namespace suspend {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(SuspendCallback, "android.system.suspend.ISuspendCallback")

}  // namespace suspend

}  // namespace system

}  // namespace android
#include <android/system/suspend/BpSuspendCallback.h>
#include <android/system/suspend/BnSuspendCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace system {

namespace suspend {

BpSuspendCallback::BpSuspendCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<ISuspendCallback>(_aidl_impl){
}

::android::binder::Status BpSuspendCallback::notifyWakeup(bool success, const ::std::vector<::std::string>& wakeupReasons) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(success);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8VectorAsUtf16Vector(wakeupReasons);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnSuspendCallback::TRANSACTION_notifyWakeup, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && ISuspendCallback::getDefaultImpl())) {
     return ISuspendCallback::getDefaultImpl()->notifyWakeup(success, wakeupReasons);
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

int32_t BpSuspendCallback::getInterfaceVersion() {
  if (cached_version_ == -1) {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnSuspendCallback::TRANSACTION_getInterfaceVersion, data, &reply);
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

std::string BpSuspendCallback::getInterfaceHash() {
  std::lock_guard<std::mutex> lockGuard(cached_hash_mutex_);
  if (cached_hash_ == "-1") {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnSuspendCallback::TRANSACTION_getInterfaceHash, data, &reply);
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

}  // namespace suspend

}  // namespace system

}  // namespace android
#include <android/system/suspend/BnSuspendCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace system {

namespace suspend {

BnSuspendCallback::BnSuspendCallback()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnSuspendCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnSuspendCallback::TRANSACTION_notifyWakeup:
  {
    bool in_success;
    ::std::vector<::std::string> in_wakeupReasons;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_success);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8VectorFromUtf16Vector(&in_wakeupReasons);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(notifyWakeup(in_success, in_wakeupReasons));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnSuspendCallback::TRANSACTION_getInterfaceVersion:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeInt32(ISuspendCallback::VERSION);
  }
  break;
  case BnSuspendCallback::TRANSACTION_getInterfaceHash:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeUtf8AsUtf16(ISuspendCallback::HASH);
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

int32_t BnSuspendCallback::getInterfaceVersion() {
  return ISuspendCallback::VERSION;
}

std::string BnSuspendCallback::getInterfaceHash() {
  return ISuspendCallback::HASH;
}

}  // namespace suspend

}  // namespace system

}  // namespace android
