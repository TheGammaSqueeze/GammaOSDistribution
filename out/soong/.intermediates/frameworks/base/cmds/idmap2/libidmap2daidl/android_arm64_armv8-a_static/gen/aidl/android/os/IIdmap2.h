#pragma once

#include <android/os/FabricatedOverlayInfo.h>
#include <android/os/FabricatedOverlayInternal.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <string>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace os {

class IIdmap2 : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Idmap2)
  virtual ::android::binder::Status getIdmapPath(const ::std::string& overlayApkPath, int32_t userId, ::std::string* _aidl_return) = 0;
  virtual ::android::binder::Status removeIdmap(const ::std::string& overlayApkPath, int32_t userId, bool* _aidl_return) = 0;
  virtual ::android::binder::Status verifyIdmap(const ::std::string& targetApkPath, const ::std::string& overlayApkPath, const ::std::string& overlayName, int32_t fulfilledPolicies, bool enforceOverlayable, int32_t userId, bool* _aidl_return) = 0;
  virtual ::android::binder::Status createIdmap(const ::std::string& targetApkPath, const ::std::string& overlayApkPath, const ::std::string& overlayName, int32_t fulfilledPolicies, bool enforceOverlayable, int32_t userId, ::std::optional<::std::string>* _aidl_return) = 0;
  virtual ::android::binder::Status createFabricatedOverlay(const ::android::os::FabricatedOverlayInternal& overlay, ::std::optional<::android::os::FabricatedOverlayInfo>* _aidl_return) = 0;
  virtual ::android::binder::Status deleteFabricatedOverlay(const ::std::string& path, bool* _aidl_return) = 0;
  virtual ::android::binder::Status acquireFabricatedOverlayIterator() = 0;
  virtual ::android::binder::Status releaseFabricatedOverlayIterator() = 0;
  virtual ::android::binder::Status nextFabricatedOverlayInfos(::std::vector<::android::os::FabricatedOverlayInfo>* _aidl_return) = 0;
  virtual ::android::binder::Status dumpIdmap(const ::std::string& overlayApkPath, ::std::string* _aidl_return) = 0;
};  // class IIdmap2

class IIdmap2Default : public IIdmap2 {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getIdmapPath(const ::std::string&, int32_t, ::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status removeIdmap(const ::std::string&, int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status verifyIdmap(const ::std::string&, const ::std::string&, const ::std::string&, int32_t, bool, int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createIdmap(const ::std::string&, const ::std::string&, const ::std::string&, int32_t, bool, int32_t, ::std::optional<::std::string>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createFabricatedOverlay(const ::android::os::FabricatedOverlayInternal&, ::std::optional<::android::os::FabricatedOverlayInfo>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status deleteFabricatedOverlay(const ::std::string&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status acquireFabricatedOverlayIterator() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status releaseFabricatedOverlayIterator() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status nextFabricatedOverlayInfos(::std::vector<::android::os::FabricatedOverlayInfo>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status dumpIdmap(const ::std::string&, ::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IIdmap2Default

}  // namespace os

}  // namespace android
