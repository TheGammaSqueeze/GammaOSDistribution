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

package com.android.car.carlauncher;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.content.res.Resources;
import android.util.Log;

import java.net.URISyntaxException;

/**
 * Utils for CarLauncher package.
 */
public class CarLauncherUtils {

    private static final String TAG = "CarLauncherUtils";

    private CarLauncherUtils() {
    }

    /** Intent used to find/launch the maps activity to run in the relevant DisplayArea. */
    public static Intent getMapsIntent(Context context) {
        Intent defaultIntent =
                Intent.makeMainSelectorActivity(Intent.ACTION_MAIN, Intent.CATEGORY_APP_MAPS);
        defaultIntent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        PackageManager pm = context.getPackageManager();
        ComponentName defaultActivity = defaultIntent.resolveActivity(pm);
        defaultIntent.setComponent(defaultActivity);

        for (String intentUri : context.getResources().getStringArray(
                R.array.config_homeCardPreferredMapActivities)) {
            Intent preferredIntent;
            try {
                preferredIntent = Intent.parseUri(intentUri, Intent.URI_ANDROID_APP_SCHEME);
            } catch (URISyntaxException se) {
                Log.w(TAG, "Invalid intent URI in config_homeCardPreferredMapActivities", se);
                continue;
            }

            if (defaultActivity != null && !defaultActivity.getPackageName().equals(
                    preferredIntent.getPackage())) {
                continue;
            }

            if (preferredIntent.resolveActivityInfo(pm, /* flags= */ 0) != null) {
                return preferredIntent;
            }
        }
        return defaultIntent;
    }

    /**
     * Returns {@code true} if a proper limited map intent is configured via
     * {@code config_smallCanvasOptimizedMapIntent} string resource.
     */
    public static boolean isSmallCanvasOptimizedMapIntentConfigured(Context context) {
        String intentString = context.getString(R.string.config_smallCanvasOptimizedMapIntent);
        if (intentString.isEmpty()) {
            return false;
        }

        try {
            Intent.parseUri(intentString, Intent.URI_INTENT_SCHEME);
            return true;
        } catch (URISyntaxException e) {
            return false;
        }
    }

    /**
     * Returns an intent to trigger a map with a limited functionality (e.g., one to be used when
     * there's not much screen real estate).
     */
    public static Intent getSmallCanvasOptimizedMapIntent(Context context) {
        String intentString = context.getString(R.string.config_smallCanvasOptimizedMapIntent);
        try {
            Intent intent = Intent.parseUri(intentString, Intent.URI_INTENT_SCHEME);
            intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
            return intent;
        } catch (URISyntaxException e) {
            Log.w(TAG, "Invalid intent URI in config_smallCanvasOptimizedMapIntent: \""
                    + intentString + "\". Falling back to fullscreen map.");
            return getMapsIntent(context);
        }
    }

    static boolean isCustomDisplayPolicyDefined(Context context) {
        Resources resources = context.getResources();
        String customPolicyName = null;
        try {
            customPolicyName = resources
                    .getString(
                            com.android.internal
                                    .R.string.config_deviceSpecificDisplayAreaPolicyProvider);
        } catch (Resources.NotFoundException ex) {
            Log.w(TAG, "custom policy provider not defined");
        }
        return customPolicyName != null && !customPolicyName.isEmpty();
    }
}
