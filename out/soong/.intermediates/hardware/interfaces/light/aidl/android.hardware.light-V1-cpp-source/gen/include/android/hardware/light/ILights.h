#pragma once

#include <android/hardware/light/HwLight.h>
#include <android/hardware/light/HwLightState.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace hardware {

namespace light {

class ILights : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Lights)
  const int32_t VERSION = 1;
  const std::string HASH = "33fec8401b6e66bddaeff251e1a2a0f4fa0d3bee";
  virtual ::android::binder::Status setLightState(int32_t id, const ::android::hardware::light::HwLightState& state) = 0;
  virtual ::android::binder::Status getLights(::std::vector<::android::hardware::light::HwLight>* _aidl_return) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class ILights

class ILightsDefault : public ILights {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status setLightState(int32_t, const ::android::hardware::light::HwLightState&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getLights(::std::vector<::android::hardware::light::HwLight>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class ILightsDefault

}  // namespace light

}  // namespace hardware

}  // namespace android
