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
namespace security {
namespace legacykeystore {
class ILegacyKeystore : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  ILegacyKeystore();
  virtual ~ILegacyKeystore();

  enum : int32_t { UID_SELF = -1 };
  enum : int32_t { ERROR_SYSTEM_ERROR = 4 };
  enum : int32_t { ERROR_PERMISSION_DENIED = 6 };
  enum : int32_t { ERROR_ENTRY_NOT_FOUND = 7 };
  static constexpr uint32_t TRANSACTION_get = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_put = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_remove = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_list = FIRST_CALL_TRANSACTION + 3;

  static std::shared_ptr<ILegacyKeystore> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ILegacyKeystore>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ILegacyKeystore>* instance);
  static bool setDefaultImpl(const std::shared_ptr<ILegacyKeystore>& impl);
  static const std::shared_ptr<ILegacyKeystore>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus get(const std::string& in_alias, int32_t in_uid, std::vector<uint8_t>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus put(const std::string& in_alias, int32_t in_uid, const std::vector<uint8_t>& in_blob) = 0;
  virtual ::ndk::ScopedAStatus remove(const std::string& in_alias, int32_t in_uid) = 0;
  virtual ::ndk::ScopedAStatus list(const std::string& in_prefix, int32_t in_uid, std::vector<std::string>* _aidl_return) = 0;
private:
  static std::shared_ptr<ILegacyKeystore> default_impl;
};
class ILegacyKeystoreDefault : public ILegacyKeystore {
public:
  ::ndk::ScopedAStatus get(const std::string& in_alias, int32_t in_uid, std::vector<uint8_t>* _aidl_return) override;
  ::ndk::ScopedAStatus put(const std::string& in_alias, int32_t in_uid, const std::vector<uint8_t>& in_blob) override;
  ::ndk::ScopedAStatus remove(const std::string& in_alias, int32_t in_uid) override;
  ::ndk::ScopedAStatus list(const std::string& in_prefix, int32_t in_uid, std::vector<std::string>* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace legacykeystore
}  // namespace security
}  // namespace android
}  // namespace aidl
