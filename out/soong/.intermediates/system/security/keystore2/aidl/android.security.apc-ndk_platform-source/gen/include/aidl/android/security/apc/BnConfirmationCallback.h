#pragma once

#include "aidl/android/security/apc/IConfirmationCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace security {
namespace apc {
class BnConfirmationCallback : public ::ndk::BnCInterface<IConfirmationCallback> {
public:
  BnConfirmationCallback();
  virtual ~BnConfirmationCallback();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace apc
}  // namespace security
}  // namespace android
}  // namespace aidl
