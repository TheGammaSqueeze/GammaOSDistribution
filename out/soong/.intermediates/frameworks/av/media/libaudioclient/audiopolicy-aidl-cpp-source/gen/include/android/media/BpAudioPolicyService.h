#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/IAudioPolicyService.h>

namespace android {

namespace media {

class BpAudioPolicyService : public ::android::BpInterface<IAudioPolicyService> {
public:
  explicit BpAudioPolicyService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpAudioPolicyService() = default;
  ::android::binder::Status onNewAudioModulesAvailable() override;
  ::android::binder::Status setDeviceConnectionState(const ::android::media::AudioDevice& device, ::android::media::AudioPolicyDeviceState state, const ::std::string& deviceName, ::android::media::audio::common::AudioFormat encodedFormat) override;
  ::android::binder::Status getDeviceConnectionState(const ::android::media::AudioDevice& device, ::android::media::AudioPolicyDeviceState* _aidl_return) override;
  ::android::binder::Status handleDeviceConfigChange(const ::android::media::AudioDevice& device, const ::std::string& deviceName, ::android::media::audio::common::AudioFormat encodedFormat) override;
  ::android::binder::Status setPhoneState(::android::media::AudioMode state, int32_t uid) override;
  ::android::binder::Status setForceUse(::android::media::AudioPolicyForceUse usage, ::android::media::AudioPolicyForcedConfig config) override;
  ::android::binder::Status getForceUse(::android::media::AudioPolicyForceUse usage, ::android::media::AudioPolicyForcedConfig* _aidl_return) override;
  ::android::binder::Status getOutput(::android::media::AudioStreamType stream, int32_t* _aidl_return) override;
  ::android::binder::Status getOutputForAttr(const ::android::media::AudioAttributesInternal& attr, int32_t session, const ::android::content::AttributionSourceState& attributionSource, const ::android::media::AudioConfig& config, int32_t flags, int32_t selectedDeviceId, ::android::media::GetOutputForAttrResponse* _aidl_return) override;
  ::android::binder::Status startOutput(int32_t portId) override;
  ::android::binder::Status stopOutput(int32_t portId) override;
  ::android::binder::Status releaseOutput(int32_t portId) override;
  ::android::binder::Status getInputForAttr(const ::android::media::AudioAttributesInternal& attr, int32_t input, int32_t riid, int32_t session, const ::android::content::AttributionSourceState& attributionSource, const ::android::media::AudioConfigBase& config, int32_t flags, int32_t selectedDeviceId, ::android::media::GetInputForAttrResponse* _aidl_return) override;
  ::android::binder::Status startInput(int32_t portId) override;
  ::android::binder::Status stopInput(int32_t portId) override;
  ::android::binder::Status releaseInput(int32_t portId) override;
  ::android::binder::Status initStreamVolume(::android::media::AudioStreamType stream, int32_t indexMin, int32_t indexMax) override;
  ::android::binder::Status setStreamVolumeIndex(::android::media::AudioStreamType stream, int32_t device, int32_t index) override;
  ::android::binder::Status getStreamVolumeIndex(::android::media::AudioStreamType stream, int32_t device, int32_t* _aidl_return) override;
  ::android::binder::Status setVolumeIndexForAttributes(const ::android::media::AudioAttributesInternal& attr, int32_t device, int32_t index) override;
  ::android::binder::Status getVolumeIndexForAttributes(const ::android::media::AudioAttributesInternal& attr, int32_t device, int32_t* _aidl_return) override;
  ::android::binder::Status getMaxVolumeIndexForAttributes(const ::android::media::AudioAttributesInternal& attr, int32_t* _aidl_return) override;
  ::android::binder::Status getMinVolumeIndexForAttributes(const ::android::media::AudioAttributesInternal& attr, int32_t* _aidl_return) override;
  ::android::binder::Status getStrategyForStream(::android::media::AudioStreamType stream, int32_t* _aidl_return) override;
  ::android::binder::Status getDevicesForStream(::android::media::AudioStreamType stream, int32_t* _aidl_return) override;
  ::android::binder::Status getDevicesForAttributes(const ::android::media::AudioAttributesEx& attr, ::std::vector<::android::media::AudioDevice>* _aidl_return) override;
  ::android::binder::Status getOutputForEffect(const ::android::media::EffectDescriptor& desc, int32_t* _aidl_return) override;
  ::android::binder::Status registerEffect(const ::android::media::EffectDescriptor& desc, int32_t io, int32_t strategy, int32_t session, int32_t id) override;
  ::android::binder::Status unregisterEffect(int32_t id) override;
  ::android::binder::Status setEffectEnabled(int32_t id, bool enabled) override;
  ::android::binder::Status moveEffectsToIo(const ::std::vector<int32_t>& ids, int32_t io) override;
  ::android::binder::Status isStreamActive(::android::media::AudioStreamType stream, int32_t inPastMs, bool* _aidl_return) override;
  ::android::binder::Status isStreamActiveRemotely(::android::media::AudioStreamType stream, int32_t inPastMs, bool* _aidl_return) override;
  ::android::binder::Status isSourceActive(::android::media::AudioSourceType source, bool* _aidl_return) override;
  ::android::binder::Status queryDefaultPreProcessing(int32_t audioSession, ::android::media::Int* count, ::std::vector<::android::media::EffectDescriptor>* _aidl_return) override;
  ::android::binder::Status addSourceDefaultEffect(const ::android::media::AudioUuid& type, const ::std::string& opPackageName, const ::android::media::AudioUuid& uuid, int32_t priority, ::android::media::AudioSourceType source, int32_t* _aidl_return) override;
  ::android::binder::Status addStreamDefaultEffect(const ::android::media::AudioUuid& type, const ::std::string& opPackageName, const ::android::media::AudioUuid& uuid, int32_t priority, ::android::media::AudioUsage usage, int32_t* _aidl_return) override;
  ::android::binder::Status removeSourceDefaultEffect(int32_t id) override;
  ::android::binder::Status removeStreamDefaultEffect(int32_t id) override;
  ::android::binder::Status setSupportedSystemUsages(const ::std::vector<::android::media::AudioUsage>& systemUsages) override;
  ::android::binder::Status setAllowedCapturePolicy(int32_t uid, int32_t capturePolicy) override;
  ::android::binder::Status getOffloadSupport(const ::android::media::AudioOffloadInfo& info, ::android::media::AudioOffloadMode* _aidl_return) override;
  ::android::binder::Status isDirectOutputSupported(const ::android::media::AudioConfigBase& config, const ::android::media::AudioAttributesInternal& attributes, bool* _aidl_return) override;
  ::android::binder::Status listAudioPorts(::android::media::AudioPortRole role, ::android::media::AudioPortType type, ::android::media::Int* count, ::std::vector<::android::media::AudioPort>* ports, int32_t* _aidl_return) override;
  ::android::binder::Status getAudioPort(const ::android::media::AudioPort& port, ::android::media::AudioPort* _aidl_return) override;
  ::android::binder::Status createAudioPatch(const ::android::media::AudioPatch& patch, int32_t handle, int32_t* _aidl_return) override;
  ::android::binder::Status releaseAudioPatch(int32_t handle) override;
  ::android::binder::Status listAudioPatches(::android::media::Int* count, ::std::vector<::android::media::AudioPatch>* patches, int32_t* _aidl_return) override;
  ::android::binder::Status setAudioPortConfig(const ::android::media::AudioPortConfig& config) override;
  ::android::binder::Status registerClient(const ::android::sp<::android::media::IAudioPolicyServiceClient>& client) override;
  ::android::binder::Status setAudioPortCallbacksEnabled(bool enabled) override;
  ::android::binder::Status setAudioVolumeGroupCallbacksEnabled(bool enabled) override;
  ::android::binder::Status acquireSoundTriggerSession(::android::media::SoundTriggerSession* _aidl_return) override;
  ::android::binder::Status releaseSoundTriggerSession(int32_t session) override;
  ::android::binder::Status getPhoneState(::android::media::AudioMode* _aidl_return) override;
  ::android::binder::Status registerPolicyMixes(const ::std::vector<::android::media::AudioMix>& mixes, bool registration) override;
  ::android::binder::Status setUidDeviceAffinities(int32_t uid, const ::std::vector<::android::media::AudioDevice>& devices) override;
  ::android::binder::Status removeUidDeviceAffinities(int32_t uid) override;
  ::android::binder::Status setUserIdDeviceAffinities(int32_t userId, const ::std::vector<::android::media::AudioDevice>& devices) override;
  ::android::binder::Status removeUserIdDeviceAffinities(int32_t userId) override;
  ::android::binder::Status startAudioSource(const ::android::media::AudioPortConfig& source, const ::android::media::AudioAttributesInternal& attributes, int32_t* _aidl_return) override;
  ::android::binder::Status stopAudioSource(int32_t portId) override;
  ::android::binder::Status setMasterMono(bool mono) override;
  ::android::binder::Status getMasterMono(bool* _aidl_return) override;
  ::android::binder::Status getStreamVolumeDB(::android::media::AudioStreamType stream, int32_t index, int32_t device, float* _aidl_return) override;
  ::android::binder::Status getSurroundFormats(::android::media::Int* count, ::std::vector<::android::media::audio::common::AudioFormat>* formats, ::std::vector<bool>* formatsEnabled) override;
  ::android::binder::Status getReportedSurroundFormats(::android::media::Int* count, ::std::vector<::android::media::audio::common::AudioFormat>* formats) override;
  ::android::binder::Status getHwOffloadEncodingFormatsSupportedForA2DP(::std::vector<::android::media::audio::common::AudioFormat>* _aidl_return) override;
  ::android::binder::Status setSurroundFormatEnabled(::android::media::audio::common::AudioFormat audioFormat, bool enabled) override;
  ::android::binder::Status setAssistantUid(int32_t uid) override;
  ::android::binder::Status setHotwordDetectionServiceUid(int32_t uid) override;
  ::android::binder::Status setA11yServicesUids(const ::std::vector<int32_t>& uids) override;
  ::android::binder::Status setCurrentImeUid(int32_t uid) override;
  ::android::binder::Status isHapticPlaybackSupported(bool* _aidl_return) override;
  ::android::binder::Status listAudioProductStrategies(::std::vector<::android::media::AudioProductStrategy>* _aidl_return) override;
  ::android::binder::Status getProductStrategyFromAudioAttributes(const ::android::media::AudioAttributesEx& aa, bool fallbackOnDefault, int32_t* _aidl_return) override;
  ::android::binder::Status listAudioVolumeGroups(::std::vector<::android::media::AudioVolumeGroup>* _aidl_return) override;
  ::android::binder::Status getVolumeGroupFromAudioAttributes(const ::android::media::AudioAttributesEx& aa, bool fallbackOnDefault, int32_t* _aidl_return) override;
  ::android::binder::Status setRttEnabled(bool enabled) override;
  ::android::binder::Status isCallScreenModeSupported(bool* _aidl_return) override;
  ::android::binder::Status setDevicesRoleForStrategy(int32_t strategy, ::android::media::DeviceRole role, const ::std::vector<::android::media::AudioDevice>& devices) override;
  ::android::binder::Status removeDevicesRoleForStrategy(int32_t strategy, ::android::media::DeviceRole role) override;
  ::android::binder::Status getDevicesForRoleAndStrategy(int32_t strategy, ::android::media::DeviceRole role, ::std::vector<::android::media::AudioDevice>* _aidl_return) override;
  ::android::binder::Status setDevicesRoleForCapturePreset(::android::media::AudioSourceType audioSource, ::android::media::DeviceRole role, const ::std::vector<::android::media::AudioDevice>& devices) override;
  ::android::binder::Status addDevicesRoleForCapturePreset(::android::media::AudioSourceType audioSource, ::android::media::DeviceRole role, const ::std::vector<::android::media::AudioDevice>& devices) override;
  ::android::binder::Status removeDevicesRoleForCapturePreset(::android::media::AudioSourceType audioSource, ::android::media::DeviceRole role, const ::std::vector<::android::media::AudioDevice>& devices) override;
  ::android::binder::Status clearDevicesRoleForCapturePreset(::android::media::AudioSourceType audioSource, ::android::media::DeviceRole role) override;
  ::android::binder::Status getDevicesForRoleAndCapturePreset(::android::media::AudioSourceType audioSource, ::android::media::DeviceRole role, ::std::vector<::android::media::AudioDevice>* _aidl_return) override;
  ::android::binder::Status registerSoundTriggerCaptureStateListener(const ::android::sp<::android::media::ICaptureStateListener>& listener, bool* _aidl_return) override;
  ::android::binder::Status getSpatializer(const ::android::sp<::android::media::INativeSpatializerCallback>& callback, ::android::media::GetSpatializerResponse* _aidl_return) override;
  ::android::binder::Status canBeSpatialized(const ::std::optional<::android::media::AudioAttributesInternal>& attr, const ::std::optional<::android::media::AudioConfig>& config, const ::std::vector<::android::media::AudioDevice>& devices, bool* _aidl_return) override;
};  // class BpAudioPolicyService

}  // namespace media

}  // namespace android
