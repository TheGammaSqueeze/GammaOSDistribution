/*
 * Copyright (C) 2017-2021 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package org.lineageos.lineageparts.statusbar;

import android.content.ContentResolver;
import android.os.Bundle;
import android.widget.Toast;

import androidx.preference.DropDownPreference;
import androidx.preference.Preference;

import lineageos.preference.LineageSecureSettingSwitchPreference;
import lineageos.providers.LineageSettings;
import org.lineageos.lineageparts.R;
import org.lineageos.lineageparts.SettingsPreferenceFragment;


public class NetworkTrafficSettings extends SettingsPreferenceFragment
        implements Preference.OnPreferenceChangeListener  {

    private static final String TAG = "NetworkTrafficSettings";
    private static final String STATUS_BAR_CLOCK_STYLE = "status_bar_clock";

    private DropDownPreference mNetTrafficMode;
    private LineageSecureSettingSwitchPreference mNetTrafficAutohide;
    private DropDownPreference mNetTrafficUnits;
    private LineageSecureSettingSwitchPreference mNetTrafficShowUnits;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        addPreferencesFromResource(R.xml.network_traffic_settings);
        getActivity().setTitle(R.string.network_traffic_settings_title);

        final ContentResolver resolver = getActivity().getContentResolver();

        mNetTrafficMode = findPreference(LineageSettings.Secure.NETWORK_TRAFFIC_MODE);
        mNetTrafficMode.setOnPreferenceChangeListener(this);
        int mode = LineageSettings.Secure.getInt(resolver,
                LineageSettings.Secure.NETWORK_TRAFFIC_MODE, 0);
        mNetTrafficMode.setValue(String.valueOf(mode));

        mNetTrafficAutohide = findPreference(LineageSettings.Secure.NETWORK_TRAFFIC_AUTOHIDE);
        mNetTrafficAutohide.setOnPreferenceChangeListener(this);

        mNetTrafficUnits = findPreference(LineageSettings.Secure.NETWORK_TRAFFIC_UNITS);
        mNetTrafficUnits.setOnPreferenceChangeListener(this);
        int units = LineageSettings.Secure.getInt(resolver,
                LineageSettings.Secure.NETWORK_TRAFFIC_UNITS, /* Mbps */ 1);
        mNetTrafficUnits.setValue(String.valueOf(units));

        mNetTrafficShowUnits = findPreference(LineageSettings.Secure.NETWORK_TRAFFIC_SHOW_UNITS);
        mNetTrafficShowUnits.setOnPreferenceChangeListener(this);

        updateEnabledStates(mode);
        updateForClockConflicts();
    }

    @Override
    public boolean onPreferenceChange(Preference preference, Object newValue) {
        if (preference == mNetTrafficMode) {
            int mode = Integer.valueOf((String) newValue);
            LineageSettings.Secure.putInt(getActivity().getContentResolver(),
                    LineageSettings.Secure.NETWORK_TRAFFIC_MODE, mode);
            updateEnabledStates(mode);
            updateForClockConflicts();
        } else if (preference == mNetTrafficUnits) {
            int units = Integer.valueOf((String) newValue);
            LineageSettings.Secure.putInt(getActivity().getContentResolver(),
                    LineageSettings.Secure.NETWORK_TRAFFIC_UNITS, units);
        }
        return true;
    }

    private void updateEnabledStates(int mode) {
        final boolean enabled = mode != 0;
        mNetTrafficAutohide.setEnabled(enabled);
        mNetTrafficUnits.setEnabled(enabled);
        mNetTrafficShowUnits.setEnabled(enabled);
    }

    private void updateForClockConflicts() {
        int clockPosition = LineageSettings.System.getInt(getActivity().getContentResolver(),
                STATUS_BAR_CLOCK_STYLE, 2);

        if (clockPosition != 1) {
            return;
        }

        mNetTrafficMode.setEnabled(false);
        Toast.makeText(getActivity(),
                R.string.network_traffic_disabled_clock,
                Toast.LENGTH_LONG).show();
        updateEnabledStates(0);
    }
}
