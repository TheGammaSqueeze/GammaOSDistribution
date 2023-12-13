#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioEncapsulationType.h>
#include <android/media/AudioStandard.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace media {

class ExtraAudioDescriptor : public ::android::Parcelable {
public:
  inline bool operator!=(const ExtraAudioDescriptor& rhs) const {
    return std::tie(standard, audioDescriptor, encapsulationType) != std::tie(rhs.standard, rhs.audioDescriptor, rhs.encapsulationType);
  }
  inline bool operator<(const ExtraAudioDescriptor& rhs) const {
    return std::tie(standard, audioDescriptor, encapsulationType) < std::tie(rhs.standard, rhs.audioDescriptor, rhs.encapsulationType);
  }
  inline bool operator<=(const ExtraAudioDescriptor& rhs) const {
    return std::tie(standard, audioDescriptor, encapsulationType) <= std::tie(rhs.standard, rhs.audioDescriptor, rhs.encapsulationType);
  }
  inline bool operator==(const ExtraAudioDescriptor& rhs) const {
    return std::tie(standard, audioDescriptor, encapsulationType) == std::tie(rhs.standard, rhs.audioDescriptor, rhs.encapsulationType);
  }
  inline bool operator>(const ExtraAudioDescriptor& rhs) const {
    return std::tie(standard, audioDescriptor, encapsulationType) > std::tie(rhs.standard, rhs.audioDescriptor, rhs.encapsulationType);
  }
  inline bool operator>=(const ExtraAudioDescriptor& rhs) const {
    return std::tie(standard, audioDescriptor, encapsulationType) >= std::tie(rhs.standard, rhs.audioDescriptor, rhs.encapsulationType);
  }

  ::android::media::AudioStandard standard = ::android::media::AudioStandard(0);
  ::std::vector<uint8_t> audioDescriptor;
  ::android::media::AudioEncapsulationType encapsulationType = ::android::media::AudioEncapsulationType(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.ExtraAudioDescriptor");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "ExtraAudioDescriptor{";
    os << "standard: " << ::android::internal::ToString(standard);
    os << ", audioDescriptor: " << ::android::internal::ToString(audioDescriptor);
    os << ", encapsulationType: " << ::android::internal::ToString(encapsulationType);
    os << "}";
    return os.str();
  }
};  // class ExtraAudioDescriptor

}  // namespace media

}  // namespace android
