#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioEncapsulationType.h>
#include <android/media/audio/common/AudioFormat.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace media {

class AudioProfile : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioProfile& rhs) const {
    return std::tie(name, format, channelMasks, samplingRates, isDynamicFormat, isDynamicChannels, isDynamicRate, encapsulationType) != std::tie(rhs.name, rhs.format, rhs.channelMasks, rhs.samplingRates, rhs.isDynamicFormat, rhs.isDynamicChannels, rhs.isDynamicRate, rhs.encapsulationType);
  }
  inline bool operator<(const AudioProfile& rhs) const {
    return std::tie(name, format, channelMasks, samplingRates, isDynamicFormat, isDynamicChannels, isDynamicRate, encapsulationType) < std::tie(rhs.name, rhs.format, rhs.channelMasks, rhs.samplingRates, rhs.isDynamicFormat, rhs.isDynamicChannels, rhs.isDynamicRate, rhs.encapsulationType);
  }
  inline bool operator<=(const AudioProfile& rhs) const {
    return std::tie(name, format, channelMasks, samplingRates, isDynamicFormat, isDynamicChannels, isDynamicRate, encapsulationType) <= std::tie(rhs.name, rhs.format, rhs.channelMasks, rhs.samplingRates, rhs.isDynamicFormat, rhs.isDynamicChannels, rhs.isDynamicRate, rhs.encapsulationType);
  }
  inline bool operator==(const AudioProfile& rhs) const {
    return std::tie(name, format, channelMasks, samplingRates, isDynamicFormat, isDynamicChannels, isDynamicRate, encapsulationType) == std::tie(rhs.name, rhs.format, rhs.channelMasks, rhs.samplingRates, rhs.isDynamicFormat, rhs.isDynamicChannels, rhs.isDynamicRate, rhs.encapsulationType);
  }
  inline bool operator>(const AudioProfile& rhs) const {
    return std::tie(name, format, channelMasks, samplingRates, isDynamicFormat, isDynamicChannels, isDynamicRate, encapsulationType) > std::tie(rhs.name, rhs.format, rhs.channelMasks, rhs.samplingRates, rhs.isDynamicFormat, rhs.isDynamicChannels, rhs.isDynamicRate, rhs.encapsulationType);
  }
  inline bool operator>=(const AudioProfile& rhs) const {
    return std::tie(name, format, channelMasks, samplingRates, isDynamicFormat, isDynamicChannels, isDynamicRate, encapsulationType) >= std::tie(rhs.name, rhs.format, rhs.channelMasks, rhs.samplingRates, rhs.isDynamicFormat, rhs.isDynamicChannels, rhs.isDynamicRate, rhs.encapsulationType);
  }

  ::std::string name;
  ::android::media::audio::common::AudioFormat format = ::android::media::audio::common::AudioFormat(0);
  ::std::vector<int32_t> channelMasks;
  ::std::vector<int32_t> samplingRates;
  bool isDynamicFormat = bool(false);
  bool isDynamicChannels = bool(false);
  bool isDynamicRate = bool(false);
  ::android::media::AudioEncapsulationType encapsulationType = ::android::media::AudioEncapsulationType(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioProfile");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioProfile{";
    os << "name: " << ::android::internal::ToString(name);
    os << ", format: " << ::android::internal::ToString(format);
    os << ", channelMasks: " << ::android::internal::ToString(channelMasks);
    os << ", samplingRates: " << ::android::internal::ToString(samplingRates);
    os << ", isDynamicFormat: " << ::android::internal::ToString(isDynamicFormat);
    os << ", isDynamicChannels: " << ::android::internal::ToString(isDynamicChannels);
    os << ", isDynamicRate: " << ::android::internal::ToString(isDynamicRate);
    os << ", encapsulationType: " << ::android::internal::ToString(encapsulationType);
    os << "}";
    return os.str();
  }
};  // class AudioProfile

}  // namespace media

}  // namespace android
