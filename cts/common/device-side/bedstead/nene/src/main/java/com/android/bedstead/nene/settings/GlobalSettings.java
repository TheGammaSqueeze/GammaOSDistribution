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

package com.android.bedstead.nene.settings;

import static android.Manifest.permission.INTERACT_ACROSS_USERS_FULL;
import static android.Manifest.permission.WRITE_SECURE_SETTINGS;

import android.annotation.SuppressLint;
import android.content.ContentResolver;
import android.os.Build;
import android.provider.Settings;

import androidx.annotation.RequiresApi;

import com.android.bedstead.nene.TestApis;
import com.android.bedstead.nene.exceptions.NeneException;
import com.android.bedstead.nene.permissions.PermissionContext;
import com.android.bedstead.nene.users.UserReference;
import com.android.bedstead.nene.utils.Versions;

/** APIs related to {@link Settings.Global}. */
public final class GlobalSettings {

    private static final TestApis sTestApis = new TestApis();
    public static final GlobalSettings sInstance = new GlobalSettings();

    private GlobalSettings() {

    }

    /**
     * See {@link Settings.Global#putInt(ContentResolver, String, int)}
     */
    @RequiresApi(Build.VERSION_CODES.S)
    public void putInt(ContentResolver contentResolver, String key, int value) {
        Versions.requireMinimumVersion(Build.VERSION_CODES.S);
        try (PermissionContext p = sTestApis.permissions().withPermission(
                INTERACT_ACROSS_USERS_FULL, WRITE_SECURE_SETTINGS)) {
            Settings.Global.putInt(contentResolver, key, value);
        }
    }

    /**
     * Put int to global settings for the given {@link UserReference}.
     *
     * <p>If the user is not the instrumented user, this will only succeed when running on Android S
     * and above.
     *
     * <p>See {@link #putInt(ContentResolver, String, int)}
     */
    @SuppressLint("NewApi")
    public void putInt(UserReference user, String key, int value) {
        if (user.equals(sTestApis.users().instrumented())) {
            putInt(key, value);
            return;
        }

        putInt(sTestApis.context().androidContextAsUser(user).getContentResolver(), key, value);
    }

    /**
     * Put int to global settings for the instrumented user.
     *
     * <p>See {@link #putInt(ContentResolver, String, int)}
     */
    public void putInt(String key, int value) {
        try (PermissionContext p = sTestApis.permissions().withPermission(WRITE_SECURE_SETTINGS)) {
            Settings.Global.putInt(
                    sTestApis.context().instrumentedContext().getContentResolver(), key, value);
        }
    }

    /**
     * See {@link Settings.Global#putString(ContentResolver, String, String)}
     */
    @RequiresApi(Build.VERSION_CODES.S)
    public void putString(ContentResolver contentResolver, String key, String value) {
        Versions.requireMinimumVersion(Build.VERSION_CODES.S);
        try (PermissionContext p = sTestApis.permissions().withPermission(
                INTERACT_ACROSS_USERS_FULL, WRITE_SECURE_SETTINGS)) {
            Settings.Global.putString(contentResolver, key, value);
        }
    }

    /**
     * Put string to global settings for the given {@link UserReference}.
     *
     * <p>If the user is not the instrumented user, this will only succeed when running on Android S
     * and above.
     *
     * <p>See {@link #putString(ContentResolver, String, String)}
     */
    @SuppressLint("NewApi")
    public void putString(UserReference user, String key, String value) {
        if (user.equals(sTestApis.users().instrumented())) {
            putString(key, value);
            return;
        }

        putString(sTestApis.context().androidContextAsUser(user).getContentResolver(), key, value);
    }

    /**
     * Put string to global settings for the instrumented user.
     *
     * <p>See {@link #putString(ContentResolver, String, String)}
     */
    public void putString(String key, String value) {
        try (PermissionContext p = sTestApis.permissions().withPermission(WRITE_SECURE_SETTINGS)) {
            Settings.Global.putString(
                    sTestApis.context().instrumentedContext().getContentResolver(), key, value);
        }
    }

    /**
     * See {@link Settings.Global#getInt(ContentResolver, String)}
     */
    @RequiresApi(Build.VERSION_CODES.S)
    public int getInt(ContentResolver contentResolver, String key) {
        Versions.requireMinimumVersion(Build.VERSION_CODES.S);
        try (PermissionContext p =
                     sTestApis.permissions().withPermission(INTERACT_ACROSS_USERS_FULL)) {
            return getIntInner(contentResolver, key);
        }
    }

    /**
     * See {@link Settings.Global#getInt(ContentResolver, String, int)}
     */
    @RequiresApi(Build.VERSION_CODES.S)
    public int getInt(ContentResolver contentResolver, String key, int defaultValue) {
        Versions.requireMinimumVersion(Build.VERSION_CODES.S);
        try (PermissionContext p =
                     sTestApis.permissions().withPermission(INTERACT_ACROSS_USERS_FULL)) {
            return getIntInner(contentResolver, key, defaultValue);
        }
    }

