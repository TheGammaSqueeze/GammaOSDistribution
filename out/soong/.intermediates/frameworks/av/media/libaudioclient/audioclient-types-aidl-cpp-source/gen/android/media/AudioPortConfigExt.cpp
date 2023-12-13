#include <android/media/AudioPortConfigExt.h>

namespace android {

namespace media {

::android::status_t AudioPortConfigExt::readFromParcel(const ::android::Parcel* _aidl_parcel) {
  ::android::status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = _aidl_parcel->readInt32(&_aidl_tag)) != ::android::OK) return _aidl_ret_status;
  switch (_aidl_tag) {
  case unspecified: {
    bool _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readBool(&_aidl_value)) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<bool>) {
      set<unspecified>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<unspecified>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case device: {
    ::android::media::AudioPortConfigDeviceExt _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readParcelable(&_aidl_value)) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::android::media::AudioPortConfigDeviceExt>) {
      set<device>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<device>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case mix: {
    ::android::media::AudioPortConfigMixExt _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readParcelable(&_aidl_value)) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::android::media::AudioPortConfigMixExt>) {
      set<mix>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<mix>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case session: {
    ::android::media::AudioPortConfigSessionExt _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readParcelable(&_aidl_value)) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::android::media::AudioPortConfigSessionExt>) {
      set<session>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<session>(std::move(_aidl_value));
    }
    return ::android::OK; }
  }
  return ::android::BAD_VALUE;
}

::android::status_t AudioPortConfigExt::writeToParcel(::android::Parcel* _aidl_parcel) const {
  ::android::status_t _aidl_ret_status = _aidl_parcel->writeInt32(getTag());
  if (_aidl_ret_status != ::android::OK) return _aidl_ret_status;
  switch (getTag()) {
  case unspecified: return _aidl_parcel->writeBool(get<unspecified>());
  case device: return _aidl_parcel->writeParcelable(get<device>());
  case mix: return _aidl_parcel->writeParcelable(get<mix>());
  case session: return _aidl_parcel->writeParcelable(get<session>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

}  // namespace media

}  // namespace android
