#pragma once

#include <android/binder_to_string.h>
#include <android/media/audio/common/AudioFormat.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class AudioConfigBase : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioConfigBase& rhs) const {
    return std::tie(sampleRate, channelMask, format) != std::tie(rhs.sampleRate, rhs.channelMask, rhs.format);
  }
  inline bool operator<(const AudioConfigBase& rhs) const {
    return std::tie(sampleRate, channelMask, format) < std::tie(rhs.sampleRate, rhs.channelMask, rhs.format);
  }
  inline bool operator<=(const AudioConfigBase& rhs) const {
    return std::tie(sampleRate, channelMask, format) <= std::tie(rhs.sampleRate, rhs.channelMask, rhs.format);
  }
  inline bool operator==(const AudioConfigBase& rhs) const {
    return std::tie(sampleRate, channelMask, format) == std::tie(rhs.sampleRate, rhs.channelMask, rhs.format);
  }
  inline bool operator>(const AudioConfigBase& rhs) const {
    return std::tie(sampleRate, channelMask, format) > std::tie(rhs.sampleRate, rhs.channelMask, rhs.format);
  }
  inline bool operator>=(const AudioConfigBase& rhs) const {
    return std::tie(sampleRate, channelMask, format) >= std::tie(rhs.sampleRate, rhs.channelMask, rhs.format);
  }

  int32_t sampleRate = int32_t(0);
  int32_t channelMask = int32_t(0);
  ::android::media::audio::common::AudioFormat format = ::android::media::audio::common::AudioFormat(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioConfigBase");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioConfigBase{";
    os << "sampleRate: " << ::android::internal::ToString(sampleRate);
    os << ", channelMask: " << ::android::internal::ToString(channelMask);
    os << ", format: " << ::android::internal::ToString(format);
    os << "}";
    return os.str();
  }
};  // class AudioConfigBase

}  // namespace media

}  // namespace android
