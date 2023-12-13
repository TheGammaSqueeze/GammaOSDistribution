#include <com/google/android/startop/iorap/ITaskListener.h>
#include <com/google/android/startop/iorap/BpTaskListener.h>

namespace com {

namespace google {

namespace android {

namespace startop {

namespace iorap {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(TaskListener, "com.google.android.startop.iorap.ITaskListener")

}  // namespace iorap

}  // namespace startop

}  // namespace android

}  // namespace google

}  // namespace com
#include <com/google/android/startop/iorap/BpTaskListener.h>
#include <com/google/android/startop/iorap/BnTaskListener.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace com {

namespace google {

namespace android {

namespace startop {

namespace iorap {

BpTaskListener::BpTaskListener(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<ITaskListener>(_aidl_impl){
}

::android::binder::Status BpTaskListener::onProgress(const ::com::google::android::startop::iorap::RequestId& requestId, const ::com::google::android::startop::iorap::TaskResult& result) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(requestId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(result);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnTaskListener::TRANSACTION_onProgress, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && ITaskListener::getDefaultImpl())) {
     return ITaskListener::getDefaultImpl()->onProgress(requestId, result);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpTaskListener::onComplete(const ::com::google::android::startop::iorap::RequestId& requestId, const ::com::google::android::startop::iorap::TaskResult& result) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(requestId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(result);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnTaskListener::TRANSACTION_onComplete, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && ITaskListener::getDefaultImpl())) {
     return ITaskListener::getDefaultImpl()->onComplete(requestId, result);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace iorap

}  // namespace startop

}  // namespace android

}  // namespace google

}  // namespace com
#include <com/google/android/startop/iorap/BnTaskListener.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace com {

namespace google {

namespace android {

namespace startop {

namespace iorap {

BnTaskListener::BnTaskListener()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnTaskListener::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnTaskListener::TRANSACTION_onProgress:
  {
    ::com::google::android::startop::iorap::RequestId in_requestId;
    ::com::google::android::startop::iorap::TaskResult in_result;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_requestId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_result);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onProgress(in_requestId, in_result));
  }
  break;
  case BnTaskListener::TRANSACTION_onComplete:
  {
    ::com::google::android::startop::iorap::RequestId in_requestId;
    ::com::google::android::startop::iorap::TaskResult in_result;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_requestId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_result);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onComplete(in_requestId, in_result));
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

}  // namespace iorap

}  // namespace startop

}  // namespace android

}  // namespace google

}  // namespace com
