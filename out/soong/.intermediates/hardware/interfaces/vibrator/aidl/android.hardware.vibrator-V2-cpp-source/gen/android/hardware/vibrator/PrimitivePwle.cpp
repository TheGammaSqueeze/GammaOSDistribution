#include <android/hardware/vibrator/PrimitivePwle.h>

namespace android {

namespace hardware {

namespace vibrator {

::android::status_t PrimitivePwle::readFromParcel(const ::android::Parcel* _aidl_parcel) {
  ::android::status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = _aidl_parcel->readInt32(&_aidl_tag)) != ::android::OK) return _aidl_ret_status;
  switch (_aidl_tag) {
  case active: {
    ::android::hardware::vibrator::ActivePwle _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readParcelable(&_aidl_value)) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::android::hardware::vibrator::ActivePwle>) {
      set<active>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<active>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case braking: {
    ::android::hardware::vibrator::BrakingPwle _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readParcelable(&_aidl_value)) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::android::hardware::vibrator::BrakingPwle>) {
      set<braking>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<braking>(std::move(_aidl_value));
    }
    return ::android::OK; }
  }
  return ::android::BAD_VALUE;
}

::android::status_t PrimitivePwle::writeToParcel(::android::Parcel* _aidl_parcel) const {
  ::android::status_t _aidl_ret_status = _aidl_parcel->writeInt32(getTag());
  if (_aidl_ret_status != ::android::OK) return _aidl_ret_status;
  switch (getTag()) {
  case active: return _aidl_parcel->writeParcelable(get<active>());
  case braking: return _aidl_parcel->writeParcelable(get<braking>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

}  // namespace vibrator

}  // namespace hardware

}  // namespace android
