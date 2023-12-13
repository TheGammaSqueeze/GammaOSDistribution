#pragma once

#include <binder/IInterface.h>
#include <android/media/IAudioFlingerService.h>

namespace android {

namespace media {

class BnAudioFlingerService : public ::android::BnInterface<IAudioFlingerService> {
public:
  static constexpr uint32_t TRANSACTION_createTrack = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_createRecord = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_sampleRate = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_format = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_frameCount = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_latency = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_setMasterVolume = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_setMasterMute = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_masterVolume = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_masterMute = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_setMasterBalance = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_getMasterBalance = ::android::IBinder::FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_setStreamVolume = ::android::IBinder::FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_setStreamMute = ::android::IBinder::FIRST_CALL_TRANSACTION + 13;
  static constexpr uint32_t TRANSACTION_streamVolume = ::android::IBinder::FIRST_CALL_TRANSACTION + 14;
  static constexpr uint32_t TRANSACTION_streamMute = ::android::IBinder::FIRST_CALL_TRANSACTION + 15;
  static constexpr uint32_t TRANSACTION_setMode = ::android::IBinder::FIRST_CALL_TRANSACTION + 16;
  static constexpr uint32_t TRANSACTION_setMicMute = ::android::IBinder::FIRST_CALL_TRANSACTION + 17;
  static constexpr uint32_t TRANSACTION_getMicMute = ::android::IBinder::FIRST_CALL_TRANSACTION + 18;
  static constexpr uint32_t TRANSACTION_setRecordSilenced = ::android::IBinder::FIRST_CALL_TRANSACTION + 19;
  static constexpr uint32_t TRANSACTION_setParameters = ::android::IBinder::FIRST_CALL_TRANSACTION + 20;
  static constexpr uint32_t TRANSACTION_getParameters = ::android::IBinder::FIRST_CALL_TRANSACTION + 21;
  static constexpr uint32_t TRANSACTION_registerClient = ::android::IBinder::FIRST_CALL_TRANSACTION + 22;
  static constexpr uint32_t TRANSACTION_getInputBufferSize = ::android::IBinder::FIRST_CALL_TRANSACTION + 23;
  static constexpr uint32_t TRANSACTION_openOutput = ::android::IBinder::FIRST_CALL_TRANSACTION + 24;
  static constexpr uint32_t TRANSACTION_openDuplicateOutput = ::android::IBinder::FIRST_CALL_TRANSACTION + 25;
  static constexpr uint32_t TRANSACTION_closeOutput = ::android::IBinder::FIRST_CALL_TRANSACTION + 26;
  static constexpr uint32_t TRANSACTION_suspendOutput = ::android::IBinder::FIRST_CALL_TRANSACTION + 27;
  static constexpr uint32_t TRANSACTION_restoreOutput = ::android::IBinder::FIRST_CALL_TRANSACTION + 28;
  static constexpr uint32_t TRANSACTION_openInput = ::android::IBinder::FIRST_CALL_TRANSACTION + 29;
  static constexpr uint32_t TRANSACTION_closeInput = ::android::IBinder::FIRST_CALL_TRANSACTION + 30;
  static constexpr uint32_t TRANSACTION_invalidateStream = ::android::IBinder::FIRST_CALL_TRANSACTION + 31;
  static constexpr uint32_t TRANSACTION_setVoiceVolume = ::android::IBinder::FIRST_CALL_TRANSACTION + 32;
  static constexpr uint32_t TRANSACTION_getRenderPosition = ::android::IBinder::FIRST_CALL_TRANSACTION + 33;
  static constexpr uint32_t TRANSACTION_getInputFramesLost = ::android::IBinder::FIRST_CALL_TRANSACTION + 34;
  static constexpr uint32_t TRANSACTION_newAudioUniqueId = ::android::IBinder::FIRST_CALL_TRANSACTION + 35;
  static constexpr uint32_t TRANSACTION_acquireAudioSessionId = ::android::IBinder::FIRST_CALL_TRANSACTION + 36;
  static constexpr uint32_t TRANSACTION_releaseAudioSessionId = ::android::IBinder::FIRST_CALL_TRANSACTION + 37;
  static constexpr uint32_t TRANSACTION_queryNumberEffects = ::android::IBinder::FIRST_CALL_TRANSACTION + 38;
  static constexpr uint32_t TRANSACTION_queryEffect = ::android::IBinder::FIRST_CALL_TRANSACTION + 39;
  static constexpr uint32_t TRANSACTION_getEffectDescriptor = ::android::IBinder::FIRST_CALL_TRANSACTION + 40;
  static constexpr uint32_t TRANSACTION_createEffect = ::android::IBinder::FIRST_CALL_TRANSACTION + 41;
  static constexpr uint32_t TRANSACTION_moveEffects = ::android::IBinder::FIRST_CALL_TRANSACTION + 42;
  static constexpr uint32_t TRANSACTION_setEffectSuspended = ::android::IBinder::FIRST_CALL_TRANSACTION + 43;
  static constexpr uint32_t TRANSACTION_loadHwModule = ::android::IBinder::FIRST_CALL_TRANSACTION + 44;
  static constexpr uint32_t TRANSACTION_getPrimaryOutputSamplingRate = ::android::IBinder::FIRST_CALL_TRANSACTION + 45;
  static constexpr uint32_t TRANSACTION_getPrimaryOutputFrameCount = ::android::IBinder::FIRST_CALL_TRANSACTION + 46;
  static constexpr uint32_t TRANSACTION_setLowRamDevice = ::android::IBinder::FIRST_CALL_TRANSACTION + 47;
  static constexpr uint32_t TRANSACTION_getAudioPort = ::android::IBinder::FIRST_CALL_TRANSACTION + 48;
  static constexpr uint32_t TRANSACTION_createAudioPatch = ::android::IBinder::FIRST_CALL_TRANSACTION + 49;
  static constexpr uint32_t TRANSACTION_releaseAudioPatch = ::android::IBinder::FIRST_CALL_TRANSACTION + 50;
  static constexpr uint32_t TRANSACTION_listAudioPatches = ::android::IBinder::FIRST_CALL_TRANSACTION + 51;
  static constexpr uint32_t TRANSACTION_setAudioPortConfig = ::android::IBinder::FIRST_CALL_TRANSACTION + 52;
  static constexpr uint32_t TRANSACTION_getAudioHwSyncForSession = ::android::IBinder::FIRST_CALL_TRANSACTION + 53;
  static constexpr uint32_t TRANSACTION_systemReady = ::android::IBinder::FIRST_CALL_TRANSACTION + 54;
  static constexpr uint32_t TRANSACTION_audioPolicyReady = ::android::IBinder::FIRST_CALL_TRANSACTION + 55;
  static constexpr uint32_t TRANSACTION_frameCountHAL = ::android::IBinder::FIRST_CALL_TRANSACTION + 56;
  static constexpr uint32_t TRANSACTION_getMicrophones = ::android::IBinder::FIRST_CALL_TRANSACTION + 57;
  static constexpr uint32_t TRANSACTION_setAudioHalPids = ::android::IBinder::FIRST_CALL_TRANSACTION + 58;
  static constexpr uint32_t TRANSACTION_setVibratorInfos = ::android::IBinder::FIRST_CALL_TRANSACTION + 59;
  static constexpr uint32_t TRANSACTION_updateSecondaryOutputs = ::android::IBinder::FIRST_CALL_TRANSACTION + 60;
  explicit BnAudioFlingerService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnAudioFlingerService

}  // namespace media

}  // namespace android
