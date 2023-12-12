/*
 * Copyright (C) 2017 The Android Open Source Project
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
package com.android.server.wifi;

import static android.net.wifi.WifiManager.WIFI_FEATURE_OWE;
import static android.net.wifi.WifiManager.WIFI_FEATURE_WPA3_SAE;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;
import static org.mockito.Mockito.validateMockitoUsage;
import static org.mockito.Mockito.when;
import static org.mockito.Mockito.withSettings;

import android.net.wifi.ScanResult;
import android.net.wifi.SecurityParams;
import android.net.wifi.WifiConfiguration;

import androidx.test.filters.SmallTest;

import com.android.dx.mockito.inline.extended.ExtendedMockito;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;
import org.mockito.MockitoSession;

import java.util.ArrayList;
import java.util.List;

/**
 * Unit tests for {@link com.android.server.wifi.ScanResultMatchInfoTest}.
 */
@SmallTest
public class ScanResultMatchInfoTest extends WifiBaseTest {
    private static final String TEST_BSSID = "0a:08:5c:67:89:01";
    private static final String TEST_SSID = "\"ScanResultMatchInfoSSID\"";

    @Mock WifiInjector mWifiInjector;
    @Mock WifiGlobals mWifiGlobals;
    @Mock ActiveModeWarden mActiveModeWarden;
    @Mock ClientModeManager mClientModeManager;
    private MockitoSession mSession;
    /**
     * Sets up for unit test
     */
    @Before
    public void setUp() throws Exception {
        MockitoAnnotations.initMocks(this);
        // static mocking
        mSession = ExtendedMockito.mockitoSession()
                .mockStatic(WifiInjector.class, withSettings().lenient())
                .startMocking();
        when(WifiInjector.getInstance()).thenReturn(mWifiInjector);
        when(mWifiInjector.getWifiGlobals()).thenReturn(mWifiGlobals);
        when(mWifiInjector.getActiveModeWarden()).thenReturn(mActiveModeWarden);
        when(mActiveModeWarden.getPrimaryClientModeManager()).thenReturn(mClientModeManager);
        when(mClientModeManager.getSupportedFeatures()).thenReturn(
                WIFI_FEATURE_OWE | WIFI_FEATURE_WPA3_SAE);
        when(mWifiGlobals.isWpa3SaeUpgradeEnabled()).thenReturn(true);
        when(mWifiGlobals.isOweUpgradeEnabled()).thenReturn(true);
    }

    /**
     * Called after each test
     */
    @After
    public void cleanup() {
        validateMockitoUsage();
        if (mSession != null) {
            mSession.finishMocking();
        }
    }

    /**
     * Tests that equivalent ScanResultMatchInfo objects are created for WifiConfigurations and
     * their associated ScanResult
     */
    @Test
    public void testScanResultMatchesWifiConfiguration() {
        WifiConfiguration conf =
                WifiConfigurationTestUtil.createPskNetwork("\"PrettyFlyForAWifi\"");
        ScanDetail scan = createScanDetailForNetwork(conf, "AA:AA:AA:AA:AA:AA");
        assertEquals(ScanResultMatchInfo.fromWifiConfiguration(conf),
                ScanResultMatchInfo.fromScanResult(scan.getScanResult()));

        conf = WifiConfigurationTestUtil.createOpenNetwork("\"WIFIght the inevitable\"");
        scan = createScanDetailForNetwork(conf, "BB:BB:BB:BB:BB:BB");
        assertEquals(ScanResultMatchInfo.fromWifiConfiguration(conf),
                ScanResultMatchInfo.fromScanResult(scan.getScanResult()));
        assertTrue(ScanResultMatchInfo.fromWifiConfiguration(conf)
                .equals(ScanResultMatchInfo.fromScanResult(
                        scan.getScanResult())));

        conf = WifiConfigurationTestUtil.createWapiPskNetwork();
        scan = createScanDetailForNetwork(conf, "AA:AA:AA:AA:AA:AA");
        assertEquals(ScanResultMatchInfo.fromWifiConfiguration(conf),
                ScanResultMatchInfo.fromScanResult(scan.getScanResult()));

        conf = WifiConfigurationTestUtil.createWapiPskNetwork();
        scan = createScanDetailForNetwork(conf, "BB:BB:BB:BB:BB:BB");
        assertEquals(ScanResultMatchInfo.fromWifiConfiguration(conf),
                ScanResultMatchInfo.fromScanResult(scan.getScanResult()));
    }

