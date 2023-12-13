#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioPortConfig.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace media {

class AudioPatch : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioPatch& rhs) const {
    return std::tie(id, sources, sinks) != std::tie(rhs.id, rhs.sources, rhs.sinks);
  }
  inline bool operator<(const AudioPatch& rhs) const {
    return std::tie(id, sources, sinks) < std::tie(rhs.id, rhs.sources, rhs.sinks);
  }
  inline bool operator<=(const AudioPatch& rhs) const {
    return std::tie(id, sources, sinks) <= std::tie(rhs.id, rhs.sources, rhs.sinks);
  }
  inline bool operator==(const AudioPatch& rhs) const {
    return std::tie(id, sources, sinks) == std::tie(rhs.id, rhs.sources, rhs.sinks);
  }
  inline bool operator>(const AudioPatch& rhs) const {
    return std::tie(id, sources, sinks) > std::tie(rhs.id, rhs.sources, rhs.sinks);
  }
  inline bool operator>=(const AudioPatch& rhs) const {
    return std::tie(id, sources, sinks) >= std::tie(rhs.id, rhs.sources, rhs.sinks);
  }

  int32_t id = int32_t(0);
  ::std::vector<::android::media::AudioPortConfig> sources;
  ::std::vector<::android::media::AudioPortConfig> sinks;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioPatch");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioPatch{";
    os << "id: " << ::android::internal::ToString(id);
    os << ", sources: " << ::android::internal::ToString(sources);
    os << ", sinks: " << ::android::internal::ToString(sinks);
    os << "}";
    return os.str();
  }
};  // class AudioPatch

}  // namespace media

}  // namespace android
