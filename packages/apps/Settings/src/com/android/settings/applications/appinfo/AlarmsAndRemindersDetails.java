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
package com.android.settings.applications.appinfo;

import static android.app.Activity.RESULT_CANCELED;
import static android.app.Activity.RESULT_OK;

import android.app.AppOpsManager;
import android.app.settings.SettingsEnums;
import android.content.Context;
import android.os.Bundle;

import androidx.appcompat.app.AlertDialog;
import androidx.preference.Preference;
import androidx.preference.Preference.OnPreferenceChangeListener;

import com.android.settings.R;
import com.android.settings.Settings;
import com.android.settings.applications.AppInfoWithHeader;
import com.android.settings.applications.AppStateAlarmsAndRemindersBridge;
import com.android.settingslib.RestrictedSwitchPreference;
import com.android.settingslib.applications.ApplicationsState.AppEntry;

/**
 * App specific activity to show details about
 * {@link android.Manifest.permission#SCHEDULE_EXACT_ALARM}.
 */
public class AlarmsAndRemindersDetails extends AppInfoWithHeader
        implements OnPreferenceChangeListener {

    private static final String KEY_SWITCH = "alarms_and_reminders_switch";
    private static final String UNCOMMITTED_STATE_KEY = "uncommitted_state";

    private AppStateAlarmsAndRemindersBridge mAppBridge;
    private AppOpsManager mAppOpsManager;
    private RestrictedSwitchPreference mSwitchPref;
    private AppStateAlarmsAndRemindersBridge.AlarmsAndRemindersState mPermissionState;
    private volatile Boolean mUncommittedState;

    /**
     * Returns the string that states whether the app has access to
     * {@link android.Manifest.permission#SCHEDULE_EXACT_ALARM}.
     */
    public static CharSequence getSummary(Context context, AppEntry entry) {
        final AppStateAlarmsAndRemindersBridge.AlarmsAndRemindersState state =
                new AppStateAlarmsAndRemindersBridge(context, /*appState=*/null,
                        /*callback=*/null).createPermissionState(entry.info.packageName,
                        entry.info.uid);

        return context.getString(state.isAllowed() ? R.string.app_permission_summary_allowed
                : R.string.app_permission_summary_not_allowed);
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        final Context context = getActivity();
        mAppBridge = new AppStateAlarmsAndRemindersBridge(context, mState, /*callback=*/null);
        mAppOpsManager = context.getSystemService(AppOpsManager.class);

        if (savedInstanceState != null) {
            mUncommittedState = (Boolean) savedInstanceState.get(UNCOMMITTED_STATE_KEY);
            if (mUncommittedState != null && isAppSpecific()) {
                setResult(mUncommittedState ? RESULT_OK : RESULT_CANCELED);
            }
        }
        addPreferencesFromResource(R.xml.alarms_and_reminders);
        mSwitchPref = findPreference(KEY_SWITCH);
        mSwitchPref.setOnPreferenceChangeListener(this);
    }

    @Override
    public void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
        if (mUncommittedState != null) {
            outState.putObject(UNCOMMITTED_STATE_KEY, mUncommittedState);
        }
    }

    @Override
    public boolean onPreferenceChange(Preference preference, Object newValue) {
        if (preference == mSwitchPref) {
            mUncommittedState = (Boolean) newValue;
            if (isAppSpecific()) {
                setResult(mUncommittedState ? RESULT_OK : RESULT_CANCELED);
            }
            refreshUi();
            return true;
        }
        return false;
    }

    private void setCanScheduleAlarms(boolean newState) {
        final int uid = mPackageInfo.applicationInfo.uid;
        mAppOpsManager.setUidMode(AppOpsManager.OPSTR_SCHEDULE_EXACT_ALARM, uid,
                newState ? AppOpsManager.MODE_ALLOWED : AppOpsManager.MODE_ERRORED);
    }

    private void logPermissionChange(boolean newState, String packageName) {
        mMetricsFeatureProvider.action(
                mMetricsFeatureProvider.getAttribution(getActivity()),
                SettingsEnums.ACTION_ALARMS_AND_REMINDERS_TOGGLE,
                getMetricsCategory(),
                packageName,
                newState ? 1 : 0);
    }

    private boolean isAppSpecific() {
        return Settings.AlarmsAndRemindersAppActivity.class.getName().equals(
                getIntent().getComponent().getClassName());
    }

    @Override
    public void onPause() {
        super.onPause();
        if (getActivity().isChangingConfigurations()) {
            return;
        }
        if (mPermissionState != null && mUncommittedState != null
                && mUncommittedState != mPermissionState.isAllowed()) {
            setCanScheduleAlarms(mUncommittedState);
            logPermissionChange(mUncommittedState, mPackageName);
            mUncommittedState = null;
        }
    }

    @Override
    protected boolean refreshUi() {
        if (mPackageInfo == null || mPackageInfo.applicationInfo == null) {
            return false;
        }
        mPermissionState = mAppBridge.createPermissionState(mPackageName,
                mPackageInfo.applicationInfo.uid);
        mSwitchPref.setEnabled(mPermissionState.shouldBeVisible());
        mSwitchPref.setChecked(
                mUncommittedState != null ? mUncommittedState : mPermissionState.isAllowed());
        return true;
    }

    @Override
    protected AlertDialog createDialog(int id, int errorCode) {
        return null;
    }

    @Override
    public int getMetricsCategory() {
        return SettingsEnums.ALARMS_AND_REMINDERS;
    }
}
