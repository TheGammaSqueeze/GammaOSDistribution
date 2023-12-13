/*
 * Copyright (C) 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once
#include <atomic>
#include <android/hardware/audio/7.0/IStreamOut.h>
#include <android/hardware/audio/7.0/IDevice.h>
#include "stream_common.h"
#include "io_thread.h"
#include "primary_device.h"

namespace android {
namespace hardware {
namespace audio {
namespace V7_0 {
namespace implementation {

using ::android::sp;
using ::android::hardware::hidl_bitfield;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using namespace ::android::hardware::audio::common::V7_0;
using namespace ::android::hardware::audio::V7_0;

struct StreamOut : public IStreamOut {
    StreamOut(sp<PrimaryDevice> dev,
              int32_t ioHandle,
              const DeviceAddress& device,
              const AudioConfig& config,
              hidl_vec<AudioInOutFlag> flags,
              const SourceMetadata& sourceMetadata);
    ~StreamOut();

    // IStream
    Return<uint64_t> getFrameSize() override;
    Return<uint64_t> getFrameCount() override;
    Return<uint64_t> getBufferSize() override;
    Return<void> getSupportedProfiles(getSupportedProfiles_cb _hidl_cb) override;
    Return<void> getAudioProperties(getAudioProperties_cb _hidl_cb) override;
    Return<Result> setAudioProperties(const AudioConfigBaseOptional& config) override;
    Return<Result> addEffect(uint64_t effectId) override;
    Return<Result> removeEffect(uint64_t effectId) override;
    Return<Result> standby() override;
    Return<void> getDevices(getDevices_cb _hidl_cb) override;
    Return<Result> setDevices(const hidl_vec<DeviceAddress>& devices) override;
    Return<Result> setHwAvSync(uint32_t hwAvSync) override;
    Return<void> getParameters(const hidl_vec<ParameterValue>& context,
                               const hidl_vec<hidl_string>& keys,
                               getParameters_cb _hidl_cb) override;
    Return<Result> setParameters(const hidl_vec<ParameterValue>& context,
                                 const hidl_vec<ParameterValue>& parameters) override;
    Return<Result> start() override;
    Return<Result> stop() override;
    Return<void> createMmapBuffer(int32_t minSizeFrames, createMmapBuffer_cb _hidl_cb) override;
    Return<void> getMmapPosition(getMmapPosition_cb _hidl_cb) override;
    Return<Result> close() override;

    // IStreamOut
    Return<uint32_t> getLatency() override;
    Return<Result> setVolume(float left, float right) override;
    Return<Result> updateSourceMetadata(const SourceMetadata& sourceMetadata) override;
    Return<void> prepareForWriting(uint32_t frameSize, uint32_t framesCount,
                                   prepareForWriting_cb _hidl_cb) override;
    Return<void> getRenderPosition(getRenderPosition_cb _hidl_cb) override;
    Return<void> getNextWriteTimestamp(getNextWriteTimestamp_cb _hidl_cb) override;
    Return<Result> setCallback(const sp<IStreamOutCallback>& callback) override;
    Return<Result> clearCallback() override;
    Return<Result> setEventCallback(const sp<IStreamOutEventCallback>& callback) override;
    Return<void> supportsPauseAndResume(supportsPauseAndResume_cb _hidl_cb) override;
    Return<Result> pause() override;
    Return<Result> resume() override;
    Return<bool> supportsDrain() override;
    Return<Result> drain(AudioDrain type) override;
    Return<Result> flush() override;
    Return<void> getPresentationPosition(getPresentationPosition_cb _hidl_cb) override;
    Return<Result> selectPresentation(int32_t presentationId, int32_t programId) override;
    Return<void> getDualMonoMode(getDualMonoMode_cb _hidl_cb) override;
    Return<Result> setDualMonoMode(DualMonoMode mode) override;
    Return<void> getAudioDescriptionMixLevel(getAudioDescriptionMixLevel_cb _hidl_cb) override;
    Return<Result> setAudioDescriptionMixLevel(float leveldB) override;
    Return<void> getPlaybackRateParameters(getPlaybackRateParameters_cb _hidl_cb) override;
    Return<Result> setPlaybackRateParameters(const PlaybackRate &playbackRate) override;

    void setMasterVolume(float volume);
    float getEffectiveVolume() const { return mEffectiveVolume; }
    const DeviceAddress &getDeviceAddress() const { return mCommon.m_device; }
    const AudioConfig &getAudioConfig() const { return mCommon.m_config; }
    const hidl_vec<AudioInOutFlag> &getAudioOutputFlags() const { return mCommon.m_flags; }

    uint64_t &getFrameCounter() { return mFrames; }

    static bool validateDeviceAddress(const DeviceAddress& device);
    static bool validateFlags(const hidl_vec<AudioInOutFlag>& flags);
    static bool validateSourceMetadata(const SourceMetadata& sourceMetadata);

private:
    Result closeImpl(bool fromDctor);
    void updateEffectiveVolumeLocked();

    sp<PrimaryDevice> mDev;
    const StreamCommon mCommon;
    const SourceMetadata mSourceMetadata;
    std::unique_ptr<IOThread> mWriteThread;

    float mMasterVolume = 1.0f;  // requires mMutex
    float mStreamVolume = 1.0f;  // requires mMutex
    std::atomic<float> mEffectiveVolume = 1.0f;
    std::mutex mMutex;

    // The count is not reset to zero when output enters standby.
    uint64_t mFrames = 0;
};

}  // namespace implementation
}  // namespace V7_0
}  // namespace audio
}  // namespace hardware
}  // namespace android
