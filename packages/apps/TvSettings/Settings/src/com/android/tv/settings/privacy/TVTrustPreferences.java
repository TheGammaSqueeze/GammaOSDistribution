/*
 * Copyright (C) 2021-2022 The LineageOS Project
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
package com.android.tv.settings.privacy;

import android.app.AlertDialog;
import android.content.Context;
import android.os.Bundle;
import android.provider.Settings;

import androidx.preference.ListPreference;
import androidx.preference.Preference;
import androidx.preference.PreferenceCategory;
import androidx.preference.SwitchPreference;

import lineageos.preference.LineageGlobalSettingListPreference;
import lineageos.providers.LineageSettings;
import lineageos.trust.TrustInterface;

import com.android.tv.settings.R;
import com.android.tv.settings.SettingsPreferenceFragment;

import org.lineageos.internal.logging.LineageMetricsLogger;

public class TVTrustPreferences extends SettingsPreferenceFragment {
    private static final String TAG = "TVTrustPreferences";

    private Preference mSELinuxPref;
    private Preference mSecurityPatchesPref;
    private Preference mEncryptionPref;
    private PreferenceCategory mToolsCategory;
    private LineageGlobalSettingListPreference mUsbRestrictorPref;

    private PreferenceCategory mWarnScreen;
    private SwitchPreference mWarnSELinuxPref;
    private SwitchPreference mWarnKeysPref;

    private TrustInterface mInterface;

    private int[] mSecurityLevel = new int[4];

    @Override
    public void onCreate(Bundle savedInstance) {
        super.onCreate(savedInstance);

        mInterface = TrustInterface.getInstance(getContext());

        mSELinuxPref = findPreference("trust_selinux");
        mSecurityPatchesPref = findPreference("trust_security_patch");
        mEncryptionPref = findPreference("trust_encryption");
        mToolsCategory = findPreference("trust_category_tools");
        mUsbRestrictorPref = mToolsCategory.findPreference("trust_restrict_usb");

        mWarnScreen = findPreference("trust_category_warnings");
        mWarnSELinuxPref = mWarnScreen.findPreference("trust_warning_selinux");
        mWarnKeysPref = mWarnScreen.findPreference("trust_warning_keys");

        mSELinuxPref.setOnPreferenceClickListener(p ->
                showInfo(R.string.trust_feature_selinux_explain));
        mSecurityPatchesPref.setOnPreferenceClickListener(p ->
                showInfo(R.string.trust_feature_security_patches_explain));
        mEncryptionPref.setOnPreferenceClickListener(p ->
                showInfo(R.string.trust_feature_encryption_explain));

        mWarnSELinuxPref.setOnPreferenceChangeListener((p, v) ->
                onWarningChanged((Boolean) v, TrustInterface.TRUST_WARN_SELINUX));
        mWarnKeysPref.setOnPreferenceChangeListener((p, v) ->
                onWarningChanged((Boolean) v, TrustInterface.TRUST_WARN_PUBLIC_KEY));
        setup();
    }

    @Override
    public void onCreatePreferences(Bundle bundle, String s) {
        setPreferencesFromResource(R.xml.trust_preferences, null);
    }

    private void setup() {
        int seLinuxLevel = mInterface.getLevelForFeature(TrustInterface.TRUST_FEATURE_SELINUX);
        int secPLevel =
                mInterface.getLevelForFeature(TrustInterface.TRUST_FEATURE_PLATFORM_SECURITY_PATCH);
        int secVLevel =
                mInterface.getLevelForFeature(TrustInterface.TRUST_FEATURE_VENDOR_SECURITY_PATCH);
        int encryptLevel = mInterface.getLevelForFeature(TrustInterface.TRUST_FEATURE_ENCRYPTION);

        setupSELinux(seLinuxLevel);
        setupSecurityPatches(secPLevel, secVLevel);
        setupEncryption(encryptLevel);

        int currentFeatures = LineageSettings.Secure.getInt(getContext().getContentResolver(),
                LineageSettings.Secure.TRUST_WARNINGS, TrustInterface.TRUST_WARN_MAX_VALUE);
        mWarnSELinuxPref.setChecked((currentFeatures & TrustInterface.TRUST_WARN_SELINUX) != 0);
        mWarnKeysPref.setChecked((currentFeatures & TrustInterface.TRUST_WARN_PUBLIC_KEY) != 0);

        if (!mInterface.hasUsbRestrictor()) {
            mToolsCategory.removePreference(mUsbRestrictorPref);
        }
    }

    private void setupSELinux(int level) {
        int icon;
        int summary;
        if (level == TrustInterface.TRUST_FEATURE_LEVEL_GOOD) {
            icon = R.drawable.ic_trust_selinux_good;
            summary = R.string.trust_feature_selinux_value_enforcing;
        } else {
            icon = R.drawable.ic_trust_selinux_bad;
            summary = R.string.trust_feature_selinux_value_disabled;
        }
        mSELinuxPref.setIcon(icon);
        mSELinuxPref.setSummary(getContext().getString(summary));
    }

    private void setupSecurityPatches(int platform, int vendor) {
        int icon;

        // TMP: don't enforce vendor check
        if (vendor == TrustInterface.ERROR_UNDEFINED) {
            switch (platform) {
                case TrustInterface.TRUST_FEATURE_LEVEL_GOOD:
                    icon = R.drawable.ic_trust_security_patches_good;
                    break;
                case TrustInterface.TRUST_FEATURE_LEVEL_POOR:
                    icon = R.drawable.ic_trust_security_patches_poor;
                    break;
                default:
                    icon = R.drawable.ic_trust_security_patches_bad;
                    break;
            }
        } else {
            if (platform == TrustInterface.TRUST_FEATURE_LEVEL_GOOD
                    && vendor ==  TrustInterface.TRUST_FEATURE_LEVEL_GOOD) {
                icon = R.drawable.ic_trust_security_patches_good;
            } else if (platform == TrustInterface.TRUST_FEATURE_LEVEL_POOR
                    || (platform == TrustInterface.TRUST_FEATURE_LEVEL_GOOD
                    && vendor != TrustInterface.TRUST_FEATURE_LEVEL_GOOD)) {
                icon = R.drawable.ic_trust_security_patches_poor;
            } else {
                icon = R.drawable.ic_trust_security_patches_bad;
            }
        }

        int summaryP = getSummaryForSecurityPatchLevel(platform);
        int summaryV = getSummaryForSecurityPatchLevel(vendor);
        Context context = getContext();
        // TMP: do not enforce vendor check
        String summary = summaryV == 0
                ? context.getString(summaryP)
                : context.getString(R.string.trust_feature_security_patches_value_base,
                context.getString(summaryP), context.getString(summaryV));

        mSecurityPatchesPref.setIcon(icon);
        mSecurityPatchesPref.setSummary(summary);
    }

    private int getSummaryForSecurityPatchLevel(int level) {
        switch (level) {
            case TrustInterface.TRUST_FEATURE_LEVEL_GOOD:
                return R.string.trust_feature_security_patches_value_new;
            case TrustInterface.TRUST_FEATURE_LEVEL_POOR:
                return R.string.trust_feature_security_patches_value_medium;
            case TrustInterface.TRUST_FEATURE_LEVEL_BAD:
                return R.string.trust_feature_security_patches_value_old;
            default:
                return 0;
        }
    }

    private void setupEncryption(int level) {
        int icon;
        int summary;
        boolean isLegacy = getContext().getResources()
                .getBoolean(org.lineageos.platform.internal.R.bool.config_trustLegacyEncryption);
        if (level == TrustInterface.TRUST_FEATURE_LEVEL_GOOD) {
            icon = R.drawable.ic_trust_encryption_good;
            summary = R.string.trust_feature_encryption_value_enabled;
        } else if (level == TrustInterface.TRUST_FEATURE_LEVEL_POOR) {
            icon = R.drawable.ic_trust_encryption_poor;
            summary = R.string.trust_feature_encryption_value_nolock;
        } else {
            icon = isLegacy
                ? R.drawable.ic_trust_encryption_poor
                : R.drawable.ic_trust_encryption_bad;
            summary = R.string.trust_feature_encryption_value_disabled;
        }
        mEncryptionPref.setIcon(icon);
        mEncryptionPref.setSummary(getContext().getString(summary));
    }

    private boolean showInfo(int text) {
        new AlertDialog.Builder(getContext())
            .setMessage(text)
            .show();
        return true;
    }

    private boolean onWarningChanged(Boolean value, int feature) {
        int original = LineageSettings.Secure.getInt(getContext().getContentResolver(),
                LineageSettings.Secure.TRUST_WARNINGS, TrustInterface.TRUST_WARN_MAX_VALUE);
        int newValue = value ? (original | feature) : (original & ~feature);
        boolean success = LineageSettings.Secure.putInt(getContext().getContentResolver(),
                LineageSettings.Secure.TRUST_WARNINGS,
                newValue & TrustInterface.TRUST_WARN_MAX_VALUE);
        if (success && !value) {
            mInterface.removeNotificationForFeature(feature);
        }
        return success;
    }
}
