#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IIdmap2.h>

namespace android {

namespace os {

class BpIdmap2 : public ::android::BpInterface<IIdmap2> {
public:
  explicit BpIdmap2(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpIdmap2() = default;
  ::android::binder::Status getIdmapPath(const ::std::string& overlayApkPath, int32_t userId, ::std::string* _aidl_return) override;
  ::android::binder::Status removeIdmap(const ::std::string& overlayApkPath, int32_t userId, bool* _aidl_return) override;
  ::android::binder::Status verifyIdmap(const ::std::string& targetApkPath, const ::std::string& overlayApkPath, const ::std::string& overlayName, int32_t fulfilledPolicies, bool enforceOverlayable, int32_t userId, bool* _aidl_return) override;
  ::android::binder::Status createIdmap(const ::std::string& targetApkPath, const ::std::string& overlayApkPath, const ::std::string& overlayName, int32_t fulfilledPolicies, bool enforceOverlayable, int32_t userId, ::std::optional<::std::string>* _aidl_return) override;
  ::android::binder::Status createFabricatedOverlay(const ::android::os::FabricatedOverlayInternal& overlay, ::std::optional<::android::os::FabricatedOverlayInfo>* _aidl_return) override;
  ::android::binder::Status deleteFabricatedOverlay(const ::std::string& path, bool* _aidl_return) override;
  ::android::binder::Status acquireFabricatedOverlayIterator() override;
  ::android::binder::Status releaseFabricatedOverlayIterator() override;
  ::android::binder::Status nextFabricatedOverlayInfos(::std::vector<::android::os::FabricatedOverlayInfo>* _aidl_return) override;
  ::android::binder::Status dumpIdmap(const ::std::string& overlayApkPath, ::std::string* _aidl_return) override;
};  // class BpIdmap2

}  // namespace os

}  // namespace android
