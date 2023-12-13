#pragma once

#include <android/binder_to_string.h>
#include <android/net/NativeNetworkType.h>
#include <android/net/NativeVpnType.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace net {

class NativeNetworkConfig : public ::android::Parcelable {
public:
  inline bool operator!=(const NativeNetworkConfig& rhs) const {
    return std::tie(netId, networkType, permission, secure, vpnType) != std::tie(rhs.netId, rhs.networkType, rhs.permission, rhs.secure, rhs.vpnType);
  }
  inline bool operator<(const NativeNetworkConfig& rhs) const {
    return std::tie(netId, networkType, permission, secure, vpnType) < std::tie(rhs.netId, rhs.networkType, rhs.permission, rhs.secure, rhs.vpnType);
  }
  inline bool operator<=(const NativeNetworkConfig& rhs) const {
    return std::tie(netId, networkType, permission, secure, vpnType) <= std::tie(rhs.netId, rhs.networkType, rhs.permission, rhs.secure, rhs.vpnType);
  }
  inline bool operator==(const NativeNetworkConfig& rhs) const {
    return std::tie(netId, networkType, permission, secure, vpnType) == std::tie(rhs.netId, rhs.networkType, rhs.permission, rhs.secure, rhs.vpnType);
  }
  inline bool operator>(const NativeNetworkConfig& rhs) const {
    return std::tie(netId, networkType, permission, secure, vpnType) > std::tie(rhs.netId, rhs.networkType, rhs.permission, rhs.secure, rhs.vpnType);
  }
  inline bool operator>=(const NativeNetworkConfig& rhs) const {
    return std::tie(netId, networkType, permission, secure, vpnType) >= std::tie(rhs.netId, rhs.networkType, rhs.permission, rhs.secure, rhs.vpnType);
  }

  int32_t netId = int32_t(0);
  ::android::net::NativeNetworkType networkType = ::android::net::NativeNetworkType(::android::net::NativeNetworkType::PHYSICAL);
  int32_t permission = int32_t(0);
  bool secure = bool(false);
  ::android::net::NativeVpnType vpnType = ::android::net::NativeVpnType(::android::net::NativeVpnType::PLATFORM);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.net.NativeNetworkConfig");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "NativeNetworkConfig{";
    os << "netId: " << ::android::internal::ToString(netId);
    os << ", networkType: " << ::android::internal::ToString(networkType);
    os << ", permission: " << ::android::internal::ToString(permission);
    os << ", secure: " << ::android::internal::ToString(secure);
    os << ", vpnType: " << ::android::internal::ToString(vpnType);
    os << "}";
    return os.str();
  }
};  // class NativeNetworkConfig

}  // namespace net

}  // namespace android
