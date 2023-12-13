#pragma once

#include "aidl/android/security/compat/IKeystoreCompatService.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace security {
namespace compat {
class BnKeystoreCompatService : public ::ndk::BnCInterface<IKeystoreCompatService> {
public:
  BnKeystoreCompatService();
  virtual ~BnKeystoreCompatService();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace compat
}  // namespace security
}  // namespace android
}  // namespace aidl
