#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <com/android/internal/compat/IPlatformCompatNative.h>

namespace com {

namespace android {

namespace internal {

namespace compat {

class BpPlatformCompatNative : public ::android::BpInterface<IPlatformCompatNative> {
public:
  explicit BpPlatformCompatNative(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpPlatformCompatNative() = default;
  ::android::binder::Status reportChangeByPackageName(int64_t changeId, const ::std::string& packageName, int32_t userId) override;
  ::android::binder::Status reportChangeByUid(int64_t changeId, int32_t uid) override;
  ::android::binder::Status isChangeEnabledByPackageName(int64_t changeId, const ::std::string& packageName, int32_t userId, bool* _aidl_return) override;
  ::android::binder::Status isChangeEnabledByUid(int64_t changeId, int32_t uid, bool* _aidl_return) override;
};  // class BpPlatformCompatNative

}  // namespace compat

}  // namespace internal

}  // namespace android

}  // namespace com
