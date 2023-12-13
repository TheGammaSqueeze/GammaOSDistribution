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

package com.android.car.audio;

import static android.media.AudioDeviceInfo.TYPE_BUILTIN_MIC;
import static android.media.AudioDeviceInfo.TYPE_FM_TUNER;

import static com.android.car.audio.CarAudioUtils.hasExpired;
import static com.android.car.audio.CarAudioUtils.isMicrophoneInputDevice;

import static com.google.common.truth.Truth.assertThat;

import static org.mockito.Mockito.when;

import android.media.AudioDeviceInfo;

import androidx.test.ext.junit.runners.AndroidJUnit4;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mockito;

@RunWith(AndroidJUnit4.class)
public class CarAudioUtilsTest {

    @Test
    public void hasExpired_forCurrentTimeBeforeTimeout_returnsFalse() {
        assertThat(hasExpired(0, 100, 200)).isFalse();
    }

    @Test
    public void hasExpired_forCurrentTimeAfterTimeout_returnsFalse() {
        assertThat(hasExpired(0, 300, 200)).isTrue();
    }

    @Test
    public void isMicrophoneInputDevice_forMicrophoneDevice_returnsTrue() {
        AudioDeviceInfo deviceInfo = Mockito.mock(AudioDeviceInfo.class);
        when(deviceInfo.getType()).thenReturn(TYPE_BUILTIN_MIC);
        assertThat(isMicrophoneInputDevice(deviceInfo)).isTrue();
    }

    @Test
    public void isMicrophoneInputDevice_forNonMicrophoneDevice_returnsFalse() {
        AudioDeviceInfo deviceInfo = Mockito.mock(AudioDeviceInfo.class);
        when(deviceInfo.getType()).thenReturn(TYPE_FM_TUNER);
        assertThat(isMicrophoneInputDevice(deviceInfo)).isFalse();
    }
}
