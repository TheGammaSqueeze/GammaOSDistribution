#pragma once

#include "aidl/android/media/IMediaTranscodingService.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BpMediaTranscodingService : public ::ndk::BpCInterface<IMediaTranscodingService> {
public:
  explicit BpMediaTranscodingService(const ::ndk::SpAIBinder& binder);
  virtual ~BpMediaTranscodingService();

  ::ndk::ScopedAStatus registerClient(const std::shared_ptr<::aidl::android::media::ITranscodingClientCallback>& in_callback, const std::string& in_clientName, const std::string& in_opPackageName, std::shared_ptr<::aidl::android::media::ITranscodingClient>* _aidl_return) override;
  ::ndk::ScopedAStatus getNumOfClients(int32_t* _aidl_return) override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
