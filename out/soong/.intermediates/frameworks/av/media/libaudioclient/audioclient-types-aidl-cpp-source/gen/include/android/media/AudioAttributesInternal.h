#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioContentType.h>
#include <android/media/AudioSourceType.h>
#include <android/media/AudioUsage.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class AudioAttributesInternal : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioAttributesInternal& rhs) const {
    return std::tie(contentType, usage, source, flags, tags) != std::tie(rhs.contentType, rhs.usage, rhs.source, rhs.flags, rhs.tags);
  }
  inline bool operator<(const AudioAttributesInternal& rhs) const {
    return std::tie(contentType, usage, source, flags, tags) < std::tie(rhs.contentType, rhs.usage, rhs.source, rhs.flags, rhs.tags);
  }
  inline bool operator<=(const AudioAttributesInternal& rhs) const {
    return std::tie(contentType, usage, source, flags, tags) <= std::tie(rhs.contentType, rhs.usage, rhs.source, rhs.flags, rhs.tags);
  }
  inline bool operator==(const AudioAttributesInternal& rhs) const {
    return std::tie(contentType, usage, source, flags, tags) == std::tie(rhs.contentType, rhs.usage, rhs.source, rhs.flags, rhs.tags);
  }
  inline bool operator>(const AudioAttributesInternal& rhs) const {
    return std::tie(contentType, usage, source, flags, tags) > std::tie(rhs.contentType, rhs.usage, rhs.source, rhs.flags, rhs.tags);
  }
  inline bool operator>=(const AudioAttributesInternal& rhs) const {
    return std::tie(contentType, usage, source, flags, tags) >= std::tie(rhs.contentType, rhs.usage, rhs.source, rhs.flags, rhs.tags);
  }

  ::android::media::AudioContentType contentType = ::android::media::AudioContentType(0);
  ::android::media::AudioUsage usage = ::android::media::AudioUsage(0);
  ::android::media::AudioSourceType source = ::android::media::AudioSourceType(0);
  int32_t flags = int32_t(0);
  ::std::string tags;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioAttributesInternal");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioAttributesInternal{";
    os << "contentType: " << ::android::internal::ToString(contentType);
    os << ", usage: " << ::android::internal::ToString(usage);
    os << ", source: " << ::android::internal::ToString(source);
    os << ", flags: " << ::android::internal::ToString(flags);
    os << ", tags: " << ::android::internal::ToString(tags);
    os << "}";
    return os.str();
  }
};  // class AudioAttributesInternal

}  // namespace media

}  // namespace android
