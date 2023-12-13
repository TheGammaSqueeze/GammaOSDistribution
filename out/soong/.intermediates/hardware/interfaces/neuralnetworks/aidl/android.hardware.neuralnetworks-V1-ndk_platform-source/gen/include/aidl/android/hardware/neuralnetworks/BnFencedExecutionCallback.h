#pragma once

#include "aidl/android/hardware/neuralnetworks/IFencedExecutionCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
namespace neuralnetworks {
class BnFencedExecutionCallback : public ::ndk::BnCInterface<IFencedExecutionCallback> {
public:
  BnFencedExecutionCallback();
  virtual ~BnFencedExecutionCallback();
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) final;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) final;
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace neuralnetworks
}  // namespace hardware
}  // namespace android
}  // namespace aidl
