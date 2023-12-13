#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/gnss/GnssConstellationType.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace hardware {

namespace gnss {

class GnssSignalType : public ::android::Parcelable {
public:
  inline bool operator!=(const GnssSignalType& rhs) const {
    return std::tie(constellation, carrierFrequencyHz, codeType) != std::tie(rhs.constellation, rhs.carrierFrequencyHz, rhs.codeType);
  }
  inline bool operator<(const GnssSignalType& rhs) const {
    return std::tie(constellation, carrierFrequencyHz, codeType) < std::tie(rhs.constellation, rhs.carrierFrequencyHz, rhs.codeType);
  }
  inline bool operator<=(const GnssSignalType& rhs) const {
    return std::tie(constellation, carrierFrequencyHz, codeType) <= std::tie(rhs.constellation, rhs.carrierFrequencyHz, rhs.codeType);
  }
  inline bool operator==(const GnssSignalType& rhs) const {
    return std::tie(constellation, carrierFrequencyHz, codeType) == std::tie(rhs.constellation, rhs.carrierFrequencyHz, rhs.codeType);
  }
  inline bool operator>(const GnssSignalType& rhs) const {
    return std::tie(constellation, carrierFrequencyHz, codeType) > std::tie(rhs.constellation, rhs.carrierFrequencyHz, rhs.codeType);
  }
  inline bool operator>=(const GnssSignalType& rhs) const {
    return std::tie(constellation, carrierFrequencyHz, codeType) >= std::tie(rhs.constellation, rhs.carrierFrequencyHz, rhs.codeType);
  }

  ::android::hardware::gnss::GnssConstellationType constellation = ::android::hardware::gnss::GnssConstellationType(::android::hardware::gnss::GnssConstellationType::UNKNOWN);
  double carrierFrequencyHz = double(0.000000);
  ::std::string codeType;
  static const ::std::string& CODE_TYPE_A();
  static const ::std::string& CODE_TYPE_B();
  static const ::std::string& CODE_TYPE_C();
  static const ::std::string& CODE_TYPE_D();
  static const ::std::string& CODE_TYPE_I();
  static const ::std::string& CODE_TYPE_L();
  static const ::std::string& CODE_TYPE_M();
  static const ::std::string& CODE_TYPE_N();
  static const ::std::string& CODE_TYPE_P();
  static const ::std::string& CODE_TYPE_Q();
  static const ::std::string& CODE_TYPE_S();
  static const ::std::string& CODE_TYPE_W();
  static const ::std::string& CODE_TYPE_X();
  static const ::std::string& CODE_TYPE_Y();
  static const ::std::string& CODE_TYPE_Z();
  static const ::std::string& CODE_TYPE_UNKNOWN();
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.gnss.GnssSignalType");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "GnssSignalType{";
    os << "constellation: " << ::android::internal::ToString(constellation);
    os << ", carrierFrequencyHz: " << ::android::internal::ToString(carrierFrequencyHz);
    os << ", codeType: " << ::android::internal::ToString(codeType);
    os << "}";
    return os.str();
  }
};  // class GnssSignalType

}  // namespace gnss

}  // namespace hardware

}  // namespace android
