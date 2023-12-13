#pragma once

#include "aidl/android/media/ITranscodingClientCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BpTranscodingClientCallback : public ::ndk::BpCInterface<ITranscodingClientCallback> {
public:
  explicit BpTranscodingClientCallback(const ::ndk::SpAIBinder& binder);
  virtual ~BpTranscodingClientCallback();

  ::ndk::ScopedAStatus openFileDescriptor(const std::string& in_fileUri, const std::string& in_mode, ::ndk::ScopedFileDescriptor* _aidl_return) override;
  ::ndk::ScopedAStatus onTranscodingStarted(int32_t in_sessionId) override;
  ::ndk::ScopedAStatus onTranscodingPaused(int32_t in_sessionId) override;
  ::ndk::ScopedAStatus onTranscodingResumed(int32_t in_sessionId) override;
  ::ndk::ScopedAStatus onTranscodingFinished(int32_t in_sessionId, const ::aidl::android::media::TranscodingResultParcel& in_result) override;
  ::ndk::ScopedAStatus onTranscodingFailed(int32_t in_sessionId, ::aidl::android::media::TranscodingErrorCode in_errorCode) override;
  ::ndk::ScopedAStatus onAwaitNumberOfSessionsChanged(int32_t in_sessionId, int32_t in_oldAwaitNumber, int32_t in_newAwaitNumber) override;
  ::ndk::ScopedAStatus onProgressUpdate(int32_t in_sessionId, int32_t in_progress) override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
