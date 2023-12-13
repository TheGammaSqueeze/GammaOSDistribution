#pragma once

#include "aidl/android/system/suspend/IWakelockCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace system {
namespace suspend {
class BnWakelockCallback : public ::ndk::BnCInterface<IWakelockCallback> {
public:
  BnWakelockCallback();
  virtual ~BnWakelockCallback();
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) final;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) final;
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace suspend
}  // namespace system
}  // namespace android
}  // namespace aidl
