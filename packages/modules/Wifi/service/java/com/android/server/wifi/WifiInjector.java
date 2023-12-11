/*
 * Copyright (C) 2016 The Android Open Source Project
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

import android.annotation.NonNull;
import android.annotation.Nullable;
import android.app.ActivityManager;
import android.app.AlarmManager;
import android.app.AppOpsManager;
import android.content.Context;
import android.net.IpMemoryStore;
import android.net.LinkProperties;
import android.net.MatchAllNetworkSpecifier;
import android.net.NetworkAgentConfig;
import android.net.NetworkCapabilities;
import android.net.NetworkKey;
import android.net.NetworkProvider;
import android.net.NetworkScoreManager;
import android.net.wifi.WifiScanner;
import android.net.wifi.nl80211.WifiNl80211Manager;
import android.os.BatteryStatsManager;
import android.os.Handler;
import android.os.HandlerExecutor;
import android.os.HandlerThread;
import android.os.Looper;
import android.os.Process;
import android.os.UserManager;
import android.os.WorkSource;
import android.provider.Settings.Secure;
import android.security.keystore.AndroidKeyStoreProvider;
import android.telephony.CarrierConfigManager;
import android.telephony.SubscriptionManager;
import android.telephony.TelephonyManager;
import android.util.LocalLog;
import android.util.Log;

import com.android.internal.annotations.VisibleForTesting;
import com.android.modules.utils.build.SdkLevel;
import com.android.server.wifi.aware.WifiAwareMetrics;
import com.android.server.wifi.coex.CoexManager;
import com.android.server.wifi.hotspot2.PasspointManager;
import com.android.server.wifi.hotspot2.PasspointNetworkNominateHelper;
import com.android.server.wifi.hotspot2.PasspointObjectFactory;
import com.android.server.wifi.p2p.SupplicantP2pIfaceHal;
import com.android.server.wifi.p2p.WifiP2pMetrics;
import com.android.server.wifi.p2p.WifiP2pMonitor;
import com.android.server.wifi.p2p.WifiP2pNative;
import com.android.server.wifi.rtt.RttMetrics;
import com.android.server.wifi.util.LastCallerInfoManager;
import com.android.server.wifi.util.LruConnectionTracker;
import com.android.server.wifi.util.NetdWrapper;
import com.android.server.wifi.util.SettingsMigrationDataHolder;
import com.android.server.wifi.util.WifiPermissionsUtil;
import com.android.server.wifi.util.WifiPermissionsWrapper;
import com.android.server.wifi.util.WorkSourceHelper;
import com.android.wifi.resources.R;

import java.security.KeyStore;
import java.security.KeyStoreException;
import java.security.NoSuchProviderException;
import java.util.Random;

/**
 *  WiFi dependency injector. To be used for accessing various WiFi class instances and as a
 *  handle for mock injection.
 *
 *  Some WiFi class instances currently depend on having a Looper from a HandlerThread that has
 *  been started. To accommodate this, we have a two-phased approach to initialize and retrieve
 *  an instance of the WifiInjector.
 */
public class WifiInjector {
    private static final String TAG = "WifiInjector";
    private static final String BOOT_DEFAULT_WIFI_COUNTRY_CODE = "ro.boot.wificountrycode";
    /**
     * Maximum number in-memory store network connection order;
     */
    private static final int MAX_RECENTLY_CONNECTED_NETWORK = 100;

    private static NetworkCapabilities.Builder makeBaseNetworkCapatibilitiesFilterBuilder() {
        NetworkCapabilities.Builder builder = new NetworkCapabilities.Builder()
                .addTransportType(NetworkCapabilities.TRANSPORT_WIFI)
                .addCapability(NetworkCapabilities.NET_CAPABILITY_INTERNET)
                .addCapability(NetworkCapabilities.NET_CAPABILITY_NOT_METERED)
                .addCapability(NetworkCapabilities.NET_CAPABILITY_NOT_ROAMING)
                .addCapability(NetworkCapabilities.NET_CAPABILITY_NOT_CONGESTED)
                .addCapability(NetworkCapabilities.NET_CAPABILITY_NOT_SUSPENDED)
                .setLinkUpstreamBandwidthKbps(1024 * 1024)
                .setLinkDownstreamBandwidthKbps(1024 * 1024)
                .setNetworkSpecifier(new MatchAllNetworkSpecifier());
        if (SdkLevel.isAtLeastS()) {
            builder.addCapability(NetworkCapabilities.NET_CAPABILITY_NOT_VCN_MANAGED);
        }
        return builder;
    }

    @VisibleForTesting
    public static final NetworkCapabilities REGULAR_NETWORK_CAPABILITIES_FILTER =
            makeBaseNetworkCapatibilitiesFilterBuilder()
                    .addCapability(NetworkCapabilities.NET_CAPABILITY_NOT_RESTRICTED)
                    .build();

    private static NetworkCapabilities makeOemNetworkCapatibilitiesFilter() {
        NetworkCapabilities.Builder builder =
                makeBaseNetworkCapatibilitiesFilterBuilder()
                .addCapability(NetworkCapabilities.NET_CAPABILITY_OEM_PAID);
        if (SdkLevel.isAtLeastS()) {
            // OEM_PRIVATE capability was only added in Android S.
            builder.addCapability(NetworkCapabilities.NET_CAPABILITY_OEM_PRIVATE);
        }
        return builder.build();
    }

    private static final NetworkCapabilities OEM_NETWORK_CAPABILITIES_FILTER =
            makeOemNetworkCapatibilitiesFilter();


    static WifiInjector sWifiInjector = null;

