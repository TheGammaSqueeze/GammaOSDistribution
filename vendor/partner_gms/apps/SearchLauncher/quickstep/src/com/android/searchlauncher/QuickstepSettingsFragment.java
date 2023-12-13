package com.android.searchlauncher;

import androidx.preference.Preference;

public class QuickstepSettingsFragment extends SearchSettingsFragment {

    @Override
    protected boolean initPreference(Preference preference) {
        switch (preference.getKey()) {
            case "pref_smartspace":
                if (SmartSpaceHostView.hasSettings(getActivity())) {
                    preference.setIntent(SmartSpaceHostView.createSettingsIntent());
                    return true;
                }
                return false;
        }

        return super.initPreference(preference);
    }
}
