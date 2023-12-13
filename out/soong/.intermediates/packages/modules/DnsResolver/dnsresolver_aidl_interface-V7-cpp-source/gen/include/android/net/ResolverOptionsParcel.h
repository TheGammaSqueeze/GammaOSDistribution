#pragma once

#include <android/binder_to_string.h>
#include <android/net/ResolverHostsParcel.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace net {

class ResolverOptionsParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const ResolverOptionsParcel& rhs) const {
    return std::tie(hosts, tcMode, enforceDnsUid) != std::tie(rhs.hosts, rhs.tcMode, rhs.enforceDnsUid);
  }
  inline bool operator<(const ResolverOptionsParcel& rhs) const {
    return std::tie(hosts, tcMode, enforceDnsUid) < std::tie(rhs.hosts, rhs.tcMode, rhs.enforceDnsUid);
  }
  inline bool operator<=(const ResolverOptionsParcel& rhs) const {
    return std::tie(hosts, tcMode, enforceDnsUid) <= std::tie(rhs.hosts, rhs.tcMode, rhs.enforceDnsUid);
  }
  inline bool operator==(const ResolverOptionsParcel& rhs) const {
    return std::tie(hosts, tcMode, enforceDnsUid) == std::tie(rhs.hosts, rhs.tcMode, rhs.enforceDnsUid);
  }
  inline bool operator>(const ResolverOptionsParcel& rhs) const {
    return std::tie(hosts, tcMode, enforceDnsUid) > std::tie(rhs.hosts, rhs.tcMode, rhs.enforceDnsUid);
  }
  inline bool operator>=(const ResolverOptionsParcel& rhs) const {
    return std::tie(hosts, tcMode, enforceDnsUid) >= std::tie(rhs.hosts, rhs.tcMode, rhs.enforceDnsUid);
  }

  ::std::vector<::android::net::ResolverHostsParcel> hosts = ::std::vector<::android::net::ResolverHostsParcel>({});
  int32_t tcMode = int32_t(0);
  bool enforceDnsUid = bool(false);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.net.ResolverOptionsParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "ResolverOptionsParcel{";
    os << "hosts: " << ::android::internal::ToString(hosts);
    os << ", tcMode: " << ::android::internal::ToString(tcMode);
    os << ", enforceDnsUid: " << ::android::internal::ToString(enforceDnsUid);
    os << "}";
    return os.str();
  }
};  // class ResolverOptionsParcel

}  // namespace net

}  // namespace android