    private final WifiContext mContext;
    private final BatteryStatsManager mBatteryStats;
    private final FrameworkFacade mFrameworkFacade = new FrameworkFacade();
    private final DeviceConfigFacade mDeviceConfigFacade;
    private final UserManager mUserManager;
    private final HandlerThread mWifiHandlerThread;
    private final HandlerThread mWifiP2pServiceHandlerThread;
    private final HandlerThread mPasspointProvisionerHandlerThread;
    private final HandlerThread mWifiDiagnosticsHandlerThread;
    private final WifiTrafficPoller mWifiTrafficPoller;
    private final WifiCountryCode mCountryCode;
    private final BackupManagerProxy mBackupManagerProxy = new BackupManagerProxy();
    private final WifiApConfigStore mWifiApConfigStore;
    private final WifiNative mWifiNative;
    private final WifiMonitor mWifiMonitor;
    private final WifiP2pNative mWifiP2pNative;
    private final WifiP2pMonitor mWifiP2pMonitor;
    private final SupplicantStaIfaceHal mSupplicantStaIfaceHal;
    private final SupplicantP2pIfaceHal mSupplicantP2pIfaceHal;
    private final HostapdHal mHostapdHal;
    private final WifiVendorHal mWifiVendorHal;
    private final ScoringParams mScoringParams;
    private final ActiveModeWarden mActiveModeWarden;
    private final WifiSettingsStore mSettingsStore;
    private final OpenNetworkNotifier mOpenNetworkNotifier;
    private final WifiLockManager mLockManager;
    private final WifiNl80211Manager mWifiCondManager;
    private final Clock mClock = new Clock();
    private final WifiMetrics mWifiMetrics;
    private final WifiP2pMetrics mWifiP2pMetrics;
    private final WifiLastResortWatchdog mWifiLastResortWatchdog;
    private final PropertyService mPropertyService = new SystemPropertyService();
    private final BuildProperties mBuildProperties = new SystemBuildProperties();
    private final WifiBackupRestore mWifiBackupRestore;
    // This will only be null if SdkLevel is not at least S
    @Nullable private final CoexManager mCoexManager;
    private final SoftApBackupRestore mSoftApBackupRestore;
    private final WifiMulticastLockManager mWifiMulticastLockManager;
    private final WifiConfigStore mWifiConfigStore;
    private final WifiKeyStore mWifiKeyStore;
    private final WifiConfigManager mWifiConfigManager;
    private final WifiConnectivityHelper mWifiConnectivityHelper;
    private final LocalLog mConnectivityLocalLog;
    private final WifiNetworkSelector mWifiNetworkSelector;
    private final SavedNetworkNominator mSavedNetworkNominator;
    private final NetworkSuggestionNominator mNetworkSuggestionNominator;
    private final ScoredNetworkNominator mScoredNetworkNominator;
    private final WifiNetworkScoreCache mWifiNetworkScoreCache;
    private final NetworkScoreManager mNetworkScoreManager;
    private final ClientModeManagerBroadcastQueue mBroadcastQueue;
    private WifiScanner mWifiScanner;
    private final WifiPermissionsWrapper mWifiPermissionsWrapper;
    private final WifiPermissionsUtil mWifiPermissionsUtil;
    private final PasspointManager mPasspointManager;
    private HandlerThread mWifiAwareHandlerThread;
    private HandlerThread mRttHandlerThread;
    private final HalDeviceManager mHalDeviceManager;
    private final WifiStateTracker mWifiStateTracker;
    private final SelfRecovery mSelfRecovery;
    private final WakeupController mWakeupController;
    private final ScanRequestProxy mScanRequestProxy;
    private final SarManager mSarManager;
    private final WifiDiagnostics mWifiDiagnostics;
    private final WifiDataStall mWifiDataStall;
    private final WifiScoreCard mWifiScoreCard;
    private final WifiNetworkSuggestionsManager mWifiNetworkSuggestionsManager;
    private final DppMetrics mDppMetrics;
    private final DppManager mDppManager;
    private final LinkProbeManager mLinkProbeManager;
    private IpMemoryStore mIpMemoryStore;
    private final WifiThreadRunner mWifiThreadRunner;
    private final WifiBlocklistMonitor mWifiBlocklistMonitor;
    private final MacAddressUtil mMacAddressUtil = new MacAddressUtil();
    private final MboOceController mMboOceController;
    private final WifiCarrierInfoManager mWifiCarrierInfoManager;
    private final WifiChannelUtilization mWifiChannelUtilizationScan;
    private final KeyStore mKeyStore;
    private final ConnectionFailureNotificationBuilder mConnectionFailureNotificationBuilder;
    private final ThroughputPredictor mThroughputPredictor;
    private NetdWrapper mNetdWrapper;
    private final WifiHealthMonitor mWifiHealthMonitor;
    private final WifiSettingsConfigStore mSettingsConfigStore;
    private final WifiScanAlwaysAvailableSettingsCompatibility
            mWifiScanAlwaysAvailableSettingsCompatibility;
    private final SettingsMigrationDataHolder mSettingsMigrationDataHolder;
    private final LruConnectionTracker mLruConnectionTracker;
    private final WifiConnectivityManager mWifiConnectivityManager;
    private final ConnectHelper mConnectHelper;
    private final ConnectionFailureNotifier mConnectionFailureNotifier;
    private final WifiNetworkFactory mWifiNetworkFactory;
    private final UntrustedWifiNetworkFactory mUntrustedWifiNetworkFactory;
    private final OemWifiNetworkFactory mOemWifiNetworkFactory;
    private final WifiP2pConnection mWifiP2pConnection;
    private final WifiGlobals mWifiGlobals;
    private final SimRequiredNotifier mSimRequiredNotifier;
    private final DefaultClientModeManager mDefaultClientModeManager;
    private final AdaptiveConnectivityEnabledSettingObserver
            mAdaptiveConnectivityEnabledSettingObserver;
    private final MakeBeforeBreakManager mMakeBeforeBreakManager;
    private final ClientModeImplMonitor mCmiMonitor = new ClientModeImplMonitor();
    private final ExternalScoreUpdateObserverProxy mExternalScoreUpdateObserverProxy;
    private final WifiNotificationManager mWifiNotificationManager;
    private final LastCallerInfoManager mLastCallerInfoManager;

