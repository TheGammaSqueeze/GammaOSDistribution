#pragma once

#include <android/binder_to_string.h>
#include <android/media/ISpatializer.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <optional>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class GetSpatializerResponse : public ::android::Parcelable {
public:
  inline bool operator!=(const GetSpatializerResponse& rhs) const {
    return std::tie(spatializer) != std::tie(rhs.spatializer);
  }
  inline bool operator<(const GetSpatializerResponse& rhs) const {
    return std::tie(spatializer) < std::tie(rhs.spatializer);
  }
  inline bool operator<=(const GetSpatializerResponse& rhs) const {
    return std::tie(spatializer) <= std::tie(rhs.spatializer);
  }
  inline bool operator==(const GetSpatializerResponse& rhs) const {
    return std::tie(spatializer) == std::tie(rhs.spatializer);
  }
  inline bool operator>(const GetSpatializerResponse& rhs) const {
    return std::tie(spatializer) > std::tie(rhs.spatializer);
  }
  inline bool operator>=(const GetSpatializerResponse& rhs) const {
    return std::tie(spatializer) >= std::tie(rhs.spatializer);
  }

  ::android::sp<::android::media::ISpatializer> spatializer;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.GetSpatializerResponse");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "GetSpatializerResponse{";
    os << "spatializer: " << ::android::internal::ToString(spatializer);
    os << "}";
    return os.str();
  }
};  // class GetSpatializerResponse

}  // namespace media

}  // namespace android
