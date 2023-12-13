#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace net {

class RouteInfoParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const RouteInfoParcel& rhs) const {
    return std::tie(destination, ifName, nextHop, mtu) != std::tie(rhs.destination, rhs.ifName, rhs.nextHop, rhs.mtu);
  }
  inline bool operator<(const RouteInfoParcel& rhs) const {
    return std::tie(destination, ifName, nextHop, mtu) < std::tie(rhs.destination, rhs.ifName, rhs.nextHop, rhs.mtu);
  }
  inline bool operator<=(const RouteInfoParcel& rhs) const {
    return std::tie(destination, ifName, nextHop, mtu) <= std::tie(rhs.destination, rhs.ifName, rhs.nextHop, rhs.mtu);
  }
  inline bool operator==(const RouteInfoParcel& rhs) const {
    return std::tie(destination, ifName, nextHop, mtu) == std::tie(rhs.destination, rhs.ifName, rhs.nextHop, rhs.mtu);
  }
  inline bool operator>(const RouteInfoParcel& rhs) const {
    return std::tie(destination, ifName, nextHop, mtu) > std::tie(rhs.destination, rhs.ifName, rhs.nextHop, rhs.mtu);
  }
  inline bool operator>=(const RouteInfoParcel& rhs) const {
    return std::tie(destination, ifName, nextHop, mtu) >= std::tie(rhs.destination, rhs.ifName, rhs.nextHop, rhs.mtu);
  }

  ::std::string destination;
  ::std::string ifName;
  ::std::string nextHop;
  int32_t mtu = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.net.RouteInfoParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "RouteInfoParcel{";
    os << "destination: " << ::android::internal::ToString(destination);
    os << ", ifName: " << ::android::internal::ToString(ifName);
    os << ", nextHop: " << ::android::internal::ToString(nextHop);
    os << ", mtu: " << ::android::internal::ToString(mtu);
    os << "}";
    return os.str();
  }
};  // class RouteInfoParcel

}  // namespace net

}  // namespace android