    public WifiInjector(WifiContext context) {
        if (context == null) {
            throw new IllegalStateException(
                    "WifiInjector should not be initialized with a null Context.");
        }

        if (sWifiInjector != null) {
            throw new IllegalStateException(
                    "WifiInjector was already created, use getInstance instead.");
        }

        sWifiInjector = this;

        // Now create and start handler threads
        mWifiHandlerThread = new HandlerThread("WifiHandlerThread");
        mWifiHandlerThread.start();
        Looper wifiLooper = mWifiHandlerThread.getLooper();
        Handler wifiHandler = new Handler(wifiLooper);
        mWifiDiagnosticsHandlerThread = new HandlerThread("WifiDiagnostics");
        mWifiDiagnosticsHandlerThread.start();

        mContext = context;
        mWifiNotificationManager = new WifiNotificationManager(mContext);
        mWifiGlobals = new WifiGlobals(mContext);
        mScoringParams = new ScoringParams(mContext);
        mWifiChannelUtilizationScan = new WifiChannelUtilization(mClock, mContext);
        mSettingsMigrationDataHolder = new SettingsMigrationDataHolder(mContext);
        mConnectionFailureNotificationBuilder = new ConnectionFailureNotificationBuilder(
                mContext, mFrameworkFacade);
        mBatteryStats = context.getSystemService(BatteryStatsManager.class);
        mWifiPermissionsWrapper = new WifiPermissionsWrapper(mContext);
        mNetworkScoreManager = mContext.getSystemService(NetworkScoreManager.class);
        mWifiNetworkScoreCache = new WifiNetworkScoreCache(mContext);
        mNetworkScoreManager.registerNetworkScoreCallback(NetworkKey.TYPE_WIFI,
                NetworkScoreManager.SCORE_FILTER_NONE,
                new HandlerExecutor(wifiHandler), mWifiNetworkScoreCache);
        mUserManager = mContext.getSystemService(UserManager.class);
        mWifiPermissionsUtil = new WifiPermissionsUtil(mWifiPermissionsWrapper, mContext,
                mUserManager, this);
        mWifiBackupRestore = new WifiBackupRestore(mWifiPermissionsUtil);
        mSoftApBackupRestore = new SoftApBackupRestore(mContext, mSettingsMigrationDataHolder);
        mWifiStateTracker = new WifiStateTracker(mBatteryStats);
        mWifiThreadRunner = new WifiThreadRunner(wifiHandler);
        mWifiP2pServiceHandlerThread = new HandlerThread("WifiP2pService");
        mWifiP2pServiceHandlerThread.start();
        mPasspointProvisionerHandlerThread =
                new HandlerThread("PasspointProvisionerHandlerThread");
        mPasspointProvisionerHandlerThread.start();
        WifiAwareMetrics awareMetrics = new WifiAwareMetrics(mClock);
        RttMetrics rttMetrics = new RttMetrics(mClock);
        mWifiP2pMetrics = new WifiP2pMetrics(mClock);
        mDppMetrics = new DppMetrics();
        mWifiMonitor = new WifiMonitor();
        mWifiMetrics = new WifiMetrics(mContext, mFrameworkFacade, mClock, wifiLooper,
                awareMetrics, rttMetrics, new WifiPowerMetrics(mBatteryStats), mWifiP2pMetrics,
                mDppMetrics, mWifiMonitor);
        mDeviceConfigFacade = new DeviceConfigFacade(mContext, wifiHandler, mWifiMetrics);
        mAdaptiveConnectivityEnabledSettingObserver =
                new AdaptiveConnectivityEnabledSettingObserver(wifiHandler, mWifiMetrics,
                        mFrameworkFacade, mContext);
        // Modules interacting with Native.
        mHalDeviceManager = new HalDeviceManager(mClock, this, wifiHandler);
        mWifiVendorHal = new WifiVendorHal(mContext, mHalDeviceManager, wifiHandler, mWifiGlobals);
        mSupplicantStaIfaceHal = new SupplicantStaIfaceHal(
                mContext, mWifiMonitor, mFrameworkFacade, wifiHandler, mClock, mWifiMetrics,
                mWifiGlobals);
        mHostapdHal = new HostapdHal(mContext, wifiHandler);
        mWifiCondManager = (WifiNl80211Manager) mContext.getSystemService(
                Context.WIFI_NL80211_SERVICE);
        mWifiNative = new WifiNative(
                mWifiVendorHal, mSupplicantStaIfaceHal, mHostapdHal, mWifiCondManager,
                mWifiMonitor, mPropertyService, mWifiMetrics,
                wifiHandler, new Random(), mBuildProperties, this);
        mWifiP2pMonitor = new WifiP2pMonitor();
        mSupplicantP2pIfaceHal = new SupplicantP2pIfaceHal(mWifiP2pMonitor);
        mWifiP2pNative = new WifiP2pNative(mWifiCondManager, mWifiNative,
                mWifiVendorHal, mSupplicantP2pIfaceHal, mHalDeviceManager, mPropertyService);
        SubscriptionManager subscriptionManager =
                mContext.getSystemService(SubscriptionManager.class);
        if (SdkLevel.isAtLeastS()) {
            mCoexManager = new CoexManager(mContext, mWifiNative, makeTelephonyManager(),
                    subscriptionManager, mContext.getSystemService(CarrierConfigManager.class),
                    wifiHandler);
        } else {
            mCoexManager = null;
        }

        // Now get instances of all the objects that depend on the HandlerThreads
        mWifiTrafficPoller = new WifiTrafficPoller(mContext);
        // WifiConfigManager/Store objects and their dependencies.
        KeyStore keyStore = null;
        try {
            keyStore = AndroidKeyStoreProvider.getKeyStoreForUid(Process.WIFI_UID);
        } catch (KeyStoreException | NoSuchProviderException e) {
            Log.wtf(TAG, "Failed to load keystore", e);
        }
        mKeyStore = keyStore;
        mWifiKeyStore = new WifiKeyStore(mContext, mKeyStore, mFrameworkFacade);
        // New config store
        mWifiConfigStore = new WifiConfigStore(mContext, wifiHandler, mClock, mWifiMetrics,
                WifiConfigStore.createSharedFiles(mFrameworkFacade.isNiapModeOn(mContext)));
        mWifiCarrierInfoManager = new WifiCarrierInfoManager(makeTelephonyManager(),
                subscriptionManager, this, mFrameworkFacade, mContext,
                mWifiConfigStore, wifiHandler, mWifiMetrics, mClock);
        String l2KeySeed = Secure.getString(mContext.getContentResolver(), Secure.ANDROID_ID);
        mWifiScoreCard = new WifiScoreCard(mClock, l2KeySeed, mDeviceConfigFacade,
                mFrameworkFacade, mContext);
        mWifiMetrics.setWifiScoreCard(mWifiScoreCard);
        mLruConnectionTracker = new LruConnectionTracker(MAX_RECENTLY_CONNECTED_NETWORK,
                mContext);
        mWifiConnectivityHelper = new WifiConnectivityHelper(this);
        int maxLinesLowRam = mContext.getResources().getInteger(
                R.integer.config_wifiConnectivityLocalLogMaxLinesLowRam);
        int maxLinesHighRam = mContext.getResources().getInteger(
                R.integer.config_wifiConnectivityLocalLogMaxLinesHighRam);
        mConnectivityLocalLog = new LocalLog(
                mContext.getSystemService(ActivityManager.class).isLowRamDevice() ? maxLinesLowRam
                        : maxLinesHighRam);
        mWifiDiagnostics = new WifiDiagnostics(
                mContext, this, mWifiNative, mBuildProperties,
                new LastMileLogger(this), mClock, mWifiDiagnosticsHandlerThread.getLooper());
        mWifiLastResortWatchdog = new WifiLastResortWatchdog(this, mContext, mClock,
                mWifiMetrics, mWifiDiagnostics, wifiLooper,
                mDeviceConfigFacade, mWifiThreadRunner, mWifiMonitor);
        mWifiBlocklistMonitor = new WifiBlocklistMonitor(mContext, mWifiConnectivityHelper,
                mWifiLastResortWatchdog, mClock, new LocalLog(
                mContext.getSystemService(ActivityManager.class).isLowRamDevice() ? 128 : 256),
                mWifiScoreCard, mScoringParams, mWifiMetrics);
        mWifiMetrics.setWifiBlocklistMonitor(mWifiBlocklistMonitor);
        // Config Manager
        mWifiConfigManager = new WifiConfigManager(mContext, mClock,
                mUserManager, mWifiCarrierInfoManager,
                mWifiKeyStore, mWifiConfigStore, mWifiPermissionsUtil,
                mMacAddressUtil, mWifiMetrics, mWifiBlocklistMonitor, mWifiLastResortWatchdog,
                new NetworkListSharedStoreData(mContext),
                new NetworkListUserStoreData(mContext),
                new RandomizedMacStoreData(), mFrameworkFacade, mDeviceConfigFacade,
                mWifiScoreCard, mLruConnectionTracker, mBuildProperties);
        mSettingsConfigStore = new WifiSettingsConfigStore(context, wifiHandler,
                mSettingsMigrationDataHolder, mWifiConfigManager, mWifiConfigStore);
        mSettingsStore = new WifiSettingsStore(mContext, mSettingsConfigStore);
        mWifiMetrics.setWifiConfigManager(mWifiConfigManager);
        mWifiMetrics.setWifiSettingsStore(mSettingsStore);

        mWifiMetrics.setScoringParams(mScoringParams);
        mThroughputPredictor = new ThroughputPredictor(mContext);
        mScanRequestProxy = new ScanRequestProxy(mContext,
                mContext.getSystemService(AppOpsManager.class),
                mContext.getSystemService(ActivityManager.class),
                this, mWifiConfigManager,
                mWifiPermissionsUtil, mWifiMetrics, mClock, wifiHandler, mSettingsConfigStore);
        mSarManager = new SarManager(mContext, makeTelephonyManager(), wifiLooper,
                mWifiNative);
        mWifiNetworkSelector = new WifiNetworkSelector(mContext, mWifiScoreCard, mScoringParams,
                mWifiConfigManager, mClock, mConnectivityLocalLog, mWifiMetrics, this,
                mThroughputPredictor, mWifiChannelUtilizationScan, mWifiGlobals,
                mScanRequestProxy);
        CompatibilityScorer compatibilityScorer = new CompatibilityScorer(mScoringParams);
        mWifiNetworkSelector.registerCandidateScorer(compatibilityScorer);
        ScoreCardBasedScorer scoreCardBasedScorer = new ScoreCardBasedScorer(mScoringParams);
        mWifiNetworkSelector.registerCandidateScorer(scoreCardBasedScorer);
        BubbleFunScorer bubbleFunScorer = new BubbleFunScorer(mScoringParams);
        mWifiNetworkSelector.registerCandidateScorer(bubbleFunScorer);
        ThroughputScorer throughputScorer = new ThroughputScorer(mScoringParams);
        mWifiNetworkSelector.registerCandidateScorer(throughputScorer);
        mWifiMetrics.setWifiNetworkSelector(mWifiNetworkSelector);
        mWifiNetworkSuggestionsManager = new WifiNetworkSuggestionsManager(mContext, wifiHandler,
                this, mWifiPermissionsUtil, mWifiConfigManager, mWifiConfigStore, mWifiMetrics,
                mWifiCarrierInfoManager, mWifiKeyStore, mLruConnectionTracker,
                mClock);
        mPasspointManager = new PasspointManager(mContext, this,
                wifiHandler, mWifiNative, mWifiKeyStore, mClock, new PasspointObjectFactory(),
                mWifiConfigManager, mWifiConfigStore, mWifiMetrics, mWifiCarrierInfoManager,
                mMacAddressUtil, mWifiPermissionsUtil);
        PasspointNetworkNominateHelper nominateHelper =
                new PasspointNetworkNominateHelper(mPasspointManager, mWifiConfigManager,
                        mConnectivityLocalLog);
        mSavedNetworkNominator = new SavedNetworkNominator(
                mWifiConfigManager, nominateHelper, mConnectivityLocalLog, mWifiCarrierInfoManager,
                mWifiPermissionsUtil, mWifiNetworkSuggestionsManager);
        mNetworkSuggestionNominator = new NetworkSuggestionNominator(mWifiNetworkSuggestionsManager,
                mWifiConfigManager, nominateHelper, mConnectivityLocalLog, mWifiCarrierInfoManager,
                mWifiMetrics);
        mScoredNetworkNominator = new ScoredNetworkNominator(mContext, wifiHandler,
                mFrameworkFacade, mNetworkScoreManager, mContext.getPackageManager(),
                mWifiConfigManager, mConnectivityLocalLog,
                mWifiNetworkScoreCache, mWifiPermissionsUtil);

        mWifiMetrics.setPasspointManager(mPasspointManager);
        WifiChannelUtilization wifiChannelUtilizationConnected =
                new WifiChannelUtilization(mClock, mContext);
        mWifiMetrics.setWifiChannelUtilization(wifiChannelUtilizationConnected);
        mLinkProbeManager = new LinkProbeManager(mClock, mWifiNative, mWifiMetrics,
                mFrameworkFacade, wifiHandler, mContext);
        mDefaultClientModeManager = new DefaultClientModeManager();
        mExternalScoreUpdateObserverProxy =
                new ExternalScoreUpdateObserverProxy(mWifiThreadRunner);
        mDppManager = new DppManager(wifiHandler, mWifiNative,
                mWifiConfigManager, mContext, mDppMetrics, mScanRequestProxy, mWifiPermissionsUtil);
        mActiveModeWarden = new ActiveModeWarden(this, wifiLooper,
                mWifiNative, mDefaultClientModeManager, mBatteryStats, mWifiDiagnostics,
                mContext, mSettingsStore, mFrameworkFacade, mWifiPermissionsUtil, mWifiMetrics,
                mExternalScoreUpdateObserverProxy, mDppManager);
        mWifiMetrics.setActiveModeWarden(mActiveModeWarden);
        mWifiHealthMonitor = new WifiHealthMonitor(mContext, this, mClock, mWifiConfigManager,
            mWifiScoreCard, wifiHandler, mWifiNative, l2KeySeed, mDeviceConfigFacade,
            mActiveModeWarden);
        mWifiDataStall = new WifiDataStall(mFrameworkFacade, mWifiMetrics, mContext,
                mDeviceConfigFacade, wifiChannelUtilizationConnected, mClock, wifiHandler,
                mThroughputPredictor, mActiveModeWarden, mCmiMonitor);
        mWifiMetrics.setWifiDataStall(mWifiDataStall);
        mWifiMetrics.setWifiHealthMonitor(mWifiHealthMonitor);
        mWifiP2pConnection = new WifiP2pConnection(mContext, wifiLooper, mActiveModeWarden);
        mConnectHelper = new ConnectHelper(mActiveModeWarden, mWifiConfigManager);
        mBroadcastQueue = new ClientModeManagerBroadcastQueue(mActiveModeWarden, mContext);
        mMakeBeforeBreakManager = new MakeBeforeBreakManager(mActiveModeWarden, mFrameworkFacade,
                mContext, mCmiMonitor, mBroadcastQueue, mWifiMetrics);
        mOpenNetworkNotifier = new OpenNetworkNotifier(mContext,
                wifiLooper, mFrameworkFacade, mClock, mWifiMetrics,
                mWifiConfigManager, mWifiConfigStore, mConnectHelper,
                new ConnectToNetworkNotificationBuilder(mContext, mFrameworkFacade),
                mMakeBeforeBreakManager, mWifiNotificationManager);
        mWifiConnectivityManager = new WifiConnectivityManager(
                mContext, mScoringParams, mWifiConfigManager,
                mWifiNetworkSuggestionsManager, mWifiNetworkSelector,
                mWifiConnectivityHelper, mWifiLastResortWatchdog, mOpenNetworkNotifier,
                mWifiMetrics, wifiHandler,
                mClock, mConnectivityLocalLog, mWifiScoreCard, mWifiBlocklistMonitor,
                mWifiChannelUtilizationScan, mPasspointManager, mDeviceConfigFacade,
                mActiveModeWarden, mWifiGlobals);
        mMboOceController = new MboOceController(makeTelephonyManager(), mActiveModeWarden);
        mCountryCode = new WifiCountryCode(mContext, mActiveModeWarden,
                mCmiMonitor, mWifiNative, mSettingsConfigStore);
        mConnectionFailureNotifier = new ConnectionFailureNotifier(
                mContext, mFrameworkFacade, mWifiConfigManager,
                mWifiConnectivityManager, wifiHandler,
                mWifiNotificationManager, mConnectionFailureNotificationBuilder);
        mWifiNetworkFactory = new WifiNetworkFactory(
                wifiLooper, mContext, REGULAR_NETWORK_CAPABILITIES_FILTER,
                (ActivityManager) mContext.getSystemService(Context.ACTIVITY_SERVICE),
                (AlarmManager) mContext.getSystemService(Context.ALARM_SERVICE),
                (AppOpsManager) mContext.getSystemService(Context.APP_OPS_SERVICE),
                mClock, this, mWifiConnectivityManager, mWifiConfigManager,
                mWifiConfigStore, mWifiPermissionsUtil, mWifiMetrics, mActiveModeWarden,
                mConnectHelper, mCmiMonitor);
        // We can't filter untrusted network in the capabilities filter because a trusted
        // network would still satisfy a request that accepts untrusted ones.
        // We need a second network factory for untrusted network requests because we need a
        // different score filter for these requests.
        mUntrustedWifiNetworkFactory = new UntrustedWifiNetworkFactory(
                wifiLooper, mContext, REGULAR_NETWORK_CAPABILITIES_FILTER,
                mWifiConnectivityManager);
        mOemWifiNetworkFactory = new OemWifiNetworkFactory(
                wifiLooper, mContext, OEM_NETWORK_CAPABILITIES_FILTER,
                mWifiConnectivityManager);
        mWifiScanAlwaysAvailableSettingsCompatibility =
                new WifiScanAlwaysAvailableSettingsCompatibility(mContext, wifiHandler,
                        mSettingsStore, mActiveModeWarden, mFrameworkFacade);
        mWifiApConfigStore = new WifiApConfigStore(
                mContext, this, wifiHandler, mBackupManagerProxy,
                mWifiConfigStore, mWifiConfigManager, mActiveModeWarden, mWifiMetrics);
        WakeupNotificationFactory wakeupNotificationFactory =
                new WakeupNotificationFactory(mContext, mFrameworkFacade);
        WakeupOnboarding wakeupOnboarding = new WakeupOnboarding(mContext, mWifiConfigManager,
                wifiHandler, mFrameworkFacade, wakeupNotificationFactory, mWifiNotificationManager);
        mWakeupController = new WakeupController(mContext, wifiHandler,
                new WakeupLock(mWifiConfigManager, mWifiMetrics.getWakeupMetrics(), mClock),
                new WakeupEvaluator(mScoringParams), wakeupOnboarding, mWifiConfigManager,
                mWifiConfigStore, mWifiNetworkSuggestionsManager, mWifiMetrics.getWakeupMetrics(),
                this, mFrameworkFacade, mClock, mActiveModeWarden);
        mLockManager = new WifiLockManager(mContext, mBatteryStats, mActiveModeWarden,
                mFrameworkFacade, wifiHandler, mClock, mWifiMetrics);
        mSelfRecovery = new SelfRecovery(mContext, mActiveModeWarden, mClock, mWifiNative);
        mWifiMulticastLockManager = new WifiMulticastLockManager(mActiveModeWarden, mBatteryStats);

        // Register the various network Nominators with the network selector.
        mWifiNetworkSelector.registerNetworkNominator(mSavedNetworkNominator);
        mWifiNetworkSelector.registerNetworkNominator(mNetworkSuggestionNominator);
        mWifiNetworkSelector.registerNetworkNominator(mScoredNetworkNominator);

        mSimRequiredNotifier = new SimRequiredNotifier(mContext, mFrameworkFacade,
                mWifiNotificationManager);
        mLastCallerInfoManager = new LastCallerInfoManager();
    }

