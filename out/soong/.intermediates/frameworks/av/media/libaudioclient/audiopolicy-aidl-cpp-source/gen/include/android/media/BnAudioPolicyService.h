#pragma once

#include <binder/IInterface.h>
#include <android/media/IAudioPolicyService.h>

namespace android {

namespace media {

class BnAudioPolicyService : public ::android::BnInterface<IAudioPolicyService> {
public:
  static constexpr uint32_t TRANSACTION_onNewAudioModulesAvailable = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_setDeviceConnectionState = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getDeviceConnectionState = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_handleDeviceConfigChange = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_setPhoneState = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_setForceUse = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_getForceUse = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_getOutput = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_getOutputForAttr = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_startOutput = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_stopOutput = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_releaseOutput = ::android::IBinder::FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_getInputForAttr = ::android::IBinder::FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_startInput = ::android::IBinder::FIRST_CALL_TRANSACTION + 13;
  static constexpr uint32_t TRANSACTION_stopInput = ::android::IBinder::FIRST_CALL_TRANSACTION + 14;
  static constexpr uint32_t TRANSACTION_releaseInput = ::android::IBinder::FIRST_CALL_TRANSACTION + 15;
  static constexpr uint32_t TRANSACTION_initStreamVolume = ::android::IBinder::FIRST_CALL_TRANSACTION + 16;
  static constexpr uint32_t TRANSACTION_setStreamVolumeIndex = ::android::IBinder::FIRST_CALL_TRANSACTION + 17;
  static constexpr uint32_t TRANSACTION_getStreamVolumeIndex = ::android::IBinder::FIRST_CALL_TRANSACTION + 18;
  static constexpr uint32_t TRANSACTION_setVolumeIndexForAttributes = ::android::IBinder::FIRST_CALL_TRANSACTION + 19;
  static constexpr uint32_t TRANSACTION_getVolumeIndexForAttributes = ::android::IBinder::FIRST_CALL_TRANSACTION + 20;
  static constexpr uint32_t TRANSACTION_getMaxVolumeIndexForAttributes = ::android::IBinder::FIRST_CALL_TRANSACTION + 21;
  static constexpr uint32_t TRANSACTION_getMinVolumeIndexForAttributes = ::android::IBinder::FIRST_CALL_TRANSACTION + 22;
  static constexpr uint32_t TRANSACTION_getStrategyForStream = ::android::IBinder::FIRST_CALL_TRANSACTION + 23;
  static constexpr uint32_t TRANSACTION_getDevicesForStream = ::android::IBinder::FIRST_CALL_TRANSACTION + 24;
  static constexpr uint32_t TRANSACTION_getDevicesForAttributes = ::android::IBinder::FIRST_CALL_TRANSACTION + 25;
  static constexpr uint32_t TRANSACTION_getOutputForEffect = ::android::IBinder::FIRST_CALL_TRANSACTION + 26;
  static constexpr uint32_t TRANSACTION_registerEffect = ::android::IBinder::FIRST_CALL_TRANSACTION + 27;
  static constexpr uint32_t TRANSACTION_unregisterEffect = ::android::IBinder::FIRST_CALL_TRANSACTION + 28;
  static constexpr uint32_t TRANSACTION_setEffectEnabled = ::android::IBinder::FIRST_CALL_TRANSACTION + 29;
  static constexpr uint32_t TRANSACTION_moveEffectsToIo = ::android::IBinder::FIRST_CALL_TRANSACTION + 30;
  static constexpr uint32_t TRANSACTION_isStreamActive = ::android::IBinder::FIRST_CALL_TRANSACTION + 31;
  static constexpr uint32_t TRANSACTION_isStreamActiveRemotely = ::android::IBinder::FIRST_CALL_TRANSACTION + 32;
  static constexpr uint32_t TRANSACTION_isSourceActive = ::android::IBinder::FIRST_CALL_TRANSACTION + 33;
  static constexpr uint32_t TRANSACTION_queryDefaultPreProcessing = ::android::IBinder::FIRST_CALL_TRANSACTION + 34;
  static constexpr uint32_t TRANSACTION_addSourceDefaultEffect = ::android::IBinder::FIRST_CALL_TRANSACTION + 35;
  static constexpr uint32_t TRANSACTION_addStreamDefaultEffect = ::android::IBinder::FIRST_CALL_TRANSACTION + 36;
  static constexpr uint32_t TRANSACTION_removeSourceDefaultEffect = ::android::IBinder::FIRST_CALL_TRANSACTION + 37;
  static constexpr uint32_t TRANSACTION_removeStreamDefaultEffect = ::android::IBinder::FIRST_CALL_TRANSACTION + 38;
  static constexpr uint32_t TRANSACTION_setSupportedSystemUsages = ::android::IBinder::FIRST_CALL_TRANSACTION + 39;
  static constexpr uint32_t TRANSACTION_setAllowedCapturePolicy = ::android::IBinder::FIRST_CALL_TRANSACTION + 40;
  static constexpr uint32_t TRANSACTION_getOffloadSupport = ::android::IBinder::FIRST_CALL_TRANSACTION + 41;
  static constexpr uint32_t TRANSACTION_isDirectOutputSupported = ::android::IBinder::FIRST_CALL_TRANSACTION + 42;
  static constexpr uint32_t TRANSACTION_listAudioPorts = ::android::IBinder::FIRST_CALL_TRANSACTION + 43;
  static constexpr uint32_t TRANSACTION_getAudioPort = ::android::IBinder::FIRST_CALL_TRANSACTION + 44;
  static constexpr uint32_t TRANSACTION_createAudioPatch = ::android::IBinder::FIRST_CALL_TRANSACTION + 45;
  static constexpr uint32_t TRANSACTION_releaseAudioPatch = ::android::IBinder::FIRST_CALL_TRANSACTION + 46;
  static constexpr uint32_t TRANSACTION_listAudioPatches = ::android::IBinder::FIRST_CALL_TRANSACTION + 47;
  static constexpr uint32_t TRANSACTION_setAudioPortConfig = ::android::IBinder::FIRST_CALL_TRANSACTION + 48;
  static constexpr uint32_t TRANSACTION_registerClient = ::android::IBinder::FIRST_CALL_TRANSACTION + 49;
  static constexpr uint32_t TRANSACTION_setAudioPortCallbacksEnabled = ::android::IBinder::FIRST_CALL_TRANSACTION + 50;
  static constexpr uint32_t TRANSACTION_setAudioVolumeGroupCallbacksEnabled = ::android::IBinder::FIRST_CALL_TRANSACTION + 51;
  static constexpr uint32_t TRANSACTION_acquireSoundTriggerSession = ::android::IBinder::FIRST_CALL_TRANSACTION + 52;
  static constexpr uint32_t TRANSACTION_releaseSoundTriggerSession = ::android::IBinder::FIRST_CALL_TRANSACTION + 53;
  static constexpr uint32_t TRANSACTION_getPhoneState = ::android::IBinder::FIRST_CALL_TRANSACTION + 54;
  static constexpr uint32_t TRANSACTION_registerPolicyMixes = ::android::IBinder::FIRST_CALL_TRANSACTION + 55;
  static constexpr uint32_t TRANSACTION_setUidDeviceAffinities = ::android::IBinder::FIRST_CALL_TRANSACTION + 56;
  static constexpr uint32_t TRANSACTION_removeUidDeviceAffinities = ::android::IBinder::FIRST_CALL_TRANSACTION + 57;
  static constexpr uint32_t TRANSACTION_setUserIdDeviceAffinities = ::android::IBinder::FIRST_CALL_TRANSACTION + 58;
  static constexpr uint32_t TRANSACTION_removeUserIdDeviceAffinities = ::android::IBinder::FIRST_CALL_TRANSACTION + 59;
  static constexpr uint32_t TRANSACTION_startAudioSource = ::android::IBinder::FIRST_CALL_TRANSACTION + 60;
  static constexpr uint32_t TRANSACTION_stopAudioSource = ::android::IBinder::FIRST_CALL_TRANSACTION + 61;
  static constexpr uint32_t TRANSACTION_setMasterMono = ::android::IBinder::FIRST_CALL_TRANSACTION + 62;
  static constexpr uint32_t TRANSACTION_getMasterMono = ::android::IBinder::FIRST_CALL_TRANSACTION + 63;
  static constexpr uint32_t TRANSACTION_getStreamVolumeDB = ::android::IBinder::FIRST_CALL_TRANSACTION + 64;
  static constexpr uint32_t TRANSACTION_getSurroundFormats = ::android::IBinder::FIRST_CALL_TRANSACTION + 65;
  static constexpr uint32_t TRANSACTION_getReportedSurroundFormats = ::android::IBinder::FIRST_CALL_TRANSACTION + 66;
  static constexpr uint32_t TRANSACTION_getHwOffloadEncodingFormatsSupportedForA2DP = ::android::IBinder::FIRST_CALL_TRANSACTION + 67;
  static constexpr uint32_t TRANSACTION_setSurroundFormatEnabled = ::android::IBinder::FIRST_CALL_TRANSACTION + 68;
  static constexpr uint32_t TRANSACTION_setAssistantUid = ::android::IBinder::FIRST_CALL_TRANSACTION + 69;
  static constexpr uint32_t TRANSACTION_setHotwordDetectionServiceUid = ::android::IBinder::FIRST_CALL_TRANSACTION + 70;
  static constexpr uint32_t TRANSACTION_setA11yServicesUids = ::android::IBinder::FIRST_CALL_TRANSACTION + 71;
  static constexpr uint32_t TRANSACTION_setCurrentImeUid = ::android::IBinder::FIRST_CALL_TRANSACTION + 72;
  static constexpr uint32_t TRANSACTION_isHapticPlaybackSupported = ::android::IBinder::FIRST_CALL_TRANSACTION + 73;
  static constexpr uint32_t TRANSACTION_listAudioProductStrategies = ::android::IBinder::FIRST_CALL_TRANSACTION + 74;
  static constexpr uint32_t TRANSACTION_getProductStrategyFromAudioAttributes = ::android::IBinder::FIRST_CALL_TRANSACTION + 75;
  static constexpr uint32_t TRANSACTION_listAudioVolumeGroups = ::android::IBinder::FIRST_CALL_TRANSACTION + 76;
  static constexpr uint32_t TRANSACTION_getVolumeGroupFromAudioAttributes = ::android::IBinder::FIRST_CALL_TRANSACTION + 77;
  static constexpr uint32_t TRANSACTION_setRttEnabled = ::android::IBinder::FIRST_CALL_TRANSACTION + 78;
  static constexpr uint32_t TRANSACTION_isCallScreenModeSupported = ::android::IBinder::FIRST_CALL_TRANSACTION + 79;
  static constexpr uint32_t TRANSACTION_setDevicesRoleForStrategy = ::android::IBinder::FIRST_CALL_TRANSACTION + 80;
  static constexpr uint32_t TRANSACTION_removeDevicesRoleForStrategy = ::android::IBinder::FIRST_CALL_TRANSACTION + 81;
  static constexpr uint32_t TRANSACTION_getDevicesForRoleAndStrategy = ::android::IBinder::FIRST_CALL_TRANSACTION + 82;
  static constexpr uint32_t TRANSACTION_setDevicesRoleForCapturePreset = ::android::IBinder::FIRST_CALL_TRANSACTION + 83;
  static constexpr uint32_t TRANSACTION_addDevicesRoleForCapturePreset = ::android::IBinder::FIRST_CALL_TRANSACTION + 84;
  static constexpr uint32_t TRANSACTION_removeDevicesRoleForCapturePreset = ::android::IBinder::FIRST_CALL_TRANSACTION + 85;
  static constexpr uint32_t TRANSACTION_clearDevicesRoleForCapturePreset = ::android::IBinder::FIRST_CALL_TRANSACTION + 86;
  static constexpr uint32_t TRANSACTION_getDevicesForRoleAndCapturePreset = ::android::IBinder::FIRST_CALL_TRANSACTION + 87;
  static constexpr uint32_t TRANSACTION_registerSoundTriggerCaptureStateListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 88;
  static constexpr uint32_t TRANSACTION_getSpatializer = ::android::IBinder::FIRST_CALL_TRANSACTION + 89;
  static constexpr uint32_t TRANSACTION_canBeSpatialized = ::android::IBinder::FIRST_CALL_TRANSACTION + 90;
  explicit BnAudioPolicyService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnAudioPolicyService

}  // namespace media

}  // namespace android
