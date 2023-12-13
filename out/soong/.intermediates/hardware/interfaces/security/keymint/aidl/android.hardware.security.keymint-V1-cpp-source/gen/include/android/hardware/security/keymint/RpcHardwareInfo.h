#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

class RpcHardwareInfo : public ::android::Parcelable {
public:
  inline bool operator!=(const RpcHardwareInfo& rhs) const {
    return std::tie(versionNumber, rpcAuthorName, supportedEekCurve) != std::tie(rhs.versionNumber, rhs.rpcAuthorName, rhs.supportedEekCurve);
  }
  inline bool operator<(const RpcHardwareInfo& rhs) const {
    return std::tie(versionNumber, rpcAuthorName, supportedEekCurve) < std::tie(rhs.versionNumber, rhs.rpcAuthorName, rhs.supportedEekCurve);
  }
  inline bool operator<=(const RpcHardwareInfo& rhs) const {
    return std::tie(versionNumber, rpcAuthorName, supportedEekCurve) <= std::tie(rhs.versionNumber, rhs.rpcAuthorName, rhs.supportedEekCurve);
  }
  inline bool operator==(const RpcHardwareInfo& rhs) const {
    return std::tie(versionNumber, rpcAuthorName, supportedEekCurve) == std::tie(rhs.versionNumber, rhs.rpcAuthorName, rhs.supportedEekCurve);
  }
  inline bool operator>(const RpcHardwareInfo& rhs) const {
    return std::tie(versionNumber, rpcAuthorName, supportedEekCurve) > std::tie(rhs.versionNumber, rhs.rpcAuthorName, rhs.supportedEekCurve);
  }
  inline bool operator>=(const RpcHardwareInfo& rhs) const {
    return std::tie(versionNumber, rpcAuthorName, supportedEekCurve) >= std::tie(rhs.versionNumber, rhs.rpcAuthorName, rhs.supportedEekCurve);
  }

  int32_t versionNumber = int32_t(0);
  ::std::string rpcAuthorName;
  int32_t supportedEekCurve = int32_t(0);
  enum  : int32_t {
    CURVE_NONE = 0,
    CURVE_P256 = 1,
    CURVE_25519 = 2,
  };
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.security.keymint.RpcHardwareInfo");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "RpcHardwareInfo{";
    os << "versionNumber: " << ::android::internal::ToString(versionNumber);
    os << ", rpcAuthorName: " << ::android::internal::ToString(rpcAuthorName);
    os << ", supportedEekCurve: " << ::android::internal::ToString(supportedEekCurve);
    os << "}";
    return os.str();
  }
};  // class RpcHardwareInfo

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
