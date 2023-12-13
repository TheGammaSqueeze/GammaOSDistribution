#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioMixLatencyClass.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class AudioPortMixExt : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioPortMixExt& rhs) const {
    return std::tie(hwModule, handle, latencyClass) != std::tie(rhs.hwModule, rhs.handle, rhs.latencyClass);
  }
  inline bool operator<(const AudioPortMixExt& rhs) const {
    return std::tie(hwModule, handle, latencyClass) < std::tie(rhs.hwModule, rhs.handle, rhs.latencyClass);
  }
  inline bool operator<=(const AudioPortMixExt& rhs) const {
    return std::tie(hwModule, handle, latencyClass) <= std::tie(rhs.hwModule, rhs.handle, rhs.latencyClass);
  }
  inline bool operator==(const AudioPortMixExt& rhs) const {
    return std::tie(hwModule, handle, latencyClass) == std::tie(rhs.hwModule, rhs.handle, rhs.latencyClass);
  }
  inline bool operator>(const AudioPortMixExt& rhs) const {
    return std::tie(hwModule, handle, latencyClass) > std::tie(rhs.hwModule, rhs.handle, rhs.latencyClass);
  }
  inline bool operator>=(const AudioPortMixExt& rhs) const {
    return std::tie(hwModule, handle, latencyClass) >= std::tie(rhs.hwModule, rhs.handle, rhs.latencyClass);
  }

  int32_t hwModule = int32_t(0);
  int32_t handle = int32_t(0);
  ::android::media::AudioMixLatencyClass latencyClass = ::android::media::AudioMixLatencyClass(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioPortMixExt");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioPortMixExt{";
    os << "hwModule: " << ::android::internal::ToString(hwModule);
    os << ", handle: " << ::android::internal::ToString(handle);
    os << ", latencyClass: " << ::android::internal::ToString(latencyClass);
    os << "}";
    return os.str();
  }
};  // class AudioPortMixExt

}  // namespace media

}  // namespace android
