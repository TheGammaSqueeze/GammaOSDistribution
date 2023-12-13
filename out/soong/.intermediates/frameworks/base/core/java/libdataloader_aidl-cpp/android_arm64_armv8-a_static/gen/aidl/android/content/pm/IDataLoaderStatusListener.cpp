#include <android/content/pm/IDataLoaderStatusListener.h>
#include <android/content/pm/BpDataLoaderStatusListener.h>

namespace android {

namespace content {

namespace pm {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(DataLoaderStatusListener, "android.content.pm.IDataLoaderStatusListener")

}  // namespace pm

}  // namespace content

}  // namespace android
#include <android/content/pm/BpDataLoaderStatusListener.h>
#include <android/content/pm/BnDataLoaderStatusListener.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace content {

namespace pm {

BpDataLoaderStatusListener::BpDataLoaderStatusListener(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IDataLoaderStatusListener>(_aidl_impl){
}

::android::binder::Status BpDataLoaderStatusListener::onStatusChanged(int32_t dataLoaderId, int32_t status) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(dataLoaderId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(status);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnDataLoaderStatusListener::TRANSACTION_onStatusChanged, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IDataLoaderStatusListener::getDefaultImpl())) {
     return IDataLoaderStatusListener::getDefaultImpl()->onStatusChanged(dataLoaderId, status);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace pm

}  // namespace content

}  // namespace android
#include <android/content/pm/BnDataLoaderStatusListener.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace content {

namespace pm {

BnDataLoaderStatusListener::BnDataLoaderStatusListener()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnDataLoaderStatusListener::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnDataLoaderStatusListener::TRANSACTION_onStatusChanged:
  {
    int32_t in_dataLoaderId;
    int32_t in_status;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_dataLoaderId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_status);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onStatusChanged(in_dataLoaderId, in_status));
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

}  // namespace pm

}  // namespace content

}  // namespace android
