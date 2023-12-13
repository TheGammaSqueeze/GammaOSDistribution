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
#include <aidl/android/util/StatsEventParcel.h>

namespace aidl {
namespace android {
namespace os {
class IPullAtomResultReceiver : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IPullAtomResultReceiver();
  virtual ~IPullAtomResultReceiver();

  static constexpr uint32_t TRANSACTION_pullFinished = FIRST_CALL_TRANSACTION + 0;

  static std::shared_ptr<IPullAtomResultReceiver> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IPullAtomResultReceiver>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IPullAtomResultReceiver>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IPullAtomResultReceiver>& impl);
  static const std::shared_ptr<IPullAtomResultReceiver>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus pullFinished(int32_t in_atomTag, bool in_success, const std::vector<::aidl::android::util::StatsEventParcel>& in_output) = 0;
private:
  static std::shared_ptr<IPullAtomResultReceiver> default_impl;
};
class IPullAtomResultReceiverDefault : public IPullAtomResultReceiver {
public:
  ::ndk::ScopedAStatus pullFinished(int32_t in_atomTag, bool in_success, const std::vector<::aidl::android::util::StatsEventParcel>& in_output) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace os
}  // namespace android
}  // namespace aidl
