#pragma once

#include "aidl/android/os/IPullAtomCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace os {
class BpPullAtomCallback : public ::ndk::BpCInterface<IPullAtomCallback> {
public:
  explicit BpPullAtomCallback(const ::ndk::SpAIBinder& binder);
  virtual ~BpPullAtomCallback();

  ::ndk::ScopedAStatus onPullAtom(int32_t in_atomTag, const std::shared_ptr<::aidl::android::os::IPullAtomResultReceiver>& in_resultReceiver) override;
};
}  // namespace os
}  // namespace android
}  // namespace aidl
