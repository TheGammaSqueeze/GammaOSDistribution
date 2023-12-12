#pragma once

#include <android/media/AudioMode.h>
#include <android/media/AudioPatch.h>
#include <android/media/AudioPort.h>
#include <android/media/AudioPortConfig.h>
#include <android/media/AudioStreamType.h>
#include <android/media/AudioUniqueIdUse.h>
#include <android/media/AudioUuid.h>
#include <android/media/AudioVibratorInfo.h>
#include <android/media/CreateEffectRequest.h>
#include <android/media/CreateEffectResponse.h>
#include <android/media/CreateRecordRequest.h>
#include <android/media/CreateRecordResponse.h>
#include <android/media/CreateTrackRequest.h>
#include <android/media/CreateTrackResponse.h>
#include <android/media/EffectDescriptor.h>
#include <android/media/IAudioFlingerClient.h>
#include <android/media/MicrophoneInfoData.h>
#include <android/media/OpenInputRequest.h>
#include <android/media/OpenInputResponse.h>
#include <android/media/OpenOutputRequest.h>
#include <android/media/OpenOutputResponse.h>
#include <android/media/RenderPosition.h>
#include <android/media/TrackSecondaryOutputInfo.h>
#include <android/media/audio/common/AudioFormat.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace media {

class IAudioFlingerService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(AudioFlingerService)
  virtual ::android::binder::Status createTrack(const ::android::media::CreateTrackRequest& request, ::android::media::CreateTrackResponse* _aidl_return) = 0;
  virtual ::android::binder::Status createRecord(const ::android::media::CreateRecordRequest& request, ::android::media::CreateRecordResponse* _aidl_return) = 0;
  virtual ::android::binder::Status sampleRate(int32_t ioHandle, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status format(int32_t output, ::android::media::audio::common::AudioFormat* _aidl_return) = 0;
  virtual ::android::binder::Status frameCount(int32_t ioHandle, int64_t* _aidl_return) = 0;
  virtual ::android::binder::Status latency(int32_t output, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status setMasterVolume(float value) = 0;
  virtual ::android::binder::Status setMasterMute(bool muted) = 0;
  virtual ::android::binder::Status masterVolume(float* _aidl_return) = 0;
  virtual ::android::binder::Status masterMute(bool* _aidl_return) = 0;
  virtual ::android::binder::Status setMasterBalance(float balance) = 0;
  virtual ::android::binder::Status getMasterBalance(float* _aidl_return) = 0;
  virtual ::android::binder::Status setStreamVolume(::android::media::AudioStreamType stream, float value, int32_t output) = 0;
  virtual ::android::binder::Status setStreamMute(::android::media::AudioStreamType stream, bool muted) = 0;
  virtual ::android::binder::Status streamVolume(::android::media::AudioStreamType stream, int32_t output, float* _aidl_return) = 0;
  virtual ::android::binder::Status streamMute(::android::media::AudioStreamType stream, bool* _aidl_return) = 0;
  virtual ::android::binder::Status setMode(::android::media::AudioMode mode) = 0;
  virtual ::android::binder::Status setMicMute(bool state) = 0;
  virtual ::android::binder::Status getMicMute(bool* _aidl_return) = 0;
  virtual ::android::binder::Status setRecordSilenced(int32_t portId, bool silenced) = 0;
  virtual ::android::binder::Status setParameters(int32_t ioHandle, const ::std::string& keyValuePairs) = 0;
  virtual ::android::binder::Status getParameters(int32_t ioHandle, const ::std::string& keys, ::std::string* _aidl_return) = 0;
  virtual ::android::binder::Status registerClient(const ::android::sp<::android::media::IAudioFlingerClient>& client) = 0;
  virtual ::android::binder::Status getInputBufferSize(int32_t sampleRate, ::android::media::audio::common::AudioFormat format, int32_t channelMask, int64_t* _aidl_return) = 0;
  virtual ::android::binder::Status openOutput(const ::android::media::OpenOutputRequest& request, ::android::media::OpenOutputResponse* _aidl_return) = 0;
  virtual ::android::binder::Status openDuplicateOutput(int32_t output1, int32_t output2, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status closeOutput(int32_t output) = 0;
  virtual ::android::binder::Status suspendOutput(int32_t output) = 0;
  virtual ::android::binder::Status restoreOutput(int32_t output) = 0;
  virtual ::android::binder::Status openInput(const ::android::media::OpenInputRequest& request, ::android::media::OpenInputResponse* _aidl_return) = 0;
  virtual ::android::binder::Status closeInput(int32_t input) = 0;
  virtual ::android::binder::Status invalidateStream(::android::media::AudioStreamType stream) = 0;
  virtual ::android::binder::Status setVoiceVolume(float volume) = 0;
  virtual ::android::binder::Status getRenderPosition(int32_t output, ::android::media::RenderPosition* _aidl_return) = 0;
  virtual ::android::binder::Status getInputFramesLost(int32_t ioHandle, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status newAudioUniqueId(::android::media::AudioUniqueIdUse use, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status acquireAudioSessionId(int32_t audioSession, int32_t pid, int32_t uid) = 0;
  virtual ::android::binder::Status releaseAudioSessionId(int32_t audioSession, int32_t pid) = 0;
  virtual ::android::binder::Status queryNumberEffects(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status queryEffect(int32_t index, ::android::media::EffectDescriptor* _aidl_return) = 0;
  virtual ::android::binder::Status getEffectDescriptor(const ::android::media::AudioUuid& effectUUID, const ::android::media::AudioUuid& typeUUID, int32_t preferredTypeFlag, ::android::media::EffectDescriptor* _aidl_return) = 0;
  virtual ::android::binder::Status createEffect(const ::android::media::CreateEffectRequest& request, ::android::media::CreateEffectResponse* _aidl_return) = 0;
  virtual ::android::binder::Status moveEffects(int32_t session, int32_t srcOutput, int32_t dstOutput) = 0;
  virtual ::android::binder::Status setEffectSuspended(int32_t effectId, int32_t sessionId, bool suspended) = 0;
  virtual ::android::binder::Status loadHwModule(const ::std::string& name, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getPrimaryOutputSamplingRate(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getPrimaryOutputFrameCount(int64_t* _aidl_return) = 0;
  virtual ::android::binder::Status setLowRamDevice(bool isLowRamDevice, int64_t totalMemory) = 0;
  virtual ::android::binder::Status getAudioPort(const ::android::media::AudioPort& port, ::android::media::AudioPort* _aidl_return) = 0;
  virtual ::android::binder::Status createAudioPatch(const ::android::media::AudioPatch& patch, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status releaseAudioPatch(int32_t handle) = 0;
  virtual ::android::binder::Status listAudioPatches(int32_t maxCount, ::std::vector<::android::media::AudioPatch>* _aidl_return) = 0;
  virtual ::android::binder::Status setAudioPortConfig(const ::android::media::AudioPortConfig& config) = 0;
  virtual ::android::binder::Status getAudioHwSyncForSession(int32_t sessionId, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status systemReady() = 0;
  virtual ::android::binder::Status audioPolicyReady() = 0;
  virtual ::android::binder::Status frameCountHAL(int32_t ioHandle, int64_t* _aidl_return) = 0;
  virtual ::android::binder::Status getMicrophones(::std::vector<::android::media::MicrophoneInfoData>* _aidl_return) = 0;
  virtual ::android::binder::Status setAudioHalPids(const ::std::vector<int32_t>& pids) = 0;
  virtual ::android::binder::Status setVibratorInfos(const ::std::vector<::android::media::AudioVibratorInfo>& vibratorInfos) = 0;
  virtual ::android::binder::Status updateSecondaryOutputs(const ::std::vector<::android::media::TrackSecondaryOutputInfo>& trackSecondaryOutputInfos) = 0;
};  // class IAudioFlingerService

class IAudioFlingerServiceDefault : public IAudioFlingerService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status createTrack(const ::android::media::CreateTrackRequest&, ::android::media::CreateTrackResponse*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createRecord(const ::android::media::CreateRecordRequest&, ::android::media::CreateRecordResponse*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status sampleRate(int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status format(int32_t, ::android::media::audio::common::AudioFormat*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status frameCount(int32_t, int64_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status latency(int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setMasterVolume(float) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setMasterMute(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status masterVolume(float*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status masterMute(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setMasterBalance(float) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getMasterBalance(float*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setStreamVolume(::android::media::AudioStreamType, float, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setStreamMute(::android::media::AudioStreamType, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status streamVolume(::android::media::AudioStreamType, int32_t, float*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status streamMute(::android::media::AudioStreamType, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setMode(::android::media::AudioMode) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setMicMute(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getMicMute(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setRecordSilenced(int32_t, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setParameters(int32_t, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getParameters(int32_t, const ::std::string&, ::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status registerClient(const ::android::sp<::android::media::IAudioFlingerClient>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getInputBufferSize(int32_t, ::android::media::audio::common::AudioFormat, int32_t, int64_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status openOutput(const ::android::media::OpenOutputRequest&, ::android::media::OpenOutputResponse*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status openDuplicateOutput(int32_t, int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status closeOutput(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status suspendOutput(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status restoreOutput(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status openInput(const ::android::media::OpenInputRequest&, ::android::media::OpenInputResponse*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status closeInput(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status invalidateStream(::android::media::AudioStreamType) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setVoiceVolume(float) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getRenderPosition(int32_t, ::android::media::RenderPosition*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getInputFramesLost(int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status newAudioUniqueId(::android::media::AudioUniqueIdUse, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status acquireAudioSessionId(int32_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status releaseAudioSessionId(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status queryNumberEffects(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status queryEffect(int32_t, ::android::media::EffectDescriptor*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getEffectDescriptor(const ::android::media::AudioUuid&, const ::android::media::AudioUuid&, int32_t, ::android::media::EffectDescriptor*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createEffect(const ::android::media::CreateEffectRequest&, ::android::media::CreateEffectResponse*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status moveEffects(int32_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setEffectSuspended(int32_t, int32_t, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status loadHwModule(const ::std::string&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getPrimaryOutputSamplingRate(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getPrimaryOutputFrameCount(int64_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setLowRamDevice(bool, int64_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getAudioPort(const ::android::media::AudioPort&, ::android::media::AudioPort*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createAudioPatch(const ::android::media::AudioPatch&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status releaseAudioPatch(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status listAudioPatches(int32_t, ::std::vector<::android::media::AudioPatch>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setAudioPortConfig(const ::android::media::AudioPortConfig&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getAudioHwSyncForSession(int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status systemReady() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status audioPolicyReady() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status frameCountHAL(int32_t, int64_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getMicrophones(::std::vector<::android::media::MicrophoneInfoData>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setAudioHalPids(const ::std::vector<int32_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setVibratorInfos(const ::std::vector<::android::media::AudioVibratorInfo>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status updateSecondaryOutputs(const ::std::vector<::android::media::TrackSecondaryOutputInfo>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IAudioFlingerServiceDefault

}  // namespace media

}  // namespace android
