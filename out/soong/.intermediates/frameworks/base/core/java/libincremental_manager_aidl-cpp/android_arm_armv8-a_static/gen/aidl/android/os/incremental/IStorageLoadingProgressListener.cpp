#include <android/os/incremental/IStorageLoadingProgressListener.h>
#include <android/os/incremental/BpStorageLoadingProgressListener.h>

namespace android {

namespace os {

namespace incremental {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(StorageLoadingProgressListener, "android.os.incremental.IStorageLoadingProgressListener")

}  // namespace incremental

}  // namespace os

}  // namespace android
#include <android/os/incremental/BpStorageLoadingProgressListener.h>
#include <android/os/incremental/BnStorageLoadingProgressListener.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace os {

namespace incremental {

BpStorageLoadingProgressListener::BpStorageLoadingProgressListener(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IStorageLoadingProgressListener>(_aidl_impl){
}

::android::binder::Status BpStorageLoadingProgressListener::onStorageLoadingProgressChanged(int32_t storageId, float progress) {
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
  _aidl_ret_status = _aidl_data.writeFloat(progress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnStorageLoadingProgressListener::TRANSACTION_onStorageLoadingProgressChanged, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IStorageLoadingProgressListener::getDefaultImpl())) {
     return IStorageLoadingProgressListener::getDefaultImpl()->onStorageLoadingProgressChanged(storageId, progress);
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
#include <android/os/incremental/BnStorageLoadingProgressListener.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace os {

namespace incremental {

BnStorageLoadingProgressListener::BnStorageLoadingProgressListener()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnStorageLoadingProgressListener::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnStorageLoadingProgressListener::TRANSACTION_onStorageLoadingProgressChanged:
  {
    int32_t in_storageId;
    float in_progress;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_storageId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readFloat(&in_progress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onStorageLoadingProgressChanged(in_storageId, in_progress));
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
