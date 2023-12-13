#pragma once

#include <android/binder_to_string.h>
#include <android/media/audio/common/AudioFormat.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace aaudio {

class StreamParameters : public ::android::Parcelable {
public:
  inline bool operator!=(const StreamParameters& rhs) const {
    return std::tie(channelMask, sampleRate, deviceId, sharingMode, audioFormat, direction, usage, contentType, spatializationBehavior, isContentSpatialized, inputPreset, bufferCapacity, allowedCapturePolicy, sessionId, isPrivacySensitive) != std::tie(rhs.channelMask, rhs.sampleRate, rhs.deviceId, rhs.sharingMode, rhs.audioFormat, rhs.direction, rhs.usage, rhs.contentType, rhs.spatializationBehavior, rhs.isContentSpatialized, rhs.inputPreset, rhs.bufferCapacity, rhs.allowedCapturePolicy, rhs.sessionId, rhs.isPrivacySensitive);
  }
  inline bool operator<(const StreamParameters& rhs) const {
    return std::tie(channelMask, sampleRate, deviceId, sharingMode, audioFormat, direction, usage, contentType, spatializationBehavior, isContentSpatialized, inputPreset, bufferCapacity, allowedCapturePolicy, sessionId, isPrivacySensitive) < std::tie(rhs.channelMask, rhs.sampleRate, rhs.deviceId, rhs.sharingMode, rhs.audioFormat, rhs.direction, rhs.usage, rhs.contentType, rhs.spatializationBehavior, rhs.isContentSpatialized, rhs.inputPreset, rhs.bufferCapacity, rhs.allowedCapturePolicy, rhs.sessionId, rhs.isPrivacySensitive);
  }
  inline bool operator<=(const StreamParameters& rhs) const {
    return std::tie(channelMask, sampleRate, deviceId, sharingMode, audioFormat, direction, usage, contentType, spatializationBehavior, isContentSpatialized, inputPreset, bufferCapacity, allowedCapturePolicy, sessionId, isPrivacySensitive) <= std::tie(rhs.channelMask, rhs.sampleRate, rhs.deviceId, rhs.sharingMode, rhs.audioFormat, rhs.direction, rhs.usage, rhs.contentType, rhs.spatializationBehavior, rhs.isContentSpatialized, rhs.inputPreset, rhs.bufferCapacity, rhs.allowedCapturePolicy, rhs.sessionId, rhs.isPrivacySensitive);
  }
  inline bool operator==(const StreamParameters& rhs) const {
    return std::tie(channelMask, sampleRate, deviceId, sharingMode, audioFormat, direction, usage, contentType, spatializationBehavior, isContentSpatialized, inputPreset, bufferCapacity, allowedCapturePolicy, sessionId, isPrivacySensitive) == std::tie(rhs.channelMask, rhs.sampleRate, rhs.deviceId, rhs.sharingMode, rhs.audioFormat, rhs.direction, rhs.usage, rhs.contentType, rhs.spatializationBehavior, rhs.isContentSpatialized, rhs.inputPreset, rhs.bufferCapacity, rhs.allowedCapturePolicy, rhs.sessionId, rhs.isPrivacySensitive);
  }
  inline bool operator>(const StreamParameters& rhs) const {
    return std::tie(channelMask, sampleRate, deviceId, sharingMode, audioFormat, direction, usage, contentType, spatializationBehavior, isContentSpatialized, inputPreset, bufferCapacity, allowedCapturePolicy, sessionId, isPrivacySensitive) > std::tie(rhs.channelMask, rhs.sampleRate, rhs.deviceId, rhs.sharingMode, rhs.audioFormat, rhs.direction, rhs.usage, rhs.contentType, rhs.spatializationBehavior, rhs.isContentSpatialized, rhs.inputPreset, rhs.bufferCapacity, rhs.allowedCapturePolicy, rhs.sessionId, rhs.isPrivacySensitive);
  }
  inline bool operator>=(const StreamParameters& rhs) const {
    return std::tie(channelMask, sampleRate, deviceId, sharingMode, audioFormat, direction, usage, contentType, spatializationBehavior, isContentSpatialized, inputPreset, bufferCapacity, allowedCapturePolicy, sessionId, isPrivacySensitive) >= std::tie(rhs.channelMask, rhs.sampleRate, rhs.deviceId, rhs.sharingMode, rhs.audioFormat, rhs.direction, rhs.usage, rhs.contentType, rhs.spatializationBehavior, rhs.isContentSpatialized, rhs.inputPreset, rhs.bufferCapacity, rhs.allowedCapturePolicy, rhs.sessionId, rhs.isPrivacySensitive);
  }

  int32_t channelMask = int32_t(0);
  int32_t sampleRate = int32_t(0);
  int32_t deviceId = int32_t(0);
  int32_t sharingMode = int32_t(0);
  ::android::media::audio::common::AudioFormat audioFormat = ::android::media::audio::common::AudioFormat(0);
  int32_t direction = int32_t(0);
  int32_t usage = int32_t(0);
  int32_t contentType = int32_t(0);
  int32_t spatializationBehavior = int32_t(0);
  bool isContentSpatialized = bool(false);
  int32_t inputPreset = int32_t(0);
  int32_t bufferCapacity = int32_t(0);
  int32_t allowedCapturePolicy = int32_t(0);
  int32_t sessionId = int32_t(0);
  bool isPrivacySensitive = bool(false);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"aaudio.StreamParameters");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "StreamParameters{";
    os << "channelMask: " << ::android::internal::ToString(channelMask);
    os << ", sampleRate: " << ::android::internal::ToString(sampleRate);
    os << ", deviceId: " << ::android::internal::ToString(deviceId);
    os << ", sharingMode: " << ::android::internal::ToString(sharingMode);
    os << ", audioFormat: " << ::android::internal::ToString(audioFormat);
    os << ", direction: " << ::android::internal::ToString(direction);
    os << ", usage: " << ::android::internal::ToString(usage);
    os << ", contentType: " << ::android::internal::ToString(contentType);
    os << ", spatializationBehavior: " << ::android::internal::ToString(spatializationBehavior);
    os << ", isContentSpatialized: " << ::android::internal::ToString(isContentSpatialized);
    os << ", inputPreset: " << ::android::internal::ToString(inputPreset);
    os << ", bufferCapacity: " << ::android::internal::ToString(bufferCapacity);
    os << ", allowedCapturePolicy: " << ::android::internal::ToString(allowedCapturePolicy);
    os << ", sessionId: " << ::android::internal::ToString(sessionId);
    os << ", isPrivacySensitive: " << ::android::internal::ToString(isPrivacySensitive);
    os << "}";
    return os.str();
  }
};  // class StreamParameters

}  // namespace aaudio
