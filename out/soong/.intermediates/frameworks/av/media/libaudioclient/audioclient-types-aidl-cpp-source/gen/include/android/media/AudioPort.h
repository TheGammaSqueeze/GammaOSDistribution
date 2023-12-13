#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioGain.h>
#include <android/media/AudioPortConfig.h>
#include <android/media/AudioPortExt.h>
#include <android/media/AudioPortRole.h>
#include <android/media/AudioPortType.h>
#include <android/media/AudioProfile.h>
#include <android/media/ExtraAudioDescriptor.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace media {

class AudioPort : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioPort& rhs) const {
    return std::tie(id, role, type, name, profiles, extraAudioDescriptors, gains, activeConfig, ext) != std::tie(rhs.id, rhs.role, rhs.type, rhs.name, rhs.profiles, rhs.extraAudioDescriptors, rhs.gains, rhs.activeConfig, rhs.ext);
  }
  inline bool operator<(const AudioPort& rhs) const {
    return std::tie(id, role, type, name, profiles, extraAudioDescriptors, gains, activeConfig, ext) < std::tie(rhs.id, rhs.role, rhs.type, rhs.name, rhs.profiles, rhs.extraAudioDescriptors, rhs.gains, rhs.activeConfig, rhs.ext);
  }
  inline bool operator<=(const AudioPort& rhs) const {
    return std::tie(id, role, type, name, profiles, extraAudioDescriptors, gains, activeConfig, ext) <= std::tie(rhs.id, rhs.role, rhs.type, rhs.name, rhs.profiles, rhs.extraAudioDescriptors, rhs.gains, rhs.activeConfig, rhs.ext);
  }
  inline bool operator==(const AudioPort& rhs) const {
    return std::tie(id, role, type, name, profiles, extraAudioDescriptors, gains, activeConfig, ext) == std::tie(rhs.id, rhs.role, rhs.type, rhs.name, rhs.profiles, rhs.extraAudioDescriptors, rhs.gains, rhs.activeConfig, rhs.ext);
  }
  inline bool operator>(const AudioPort& rhs) const {
    return std::tie(id, role, type, name, profiles, extraAudioDescriptors, gains, activeConfig, ext) > std::tie(rhs.id, rhs.role, rhs.type, rhs.name, rhs.profiles, rhs.extraAudioDescriptors, rhs.gains, rhs.activeConfig, rhs.ext);
  }
  inline bool operator>=(const AudioPort& rhs) const {
    return std::tie(id, role, type, name, profiles, extraAudioDescriptors, gains, activeConfig, ext) >= std::tie(rhs.id, rhs.role, rhs.type, rhs.name, rhs.profiles, rhs.extraAudioDescriptors, rhs.gains, rhs.activeConfig, rhs.ext);
  }

  int32_t id = int32_t(0);
  ::android::media::AudioPortRole role = ::android::media::AudioPortRole(0);
  ::android::media::AudioPortType type = ::android::media::AudioPortType(0);
  ::std::string name;
  ::std::vector<::android::media::AudioProfile> profiles;
  ::std::vector<::android::media::ExtraAudioDescriptor> extraAudioDescriptors;
  ::std::vector<::android::media::AudioGain> gains;
  ::android::media::AudioPortConfig activeConfig;
  ::android::media::AudioPortExt ext;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioPort");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioPort{";
    os << "id: " << ::android::internal::ToString(id);
    os << ", role: " << ::android::internal::ToString(role);
    os << ", type: " << ::android::internal::ToString(type);
    os << ", name: " << ::android::internal::ToString(name);
    os << ", profiles: " << ::android::internal::ToString(profiles);
    os << ", extraAudioDescriptors: " << ::android::internal::ToString(extraAudioDescriptors);
    os << ", gains: " << ::android::internal::ToString(gains);
    os << ", activeConfig: " << ::android::internal::ToString(activeConfig);
    os << ", ext: " << ::android::internal::ToString(ext);
    os << "}";
    return os.str();
  }
};  // class AudioPort

}  // namespace media

}  // namespace android
