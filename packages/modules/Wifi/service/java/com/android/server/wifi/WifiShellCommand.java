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

import static android.net.NetworkCapabilities.NET_CAPABILITY_INTERNET;
import static android.net.NetworkCapabilities.NET_CAPABILITY_OEM_PAID;
import static android.net.NetworkCapabilities.NET_CAPABILITY_OEM_PRIVATE;
import static android.net.NetworkCapabilities.NET_CAPABILITY_TRUSTED;
import static android.net.NetworkCapabilities.TRANSPORT_WIFI;
import static android.net.wifi.WifiConfiguration.METERED_OVERRIDE_METERED;
import static android.net.wifi.WifiManager.WIFI_STATE_DISABLED;
import static android.net.wifi.WifiManager.WIFI_STATE_ENABLED;

import static com.android.server.wifi.SelfRecovery.REASON_API_CALL;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.net.ConnectivityManager;
import android.net.MacAddress;
import android.net.Network;
import android.net.NetworkCapabilities;
import android.net.NetworkRequest;
import android.net.wifi.IActionListener;
import android.net.wifi.IScoreUpdateObserver;
import android.net.wifi.ISoftApCallback;
import android.net.wifi.IWifiConnectedNetworkScorer;
import android.net.wifi.ScanResult;
import android.net.wifi.SoftApCapability;
import android.net.wifi.SoftApConfiguration;
import android.net.wifi.SoftApInfo;
import android.net.wifi.SupplicantState;
import android.net.wifi.WifiClient;
import android.net.wifi.WifiConfiguration;
import android.net.wifi.WifiConnectedSessionInfo;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.net.wifi.WifiNetworkSpecifier;
import android.net.wifi.WifiNetworkSuggestion;
import android.net.wifi.WifiScanner;
import android.net.wifi.WifiSsid;
import android.os.Binder;
import android.os.Process;
import android.os.RemoteException;
import android.os.SystemClock;
import android.telephony.Annotation;
import android.telephony.PhysicalChannelConfig;
import android.telephony.SubscriptionManager;
import android.telephony.TelephonyManager;
import android.text.TextUtils;
import android.util.Pair;

import androidx.annotation.NonNull;

import com.android.internal.annotations.VisibleForTesting;
import com.android.modules.utils.BasicShellCommandHandler;
import com.android.modules.utils.ParceledListSlice;
import com.android.modules.utils.build.SdkLevel;
import com.android.server.wifi.ClientMode.LinkProbeCallback;
import com.android.server.wifi.coex.CoexManager;
import com.android.server.wifi.coex.CoexUtils;
import com.android.server.wifi.hotspot2.NetworkDetail;
import com.android.server.wifi.util.ApConfigUtil;
import com.android.server.wifi.util.ArrayUtils;
import com.android.server.wifi.util.ScanResultUtil;

import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;
import java.util.stream.Collectors;

/**
 * Interprets and executes 'adb shell cmd wifi [args]'.
 *
 * To add new commands:
 * - onCommand: Add a case "<command>" execute. Return a 0
 *   if command executed successfully.
 * - onHelp: add a description string.
 *
 * Permissions: currently root permission is required for some commands. Others will
 * enforce the corresponding API permissions.
 */
public class WifiShellCommand extends BasicShellCommandHandler {
    @VisibleForTesting
    public static String SHELL_PACKAGE_NAME = "com.android.shell";

    // These don't require root access.
    // However, these do perform permission checks in the corresponding WifiService methods.
    private static final String[] NON_PRIVILEGED_COMMANDS = {
            "add-suggestion",
            "add-network",
            "connect-network",
            "forget-network",
            "get-country-code",
            "help",
            "-h",
            "is-verbose-logging",
            "list-scan-results",
            "list-networks",
            "list-suggestions",
            "remove-suggestion",
            "remove-all-suggestions",
            "reset-connected-score",
            "set-connected-score",
            "set-scan-always-available",
            "set-verbose-logging",
            "set-wifi-enabled",
            "start-scan",
            "start-softap",
            "status",
            "stop-softap",
    };

    private static final Map<String, Pair<NetworkRequest, ConnectivityManager.NetworkCallback>>
            sActiveRequests = new ConcurrentHashMap<>();

    private final ActiveModeWarden mActiveModeWarden;
    private final WifiGlobals mWifiGlobals;
    private final WifiLockManager mWifiLockManager;
    private final WifiNetworkSuggestionsManager mWifiNetworkSuggestionsManager;
    private final WifiConfigManager mWifiConfigManager;
    private final WifiNative mWifiNative;
    private final CoexManager mCoexManager;
    private final WifiCountryCode mWifiCountryCode;
    private final WifiLastResortWatchdog mWifiLastResortWatchdog;
    private final WifiServiceImpl mWifiService;
    private final Context mContext;
    private final ConnectivityManager mConnectivityManager;
    private final WifiCarrierInfoManager mWifiCarrierInfoManager;
    private final WifiNetworkFactory mWifiNetworkFactory;
    private final SelfRecovery mSelfRecovery;
    private final WifiThreadRunner mWifiThreadRunner;
    private final WifiApConfigStore mWifiApConfigStore;
    private int mSapState = WifiManager.WIFI_STATE_UNKNOWN;
    private final ScanRequestProxy mScanRequestProxy;

    /**
     * Used for shell command testing of scorer.
     */
    public static class WifiScorer extends IWifiConnectedNetworkScorer.Stub {
        private final WifiServiceImpl mWifiService;
        private final CountDownLatch mCountDownLatch;
        private Integer mSessionId;
        private IScoreUpdateObserver mScoreUpdateObserver;

        public WifiScorer(WifiServiceImpl wifiService, CountDownLatch countDownLatch) {
            mWifiService = wifiService;
            mCountDownLatch  = countDownLatch;
        }

        @Override
        public void onStart(WifiConnectedSessionInfo sessionInfo) {
            mSessionId = sessionInfo.getSessionId();
            mCountDownLatch.countDown();
        }
        @Override
        public void onStop(int sessionId) {
            // clear the external scorer on disconnect.
            mWifiService.clearWifiConnectedNetworkScorer();
        }
        @Override
        public void onSetScoreUpdateObserver(IScoreUpdateObserver observerImpl) {
            mScoreUpdateObserver = observerImpl;
            mCountDownLatch.countDown();
        }

        public Integer getSessionId() {
            return mSessionId;
        }

        public IScoreUpdateObserver getScoreUpdateObserver() {
            return mScoreUpdateObserver;
        }
    }

    WifiShellCommand(WifiInjector wifiInjector, WifiServiceImpl wifiService, Context context,
            WifiGlobals wifiGlobals, WifiThreadRunner wifiThreadRunner) {
        mWifiGlobals = wifiGlobals;
        mWifiThreadRunner = wifiThreadRunner;
        mActiveModeWarden = wifiInjector.getActiveModeWarden();
        mWifiLockManager = wifiInjector.getWifiLockManager();
        mWifiNetworkSuggestionsManager = wifiInjector.getWifiNetworkSuggestionsManager();
        mWifiConfigManager = wifiInjector.getWifiConfigManager();
        mWifiNative = wifiInjector.getWifiNative();
        mCoexManager = wifiInjector.getCoexManager();
        mWifiCountryCode = wifiInjector.getWifiCountryCode();
        mWifiLastResortWatchdog = wifiInjector.getWifiLastResortWatchdog();
        mWifiService = wifiService;
        mContext = context;
        mConnectivityManager = context.getSystemService(ConnectivityManager.class);
        mWifiCarrierInfoManager = wifiInjector.getWifiCarrierInfoManager();
        mWifiNetworkFactory = wifiInjector.getWifiNetworkFactory();
        mSelfRecovery = wifiInjector.getSelfRecovery();
        mWifiApConfigStore = wifiInjector.getWifiApConfigStore();
        mScanRequestProxy = wifiInjector.getScanRequestProxy();
    }

