#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IPowerManager.h>

namespace android {

namespace os {

class BpPowerManager : public ::android::BpInterface<IPowerManager> {
public:
  explicit BpPowerManager(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpPowerManager() = default;
  ::android::binder::Status acquireWakeLock(const ::android::sp<::android::IBinder>& lock, int32_t flags, const ::android::String16& tag, const ::android::String16& packageName, const ::android::os::WorkSource& ws, const ::android::String16& historyTag, int32_t displayId) override;
  ::android::binder::Status acquireWakeLockWithUid(const ::android::sp<::android::IBinder>& lock, int32_t flags, const ::android::String16& tag, const ::android::String16& packageName, int32_t uidtoblame, int32_t displayId) override;
  ::android::binder::Status releaseWakeLock(const ::android::sp<::android::IBinder>& lock, int32_t flags) override;
  ::android::binder::Status updateWakeLockUids(const ::android::sp<::android::IBinder>& lock, const ::std::vector<int32_t>& uids) override;
  ::android::binder::Status setPowerBoost(int32_t boost, int32_t durationMs) override;
  ::android::binder::Status setPowerMode(int32_t mode, bool enabled) override;
  ::android::binder::Status setPowerModeChecked(int32_t mode, bool enabled, bool* _aidl_return) override;
  ::android::binder::Status updateWakeLockWorkSource(const ::android::sp<::android::IBinder>& lock, const ::android::os::WorkSource& ws, const ::android::String16& historyTag) override;
  ::android::binder::Status isWakeLockLevelSupported(int32_t level, bool* _aidl_return) override;
  ::android::binder::Status userActivity(int32_t displayId, int64_t time, int32_t event, int32_t flags) override;
  ::android::binder::Status wakeUp(int64_t time, int32_t reason, const ::android::String16& details, const ::android::String16& opPackageName) override;
  ::android::binder::Status goToSleep(int64_t time, int32_t reason, int32_t flags) override;
  ::android::binder::Status nap(int64_t time) override;
  ::android::binder::Status getBrightnessConstraint(int32_t constraint, float* _aidl_return) override;
  ::android::binder::Status isInteractive(bool* _aidl_return) override;
  ::android::binder::Status isPowerSaveMode(bool* _aidl_return) override;
  ::android::binder::Status getPowerSaveState(int32_t serviceType, ::android::os::PowerSaveState* _aidl_return) override;
  ::android::binder::Status setPowerSaveModeEnabled(bool mode, bool* _aidl_return) override;
  ::android::binder::Status getFullPowerSavePolicy(::android::os::BatterySaverPolicyConfig* _aidl_return) override;
  ::android::binder::Status setFullPowerSavePolicy(const ::android::os::BatterySaverPolicyConfig& config, bool* _aidl_return) override;
  ::android::binder::Status setDynamicPowerSaveHint(bool powerSaveHint, int32_t disableThreshold, bool* _aidl_return) override;
  ::android::binder::Status setAdaptivePowerSavePolicy(const ::android::os::BatterySaverPolicyConfig& config, bool* _aidl_return) override;
  ::android::binder::Status setAdaptivePowerSaveEnabled(bool enabled, bool* _aidl_return) override;
  ::android::binder::Status getPowerSaveModeTrigger(int32_t* _aidl_return) override;
  ::android::binder::Status setBatteryDischargePrediction(const ::android::os::ParcelDuration& timeRemaining, bool isCustomized) override;
  ::android::binder::Status getBatteryDischargePrediction(::android::os::ParcelDuration* _aidl_return) override;
  ::android::binder::Status isBatteryDischargePredictionPersonalized(bool* _aidl_return) override;
  ::android::binder::Status isDeviceIdleMode(bool* _aidl_return) override;
  ::android::binder::Status isLightDeviceIdleMode(bool* _aidl_return) override;
  ::android::binder::Status reboot(bool confirm, const ::android::String16& reason, bool wait) override;
  ::android::binder::Status rebootSafeMode(bool confirm, bool wait) override;
  ::android::binder::Status shutdown(bool confirm, const ::android::String16& reason, bool wait) override;
  ::android::binder::Status crash(const ::android::String16& message) override;
  ::android::binder::Status getLastShutdownReason(int32_t* _aidl_return) override;
  ::android::binder::Status getLastSleepReason(int32_t* _aidl_return) override;
  ::android::binder::Status setStayOnSetting(int32_t val) override;
  ::android::binder::Status boostScreenBrightness(int64_t time) override;
  ::android::binder::Status acquireWakeLockAsync(const ::android::sp<::android::IBinder>& lock, int32_t flags, const ::android::String16& tag, const ::android::String16& packageName, const ::android::os::WorkSource& ws, const ::android::String16& historyTag) override;
  ::android::binder::Status releaseWakeLockAsync(const ::android::sp<::android::IBinder>& lock, int32_t flags) override;
  ::android::binder::Status updateWakeLockUidsAsync(const ::android::sp<::android::IBinder>& lock, const ::std::vector<int32_t>& uids) override;
  ::android::binder::Status isScreenBrightnessBoosted(bool* _aidl_return) override;
  ::android::binder::Status setAttentionLight(bool on, int32_t color) override;
  ::android::binder::Status setDozeAfterScreenOff(bool on) override;
  ::android::binder::Status isAmbientDisplayAvailable(bool* _aidl_return) override;
  ::android::binder::Status suppressAmbientDisplay(const ::android::String16& token, bool suppress) override;
  ::android::binder::Status isAmbientDisplaySuppressedForToken(const ::android::String16& token, bool* _aidl_return) override;
  ::android::binder::Status isAmbientDisplaySuppressed(bool* _aidl_return) override;
  ::android::binder::Status isAmbientDisplaySuppressedForTokenByApp(const ::android::String16& token, int32_t appUid, bool* _aidl_return) override;
  ::android::binder::Status forceSuspend(bool* _aidl_return) override;
  ::android::binder::Status rebootCustom(bool confirm, const ::android::String16& reason, bool wait) override;
  ::android::binder::Status setKeyboardVisibility(bool visible) override;
  ::android::binder::Status wakeUpWithProximityCheck(int64_t time, int32_t reason, const ::android::String16& details, const ::android::String16& opPackageName) override;
};  // class BpPowerManager

}  // namespace os

}  // namespace android
