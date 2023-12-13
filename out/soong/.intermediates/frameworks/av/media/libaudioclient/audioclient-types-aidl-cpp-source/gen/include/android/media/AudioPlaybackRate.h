#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class AudioPlaybackRate : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioPlaybackRate& rhs) const {
    return std::tie(speed, pitch, stretchMode, fallbackMode) != std::tie(rhs.speed, rhs.pitch, rhs.stretchMode, rhs.fallbackMode);
  }
  inline bool operator<(const AudioPlaybackRate& rhs) const {
    return std::tie(speed, pitch, stretchMode, fallbackMode) < std::tie(rhs.speed, rhs.pitch, rhs.stretchMode, rhs.fallbackMode);
  }
  inline bool operator<=(const AudioPlaybackRate& rhs) const {
    return std::tie(speed, pitch, stretchMode, fallbackMode) <= std::tie(rhs.speed, rhs.pitch, rhs.stretchMode, rhs.fallbackMode);
  }
  inline bool operator==(const AudioPlaybackRate& rhs) const {
    return std::tie(speed, pitch, stretchMode, fallbackMode) == std::tie(rhs.speed, rhs.pitch, rhs.stretchMode, rhs.fallbackMode);
  }
  inline bool operator>(const AudioPlaybackRate& rhs) const {
    return std::tie(speed, pitch, stretchMode, fallbackMode) > std::tie(rhs.speed, rhs.pitch, rhs.stretchMode, rhs.fallbackMode);
  }
  inline bool operator>=(const AudioPlaybackRate& rhs) const {
    return std::tie(speed, pitch, stretchMode, fallbackMode) >= std::tie(rhs.speed, rhs.pitch, rhs.stretchMode, rhs.fallbackMode);
  }

  float speed = float(0.000000f);
  float pitch = float(0.000000f);
  int32_t stretchMode = int32_t(0);
  int32_t fallbackMode = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioPlaybackRate");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioPlaybackRate{";
    os << "speed: " << ::android::internal::ToString(speed);
    os << ", pitch: " << ::android::internal::ToString(pitch);
    os << ", stretchMode: " << ::android::internal::ToString(stretchMode);
    os << ", fallbackMode: " << ::android::internal::ToString(fallbackMode);
    os << "}";
    return os.str();
  }
};  // class AudioPlaybackRate

}  // namespace media

}  // namespace android