    @Override
    public int onCommand(String cmd) {
        // Treat no command as help command.
        if (cmd == null || cmd.equals("")) {
            cmd = "help";
        }
        // Explicit exclusion from root permission
        if (ArrayUtils.indexOf(NON_PRIVILEGED_COMMANDS, cmd) == -1) {
            final int uid = Binder.getCallingUid();
            if (uid != Process.ROOT_UID) {
                throw new SecurityException(
                        "Uid " + uid + " does not have access to " + cmd + " wifi command "
                                + "(or such command doesn't exist)");
            }
        }

        final PrintWriter pw = getOutPrintWriter();
        try {
            switch (cmd) {
                case "set-ipreach-disconnect": {
                    boolean enabled = getNextArgRequiredTrueOrFalse("enabled", "disabled");
                    mWifiGlobals.setIpReachabilityDisconnectEnabled(enabled);
                    return 0;
                }
                case "get-ipreach-disconnect":
                    pw.println("IPREACH_DISCONNECT state is "
                            + mWifiGlobals.getIpReachabilityDisconnectEnabled());
                    return 0;
                case "set-poll-rssi-interval-msecs":
                    int newPollIntervalMsecs;
                    try {
                        newPollIntervalMsecs = Integer.parseInt(getNextArgRequired());
                    } catch (NumberFormatException e) {
                        pw.println(
                                "Invalid argument to 'set-poll-rssi-interval-msecs' "
                                        + "- must be a positive integer");
                        return -1;
                    }

                    if (newPollIntervalMsecs < 1) {
                        pw.println(
                                "Invalid argument to 'set-poll-rssi-interval-msecs' "
                                        + "- must be a positive integer");
                        return -1;
                    }

                    mWifiGlobals.setPollRssiIntervalMillis(newPollIntervalMsecs);
                    return 0;
                case "get-poll-rssi-interval-msecs":
                    pw.println("WifiGlobals.getPollRssiIntervalMillis() = "
                            + mWifiGlobals.getPollRssiIntervalMillis());
                    return 0;
                case "force-hi-perf-mode": {
                    boolean enabled = getNextArgRequiredTrueOrFalse("enabled", "disabled");
                    if (!mWifiLockManager.forceHiPerfMode(enabled)) {
                        pw.println("Command execution failed");
                    }
                    return 0;
                }
                case "force-low-latency-mode": {
                    boolean enabled = getNextArgRequiredTrueOrFalse("enabled", "disabled");
                    if (!mWifiLockManager.forceLowLatencyMode(enabled)) {
                        pw.println("Command execution failed");
                    }
                    return 0;
                }
                case "network-suggestions-set-user-approved": {
                    String packageName = getNextArgRequired();
                    boolean approved = getNextArgRequiredTrueOrFalse("yes", "no");
                    mWifiNetworkSuggestionsManager.setHasUserApprovedForApp(approved,
                            Binder.getCallingUid(), packageName);
                    return 0;
                }
                case "network-suggestions-has-user-approved": {
                    String packageName = getNextArgRequired();
                    boolean hasUserApproved =
                            mWifiNetworkSuggestionsManager.hasUserApprovedForApp(packageName);
                    pw.println(hasUserApproved ? "yes" : "no");
                    return 0;
                }
                case "imsi-protection-exemption-set-user-approved-for-carrier": {
                    String arg1 = getNextArgRequired();
                    int carrierId = -1;
                    try {
                        carrierId = Integer.parseInt(arg1);
                    } catch (NumberFormatException e) {
                        pw.println("Invalid argument to "
                                + "'imsi-protection-exemption-set-user-approved-for-carrier' "
                                + "- carrierId must be an Integer");
                        return -1;
                    }
                    boolean approved = getNextArgRequiredTrueOrFalse("yes", "no");
                    mWifiCarrierInfoManager
                            .setHasUserApprovedImsiPrivacyExemptionForCarrier(approved, carrierId);
                    return 0;
                }
                case "imsi-protection-exemption-has-user-approved-for-carrier": {
                    String arg1 = getNextArgRequired();
                    int carrierId = -1;
                    try {
                        carrierId = Integer.parseInt(arg1);
                    } catch (NumberFormatException e) {
                        pw.println("Invalid argument to "
                                + "'imsi-protection-exemption-has-user-approved-for-carrier' "
                                + "- 'carrierId' must be an Integer");
                        return -1;
                    }
                    boolean hasUserApproved = mWifiCarrierInfoManager
                            .hasUserApprovedImsiPrivacyExemptionForCarrier(carrierId);
                    pw.println(hasUserApproved ? "yes" : "no");
                    return 0;
                }
                case "imsi-protection-exemption-clear-user-approved-for-carrier": {
                    String arg1 = getNextArgRequired();
                    int carrierId = -1;
                    try {
                        carrierId = Integer.parseInt(arg1);
                    } catch (NumberFormatException e) {
                        pw.println("Invalid argument to "
                                + "'imsi-protection-exemption-clear-user-approved-for-carrier' "
                                + "- 'carrierId' must be an Integer");
                        return -1;
                    }
                    mWifiCarrierInfoManager.clearImsiPrivacyExemptionForCarrier(carrierId);
                    return 0;
                }
                case "network-requests-remove-user-approved-access-points": {
                    String packageName = getNextArgRequired();
                    mWifiNetworkFactory.removeUserApprovedAccessPointsForApp(packageName);
                    return 0;
                }
                case "clear-user-disabled-networks": {
                    mWifiConfigManager.clearUserTemporarilyDisabledList();
                    return 0;
                }
                case "send-link-probe": {
                    return sendLinkProbe(pw);
                }
                case "force-softap-band": {
                    boolean forceBandEnabled = getNextArgRequiredTrueOrFalse("enabled", "disabled");
                    if (forceBandEnabled) {
                        String forcedBand = getNextArgRequired();
                        if (forcedBand.equals("2")) {
                            mWifiApConfigStore.enableForceSoftApBandOrChannel(
                                    SoftApConfiguration.BAND_2GHZ, 0);
                        } else if (forcedBand.equals("5")) {
                            mWifiApConfigStore.enableForceSoftApBandOrChannel(
                                    SoftApConfiguration.BAND_5GHZ, 0);
                        } else if (forcedBand.equals("6")) {
                            mWifiApConfigStore.enableForceSoftApBandOrChannel(
                                    SoftApConfiguration.BAND_6GHZ, 0);
                        } else {
                            pw.println("Invalid argument to 'force-softap-band enabled' "
                                    + "- must be a valid band integer (2|5|6)");
                            return -1;
                        }
                        return 0;
                    } else {
                        mWifiApConfigStore.disableForceSoftApBandOrChannel();
                        return 0;
                    }

                }
                case "force-softap-channel": {
                    boolean enabled = getNextArgRequiredTrueOrFalse("enabled", "disabled");
                    if (enabled) {
                        int apChannelMHz;
                        try {
                            apChannelMHz = Integer.parseInt(getNextArgRequired());
                        } catch (NumberFormatException e) {
                            pw.println("Invalid argument to 'force-softap-channel enabled' "
                                    + "- must be a positive integer");
                            return -1;
                        }
                        int apChannel = ScanResult.convertFrequencyMhzToChannelIfSupported(
                                apChannelMHz);
                        int band = ApConfigUtil.convertFrequencyToBand(apChannelMHz);
                        pw.println("channel: " + apChannel + " band: " + band);
                        if (apChannel == -1 || band == -1) {
                            pw.println("Invalid argument to 'force-softap-channel enabled' "
                                    + "- must be a valid WLAN channel");
                            return -1;
                        }
                        boolean isTemporarilyEnablingWifiNeeded = mWifiService.getWifiEnabledState()
                                != WIFI_STATE_ENABLED;
                        if (isTemporarilyEnablingWifiNeeded) {
                            waitForWifiEnabled(true);
                        }
                        // Following calls will fail if wifi is not enabled
                        boolean isValidChannel = isApChannelMHzValid(pw, apChannelMHz);
                        if (isTemporarilyEnablingWifiNeeded) {
                            waitForWifiEnabled(false);
                        }
                        if (!isValidChannel
                                || (band == SoftApConfiguration.BAND_5GHZ
                                && !mWifiService.is5GHzBandSupported())
                                || (band == SoftApConfiguration.BAND_6GHZ
                                && !mWifiService.is6GHzBandSupported())
                                || (band == SoftApConfiguration.BAND_60GHZ
                                && !mWifiService.is60GHzBandSupported())) {
                            pw.println("Invalid argument to 'force-softap-channel enabled' "
                                    + "- must be a valid WLAN channel"
                                    + " in a band supported by the device");
                            return -1;
                        }
                        mWifiApConfigStore.enableForceSoftApBandOrChannel(band, apChannel);
                        return 0;
                    } else {
                        mWifiApConfigStore.disableForceSoftApBandOrChannel();
                        return 0;
                    }
                }
                case "start-softap": {
                    CountDownLatch countDownLatch = new CountDownLatch(1);
                    ISoftApCallback.Stub softApCallback = new ISoftApCallback.Stub() {
                        @Override
                        public void onStateChanged(int state, int failureReason) {
                            pw.println("onStateChanged with state: " + state
                                    + " failure reason: " + failureReason);
                            mSapState = state;
                            if (state == WifiManager.WIFI_AP_STATE_ENABLED) {
                                pw.println(" SAP is enabled successfully");
                                // Skip countDown() and wait for onInfoChanged() which has
                                // the confirmed softAp channel information
                            } else if (state == WifiManager.WIFI_AP_STATE_DISABLED) {
                                pw.println(" SAP is disabled");
                            } else if (state == WifiManager.WIFI_AP_STATE_FAILED) {
                                pw.println(" SAP failed to start");
                                countDownLatch.countDown();
                            }
                        }

                        @Override
                        public void onConnectedClientsOrInfoChanged(Map<String, SoftApInfo> infos,
                                Map<String, List<WifiClient>> clients, boolean isBridged,
                                boolean isRegistration) {
                            if (mSapState == WifiManager.WIFI_AP_STATE_ENABLED) {
                                countDownLatch.countDown();
                            }
                        }

                        @Override
                        public void onCapabilityChanged(SoftApCapability capability) {
                            pw.println("onCapabilityChanged " + capability);
                        }

                        @Override
                        public void onBlockedClientConnecting(WifiClient client, int reason) {
                        }

                    };
                    mWifiService.registerSoftApCallback(softApCallback);
                    SoftApConfiguration config = buildSoftApConfiguration(pw);
                    if (!mWifiService.startTetheredHotspot(config, SHELL_PACKAGE_NAME)) {
                        pw.println("Soft AP failed to start. Please check config parameters");
                    }
                    // Wait for softap to start and complete callback
                    countDownLatch.await(3000, TimeUnit.MILLISECONDS);
                    mWifiService.unregisterSoftApCallback(softApCallback);
                    return 0;
                }
                case "stop-softap": {
                    if (mWifiService.stopSoftAp()) {
                        pw.println("Soft AP stopped successfully");
                    } else {
                        pw.println("Soft AP failed to stop");
                    }
                    return 0;
                }
                case "force-country-code": {
                    boolean enabled = getNextArgRequiredTrueOrFalse("enabled", "disabled");
                    if (enabled) {
                        String countryCode = getNextArgRequired();
                        if (!WifiCountryCode.isValid(countryCode)) {
                            pw.println("Invalid argument: Country code must be a 2-Character"
                                    + " alphanumeric code. But got countryCode " + countryCode
                                    + " instead");
                            return -1;
                        }
                        mWifiCountryCode.setOverrideCountryCode(countryCode);
                        return 0;
                    } else {
                        mWifiCountryCode.clearOverrideCountryCode();
                        return 0;
                    }
                }
                case "get-country-code": {
                    pw.println("Wifi Country Code = "
                            + mWifiCountryCode.getCountryCode());
                    return 0;
                }
                case "set-wifi-watchdog": {
                    boolean enabled = getNextArgRequiredTrueOrFalse("enabled", "disabled");
                    mWifiLastResortWatchdog.setWifiWatchdogFeature(enabled);
                    return 0;
                }
                case "get-wifi-watchdog": {
                    pw.println("wifi watchdog state is "
                            + mWifiLastResortWatchdog.getWifiWatchdogFeature());
                    return 0;
                }
                case "set-wifi-enabled": {
                    boolean enabled = getNextArgRequiredTrueOrFalse("enabled", "disabled");
                    mWifiService.setWifiEnabled(SHELL_PACKAGE_NAME, enabled);
                    return 0;
                }
                case "set-scan-always-available": {
                    boolean enabled = getNextArgRequiredTrueOrFalse("enabled", "disabled");
                    mWifiService.setScanAlwaysAvailable(enabled, SHELL_PACKAGE_NAME);
                    return 0;
                }
                case "get-softap-supported-features":
                    // This command is used for vts to check softap supported features.
                    if (ApConfigUtil.isAcsSupported(mContext)) {
                        pw.println("wifi_softap_acs_supported");
                    }
                    if (ApConfigUtil.isWpa3SaeSupported(mContext)) {
                        pw.println("wifi_softap_wpa3_sae_supported");
                    }
                    if ((mWifiService.getSupportedFeatures()
                            & WifiManager.WIFI_FEATURE_BRIDGED_AP)
                            == WifiManager.WIFI_FEATURE_BRIDGED_AP) {
                        pw.println("wifi_softap_bridged_ap_supported");
                    }
                    if ((mWifiService.getSupportedFeatures()
                            & WifiManager.WIFI_FEATURE_STA_BRIDGED_AP)
                            == WifiManager.WIFI_FEATURE_STA_BRIDGED_AP) {
                        pw.println("wifi_softap_bridged_ap_with_sta_supported");
                    }
                    return 0;
                case "settings-reset":
                    mWifiNative.stopFakingScanDetails();
                    mWifiNative.resetFakeScanDetails();
                    mWifiService.factoryReset(SHELL_PACKAGE_NAME);
                    return 0;
                case "list-scan-results":
                    List<ScanResult> scanResults =
                            mWifiService.getScanResults(SHELL_PACKAGE_NAME, null);
                    if (scanResults.isEmpty()) {
                        pw.println("No scan results");
                    } else {
                        ScanResultUtil.dumpScanResults(pw, scanResults,
                                SystemClock.elapsedRealtime());
                    }
                    return 0;
                case "start-scan":
                    mWifiService.startScan(SHELL_PACKAGE_NAME, null);
                    return 0;
                case "list-networks":
                    ParceledListSlice<WifiConfiguration> networks =
                            mWifiService.getConfiguredNetworks(SHELL_PACKAGE_NAME, null, false);
                    if (networks == null || networks.getList().isEmpty()) {
                        pw.println("No networks");
                    } else {
                        pw.println("Network Id      SSID                         Security type");
                        for (WifiConfiguration network : networks.getList()) {
                            String securityType = network.getSecurityParamsList().stream()
                                    .map(p -> WifiConfiguration.getSecurityTypeName(
                                                    p.getSecurityType())
                                            + (p.isAddedByAutoUpgrade() ? "^" : ""))
                                    .collect(Collectors.joining("/"));
                            pw.println(String.format("%-12d %-32s %-4s",
                                    network.networkId, WifiInfo.sanitizeSsid(network.SSID),
                                    securityType));
                        }
                    }
                    return 0;
                case "connect-network": {
                    CountDownLatch countDownLatch = new CountDownLatch(1);
                    IActionListener.Stub actionListener = new IActionListener.Stub() {
                        @Override
                        public void onSuccess() throws RemoteException {
                            pw.println("Connection initiated ");
                            countDownLatch.countDown();
                        }

                        @Override
                        public void onFailure(int i) throws RemoteException {
                            pw.println("Connection failed");
                            countDownLatch.countDown();
                        }
                    };
                    WifiConfiguration config = buildWifiConfiguration(pw);
                    mWifiService.connect(config, -1, actionListener);
                    // wait for status.
                    countDownLatch.await(500, TimeUnit.MILLISECONDS);
                    setAutoJoin(pw, config.SSID, config.allowAutojoin);
                    return 0;
                }
                case "add-network": {
                    CountDownLatch countDownLatch = new CountDownLatch(1);
                    IActionListener.Stub actionListener = new IActionListener.Stub() {
                        @Override
                        public void onSuccess() throws RemoteException {
                            pw.println("Save successful");
                            countDownLatch.countDown();
                        }

                        @Override
                        public void onFailure(int i) throws RemoteException {
                            pw.println("Save failed");
                            countDownLatch.countDown();
                        }
                    };
                    WifiConfiguration config = buildWifiConfiguration(pw);
                    mWifiService.save(config, actionListener);
                    // wait for status.
                    countDownLatch.await(500, TimeUnit.MILLISECONDS);
                    setAutoJoin(pw, config.SSID, config.allowAutojoin);
                    return 0;
                }
                case "forget-network": {
                    String networkId = getNextArgRequired();
                    CountDownLatch countDownLatch = new CountDownLatch(1);
                    IActionListener.Stub actionListener = new IActionListener.Stub() {
                        @Override
                        public void onSuccess() throws RemoteException {
                            pw.println("Forget successful");
                            countDownLatch.countDown();
                        }

                        @Override
                        public void onFailure(int i) throws RemoteException {
                            pw.println("Forget failed");
                            countDownLatch.countDown();
                        }
                    };
                    mWifiService.forget(Integer.parseInt(networkId), actionListener);
                    // wait for status.
                    countDownLatch.await(500, TimeUnit.MILLISECONDS);
                    return 0;
                }
                case "pmksa-flush": {
                    String networkId = getNextArgRequired();
                    int netId = Integer.parseInt(networkId);
                    WifiConfiguration config = mWifiConfigManager.getConfiguredNetwork(netId);
                    if (config == null) {
                        pw.println("No Wifi config corresponding to networkId: " + netId);
                        return -1;
                    }
                    mWifiNative.removeNetworkCachedData(netId);
                    return 0;
                }
                case "status":
                    printStatus(pw);
                    return 0;
                case "set-verbose-logging": {
                    boolean enabled = getNextArgRequiredTrueOrFalse("enabled", "disabled");
                    mWifiService.enableVerboseLogging(enabled ? 1 : 0);
                    return 0;
                }
                case "is-verbose-logging": {
                    int enabled = mWifiService.getVerboseLoggingLevel();
                    pw.println(enabled > 0 ? "enabled" : "disabled");
                    return 0;
                }
                case "start-restricting-auto-join-to-subscription-id": {
                    if (!SdkLevel.isAtLeastS()) {
                        pw.println("This feature is only supported on SdkLevel S or later.");
                        return -1;
                    }
                    int subId = Integer.parseInt(getNextArgRequired());
                    mWifiService.startRestrictingAutoJoinToSubscriptionId(subId);
                    return 0;
                }
                case "stop-restricting-auto-join-to-subscription-id": {
                    if (!SdkLevel.isAtLeastS()) {
                        pw.println("This feature is only supported on SdkLevel S or later.");
                        return -1;
                    }
                    mWifiService.stopRestrictingAutoJoinToSubscriptionId();
                    return 0;
                }
                case "add-suggestion": {
                    WifiNetworkSuggestion suggestion = buildSuggestion(pw);
                    if (suggestion  == null) {
                        pw.println("Invalid network suggestion parameter");
                        return -1;
                    }
                    int errorCode = mWifiService.addNetworkSuggestions(
                            Arrays.asList(suggestion), SHELL_PACKAGE_NAME, null);
                    if (errorCode != WifiManager.STATUS_NETWORK_SUGGESTIONS_SUCCESS) {
                        pw.println("Add network suggestion failed with error code: " + errorCode);
                        return -1;
                    }
                    // untrusted/oem-paid networks need a corresponding NetworkRequest.
                    if (suggestion.isUntrusted()
                            || (SdkLevel.isAtLeastS()
                            && (suggestion.isOemPaid() || suggestion.isOemPrivate()))) {
                        NetworkRequest.Builder networkRequestBuilder =
                                new NetworkRequest.Builder()
                                        .addTransportType(TRANSPORT_WIFI);
                        if (suggestion.isUntrusted()) {
                            networkRequestBuilder.removeCapability(NET_CAPABILITY_TRUSTED);
                        }
                        if (SdkLevel.isAtLeastS()) {
                            if (suggestion.isOemPaid()) {
                                networkRequestBuilder.addCapability(NET_CAPABILITY_OEM_PAID);
                            }
                            if (suggestion.isOemPrivate()) {
                                networkRequestBuilder.addCapability(NET_CAPABILITY_OEM_PRIVATE);
                            }
                        }
                        NetworkRequest networkRequest = networkRequestBuilder.build();
                        ConnectivityManager.NetworkCallback networkCallback =
                                new ConnectivityManager.NetworkCallback();
                        pw.println("Adding request: " + networkRequest);
                        mConnectivityManager.requestNetwork(networkRequest, networkCallback);
                        sActiveRequests.put(
                                suggestion.getSsid(), Pair.create(networkRequest, networkCallback));
                    }
                    return 0;
                }
                case "remove-suggestion": {
                    String ssid = getNextArgRequired();
                    List<WifiNetworkSuggestion> suggestions =
                            mWifiService.getNetworkSuggestions(SHELL_PACKAGE_NAME);
                    WifiNetworkSuggestion suggestion = suggestions.stream()
                            .filter(s -> s.getSsid().equals(ssid))
                            .findAny()
                            .orElse(null);
                    if (suggestion == null) {
                        pw.println("No matching suggestion to remove");
                        return -1;
                    }
                    mWifiService.removeNetworkSuggestions(
                            Arrays.asList(suggestion), SHELL_PACKAGE_NAME);
                    // untrusted/oem-paid networks need a corresponding NetworkRequest.
                    if (suggestion.isUntrusted()
                            || (SdkLevel.isAtLeastS()
                            && (suggestion.isOemPaid() || suggestion.isOemPrivate()))) {
                        Pair<NetworkRequest, ConnectivityManager.NetworkCallback> nrAndNc =
                                sActiveRequests.remove(suggestion.getSsid());
                        if (nrAndNc == null) {
                            pw.println("No matching request to remove");
                            return -1;
                        }
                        pw.println("Removing request: " + nrAndNc.first);
                        mConnectivityManager.unregisterNetworkCallback(nrAndNc.second);
                    }
                    return 0;
                }
                case "remove-all-suggestions":
                    mWifiService.removeNetworkSuggestions(
                            Collections.emptyList(), SHELL_PACKAGE_NAME);
                    return 0;
                case "list-suggestions": {
                    List<WifiNetworkSuggestion> suggestions =
                            mWifiService.getNetworkSuggestions(SHELL_PACKAGE_NAME);
                    printWifiNetworkSuggestions(pw, suggestions);
                    return 0;
                }
                case "list-all-suggestions": {
                    Set<WifiNetworkSuggestion> suggestions =
                            mWifiNetworkSuggestionsManager.getAllNetworkSuggestions();
                    printWifiNetworkSuggestions(pw, suggestions);
                    return 0;
                }
                case "list-suggestions-from-app": {
                    String packageName = getNextArgRequired();
                    List<WifiNetworkSuggestion> suggestions =
                            mWifiService.getNetworkSuggestions(packageName);
                    printWifiNetworkSuggestions(pw, suggestions);
                    return 0;
                }
                case "add-request": {
                    NetworkRequest networkRequest = buildNetworkRequest(pw);
                    ConnectivityManager.NetworkCallback networkCallback =
                            new ConnectivityManager.NetworkCallback();
                    pw.println("Adding request: " + networkRequest);
                    mConnectivityManager.requestNetwork(networkRequest, networkCallback);
                    String ssid = getAllArgs()[1];
                    sActiveRequests.put(ssid, Pair.create(networkRequest, networkCallback));
                    return 0;
                }
                case "remove-request": {
                    String ssid = getNextArgRequired();
                    Pair<NetworkRequest, ConnectivityManager.NetworkCallback> nrAndNc =
                            sActiveRequests.remove(ssid);
                    if (nrAndNc == null) {
                        pw.println("No matching request to remove");
                        return -1;
                    }
                    pw.println("Removing request: " + nrAndNc.first);
                    mConnectivityManager.unregisterNetworkCallback(nrAndNc.second);
                    return 0;
                }
                case "remove-all-requests":
                    if (sActiveRequests.isEmpty()) {
                        pw.println("No active requests");
                        return -1;
                    }
                    for (Pair<NetworkRequest, ConnectivityManager.NetworkCallback> nrAndNc
                            : sActiveRequests.values()) {
                        pw.println("Removing request: " + nrAndNc.first);
                        mConnectivityManager.unregisterNetworkCallback(nrAndNc.second);
                    }
                    sActiveRequests.clear();
                    return 0;
                case "list-requests":
                    if (sActiveRequests.isEmpty()) {
                        pw.println("No active requests");
                    } else {
                        pw.println("SSID                         NetworkRequest");
                        for (Map.Entry<String,
                                Pair<NetworkRequest, ConnectivityManager.NetworkCallback>> entry :
                                sActiveRequests.entrySet()) {
                            pw.println(String.format("%-32s %-4s",
                                    entry.getKey(), entry.getValue().first));
                        }
                    }
                    return 0;
                case "network-requests-set-user-approved": {
                    String packageName = getNextArgRequired();
                    boolean approved = getNextArgRequiredTrueOrFalse("yes", "no");
                    mWifiNetworkFactory.setUserApprovedApp(packageName, approved);
                    return 0;
                }
                case "network-requests-has-user-approved": {
                    String packageName = getNextArgRequired();
                    boolean hasUserApproved = mWifiNetworkFactory.hasUserApprovedApp(packageName);
                    pw.println(hasUserApproved ? "yes" : "no");
                    return 0;
                }
                case "set-coex-cell-channels": {
                    if (!SdkLevel.isAtLeastS()) {
                        return handleDefaultCommands(cmd);
                    }
                    mCoexManager.setMockCellChannels(buildCoexCellChannels());
                    return 0;
                }
                case "reset-coex-cell-channels": {
                    if (!SdkLevel.isAtLeastS()) {
                        return handleDefaultCommands(cmd);
                    }
                    mCoexManager.resetMockCellChannels();
                    return 0;
                }
                case "get-coex-cell-channels": {
                    if (!SdkLevel.isAtLeastS()) {
                        return handleDefaultCommands(cmd);
                    }
                    pw.println("Cell channels: " + mCoexManager.getCellChannels());
                    return 0;
                }
                case "set-connected-score": {
                    int score = Integer.parseInt(getNextArgRequired());
                    CountDownLatch countDownLatch = new CountDownLatch(2);
                    mWifiService.clearWifiConnectedNetworkScorer(); // clear any previous scorer
                    WifiScorer connectedScorer = new WifiScorer(mWifiService, countDownLatch);
                    if (mWifiService.setWifiConnectedNetworkScorer(new Binder(), connectedScorer)) {
                        // wait for retrieving the session id & score observer.
                        countDownLatch.await(1000, TimeUnit.MILLISECONDS);
                    }
                    if (connectedScorer.getSessionId() == null
                            || connectedScorer.getScoreUpdateObserver() == null) {
                        pw.println("Did not receive session id and/or the score update observer. "
                                + "Is the device connected to a wifi network?");
                        mWifiService.clearWifiConnectedNetworkScorer();
                        return -1;
                    }
                    pw.println("Updating score: " + score + " for session id: "
                            + connectedScorer.getSessionId());
                    try {
                        connectedScorer.getScoreUpdateObserver().notifyScoreUpdate(
                                connectedScorer.getSessionId(), score);
                    } catch (RemoteException e) {
                        pw.println("Failed to send the score update");
                        mWifiService.clearWifiConnectedNetworkScorer();
                        return -1;
                    }
                    return 0;
                }
                case "reset-connected-score": {
                    mWifiService.clearWifiConnectedNetworkScorer(); // clear any previous scorer
                    return 0;
                }
                case "network-suggestions-set-as-carrier-provider": {
                    String packageName = getNextArgRequired();
                    boolean enabled = getNextArgRequiredTrueOrFalse("yes", "no");
                    mWifiNetworkSuggestionsManager
                            .setAppWorkingAsCrossCarrierProvider(packageName, enabled);
                    return 0;
                }
                case "is-network-suggestions-set-as-carrier-provider": {
                    String packageName = getNextArgRequired();
                    pw.println(mWifiNetworkSuggestionsManager
                            .isAppWorkingAsCrossCarrierProvider(packageName) ? "yes" : "no");
                    return 0;
                }
                case "remove-shell-app-from-suggestion_database <packageName>": {
                    String packageName = getNextArgRequired();
                    mWifiNetworkSuggestionsManager.removeApp(packageName);
                    return 0;
                }
                case "set-emergency-callback-mode": {
                    boolean enabled = getNextArgRequiredTrueOrFalse("enabled", "disabled");
                    mActiveModeWarden.emergencyCallbackModeChanged(enabled);
                    return 0;
                }
                case "set-emergency-call-state": {
                    boolean enabled = getNextArgRequiredTrueOrFalse("enabled", "disabled");
                    mActiveModeWarden.emergencyCallStateChanged(enabled);
                    return 0;
                }
                case "trigger-recovery": {
                    mSelfRecovery.trigger(REASON_API_CALL);
                    return 0;
                }
                case "add-fake-scan": {
                    String ssid = getNextArgRequired();
                    String bssid = getNextArgRequired();
                    String capabilities = getNextArgRequired();
                    int frequency;
                    int dbm;
                    String freqStr = getNextArgRequired();
                    try {
                        frequency = Integer.parseInt(freqStr);
                    } catch (NumberFormatException e) {
                        pw.println(
                                "Invalid frequency argument to 'add-fake-scan' "
                                        + "- must be an integer: " + freqStr);
                        return -1;
                    }
                    if (frequency <= 0) {
                        pw.println("Invalid frequency argument to 'add-fake-scan' - must be a "
                                + "positive integer: " + freqStr);
                    }
                    String dbmString = getNextArgRequired();
                    try {
                        dbm = Integer.parseInt(dbmString);
                    } catch (NumberFormatException e) {
                        pw.println(
                                "Invalid dbm argument to 'add-fake-scan' "
                                        + "- must be an integer: " + dbmString);
                        return -1;
                    }
                    ScanResult.InformationElement ieSSid = new ScanResult.InformationElement(
                            ScanResult.InformationElement.EID_SSID,
                            0,
                            ssid.getBytes(StandardCharsets.UTF_8));
                    ScanResult.InformationElement[] ies =
                            new ScanResult.InformationElement[]{ieSSid};
                    ScanDetail sd = new ScanDetail(new NetworkDetail(bssid, ies, null, frequency),
                            WifiSsid.createFromAsciiEncoded(ssid), bssid, capabilities, dbm,
                            frequency, SystemClock.elapsedRealtime() * 1000, ies, null, null);
                    mWifiNative.addFakeScanDetail(sd);
                    return 0;
                }
                case "reset-fake-scans":
                    mWifiNative.resetFakeScanDetails();
                    return 0;
                case "start-faking-scans":
                    mWifiNative.startFakingScanDetails();
                    mWifiService.startScan(SHELL_PACKAGE_NAME, null); // to trigger update
                    return 0;
                case "stop-faking-scans":
                    mWifiNative.stopFakingScanDetails();
                    return 0;
                case "enable-scanning":
                    boolean enabled = getNextArgRequiredTrueOrFalse("enabled", "disabled");
                    boolean hiddenEnabled = false;
                    String option = getNextOption();
                    if (option != null) {
                        if (option.equals("-h")) {
                            hiddenEnabled = true;
                        } else {
                            pw.println("Invalid argument to 'enable-scanning' "
                                    + "- only allowed option is '-h'");
                            return -1;
                        }
                    }
                    mScanRequestProxy.enableScanning(enabled, hiddenEnabled);
                    return 0;
                default:
                    return handleDefaultCommands(cmd);
            }
        } catch (IllegalArgumentException e) {
            pw.println("Invalid args for " + cmd + ": " + e);
            return -1;
        } catch (Exception e) {
            pw.println("Exception while executing WifiShellCommand: ");
            e.printStackTrace(pw);
            return -1;
        }
    }

