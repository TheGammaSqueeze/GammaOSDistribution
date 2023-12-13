#include <android/media/ISpatializerHeadTrackingCallback.h>
#include <android/media/BpSpatializerHeadTrackingCallback.h>

namespace android {

namespace media {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(SpatializerHeadTrackingCallback, "android.media.ISpatializerHeadTrackingCallback")

}  // namespace media

}  // namespace android
#include <android/media/BpSpatializerHeadTrackingCallback.h>
#include <android/media/BnSpatializerHeadTrackingCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace media {

BpSpatializerHeadTrackingCallback::BpSpatializerHeadTrackingCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<ISpatializerHeadTrackingCallback>(_aidl_impl){
}

::android::binder::Status BpSpatializerHeadTrackingCallback::onHeadTrackingModeChanged(::android::media::SpatializerHeadTrackingMode mode) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByte(static_cast<int8_t>(mode));
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnSpatializerHeadTrackingCallback::TRANSACTION_onHeadTrackingModeChanged, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && ISpatializerHeadTrackingCallback::getDefaultImpl())) {
     return ISpatializerHeadTrackingCallback::getDefaultImpl()->onHeadTrackingModeChanged(mode);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpSpatializerHeadTrackingCallback::onHeadToSoundStagePoseUpdated(const ::std::vector<float>& headToStage) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeFloatVector(headToStage);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnSpatializerHeadTrackingCallback::TRANSACTION_onHeadToSoundStagePoseUpdated, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && ISpatializerHeadTrackingCallback::getDefaultImpl())) {
     return ISpatializerHeadTrackingCallback::getDefaultImpl()->onHeadToSoundStagePoseUpdated(headToStage);
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
#include <android/media/BnSpatializerHeadTrackingCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace media {

BnSpatializerHeadTrackingCallback::BnSpatializerHeadTrackingCallback()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnSpatializerHeadTrackingCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnSpatializerHeadTrackingCallback::TRANSACTION_onHeadTrackingModeChanged:
  {
    ::android::media::SpatializerHeadTrackingMode in_mode;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readByte(reinterpret_cast<int8_t *>(&in_mode));
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onHeadTrackingModeChanged(in_mode));
  }
  break;
  case BnSpatializerHeadTrackingCallback::TRANSACTION_onHeadToSoundStagePoseUpdated:
  {
    ::std::vector<float> in_headToStage;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readFloatVector(&in_headToStage);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onHeadToSoundStagePoseUpdated(in_headToStage));
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
