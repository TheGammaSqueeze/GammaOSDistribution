/*
 * Copyright (C) 2019 The Android Open Source Project
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

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;

import android.content.Context;
import android.net.wifi.ScanResult;
import android.net.wifi.WifiConfiguration;
import android.net.wifi.WifiConfiguration.NetworkSelectionStatus;
import android.net.wifi.WifiConfiguration.NetworkSelectionStatus.DisableReasonInfo;
import android.util.LocalLog;

import androidx.test.filters.SmallTest;

import com.android.wifi.resources.R;

import org.junit.Before;
import org.junit.Test;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.TimeUnit;

/**
 * Unit tests for {@link com.android.server.wifi.WifiBlocklistMonitor}.
 */
@SmallTest
public class WifiBlocklistMonitorTest {
    private static final int TEST_NUM_MAX_FIRMWARE_SUPPORT_BSSIDS = 3;
    private static final int TEST_NUM_MAX_FIRMWARE_SUPPORT_SSIDS = 3;
    private static final String TEST_SSID_1 = "TestSSID1";
    private static final String TEST_SSID_2 = "TestSSID2";
    private static final String TEST_SSID_3 = "TestSSID3";
    private static final String TEST_BSSID_1 = "0a:08:5c:67:89:00";
    private static final String TEST_BSSID_2 = "0a:08:5c:67:89:01";
    private static final String TEST_BSSID_3 = "0a:08:5c:67:89:02";
    private static final long TEST_ELAPSED_UPDATE_NETWORK_SELECTION_TIME_MILLIS = 29457631;
    private static final int TEST_GOOD_RSSI = -50;
    private static final int TEST_SUFFICIENT_RSSI = -67;
    private static final int MIN_RSSI_DIFF_TO_UNBLOCK_BSSID = 5;
    private static final int TEST_FRAMEWORK_BLOCK_REASON =
            WifiBlocklistMonitor.REASON_FRAMEWORK_DISCONNECT_MBO_OCE;
    private static final int TEST_L2_FAILURE = WifiBlocklistMonitor.REASON_ASSOCIATION_REJECTION;
    private static final int TEST_DHCP_FAILURE = WifiBlocklistMonitor.REASON_DHCP_FAILURE;
    private static final long BASE_BLOCKLIST_DURATION = TimeUnit.MINUTES.toMillis(5); // 5 minutes
    private static final long BASE_CONNECTED_SCORE_BLOCKLIST_DURATION =
            TimeUnit.SECONDS.toMillis(30);
    private static final long ABNORMAL_DISCONNECT_TIME_WINDOW_MS = TimeUnit.SECONDS.toMillis(30);
    private static final long ABNORMAL_DISCONNECT_RESET_TIME_MS = TimeUnit.HOURS.toMillis(3);
    private static final int FAILURE_STREAK_CAP = 7;
    private static final Map<Integer, Integer> BLOCK_REASON_TO_DISABLE_THRESHOLD_MAP =
            Map.ofEntries(
                    Map.entry(WifiBlocklistMonitor.REASON_AP_UNABLE_TO_HANDLE_NEW_STA, 1),
                    Map.entry(WifiBlocklistMonitor.REASON_NETWORK_VALIDATION_FAILURE, 1),
                    Map.entry(WifiBlocklistMonitor.REASON_WRONG_PASSWORD, 1),
                    Map.entry(WifiBlocklistMonitor.REASON_EAP_FAILURE, 1),
                    Map.entry(WifiBlocklistMonitor.REASON_ASSOCIATION_REJECTION, 3),
                    Map.entry(WifiBlocklistMonitor.REASON_ASSOCIATION_TIMEOUT, 3),
                    Map.entry(WifiBlocklistMonitor.REASON_AUTHENTICATION_FAILURE, 3),
                    Map.entry(WifiBlocklistMonitor.REASON_DHCP_FAILURE, 3),
                    Map.entry(WifiBlocklistMonitor.REASON_ABNORMAL_DISCONNECT, 3),
                    Map.entry(WifiBlocklistMonitor.REASON_FRAMEWORK_DISCONNECT_MBO_OCE, 1),
                    Map.entry(WifiBlocklistMonitor.REASON_FRAMEWORK_DISCONNECT_FAST_RECONNECT, 1),
                    Map.entry(WifiBlocklistMonitor.REASON_FRAMEWORK_DISCONNECT_CONNECTED_SCORE, 1),
                    Map.entry(WifiBlocklistMonitor.REASON_NONLOCAL_DISCONNECT_CONNECTING, 2)
            );
    private static final int NUM_FAILURES_TO_BLOCKLIST =
            BLOCK_REASON_TO_DISABLE_THRESHOLD_MAP.get(TEST_L2_FAILURE);

    @Mock private Context mContext;
    @Mock private WifiConnectivityHelper mWifiConnectivityHelper;
    @Mock private WifiLastResortWatchdog mWifiLastResortWatchdog;
    @Mock private Clock mClock;
    @Mock private LocalLog mLocalLog;
    @Mock private WifiScoreCard mWifiScoreCard;
    @Mock private ScoringParams mScoringParams;
    @Mock private WifiMetrics mWifiMetrics;
    @Mock private WifiScoreCard.PerNetwork mPerNetwork;
    @Mock private WifiScoreCard.NetworkConnectionStats mRecentStats;

    private MockResources mResources;
    private WifiBlocklistMonitor mWifiBlocklistMonitor;

    @Before
    public void setup() {
        MockitoAnnotations.initMocks(this);

        when(mWifiConnectivityHelper.isFirmwareRoamingSupported()).thenReturn(true);
        when(mWifiConnectivityHelper.getMaxNumBlocklistBssid())
                .thenReturn(TEST_NUM_MAX_FIRMWARE_SUPPORT_BSSIDS);
        when(mWifiConnectivityHelper.getMaxNumAllowlistSsid())
                .thenReturn(TEST_NUM_MAX_FIRMWARE_SUPPORT_SSIDS);
        when(mScoringParams.getSufficientRssi(anyInt())).thenReturn(TEST_SUFFICIENT_RSSI);
        mResources = new MockResources();
        mResources.setInteger(R.integer.config_wifiBssidBlocklistMonitorBaseBlockDurationMs,
                (int) BASE_BLOCKLIST_DURATION);
        mResources.setInteger(
                R.integer.config_wifiBssidBlocklistMonitorConnectedScoreBaseBlockDurationMs,
                (int) BASE_CONNECTED_SCORE_BLOCKLIST_DURATION);
        mResources.setInteger(R.integer.config_wifiBssidBlocklistMonitorFailureStreakCap,
                FAILURE_STREAK_CAP);
        mResources.setInteger(R.integer.config_wifiBssidBlocklistAbnormalDisconnectTimeWindowMs,
                (int) ABNORMAL_DISCONNECT_TIME_WINDOW_MS);
        mResources.setInteger(
                R.integer.config_wifiBssidBlocklistMonitorApUnableToHandleNewStaThreshold,
                BLOCK_REASON_TO_DISABLE_THRESHOLD_MAP.get(
                        WifiBlocklistMonitor.REASON_AP_UNABLE_TO_HANDLE_NEW_STA));
        mResources.setInteger(
                R.integer.config_wifiBssidBlocklistMonitorNetworkValidationFailureThreshold,
                BLOCK_REASON_TO_DISABLE_THRESHOLD_MAP.get(
                        WifiBlocklistMonitor.REASON_NETWORK_VALIDATION_FAILURE));
        mResources.setInteger(R.integer.config_wifiBssidBlocklistMonitorWrongPasswordThreshold,
                BLOCK_REASON_TO_DISABLE_THRESHOLD_MAP.get(
                        WifiBlocklistMonitor.REASON_WRONG_PASSWORD));
        mResources.setInteger(R.integer.config_wifiBssidBlocklistMonitorEapFailureThreshold,
                BLOCK_REASON_TO_DISABLE_THRESHOLD_MAP.get(
                        WifiBlocklistMonitor.REASON_EAP_FAILURE));
        mResources.setInteger(
                R.integer.config_wifiBssidBlocklistMonitorAssociationRejectionThreshold,
                BLOCK_REASON_TO_DISABLE_THRESHOLD_MAP.get(
                        WifiBlocklistMonitor.REASON_ASSOCIATION_REJECTION));
        mResources.setInteger(
                R.integer.config_wifiBssidBlocklistMonitorAssociationTimeoutThreshold,
                BLOCK_REASON_TO_DISABLE_THRESHOLD_MAP.get(
                        WifiBlocklistMonitor.REASON_ASSOCIATION_TIMEOUT));
        mResources.setInteger(
                R.integer.config_wifiBssidBlocklistMonitorAuthenticationFailureThreshold,
                BLOCK_REASON_TO_DISABLE_THRESHOLD_MAP.get(
                        WifiBlocklistMonitor.REASON_AUTHENTICATION_FAILURE));
        mResources.setInteger(R.integer.config_wifiBssidBlocklistMonitorDhcpFailureThreshold,
                BLOCK_REASON_TO_DISABLE_THRESHOLD_MAP.get(
                        WifiBlocklistMonitor.REASON_DHCP_FAILURE));
        mResources.setInteger(
                R.integer.config_wifiBssidBlocklistMonitorAbnormalDisconnectThreshold,
                BLOCK_REASON_TO_DISABLE_THRESHOLD_MAP.get(
                        WifiBlocklistMonitor.REASON_ABNORMAL_DISCONNECT));
        mResources.setInteger(
                R.integer.config_wifiBssidBlocklistMonitorNonlocalDisconnectConnectingThreshold,
                BLOCK_REASON_TO_DISABLE_THRESHOLD_MAP.get(
                        WifiBlocklistMonitor.REASON_NONLOCAL_DISCONNECT_CONNECTING));
        mResources.setInteger(
                R.integer.config_wifiDisableReasonAssociationRejectionThreshold,
                NetworkSelectionStatus.DISABLE_REASON_INFOS
                        .get(NetworkSelectionStatus.DISABLED_ASSOCIATION_REJECTION)
                        .mDisableThreshold);
        mResources.setInteger(
                R.integer.config_wifiDisableReasonAuthenticationFailureThreshold,
                NetworkSelectionStatus.DISABLE_REASON_INFOS
                        .get(NetworkSelectionStatus.DISABLED_AUTHENTICATION_FAILURE)
                        .mDisableThreshold);
        mResources.setInteger(
                R.integer.config_wifiDisableReasonDhcpFailureThreshold,
                NetworkSelectionStatus.DISABLE_REASON_INFOS
                        .get(NetworkSelectionStatus.DISABLED_DHCP_FAILURE).mDisableThreshold);
        mResources.setInteger(
                R.integer.config_wifiDisableReasonNetworkNotFoundThreshold,
                NetworkSelectionStatus.DISABLE_REASON_INFOS
                        .get(NetworkSelectionStatus.DISABLED_NETWORK_NOT_FOUND).mDisableThreshold);
        when(mContext.getResources()).thenReturn(mResources);
        when(mPerNetwork.getRecentStats()).thenReturn(mRecentStats);
        when(mWifiScoreCard.lookupNetwork(anyString())).thenReturn(mPerNetwork);
        mWifiBlocklistMonitor = new WifiBlocklistMonitor(mContext, mWifiConnectivityHelper,
                mWifiLastResortWatchdog, mClock, mLocalLog, mWifiScoreCard, mScoringParams,
                mWifiMetrics);
    }

