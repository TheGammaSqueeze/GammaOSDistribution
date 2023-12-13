#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioAttributesInternal.h>
#include <android/media/AudioStreamType.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace media {

class AudioVolumeGroup : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioVolumeGroup& rhs) const {
    return std::tie(groupId, name, audioAttributes, streams) != std::tie(rhs.groupId, rhs.name, rhs.audioAttributes, rhs.streams);
  }
  inline bool operator<(const AudioVolumeGroup& rhs) const {
    return std::tie(groupId, name, audioAttributes, streams) < std::tie(rhs.groupId, rhs.name, rhs.audioAttributes, rhs.streams);
  }
  inline bool operator<=(const AudioVolumeGroup& rhs) const {
    return std::tie(groupId, name, audioAttributes, streams) <= std::tie(rhs.groupId, rhs.name, rhs.audioAttributes, rhs.streams);
  }
  inline bool operator==(const AudioVolumeGroup& rhs) const {
    return std::tie(groupId, name, audioAttributes, streams) == std::tie(rhs.groupId, rhs.name, rhs.audioAttributes, rhs.streams);
  }
  inline bool operator>(const AudioVolumeGroup& rhs) const {
    return std::tie(groupId, name, audioAttributes, streams) > std::tie(rhs.groupId, rhs.name, rhs.audioAttributes, rhs.streams);
  }
  inline bool operator>=(const AudioVolumeGroup& rhs) const {
    return std::tie(groupId, name, audioAttributes, streams) >= std::tie(rhs.groupId, rhs.name, rhs.audioAttributes, rhs.streams);
  }

  int32_t groupId = int32_t(0);
  ::std::string name;
  ::std::vector<::android::media::AudioAttributesInternal> audioAttributes;
  ::std::vector<::android::media::AudioStreamType> streams;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioVolumeGroup");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioVolumeGroup{";
    os << "groupId: " << ::android::internal::ToString(groupId);
    os << ", name: " << ::android::internal::ToString(name);
    os << ", audioAttributes: " << ::android::internal::ToString(audioAttributes);
    os << ", streams: " << ::android::internal::ToString(streams);
    os << "}";
    return os.str();
  }
};  // class AudioVolumeGroup

}  // namespace media

}  // namespace android
