#pragma once

#include <android/media/ISpatializerHeadTrackingCallback.h>
#include <android/media/SpatializationLevel.h>
#include <android/media/SpatializationMode.h>
#include <android/media/SpatializerHeadTrackingMode.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace media {

class ISpatializer : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Spatializer)
  virtual ::android::binder::Status release() = 0;
  virtual ::android::binder::Status getSupportedLevels(::std::vector<::android::media::SpatializationLevel>* _aidl_return) = 0;
  virtual ::android::binder::Status setLevel(::android::media::SpatializationLevel level) = 0;
  virtual ::android::binder::Status getLevel(::android::media::SpatializationLevel* _aidl_return) = 0;
  virtual ::android::binder::Status isHeadTrackingSupported(bool* _aidl_return) = 0;
  virtual ::android::binder::Status getSupportedHeadTrackingModes(::std::vector<::android::media::SpatializerHeadTrackingMode>* _aidl_return) = 0;
  virtual ::android::binder::Status setDesiredHeadTrackingMode(::android::media::SpatializerHeadTrackingMode mode) = 0;
  virtual ::android::binder::Status getActualHeadTrackingMode(::android::media::SpatializerHeadTrackingMode* _aidl_return) = 0;
  virtual ::android::binder::Status recenterHeadTracker() = 0;
  virtual ::android::binder::Status setGlobalTransform(const ::std::vector<float>& screenToStage) = 0;
  virtual ::android::binder::Status setHeadSensor(int32_t sensorHandle) = 0;
  virtual ::android::binder::Status setScreenSensor(int32_t sensorHandle) = 0;
  virtual ::android::binder::Status setDisplayOrientation(float physicalToLogicalAngle) = 0;
  virtual ::android::binder::Status setHingeAngle(float hingeAngle) = 0;
  virtual ::android::binder::Status getSupportedModes(::std::vector<::android::media::SpatializationMode>* _aidl_return) = 0;
  virtual ::android::binder::Status registerHeadTrackingCallback(const ::android::sp<::android::media::ISpatializerHeadTrackingCallback>& callback) = 0;
  virtual ::android::binder::Status setParameter(int32_t key, const ::std::vector<uint8_t>& value) = 0;
  virtual ::android::binder::Status getParameter(int32_t key, ::std::vector<uint8_t>* value) = 0;
  virtual ::android::binder::Status getOutput(int32_t* _aidl_return) = 0;
};  // class ISpatializer

class ISpatializerDefault : public ISpatializer {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status release() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getSupportedLevels(::std::vector<::android::media::SpatializationLevel>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setLevel(::android::media::SpatializationLevel) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getLevel(::android::media::SpatializationLevel*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isHeadTrackingSupported(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getSupportedHeadTrackingModes(::std::vector<::android::media::SpatializerHeadTrackingMode>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setDesiredHeadTrackingMode(::android::media::SpatializerHeadTrackingMode) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getActualHeadTrackingMode(::android::media::SpatializerHeadTrackingMode*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status recenterHeadTracker() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setGlobalTransform(const ::std::vector<float>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setHeadSensor(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setScreenSensor(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setDisplayOrientation(float) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setHingeAngle(float) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getSupportedModes(::std::vector<::android::media::SpatializationMode>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status registerHeadTrackingCallback(const ::android::sp<::android::media::ISpatializerHeadTrackingCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setParameter(int32_t, const ::std::vector<uint8_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getParameter(int32_t, ::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getOutput(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ISpatializerDefault

}  // namespace media

}  // namespace android
