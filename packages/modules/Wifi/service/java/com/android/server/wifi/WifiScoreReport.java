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

import android.annotation.Nullable;
import android.content.Context;
import android.net.Network;
import android.net.NetworkCapabilities;
import android.net.NetworkScore;
import android.net.wifi.IWifiConnectedNetworkScorer;
import android.net.wifi.WifiConnectedSessionInfo;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.net.wifi.nl80211.WifiNl80211Manager;
import android.os.Build;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;

import androidx.annotation.RequiresApi;

import com.android.internal.annotations.VisibleForTesting;
import com.android.modules.utils.build.SdkLevel;
import com.android.server.wifi.ActiveModeManager.ClientRole;
import com.android.wifi.resources.R;

import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.LinkedList;
import java.util.Locale;

/**
 * Class used to calculate scores for connected wifi networks and report it to the associated
 * network agent.
 */
public class WifiScoreReport {
    private static final String TAG = "WifiScoreReport";

    private static final int DUMPSYS_ENTRY_COUNT_LIMIT = 3600; // 3 hours on 3 second poll

    private boolean mVerboseLoggingEnabled = false;
    private static final long FIRST_REASONABLE_WALL_CLOCK = 1490000000000L; // mid-December 2016

    private static final long MIN_TIME_TO_KEEP_BELOW_TRANSITION_SCORE_MILLIS = 9000;
    private long mLastDownwardBreachTimeMillis = 0;

    private static final int WIFI_CONNECTED_NETWORK_SCORER_IDENTIFIER = 0;
    private static final int INVALID_SESSION_ID = -1;
    private static final long MIN_TIME_TO_WAIT_BEFORE_BLOCKLIST_BSSID_MILLIS = 29000;
    private static final long INVALID_WALL_CLOCK_MILLIS = -1;

    /**
     * Set lingering score to be artificially lower than all other scores so that it will force
     * ConnectivityService to prefer any other network over this one.
     */
    @VisibleForTesting
    static final int LINGERING_SCORE = 1;

    // Cache of the last score
    private int mLegacyIntScore = ConnectedScore.WIFI_INITIAL_SCORE;
    // Cache of the last usability status
    private boolean mIsUsable = true;

    /**
     * If true, indicates that the associated {@link ClientModeImpl} instance is lingering
     * as a part of make before break STA + STA use-case, and will always send
     * {@link #LINGERING_SCORE} to NetworkAgent.
     */
    private boolean mShouldReduceNetworkScore = false;

    /** The current role of the ClientModeManager which owns this instance of WifiScoreReport. */
    @Nullable
    private ClientRole mCurrentRole = null;

    private final ScoringParams mScoringParams;
    private final Clock mClock;
    private int mSessionNumber = 0; // not to be confused with sessionid, this just counts resets
    private final String mInterfaceName;
    private final WifiBlocklistMonitor mWifiBlocklistMonitor;
    private final WifiScoreCard mWifiScoreCard;
    private final Context mContext;
    private long mLastScoreBreachLowTimeMillis = INVALID_WALL_CLOCK_MILLIS;
    private long mLastScoreBreachHighTimeMillis = INVALID_WALL_CLOCK_MILLIS;

    private final ConnectedScore mAggressiveConnectedScore;
    private VelocityBasedConnectedScore mVelocityBasedConnectedScore;
    private final WifiSettingsStore mWifiSettingsStore;
    private int mSessionIdNoReset = INVALID_SESSION_ID;
    // Indicate whether current network is selected by the user
    private boolean mIsUserSelected = false;

    @Nullable
    private WifiNetworkAgent mNetworkAgent;
    private final WifiMetrics mWifiMetrics;
    private final ExtendedWifiInfo mWifiInfo;
    private final WifiNative mWifiNative;
    private final WifiThreadRunner mWifiThreadRunner;
    private final DeviceConfigFacade mDeviceConfigFacade;
    private final ExternalScoreUpdateObserverProxy mExternalScoreUpdateObserverProxy;
    private final WifiInfo mWifiInfoNoReset;

    /**
     * Callback from {@link ExternalScoreUpdateObserverProxy}
     */
    private class ScoreUpdateObserverProxy implements WifiManager.ScoreUpdateObserver {
        @Override
        public void notifyScoreUpdate(int sessionId, int score) {
            if (mWifiConnectedNetworkScorerHolder == null
                    || sessionId == INVALID_SESSION_ID
                    || sessionId != getCurrentSessionId()) {
                Log.w(TAG, "Ignoring stale/invalid external score"
                        + " sessionId=" + sessionId
                        + " currentSessionId=" + getCurrentSessionId()
                        + " score=" + score);
                return;
            }
            long millis = mClock.getWallClockMillis();
            if (SdkLevel.isAtLeastS()) {
                mLegacyIntScore = score;
                updateWifiMetrics(millis, -1);
                return;
            }
            if (score < ConnectedScore.WIFI_TRANSITION_SCORE) {
                if (mLegacyIntScore >= ConnectedScore.WIFI_TRANSITION_SCORE) {
                    mLastScoreBreachLowTimeMillis = millis;
                }
            } else {
                mLastScoreBreachLowTimeMillis = INVALID_WALL_CLOCK_MILLIS;
            }
            if (score > ConnectedScore.WIFI_TRANSITION_SCORE) {
                if (mLegacyIntScore <= ConnectedScore.WIFI_TRANSITION_SCORE) {
                    mLastScoreBreachHighTimeMillis = millis;
                }
            } else {
                mLastScoreBreachHighTimeMillis = INVALID_WALL_CLOCK_MILLIS;
            }
            mLegacyIntScore = score;
            reportNetworkScoreToConnectivityServiceIfNecessary();
            updateWifiMetrics(millis, -1);
        }