    /**
     * Tests that multiple ScanResults with different BSSIDs will produce equivalent
     * ScanResultMatchInfo objects to their associated WifiConfiguration
     */
    @Test
    public void testDifferentBssidScanResultsMatch() {
        WifiConfiguration conf =
                WifiConfigurationTestUtil.createPskNetwork("\"PrettyFlyForAWifi-5G\"");
        ScanDetail scan1 = createScanDetailForNetwork(conf, "AA:AA:AA:AA:AA:AA");
        ScanDetail scan2 = createScanDetailForNetwork(conf, "BB:BB:BB:BB:BB:BB");
        assertFalse(scan1.getScanResult().BSSID.equals(scan2.getScanResult().BSSID));
        assertEquals(ScanResultMatchInfo.fromScanResult(scan1.getScanResult()),
                ScanResultMatchInfo.fromScanResult(scan2.getScanResult()));
    }

    /**
     * Tests that ScanResultMatchInfo objects created for different SSIDs or security types are not
     * equivalent
     */
    @Test
    public void testDifferentNetworkScanResultsDontMatch() {
        WifiConfiguration psk =
                WifiConfigurationTestUtil.createPskNetwork("\"Series Of Tubes\"");
        WifiConfiguration open1 =
                WifiConfigurationTestUtil.createOpenNetwork("\"Series Of Tubes\"");
        WifiConfiguration open2 =
                WifiConfigurationTestUtil.createOpenNetwork("\"Mom, Click Here For Internet\"");
        ScanDetail scanOpen1 = createScanDetailForNetwork(open1, "AA:AA:AA:AA:AA:AA");
        ScanDetail scanOpen2 = createScanDetailForNetwork(open2, "BB:BB:BB:BB:BB:BB");
        ScanDetail scanPsk =   createScanDetailForNetwork(psk,   "CC:CC:CC:CC:CC:CC");
        assertTrue(ScanResultMatchInfo.fromScanResult(scanOpen1.getScanResult())
                != ScanResultMatchInfo.fromScanResult(scanOpen2.getScanResult()));
        assertTrue(ScanResultMatchInfo.fromScanResult(scanOpen1.getScanResult())
                != ScanResultMatchInfo.fromScanResult(scanPsk.getScanResult()));
    }

    /**
     * Tests equality properties, reflexive, symmetric, transitive, consistent for transition mode
     * network.
     */
    @Test
    public void testEqualityRulesForTransitionMode() {
        WifiConfiguration wifiConfiguration =
                WifiConfigurationTestUtil.createPskNetwork("\"Transition is Hard\"");
        ScanDetail scanDetail = createScanDetailForWpa2Wpa3TransitionModeNetwork(wifiConfiguration,
                "AA:BB:CC:DD:CC:BB");

        ScanResultMatchInfo key1 = ScanResultMatchInfo.fromWifiConfiguration(wifiConfiguration);
        ScanResultMatchInfo key2 = ScanResultMatchInfo.fromScanResult(scanDetail.getScanResult());
        ScanResultMatchInfo key3 = ScanResultMatchInfo.fromWifiConfiguration(wifiConfiguration);

        // Test a.equals(a)
        assertTrue(key1.equals(key1));

        // Test if a.equals(b) then b.equals(a)
        assertTrue(key1.equals(key2));
        assertTrue(key2.equals(key1));

        // Test transitivity
        assertTrue(key1.equals(key2));
        assertTrue(key2.equals(key3));
        assertTrue(key1.equals(key3));

        // Test consistency
        assertTrue(key1.equals(key2));
        assertTrue(key1.equals(key2));
        assertTrue(key1.equals(key2));
        assertTrue(key1.equals(key2));
    }

