/*
 * Copyright (C) 2008 The Android Open Source Project
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

package android.net.wifi.cts;

import static android.net.wifi.WifiConfiguration.SECURITY_TYPE_EAP;
import static android.net.wifi.WifiConfiguration.SECURITY_TYPE_EAP_SUITE_B;
import static android.net.wifi.WifiConfiguration.SECURITY_TYPE_EAP_WPA3_ENTERPRISE;
import static android.net.wifi.WifiConfiguration.SECURITY_TYPE_EAP_WPA3_ENTERPRISE_192_BIT;
import static android.net.wifi.WifiConfiguration.SECURITY_TYPE_OPEN;
import static android.net.wifi.WifiConfiguration.SECURITY_TYPE_OWE;
import static android.net.wifi.WifiConfiguration.SECURITY_TYPE_PSK;
import static android.net.wifi.WifiConfiguration.SECURITY_TYPE_SAE;
import static android.net.wifi.WifiConfiguration.SECURITY_TYPE_WAPI_CERT;
import static android.net.wifi.WifiConfiguration.SECURITY_TYPE_WAPI_PSK;

import android.content.Context;
import android.net.wifi.WifiConfiguration;
import android.net.wifi.WifiManager;
import android.os.Build;
import android.platform.test.annotations.AppModeFull;

import androidx.test.filters.SdkSuppress;

import java.util.List;

@AppModeFull(reason = "Cannot get WifiManager in instant app mode")
public class WifiConfigurationTest extends WifiJUnit3TestBase {
    private  WifiManager mWifiManager;
    @Override
    protected void setUp() throws Exception {
        super.setUp();
        mWifiManager = (WifiManager) mContext
                .getSystemService(Context.WIFI_SERVICE);
    }

    public void testWifiConfiguration() {
        if (!WifiFeature.isWifiSupported(getContext())) {
            // skip the test if WiFi is not supported
            return;
        }
        List<WifiConfiguration> wifiConfigurations = mWifiManager.getConfiguredNetworks();
        if (wifiConfigurations != null) {
            for (int i = 0; i < wifiConfigurations.size(); i++) {
                WifiConfiguration wifiConfiguration = wifiConfigurations.get(i);
                assertNotNull(wifiConfiguration);
                assertNotNull(wifiConfiguration.toString());
            }
        }
    }

    @SdkSuppress(minSdkVersion = Build.VERSION_CODES.S)
    public void testGetAuthType() throws Exception {
        WifiConfiguration configuration = new WifiConfiguration();

        configuration.setSecurityParams(SECURITY_TYPE_PSK);
        assertEquals(WifiConfiguration.KeyMgmt.WPA_PSK, configuration.getAuthType());

        configuration.setSecurityParams(SECURITY_TYPE_SAE);
        assertEquals(WifiConfiguration.KeyMgmt.SAE, configuration.getAuthType());

        configuration.setSecurityParams(SECURITY_TYPE_WAPI_PSK);
        assertEquals(WifiConfiguration.KeyMgmt.WAPI_PSK, configuration.getAuthType());

        configuration.setSecurityParams(SECURITY_TYPE_OPEN);
        assertEquals(WifiConfiguration.KeyMgmt.NONE, configuration.getAuthType());

        configuration.setSecurityParams(SECURITY_TYPE_OWE);
        assertEquals(WifiConfiguration.KeyMgmt.OWE, configuration.getAuthType());

        configuration.setSecurityParams(SECURITY_TYPE_EAP);
        assertEquals(WifiConfiguration.KeyMgmt.WPA_EAP, configuration.getAuthType());

        configuration.setSecurityParams(SECURITY_TYPE_EAP_WPA3_ENTERPRISE);
        assertEquals(WifiConfiguration.KeyMgmt.WPA_EAP, configuration.getAuthType());

        configuration.setSecurityParams(SECURITY_TYPE_EAP_SUITE_B);
        assertEquals(WifiConfiguration.KeyMgmt.SUITE_B_192, configuration.getAuthType());

        configuration.setSecurityParams(SECURITY_TYPE_EAP_WPA3_ENTERPRISE_192_BIT);
        assertEquals(WifiConfiguration.KeyMgmt.SUITE_B_192, configuration.getAuthType());

        configuration.setSecurityParams(SECURITY_TYPE_WAPI_CERT);
        assertEquals(WifiConfiguration.KeyMgmt.WAPI_CERT, configuration.getAuthType());
    }

    @SdkSuppress(minSdkVersion = Build.VERSION_CODES.S)
    public void testGetAuthTypeFailurePsk8021X() throws Exception {
        WifiConfiguration configuration = new WifiConfiguration();

        configuration.setSecurityParams(SECURITY_TYPE_PSK);
        configuration.allowedKeyManagement.set(WifiConfiguration.KeyMgmt.IEEE8021X);
        try {
            configuration.getAuthType();
            fail("Expected IllegalStateException exception");
        } catch(IllegalStateException e) {
            // empty
        }
    }

    @SdkSuppress(minSdkVersion = Build.VERSION_CODES.S)
    public void testGetAuthTypeFailure8021xEapSae() throws Exception {
        WifiConfiguration configuration = new WifiConfiguration();

        configuration.allowedKeyManagement.set(WifiConfiguration.KeyMgmt.IEEE8021X);
        configuration.allowedKeyManagement.set(WifiConfiguration.KeyMgmt.WPA_EAP);
        configuration.allowedKeyManagement.set(WifiConfiguration.KeyMgmt.SAE);
        try {
            configuration.getAuthType();
            fail("Expected IllegalStateException exception");
        } catch(IllegalStateException e) {
            // empty
        }
    }

    @SdkSuppress(minSdkVersion = Build.VERSION_CODES.S)
    public void testSetGetDeletionPriority() throws Exception {
        WifiConfiguration configuration = new WifiConfiguration();

        assertEquals(0, configuration.getDeletionPriority());
        try {
            configuration.setDeletionPriority(-1);
            fail("Expected IllegalArgumentException exception");
        } catch(IllegalArgumentException e) {
            // empty
        }
        configuration.setDeletionPriority(1);
        assertEquals(1, configuration.getDeletionPriority());
    }
}
