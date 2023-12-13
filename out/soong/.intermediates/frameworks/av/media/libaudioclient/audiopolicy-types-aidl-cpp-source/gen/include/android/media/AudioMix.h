#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioConfig.h>
#include <android/media/AudioDevice.h>
#include <android/media/AudioMixMatchCriterion.h>
#include <android/media/AudioMixType.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace media {

class AudioMix : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioMix& rhs) const {
    return std::tie(criteria, mixType, format, routeFlags, device, cbFlags, allowPrivilegedMediaPlaybackCapture, voiceCommunicationCaptureAllowed) != std::tie(rhs.criteria, rhs.mixType, rhs.format, rhs.routeFlags, rhs.device, rhs.cbFlags, rhs.allowPrivilegedMediaPlaybackCapture, rhs.voiceCommunicationCaptureAllowed);
  }
  inline bool operator<(const AudioMix& rhs) const {
    return std::tie(criteria, mixType, format, routeFlags, device, cbFlags, allowPrivilegedMediaPlaybackCapture, voiceCommunicationCaptureAllowed) < std::tie(rhs.criteria, rhs.mixType, rhs.format, rhs.routeFlags, rhs.device, rhs.cbFlags, rhs.allowPrivilegedMediaPlaybackCapture, rhs.voiceCommunicationCaptureAllowed);
  }
  inline bool operator<=(const AudioMix& rhs) const {
    return std::tie(criteria, mixType, format, routeFlags, device, cbFlags, allowPrivilegedMediaPlaybackCapture, voiceCommunicationCaptureAllowed) <= std::tie(rhs.criteria, rhs.mixType, rhs.format, rhs.routeFlags, rhs.device, rhs.cbFlags, rhs.allowPrivilegedMediaPlaybackCapture, rhs.voiceCommunicationCaptureAllowed);
  }
  inline bool operator==(const AudioMix& rhs) const {
    return std::tie(criteria, mixType, format, routeFlags, device, cbFlags, allowPrivilegedMediaPlaybackCapture, voiceCommunicationCaptureAllowed) == std::tie(rhs.criteria, rhs.mixType, rhs.format, rhs.routeFlags, rhs.device, rhs.cbFlags, rhs.allowPrivilegedMediaPlaybackCapture, rhs.voiceCommunicationCaptureAllowed);
  }
  inline bool operator>(const AudioMix& rhs) const {
    return std::tie(criteria, mixType, format, routeFlags, device, cbFlags, allowPrivilegedMediaPlaybackCapture, voiceCommunicationCaptureAllowed) > std::tie(rhs.criteria, rhs.mixType, rhs.format, rhs.routeFlags, rhs.device, rhs.cbFlags, rhs.allowPrivilegedMediaPlaybackCapture, rhs.voiceCommunicationCaptureAllowed);
  }
  inline bool operator>=(const AudioMix& rhs) const {
    return std::tie(criteria, mixType, format, routeFlags, device, cbFlags, allowPrivilegedMediaPlaybackCapture, voiceCommunicationCaptureAllowed) >= std::tie(rhs.criteria, rhs.mixType, rhs.format, rhs.routeFlags, rhs.device, rhs.cbFlags, rhs.allowPrivilegedMediaPlaybackCapture, rhs.voiceCommunicationCaptureAllowed);
  }

  ::std::vector<::android::media::AudioMixMatchCriterion> criteria;
  ::android::media::AudioMixType mixType = ::android::media::AudioMixType(0);
  ::android::media::AudioConfig format;
  int32_t routeFlags = int32_t(0);
  ::android::media::AudioDevice device;
  int32_t cbFlags = int32_t(0);
  bool allowPrivilegedMediaPlaybackCapture = bool(false);
  bool voiceCommunicationCaptureAllowed = bool(false);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioMix");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioMix{";
    os << "criteria: " << ::android::internal::ToString(criteria);
    os << ", mixType: " << ::android::internal::ToString(mixType);
    os << ", format: " << ::android::internal::ToString(format);
    os << ", routeFlags: " << ::android::internal::ToString(routeFlags);
    os << ", device: " << ::android::internal::ToString(device);
    os << ", cbFlags: " << ::android::internal::ToString(cbFlags);
    os << ", allowPrivilegedMediaPlaybackCapture: " << ::android::internal::ToString(allowPrivilegedMediaPlaybackCapture);
    os << ", voiceCommunicationCaptureAllowed: " << ::android::internal::ToString(voiceCommunicationCaptureAllowed);
    os << "}";
    return os.str();
  }
};  // class AudioMix

}  // namespace media

}  // namespace android
