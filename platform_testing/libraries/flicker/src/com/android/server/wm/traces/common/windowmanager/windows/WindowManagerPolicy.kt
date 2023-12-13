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

package com.android.server.wm.traces.common.windowmanager.windows

/**
 * Represents the requested policy of a WM container
 *
 * This is a generic object that is reused by both Flicker and Winscope and cannot
 * access internal Java/Android functionality
 *
 */
data class WindowManagerPolicy(
    val focusedAppToken: String,
    val forceStatusBar: Boolean,
    val forceStatusBarFromKeyguard: Boolean,
    val keyguardDrawComplete: Boolean,
    val keyguardOccluded: Boolean,
    val keyguardOccludedChanged: Boolean,
    val keyguardOccludedPending: Boolean,
    val lastSystemUiFlags: Int,
    val orientation: Int,
    val rotation: Int,
    val rotationMode: Int,
    val screenOnFully: Boolean,
    val windowManagerDrawComplete: Boolean
) {
    val isOrientationNoSensor: Boolean
        get() = orientation == SCREEN_ORIENTATION_NOSENSOR

    val isFixedOrientation: Boolean
        get() = isFixedOrientationLandscape ||
            isFixedOrientationPortrait ||
            orientation == SCREEN_ORIENTATION_LOCKED

    private val isFixedOrientationLandscape
        get() = orientation == SCREEN_ORIENTATION_LANDSCAPE ||
            orientation == SCREEN_ORIENTATION_SENSOR_LANDSCAPE ||
            orientation == SCREEN_ORIENTATION_REVERSE_LANDSCAPE ||
            orientation == SCREEN_ORIENTATION_USER_LANDSCAPE

    private val isFixedOrientationPortrait
        get() = orientation == SCREEN_ORIENTATION_PORTRAIT ||
            orientation == SCREEN_ORIENTATION_SENSOR_PORTRAIT ||
            orientation == SCREEN_ORIENTATION_REVERSE_PORTRAIT ||
            orientation == SCREEN_ORIENTATION_USER_PORTRAIT

    companion object {
        /**
         * From [android.content.pm.ActivityInfo]
         */
        private const val SCREEN_ORIENTATION_LANDSCAPE = 0
        private const val SCREEN_ORIENTATION_PORTRAIT = 1
        private const val SCREEN_ORIENTATION_NOSENSOR = 5
        private const val SCREEN_ORIENTATION_SENSOR_LANDSCAPE = 6
        private const val SCREEN_ORIENTATION_SENSOR_PORTRAIT = 7
        private const val SCREEN_ORIENTATION_REVERSE_LANDSCAPE = 8
        private const val SCREEN_ORIENTATION_REVERSE_PORTRAIT = 9
        private const val SCREEN_ORIENTATION_USER_LANDSCAPE = 11
        private const val SCREEN_ORIENTATION_USER_PORTRAIT = 12
        private const val SCREEN_ORIENTATION_LOCKED = 14
    }

    override fun equals(other: Any?): Boolean {
        if (this === other) return true
        if (other !is WindowManagerPolicy) return false

        if (focusedAppToken != other.focusedAppToken) return false
        if (forceStatusBar != other.forceStatusBar) return false
        if (forceStatusBarFromKeyguard != other.forceStatusBarFromKeyguard) return false
        if (keyguardDrawComplete != other.keyguardDrawComplete) return false
        if (keyguardOccluded != other.keyguardOccluded) return false
        if (keyguardOccludedChanged != other.keyguardOccludedChanged) return false
        if (keyguardOccludedPending != other.keyguardOccludedPending) return false
        if (lastSystemUiFlags != other.lastSystemUiFlags) return false
        if (orientation != other.orientation) return false
        if (rotation != other.rotation) return false
        if (rotationMode != other.rotationMode) return false
        if (screenOnFully != other.screenOnFully) return false
        if (windowManagerDrawComplete != other.windowManagerDrawComplete) return false

        return true
    }

    override fun hashCode(): Int {
        var result = focusedAppToken.hashCode()
        result = 31 * result + forceStatusBar.hashCode()
        result = 31 * result + forceStatusBarFromKeyguard.hashCode()
        result = 31 * result + keyguardDrawComplete.hashCode()
        result = 31 * result + keyguardOccluded.hashCode()
        result = 31 * result + keyguardOccludedChanged.hashCode()
        result = 31 * result + keyguardOccludedPending.hashCode()
        result = 31 * result + lastSystemUiFlags
        result = 31 * result + orientation
        result = 31 * result + rotation
        result = 31 * result + rotationMode
        result = 31 * result + screenOnFully.hashCode()
        result = 31 * result + windowManagerDrawComplete.hashCode()
        return result
    }
}
