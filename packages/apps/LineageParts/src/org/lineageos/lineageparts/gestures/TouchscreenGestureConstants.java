/*
 * Copyright (C) 2016 The CyanogenMod Project
 *               2017-2022 The LineageOS Project
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

package org.lineageos.lineageparts.gestures;

class TouchscreenGestureConstants {
    // Broadcast action for settings update
    static final String UPDATE_PREFS_ACTION = "org.lineageos.lineageparts.gestures.UPDATE_SETTINGS";
    // Broadcast extra: keycode mapping (int[]: key = gesture ID, value = keycode)
    static final String UPDATE_EXTRA_KEYCODE_MAPPING = "keycode_mappings";
    // Broadcast extra: assigned actions (int[]: key = gesture ID, value = action)
    static final String UPDATE_EXTRA_ACTION_MAPPING = "action_mappings";

    // Touchscreen gesture actions
    static final int ACTION_FLASHLIGHT = 1;
    static final int ACTION_CAMERA = 2;
    static final int ACTION_BROWSER = 3;
    static final int ACTION_DIALER = 4;
    static final int ACTION_EMAIL = 5;
    static final int ACTION_MESSAGES = 6;
    static final int ACTION_PLAY_PAUSE_MUSIC = 7;
    static final int ACTION_PREVIOUS_TRACK = 8;
    static final int ACTION_NEXT_TRACK = 9;
    static final int ACTION_VOLUME_DOWN = 10;
    static final int ACTION_VOLUME_UP = 11;
    static final int ACTION_AMBIENT_DISPLAY = 12;
}
