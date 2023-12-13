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

namespace aidl {
namespace android {
namespace system {
namespace suspend {
class IWakelockCallback : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IWakelockCallback();
  virtual ~IWakelockCallback();

  static const int32_t version = 1;
  static inline const std::string hash = "34506b107801d68c881c2c7368ad4c676aed3e9b";
  static constexpr uint32_t TRANSACTION_notifyAcquired = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_notifyReleased = FIRST_CALL_TRANSACTION + 1;

  static std::shared_ptr<IWakelockCallback> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IWakelockCallback>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IWakelockCallback>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IWakelockCallback>& impl);
  static const std::shared_ptr<IWakelockCallback>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus notifyAcquired() = 0;
  virtual ::ndk::ScopedAStatus notifyReleased() = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IWakelockCallback> default_impl;
};
class IWakelockCallbackDefault : public IWakelockCallback {
public:
  ::ndk::ScopedAStatus notifyAcquired() override;
  ::ndk::ScopedAStatus notifyReleased() override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace suspend
}  // namespace system
}  // namespace android
}  // namespace aidl
