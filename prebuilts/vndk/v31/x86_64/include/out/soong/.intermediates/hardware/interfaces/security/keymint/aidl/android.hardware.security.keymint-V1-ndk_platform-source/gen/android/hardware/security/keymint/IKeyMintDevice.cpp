#include <android/binder_parcel_utils.h>
#include <aidl/android/hardware/security/keymint/BpKeyMintDevice.h>
#include <aidl/android/hardware/security/keymint/BnKeyMintDevice.h>
#include <aidl/android/hardware/security/keymint/IKeyMintDevice.h>

namespace aidl {
namespace android {
namespace hardware {
namespace security {
namespace keymint {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnKeyMintDevice> _aidl_impl = std::static_pointer_cast<BnKeyMintDevice>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*getHardwareInfo*/): {
      ::aidl::android::hardware::security::keymint::KeyMintHardwareInfo _aidl_return;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getHardwareInfo(&_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeParcelable(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*addRngEntropy*/): {
      std::vector<uint8_t> in_data;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_data);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->addRngEntropy(in_data);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 2 /*generateKey*/): {
      std::vector<::aidl::android::hardware::security::keymint::KeyParameter> in_keyParams;
      std::optional<::aidl::android::hardware::security::keymint::AttestationKey> in_attestationKey;
      ::aidl::android::hardware::security::keymint::KeyCreationResult _aidl_return;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_keyParams);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readNullableParcelable(_aidl_in, &in_attestationKey);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->generateKey(in_keyParams, in_attestationKey, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeParcelable(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 3 /*importKey*/): {
      std::vector<::aidl::android::hardware::security::keymint::KeyParameter> in_keyParams;
      ::aidl::android::hardware::security::keymint::KeyFormat in_keyFormat;
      std::vector<uint8_t> in_keyData;
      std::optional<::aidl::android::hardware::security::keymint::AttestationKey> in_attestationKey;
      ::aidl::android::hardware::security::keymint::KeyCreationResult _aidl_return;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_keyParams);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, reinterpret_cast<int32_t*>(&in_keyFormat));
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_keyData);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readNullableParcelable(_aidl_in, &in_attestationKey);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->importKey(in_keyParams, in_keyFormat, in_keyData, in_attestationKey, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeParcelable(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 4 /*importWrappedKey*/): {
      std::vector<uint8_t> in_wrappedKeyData;
      std::vector<uint8_t> in_wrappingKeyBlob;
      std::vector<uint8_t> in_maskingKey;
      std::vector<::aidl::android::hardware::security::keymint::KeyParameter> in_unwrappingParams;
      int64_t in_passwordSid;
      int64_t in_biometricSid;
      ::aidl::android::hardware::security::keymint::KeyCreationResult _aidl_return;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_wrappedKeyData);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_wrappingKeyBlob);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_maskingKey);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_unwrappingParams);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_passwordSid);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_biometricSid);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->importWrappedKey(in_wrappedKeyData, in_wrappingKeyBlob, in_maskingKey, in_unwrappingParams, in_passwordSid, in_biometricSid, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeParcelable(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 5 /*upgradeKey*/): {
      std::vector<uint8_t> in_keyBlobToUpgrade;
      std::vector<::aidl::android::hardware::security::keymint::KeyParameter> in_upgradeParams;
      std::vector<uint8_t> _aidl_return;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_keyBlobToUpgrade);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_upgradeParams);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->upgradeKey(in_keyBlobToUpgrade, in_upgradeParams, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 6 /*deleteKey*/): {
      std::vector<uint8_t> in_keyBlob;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_keyBlob);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->deleteKey(in_keyBlob);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 7 /*deleteAllKeys*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->deleteAllKeys();
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 8 /*destroyAttestationIds*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->destroyAttestationIds();
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 9 /*begin*/): {
      ::aidl::android::hardware::security::keymint::KeyPurpose in_purpose;
      std::vector<uint8_t> in_keyBlob;
      std::vector<::aidl::android::hardware::security::keymint::KeyParameter> in_params;
      std::optional<::aidl::android::hardware::security::keymint::HardwareAuthToken> in_authToken;
      ::aidl::android::hardware::security::keymint::BeginResult _aidl_return;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, reinterpret_cast<int32_t*>(&in_purpose));
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_keyBlob);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_params);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readNullableParcelable(_aidl_in, &in_authToken);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->begin(in_purpose, in_keyBlob, in_params, in_authToken, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeParcelable(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 10 /*deviceLocked*/): {
      bool in_passwordOnly;
      std::optional<::aidl::android::hardware::security::secureclock::TimeStampToken> in_timestampToken;

      _aidl_ret_status = AParcel_readBool(_aidl_in, &in_passwordOnly);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readNullableParcelable(_aidl_in, &in_timestampToken);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->deviceLocked(in_passwordOnly, in_timestampToken);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 11 /*earlyBootEnded*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->earlyBootEnded();
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 12 /*convertStorageKeyToEphemeral*/): {
      std::vector<uint8_t> in_storageKeyBlob;
      std::vector<uint8_t> _aidl_return;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_storageKeyBlob);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->convertStorageKeyToEphemeral(in_storageKeyBlob, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 13 /*getKeyCharacteristics*/): {
      std::vector<uint8_t> in_keyBlob;
      std::vector<uint8_t> in_appId;
      std::vector<uint8_t> in_appData;
      std::vector<::aidl::android::hardware::security::keymint::KeyCharacteristics> _aidl_return;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_keyBlob);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_appId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_appData);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getKeyCharacteristics(in_keyBlob, in_appId, in_appData, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 16777214 /*getInterfaceVersion*/): {
      int32_t _aidl_return;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getInterfaceVersion(&_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = AParcel_writeInt32(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 16777213 /*getInterfaceHash*/): {
      std::string _aidl_return;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getInterfaceHash(&_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IKeyMintDevice::descriptor, _aidl_onTransact);

BpKeyMintDevice::BpKeyMintDevice(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpKeyMintDevice::~BpKeyMintDevice() {}

::ndk::ScopedAStatus BpKeyMintDevice::getHardwareInfo(::aidl::android::hardware::security::keymint::KeyMintHardwareInfo* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  AParcel_markSensitive(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*getHardwareInfo*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_CLEAR_BUF
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl()) {
    _aidl_status = IKeyMintDevice::getDefaultImpl()->getHardwareInfo(_aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readParcelable(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpKeyMintDevice::addRngEntropy(const std::vector<uint8_t>& in_data) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  AParcel_markSensitive(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_data);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*addRngEntropy*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_CLEAR_BUF
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl()) {
    _aidl_status = IKeyMintDevice::getDefaultImpl()->addRngEntropy(in_data);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpKeyMintDevice::generateKey(const std::vector<::aidl::android::hardware::security::keymint::KeyParameter>& in_keyParams, const std::optional<::aidl::android::hardware::security::keymint::AttestationKey>& in_attestationKey, ::aidl::android::hardware::security::keymint::KeyCreationResult* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  AParcel_markSensitive(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_keyParams);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeNullableParcelable(_aidl_in.get(), in_attestationKey);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 2 /*generateKey*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_CLEAR_BUF
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl()) {
    _aidl_status = IKeyMintDevice::getDefaultImpl()->generateKey(in_keyParams, in_attestationKey, _aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readParcelable(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpKeyMintDevice::importKey(const std::vector<::aidl::android::hardware::security::keymint::KeyParameter>& in_keyParams, ::aidl::android::hardware::security::keymint::KeyFormat in_keyFormat, const std::vector<uint8_t>& in_keyData, const std::optional<::aidl::android::hardware::security::keymint::AttestationKey>& in_attestationKey, ::aidl::android::hardware::security::keymint::KeyCreationResult* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  AParcel_markSensitive(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_keyParams);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), static_cast<int32_t>(in_keyFormat));
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_keyData);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeNullableParcelable(_aidl_in.get(), in_attestationKey);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 3 /*importKey*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_CLEAR_BUF
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl()) {
    _aidl_status = IKeyMintDevice::getDefaultImpl()->importKey(in_keyParams, in_keyFormat, in_keyData, in_attestationKey, _aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readParcelable(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpKeyMintDevice::importWrappedKey(const std::vector<uint8_t>& in_wrappedKeyData, const std::vector<uint8_t>& in_wrappingKeyBlob, const std::vector<uint8_t>& in_maskingKey, const std::vector<::aidl::android::hardware::security::keymint::KeyParameter>& in_unwrappingParams, int64_t in_passwordSid, int64_t in_biometricSid, ::aidl::android::hardware::security::keymint::KeyCreationResult* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  AParcel_markSensitive(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_wrappedKeyData);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_wrappingKeyBlob);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_maskingKey);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_unwrappingParams);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_passwordSid);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_biometricSid);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 4 /*importWrappedKey*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_CLEAR_BUF
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl()) {
    _aidl_status = IKeyMintDevice::getDefaultImpl()->importWrappedKey(in_wrappedKeyData, in_wrappingKeyBlob, in_maskingKey, in_unwrappingParams, in_passwordSid, in_biometricSid, _aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readParcelable(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpKeyMintDevice::upgradeKey(const std::vector<uint8_t>& in_keyBlobToUpgrade, const std::vector<::aidl::android::hardware::security::keymint::KeyParameter>& in_upgradeParams, std::vector<uint8_t>* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  AParcel_markSensitive(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_keyBlobToUpgrade);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_upgradeParams);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 5 /*upgradeKey*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_CLEAR_BUF
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl()) {
    _aidl_status = IKeyMintDevice::getDefaultImpl()->upgradeKey(in_keyBlobToUpgrade, in_upgradeParams, _aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpKeyMintDevice::deleteKey(const std::vector<uint8_t>& in_keyBlob) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  AParcel_markSensitive(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_keyBlob);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 6 /*deleteKey*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_CLEAR_BUF
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl()) {
    _aidl_status = IKeyMintDevice::getDefaultImpl()->deleteKey(in_keyBlob);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpKeyMintDevice::deleteAllKeys() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  AParcel_markSensitive(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 7 /*deleteAllKeys*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_CLEAR_BUF
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl()) {
    _aidl_status = IKeyMintDevice::getDefaultImpl()->deleteAllKeys();
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpKeyMintDevice::destroyAttestationIds() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  AParcel_markSensitive(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 8 /*destroyAttestationIds*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_CLEAR_BUF
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl()) {
    _aidl_status = IKeyMintDevice::getDefaultImpl()->destroyAttestationIds();
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpKeyMintDevice::begin(::aidl::android::hardware::security::keymint::KeyPurpose in_purpose, const std::vector<uint8_t>& in_keyBlob, const std::vector<::aidl::android::hardware::security::keymint::KeyParameter>& in_params, const std::optional<::aidl::android::hardware::security::keymint::HardwareAuthToken>& in_authToken, ::aidl::android::hardware::security::keymint::BeginResult* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  AParcel_markSensitive(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), static_cast<int32_t>(in_purpose));
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_keyBlob);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_params);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeNullableParcelable(_aidl_in.get(), in_authToken);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 9 /*begin*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_CLEAR_BUF
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl()) {
    _aidl_status = IKeyMintDevice::getDefaultImpl()->begin(in_purpose, in_keyBlob, in_params, in_authToken, _aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readParcelable(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpKeyMintDevice::deviceLocked(bool in_passwordOnly, const std::optional<::aidl::android::hardware::security::secureclock::TimeStampToken>& in_timestampToken) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  AParcel_markSensitive(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeBool(_aidl_in.get(), in_passwordOnly);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeNullableParcelable(_aidl_in.get(), in_timestampToken);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 10 /*deviceLocked*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_CLEAR_BUF
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl()) {
    _aidl_status = IKeyMintDevice::getDefaultImpl()->deviceLocked(in_passwordOnly, in_timestampToken);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpKeyMintDevice::earlyBootEnded() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  AParcel_markSensitive(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 11 /*earlyBootEnded*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_CLEAR_BUF
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl()) {
    _aidl_status = IKeyMintDevice::getDefaultImpl()->earlyBootEnded();
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpKeyMintDevice::convertStorageKeyToEphemeral(const std::vector<uint8_t>& in_storageKeyBlob, std::vector<uint8_t>* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  AParcel_markSensitive(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_storageKeyBlob);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 12 /*convertStorageKeyToEphemeral*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_CLEAR_BUF
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl()) {
    _aidl_status = IKeyMintDevice::getDefaultImpl()->convertStorageKeyToEphemeral(in_storageKeyBlob, _aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpKeyMintDevice::getKeyCharacteristics(const std::vector<uint8_t>& in_keyBlob, const std::vector<uint8_t>& in_appId, const std::vector<uint8_t>& in_appData, std::vector<::aidl::android::hardware::security::keymint::KeyCharacteristics>* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  AParcel_markSensitive(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_keyBlob);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_appId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_appData);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 13 /*getKeyCharacteristics*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_CLEAR_BUF
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl()) {
    _aidl_status = IKeyMintDevice::getDefaultImpl()->getKeyCharacteristics(in_keyBlob, in_appId, in_appData, _aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpKeyMintDevice::getInterfaceVersion(int32_t* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  if (_aidl_cached_version != -1) {
    *_aidl_return = _aidl_cached_version;
    _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
    return _aidl_status;
  }
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  AParcel_markSensitive(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 16777214 /*getInterfaceVersion*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_CLEAR_BUF
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl()) {
    _aidl_status = IKeyMintDevice::getDefaultImpl()->getInterfaceVersion(_aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = AParcel_readInt32(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_cached_version = *_aidl_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpKeyMintDevice::getInterfaceHash(std::string* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  const std::lock_guard<std::mutex> lock(_aidl_cached_hash_mutex);
  if (_aidl_cached_hash != "-1") {
    *_aidl_return = _aidl_cached_hash;
    _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
    return _aidl_status;
  }
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  AParcel_markSensitive(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 16777213 /*getInterfaceHash*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_CLEAR_BUF
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeyMintDevice::getDefaultImpl()) {
    _aidl_status = IKeyMintDevice::getDefaultImpl()->getInterfaceHash(_aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readString(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_cached_hash = *_aidl_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
// Source for BnKeyMintDevice
BnKeyMintDevice::BnKeyMintDevice() {}
BnKeyMintDevice::~BnKeyMintDevice() {}
::ndk::SpAIBinder BnKeyMintDevice::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markVintfStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
::ndk::ScopedAStatus BnKeyMintDevice::getInterfaceVersion(int32_t* _aidl_return) {
  *_aidl_return = IKeyMintDevice::version;
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
::ndk::ScopedAStatus BnKeyMintDevice::getInterfaceHash(std::string* _aidl_return) {
  *_aidl_return = IKeyMintDevice::hash;
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
// Source for IKeyMintDevice
const char* IKeyMintDevice::descriptor = "android.hardware.security.keymint.IKeyMintDevice";
IKeyMintDevice::IKeyMintDevice() {}
IKeyMintDevice::~IKeyMintDevice() {}


std::shared_ptr<IKeyMintDevice> IKeyMintDevice::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IKeyMintDevice>(interface);
  }
  return ::ndk::SharedRefBase::make<BpKeyMintDevice>(binder);
}

binder_status_t IKeyMintDevice::writeToParcel(AParcel* parcel, const std::shared_ptr<IKeyMintDevice>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IKeyMintDevice::readFromParcel(const AParcel* parcel, std::shared_ptr<IKeyMintDevice>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IKeyMintDevice::fromBinder(binder);
  return STATUS_OK;
}
bool IKeyMintDevice::setDefaultImpl(const std::shared_ptr<IKeyMintDevice>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IKeyMintDevice::default_impl);
  if (impl) {
    IKeyMintDevice::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IKeyMintDevice>& IKeyMintDevice::getDefaultImpl() {
  return IKeyMintDevice::default_impl;
}
std::shared_ptr<IKeyMintDevice> IKeyMintDevice::default_impl = nullptr;
::ndk::ScopedAStatus IKeyMintDeviceDefault::getHardwareInfo(::aidl::android::hardware::security::keymint::KeyMintHardwareInfo* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IKeyMintDeviceDefault::addRngEntropy(const std::vector<uint8_t>& /*in_data*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IKeyMintDeviceDefault::generateKey(const std::vector<::aidl::android::hardware::security::keymint::KeyParameter>& /*in_keyParams*/, const std::optional<::aidl::android::hardware::security::keymint::AttestationKey>& /*in_attestationKey*/, ::aidl::android::hardware::security::keymint::KeyCreationResult* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IKeyMintDeviceDefault::importKey(const std::vector<::aidl::android::hardware::security::keymint::KeyParameter>& /*in_keyParams*/, ::aidl::android::hardware::security::keymint::KeyFormat /*in_keyFormat*/, const std::vector<uint8_t>& /*in_keyData*/, const std::optional<::aidl::android::hardware::security::keymint::AttestationKey>& /*in_attestationKey*/, ::aidl::android::hardware::security::keymint::KeyCreationResult* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IKeyMintDeviceDefault::importWrappedKey(const std::vector<uint8_t>& /*in_wrappedKeyData*/, const std::vector<uint8_t>& /*in_wrappingKeyBlob*/, const std::vector<uint8_t>& /*in_maskingKey*/, const std::vector<::aidl::android::hardware::security::keymint::KeyParameter>& /*in_unwrappingParams*/, int64_t /*in_passwordSid*/, int64_t /*in_biometricSid*/, ::aidl::android::hardware::security::keymint::KeyCreationResult* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IKeyMintDeviceDefault::upgradeKey(const std::vector<uint8_t>& /*in_keyBlobToUpgrade*/, const std::vector<::aidl::android::hardware::security::keymint::KeyParameter>& /*in_upgradeParams*/, std::vector<uint8_t>* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IKeyMintDeviceDefault::deleteKey(const std::vector<uint8_t>& /*in_keyBlob*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IKeyMintDeviceDefault::deleteAllKeys() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IKeyMintDeviceDefault::destroyAttestationIds() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IKeyMintDeviceDefault::begin(::aidl::android::hardware::security::keymint::KeyPurpose /*in_purpose*/, const std::vector<uint8_t>& /*in_keyBlob*/, const std::vector<::aidl::android::hardware::security::keymint::KeyParameter>& /*in_params*/, const std::optional<::aidl::android::hardware::security::keymint::HardwareAuthToken>& /*in_authToken*/, ::aidl::android::hardware::security::keymint::BeginResult* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IKeyMintDeviceDefault::deviceLocked(bool /*in_passwordOnly*/, const std::optional<::aidl::android::hardware::security::secureclock::TimeStampToken>& /*in_timestampToken*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IKeyMintDeviceDefault::earlyBootEnded() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IKeyMintDeviceDefault::convertStorageKeyToEphemeral(const std::vector<uint8_t>& /*in_storageKeyBlob*/, std::vector<uint8_t>* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IKeyMintDeviceDefault::getKeyCharacteristics(const std::vector<uint8_t>& /*in_keyBlob*/, const std::vector<uint8_t>& /*in_appId*/, const std::vector<uint8_t>& /*in_appData*/, std::vector<::aidl::android::hardware::security::keymint::KeyCharacteristics>* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IKeyMintDeviceDefault::getInterfaceVersion(int32_t* _aidl_return) {
  *_aidl_return = 0;
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
::ndk::ScopedAStatus IKeyMintDeviceDefault::getInterfaceHash(std::string* _aidl_return) {
  *_aidl_return = "";
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
::ndk::SpAIBinder IKeyMintDeviceDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IKeyMintDeviceDefault::isRemote() {
  return false;
}
}  // namespace keymint
}  // namespace security
}  // namespace hardware
}  // namespace android
}  // namespace aidl
