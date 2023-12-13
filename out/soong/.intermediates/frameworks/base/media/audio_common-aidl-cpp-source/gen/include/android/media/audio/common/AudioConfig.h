#pragma once

#include <android/binder_to_string.h>
#include <android/media/audio/common/AudioFormat.h>
#include <android/media/audio/common/AudioOffloadInfo.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

namespace audio {

namespace common {

class AudioConfig : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioConfig& rhs) const {
    return std::tie(sampleRateHz, channelMask, format, offloadInfo, frameCount) != std::tie(rhs.sampleRateHz, rhs.channelMask, rhs.format, rhs.offloadInfo, rhs.frameCount);
  }
  inline bool operator<(const AudioConfig& rhs) const {
    return std::tie(sampleRateHz, channelMask, format, offloadInfo, frameCount) < std::tie(rhs.sampleRateHz, rhs.channelMask, rhs.format, rhs.offloadInfo, rhs.frameCount);
  }
  inline bool operator<=(const AudioConfig& rhs) const {
    return std::tie(sampleRateHz, channelMask, format, offloadInfo, frameCount) <= std::tie(rhs.sampleRateHz, rhs.channelMask, rhs.format, rhs.offloadInfo, rhs.frameCount);
  }
  inline bool operator==(const AudioConfig& rhs) const {
    return std::tie(sampleRateHz, channelMask, format, offloadInfo, frameCount) == std::tie(rhs.sampleRateHz, rhs.channelMask, rhs.format, rhs.offloadInfo, rhs.frameCount);
  }
  inline bool operator>(const AudioConfig& rhs) const {
    return std::tie(sampleRateHz, channelMask, format, offloadInfo, frameCount) > std::tie(rhs.sampleRateHz, rhs.channelMask, rhs.format, rhs.offloadInfo, rhs.frameCount);
  }
  inline bool operator>=(const AudioConfig& rhs) const {
    return std::tie(sampleRateHz, channelMask, format, offloadInfo, frameCount) >= std::tie(rhs.sampleRateHz, rhs.channelMask, rhs.format, rhs.offloadInfo, rhs.frameCount);
  }

  int32_t sampleRateHz = int32_t(0);
  int32_t channelMask = int32_t(0);
  ::android::media::audio::common::AudioFormat format = ::android::media::audio::common::AudioFormat(0);
  ::android::media::audio::common::AudioOffloadInfo offloadInfo;
  int64_t frameCount = int64_t(0L);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.audio.common.AudioConfig");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioConfig{";
    os << "sampleRateHz: " << ::android::internal::ToString(sampleRateHz);
    os << ", channelMask: " << ::android::internal::ToString(channelMask);
    os << ", format: " << ::android::internal::ToString(format);
    os << ", offloadInfo: " << ::android::internal::ToString(offloadInfo);
    os << ", frameCount: " << ::android::internal::ToString(frameCount);
    os << "}";
    return os.str();
  }
};  // class AudioConfig

}  // namespace common

}  // namespace audio

}  // namespace media

}  // namespace android
