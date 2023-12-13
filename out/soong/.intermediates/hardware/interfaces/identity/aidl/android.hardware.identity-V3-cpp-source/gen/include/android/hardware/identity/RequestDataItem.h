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

namespace hardware {

namespace identity {

class RequestDataItem : public ::android::Parcelable {
public:
  inline bool operator!=(const RequestDataItem& rhs) const {
    return std::tie(name, size, accessControlProfileIds) != std::tie(rhs.name, rhs.size, rhs.accessControlProfileIds);
  }
  inline bool operator<(const RequestDataItem& rhs) const {
    return std::tie(name, size, accessControlProfileIds) < std::tie(rhs.name, rhs.size, rhs.accessControlProfileIds);
  }
  inline bool operator<=(const RequestDataItem& rhs) const {
    return std::tie(name, size, accessControlProfileIds) <= std::tie(rhs.name, rhs.size, rhs.accessControlProfileIds);
  }
  inline bool operator==(const RequestDataItem& rhs) const {
    return std::tie(name, size, accessControlProfileIds) == std::tie(rhs.name, rhs.size, rhs.accessControlProfileIds);
  }
  inline bool operator>(const RequestDataItem& rhs) const {
    return std::tie(name, size, accessControlProfileIds) > std::tie(rhs.name, rhs.size, rhs.accessControlProfileIds);
  }
  inline bool operator>=(const RequestDataItem& rhs) const {
    return std::tie(name, size, accessControlProfileIds) >= std::tie(rhs.name, rhs.size, rhs.accessControlProfileIds);
  }

  ::std::string name;
  int64_t size = int64_t(0L);
  ::std::vector<int32_t> accessControlProfileIds;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.identity.RequestDataItem");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "RequestDataItem{";
    os << "name: " << ::android::internal::ToString(name);
    os << ", size: " << ::android::internal::ToString(size);
    os << ", accessControlProfileIds: " << ::android::internal::ToString(accessControlProfileIds);
    os << "}";
    return os.str();
  }
};  // class RequestDataItem

}  // namespace identity

}  // namespace hardware

}  // namespace android
