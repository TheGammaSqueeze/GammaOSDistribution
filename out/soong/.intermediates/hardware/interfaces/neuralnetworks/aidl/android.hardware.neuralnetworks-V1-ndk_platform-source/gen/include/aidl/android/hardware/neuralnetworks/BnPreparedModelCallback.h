#pragma once

#include "aidl/android/hardware/neuralnetworks/IPreparedModelCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
namespace neuralnetworks {
class BnPreparedModelCallback : public ::ndk::BnCInterface<IPreparedModelCallback> {
public:
  BnPreparedModelCallback();
  virtual ~BnPreparedModelCallback();
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
