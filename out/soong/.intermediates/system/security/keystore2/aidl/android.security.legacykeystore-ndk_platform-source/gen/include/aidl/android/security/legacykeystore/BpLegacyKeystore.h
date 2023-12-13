#pragma once

#include "aidl/android/security/legacykeystore/ILegacyKeystore.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace security {
namespace legacykeystore {
class BpLegacyKeystore : public ::ndk::BpCInterface<ILegacyKeystore> {
public:
  explicit BpLegacyKeystore(const ::ndk::SpAIBinder& binder);
  virtual ~BpLegacyKeystore();

  ::ndk::ScopedAStatus get(const std::string& in_alias, int32_t in_uid, std::vector<uint8_t>* _aidl_return) override;
  ::ndk::ScopedAStatus put(const std::string& in_alias, int32_t in_uid, const std::vector<uint8_t>& in_blob) override;
  ::ndk::ScopedAStatus remove(const std::string& in_alias, int32_t in_uid) override;
  ::ndk::ScopedAStatus list(const std::string& in_prefix, int32_t in_uid, std::vector<std::string>* _aidl_return) override;
};
}  // namespace legacykeystore
}  // namespace security
}  // namespace android
}  // namespace aidl
