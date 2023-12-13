#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioConfigBase.h>
#include <android/media/AudioEncapsulationMode.h>
#include <android/media/AudioStreamType.h>
#include <android/media/AudioUsage.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class AudioOffloadInfo : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioOffloadInfo& rhs) const {
    return std::tie(version, config, streamType, bitRate, durationUs, hasVideo, isStreaming, bitWidth, offloadBufferSize, usage, encapsulationMode, contentId, syncId) != std::tie(rhs.version, rhs.config, rhs.streamType, rhs.bitRate, rhs.durationUs, rhs.hasVideo, rhs.isStreaming, rhs.bitWidth, rhs.offloadBufferSize, rhs.usage, rhs.encapsulationMode, rhs.contentId, rhs.syncId);
  }
  inline bool operator<(const AudioOffloadInfo& rhs) const {
    return std::tie(version, config, streamType, bitRate, durationUs, hasVideo, isStreaming, bitWidth, offloadBufferSize, usage, encapsulationMode, contentId, syncId) < std::tie(rhs.version, rhs.config, rhs.streamType, rhs.bitRate, rhs.durationUs, rhs.hasVideo, rhs.isStreaming, rhs.bitWidth, rhs.offloadBufferSize, rhs.usage, rhs.encapsulationMode, rhs.contentId, rhs.syncId);
  }
  inline bool operator<=(const AudioOffloadInfo& rhs) const {
    return std::tie(version, config, streamType, bitRate, durationUs, hasVideo, isStreaming, bitWidth, offloadBufferSize, usage, encapsulationMode, contentId, syncId) <= std::tie(rhs.version, rhs.config, rhs.streamType, rhs.bitRate, rhs.durationUs, rhs.hasVideo, rhs.isStreaming, rhs.bitWidth, rhs.offloadBufferSize, rhs.usage, rhs.encapsulationMode, rhs.contentId, rhs.syncId);
  }
  inline bool operator==(const AudioOffloadInfo& rhs) const {
    return std::tie(version, config, streamType, bitRate, durationUs, hasVideo, isStreaming, bitWidth, offloadBufferSize, usage, encapsulationMode, contentId, syncId) == std::tie(rhs.version, rhs.config, rhs.streamType, rhs.bitRate, rhs.durationUs, rhs.hasVideo, rhs.isStreaming, rhs.bitWidth, rhs.offloadBufferSize, rhs.usage, rhs.encapsulationMode, rhs.contentId, rhs.syncId);
  }
  inline bool operator>(const AudioOffloadInfo& rhs) const {
    return std::tie(version, config, streamType, bitRate, durationUs, hasVideo, isStreaming, bitWidth, offloadBufferSize, usage, encapsulationMode, contentId, syncId) > std::tie(rhs.version, rhs.config, rhs.streamType, rhs.bitRate, rhs.durationUs, rhs.hasVideo, rhs.isStreaming, rhs.bitWidth, rhs.offloadBufferSize, rhs.usage, rhs.encapsulationMode, rhs.contentId, rhs.syncId);
  }
  inline bool operator>=(const AudioOffloadInfo& rhs) const {
    return std::tie(version, config, streamType, bitRate, durationUs, hasVideo, isStreaming, bitWidth, offloadBufferSize, usage, encapsulationMode, contentId, syncId) >= std::tie(rhs.version, rhs.config, rhs.streamType, rhs.bitRate, rhs.durationUs, rhs.hasVideo, rhs.isStreaming, rhs.bitWidth, rhs.offloadBufferSize, rhs.usage, rhs.encapsulationMode, rhs.contentId, rhs.syncId);
  }

  int32_t version = int32_t(0);
  ::android::media::AudioConfigBase config;
  ::android::media::AudioStreamType streamType = ::android::media::AudioStreamType(0);
  int32_t bitRate = int32_t(0);
  int64_t durationUs = int64_t(0L);
  bool hasVideo = bool(false);
  bool isStreaming = bool(false);
  int32_t bitWidth = int32_t(0);
  int32_t offloadBufferSize = int32_t(0);
  ::android::media::AudioUsage usage = ::android::media::AudioUsage(0);
  ::android::media::AudioEncapsulationMode encapsulationMode = ::android::media::AudioEncapsulationMode(0);
  int32_t contentId = int32_t(0);
  int32_t syncId = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioOffloadInfo");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioOffloadInfo{";
    os << "version: " << ::android::internal::ToString(version);
    os << ", config: " << ::android::internal::ToString(config);
    os << ", streamType: " << ::android::internal::ToString(streamType);
    os << ", bitRate: " << ::android::internal::ToString(bitRate);
    os << ", durationUs: " << ::android::internal::ToString(durationUs);
    os << ", hasVideo: " << ::android::internal::ToString(hasVideo);
    os << ", isStreaming: " << ::android::internal::ToString(isStreaming);
    os << ", bitWidth: " << ::android::internal::ToString(bitWidth);
    os << ", offloadBufferSize: " << ::android::internal::ToString(offloadBufferSize);
    os << ", usage: " << ::android::internal::ToString(usage);
    os << ", encapsulationMode: " << ::android::internal::ToString(encapsulationMode);
    os << ", contentId: " << ::android::internal::ToString(contentId);
    os << ", syncId: " << ::android::internal::ToString(syncId);
    os << "}";
    return os.str();
  }
};  // class AudioOffloadInfo

}  // namespace media

}  // namespace android
