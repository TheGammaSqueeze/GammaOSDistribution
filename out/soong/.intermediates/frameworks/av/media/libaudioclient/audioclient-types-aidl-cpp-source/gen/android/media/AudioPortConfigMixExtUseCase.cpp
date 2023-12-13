#include <android/media/AudioPortConfigMixExtUseCase.h>

namespace android {

namespace media {

::android::status_t AudioPortConfigMixExtUseCase::readFromParcel(const ::android::Parcel* _aidl_parcel) {
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
  case stream: {
    ::android::media::AudioStreamType _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readInt32(reinterpret_cast<int32_t *>(&_aidl_value))) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::android::media::AudioStreamType>) {
      set<stream>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<stream>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case source: {
    ::android::media::AudioSourceType _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readInt32(reinterpret_cast<int32_t *>(&_aidl_value))) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::android::media::AudioSourceType>) {
      set<source>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<source>(std::move(_aidl_value));
    }
    return ::android::OK; }
  }
  return ::android::BAD_VALUE;
}

::android::status_t AudioPortConfigMixExtUseCase::writeToParcel(::android::Parcel* _aidl_parcel) const {
  ::android::status_t _aidl_ret_status = _aidl_parcel->writeInt32(getTag());
  if (_aidl_ret_status != ::android::OK) return _aidl_ret_status;
  switch (getTag()) {
  case unspecified: return _aidl_parcel->writeBool(get<unspecified>());
  case stream: return _aidl_parcel->writeInt32(static_cast<int32_t>(get<stream>()));
  case source: return _aidl_parcel->writeInt32(static_cast<int32_t>(get<source>()));
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

}  // namespace media

}  // namespace android
