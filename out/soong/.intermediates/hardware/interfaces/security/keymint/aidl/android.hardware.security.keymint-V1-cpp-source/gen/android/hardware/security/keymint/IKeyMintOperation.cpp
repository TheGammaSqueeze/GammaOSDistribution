#include <android/hardware/security/keymint/IKeyMintOperation.h>
#include <android/hardware/security/keymint/BpKeyMintOperation.h>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(KeyMintOperation, "android.hardware.security.keymint.IKeyMintOperation")

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
#include <android/hardware/security/keymint/BpKeyMintOperation.h>
#include <android/hardware/security/keymint/BnKeyMintOperation.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

BpKeyMintOperation::BpKeyMintOperation(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IKeyMintOperation>(_aidl_impl){
}

::android::binder::Status BpKeyMintOperation::updateAad(const ::std::vector<uint8_t>& input, const ::std::optional<::android::hardware::security::keymint::HardwareAuthToken>& authToken, const ::std::optional<::android::hardware::security::secureclock::TimeStampToken>& timeStampToken) {
  ::android::Parcel _aidl_data;
  _aidl_data.markSensitive();
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(input);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeNullableParcelable(authToken);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeNullableParcelable(timeStampToken);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeyMintOperation::TRANSACTION_updateAad, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeyMintOperation::getDefaultImpl())) {
     return IKeyMintOperation::getDefaultImpl()->updateAad(input, authToken, timeStampToken);
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
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpKeyMintOperation::update(const ::std::vector<uint8_t>& input, const ::std::optional<::android::hardware::security::keymint::HardwareAuthToken>& authToken, const ::std::optional<::android::hardware::security::secureclock::TimeStampToken>& timeStampToken, ::std::vector<uint8_t>* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markSensitive();
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(input);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeNullableParcelable(authToken);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeNullableParcelable(timeStampToken);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeyMintOperation::TRANSACTION_update, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeyMintOperation::getDefaultImpl())) {
     return IKeyMintOperation::getDefaultImpl()->update(input, authToken, timeStampToken, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readByteVector(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpKeyMintOperation::finish(const ::std::optional<::std::vector<uint8_t>>& input, const ::std::optional<::std::vector<uint8_t>>& signature, const ::std::optional<::android::hardware::security::keymint::HardwareAuthToken>& authToken, const ::std::optional<::android::hardware::security::secureclock::TimeStampToken>& timestampToken, const ::std::optional<::std::vector<uint8_t>>& confirmationToken, ::std::vector<uint8_t>* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markSensitive();
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(input);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(signature);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeNullableParcelable(authToken);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeNullableParcelable(timestampToken);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(confirmationToken);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeyMintOperation::TRANSACTION_finish, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeyMintOperation::getDefaultImpl())) {
     return IKeyMintOperation::getDefaultImpl()->finish(input, signature, authToken, timestampToken, confirmationToken, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readByteVector(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpKeyMintOperation::abort() {
  ::android::Parcel _aidl_data;
  _aidl_data.markSensitive();
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeyMintOperation::TRANSACTION_abort, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeyMintOperation::getDefaultImpl())) {
     return IKeyMintOperation::getDefaultImpl()->abort();
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
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

int32_t BpKeyMintOperation::getInterfaceVersion() {
  if (cached_version_ == -1) {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnKeyMintOperation::TRANSACTION_getInterfaceVersion, data, &reply);
    if (err == ::android::OK) {
      ::android::binder::Status _aidl_status;
      err = _aidl_status.readFromParcel(reply);
      if (err == ::android::OK && _aidl_status.isOk()) {
        cached_version_ = reply.readInt32();
      }
    }
  }
  return cached_version_;
}

std::string BpKeyMintOperation::getInterfaceHash() {
  std::lock_guard<std::mutex> lockGuard(cached_hash_mutex_);
  if (cached_hash_ == "-1") {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnKeyMintOperation::TRANSACTION_getInterfaceHash, data, &reply);
    if (err == ::android::OK) {
      ::android::binder::Status _aidl_status;
      err = _aidl_status.readFromParcel(reply);
      if (err == ::android::OK && _aidl_status.isOk()) {
        reply.readUtf8FromUtf16(&cached_hash_);
      }
    }
  }
  return cached_hash_;
}

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
#include <android/hardware/security/keymint/BnKeyMintOperation.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

BnKeyMintOperation::BnKeyMintOperation()
{
  ::android::internal::Stability::markVintf(this);
}

::android::status_t BnKeyMintOperation::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnKeyMintOperation::TRANSACTION_updateAad:
  {
    ::std::vector<uint8_t> in_input;
    ::std::optional<::android::hardware::security::keymint::HardwareAuthToken> in_authToken;
    ::std::optional<::android::hardware::security::secureclock::TimeStampToken> in_timeStampToken;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_input);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_authToken);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_timeStampToken);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(updateAad(in_input, in_authToken, in_timeStampToken));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnKeyMintOperation::TRANSACTION_update:
  {
    ::std::vector<uint8_t> in_input;
    ::std::optional<::android::hardware::security::keymint::HardwareAuthToken> in_authToken;
    ::std::optional<::android::hardware::security::secureclock::TimeStampToken> in_timeStampToken;
    ::std::vector<uint8_t> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_input);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_authToken);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_timeStampToken);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(update(in_input, in_authToken, in_timeStampToken, &_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeByteVector(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnKeyMintOperation::TRANSACTION_finish:
  {
    ::std::optional<::std::vector<uint8_t>> in_input;
    ::std::optional<::std::vector<uint8_t>> in_signature;
    ::std::optional<::android::hardware::security::keymint::HardwareAuthToken> in_authToken;
    ::std::optional<::android::hardware::security::secureclock::TimeStampToken> in_timestampToken;
    ::std::optional<::std::vector<uint8_t>> in_confirmationToken;
    ::std::vector<uint8_t> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_input);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_signature);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_authToken);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_timestampToken);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_confirmationToken);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(finish(in_input, in_signature, in_authToken, in_timestampToken, in_confirmationToken, &_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeByteVector(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnKeyMintOperation::TRANSACTION_abort:
  {
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    ::android::binder::Status _aidl_status(abort());
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnKeyMintOperation::TRANSACTION_getInterfaceVersion:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeInt32(IKeyMintOperation::VERSION);
  }
  break;
  case BnKeyMintOperation::TRANSACTION_getInterfaceHash:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeUtf8AsUtf16(IKeyMintOperation::HASH);
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

int32_t BnKeyMintOperation::getInterfaceVersion() {
  return IKeyMintOperation::VERSION;
}

std::string BnKeyMintOperation::getInterfaceHash() {
  return IKeyMintOperation::HASH;
}

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
