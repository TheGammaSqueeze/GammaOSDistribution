#pragma once

#include <aaudio/StreamParameters.h>
#include <android/binder_to_string.h>
#include <android/content/AttributionSourceState.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>
#include <utils/String16.h>

namespace aaudio {

class StreamRequest : public ::android::Parcelable {
public:
  inline bool operator!=(const StreamRequest& rhs) const {
    return std::tie(params, attributionSource, sharingModeMatchRequired, inService) != std::tie(rhs.params, rhs.attributionSource, rhs.sharingModeMatchRequired, rhs.inService);
  }
  inline bool operator<(const StreamRequest& rhs) const {
    return std::tie(params, attributionSource, sharingModeMatchRequired, inService) < std::tie(rhs.params, rhs.attributionSource, rhs.sharingModeMatchRequired, rhs.inService);
  }
  inline bool operator<=(const StreamRequest& rhs) const {
    return std::tie(params, attributionSource, sharingModeMatchRequired, inService) <= std::tie(rhs.params, rhs.attributionSource, rhs.sharingModeMatchRequired, rhs.inService);
  }
  inline bool operator==(const StreamRequest& rhs) const {
    return std::tie(params, attributionSource, sharingModeMatchRequired, inService) == std::tie(rhs.params, rhs.attributionSource, rhs.sharingModeMatchRequired, rhs.inService);
  }
  inline bool operator>(const StreamRequest& rhs) const {
    return std::tie(params, attributionSource, sharingModeMatchRequired, inService) > std::tie(rhs.params, rhs.attributionSource, rhs.sharingModeMatchRequired, rhs.inService);
  }
  inline bool operator>=(const StreamRequest& rhs) const {
    return std::tie(params, attributionSource, sharingModeMatchRequired, inService) >= std::tie(rhs.params, rhs.attributionSource, rhs.sharingModeMatchRequired, rhs.inService);
  }

  ::aaudio::StreamParameters params;
  ::android::content::AttributionSourceState attributionSource;
  bool sharingModeMatchRequired = bool(false);
  bool inService = bool(false);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"aaudio.StreamRequest");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "StreamRequest{";
    os << "params: " << ::android::internal::ToString(params);
    os << ", attributionSource: " << ::android::internal::ToString(attributionSource);
    os << ", sharingModeMatchRequired: " << ::android::internal::ToString(sharingModeMatchRequired);
    os << ", inService: " << ::android::internal::ToString(inService);
    os << "}";
    return os.str();
  }
};  // class StreamRequest

}  // namespace aaudio
