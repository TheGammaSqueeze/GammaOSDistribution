#pragma once

#include <android/binder_interface_utils.h>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT
#include <aidl/android/media/TranscodingErrorCode.h>
#include <aidl/android/media/TranscodingResultParcel.h>

namespace aidl {
namespace android {
namespace media {
class ITranscodingClientCallback : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  ITranscodingClientCallback();
  virtual ~ITranscodingClientCallback();

  static constexpr uint32_t TRANSACTION_openFileDescriptor = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onTranscodingStarted = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onTranscodingPaused = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_onTranscodingResumed = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_onTranscodingFinished = FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_onTranscodingFailed = FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_onAwaitNumberOfSessionsChanged = FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_onProgressUpdate = FIRST_CALL_TRANSACTION + 7;

  static std::shared_ptr<ITranscodingClientCallback> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ITranscodingClientCallback>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ITranscodingClientCallback>* instance);
  static bool setDefaultImpl(const std::shared_ptr<ITranscodingClientCallback>& impl);
  static const std::shared_ptr<ITranscodingClientCallback>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus openFileDescriptor(const std::string& in_fileUri, const std::string& in_mode, ::ndk::ScopedFileDescriptor* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus onTranscodingStarted(int32_t in_sessionId) = 0;
  virtual ::ndk::ScopedAStatus onTranscodingPaused(int32_t in_sessionId) = 0;
  virtual ::ndk::ScopedAStatus onTranscodingResumed(int32_t in_sessionId) = 0;
  virtual ::ndk::ScopedAStatus onTranscodingFinished(int32_t in_sessionId, const ::aidl::android::media::TranscodingResultParcel& in_result) = 0;
  virtual ::ndk::ScopedAStatus onTranscodingFailed(int32_t in_sessionId, ::aidl::android::media::TranscodingErrorCode in_errorCode) = 0;
  virtual ::ndk::ScopedAStatus onAwaitNumberOfSessionsChanged(int32_t in_sessionId, int32_t in_oldAwaitNumber, int32_t in_newAwaitNumber) = 0;
  virtual ::ndk::ScopedAStatus onProgressUpdate(int32_t in_sessionId, int32_t in_progress) = 0;
private:
  static std::shared_ptr<ITranscodingClientCallback> default_impl;
};
class ITranscodingClientCallbackDefault : public ITranscodingClientCallback {
public:
  ::ndk::ScopedAStatus openFileDescriptor(const std::string& in_fileUri, const std::string& in_mode, ::ndk::ScopedFileDescriptor* _aidl_return) override;
  ::ndk::ScopedAStatus onTranscodingStarted(int32_t in_sessionId) override;
  ::ndk::ScopedAStatus onTranscodingPaused(int32_t in_sessionId) override;
  ::ndk::ScopedAStatus onTranscodingResumed(int32_t in_sessionId) override;
  ::ndk::ScopedAStatus onTranscodingFinished(int32_t in_sessionId, const ::aidl::android::media::TranscodingResultParcel& in_result) override;
  ::ndk::ScopedAStatus onTranscodingFailed(int32_t in_sessionId, ::aidl::android::media::TranscodingErrorCode in_errorCode) override;
  ::ndk::ScopedAStatus onAwaitNumberOfSessionsChanged(int32_t in_sessionId, int32_t in_oldAwaitNumber, int32_t in_newAwaitNumber) override;
  ::ndk::ScopedAStatus onProgressUpdate(int32_t in_sessionId, int32_t in_progress) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
