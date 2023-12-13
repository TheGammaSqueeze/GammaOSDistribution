#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace net {

class ResolverHostsParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const ResolverHostsParcel& rhs) const {
    return std::tie(ipAddr, hostName) != std::tie(rhs.ipAddr, rhs.hostName);
  }
  inline bool operator<(const ResolverHostsParcel& rhs) const {
    return std::tie(ipAddr, hostName) < std::tie(rhs.ipAddr, rhs.hostName);
  }
  inline bool operator<=(const ResolverHostsParcel& rhs) const {
    return std::tie(ipAddr, hostName) <= std::tie(rhs.ipAddr, rhs.hostName);
  }
  inline bool operator==(const ResolverHostsParcel& rhs) const {
    return std::tie(ipAddr, hostName) == std::tie(rhs.ipAddr, rhs.hostName);
  }
  inline bool operator>(const ResolverHostsParcel& rhs) const {
    return std::tie(ipAddr, hostName) > std::tie(rhs.ipAddr, rhs.hostName);
  }
  inline bool operator>=(const ResolverHostsParcel& rhs) const {
    return std::tie(ipAddr, hostName) >= std::tie(rhs.ipAddr, rhs.hostName);
  }

  ::std::string ipAddr;
  ::std::string hostName = ::std::string("");
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.net.ResolverHostsParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "ResolverHostsParcel{";
    os << "ipAddr: " << ::android::internal::ToString(ipAddr);
    os << ", hostName: " << ::android::internal::ToString(hostName);
    os << "}";
    return os.str();
  }
};  // class ResolverHostsParcel

}  // namespace net

}  // namespace android
