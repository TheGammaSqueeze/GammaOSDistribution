#pragma once

#include "aidl/android/frameworks/stats/IStats.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace frameworks {
namespace stats {
class BnStats : public ::ndk::BnCInterface<IStats> {
public:
  BnStats();
  virtual ~BnStats();
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) final;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) final;
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace stats
}  // namespace frameworks
}  // namespace android
}  // namespace aidl
