#pragma once
#include <android/binder_interface_utils.h>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT
namespace aidl {
namespace android {
namespace hardware {
namespace automotive {
namespace occupant_awareness {
class PresenceDetection {
public:
  static const char* descriptor;

  bool isOccupantDetected;
  int64_t detectionDurationMillis;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;
};
}  // namespace occupant_awareness
}  // namespace automotive
}  // namespace hardware
}  // namespace android
}  // namespace aidl
