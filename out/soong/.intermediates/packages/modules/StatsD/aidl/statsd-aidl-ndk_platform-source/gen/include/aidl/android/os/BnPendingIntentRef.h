#pragma once

#include "aidl/android/os/IPendingIntentRef.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace os {
class BnPendingIntentRef : public ::ndk::BnCInterface<IPendingIntentRef> {
public:
  BnPendingIntentRef();
  virtual ~BnPendingIntentRef();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace os
}  // namespace android
}  // namespace aidl
