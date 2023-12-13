#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class AudioTimestampInternal : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioTimestampInternal& rhs) const {
    return std::tie(position, sec, nsec) != std::tie(rhs.position, rhs.sec, rhs.nsec);
  }
  inline bool operator<(const AudioTimestampInternal& rhs) const {
    return std::tie(position, sec, nsec) < std::tie(rhs.position, rhs.sec, rhs.nsec);
  }
  inline bool operator<=(const AudioTimestampInternal& rhs) const {
    return std::tie(position, sec, nsec) <= std::tie(rhs.position, rhs.sec, rhs.nsec);
  }
  inline bool operator==(const AudioTimestampInternal& rhs) const {
    return std::tie(position, sec, nsec) == std::tie(rhs.position, rhs.sec, rhs.nsec);
  }
  inline bool operator>(const AudioTimestampInternal& rhs) const {
    return std::tie(position, sec, nsec) > std::tie(rhs.position, rhs.sec, rhs.nsec);
  }
  inline bool operator>=(const AudioTimestampInternal& rhs) const {
    return std::tie(position, sec, nsec) >= std::tie(rhs.position, rhs.sec, rhs.nsec);
  }

  int32_t position = int32_t(0);
  int64_t sec = int64_t(0L);
  int32_t nsec = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioTimestampInternal");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioTimestampInternal{";
    os << "position: " << ::android::internal::ToString(position);
    os << ", sec: " << ::android::internal::ToString(sec);
    os << ", nsec: " << ::android::internal::ToString(nsec);
    os << "}";
    return os.str();
  }
};  // class AudioTimestampInternal

}  // namespace media

}  // namespace android