    private boolean getNextArgRequiredTrueOrFalse(String trueString, String falseString)
            throws IllegalArgumentException {
        String nextArg = getNextArgRequired();
        if (trueString.equals(nextArg)) {
            return true;
        } else if (falseString.equals(nextArg)) {
            return false;
        } else {
            throw new IllegalArgumentException("Expected '" + trueString + "' or '" + falseString
                    + "' as next arg but got '" + nextArg + "'");
        }
    }

    private WifiConfiguration buildWifiConfiguration(PrintWriter pw) {
        String ssid = getNextArgRequired();
        String type = getNextArgRequired();
        WifiConfiguration configuration = new WifiConfiguration();
        configuration.SSID = "\"" + ssid + "\"";
        if (TextUtils.equals(type, "wpa3")) {
            configuration.setSecurityParams(WifiConfiguration.SECURITY_TYPE_SAE);
            configuration.preSharedKey = "\"" + getNextArgRequired() + "\"";
        } else if (TextUtils.equals(type, "wpa2")) {
            configuration.setSecurityParams(WifiConfiguration.SECURITY_TYPE_PSK);
            configuration.preSharedKey = "\"" + getNextArgRequired() + "\"";
        } else if (TextUtils.equals(type, "owe")) {
            configuration.setSecurityParams(WifiConfiguration.SECURITY_TYPE_OWE);
        } else if (TextUtils.equals(type, "open")) {
            configuration.setSecurityParams(WifiConfiguration.SECURITY_TYPE_OPEN);
        } else {
            throw new IllegalArgumentException("Unknown network type " + type);
        }
        String option = getNextOption();
        while (option != null) {
            if (option.equals("-m")) {
                configuration.meteredOverride = METERED_OVERRIDE_METERED;
            } else if (option.equals("-d")) {
                configuration.allowAutojoin = false;
            } else if (option.equals("-b")) {
                configuration.BSSID = getNextArgRequired();
            } else if (option.equals("-r")) {
                String macRandomizationScheme = getNextArgRequired();
                if (macRandomizationScheme.equals("auto")) {
                    configuration.macRandomizationSetting = WifiConfiguration.RANDOMIZATION_AUTO;
                } else if (macRandomizationScheme.equals("none")) {
                    configuration.macRandomizationSetting = WifiConfiguration.RANDOMIZATION_NONE;
                } else if (macRandomizationScheme.equals("persistent")) {
                    configuration.macRandomizationSetting =
                            WifiConfiguration.RANDOMIZATION_PERSISTENT;
                } else if (macRandomizationScheme.equals("non_persistent")) {
                    if (SdkLevel.isAtLeastS()) {
                        configuration.macRandomizationSetting =
                                WifiConfiguration.RANDOMIZATION_NON_PERSISTENT;
                    } else {
                        throw new IllegalArgumentException(
                                "-r non_persistent MAC randomization not supported before S");
                    }
                }
            } else if (option.equals("-h")) {
                configuration.hiddenSSID = true;
            } else if (option.equals("-p")) {
                configuration.shared = false;
            } else {
                pw.println("Ignoring unknown option " + option);
            }
            option = getNextOption();
        }
        return configuration;
    }

