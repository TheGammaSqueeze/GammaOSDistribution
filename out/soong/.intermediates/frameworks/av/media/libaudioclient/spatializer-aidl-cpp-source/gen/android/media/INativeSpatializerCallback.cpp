#include <android/media/INativeSpatializerCallback.h>
#include <android/media/BpNativeSpatializerCallback.h>

namespace android {

namespace media {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(NativeSpatializerCallback, "android.media.INativeSpatializerCallback")

}  // namespace media

}  // namespace android
#include <android/media/BpNativeSpatializerCallback.h>
#include <android/media/BnNativeSpatializerCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace media {

BpNativeSpatializerCallback::BpNativeSpatializerCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<INativeSpatializerCallback>(_aidl_impl){
}

::android::binder::Status BpNativeSpatializerCallback::onLevelChanged(::android::media::SpatializationLevel level) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByte(static_cast<int8_t>(level));
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNativeSpatializerCallback::TRANSACTION_onLevelChanged, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INativeSpatializerCallback::getDefaultImpl())) {
     return INativeSpatializerCallback::getDefaultImpl()->onLevelChanged(level);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpNativeSpatializerCallback::onOutputChanged(int32_t output) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(output);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNativeSpatializerCallback::TRANSACTION_onOutputChanged, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INativeSpatializerCallback::getDefaultImpl())) {
     return INativeSpatializerCallback::getDefaultImpl()->onOutputChanged(output);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace media

}  // namespace android
#include <android/media/BnNativeSpatializerCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace media {

BnNativeSpatializerCallback::BnNativeSpatializerCallback()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnNativeSpatializerCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnNativeSpatializerCallback::TRANSACTION_onLevelChanged:
  {
    ::android::media::SpatializationLevel in_level;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readByte(reinterpret_cast<int8_t *>(&in_level));
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onLevelChanged(in_level));
  }
  break;
  case BnNativeSpatializerCallback::TRANSACTION_onOutputChanged:
  {
    int32_t in_output;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_output);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onOutputChanged(in_output));
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

}  // namespace media

}  // namespace android
