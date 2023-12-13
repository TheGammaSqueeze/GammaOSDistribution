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
#include <aidl/android/system/suspend/ISuspendCallback.h>
#include <aidl/android/system/suspend/IWakelockCallback.h>

namespace aidl {
namespace android {
namespace system {
namespace suspend {
class ISuspendControlService : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  ISuspendControlService();
  virtual ~ISuspendControlService();

  static const int32_t version = 1;
  static inline const std::string hash = "34506b107801d68c881c2c7368ad4c676aed3e9b";
  static constexpr uint32_t TRANSACTION_registerCallback = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_registerWakelockCallback = FIRST_CALL_TRANSACTION + 1;

  static std::shared_ptr<ISuspendControlService> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ISuspendControlService>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ISuspendControlService>* instance);
  static bool setDefaultImpl(const std::shared_ptr<ISuspendControlService>& impl);
  static const std::shared_ptr<ISuspendControlService>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus registerCallback(const std::shared_ptr<::aidl::android::system::suspend::ISuspendCallback>& in_callback, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus registerWakelockCallback(const std::shared_ptr<::aidl::android::system::suspend::IWakelockCallback>& in_callback, const std::string& in_name, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<ISuspendControlService> default_impl;
};
class ISuspendControlServiceDefault : public ISuspendControlService {
public:
  ::ndk::ScopedAStatus registerCallback(const std::shared_ptr<::aidl::android::system::suspend::ISuspendCallback>& in_callback, bool* _aidl_return) override;
  ::ndk::ScopedAStatus registerWakelockCallback(const std::shared_ptr<::aidl::android::system::suspend::IWakelockCallback>& in_callback, const std::string& in_name, bool* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace suspend
}  // namespace system
}  // namespace android
}  // namespace aidl
