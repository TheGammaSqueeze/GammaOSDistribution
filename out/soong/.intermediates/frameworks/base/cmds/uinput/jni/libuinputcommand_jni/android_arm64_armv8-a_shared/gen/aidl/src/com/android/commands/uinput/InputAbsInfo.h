#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace src {

namespace com {

namespace android {

namespace commands {

namespace uinput {

class InputAbsInfo : public ::android::Parcelable {
public:
  inline bool operator!=(const InputAbsInfo& rhs) const {
    return std::tie(value, minimum, maximum, fuzz, flat, resolution) != std::tie(rhs.value, rhs.minimum, rhs.maximum, rhs.fuzz, rhs.flat, rhs.resolution);
  }
  inline bool operator<(const InputAbsInfo& rhs) const {
    return std::tie(value, minimum, maximum, fuzz, flat, resolution) < std::tie(rhs.value, rhs.minimum, rhs.maximum, rhs.fuzz, rhs.flat, rhs.resolution);
  }
  inline bool operator<=(const InputAbsInfo& rhs) const {
    return std::tie(value, minimum, maximum, fuzz, flat, resolution) <= std::tie(rhs.value, rhs.minimum, rhs.maximum, rhs.fuzz, rhs.flat, rhs.resolution);
  }
  inline bool operator==(const InputAbsInfo& rhs) const {
    return std::tie(value, minimum, maximum, fuzz, flat, resolution) == std::tie(rhs.value, rhs.minimum, rhs.maximum, rhs.fuzz, rhs.flat, rhs.resolution);
  }
  inline bool operator>(const InputAbsInfo& rhs) const {
    return std::tie(value, minimum, maximum, fuzz, flat, resolution) > std::tie(rhs.value, rhs.minimum, rhs.maximum, rhs.fuzz, rhs.flat, rhs.resolution);
  }
  inline bool operator>=(const InputAbsInfo& rhs) const {
    return std::tie(value, minimum, maximum, fuzz, flat, resolution) >= std::tie(rhs.value, rhs.minimum, rhs.maximum, rhs.fuzz, rhs.flat, rhs.resolution);
  }

  int32_t value = int32_t(0);
  int32_t minimum = int32_t(0);
  int32_t maximum = int32_t(0);
  int32_t fuzz = int32_t(0);
  int32_t flat = int32_t(0);
  int32_t resolution = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"src.com.android.commands.uinput.InputAbsInfo");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "InputAbsInfo{";
    os << "value: " << ::android::internal::ToString(value);
    os << ", minimum: " << ::android::internal::ToString(minimum);
    os << ", maximum: " << ::android::internal::ToString(maximum);
    os << ", fuzz: " << ::android::internal::ToString(fuzz);
    os << ", flat: " << ::android::internal::ToString(flat);
    os << ", resolution: " << ::android::internal::ToString(resolution);
    os << "}";
    return os.str();
  }
};  // class InputAbsInfo

}  // namespace uinput

}  // namespace commands

}  // namespace android

}  // namespace com

}  // namespace src
