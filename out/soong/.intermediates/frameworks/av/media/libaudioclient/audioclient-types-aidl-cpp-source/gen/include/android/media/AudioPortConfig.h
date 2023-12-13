#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioGainConfig.h>
#include <android/media/AudioIoFlags.h>
#include <android/media/AudioPortConfigExt.h>
#include <android/media/AudioPortRole.h>
#include <android/media/AudioPortType.h>
#include <android/media/audio/common/AudioFormat.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class AudioPortConfig : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioPortConfig& rhs) const {
    return std::tie(id, role, type, configMask, sampleRate, channelMask, format, gain, flags, ext) != std::tie(rhs.id, rhs.role, rhs.type, rhs.configMask, rhs.sampleRate, rhs.channelMask, rhs.format, rhs.gain, rhs.flags, rhs.ext);
  }
  inline bool operator<(const AudioPortConfig& rhs) const {
    return std::tie(id, role, type, configMask, sampleRate, channelMask, format, gain, flags, ext) < std::tie(rhs.id, rhs.role, rhs.type, rhs.configMask, rhs.sampleRate, rhs.channelMask, rhs.format, rhs.gain, rhs.flags, rhs.ext);
  }
  inline bool operator<=(const AudioPortConfig& rhs) const {
    return std::tie(id, role, type, configMask, sampleRate, channelMask, format, gain, flags, ext) <= std::tie(rhs.id, rhs.role, rhs.type, rhs.configMask, rhs.sampleRate, rhs.channelMask, rhs.format, rhs.gain, rhs.flags, rhs.ext);
  }
  inline bool operator==(const AudioPortConfig& rhs) const {
    return std::tie(id, role, type, configMask, sampleRate, channelMask, format, gain, flags, ext) == std::tie(rhs.id, rhs.role, rhs.type, rhs.configMask, rhs.sampleRate, rhs.channelMask, rhs.format, rhs.gain, rhs.flags, rhs.ext);
  }
  inline bool operator>(const AudioPortConfig& rhs) const {
    return std::tie(id, role, type, configMask, sampleRate, channelMask, format, gain, flags, ext) > std::tie(rhs.id, rhs.role, rhs.type, rhs.configMask, rhs.sampleRate, rhs.channelMask, rhs.format, rhs.gain, rhs.flags, rhs.ext);
  }
  inline bool operator>=(const AudioPortConfig& rhs) const {
    return std::tie(id, role, type, configMask, sampleRate, channelMask, format, gain, flags, ext) >= std::tie(rhs.id, rhs.role, rhs.type, rhs.configMask, rhs.sampleRate, rhs.channelMask, rhs.format, rhs.gain, rhs.flags, rhs.ext);
  }

  int32_t id = int32_t(0);
  ::android::media::AudioPortRole role = ::android::media::AudioPortRole(0);
  ::android::media::AudioPortType type = ::android::media::AudioPortType(0);
  int32_t configMask = int32_t(0);
  int32_t sampleRate = int32_t(0);
  int32_t channelMask = int32_t(0);
  ::android::media::audio::common::AudioFormat format = ::android::media::audio::common::AudioFormat(0);
  ::android::media::AudioGainConfig gain;
  ::android::media::AudioIoFlags flags;
  ::android::media::AudioPortConfigExt ext;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioPortConfig");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioPortConfig{";
    os << "id: " << ::android::internal::ToString(id);
    os << ", role: " << ::android::internal::ToString(role);
    os << ", type: " << ::android::internal::ToString(type);
    os << ", configMask: " << ::android::internal::ToString(configMask);
    os << ", sampleRate: " << ::android::internal::ToString(sampleRate);
    os << ", channelMask: " << ::android::internal::ToString(channelMask);
    os << ", format: " << ::android::internal::ToString(format);
    os << ", gain: " << ::android::internal::ToString(gain);
    os << ", flags: " << ::android::internal::ToString(flags);
    os << ", ext: " << ::android::internal::ToString(ext);
    os << "}";
    return os.str();
  }
};  // class AudioPortConfig

}  // namespace media

}  // namespace android