    /**
     * Obtain an instance of the WifiInjector class.
     *
     * This is the generic method to get an instance of the class. The first instance should be
     * retrieved using the getInstanceWithContext method.
     */
    public static WifiInjector getInstance() {
        if (sWifiInjector == null) {
            throw new IllegalStateException(
                    "Attempted to retrieve a WifiInjector instance before constructor was called.");
        }
        return sWifiInjector;
    }

    /**
     * Enable verbose logging in Injector objects. Called from the WifiServiceImpl (based on
     * binder call).
     */
    public void enableVerboseLogging(int verbose) {
        mWifiLastResortWatchdog.enableVerboseLogging(verbose);
        mWifiBackupRestore.enableVerboseLogging(verbose);
        mHalDeviceManager.enableVerboseLogging(verbose);
        mScanRequestProxy.enableVerboseLogging(verbose);
        mWakeupController.enableVerboseLogging(verbose);
        mWifiNetworkSuggestionsManager.enableVerboseLogging(verbose);
        LogcatLog.enableVerboseLogging(verbose);
        mDppManager.enableVerboseLogging(verbose);
        mWifiCarrierInfoManager.enableVerboseLogging(verbose);

        boolean verboseBool = verbose > 0;
        Log.i(TAG, "enableVerboseLogging(" + verbose + "): " + verboseBool);
        mCountryCode.enableVerboseLogging(verboseBool);
        mWifiDiagnostics.enableVerboseLogging(verboseBool);
        mWifiMonitor.enableVerboseLogging(verboseBool);
        mWifiNative.enableVerboseLogging(verboseBool);
        mWifiConfigManager.enableVerboseLogging(verboseBool);
        mPasspointManager.enableVerboseLogging(verboseBool);
        mWifiNetworkFactory.enableVerboseLogging(verboseBool);
        mLinkProbeManager.enableVerboseLogging(verboseBool);
        mMboOceController.enableVerboseLogging(verboseBool);
        mWifiScoreCard.enableVerboseLogging(verboseBool);
        mWifiHealthMonitor.enableVerboseLogging(verboseBool);
        mThroughputPredictor.enableVerboseLogging(verboseBool);
        mWifiDataStall.enableVerboseLogging(verboseBool);
        mWifiConnectivityManager.enableVerboseLogging(verboseBool);
        mWifiNetworkSelector.enableVerboseLogging(verboseBool);
        mMakeBeforeBreakManager.setVerboseLoggingEnabled(verboseBool);
        mBroadcastQueue.setVerboseLoggingEnabled(verboseBool);
        if (SdkLevel.isAtLeastS()) {
            mCoexManager.enableVerboseLogging(verboseBool);
        }
        mWifiPermissionsWrapper.enableVerboseLogging(verboseBool);
        mWifiPermissionsUtil.enableVerboseLogging(verboseBool);
    }

