#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/camera2/ICameraDeviceUser.h>

namespace android {

namespace hardware {

namespace camera2 {

class BpCameraDeviceUser : public ::android::BpInterface<ICameraDeviceUser> {
public:
  explicit BpCameraDeviceUser(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpCameraDeviceUser() = default;
  ::android::binder::Status disconnect() override;
  ::android::binder::Status submitRequest(const ::android::hardware::camera2::CaptureRequest& request, bool streaming, ::android::hardware::camera2::utils::SubmitInfo* _aidl_return) override;
  ::android::binder::Status submitRequestList(const ::std::vector<::android::hardware::camera2::CaptureRequest>& requestList, bool streaming, ::android::hardware::camera2::utils::SubmitInfo* _aidl_return) override;
  ::android::binder::Status cancelRequest(int32_t requestId, int64_t* _aidl_return) override;
  ::android::binder::Status beginConfigure() override;
  ::android::binder::Status endConfigure(int32_t operatingMode, const ::android::hardware::camera2::impl::CameraMetadataNative& sessionParams, int64_t startTimeMs, ::std::vector<int32_t>* _aidl_return) override;
  ::android::binder::Status isSessionConfigurationSupported(const ::android::hardware::camera2::params::SessionConfiguration& sessionConfiguration, bool* _aidl_return) override;
  ::android::binder::Status deleteStream(int32_t streamId) override;
  ::android::binder::Status createStream(const ::android::hardware::camera2::params::OutputConfiguration& outputConfiguration, int32_t* _aidl_return) override;
  ::android::binder::Status createInputStream(int32_t width, int32_t height, int32_t format, bool isMultiResolution, int32_t* _aidl_return) override;
  ::android::binder::Status getInputSurface(::android::view::Surface* _aidl_return) override;
  ::android::binder::Status createDefaultRequest(int32_t templateId, ::android::hardware::camera2::impl::CameraMetadataNative* _aidl_return) override;
  ::android::binder::Status getCameraInfo(::android::hardware::camera2::impl::CameraMetadataNative* _aidl_return) override;
  ::android::binder::Status waitUntilIdle() override;
  ::android::binder::Status flush(int64_t* _aidl_return) override;
  ::android::binder::Status prepare(int32_t streamId) override;
  ::android::binder::Status tearDown(int32_t streamId) override;
  ::android::binder::Status prepare2(int32_t maxCount, int32_t streamId) override;
  ::android::binder::Status updateOutputConfiguration(int32_t streamId, const ::android::hardware::camera2::params::OutputConfiguration& outputConfiguration) override;
  ::android::binder::Status finalizeOutputConfigurations(int32_t streamId, const ::android::hardware::camera2::params::OutputConfiguration& outputConfiguration) override;
  ::android::binder::Status setCameraAudioRestriction(int32_t mode) override;
  ::android::binder::Status getGlobalAudioRestriction(int32_t* _aidl_return) override;
  ::android::binder::Status switchToOffline(const ::android::sp<::android::hardware::camera2::ICameraDeviceCallbacks>& callbacks, const ::std::vector<int32_t>& offlineOutputIds, ::android::sp<::android::hardware::camera2::ICameraOfflineSession>* _aidl_return) override;
};  // class BpCameraDeviceUser

}  // namespace camera2

}  // namespace hardware

}  // namespace android
