#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioOffloadInfo.h>
#include <android/media/audio/common/AudioFormat.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class AudioConfig : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioConfig& rhs) const {
    return std::tie(sampleRate, channelMask, format, offloadInfo, frameCount) != std::tie(rhs.sampleRate, rhs.channelMask, rhs.format, rhs.offloadInfo, rhs.frameCount);
  }
  inline bool operator<(const AudioConfig& rhs) const {
    return std::tie(sampleRate, channelMask, format, offloadInfo, frameCount) < std::tie(rhs.sampleRate, rhs.channelMask, rhs.format, rhs.offloadInfo, rhs.frameCount);
  }
  inline bool operator<=(const AudioConfig& rhs) const {
    return std::tie(sampleRate, channelMask, format, offloadInfo, frameCount) <= std::tie(rhs.sampleRate, rhs.channelMask, rhs.format, rhs.offloadInfo, rhs.frameCount);
  }
  inline bool operator==(const AudioConfig& rhs) const {
    return std::tie(sampleRate, channelMask, format, offloadInfo, frameCount) == std::tie(rhs.sampleRate, rhs.channelMask, rhs.format, rhs.offloadInfo, rhs.frameCount);
  }
  inline bool operator>(const AudioConfig& rhs) const {
    return std::tie(sampleRate, channelMask, format, offloadInfo, frameCount) > std::tie(rhs.sampleRate, rhs.channelMask, rhs.format, rhs.offloadInfo, rhs.frameCount);
  }
  inline bool operator>=(const AudioConfig& rhs) const {
    return std::tie(sampleRate, channelMask, format, offloadInfo, frameCount) >= std::tie(rhs.sampleRate, rhs.channelMask, rhs.format, rhs.offloadInfo, rhs.frameCount);
  }

  int32_t sampleRate = int32_t(0);
  int32_t channelMask = int32_t(0);
  ::android::media::audio::common::AudioFormat format = ::android::media::audio::common::AudioFormat(0);
  ::android::media::AudioOffloadInfo offloadInfo;
  int64_t frameCount = int64_t(0L);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioConfig");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioConfig{";
    os << "sampleRate: " << ::android::internal::ToString(sampleRate);
    os << ", channelMask: " << ::android::internal::ToString(channelMask);
    os << ", format: " << ::android::internal::ToString(format);
    os << ", offloadInfo: " << ::android::internal::ToString(offloadInfo);
    os << ", frameCount: " << ::android::internal::ToString(frameCount);
    os << "}";
    return os.str();
  }
};  // class AudioConfig

}  // namespace media

}  // namespace android
