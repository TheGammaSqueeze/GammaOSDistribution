#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/permission/IPermissionChecker.h>

namespace android {

namespace permission {

class BpPermissionChecker : public ::android::BpInterface<IPermissionChecker> {
public:
  explicit BpPermissionChecker(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpPermissionChecker() = default;
  ::android::binder::Status checkPermission(const ::android::String16& permission, const ::android::content::AttributionSourceState& attributionSource, const ::std::optional<::android::String16>& message, bool forDataDelivery, bool startDataDelivery, bool fromDatasource, int32_t attributedOp, int32_t* _aidl_return) override;
  ::android::binder::Status finishDataDelivery(int32_t op, const ::android::content::AttributionSourceState& attributionSource, bool fromDatasource) override;
  ::android::binder::Status checkOp(int32_t op, const ::android::content::AttributionSourceState& attributionSource, const ::android::String16& message, bool forDataDelivery, bool startDataDelivery, int32_t* _aidl_return) override;
};  // class BpPermissionChecker

}  // namespace permission

}  // namespace android
