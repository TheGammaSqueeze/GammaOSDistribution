#pragma once

#include <android/hardware/ICamera.h>
#include <android/hardware/ICameraClient.h>
#include <android/hardware/ICameraServiceListener.h>
#include <android/hardware/camera2/ICameraDeviceCallbacks.h>
#include <android/hardware/camera2/ICameraDeviceUser.h>
#include <android/hardware/camera2/ICameraInjectionCallback.h>
#include <android/hardware/camera2/ICameraInjectionSession.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <camera/CameraBase.h>
#include <camera/CameraMetadata.h>
#include <camera/VendorTagDescriptor.h>
#include <camera/camera2/ConcurrentCamera.h>
#include <cstdint>
#include <optional>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace hardware {

class ICameraService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(CameraService)
  enum  : int32_t {
    ERROR_PERMISSION_DENIED = 1,
    ERROR_ALREADY_EXISTS = 2,
    ERROR_ILLEGAL_ARGUMENT = 3,
    ERROR_DISCONNECTED = 4,
    ERROR_TIMED_OUT = 5,
    ERROR_DISABLED = 6,
    ERROR_CAMERA_IN_USE = 7,
    ERROR_MAX_CAMERAS_IN_USE = 8,
    ERROR_DEPRECATED_HAL = 9,
    ERROR_INVALID_OPERATION = 10,
    CAMERA_TYPE_BACKWARD_COMPATIBLE = 0,
    CAMERA_TYPE_ALL = 1,
    USE_CALLING_UID = -1,
    USE_CALLING_PID = -1,
    API_VERSION_1 = 1,
    API_VERSION_2 = 2,
    EVENT_NONE = 0,
    EVENT_USER_SWITCHED = 1,
    DEVICE_STATE_NORMAL = 0,
    DEVICE_STATE_BACK_COVERED = 1,
    DEVICE_STATE_FRONT_COVERED = 2,
    DEVICE_STATE_FOLDED = 4,
    DEVICE_STATE_LAST_FRAMEWORK_BIT = -2147483648,
  };
  virtual ::android::binder::Status getNumberOfCameras(int32_t type, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getCameraInfo(int32_t cameraId, ::android::hardware::CameraInfo* _aidl_return) = 0;
  virtual ::android::binder::Status connect(const ::android::sp<::android::hardware::ICameraClient>& client, int32_t cameraId, const ::android::String16& opPackageName, int32_t clientUid, int32_t clientPid, int32_t targetSdkVersion, ::android::sp<::android::hardware::ICamera>* _aidl_return) = 0;
  virtual ::android::binder::Status connectDevice(const ::android::sp<::android::hardware::camera2::ICameraDeviceCallbacks>& callbacks, const ::android::String16& cameraId, const ::android::String16& opPackageName, const ::std::optional<::android::String16>& featureId, int32_t clientUid, int32_t oomScoreOffset, int32_t targetSdkVersion, ::android::sp<::android::hardware::camera2::ICameraDeviceUser>* _aidl_return) = 0;
  virtual ::android::binder::Status addListener(const ::android::sp<::android::hardware::ICameraServiceListener>& listener, ::std::vector<::android::hardware::CameraStatus>* _aidl_return) = 0;
  virtual ::android::binder::Status getConcurrentCameraIds(::std::vector<::android::hardware::camera2::utils::ConcurrentCameraIdCombination>* _aidl_return) = 0;
  virtual ::android::binder::Status isConcurrentSessionConfigurationSupported(const ::std::vector<::android::hardware::camera2::utils::CameraIdAndSessionConfiguration>& sessions, int32_t targetSdkVersion, bool* _aidl_return) = 0;
  virtual ::android::binder::Status removeListener(const ::android::sp<::android::hardware::ICameraServiceListener>& listener) = 0;
  virtual ::android::binder::Status getCameraCharacteristics(const ::android::String16& cameraId, int32_t targetSdkVersion, ::android::hardware::camera2::impl::CameraMetadataNative* _aidl_return) = 0;
  virtual ::android::binder::Status getCameraVendorTagDescriptor(::android::hardware::camera2::params::VendorTagDescriptor* _aidl_return) = 0;
  virtual ::android::binder::Status getCameraVendorTagCache(::android::hardware::camera2::params::VendorTagDescriptorCache* _aidl_return) = 0;
  virtual ::android::binder::Status getLegacyParameters(int32_t cameraId, ::android::String16* _aidl_return) = 0;
  virtual ::android::binder::Status supportsCameraApi(const ::android::String16& cameraId, int32_t apiVersion, bool* _aidl_return) = 0;
  virtual ::android::binder::Status isHiddenPhysicalCamera(const ::android::String16& cameraId, bool* _aidl_return) = 0;
  virtual ::android::binder::Status injectCamera(const ::android::String16& packageName, const ::android::String16& internalCamId, const ::android::String16& externalCamId, const ::android::sp<::android::hardware::camera2::ICameraInjectionCallback>& CameraInjectionCallback, ::android::sp<::android::hardware::camera2::ICameraInjectionSession>* _aidl_return) = 0;
  virtual ::android::binder::Status setTorchMode(const ::android::String16& cameraId, bool enabled, const ::android::sp<::android::IBinder>& clientBinder) = 0;
  virtual ::android::binder::Status notifySystemEvent(int32_t eventId, const ::std::vector<int32_t>& args) = 0;
  virtual ::android::binder::Status notifyDisplayConfigurationChange() = 0;
  virtual ::android::binder::Status notifyDeviceStateChange(int64_t newState) = 0;
};  // class ICameraService