        @Override
        public void triggerUpdateOfWifiUsabilityStats(int sessionId) {
            if (mWifiConnectedNetworkScorerHolder == null
                    || sessionId == INVALID_SESSION_ID
                    || sessionId != getCurrentSessionId()
                    || mInterfaceName == null) {
                Log.w(TAG, "Ignoring triggerUpdateOfWifiUsabilityStats"
                        + " sessionId=" + sessionId
                        + " currentSessionId=" + getCurrentSessionId()
                        + " interfaceName=" + mInterfaceName);
                return;
            }
            WifiLinkLayerStats stats = mWifiNative.getWifiLinkLayerStats(mInterfaceName);

            // update mWifiInfo
            // TODO(b/153075963): Better coordinate this class and ClientModeImpl to remove
            // redundant codes below and in ClientModeImpl#fetchRssiLinkSpeedAndFrequencyNative.
            WifiNl80211Manager.SignalPollResult pollResult =
                    mWifiNative.signalPoll(mInterfaceName);
            if (pollResult != null) {
                int newRssi = pollResult.currentRssiDbm;
                int newTxLinkSpeed = pollResult.txBitrateMbps;
                int newFrequency = pollResult.associationFrequencyMHz;
                int newRxLinkSpeed = pollResult.rxBitrateMbps;

                if (newRssi > WifiInfo.INVALID_RSSI && newRssi < WifiInfo.MAX_RSSI) {
                    if (newRssi > (WifiInfo.INVALID_RSSI + 256)) {
                        Log.wtf(TAG, "Error! +ve value RSSI: " + newRssi);
                        newRssi -= 256;
                    }
                    mWifiInfo.setRssi(newRssi);
                } else {
                    mWifiInfo.setRssi(WifiInfo.INVALID_RSSI);
                }
                /*
                 * set Tx link speed only if it is valid
                 */
                if (newTxLinkSpeed > 0) {
                    mWifiInfo.setLinkSpeed(newTxLinkSpeed);
                    mWifiInfo.setTxLinkSpeedMbps(newTxLinkSpeed);
                }
                /*
                 * set Rx link speed only if it is valid
                 */
                if (newRxLinkSpeed > 0) {
                    mWifiInfo.setRxLinkSpeedMbps(newRxLinkSpeed);
                }
                if (newFrequency > 0) {
                    mWifiInfo.setFrequency(newFrequency);
                }
            }

            // TODO(b/153075963): This should not be plumbed through WifiMetrics
            mWifiMetrics.updateWifiUsabilityStatsEntries(mInterfaceName, mWifiInfo, stats);
        }

        @Override
        public void notifyStatusUpdate(int sessionId, boolean isUsable) {
            if (mWifiConnectedNetworkScorerHolder == null
                    || sessionId == INVALID_SESSION_ID
                    || sessionId != getCurrentSessionId()) {
                Log.w(TAG, "Ignoring stale/invalid external status"
                        + " sessionId=" + sessionId
                        + " currentSessionId=" + getCurrentSessionId()
                        + " isUsable=" + isUsable);
                return;
            }
            if (mNetworkAgent == null) {
                return;
            }
            if (mShouldReduceNetworkScore) {
                return;
            }
            mIsUsable = isUsable;
            // Wifi is set to be usable if adaptive connectivity is disabled.
            if (!mAdaptiveConnectivityEnabledSettingObserver.get()
                    || !mWifiSettingsStore.isWifiScoringEnabled()) {
                mIsUsable = true;
                if (mVerboseLoggingEnabled) {
                    Log.d(TAG, "Wifi scoring disabled - Notify that Wifi is usable");
                }
            }
            // Send `exiting` to NetworkScore, but don't update and send mLegacyIntScore
            // and don't change any other fields. All we want to do is relay to ConnectivityService
            // whether the current network is usable.
            if (SdkLevel.isAtLeastS()) {
                mNetworkAgent.sendNetworkScore(
                        getScoreBuilder()
                                .setLegacyInt(mLegacyIntScore)
                                .setExiting(!mIsUsable)
                                .build());
            } else  {
                mNetworkAgent.sendNetworkScore(mIsUsable ? ConnectedScore.WIFI_TRANSITION_SCORE + 1
                        : ConnectedScore.WIFI_TRANSITION_SCORE - 1);
            }
        }

        @Override
        public void requestNudOperation(int sessionId) {
            if (mWifiConnectedNetworkScorerHolder == null
                    || sessionId == INVALID_SESSION_ID
                    || sessionId != getCurrentSessionId()) {
                Log.w(TAG, "Ignoring stale/invalid external input for NUD triggering"
                        + " sessionId=" + sessionId
                        + " currentSessionId=" + getCurrentSessionId());
                return;
            }
            if (!mAdaptiveConnectivityEnabledSettingObserver.get()
                    || !mWifiSettingsStore.isWifiScoringEnabled()) {
                if (mVerboseLoggingEnabled) {
                    Log.d(TAG, "Wifi scoring disabled - Cannot request a NUD operation");
                }
                return;
            }
            mWifiConnectedNetworkScorerHolder.setShouldCheckIpLayerOnce(true);
        }

