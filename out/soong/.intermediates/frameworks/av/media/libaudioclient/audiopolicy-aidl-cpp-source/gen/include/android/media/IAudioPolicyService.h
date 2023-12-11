#pragma once

#include <android/content/AttributionSourceState.h>
#include <android/media/AudioAttributesEx.h>
#include <android/media/AudioAttributesInternal.h>
#include <android/media/AudioConfig.h>
#include <android/media/AudioConfigBase.h>
#include <android/media/AudioDevice.h>
#include <android/media/AudioMix.h>
#include <android/media/AudioMode.h>
#include <android/media/AudioOffloadInfo.h>
#include <android/media/AudioOffloadMode.h>
#include <android/media/AudioPatch.h>
#include <android/media/AudioPolicyDeviceState.h>
#include <android/media/AudioPolicyForceUse.h>
#include <android/media/AudioPolicyForcedConfig.h>
#include <android/media/AudioPort.h>
#include <android/media/AudioPortConfig.h>
#include <android/media/AudioPortRole.h>
#include <android/media/AudioPortType.h>
#include <android/media/AudioProductStrategy.h>
#include <android/media/AudioSourceType.h>
#include <android/media/AudioStreamType.h>
#include <android/media/AudioUsage.h>
#include <android/media/AudioUuid.h>
#include <android/media/AudioVolumeGroup.h>
#include <android/media/DeviceRole.h>
#include <android/media/EffectDescriptor.h>
#include <android/media/GetInputForAttrResponse.h>
#include <android/media/GetOutputForAttrResponse.h>
#include <android/media/GetSpatializerResponse.h>
#include <android/media/IAudioPolicyServiceClient.h>
#include <android/media/ICaptureStateListener.h>
#include <android/media/INativeSpatializerCallback.h>
#include <android/media/Int.h>
#include <android/media/SoundTriggerSession.h>
#include <android/media/audio/common/AudioFormat.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <string>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace media {

