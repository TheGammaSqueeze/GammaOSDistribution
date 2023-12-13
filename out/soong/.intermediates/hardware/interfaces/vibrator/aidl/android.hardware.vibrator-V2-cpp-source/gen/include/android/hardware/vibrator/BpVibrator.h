#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/vibrator/IVibrator.h>

namespace android {

namespace hardware {

namespace vibrator {

class BpVibrator : public ::android::BpInterface<IVibrator> {
public:
  explicit BpVibrator(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpVibrator() = default;
  ::android::binder::Status getCapabilities(int32_t* _aidl_return) override;
  ::android::binder::Status off() override;
  ::android::binder::Status on(int32_t timeoutMs, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>& callback) override;
  ::android::binder::Status perform(::android::hardware::vibrator::Effect effect, ::android::hardware::vibrator::EffectStrength strength, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>& callback, int32_t* _aidl_return) override;
  ::android::binder::Status getSupportedEffects(::std::vector<::android::hardware::vibrator::Effect>* _aidl_return) override;
  ::android::binder::Status setAmplitude(float amplitude) override;
  ::android::binder::Status setExternalControl(bool enabled) override;
  ::android::binder::Status getCompositionDelayMax(int32_t* _aidl_return) override;
  ::android::binder::Status getCompositionSizeMax(int32_t* _aidl_return) override;
  ::android::binder::Status getSupportedPrimitives(::std::vector<::android::hardware::vibrator::CompositePrimitive>* _aidl_return) override;
  ::android::binder::Status getPrimitiveDuration(::android::hardware::vibrator::CompositePrimitive primitive, int32_t* _aidl_return) override;
  ::android::binder::Status compose(const ::std::vector<::android::hardware::vibrator::CompositeEffect>& composite, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>& callback) override;
  ::android::binder::Status getSupportedAlwaysOnEffects(::std::vector<::android::hardware::vibrator::Effect>* _aidl_return) override;
  ::android::binder::Status alwaysOnEnable(int32_t id, ::android::hardware::vibrator::Effect effect, ::android::hardware::vibrator::EffectStrength strength) override;
  ::android::binder::Status alwaysOnDisable(int32_t id) override;
  ::android::binder::Status getResonantFrequency(float* _aidl_return) override;
  ::android::binder::Status getQFactor(float* _aidl_return) override;
  ::android::binder::Status getFrequencyResolution(float* _aidl_return) override;
  ::android::binder::Status getFrequencyMinimum(float* _aidl_return) override;
  ::android::binder::Status getBandwidthAmplitudeMap(::std::vector<float>* _aidl_return) override;
  ::android::binder::Status getPwlePrimitiveDurationMax(int32_t* _aidl_return) override;
  ::android::binder::Status getPwleCompositionSizeMax(int32_t* _aidl_return) override;
  ::android::binder::Status getSupportedBraking(::std::vector<::android::hardware::vibrator::Braking>* _aidl_return) override;
  ::android::binder::Status composePwle(const ::std::vector<::android::hardware::vibrator::PrimitivePwle>& composite, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>& callback) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpVibrator

}  // namespace vibrator

}  // namespace hardware

}  // namespace android
