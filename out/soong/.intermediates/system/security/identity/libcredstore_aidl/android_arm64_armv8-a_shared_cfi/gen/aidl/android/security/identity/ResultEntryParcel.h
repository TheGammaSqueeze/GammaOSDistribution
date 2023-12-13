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

namespace security {

namespace identity {

class ResultEntryParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const ResultEntryParcel& rhs) const {
    return std::tie(status, name, value) != std::tie(rhs.status, rhs.name, rhs.value);
  }
  inline bool operator<(const ResultEntryParcel& rhs) const {
    return std::tie(status, name, value) < std::tie(rhs.status, rhs.name, rhs.value);
  }
  inline bool operator<=(const ResultEntryParcel& rhs) const {
    return std::tie(status, name, value) <= std::tie(rhs.status, rhs.name, rhs.value);
  }
  inline bool operator==(const ResultEntryParcel& rhs) const {
    return std::tie(status, name, value) == std::tie(rhs.status, rhs.name, rhs.value);
  }
  inline bool operator>(const ResultEntryParcel& rhs) const {
    return std::tie(status, name, value) > std::tie(rhs.status, rhs.name, rhs.value);
  }
  inline bool operator>=(const ResultEntryParcel& rhs) const {
    return std::tie(status, name, value) >= std::tie(rhs.status, rhs.name, rhs.value);
  }

  int32_t status = int32_t(0);
  ::std::string name;
  ::std::vector<uint8_t> value;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.security.identity.ResultEntryParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "ResultEntryParcel{";
    os << "status: " << ::android::internal::ToString(status);
    os << ", name: " << ::android::internal::ToString(name);
    os << ", value: " << ::android::internal::ToString(value);
    os << "}";
    return os.str();
  }
};  // class ResultEntryParcel

}  // namespace identity

}  // namespace security

}  // namespace android
