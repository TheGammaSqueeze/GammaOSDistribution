#include <android/hardware/gnss/GnssSignalType.h>

namespace android {

namespace hardware {

namespace gnss {

const ::std::string& GnssSignalType::CODE_TYPE_A() {
  static const ::std::string value("A");
  return value;
}

const ::std::string& GnssSignalType::CODE_TYPE_B() {
  static const ::std::string value("B");
  return value;
}

const ::std::string& GnssSignalType::CODE_TYPE_C() {
  static const ::std::string value("C");
  return value;
}

const ::std::string& GnssSignalType::CODE_TYPE_D() {
  static const ::std::string value("D");
  return value;
}

const ::std::string& GnssSignalType::CODE_TYPE_I() {
  static const ::std::string value("I");
  return value;
}

const ::std::string& GnssSignalType::CODE_TYPE_L() {
  static const ::std::string value("L");
  return value;
}

const ::std::string& GnssSignalType::CODE_TYPE_M() {
  static const ::std::string value("M");
  return value;
}

const ::std::string& GnssSignalType::CODE_TYPE_N() {
  static const ::std::string value("N");
  return value;
}

const ::std::string& GnssSignalType::CODE_TYPE_P() {
  static const ::std::string value("P");
  return value;
}

const ::std::string& GnssSignalType::CODE_TYPE_Q() {
  static const ::std::string value("Q");
  return value;
}

const ::std::string& GnssSignalType::CODE_TYPE_S() {
  static const ::std::string value("S");
  return value;
}

const ::std::string& GnssSignalType::CODE_TYPE_W() {
  static const ::std::string value("W");
  return value;
}

const ::std::string& GnssSignalType::CODE_TYPE_X() {
  static const ::std::string value("X");
  return value;
}

const ::std::string& GnssSignalType::CODE_TYPE_Y() {
  static const ::std::string value("Y");
  return value;
}

const ::std::string& GnssSignalType::CODE_TYPE_Z() {
  static const ::std::string value("Z");
  return value;
}

const ::std::string& GnssSignalType::CODE_TYPE_UNKNOWN() {
  static const ::std::string value("UNKNOWN");
  return value;
}

::android::status_t GnssSignalType::readFromParcel(const ::android::Parcel* _aidl_parcel) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  [[maybe_unused]] size_t _aidl_start_pos = _aidl_parcel->dataPosition();
  int32_t _aidl_parcelable_raw_size = _aidl_parcel->readInt32();
  if (_aidl_parcelable_raw_size < 0) return ::android::BAD_VALUE;
  [[maybe_unused]] size_t _aidl_parcelable_size = static_cast<size_t>(_aidl_parcelable_raw_size);
  if (_aidl_start_pos > SIZE_MAX - _aidl_parcelable_size) return ::android::BAD_VALUE;
  if (_aidl_parcel->dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) {
    _aidl_parcel->setDataPosition(_aidl_start_pos + _aidl_parcelable_size);
    return _aidl_ret_status;
  }
  _aidl_ret_status = _aidl_parcel->readInt32(reinterpret_cast<int32_t *>(&constellation));
  if (((_aidl_ret_status) != (::android::OK))) {
    return _aidl_ret_status;
  }
  if (_aidl_parcel->dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) {
    _aidl_parcel->setDataPosition(_aidl_start_pos + _aidl_parcelable_size);
    return _aidl_ret_status;
  }
  _aidl_ret_status = _aidl_parcel->readDouble(&carrierFrequencyHz);
  if (((_aidl_ret_status) != (::android::OK))) {
    return _aidl_ret_status;
  }
  if (_aidl_parcel->dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) {
    _aidl_parcel->setDataPosition(_aidl_start_pos + _aidl_parcelable_size);
    return _aidl_ret_status;
  }
  _aidl_ret_status = _aidl_parcel->readUtf8FromUtf16(&codeType);
  if (((_aidl_ret_status) != (::android::OK))) {
    return _aidl_ret_status;
  }
  _aidl_parcel->setDataPosition(_aidl_start_pos + _aidl_parcelable_size);
  return _aidl_ret_status;
}

::android::status_t GnssSignalType::writeToParcel(::android::Parcel* _aidl_parcel) const {
  ::android::status_t _aidl_ret_status = ::android::OK;
  auto _aidl_start_pos = _aidl_parcel->dataPosition();
  _aidl_parcel->writeInt32(0);
  _aidl_ret_status = _aidl_parcel->writeInt32(static_cast<int32_t>(constellation));
  if (((_aidl_ret_status) != (::android::OK))) {
    return _aidl_ret_status;
  }
  _aidl_ret_status = _aidl_parcel->writeDouble(carrierFrequencyHz);
  if (((_aidl_ret_status) != (::android::OK))) {
    return _aidl_ret_status;
  }
  _aidl_ret_status = _aidl_parcel->writeUtf8AsUtf16(codeType);
  if (((_aidl_ret_status) != (::android::OK))) {
    return _aidl_ret_status;
  }
  auto _aidl_end_pos = _aidl_parcel->dataPosition();
  _aidl_parcel->setDataPosition(_aidl_start_pos);
  _aidl_parcel->writeInt32(_aidl_end_pos - _aidl_start_pos);
  _aidl_parcel->setDataPosition(_aidl_end_pos);
  return _aidl_ret_status;
}

}  // namespace gnss

}  // namespace hardware

}  // namespace android