    private SoftApConfiguration buildSoftApConfiguration(PrintWriter pw) {
        String ssid = getNextArgRequired();
        String type = getNextArgRequired();
        SoftApConfiguration.Builder configBuilder = new SoftApConfiguration.Builder();
        configBuilder.setSsid(ssid);
        if (TextUtils.equals(type, "wpa2")) {
            configBuilder.setPassphrase(getNextArgRequired(),
                    SoftApConfiguration.SECURITY_TYPE_WPA2_PSK);
        } else if (TextUtils.equals(type, "wpa3")) {
            configBuilder.setPassphrase(getNextArgRequired(),
                    SoftApConfiguration.SECURITY_TYPE_WPA3_SAE);
        } else if (TextUtils.equals(type, "wpa3_transition")) {
            configBuilder.setPassphrase(getNextArgRequired(),
                    SoftApConfiguration.SECURITY_TYPE_WPA3_SAE_TRANSITION);
        } else if (TextUtils.equals(type, "open")) {
            configBuilder.setPassphrase(null, SoftApConfiguration.SECURITY_TYPE_OPEN);
        } else {
            throw new IllegalArgumentException("Unknown network type " + type);
        }
        String option = getNextOption();
        while (option != null) {
            if (option.equals("-b")) {
                String preferredBand = getNextArgRequired();
                if (preferredBand.equals("2")) {
                    configBuilder.setBand(SoftApConfiguration.BAND_2GHZ);
                } else if (preferredBand.equals("5")) {
                    configBuilder.setBand(SoftApConfiguration.BAND_5GHZ);
                } else if (preferredBand.equals("6")) {
                    configBuilder.setBand(SoftApConfiguration.BAND_6GHZ);
                } else if (preferredBand.equals("any")) {
                    configBuilder.setBand(SoftApConfiguration.BAND_2GHZ
                            | SoftApConfiguration.BAND_5GHZ | SoftApConfiguration.BAND_6GHZ);
                } else if (preferredBand.equals("bridged")) {
                    if (SdkLevel.isAtLeastS()) {
                        int[] dualBands = new int[] {
                                SoftApConfiguration.BAND_2GHZ, SoftApConfiguration.BAND_5GHZ};
                        configBuilder.setBands(dualBands);
                    } else {
                        throw new IllegalArgumentException(
                                "-b bridged option is not supported before S");
                    }
                } else {
                    throw new IllegalArgumentException("Invalid band option " + preferredBand);
                }
            } else {
                pw.println("Ignoring unknown option " + option);
            }
            option = getNextOption();
        }
        return configBuilder.build();
    }

