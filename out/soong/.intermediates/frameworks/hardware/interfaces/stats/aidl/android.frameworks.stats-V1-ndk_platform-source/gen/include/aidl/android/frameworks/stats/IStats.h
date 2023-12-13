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
#include <aidl/android/frameworks/stats/VendorAtom.h>

namespace aidl {
namespace android {
namespace frameworks {
namespace stats {
class IStats : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IStats();
  virtual ~IStats();

  static const int32_t version = 1;
  static inline const std::string hash = "ee0b303cae7889e83a6a198c9b33781ad74ae633";
  static constexpr uint32_t TRANSACTION_reportVendorAtom = FIRST_CALL_TRANSACTION + 0;

  static std::shared_ptr<IStats> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IStats>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IStats>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IStats>& impl);
  static const std::shared_ptr<IStats>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus reportVendorAtom(const ::aidl::android::frameworks::stats::VendorAtom& in_vendorAtom) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IStats> default_impl;
};
class IStatsDefault : public IStats {
public:
  ::ndk::ScopedAStatus reportVendorAtom(const ::aidl::android::frameworks::stats::VendorAtom& in_vendorAtom) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace stats
}  // namespace frameworks
}  // namespace android
}  // namespace aidl
