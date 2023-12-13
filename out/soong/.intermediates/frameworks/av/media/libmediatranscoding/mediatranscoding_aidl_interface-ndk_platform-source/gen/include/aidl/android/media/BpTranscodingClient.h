#pragma once

#include "aidl/android/media/ITranscodingClient.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BpTranscodingClient : public ::ndk::BpCInterface<ITranscodingClient> {
public:
  explicit BpTranscodingClient(const ::ndk::SpAIBinder& binder);
  virtual ~BpTranscodingClient();

  ::ndk::ScopedAStatus submitRequest(const ::aidl::android::media::TranscodingRequestParcel& in_request, ::aidl::android::media::TranscodingSessionParcel* out_session, bool* _aidl_return) override;
  ::ndk::ScopedAStatus cancelSession(int32_t in_sessionId, bool* _aidl_return) override;
  ::ndk::ScopedAStatus getSessionWithId(int32_t in_sessionId, ::aidl::android::media::TranscodingSessionParcel* out_session, bool* _aidl_return) override;
  ::ndk::ScopedAStatus addClientUid(int32_t in_sessionId, int32_t in_clientUid, bool* _aidl_return) override;
  ::ndk::ScopedAStatus getClientUids(int32_t in_sessionId, std::optional<std::vector<int32_t>>* _aidl_return) override;
  ::ndk::ScopedAStatus unregister() override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
