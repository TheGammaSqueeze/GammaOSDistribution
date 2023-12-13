#pragma once

#include "aidl/android/adbroot/IADBRootService.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace adbroot {
class BnADBRootService : public ::ndk::BnCInterface<IADBRootService> {
public:
  BnADBRootService();
  virtual ~BnADBRootService();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace adbroot
}  // namespace android
}  // namespace aidl