    public UserManager getUserManager() {
        return mUserManager;
    }

    public WifiMetrics getWifiMetrics() {
        return mWifiMetrics;
    }

    public WifiP2pMetrics getWifiP2pMetrics() {
        return mWifiP2pMetrics;
    }

    public SupplicantStaIfaceHal getSupplicantStaIfaceHal() {
        return mSupplicantStaIfaceHal;
    }

    public BackupManagerProxy getBackupManagerProxy() {
        return mBackupManagerProxy;
    }

    public FrameworkFacade getFrameworkFacade() {
        return mFrameworkFacade;
    }

    public HandlerThread getWifiP2pServiceHandlerThread() {
        return mWifiP2pServiceHandlerThread;
    }

    public HandlerThread getPasspointProvisionerHandlerThread() {
        return mPasspointProvisionerHandlerThread;
    }

    public HandlerThread getWifiHandlerThread() {
        return mWifiHandlerThread;
    }

    public WifiTrafficPoller getWifiTrafficPoller() {
        return mWifiTrafficPoller;
    }

    public WifiCountryCode getWifiCountryCode() {
        return mCountryCode;
    }

    public WifiApConfigStore getWifiApConfigStore() {
        return mWifiApConfigStore;
    }

    public SarManager getSarManager() {
        return mSarManager;
    }

