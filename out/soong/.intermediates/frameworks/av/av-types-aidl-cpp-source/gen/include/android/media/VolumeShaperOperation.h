#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class VolumeShaperOperation : public ::android::Parcelable {
public:
  inline bool operator!=(const VolumeShaperOperation& rhs) const {
    return std::tie(flags, replaceId, xOffset) != std::tie(rhs.flags, rhs.replaceId, rhs.xOffset);
  }
  inline bool operator<(const VolumeShaperOperation& rhs) const {
    return std::tie(flags, replaceId, xOffset) < std::tie(rhs.flags, rhs.replaceId, rhs.xOffset);
  }
  inline bool operator<=(const VolumeShaperOperation& rhs) const {
    return std::tie(flags, replaceId, xOffset) <= std::tie(rhs.flags, rhs.replaceId, rhs.xOffset);
  }
  inline bool operator==(const VolumeShaperOperation& rhs) const {
    return std::tie(flags, replaceId, xOffset) == std::tie(rhs.flags, rhs.replaceId, rhs.xOffset);
  }
  inline bool operator>(const VolumeShaperOperation& rhs) const {
    return std::tie(flags, replaceId, xOffset) > std::tie(rhs.flags, rhs.replaceId, rhs.xOffset);
  }
  inline bool operator>=(const VolumeShaperOperation& rhs) const {
    return std::tie(flags, replaceId, xOffset) >= std::tie(rhs.flags, rhs.replaceId, rhs.xOffset);
  }

  int32_t flags = int32_t(0);
  int32_t replaceId = int32_t(0);
  float xOffset = float(0.000000f);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.VolumeShaperOperation");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "VolumeShaperOperation{";
    os << "flags: " << ::android::internal::ToString(flags);
    os << ", replaceId: " << ::android::internal::ToString(replaceId);
    os << ", xOffset: " << ::android::internal::ToString(xOffset);
    os << "}";
    return os.str();
  }
};  // class VolumeShaperOperation

}  // namespace media

}  // namespace android
