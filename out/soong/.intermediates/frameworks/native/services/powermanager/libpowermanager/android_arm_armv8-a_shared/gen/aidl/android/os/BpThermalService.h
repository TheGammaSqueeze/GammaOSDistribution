#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IThermalService.h>

namespace android {

namespace os {

class BpThermalService : public ::android::BpInterface<IThermalService> {
public:
  explicit BpThermalService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpThermalService() = default;
  ::android::binder::Status registerThermalEventListener(const ::android::sp<::android::os::IThermalEventListener>& listener, bool* _aidl_return) override;
  ::android::binder::Status registerThermalEventListenerWithType(const ::android::sp<::android::os::IThermalEventListener>& listener, int32_t type, bool* _aidl_return) override;
  ::android::binder::Status unregisterThermalEventListener(const ::android::sp<::android::os::IThermalEventListener>& listener, bool* _aidl_return) override;
  ::android::binder::Status getCurrentTemperatures(::std::vector<::android::os::Temperature>* _aidl_return) override;
  ::android::binder::Status getCurrentTemperaturesWithType(int32_t type, ::std::vector<::android::os::Temperature>* _aidl_return) override;
  ::android::binder::Status registerThermalStatusListener(const ::android::sp<::android::os::IThermalStatusListener>& listener, bool* _aidl_return) override;
  ::android::binder::Status unregisterThermalStatusListener(const ::android::sp<::android::os::IThermalStatusListener>& listener, bool* _aidl_return) override;
  ::android::binder::Status getCurrentThermalStatus(int32_t* _aidl_return) override;
  ::android::binder::Status getCurrentCoolingDevices(::std::vector<::android::os::CoolingDevice>* _aidl_return) override;
  ::android::binder::Status getCurrentCoolingDevicesWithType(int32_t type, ::std::vector<::android::os::CoolingDevice>* _aidl_return) override;
  ::android::binder::Status getThermalHeadroom(int32_t forecastSeconds, float* _aidl_return) override;
};  // class BpThermalService

}  // namespace os

}  // namespace android