    public ActiveModeWarden getActiveModeWarden() {
        return mActiveModeWarden;
    }

    public WifiSettingsStore getWifiSettingsStore() {
        return mSettingsStore;
    }

    public WifiLockManager getWifiLockManager() {
        return mLockManager;
    }

    public WifiLastResortWatchdog getWifiLastResortWatchdog() {
        return mWifiLastResortWatchdog;
    }

    public Clock getClock() {
        return mClock;
    }

    public WifiBackupRestore getWifiBackupRestore() {
        return mWifiBackupRestore;
    }

    public SoftApBackupRestore getSoftApBackupRestore() {
        return mSoftApBackupRestore;
    }

    public WifiMulticastLockManager getWifiMulticastLockManager() {
        return mWifiMulticastLockManager;
    }

    public WifiConfigManager getWifiConfigManager() {
        return mWifiConfigManager;
    }

    public PasspointManager getPasspointManager() {
        return mPasspointManager;
    }

    public WakeupController getWakeupController() {
        return mWakeupController;
    }

    public ScoringParams getScoringParams() {
        return mScoringParams;
    }

    public WifiScoreCard getWifiScoreCard() {
        return mWifiScoreCard;
    }

    public TelephonyManager makeTelephonyManager() {
        return mContext.getSystemService(TelephonyManager.class);
    }

    public WifiCarrierInfoManager getWifiCarrierInfoManager() {
        return mWifiCarrierInfoManager;
    }

    public DppManager getDppManager() {
        return mDppManager;
    }

    /**
     * Create a SoftApManager.
     *
     * @param config SoftApModeConfiguration object holding the config and mode
     * @return an instance of SoftApManager
     */
    public SoftApManager makeSoftApManager(
            @NonNull ActiveModeManager.Listener<SoftApManager> listener,
            @NonNull WifiServiceImpl.SoftApCallbackInternal callback,
            @NonNull SoftApModeConfiguration config,
            @NonNull WorkSource requestorWs,
            @NonNull ActiveModeManager.SoftApRole role,
            boolean verboseLoggingEnabled) {
        return new SoftApManager(mContext, mWifiHandlerThread.getLooper(),
                mFrameworkFacade, mWifiNative, mCoexManager, mCountryCode.getCountryCode(),
                listener, callback, mWifiApConfigStore, config, mWifiMetrics, mSarManager,
                mWifiDiagnostics, new SoftApNotifier(mContext, mFrameworkFacade,
                mWifiNotificationManager), mCmiMonitor, mActiveModeWarden,
                mClock.getElapsedSinceBootMillis(), requestorWs, role, verboseLoggingEnabled);
    }

