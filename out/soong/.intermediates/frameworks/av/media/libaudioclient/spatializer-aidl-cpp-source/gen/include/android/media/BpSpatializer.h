#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/ISpatializer.h>

namespace android {

namespace media {

class BpSpatializer : public ::android::BpInterface<ISpatializer> {
public:
  explicit BpSpatializer(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpSpatializer() = default;
  ::android::binder::Status release() override;
  ::android::binder::Status getSupportedLevels(::std::vector<::android::media::SpatializationLevel>* _aidl_return) override;
  ::android::binder::Status setLevel(::android::media::SpatializationLevel level) override;
  ::android::binder::Status getLevel(::android::media::SpatializationLevel* _aidl_return) override;
  ::android::binder::Status isHeadTrackingSupported(bool* _aidl_return) override;
  ::android::binder::Status getSupportedHeadTrackingModes(::std::vector<::android::media::SpatializerHeadTrackingMode>* _aidl_return) override;
  ::android::binder::Status setDesiredHeadTrackingMode(::android::media::SpatializerHeadTrackingMode mode) override;
  ::android::binder::Status getActualHeadTrackingMode(::android::media::SpatializerHeadTrackingMode* _aidl_return) override;
  ::android::binder::Status recenterHeadTracker() override;
  ::android::binder::Status setGlobalTransform(const ::std::vector<float>& screenToStage) override;
  ::android::binder::Status setHeadSensor(int32_t sensorHandle) override;
  ::android::binder::Status setScreenSensor(int32_t sensorHandle) override;
  ::android::binder::Status setDisplayOrientation(float physicalToLogicalAngle) override;
  ::android::binder::Status setHingeAngle(float hingeAngle) override;
  ::android::binder::Status getSupportedModes(::std::vector<::android::media::SpatializationMode>* _aidl_return) override;
  ::android::binder::Status registerHeadTrackingCallback(const ::android::sp<::android::media::ISpatializerHeadTrackingCallback>& callback) override;
  ::android::binder::Status setParameter(int32_t key, const ::std::vector<uint8_t>& value) override;
  ::android::binder::Status getParameter(int32_t key, ::std::vector<uint8_t>* value) override;
  ::android::binder::Status getOutput(int32_t* _aidl_return) override;
};  // class BpSpatializer

}  // namespace media

}  // namespace android
