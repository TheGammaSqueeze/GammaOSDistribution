#include <android/hardware/security/keymint/IKeyMintDevice.h>
#include <android/hardware/security/keymint/BpKeyMintDevice.h>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(KeyMintDevice, "android.hardware.security.keymint.IKeyMintDevice")

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
#include <android/hardware/security/keymint/BpKeyMintDevice.h>
#include <android/hardware/security/keymint/BnKeyMintDevice.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

BpKeyMintDevice::BpKeyMintDevice(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IKeyMintDevice>(_aidl_impl){
}

::android::binder::Status BpKeyMintDevice::getHardwareInfo(::android::hardware::security::keymint::KeyMintHardwareInfo* _aidl_return) {
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
  _aidl_ret_status = remote()->transact(BnKeyMintDevice::TRANSACTION_getHardwareInfo, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl())) {
     return IKeyMintDevice::getDefaultImpl()->getHardwareInfo(_aidl_return);
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

::android::binder::Status BpKeyMintDevice::addRngEntropy(const ::std::vector<uint8_t>& data) {
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
  _aidl_ret_status = _aidl_data.writeByteVector(data);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeyMintDevice::TRANSACTION_addRngEntropy, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl())) {
     return IKeyMintDevice::getDefaultImpl()->addRngEntropy(data);
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

::android::binder::Status BpKeyMintDevice::generateKey(const ::std::vector<::android::hardware::security::keymint::KeyParameter>& keyParams, const ::std::optional<::android::hardware::security::keymint::AttestationKey>& attestationKey, ::android::hardware::security::keymint::KeyCreationResult* _aidl_return) {
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
  _aidl_ret_status = _aidl_data.writeParcelableVector(keyParams);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeNullableParcelable(attestationKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeyMintDevice::TRANSACTION_generateKey, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl())) {
     return IKeyMintDevice::getDefaultImpl()->generateKey(keyParams, attestationKey, _aidl_return);
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

::android::binder::Status BpKeyMintDevice::importKey(const ::std::vector<::android::hardware::security::keymint::KeyParameter>& keyParams, ::android::hardware::security::keymint::KeyFormat keyFormat, const ::std::vector<uint8_t>& keyData, const ::std::optional<::android::hardware::security::keymint::AttestationKey>& attestationKey, ::android::hardware::security::keymint::KeyCreationResult* _aidl_return) {
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
  _aidl_ret_status = _aidl_data.writeParcelableVector(keyParams);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(static_cast<int32_t>(keyFormat));
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(keyData);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeNullableParcelable(attestationKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeyMintDevice::TRANSACTION_importKey, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl())) {
     return IKeyMintDevice::getDefaultImpl()->importKey(keyParams, keyFormat, keyData, attestationKey, _aidl_return);
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

::android::binder::Status BpKeyMintDevice::importWrappedKey(const ::std::vector<uint8_t>& wrappedKeyData, const ::std::vector<uint8_t>& wrappingKeyBlob, const ::std::vector<uint8_t>& maskingKey, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& unwrappingParams, int64_t passwordSid, int64_t biometricSid, ::android::hardware::security::keymint::KeyCreationResult* _aidl_return) {
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
  _aidl_ret_status = _aidl_data.writeByteVector(wrappedKeyData);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(wrappingKeyBlob);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(maskingKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelableVector(unwrappingParams);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt64(passwordSid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt64(biometricSid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeyMintDevice::TRANSACTION_importWrappedKey, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl())) {
     return IKeyMintDevice::getDefaultImpl()->importWrappedKey(wrappedKeyData, wrappingKeyBlob, maskingKey, unwrappingParams, passwordSid, biometricSid, _aidl_return);
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

::android::binder::Status BpKeyMintDevice::upgradeKey(const ::std::vector<uint8_t>& keyBlobToUpgrade, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& upgradeParams, ::std::vector<uint8_t>* _aidl_return) {
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
  _aidl_ret_status = _aidl_data.writeByteVector(keyBlobToUpgrade);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelableVector(upgradeParams);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeyMintDevice::TRANSACTION_upgradeKey, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl())) {
     return IKeyMintDevice::getDefaultImpl()->upgradeKey(keyBlobToUpgrade, upgradeParams, _aidl_return);
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

::android::binder::Status BpKeyMintDevice::deleteKey(const ::std::vector<uint8_t>& keyBlob) {
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
  _aidl_ret_status = _aidl_data.writeByteVector(keyBlob);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeyMintDevice::TRANSACTION_deleteKey, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl())) {
     return IKeyMintDevice::getDefaultImpl()->deleteKey(keyBlob);
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

::android::binder::Status BpKeyMintDevice::deleteAllKeys() {
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
  _aidl_ret_status = remote()->transact(BnKeyMintDevice::TRANSACTION_deleteAllKeys, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl())) {
     return IKeyMintDevice::getDefaultImpl()->deleteAllKeys();
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

::android::binder::Status BpKeyMintDevice::destroyAttestationIds() {
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
  _aidl_ret_status = remote()->transact(BnKeyMintDevice::TRANSACTION_destroyAttestationIds, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl())) {
     return IKeyMintDevice::getDefaultImpl()->destroyAttestationIds();
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

::android::binder::Status BpKeyMintDevice::begin(::android::hardware::security::keymint::KeyPurpose purpose, const ::std::vector<uint8_t>& keyBlob, const ::std::vector<::android::hardware::security::keymint::KeyParameter>& params, const ::std::optional<::android::hardware::security::keymint::HardwareAuthToken>& authToken, ::android::hardware::security::keymint::BeginResult* _aidl_return) {
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
  _aidl_ret_status = _aidl_data.writeInt32(static_cast<int32_t>(purpose));
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(keyBlob);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelableVector(params);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeNullableParcelable(authToken);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeyMintDevice::TRANSACTION_begin, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl())) {
     return IKeyMintDevice::getDefaultImpl()->begin(purpose, keyBlob, params, authToken, _aidl_return);
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

::android::binder::Status BpKeyMintDevice::deviceLocked(bool passwordOnly, const ::std::optional<::android::hardware::security::secureclock::TimeStampToken>& timestampToken) {
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
  _aidl_ret_status = _aidl_data.writeBool(passwordOnly);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeNullableParcelable(timestampToken);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeyMintDevice::TRANSACTION_deviceLocked, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl())) {
     return IKeyMintDevice::getDefaultImpl()->deviceLocked(passwordOnly, timestampToken);
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

::android::binder::Status BpKeyMintDevice::earlyBootEnded() {
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
  _aidl_ret_status = remote()->transact(BnKeyMintDevice::TRANSACTION_earlyBootEnded, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl())) {
     return IKeyMintDevice::getDefaultImpl()->earlyBootEnded();
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

::android::binder::Status BpKeyMintDevice::convertStorageKeyToEphemeral(const ::std::vector<uint8_t>& storageKeyBlob, ::std::vector<uint8_t>* _aidl_return) {
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
  _aidl_ret_status = _aidl_data.writeByteVector(storageKeyBlob);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeyMintDevice::TRANSACTION_convertStorageKeyToEphemeral, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl())) {
     return IKeyMintDevice::getDefaultImpl()->convertStorageKeyToEphemeral(storageKeyBlob, _aidl_return);
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

::android::binder::Status BpKeyMintDevice::getKeyCharacteristics(const ::std::vector<uint8_t>& keyBlob, const ::std::vector<uint8_t>& appId, const ::std::vector<uint8_t>& appData, ::std::vector<::android::hardware::security::keymint::KeyCharacteristics>* _aidl_return) {
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
  _aidl_ret_status = _aidl_data.writeByteVector(keyBlob);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(appId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(appData);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeyMintDevice::TRANSACTION_getKeyCharacteristics, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl())) {
     return IKeyMintDevice::getDefaultImpl()->getKeyCharacteristics(keyBlob, appId, appData, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readParcelableVector(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

int32_t BpKeyMintDevice::getInterfaceVersion() {
  if (cached_version_ == -1) {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnKeyMintDevice::TRANSACTION_getInterfaceVersion, data, &reply);
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

std::string BpKeyMintDevice::getInterfaceHash() {
  std::lock_guard<std::mutex> lockGuard(cached_hash_mutex_);
  if (cached_hash_ == "-1") {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnKeyMintDevice::TRANSACTION_getInterfaceHash, data, &reply);
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
#include <android/hardware/security/keymint/BnKeyMintDevice.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

BnKeyMintDevice::BnKeyMintDevice()
{
  ::android::internal::Stability::markVintf(this);
}

::android::status_t BnKeyMintDevice::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnKeyMintDevice::TRANSACTION_getHardwareInfo:
  {
    ::android::hardware::security::keymint::KeyMintHardwareInfo _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    ::android::binder::Status _aidl_status(getHardwareInfo(&_aidl_return));
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
  case BnKeyMintDevice::TRANSACTION_addRngEntropy:
  {
    ::std::vector<uint8_t> in_data;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_data);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(addRngEntropy(in_data));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnKeyMintDevice::TRANSACTION_generateKey:
  {
    ::std::vector<::android::hardware::security::keymint::KeyParameter> in_keyParams;
    ::std::optional<::android::hardware::security::keymint::AttestationKey> in_attestationKey;
    ::android::hardware::security::keymint::KeyCreationResult _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_keyParams);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_attestationKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(generateKey(in_keyParams, in_attestationKey, &_aidl_return));
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
  case BnKeyMintDevice::TRANSACTION_importKey:
  {
    ::std::vector<::android::hardware::security::keymint::KeyParameter> in_keyParams;
    ::android::hardware::security::keymint::KeyFormat in_keyFormat;
    ::std::vector<uint8_t> in_keyData;
    ::std::optional<::android::hardware::security::keymint::AttestationKey> in_attestationKey;
    ::android::hardware::security::keymint::KeyCreationResult _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_keyParams);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(reinterpret_cast<int32_t *>(&in_keyFormat));
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_keyData);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_attestationKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(importKey(in_keyParams, in_keyFormat, in_keyData, in_attestationKey, &_aidl_return));
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
  case BnKeyMintDevice::TRANSACTION_importWrappedKey:
  {
    ::std::vector<uint8_t> in_wrappedKeyData;
    ::std::vector<uint8_t> in_wrappingKeyBlob;
    ::std::vector<uint8_t> in_maskingKey;
    ::std::vector<::android::hardware::security::keymint::KeyParameter> in_unwrappingParams;
    int64_t in_passwordSid;
    int64_t in_biometricSid;
    ::android::hardware::security::keymint::KeyCreationResult _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_wrappedKeyData);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_wrappingKeyBlob);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_maskingKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_unwrappingParams);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_passwordSid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_biometricSid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(importWrappedKey(in_wrappedKeyData, in_wrappingKeyBlob, in_maskingKey, in_unwrappingParams, in_passwordSid, in_biometricSid, &_aidl_return));
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
  case BnKeyMintDevice::TRANSACTION_upgradeKey:
  {
    ::std::vector<uint8_t> in_keyBlobToUpgrade;
    ::std::vector<::android::hardware::security::keymint::KeyParameter> in_upgradeParams;
    ::std::vector<uint8_t> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_keyBlobToUpgrade);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_upgradeParams);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(upgradeKey(in_keyBlobToUpgrade, in_upgradeParams, &_aidl_return));
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
  case BnKeyMintDevice::TRANSACTION_deleteKey:
  {
    ::std::vector<uint8_t> in_keyBlob;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_keyBlob);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(deleteKey(in_keyBlob));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnKeyMintDevice::TRANSACTION_deleteAllKeys:
  {
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    ::android::binder::Status _aidl_status(deleteAllKeys());
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnKeyMintDevice::TRANSACTION_destroyAttestationIds:
  {
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    ::android::binder::Status _aidl_status(destroyAttestationIds());
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnKeyMintDevice::TRANSACTION_begin:
  {
    ::android::hardware::security::keymint::KeyPurpose in_purpose;
    ::std::vector<uint8_t> in_keyBlob;
    ::std::vector<::android::hardware::security::keymint::KeyParameter> in_params;
    ::std::optional<::android::hardware::security::keymint::HardwareAuthToken> in_authToken;
    ::android::hardware::security::keymint::BeginResult _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(reinterpret_cast<int32_t *>(&in_purpose));
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_keyBlob);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_params);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_authToken);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(begin(in_purpose, in_keyBlob, in_params, in_authToken, &_aidl_return));
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
  case BnKeyMintDevice::TRANSACTION_deviceLocked:
  {
    bool in_passwordOnly;
    ::std::optional<::android::hardware::security::secureclock::TimeStampToken> in_timestampToken;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_passwordOnly);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_timestampToken);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(deviceLocked(in_passwordOnly, in_timestampToken));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnKeyMintDevice::TRANSACTION_earlyBootEnded:
  {
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    ::android::binder::Status _aidl_status(earlyBootEnded());
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnKeyMintDevice::TRANSACTION_convertStorageKeyToEphemeral:
  {
    ::std::vector<uint8_t> in_storageKeyBlob;
    ::std::vector<uint8_t> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_storageKeyBlob);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(convertStorageKeyToEphemeral(in_storageKeyBlob, &_aidl_return));
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
  case BnKeyMintDevice::TRANSACTION_getKeyCharacteristics:
  {
    ::std::vector<uint8_t> in_keyBlob;
    ::std::vector<uint8_t> in_appId;
    ::std::vector<uint8_t> in_appData;
    ::std::vector<::android::hardware::security::keymint::KeyCharacteristics> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_keyBlob);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_appId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_appData);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(getKeyCharacteristics(in_keyBlob, in_appId, in_appData, &_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeParcelableVector(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnKeyMintDevice::TRANSACTION_getInterfaceVersion:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeInt32(IKeyMintDevice::VERSION);
  }
  break;
  case BnKeyMintDevice::TRANSACTION_getInterfaceHash:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeUtf8AsUtf16(IKeyMintDevice::HASH);
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

int32_t BnKeyMintDevice::getInterfaceVersion() {
  return IKeyMintDevice::VERSION;
}

std::string BnKeyMintDevice::getInterfaceHash() {
  return IKeyMintDevice::HASH;
}

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
