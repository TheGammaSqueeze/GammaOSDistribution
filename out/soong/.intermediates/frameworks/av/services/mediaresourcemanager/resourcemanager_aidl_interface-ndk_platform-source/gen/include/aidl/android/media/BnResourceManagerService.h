#pragma once

#include "aidl/android/media/IResourceManagerService.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BnResourceManagerService : public ::ndk::BnCInterface<IResourceManagerService> {
public:
  BnResourceManagerService();
  virtual ~BnResourceManagerService();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace media
}  // namespace android
}  // namespace aidl
