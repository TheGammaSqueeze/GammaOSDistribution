#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/light/ILights.h>

namespace android {

namespace hardware {

namespace light {

class BpLights : public ::android::BpInterface<ILights> {
public:
  explicit BpLights(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpLights() = default;
  ::android::binder::Status setLightState(int32_t id, const ::android::hardware::light::HwLightState& state) override;
  ::android::binder::Status getLights(::std::vector<::android::hardware::light::HwLight>* _aidl_return) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpLights

}  // namespace light

}  // namespace hardware

}  // namespace android