    /**
     * Tests equality properties, reflexive, symmetric, transitive, consistent for PSK network.
     */
    @Test
    public void testEqualityRulesForPsk() {
        WifiConfiguration wifiConfiguration =
                WifiConfigurationTestUtil.createPskNetwork("\"Psk Tsk\"");
        ScanDetail scanDetail = createScanDetailForNetwork(wifiConfiguration,
                "AA:BB:CC:DD:CC:BB");

        ScanResultMatchInfo key1 = ScanResultMatchInfo.fromWifiConfiguration(wifiConfiguration);
        ScanResultMatchInfo key2 = ScanResultMatchInfo.fromScanResult(scanDetail.getScanResult());
        ScanResultMatchInfo key3 = ScanResultMatchInfo.fromWifiConfiguration(wifiConfiguration);

        // Test a.equals(a)
        assertTrue(key1.equals(key1));

        // Test if a.equals(b) then b.equals(a)
        assertTrue(key1.equals(key2));
        assertTrue(key2.equals(key1));

        // Test transitivity
        assertTrue(key1.equals(key2));
        assertTrue(key2.equals(key3));
        assertTrue(key1.equals(key3));

        // Test consistency
        assertTrue(key1.equals(key2));
        assertTrue(key1.equals(key2));
        assertTrue(key1.equals(key2));
        assertTrue(key1.equals(key2));
    }


    /**
     * Tests equality properties, reflexive, symmetric, transitive, consistent for SAE network.
     */
    @Test
    public void testEqualityRulesForSae() {
        WifiConfiguration wifiConfiguration =
                WifiConfigurationTestUtil.createSaeNetwork();
        ScanDetail scanDetail = createScanDetailForNetwork(wifiConfiguration,
                "AC:AB:AD:AE:AF:FC");

        ScanResultMatchInfo key1 = ScanResultMatchInfo.fromWifiConfiguration(wifiConfiguration);
        ScanResultMatchInfo key2 = ScanResultMatchInfo.fromScanResult(scanDetail.getScanResult());
        ScanResultMatchInfo key3 = ScanResultMatchInfo.fromWifiConfiguration(wifiConfiguration);

        // Test a.equals(a)
        assertTrue(key1.equals(key1));

        // Test if a.equals(b) then b.equals(a)
        assertTrue(key1.equals(key2));
        assertTrue(key2.equals(key1));

        // Test transitivity
        assertTrue(key1.equals(key2));
        assertTrue(key2.equals(key3));
        assertTrue(key1.equals(key3));

        // Test consistency
        assertTrue(key1.equals(key2));
        assertTrue(key1.equals(key2));
        assertTrue(key1.equals(key2));
        assertTrue(key1.equals(key2));
    }

    /**
     * Tests that hashes of various configurations are equal
     */
    @Test
    public void testHashForTransitionMode() {
        WifiConfiguration wifiConfigurationPsk =
                WifiConfigurationTestUtil.createPskNetwork("\"Transition is Hard\"");
        WifiConfiguration wifiConfigurationSae =
                WifiConfigurationTestUtil.createSaeNetwork("\"Transition is Hard\"");
        ScanDetail scanDetail = createScanDetailForWpa2Wpa3TransitionModeNetwork(
                wifiConfigurationPsk, "AA:BB:CC:DD:CC:BB");

        ScanResultMatchInfo key1 = ScanResultMatchInfo.fromWifiConfiguration(wifiConfigurationPsk);
        ScanResultMatchInfo key2 = ScanResultMatchInfo.fromScanResult(scanDetail.getScanResult());
        ScanResultMatchInfo key3 = ScanResultMatchInfo.fromWifiConfiguration(wifiConfigurationSae);

        // Assert that all hashes are equal
        assertEquals(key1.hashCode(), key2.hashCode());
        assertEquals(key1.hashCode(), key3.hashCode());
        assertEquals(key2.hashCode(), key3.hashCode());
    }

    /**
     * Creates a scan detail corresponding to the provided network and given BSSID
     */
    private ScanDetail createScanDetailForNetwork(
            WifiConfiguration configuration, String bssid) {
        return WifiConfigurationTestUtil.createScanDetailForNetwork(configuration, bssid, -40,
                2402, 0, 0);
    }

    /**
     * Creates a scan detail corresponding to the provided network and given BSSID
     */
    private ScanDetail createScanDetailForWpa2Wpa3TransitionModeNetwork(
            WifiConfiguration configuration, String bssid) {
        return WifiConfigurationTestUtil.createScanDetailForWpa2Wpa3TransitionModeNetwork(
                configuration, bssid, -40, 2402, 0, 0);
    }

