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
#include <aidl/android/media/MediaObservableEvent.h>
#include <aidl/android/media/MediaObservableParcel.h>

namespace aidl {
namespace android {
namespace media {
class IResourceObserver : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IResourceObserver();
  virtual ~IResourceObserver();

  static const int32_t version = 1;
  static inline const std::string hash = "7e198281434e9c679b02265e95c51ea25ed180d3";
  static constexpr uint32_t TRANSACTION_onStatusChanged = FIRST_CALL_TRANSACTION + 0;

  static std::shared_ptr<IResourceObserver> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IResourceObserver>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IResourceObserver>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IResourceObserver>& impl);
  static const std::shared_ptr<IResourceObserver>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onStatusChanged(::aidl::android::media::MediaObservableEvent in_event, int32_t in_uid, int32_t in_pid, const std::vector<::aidl::android::media::MediaObservableParcel>& in_observables) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IResourceObserver> default_impl;
};
class IResourceObserverDefault : public IResourceObserver {
public:
  ::ndk::ScopedAStatus onStatusChanged(::aidl::android::media::MediaObservableEvent in_event, int32_t in_uid, int32_t in_pid, const std::vector<::aidl::android::media::MediaObservableParcel>& in_observables) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
