#include <android/os/incremental/IIncrementalServiceConnector.h>
#include <android/os/incremental/BpIncrementalServiceConnector.h>

namespace android {

namespace os {

namespace incremental {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(IncrementalServiceConnector, "android.os.incremental.IIncrementalServiceConnector")

}  // namespace incremental

}  // namespace os

}  // namespace android
#include <android/os/incremental/BpIncrementalServiceConnector.h>
#include <android/os/incremental/BnIncrementalServiceConnector.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace os {

namespace incremental {

BpIncrementalServiceConnector::BpIncrementalServiceConnector(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IIncrementalServiceConnector>(_aidl_impl){
}

::android::binder::Status BpIncrementalServiceConnector::setStorageParams(bool enableReadLogs, int32_t* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(enableReadLogs);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnIncrementalServiceConnector::TRANSACTION_setStorageParams, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IIncrementalServiceConnector::getDefaultImpl())) {
     return IIncrementalServiceConnector::getDefaultImpl()->setStorageParams(enableReadLogs, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readInt32(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace incremental

}  // namespace os

}  // namespace android
#include <android/os/incremental/BnIncrementalServiceConnector.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace os {

namespace incremental {

BnIncrementalServiceConnector::BnIncrementalServiceConnector()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnIncrementalServiceConnector::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnIncrementalServiceConnector::TRANSACTION_setStorageParams:
  {
    bool in_enableReadLogs;
    int32_t _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_enableReadLogs);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(setStorageParams(in_enableReadLogs, &_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeInt32(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
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

}  // namespace incremental

}  // namespace os

}  // namespace android