    private void verifyUpgradeMatching(
            WifiConfiguration baseTypeConfig,
            WifiConfiguration upgradeTypeConfig,
            boolean isUpgradeEnabled) {

        ScanDetail scanDetailUpgrade = createScanDetailForNetwork(upgradeTypeConfig,
                "AC:AB:AD:AE:AF:FC");

        ScanResultMatchInfo baseTypeKey = ScanResultMatchInfo
                .fromWifiConfiguration(baseTypeConfig);
        ScanResultMatchInfo upgradeTypeScanResultKey = ScanResultMatchInfo
                .fromScanResult(scanDetailUpgrade.getScanResult());
        ScanResultMatchInfo upgradeTypeKey = ScanResultMatchInfo
                .fromWifiConfiguration(upgradeTypeConfig);

        // Test a.equals(a)
        assertTrue(baseTypeKey.equals(baseTypeKey));

        // Test if a.equals(b) then b.equals(a)
        assertEquals(isUpgradeEnabled,
                baseTypeKey.equals(upgradeTypeScanResultKey));
        assertEquals(isUpgradeEnabled,
                upgradeTypeScanResultKey.equals(baseTypeKey));

        // Test consistency
        assertEquals(isUpgradeEnabled,
                baseTypeKey.equals(upgradeTypeScanResultKey));
        assertEquals(isUpgradeEnabled,
                baseTypeKey.equals(upgradeTypeScanResultKey));
        assertEquals(isUpgradeEnabled,
                baseTypeKey.equals(upgradeTypeScanResultKey));
        assertEquals(isUpgradeEnabled,
                baseTypeKey.equals(upgradeTypeScanResultKey));

        // Test WifiConfiguration objects are not equal
        assertFalse(baseTypeKey.equals(upgradeTypeKey));
        assertFalse(upgradeTypeKey.equals(baseTypeKey));
    }

    /**
     * Tests equality properties for PSK to SAE upgrades
     */
    @Test
    public void testEqualityRulesForPskToSaeUpgrade() {
        verifyUpgradeMatching(
                WifiConfigurationTestUtil.createPskSaeNetwork("\"Upgrade\""),
                WifiConfigurationTestUtil.createSaeNetwork("\"Upgrade\""),
                true);
    }

    /**
     * Tests equality properties for PSK to SAE upgrades when feature is disabled
     */
    @Test
    public void testEqualityRulesForPskToSaeUpgradeWithOverlayDisable() {
        when(mWifiGlobals.isWpa3SaeUpgradeEnabled()).thenReturn(false);
        // Note: createPskSaeNetwork sets setIsAddedByAutoUpgrade
        verifyUpgradeMatching(
                WifiConfigurationTestUtil.createPskSaeNetwork("\"Upgrade\""),
                WifiConfigurationTestUtil.createSaeNetwork("\"Upgrade\""),
                /* isUpgradeEnabled */ false);
    }

    /**
     * Test that SAE saved network will never downgrade to a PSK AP (from scan result)
     */
    @Test
    public void testSaeToPskDoesNotDowngrade() {
        WifiConfiguration wifiConfigurationSae =
                WifiConfigurationTestUtil.createSaeNetwork("\"Downgrade\"");
        WifiConfiguration wifiConfigurationPsk =
                WifiConfigurationTestUtil.createPskNetwork("\"Downgrade\"");
        wifiConfigurationPsk.setSecurityParams(WifiConfiguration.SECURITY_TYPE_PSK);
        ScanDetail scanDetailPsk = createScanDetailForNetwork(wifiConfigurationPsk,
                "AC:AB:AD:AE:AF:FC");

        ScanResultMatchInfo key1 = ScanResultMatchInfo.fromWifiConfiguration(wifiConfigurationSae);
        ScanResultMatchInfo key2 = ScanResultMatchInfo
                .fromScanResult(scanDetailPsk.getScanResult());

        // Test both a.equals(b) and b.equals(a) are false:
        // i.e. SAE saved network will never downgrade to a PSK AP (from scan result)
        assertFalse(key1.equals(key2));
        assertFalse(key2.equals(key1));
    }

