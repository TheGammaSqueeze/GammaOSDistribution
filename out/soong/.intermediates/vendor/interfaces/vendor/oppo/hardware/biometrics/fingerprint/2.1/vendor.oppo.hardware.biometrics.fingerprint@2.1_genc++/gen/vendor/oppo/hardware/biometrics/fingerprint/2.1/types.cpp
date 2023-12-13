#define LOG_TAG "vendor.oppo.hardware.biometrics.fingerprint@2.1::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <vendor/oppo/hardware/biometrics/fingerprint/2.1/types.h>
#include <vendor/oppo/hardware/biometrics/fingerprint/2.1/hwtypes.h>

namespace vendor {
namespace oppo {
namespace hardware {
namespace biometrics {
namespace fingerprint {
namespace V2_1 {

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_1
}  // namespace fingerprint
}  // namespace biometrics
}  // namespace hardware
}  // namespace oppo
}  // namespace vendor
