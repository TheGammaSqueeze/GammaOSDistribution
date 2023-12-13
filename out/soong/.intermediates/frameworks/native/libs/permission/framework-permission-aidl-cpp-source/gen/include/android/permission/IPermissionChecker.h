#pragma once

#include <android/content/AttributionSourceState.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace permission {

class IPermissionChecker : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(PermissionChecker)
  enum  : int32_t {
    PERMISSION_GRANTED = 0,
    PERMISSION_SOFT_DENIED = 1,
    PERMISSION_HARD_DENIED = 2,
  };
  virtual ::android::binder::Status checkPermission(const ::android::String16& permission, const ::android::content::AttributionSourceState& attributionSource, const ::std::optional<::android::String16>& message, bool forDataDelivery, bool startDataDelivery, bool fromDatasource, int32_t attributedOp, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status finishDataDelivery(int32_t op, const ::android::content::AttributionSourceState& attributionSource, bool fromDatasource) = 0;
  virtual ::android::binder::Status checkOp(int32_t op, const ::android::content::AttributionSourceState& attributionSource, const ::android::String16& message, bool forDataDelivery, bool startDataDelivery, int32_t* _aidl_return) = 0;
};  // class IPermissionChecker

class IPermissionCheckerDefault : public IPermissionChecker {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status checkPermission(const ::android::String16&, const ::android::content::AttributionSourceState&, const ::std::optional<::android::String16>&, bool, bool, bool, int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status finishDataDelivery(int32_t, const ::android::content::AttributionSourceState&, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status checkOp(int32_t, const ::android::content::AttributionSourceState&, const ::android::String16&, bool, bool, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IPermissionCheckerDefault

}  // namespace permission

}  // namespace android
