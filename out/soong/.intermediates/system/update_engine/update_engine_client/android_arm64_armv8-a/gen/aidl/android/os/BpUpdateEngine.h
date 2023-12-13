#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IUpdateEngine.h>

namespace android {

namespace os {

class BpUpdateEngine : public ::android::BpInterface<IUpdateEngine> {
public:
  explicit BpUpdateEngine(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpUpdateEngine() = default;
  ::android::binder::Status applyPayload(const ::android::String16& url, int64_t payload_offset, int64_t payload_size, const ::std::vector<::android::String16>& headerKeyValuePairs) override;
  ::android::binder::Status applyPayloadFd(const ::android::os::ParcelFileDescriptor& pfd, int64_t payload_offset, int64_t payload_size, const ::std::vector<::android::String16>& headerKeyValuePairs) override;
  ::android::binder::Status bind(const ::android::sp<::android::os::IUpdateEngineCallback>& callback, bool* _aidl_return) override;
  ::android::binder::Status unbind(const ::android::sp<::android::os::IUpdateEngineCallback>& callback, bool* _aidl_return) override;
  ::android::binder::Status suspend() override;
  ::android::binder::Status resume() override;
  ::android::binder::Status cancel() override;
  ::android::binder::Status resetStatus() override;
  ::android::binder::Status verifyPayloadApplicable(const ::android::String16& metadataFilename, bool* _aidl_return) override;
  ::android::binder::Status allocateSpaceForPayload(const ::android::String16& metadataFilename, const ::std::vector<::android::String16>& headerKeyValuePairs, int64_t* _aidl_return) override;
  ::android::binder::Status cleanupSuccessfulUpdate(const ::android::sp<::android::os::IUpdateEngineCallback>& callback) override;
  ::android::binder::Status setPerformanceMode(bool enable) override;
};  // class BpUpdateEngine

}  // namespace os

}  // namespace android