    private WifiNetworkSuggestion buildSuggestion(PrintWriter pw) {
        String ssid = getNextArgRequired();
        String type = getNextArgRequired();
        WifiNetworkSuggestion.Builder suggestionBuilder =
                new WifiNetworkSuggestion.Builder();
        suggestionBuilder.setSsid(ssid);
        if (TextUtils.equals(type, "wpa3")) {
            suggestionBuilder.setWpa3Passphrase(getNextArgRequired());
        } else if (TextUtils.equals(type, "wpa2")) {
            suggestionBuilder.setWpa2Passphrase(getNextArgRequired());
        } else if (TextUtils.equals(type, "owe")) {
            suggestionBuilder.setIsEnhancedOpen(true);
        } else if (TextUtils.equals(type, "open")) {
            // nothing to do.
        } else {
            throw new IllegalArgumentException("Unknown network type " + type);
        }
        boolean isCarrierMerged = false;
        String option = getNextOption();
        while (option != null) {
            if (option.equals("-u")) {
                suggestionBuilder.setUntrusted(true);
            } else if (option.equals("-o")) {
                if (SdkLevel.isAtLeastS()) {
                    suggestionBuilder.setOemPaid(true);
                } else {
                    throw new IllegalArgumentException(
                            "-o OEM paid suggestions not supported before S");
                }
            } else if (option.equals("-p")) {
                if (SdkLevel.isAtLeastS()) {
                    suggestionBuilder.setOemPrivate(true);
                } else {
                    throw new IllegalArgumentException(
                            "-p OEM private suggestions not supported before S");
                }
            } else if (option.equals("-m")) {
                suggestionBuilder.setIsMetered(true);
            } else if (option.equals("-s")) {
                suggestionBuilder.setCredentialSharedWithUser(true);
            } else if (option.equals("-d")) {
                suggestionBuilder.setIsInitialAutojoinEnabled(false);
            } else if (option.equals("-b")) {
                suggestionBuilder.setBssid(MacAddress.fromString(getNextArgRequired()));
            } else if (option.equals("-r")) {
                if (SdkLevel.isAtLeastS()) {
                    suggestionBuilder.setMacRandomizationSetting(
                            WifiNetworkSuggestion.RANDOMIZATION_NON_PERSISTENT);
                } else {
                    throw new IllegalArgumentException(
                            "-r non_persistent MAC randomization not supported before S");
                }
            } else if (option.equals("-a")) {
                if (SdkLevel.isAtLeastS()) {
                    isCarrierMerged = true;
                } else {
                    throw new IllegalArgumentException("-a option is not supported before S");
                }
            } else if (option.equals("-i")) {
                if (SdkLevel.isAtLeastS()) {
                    int subId = Integer.parseInt(getNextArgRequired());
                    suggestionBuilder.setSubscriptionId(subId);
                } else {
                    throw new IllegalArgumentException(
                            "-i subscription ID option is not supported before S");
                }
            } else if (option.equals("-c")) {
                int carrierId = Integer.parseInt(getNextArgRequired());
                suggestionBuilder.setCarrierId(carrierId);
            } else if (option.equals("-h")) {
                suggestionBuilder.setIsHiddenSsid(true);
            } else {
                pw.println("Ignoring unknown option " + option);
            }
            option = getNextOption();
        }
        WifiNetworkSuggestion suggestion = suggestionBuilder.build();
        if (isCarrierMerged) {
            if (suggestion.wifiConfiguration.subscriptionId
                    == SubscriptionManager.INVALID_SUBSCRIPTION_ID) {
                pw.println("Carrier merged network must have valid subscription Id");
                return null;
            }
            suggestion.wifiConfiguration.carrierMerged = true;
        }
        return suggestion;
    }

    private NetworkRequest buildNetworkRequest(PrintWriter pw) {
        String ssid = getNextArgRequired();
        String type = getNextArgRequired();
        WifiNetworkSpecifier.Builder specifierBuilder =
                new WifiNetworkSpecifier.Builder();
        specifierBuilder.setSsid(ssid);
        if (TextUtils.equals(type, "wpa3")) {
            specifierBuilder.setWpa3Passphrase(getNextArgRequired());
        } else if (TextUtils.equals(type, "wpa3_transition")) {
            specifierBuilder.setWpa3Passphrase(getNextArgRequired());
        } else if (TextUtils.equals(type, "wpa2")) {
            specifierBuilder.setWpa2Passphrase(getNextArgRequired());
        } else if (TextUtils.equals(type, "owe")) {
            specifierBuilder.setIsEnhancedOpen(true);
        } else if (TextUtils.equals(type, "open")) {
            // nothing to do.
        } else {
            throw new IllegalArgumentException("Unknown network type " + type);
        }
        String bssid = null;
        String option = getNextOption();
        while (option != null) {
            if (option.equals("-b")) {
                bssid = getNextArgRequired();
            } else {
                pw.println("Ignoring unknown option " + option);
            }
            option = getNextOption();
        }

        // Permission approval bypass is only available to requests with both ssid & bssid set.
        // So, find scan result with the best rssi level to set in the request.
        if (bssid == null) {
            ScanResult matchingScanResult =
                    mWifiService.getScanResults(SHELL_PACKAGE_NAME, null)
                            .stream()
                            .filter(s -> s.SSID.equals(ssid))
                            .max(Comparator.comparingInt(s -> s.level))
                            .orElse(null);
            if (matchingScanResult != null) {
                bssid = matchingScanResult.BSSID;
            } else {
                pw.println("No matching bssid found, request will need UI approval");
            }
        }
        if (bssid != null) specifierBuilder.setBssid(MacAddress.fromString(bssid));
        return new NetworkRequest.Builder()
                .addTransportType(TRANSPORT_WIFI)
                .removeCapability(NET_CAPABILITY_INTERNET)
                .setNetworkSpecifier(specifierBuilder.build())
                .build();
    }

