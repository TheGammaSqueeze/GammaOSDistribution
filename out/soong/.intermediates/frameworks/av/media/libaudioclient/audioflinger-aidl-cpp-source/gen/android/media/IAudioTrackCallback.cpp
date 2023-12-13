#include <android/media/IAudioTrackCallback.h>
#include <android/media/BpAudioTrackCallback.h>

namespace android {

namespace media {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(AudioTrackCallback, "android.media.IAudioTrackCallback")

}  // namespace media

}  // namespace android
#include <android/media/BpAudioTrackCallback.h>
#include <android/media/BnAudioTrackCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace media {

BpAudioTrackCallback::BpAudioTrackCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IAudioTrackCallback>(_aidl_impl){
}

::android::binder::Status BpAudioTrackCallback::onCodecFormatChanged(const ::std::vector<uint8_t>& audioMetadata) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(audioMetadata);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnAudioTrackCallback::TRANSACTION_onCodecFormatChanged, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IAudioTrackCallback::getDefaultImpl())) {
     return IAudioTrackCallback::getDefaultImpl()->onCodecFormatChanged(audioMetadata);
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
#include <android/media/BnAudioTrackCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace media {

BnAudioTrackCallback::BnAudioTrackCallback()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnAudioTrackCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnAudioTrackCallback::TRANSACTION_onCodecFormatChanged:
  {
    ::std::vector<uint8_t> in_audioMetadata;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_audioMetadata);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onCodecFormatChanged(in_audioMetadata));
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