        @Override
        public void blocklistCurrentBssid(int sessionId) {
            if (mWifiConnectedNetworkScorerHolder == null
                    || sessionId == INVALID_SESSION_ID
                    || sessionId != mSessionIdNoReset) {
                Log.w(TAG, "Ignoring stale/invalid external input for blocklisting"
                        + " sessionId=" + sessionId
                        + " mSessionIdNoReset=" + mSessionIdNoReset);
                return;
            }
            if (!mAdaptiveConnectivityEnabledSettingObserver.get()
                    || !mWifiSettingsStore.isWifiScoringEnabled()) {
                if (mVerboseLoggingEnabled) {
                    Log.d(TAG, "Wifi scoring disabled - Cannot blocklist current BSSID");
                }
                return;
            }
            if (mWifiInfoNoReset.getBSSID() != null) {
                mWifiBlocklistMonitor.handleBssidConnectionFailure(mWifiInfoNoReset.getBSSID(),
                        mWifiInfoNoReset.getSSID(),
                        WifiBlocklistMonitor.REASON_FRAMEWORK_DISCONNECT_CONNECTED_SCORE,
                        mWifiInfoNoReset.getRssi());
            }
        }
    }

    /**
     * If true, put the WifiScoreReport in lingering mode. A very low score is reported to
     * NetworkAgent, and the real score is never reported.
     */
    public void setShouldReduceNetworkScore(boolean shouldReduceNetworkScore) {
        Log.d(TAG, "setShouldReduceNetworkScore=" + shouldReduceNetworkScore
                + " mNetworkAgent is null? " + (mNetworkAgent == null));
        mShouldReduceNetworkScore = shouldReduceNetworkScore;
        // inform the external scorer that ongoing session has ended (since the score is no longer
        // under their control)
        if (mShouldReduceNetworkScore && mWifiConnectedNetworkScorerHolder != null) {
            mWifiConnectedNetworkScorerHolder.stopSession();
        }
        // if set to true, send score below disconnect threshold to start lingering
        sendNetworkScore();
    }

    /**
     * Report network score to connectivity service.
     */
    private void reportNetworkScoreToConnectivityServiceIfNecessary() {
        if (mNetworkAgent == null) {
            return;
        }
        if (mWifiConnectedNetworkScorerHolder == null && mLegacyIntScore == mWifiInfo.getScore()) {
            return;
        }
        // only send network score if not lingering. If lingering, would have already sent score at
        // start of lingering.
        if (mShouldReduceNetworkScore) {
            return;
        }
        if (mWifiConnectedNetworkScorerHolder != null
                && mContext.getResources().getBoolean(
                        R.bool.config_wifiMinConfirmationDurationSendNetworkScoreEnabled)
                /// Turn off hysteresis/dampening for shell commands.
                && !mWifiConnectedNetworkScorerHolder.isShellCommandScorer()) {
            long millis = mClock.getWallClockMillis();
            if (mLastScoreBreachLowTimeMillis != INVALID_WALL_CLOCK_MILLIS) {
                if (mWifiInfo.getRssi()
                        >= mDeviceConfigFacade.getRssiThresholdNotSendLowScoreToCsDbm()) {
                    Log.d(TAG, "Not reporting low score because RSSI is high "
                            + mWifiInfo.getRssi());
                    return;
                }
                if ((millis - mLastScoreBreachLowTimeMillis)
                        < mDeviceConfigFacade.getMinConfirmationDurationSendLowScoreMs()) {
                    Log.d(TAG, "Not reporting low score because elapsed time is shorter than "
                            + "the minimum confirmation duration");
                    return;
                }
            }
            if (mLastScoreBreachHighTimeMillis != INVALID_WALL_CLOCK_MILLIS
                    && (millis - mLastScoreBreachHighTimeMillis)
                            < mDeviceConfigFacade.getMinConfirmationDurationSendHighScoreMs()) {
                Log.d(TAG, "Not reporting high score because elapsed time is shorter than "
                        + "the minimum confirmation duration");
                return;
            }
        }
        // Stay a notch above the transition score if adaptive connectivity is disabled.
        if (!mAdaptiveConnectivityEnabledSettingObserver.get()
                || !mWifiSettingsStore.isWifiScoringEnabled()) {
            mLegacyIntScore = ConnectedScore.WIFI_TRANSITION_SCORE + 1;
            if (mVerboseLoggingEnabled) {
                Log.d(TAG, "Wifi scoring disabled - Stay a notch above the transition score");
            }
        }
        sendNetworkScore();
    }

    /**
     * Container for storing info about external scorer and tracking its death.
     */
    private final class WifiConnectedNetworkScorerHolder implements IBinder.DeathRecipient {
        private final IBinder mBinder;
        private final IWifiConnectedNetworkScorer mScorer;
        private int mSessionId = INVALID_SESSION_ID;
        private boolean mShouldCheckIpLayerOnce = false;

        WifiConnectedNetworkScorerHolder(IBinder binder, IWifiConnectedNetworkScorer scorer) {
            mBinder = binder;
            mScorer = scorer;
        }

        /**
         * Link WiFi connected scorer to death listener.
         */
        public boolean linkScorerToDeath() {
            try {
                mBinder.linkToDeath(this, 0);
            } catch (RemoteException e) {
                Log.e(TAG, "Unable to linkToDeath Wifi connected network scorer " + mScorer, e);
                return false;
            }
            return true;
        }