    @NonNull
    private List<CoexUtils.CoexCellChannel> buildCoexCellChannels() {
        List<CoexUtils.CoexCellChannel> cellChannels = new ArrayList<>();
        while (getRemainingArgsCount() > 0) {
            final @Annotation.NetworkType int rat;
            final String ratArg = getNextArgRequired();
            if (TextUtils.equals(ratArg, "lte")) {
                rat = TelephonyManager.NETWORK_TYPE_LTE;
            } else if (TextUtils.equals(ratArg, "nr")) {
                rat = TelephonyManager.NETWORK_TYPE_NR;
            } else {
                throw new IllegalArgumentException("Unknown rat type " + ratArg);
            }
            final int band = Integer.parseInt(getNextArgRequired());
            if (band < 1 || band > 261) {
                throw new IllegalArgumentException("Band is " + band
                        + " but should be a value from 1 to 261");
            }
            final int downlinkFreqKhz = Integer.parseInt(getNextArgRequired());
            if (downlinkFreqKhz < 0 && downlinkFreqKhz != PhysicalChannelConfig.FREQUENCY_UNKNOWN) {
                throw new IllegalArgumentException("Downlink frequency is " + downlinkFreqKhz
                        + " but should be >= 0 or UNKNOWN: "
                        + PhysicalChannelConfig.FREQUENCY_UNKNOWN);
            }
            final int downlinkBandwidthKhz = Integer.parseInt(getNextArgRequired());
            if (downlinkBandwidthKhz <= 0
                    && downlinkBandwidthKhz != PhysicalChannelConfig.CELL_BANDWIDTH_UNKNOWN) {
                throw new IllegalArgumentException("Downlink bandwidth is " + downlinkBandwidthKhz
                        + " but should be > 0 or UNKNOWN: "
                        + PhysicalChannelConfig.CELL_BANDWIDTH_UNKNOWN);
            }
            final int uplinkFreqKhz = Integer.parseInt(getNextArgRequired());
            if (uplinkFreqKhz < 0 && uplinkFreqKhz != PhysicalChannelConfig.FREQUENCY_UNKNOWN) {
                throw new IllegalArgumentException("Uplink frequency is " + uplinkFreqKhz
                        + " but should be >= 0 or UNKNOWN: "
                        + PhysicalChannelConfig.FREQUENCY_UNKNOWN);
            }
            final int uplinkBandwidthKhz = Integer.parseInt(getNextArgRequired());
            if (uplinkBandwidthKhz <= 0
                    && uplinkBandwidthKhz != PhysicalChannelConfig.CELL_BANDWIDTH_UNKNOWN) {
                throw new IllegalArgumentException("Uplink bandwidth is " + uplinkBandwidthKhz
                        + " but should be > 0 or UNKNOWN: "
                        + PhysicalChannelConfig.CELL_BANDWIDTH_UNKNOWN);
            }
            cellChannels.add(new CoexUtils.CoexCellChannel(rat, band,
                    downlinkFreqKhz, downlinkBandwidthKhz, uplinkFreqKhz, uplinkBandwidthKhz,
                    SubscriptionManager.INVALID_SUBSCRIPTION_ID));
        }
        return cellChannels;
    }

    private void setAutoJoin(PrintWriter pw, String ssid, boolean allowAutojoin) {
        // For suggestions, this will work only if the config has already been added
        // to WifiConfigManager.
        WifiConfiguration retrievedConfig =
                mWifiService.getPrivilegedConfiguredNetworks(SHELL_PACKAGE_NAME, null)
                        .getList()
                        .stream()
                        .filter(n -> n.SSID.equals(ssid))
                        .findAny()
                        .orElse(null);
        if (retrievedConfig == null) {
            pw.println("Cannot retrieve config, autojoin setting skipped.");
            return;
        }
        mWifiService.allowAutojoin(retrievedConfig.networkId, allowAutojoin);
    }

    private int sendLinkProbe(PrintWriter pw) throws InterruptedException {
        // Note: should match WifiNl80211Manager#SEND_MGMT_FRAME_TIMEOUT_MS
        final int sendMgmtFrameTimeoutMs = 1000;

        ArrayBlockingQueue<String> queue = new ArrayBlockingQueue<>(1);
        mWifiThreadRunner.post(() ->
                mActiveModeWarden.getPrimaryClientModeManager().probeLink(new LinkProbeCallback() {
                    @Override
                    public void onAck(int elapsedTimeMs) {
                        queue.offer("Link probe succeeded after " + elapsedTimeMs + " ms");
                    }

                    @Override
                    public void onFailure(int reason) {
                        queue.offer("Link probe failed with reason "
                                + LinkProbeCallback.failureReasonToString(reason));
                    }
                }, -1));

        // block until msg is received, or timed out
        String msg = queue.poll(sendMgmtFrameTimeoutMs + 1000, TimeUnit.MILLISECONDS);
        if (msg == null) {
            pw.println("Link probe timed out");
        } else {
            pw.println(msg);
        }
        return 0;
    }

    private boolean isApChannelMHzValid(PrintWriter pw, int apChannelMHz) {
        int[] allowed2gFreq = mWifiNative.getChannelsForBand(WifiScanner.WIFI_BAND_24_GHZ);
        int[] allowed5gFreq = mWifiNative.getChannelsForBand(WifiScanner.WIFI_BAND_5_GHZ);
        int[] allowed5gDfsFreq =
            mWifiNative.getChannelsForBand(WifiScanner.WIFI_BAND_5_GHZ_DFS_ONLY);
        int[] allowed6gFreq = mWifiNative.getChannelsForBand(WifiScanner.WIFI_BAND_6_GHZ);
        int[] allowed60gFreq = mWifiNative.getChannelsForBand(WifiScanner.WIFI_BAND_60_GHZ);
        if (allowed2gFreq == null) {
            allowed2gFreq = new int[0];
        }
        if (allowed5gFreq == null) {
            allowed5gFreq = new int[0];
        }
        if (allowed5gDfsFreq == null) {
            allowed5gDfsFreq = new int[0];
        }
        if (allowed6gFreq == null) {
            allowed6gFreq = new int[0];
        }
        if (allowed60gFreq == null) {
            allowed60gFreq = new int[0];
        }
        pw.println("2G freq: " + Arrays.toString(allowed2gFreq));
        pw.println("5G freq: " + Arrays.toString(allowed5gFreq));
        pw.println("5G DFS: " + Arrays.toString(allowed5gDfsFreq));
        pw.println("6G freq: " + Arrays.toString(allowed6gFreq));
        pw.println("60G freq: " + Arrays.toString(allowed60gFreq));
        return (Arrays.binarySearch(allowed2gFreq, apChannelMHz) >= 0
                || Arrays.binarySearch(allowed5gFreq, apChannelMHz) >= 0
                || Arrays.binarySearch(allowed5gDfsFreq, apChannelMHz) >= 0)
                || Arrays.binarySearch(allowed6gFreq, apChannelMHz) >= 0
                || Arrays.binarySearch(allowed60gFreq, apChannelMHz) >= 0;
    }

    private void waitForWifiEnabled(boolean enabled) throws InterruptedException {
        CountDownLatch countDownLatch = new CountDownLatch(1);
        BroadcastReceiver broadcastReceiver = new BroadcastReceiver() {
            @Override
            public void onReceive(Context context, Intent intent) {
                String action = intent.getAction();
                if (WifiManager.WIFI_STATE_CHANGED_ACTION.equals(action)) {
                    int state = mWifiService.getWifiEnabledState();
                    if ((enabled && state == WIFI_STATE_ENABLED)
                            || (!enabled && state == WIFI_STATE_DISABLED)) {
                        countDownLatch.countDown();
                    }
                }
            }
        };
        IntentFilter filter = new IntentFilter();
        filter.addAction(WifiManager.WIFI_STATE_CHANGED_ACTION);
        mContext.registerReceiver(broadcastReceiver, filter);
        mWifiService.setWifiEnabled(SHELL_PACKAGE_NAME, enabled);
        countDownLatch.await(5000, TimeUnit.MILLISECONDS);
        mContext.unregisterReceiver(broadcastReceiver);
    }

    private void printWifiInfo(PrintWriter pw, WifiInfo info) {
        if (info.getSupplicantState() != SupplicantState.COMPLETED) {
            pw.println("Wifi is not connected");
            return;
        }
        pw.println("Wifi is connected to " + info.getSSID());
        pw.println("WifiInfo: " + info);
        // additional diagnostics not printed by WifiInfo.toString()
        pw.println("successfulTxPackets: " + info.txSuccess);
        pw.println("successfulTxPacketsPerSecond: " + info.getSuccessfulTxPacketsPerSecond());
        pw.println("retriedTxPackets: " + info.txRetries);
        pw.println("retriedTxPacketsPerSecond: " + info.getRetriedTxPacketsPerSecond());
        pw.println("lostTxPackets: " + info.txBad);
        pw.println("lostTxPacketsPerSecond: " + info.getLostTxPacketsPerSecond());
        pw.println("successfulRxPackets: " + info.rxSuccess);
        pw.println("successfulRxPacketsPerSecond: " + info.getSuccessfulRxPacketsPerSecond());
    }

