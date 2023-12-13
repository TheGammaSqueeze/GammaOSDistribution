#include <aaudio/IAAudioClient.h>
#include <aaudio/BpAAudioClient.h>

namespace aaudio {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(AAudioClient, "aaudio.IAAudioClient")

}  // namespace aaudio
#include <aaudio/BpAAudioClient.h>
#include <aaudio/BnAAudioClient.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace aaudio {

BpAAudioClient::BpAAudioClient(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IAAudioClient>(_aidl_impl){
}

::android::binder::Status BpAAudioClient::onStreamChange(int32_t handle, int32_t opcode, int32_t value) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(handle);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(opcode);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(value);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnAAudioClient::TRANSACTION_onStreamChange, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IAAudioClient::getDefaultImpl())) {
     return IAAudioClient::getDefaultImpl()->onStreamChange(handle, opcode, value);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace aaudio
#include <aaudio/BnAAudioClient.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace aaudio {

BnAAudioClient::BnAAudioClient()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnAAudioClient::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnAAudioClient::TRANSACTION_onStreamChange:
  {
    int32_t in_handle;
    int32_t in_opcode;
    int32_t in_value;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_handle);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_opcode);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_value);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onStreamChange(in_handle, in_opcode, in_value));
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

}  // namespace aaudio
