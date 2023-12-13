#include <android/os/IVoldMountCallback.h>
#include <android/os/BpVoldMountCallback.h>

namespace android {

namespace os {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(VoldMountCallback, "android.os.IVoldMountCallback")

}  // namespace os

}  // namespace android
#include <android/os/BpVoldMountCallback.h>
#include <android/os/BnVoldMountCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace os {

BpVoldMountCallback::BpVoldMountCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IVoldMountCallback>(_aidl_impl){
}

::android::binder::Status BpVoldMountCallback::onVolumeChecking(::android::base::unique_fd fuseFd, const ::std::string& path, const ::std::string& internalPath, bool* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUniqueFileDescriptor(fuseFd);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(path);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(internalPath);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnVoldMountCallback::TRANSACTION_onVolumeChecking, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IVoldMountCallback::getDefaultImpl())) {
     return IVoldMountCallback::getDefaultImpl()->onVolumeChecking(std::move(fuseFd), path, internalPath, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readBool(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace os

}  // namespace android
#include <android/os/BnVoldMountCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace os {

BnVoldMountCallback::BnVoldMountCallback()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnVoldMountCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnVoldMountCallback::TRANSACTION_onVolumeChecking:
  {
    ::android::base::unique_fd in_fuseFd;
    ::std::string in_path;
    ::std::string in_internalPath;
    bool _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUniqueFileDescriptor(&in_fuseFd);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_path);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_internalPath);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onVolumeChecking(std::move(in_fuseFd), in_path, in_internalPath, &_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeBool(_aidl_return);
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

}  // namespace os

}  // namespace android
