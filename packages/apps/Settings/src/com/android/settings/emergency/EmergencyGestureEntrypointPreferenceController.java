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

package com.android.settings.emergency;

import android.content.Context;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.text.TextUtils;
import android.util.Log;

import androidx.annotation.VisibleForTesting;
import androidx.preference.Preference;

import com.android.settings.R;
import com.android.settings.core.BasePreferenceController;

/**
 * Preference controller for emergency gesture setting's entyrpoint preference
 */
public class EmergencyGestureEntrypointPreferenceController extends BasePreferenceController {
    private static final String TAG = "EmergencyGestureEntry";

    @VisibleForTesting
    static final String ACTION_EMERGENCY_GESTURE_SETTINGS =
            "com.android.settings.action.emergency_gesture_settings";
    @VisibleForTesting
    Intent mIntent;

    private boolean mUseCustomIntent;

    public EmergencyGestureEntrypointPreferenceController(Context context, String key) {
        super(context, key);
        final String emergencyGestureSettingsPackageName = context.getResources().getString(
                R.string.emergency_gesture_settings_package);
        if (!TextUtils.isEmpty(emergencyGestureSettingsPackageName)) {
            final Intent intent = new Intent(ACTION_EMERGENCY_GESTURE_SETTINGS)
                    .setPackage(emergencyGestureSettingsPackageName);
            if (canResolveIntent(intent)) {
                // Use custom intent if it's configured and system can resolve it.
                mUseCustomIntent = true;
                mIntent = intent;
            }
        }
    }

    @Override
    public void updateState(Preference preference) {
        super.updateState(preference);
        final boolean canHandleClicks = canHandleClicks();
        if (preference != null) {
            preference.setEnabled(canHandleClicks);
        }
    }

    @Override
    public boolean handlePreferenceTreeClick(Preference preference) {
        if (TextUtils.equals(getPreferenceKey(), preference.getKey()) && mIntent != null) {
            mIntent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
            mContext.startActivity(mIntent);
            return true;
        }
        return super.handlePreferenceTreeClick(preference);
    }

    @Override
    public int getAvailabilityStatus() {
        final boolean isConfigEnabled = mContext.getResources()
                .getBoolean(R.bool.config_show_emergency_gesture_settings);

        if (!isConfigEnabled) {
            return UNSUPPORTED_ON_DEVICE;
        }
        if (!canHandleClicks()) {
            return UNSUPPORTED_ON_DEVICE;
        }
        return AVAILABLE;
    }

    @Override
    public CharSequence getSummary() {
        if (mUseCustomIntent) {
            final String packageName = mContext.getResources().getString(
                    R.string.emergency_gesture_settings_package);
            try {
                final PackageManager pm = mContext.getPackageManager();
                final ApplicationInfo appInfo = pm.getApplicationInfo(
                        packageName, PackageManager.MATCH_DISABLED_COMPONENTS
                                | PackageManager.MATCH_DISABLED_UNTIL_USED_COMPONENTS);
                return mContext.getString(R.string.emergency_gesture_entrypoint_summary,
                        appInfo.loadLabel(pm));
            } catch (Exception e) {
                Log.d(TAG, "Failed to get custom summary, falling back.");
                return super.getSummary();
            }
        }

        return super.getSummary();
    }

    /**
     * Whether or not gesture page content should be suppressed from search.
     */
    public boolean shouldSuppressFromSearch() {
        return mUseCustomIntent;
    }

    /**
     * Whether or not this setting can react to user click
     */
    private boolean canHandleClicks() {
        return !mUseCustomIntent || mIntent != null;
    }

    private boolean canResolveIntent(Intent intent) {
        final ResolveInfo resolveActivity = mContext.getPackageManager()
                .resolveActivity(intent, 0);
        return resolveActivity != null;
    }
}