        /**
         * App hosting the binder has died.
         */
        @Override
        public void binderDied() {
            mWifiThreadRunner.post(() -> revertToDefaultConnectedScorer());
        }

        /**
         * Unlink this object from binder death.
         */
        public void reset() {
            mBinder.unlinkToDeath(this, 0);
        }

        /**
         * Starts a new scoring session.
         */
        public void startSession(int sessionId, boolean isUserSelected) {
            if (sessionId == INVALID_SESSION_ID) {
                throw new IllegalArgumentException();
            }
            if (mSessionId != INVALID_SESSION_ID) {
                // This is not expected to happen, log if it does
                Log.e(TAG, "Stopping session " + mSessionId + " before starting " + sessionId);
                stopSession();
            }
            // Bail now if the scorer has gone away
            if (this != mWifiConnectedNetworkScorerHolder) {
                return;
            }
            mSessionId = sessionId;
            mSessionIdNoReset = sessionId;
            try {
                WifiConnectedSessionInfo sessionInfo =
                        new WifiConnectedSessionInfo.Builder(sessionId)
                                .setUserSelected(isUserSelected)
                                .build();
                mScorer.onStart(sessionInfo);
            } catch (RemoteException e) {
                Log.e(TAG, "Unable to start Wifi connected network scorer " + this, e);
                revertToDefaultConnectedScorer();
            }
        }
        public void stopSession() {
            final int sessionId = mSessionId;
            if (sessionId == INVALID_SESSION_ID) return;
            mSessionId = INVALID_SESSION_ID;
            mShouldCheckIpLayerOnce = false;
            try {
                mScorer.onStop(sessionId);
            } catch (RemoteException e) {
                Log.e(TAG, "Unable to stop Wifi connected network scorer " + this, e);
                revertToDefaultConnectedScorer();
            }
        }

        public boolean isShellCommandScorer() {
            return mScorer instanceof WifiShellCommand.WifiScorer;
        }

        private void setShouldCheckIpLayerOnce(boolean shouldCheckIpLayerOnce) {
            mShouldCheckIpLayerOnce = shouldCheckIpLayerOnce;
        }

        private boolean getShouldCheckIpLayerOnce() {
            return mShouldCheckIpLayerOnce;
        }
    }

    private final ScoreUpdateObserverProxy mScoreUpdateObserverCallback =
            new ScoreUpdateObserverProxy();

    @Nullable
    private WifiConnectedNetworkScorerHolder mWifiConnectedNetworkScorerHolder;

    private final AdaptiveConnectivityEnabledSettingObserver
            mAdaptiveConnectivityEnabledSettingObserver;

    WifiScoreReport(ScoringParams scoringParams, Clock clock, WifiMetrics wifiMetrics,
            ExtendedWifiInfo wifiInfo, WifiNative wifiNative,
            WifiBlocklistMonitor wifiBlocklistMonitor,
            WifiThreadRunner wifiThreadRunner, WifiScoreCard wifiScoreCard,
            DeviceConfigFacade deviceConfigFacade, Context context,
            AdaptiveConnectivityEnabledSettingObserver adaptiveConnectivityEnabledSettingObserver,
            String interfaceName,
            ExternalScoreUpdateObserverProxy externalScoreUpdateObserverProxy,
            WifiSettingsStore wifiSettingsStore) {
        mScoringParams = scoringParams;
        mClock = clock;
        mAdaptiveConnectivityEnabledSettingObserver = adaptiveConnectivityEnabledSettingObserver;
        mAggressiveConnectedScore = new AggressiveConnectedScore(scoringParams, clock);
        mVelocityBasedConnectedScore = new VelocityBasedConnectedScore(scoringParams, clock);
        mWifiMetrics = wifiMetrics;
        mWifiInfo = wifiInfo;
        mWifiNative = wifiNative;
        mWifiBlocklistMonitor = wifiBlocklistMonitor;
        mWifiThreadRunner = wifiThreadRunner;
        mWifiScoreCard = wifiScoreCard;
        mDeviceConfigFacade = deviceConfigFacade;
        mContext = context;
        mInterfaceName = interfaceName;
        mExternalScoreUpdateObserverProxy = externalScoreUpdateObserverProxy;
        mWifiSettingsStore = wifiSettingsStore;
        mWifiInfoNoReset = new WifiInfo(mWifiInfo);
    }

    /**
     * Reset the last calculated score.
     */
    public void reset() {
        mSessionNumber++;
        mLegacyIntScore = ConnectedScore.WIFI_INITIAL_SCORE;
        mIsUsable = true;
        mLastKnownNudCheckScore = ConnectedScore.WIFI_TRANSITION_SCORE;
        mAggressiveConnectedScore.reset();
        if (mVelocityBasedConnectedScore != null) {
            mVelocityBasedConnectedScore.reset();
        }
        mLastDownwardBreachTimeMillis = 0;
        mLastScoreBreachLowTimeMillis = INVALID_WALL_CLOCK_MILLIS;
        mLastScoreBreachHighTimeMillis = INVALID_WALL_CLOCK_MILLIS;
        if (mVerboseLoggingEnabled) Log.d(TAG, "reset");
    }

    /**
     * Enable/Disable verbose logging in score report generation.
     */
    public void enableVerboseLogging(boolean enable) {
        mVerboseLoggingEnabled = enable;
    }

