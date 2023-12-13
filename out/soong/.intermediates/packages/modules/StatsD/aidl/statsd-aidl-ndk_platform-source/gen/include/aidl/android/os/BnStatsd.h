#pragma once

#include "aidl/android/os/IStatsd.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace os {
class BnStatsd : public ::ndk::BnCInterface<IStatsd> {
public:
  BnStatsd();
  virtual ~BnStatsd();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace os
}  // namespace android
}  // namespace aidl
