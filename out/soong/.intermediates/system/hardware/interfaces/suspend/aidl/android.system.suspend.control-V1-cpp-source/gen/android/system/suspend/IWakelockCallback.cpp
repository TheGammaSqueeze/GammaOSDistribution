#include <android/system/suspend/IWakelockCallback.h>
#include <android/system/suspend/BpWakelockCallback.h>

namespace android {

namespace system {

namespace suspend {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(WakelockCallback, "android.system.suspend.IWakelockCallback")

}  // namespace suspend

}  // namespace system

}  // namespace android
#include <android/system/suspend/BpWakelockCallback.h>
#include <android/system/suspend/BnWakelockCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace system {

namespace suspend {

BpWakelockCallback::BpWakelockCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IWakelockCallback>(_aidl_impl){
}

::android::binder::Status BpWakelockCallback::notifyAcquired() {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnWakelockCallback::TRANSACTION_notifyAcquired, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IWakelockCallback::getDefaultImpl())) {
     return IWakelockCallback::getDefaultImpl()->notifyAcquired();
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpWakelockCallback::notifyReleased() {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnWakelockCallback::TRANSACTION_notifyReleased, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IWakelockCallback::getDefaultImpl())) {
     return IWakelockCallback::getDefaultImpl()->notifyReleased();
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

int32_t BpWakelockCallback::getInterfaceVersion() {
  if (cached_version_ == -1) {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnWakelockCallback::TRANSACTION_getInterfaceVersion, data, &reply);
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

std::string BpWakelockCallback::getInterfaceHash() {
  std::lock_guard<std::mutex> lockGuard(cached_hash_mutex_);
  if (cached_hash_ == "-1") {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnWakelockCallback::TRANSACTION_getInterfaceHash, data, &reply);
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
#include <android/system/suspend/BnWakelockCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace system {

namespace suspend {

BnWakelockCallback::BnWakelockCallback()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnWakelockCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnWakelockCallback::TRANSACTION_notifyAcquired:
  {
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    ::android::binder::Status _aidl_status(notifyAcquired());
  }
  break;
  case BnWakelockCallback::TRANSACTION_notifyReleased:
  {
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    ::android::binder::Status _aidl_status(notifyReleased());
  }
  break;
  case BnWakelockCallback::TRANSACTION_getInterfaceVersion:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeInt32(IWakelockCallback::VERSION);
  }
  break;
  case BnWakelockCallback::TRANSACTION_getInterfaceHash:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeUtf8AsUtf16(IWakelockCallback::HASH);
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

int32_t BnWakelockCallback::getInterfaceVersion() {
  return IWakelockCallback::VERSION;
}

std::string BnWakelockCallback::getInterfaceHash() {
  return IWakelockCallback::HASH;
}

}  // namespace suspend

}  // namespace system

}  // namespace android