    private void printStatus(PrintWriter pw) {
        boolean wifiEnabled = mWifiService.getWifiEnabledState() == WIFI_STATE_ENABLED;
        pw.println("Wifi is " + (wifiEnabled ? "enabled" : "disabled"));
        pw.println("Wifi scanning is "
                + (mWifiService.isScanAlwaysAvailable()
                ? "always available" : "only available when wifi is enabled"));
        if (!wifiEnabled) {
            return;
        }
        if (Binder.getCallingUid() != Process.ROOT_UID) {
            // not privileged, just dump the primary client mode manager manager status
            // (public API contents).
            pw.println("==== Primary ClientModeManager instance ====");
            printWifiInfo(pw, mWifiService.getConnectionInfo(SHELL_PACKAGE_NAME, null));
        } else {
            // privileged, dump out all the client mode manager manager statuses
            for (ClientModeManager cm : mActiveModeWarden.getClientModeManagers()) {
                pw.println("==== ClientModeManager instance: " + cm + " ====");
                WifiInfo info = cm.syncRequestConnectionInfo();
                printWifiInfo(pw, info);
                if (info.getSupplicantState() != SupplicantState.COMPLETED) {
                    continue;
                }
                Network network = cm.syncGetCurrentNetwork();
                NetworkCapabilities capabilities =
                        mConnectivityManager.getNetworkCapabilities(network);
                pw.println("NetworkCapabilities: " + capabilities);
            }
        }
    }

    private void onHelpNonPrivileged(PrintWriter pw) {
        pw.println("  get-country-code");
        pw.println("    Gets country code as a two-letter string");
        pw.println("  set-wifi-enabled enabled|disabled");
        pw.println("    Enables/disables Wifi on this device.");
        pw.println("  set-scan-always-available enabled|disabled");
        pw.println("    Sets whether scanning should be available even when wifi is off.");
        pw.println("  list-scan-results");
        pw.println("    Lists the latest scan results");
        pw.println("  start-scan");
        pw.println("    Start a new scan");
        pw.println("  list-networks");
        pw.println("    Lists the saved networks");
        pw.println("  connect-network <ssid> open|owe|wpa2|wpa3 [<passphrase>] [-m] [-d] "
                + "[-b <bssid>] [-r auto|none|persistent|non_persistent]");
        pw.println("    Connect to a network with provided params and add to saved networks list");
        pw.println("    <ssid> - SSID of the network");
        pw.println("    open|owe|wpa2|wpa3 - Security type of the network.");
        pw.println("        - Use 'open' or 'owe' for networks with no passphrase");
        pw.println("           - 'open' - Open networks (Most prevalent)");
        pw.println("           - 'owe' - Enhanced open networks");
        pw.println("        - Use 'wpa2' or 'wpa3' for networks with passphrase");
        pw.println("           - 'wpa2' - WPA-2 PSK networks (Most prevalent)");
        pw.println("           - 'wpa3' - WPA-3 PSK networks");
        pw.println("    -m - Mark the network metered.");
        pw.println("    -d - Mark the network autojoin disabled.");
        pw.println("    -h - Mark the network hidden.");
        pw.println("    -p - Mark the network private (not shared).");
        pw.println("    -b <bssid> - Set specific BSSID.");
        pw.println("    -r auto|none|persistent|non_persistent - MAC randomization scheme for the"
                + " network");
        pw.println("  add-network <ssid> open|owe|wpa2|wpa3 [<passphrase>] [-m] [-d] "
                + "[-b <bssid>] [-r auto|none|persistent|non_persistent]");
        pw.println("    Add/update saved network with provided params");
        pw.println("    <ssid> - SSID of the network");
        pw.println("    open|owe|wpa2|wpa3 - Security type of the network.");
        pw.println("        - Use 'open' or 'owe' for networks with no passphrase");
        pw.println("           - 'open' - Open networks (Most prevalent)");
        pw.println("           - 'owe' - Enhanced open networks");
        pw.println("        - Use 'wpa2' or 'wpa3' for networks with passphrase");
        pw.println("           - 'wpa2' - WPA-2 PSK networks (Most prevalent)");
        pw.println("           - 'wpa3' - WPA-3 PSK networks");
        pw.println("    -m - Mark the network metered.");
        pw.println("    -d - Mark the network autojoin disabled.");
        pw.println("    -h - Mark the network hidden.");
        pw.println("    -p - Mark the network private (not shared).");
        pw.println("    -b <bssid> - Set specific BSSID.");
        pw.println("    -r auto|none|persistent|non_persistent - MAC randomization scheme for the"
                + " network");
        pw.println("  forget-network <networkId>");
        pw.println("    Remove the network mentioned by <networkId>");
        pw.println("        - Use list-networks to retrieve <networkId> for the network");
        pw.println("  status");
        pw.println("    Current wifi status");
        pw.println("  set-verbose-logging enabled|disabled ");
        pw.println("    Set the verbose logging enabled or disabled");
        pw.println("  is-verbose-logging");
        pw.println("    Check whether verbose logging enabled or disabled");
        pw.println("  start-restricting-auto-join-to-subscription-id subId");
        pw.println("    temporarily disable all wifi networks except merged carrier networks with"
                + " the given subId");
        pw.println("  stop-restricting-auto-join-to-subscription-id");
        pw.println("    Undo the effects of "
                + "start-restricting-auto-join-to-subscription-id");
        pw.println("  add-suggestion <ssid> open|owe|wpa2|wpa3 [<passphrase>] [-u] [-o] [-p] [-m] "
                + " [-s] [-d] [-b <bssid>] [-e] [-i] [-a <carrierId>] [-c <subscriptionId>]");
        pw.println("    Add a network suggestion with provided params");
        pw.println("    Use 'network-suggestions-set-user-approved " + SHELL_PACKAGE_NAME + " yes'"
                +  " to approve suggestions added via shell (Needs root access)");
        pw.println("    <ssid> - SSID of the network");
        pw.println("    open|owe|wpa2|wpa3 - Security type of the network.");
        pw.println("        - Use 'open' or 'owe' for networks with no passphrase");
        pw.println("           - 'open' - Open networks (Most prevalent)");
        pw.println("           - 'owe' - Enhanced open networks");
        pw.println("        - Use 'wpa2' or 'wpa3' for networks with passphrase");
        pw.println("           - 'wpa2' - WPA-2 PSK networks (Most prevalent)");
        pw.println("           - 'wpa3' - WPA-3 PSK networks");
        pw.println("    -u - Mark the suggestion untrusted.");
        pw.println("    -o - Mark the suggestion oem paid.");
        pw.println("    -p - Mark the suggestion oem private.");
        pw.println("    -m - Mark the suggestion metered.");
        pw.println("    -h - Mark the network hidden.");
        pw.println("    -s - Share the suggestion with user.");
        pw.println("    -d - Mark the suggestion autojoin disabled.");
        pw.println("    -b <bssid> - Set specific BSSID.");
        pw.println("    -r - Enable non_persistent randomization (disabled by default)");
        pw.println("    -a - Mark the suggestion carrier merged");
        pw.println("    -c <carrierId> - set carrier Id");
        pw.println("    -i <subscriptionId> - set subscription Id, if -a is used, "
                + "this must be set");
        pw.println("  remove-suggestion <ssid>");
        pw.println("    Remove a network suggestion with provided SSID of the network");
        pw.println("  remove-all-suggestions");
        pw.println("    Removes all suggestions added via shell");
        pw.println("  list-suggestions");
        pw.println("    Lists the suggested networks added via shell");
        if (SdkLevel.isAtLeastS()) {
            pw.println("  set-coex-cell-channels [lte|nr <bandNumber 1-261> "
                    + "<downlinkFreqKhz or UNKNOWN: "
                    + PhysicalChannelConfig.FREQUENCY_UNKNOWN + "> "
                    + "<downlinkBandwidthKhz or UNKNOWN: "
                    + PhysicalChannelConfig.CELL_BANDWIDTH_UNKNOWN + "> "
                    + "<uplinkFreqKhz or UNKNOWN: "
                    + PhysicalChannelConfig.FREQUENCY_UNKNOWN + "> "
                    + "<uplinkBandwidthKhz or UNKNOWN: "
                    + PhysicalChannelConfig.CELL_BANDWIDTH_UNKNOWN + ">] ...");
            pw.println("    Sets a list of zero or more cell channels to use for coex calculations."
                    + " Actual device reported cell channels will be ignored until"
                    + " reset-coex-cell-channels is called.");
            pw.println("  reset-coex-cell-channels");
            pw.println("    Removes all cell channels set in set-coex-cell-channels and returns to "
                    + "listening on actual device reported cell channels");
            pw.println("  get-coex-cell-channels");
            pw.println("    Prints the cell channels being used for coex.");
        }
        pw.println("  set-connected-score <score>");
        pw.println("    Set connected wifi network score (to choose between LTE & Wifi for "
                + "default route).");
        pw.println("    This turns off the active connected scorer (default or external).");
        pw.println("    Only works while connected to a wifi network. This score will stay in "
                + "effect until you call reset-connected-score or the device disconnects from the "
                + "current network.");
        pw.println("    <score> - Integer score should be in the range of 0 - 60");
        pw.println("  reset-connected-score");
        pw.println("    Turns on the default connected scorer.");
        pw.println("    Note: Will clear any external scorer set.");
        pw.println("  start-softap <ssid> (open|wpa2|wpa3|wpa3_transition) <passphrase> "
                + "[-b 2|5|6|any]");
        pw.println("    Start softap with provided params");
        pw.println("    Note that the shell command doesn't activate internet tethering. In some "
                + "devices, internet sharing is possible when Wi-Fi STA is also enabled and is"
                + "associated to another AP with internet access.");
        pw.println("    <ssid> - SSID of the network");
        pw.println("    open|wpa2|wpa3|wpa3_transition - Security type of the network.");
        pw.println("        - Use 'open' for networks with no passphrase");
        pw.println("        - Use 'wpa2', 'wpa3', 'wpa3_transition' for networks with passphrase");
        pw.println("    -b 2|5|6|any|bridged - select the preferred band.");
        pw.println("        - Use '2' to select 2.4GHz band as the preferred band");
        pw.println("        - Use '5' to select 5GHz band as the preferred band");
        pw.println("        - Use '6' to select 6GHz band as the preferred band");
        pw.println("        - Use 'any' to indicate no band preference");
        pw.println("        - Use 'bridged' to indicate bridged AP which enables APs on both "
                + "2.4G + 5G");
        pw.println("    Note: If the band option is not provided, 2.4GHz is the preferred band.");
        pw.println("          The exact channel is auto-selected by FW unless overridden by "
                + "force-softap-channel command");
        pw.println("  stop-softap");
        pw.println("    Stop softap (hotspot)");
        pw.println("  pmksa-flush <networkId>");
        pw.println("        - Flush the local PMKSA cache associated with the network id."
                + " Use list-networks to retrieve <networkId> for the network");
    }

