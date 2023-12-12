#include <android/hardware/security/keymint/IRemotelyProvisionedComponent.h>
#include <android/hardware/security/keymint/BpRemotelyProvisionedComponent.h>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(RemotelyProvisionedComponent, "android.hardware.security.keymint.IRemotelyProvisionedComponent")

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
#include <android/hardware/security/keymint/BpRemotelyProvisionedComponent.h>
#include <android/hardware/security/keymint/BnRemotelyProvisionedComponent.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

BpRemotelyProvisionedComponent::BpRemotelyProvisionedComponent(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IRemotelyProvisionedComponent>(_aidl_impl){
}

::android::binder::Status BpRemotelyProvisionedComponent::getHardwareInfo(::android::hardware::security::keymint::RpcHardwareInfo* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnRemotelyProvisionedComponent::TRANSACTION_getHardwareInfo, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IRemotelyProvisionedComponent::getDefaultImpl())) {
     return IRemotelyProvisionedComponent::getDefaultImpl()->getHardwareInfo(_aidl_return);
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

::android::binder::Status BpRemotelyProvisionedComponent::generateEcdsaP256KeyPair(bool testMode, ::android::hardware::security::keymint::MacedPublicKey* macedPublicKey, ::std::vector<uint8_t>* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(testMode);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnRemotelyProvisionedComponent::TRANSACTION_generateEcdsaP256KeyPair, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IRemotelyProvisionedComponent::getDefaultImpl())) {
     return IRemotelyProvisionedComponent::getDefaultImpl()->generateEcdsaP256KeyPair(testMode, macedPublicKey, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readParcelable(macedPublicKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpRemotelyProvisionedComponent::generateCertificateRequest(bool testMode, const ::std::vector<::android::hardware::security::keymint::MacedPublicKey>& keysToSign, const ::std::vector<uint8_t>& endpointEncryptionCertChain, const ::std::vector<uint8_t>& challenge, ::android::hardware::security::keymint::DeviceInfo* deviceInfo, ::android::hardware::security::keymint::ProtectedData* protectedData, ::std::vector<uint8_t>* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(testMode);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelableVector(keysToSign);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(endpointEncryptionCertChain);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(challenge);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnRemotelyProvisionedComponent::TRANSACTION_generateCertificateRequest, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IRemotelyProvisionedComponent::getDefaultImpl())) {
     return IRemotelyProvisionedComponent::getDefaultImpl()->generateCertificateRequest(testMode, keysToSign, endpointEncryptionCertChain, challenge, deviceInfo, protectedData, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readParcelable(deviceInfo);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_reply.readParcelable(protectedData);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

int32_t BpRemotelyProvisionedComponent::getInterfaceVersion() {
  if (cached_version_ == -1) {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnRemotelyProvisionedComponent::TRANSACTION_getInterfaceVersion, data, &reply);
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

std::string BpRemotelyProvisionedComponent::getInterfaceHash() {
  std::lock_guard<std::mutex> lockGuard(cached_hash_mutex_);
  if (cached_hash_ == "-1") {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnRemotelyProvisionedComponent::TRANSACTION_getInterfaceHash, data, &reply);
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
#include <android/hardware/security/keymint/BnRemotelyProvisionedComponent.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

BnRemotelyProvisionedComponent::BnRemotelyProvisionedComponent()
{
  ::android::internal::Stability::markVintf(this);
}

::android::status_t BnRemotelyProvisionedComponent::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnRemotelyProvisionedComponent::TRANSACTION_getHardwareInfo:
  {
    ::android::hardware::security::keymint::RpcHardwareInfo _aidl_return;
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
  case BnRemotelyProvisionedComponent::TRANSACTION_generateEcdsaP256KeyPair:
  {
    bool in_testMode;
    ::android::hardware::security::keymint::MacedPublicKey out_macedPublicKey;
    ::std::vector<uint8_t> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_testMode);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(generateEcdsaP256KeyPair(in_testMode, &out_macedPublicKey, &_aidl_return));
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
    _aidl_ret_status = _aidl_reply->writeParcelable(out_macedPublicKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnRemotelyProvisionedComponent::TRANSACTION_generateCertificateRequest:
  {
    bool in_testMode;
    ::std::vector<::android::hardware::security::keymint::MacedPublicKey> in_keysToSign;
    ::std::vector<uint8_t> in_endpointEncryptionCertChain;
    ::std::vector<uint8_t> in_challenge;
    ::android::hardware::security::keymint::DeviceInfo out_deviceInfo;
    ::android::hardware::security::keymint::ProtectedData out_protectedData;
    ::std::vector<uint8_t> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_testMode);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_keysToSign);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_endpointEncryptionCertChain);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_challenge);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(generateCertificateRequest(in_testMode, in_keysToSign, in_endpointEncryptionCertChain, in_challenge, &out_deviceInfo, &out_protectedData, &_aidl_return));
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
    _aidl_ret_status = _aidl_reply->writeParcelable(out_deviceInfo);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeParcelable(out_protectedData);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnRemotelyProvisionedComponent::TRANSACTION_getInterfaceVersion:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeInt32(IRemotelyProvisionedComponent::VERSION);
  }
  break;
  case BnRemotelyProvisionedComponent::TRANSACTION_getInterfaceHash:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeUtf8AsUtf16(IRemotelyProvisionedComponent::HASH);
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

int32_t BnRemotelyProvisionedComponent::getInterfaceVersion() {
  return IRemotelyProvisionedComponent::VERSION;
}

std::string BnRemotelyProvisionedComponent::getInterfaceHash() {
  return IRemotelyProvisionedComponent::HASH;
}

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
