#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <string>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace net {

class TetherConfigParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const TetherConfigParcel& rhs) const {
    return std::tie(usingLegacyDnsProxy, dhcpRanges) != std::tie(rhs.usingLegacyDnsProxy, rhs.dhcpRanges);
  }
  inline bool operator<(const TetherConfigParcel& rhs) const {
    return std::tie(usingLegacyDnsProxy, dhcpRanges) < std::tie(rhs.usingLegacyDnsProxy, rhs.dhcpRanges);
  }
  inline bool operator<=(const TetherConfigParcel& rhs) const {
    return std::tie(usingLegacyDnsProxy, dhcpRanges) <= std::tie(rhs.usingLegacyDnsProxy, rhs.dhcpRanges);
  }
  inline bool operator==(const TetherConfigParcel& rhs) const {
    return std::tie(usingLegacyDnsProxy, dhcpRanges) == std::tie(rhs.usingLegacyDnsProxy, rhs.dhcpRanges);
  }
  inline bool operator>(const TetherConfigParcel& rhs) const {
    return std::tie(usingLegacyDnsProxy, dhcpRanges) > std::tie(rhs.usingLegacyDnsProxy, rhs.dhcpRanges);
  }
  inline bool operator>=(const TetherConfigParcel& rhs) const {
    return std::tie(usingLegacyDnsProxy, dhcpRanges) >= std::tie(rhs.usingLegacyDnsProxy, rhs.dhcpRanges);
  }

  bool usingLegacyDnsProxy = bool(false);
  ::std::vector<::std::string> dhcpRanges;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.net.TetherConfigParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "TetherConfigParcel{";
    os << "usingLegacyDnsProxy: " << ::android::internal::ToString(usingLegacyDnsProxy);
    os << ", dhcpRanges: " << ::android::internal::ToString(dhcpRanges);
    os << "}";
    return os.str();
  }
};  // class TetherConfigParcel

}  // namespace net

}  // namespace android