    /**
     * Calculate wifi network score based on updated link layer stats and send the score to
     * the WifiNetworkAgent.
     *
     * If the score has changed from the previous value, update the WifiNetworkAgent.
     *
     * Called periodically (POLL_RSSI_INTERVAL_MSECS) about every 3 seconds.
     */
    public void calculateAndReportScore() {
        // Bypass AOSP scorer if Wifi connected network scorer is set
        if (mWifiConnectedNetworkScorerHolder != null) {
            return;
        }

        if (mWifiInfo.getRssi() == mWifiInfo.INVALID_RSSI) {
            Log.d(TAG, "Not reporting score because RSSI is invalid");
            return;
        }
        int score;

        long millis = mClock.getWallClockMillis();
        mVelocityBasedConnectedScore.updateUsingWifiInfo(mWifiInfo, millis);

        int s2 = mVelocityBasedConnectedScore.generateScore();
        score = s2;

        if (mWifiInfo.getScore() > ConnectedScore.WIFI_TRANSITION_SCORE
                && score <= ConnectedScore.WIFI_TRANSITION_SCORE
                && mWifiInfo.getSuccessfulTxPacketsPerSecond()
                >= mScoringParams.getYippeeSkippyPacketsPerSecond()
                && mWifiInfo.getSuccessfulRxPacketsPerSecond()
                >= mScoringParams.getYippeeSkippyPacketsPerSecond()
        ) {
            score = ConnectedScore.WIFI_TRANSITION_SCORE + 1;
        }

        if (mWifiInfo.getScore() > ConnectedScore.WIFI_TRANSITION_SCORE
                && score <= ConnectedScore.WIFI_TRANSITION_SCORE) {
            // We don't want to trigger a downward breach unless the rssi is
            // below the entry threshold.  There is noise in the measured rssi, and
            // the kalman-filtered rssi is affected by the trend, so check them both.
            // TODO(b/74613347) skip this if there are other indications to support the low score
            int entry = mScoringParams.getEntryRssi(mWifiInfo.getFrequency());
            if (mVelocityBasedConnectedScore.getFilteredRssi() >= entry
                    || mWifiInfo.getRssi() >= entry) {
                // Stay a notch above the transition score to reduce ambiguity.
                score = ConnectedScore.WIFI_TRANSITION_SCORE + 1;
            }
        }

        if (mWifiInfo.getScore() >= ConnectedScore.WIFI_TRANSITION_SCORE
                && score < ConnectedScore.WIFI_TRANSITION_SCORE) {
            mLastDownwardBreachTimeMillis = millis;
        } else if (mWifiInfo.getScore() < ConnectedScore.WIFI_TRANSITION_SCORE
                && score >= ConnectedScore.WIFI_TRANSITION_SCORE) {
            // Staying at below transition score for a certain period of time
            // to prevent going back to wifi network again in a short time.
            long elapsedMillis = millis - mLastDownwardBreachTimeMillis;
            if (elapsedMillis < MIN_TIME_TO_KEEP_BELOW_TRANSITION_SCORE_MILLIS) {
                score = mWifiInfo.getScore();
            }
        }
        //sanitize boundaries
        if (score > ConnectedScore.WIFI_MAX_SCORE) {
            score = ConnectedScore.WIFI_MAX_SCORE;
        }
        if (score < 0) {
            score = 0;
        }

        // report score
        mLegacyIntScore = score;
        reportNetworkScoreToConnectivityServiceIfNecessary();
        updateWifiMetrics(millis, s2);
    }

    private int getCurrentNetId() {
        int netId = 0;
        if (mNetworkAgent != null) {
            final Network network = mNetworkAgent.getNetwork();
            if (network != null) {
                netId = network.getNetId();
            }
        }
        return netId;
    }

    @Nullable
    private NetworkCapabilities getCurrentNetCapabilities() {
        return mNetworkAgent == null ? null : mNetworkAgent.getCurrentNetworkCapabilities();
    }

    private int getCurrentSessionId() {
        return sessionIdFromNetId(getCurrentNetId());
    }

    /**
     * Encodes a network id into a scoring session id.
     *
     * We use a different numeric value for session id and the network id
     * to make it clear that these are not the same thing. However, for
     * easier debugging, the network id can be recovered by dropping the
     * last decimal digit (at least until they get very, very, large).
     */
    public static int sessionIdFromNetId(final int netId) {
        if (netId <= 0) return INVALID_SESSION_ID;
        return (int) (((long) netId * 10 + (8 - (netId % 9))) % Integer.MAX_VALUE + 1);
    }

    private void updateWifiMetrics(long now, int s2) {
        int netId = getCurrentNetId();

        mAggressiveConnectedScore.updateUsingWifiInfo(mWifiInfo, now);
        int s1 = mAggressiveConnectedScore.generateScore();
        logLinkMetrics(now, netId, s1, s2, mLegacyIntScore);

        if (mLegacyIntScore != mWifiInfo.getScore()) {
            if (mVerboseLoggingEnabled) {
                Log.d(TAG, "report new wifi score " + mLegacyIntScore);
            }
            mWifiInfo.setScore(mLegacyIntScore);
        }
        mWifiMetrics.incrementWifiScoreCount(mInterfaceName, mLegacyIntScore);
    }

    private static final double TIME_CONSTANT_MILLIS = 30.0e+3;
    private static final long NUD_THROTTLE_MILLIS = 5000;
    private long mLastKnownNudCheckTimeMillis = 0;
    private int mLastKnownNudCheckScore = ConnectedScore.WIFI_TRANSITION_SCORE;
    private int mNudYes = 0;    // Counts when we voted for a NUD
    private int mNudCount = 0;  // Counts when we were told a NUD was sent

