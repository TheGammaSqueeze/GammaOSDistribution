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
#include <aidl/android/media/IResourceObserver.h>
#include <aidl/android/media/MediaObservableFilter.h>

namespace aidl {
namespace android {
namespace media {
class IResourceObserverService : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IResourceObserverService();
  virtual ~IResourceObserverService();

  static const int32_t version = 1;
  static inline const std::string hash = "7e198281434e9c679b02265e95c51ea25ed180d3";
  static constexpr uint32_t TRANSACTION_registerObserver = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_unregisterObserver = FIRST_CALL_TRANSACTION + 1;

  static std::shared_ptr<IResourceObserverService> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IResourceObserverService>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IResourceObserverService>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IResourceObserverService>& impl);
  static const std::shared_ptr<IResourceObserverService>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus registerObserver(const std::shared_ptr<::aidl::android::media::IResourceObserver>& in_observer, const std::vector<::aidl::android::media::MediaObservableFilter>& in_filters) = 0;
  virtual ::ndk::ScopedAStatus unregisterObserver(const std::shared_ptr<::aidl::android::media::IResourceObserver>& in_observer) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IResourceObserverService> default_impl;
};
class IResourceObserverServiceDefault : public IResourceObserverService {
public:
  ::ndk::ScopedAStatus registerObserver(const std::shared_ptr<::aidl::android::media::IResourceObserver>& in_observer, const std::vector<::aidl::android::media::MediaObservableFilter>& in_filters) override;
  ::ndk::ScopedAStatus unregisterObserver(const std::shared_ptr<::aidl::android::media::IResourceObserver>& in_observer) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
