#pragma once

#include <android-base/unique_fd.h>
#include <android/IDataSource.h>
#include <android/IMediaExtractor.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <string>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

class IMediaExtractorService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(MediaExtractorService)
  virtual ::android::binder::Status makeExtractor(const ::android::sp<::android::IDataSource>& source, const ::std::optional<::std::string>& mime, ::android::sp<::android::IMediaExtractor>* _aidl_return) = 0;
  virtual ::android::binder::Status makeIDataSource(::android::base::unique_fd fd, int64_t offset, int64_t length, ::android::sp<::android::IDataSource>* _aidl_return) = 0;
  virtual ::android::binder::Status getSupportedTypes(::std::vector<::std::string>* _aidl_return) = 0;
};  // class IMediaExtractorService

class IMediaExtractorServiceDefault : public IMediaExtractorService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status makeExtractor(const ::android::sp<::android::IDataSource>&, const ::std::optional<::std::string>&, ::android::sp<::android::IMediaExtractor>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status makeIDataSource(::android::base::unique_fd, int64_t, int64_t, ::android::sp<::android::IDataSource>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getSupportedTypes(::std::vector<::std::string>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IMediaExtractorServiceDefault

}  // namespace android