    /**
     * Recommends that a layer 3 check be done
     *
     * The caller can use this to (help) decide that an IP reachability check
     * is desirable. The check is not done here; that is the caller's responsibility.
     *
     * @return true to indicate that an IP reachability check is recommended
     */
    public boolean shouldCheckIpLayer() {
        // Don't recommend if adaptive connectivity is disabled.
        if (!mAdaptiveConnectivityEnabledSettingObserver.get()
                || !mWifiSettingsStore.isWifiScoringEnabled()) {
            if (mVerboseLoggingEnabled) {
                Log.d(TAG, "Wifi scoring disabled - Don't check IP layer");
            }
            return false;
        }
        long millis = mClock.getWallClockMillis();
        long deltaMillis = millis - mLastKnownNudCheckTimeMillis;
        // Don't ever ask back-to-back - allow at least 5 seconds
        // for the previous one to finish.
        if (deltaMillis < NUD_THROTTLE_MILLIS) {
            return false;
        }
        if (SdkLevel.isAtLeastS() && mWifiConnectedNetworkScorerHolder != null) {
            if (!mWifiConnectedNetworkScorerHolder.getShouldCheckIpLayerOnce()) {
                return false;
            }
            mNudYes++;
            return true;
        }
        int nud = mScoringParams.getNudKnob();
        if (nud == 0) {
            return false;
        }
        // nextNudBreach is the bar the score needs to cross before we ask for NUD
        double nextNudBreach = ConnectedScore.WIFI_TRANSITION_SCORE;
        if (mWifiConnectedNetworkScorerHolder == null) {
            // nud is between 1 and 10 at this point
            double deltaLevel = 11 - nud;
            // If we were below threshold the last time we checked, then compute a new bar
            // that starts down from there and decays exponentially back up to the steady-state
            // bar. If 5 time constants have passed, we are 99% of the way there, so skip the math.
            if (mLastKnownNudCheckScore < ConnectedScore.WIFI_TRANSITION_SCORE
                    && deltaMillis < 5.0 * TIME_CONSTANT_MILLIS) {
                double a = Math.exp(-deltaMillis / TIME_CONSTANT_MILLIS);
                nextNudBreach =
                        a * (mLastKnownNudCheckScore - deltaLevel) + (1.0 - a) * nextNudBreach;
            }
        }
        if (mLegacyIntScore >= nextNudBreach) {
            return false;
        }
        mNudYes++;
        return true;
    }

    /**
     * Should be called when a reachability check has been issued
     *
     * When the caller has requested an IP reachability check, calling this will
     * help to rate-limit requests via shouldCheckIpLayer()
     */
    public void noteIpCheck() {
        long millis = mClock.getWallClockMillis();
        mLastKnownNudCheckTimeMillis = millis;
        mLastKnownNudCheckScore = mLegacyIntScore;
        mNudCount++;
        // Make sure that only one NUD operation can be triggered.
        if (mWifiConnectedNetworkScorerHolder != null) {
            mWifiConnectedNetworkScorerHolder.setShouldCheckIpLayerOnce(false);
        }
    }

    /**
     * Data for dumpsys
     *
     * These are stored as csv formatted lines
     */
    private LinkedList<String> mLinkMetricsHistory = new LinkedList<String>();

    /**
     * Data logging for dumpsys
     */
    private void logLinkMetrics(long now, int netId, int s1, int s2, int score) {
        if (now < FIRST_REASONABLE_WALL_CLOCK) return;
        double rssi = mWifiInfo.getRssi();
        double filteredRssi = -1;
        double rssiThreshold = -1;
        if (mWifiConnectedNetworkScorerHolder == null) {
            filteredRssi = mVelocityBasedConnectedScore.getFilteredRssi();
            rssiThreshold = mVelocityBasedConnectedScore.getAdjustedRssiThreshold();
        }
        int freq = mWifiInfo.getFrequency();
        int txLinkSpeed = mWifiInfo.getLinkSpeed();
        int rxLinkSpeed = mWifiInfo.getRxLinkSpeedMbps();
        WifiScoreCard.PerNetwork network = mWifiScoreCard.lookupNetwork(mWifiInfo.getSSID());
        int txThroughputMbps = network.getTxLinkBandwidthKbps() / 1000;
        int rxThroughputMbps = network.getRxLinkBandwidthKbps() / 1000;
        double txSuccessRate = mWifiInfo.getSuccessfulTxPacketsPerSecond();
        double txRetriesRate = mWifiInfo.getRetriedTxPacketsPerSecond();
        double txBadRate = mWifiInfo.getLostTxPacketsPerSecond();
        double rxSuccessRate = mWifiInfo.getSuccessfulRxPacketsPerSecond();
        long totalBeaconRx = mWifiMetrics.getTotalBeaconRxCount();
        String s;
        try {
            String timestamp = new SimpleDateFormat("MM-dd HH:mm:ss.SSS").format(new Date(now));
            s = String.format(Locale.US, // Use US to avoid comma/decimal confusion
                    "%s,%d,%d,%.1f,%.1f,%.1f,%d,%d,%d,%d,%d,%d,%.2f,%.2f,%.2f,%.2f,%d,%d,%d,%d,%d",
                    timestamp, mSessionNumber, netId,
                    rssi, filteredRssi, rssiThreshold, freq, txLinkSpeed, rxLinkSpeed,
                    txThroughputMbps, rxThroughputMbps, totalBeaconRx,
                    txSuccessRate, txRetriesRate, txBadRate, rxSuccessRate,
                    mNudYes, mNudCount,
                    s1, s2, score);

        } catch (Exception e) {
            Log.e(TAG, "format problem", e);
            return;
        }
        synchronized (mLinkMetricsHistory) {
            mLinkMetricsHistory.add(s);
            while (mLinkMetricsHistory.size() > DUMPSYS_ENTRY_COUNT_LIMIT) {
                mLinkMetricsHistory.removeFirst();
            }
        }
    }

