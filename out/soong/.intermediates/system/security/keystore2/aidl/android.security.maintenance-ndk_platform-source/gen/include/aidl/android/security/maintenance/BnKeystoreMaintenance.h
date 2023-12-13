#pragma once

#include "aidl/android/security/maintenance/IKeystoreMaintenance.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace security {
namespace maintenance {
class BnKeystoreMaintenance : public ::ndk::BnCInterface<IKeystoreMaintenance> {
public:
  BnKeystoreMaintenance();
  virtual ~BnKeystoreMaintenance();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace maintenance
}  // namespace security
}  // namespace android
}  // namespace aidl