    /**
     * Tests equality properties for OPEN to OWE upgrades
     */
    @Test
    public void testEqualityRulesForOpenToOweUpgrade() {
        verifyUpgradeMatching(
                WifiConfigurationTestUtil.createOpenOweNetwork("\"Upgrade\""),
                WifiConfigurationTestUtil.createOweNetwork("\"Upgrade\""),
                true);
    }

    /**
     * Tests equality properties for OPEN to OWE upgrades when feature is disabled
     */
    @Test
    public void testEqualityRulesForOpenToOweUpgradeWithOverlayDisable() {
        when(mWifiGlobals.isOweUpgradeEnabled()).thenReturn(false);
        // Note: createOpenOweNetwork sets setIsAddedByAutoUpgrade
        verifyUpgradeMatching(
                WifiConfigurationTestUtil.createOpenOweNetwork("\"Upgrade\""),
                WifiConfigurationTestUtil.createOweNetwork("\"Upgrade\""),
                /* isUpgradeEnabled */ false);
    }

    /**
     * Test that OWE saved network will never downgrade to a OPEN AP (from scan result)
     */
    @Test
    public void testOweToOpenDoesNotDowngrade() {
        WifiConfiguration wifiConfigurationOwe =
                WifiConfigurationTestUtil.createOweNetwork("\"Downgrade\"");
        WifiConfiguration wifiConfigurationOpen =
                WifiConfigurationTestUtil.createOpenNetwork("\"Downgrade\"");
        wifiConfigurationOpen.setSecurityParams(WifiConfiguration.SECURITY_TYPE_OPEN);
        ScanDetail scanDetailOpen = createScanDetailForNetwork(wifiConfigurationOpen,
                "AC:AB:AD:AE:AF:FC");

        ScanResultMatchInfo key1 = ScanResultMatchInfo
                .fromWifiConfiguration(wifiConfigurationOwe);
        ScanResultMatchInfo key2 = ScanResultMatchInfo
                .fromScanResult(scanDetailOpen.getScanResult());

        // Test both a.equals(b) and b.equals(a) are false:
        // i.e. OWE saved network will never downgrade to a OPEN AP (from scan result)
        assertFalse(key1.equals(key2));
        assertFalse(key2.equals(key1));
    }

    @Test
    public void testEqualityRulesForWpa2EnterpriseToWpa3EnterpriseUpgrade() {
        verifyUpgradeMatching(
                WifiConfigurationTestUtil.createWpa2Wpa3EnterpriseNetwork("\"Upgrade\""),
                WifiConfigurationTestUtil.createWpa3EnterpriseNetwork("\"Upgrade\""),
                true);
    }

    /**
     * Test that WPA3 Enterprise saved network will never downgrade to a
     * WPA2 Enterprise AP (from scan result)
     */
    @Test
    public void testWpa3EnterpriseToWpa2EnterpriseDoesNotDowngrade() {
        WifiConfiguration wifiConfigurationWpa2Enterprise =
                WifiConfigurationTestUtil.createEapNetwork("\"Downgrade\"");
        WifiConfiguration wifiConfigurationWpa3Enterprise =
                WifiConfigurationTestUtil.createWpa3EnterpriseNetwork("\"Downgrade\"");
        ScanDetail scanDetailWpa2Enterprise = createScanDetailForNetwork(
                wifiConfigurationWpa2Enterprise,
                "AC:AB:AD:AE:AF:FC");

        ScanResultMatchInfo key1 = ScanResultMatchInfo
                .fromWifiConfiguration(wifiConfigurationWpa3Enterprise);
        ScanResultMatchInfo key2 = ScanResultMatchInfo
                .fromScanResult(scanDetailWpa2Enterprise.getScanResult());

        // Test both a.equals(b) and b.equals(a) are false:
        // i.e. WPA3 Enterprise saved network will never downgrade to
        // a WPA2 Enterprise AP (from scan result)
        assertFalse(key1.equals(key2));
        assertFalse(key2.equals(key1));
    }

