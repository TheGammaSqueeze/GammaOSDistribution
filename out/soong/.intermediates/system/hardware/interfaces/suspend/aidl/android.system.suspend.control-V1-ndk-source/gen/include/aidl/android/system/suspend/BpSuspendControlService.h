#pragma once

#include "aidl/android/system/suspend/ISuspendControlService.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace system {
namespace suspend {
class BpSuspendControlService : public ::ndk::BpCInterface<ISuspendControlService> {
public:
  explicit BpSuspendControlService(const ::ndk::SpAIBinder& binder);
  virtual ~BpSuspendControlService();

  ::ndk::ScopedAStatus registerCallback(const std::shared_ptr<::aidl::android::system::suspend::ISuspendCallback>& in_callback, bool* _aidl_return) override;
  ::ndk::ScopedAStatus registerWakelockCallback(const std::shared_ptr<::aidl::android::system::suspend::IWakelockCallback>& in_callback, const std::string& in_name, bool* _aidl_return) override;
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