    /**
     * Tag to be used in dumpsys request
     */
    public static final String DUMP_ARG = "WifiScoreReport";

    /**
     * Dump logged signal strength and traffic measurements.
     * @param fd unused
     * @param pw PrintWriter for writing dump to
     * @param args unused
     */
    public void dump(FileDescriptor fd, PrintWriter pw, String[] args) {
        LinkedList<String> history;
        synchronized (mLinkMetricsHistory) {
            history = new LinkedList<>(mLinkMetricsHistory);
        }
        pw.println("time,session,netid,rssi,filtered_rssi,rssi_threshold,freq,txLinkSpeed,"
                + "rxLinkSpeed,txTput,rxTput,bcnCnt,tx_good,tx_retry,tx_bad,rx_pps,nudrq,nuds,"
                + "s1,s2,score");
        for (String line : history) {
            pw.println(line);
        }
        history.clear();
        pw.println("externalScorerActive=" + (mWifiConnectedNetworkScorerHolder != null));
        pw.println("mShouldReduceNetworkScore=" + mShouldReduceNetworkScore);
    }

    /**
     * Set a scorer for Wi-Fi connected network score handling.
     * @param binder
     * @param scorer
     */
    public boolean setWifiConnectedNetworkScorer(IBinder binder,
            IWifiConnectedNetworkScorer scorer) {
        if (binder == null || scorer == null) return false;
        // Enforce that only a single scorer can be set successfully.
        if (mWifiConnectedNetworkScorerHolder != null) {
            Log.e(TAG, "Failed to set current scorer because one scorer is already set");
            return false;
        }
        WifiConnectedNetworkScorerHolder scorerHolder =
                new WifiConnectedNetworkScorerHolder(binder, scorer);
        if (!scorerHolder.linkScorerToDeath()) {
            return false;
        }
        mWifiConnectedNetworkScorerHolder = scorerHolder;

        // Register to receive updates from external scorer.
        mExternalScoreUpdateObserverProxy.registerCallback(mScoreUpdateObserverCallback);

        // Disable AOSP scorer
        mVelocityBasedConnectedScore = null;
        mWifiMetrics.setIsExternalWifiScorerOn(true);
        // If there is already a connection, start a new session
        final int netId = getCurrentNetId();
        if (netId > 0 && !mShouldReduceNetworkScore) {
            startConnectedNetworkScorer(netId, mIsUserSelected);
        }
        return true;
    }

    /**
     * Clear an existing scorer for Wi-Fi connected network score handling.
     */
    public void clearWifiConnectedNetworkScorer() {
        if (mWifiConnectedNetworkScorerHolder == null) {
            return;
        }
        mWifiConnectedNetworkScorerHolder.reset();
        revertToDefaultConnectedScorer();
    }

    /**
     * If this connection is not going to be the default route on the device when cellular is
     * present, don't send this connection to external scorer for scoring (since scoring only makes
     * sense if we need to score wifi vs cellular to determine the default network).
     *
     * Hence, we ignore local only or restricted wifi connections.
     * @return true if the connection is local only or restricted, false otherwise.
     */
    private boolean isLocalOnlyOrRestrictedConnection() {
        final NetworkCapabilities nc = getCurrentNetCapabilities();
        if (nc == null) return false;
        if (SdkLevel.isAtLeastS()) {
            // restricted connection support only added in S.
            if (nc.hasCapability(NetworkCapabilities.NET_CAPABILITY_OEM_PAID)
                    || nc.hasCapability(NetworkCapabilities.NET_CAPABILITY_OEM_PRIVATE)) {
                // restricted connection.
                Log.v(TAG, "Restricted connection, ignore.");
                return true;
            }
        }
        if (!nc.hasCapability(NetworkCapabilities.NET_CAPABILITY_INTERNET)) {
            // local only connection.
            Log.v(TAG, "Local only connection, ignore.");
            return true;
        }
        return false;
    }

    /**
     * Start the registered Wi-Fi connected network scorer.
     * @param netId identifies the current android.net.Network
     */
    public void startConnectedNetworkScorer(int netId, boolean isUserSelected) {
        mIsUserSelected = isUserSelected;
        final int sessionId = getCurrentSessionId();
        if (mWifiConnectedNetworkScorerHolder == null
                || netId != getCurrentNetId()
                || isLocalOnlyOrRestrictedConnection()
                || sessionId == INVALID_SESSION_ID) {
            Log.w(TAG, "Cannot start external scoring"
                    + " netId=" + netId
                    + " currentNetId=" + getCurrentNetId()
                    + " currentNetCapabilities=" + getCurrentNetCapabilities()
                    + " sessionId=" + sessionId);
            return;
        }
        mWifiInfo.setScore(ConnectedScore.WIFI_MAX_SCORE);
        mWifiConnectedNetworkScorerHolder.startSession(sessionId, mIsUserSelected);
        mWifiInfoNoReset.setBSSID(mWifiInfo.getBSSID());
        mWifiInfoNoReset.setSSID(mWifiInfo.getWifiSsid());
        mWifiInfoNoReset.setRssi(mWifiInfo.getRssi());
        mLastScoreBreachLowTimeMillis = INVALID_WALL_CLOCK_MILLIS;
        mLastScoreBreachHighTimeMillis = INVALID_WALL_CLOCK_MILLIS;
    }

