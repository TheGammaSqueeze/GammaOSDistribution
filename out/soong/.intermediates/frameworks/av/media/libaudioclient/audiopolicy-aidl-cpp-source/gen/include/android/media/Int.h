#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class Int : public ::android::Parcelable {
public:
  inline bool operator!=(const Int& rhs) const {
    return std::tie(value) != std::tie(rhs.value);
  }
  inline bool operator<(const Int& rhs) const {
    return std::tie(value) < std::tie(rhs.value);
  }
  inline bool operator<=(const Int& rhs) const {
    return std::tie(value) <= std::tie(rhs.value);
  }
  inline bool operator==(const Int& rhs) const {
    return std::tie(value) == std::tie(rhs.value);
  }
  inline bool operator>(const Int& rhs) const {
    return std::tie(value) > std::tie(rhs.value);
  }
  inline bool operator>=(const Int& rhs) const {
    return std::tie(value) >= std::tie(rhs.value);
  }

  int32_t value = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.Int");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "Int{";
    os << "value: " << ::android::internal::ToString(value);
    os << "}";
    return os.str();
  }
};  // class Int

}  // namespace media

}  // namespace android