    private int getIntInner(ContentResolver contentResolver, String key) {
        try {
            return Settings.Global.getInt(contentResolver, key);
        } catch (Settings.SettingNotFoundException e) {
            throw new NeneException("Error getting int setting", e);
        }
    }

    private int getIntInner(ContentResolver contentResolver, String key, int defaultValue) {
        return Settings.Global.getInt(contentResolver, key, defaultValue);
    }

    /**
     * Get int from global settings for the given {@link UserReference}.
     *
     * <p>If the user is not the instrumented user, this will only succeed when running on Android S
     * and above.
     *
     * <p>See {@link #getInt(ContentResolver, String)}
     */
    @SuppressLint("NewApi")
    public int getInt(UserReference user, String key) {
        if (user.equals(sTestApis.users().instrumented())) {
            return getInt(key);
        }
        return getInt(sTestApis.context().androidContextAsUser(user).getContentResolver(), key);
    }

    /**
     * Get int from global settings for the given {@link UserReference}, or the default value.
     *
     * <p>If the user is not the instrumented user, this will only succeed when running on Android S
     * and above.
     *
     * <p>See {@link #getInt(ContentResolver, String, int)}
     */
    @SuppressLint("NewApi")
    public int getInt(UserReference user, String key, int defaultValue) {
        if (user.equals(sTestApis.users().instrumented())) {
            return getInt(key, defaultValue);
        }
        return getInt(
                sTestApis.context().androidContextAsUser(user).getContentResolver(),
                key, defaultValue);
    }

    /**
     * Get int from global settings for the instrumented user.
     *
     * <p>See {@link #getInt(ContentResolver, String)}
     */
    public int getInt(String key) {
        return getIntInner(sTestApis.context().instrumentedContext().getContentResolver(), key);
    }

    /**
     * Get int from global settings for the instrumented user, or the default value.
     *
     * <p>See {@link #getInt(ContentResolver, String)}
     */
    public int getInt(String key, int defaultValue) {
        return getIntInner(
                sTestApis.context().instrumentedContext().getContentResolver(), key, defaultValue);
    }

    /**
     * See {@link Settings.Global#getString(ContentResolver, String)}
     */
    @RequiresApi(Build.VERSION_CODES.S)
    public String getString(ContentResolver contentResolver, String key) {
        Versions.requireMinimumVersion(Build.VERSION_CODES.S);
        try (PermissionContext p =
                     sTestApis.permissions().withPermission(INTERACT_ACROSS_USERS_FULL)) {
            return getStringInner(contentResolver, key);
        }
    }

    private String getStringInner(ContentResolver contentResolver, String key) {
        return Settings.Global.getString(contentResolver, key);
    }

    /**
     * Get string from global settings for the given {@link UserReference}.
     *
     * <p>If the user is not the instrumented user, this will only succeed when running on Android S
     * and above.
     *
     * <p>See {@link #getString(ContentResolver, String)}
     */
    @SuppressLint("NewApi")
    public String getString(UserReference user, String key) {
        if (user.equals(sTestApis.users().instrumented())) {
            return getString(key);
        }
        return getString(sTestApis.context().androidContextAsUser(user).getContentResolver(), key);
    }

    /**
     * Get string from global settings for the instrumented user.
     *
     * <p>See {@link #getString(ContentResolver, String)}
     */
    public String getString(String key) {
        return getStringInner(sTestApis.context().instrumentedContext().getContentResolver(), key);
    }

    /**
     * Reset all global settings set by this package.
     *
     * See {@link Settings.Global#resetToDefaults(ContentResolver, String)}.
     *
     * <p>The {@code tag} argument is always set to null.
     */
    @RequiresApi(Build.VERSION_CODES.S)
    public void reset(ContentResolver contentResolver) {
        Versions.requireMinimumVersion(Build.VERSION_CODES.S);
        try (PermissionContext p = sTestApis.permissions().withPermission(
                WRITE_SECURE_SETTINGS, INTERACT_ACROSS_USERS_FULL)) {
            Settings.Global.resetToDefaults(contentResolver, /* tag= */ null);
        }
    }

    /**
     * Reset all global settings set by this package for the given user.
     *
     * <p>If the user is not the instrumented user, this will only succeed when running on Android S
     * and above.
     *
     * See {@link #reset(ContentResolver)}.
     */
    @SuppressLint("NewApi")
    public void reset(UserReference user) {
        if (user.equals(sTestApis.users().instrumented())) {
            reset();
            return;
        }
        reset(sTestApis.context().androidContextAsUser(user).getContentResolver());
    }

    /**
     * Reset all global settings set by this package for the instrumented user.
     *
     * See {@link #reset(ContentResolver)}.
     */
    public void reset() {
        try (PermissionContext p = sTestApis.permissions().withPermission(WRITE_SECURE_SETTINGS)) {
            Settings.Global.resetToDefaults(
                    sTestApis.context().instrumentedContext().getContentResolver(),
                    /* tag= */null);
        }
    }
}
