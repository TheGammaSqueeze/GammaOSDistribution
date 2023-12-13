/**
 * Copyright 2021, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package android.media.tv.tuner;

import android.hardware.common.NativeHandle;
import android.media.tv.tuner.TunerAudioExtraMetaData;

/**
 * Filter Event for Audio or Video Filter.
 *
 * {@hide}
 */
parcelable TunerFilterMediaEvent {
    char streamId;

    /**
     * true if PTS is present in PES header.
     */
    boolean isPtsPresent;

    /**
     * Presentation Time Stamp for audio or video frame. It based on 90KHz has
     * the same format as PTS (Presentation Time Stamp).
     */
    long pts;

    /**
     * Data size in bytes of audio or video frame
     */
    int dataLength;

    /**
     *  The offset in the memory block which is shared among multiple
     *  MediaEvents.
     */
    int offset;

    /**
     * A handle associated to the memory where audio or video data stays.
     */
    NativeHandle avMemory;

    /**
     * True if the avMemory is in secure area, and isn't mappable.
     */
    boolean isSecureMemory;

    /**
     * An Id is used by HAL to provide additional information for AV data.
     * For secure audio, it's the audio handle used by Audio Track.
     */
    long avDataId;

    /**
     * MPU sequence number of filtered data (only for MMTP)
     */
    int mpuSequenceNumber;

    boolean isPesPrivateData;

    /**
     * If TunerAudioExtraMetaData field is valid or not
     */
    boolean isAudioExtraMetaData;

    /**
     * Only valid when isAudioExtraMetaData is true
     */
    TunerAudioExtraMetaData audio;
}
