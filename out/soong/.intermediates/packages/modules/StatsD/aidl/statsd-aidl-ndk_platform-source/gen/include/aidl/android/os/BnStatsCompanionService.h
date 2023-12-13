#pragma once

#include "aidl/android/os/IStatsCompanionService.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace os {
class BnStatsCompanionService : public ::ndk::BnCInterface<IStatsCompanionService> {
public:
  BnStatsCompanionService();
  virtual ~BnStatsCompanionService();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace os
}  // namespace android
}  // namespace aidl
