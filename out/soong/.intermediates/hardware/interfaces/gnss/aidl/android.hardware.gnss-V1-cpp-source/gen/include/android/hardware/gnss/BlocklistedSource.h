#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/gnss/GnssConstellationType.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace hardware {

namespace gnss {

class BlocklistedSource : public ::android::Parcelable {
public:
  inline bool operator!=(const BlocklistedSource& rhs) const {
    return std::tie(constellation, svid) != std::tie(rhs.constellation, rhs.svid);
  }
  inline bool operator<(const BlocklistedSource& rhs) const {
    return std::tie(constellation, svid) < std::tie(rhs.constellation, rhs.svid);
  }
  inline bool operator<=(const BlocklistedSource& rhs) const {
    return std::tie(constellation, svid) <= std::tie(rhs.constellation, rhs.svid);
  }
  inline bool operator==(const BlocklistedSource& rhs) const {
    return std::tie(constellation, svid) == std::tie(rhs.constellation, rhs.svid);
  }
  inline bool operator>(const BlocklistedSource& rhs) const {
    return std::tie(constellation, svid) > std::tie(rhs.constellation, rhs.svid);
  }
  inline bool operator>=(const BlocklistedSource& rhs) const {
    return std::tie(constellation, svid) >= std::tie(rhs.constellation, rhs.svid);
  }

  ::android::hardware::gnss::GnssConstellationType constellation = ::android::hardware::gnss::GnssConstellationType(::android::hardware::gnss::GnssConstellationType::UNKNOWN);
  int32_t svid = int32_t(0);
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.gnss.BlocklistedSource");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "BlocklistedSource{";
    os << "constellation: " << ::android::internal::ToString(constellation);
    os << ", svid: " << ::android::internal::ToString(svid);
    os << "}";
    return os.str();
  }
};  // class BlocklistedSource

}  // namespace gnss

}  // namespace hardware

}  // namespace android
