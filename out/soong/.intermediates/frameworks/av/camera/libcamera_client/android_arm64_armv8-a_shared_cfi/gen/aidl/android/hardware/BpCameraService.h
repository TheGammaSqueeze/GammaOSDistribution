#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/ICameraService.h>

namespace android {

namespace hardware {

class BpCameraService : public ::android::BpInterface<ICameraService> {
public:
  explicit BpCameraService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpCameraService() = default;
  ::android::binder::Status getNumberOfCameras(int32_t type, int32_t* _aidl_return) override;
  ::android::binder::Status getCameraInfo(int32_t cameraId, ::android::hardware::CameraInfo* _aidl_return) override;
  ::android::binder::Status connect(const ::android::sp<::android::hardware::ICameraClient>& client, int32_t cameraId, const ::android::String16& opPackageName, int32_t clientUid, int32_t clientPid, int32_t targetSdkVersion, ::android::sp<::android::hardware::ICamera>* _aidl_return) override;
  ::android::binder::Status connectDevice(const ::android::sp<::android::hardware::camera2::ICameraDeviceCallbacks>& callbacks, const ::android::String16& cameraId, const ::android::String16& opPackageName, const ::std::optional<::android::String16>& featureId, int32_t clientUid, int32_t oomScoreOffset, int32_t targetSdkVersion, ::android::sp<::android::hardware::camera2::ICameraDeviceUser>* _aidl_return) override;
  ::android::binder::Status addListener(const ::android::sp<::android::hardware::ICameraServiceListener>& listener, ::std::vector<::android::hardware::CameraStatus>* _aidl_return) override;
  ::android::binder::Status getConcurrentCameraIds(::std::vector<::android::hardware::camera2::utils::ConcurrentCameraIdCombination>* _aidl_return) override;
  ::android::binder::Status isConcurrentSessionConfigurationSupported(const ::std::vector<::android::hardware::camera2::utils::CameraIdAndSessionConfiguration>& sessions, int32_t targetSdkVersion, bool* _aidl_return) override;
  ::android::binder::Status removeListener(const ::android::sp<::android::hardware::ICameraServiceListener>& listener) override;
  ::android::binder::Status getCameraCharacteristics(const ::android::String16& cameraId, int32_t targetSdkVersion, ::android::hardware::camera2::impl::CameraMetadataNative* _aidl_return) override;
  ::android::binder::Status getCameraVendorTagDescriptor(::android::hardware::camera2::params::VendorTagDescriptor* _aidl_return) override;
  ::android::binder::Status getCameraVendorTagCache(::android::hardware::camera2::params::VendorTagDescriptorCache* _aidl_return) override;
  ::android::binder::Status getLegacyParameters(int32_t cameraId, ::android::String16* _aidl_return) override;
  ::android::binder::Status supportsCameraApi(const ::android::String16& cameraId, int32_t apiVersion, bool* _aidl_return) override;
  ::android::binder::Status isHiddenPhysicalCamera(const ::android::String16& cameraId, bool* _aidl_return) override;
  ::android::binder::Status injectCamera(const ::android::String16& packageName, const ::android::String16& internalCamId, const ::android::String16& externalCamId, const ::android::sp<::android::hardware::camera2::ICameraInjectionCallback>& CameraInjectionCallback, ::android::sp<::android::hardware::camera2::ICameraInjectionSession>* _aidl_return) override;
  ::android::binder::Status setTorchMode(const ::android::String16& cameraId, bool enabled, const ::android::sp<::android::IBinder>& clientBinder) override;
  ::android::binder::Status notifySystemEvent(int32_t eventId, const ::std::vector<int32_t>& args) override;
  ::android::binder::Status notifyDisplayConfigurationChange() override;
  ::android::binder::Status notifyDeviceStateChange(int64_t newState) override;
};  // class BpCameraService

}  // namespace hardware

}  // namespace android
