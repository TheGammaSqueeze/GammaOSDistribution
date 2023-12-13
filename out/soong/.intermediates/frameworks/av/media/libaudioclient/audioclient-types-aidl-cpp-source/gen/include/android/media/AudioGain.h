#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class AudioGain : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioGain& rhs) const {
    return std::tie(index, useInChannelMask, useForVolume, mode, channelMask, minValue, maxValue, defaultValue, stepValue, minRampMs, maxRampMs) != std::tie(rhs.index, rhs.useInChannelMask, rhs.useForVolume, rhs.mode, rhs.channelMask, rhs.minValue, rhs.maxValue, rhs.defaultValue, rhs.stepValue, rhs.minRampMs, rhs.maxRampMs);
  }
  inline bool operator<(const AudioGain& rhs) const {
    return std::tie(index, useInChannelMask, useForVolume, mode, channelMask, minValue, maxValue, defaultValue, stepValue, minRampMs, maxRampMs) < std::tie(rhs.index, rhs.useInChannelMask, rhs.useForVolume, rhs.mode, rhs.channelMask, rhs.minValue, rhs.maxValue, rhs.defaultValue, rhs.stepValue, rhs.minRampMs, rhs.maxRampMs);
  }
  inline bool operator<=(const AudioGain& rhs) const {
    return std::tie(index, useInChannelMask, useForVolume, mode, channelMask, minValue, maxValue, defaultValue, stepValue, minRampMs, maxRampMs) <= std::tie(rhs.index, rhs.useInChannelMask, rhs.useForVolume, rhs.mode, rhs.channelMask, rhs.minValue, rhs.maxValue, rhs.defaultValue, rhs.stepValue, rhs.minRampMs, rhs.maxRampMs);
  }
  inline bool operator==(const AudioGain& rhs) const {
    return std::tie(index, useInChannelMask, useForVolume, mode, channelMask, minValue, maxValue, defaultValue, stepValue, minRampMs, maxRampMs) == std::tie(rhs.index, rhs.useInChannelMask, rhs.useForVolume, rhs.mode, rhs.channelMask, rhs.minValue, rhs.maxValue, rhs.defaultValue, rhs.stepValue, rhs.minRampMs, rhs.maxRampMs);
  }
  inline bool operator>(const AudioGain& rhs) const {
    return std::tie(index, useInChannelMask, useForVolume, mode, channelMask, minValue, maxValue, defaultValue, stepValue, minRampMs, maxRampMs) > std::tie(rhs.index, rhs.useInChannelMask, rhs.useForVolume, rhs.mode, rhs.channelMask, rhs.minValue, rhs.maxValue, rhs.defaultValue, rhs.stepValue, rhs.minRampMs, rhs.maxRampMs);
  }
  inline bool operator>=(const AudioGain& rhs) const {
    return std::tie(index, useInChannelMask, useForVolume, mode, channelMask, minValue, maxValue, defaultValue, stepValue, minRampMs, maxRampMs) >= std::tie(rhs.index, rhs.useInChannelMask, rhs.useForVolume, rhs.mode, rhs.channelMask, rhs.minValue, rhs.maxValue, rhs.defaultValue, rhs.stepValue, rhs.minRampMs, rhs.maxRampMs);
  }

  int32_t index = int32_t(0);
  bool useInChannelMask = bool(false);
  bool useForVolume = bool(false);
  int32_t mode = int32_t(0);
  int32_t channelMask = int32_t(0);
  int32_t minValue = int32_t(0);
  int32_t maxValue = int32_t(0);
  int32_t defaultValue = int32_t(0);
  int32_t stepValue = int32_t(0);
  int32_t minRampMs = int32_t(0);
  int32_t maxRampMs = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioGain");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioGain{";
    os << "index: " << ::android::internal::ToString(index);
    os << ", useInChannelMask: " << ::android::internal::ToString(useInChannelMask);
    os << ", useForVolume: " << ::android::internal::ToString(useForVolume);
    os << ", mode: " << ::android::internal::ToString(mode);
    os << ", channelMask: " << ::android::internal::ToString(channelMask);
    os << ", minValue: " << ::android::internal::ToString(minValue);
    os << ", maxValue: " << ::android::internal::ToString(maxValue);
    os << ", defaultValue: " << ::android::internal::ToString(defaultValue);
    os << ", stepValue: " << ::android::internal::ToString(stepValue);
    os << ", minRampMs: " << ::android::internal::ToString(minRampMs);
    os << ", maxRampMs: " << ::android::internal::ToString(maxRampMs);
    os << "}";
    return os.str();
  }
};  // class AudioGain

}  // namespace media

}  // namespace android