    private void verifyAddTestBssidToBlocklist() {
        mWifiBlocklistMonitor.handleBssidConnectionFailure(
                TEST_BSSID_1, TEST_SSID_1,
                WifiBlocklistMonitor.REASON_AP_UNABLE_TO_HANDLE_NEW_STA, TEST_GOOD_RSSI);
        assertTrue(mWifiBlocklistMonitor.updateAndGetBssidBlocklist().contains(TEST_BSSID_1));
    }

    // Verify adding 2 BSSID for SSID_1 and 1 BSSID for SSID_2 to the blocklist.
    private void verifyAddMultipleBssidsToBlocklist() {
        when(mClock.getWallClockMillis()).thenReturn(0L);
        mWifiBlocklistMonitor.handleBssidConnectionFailure(TEST_BSSID_1,
                TEST_SSID_1, WifiBlocklistMonitor.REASON_AP_UNABLE_TO_HANDLE_NEW_STA,
                TEST_GOOD_RSSI);
        when(mClock.getWallClockMillis()).thenReturn(1L);
        mWifiBlocklistMonitor.handleBssidConnectionFailure(TEST_BSSID_2,
                TEST_SSID_1, WifiBlocklistMonitor.REASON_AP_UNABLE_TO_HANDLE_NEW_STA,
                TEST_GOOD_RSSI);
        mWifiBlocklistMonitor.handleBssidConnectionFailure(TEST_BSSID_3,
                TEST_SSID_2, WifiBlocklistMonitor.REASON_AP_UNABLE_TO_HANDLE_NEW_STA,
                TEST_GOOD_RSSI);

        // Verify that we have 3 BSSIDs in the blocklist.
        Set<String> bssidList = mWifiBlocklistMonitor.updateAndGetBssidBlocklist();
        assertEquals(3, bssidList.size());
        assertTrue(bssidList.contains(TEST_BSSID_1));
        assertTrue(bssidList.contains(TEST_BSSID_2));
        assertTrue(bssidList.contains(TEST_BSSID_3));
    }

    private void handleBssidConnectionFailureMultipleTimes(String bssid, int reason, int times) {
        handleBssidConnectionFailureMultipleTimes(bssid, TEST_SSID_1, reason, times);
    }

    private void handleBssidConnectionFailureMultipleTimes(String bssid, String ssid, int reason,
            int times) {
        for (int i = 0; i < times; i++) {
            mWifiBlocklistMonitor.handleBssidConnectionFailure(bssid, ssid, reason,
                    TEST_GOOD_RSSI);
        }
    }

    /**
     * Verify updateAndGetNumBlockedBssidsForSsid returns the correct number of blocked BSSIDs.
     */
    @Test
    public void testUpdateAndGetNumBlockedBssidsForSsid() {
        verifyAddMultipleBssidsToBlocklist();
        assertEquals(2, mWifiBlocklistMonitor.updateAndGetNumBlockedBssidsForSsid(TEST_SSID_1));
        assertEquals(1, mWifiBlocklistMonitor.updateAndGetNumBlockedBssidsForSsid(TEST_SSID_2));
    }

