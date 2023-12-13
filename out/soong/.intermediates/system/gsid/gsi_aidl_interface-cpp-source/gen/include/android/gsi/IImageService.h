#pragma once

#include <android/gsi/AvbPublicKey.h>
#include <android/gsi/IProgressCallback.h>
#include <android/gsi/MappedImage.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <string>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace gsi {

class IImageService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(ImageService)
  enum  : int32_t {
    CREATE_IMAGE_DEFAULT = 0,
    CREATE_IMAGE_READONLY = 1,
    CREATE_IMAGE_ZERO_FILL = 2,
    IMAGE_OK = 0,
    IMAGE_ERROR = 1,
  };
  virtual ::android::binder::Status createBackingImage(const ::std::string& name, int64_t size, int32_t flags, const ::android::sp<::android::gsi::IProgressCallback>& on_progress) = 0;
  virtual ::android::binder::Status deleteBackingImage(const ::std::string& name) = 0;
  virtual ::android::binder::Status mapImageDevice(const ::std::string& name, int32_t timeout_ms, ::android::gsi::MappedImage* mapping) = 0;
  virtual ::android::binder::Status unmapImageDevice(const ::std::string& name) = 0;
  virtual ::android::binder::Status backingImageExists(const ::std::string& name, bool* _aidl_return) = 0;
  virtual ::android::binder::Status isImageMapped(const ::std::string& name, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getAvbPublicKey(const ::std::string& name, ::android::gsi::AvbPublicKey* dst, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getAllBackingImages(::std::vector<::std::string>* _aidl_return) = 0;
  virtual ::android::binder::Status zeroFillNewImage(const ::std::string& name, int64_t bytes) = 0;
  virtual ::android::binder::Status removeAllImages() = 0;
  virtual ::android::binder::Status removeDisabledImages() = 0;
  virtual ::android::binder::Status getMappedImageDevice(const ::std::string& name, ::std::string* _aidl_return) = 0;
};  // class IImageService

class IImageServiceDefault : public IImageService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status createBackingImage(const ::std::string&, int64_t, int32_t, const ::android::sp<::android::gsi::IProgressCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status deleteBackingImage(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status mapImageDevice(const ::std::string&, int32_t, ::android::gsi::MappedImage*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unmapImageDevice(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status backingImageExists(const ::std::string&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isImageMapped(const ::std::string&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getAvbPublicKey(const ::std::string&, ::android::gsi::AvbPublicKey*, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getAllBackingImages(::std::vector<::std::string>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status zeroFillNewImage(const ::std::string&, int64_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status removeAllImages() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status removeDisabledImages() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getMappedImageDevice(const ::std::string&, ::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IImageServiceDefault

}  // namespace gsi

}  // namespace android
