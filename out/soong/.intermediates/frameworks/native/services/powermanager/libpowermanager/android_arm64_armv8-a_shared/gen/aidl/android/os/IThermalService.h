#pragma once

#include <android/CoolingDevice.h>
#include <android/Temperature.h>
#include <android/os/IThermalEventListener.h>
#include <android/os/IThermalStatusListener.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace os {

class IThermalService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(ThermalService)
  virtual ::android::binder::Status registerThermalEventListener(const ::android::sp<::android::os::IThermalEventListener>& listener, bool* _aidl_return) = 0;
  virtual ::android::binder::Status registerThermalEventListenerWithType(const ::android::sp<::android::os::IThermalEventListener>& listener, int32_t type, bool* _aidl_return) = 0;
  virtual ::android::binder::Status unregisterThermalEventListener(const ::android::sp<::android::os::IThermalEventListener>& listener, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getCurrentTemperatures(::std::vector<::android::os::Temperature>* _aidl_return) = 0;
  virtual ::android::binder::Status getCurrentTemperaturesWithType(int32_t type, ::std::vector<::android::os::Temperature>* _aidl_return) = 0;
  virtual ::android::binder::Status registerThermalStatusListener(const ::android::sp<::android::os::IThermalStatusListener>& listener, bool* _aidl_return) = 0;
  virtual ::android::binder::Status unregisterThermalStatusListener(const ::android::sp<::android::os::IThermalStatusListener>& listener, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getCurrentThermalStatus(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getCurrentCoolingDevices(::std::vector<::android::os::CoolingDevice>* _aidl_return) = 0;
  virtual ::android::binder::Status getCurrentCoolingDevicesWithType(int32_t type, ::std::vector<::android::os::CoolingDevice>* _aidl_return) = 0;
  virtual ::android::binder::Status getThermalHeadroom(int32_t forecastSeconds, float* _aidl_return) = 0;
};  // class IThermalService

class IThermalServiceDefault : public IThermalService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status registerThermalEventListener(const ::android::sp<::android::os::IThermalEventListener>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status registerThermalEventListenerWithType(const ::android::sp<::android::os::IThermalEventListener>&, int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unregisterThermalEventListener(const ::android::sp<::android::os::IThermalEventListener>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCurrentTemperatures(::std::vector<::android::os::Temperature>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCurrentTemperaturesWithType(int32_t, ::std::vector<::android::os::Temperature>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status registerThermalStatusListener(const ::android::sp<::android::os::IThermalStatusListener>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unregisterThermalStatusListener(const ::android::sp<::android::os::IThermalStatusListener>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCurrentThermalStatus(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCurrentCoolingDevices(::std::vector<::android::os::CoolingDevice>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCurrentCoolingDevicesWithType(int32_t, ::std::vector<::android::os::CoolingDevice>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getThermalHeadroom(int32_t, float*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IThermalServiceDefault

}  // namespace os

}  // namespace android
