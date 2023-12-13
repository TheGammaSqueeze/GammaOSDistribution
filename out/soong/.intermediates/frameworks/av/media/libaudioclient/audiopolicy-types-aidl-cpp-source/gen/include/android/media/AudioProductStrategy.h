#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioAttributesEx.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace media {

class AudioProductStrategy : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioProductStrategy& rhs) const {
    return std::tie(id, name, audioAttributes) != std::tie(rhs.id, rhs.name, rhs.audioAttributes);
  }
  inline bool operator<(const AudioProductStrategy& rhs) const {
    return std::tie(id, name, audioAttributes) < std::tie(rhs.id, rhs.name, rhs.audioAttributes);
  }
  inline bool operator<=(const AudioProductStrategy& rhs) const {
    return std::tie(id, name, audioAttributes) <= std::tie(rhs.id, rhs.name, rhs.audioAttributes);
  }
  inline bool operator==(const AudioProductStrategy& rhs) const {
    return std::tie(id, name, audioAttributes) == std::tie(rhs.id, rhs.name, rhs.audioAttributes);
  }
  inline bool operator>(const AudioProductStrategy& rhs) const {
    return std::tie(id, name, audioAttributes) > std::tie(rhs.id, rhs.name, rhs.audioAttributes);
  }
  inline bool operator>=(const AudioProductStrategy& rhs) const {
    return std::tie(id, name, audioAttributes) >= std::tie(rhs.id, rhs.name, rhs.audioAttributes);
  }

  int32_t id = int32_t(0);
  ::std::string name;
  ::std::vector<::android::media::AudioAttributesEx> audioAttributes;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioProductStrategy");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioProductStrategy{";
    os << "id: " << ::android::internal::ToString(id);
    os << ", name: " << ::android::internal::ToString(name);
    os << ", audioAttributes: " << ::android::internal::ToString(audioAttributes);
    os << "}";
    return os.str();
  }
};  // class AudioProductStrategy

}  // namespace media

}  // namespace android
