#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace net {

class UidRangeParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const UidRangeParcel& rhs) const {
    return std::tie(start, stop) != std::tie(rhs.start, rhs.stop);
  }
  inline bool operator<(const UidRangeParcel& rhs) const {
    return std::tie(start, stop) < std::tie(rhs.start, rhs.stop);
  }
  inline bool operator<=(const UidRangeParcel& rhs) const {
    return std::tie(start, stop) <= std::tie(rhs.start, rhs.stop);
  }
  inline bool operator==(const UidRangeParcel& rhs) const {
    return std::tie(start, stop) == std::tie(rhs.start, rhs.stop);
  }
  inline bool operator>(const UidRangeParcel& rhs) const {
    return std::tie(start, stop) > std::tie(rhs.start, rhs.stop);
  }
  inline bool operator>=(const UidRangeParcel& rhs) const {
    return std::tie(start, stop) >= std::tie(rhs.start, rhs.stop);
  }

  int32_t start = int32_t(0);
  int32_t stop = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.net.UidRangeParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "UidRangeParcel{";
    os << "start: " << ::android::internal::ToString(start);
    os << ", stop: " << ::android::internal::ToString(stop);
    os << "}";
    return os.str();
  }
};  // class UidRangeParcel

}  // namespace net

}  // namespace android
