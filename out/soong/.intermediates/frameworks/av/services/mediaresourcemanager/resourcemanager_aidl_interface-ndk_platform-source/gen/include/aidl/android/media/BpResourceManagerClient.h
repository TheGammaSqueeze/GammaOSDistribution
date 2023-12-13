#pragma once

#include "aidl/android/media/IResourceManagerClient.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BpResourceManagerClient : public ::ndk::BpCInterface<IResourceManagerClient> {
public:
  explicit BpResourceManagerClient(const ::ndk::SpAIBinder& binder);
  virtual ~BpResourceManagerClient();

  ::ndk::ScopedAStatus reclaimResource(bool* _aidl_return) override;
  ::ndk::ScopedAStatus getName(std::string* _aidl_return) override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
