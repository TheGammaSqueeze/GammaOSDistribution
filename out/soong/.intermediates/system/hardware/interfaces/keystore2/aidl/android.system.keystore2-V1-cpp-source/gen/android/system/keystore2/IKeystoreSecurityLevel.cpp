#include <android/system/keystore2/IKeystoreSecurityLevel.h>
#include <android/system/keystore2/BpKeystoreSecurityLevel.h>

namespace android {

namespace system {

namespace keystore2 {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(KeystoreSecurityLevel, "android.system.keystore2.IKeystoreSecurityLevel")

}  // namespace keystore2

}  // namespace system

}  // namespace android
#include <android/system/keystore2/BpKeystoreSecurityLevel.h>
#include <android/system/keystore2/BnKeystoreSecurityLevel.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace system {

namespace keystore2 {

BpKeystoreSecurityLevel::BpKeystoreSecurityLevel(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IKeystoreSecurityLevel>(_aidl_impl){
}

::android::binder::Status BpKeystoreSecurityLevel::createOperation(const ::android::system::keystore2::KeyDescriptor& key, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& operationParameters, bool forced, ::android::system::keystore2::CreateOperationResponse* _aidl_return) {
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
  _aidl_ret_status = _aidl_data.writeParcelable(key);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelableVector(operationParameters);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(forced);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeystoreSecurityLevel::TRANSACTION_createOperation, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeystoreSecurityLevel::getDefaultImpl())) {
     return IKeystoreSecurityLevel::getDefaultImpl()->createOperation(key, operationParameters, forced, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readParcelable(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpKeystoreSecurityLevel::generateKey(const ::android::system::keystore2::KeyDescriptor& key, const ::std::optional<::android::system::keystore2::KeyDescriptor>& attestationKey, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& params, int32_t flags, const ::std::vector<uint8_t>& entropy, ::android::system::keystore2::KeyMetadata* _aidl_return) {
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
  _aidl_ret_status = _aidl_data.writeParcelable(key);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeNullableParcelable(attestationKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelableVector(params);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(flags);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(entropy);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeystoreSecurityLevel::TRANSACTION_generateKey, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeystoreSecurityLevel::getDefaultImpl())) {
     return IKeystoreSecurityLevel::getDefaultImpl()->generateKey(key, attestationKey, params, flags, entropy, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readParcelable(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpKeystoreSecurityLevel::importKey(const ::android::system::keystore2::KeyDescriptor& key, const ::std::optional<::android::system::keystore2::KeyDescriptor>& attestationKey, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& params, int32_t flags, const ::std::vector<uint8_t>& keyData, ::android::system::keystore2::KeyMetadata* _aidl_return) {
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
  _aidl_ret_status = _aidl_data.writeParcelable(key);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeNullableParcelable(attestationKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelableVector(params);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(flags);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(keyData);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeystoreSecurityLevel::TRANSACTION_importKey, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeystoreSecurityLevel::getDefaultImpl())) {
     return IKeystoreSecurityLevel::getDefaultImpl()->importKey(key, attestationKey, params, flags, keyData, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readParcelable(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpKeystoreSecurityLevel::importWrappedKey(const ::android::system::keystore2::KeyDescriptor& key, const ::android::system::keystore2::KeyDescriptor& wrappingKey, const ::std::optional<::std::vector<uint8_t>>& maskingKey, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& params, const ::std::vector<::android::system::keystore2::AuthenticatorSpec>& authenticators, ::android::system::keystore2::KeyMetadata* _aidl_return) {
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
  _aidl_ret_status = _aidl_data.writeParcelable(key);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(wrappingKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(maskingKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelableVector(params);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelableVector(authenticators);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeystoreSecurityLevel::TRANSACTION_importWrappedKey, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeystoreSecurityLevel::getDefaultImpl())) {
     return IKeystoreSecurityLevel::getDefaultImpl()->importWrappedKey(key, wrappingKey, maskingKey, params, authenticators, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readParcelable(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpKeystoreSecurityLevel::convertStorageKeyToEphemeral(const ::android::system::keystore2::KeyDescriptor& storageKey, ::android::system::keystore2::EphemeralStorageKeyResponse* _aidl_return) {
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
  _aidl_ret_status = _aidl_data.writeParcelable(storageKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeystoreSecurityLevel::TRANSACTION_convertStorageKeyToEphemeral, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeystoreSecurityLevel::getDefaultImpl())) {
     return IKeystoreSecurityLevel::getDefaultImpl()->convertStorageKeyToEphemeral(storageKey, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readParcelable(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpKeystoreSecurityLevel::deleteKey(const ::android::system::keystore2::KeyDescriptor& key) {
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
  _aidl_ret_status = _aidl_data.writeParcelable(key);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeystoreSecurityLevel::TRANSACTION_deleteKey, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeystoreSecurityLevel::getDefaultImpl())) {
     return IKeystoreSecurityLevel::getDefaultImpl()->deleteKey(key);
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

int32_t BpKeystoreSecurityLevel::getInterfaceVersion() {
  if (cached_version_ == -1) {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnKeystoreSecurityLevel::TRANSACTION_getInterfaceVersion, data, &reply);
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

std::string BpKeystoreSecurityLevel::getInterfaceHash() {
  std::lock_guard<std::mutex> lockGuard(cached_hash_mutex_);
  if (cached_hash_ == "-1") {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnKeystoreSecurityLevel::TRANSACTION_getInterfaceHash, data, &reply);
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

}  // namespace keystore2

}  // namespace system

}  // namespace android
#include <android/system/keystore2/BnKeystoreSecurityLevel.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace system {

namespace keystore2 {

BnKeystoreSecurityLevel::BnKeystoreSecurityLevel()
{
  ::android::internal::Stability::markVintf(this);
}

::android::status_t BnKeystoreSecurityLevel::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnKeystoreSecurityLevel::TRANSACTION_createOperation:
  {
    ::android::system::keystore2::KeyDescriptor in_key;
    ::std::vector<::android::hardware::security::keymint::KeyParameter> in_operationParameters;
    bool in_forced;
    ::android::system::keystore2::CreateOperationResponse _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_key);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_operationParameters);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_forced);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(createOperation(in_key, in_operationParameters, in_forced, &_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeParcelable(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnKeystoreSecurityLevel::TRANSACTION_generateKey:
  {
    ::android::system::keystore2::KeyDescriptor in_key;
    ::std::optional<::android::system::keystore2::KeyDescriptor> in_attestationKey;
    ::std::vector<::android::hardware::security::keymint::KeyParameter> in_params;
    int32_t in_flags;
    ::std::vector<uint8_t> in_entropy;
    ::android::system::keystore2::KeyMetadata _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_key);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_attestationKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_params);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_flags);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_entropy);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(generateKey(in_key, in_attestationKey, in_params, in_flags, in_entropy, &_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeParcelable(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnKeystoreSecurityLevel::TRANSACTION_importKey:
  {
    ::android::system::keystore2::KeyDescriptor in_key;
    ::std::optional<::android::system::keystore2::KeyDescriptor> in_attestationKey;
    ::std::vector<::android::hardware::security::keymint::KeyParameter> in_params;
    int32_t in_flags;
    ::std::vector<uint8_t> in_keyData;
    ::android::system::keystore2::KeyMetadata _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_key);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_attestationKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_params);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_flags);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_keyData);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(importKey(in_key, in_attestationKey, in_params, in_flags, in_keyData, &_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeParcelable(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnKeystoreSecurityLevel::TRANSACTION_importWrappedKey:
  {
    ::android::system::keystore2::KeyDescriptor in_key;
    ::android::system::keystore2::KeyDescriptor in_wrappingKey;
    ::std::optional<::std::vector<uint8_t>> in_maskingKey;
    ::std::vector<::android::hardware::security::keymint::KeyParameter> in_params;
    ::std::vector<::android::system::keystore2::AuthenticatorSpec> in_authenticators;
    ::android::system::keystore2::KeyMetadata _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_key);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_wrappingKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_maskingKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_params);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_authenticators);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(importWrappedKey(in_key, in_wrappingKey, in_maskingKey, in_params, in_authenticators, &_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeParcelable(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnKeystoreSecurityLevel::TRANSACTION_convertStorageKeyToEphemeral:
  {
    ::android::system::keystore2::KeyDescriptor in_storageKey;
    ::android::system::keystore2::EphemeralStorageKeyResponse _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_storageKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(convertStorageKeyToEphemeral(in_storageKey, &_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeParcelable(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnKeystoreSecurityLevel::TRANSACTION_deleteKey:
  {
    ::android::system::keystore2::KeyDescriptor in_key;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_key);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(deleteKey(in_key));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnKeystoreSecurityLevel::TRANSACTION_getInterfaceVersion:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeInt32(IKeystoreSecurityLevel::VERSION);
  }
  break;
  case BnKeystoreSecurityLevel::TRANSACTION_getInterfaceHash:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeUtf8AsUtf16(IKeystoreSecurityLevel::HASH);
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

int32_t BnKeystoreSecurityLevel::getInterfaceVersion() {
  return IKeystoreSecurityLevel::VERSION;
}

std::string BnKeystoreSecurityLevel::getInterfaceHash() {
  return IKeystoreSecurityLevel::HASH;
}

}  // namespace keystore2

}  // namespace system

}  // namespace android
