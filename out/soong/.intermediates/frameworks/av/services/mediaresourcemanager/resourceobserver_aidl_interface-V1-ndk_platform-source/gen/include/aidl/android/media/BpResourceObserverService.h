#pragma once

#include "aidl/android/media/IResourceObserverService.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BpResourceObserverService : public ::ndk::BpCInterface<IResourceObserverService> {
public:
  explicit BpResourceObserverService(const ::ndk::SpAIBinder& binder);
  virtual ~BpResourceObserverService();

  ::ndk::ScopedAStatus registerObserver(const std::shared_ptr<::aidl::android::media::IResourceObserver>& in_observer, const std::vector<::aidl::android::media::MediaObservableFilter>& in_filters) override;
  ::ndk::ScopedAStatus unregisterObserver(const std::shared_ptr<::aidl::android::media::IResourceObserver>& in_observer) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  int32_t _aidl_cached_version = -1;
  std::string _aidl_cached_hash = "-1";
  std::mutex _aidl_cached_hash_mutex;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
