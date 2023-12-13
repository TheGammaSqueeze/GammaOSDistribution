#pragma once

#include "aidl/android/net/metrics/INetdEventListener.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace net {
namespace metrics {
class BnNetdEventListener : public ::ndk::BnCInterface<INetdEventListener> {
public:
  BnNetdEventListener();
  virtual ~BnNetdEventListener();
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) final;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) final;
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace metrics
}  // namespace net
}  // namespace android
}  // namespace aidl
