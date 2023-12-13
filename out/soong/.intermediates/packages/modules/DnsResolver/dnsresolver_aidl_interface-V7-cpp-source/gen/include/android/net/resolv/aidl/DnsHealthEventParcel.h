#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace net {

namespace resolv {

namespace aidl {

class DnsHealthEventParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const DnsHealthEventParcel& rhs) const {
    return std::tie(netId, healthResult, successRttMicros) != std::tie(rhs.netId, rhs.healthResult, rhs.successRttMicros);
  }
  inline bool operator<(const DnsHealthEventParcel& rhs) const {
    return std::tie(netId, healthResult, successRttMicros) < std::tie(rhs.netId, rhs.healthResult, rhs.successRttMicros);
  }
  inline bool operator<=(const DnsHealthEventParcel& rhs) const {
    return std::tie(netId, healthResult, successRttMicros) <= std::tie(rhs.netId, rhs.healthResult, rhs.successRttMicros);
  }
  inline bool operator==(const DnsHealthEventParcel& rhs) const {
    return std::tie(netId, healthResult, successRttMicros) == std::tie(rhs.netId, rhs.healthResult, rhs.successRttMicros);
  }
  inline bool operator>(const DnsHealthEventParcel& rhs) const {
    return std::tie(netId, healthResult, successRttMicros) > std::tie(rhs.netId, rhs.healthResult, rhs.successRttMicros);
  }
  inline bool operator>=(const DnsHealthEventParcel& rhs) const {
    return std::tie(netId, healthResult, successRttMicros) >= std::tie(rhs.netId, rhs.healthResult, rhs.successRttMicros);
  }

  int32_t netId = int32_t(0);
  int32_t healthResult = int32_t(0);
  ::std::vector<int32_t> successRttMicros;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.net.resolv.aidl.DnsHealthEventParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "DnsHealthEventParcel{";
    os << "netId: " << ::android::internal::ToString(netId);
    os << ", healthResult: " << ::android::internal::ToString(healthResult);
    os << ", successRttMicros: " << ::android::internal::ToString(successRttMicros);
    os << "}";
    return os.str();
  }
};  // class DnsHealthEventParcel

}  // namespace aidl

}  // namespace resolv

}  // namespace net

}  // namespace android
