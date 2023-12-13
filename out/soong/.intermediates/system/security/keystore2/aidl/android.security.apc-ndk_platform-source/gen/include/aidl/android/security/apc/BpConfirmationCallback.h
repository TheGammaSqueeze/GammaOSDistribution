#pragma once

#include "aidl/android/security/apc/IConfirmationCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace security {
namespace apc {
class BpConfirmationCallback : public ::ndk::BpCInterface<IConfirmationCallback> {
public:
  explicit BpConfirmationCallback(const ::ndk::SpAIBinder& binder);
  virtual ~BpConfirmationCallback();

  ::ndk::ScopedAStatus onCompleted(::aidl::android::security::apc::ResponseCode in_result, const std::optional<std::vector<uint8_t>>& in_dataConfirmed) override;
};
}  // namespace apc
}  // namespace security
}  // namespace android
}  // namespace aidl
