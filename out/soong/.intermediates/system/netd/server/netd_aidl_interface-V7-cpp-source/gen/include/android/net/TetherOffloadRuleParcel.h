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

class TetherOffloadRuleParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const TetherOffloadRuleParcel& rhs) const {
    return std::tie(inputInterfaceIndex, outputInterfaceIndex, destination, prefixLength, srcL2Address, dstL2Address, pmtu) != std::tie(rhs.inputInterfaceIndex, rhs.outputInterfaceIndex, rhs.destination, rhs.prefixLength, rhs.srcL2Address, rhs.dstL2Address, rhs.pmtu);
  }
  inline bool operator<(const TetherOffloadRuleParcel& rhs) const {
    return std::tie(inputInterfaceIndex, outputInterfaceIndex, destination, prefixLength, srcL2Address, dstL2Address, pmtu) < std::tie(rhs.inputInterfaceIndex, rhs.outputInterfaceIndex, rhs.destination, rhs.prefixLength, rhs.srcL2Address, rhs.dstL2Address, rhs.pmtu);
  }
  inline bool operator<=(const TetherOffloadRuleParcel& rhs) const {
    return std::tie(inputInterfaceIndex, outputInterfaceIndex, destination, prefixLength, srcL2Address, dstL2Address, pmtu) <= std::tie(rhs.inputInterfaceIndex, rhs.outputInterfaceIndex, rhs.destination, rhs.prefixLength, rhs.srcL2Address, rhs.dstL2Address, rhs.pmtu);
  }
  inline bool operator==(const TetherOffloadRuleParcel& rhs) const {
    return std::tie(inputInterfaceIndex, outputInterfaceIndex, destination, prefixLength, srcL2Address, dstL2Address, pmtu) == std::tie(rhs.inputInterfaceIndex, rhs.outputInterfaceIndex, rhs.destination, rhs.prefixLength, rhs.srcL2Address, rhs.dstL2Address, rhs.pmtu);
  }
  inline bool operator>(const TetherOffloadRuleParcel& rhs) const {
    return std::tie(inputInterfaceIndex, outputInterfaceIndex, destination, prefixLength, srcL2Address, dstL2Address, pmtu) > std::tie(rhs.inputInterfaceIndex, rhs.outputInterfaceIndex, rhs.destination, rhs.prefixLength, rhs.srcL2Address, rhs.dstL2Address, rhs.pmtu);
  }
  inline bool operator>=(const TetherOffloadRuleParcel& rhs) const {
    return std::tie(inputInterfaceIndex, outputInterfaceIndex, destination, prefixLength, srcL2Address, dstL2Address, pmtu) >= std::tie(rhs.inputInterfaceIndex, rhs.outputInterfaceIndex, rhs.destination, rhs.prefixLength, rhs.srcL2Address, rhs.dstL2Address, rhs.pmtu);
  }

  int32_t inputInterfaceIndex = int32_t(0);
  int32_t outputInterfaceIndex = int32_t(0);
  ::std::vector<uint8_t> destination;
  int32_t prefixLength = int32_t(0);
  ::std::vector<uint8_t> srcL2Address;
  ::std::vector<uint8_t> dstL2Address;
  int32_t pmtu = int32_t(1500);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.net.TetherOffloadRuleParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "TetherOffloadRuleParcel{";
    os << "inputInterfaceIndex: " << ::android::internal::ToString(inputInterfaceIndex);
    os << ", outputInterfaceIndex: " << ::android::internal::ToString(outputInterfaceIndex);
    os << ", destination: " << ::android::internal::ToString(destination);
    os << ", prefixLength: " << ::android::internal::ToString(prefixLength);
    os << ", srcL2Address: " << ::android::internal::ToString(srcL2Address);
    os << ", dstL2Address: " << ::android::internal::ToString(dstL2Address);
    os << ", pmtu: " << ::android::internal::ToString(pmtu);
    os << "}";
    return os.str();
  }
};  // class TetherOffloadRuleParcel

}  // namespace net

}  // namespace android
