#pragma once

#include "aidl/android/os/IPullAtomResultReceiver.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace os {
class BnPullAtomResultReceiver : public ::ndk::BnCInterface<IPullAtomResultReceiver> {
public:
  BnPullAtomResultReceiver();
  virtual ~BnPullAtomResultReceiver();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace os
}  // namespace android
}  // namespace aidl
