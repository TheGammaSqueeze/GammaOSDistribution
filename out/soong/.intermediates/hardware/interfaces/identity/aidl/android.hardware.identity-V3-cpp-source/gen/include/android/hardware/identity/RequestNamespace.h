#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/identity/RequestDataItem.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <string>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace hardware {

namespace identity {

class RequestNamespace : public ::android::Parcelable {
public:
  inline bool operator!=(const RequestNamespace& rhs) const {
    return std::tie(namespaceName, items) != std::tie(rhs.namespaceName, rhs.items);
  }
  inline bool operator<(const RequestNamespace& rhs) const {
    return std::tie(namespaceName, items) < std::tie(rhs.namespaceName, rhs.items);
  }
  inline bool operator<=(const RequestNamespace& rhs) const {
    return std::tie(namespaceName, items) <= std::tie(rhs.namespaceName, rhs.items);
  }
  inline bool operator==(const RequestNamespace& rhs) const {
    return std::tie(namespaceName, items) == std::tie(rhs.namespaceName, rhs.items);
  }
  inline bool operator>(const RequestNamespace& rhs) const {
    return std::tie(namespaceName, items) > std::tie(rhs.namespaceName, rhs.items);
  }
  inline bool operator>=(const RequestNamespace& rhs) const {
    return std::tie(namespaceName, items) >= std::tie(rhs.namespaceName, rhs.items);
  }

  ::std::string namespaceName;
  ::std::vector<::android::hardware::identity::RequestDataItem> items;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.identity.RequestNamespace");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "RequestNamespace{";
    os << "namespaceName: " << ::android::internal::ToString(namespaceName);
    os << ", items: " << ::android::internal::ToString(items);
    os << "}";
    return os.str();
  }
};  // class RequestNamespace

}  // namespace identity

}  // namespace hardware

}  // namespace android