    /**
     * Create a ClientModeImpl
     * @param ifaceName interface name for the ClientModeImpl
     * @param clientModeManager ClientModeManager that will own the ClientModeImpl
     */
    public ClientModeImpl makeClientModeImpl(
            @NonNull String ifaceName,
            @NonNull ConcreteClientModeManager clientModeManager,
            boolean verboseLoggingEnabled) {
        ExtendedWifiInfo wifiInfo = new ExtendedWifiInfo(mWifiGlobals, ifaceName);
        SupplicantStateTracker supplicantStateTracker = new SupplicantStateTracker(
                mContext, mWifiConfigManager, mBatteryStats, mWifiHandlerThread.getLooper(),
                mWifiMonitor, ifaceName, clientModeManager, mBroadcastQueue);
        supplicantStateTracker.enableVerboseLogging(verboseLoggingEnabled);
        return new ClientModeImpl(mContext, mWifiMetrics, mClock,
                mWifiScoreCard, mWifiStateTracker, mWifiPermissionsUtil, mWifiConfigManager,
                mPasspointManager, mWifiMonitor, mWifiDiagnostics,
                mWifiDataStall, mScoringParams, mWifiThreadRunner,
                mWifiNetworkSuggestionsManager, mWifiHealthMonitor, mThroughputPredictor,
                mDeviceConfigFacade, mScanRequestProxy, wifiInfo, mWifiConnectivityManager,
                mWifiBlocklistMonitor, mConnectionFailureNotifier,
                REGULAR_NETWORK_CAPABILITIES_FILTER, mWifiNetworkFactory,
                mUntrustedWifiNetworkFactory, mOemWifiNetworkFactory,
                mWifiLastResortWatchdog, mWakeupController,
                mLockManager, mFrameworkFacade, mWifiHandlerThread.getLooper(),
                mWifiNative, new WrongPasswordNotifier(mContext, mFrameworkFacade,
                mWifiNotificationManager),
                mWifiTrafficPoller, mLinkProbeManager, mClock.getElapsedSinceBootMillis(),
                mBatteryStats, supplicantStateTracker, mMboOceController, mWifiCarrierInfoManager,
                new EapFailureNotifier(mContext, mFrameworkFacade, mWifiCarrierInfoManager,
                        mWifiNotificationManager),
                mSimRequiredNotifier,
                new WifiScoreReport(mScoringParams, mClock, mWifiMetrics, wifiInfo,
                        mWifiNative, mWifiBlocklistMonitor, mWifiThreadRunner, mWifiScoreCard,
                        mDeviceConfigFacade, mContext, mAdaptiveConnectivityEnabledSettingObserver,
                        ifaceName, mExternalScoreUpdateObserverProxy, mSettingsStore),
                mWifiP2pConnection, mWifiGlobals, ifaceName, clientModeManager,
                mCmiMonitor, mBroadcastQueue, mWifiNetworkSelector, makeTelephonyManager(),
                this, mSettingsConfigStore, verboseLoggingEnabled);
    }

    public WifiNetworkAgent makeWifiNetworkAgent(
            @NonNull NetworkCapabilities nc,
            @NonNull LinkProperties linkProperties,
            @NonNull NetworkAgentConfig naConfig,
            @Nullable NetworkProvider provider,
            @NonNull WifiNetworkAgent.Callback callback) {
        return new WifiNetworkAgent(mContext, mWifiHandlerThread.getLooper(),
                nc, linkProperties, naConfig, provider, callback);
    }

    /**
     * Create a ClientModeManager
     *
     * @param listener listener for ClientModeManager state changes
     * @return a new instance of ClientModeManager
     */
    public ConcreteClientModeManager makeClientModeManager(
            @NonNull ClientModeManager.Listener<ConcreteClientModeManager> listener,
            @NonNull WorkSource requestorWs,
            @NonNull ActiveModeManager.ClientRole role,
            boolean verboseLoggingEnabled) {
        return new ConcreteClientModeManager(
                mContext, mWifiHandlerThread.getLooper(), mClock,
                mWifiNative, listener, mWifiMetrics, mWakeupController,
                this, mSelfRecovery, mWifiGlobals, mDefaultClientModeManager,
                mClock.getElapsedSinceBootMillis(), requestorWs, role, mBroadcastQueue,
                verboseLoggingEnabled);
    }

    public ScanOnlyModeImpl makeScanOnlyModeImpl(@NonNull String ifaceName) {
        return new ScanOnlyModeImpl(mClock.getElapsedSinceBootMillis(), mWifiNative, ifaceName);
    }

    /**
     * Create a WifiLog instance.
     *
     * @param tag module name to include in all log messages
     */
    public WifiLog makeLog(String tag) {
        return new LogcatLog(tag);
    }

    /**
     * Obtain an instance of WifiScanner.
     * If it was not already created, then obtain an instance.  Note, this must be done lazily since
     * WifiScannerService is separate and created later.
     */
    public synchronized WifiScanner getWifiScanner() {
        if (mWifiScanner == null) {
            mWifiScanner = mContext.getSystemService(WifiScanner.class);
        }
        return mWifiScanner;
    }

    /**
     * Construct an instance of {@link NetworkRequestStoreData}.
     */
    public NetworkRequestStoreData makeNetworkRequestStoreData(
            NetworkRequestStoreData.DataSource dataSource) {
        return new NetworkRequestStoreData(dataSource);
    }

    /**
     * Construct an instance of {@link NetworkSuggestionStoreData}.
     */
    public NetworkSuggestionStoreData makeNetworkSuggestionStoreData(
            NetworkSuggestionStoreData.DataSource dataSource) {
        return new NetworkSuggestionStoreData(dataSource);
    }

    /**
     * Construct an instance of {@link WifiCarrierInfoStoreManagerData}
     */
    public WifiCarrierInfoStoreManagerData makeWifiCarrierInfoStoreManagerData(
            WifiCarrierInfoStoreManagerData.DataSource dataSource) {
        return new WifiCarrierInfoStoreManagerData(dataSource);
    }

    /**
     * Construct an instance of {@link ImsiPrivacyProtectionExemptionStoreData}
     */
    public ImsiPrivacyProtectionExemptionStoreData makeImsiPrivacyProtectionExemptionStoreData(
            ImsiPrivacyProtectionExemptionStoreData.DataSource dataSource) {
        return new ImsiPrivacyProtectionExemptionStoreData(dataSource);
    }

    /**
     * Construct an instance of {@link SoftApStoreData}.
     */
    public SoftApStoreData makeSoftApStoreData(
            SoftApStoreData.DataSource dataSource) {
        return new SoftApStoreData(mContext, mSettingsMigrationDataHolder, dataSource);
    }

