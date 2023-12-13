package com.android.searchlauncher;

import static com.android.searchlauncher.OverlayCallbackImpl.KEY_ENABLE_MINUS_ONE;

import android.content.Context;
import android.content.pm.PackageManager;

import androidx.preference.Preference;

import com.android.launcher3.settings.SettingsActivity.LauncherSettingsFragment;

public class SearchSettingsFragment extends LauncherSettingsFragment {

    protected static final String GSA_PACKAGE = "com.google.android.googlequicksearchbox";

    private Preference mShowGoogleAppPref;

    @Override
    protected boolean initPreference(Preference preference) {
        switch (preference.getKey()) {
            case KEY_ENABLE_MINUS_ONE:
                mShowGoogleAppPref = preference;
                updateIsGoogleAppEnabled();
                return true;

            case "pref_smartspace":
                return false;
        }

        return super.initPreference(preference);
    }

    private void updateIsGoogleAppEnabled() {
        if (mShowGoogleAppPref != null) {
            mShowGoogleAppPref.setEnabled(isGSAEnabled(getContext()));
        }
    }

    @Override
    public void onResume() {
        super.onResume();
        updateIsGoogleAppEnabled();
    }

    public static boolean isGSAEnabled(Context context) {
        try {
            return context.getPackageManager().getApplicationInfo(GSA_PACKAGE, 0).enabled;
        } catch (PackageManager.NameNotFoundException e) {
            return false;
        }
    }
}
