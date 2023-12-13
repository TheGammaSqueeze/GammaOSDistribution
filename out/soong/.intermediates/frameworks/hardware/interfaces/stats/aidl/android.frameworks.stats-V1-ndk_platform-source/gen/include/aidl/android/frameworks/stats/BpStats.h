#pragma once

#include "aidl/android/frameworks/stats/IStats.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace frameworks {
namespace stats {
class BpStats : public ::ndk::BpCInterface<IStats> {
public:
  explicit BpStats(const ::ndk::SpAIBinder& binder);
  virtual ~BpStats();

  ::ndk::ScopedAStatus reportVendorAtom(const ::aidl::android::frameworks::stats::VendorAtom& in_vendorAtom) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  int32_t _aidl_cached_version = -1;
  std::string _aidl_cached_hash = "-1";
  std::mutex _aidl_cached_hash_mutex;
};
}  // namespace stats
}  // namespace frameworks
}  // namespace android
}  // namespace aidl
