/*
 * Copyright (C) 2015 The Android Open Source Project
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
package com.android.settings.wifi;

import static android.content.Context.WIFI_SERVICE;

import android.app.settings.SettingsEnums;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.net.wifi.WifiManager;
import android.os.Bundle;
import android.util.FeatureFlagUtils;
import android.util.Log;

import androidx.preference.Preference;
import androidx.preference.PreferenceScreen;

import com.android.settings.R;
import com.android.settings.dashboard.DashboardFragment;
import com.android.settings.search.BaseSearchIndexProvider;
import com.android.settings.wifi.p2p.WifiP2pPreferenceController;
import com.android.settingslib.core.AbstractPreferenceController;
import com.android.settingslib.search.SearchIndexable;

import java.util.ArrayList;
import java.util.List;

@SearchIndexable
public class ConfigureWifiSettings extends DashboardFragment {

    private static final String TAG = "ConfigureWifiSettings";
    private static final String KEY_INSTALL_CREDENTIALS = "install_credentials";
    private static final String ACTION_INSTALL_CERTS = "android.credentials.INSTALL";
    private static final String PACKAGE_INSTALL_CERTS = "com.android.certinstaller";
    private static final String CLASS_INSTALL_CERTS = "com.android.certinstaller.CertInstallerMain";
    private static final String KEY_INSTALL_CERTIFICATE = "certificate_install_usage";
    private static final String INSTALL_CERTIFICATE_VALUE = "wifi";

    public static final int WIFI_WAKEUP_REQUEST_CODE = 600;

    private WifiWakeupPreferenceController mWifiWakeupPreferenceController;
    private Preference mCertinstallerPreference;

    @Override
    public void onCreate(Bundle icicle) {
        super.onCreate(icicle);
        getActivity().setTitle(R.string.network_and_internet_preferences_title);

        mCertinstallerPreference = findPreference(KEY_INSTALL_CREDENTIALS);
        if (mCertinstallerPreference != null) {
            mCertinstallerPreference.setOnPreferenceClickListener(preference -> {
                Intent intent = new Intent(ACTION_INSTALL_CERTS);
                intent.setFlags(
                        Intent.FLAG_ACTIVITY_NEW_TASK);
                intent.setComponent(
                        new ComponentName(PACKAGE_INSTALL_CERTS, CLASS_INSTALL_CERTS));
                intent.putExtra(KEY_INSTALL_CERTIFICATE, INSTALL_CERTIFICATE_VALUE);
                getContext().startActivity(intent);
                return true;
            });
        } else {
            Log.d(TAG, "Can not find the preference.");
        }
    }

    @Override
    public int getMetricsCategory() {
        return SettingsEnums.CONFIGURE_WIFI;
    }

    @Override
    protected String getLogTag() {
        return TAG;
    }

    @Override
    protected int getPreferenceScreenResId() {
        return R.xml.wifi_configure_settings;
    }

    @Override
    protected List<AbstractPreferenceController> createPreferenceControllers(Context context) {
        final WifiManager wifiManager = (WifiManager) getSystemService(WIFI_SERVICE);
        final List<AbstractPreferenceController> controllers = new ArrayList<>();
        controllers.add(new WifiP2pPreferenceController(context, getSettingsLifecycle(),
                wifiManager));
        return controllers;
    }

    @Override
    public void onAttach(Context context) {
        super.onAttach(context);


        mWifiWakeupPreferenceController = use(WifiWakeupPreferenceController.class);
        mWifiWakeupPreferenceController.setFragment(this);
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (requestCode == WIFI_WAKEUP_REQUEST_CODE) {
            mWifiWakeupPreferenceController.onActivityResult(requestCode, resultCode);
            return;
        }
        super.onActivityResult(requestCode, resultCode, data);
    }

    public static final BaseSearchIndexProvider SEARCH_INDEX_DATA_PROVIDER =
            new BaseSearchIndexProvider(R.xml.wifi_configure_settings) {
                protected boolean isPageSearchEnabled(Context context) {
                    return context.getResources()
                            .getBoolean(R.bool.config_show_wifi_settings);
                }
            };
}
