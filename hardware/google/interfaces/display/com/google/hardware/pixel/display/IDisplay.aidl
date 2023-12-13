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

package com.google.hardware.pixel.display;

import com.google.hardware.pixel.display.HbmState;
import com.google.hardware.pixel.display.LbeState;
import android.hardware.common.NativeHandle;

@VintfStability
interface IDisplay {
    /**
     * Query Display High Brightness Mode Supported
     *
     * @return true if HBM is supported on this platform.
     *         If false, HBM is not supported.
     */
    boolean isHbmSupported();

    /**
     * Set Display High Brightness Mode
     *
     * @param state to be queried.
     */
    void setHbmState(in HbmState state);

    /**
     * Get Display High Brightness Mode State
     *
     * @return state of display high brightness mode
     */
    HbmState getHbmState();

    /**
     * Query Display Local Brightness Enhancement Supported
     *
     * @return true if LBE is supported on this platform.
     *         If false, LBE is not supported.
     */
    boolean isLbeSupported();

    /**
     * Set Display Local Brightness Enhancement
     *
     * @param state to be queried.
     */
    void setLbeState(in LbeState state);

    /**
     * Set Display Local Brightness Enhancement Ambient Light
     *
     * @param ambientLux the proper ambient light in Lux.
     *        The value is equal to zero or above zero.
     */
    void setLbeAmbientLight(in int ambientLux);

    /**
     * Get Display Local Brightness Enhancement State
     *
     * @return state of display local brightness enhancement
     */
    LbeState getLbeState();

    /**
     * Query Display Local High Brightness Mode Supported
     *
     * @return true if LHBM is supported on this platform.
     *         If false, LHBM is not supported.
     */
    boolean isLhbmSupported();

    /**
     * Set Display Local High Brightness Mode
     *
     * @param enabled true if LHBM should be enabled, false otherwise.
     */
    void setLhbmState(in boolean enabled);

    /**
     * Get Display Local High Brightness Mode State
     *
     * @return true if LHBM is ON, false otherwise.
     */
    boolean getLhbmState();

    /**
     * Set NativeHandle then server can fill the compensation
     * image into the native handle
     *
     * @param native_handle share the NativeHandle from client.
     * @param imageName the image name that define in client.
     * @return errno of setCompensationImageHandle
     */
    int setCompensationImageHandle(in NativeHandle native_handle, in String imageName);

    /**
     * Limit minimum idle display refresh rate. This is only relevant for displays
     * that can idle to a lower refresh rate than what is set by the platform. That is,
     * this API only controls kernel driver or panel self-driven refresh rate updates
     * it does not enforce the platform selected refresh rate (via setActiveConfig).
     *
     * @param fps The lowest refresh rate allowed. Setting to -1 means display
     *            should not switch to lower refresh rate while idle.
     * @return errno if there was a problem with the request, zero if successful
     */
    int setMinIdleRefreshRate(in int fps);

    /**
     * Throttle refresh rate switching such that switches don't happen earlier
     * than the provided delay in milliseconds
     *
     * @param delayMs Amount of time in milliseconds to wait before switching to
     *                 a new refresh rate
     * @return errno if there was a problem with the request, zero if successful
     */
    int setRefreshRateThrottle(in int delayMs);
}
