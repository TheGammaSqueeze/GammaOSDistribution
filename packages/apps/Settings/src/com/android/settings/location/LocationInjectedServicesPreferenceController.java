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
package com.android.settings.location;

import android.content.Context;
import android.os.UserHandle;

import androidx.preference.Preference;
import androidx.preference.PreferenceCategory;
import androidx.preference.PreferenceScreen;

import com.android.settings.widget.RestrictedAppPreference;

import java.util.List;
import java.util.Map;

/**
 * Preference controller for the injected Location Services.
 */
public class LocationInjectedServicesPreferenceController
        extends LocationInjectedServiceBasePreferenceController {

    private static final String TAG = "LocationPrefCtrl";

    public LocationInjectedServicesPreferenceController(Context context, String key) {
        super(context, key);
    }

    @Override
    protected void injectLocationServices(PreferenceScreen screen) {
        final PreferenceCategory categoryLocationServices =
                screen.findPreference(getPreferenceKey());
        final Map<Integer, List<Preference>> prefs = getLocationServices();
        for (Map.Entry<Integer, List<Preference>> entry : prefs.entrySet()) {
            for (Preference pref : entry.getValue()) {
                if (pref instanceof RestrictedAppPreference) {
                    ((RestrictedAppPreference) pref).checkRestrictionAndSetDisabled();
                }
            }
            if (entry.getKey() == UserHandle.myUserId()) {
                if (categoryLocationServices != null) {
                    LocationSettings.addPreferencesSorted(entry.getValue(),
                            categoryLocationServices);
                }
            }
        }
    }
}