    /**
     * Verify that updateAndGetBssidBlocklist removes expired blocklist entries and clears
     * all failure counters for those networks.
     */
    @Test
    public void testBssidIsRemovedFromBlocklistAfterTimeout() {
        verifyAddTestBssidToBlocklist();
        // Verify TEST_BSSID_1 is not removed from the blocklist until sufficient time have passed.
        when(mClock.getWallClockMillis()).thenReturn(BASE_BLOCKLIST_DURATION);
        assertTrue(mWifiBlocklistMonitor.updateAndGetBssidBlocklist().contains(TEST_BSSID_1));

        // Verify that TEST_BSSID_1 is removed from the blocklist after the timeout duration.
        // By default there is no blocklist streak so the timeout duration is simply
        // BASE_BLOCKLIST_DURATION
        when(mClock.getWallClockMillis()).thenReturn(BASE_BLOCKLIST_DURATION + 1);
        assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());
    }

    /**
     * Verify that updateAndGetBssidBlocklist(ssid) updates firmware roaming configuration
     * if a BSSID that belongs to the ssid is removed from blocklist.
     */
    @Test
    public void testBssidRemovalUpdatesFirmwareConfiguration() {
        verifyAddTestBssidToBlocklist();
        when(mClock.getWallClockMillis()).thenReturn(BASE_BLOCKLIST_DURATION + 1);
        assertEquals(0, mWifiBlocklistMonitor
                .updateAndGetBssidBlocklistForSsids(Set.of(TEST_SSID_1)).size());
        verify(mWifiConnectivityHelper).setFirmwareRoamingConfiguration(eq(new ArrayList<>()),
                eq(new ArrayList<>()));
    }

    /**
     * Verify that updateAndGetBssidBlocklist(ssid) does not update firmware roaming configuration
     * if there are no BSSIDs belonging to the ssid removed from blocklist.
     */
    @Test
    public void testBssidRemovalNotUpdateFirmwareConfiguration() {
        verifyAddTestBssidToBlocklist();
        when(mClock.getWallClockMillis()).thenReturn(BASE_BLOCKLIST_DURATION + 1);
        assertEquals(0, mWifiBlocklistMonitor
                .updateAndGetBssidBlocklistForSsids(Set.of(TEST_SSID_2)).size());
        verify(mWifiConnectivityHelper, never()).setFirmwareRoamingConfiguration(
                eq(new ArrayList<>()), eq(new ArrayList<>()));
    }

    /**
     * Verify that if REASON_AUTHENTICATION_FAILURE happens on the only BSSID of a SSID, the BSSID
     * will not get blocked.
     */
    @Test
    public void testIgnoreIfOnlyBssid() {
        // setup TEST_BSSID_1 to be the only BSSID for its SSID
        when(mWifiLastResortWatchdog.isBssidOnlyApOfSsid(TEST_BSSID_1)).thenReturn(true);
        when(mWifiLastResortWatchdog.isBssidOnlyApOfSsid(TEST_BSSID_2)).thenReturn(false);

        // Simulate both BSSIDs failing
        int failureReason = WifiBlocklistMonitor.REASON_AUTHENTICATION_FAILURE;
        int threshold = BLOCK_REASON_TO_DISABLE_THRESHOLD_MAP.get(failureReason);
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_1, TEST_SSID_1,
                failureReason, threshold);
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_2, TEST_SSID_2,
                failureReason, threshold);

        // Verify that only TEST_BSSID_2 is added to the blocklist.
        assertEquals(1, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());
        assertTrue(mWifiBlocklistMonitor.updateAndGetBssidBlocklist().contains(TEST_BSSID_2));
    }

    /**
     * Verify that for REASON_AP_UNABLE_TO_HANDLE_NEW_STA, the BSSID will get blocked even if it's
     * the only BSSID for its SSID.
     */
    @Test
    public void testIgnoreIfOnlyBssidNotApplicableForSomeFailures() {
        // setup TEST_BSSID_1 to be the only BSSID for its SSID
        when(mWifiLastResortWatchdog.isBssidOnlyApOfSsid(TEST_BSSID_1)).thenReturn(true);

        // Simulate TEST_BSSID_1 failing
        int failureReason = WifiBlocklistMonitor.REASON_AP_UNABLE_TO_HANDLE_NEW_STA;
        int threshold = BLOCK_REASON_TO_DISABLE_THRESHOLD_MAP.get(failureReason);
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_1, TEST_SSID_1,
                failureReason, threshold);

        // Verify verify that TEST_BSSID_1 is in the blocklist
        assertEquals(1, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());
        assertTrue(mWifiBlocklistMonitor.updateAndGetBssidBlocklist().contains(TEST_BSSID_1));
    }

    /**
     * Verify that if a failure happens on a disabled WifiConfiguration, the failure will not get
     * ignored even if it's the only BSSID remaining.
     */
    @Test
    public void testFailuresOnDisabledConfigsGetBlocked() {
        // setup both TEST_BSSID_1 and TEST_BSSID_2 to be the only BSSID for its SSID
        when(mWifiLastResortWatchdog.isBssidOnlyApOfSsid(TEST_BSSID_1)).thenReturn(true);
        when(mWifiLastResortWatchdog.isBssidOnlyApOfSsid(TEST_BSSID_2)).thenReturn(true);

        // setup TEST_SSID_2 to be disabled
        mWifiBlocklistMonitor.handleWifiConfigurationDisabled(TEST_SSID_2);

        // Simulate both BSSIDs failing
        int failureReason = WifiBlocklistMonitor.REASON_AUTHENTICATION_FAILURE;
        int threshold = BLOCK_REASON_TO_DISABLE_THRESHOLD_MAP.get(failureReason);
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_1, TEST_SSID_1,
                failureReason, threshold);
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_2, TEST_SSID_2,
                failureReason, threshold);

        // Verify that only TEST_BSSID_2 is added to the blocklist.
        assertEquals(1, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());
        assertTrue(mWifiBlocklistMonitor.updateAndGetBssidBlocklist().contains(TEST_BSSID_2));

        // Now simulate having a connection success on TEST_BSSID_2 and verify there are
        // no more blocked BSSIDs, and connection failure should be ignored on TEST_BSSID_2 again.
        mWifiBlocklistMonitor.handleBssidConnectionSuccess(TEST_BSSID_2, TEST_SSID_2);
        mWifiBlocklistMonitor.clearBssidBlocklistForSsid(TEST_SSID_2);
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_2, TEST_SSID_2,
                failureReason, threshold);
        assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());
    }

    /**
     * Verify that when adding a AP that had already been failing (therefore has a blocklist
     * streak), we are setting the blocklist duration using an exponential backoff technique.
     */
    @Test
    public void testBssidIsRemoveFromBlocklistAfterTimoutExponentialBackoff() {
        verifyAddTestBssidToBlocklist();
        int multiplier = 2;
        long duration = 0;
        for (int i = 1; i <= FAILURE_STREAK_CAP; i++) {
            when(mWifiScoreCard.getBssidBlocklistStreak(anyString(), anyString(), anyInt()))
                    .thenReturn(i);
            when(mClock.getWallClockMillis()).thenReturn(0L);
            verifyAddTestBssidToBlocklist();

            // calculate the expected blocklist duration then verify that timeout happens
            // exactly after the duration.
            duration = multiplier * BASE_BLOCKLIST_DURATION;
            when(mClock.getWallClockMillis()).thenReturn(duration);
            assertTrue(mWifiBlocklistMonitor.updateAndGetBssidBlocklist().contains(TEST_BSSID_1));
            when(mClock.getWallClockMillis()).thenReturn(duration + 1);
            assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());

            multiplier *= 2;
        }

        // finally verify that the timout is capped by the FAILURE_STREAK_CAP
        when(mWifiScoreCard.getBssidBlocklistStreak(anyString(), anyString(), anyInt()))
                .thenReturn(FAILURE_STREAK_CAP + 1);
        when(mClock.getWallClockMillis()).thenReturn(0L);
        verifyAddTestBssidToBlocklist();
        when(mClock.getWallClockMillis()).thenReturn(duration);
        assertTrue(mWifiBlocklistMonitor.updateAndGetBssidBlocklist().contains(TEST_BSSID_1));
        when(mClock.getWallClockMillis()).thenReturn(duration + 1);
        assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());
    }

    /**
     * Verify that consecutive failures will add a BSSID to blocklist.
     */
    @Test
    public void testRepeatedConnectionFailuresAddToBlocklist() {
        // First verify that n-1 failrues does not add the BSSID to blocklist
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_1, TEST_L2_FAILURE,
                NUM_FAILURES_TO_BLOCKLIST - 1);
        assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());

        // Simulate a long time passing to make sure failure counters are not being cleared through
        // some time based check
        when(mClock.getWallClockMillis()).thenReturn(10 * BASE_BLOCKLIST_DURATION);
        assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());

        // Verify that 1 more failure will add the BSSID to blocklist.
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_1, TEST_L2_FAILURE, 1);
        assertTrue(mWifiBlocklistMonitor.updateAndGetBssidBlocklist().contains(TEST_BSSID_1));
    }

    /**
     * Verify that only abnormal disconnects that happened in a window of time right after
     * connection gets counted in the WifiBlocklistMonitor.
     */
    @Test
    public void testAbnormalDisconnectRecencyCheck() {
        // does some setup so that 1 failure is enough to add the BSSID to blocklist.
        when(mWifiScoreCard.getBssidBlocklistStreak(TEST_SSID_1, TEST_BSSID_1,
                WifiBlocklistMonitor.REASON_ABNORMAL_DISCONNECT)).thenReturn(1);

        // simulate an abnormal disconnect coming in after the allowed window of time
        when(mWifiScoreCard.getBssidConnectionTimestampMs(TEST_SSID_1, TEST_BSSID_1))
                .thenReturn(0L);
        when(mClock.getWallClockMillis()).thenReturn(ABNORMAL_DISCONNECT_TIME_WINDOW_MS + 1);
        assertFalse(mWifiBlocklistMonitor.handleBssidConnectionFailure(TEST_BSSID_1, TEST_SSID_1,
                WifiBlocklistMonitor.REASON_ABNORMAL_DISCONNECT, TEST_GOOD_RSSI));
        verify(mWifiScoreCard, never()).incrementBssidBlocklistStreak(TEST_SSID_1, TEST_BSSID_1,
                WifiBlocklistMonitor.REASON_ABNORMAL_DISCONNECT);

        // simulate another abnormal disconnect within the time window and verify the BSSID is
        // added to blocklist.
        when(mClock.getWallClockMillis()).thenReturn(ABNORMAL_DISCONNECT_TIME_WINDOW_MS);
        assertTrue(mWifiBlocklistMonitor.handleBssidConnectionFailure(TEST_BSSID_1, TEST_SSID_1,
                WifiBlocklistMonitor.REASON_ABNORMAL_DISCONNECT, TEST_GOOD_RSSI));
        verify(mWifiScoreCard).incrementBssidBlocklistStreak(TEST_SSID_1, TEST_BSSID_1,
                WifiBlocklistMonitor.REASON_ABNORMAL_DISCONNECT);
    }

    /**
     * Verify that when the BSSID blocklist streak is greater or equal to 1, then we block a
     * BSSID on a single failure regardless of failure type.
     */
    @Test
    public void testBlocklistStreakExpeditesAddingToBlocklist() {
        when(mWifiScoreCard.getBssidBlocklistStreak(anyString(), anyString(), anyInt()))
                .thenReturn(1);
        assertTrue(mWifiBlocklistMonitor.handleBssidConnectionFailure(
                TEST_BSSID_1, TEST_SSID_1, TEST_L2_FAILURE, TEST_GOOD_RSSI));
        assertTrue(mWifiBlocklistMonitor.updateAndGetBssidBlocklist().contains(TEST_BSSID_1));
    }

    /**
     * Verify that onSuccessfulConnection resets L2 related failure counts.
     */
    @Test
    public void testL2FailureCountIsResetAfterSuccessfulConnection() {
        // First simulate getting a particular L2 failure n-1 times
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_1, TEST_L2_FAILURE,
                NUM_FAILURES_TO_BLOCKLIST - 1);

        // Verify that a connection success event will clear the failure count.
        mWifiBlocklistMonitor.handleBssidConnectionSuccess(TEST_BSSID_1, TEST_SSID_1);
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_1, TEST_L2_FAILURE,
                NUM_FAILURES_TO_BLOCKLIST - 1);

        // Verify we have not blocklisted anything yet because the failure count was cleared.
        assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());

        // Verify that TEST_BSSID_1 is added to blocklist after 1 more failure.
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_1, TEST_L2_FAILURE, 1);
        assertTrue(mWifiBlocklistMonitor.updateAndGetBssidBlocklist().contains(TEST_BSSID_1));
    }

    /**
     * Verify that handleDhcpProvisioningSuccess resets DHCP failure counts.
     */
    @Test
    public void testL3FailureCountIsResetAfterDhcpConfiguration() {
        // First simulate getting an DHCP failure n-1 times.
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_1, TEST_DHCP_FAILURE,
                NUM_FAILURES_TO_BLOCKLIST - 1);

        // Verify that a dhcp provisioning success event will clear appropirate failure counts.
        mWifiBlocklistMonitor.handleDhcpProvisioningSuccess(TEST_BSSID_1, TEST_SSID_1);
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_1, TEST_DHCP_FAILURE,
                NUM_FAILURES_TO_BLOCKLIST - 1);

        // Verify we have not blocklisted anything yet because the failure count was cleared.
        assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());

        // Verify that TEST_BSSID_1 is added to blocklist after 1 more failure.
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_1, TEST_DHCP_FAILURE, 1);
        assertTrue(mWifiBlocklistMonitor.updateAndGetBssidBlocklist().contains(TEST_BSSID_1));
    }

    /**
     * Verify that handleBssidConnectionSuccess resets appropriate blocklist streak counts, and
     * notifies WifiScorecard of the successful connection.
     */
    @Test
    public void testNetworkConnectionResetsBlocklistStreak() {
        when(mClock.getWallClockMillis()).thenReturn(ABNORMAL_DISCONNECT_RESET_TIME_MS + 1);
        mWifiBlocklistMonitor.handleBssidConnectionSuccess(TEST_BSSID_1, TEST_SSID_1);
        verify(mWifiScoreCard).resetBssidBlocklistStreak(TEST_SSID_1, TEST_BSSID_1,
                WifiBlocklistMonitor.REASON_AP_UNABLE_TO_HANDLE_NEW_STA);
        verify(mWifiScoreCard).resetBssidBlocklistStreak(TEST_SSID_1, TEST_BSSID_1,
                WifiBlocklistMonitor.REASON_WRONG_PASSWORD);
        verify(mWifiScoreCard).resetBssidBlocklistStreak(TEST_SSID_1, TEST_BSSID_1,
                WifiBlocklistMonitor.REASON_EAP_FAILURE);
        verify(mWifiScoreCard).resetBssidBlocklistStreak(TEST_SSID_1, TEST_BSSID_1,
                WifiBlocklistMonitor.REASON_ASSOCIATION_REJECTION);
        verify(mWifiScoreCard).resetBssidBlocklistStreak(TEST_SSID_1, TEST_BSSID_1,
                WifiBlocklistMonitor.REASON_ASSOCIATION_TIMEOUT);
        verify(mWifiScoreCard).resetBssidBlocklistStreak(TEST_SSID_1, TEST_BSSID_1,
                WifiBlocklistMonitor.REASON_AUTHENTICATION_FAILURE);
        verify(mWifiScoreCard).setBssidConnectionTimestampMs(TEST_SSID_1, TEST_BSSID_1,
                ABNORMAL_DISCONNECT_RESET_TIME_MS + 1);
        verify(mWifiScoreCard).resetBssidBlocklistStreak(TEST_SSID_1, TEST_BSSID_1,
                WifiBlocklistMonitor.REASON_ABNORMAL_DISCONNECT);
        verify(mWifiScoreCard).resetBssidBlocklistStreak(TEST_SSID_1, TEST_BSSID_1,
                WifiBlocklistMonitor.REASON_FRAMEWORK_DISCONNECT_CONNECTED_SCORE);
        verify(mWifiScoreCard).resetBssidBlocklistStreak(TEST_SSID_1, TEST_BSSID_1,
                WifiBlocklistMonitor.REASON_NONLOCAL_DISCONNECT_CONNECTING);
    }

    /**
     * Verify that the abnormal disconnect streak is not reset if insufficient time has passed.
     */
    @Test
    public void testNetworkConnectionNotResetAbnormalDisconnectStreak() {
        when(mClock.getWallClockMillis()).thenReturn(ABNORMAL_DISCONNECT_RESET_TIME_MS);
        mWifiBlocklistMonitor.handleBssidConnectionSuccess(TEST_BSSID_1, TEST_SSID_1);
        verify(mWifiScoreCard).setBssidConnectionTimestampMs(TEST_SSID_1, TEST_BSSID_1,
                ABNORMAL_DISCONNECT_RESET_TIME_MS);
        verify(mWifiScoreCard, never()).resetBssidBlocklistStreak(TEST_SSID_1, TEST_BSSID_1,
                WifiBlocklistMonitor.REASON_ABNORMAL_DISCONNECT);
    }

    /**
     * Verify that the streak count for REASON_FRAMEWORK_DISCONNECT_CONNECTED_SCORE is not reset
     * if insufficient time has passed.
     */
    @Test
    public void testNetworkConnectionNotResetConnectedScoreStreak() {
        when(mClock.getWallClockMillis()).thenReturn(ABNORMAL_DISCONNECT_RESET_TIME_MS);
        mWifiBlocklistMonitor.handleBssidConnectionSuccess(TEST_BSSID_1, TEST_SSID_1);
        verify(mWifiScoreCard).setBssidConnectionTimestampMs(TEST_SSID_1, TEST_BSSID_1,
                ABNORMAL_DISCONNECT_RESET_TIME_MS);
        verify(mWifiScoreCard, never()).resetBssidBlocklistStreak(TEST_SSID_1, TEST_BSSID_1,
                WifiBlocklistMonitor.REASON_FRAMEWORK_DISCONNECT_CONNECTED_SCORE);
    }

    /**
     * Verify that handleDhcpProvisioningSuccess resets appropriate blocklist streak counts.
     */
    @Test
    public void testDhcpProvisioningResetsBlocklistStreak() {
        mWifiBlocklistMonitor.handleDhcpProvisioningSuccess(TEST_BSSID_1, TEST_SSID_1);
        verify(mWifiScoreCard).resetBssidBlocklistStreak(TEST_SSID_1, TEST_BSSID_1,
                WifiBlocklistMonitor.REASON_DHCP_FAILURE);
    }

    /**
     * Verify that handleNetworkValidationSuccess resets appropriate blocklist streak counts
     * and removes the BSSID from blocklist.
     */
    @Test
    public void testNetworkValidationResetsBlocklistStreak() {
        verifyAddTestBssidToBlocklist();
        mWifiBlocklistMonitor.handleNetworkValidationSuccess(TEST_BSSID_1, TEST_SSID_1);
        verify(mWifiScoreCard).resetBssidBlocklistStreak(TEST_SSID_1, TEST_BSSID_1,
                WifiBlocklistMonitor.REASON_NETWORK_VALIDATION_FAILURE);
        assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());
    }

    /**
     * Verify that L3 failure counts are not affected when L2 failure counts are reset.
     */
    @Test
    public void testL3FailureCountIsNotResetByConnectionSuccess() {
        // First simulate getting an L3 failure n-1 times.
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_1, TEST_DHCP_FAILURE,
                NUM_FAILURES_TO_BLOCKLIST - 1);
        assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());

        // Verify that the failure counter is not cleared by |handleBssidConnectionSuccess|.
        mWifiBlocklistMonitor.handleBssidConnectionSuccess(TEST_BSSID_1, TEST_SSID_1);
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_1, TEST_DHCP_FAILURE, 1);
        assertEquals(1, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());
    }

    /**
     * Verify that the blocklist streak is incremented after adding a BSSID to blocklist.
     * And then verify the blocklist streak is not reset by a regular timeout.
     */
    @Test
    public void testIncrementingBlocklistStreakCount() {
        for (Map.Entry<Integer, Integer> entry : BLOCK_REASON_TO_DISABLE_THRESHOLD_MAP.entrySet()) {
            int reason = entry.getKey();
            int threshold = entry.getValue();
            when(mClock.getWallClockMillis()).thenReturn(0L);
            handleBssidConnectionFailureMultipleTimes(TEST_BSSID_1, TEST_SSID_1, reason, threshold);

            // verify the BSSID is blocked
            assertEquals(1, mWifiBlocklistMonitor.updateAndGetNumBlockedBssidsForSsid(
                    TEST_SSID_1));

            // verify that the blocklist streak is incremented
            verify(mWifiScoreCard).incrementBssidBlocklistStreak(TEST_SSID_1, TEST_BSSID_1, reason);
            // verify WifiMetrics also increments the blocklist count.
            verify(mWifiMetrics).incrementBssidBlocklistCount(reason);

            // Verify that TEST_BSSID_1 is removed from the blocklist after the timeout duration.
            when(mClock.getWallClockMillis()).thenReturn(BASE_BLOCKLIST_DURATION + 1);
            assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());

            // But the blocklist streak count is not cleared
            verify(mWifiScoreCard, never()).resetBssidBlocklistStreak(TEST_SSID_1, TEST_BSSID_1,
                    reason);
        }
    }

    /**
     * Verify that when a failure signal is received for a BSSID with different SSID from before,
     * then the failure counts are reset.
     */
    @Test
    public void testFailureCountIsResetIfSsidChanges() {
        // First simulate getting a particular L2 failure n-1 times
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_1, TEST_L2_FAILURE,
                NUM_FAILURES_TO_BLOCKLIST - 1);

        // Verify that when the SSID changes, the failure counts are cleared.
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_1, TEST_SSID_2, TEST_L2_FAILURE,
                NUM_FAILURES_TO_BLOCKLIST - 1);

        // Verify we have not blocklisted anything yet because the failure count was cleared.
        assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());

        // Verify that TEST_BSSID_1 is added to blocklist after 1 more failure.
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_1, TEST_SSID_2, TEST_L2_FAILURE, 1);
        assertTrue(mWifiBlocklistMonitor.updateAndGetBssidBlocklist().contains(TEST_BSSID_1));
    }

    /**
     * Verify that a BSSID is not added to blocklist as long as
     * mWifiLastResortWatchdog.shouldIgnoreBssidUpdate is returning true, for failure reasons
     * that are also being tracked by the watchdog.
     */
    @Test
    public void testWatchdogIsGivenChanceToTrigger() {
        // Verify that |shouldIgnoreBssidUpdate| can prevent a BSSID from being added to blocklist.
        when(mWifiLastResortWatchdog.shouldIgnoreBssidUpdate(anyString())).thenReturn(true);
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_1, TEST_L2_FAILURE,
                NUM_FAILURES_TO_BLOCKLIST * 2);
        assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());

        // Verify that after watchdog is okay with blocking a BSSID, it gets blocked after 1
        // more failure.
        when(mWifiLastResortWatchdog.shouldIgnoreBssidUpdate(anyString())).thenReturn(false);
        handleBssidConnectionFailureMultipleTimes(TEST_BSSID_1, TEST_L2_FAILURE, 1);
        assertTrue(mWifiBlocklistMonitor.updateAndGetBssidBlocklist().contains(TEST_BSSID_1));
    }

    /**
     * Verify that non device related errors, and errors that are not monitored by the watchdog
     * bypasses the watchdog check.
     */
    @Test
    public void testUnrelatedErrorsBypassWatchdogCheck() {
        when(mWifiLastResortWatchdog.shouldIgnoreBssidUpdate(anyString())).thenReturn(true);
        verifyAddTestBssidToBlocklist();
        verify(mWifiLastResortWatchdog, never()).shouldIgnoreBssidUpdate(anyString());
    }

    /**
     * Verify that we are correctly filtering by SSID when sending a blocklist down to firmware.
     */
    @Test
    public void testSendBlocklistToFirmwareFilterBySsid() {
        verifyAddMultipleBssidsToBlocklist();

        // Verify we are sending 2 BSSIDs down to the firmware for SSID_1.
        ArrayList<String> blocklist1 = new ArrayList<>();
        blocklist1.add(TEST_BSSID_2);
        blocklist1.add(TEST_BSSID_1);
        mWifiBlocklistMonitor.updateFirmwareRoamingConfiguration(Set.of(TEST_SSID_1));
        verify(mWifiConnectivityHelper).setFirmwareRoamingConfiguration(eq(blocklist1),
                eq(new ArrayList<>()));

        // Verify we are sending 1 BSSID down to the firmware for SSID_2.
        ArrayList<String> blocklist2 = new ArrayList<>();
        blocklist2.add(TEST_BSSID_3);
        mWifiBlocklistMonitor.updateFirmwareRoamingConfiguration(Set.of(TEST_SSID_2));
        verify(mWifiConnectivityHelper).setFirmwareRoamingConfiguration(eq(blocklist2),
                eq(new ArrayList<>()));

        // Verify we are not sending any BSSIDs down to the firmware since there does not
        // exists any BSSIDs for TEST_SSID_3 in the blocklist.
        mWifiBlocklistMonitor.updateFirmwareRoamingConfiguration(Set.of(TEST_SSID_3));
        verify(mWifiConnectivityHelper).setFirmwareRoamingConfiguration(eq(new ArrayList<>()),
                eq(new ArrayList<>()));
    }

    /**
     * Verify that when sending the blocklist down to firmware, the list is sorted by latest
     * end time first.
     * Also verify that when there are more blocklisted BSSIDs than the allowed limit by the
     * firmware, the list sent down is trimmed.
     */
    @Test
    public void testMostRecentBlocklistEntriesAreSentToFirmware() {
        // Add BSSIDs to blocklist
        String bssid = "0a:08:5c:67:89:0";
        for (int i = 0; i < 10; i++) {
            when(mClock.getWallClockMillis()).thenReturn((long) i);
            mWifiBlocklistMonitor.handleBssidConnectionFailure(bssid + i,
                    TEST_SSID_1, WifiBlocklistMonitor.REASON_AP_UNABLE_TO_HANDLE_NEW_STA,
                    TEST_GOOD_RSSI);

            // This will build a List of BSSIDs starting from the latest added ones that is at
            // most size |TEST_NUM_MAX_FIRMWARE_SUPPORT_BSSIDS|.
            // Then verify that the blocklist is sent down in this sorted order.
            ArrayList<String> blocklist = new ArrayList<>();
            for (int j = i; j > i - TEST_NUM_MAX_FIRMWARE_SUPPORT_BSSIDS; j--) {
                if (j < 0) {
                    break;
                }
                blocklist.add(bssid + j);
            }
            mWifiBlocklistMonitor.updateFirmwareRoamingConfiguration(Set.of(TEST_SSID_1));
            verify(mWifiConnectivityHelper).setFirmwareRoamingConfiguration(eq(blocklist),
                    eq(new ArrayList<>()));
        }
        assertEquals(10, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());
    }

    /**
     * Verifies that when firmware roaming is disabled, the blocklist does not get plumbed to
     * hardware, but the blocklist should still accessible by the framework.
     */
    @Test
    public void testFirmwareRoamingDisabled() {
        when(mWifiConnectivityHelper.isFirmwareRoamingSupported()).thenReturn(false);
        verifyAddTestBssidToBlocklist();

        mWifiBlocklistMonitor.updateFirmwareRoamingConfiguration(Set.of(TEST_SSID_1));
        verify(mWifiConnectivityHelper, never()).setFirmwareRoamingConfiguration(any(), any());
    }

    /**
     * Verify that clearBssidBlocklist resets internal state.
     */
    @Test
    public void testClearBssidBlocklist() {
        verifyAddTestBssidToBlocklist();
        mWifiBlocklistMonitor.clearBssidBlocklist();
        assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());

    }

    /**
     * Verify that the BssidBlocklistMonitorLogger is capped.
     */
    @Test
    public void testBssidBlocklistMonitorLoggerSize() {
        int loggerMaxSize = 60;
        for (int i = 0; i < loggerMaxSize; i++) {
            verifyAddTestBssidToBlocklist();
            mWifiBlocklistMonitor.clearBssidBlocklist();
            assertEquals(i + 1, mWifiBlocklistMonitor.getBssidBlocklistMonitorLoggerSize());
        }
        verifyAddTestBssidToBlocklist();
        mWifiBlocklistMonitor.clearBssidBlocklist();
        assertEquals(loggerMaxSize,
                mWifiBlocklistMonitor.getBssidBlocklistMonitorLoggerSize());
    }

    /**
     * Verify that clearBssidBlocklistForSsid removes all BSSIDs for that network from the
     * blocklist.
     */
    @Test
    public void testClearBssidBlocklistForSsid() {
        verifyAddMultipleBssidsToBlocklist();

        // Clear the blocklist for SSID 1.
        mWifiBlocklistMonitor.clearBssidBlocklistForSsid(TEST_SSID_1);

        // Verify that the blocklist is deleted for SSID 1 and the BSSID for SSID 2 still remains.
        Set<String> bssidList = mWifiBlocklistMonitor.updateAndGetBssidBlocklist();
        assertEquals(1, bssidList.size());
        assertTrue(bssidList.contains(TEST_BSSID_3));
        verify(mWifiScoreCard, never()).resetBssidBlocklistStreakForSsid(TEST_SSID_1);
    }

    /**
     * Verify that handleNetworkRemoved removes all BSSIDs for that network from the blocklist
     * and also reset the blocklist streak count from WifiScoreCard.
     */
    @Test
    public void testHandleNetworkRemovedResetsState() {
        verifyAddMultipleBssidsToBlocklist();

        // Clear the blocklist for SSID 1.
        mWifiBlocklistMonitor.handleNetworkRemoved(TEST_SSID_1);

        // Verify that the blocklist is deleted for SSID 1 and the BSSID for SSID 2 still remains.
        Set<String> bssidList = mWifiBlocklistMonitor.updateAndGetBssidBlocklist();
        assertEquals(1, bssidList.size());
        assertTrue(bssidList.contains(TEST_BSSID_3));
        verify(mWifiScoreCard).resetBssidBlocklistStreakForSsid(TEST_SSID_1);
    }

    /**
     * Verify that |blockBssidForDurationMs| adds a BSSID to blocklist for the specified duration.
     */
    @Test
    public void testBlockBssidForDurationMs() {
        when(mClock.getWallClockMillis()).thenReturn(0L);
        long testDuration = 5500L;
        mWifiBlocklistMonitor.blockBssidForDurationMs(TEST_BSSID_1, TEST_SSID_1, testDuration,
                TEST_FRAMEWORK_BLOCK_REASON, TEST_GOOD_RSSI);
        assertEquals(1, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());

        // Verify that the BSSID is removed from blocklist by clearBssidBlocklistForSsid
        mWifiBlocklistMonitor.clearBssidBlocklistForSsid(TEST_SSID_1);
        assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());

        // Add the BSSID to blocklist again.
        mWifiBlocklistMonitor.blockBssidForDurationMs(TEST_BSSID_1, TEST_SSID_1, testDuration,
                TEST_FRAMEWORK_BLOCK_REASON, TEST_GOOD_RSSI);
        assertEquals(1, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());

        // Verify that the BSSID is removed from blocklist once the specified duration is over.
        when(mClock.getWallClockMillis()).thenReturn(testDuration + 1);
        assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());
    }

    /**
     * Verify that invalid inputs are handled and result in no-op.
     */
    @Test
    public void testBlockBssidForDurationMsInvalidInputs() {
        // test invalid BSSID
        when(mClock.getWallClockMillis()).thenReturn(0L);
        long testDuration = 5500L;
        mWifiBlocklistMonitor.blockBssidForDurationMs(null, TEST_SSID_1, testDuration,
                TEST_FRAMEWORK_BLOCK_REASON, TEST_GOOD_RSSI);
        assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());

        // test invalid SSID
        mWifiBlocklistMonitor.blockBssidForDurationMs(TEST_BSSID_1, null, testDuration,
                TEST_FRAMEWORK_BLOCK_REASON, TEST_GOOD_RSSI);
        assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());

        // test invalid duration
        mWifiBlocklistMonitor.blockBssidForDurationMs(TEST_BSSID_1, TEST_SSID_1, -1,
                TEST_FRAMEWORK_BLOCK_REASON, TEST_GOOD_RSSI);
        assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());
    }

    private void simulateRssiUpdate(String bssid, int rssi) {
        ScanDetail scanDetail = mock(ScanDetail.class);
        ScanResult scanResult = mock(ScanResult.class);
        scanResult.BSSID = bssid;
        scanResult.level = rssi;
        when(scanDetail.getScanResult()).thenReturn(scanResult);
        List<ScanDetail> scanDetails = new ArrayList<>();
        scanDetails.add(scanDetail);
        mWifiBlocklistMonitor.tryEnablingBlockedBssids(scanDetails);
    }

    /**
     * Verify that if the RSSI is low when the BSSID is blocked, a RSSI improvement will remove
     * the BSSID from blocklist.
     */
    @Test
    public void testUnblockBssidAfterRssiImproves() {
        when(mClock.getWallClockMillis()).thenReturn(0L);
        // verify TEST_BSSID_1 is blocked
        mWifiBlocklistMonitor.handleBssidConnectionFailure(
                TEST_BSSID_1, TEST_SSID_1, WifiBlocklistMonitor.REASON_EAP_FAILURE,
                TEST_SUFFICIENT_RSSI - MIN_RSSI_DIFF_TO_UNBLOCK_BSSID);
        assertTrue(mWifiBlocklistMonitor.updateAndGetBssidBlocklist().contains(TEST_BSSID_1));

        // verify the blocklist is not cleared when the rssi improvement is not large enough.
        simulateRssiUpdate(TEST_BSSID_1, TEST_SUFFICIENT_RSSI - 1);
        assertTrue(mWifiBlocklistMonitor.updateAndGetBssidBlocklist().contains(TEST_BSSID_1));

        // verify TEST_BSSID_1 is removed from the blocklist after RSSI improves
        simulateRssiUpdate(TEST_BSSID_1, TEST_SUFFICIENT_RSSI);
        assertEquals(0, mWifiBlocklistMonitor.updateAndGetBssidBlocklist().size());
    }

    /**
     * Verify that if the RSSI is already good when the BSSID is blocked, a RSSI improvement will
     * not remove the BSSID from blocklist.
     */
    @Test
    public void testBssidNotUnblockedIfRssiAlreadyGood() {
        when(mClock.getWallClockMillis()).thenReturn(0L);
        // verify TEST_BSSID_1 is blocked
        mWifiBlocklistMonitor.handleBssidConnectionFailure(
                TEST_BSSID_1, TEST_SSID_1, WifiBlocklistMonitor.REASON_EAP_FAILURE,
                TEST_SUFFICIENT_RSSI);
        assertTrue(mWifiBlocklistMonitor.updateAndGetBssidBlocklist().contains(TEST_BSSID_1));

        // verify TEST_BSSID_1 is not removed from blocklist
        simulateRssiUpdate(TEST_BSSID_1, TEST_GOOD_RSSI);
        assertTrue(mWifiBlocklistMonitor.updateAndGetBssidBlocklist().contains(TEST_BSSID_1));
    }

    /**
     * Verify that the logic to unblock BSSIDs after RSSI improvement does not apply for some
     * failure reasons.
     */
    @Test
    public void testRssiImprovementNotUnblockBssidForSomeFailureReasons() {
        when(mClock.getWallClockMillis()).thenReturn(0L);
        mWifiBlocklistMonitor.handleBssidConnectionFailure(
                TEST_BSSID_1, TEST_SSID_1, WifiBlocklistMonitor.REASON_WRONG_PASSWORD,
                TEST_SUFFICIENT_RSSI - MIN_RSSI_DIFF_TO_UNBLOCK_BSSID);
        assertTrue(mWifiBlocklistMonitor.updateAndGetBssidBlocklist().contains(TEST_BSSID_1));

        simulateRssiUpdate(TEST_BSSID_1, TEST_SUFFICIENT_RSSI);
        assertTrue(mWifiBlocklistMonitor.updateAndGetBssidBlocklist().contains(TEST_BSSID_1));
    }

    /**
     * Verify the failure reasons for all blocked BSSIDs are retrieved.
     */
    @Test
    public void testGetFailureReasonsForSsid() {
        // Null input should not crash
        mWifiBlocklistMonitor.getFailureReasonsForSsid(null).size();
        assertEquals(0, mWifiBlocklistMonitor.getFailureReasonsForSsid(TEST_SSID_1).size());
        mWifiBlocklistMonitor.blockBssidForDurationMs(TEST_BSSID_1, TEST_SSID_1, 1000,
                WifiBlocklistMonitor.REASON_AP_UNABLE_TO_HANDLE_NEW_STA, TEST_GOOD_RSSI);
        mWifiBlocklistMonitor.blockBssidForDurationMs(TEST_BSSID_2, TEST_SSID_1, 1000,
                WifiBlocklistMonitor.REASON_ABNORMAL_DISCONNECT, TEST_GOOD_RSSI);

        assertEquals(2, mWifiBlocklistMonitor.getFailureReasonsForSsid(TEST_SSID_1).size());
        assertTrue(mWifiBlocklistMonitor.getFailureReasonsForSsid(TEST_SSID_1)
                .contains(WifiBlocklistMonitor.REASON_AP_UNABLE_TO_HANDLE_NEW_STA));
        assertTrue(mWifiBlocklistMonitor.getFailureReasonsForSsid(TEST_SSID_1)
                .contains(WifiBlocklistMonitor.REASON_ABNORMAL_DISCONNECT));
    }

    /**
     * Verifies SSID blocklist consistent with Watchdog trigger.
     *
     * Expected behavior: A SSID won't gets blocklisted if there only single SSID
     * be observed and Watchdog trigger is activated.
     */
    @Test
    public void verifyConsistentWatchdogAndSsidBlocklist() {
        WifiConfiguration openNetwork = WifiConfigurationTestUtil.createOpenNetwork();
        when(mWifiLastResortWatchdog.shouldIgnoreSsidUpdate()).thenReturn(true);
        // First set it to enabled.
        assertTrue(mWifiBlocklistMonitor.updateNetworkSelectionStatus(openNetwork,
                NetworkSelectionStatus.DISABLED_NONE));
        assertEquals(NetworkSelectionStatus.NETWORK_SELECTION_ENABLED,
                openNetwork.getNetworkSelectionStatus().getNetworkSelectionStatus());

        int assocRejectReason = NetworkSelectionStatus.DISABLED_ASSOCIATION_REJECTION;
        int assocRejectThreshold =
                mWifiBlocklistMonitor.getNetworkSelectionDisableThreshold(assocRejectReason);
        for (int i = 1; i <= assocRejectThreshold; i++) {
            assertFalse(mWifiBlocklistMonitor.updateNetworkSelectionStatus(
                    openNetwork, assocRejectReason));
        }
        assertFalse(openNetwork.getNetworkSelectionStatus().isNetworkTemporaryDisabled());
    }

    /**
     * Verifies the update of network status using
     * {@link WifiConfigManager#updateNetworkSelectionStatus(int, int)}.
     */
    @Test
    public void testNetworkSelectionStatus() {
        WifiConfiguration openNetwork = WifiConfigurationTestUtil.createOpenNetwork();
        // First set it to enabled.
        verifyUpdateNetworkSelectionStatus(
                openNetwork, NetworkSelectionStatus.DISABLED_NONE, 0);

        // Now set it to temporarily disabled. The threshold for association rejection is 5, so
        // disable it 5 times to actually mark it temporarily disabled.
        int assocRejectReason = NetworkSelectionStatus.DISABLED_ASSOCIATION_REJECTION;
        int assocRejectThreshold =
                mWifiBlocklistMonitor.getNetworkSelectionDisableThreshold(assocRejectReason);
        for (int i = 1; i <= assocRejectThreshold; i++) {
            verifyUpdateNetworkSelectionStatus(openNetwork, assocRejectReason, i);
        }
        assertEquals(NetworkSelectionStatus.DISABLED_ASSOCIATION_REJECTION,
                openNetwork.getNetworkSelectionStatus().getNetworkSelectionDisableReason());
        // Now set it to permanently disabled.
        verifyUpdateNetworkSelectionStatus(
                openNetwork, NetworkSelectionStatus.DISABLED_BY_WIFI_MANAGER, 0);
        assertEquals(NetworkSelectionStatus.DISABLED_BY_WIFI_MANAGER,
                openNetwork.getNetworkSelectionStatus().getNetworkSelectionDisableReason());
        // Now set it back to enabled.
        verifyUpdateNetworkSelectionStatus(
                openNetwork, NetworkSelectionStatus.DISABLED_NONE, 0);
        assertEquals(NetworkSelectionStatus.DISABLED_NONE,
                openNetwork.getNetworkSelectionStatus().getNetworkSelectionDisableReason());
    }

    /**
     * Verifies the update of network status using
     * {@link WifiBlocklistMonitor#updateNetworkSelectionStatus(int, int)}.
     */
    @Test
    public void testNetworkSelectionStatusTemporarilyDisabledDueToNoInternet() {
        WifiConfiguration openNetwork = WifiConfigurationTestUtil.createOpenNetwork();
        // First set it to enabled.
        verifyUpdateNetworkSelectionStatus(
                openNetwork, NetworkSelectionStatus.DISABLED_NONE, 0);

        // Now set it to temporarily disabled. The threshold for no internet is 1, so
        // disable it once to actually mark it temporarily disabled.
        verifyUpdateNetworkSelectionStatus(openNetwork,
                NetworkSelectionStatus.DISABLED_NO_INTERNET_TEMPORARY, 1);
        // Now set it back to enabled.
        verifyUpdateNetworkSelectionStatus(
                openNetwork, NetworkSelectionStatus.DISABLED_NONE, 0);
    }

    /**
     * Verifies the update of network status using
     * {@link WifiConfigManager#updateNetworkSelectionStatus(int, int)} and ensures that
     * enabling a network clears out all the temporary disable counters.
     */
    @Test
    public void testNetworkSelectionStatusEnableClearsDisableCounters() {
        WifiConfiguration openNetwork = WifiConfigurationTestUtil.createOpenNetwork();
        // First set it to enabled.
        verifyUpdateNetworkSelectionStatus(
                openNetwork, NetworkSelectionStatus.DISABLED_NONE, 0);

        // Now set it to temporarily disabled 2 times for 2 different reasons.
        verifyUpdateNetworkSelectionStatus(
                openNetwork, NetworkSelectionStatus.DISABLED_ASSOCIATION_REJECTION, 1);
        verifyUpdateNetworkSelectionStatus(
                openNetwork, NetworkSelectionStatus.DISABLED_ASSOCIATION_REJECTION, 2);
        verifyUpdateNetworkSelectionStatus(
                openNetwork, NetworkSelectionStatus.DISABLED_AUTHENTICATION_FAILURE, 1);
        verifyUpdateNetworkSelectionStatus(
                openNetwork, NetworkSelectionStatus.DISABLED_AUTHENTICATION_FAILURE, 2);

        // Now set it back to enabled.
        verifyUpdateNetworkSelectionStatus(
                openNetwork, NetworkSelectionStatus.DISABLED_NONE, 0);

        // Ensure that the counters have all been reset now.
        verifyUpdateNetworkSelectionStatus(
                openNetwork, NetworkSelectionStatus.DISABLED_ASSOCIATION_REJECTION, 1);
        verifyUpdateNetworkSelectionStatus(
                openNetwork, NetworkSelectionStatus.DISABLED_AUTHENTICATION_FAILURE, 1);
    }

    /**
     * Verifies the network's selection status update.
     *
     * For temporarily disabled reasons, the method ensures that the status has changed only if
     * disable reason counter has exceeded the threshold.
     *
     * For permanently disabled/enabled reasons, the method ensures that the public status has
     * changed and the network change broadcast has been sent out.
     */
    private void verifyUpdateNetworkSelectionStatus(
            WifiConfiguration config, int reason, int temporaryDisableReasonCounter) {
        when(mClock.getElapsedSinceBootMillis())
                .thenReturn(TEST_ELAPSED_UPDATE_NETWORK_SELECTION_TIME_MILLIS);
        NetworkSelectionStatus currentStatus = config.getNetworkSelectionStatus();
        int currentDisableReason = currentStatus.getNetworkSelectionDisableReason();

        // First set the status to the provided reason.
        mWifiBlocklistMonitor.updateNetworkSelectionStatus(config, reason);

        NetworkSelectionStatus retrievedStatus = config.getNetworkSelectionStatus();
        int retrievedDisableReason = retrievedStatus.getNetworkSelectionDisableReason();
        long retrievedDisableTime = retrievedStatus.getDisableTime();
        int retrievedDisableReasonCounter = retrievedStatus.getDisableReasonCounter(reason);
        int disableReasonThreshold =
                mWifiBlocklistMonitor.getNetworkSelectionDisableThreshold(reason);

        if (reason == NetworkSelectionStatus.DISABLED_NONE) {
            assertEquals(reason, retrievedDisableReason);
            assertTrue(retrievedStatus.isNetworkEnabled());
            assertEquals(
                    NetworkSelectionStatus.INVALID_NETWORK_SELECTION_DISABLE_TIMESTAMP,
                    retrievedDisableTime);
            assertEquals(WifiConfiguration.Status.ENABLED, config.status);
        } else if (mWifiBlocklistMonitor.getNetworkSelectionDisableTimeoutMillis(reason)
                != DisableReasonInfo.PERMANENT_DISABLE_TIMEOUT) {
            // For temporarily disabled networks, we need to ensure that the current status remains
            // until the threshold is crossed.
            assertEquals(temporaryDisableReasonCounter, retrievedDisableReasonCounter);
            if (retrievedDisableReasonCounter < disableReasonThreshold) {
                assertEquals(currentDisableReason, retrievedDisableReason);
                assertEquals(
                        currentStatus.getNetworkSelectionStatus(),
                        retrievedStatus.getNetworkSelectionStatus());
            } else {
                assertEquals(reason, retrievedDisableReason);
                assertTrue(retrievedStatus.isNetworkTemporaryDisabled());
                assertEquals(
                        TEST_ELAPSED_UPDATE_NETWORK_SELECTION_TIME_MILLIS, retrievedDisableTime);
            }
        } else if (reason < NetworkSelectionStatus.NETWORK_SELECTION_DISABLED_MAX) {
            assertEquals(reason, retrievedDisableReason);
            assertTrue(retrievedStatus.isNetworkPermanentlyDisabled());
            assertEquals(
                    NetworkSelectionStatus.INVALID_NETWORK_SELECTION_DISABLE_TIMESTAMP,
                    retrievedDisableTime);
            assertEquals(WifiConfiguration.Status.DISABLED, config.status);
        }
    }

    /**
     * Verify the disable duration of a network exponentially increases with increasing
     * CNT_CONSECUTIVE_CONNECTION_FAILURE.
     */
    @Test
    public void testTryEnableNetworkExponentialBackoff() {
        WifiConfiguration openNetwork = WifiConfigurationTestUtil.createOpenNetwork();

        // Verify exponential backoff on the disable duration based on number of BSSIDs in the
        // BSSID blocklist
        int disableReason = NetworkSelectionStatus.DISABLED_ASSOCIATION_REJECTION;
        verifyDisableNetwork(openNetwork, disableReason);

        // expect exponential backoff 2 times
        when(mRecentStats.getCount(WifiScoreCard.CNT_CONSECUTIVE_CONNECTION_FAILURE)).thenReturn(
                WifiBlocklistMonitor.NUM_CONSECUTIVE_FAILURES_PER_NETWORK_EXP_BACKOFF + 2);
        verifyNetworkIsEnabledAfter(openNetwork,
                TEST_ELAPSED_UPDATE_NETWORK_SELECTION_TIME_MILLIS
                        + (mWifiBlocklistMonitor.getNetworkSelectionDisableTimeoutMillis(
                                disableReason) * 4));
    }

    /**
     * Verify the disable duration for a network is capped at
     * WIFI_CONFIG_MAX_DISABLE_DURATION_MILLIS.
     */
    @Test
    public void testTryEnableNetworkExponentialBackoffCapped() {
        WifiConfiguration openNetwork = WifiConfigurationTestUtil.createOpenNetwork();
        int disableReason = NetworkSelectionStatus.DISABLED_ASSOCIATION_REJECTION;
        verifyDisableNetwork(openNetwork, disableReason);

        // verify the exponential backoff is capped at WIFI_CONFIG_MAX_DISABLE_DURATION_MILLIS
        when(mRecentStats.getCount(WifiScoreCard.CNT_CONSECUTIVE_CONNECTION_FAILURE)).thenReturn(
                Integer.MAX_VALUE);
        verifyNetworkIsEnabledAfter(openNetwork,
                TEST_ELAPSED_UPDATE_NETWORK_SELECTION_TIME_MILLIS
                        + WifiBlocklistMonitor.WIFI_CONFIG_MAX_DISABLE_DURATION_MILLIS);
    }

    /**
     * Verifies that a network is disabled for the base duration even when there are no BSSIDs
     * blocked.
     */
    @Test
    public void testTryEnableNetworkNoBssidsInBlocklist() {
        WifiConfiguration openNetwork = WifiConfigurationTestUtil.createOpenNetwork();
        int disableReason = NetworkSelectionStatus.DISABLED_ASSOCIATION_REJECTION;

        verifyDisableNetwork(openNetwork, disableReason);
        verifyNetworkIsEnabledAfter(openNetwork,
                mWifiBlocklistMonitor.getNetworkSelectionDisableTimeoutMillis(disableReason)
                        + TEST_ELAPSED_UPDATE_NETWORK_SELECTION_TIME_MILLIS);
    }

    private void verifyDisableNetwork(WifiConfiguration config, int reason) {
        // First set it to enabled.
        verifyUpdateNetworkSelectionStatus(
                config, NetworkSelectionStatus.DISABLED_NONE, 0);

        int disableThreshold =
                mWifiBlocklistMonitor.getNetworkSelectionDisableThreshold(reason);
        for (int i = 1; i <= disableThreshold; i++) {
            verifyUpdateNetworkSelectionStatus(config, reason, i);
        }
        // verify WifiMetrics increments the blocklist count.
        verify(mWifiMetrics).incrementWificonfigurationBlocklistCount(reason);
    }

    private void verifyNetworkIsEnabledAfter(WifiConfiguration config, long timeout) {
        // try enabling this network 1 second earlier than the expected timeout. This
        // should fail and the status should remain temporarily disabled.
        when(mClock.getElapsedSinceBootMillis()).thenReturn(timeout - 1);
        assertFalse(mWifiBlocklistMonitor.shouldEnableNetwork(config));

        // Now advance time by the timeout for association rejection and ensure that the
        // network is now enabled.
        when(mClock.getElapsedSinceBootMillis()).thenReturn(timeout);
        assertTrue(mWifiBlocklistMonitor.shouldEnableNetwork(config));
    }

    /**
     * Verify that the parameters in DISABLE_REASON_INFOS are overlayable.
     */
    @Test
    public void testNetworkSelectionDisableReasonCustomConfigOverride() {
        int oldThreshold = NetworkSelectionStatus.DISABLE_REASON_INFOS
                .get(NetworkSelectionStatus.DISABLED_DHCP_FAILURE).mDisableThreshold;

        // Modify the overlay value and create WifiConfigManager again.
        int newThreshold = oldThreshold + 1;
        mResources.setInteger(
                R.integer.config_wifiDisableReasonDhcpFailureThreshold, newThreshold);
        mWifiBlocklistMonitor = new WifiBlocklistMonitor(mContext, mWifiConnectivityHelper,
                mWifiLastResortWatchdog, mClock, mLocalLog, mWifiScoreCard, mScoringParams,
                mWifiMetrics);

        // Verify that the threshold is updated in the copied version
        assertEquals(newThreshold, mWifiBlocklistMonitor.getNetworkSelectionDisableThreshold(
                NetworkSelectionStatus.DISABLED_DHCP_FAILURE));
        // Verify the original DISABLE_REASON_INFOS is unchanged
        assertEquals(oldThreshold, NetworkSelectionStatus.DISABLE_REASON_INFOS
                .get(NetworkSelectionStatus.DISABLED_DHCP_FAILURE).mDisableThreshold);
    }

    /**
     * Verify the correctness of the copied DISABLE_REASON_INFOS.
     */
    @Test
    public void testNetworkSelectionDisableReasonClone() {
        for (int i = 1; i < NetworkSelectionStatus.NETWORK_SELECTION_DISABLED_MAX; i++) {
            assertEquals("Disable threshold for reason=" + i + " should be equal",
                    NetworkSelectionStatus.DISABLE_REASON_INFOS.get(i).mDisableThreshold,
                    mWifiBlocklistMonitor.getNetworkSelectionDisableThreshold(i));
        }
    }
}
