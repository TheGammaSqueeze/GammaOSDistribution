#pragma once

#include "aidl/android/media/IResourceObserver.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BpResourceObserver : public ::ndk::BpCInterface<IResourceObserver> {
public:
  explicit BpResourceObserver(const ::ndk::SpAIBinder& binder);
  virtual ~BpResourceObserver();

  ::ndk::ScopedAStatus onStatusChanged(::aidl::android::media::MediaObservableEvent in_event, int32_t in_uid, int32_t in_pid, const std::vector<::aidl::android::media::MediaObservableParcel>& in_observables) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  int32_t _aidl_cached_version = -1;
  std::string _aidl_cached_hash = "-1";
  std::mutex _aidl_cached_hash_mutex;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
