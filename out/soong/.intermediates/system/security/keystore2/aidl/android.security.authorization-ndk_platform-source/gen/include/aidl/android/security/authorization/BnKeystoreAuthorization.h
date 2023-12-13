#pragma once

#include "aidl/android/security/authorization/IKeystoreAuthorization.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace security {
namespace authorization {
class BnKeystoreAuthorization : public ::ndk::BnCInterface<IKeystoreAuthorization> {
public:
  BnKeystoreAuthorization();
  virtual ~BnKeystoreAuthorization();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace authorization
}  // namespace security
}  // namespace android
}  // namespace aidl
