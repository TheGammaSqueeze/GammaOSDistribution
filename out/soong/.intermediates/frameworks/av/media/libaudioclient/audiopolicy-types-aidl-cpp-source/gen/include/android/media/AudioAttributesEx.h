#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioAttributesInternal.h>
#include <android/media/AudioStreamType.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class AudioAttributesEx : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioAttributesEx& rhs) const {
    return std::tie(attributes, streamType, groupId) != std::tie(rhs.attributes, rhs.streamType, rhs.groupId);
  }
  inline bool operator<(const AudioAttributesEx& rhs) const {
    return std::tie(attributes, streamType, groupId) < std::tie(rhs.attributes, rhs.streamType, rhs.groupId);
  }
  inline bool operator<=(const AudioAttributesEx& rhs) const {
    return std::tie(attributes, streamType, groupId) <= std::tie(rhs.attributes, rhs.streamType, rhs.groupId);
  }
  inline bool operator==(const AudioAttributesEx& rhs) const {
    return std::tie(attributes, streamType, groupId) == std::tie(rhs.attributes, rhs.streamType, rhs.groupId);
  }
  inline bool operator>(const AudioAttributesEx& rhs) const {
    return std::tie(attributes, streamType, groupId) > std::tie(rhs.attributes, rhs.streamType, rhs.groupId);
  }
  inline bool operator>=(const AudioAttributesEx& rhs) const {
    return std::tie(attributes, streamType, groupId) >= std::tie(rhs.attributes, rhs.streamType, rhs.groupId);
  }

  ::android::media::AudioAttributesInternal attributes;
  ::android::media::AudioStreamType streamType = ::android::media::AudioStreamType(0);
  int32_t groupId = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioAttributesEx");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioAttributesEx{";
    os << "attributes: " << ::android::internal::ToString(attributes);
    os << ", streamType: " << ::android::internal::ToString(streamType);
    os << ", groupId: " << ::android::internal::ToString(groupId);
    os << "}";
    return os.str();
  }
};  // class AudioAttributesEx

}  // namespace media

}  // namespace android