    public WifiPermissionsUtil getWifiPermissionsUtil() {
        return mWifiPermissionsUtil;
    }

    public WifiPermissionsWrapper getWifiPermissionsWrapper() {
        return mWifiPermissionsWrapper;
    }

    /**
     * Returns a singleton instance of a HandlerThread for injection. Uses lazy initialization.
     *
     * TODO: share worker thread with other Wi-Fi handlers (b/27924886)
     */
    public HandlerThread getWifiAwareHandlerThread() {
        if (mWifiAwareHandlerThread == null) { // lazy initialization
            mWifiAwareHandlerThread = new HandlerThread("wifiAwareService");
            mWifiAwareHandlerThread.start();
        }
        return mWifiAwareHandlerThread;
    }

    /**
     * Returns a singleton instance of a HandlerThread for injection. Uses lazy initialization.
     *
     * TODO: share worker thread with other Wi-Fi handlers (b/27924886)
     */
    public HandlerThread getRttHandlerThread() {
        if (mRttHandlerThread == null) { // lazy initialization
            mRttHandlerThread = new HandlerThread("wifiRttService");
            mRttHandlerThread.start();
        }
        return mRttHandlerThread;
    }

    public MacAddressUtil getMacAddressUtil() {
        return mMacAddressUtil;
    }

    /**
     * Returns a single instance of HalDeviceManager for injection.
     */
    public HalDeviceManager getHalDeviceManager() {
        return mHalDeviceManager;
    }

    public WifiNative getWifiNative() {
        return mWifiNative;
    }

    public WifiMonitor getWifiMonitor() {
        return mWifiMonitor;
    }

    public WifiP2pNative getWifiP2pNative() {
        return mWifiP2pNative;
    }

    /**
     * Returns a single instance of CoexManager for injection.
     * This will be null if SdkLevel is not at least S.
     */
    @Nullable public CoexManager getCoexManager() {
        return mCoexManager;
    }

    public WifiP2pMonitor getWifiP2pMonitor() {
        return mWifiP2pMonitor;
    }

    public SelfRecovery getSelfRecovery() {
        return mSelfRecovery;
    }

    public ScanRequestProxy getScanRequestProxy() {
        return mScanRequestProxy;
    }

    public Runtime getJavaRuntime() {
        return Runtime.getRuntime();
    }

    public WifiDataStall getWifiDataStall() {
        return mWifiDataStall;
    }

    public WifiNetworkSuggestionsManager getWifiNetworkSuggestionsManager() {
        return mWifiNetworkSuggestionsManager;
    }

    public IpMemoryStore getIpMemoryStore() {
        if (mIpMemoryStore == null) {
            mIpMemoryStore = IpMemoryStore.getMemoryStore(mContext);
        }
        return mIpMemoryStore;
    }

    public WifiBlocklistMonitor getWifiBlocklistMonitor() {
        return mWifiBlocklistMonitor;
    }

    public HostapdHal getHostapdHal() {
        return mHostapdHal;
    }

    public WifiThreadRunner getWifiThreadRunner() {
        return mWifiThreadRunner;
    }

    public WifiNetworkScoreCache getWifiNetworkScoreCache() {
        return mWifiNetworkScoreCache;
    }

    public NetdWrapper makeNetdWrapper() {
        if (mNetdWrapper == null) {
            mNetdWrapper = new NetdWrapper(mContext, new Handler(mWifiHandlerThread.getLooper()));
        }
        return mNetdWrapper;
    }

    public WifiNl80211Manager getWifiCondManager() {
        return mWifiCondManager;
    }

    public WifiHealthMonitor getWifiHealthMonitor() {
        return mWifiHealthMonitor;
    }

    public WifiSettingsConfigStore getSettingsConfigStore() {
        return mSettingsConfigStore;
    }

    public WifiScanAlwaysAvailableSettingsCompatibility
            getWifiScanAlwaysAvailableSettingsCompatibility() {
        return mWifiScanAlwaysAvailableSettingsCompatibility;
    }

    public DeviceConfigFacade getDeviceConfigFacade() {
        return mDeviceConfigFacade;
    }

    public WifiConnectivityManager getWifiConnectivityManager() {
        return mWifiConnectivityManager;
    }

    public ConnectHelper getConnectHelper() {
        return mConnectHelper;
    }

    public WifiNetworkFactory getWifiNetworkFactory() {
        return mWifiNetworkFactory;
    }

    public UntrustedWifiNetworkFactory getUntrustedWifiNetworkFactory() {
        return mUntrustedWifiNetworkFactory;
    }

    public OemWifiNetworkFactory getOemWifiNetworkFactory() {
        return mOemWifiNetworkFactory;
    }

    public WifiDiagnostics getWifiDiagnostics() {
        return mWifiDiagnostics;
    }

    public WifiP2pConnection getWifiP2pConnection() {
        return mWifiP2pConnection;
    }

    public WifiGlobals getWifiGlobals() {
        return mWifiGlobals;
    }

    public SimRequiredNotifier getSimRequiredNotifier() {
        return mSimRequiredNotifier;
    }

    /**
     * Useful for mocking {@link WorkSourceHelper} instance in {@link HalDeviceManager} unit tests.
     */
    public WorkSourceHelper makeWsHelper(@NonNull WorkSource ws) {
        return new WorkSourceHelper(ws, mWifiPermissionsUtil,
                mContext.getSystemService(ActivityManager.class), mContext.getPackageManager());
    }

    public AdaptiveConnectivityEnabledSettingObserver
            getAdaptiveConnectivityEnabledSettingObserver() {
        return mAdaptiveConnectivityEnabledSettingObserver;
    }

    public MakeBeforeBreakManager getMakeBeforeBreakManager() {
        return mMakeBeforeBreakManager;
    }

    public OpenNetworkNotifier getOpenNetworkNotifier() {
        return mOpenNetworkNotifier;
    }

    public WifiNotificationManager getWifiNotificationManager() {
        return mWifiNotificationManager;
    }

    public LastCallerInfoManager getLastCallerInfoManager() {
        return mLastCallerInfoManager;
    }

    public BuildProperties getBuildProperties() {
        return mBuildProperties;
    }

    public DefaultClientModeManager getDefaultClientModeManager() {
        return mDefaultClientModeManager;
    }

    public LinkProbeManager getLinkProbeManager() {
        return mLinkProbeManager;
    }

    @NonNull
    public WifiKeyStore getWifiKeyStore() {
        return mWifiKeyStore;
    }
}
