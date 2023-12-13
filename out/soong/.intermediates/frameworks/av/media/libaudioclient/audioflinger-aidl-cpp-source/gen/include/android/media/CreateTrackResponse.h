#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioStreamType.h>
#include <android/media/IAudioTrack.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class CreateTrackResponse : public ::android::Parcelable {
public:
  inline bool operator!=(const CreateTrackResponse& rhs) const {
    return std::tie(flags, frameCount, notificationFrameCount, selectedDeviceId, sessionId, sampleRate, streamType, afFrameCount, afSampleRate, afLatencyMs, outputId, portId, audioTrack) != std::tie(rhs.flags, rhs.frameCount, rhs.notificationFrameCount, rhs.selectedDeviceId, rhs.sessionId, rhs.sampleRate, rhs.streamType, rhs.afFrameCount, rhs.afSampleRate, rhs.afLatencyMs, rhs.outputId, rhs.portId, rhs.audioTrack);
  }
  inline bool operator<(const CreateTrackResponse& rhs) const {
    return std::tie(flags, frameCount, notificationFrameCount, selectedDeviceId, sessionId, sampleRate, streamType, afFrameCount, afSampleRate, afLatencyMs, outputId, portId, audioTrack) < std::tie(rhs.flags, rhs.frameCount, rhs.notificationFrameCount, rhs.selectedDeviceId, rhs.sessionId, rhs.sampleRate, rhs.streamType, rhs.afFrameCount, rhs.afSampleRate, rhs.afLatencyMs, rhs.outputId, rhs.portId, rhs.audioTrack);
  }
  inline bool operator<=(const CreateTrackResponse& rhs) const {
    return std::tie(flags, frameCount, notificationFrameCount, selectedDeviceId, sessionId, sampleRate, streamType, afFrameCount, afSampleRate, afLatencyMs, outputId, portId, audioTrack) <= std::tie(rhs.flags, rhs.frameCount, rhs.notificationFrameCount, rhs.selectedDeviceId, rhs.sessionId, rhs.sampleRate, rhs.streamType, rhs.afFrameCount, rhs.afSampleRate, rhs.afLatencyMs, rhs.outputId, rhs.portId, rhs.audioTrack);
  }
  inline bool operator==(const CreateTrackResponse& rhs) const {
    return std::tie(flags, frameCount, notificationFrameCount, selectedDeviceId, sessionId, sampleRate, streamType, afFrameCount, afSampleRate, afLatencyMs, outputId, portId, audioTrack) == std::tie(rhs.flags, rhs.frameCount, rhs.notificationFrameCount, rhs.selectedDeviceId, rhs.sessionId, rhs.sampleRate, rhs.streamType, rhs.afFrameCount, rhs.afSampleRate, rhs.afLatencyMs, rhs.outputId, rhs.portId, rhs.audioTrack);
  }
  inline bool operator>(const CreateTrackResponse& rhs) const {
    return std::tie(flags, frameCount, notificationFrameCount, selectedDeviceId, sessionId, sampleRate, streamType, afFrameCount, afSampleRate, afLatencyMs, outputId, portId, audioTrack) > std::tie(rhs.flags, rhs.frameCount, rhs.notificationFrameCount, rhs.selectedDeviceId, rhs.sessionId, rhs.sampleRate, rhs.streamType, rhs.afFrameCount, rhs.afSampleRate, rhs.afLatencyMs, rhs.outputId, rhs.portId, rhs.audioTrack);
  }
  inline bool operator>=(const CreateTrackResponse& rhs) const {
    return std::tie(flags, frameCount, notificationFrameCount, selectedDeviceId, sessionId, sampleRate, streamType, afFrameCount, afSampleRate, afLatencyMs, outputId, portId, audioTrack) >= std::tie(rhs.flags, rhs.frameCount, rhs.notificationFrameCount, rhs.selectedDeviceId, rhs.sessionId, rhs.sampleRate, rhs.streamType, rhs.afFrameCount, rhs.afSampleRate, rhs.afLatencyMs, rhs.outputId, rhs.portId, rhs.audioTrack);
  }

  int32_t flags = int32_t(0);
  int64_t frameCount = int64_t(0L);
  int64_t notificationFrameCount = int64_t(0L);
  int32_t selectedDeviceId = int32_t(0);
  int32_t sessionId = int32_t(0);
  int32_t sampleRate = int32_t(0);
  ::android::media::AudioStreamType streamType = ::android::media::AudioStreamType(0);
  int64_t afFrameCount = int64_t(0L);
  int32_t afSampleRate = int32_t(0);
  int32_t afLatencyMs = int32_t(0);
  int32_t outputId = int32_t(0);
  int32_t portId = int32_t(0);
  ::android::sp<::android::media::IAudioTrack> audioTrack;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.CreateTrackResponse");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "CreateTrackResponse{";
    os << "flags: " << ::android::internal::ToString(flags);
    os << ", frameCount: " << ::android::internal::ToString(frameCount);
    os << ", notificationFrameCount: " << ::android::internal::ToString(notificationFrameCount);
    os << ", selectedDeviceId: " << ::android::internal::ToString(selectedDeviceId);
    os << ", sessionId: " << ::android::internal::ToString(sessionId);
    os << ", sampleRate: " << ::android::internal::ToString(sampleRate);
    os << ", streamType: " << ::android::internal::ToString(streamType);
    os << ", afFrameCount: " << ::android::internal::ToString(afFrameCount);
    os << ", afSampleRate: " << ::android::internal::ToString(afSampleRate);
    os << ", afLatencyMs: " << ::android::internal::ToString(afLatencyMs);
    os << ", outputId: " << ::android::internal::ToString(outputId);
    os << ", portId: " << ::android::internal::ToString(portId);
    os << ", audioTrack: " << ::android::internal::ToString(audioTrack);
    os << "}";
    return os.str();
  }
};  // class CreateTrackResponse

}  // namespace media

}  // namespace android