    private void onHelpPrivileged(PrintWriter pw) {
        pw.println("  set-ipreach-disconnect enabled|disabled");
        pw.println("    Sets whether CMD_IP_REACHABILITY_LOST events should trigger disconnects.");
        pw.println("  get-ipreach-disconnect");
        pw.println("    Gets setting of CMD_IP_REACHABILITY_LOST events triggering disconnects.");
        pw.println("  set-poll-rssi-interval-msecs <int>");
        pw.println("    Sets the interval between RSSI polls to <int> milliseconds.");
        pw.println("  get-poll-rssi-interval-msecs");
        pw.println("    Gets current interval between RSSI polls, in milliseconds.");
        pw.println("  force-hi-perf-mode enabled|disabled");
        pw.println("    Sets whether hi-perf mode is forced or left for normal operation.");
        pw.println("  force-low-latency-mode enabled|disabled");
        pw.println("    Sets whether low latency mode is forced or left for normal operation.");
        pw.println("  network-suggestions-set-user-approved <package name> yes|no");
        pw.println("    Sets whether network suggestions from the app is approved or not.");
        pw.println("  network-suggestions-has-user-approved <package name>");
        pw.println("    Queries whether network suggestions from the app is approved or not.");
        pw.println("  imsi-protection-exemption-set-user-approved-for-carrier <carrier id> yes|no");
        pw.println("    Sets whether Imsi protection exemption for carrier is approved or not");
        pw.println("  imsi-protection-exemption-has-user-approved-for-carrier <carrier id>");
        pw.println("    Queries whether Imsi protection exemption for carrier is approved or not");
        pw.println("  imsi-protection-exemption-clear-user-approved-for-carrier <carrier id>");
        pw.println("    Clear the user choice on Imsi protection exemption for carrier");
        pw.println("  network-requests-remove-user-approved-access-points <package name>");
        pw.println("    Removes all user approved network requests for the app.");
        pw.println("  clear-user-disabled-networks");
        pw.println("    Clears the user disabled networks list.");
        pw.println("  send-link-probe");
        pw.println("    Manually triggers a link probe.");
        pw.println("  force-softap-band enabled <int> | disabled");
        pw.println("    Forces soft AP band to 2|5|6");
        pw.println("  force-softap-channel enabled <int> | disabled");
        pw.println("    Sets whether soft AP channel is forced to <int> MHz");
        pw.println("    or left for normal   operation.");
        pw.println("  force-country-code enabled <two-letter code> | disabled ");
        pw.println("    Sets country code to <two-letter code> or left for normal value");
        pw.println("  set-wifi-watchdog enabled|disabled");
        pw.println("    Sets whether wifi watchdog should trigger recovery");
        pw.println("  get-wifi-watchdog");
        pw.println("    Gets setting of wifi watchdog trigger recovery.");
        pw.println("  get-softap-supported-features");
        pw.println("    Gets softap supported features. Will print 'wifi_softap_acs_supported'");
        pw.println("    and/or 'wifi_softap_wpa3_sae_supported',");
        pw.println("    and/or 'wifi_softap_bridged_ap_supported',");
        pw.println("    and/or 'wifi_softap_bridged_ap_with_sta_supported',");
        pw.println("    each on a separate line.");
        pw.println("  settings-reset");
        pw.println("    Initiates wifi settings reset");
        pw.println("  add-request <ssid> open|owe|wpa2|wpa3 [<passphrase>] [-b <bssid>]");
        pw.println("    Add a network request with provided params");
        pw.println("    Use 'network-requests-set-user-approved android yes'"
                +  " to pre-approve requests added via rooted shell (Not persisted)");
        pw.println("    <ssid> - SSID of the network");
        pw.println("    open|owe|wpa2|wpa3 - Security type of the network.");
        pw.println("        - Use 'open' or 'owe' for networks with no passphrase");
        pw.println("           - 'open' - Open networks (Most prevalent)");
        pw.println("           - 'owe' - Enhanced open networks");
        pw.println("        - Use 'wpa2' or 'wpa3' for networks with passphrase");
        pw.println("           - 'wpa2' - WPA-2 PSK networks (Most prevalent)");
        pw.println("           - 'wpa3' - WPA-3 PSK networks");
        pw.println("    -b <bssid> - Set specific BSSID.");
        pw.println("  remove-request <ssid>");
        pw.println("    Remove a network request with provided SSID of the network");
        pw.println("  remove-all-requests");
        pw.println("    Removes all active requests added via shell");
        pw.println("  list-requests");
        pw.println("    Lists the requested networks added via shell");
        pw.println("  network-requests-set-user-approved <package name> yes|no");
        pw.println("    Sets whether network requests from the app is approved or not.");
        pw.println("    Note: Only 1 such app can be approved from the shell at a time");
        pw.println("  network-requests-has-user-approved <package name>");
        pw.println("    Queries whether network requests from the app is approved or not.");
        pw.println("    Note: This only returns whether the app was set via the "
                + "'network-requests-set-user-approved' shell command");
        pw.println("  list-all-suggestions");
        pw.println("    Lists all suggested networks on this device");
        pw.println("  list-suggestions-from-app <package name>");
        pw.println("    Lists the suggested networks from the app");
        pw.println("  set-emergency-callback-mode enabled|disabled");
        pw.println("    Sets whether Emergency Callback Mode (ECBM) is enabled.");
        pw.println("    Equivalent to receiving the "
                + "TelephonyManager.ACTION_EMERGENCY_CALLBACK_MODE_CHANGED broadcast.");
        pw.println("  set-emergency-call-state enabled|disabled");
        pw.println("    Sets whether we are in the middle of an emergency call.");
        pw.println("Equivalent to receiving the "
                + "TelephonyManager.ACTION_EMERGENCY_CALL_STATE_CHANGED broadcast.");
        pw.println("  network-suggestions-set-as-carrier-provider <packageName> yes|no");
        pw.println("    Set the <packageName> work as carrier provider or not.");
        pw.println("  is-network-suggestions-set-as-carrier-provider <packageName>");
        pw.println("    Queries whether the <packageName> is working as carrier provider or not.");
        pw.println("  remove-app-from-suggestion_database <packageName>");
        pw.println("    Remove <packageName> from the suggestion database, all suggestions and user"
                + " approval will be deleted, it is the same as uninstalling this app.");
        pw.println("  trigger-recovery");
        pw.println("    Trigger Wi-Fi subsystem restart.");
        pw.println("  start-faking-scans");
        pw.println("    Start faking scan results into the framework (configured with "
                + "'add-fake-scan'), stop with 'stop-faking-scans'.");
        pw.println("  stop-faking-scans");
        pw.println("    Stop faking scan results - started with 'start-faking-scans'.");
        pw.println("  add-fake-scan <ssid> <bssid> <capabilities> <frequency> <dbm>");
        pw.println("    Add a fake scan result to be used when enabled via `start-faking-scans'.");
        pw.println("    Example WPA2: add-fake-scan fakeWpa2 80:01:02:03:04:05 "
                + "\"[WPA2-PSK-CCMP][RSN-PSK-CCMP][ESS]\" 2412 -55");
        pw.println("    Example WPA3: add-fake-scan fakeWpa3 80:01:02:03:04:06 "
                + "\"[RSN-SAE+FT/SAE-CCMP][ESS]\" 2412 -55");
        pw.println(
                "    Example Open: add-fake-scan fakeOpen 80:01:02:03:04:07 \"[ESS]\" 2412 -55");
        pw.println("    Example OWE: add-fake-scan fakeOwe 80:01:02:03:04:08 \"[RSN-OWE-CCMP]\" "
                + "2412 -55");
        pw.println(
                "    Example WPA2/WPA3 transition mode: add-fake-scan fakeWpa2t3 80:01:02:03:04:09 "
                        + "\"[WPA2-PSK-CCMP][RSN-PSK+SAE-CCMP][ESS][MFPC]\" 2412 -55");
        pw.println(
                "    Example Open/OWE transition mode: add-fake-scan fakeOpenOwe 80:01:02:03:04:0A "
                        + "\"[RSN-OWE_TRANSITION-CCMP][ESS]\" 2412 -55");
        pw.println(
                "    Example Passpoint: add-fake-scan fakePasspoint 80:01:02:03:04:0B "
                        + "\"[WPA2-EAP/SHA1-CCMP][RSN-EAP/SHA1-CCMP][ESS][MFPR][MFPC]"
                        + "[PASSPOINT]\" 2412 -55");
        pw.println("  reset-fake-scans");
        pw.println("    Resets all fake scan results added by 'add-fake-scan'.");
        pw.println("  enable-scanning enabled|disabled [-h]");
        pw.println("    Sets whether all scanning should be enabled or disabled");
        pw.println("    -h - Enable scanning for hidden networks.");
    }

    @Override
    public void onHelp() {
        final PrintWriter pw = getOutPrintWriter();
        pw.println("Wi-Fi (wifi) commands:");
        pw.println("  help or -h");
        pw.println("    Print this help text.");
        onHelpNonPrivileged(pw);
        if (Binder.getCallingUid() == Process.ROOT_UID) {
            onHelpPrivileged(pw);
        }
        pw.println();
    }

    private void printWifiNetworkSuggestions(PrintWriter pw,
            Collection<WifiNetworkSuggestion> suggestions) {
        if (suggestions == null || suggestions.isEmpty()) {
            pw.println("No suggestions on this device");
        } else {
            pw.println("SSID                         Security type(s)");
            for (WifiNetworkSuggestion suggestion : suggestions) {
                pw.println(String.format("%-32s %-4s",
                        WifiInfo.sanitizeSsid(suggestion.getWifiConfiguration().SSID),
                        suggestion.getWifiConfiguration().getSecurityParamsList().stream()
                                .map(p -> WifiConfiguration.getSecurityTypeName(
                                        p.getSecurityType())
                                        + (p.isAddedByAutoUpgrade() ? "^" : ""))
                                .collect(Collectors.joining("/"))));
            }
        }
    }
}
