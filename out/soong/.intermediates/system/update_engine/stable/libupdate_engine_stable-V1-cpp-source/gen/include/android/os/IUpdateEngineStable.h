#pragma once

#include <android/os/IUpdateEngineStableCallback.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/ParcelFileDescriptor.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace os {

class IUpdateEngineStable : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(UpdateEngineStable)
  const int32_t VERSION = 1;
  const std::string HASH = "526043ea6cb098d53a9c3e778420e64c4e864d8c";
  virtual ::android::binder::Status applyPayloadFd(const ::android::os::ParcelFileDescriptor& pfd, int64_t payload_offset, int64_t payload_size, const ::std::vector<::android::String16>& headerKeyValuePairs) = 0;
  virtual ::android::binder::Status bind(const ::android::sp<::android::os::IUpdateEngineStableCallback>& callback, bool* _aidl_return) = 0;
  virtual ::android::binder::Status unbind(const ::android::sp<::android::os::IUpdateEngineStableCallback>& callback, bool* _aidl_return) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IUpdateEngineStable

class IUpdateEngineStableDefault : public IUpdateEngineStable {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status applyPayloadFd(const ::android::os::ParcelFileDescriptor&, int64_t, int64_t, const ::std::vector<::android::String16>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status bind(const ::android::sp<::android::os::IUpdateEngineStableCallback>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unbind(const ::android::sp<::android::os::IUpdateEngineStableCallback>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IUpdateEngineStableDefault

}  // namespace os

}  // namespace android
