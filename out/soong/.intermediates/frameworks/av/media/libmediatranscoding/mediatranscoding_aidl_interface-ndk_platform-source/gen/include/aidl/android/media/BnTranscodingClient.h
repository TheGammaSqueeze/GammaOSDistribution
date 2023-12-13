#pragma once

#include "aidl/android/media/ITranscodingClient.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BnTranscodingClient : public ::ndk::BnCInterface<ITranscodingClient> {
public:
  BnTranscodingClient();
  virtual ~BnTranscodingClient();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace media
}  // namespace android
}  // namespace aidl
