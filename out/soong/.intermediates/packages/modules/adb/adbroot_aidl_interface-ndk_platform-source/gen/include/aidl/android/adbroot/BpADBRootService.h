#pragma once

#include "aidl/android/adbroot/IADBRootService.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace adbroot {
class BpADBRootService : public ::ndk::BpCInterface<IADBRootService> {
public:
  explicit BpADBRootService(const ::ndk::SpAIBinder& binder);
  virtual ~BpADBRootService();

  ::ndk::ScopedAStatus isSupported(bool* _aidl_return) override;
  ::ndk::ScopedAStatus setEnabled(bool in_enabled) override;
  ::ndk::ScopedAStatus getEnabled(bool* _aidl_return) override;
};
}  // namespace adbroot
}  // namespace android
}  // namespace aidl
