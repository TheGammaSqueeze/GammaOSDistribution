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

class EntryParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const EntryParcel& rhs) const {
    return std::tie(name, value, accessControlProfileIds) != std::tie(rhs.name, rhs.value, rhs.accessControlProfileIds);
  }
  inline bool operator<(const EntryParcel& rhs) const {
    return std::tie(name, value, accessControlProfileIds) < std::tie(rhs.name, rhs.value, rhs.accessControlProfileIds);
  }
  inline bool operator<=(const EntryParcel& rhs) const {
    return std::tie(name, value, accessControlProfileIds) <= std::tie(rhs.name, rhs.value, rhs.accessControlProfileIds);
  }
  inline bool operator==(const EntryParcel& rhs) const {
    return std::tie(name, value, accessControlProfileIds) == std::tie(rhs.name, rhs.value, rhs.accessControlProfileIds);
  }
  inline bool operator>(const EntryParcel& rhs) const {
    return std::tie(name, value, accessControlProfileIds) > std::tie(rhs.name, rhs.value, rhs.accessControlProfileIds);
  }
  inline bool operator>=(const EntryParcel& rhs) const {
    return std::tie(name, value, accessControlProfileIds) >= std::tie(rhs.name, rhs.value, rhs.accessControlProfileIds);
  }

  ::std::string name;
  ::std::vector<uint8_t> value;
  ::std::vector<int32_t> accessControlProfileIds;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.security.identity.EntryParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "EntryParcel{";
    os << "name: " << ::android::internal::ToString(name);
    os << ", value: " << ::android::internal::ToString(value);
    os << ", accessControlProfileIds: " << ::android::internal::ToString(accessControlProfileIds);
    os << "}";
    return os.str();
  }
};  // class EntryParcel

}  // namespace identity

}  // namespace security

}  // namespace android
