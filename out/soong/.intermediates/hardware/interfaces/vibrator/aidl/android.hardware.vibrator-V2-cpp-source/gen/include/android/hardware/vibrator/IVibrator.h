#pragma once

#include <android/hardware/vibrator/Braking.h>
#include <android/hardware/vibrator/CompositeEffect.h>
#include <android/hardware/vibrator/CompositePrimitive.h>
#include <android/hardware/vibrator/Effect.h>
#include <android/hardware/vibrator/EffectStrength.h>
#include <android/hardware/vibrator/IVibratorCallback.h>
#include <android/hardware/vibrator/PrimitivePwle.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace hardware {

namespace vibrator {

class IVibrator : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Vibrator)
  const int32_t VERSION = 2;
  const std::string HASH = "ea8742d6993e1a82917da38b9938e537aa7fcb54";
  enum  : int32_t {
    CAP_ON_CALLBACK = 1,
    CAP_PERFORM_CALLBACK = 2,
    CAP_AMPLITUDE_CONTROL = 4,
    CAP_EXTERNAL_CONTROL = 8,
    CAP_EXTERNAL_AMPLITUDE_CONTROL = 16,
    CAP_COMPOSE_EFFECTS = 32,
    CAP_ALWAYS_ON_CONTROL = 64,
    CAP_GET_RESONANT_FREQUENCY = 128,
    CAP_GET_Q_FACTOR = 256,
    CAP_FREQUENCY_CONTROL = 512,
    CAP_COMPOSE_PWLE_EFFECTS = 1024,
  };
  virtual ::android::binder::Status getCapabilities(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status off() = 0;
  virtual ::android::binder::Status on(int32_t timeoutMs, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>& callback) = 0;
  virtual ::android::binder::Status perform(::android::hardware::vibrator::Effect effect, ::android::hardware::vibrator::EffectStrength strength, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>& callback, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getSupportedEffects(::std::vector<::android::hardware::vibrator::Effect>* _aidl_return) = 0;
  virtual ::android::binder::Status setAmplitude(float amplitude) = 0;
  virtual ::android::binder::Status setExternalControl(bool enabled) = 0;
  virtual ::android::binder::Status getCompositionDelayMax(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getCompositionSizeMax(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getSupportedPrimitives(::std::vector<::android::hardware::vibrator::CompositePrimitive>* _aidl_return) = 0;
  virtual ::android::binder::Status getPrimitiveDuration(::android::hardware::vibrator::CompositePrimitive primitive, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status compose(const ::std::vector<::android::hardware::vibrator::CompositeEffect>& composite, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>& callback) = 0;
  virtual ::android::binder::Status getSupportedAlwaysOnEffects(::std::vector<::android::hardware::vibrator::Effect>* _aidl_return) = 0;
  virtual ::android::binder::Status alwaysOnEnable(int32_t id, ::android::hardware::vibrator::Effect effect, ::android::hardware::vibrator::EffectStrength strength) = 0;
  virtual ::android::binder::Status alwaysOnDisable(int32_t id) = 0;
  virtual ::android::binder::Status getResonantFrequency(float* _aidl_return) = 0;
  virtual ::android::binder::Status getQFactor(float* _aidl_return) = 0;
  virtual ::android::binder::Status getFrequencyResolution(float* _aidl_return) = 0;
  virtual ::android::binder::Status getFrequencyMinimum(float* _aidl_return) = 0;
  virtual ::android::binder::Status getBandwidthAmplitudeMap(::std::vector<float>* _aidl_return) = 0;
  virtual ::android::binder::Status getPwlePrimitiveDurationMax(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getPwleCompositionSizeMax(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getSupportedBraking(::std::vector<::android::hardware::vibrator::Braking>* _aidl_return) = 0;
  virtual ::android::binder::Status composePwle(const ::std::vector<::android::hardware::vibrator::PrimitivePwle>& composite, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>& callback) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IVibrator

class IVibratorDefault : public IVibrator {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getCapabilities(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status off() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status on(int32_t, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status perform(::android::hardware::vibrator::Effect, ::android::hardware::vibrator::EffectStrength, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getSupportedEffects(::std::vector<::android::hardware::vibrator::Effect>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setAmplitude(float) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setExternalControl(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCompositionDelayMax(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCompositionSizeMax(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getSupportedPrimitives(::std::vector<::android::hardware::vibrator::CompositePrimitive>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getPrimitiveDuration(::android::hardware::vibrator::CompositePrimitive, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status compose(const ::std::vector<::android::hardware::vibrator::CompositeEffect>&, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getSupportedAlwaysOnEffects(::std::vector<::android::hardware::vibrator::Effect>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status alwaysOnEnable(int32_t, ::android::hardware::vibrator::Effect, ::android::hardware::vibrator::EffectStrength) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status alwaysOnDisable(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getResonantFrequency(float*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getQFactor(float*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getFrequencyResolution(float*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getFrequencyMinimum(float*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getBandwidthAmplitudeMap(::std::vector<float>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getPwlePrimitiveDurationMax(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getPwleCompositionSizeMax(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getSupportedBraking(::std::vector<::android::hardware::vibrator::Braking>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status composePwle(const ::std::vector<::android::hardware::vibrator::PrimitivePwle>&, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IVibratorDefault

}  // namespace vibrator

}  // namespace hardware

}  // namespace android
