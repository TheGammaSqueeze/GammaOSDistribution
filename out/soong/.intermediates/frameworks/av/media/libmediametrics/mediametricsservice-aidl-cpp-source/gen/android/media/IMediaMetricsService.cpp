#include <android/media/IMediaMetricsService.h>
#include <android/media/BpMediaMetricsService.h>

namespace android {

namespace media {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(MediaMetricsService, "android.media.IMediaMetricsService")

}  // namespace media

}  // namespace android
#include <android/media/BpMediaMetricsService.h>
#include <android/media/BnMediaMetricsService.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace media {

BpMediaMetricsService::BpMediaMetricsService(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IMediaMetricsService>(_aidl_impl){
}

::android::binder::Status BpMediaMetricsService::submitBuffer(const ::std::vector<uint8_t>& buffer) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(buffer);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnMediaMetricsService::TRANSACTION_submitBuffer, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IMediaMetricsService::getDefaultImpl())) {
     return IMediaMetricsService::getDefaultImpl()->submitBuffer(buffer);
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
#include <android/media/BnMediaMetricsService.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace media {

BnMediaMetricsService::BnMediaMetricsService()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnMediaMetricsService::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnMediaMetricsService::TRANSACTION_submitBuffer:
  {
    ::std::vector<uint8_t> in_buffer;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_buffer);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(submitBuffer(in_buffer));
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