    @Test
    public void testMatchBehaviorWithWpa3AutoUpgradeFlagStates() {
        // Add a PSK network and manually add SAE type (added by the framework)
        WifiConfiguration configPskWithSaeSecurityType =
                WifiConfigurationTestUtil.createPskSaeNetwork(TEST_SSID);

        // Create a WPA3 SAE only scan result
        WifiConfiguration configSaeOnly =
                WifiConfigurationTestUtil.createSaeNetwork(TEST_SSID);
        ScanResult scanResult = WifiConfigurationTestUtil.createScanDetailForNetwork(configSaeOnly,
                TEST_BSSID, 0, 0, 0, 0).getScanResult();

        // Default setting of the auto-upgrade flag is enabled.
        assertNotNull(ScanResultMatchInfo
                .getBestMatchingSecurityParams(configPskWithSaeSecurityType, scanResult));
        SecurityParams params = SecurityParams.createSecurityParamsBySecurityType(
                WifiConfiguration.SECURITY_TYPE_SAE);
        List<SecurityParams> securityParamsList = new ArrayList<>();
        securityParamsList.add(params);
        assertNotNull(ScanResultMatchInfo
                .getBestMatchingSecurityParams(configPskWithSaeSecurityType, securityParamsList));

        ScanResultMatchInfo fromScanResult = ScanResultMatchInfo.fromScanResult(scanResult);
        ScanResultMatchInfo fromWifiConfig = ScanResultMatchInfo.fromWifiConfiguration(
                configPskWithSaeSecurityType);
        assertNotNull(fromWifiConfig.matchForNetworkSelection(fromScanResult));
        assertTrue(fromWifiConfig.networkTypeEquals(fromScanResult));

        // Now change the auto-upgrade flag to disabled.
        when(mWifiGlobals.isWpa3SaeUpgradeEnabled()).thenReturn(false);
        assertNull(ScanResultMatchInfo
                .getBestMatchingSecurityParams(configPskWithSaeSecurityType, scanResult));
        assertNull(ScanResultMatchInfo
                .getBestMatchingSecurityParams(configPskWithSaeSecurityType, securityParamsList));
        assertNull(fromWifiConfig.matchForNetworkSelection(fromScanResult));
        assertFalse(fromWifiConfig.networkTypeEquals(fromScanResult));
    }

    @Test
    public void testMatchBehaviorWithOweAutoUpgradeFlagStates() {
        // Add a PSK network and manually add OWE type (added by the framework)
        WifiConfiguration configOpenWithOweSecurityType =
                WifiConfigurationTestUtil.createOpenOweNetwork(TEST_SSID);

        // Create an OWE only scan result
        WifiConfiguration configOweOnly =
                WifiConfigurationTestUtil.createOweNetwork(TEST_SSID);
        ScanResult scanResult = WifiConfigurationTestUtil.createScanDetailForNetwork(configOweOnly,
                TEST_BSSID, 0, 0, 0, 0).getScanResult();

        // Default setting of the auto-upgrade flag is enabled.
        assertNotNull(ScanResultMatchInfo
                .getBestMatchingSecurityParams(configOpenWithOweSecurityType, scanResult));
        SecurityParams params = SecurityParams.createSecurityParamsBySecurityType(
                WifiConfiguration.SECURITY_TYPE_OWE);
        List<SecurityParams> securityParamsList = new ArrayList<>();
        securityParamsList.add(params);
        assertNotNull(ScanResultMatchInfo
                .getBestMatchingSecurityParams(configOpenWithOweSecurityType, securityParamsList));

        ScanResultMatchInfo fromScanResult = ScanResultMatchInfo.fromScanResult(scanResult);
        ScanResultMatchInfo fromWifiConfig = ScanResultMatchInfo.fromWifiConfiguration(
                configOpenWithOweSecurityType);
        assertNotNull(fromWifiConfig.matchForNetworkSelection(fromScanResult));
        assertTrue(fromWifiConfig.networkTypeEquals(fromScanResult));

        // Now change the auto-upgrade flag to disabled.
        when(mWifiGlobals.isOweUpgradeEnabled()).thenReturn(false);
        assertNull(ScanResultMatchInfo
                .getBestMatchingSecurityParams(configOpenWithOweSecurityType, scanResult));
        assertNull(ScanResultMatchInfo
                .getBestMatchingSecurityParams(configOpenWithOweSecurityType, securityParamsList));
        assertNull(fromWifiConfig.matchForNetworkSelection(fromScanResult));
        assertFalse(fromWifiConfig.networkTypeEquals(fromScanResult));
    }
}
