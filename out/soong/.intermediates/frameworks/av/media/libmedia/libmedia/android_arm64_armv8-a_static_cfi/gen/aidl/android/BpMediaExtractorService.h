#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/IMediaExtractorService.h>

namespace android {

class BpMediaExtractorService : public ::android::BpInterface<IMediaExtractorService> {
public:
  explicit BpMediaExtractorService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpMediaExtractorService() = default;
  ::android::binder::Status makeExtractor(const ::android::sp<::android::IDataSource>& source, const ::std::optional<::std::string>& mime, ::android::sp<::android::IMediaExtractor>* _aidl_return) override;
  ::android::binder::Status makeIDataSource(::android::base::unique_fd fd, int64_t offset, int64_t length, ::android::sp<::android::IDataSource>* _aidl_return) override;
  ::android::binder::Status getSupportedTypes(::std::vector<::std::string>* _aidl_return) override;
};  // class BpMediaExtractorService

}  // namespace android
