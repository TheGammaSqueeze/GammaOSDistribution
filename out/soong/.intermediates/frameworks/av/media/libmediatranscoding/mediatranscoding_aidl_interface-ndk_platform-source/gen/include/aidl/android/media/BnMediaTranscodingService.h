#pragma once

#include "aidl/android/media/IMediaTranscodingService.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BnMediaTranscodingService : public ::ndk::BnCInterface<IMediaTranscodingService> {
public:
  BnMediaTranscodingService();
  virtual ~BnMediaTranscodingService();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace media
}  // namespace android
}  // namespace aidl