class IAudioPolicyService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(AudioPolicyService)
  virtual ::android::binder::Status onNewAudioModulesAvailable() = 0;
  virtual ::android::binder::Status setDeviceConnectionState(const ::android::media::AudioDevice& device, ::android::media::AudioPolicyDeviceState state, const ::std::string& deviceName, ::android::media::audio::common::AudioFormat encodedFormat) = 0;
  virtual ::android::binder::Status getDeviceConnectionState(const ::android::media::AudioDevice& device, ::android::media::AudioPolicyDeviceState* _aidl_return) = 0;
  virtual ::android::binder::Status handleDeviceConfigChange(const ::android::media::AudioDevice& device, const ::std::string& deviceName, ::android::media::audio::common::AudioFormat encodedFormat) = 0;
  virtual ::android::binder::Status setPhoneState(::android::media::AudioMode state, int32_t uid) = 0;
  virtual ::android::binder::Status setForceUse(::android::media::AudioPolicyForceUse usage, ::android::media::AudioPolicyForcedConfig config) = 0;
  virtual ::android::binder::Status getForceUse(::android::media::AudioPolicyForceUse usage, ::android::media::AudioPolicyForcedConfig* _aidl_return) = 0;
  virtual ::android::binder::Status getOutput(::android::media::AudioStreamType stream, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getOutputForAttr(const ::android::media::AudioAttributesInternal& attr, int32_t session, const ::android::content::AttributionSourceState& attributionSource, const ::android::media::AudioConfig& config, int32_t flags, int32_t selectedDeviceId, ::android::media::GetOutputForAttrResponse* _aidl_return) = 0;
  virtual ::android::binder::Status startOutput(int32_t portId) = 0;
  virtual ::android::binder::Status stopOutput(int32_t portId) = 0;
  virtual ::android::binder::Status releaseOutput(int32_t portId) = 0;
  virtual ::android::binder::Status getInputForAttr(const ::android::media::AudioAttributesInternal& attr, int32_t input, int32_t riid, int32_t session, const ::android::content::AttributionSourceState& attributionSource, const ::android::media::AudioConfigBase& config, int32_t flags, int32_t selectedDeviceId, ::android::media::GetInputForAttrResponse* _aidl_return) = 0;
  virtual ::android::binder::Status startInput(int32_t portId) = 0;
  virtual ::android::binder::Status stopInput(int32_t portId) = 0;
  virtual ::android::binder::Status releaseInput(int32_t portId) = 0;
  virtual ::android::binder::Status initStreamVolume(::android::media::AudioStreamType stream, int32_t indexMin, int32_t indexMax) = 0;
  virtual ::android::binder::Status setStreamVolumeIndex(::android::media::AudioStreamType stream, int32_t device, int32_t index) = 0;
  virtual ::android::binder::Status getStreamVolumeIndex(::android::media::AudioStreamType stream, int32_t device, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status setVolumeIndexForAttributes(const ::android::media::AudioAttributesInternal& attr, int32_t device, int32_t index) = 0;
  virtual ::android::binder::Status getVolumeIndexForAttributes(const ::android::media::AudioAttributesInternal& attr, int32_t device, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getMaxVolumeIndexForAttributes(const ::android::media::AudioAttributesInternal& attr, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getMinVolumeIndexForAttributes(const ::android::media::AudioAttributesInternal& attr, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getStrategyForStream(::android::media::AudioStreamType stream, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getDevicesForStream(::android::media::AudioStreamType stream, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getDevicesForAttributes(const ::android::media::AudioAttributesEx& attr, ::std::vector<::android::media::AudioDevice>* _aidl_return) = 0;
  virtual ::android::binder::Status getOutputForEffect(const ::android::media::EffectDescriptor& desc, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status registerEffect(const ::android::media::EffectDescriptor& desc, int32_t io, int32_t strategy, int32_t session, int32_t id) = 0;
  virtual ::android::binder::Status unregisterEffect(int32_t id) = 0;
  virtual ::android::binder::Status setEffectEnabled(int32_t id, bool enabled) = 0;
  virtual ::android::binder::Status moveEffectsToIo(const ::std::vector<int32_t>& ids, int32_t io) = 0;
  virtual ::android::binder::Status isStreamActive(::android::media::AudioStreamType stream, int32_t inPastMs, bool* _aidl_return) = 0;
  virtual ::android::binder::Status isStreamActiveRemotely(::android::media::AudioStreamType stream, int32_t inPastMs, bool* _aidl_return) = 0;
  virtual ::android::binder::Status isSourceActive(::android::media::AudioSourceType source, bool* _aidl_return) = 0;
  virtual ::android::binder::Status queryDefaultPreProcessing(int32_t audioSession, ::android::media::Int* count, ::std::vector<::android::media::EffectDescriptor>* _aidl_return) = 0;
  virtual ::android::binder::Status addSourceDefaultEffect(const ::android::media::AudioUuid& type, const ::std::string& opPackageName, const ::android::media::AudioUuid& uuid, int32_t priority, ::android::media::AudioSourceType source, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status addStreamDefaultEffect(const ::android::media::AudioUuid& type, const ::std::string& opPackageName, const ::android::media::AudioUuid& uuid, int32_t priority, ::android::media::AudioUsage usage, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status removeSourceDefaultEffect(int32_t id) = 0;
  virtual ::android::binder::Status removeStreamDefaultEffect(int32_t id) = 0;
  virtual ::android::binder::Status setSupportedSystemUsages(const ::std::vector<::android::media::AudioUsage>& systemUsages) = 0;
  virtual ::android::binder::Status setAllowedCapturePolicy(int32_t uid, int32_t capturePolicy) = 0;
  virtual ::android::binder::Status getOffloadSupport(const ::android::media::AudioOffloadInfo& info, ::android::media::AudioOffloadMode* _aidl_return) = 0;
  virtual ::android::binder::Status isDirectOutputSupported(const ::android::media::AudioConfigBase& config, const ::android::media::AudioAttributesInternal& attributes, bool* _aidl_return) = 0;
  virtual ::android::binder::Status listAudioPorts(::android::media::AudioPortRole role, ::android::media::AudioPortType type, ::android::media::Int* count, ::std::vector<::android::media::AudioPort>* ports, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getAudioPort(const ::android::media::AudioPort& port, ::android::media::AudioPort* _aidl_return) = 0;
  virtual ::android::binder::Status createAudioPatch(const ::android::media::AudioPatch& patch, int32_t handle, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status releaseAudioPatch(int32_t handle) = 0;
  virtual ::android::binder::Status listAudioPatches(::android::media::Int* count, ::std::vector<::android::media::AudioPatch>* patches, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status setAudioPortConfig(const ::android::media::AudioPortConfig& config) = 0;
  virtual ::android::binder::Status registerClient(const ::android::sp<::android::media::IAudioPolicyServiceClient>& client) = 0;
  virtual ::android::binder::Status setAudioPortCallbacksEnabled(bool enabled) = 0;
  virtual ::android::binder::Status setAudioVolumeGroupCallbacksEnabled(bool enabled) = 0;
  virtual ::android::binder::Status acquireSoundTriggerSession(::android::media::SoundTriggerSession* _aidl_return) = 0;
  virtual ::android::binder::Status releaseSoundTriggerSession(int32_t session) = 0;
  virtual ::android::binder::Status getPhoneState(::android::media::AudioMode* _aidl_return) = 0;
  virtual ::android::binder::Status registerPolicyMixes(const ::std::vector<::android::media::AudioMix>& mixes, bool registration) = 0;
  virtual ::android::binder::Status setUidDeviceAffinities(int32_t uid, const ::std::vector<::android::media::AudioDevice>& devices) = 0;
  virtual ::android::binder::Status removeUidDeviceAffinities(int32_t uid) = 0;
  virtual ::android::binder::Status setUserIdDeviceAffinities(int32_t userId, const ::std::vector<::android::media::AudioDevice>& devices) = 0;
  virtual ::android::binder::Status removeUserIdDeviceAffinities(int32_t userId) = 0;
  virtual ::android::binder::Status startAudioSource(const ::android::media::AudioPortConfig& source, const ::android::media::AudioAttributesInternal& attributes, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status stopAudioSource(int32_t portId) = 0;
  virtual ::android::binder::Status setMasterMono(bool mono) = 0;
  virtual ::android::binder::Status getMasterMono(bool* _aidl_return) = 0;
  virtual ::android::binder::Status getStreamVolumeDB(::android::media::AudioStreamType stream, int32_t index, int32_t device, float* _aidl_return) = 0;
  virtual ::android::binder::Status getSurroundFormats(::android::media::Int* count, ::std::vector<::android::media::audio::common::AudioFormat>* formats, ::std::vector<bool>* formatsEnabled) = 0;
  virtual ::android::binder::Status getReportedSurroundFormats(::android::media::Int* count, ::std::vector<::android::media::audio::common::AudioFormat>* formats) = 0;
  virtual ::android::binder::Status getHwOffloadEncodingFormatsSupportedForA2DP(::std::vector<::android::media::audio::common::AudioFormat>* _aidl_return) = 0;
  virtual ::android::binder::Status setSurroundFormatEnabled(::android::media::audio::common::AudioFormat audioFormat, bool enabled) = 0;
  virtual ::android::binder::Status setAssistantUid(int32_t uid) = 0;
  virtual ::android::binder::Status setHotwordDetectionServiceUid(int32_t uid) = 0;
  virtual ::android::binder::Status setA11yServicesUids(const ::std::vector<int32_t>& uids) = 0;
  virtual ::android::binder::Status setCurrentImeUid(int32_t uid) = 0;
  virtual ::android::binder::Status isHapticPlaybackSupported(bool* _aidl_return) = 0;
  virtual ::android::binder::Status listAudioProductStrategies(::std::vector<::android::media::AudioProductStrategy>* _aidl_return) = 0;
  virtual ::android::binder::Status getProductStrategyFromAudioAttributes(const ::android::media::AudioAttributesEx& aa, bool fallbackOnDefault, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status listAudioVolumeGroups(::std::vector<::android::media::AudioVolumeGroup>* _aidl_return) = 0;
  virtual ::android::binder::Status getVolumeGroupFromAudioAttributes(const ::android::media::AudioAttributesEx& aa, bool fallbackOnDefault, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status setRttEnabled(bool enabled) = 0;
  virtual ::android::binder::Status isCallScreenModeSupported(bool* _aidl_return) = 0;
  virtual ::android::binder::Status setDevicesRoleForStrategy(int32_t strategy, ::android::media::DeviceRole role, const ::std::vector<::android::media::AudioDevice>& devices) = 0;
  virtual ::android::binder::Status removeDevicesRoleForStrategy(int32_t strategy, ::android::media::DeviceRole role) = 0;
  virtual ::android::binder::Status getDevicesForRoleAndStrategy(int32_t strategy, ::android::media::DeviceRole role, ::std::vector<::android::media::AudioDevice>* _aidl_return) = 0;
  virtual ::android::binder::Status setDevicesRoleForCapturePreset(::android::media::AudioSourceType audioSource, ::android::media::DeviceRole role, const ::std::vector<::android::media::AudioDevice>& devices) = 0;
  virtual ::android::binder::Status addDevicesRoleForCapturePreset(::android::media::AudioSourceType audioSource, ::android::media::DeviceRole role, const ::std::vector<::android::media::AudioDevice>& devices) = 0;
  virtual ::android::binder::Status removeDevicesRoleForCapturePreset(::android::media::AudioSourceType audioSource, ::android::media::DeviceRole role, const ::std::vector<::android::media::AudioDevice>& devices) = 0;
  virtual ::android::binder::Status clearDevicesRoleForCapturePreset(::android::media::AudioSourceType audioSource, ::android::media::DeviceRole role) = 0;
  virtual ::android::binder::Status getDevicesForRoleAndCapturePreset(::android::media::AudioSourceType audioSource, ::android::media::DeviceRole role, ::std::vector<::android::media::AudioDevice>* _aidl_return) = 0;
  virtual ::android::binder::Status registerSoundTriggerCaptureStateListener(const ::android::sp<::android::media::ICaptureStateListener>& listener, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getSpatializer(const ::android::sp<::android::media::INativeSpatializerCallback>& callback, ::android::media::GetSpatializerResponse* _aidl_return) = 0;
  virtual ::android::binder::Status canBeSpatialized(const ::std::optional<::android::media::AudioAttributesInternal>& attr, const ::std::optional<::android::media::AudioConfig>& config, const ::std::vector<::android::media::AudioDevice>& devices, bool* _aidl_return) = 0;
};  // class IAudioPolicyService

class IAudioPolicyServiceDefault : public IAudioPolicyService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onNewAudioModulesAvailable() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setDeviceConnectionState(const ::android::media::AudioDevice&, ::android::media::AudioPolicyDeviceState, const ::std::string&, ::android::media::audio::common::AudioFormat) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getDeviceConnectionState(const ::android::media::AudioDevice&, ::android::media::AudioPolicyDeviceState*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status handleDeviceConfigChange(const ::android::media::AudioDevice&, const ::std::string&, ::android::media::audio::common::AudioFormat) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setPhoneState(::android::media::AudioMode, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setForceUse(::android::media::AudioPolicyForceUse, ::android::media::AudioPolicyForcedConfig) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getForceUse(::android::media::AudioPolicyForceUse, ::android::media::AudioPolicyForcedConfig*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getOutput(::android::media::AudioStreamType, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getOutputForAttr(const ::android::media::AudioAttributesInternal&, int32_t, const ::android::content::AttributionSourceState&, const ::android::media::AudioConfig&, int32_t, int32_t, ::android::media::GetOutputForAttrResponse*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status startOutput(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status stopOutput(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status releaseOutput(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getInputForAttr(const ::android::media::AudioAttributesInternal&, int32_t, int32_t, int32_t, const ::android::content::AttributionSourceState&, const ::android::media::AudioConfigBase&, int32_t, int32_t, ::android::media::GetInputForAttrResponse*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status startInput(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status stopInput(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status releaseInput(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status initStreamVolume(::android::media::AudioStreamType, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setStreamVolumeIndex(::android::media::AudioStreamType, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getStreamVolumeIndex(::android::media::AudioStreamType, int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setVolumeIndexForAttributes(const ::android::media::AudioAttributesInternal&, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getVolumeIndexForAttributes(const ::android::media::AudioAttributesInternal&, int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getMaxVolumeIndexForAttributes(const ::android::media::AudioAttributesInternal&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getMinVolumeIndexForAttributes(const ::android::media::AudioAttributesInternal&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getStrategyForStream(::android::media::AudioStreamType, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getDevicesForStream(::android::media::AudioStreamType, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getDevicesForAttributes(const ::android::media::AudioAttributesEx&, ::std::vector<::android::media::AudioDevice>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getOutputForEffect(const ::android::media::EffectDescriptor&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status registerEffect(const ::android::media::EffectDescriptor&, int32_t, int32_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unregisterEffect(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setEffectEnabled(int32_t, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status moveEffectsToIo(const ::std::vector<int32_t>&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isStreamActive(::android::media::AudioStreamType, int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isStreamActiveRemotely(::android::media::AudioStreamType, int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isSourceActive(::android::media::AudioSourceType, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status queryDefaultPreProcessing(int32_t, ::android::media::Int*, ::std::vector<::android::media::EffectDescriptor>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status addSourceDefaultEffect(const ::android::media::AudioUuid&, const ::std::string&, const ::android::media::AudioUuid&, int32_t, ::android::media::AudioSourceType, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status addStreamDefaultEffect(const ::android::media::AudioUuid&, const ::std::string&, const ::android::media::AudioUuid&, int32_t, ::android::media::AudioUsage, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status removeSourceDefaultEffect(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status removeStreamDefaultEffect(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setSupportedSystemUsages(const ::std::vector<::android::media::AudioUsage>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setAllowedCapturePolicy(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getOffloadSupport(const ::android::media::AudioOffloadInfo&, ::android::media::AudioOffloadMode*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isDirectOutputSupported(const ::android::media::AudioConfigBase&, const ::android::media::AudioAttributesInternal&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status listAudioPorts(::android::media::AudioPortRole, ::android::media::AudioPortType, ::android::media::Int*, ::std::vector<::android::media::AudioPort>*, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getAudioPort(const ::android::media::AudioPort&, ::android::media::AudioPort*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createAudioPatch(const ::android::media::AudioPatch&, int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status releaseAudioPatch(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status listAudioPatches(::android::media::Int*, ::std::vector<::android::media::AudioPatch>*, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setAudioPortConfig(const ::android::media::AudioPortConfig&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status registerClient(const ::android::sp<::android::media::IAudioPolicyServiceClient>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setAudioPortCallbacksEnabled(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setAudioVolumeGroupCallbacksEnabled(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status acquireSoundTriggerSession(::android::media::SoundTriggerSession*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status releaseSoundTriggerSession(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getPhoneState(::android::media::AudioMode*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status registerPolicyMixes(const ::std::vector<::android::media::AudioMix>&, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setUidDeviceAffinities(int32_t, const ::std::vector<::android::media::AudioDevice>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status removeUidDeviceAffinities(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setUserIdDeviceAffinities(int32_t, const ::std::vector<::android::media::AudioDevice>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status removeUserIdDeviceAffinities(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status startAudioSource(const ::android::media::AudioPortConfig&, const ::android::media::AudioAttributesInternal&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status stopAudioSource(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setMasterMono(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getMasterMono(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getStreamVolumeDB(::android::media::AudioStreamType, int32_t, int32_t, float*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getSurroundFormats(::android::media::Int*, ::std::vector<::android::media::audio::common::AudioFormat>*, ::std::vector<bool>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getReportedSurroundFormats(::android::media::Int*, ::std::vector<::android::media::audio::common::AudioFormat>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getHwOffloadEncodingFormatsSupportedForA2DP(::std::vector<::android::media::audio::common::AudioFormat>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setSurroundFormatEnabled(::android::media::audio::common::AudioFormat, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setAssistantUid(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setHotwordDetectionServiceUid(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setA11yServicesUids(const ::std::vector<int32_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setCurrentImeUid(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isHapticPlaybackSupported(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status listAudioProductStrategies(::std::vector<::android::media::AudioProductStrategy>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getProductStrategyFromAudioAttributes(const ::android::media::AudioAttributesEx&, bool, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status listAudioVolumeGroups(::std::vector<::android::media::AudioVolumeGroup>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getVolumeGroupFromAudioAttributes(const ::android::media::AudioAttributesEx&, bool, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setRttEnabled(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isCallScreenModeSupported(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setDevicesRoleForStrategy(int32_t, ::android::media::DeviceRole, const ::std::vector<::android::media::AudioDevice>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status removeDevicesRoleForStrategy(int32_t, ::android::media::DeviceRole) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getDevicesForRoleAndStrategy(int32_t, ::android::media::DeviceRole, ::std::vector<::android::media::AudioDevice>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setDevicesRoleForCapturePreset(::android::media::AudioSourceType, ::android::media::DeviceRole, const ::std::vector<::android::media::AudioDevice>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status addDevicesRoleForCapturePreset(::android::media::AudioSourceType, ::android::media::DeviceRole, const ::std::vector<::android::media::AudioDevice>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status removeDevicesRoleForCapturePreset(::android::media::AudioSourceType, ::android::media::DeviceRole, const ::std::vector<::android::media::AudioDevice>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status clearDevicesRoleForCapturePreset(::android::media::AudioSourceType, ::android::media::DeviceRole) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getDevicesForRoleAndCapturePreset(::android::media::AudioSourceType, ::android::media::DeviceRole, ::std::vector<::android::media::AudioDevice>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status registerSoundTriggerCaptureStateListener(const ::android::sp<::android::media::ICaptureStateListener>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getSpatializer(const ::android::sp<::android::media::INativeSpatializerCallback>&, ::android::media::GetSpatializerResponse*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status canBeSpatialized(const ::std::optional<::android::media::AudioAttributesInternal>&, const ::std::optional<::android::media::AudioConfig>&, const ::std::vector<::android::media::AudioDevice>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IAudioPolicyServiceDefault

}  // namespace media

}  // namespace android
