#pragma once

#include "aidl/android/security/apc/IProtectedConfirmation.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace security {
namespace apc {
class BnProtectedConfirmation : public ::ndk::BnCInterface<IProtectedConfirmation> {
public:
  BnProtectedConfirmation();
  virtual ~BnProtectedConfirmation();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace apc
}  // namespace security
}  // namespace android
}  // namespace aidl
