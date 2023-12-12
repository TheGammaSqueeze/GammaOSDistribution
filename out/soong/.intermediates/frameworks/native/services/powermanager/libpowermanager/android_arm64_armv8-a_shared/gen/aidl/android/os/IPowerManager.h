#pragma once

#include <android/BatterySaverPolicyConfig.h>
#include <android/ParcelDuration.h>
#include <android/PowerSaveState.h>
#include <android/WorkSource.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace os {

class IPowerManager : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(PowerManager)
  enum  : int32_t {
    LOCATION_MODE_NO_CHANGE = 0,
    LOCATION_MODE_GPS_DISABLED_WHEN_SCREEN_OFF = 1,
    LOCATION_MODE_ALL_DISABLED_WHEN_SCREEN_OFF = 2,
    LOCATION_MODE_FOREGROUND_ONLY = 3,
    LOCATION_MODE_THROTTLE_REQUESTS_WHEN_SCREEN_OFF = 4,
    MIN_LOCATION_MODE = 0,
    MAX_LOCATION_MODE = 4,
    GO_TO_SLEEP_REASON_MIN = 0,
    GO_TO_SLEEP_REASON_APPLICATION = 0,
    GO_TO_SLEEP_REASON_TIMEOUT = 2,
    GO_TO_SLEEP_REASON_LID_SWITCH = 3,
    GO_TO_SLEEP_REASON_POWER_BUTTON = 4,
    GO_TO_SLEEP_REASON_HDMI = 5,
    GO_TO_SLEEP_REASON_SLEEP_BUTTON = 6,
    GO_TO_SLEEP_REASON_ACCESSIBILITY = 7,
    GO_TO_SLEEP_REASON_FORCE_SUSPEND = 8,
    GO_TO_SLEEP_REASON_INATTENTIVE = 9,
    GO_TO_SLEEP_REASON_QUIESCENT = 10,
    GO_TO_SLEEP_REASON_MAX = 10,
    GO_TO_SLEEP_FLAG_NO_DOZE = 1,
  };
  virtual ::android::binder::Status acquireWakeLock(const ::android::sp<::android::IBinder>& lock, int32_t flags, const ::android::String16& tag, const ::android::String16& packageName, const ::android::os::WorkSource& ws, const ::android::String16& historyTag, int32_t displayId) = 0;
  virtual ::android::binder::Status acquireWakeLockWithUid(const ::android::sp<::android::IBinder>& lock, int32_t flags, const ::android::String16& tag, const ::android::String16& packageName, int32_t uidtoblame, int32_t displayId) = 0;
  virtual ::android::binder::Status releaseWakeLock(const ::android::sp<::android::IBinder>& lock, int32_t flags) = 0;
  virtual ::android::binder::Status updateWakeLockUids(const ::android::sp<::android::IBinder>& lock, const ::std::vector<int32_t>& uids) = 0;
  virtual ::android::binder::Status setPowerBoost(int32_t boost, int32_t durationMs) = 0;
  virtual ::android::binder::Status setPowerMode(int32_t mode, bool enabled) = 0;
  virtual ::android::binder::Status setPowerModeChecked(int32_t mode, bool enabled, bool* _aidl_return) = 0;
  virtual ::android::binder::Status updateWakeLockWorkSource(const ::android::sp<::android::IBinder>& lock, const ::android::os::WorkSource& ws, const ::android::String16& historyTag) = 0;
  virtual ::android::binder::Status isWakeLockLevelSupported(int32_t level, bool* _aidl_return) = 0;
  virtual ::android::binder::Status userActivity(int32_t displayId, int64_t time, int32_t event, int32_t flags) = 0;
  virtual ::android::binder::Status wakeUp(int64_t time, int32_t reason, const ::android::String16& details, const ::android::String16& opPackageName) = 0;
  virtual ::android::binder::Status goToSleep(int64_t time, int32_t reason, int32_t flags) = 0;
  virtual ::android::binder::Status nap(int64_t time) = 0;
  virtual ::android::binder::Status getBrightnessConstraint(int32_t constraint, float* _aidl_return) = 0;
  virtual ::android::binder::Status isInteractive(bool* _aidl_return) = 0;
  virtual ::android::binder::Status isPowerSaveMode(bool* _aidl_return) = 0;
  virtual ::android::binder::Status getPowerSaveState(int32_t serviceType, ::android::os::PowerSaveState* _aidl_return) = 0;
  virtual ::android::binder::Status setPowerSaveModeEnabled(bool mode, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getFullPowerSavePolicy(::android::os::BatterySaverPolicyConfig* _aidl_return) = 0;
  virtual ::android::binder::Status setFullPowerSavePolicy(const ::android::os::BatterySaverPolicyConfig& config, bool* _aidl_return) = 0;
  virtual ::android::binder::Status setDynamicPowerSaveHint(bool powerSaveHint, int32_t disableThreshold, bool* _aidl_return) = 0;
  virtual ::android::binder::Status setAdaptivePowerSavePolicy(const ::android::os::BatterySaverPolicyConfig& config, bool* _aidl_return) = 0;
  virtual ::android::binder::Status setAdaptivePowerSaveEnabled(bool enabled, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getPowerSaveModeTrigger(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status setBatteryDischargePrediction(const ::android::os::ParcelDuration& timeRemaining, bool isCustomized) = 0;
  virtual ::android::binder::Status getBatteryDischargePrediction(::android::os::ParcelDuration* _aidl_return) = 0;
  virtual ::android::binder::Status isBatteryDischargePredictionPersonalized(bool* _aidl_return) = 0;
  virtual ::android::binder::Status isDeviceIdleMode(bool* _aidl_return) = 0;
  virtual ::android::binder::Status isLightDeviceIdleMode(bool* _aidl_return) = 0;
  virtual ::android::binder::Status reboot(bool confirm, const ::android::String16& reason, bool wait) = 0;
  virtual ::android::binder::Status rebootSafeMode(bool confirm, bool wait) = 0;
  virtual ::android::binder::Status shutdown(bool confirm, const ::android::String16& reason, bool wait) = 0;
  virtual ::android::binder::Status crash(const ::android::String16& message) = 0;
  virtual ::android::binder::Status getLastShutdownReason(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getLastSleepReason(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status setStayOnSetting(int32_t val) = 0;
  virtual ::android::binder::Status boostScreenBrightness(int64_t time) = 0;
  virtual ::android::binder::Status acquireWakeLockAsync(const ::android::sp<::android::IBinder>& lock, int32_t flags, const ::android::String16& tag, const ::android::String16& packageName, const ::android::os::WorkSource& ws, const ::android::String16& historyTag) = 0;
  virtual ::android::binder::Status releaseWakeLockAsync(const ::android::sp<::android::IBinder>& lock, int32_t flags) = 0;
  virtual ::android::binder::Status updateWakeLockUidsAsync(const ::android::sp<::android::IBinder>& lock, const ::std::vector<int32_t>& uids) = 0;
  virtual ::android::binder::Status isScreenBrightnessBoosted(bool* _aidl_return) = 0;
  virtual ::android::binder::Status setAttentionLight(bool on, int32_t color) = 0;
  virtual ::android::binder::Status setDozeAfterScreenOff(bool on) = 0;
  virtual ::android::binder::Status isAmbientDisplayAvailable(bool* _aidl_return) = 0;
  virtual ::android::binder::Status suppressAmbientDisplay(const ::android::String16& token, bool suppress) = 0;
  virtual ::android::binder::Status isAmbientDisplaySuppressedForToken(const ::android::String16& token, bool* _aidl_return) = 0;
  virtual ::android::binder::Status isAmbientDisplaySuppressed(bool* _aidl_return) = 0;
  virtual ::android::binder::Status isAmbientDisplaySuppressedForTokenByApp(const ::android::String16& token, int32_t appUid, bool* _aidl_return) = 0;
  virtual ::android::binder::Status forceSuspend(bool* _aidl_return) = 0;
  virtual ::android::binder::Status rebootCustom(bool confirm, const ::android::String16& reason, bool wait) = 0;
  virtual ::android::binder::Status setKeyboardVisibility(bool visible) = 0;
  virtual ::android::binder::Status wakeUpWithProximityCheck(int64_t time, int32_t reason, const ::android::String16& details, const ::android::String16& opPackageName) = 0;
};  // class IPowerManager

class IPowerManagerDefault : public IPowerManager {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status acquireWakeLock(const ::android::sp<::android::IBinder>&, int32_t, const ::android::String16&, const ::android::String16&, const ::android::os::WorkSource&, const ::android::String16&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status acquireWakeLockWithUid(const ::android::sp<::android::IBinder>&, int32_t, const ::android::String16&, const ::android::String16&, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status releaseWakeLock(const ::android::sp<::android::IBinder>&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status updateWakeLockUids(const ::android::sp<::android::IBinder>&, const ::std::vector<int32_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setPowerBoost(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setPowerMode(int32_t, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setPowerModeChecked(int32_t, bool, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status updateWakeLockWorkSource(const ::android::sp<::android::IBinder>&, const ::android::os::WorkSource&, const ::android::String16&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isWakeLockLevelSupported(int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status userActivity(int32_t, int64_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status wakeUp(int64_t, int32_t, const ::android::String16&, const ::android::String16&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status goToSleep(int64_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status nap(int64_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getBrightnessConstraint(int32_t, float*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isInteractive(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isPowerSaveMode(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getPowerSaveState(int32_t, ::android::os::PowerSaveState*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setPowerSaveModeEnabled(bool, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getFullPowerSavePolicy(::android::os::BatterySaverPolicyConfig*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setFullPowerSavePolicy(const ::android::os::BatterySaverPolicyConfig&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setDynamicPowerSaveHint(bool, int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setAdaptivePowerSavePolicy(const ::android::os::BatterySaverPolicyConfig&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setAdaptivePowerSaveEnabled(bool, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getPowerSaveModeTrigger(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setBatteryDischargePrediction(const ::android::os::ParcelDuration&, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getBatteryDischargePrediction(::android::os::ParcelDuration*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isBatteryDischargePredictionPersonalized(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isDeviceIdleMode(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isLightDeviceIdleMode(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status reboot(bool, const ::android::String16&, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status rebootSafeMode(bool, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status shutdown(bool, const ::android::String16&, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status crash(const ::android::String16&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getLastShutdownReason(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getLastSleepReason(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setStayOnSetting(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status boostScreenBrightness(int64_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status acquireWakeLockAsync(const ::android::sp<::android::IBinder>&, int32_t, const ::android::String16&, const ::android::String16&, const ::android::os::WorkSource&, const ::android::String16&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status releaseWakeLockAsync(const ::android::sp<::android::IBinder>&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status updateWakeLockUidsAsync(const ::android::sp<::android::IBinder>&, const ::std::vector<int32_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isScreenBrightnessBoosted(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setAttentionLight(bool, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setDozeAfterScreenOff(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isAmbientDisplayAvailable(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status suppressAmbientDisplay(const ::android::String16&, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isAmbientDisplaySuppressedForToken(const ::android::String16&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isAmbientDisplaySuppressed(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isAmbientDisplaySuppressedForTokenByApp(const ::android::String16&, int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status forceSuspend(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status rebootCustom(bool, const ::android::String16&, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setKeyboardVisibility(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status wakeUpWithProximityCheck(int64_t, int32_t, const ::android::String16&, const ::android::String16&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IPowerManagerDefault

}  // namespace os

}  // namespace android
