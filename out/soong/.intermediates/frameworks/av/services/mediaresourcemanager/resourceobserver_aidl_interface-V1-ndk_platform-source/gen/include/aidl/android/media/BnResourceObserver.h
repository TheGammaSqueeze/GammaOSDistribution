#pragma once

#include "aidl/android/media/IResourceObserver.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BnResourceObserver : public ::ndk::BnCInterface<IResourceObserver> {
public:
  BnResourceObserver();
  virtual ~BnResourceObserver();
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) final;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) final;
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace media
}  // namespace android
}  // namespace aidl
