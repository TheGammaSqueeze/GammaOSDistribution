#pragma once

#include <android/os/IUpdateEngineCallback.h>
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

class IUpdateEngine : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(UpdateEngine)
  virtual ::android::binder::Status applyPayload(const ::android::String16& url, int64_t payload_offset, int64_t payload_size, const ::std::vector<::android::String16>& headerKeyValuePairs) = 0;
  virtual ::android::binder::Status applyPayloadFd(const ::android::os::ParcelFileDescriptor& pfd, int64_t payload_offset, int64_t payload_size, const ::std::vector<::android::String16>& headerKeyValuePairs) = 0;
  virtual ::android::binder::Status bind(const ::android::sp<::android::os::IUpdateEngineCallback>& callback, bool* _aidl_return) = 0;
  virtual ::android::binder::Status unbind(const ::android::sp<::android::os::IUpdateEngineCallback>& callback, bool* _aidl_return) = 0;
  virtual ::android::binder::Status suspend() = 0;
  virtual ::android::binder::Status resume() = 0;
  virtual ::android::binder::Status cancel() = 0;
  virtual ::android::binder::Status resetStatus() = 0;
  virtual ::android::binder::Status verifyPayloadApplicable(const ::android::String16& metadataFilename, bool* _aidl_return) = 0;
  virtual ::android::binder::Status allocateSpaceForPayload(const ::android::String16& metadataFilename, const ::std::vector<::android::String16>& headerKeyValuePairs, int64_t* _aidl_return) = 0;
  virtual ::android::binder::Status cleanupSuccessfulUpdate(const ::android::sp<::android::os::IUpdateEngineCallback>& callback) = 0;
  virtual ::android::binder::Status setPerformanceMode(bool enable) = 0;
};  // class IUpdateEngine

class IUpdateEngineDefault : public IUpdateEngine {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status applyPayload(const ::android::String16&, int64_t, int64_t, const ::std::vector<::android::String16>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status applyPayloadFd(const ::android::os::ParcelFileDescriptor&, int64_t, int64_t, const ::std::vector<::android::String16>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status bind(const ::android::sp<::android::os::IUpdateEngineCallback>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unbind(const ::android::sp<::android::os::IUpdateEngineCallback>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status suspend() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status resume() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status cancel() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status resetStatus() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status verifyPayloadApplicable(const ::android::String16&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status allocateSpaceForPayload(const ::android::String16&, const ::std::vector<::android::String16>&, int64_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status cleanupSuccessfulUpdate(const ::android::sp<::android::os::IUpdateEngineCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setPerformanceMode(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IUpdateEngineDefault

}  // namespace os

}  // namespace android
