#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/IAudioFlingerService.h>

namespace android {

namespace media {

class BpAudioFlingerService : public ::android::BpInterface<IAudioFlingerService> {
public:
  explicit BpAudioFlingerService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpAudioFlingerService() = default;
  ::android::binder::Status createTrack(const ::android::media::CreateTrackRequest& request, ::android::media::CreateTrackResponse* _aidl_return) override;
  ::android::binder::Status createRecord(const ::android::media::CreateRecordRequest& request, ::android::media::CreateRecordResponse* _aidl_return) override;
  ::android::binder::Status sampleRate(int32_t ioHandle, int32_t* _aidl_return) override;
  ::android::binder::Status format(int32_t output, ::android::media::audio::common::AudioFormat* _aidl_return) override;
  ::android::binder::Status frameCount(int32_t ioHandle, int64_t* _aidl_return) override;
  ::android::binder::Status latency(int32_t output, int32_t* _aidl_return) override;
  ::android::binder::Status setMasterVolume(float value) override;
  ::android::binder::Status setMasterMute(bool muted) override;
  ::android::binder::Status masterVolume(float* _aidl_return) override;
  ::android::binder::Status masterMute(bool* _aidl_return) override;
  ::android::binder::Status setMasterBalance(float balance) override;
  ::android::binder::Status getMasterBalance(float* _aidl_return) override;
  ::android::binder::Status setStreamVolume(::android::media::AudioStreamType stream, float value, int32_t output) override;
  ::android::binder::Status setStreamMute(::android::media::AudioStreamType stream, bool muted) override;
  ::android::binder::Status streamVolume(::android::media::AudioStreamType stream, int32_t output, float* _aidl_return) override;
  ::android::binder::Status streamMute(::android::media::AudioStreamType stream, bool* _aidl_return) override;
  ::android::binder::Status setMode(::android::media::AudioMode mode) override;
  ::android::binder::Status setMicMute(bool state) override;
  ::android::binder::Status getMicMute(bool* _aidl_return) override;
  ::android::binder::Status setRecordSilenced(int32_t portId, bool silenced) override;
  ::android::binder::Status setParameters(int32_t ioHandle, const ::std::string& keyValuePairs) override;
  ::android::binder::Status getParameters(int32_t ioHandle, const ::std::string& keys, ::std::string* _aidl_return) override;
  ::android::binder::Status registerClient(const ::android::sp<::android::media::IAudioFlingerClient>& client) override;
  ::android::binder::Status getInputBufferSize(int32_t sampleRate, ::android::media::audio::common::AudioFormat format, int32_t channelMask, int64_t* _aidl_return) override;
  ::android::binder::Status openOutput(const ::android::media::OpenOutputRequest& request, ::android::media::OpenOutputResponse* _aidl_return) override;
  ::android::binder::Status openDuplicateOutput(int32_t output1, int32_t output2, int32_t* _aidl_return) override;
  ::android::binder::Status closeOutput(int32_t output) override;
  ::android::binder::Status suspendOutput(int32_t output) override;
  ::android::binder::Status restoreOutput(int32_t output) override;
  ::android::binder::Status openInput(const ::android::media::OpenInputRequest& request, ::android::media::OpenInputResponse* _aidl_return) override;
  ::android::binder::Status closeInput(int32_t input) override;
  ::android::binder::Status invalidateStream(::android::media::AudioStreamType stream) override;
  ::android::binder::Status setVoiceVolume(float volume) override;
  ::android::binder::Status getRenderPosition(int32_t output, ::android::media::RenderPosition* _aidl_return) override;
  ::android::binder::Status getInputFramesLost(int32_t ioHandle, int32_t* _aidl_return) override;
  ::android::binder::Status newAudioUniqueId(::android::media::AudioUniqueIdUse use, int32_t* _aidl_return) override;
  ::android::binder::Status acquireAudioSessionId(int32_t audioSession, int32_t pid, int32_t uid) override;
  ::android::binder::Status releaseAudioSessionId(int32_t audioSession, int32_t pid) override;
  ::android::binder::Status queryNumberEffects(int32_t* _aidl_return) override;
  ::android::binder::Status queryEffect(int32_t index, ::android::media::EffectDescriptor* _aidl_return) override;
  ::android::binder::Status getEffectDescriptor(const ::android::media::AudioUuid& effectUUID, const ::android::media::AudioUuid& typeUUID, int32_t preferredTypeFlag, ::android::media::EffectDescriptor* _aidl_return) override;
  ::android::binder::Status createEffect(const ::android::media::CreateEffectRequest& request, ::android::media::CreateEffectResponse* _aidl_return) override;
  ::android::binder::Status moveEffects(int32_t session, int32_t srcOutput, int32_t dstOutput) override;
  ::android::binder::Status setEffectSuspended(int32_t effectId, int32_t sessionId, bool suspended) override;
  ::android::binder::Status loadHwModule(const ::std::string& name, int32_t* _aidl_return) override;
  ::android::binder::Status getPrimaryOutputSamplingRate(int32_t* _aidl_return) override;
  ::android::binder::Status getPrimaryOutputFrameCount(int64_t* _aidl_return) override;
  ::android::binder::Status setLowRamDevice(bool isLowRamDevice, int64_t totalMemory) override;
  ::android::binder::Status getAudioPort(const ::android::media::AudioPort& port, ::android::media::AudioPort* _aidl_return) override;
  ::android::binder::Status createAudioPatch(const ::android::media::AudioPatch& patch, int32_t* _aidl_return) override;
  ::android::binder::Status releaseAudioPatch(int32_t handle) override;
  ::android::binder::Status listAudioPatches(int32_t maxCount, ::std::vector<::android::media::AudioPatch>* _aidl_return) override;
  ::android::binder::Status setAudioPortConfig(const ::android::media::AudioPortConfig& config) override;
  ::android::binder::Status getAudioHwSyncForSession(int32_t sessionId, int32_t* _aidl_return) override;
  ::android::binder::Status systemReady() override;
  ::android::binder::Status audioPolicyReady() override;
  ::android::binder::Status frameCountHAL(int32_t ioHandle, int64_t* _aidl_return) override;
  ::android::binder::Status getMicrophones(::std::vector<::android::media::MicrophoneInfoData>* _aidl_return) override;
  ::android::binder::Status setAudioHalPids(const ::std::vector<int32_t>& pids) override;
  ::android::binder::Status setVibratorInfos(const ::std::vector<::android::media::AudioVibratorInfo>& vibratorInfos) override;
  ::android::binder::Status updateSecondaryOutputs(const ::std::vector<::android::media::TrackSecondaryOutputInfo>& trackSecondaryOutputInfos) override;
};  // class BpAudioFlingerService

}  // namespace media

}  // namespace android
