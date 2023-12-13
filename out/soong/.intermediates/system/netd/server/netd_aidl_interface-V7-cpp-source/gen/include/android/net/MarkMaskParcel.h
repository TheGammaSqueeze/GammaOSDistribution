#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace net {

class MarkMaskParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const MarkMaskParcel& rhs) const {
    return std::tie(mark, mask) != std::tie(rhs.mark, rhs.mask);
  }
  inline bool operator<(const MarkMaskParcel& rhs) const {
    return std::tie(mark, mask) < std::tie(rhs.mark, rhs.mask);
  }
  inline bool operator<=(const MarkMaskParcel& rhs) const {
    return std::tie(mark, mask) <= std::tie(rhs.mark, rhs.mask);
  }
  inline bool operator==(const MarkMaskParcel& rhs) const {
    return std::tie(mark, mask) == std::tie(rhs.mark, rhs.mask);
  }
  inline bool operator>(const MarkMaskParcel& rhs) const {
    return std::tie(mark, mask) > std::tie(rhs.mark, rhs.mask);
  }
  inline bool operator>=(const MarkMaskParcel& rhs) const {
    return std::tie(mark, mask) >= std::tie(rhs.mark, rhs.mask);
  }

  int32_t mark = int32_t(0);
  int32_t mask = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.net.MarkMaskParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "MarkMaskParcel{";
    os << "mark: " << ::android::internal::ToString(mark);
    os << ", mask: " << ::android::internal::ToString(mask);
    os << "}";
    return os.str();
  }
};  // class MarkMaskParcel

}  // namespace net

}  // namespace android
