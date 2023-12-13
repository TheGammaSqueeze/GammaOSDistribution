#pragma once

#include "aidl/android/media/IResourceManagerClient.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BnResourceManagerClient : public ::ndk::BnCInterface<IResourceManagerClient> {
public:
  BnResourceManagerClient();
  virtual ~BnResourceManagerClient();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace media
}  // namespace android
}  // namespace aidl
