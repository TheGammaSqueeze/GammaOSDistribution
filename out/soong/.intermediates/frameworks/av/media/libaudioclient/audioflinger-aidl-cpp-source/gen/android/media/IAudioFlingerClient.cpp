#include <android/media/IAudioFlingerClient.h>
#include <android/media/BpAudioFlingerClient.h>

namespace android {

namespace media {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(AudioFlingerClient, "android.media.IAudioFlingerClient")

}  // namespace media

}  // namespace android
#include <android/media/BpAudioFlingerClient.h>
#include <android/media/BnAudioFlingerClient.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace media {

BpAudioFlingerClient::BpAudioFlingerClient(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IAudioFlingerClient>(_aidl_impl){
}

::android::binder::Status BpAudioFlingerClient::ioConfigChanged(::android::media::AudioIoConfigEvent event, const ::android::media::AudioIoDescriptor& ioDesc) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(static_cast<int32_t>(event));
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(ioDesc);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnAudioFlingerClient::TRANSACTION_ioConfigChanged, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IAudioFlingerClient::getDefaultImpl())) {
     return IAudioFlingerClient::getDefaultImpl()->ioConfigChanged(event, ioDesc);
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
#include <android/media/BnAudioFlingerClient.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace media {

BnAudioFlingerClient::BnAudioFlingerClient()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnAudioFlingerClient::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnAudioFlingerClient::TRANSACTION_ioConfigChanged:
  {
    ::android::media::AudioIoConfigEvent in_event;
    ::android::media::AudioIoDescriptor in_ioDesc;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(reinterpret_cast<int32_t *>(&in_event));
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_ioDesc);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(ioConfigChanged(in_event, in_ioDesc));
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
