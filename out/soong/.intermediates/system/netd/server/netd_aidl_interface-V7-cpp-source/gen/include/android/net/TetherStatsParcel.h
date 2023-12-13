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

class TetherStatsParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const TetherStatsParcel& rhs) const {
    return std::tie(iface, rxBytes, rxPackets, txBytes, txPackets, ifIndex) != std::tie(rhs.iface, rhs.rxBytes, rhs.rxPackets, rhs.txBytes, rhs.txPackets, rhs.ifIndex);
  }
  inline bool operator<(const TetherStatsParcel& rhs) const {
    return std::tie(iface, rxBytes, rxPackets, txBytes, txPackets, ifIndex) < std::tie(rhs.iface, rhs.rxBytes, rhs.rxPackets, rhs.txBytes, rhs.txPackets, rhs.ifIndex);
  }
  inline bool operator<=(const TetherStatsParcel& rhs) const {
    return std::tie(iface, rxBytes, rxPackets, txBytes, txPackets, ifIndex) <= std::tie(rhs.iface, rhs.rxBytes, rhs.rxPackets, rhs.txBytes, rhs.txPackets, rhs.ifIndex);
  }
  inline bool operator==(const TetherStatsParcel& rhs) const {
    return std::tie(iface, rxBytes, rxPackets, txBytes, txPackets, ifIndex) == std::tie(rhs.iface, rhs.rxBytes, rhs.rxPackets, rhs.txBytes, rhs.txPackets, rhs.ifIndex);
  }
  inline bool operator>(const TetherStatsParcel& rhs) const {
    return std::tie(iface, rxBytes, rxPackets, txBytes, txPackets, ifIndex) > std::tie(rhs.iface, rhs.rxBytes, rhs.rxPackets, rhs.txBytes, rhs.txPackets, rhs.ifIndex);
  }
  inline bool operator>=(const TetherStatsParcel& rhs) const {
    return std::tie(iface, rxBytes, rxPackets, txBytes, txPackets, ifIndex) >= std::tie(rhs.iface, rhs.rxBytes, rhs.rxPackets, rhs.txBytes, rhs.txPackets, rhs.ifIndex);
  }

  ::std::string iface;
  int64_t rxBytes = int64_t(0L);
  int64_t rxPackets = int64_t(0L);
  int64_t txBytes = int64_t(0L);
  int64_t txPackets = int64_t(0L);
  int32_t ifIndex = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.net.TetherStatsParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "TetherStatsParcel{";
    os << "iface: " << ::android::internal::ToString(iface);
    os << ", rxBytes: " << ::android::internal::ToString(rxBytes);
    os << ", rxPackets: " << ::android::internal::ToString(rxPackets);
    os << ", txBytes: " << ::android::internal::ToString(txBytes);
    os << ", txPackets: " << ::android::internal::ToString(txPackets);
    os << ", ifIndex: " << ::android::internal::ToString(ifIndex);
    os << "}";
    return os.str();
  }
};  // class TetherStatsParcel

}  // namespace net

}  // namespace android
