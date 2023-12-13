#pragma once

#include "aidl/android/security/legacykeystore/ILegacyKeystore.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace security {
namespace legacykeystore {
class BnLegacyKeystore : public ::ndk::BnCInterface<ILegacyKeystore> {
public:
  BnLegacyKeystore();
  virtual ~BnLegacyKeystore();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace legacykeystore
}  // namespace security
}  // namespace android
}  // namespace aidl
