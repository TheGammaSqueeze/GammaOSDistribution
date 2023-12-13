#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace media {

class TrackSecondaryOutputInfo : public ::android::Parcelable {
public:
  inline bool operator!=(const TrackSecondaryOutputInfo& rhs) const {
    return std::tie(portId, secondaryOutputIds) != std::tie(rhs.portId, rhs.secondaryOutputIds);
  }
  inline bool operator<(const TrackSecondaryOutputInfo& rhs) const {
    return std::tie(portId, secondaryOutputIds) < std::tie(rhs.portId, rhs.secondaryOutputIds);
  }
  inline bool operator<=(const TrackSecondaryOutputInfo& rhs) const {
    return std::tie(portId, secondaryOutputIds) <= std::tie(rhs.portId, rhs.secondaryOutputIds);
  }
  inline bool operator==(const TrackSecondaryOutputInfo& rhs) const {
    return std::tie(portId, secondaryOutputIds) == std::tie(rhs.portId, rhs.secondaryOutputIds);
  }
  inline bool operator>(const TrackSecondaryOutputInfo& rhs) const {
    return std::tie(portId, secondaryOutputIds) > std::tie(rhs.portId, rhs.secondaryOutputIds);
  }
  inline bool operator>=(const TrackSecondaryOutputInfo& rhs) const {
    return std::tie(portId, secondaryOutputIds) >= std::tie(rhs.portId, rhs.secondaryOutputIds);
  }

  int32_t portId = int32_t(0);
  ::std::vector<int32_t> secondaryOutputIds;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.TrackSecondaryOutputInfo");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "TrackSecondaryOutputInfo{";
    os << "portId: " << ::android::internal::ToString(portId);
    os << ", secondaryOutputIds: " << ::android::internal::ToString(secondaryOutputIds);
    os << "}";
    return os.str();
  }
};  // class TrackSecondaryOutputInfo

}  // namespace media

}  // namespace android
