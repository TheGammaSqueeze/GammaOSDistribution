#pragma once

#include "aidl/android/media/ITranscodingClientCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BnTranscodingClientCallback : public ::ndk::BnCInterface<ITranscodingClientCallback> {
public:
  BnTranscodingClientCallback();
  virtual ~BnTranscodingClientCallback();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace media
}  // namespace android
}  // namespace aidl