    /**
     * Stop the registered Wi-Fi connected network scorer.
     */
    public void stopConnectedNetworkScorer() {
        mNetworkAgent = null;
        if (mWifiConnectedNetworkScorerHolder == null) {
            return;
        }
        mWifiConnectedNetworkScorerHolder.stopSession();

        long millis = mClock.getWallClockMillis();
        // Blocklist the current BSS
        if ((mLastScoreBreachLowTimeMillis != INVALID_WALL_CLOCK_MILLIS)
                && ((millis - mLastScoreBreachLowTimeMillis)
                        >= MIN_TIME_TO_WAIT_BEFORE_BLOCKLIST_BSSID_MILLIS)) {
            mWifiBlocklistMonitor.handleBssidConnectionFailure(mWifiInfo.getBSSID(),
                    mWifiInfo.getSSID(),
                    WifiBlocklistMonitor.REASON_FRAMEWORK_DISCONNECT_CONNECTED_SCORE,
                    mWifiInfo.getRssi());
            mLastScoreBreachLowTimeMillis = INVALID_WALL_CLOCK_MILLIS;
        }
    }

    /**
     * Set NetworkAgent
     */
    public void setNetworkAgent(WifiNetworkAgent agent) {
        WifiNetworkAgent oldAgent = mNetworkAgent;
        mNetworkAgent = agent;
        // if mNetworkAgent was null previously, then the score wasn't sent to ConnectivityService.
        // Send it now that the NetworkAgent has been set.
        if (oldAgent == null && mNetworkAgent != null) {
            sendNetworkScore();
        }
    }

    /** Get cached score */
    @VisibleForTesting
    @RequiresApi(Build.VERSION_CODES.S)
    public NetworkScore getScore() {
        return getScoreBuilder().build();
    }

    @RequiresApi(Build.VERSION_CODES.S)
    private NetworkScore.Builder getScoreBuilder() {
        // We should force keep connected for a MBB CMM which is not lingering.
        boolean shouldForceKeepConnected =
                mCurrentRole == ActiveModeManager.ROLE_CLIENT_SECONDARY_TRANSIENT
                        && !mShouldReduceNetworkScore;
        int keepConnectedReason =
                shouldForceKeepConnected
                        ? NetworkScore.KEEP_CONNECTED_FOR_HANDOVER
                        : NetworkScore.KEEP_CONNECTED_NONE;
        boolean exiting = SdkLevel.isAtLeastS() && mWifiConnectedNetworkScorerHolder != null
                ? !mIsUsable : mLegacyIntScore < ConnectedScore.WIFI_TRANSITION_SCORE;
        return new NetworkScore.Builder()
                .setLegacyInt(mShouldReduceNetworkScore ? LINGERING_SCORE : mLegacyIntScore)
                .setTransportPrimary(mCurrentRole == ActiveModeManager.ROLE_CLIENT_PRIMARY)
                .setExiting(exiting)
                .setKeepConnectedReason(keepConnectedReason);
    }

    /** Get legacy int score. */
    @VisibleForTesting
    public int getLegacyIntScore() {
        // When S Wifi module is run on R:
        // - mShouldReduceNetworkScore is useless since MBB doesn't exist on R, so there isn't any
        //   forced lingering.
        // - mIsUsable can't be set as notifyStatusUpdate() for external scorer didn't exist on R
        //   SDK (assume that only R platform + S Wifi module + R external scorer is possible,
        //   and R platform + S Wifi module + S external scorer is not possible)
        // Thus, it's ok to return the raw int score on R.
        return mLegacyIntScore;
    }

    /** Get counts when we voted for a NUD. */
    @VisibleForTesting
    public int getNudYes() {
        return mNudYes;
    }

    private void revertToDefaultConnectedScorer() {
        Log.d(TAG, "Using VelocityBasedConnectedScore");
        mVelocityBasedConnectedScore = new VelocityBasedConnectedScore(mScoringParams, mClock);
        mWifiConnectedNetworkScorerHolder = null;
        mExternalScoreUpdateObserverProxy.unregisterCallback(mScoreUpdateObserverCallback);
        mWifiMetrics.setIsExternalWifiScorerOn(false);
    }

    /**
     * This is a function of {@link #mCurrentRole} {@link #mShouldReduceNetworkScore}, and
     * {@link #mLegacyIntScore}, and should be called when any of them changes.
     */
    private void sendNetworkScore() {
        if (mNetworkAgent == null) {
            return;
        }
        if (SdkLevel.isAtLeastS()) {
            // NetworkScore was introduced in S
            mNetworkAgent.sendNetworkScore(getScore());
        } else {
            mNetworkAgent.sendNetworkScore(getLegacyIntScore());
        }
    }

    /** Called when the owner {@link ConcreteClientModeManager}'s role changes. */
    public void onRoleChanged(@Nullable ClientRole role) {
        mCurrentRole = role;
        sendNetworkScore();
    }
}
