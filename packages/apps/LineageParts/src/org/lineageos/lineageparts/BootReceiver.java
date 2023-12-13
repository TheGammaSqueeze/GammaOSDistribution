/*
 * Copyright (C) 2012 The CyanogenMod Project
 *               2017-2019,2021,2023 The LineageOS project
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

package org.lineageos.lineageparts;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.UserManager;
import android.util.Log;

import androidx.preference.PreferenceManager;

import org.lineageos.lineageparts.contributors.ContributorsCloudFragment;
import org.lineageos.lineageparts.gestures.TouchscreenGestureSettings;
import org.lineageos.lineageparts.input.ButtonSettings;

public class BootReceiver extends BroadcastReceiver {

    private static final String TAG = "PartsBootReceiver";
    private static final String ONE_TIME_TUNABLE_RESTORE = "hardware_tunable_restored";

    @Override
    public void onReceive(Context ctx, Intent intent) {
        if (!ctx.getSystemService(UserManager.class).isPrimaryUser()) {
            Log.d(TAG, "Not running as the primary user, skipping tunable restoration.");
            return;
        }

        if (!hasRestoredTunable(ctx)) {
            /* Restore the hardware tunable values */
            ButtonSettings.restoreKeyDisabler(ctx);
            setRestoredTunable(ctx);
        }

        ButtonSettings.restoreKeySwapper(ctx);
        TouchscreenGestureSettings.restoreTouchscreenGestureStates(ctx);

        // Extract the contributors database
        ContributorsCloudFragment.extractContributorsCloudDatabase(ctx);
    }

    private boolean hasRestoredTunable(Context context) {
        SharedPreferences preferences = PreferenceManager.getDefaultSharedPreferences(context);
        return preferences.getBoolean(ONE_TIME_TUNABLE_RESTORE, false);
    }

    private void setRestoredTunable(Context context) {
        SharedPreferences preferences = PreferenceManager.getDefaultSharedPreferences(context);
        preferences.edit().putBoolean(ONE_TIME_TUNABLE_RESTORE, true).apply();
    }
}
