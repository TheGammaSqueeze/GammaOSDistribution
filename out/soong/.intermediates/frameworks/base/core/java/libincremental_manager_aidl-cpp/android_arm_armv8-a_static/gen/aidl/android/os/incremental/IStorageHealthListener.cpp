#include <android/os/incremental/IStorageHealthListener.h>
#include <android/os/incremental/BpStorageHealthListener.h>

namespace android {

namespace os {

namespace incremental {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(StorageHealthListener, "android.os.incremental.IStorageHealthListener")

}  // namespace incremental

}  // namespace os

}  // namespace android
#include <android/os/incremental/BpStorageHealthListener.h>
#include <android/os/incremental/BnStorageHealthListener.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace os {

namespace incremental {

BpStorageHealthListener::BpStorageHealthListener(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IStorageHealthListener>(_aidl_impl){
}

::android::binder::Status BpStorageHealthListener::onHealthStatus(int32_t storageId, int32_t status) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(storageId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(status);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnStorageHealthListener::TRANSACTION_onHealthStatus, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IStorageHealthListener::getDefaultImpl())) {
     return IStorageHealthListener::getDefaultImpl()->onHealthStatus(storageId, status);
  }
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
#include <android/os/incremental/BnStorageHealthListener.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace os {

namespace incremental {

BnStorageHealthListener::BnStorageHealthListener()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnStorageHealthListener::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnStorageHealthListener::TRANSACTION_onHealthStatus:
  {
    int32_t in_storageId;
    int32_t in_status;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_storageId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_status);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onHealthStatus(in_storageId, in_status));
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
