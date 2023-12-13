#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioPatch.h>
#include <android/media/audio/common/AudioFormat.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class AudioIoDescriptor : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioIoDescriptor& rhs) const {
    return std::tie(ioHandle, patch, samplingRate, format, channelMask, frameCount, frameCountHAL, latency, portId) != std::tie(rhs.ioHandle, rhs.patch, rhs.samplingRate, rhs.format, rhs.channelMask, rhs.frameCount, rhs.frameCountHAL, rhs.latency, rhs.portId);
  }
  inline bool operator<(const AudioIoDescriptor& rhs) const {
    return std::tie(ioHandle, patch, samplingRate, format, channelMask, frameCount, frameCountHAL, latency, portId) < std::tie(rhs.ioHandle, rhs.patch, rhs.samplingRate, rhs.format, rhs.channelMask, rhs.frameCount, rhs.frameCountHAL, rhs.latency, rhs.portId);
  }
  inline bool operator<=(const AudioIoDescriptor& rhs) const {
    return std::tie(ioHandle, patch, samplingRate, format, channelMask, frameCount, frameCountHAL, latency, portId) <= std::tie(rhs.ioHandle, rhs.patch, rhs.samplingRate, rhs.format, rhs.channelMask, rhs.frameCount, rhs.frameCountHAL, rhs.latency, rhs.portId);
  }
  inline bool operator==(const AudioIoDescriptor& rhs) const {
    return std::tie(ioHandle, patch, samplingRate, format, channelMask, frameCount, frameCountHAL, latency, portId) == std::tie(rhs.ioHandle, rhs.patch, rhs.samplingRate, rhs.format, rhs.channelMask, rhs.frameCount, rhs.frameCountHAL, rhs.latency, rhs.portId);
  }
  inline bool operator>(const AudioIoDescriptor& rhs) const {
    return std::tie(ioHandle, patch, samplingRate, format, channelMask, frameCount, frameCountHAL, latency, portId) > std::tie(rhs.ioHandle, rhs.patch, rhs.samplingRate, rhs.format, rhs.channelMask, rhs.frameCount, rhs.frameCountHAL, rhs.latency, rhs.portId);
  }
  inline bool operator>=(const AudioIoDescriptor& rhs) const {
    return std::tie(ioHandle, patch, samplingRate, format, channelMask, frameCount, frameCountHAL, latency, portId) >= std::tie(rhs.ioHandle, rhs.patch, rhs.samplingRate, rhs.format, rhs.channelMask, rhs.frameCount, rhs.frameCountHAL, rhs.latency, rhs.portId);
  }

  int32_t ioHandle = int32_t(0);
  ::android::media::AudioPatch patch;
  int32_t samplingRate = int32_t(0);
  ::android::media::audio::common::AudioFormat format = ::android::media::audio::common::AudioFormat(0);
  int32_t channelMask = int32_t(0);
  int64_t frameCount = int64_t(0L);
  int64_t frameCountHAL = int64_t(0L);
  int32_t latency = int32_t(0);
  int32_t portId = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioIoDescriptor");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioIoDescriptor{";
    os << "ioHandle: " << ::android::internal::ToString(ioHandle);
    os << ", patch: " << ::android::internal::ToString(patch);
    os << ", samplingRate: " << ::android::internal::ToString(samplingRate);
    os << ", format: " << ::android::internal::ToString(format);
    os << ", channelMask: " << ::android::internal::ToString(channelMask);
    os << ", frameCount: " << ::android::internal::ToString(frameCount);
    os << ", frameCountHAL: " << ::android::internal::ToString(frameCountHAL);
    os << ", latency: " << ::android::internal::ToString(latency);
    os << ", portId: " << ::android::internal::ToString(portId);
    os << "}";
    return os.str();
  }
};  // class AudioIoDescriptor

}  // namespace media

}  // namespace android
