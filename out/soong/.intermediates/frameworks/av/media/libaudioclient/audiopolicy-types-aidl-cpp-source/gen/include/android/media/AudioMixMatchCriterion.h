#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioMixMatchCriterionValue.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class AudioMixMatchCriterion : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioMixMatchCriterion& rhs) const {
    return std::tie(invert, value) != std::tie(rhs.invert, rhs.value);
  }
  inline bool operator<(const AudioMixMatchCriterion& rhs) const {
    return std::tie(invert, value) < std::tie(rhs.invert, rhs.value);
  }
  inline bool operator<=(const AudioMixMatchCriterion& rhs) const {
    return std::tie(invert, value) <= std::tie(rhs.invert, rhs.value);
  }
  inline bool operator==(const AudioMixMatchCriterion& rhs) const {
    return std::tie(invert, value) == std::tie(rhs.invert, rhs.value);
  }
  inline bool operator>(const AudioMixMatchCriterion& rhs) const {
    return std::tie(invert, value) > std::tie(rhs.invert, rhs.value);
  }
  inline bool operator>=(const AudioMixMatchCriterion& rhs) const {
    return std::tie(invert, value) >= std::tie(rhs.invert, rhs.value);
  }

  bool invert = bool(false);
  ::android::media::AudioMixMatchCriterionValue value;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioMixMatchCriterion");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioMixMatchCriterion{";
    os << "invert: " << ::android::internal::ToString(invert);
    os << ", value: " << ::android::internal::ToString(value);
    os << "}";
    return os.str();
  }
};  // class AudioMixMatchCriterion

}  // namespace media

}  // namespace android
