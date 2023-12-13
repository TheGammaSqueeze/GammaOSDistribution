#pragma once

#include "aidl/android/system/suspend/ISuspendCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace system {
namespace suspend {
class BpSuspendCallback : public ::ndk::BpCInterface<ISuspendCallback> {
public:
  explicit BpSuspendCallback(const ::ndk::SpAIBinder& binder);
  virtual ~BpSuspendCallback();

  ::ndk::ScopedAStatus notifyWakeup(bool in_success, const std::vector<std::string>& in_wakeupReasons) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  int32_t _aidl_cached_version = -1;
  std::string _aidl_cached_hash = "-1";
  std::mutex _aidl_cached_hash_mutex;
};
}  // namespace suspend
}  // namespace system
}  // namespace android
}  // namespace aidl
