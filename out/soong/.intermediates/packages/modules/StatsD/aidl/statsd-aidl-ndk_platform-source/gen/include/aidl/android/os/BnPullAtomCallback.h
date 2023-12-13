#pragma once

#include "aidl/android/os/IPullAtomCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace os {
class BnPullAtomCallback : public ::ndk::BnCInterface<IPullAtomCallback> {
public:
  BnPullAtomCallback();
  virtual ~BnPullAtomCallback();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace os
}  // namespace android
}  // namespace aidl
