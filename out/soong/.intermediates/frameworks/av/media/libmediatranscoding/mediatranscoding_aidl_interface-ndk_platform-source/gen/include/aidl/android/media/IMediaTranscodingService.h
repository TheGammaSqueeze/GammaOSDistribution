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
#include <aidl/android/media/ITranscodingClient.h>
#include <aidl/android/media/ITranscodingClientCallback.h>

namespace aidl {
namespace android {
namespace media {
class IMediaTranscodingService : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IMediaTranscodingService();
  virtual ~IMediaTranscodingService();

  enum : int32_t { ERROR_PERMISSION_DENIED = 1 };
  enum : int32_t { ERROR_ALREADY_EXISTS = 2 };
  enum : int32_t { ERROR_ILLEGAL_ARGUMENT = 3 };
  enum : int32_t { ERROR_DISCONNECTED = 4 };
  enum : int32_t { ERROR_TIMED_OUT = 5 };
  enum : int32_t { ERROR_DISABLED = 6 };
  enum : int32_t { ERROR_INVALID_OPERATION = 7 };
  enum : int32_t { USE_CALLING_UID = -1 };
  enum : int32_t { USE_CALLING_PID = -1 };
  static constexpr uint32_t TRANSACTION_registerClient = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getNumOfClients = FIRST_CALL_TRANSACTION + 1;

  static std::shared_ptr<IMediaTranscodingService> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IMediaTranscodingService>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IMediaTranscodingService>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IMediaTranscodingService>& impl);
  static const std::shared_ptr<IMediaTranscodingService>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus registerClient(const std::shared_ptr<::aidl::android::media::ITranscodingClientCallback>& in_callback, const std::string& in_clientName, const std::string& in_opPackageName, std::shared_ptr<::aidl::android::media::ITranscodingClient>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getNumOfClients(int32_t* _aidl_return) = 0;
private:
  static std::shared_ptr<IMediaTranscodingService> default_impl;
};
class IMediaTranscodingServiceDefault : public IMediaTranscodingService {
public:
  ::ndk::ScopedAStatus registerClient(const std::shared_ptr<::aidl::android::media::ITranscodingClientCallback>& in_callback, const std::string& in_clientName, const std::string& in_opPackageName, std::shared_ptr<::aidl::android::media::ITranscodingClient>* _aidl_return) override;
  ::ndk::ScopedAStatus getNumOfClients(int32_t* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
