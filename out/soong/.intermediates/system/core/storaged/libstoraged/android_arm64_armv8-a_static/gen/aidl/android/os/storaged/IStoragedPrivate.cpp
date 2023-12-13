#include <android/os/storaged/IStoragedPrivate.h>
#include <android/os/storaged/BpStoragedPrivate.h>

namespace android {

namespace os {

namespace storaged {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(StoragedPrivate, "android.os.storaged.IStoragedPrivate")

}  // namespace storaged

}  // namespace os

}  // namespace android
#include <android/os/storaged/BpStoragedPrivate.h>
#include <android/os/storaged/BnStoragedPrivate.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace os {

namespace storaged {

BpStoragedPrivate::BpStoragedPrivate(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IStoragedPrivate>(_aidl_impl){
}

::android::binder::Status BpStoragedPrivate::dumpUids(::std::vector<::android::os::storaged::UidInfo>* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnStoragedPrivate::TRANSACTION_dumpUids, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IStoragedPrivate::getDefaultImpl())) {
     return IStoragedPrivate::getDefaultImpl()->dumpUids(_aidl_return);
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
  _aidl_ret_status = _aidl_reply.readParcelableVector(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpStoragedPrivate::dumpPerfHistory(::std::vector<int32_t>* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnStoragedPrivate::TRANSACTION_dumpPerfHistory, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IStoragedPrivate::getDefaultImpl())) {
     return IStoragedPrivate::getDefaultImpl()->dumpPerfHistory(_aidl_return);
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
  _aidl_ret_status = _aidl_reply.readInt32Vector(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace storaged

}  // namespace os

}  // namespace android
#include <android/os/storaged/BnStoragedPrivate.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace os {

namespace storaged {

BnStoragedPrivate::BnStoragedPrivate()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnStoragedPrivate::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnStoragedPrivate::TRANSACTION_dumpUids:
  {
    ::std::vector<::android::os::storaged::UidInfo> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    ::android::binder::Status _aidl_status(dumpUids(&_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeParcelableVector(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnStoragedPrivate::TRANSACTION_dumpPerfHistory:
  {
    ::std::vector<int32_t> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    ::android::binder::Status _aidl_status(dumpPerfHistory(&_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeInt32Vector(_aidl_return);
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

}  // namespace storaged

}  // namespace os

}  // namespace android
