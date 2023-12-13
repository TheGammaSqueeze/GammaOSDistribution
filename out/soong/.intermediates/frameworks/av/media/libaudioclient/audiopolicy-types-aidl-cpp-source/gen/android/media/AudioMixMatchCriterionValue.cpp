#include <android/media/AudioMixMatchCriterionValue.h>

namespace android {

namespace media {

::android::status_t AudioMixMatchCriterionValue::readFromParcel(const ::android::Parcel* _aidl_parcel) {
  ::android::status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = _aidl_parcel->readInt32(&_aidl_tag)) != ::android::OK) return _aidl_ret_status;
  switch (_aidl_tag) {
  case usage: {
    ::android::media::AudioUsage _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readInt32(reinterpret_cast<int32_t *>(&_aidl_value))) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::android::media::AudioUsage>) {
      set<usage>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<usage>(std::move(_aidl_value));
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
  case uid: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readInt32(&_aidl_value)) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<uid>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<uid>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case userId: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readInt32(&_aidl_value)) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<userId>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<userId>(std::move(_aidl_value));
    }
    return ::android::OK; }
  }
  return ::android::BAD_VALUE;
}

::android::status_t AudioMixMatchCriterionValue::writeToParcel(::android::Parcel* _aidl_parcel) const {
  ::android::status_t _aidl_ret_status = _aidl_parcel->writeInt32(getTag());
  if (_aidl_ret_status != ::android::OK) return _aidl_ret_status;
  switch (getTag()) {
  case usage: return _aidl_parcel->writeInt32(static_cast<int32_t>(get<usage>()));
  case source: return _aidl_parcel->writeInt32(static_cast<int32_t>(get<source>()));
  case uid: return _aidl_parcel->writeInt32(get<uid>());
  case userId: return _aidl_parcel->writeInt32(get<userId>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

}  // namespace media

}  // namespace android
