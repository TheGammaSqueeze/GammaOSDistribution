#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace media {

class AudioGainConfig : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioGainConfig& rhs) const {
    return std::tie(index, mode, channelMask, values, rampDurationMs) != std::tie(rhs.index, rhs.mode, rhs.channelMask, rhs.values, rhs.rampDurationMs);
  }
  inline bool operator<(const AudioGainConfig& rhs) const {
    return std::tie(index, mode, channelMask, values, rampDurationMs) < std::tie(rhs.index, rhs.mode, rhs.channelMask, rhs.values, rhs.rampDurationMs);
  }
  inline bool operator<=(const AudioGainConfig& rhs) const {
    return std::tie(index, mode, channelMask, values, rampDurationMs) <= std::tie(rhs.index, rhs.mode, rhs.channelMask, rhs.values, rhs.rampDurationMs);
  }
  inline bool operator==(const AudioGainConfig& rhs) const {
    return std::tie(index, mode, channelMask, values, rampDurationMs) == std::tie(rhs.index, rhs.mode, rhs.channelMask, rhs.values, rhs.rampDurationMs);
  }
  inline bool operator>(const AudioGainConfig& rhs) const {
    return std::tie(index, mode, channelMask, values, rampDurationMs) > std::tie(rhs.index, rhs.mode, rhs.channelMask, rhs.values, rhs.rampDurationMs);
  }
  inline bool operator>=(const AudioGainConfig& rhs) const {
    return std::tie(index, mode, channelMask, values, rampDurationMs) >= std::tie(rhs.index, rhs.mode, rhs.channelMask, rhs.values, rhs.rampDurationMs);
  }

  int32_t index = int32_t(0);
  int32_t mode = int32_t(0);
  int32_t channelMask = int32_t(0);
  ::std::vector<int32_t> values;
  int32_t rampDurationMs = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioGainConfig");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioGainConfig{";
    os << "index: " << ::android::internal::ToString(index);
    os << ", mode: " << ::android::internal::ToString(mode);
    os << ", channelMask: " << ::android::internal::ToString(channelMask);
    os << ", values: " << ::android::internal::ToString(values);
    os << ", rampDurationMs: " << ::android::internal::ToString(rampDurationMs);
    os << "}";
    return os.str();
  }
};  // class AudioGainConfig

}  // namespace media

}  // namespace android
