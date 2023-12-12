/*
 * Copyright (C) 2021 The Android Open Source Project
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

#include <aidl/android/hardware/vibrator/BnVibrator.h>
#include <android-base/unique_fd.h>
#include <tinyalsa/asoundlib.h>

#include <array>
#include <fstream>
#include <future>

namespace aidl {
namespace android {
namespace hardware {
namespace vibrator {

class Vibrator : public BnVibrator {
  public:
    // APIs for interfacing with the kernel driver.
    class HwApi {
      public:
        virtual ~HwApi() = default;
        // Stores the LRA resonant frequency to be used for PWLE playback
        // and click compensation.
        virtual bool setF0(std::string value) = 0;
        // Stores the frequency offset for long vibrations.
        virtual bool setF0Offset(uint32_t value) = 0;
        // Stores the LRA series resistance to be used for click
        // compensation.
        virtual bool setRedc(std::string value) = 0;
        // Stores the LRA Q factor to be used for Q-dependent waveform
        // selection.
        virtual bool setQ(std::string value) = 0;
        // Reports the number of effect waveforms loaded in firmware.
        virtual bool getEffectCount(uint32_t *value) = 0;
        // Blocks until vibrator reaches desired state
        // ("Vibe state: Haptic" means enabled).
        // ("Vibe state: Stopped" means disabled).
        virtual bool pollVibeState(std::string value, int32_t timeoutMs = -1) = 0;
        // Enables/disables closed-loop active braking.
        virtual bool setClabEnable(bool value) = 0;
        // Reports the number of available PWLE segments.
        virtual bool getAvailablePwleSegments(uint32_t *value) = 0;
        // Specifies piecewise-linear specifications to generate complex
        // waveforms.
        virtual bool setPwle(std::string value) = 0;
        // Reports whether getOwtFreeSpace() is supported.
        virtual bool hasOwtFreeSpace() = 0;
        // Reports the available OWT bytes.
        virtual bool getOwtFreeSpace(uint32_t *value) = 0;
        // Emit diagnostic information to the given file.
        virtual void debug(int fd) = 0;
    };

    // APIs for obtaining calibration/configuration data from persistent memory.
    class HwCal {
      public:
        virtual ~HwCal() = default;
        // Obtain the calibration version
        virtual bool getVersion(uint32_t *value) = 0;
        // Obtains the LRA resonant frequency to be used for PWLE playback
        // and click compensation.
        virtual bool getF0(std::string *value) = 0;
        // Obtains the LRA series resistance to be used for click
        // compensation.
        virtual bool getRedc(std::string *value) = 0;
        // Obtains the LRA Q factor to be used for Q-dependent waveform
        // selection.
        virtual bool getQ(std::string *value) = 0;
        // Obtains frequency shift for long vibrations.
        virtual bool getLongFrequencyShift(int32_t *value) = 0;
        // Obtains the v0/v1(min/max) voltage levels to be applied for
        // tick/click/long in units of 1%.
        virtual bool getTickVolLevels(std::array<uint32_t, 2> *value) = 0;
        virtual bool getClickVolLevels(std::array<uint32_t, 2> *value) = 0;
        virtual bool getLongVolLevels(std::array<uint32_t, 2> *value) = 0;
        // Checks if the chirp feature is enabled.
        virtual bool isChirpEnabled() = 0;
        // Obtains the supported primitive effects.
        virtual bool getSupportedPrimitives(uint32_t *value) = 0;
        // Emit diagnostic information to the given file.
        virtual void debug(int fd) = 0;
    };

  public:
    Vibrator(std::unique_ptr<HwApi> hwapi, std::unique_ptr<HwCal> hwcal);

    ndk::ScopedAStatus getCapabilities(int32_t *_aidl_return) override;
    ndk::ScopedAStatus off() override;
    ndk::ScopedAStatus on(int32_t timeoutMs,
                          const std::shared_ptr<IVibratorCallback> &callback) override;
    ndk::ScopedAStatus perform(Effect effect, EffectStrength strength,
                               const std::shared_ptr<IVibratorCallback> &callback,
                               int32_t *_aidl_return) override;
    ndk::ScopedAStatus getSupportedEffects(std::vector<Effect> *_aidl_return) override;
    ndk::ScopedAStatus setAmplitude(float amplitude) override;
    ndk::ScopedAStatus setExternalControl(bool enabled) override;
    ndk::ScopedAStatus getCompositionDelayMax(int32_t *maxDelayMs);
    ndk::ScopedAStatus getCompositionSizeMax(int32_t *maxSize);
    ndk::ScopedAStatus getSupportedPrimitives(std::vector<CompositePrimitive> *supported) override;
    ndk::ScopedAStatus getPrimitiveDuration(CompositePrimitive primitive,
                                            int32_t *durationMs) override;
    ndk::ScopedAStatus compose(const std::vector<CompositeEffect> &composite,
                               const std::shared_ptr<IVibratorCallback> &callback) override;
    ndk::ScopedAStatus getSupportedAlwaysOnEffects(std::vector<Effect> *_aidl_return) override;
    ndk::ScopedAStatus alwaysOnEnable(int32_t id, Effect effect, EffectStrength strength) override;
    ndk::ScopedAStatus alwaysOnDisable(int32_t id) override;
    ndk::ScopedAStatus getResonantFrequency(float *resonantFreqHz) override;
    ndk::ScopedAStatus getQFactor(float *qFactor) override;
    ndk::ScopedAStatus getFrequencyResolution(float *freqResolutionHz) override;
    ndk::ScopedAStatus getFrequencyMinimum(float *freqMinimumHz) override;
    ndk::ScopedAStatus getBandwidthAmplitudeMap(std::vector<float> *_aidl_return) override;
    ndk::ScopedAStatus getPwlePrimitiveDurationMax(int32_t *durationMs) override;
    ndk::ScopedAStatus getPwleCompositionSizeMax(int32_t *maxSize) override;
    ndk::ScopedAStatus getSupportedBraking(std::vector<Braking> *supported) override;
    ndk::ScopedAStatus composePwle(const std::vector<PrimitivePwle> &composite,
                                   const std::shared_ptr<IVibratorCallback> &callback) override;

    binder_status_t dump(int fd, const char **args, uint32_t numArgs) override;

  private:
    ndk::ScopedAStatus on(uint32_t timeoutMs, uint32_t effectIndex,
                          const std::shared_ptr<IVibratorCallback> &callback);
    // set 'amplitude' based on an arbitrary scale determined by 'maximum'
    ndk::ScopedAStatus setEffectAmplitude(float amplitude, float maximum);
    ndk::ScopedAStatus setGlobalAmplitude(bool set);
    // 'simple' effects are those precompiled and loaded into the controller
    ndk::ScopedAStatus getSimpleDetails(Effect effect, EffectStrength strength,
                                        uint32_t *outEffectIndex, uint32_t *outTimeMs,
                                        uint32_t *outVolLevel);
    // 'compound' effects are those composed by stringing multiple 'simple' effects
    ndk::ScopedAStatus getCompoundDetails(Effect effect, EffectStrength strength,
                                          uint32_t *outTimeMs, struct dspmem_chunk *outCh);
    ndk::ScopedAStatus getPrimitiveDetails(CompositePrimitive primitive, uint32_t *outEffectIndex);
    ndk::ScopedAStatus uploadOwtEffect(uint8_t *owtData, uint32_t num_bytes,
                                       uint32_t *outEffectIndex);
    ndk::ScopedAStatus performEffect(Effect effect, EffectStrength strength,
                                     const std::shared_ptr<IVibratorCallback> &callback,
                                     int32_t *outTimeMs);
    ndk::ScopedAStatus performEffect(uint32_t effectIndex, uint32_t volLevel,
                                     struct dspmem_chunk *ch,
                                     const std::shared_ptr<IVibratorCallback> &callback);
    ndk::ScopedAStatus setPwle(const std::string &pwleQueue);
    bool isUnderExternalControl();
    void waitForComplete(std::shared_ptr<IVibratorCallback> &&callback);
    uint32_t intensityToVolLevel(float intensity, uint32_t effectIndex);
    bool findHapticAlsaDevice(int *card, int *device);
    bool hasHapticAlsaDevice();
    bool enableHapticPcmAmp(struct pcm **haptic_pcm, bool enable, int card, int device);

    std::unique_ptr<HwApi> mHwApi;
    std::unique_ptr<HwCal> mHwCal;
    uint32_t mF0Offset;
    std::array<uint32_t, 2> mTickEffectVol;
    std::array<uint32_t, 2> mClickEffectVol;
    std::array<uint32_t, 2> mLongEffectVol;
    std::vector<uint32_t> mEffectDurations;
    std::future<void> mAsyncHandle;
    int32_t compositionSizeMax;
    ::android::base::unique_fd mInputFd;
    int8_t mActiveId{-1};
    struct pcm *mHapticPcm;
    int mCard;
    int mDevice;
    bool mHasHapticAlsaDevice;
    bool mIsUnderExternalControl;
    float mLongEffectScale = 1.0;
    bool mIsChirpEnabled;
    uint32_t mSupportedPrimitivesBits = 0x0;
    std::vector<CompositePrimitive> mSupportedPrimitives;
};

}  // namespace vibrator
}  // namespace hardware
}  // namespace android
}  // namespace aidl
