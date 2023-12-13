#pragma once

#include "aidl/android/os/IPullAtomResultReceiver.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace os {
class BpPullAtomResultReceiver : public ::ndk::BpCInterface<IPullAtomResultReceiver> {
public:
  explicit BpPullAtomResultReceiver(const ::ndk::SpAIBinder& binder);
  virtual ~BpPullAtomResultReceiver();

  ::ndk::ScopedAStatus pullFinished(int32_t in_atomTag, bool in_success, const std::vector<::aidl::android::util::StatsEventParcel>& in_output) override;
};
}  // namespace os
}  // namespace android
}  // namespace aidl
