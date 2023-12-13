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
#include <aidl/android/os/IPullAtomResultReceiver.h>

namespace aidl {
namespace android {
namespace os {
class IPullAtomCallback : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IPullAtomCallback();
  virtual ~IPullAtomCallback();

  static constexpr uint32_t TRANSACTION_onPullAtom = FIRST_CALL_TRANSACTION + 0;

  static std::shared_ptr<IPullAtomCallback> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IPullAtomCallback>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IPullAtomCallback>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IPullAtomCallback>& impl);
  static const std::shared_ptr<IPullAtomCallback>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onPullAtom(int32_t in_atomTag, const std::shared_ptr<::aidl::android::os::IPullAtomResultReceiver>& in_resultReceiver) = 0;
private:
  static std::shared_ptr<IPullAtomCallback> default_impl;
};
class IPullAtomCallbackDefault : public IPullAtomCallback {
public:
  ::ndk::ScopedAStatus onPullAtom(int32_t in_atomTag, const std::shared_ptr<::aidl::android::os::IPullAtomResultReceiver>& in_resultReceiver) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace os
}  // namespace android
}  // namespace aidl
