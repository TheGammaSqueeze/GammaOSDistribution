/*
 * Copyright (C) 2018 The Android Open Source Project
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

package com.android.car.settings.datetime;

import android.car.drivingstate.CarUxRestrictions;
import android.content.Context;
import android.content.Intent;
import android.provider.Settings;

import androidx.preference.SwitchPreference;

import com.android.car.settings.common.FragmentController;
import com.android.car.settings.common.PreferenceController;

/**
 * Business logic which controls the auto datetime toggle.
 */
public class AutoDatetimeTogglePreferenceController extends
        PreferenceController<SwitchPreference> {

    public AutoDatetimeTogglePreferenceController(Context context, String preferenceKey,
            FragmentController fragmentController, CarUxRestrictions uxRestrictions) {
        super(context, preferenceKey, fragmentController, uxRestrictions);
    }

    @Override
    protected Class<SwitchPreference> getPreferenceType() {
        return SwitchPreference.class;
    }

    @Override
    protected void onCreateInternal() {
        super.onCreateInternal();
        setClickableWhileDisabled(getPreference(), /* clickable= */ true, p ->
                DatetimeUtils.runClickableWhileDisabled(getContext(), getFragmentController()));
    }

    @Override
    protected void updateState(SwitchPreference preference) {
        preference.setChecked(isEnabled());
    }

    @Override
    protected boolean handlePreferenceChanged(SwitchPreference preference, Object newValue) {
        boolean isAutoDatetimeEnabled = (boolean) newValue;
        Settings.Global.putInt(getContext().getContentResolver(), Settings.Global.AUTO_TIME,
                isAutoDatetimeEnabled ? 1 : 0);

        getContext().sendBroadcast(new Intent(Intent.ACTION_TIME_CHANGED));
        return true;
    }

    @Override
    public int getAvailabilityStatus() {
        return DatetimeUtils.getAvailabilityStatus(getContext());
    }

    private boolean isEnabled() {
        return Settings.Global.getInt(getContext().getContentResolver(),
                Settings.Global.AUTO_TIME, 0) > 0;
    }
}
