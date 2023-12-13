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

package com.android.bedstead.nene.utils;

import static com.android.compatibility.common.util.VersionCodes.CUR_DEVELOPMENT;
import static com.android.compatibility.common.util.VersionCodes.R;

import android.os.Build;

import com.google.common.collect.ImmutableSet;

import java.lang.reflect.Field;

/** SDK Version checks. */
public final class Versions {

    public static final int T = CUR_DEVELOPMENT;

    /** Any version. */
    public static final int ANY = -1;

    private static final ImmutableSet<String> DEVELOPMENT_CODENAMES = ImmutableSet.of("Sv2", "T");

    private Versions() {

    }

    /**
     * Throw a {@link UnsupportedOperationException} if the minimum version requirement is not met.
     */
    public static void requireMinimumVersion(int min) {
        if (!meetsSdkVersionRequirements(min, ANY)) {
            String currentVersion = meetsMinimumSdkVersionRequirement(R)
                    ? Build.VERSION.RELEASE_OR_CODENAME : Integer.toString(Build.VERSION.SDK_INT);
            throw new UnsupportedOperationException(
                    "This feature is only available on "
                            + versionToLetter(min)
                            + "+ (currently " + currentVersion + ")");
        }
    }

    private static String versionToLetter(int version) {
        for (Field field : Build.VERSION_CODES.class.getFields()) {
            if (!java.lang.reflect.Modifier.isStatic(field.getModifiers())) {
                continue;
            }
            if (!field.getType().equals(int.class)) {
                continue;
            }
            try {
                int fieldValue = (int) field.get(null);

                if (fieldValue == version) {
                    return field.getName();
                }
            } catch (IllegalAccessException e) {
                // Couldn't access this variable - ignore
            }
        }

        return Integer.toString(version);
    }

    /**
     * {@code true} if the minimum version requirement is met.
     */
    public static boolean meetsMinimumSdkVersionRequirement(int min) {
        return meetsSdkVersionRequirements(min, ANY);
    }

    /**
     * {@code true} if the minimum and maximum version requirements are met.
     *
     * <p>Use {@link #ANY} to accept any version.
     */
    public static boolean meetsSdkVersionRequirements(int min, int max) {
        if (min != ANY) {
            if (min == Build.VERSION_CODES.CUR_DEVELOPMENT) {
                if (!DEVELOPMENT_CODENAMES.contains(Build.VERSION.CODENAME)) {
                    return false;
                }
            } else if (min > Build.VERSION.SDK_INT) {
                return false;
            }
        }

        if (max != ANY
                && max != Build.VERSION_CODES.CUR_DEVELOPMENT
                && max < Build.VERSION.SDK_INT) {
            return false;
        }

        return true;
    }

    /**
     * {@code true} if the current running version is the latest in-development version.
     */
    public static boolean isDevelopmentVersion() {
        return Build.VERSION.SDK_INT == Build.VERSION_CODES.CUR_DEVELOPMENT
                && DEVELOPMENT_CODENAMES.contains(Build.VERSION.CODENAME);
    }
}