class ICameraServiceDefault : public ICameraService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getNumberOfCameras(int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCameraInfo(int32_t, ::android::hardware::CameraInfo*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status connect(const ::android::sp<::android::hardware::ICameraClient>&, int32_t, const ::android::String16&, int32_t, int32_t, int32_t, ::android::sp<::android::hardware::ICamera>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status connectDevice(const ::android::sp<::android::hardware::camera2::ICameraDeviceCallbacks>&, const ::android::String16&, const ::android::String16&, const ::std::optional<::android::String16>&, int32_t, int32_t, int32_t, ::android::sp<::android::hardware::camera2::ICameraDeviceUser>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status addListener(const ::android::sp<::android::hardware::ICameraServiceListener>&, ::std::vector<::android::hardware::CameraStatus>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getConcurrentCameraIds(::std::vector<::android::hardware::camera2::utils::ConcurrentCameraIdCombination>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isConcurrentSessionConfigurationSupported(const ::std::vector<::android::hardware::camera2::utils::CameraIdAndSessionConfiguration>&, int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status removeListener(const ::android::sp<::android::hardware::ICameraServiceListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCameraCharacteristics(const ::android::String16&, int32_t, ::android::hardware::camera2::impl::CameraMetadataNative*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCameraVendorTagDescriptor(::android::hardware::camera2::params::VendorTagDescriptor*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCameraVendorTagCache(::android::hardware::camera2::params::VendorTagDescriptorCache*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getLegacyParameters(int32_t, ::android::String16*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status supportsCameraApi(const ::android::String16&, int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isHiddenPhysicalCamera(const ::android::String16&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status injectCamera(const ::android::String16&, const ::android::String16&, const ::android::String16&, const ::android::sp<::android::hardware::camera2::ICameraInjectionCallback>&, ::android::sp<::android::hardware::camera2::ICameraInjectionSession>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setTorchMode(const ::android::String16&, bool, const ::android::sp<::android::IBinder>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status notifySystemEvent(int32_t, const ::std::vector<int32_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status notifyDisplayConfigurationChange() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status notifyDeviceStateChange(int64_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICameraServiceDefault

}  // namespace hardware

}  // namespace android
