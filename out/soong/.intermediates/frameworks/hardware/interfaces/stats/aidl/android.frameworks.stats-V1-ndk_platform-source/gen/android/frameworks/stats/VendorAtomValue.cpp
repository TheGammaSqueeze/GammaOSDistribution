#include "aidl/android/frameworks/stats/VendorAtomValue.h"

#include <android/binder_parcel_utils.h>

namespace aidl {
namespace android {
namespace frameworks {
namespace stats {
const char* VendorAtomValue::descriptor = "android.frameworks.stats.VendorAtomValue";

binder_status_t VendorAtomValue::readFromParcel(const AParcel* _parcel) {
  binder_status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = AParcel_readInt32(_parcel, &_aidl_tag)) != STATUS_OK) return _aidl_ret_status;
  switch (_aidl_tag) {
  case intValue: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = AParcel_readInt32(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<intValue>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<intValue>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case longValue: {
    int64_t _aidl_value;
    if ((_aidl_ret_status = AParcel_readInt64(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int64_t>) {
      set<longValue>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<longValue>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case floatValue: {
    float _aidl_value;
    if ((_aidl_ret_status = AParcel_readFloat(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<float>) {
      set<floatValue>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<floatValue>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  case stringValue: {
    std::string _aidl_value;
    if ((_aidl_ret_status = ::ndk::AParcel_readString(_parcel, &_aidl_value)) != STATUS_OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<std::string>) {
      set<stringValue>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<stringValue>(std::move(_aidl_value));
    }
    return STATUS_OK; }
  }
  return STATUS_BAD_VALUE;
}
binder_status_t VendorAtomValue::writeToParcel(AParcel* _parcel) const {
  binder_status_t _aidl_ret_status = AParcel_writeInt32(_parcel, getTag());
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;
  switch (getTag()) {
  case intValue: return AParcel_writeInt32(_parcel, get<intValue>());
  case longValue: return AParcel_writeInt64(_parcel, get<longValue>());
  case floatValue: return AParcel_writeFloat(_parcel, get<floatValue>());
  case stringValue: return ::ndk::AParcel_writeString(_parcel, get<stringValue>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

}  // namespace stats
}  // namespace frameworks
}  // namespace android
}  // namespace aidl
