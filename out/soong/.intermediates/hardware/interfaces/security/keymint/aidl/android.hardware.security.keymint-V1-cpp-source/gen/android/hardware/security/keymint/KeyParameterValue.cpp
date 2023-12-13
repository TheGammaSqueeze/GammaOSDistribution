#include <android/hardware/security/keymint/KeyParameterValue.h>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

::android::status_t KeyParameterValue::readFromParcel(const ::android::Parcel* _aidl_parcel) {
  ::android::status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = _aidl_parcel->readInt32(&_aidl_tag)) != ::android::OK) return _aidl_ret_status;
  switch (_aidl_tag) {
  case invalid: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readInt32(&_aidl_value)) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<invalid>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<invalid>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case algorithm: {
    ::android::hardware::security::keymint::Algorithm _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readInt32(reinterpret_cast<int32_t *>(&_aidl_value))) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::android::hardware::security::keymint::Algorithm>) {
      set<algorithm>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<algorithm>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case blockMode: {
    ::android::hardware::security::keymint::BlockMode _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readInt32(reinterpret_cast<int32_t *>(&_aidl_value))) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::android::hardware::security::keymint::BlockMode>) {
      set<blockMode>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<blockMode>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case paddingMode: {
    ::android::hardware::security::keymint::PaddingMode _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readInt32(reinterpret_cast<int32_t *>(&_aidl_value))) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::android::hardware::security::keymint::PaddingMode>) {
      set<paddingMode>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<paddingMode>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case digest: {
    ::android::hardware::security::keymint::Digest _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readInt32(reinterpret_cast<int32_t *>(&_aidl_value))) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::android::hardware::security::keymint::Digest>) {
      set<digest>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<digest>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case ecCurve: {
    ::android::hardware::security::keymint::EcCurve _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readInt32(reinterpret_cast<int32_t *>(&_aidl_value))) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::android::hardware::security::keymint::EcCurve>) {
      set<ecCurve>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<ecCurve>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case origin: {
    ::android::hardware::security::keymint::KeyOrigin _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readInt32(reinterpret_cast<int32_t *>(&_aidl_value))) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::android::hardware::security::keymint::KeyOrigin>) {
      set<origin>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<origin>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case keyPurpose: {
    ::android::hardware::security::keymint::KeyPurpose _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readInt32(reinterpret_cast<int32_t *>(&_aidl_value))) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::android::hardware::security::keymint::KeyPurpose>) {
      set<keyPurpose>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<keyPurpose>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case hardwareAuthenticatorType: {
    ::android::hardware::security::keymint::HardwareAuthenticatorType _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readInt32(reinterpret_cast<int32_t *>(&_aidl_value))) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::android::hardware::security::keymint::HardwareAuthenticatorType>) {
      set<hardwareAuthenticatorType>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<hardwareAuthenticatorType>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case securityLevel: {
    ::android::hardware::security::keymint::SecurityLevel _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readInt32(reinterpret_cast<int32_t *>(&_aidl_value))) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::android::hardware::security::keymint::SecurityLevel>) {
      set<securityLevel>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<securityLevel>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case boolValue: {
    bool _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readBool(&_aidl_value)) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<bool>) {
      set<boolValue>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<boolValue>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case integer: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readInt32(&_aidl_value)) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<integer>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<integer>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case longInteger: {
    int64_t _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readInt64(&_aidl_value)) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int64_t>) {
      set<longInteger>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<longInteger>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case dateTime: {
    int64_t _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readInt64(&_aidl_value)) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int64_t>) {
      set<dateTime>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<dateTime>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case blob: {
    ::std::vector<uint8_t> _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readByteVector(&_aidl_value)) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::std::vector<uint8_t>>) {
      set<blob>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<blob>(std::move(_aidl_value));
    }
    return ::android::OK; }
  }
  return ::android::BAD_VALUE;
}

::android::status_t KeyParameterValue::writeToParcel(::android::Parcel* _aidl_parcel) const {
  ::android::status_t _aidl_ret_status = _aidl_parcel->writeInt32(getTag());
  if (_aidl_ret_status != ::android::OK) return _aidl_ret_status;
  switch (getTag()) {
  case invalid: return _aidl_parcel->writeInt32(get<invalid>());
  case algorithm: return _aidl_parcel->writeInt32(static_cast<int32_t>(get<algorithm>()));
  case blockMode: return _aidl_parcel->writeInt32(static_cast<int32_t>(get<blockMode>()));
  case paddingMode: return _aidl_parcel->writeInt32(static_cast<int32_t>(get<paddingMode>()));
  case digest: return _aidl_parcel->writeInt32(static_cast<int32_t>(get<digest>()));
  case ecCurve: return _aidl_parcel->writeInt32(static_cast<int32_t>(get<ecCurve>()));
  case origin: return _aidl_parcel->writeInt32(static_cast<int32_t>(get<origin>()));
  case keyPurpose: return _aidl_parcel->writeInt32(static_cast<int32_t>(get<keyPurpose>()));
  case hardwareAuthenticatorType: return _aidl_parcel->writeInt32(static_cast<int32_t>(get<hardwareAuthenticatorType>()));
  case securityLevel: return _aidl_parcel->writeInt32(static_cast<int32_t>(get<securityLevel>()));
  case boolValue: return _aidl_parcel->writeBool(get<boolValue>());
  case integer: return _aidl_parcel->writeInt32(get<integer>());
  case longInteger: return _aidl_parcel->writeInt64(get<longInteger>());
  case dateTime: return _aidl_parcel->writeInt64(get<dateTime>());
  case blob: return _aidl_parcel->writeByteVector(get<blob>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
