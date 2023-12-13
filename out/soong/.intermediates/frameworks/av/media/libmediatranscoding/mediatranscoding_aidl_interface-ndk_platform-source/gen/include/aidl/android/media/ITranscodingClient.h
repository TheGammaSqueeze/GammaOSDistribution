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
#include <aidl/android/media/TranscodingRequestParcel.h>
#include <aidl/android/media/TranscodingSessionParcel.h>

namespace aidl {
namespace android {
namespace media {
class ITranscodingClient : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  ITranscodingClient();
  virtual ~ITranscodingClient();

  static constexpr uint32_t TRANSACTION_submitRequest = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_cancelSession = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getSessionWithId = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_addClientUid = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_getClientUids = FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_unregister = FIRST_CALL_TRANSACTION + 5;

  static std::shared_ptr<ITranscodingClient> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ITranscodingClient>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ITranscodingClient>* instance);
  static bool setDefaultImpl(const std::shared_ptr<ITranscodingClient>& impl);
  static const std::shared_ptr<ITranscodingClient>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus submitRequest(const ::aidl::android::media::TranscodingRequestParcel& in_request, ::aidl::android::media::TranscodingSessionParcel* out_session, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus cancelSession(int32_t in_sessionId, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getSessionWithId(int32_t in_sessionId, ::aidl::android::media::TranscodingSessionParcel* out_session, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus addClientUid(int32_t in_sessionId, int32_t in_clientUid, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getClientUids(int32_t in_sessionId, std::optional<std::vector<int32_t>>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus unregister() = 0;
private:
  static std::shared_ptr<ITranscodingClient> default_impl;
};
class ITranscodingClientDefault : public ITranscodingClient {
public:
  ::ndk::ScopedAStatus submitRequest(const ::aidl::android::media::TranscodingRequestParcel& in_request, ::aidl::android::media::TranscodingSessionParcel* out_session, bool* _aidl_return) override;
  ::ndk::ScopedAStatus cancelSession(int32_t in_sessionId, bool* _aidl_return) override;
  ::ndk::ScopedAStatus getSessionWithId(int32_t in_sessionId, ::aidl::android::media::TranscodingSessionParcel* out_session, bool* _aidl_return) override;
  ::ndk::ScopedAStatus addClientUid(int32_t in_sessionId, int32_t in_clientUid, bool* _aidl_return) override;
  ::ndk::ScopedAStatus getClientUids(int32_t in_sessionId, std::optional<std::vector<int32_t>>* _aidl_return) override;
  ::ndk::ScopedAStatus unregister() override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
