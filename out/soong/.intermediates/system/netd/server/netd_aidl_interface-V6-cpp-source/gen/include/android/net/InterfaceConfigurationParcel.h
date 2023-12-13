#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace net {

class InterfaceConfigurationParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const InterfaceConfigurationParcel& rhs) const {
    return std::tie(ifName, hwAddr, ipv4Addr, prefixLength, flags) != std::tie(rhs.ifName, rhs.hwAddr, rhs.ipv4Addr, rhs.prefixLength, rhs.flags);
  }
  inline bool operator<(const InterfaceConfigurationParcel& rhs) const {
    return std::tie(ifName, hwAddr, ipv4Addr, prefixLength, flags) < std::tie(rhs.ifName, rhs.hwAddr, rhs.ipv4Addr, rhs.prefixLength, rhs.flags);
  }
  inline bool operator<=(const InterfaceConfigurationParcel& rhs) const {
    return std::tie(ifName, hwAddr, ipv4Addr, prefixLength, flags) <= std::tie(rhs.ifName, rhs.hwAddr, rhs.ipv4Addr, rhs.prefixLength, rhs.flags);
  }
  inline bool operator==(const InterfaceConfigurationParcel& rhs) const {
    return std::tie(ifName, hwAddr, ipv4Addr, prefixLength, flags) == std::tie(rhs.ifName, rhs.hwAddr, rhs.ipv4Addr, rhs.prefixLength, rhs.flags);
  }
  inline bool operator>(const InterfaceConfigurationParcel& rhs) const {
    return std::tie(ifName, hwAddr, ipv4Addr, prefixLength, flags) > std::tie(rhs.ifName, rhs.hwAddr, rhs.ipv4Addr, rhs.prefixLength, rhs.flags);
  }
  inline bool operator>=(const InterfaceConfigurationParcel& rhs) const {
    return std::tie(ifName, hwAddr, ipv4Addr, prefixLength, flags) >= std::tie(rhs.ifName, rhs.hwAddr, rhs.ipv4Addr, rhs.prefixLength, rhs.flags);
  }

  ::std::string ifName;
  ::std::string hwAddr;
  ::std::string ipv4Addr;
  int32_t prefixLength = int32_t(0);
  ::std::vector<::std::string> flags;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.net.InterfaceConfigurationParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "InterfaceConfigurationParcel{";
    os << "ifName: " << ::android::internal::ToString(ifName);
    os << ", hwAddr: " << ::android::internal::ToString(hwAddr);
    os << ", ipv4Addr: " << ::android::internal::ToString(ipv4Addr);
    os << ", prefixLength: " << ::android::internal::ToString(prefixLength);
    os << ", flags: " << ::android::internal::ToString(flags);
    os << "}";
    return os.str();
  }
};  // class InterfaceConfigurationParcel

}  // namespace net

}  // namespace android
