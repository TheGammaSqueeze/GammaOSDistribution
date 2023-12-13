#pragma once

#include <android/binder_to_string.h>
#include <android/media/audio/common/AudioFormat.h>
#include <android/media/audio/common/AudioStreamType.h>
#include <android/media/audio/common/AudioUsage.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

namespace audio {

namespace common {

class AudioOffloadInfo : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioOffloadInfo& rhs) const {
    return std::tie(sampleRateHz, channelMask, format, streamType, bitRatePerSecond, durationMicroseconds, hasVideo, isStreaming, bitWidth, bufferSize, usage) != std::tie(rhs.sampleRateHz, rhs.channelMask, rhs.format, rhs.streamType, rhs.bitRatePerSecond, rhs.durationMicroseconds, rhs.hasVideo, rhs.isStreaming, rhs.bitWidth, rhs.bufferSize, rhs.usage);
  }
  inline bool operator<(const AudioOffloadInfo& rhs) const {
    return std::tie(sampleRateHz, channelMask, format, streamType, bitRatePerSecond, durationMicroseconds, hasVideo, isStreaming, bitWidth, bufferSize, usage) < std::tie(rhs.sampleRateHz, rhs.channelMask, rhs.format, rhs.streamType, rhs.bitRatePerSecond, rhs.durationMicroseconds, rhs.hasVideo, rhs.isStreaming, rhs.bitWidth, rhs.bufferSize, rhs.usage);
  }
  inline bool operator<=(const AudioOffloadInfo& rhs) const {
    return std::tie(sampleRateHz, channelMask, format, streamType, bitRatePerSecond, durationMicroseconds, hasVideo, isStreaming, bitWidth, bufferSize, usage) <= std::tie(rhs.sampleRateHz, rhs.channelMask, rhs.format, rhs.streamType, rhs.bitRatePerSecond, rhs.durationMicroseconds, rhs.hasVideo, rhs.isStreaming, rhs.bitWidth, rhs.bufferSize, rhs.usage);
  }
  inline bool operator==(const AudioOffloadInfo& rhs) const {
    return std::tie(sampleRateHz, channelMask, format, streamType, bitRatePerSecond, durationMicroseconds, hasVideo, isStreaming, bitWidth, bufferSize, usage) == std::tie(rhs.sampleRateHz, rhs.channelMask, rhs.format, rhs.streamType, rhs.bitRatePerSecond, rhs.durationMicroseconds, rhs.hasVideo, rhs.isStreaming, rhs.bitWidth, rhs.bufferSize, rhs.usage);
  }
  inline bool operator>(const AudioOffloadInfo& rhs) const {
    return std::tie(sampleRateHz, channelMask, format, streamType, bitRatePerSecond, durationMicroseconds, hasVideo, isStreaming, bitWidth, bufferSize, usage) > std::tie(rhs.sampleRateHz, rhs.channelMask, rhs.format, rhs.streamType, rhs.bitRatePerSecond, rhs.durationMicroseconds, rhs.hasVideo, rhs.isStreaming, rhs.bitWidth, rhs.bufferSize, rhs.usage);
  }
  inline bool operator>=(const AudioOffloadInfo& rhs) const {
    return std::tie(sampleRateHz, channelMask, format, streamType, bitRatePerSecond, durationMicroseconds, hasVideo, isStreaming, bitWidth, bufferSize, usage) >= std::tie(rhs.sampleRateHz, rhs.channelMask, rhs.format, rhs.streamType, rhs.bitRatePerSecond, rhs.durationMicroseconds, rhs.hasVideo, rhs.isStreaming, rhs.bitWidth, rhs.bufferSize, rhs.usage);
  }

  int32_t sampleRateHz = int32_t(0);
  int32_t channelMask = int32_t(0);
  ::android::media::audio::common::AudioFormat format = ::android::media::audio::common::AudioFormat(0);
  ::android::media::audio::common::AudioStreamType streamType = ::android::media::audio::common::AudioStreamType(0);
  int32_t bitRatePerSecond = int32_t(0);
  int64_t durationMicroseconds = int64_t(0L);
  bool hasVideo = bool(false);
  bool isStreaming = bool(false);
  int32_t bitWidth = int32_t(0);
  int32_t bufferSize = int32_t(0);
  ::android::media::audio::common::AudioUsage usage = ::android::media::audio::common::AudioUsage(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.audio.common.AudioOffloadInfo");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioOffloadInfo{";
    os << "sampleRateHz: " << ::android::internal::ToString(sampleRateHz);
    os << ", channelMask: " << ::android::internal::ToString(channelMask);
    os << ", format: " << ::android::internal::ToString(format);
    os << ", streamType: " << ::android::internal::ToString(streamType);
    os << ", bitRatePerSecond: " << ::android::internal::ToString(bitRatePerSecond);
    os << ", durationMicroseconds: " << ::android::internal::ToString(durationMicroseconds);
    os << ", hasVideo: " << ::android::internal::ToString(hasVideo);
    os << ", isStreaming: " << ::android::internal::ToString(isStreaming);
    os << ", bitWidth: " << ::android::internal::ToString(bitWidth);
    os << ", bufferSize: " << ::android::internal::ToString(bufferSize);
    os << ", usage: " << ::android::internal::ToString(usage);
    os << "}";
    return os.str();
  }
};  // class AudioOffloadInfo

}  // namespace common

}  // namespace audio

}  // namespace media

}  // namespace android
