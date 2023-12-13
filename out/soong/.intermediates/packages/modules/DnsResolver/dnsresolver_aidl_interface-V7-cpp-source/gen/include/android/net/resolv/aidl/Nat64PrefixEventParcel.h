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

namespace resolv {

namespace aidl {

class Nat64PrefixEventParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const Nat64PrefixEventParcel& rhs) const {
    return std::tie(netId, prefixOperation, prefixAddress, prefixLength) != std::tie(rhs.netId, rhs.prefixOperation, rhs.prefixAddress, rhs.prefixLength);
  }
  inline bool operator<(const Nat64PrefixEventParcel& rhs) const {
    return std::tie(netId, prefixOperation, prefixAddress, prefixLength) < std::tie(rhs.netId, rhs.prefixOperation, rhs.prefixAddress, rhs.prefixLength);
  }
  inline bool operator<=(const Nat64PrefixEventParcel& rhs) const {
    return std::tie(netId, prefixOperation, prefixAddress, prefixLength) <= std::tie(rhs.netId, rhs.prefixOperation, rhs.prefixAddress, rhs.prefixLength);
  }
  inline bool operator==(const Nat64PrefixEventParcel& rhs) const {
    return std::tie(netId, prefixOperation, prefixAddress, prefixLength) == std::tie(rhs.netId, rhs.prefixOperation, rhs.prefixAddress, rhs.prefixLength);
  }
  inline bool operator>(const Nat64PrefixEventParcel& rhs) const {
    return std::tie(netId, prefixOperation, prefixAddress, prefixLength) > std::tie(rhs.netId, rhs.prefixOperation, rhs.prefixAddress, rhs.prefixLength);
  }
  inline bool operator>=(const Nat64PrefixEventParcel& rhs) const {
    return std::tie(netId, prefixOperation, prefixAddress, prefixLength) >= std::tie(rhs.netId, rhs.prefixOperation, rhs.prefixAddress, rhs.prefixLength);
  }

  int32_t netId = int32_t(0);
  int32_t prefixOperation = int32_t(0);
  ::std::string prefixAddress;
  int32_t prefixLength = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.net.resolv.aidl.Nat64PrefixEventParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "Nat64PrefixEventParcel{";
    os << "netId: " << ::android::internal::ToString(netId);
    os << ", prefixOperation: " << ::android::internal::ToString(prefixOperation);
    os << ", prefixAddress: " << ::android::internal::ToString(prefixAddress);
    os << ", prefixLength: " << ::android::internal::ToString(prefixLength);
    os << "}";
    return os.str();
  }
};  // class Nat64PrefixEventParcel

}  // namespace aidl

}  // namespace resolv

}  // namespace net

}  // namespace android
