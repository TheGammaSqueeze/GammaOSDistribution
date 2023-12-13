#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/gsi/IImageService.h>

namespace android {

namespace gsi {

class BpImageService : public ::android::BpInterface<IImageService> {
public:
  explicit BpImageService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpImageService() = default;
  ::android::binder::Status createBackingImage(const ::std::string& name, int64_t size, int32_t flags, const ::android::sp<::android::gsi::IProgressCallback>& on_progress) override;
  ::android::binder::Status deleteBackingImage(const ::std::string& name) override;
  ::android::binder::Status mapImageDevice(const ::std::string& name, int32_t timeout_ms, ::android::gsi::MappedImage* mapping) override;
  ::android::binder::Status unmapImageDevice(const ::std::string& name) override;
  ::android::binder::Status backingImageExists(const ::std::string& name, bool* _aidl_return) override;
  ::android::binder::Status isImageMapped(const ::std::string& name, bool* _aidl_return) override;
  ::android::binder::Status getAvbPublicKey(const ::std::string& name, ::android::gsi::AvbPublicKey* dst, int32_t* _aidl_return) override;
  ::android::binder::Status getAllBackingImages(::std::vector<::std::string>* _aidl_return) override;
  ::android::binder::Status zeroFillNewImage(const ::std::string& name, int64_t bytes) override;
  ::android::binder::Status removeAllImages() override;
  ::android::binder::Status removeDisabledImages() override;
  ::android::binder::Status getMappedImageDevice(const ::std::string& name, ::std::string* _aidl_return) override;
};  // class BpImageService

}  // namespace gsi

}  // namespace android
