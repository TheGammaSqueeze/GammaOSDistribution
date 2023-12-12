/*
 * Copyright (C) 2022 The Android Open Source Project
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

package com.android.car.telemetry.publisher;

import static android.net.NetworkStats.TAG_NONE;
import static android.net.NetworkTemplate.OEM_MANAGED_NO;
import static android.net.NetworkTemplate.OEM_MANAGED_YES;

import static com.google.common.truth.Truth.assertThat;

import static org.mockito.Mockito.mock;

import android.annotation.NonNull;
import android.car.telemetry.TelemetryProto;
import android.car.telemetry.TelemetryProto.ConnectivityPublisher.OemType;
import android.car.telemetry.TelemetryProto.ConnectivityPublisher.Transport;
import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkIdentity;
import android.net.NetworkTemplate;
import android.os.Looper;
import android.os.PersistableBundle;
import android.os.RemoteException;
import android.os.SystemClock;
import android.telephony.TelephonyManager;

import com.android.car.telemetry.databroker.DataSubscriber;
import com.android.car.telemetry.publisher.net.FakeNetworkStats;
import com.android.car.telemetry.publisher.net.NetworkStatsServiceProxy;
import com.android.car.telemetry.publisher.net.RefinedStats;
import com.android.car.test.FakeHandlerWrapper;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.junit.MockitoJUnitRunner;

import java.time.Duration;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * Tests for {@link ConnectivityPublisher}.
 *
 * <p>Note that {@link TAG_NONE} is a total value across all the tags. NetworkStatsService returns 2
 * types of netstats: summary for all (tag is equal to 0, i.e. TAG_NONE), and summary per tag.
 */
@RunWith(MockitoJUnitRunner.class)
public class ConnectivityPublisherTest {
    private static final TelemetryProto.Publisher PUBLISHER_WIFI_OEM_NONE =
            TelemetryProto.Publisher.newBuilder()
                    .setConnectivity(
                            TelemetryProto.ConnectivityPublisher.newBuilder()
                                    .setTransport(Transport.TRANSPORT_WIFI)
                                    .setOemType(OemType.OEM_NONE))
                    .build();
    private static final TelemetryProto.Publisher PUBLISHER_WIFI_OEM_MANAGED =
            TelemetryProto.Publisher.newBuilder()
                    .setConnectivity(
                            TelemetryProto.ConnectivityPublisher.newBuilder()
                                    .setTransport(Transport.TRANSPORT_WIFI)
                                    .setOemType(OemType.OEM_MANAGED))
                    .build();
    private static final TelemetryProto.Publisher PUBLISHER_CELL_OEM_NONE =
            TelemetryProto.Publisher.newBuilder()
                    .setConnectivity(
                            TelemetryProto.ConnectivityPublisher.newBuilder()
                                    .setTransport(Transport.TRANSPORT_CELLULAR)
                                    .setOemType(OemType.OEM_NONE))
                    .build();
    private static final TelemetryProto.Subscriber SUBSCRIBER_WIFI_OEM_NONE =
            TelemetryProto.Subscriber.newBuilder()
                    .setHandler("empty_handler")
                    .setPublisher(PUBLISHER_WIFI_OEM_NONE)
                    .build();
    private static final TelemetryProto.Subscriber SUBSCRIBER_WIFI_OEM_MANAGED =
            TelemetryProto.Subscriber.newBuilder()
                    .setHandler("empty_handler")
                    .setPublisher(PUBLISHER_WIFI_OEM_MANAGED)
                    .build();
    private static final TelemetryProto.Subscriber SUBSCRIBER_CELL_OEM_NONE =
            TelemetryProto.Subscriber.newBuilder()
                    .setHandler("empty_handler")
                    .setPublisher(PUBLISHER_CELL_OEM_NONE)
                    .build();
    private static final TelemetryProto.MetricsConfig METRICS_CONFIG =
            TelemetryProto.MetricsConfig.newBuilder()
                    .setName("myconfig")
                    .setVersion(1)
                    .addSubscribers(SUBSCRIBER_WIFI_OEM_NONE)
                    .addSubscribers(SUBSCRIBER_WIFI_OEM_MANAGED)
                    .addSubscribers(SUBSCRIBER_CELL_OEM_NONE)
                    .setScript("function empty_handler()\nend")
                    .build();

    /** See {@code ConnectivityPublisher#pullInitialNetstats()}. */
    private static final int BASELINE_PULL_COUNT = 8;

    // Test network usage tags.
    private static final int TAG_1 = 1;
    private static final int TAG_2 = 2;

    // Test network usage uids.
    private static final int UID_1 = 1;
    private static final int UID_2 = 2;
    private static final int UID_3 = 3;
    private static final int UID_4 = 4;

    private final long mNow = System.currentTimeMillis(); // since epoch

    private final FakeHandlerWrapper mFakeHandler =
            new FakeHandlerWrapper(Looper.getMainLooper(), FakeHandlerWrapper.Mode.QUEUEING);

    private final FakeDataSubscriber mDataSubscriberWifi =
            new FakeDataSubscriber(METRICS_CONFIG, SUBSCRIBER_WIFI_OEM_NONE);
    private final FakeDataSubscriber mDataSubscriberWifiOemManaged =
            new FakeDataSubscriber(METRICS_CONFIG, SUBSCRIBER_WIFI_OEM_MANAGED);
    private final FakeDataSubscriber mDataSubscriberCell =
            new FakeDataSubscriber(METRICS_CONFIG, SUBSCRIBER_CELL_OEM_NONE);

    private final FakeNetworkStatsManager mFakeManager = new FakeNetworkStatsManager();

    private ConnectivityPublisher mPublisher; // subject

    @Before
    public void setUp() throws Exception {
        mPublisher =
                new ConnectivityPublisher(
                        this::onPublisherFailure,
                        mFakeManager,
                        mFakeHandler.getMockHandler(),
                        mock(Context.class));
    }

    @Test
    public void testAddDataSubscriber_storesIt_andStartsPeriodicPull() {
        mPublisher.addDataSubscriber(mDataSubscriberWifi);

        assertThat(mPublisher.hasDataSubscriber(mDataSubscriberWifi)).isTrue();
        // One for initial pull, second one for this addDataSubscriber.
        assertThat(mFakeHandler.getQueuedMessages()).hasSize(2);
    }

    @Test
    public void testRemoveDataSubscriber_removesIt() {
        mPublisher.addDataSubscriber(mDataSubscriberWifi);

        mPublisher.removeDataSubscriber(mDataSubscriberWifi);

        assertThat(mPublisher.hasDataSubscriber(mDataSubscriberWifi)).isFalse();
        // Only initial pull left, because we removed the last subscriber.
        assertThat(mFakeHandler.getQueuedMessages()).hasSize(1);
    }

    @Test
    public void testRemoveDataSubscriber_leavesPeriodicTask_ifOtherSubscriberExists() {
        mPublisher.addDataSubscriber(mDataSubscriberWifi);
        mPublisher.addDataSubscriber(mDataSubscriberCell);

        mPublisher.removeDataSubscriber(mDataSubscriberWifi);

        assertThat(mPublisher.hasDataSubscriber(mDataSubscriberWifi)).isFalse();
        // Only initial pull left + periodic puller.
        assertThat(mFakeHandler.getQueuedMessages()).hasSize(2);
    }

    @Test
    public void testRemoveDataSubscriber_givenWrongSubscriber_doesNothing() {
        mPublisher.addDataSubscriber(mDataSubscriberWifi);

        mPublisher.removeDataSubscriber(mDataSubscriberCell);

        assertThat(mPublisher.hasDataSubscriber(mDataSubscriberWifi)).isTrue();
        // One for initial pull, second one for this addDataSubscriber.
        assertThat(mFakeHandler.getQueuedMessages()).hasSize(2);
    }

    @Test
    public void testRemoveAllDataSubscribers_removesAll_andStopsPeriodicPull() {
        mPublisher.addDataSubscriber(mDataSubscriberWifi);
        mPublisher.addDataSubscriber(mDataSubscriberCell);

        mPublisher.removeAllDataSubscribers();

        assertThat(mPublisher.hasDataSubscriber(mDataSubscriberWifi)).isFalse();
        // Only initial pull left, because we removed the subscribers.
        assertThat(mFakeHandler.getQueuedMessages()).hasSize(1);
    }

    @Test
    public void testSchedulesNextPeriodicPullInHandler() {
        mFakeHandler.dispatchQueuedMessages(); // pulls empty baseline netstats
        mPublisher.addDataSubscriber(mDataSubscriberWifi);

        mFakeHandler.dispatchQueuedMessages(); // Current pull.

        assertThat(mFakeHandler.getQueuedMessages()).hasSize(1); // Next pull.
    }

    @Test
    public void testPullsOnlyNecessaryData() {
        mFakeHandler.dispatchQueuedMessages(); // pulls empty baseline netstats
        mPublisher.addDataSubscriber(mDataSubscriberWifi);

        mFakeHandler.dispatchQueuedMessages();

        // Pulls netstats only once for wifi.
        assertThat(mFakeManager.getMethodCallCount("querySummary"))
                .isEqualTo(BASELINE_PULL_COUNT + 1);
    }

    @Test
    public void testPullsOnlyNecessaryData_wifiAndMobile() {
        mFakeHandler.dispatchQueuedMessages(); // pulls empty baseline netstats
        mPublisher.addDataSubscriber(mDataSubscriberWifi);
        mPublisher.addDataSubscriber(mDataSubscriberCell);

        mFakeHandler.dispatchQueuedMessages();

        assertThat(mFakeManager.getMethodCallCount("querySummary"))
                .isEqualTo(BASELINE_PULL_COUNT + 2);
    }

    @Test
    public void testPullsTaggedAndUntaggedMobileStats() {
        mFakeHandler.dispatchQueuedMessages(); // pulls empty baseline netstats
        mFakeManager.addMobileStats(UID_1, TAG_1, 2500L, 3500L, OEM_MANAGED_NO, mNow);
        mFakeManager.addMobileStats(UID_1, TAG_NONE, 2502L, 3502L, OEM_MANAGED_NO, mNow);
        mFakeManager.addWifiStats(UID_1, TAG_2, 30, 30, OEM_MANAGED_NO, mNow);
        mFakeManager.addWifiStats(UID_2, TAG_2, 10, 10, OEM_MANAGED_YES, mNow);
        mFakeManager.addWifiStats(UID_3, TAG_2, 6, 6, OEM_MANAGED_YES, mNow);
        mPublisher.addDataSubscriber(mDataSubscriberCell);

        mFakeHandler.dispatchQueuedMessages();

        assertThat(mDataSubscriberCell.mPushedData).hasSize(1);
        PersistableBundle result = mDataSubscriberCell.get(0);
        // Matches only "UID_1/TAG_1" and "UID_1/TAG_NONE" above.
        assertThat(result.getLong("startMillis")).isLessThan(mNow);
        assertThat(result.getLong("endMillis")).isGreaterThan(result.getLong("startMillis"));
        assertThat(result.getInt("size")).isEqualTo(2);
        assertThat(result.getIntArray("uid")).asList().containsExactly(UID_1, UID_1);
        assertThat(result.getIntArray("tag")).asList().containsExactly(TAG_1, TAG_NONE);
        assertThat(result.getLongArray("rxBytes")).asList().containsExactly(2500L, 2502L);
        assertThat(result.getLongArray("txBytes")).asList().containsExactly(3500L, 3502L);
    }

    @Test
    public void testPullsOemManagedWifiStats() {
        mFakeHandler.dispatchQueuedMessages(); // pulls empty baseline netstats
        mFakeManager.addMobileStats(UID_1, TAG_2, 5000, 5000, OEM_MANAGED_NO, mNow);
        mFakeManager.addWifiStats(UID_1, TAG_1, 30, 30, OEM_MANAGED_NO, mNow);
        mFakeManager.addWifiStats(UID_2, TAG_NONE, 100L, 200L, OEM_MANAGED_YES, mNow);
        mFakeManager.addWifiStats(UID_3, TAG_2, 6L, 7L, OEM_MANAGED_YES, mNow);
        mPublisher.addDataSubscriber(mDataSubscriberWifiOemManaged);

        mFakeHandler.dispatchQueuedMessages();

        assertThat(mDataSubscriberWifiOemManaged.mPushedData).hasSize(1);
        PersistableBundle result = mDataSubscriberWifiOemManaged.get(0);
        // Matches only UID_2 + UID_3.
        assertThat(result.getInt("size")).isEqualTo(2);
        assertThat(result.getIntArray("uid")).asList().containsExactly(UID_2, UID_3);
        assertThat(result.getIntArray("tag")).asList().containsExactly(TAG_NONE, TAG_2);
        assertThat(result.getLongArray("rxBytes")).asList().containsExactly(100L, 6L);
        assertThat(result.getLongArray("txBytes")).asList().containsExactly(200L, 7L);
    }

    @Test
    public void testPullsOemNotManagedWifiStats() {
        mFakeHandler.dispatchQueuedMessages(); // pulls empty baseline netstats
        mFakeManager.addMobileStats(UID_4, TAG_2, 5000, 5000, OEM_MANAGED_NO, mNow);
        mFakeManager.addWifiStats(UID_1, TAG_1, 30, 30, OEM_MANAGED_NO, mNow);
        mFakeManager.addWifiStats(UID_2, TAG_1, 10, 10, OEM_MANAGED_YES, mNow);
        mFakeManager.addWifiStats(UID_3, TAG_1, 6, 6, OEM_MANAGED_YES, mNow);
        mPublisher.addDataSubscriber(mDataSubscriberWifi);

        mFakeHandler.dispatchQueuedMessages();

        assertThat(mDataSubscriberWifi.mPushedData).hasSize(1);
        PersistableBundle result = mDataSubscriberWifi.get(0);
        // Matches only UID_1.
        assertThat(result.getInt("size")).isEqualTo(1);
        assertThat(result.getIntArray("uid")).asList().containsExactly(UID_1);
        assertThat(result.getIntArray("tag")).asList().containsExactly(TAG_1);
        assertThat(result.getLongArray("txBytes")).asList().containsExactly(30L);
        assertThat(result.getLongArray("rxBytes")).asList().containsExactly(30L);
    }

    @Test
    public void testPullsStatsOnlyBetweenBootTimeMinus2HoursAndNow() {
        mFakeHandler.dispatchQueuedMessages(); // pulls empty baseline netstats
        long mBootTimeMillis = mNow - SystemClock.elapsedRealtime(); // since epoch
        long bootMinus30Mins = mBootTimeMillis - Duration.ofMinutes(30).toMillis();
        long bootMinus5Hours = mBootTimeMillis - Duration.ofHours(5).toMillis();
        mFakeManager.addMobileStats(UID_1, TAG_2, 5000, 5000, OEM_MANAGED_NO, mNow);
        mFakeManager.addWifiStats(UID_1, TAG_1, 10, 10, OEM_MANAGED_NO, mNow);
        mFakeManager.addWifiStats(UID_2, TAG_1, 10, 10, OEM_MANAGED_NO, bootMinus30Mins);
        mFakeManager.addWifiStats(UID_3, TAG_1, 7, 7, OEM_MANAGED_NO, bootMinus5Hours);
        mPublisher.addDataSubscriber(mDataSubscriberWifi);

        mFakeHandler.dispatchQueuedMessages();

        assertThat(mDataSubscriberWifi.mPushedData).hasSize(1);
        PersistableBundle result = mDataSubscriberWifi.get(0);
        // Only UID_1 and UID_2 are fetched, because other stats are outside
        // of the time range.
        assertThat(result.getInt("size")).isEqualTo(2);
        assertThat(result.getIntArray("uid")).asList().containsExactly(UID_1, UID_2);
        assertThat(result.getIntArray("tag")).asList().containsExactly(TAG_1, TAG_1);
        assertThat(result.getLongArray("txBytes")).asList().containsExactly(10L, 10L);
        assertThat(result.getLongArray("rxBytes")).asList().containsExactly(10L, 10L);
    }

    @Test
    public void testPushesDataAsNotLarge() {
        mPublisher.addDataSubscriber(mDataSubscriberWifi);
        mFakeManager.addWifiStats(UID_1, TAG_1, 10, 10, OEM_MANAGED_NO, mNow);

        mFakeHandler.dispatchQueuedMessages();

        // The final data should not be marked "large".
        assertThat(mDataSubscriberWifi.mPushedData.get(0).mIsLargeData).isFalse();
    }

    @Test
    public void testSubtractsFromInitialPull() {
        long someTimeAgo = mNow - Duration.ofMinutes(1).toMillis();
        mFakeManager.addWifiStats(UID_4, TAG_1, 10, 10, OEM_MANAGED_YES, someTimeAgo);
        mFakeManager.addWifiStats(UID_4, TAG_1, 11, 11, OEM_MANAGED_YES, someTimeAgo);
        mFakeManager.addWifiStats(UID_4, TAG_1, 12, 12, OEM_MANAGED_NO, someTimeAgo);
        mFakeHandler.dispatchQueuedMessages(); // pulls 10, 11, 12 bytes.

        // A hack to force the publisher to compute the diff from the initial pull.
        // Otherwise we'll get "(100 + 12) - 12".
        mFakeManager.clearNetworkStats();
        mFakeManager.addWifiStats(UID_4, TAG_1, 100, 100, OEM_MANAGED_NO, mNow);
        mPublisher.addDataSubscriber(mDataSubscriberWifi);
        mFakeHandler.dispatchQueuedMessages();

        assertThat(mDataSubscriberWifi.mPushedData).hasSize(1);
        PersistableBundle result = mDataSubscriberWifi.get(0);
        assertThat(result.getInt("size")).isEqualTo(1);
        assertThat(result.getIntArray("uid")).asList().containsExactly(UID_4);
        assertThat(result.getIntArray("tag")).asList().containsExactly(TAG_1);
        assertThat(result.getLongArray("txBytes")).asList().containsExactly(100L - 12L);
        assertThat(result.getLongArray("rxBytes")).asList().containsExactly(100L - 12L);
    }

    @Test
    public void testSubtractsFromThePreviousPull() {
        // ==== 0th (initial) pull.
        long someTimeAgo = mNow - Duration.ofMinutes(1).toMillis();
        mFakeManager.addWifiStats(UID_4, TAG_1, 12, 12, OEM_MANAGED_NO, someTimeAgo);
        mFakeHandler.dispatchQueuedMessages(); // pulls 12 bytes

        // ==== 1st pull.
        mFakeManager.addWifiStats(UID_4, TAG_1, 200, 200, OEM_MANAGED_NO, someTimeAgo);
        mPublisher.addDataSubscriber(mDataSubscriberWifi);
        mFakeHandler.dispatchQueuedMessages(); // pulls 200 + 12 bytes

        assertThat(mDataSubscriberWifi.mPushedData).hasSize(1);
        PersistableBundle result = mDataSubscriberWifi.get(0);
        assertThat(result.getInt("size")).isEqualTo(1);
        assertThat(result.getIntArray("uid")).asList().containsExactly(UID_4);
        assertThat(result.getIntArray("tag")).asList().containsExactly(TAG_1);
        // It's 200, because it subtracts previous pull 12 from (200 + 12).
        assertThat(result.getLongArray("txBytes")).asList().containsExactly(200L);

        // ==== 2nd pull.
        mFakeManager.addWifiStats(UID_4, TAG_1, 1000, 1000, OEM_MANAGED_NO, mNow);
        mFakeHandler.dispatchQueuedMessages(); // pulls 200 + 12 + 1000 bytes

        assertThat(mDataSubscriberWifi.mPushedData).hasSize(2);
        result = mDataSubscriberWifi.get(1);
        assertThat(result.getInt("size")).isEqualTo(1);
        assertThat(result.getIntArray("uid")).asList().containsExactly(UID_4);
        assertThat(result.getIntArray("tag")).asList().containsExactly(TAG_1);
        // It's 1000, because it subtracts previous pull (200 + 12) from (200 + 12 + 1000).
        assertThat(result.getLongArray("txBytes")).asList().containsExactly(1000L);
    }

    private void onPublisherFailure(
            AbstractPublisher publisher,
            List<TelemetryProto.MetricsConfig> affectedConfigs,
            Throwable error) {}

    private static class FakeDataSubscriber extends DataSubscriber {
        private final ArrayList<PushedData> mPushedData = new ArrayList<>();

        FakeDataSubscriber(
                TelemetryProto.MetricsConfig metricsConfig, TelemetryProto.Subscriber subscriber) {
            super(/* dataBroker= */ null, metricsConfig, subscriber);
        }

        @Override
        public void push(PersistableBundle data, boolean isLargeData) {
            mPushedData.add(new PushedData(data, isLargeData));
        }

        /** Returns the pushed data by the given index. */
        PersistableBundle get(int index) {
            return mPushedData.get(index).mData;
        }
    }

    /** Data pushed to a subscriber. */
    private static class PushedData {
        private final PersistableBundle mData;
        private final boolean mIsLargeData;

        PushedData(PersistableBundle data, boolean isLargeData) {
            mData = data;
            mIsLargeData = isLargeData;
        }
    }

    /** A fake for {@link INetworkStatsService}. */
    private static class FakeNetworkStatsManager extends NetworkStatsServiceProxy {
        private final ArrayList<FakeNetworkStats.CustomBucket> mBuckets = new ArrayList<>();
        private final HashMap<String, Integer> mMethodCallCount = new HashMap<>();

        private FakeNetworkStatsManager() {
            super(/* networkStatsManager= */ null);
        }

        /** Adds {@code NetworkStats.Bucket} that will be returned by {@code querySummary()}. */
        public void addWifiStats(
                int uid, int tag, long rx, long tx, int oemManaged, long timestampMillis) {
            NetworkIdentity identity =
                    new NetworkIdentity(
                            ConnectivityManager.TYPE_WIFI,
                            /* subType= */ NetworkTemplate.NETWORK_TYPE_ALL,
                            /* subscriberId= */ null,
                            /* networkId= */ "guest-wifi",
                            /* roaming= */ false,
                            /* metered= */ false,
                            /* defaultNetwork= */ false,
                            oemManaged);
            FakeNetworkStats.CustomBucket bucket =
                    new FakeNetworkStats.CustomBucket(
                            identity,
                            uid,
                            tag,
                            /* rxBytes= */ rx,
                            /* txBytes= */ tx,
                            timestampMillis);
            mBuckets.add(bucket);
        }

        /** Adds {@code NetworkStats.Bucket} that will be returned by {@code querySummary()}. */
        public void addMobileStats(
                int uid, int tag, long rx, long tx, int oemManaged, long timestampMillis) {
            NetworkIdentity identity =
                    new NetworkIdentity(
                            ConnectivityManager.TYPE_MOBILE,
                            /* subType= */ TelephonyManager.NETWORK_TYPE_GPRS,
                            /* subscriberId= */ null,
                            /* networkId= */ null,
                            /* roaming= */ false,
                            /* metered= */ false,
                            /* defaultNetwork= */ true,
                            oemManaged);
            FakeNetworkStats.CustomBucket bucket =
                    new FakeNetworkStats.CustomBucket(
                            identity,
                            uid,
                            tag,
                            /* rxBytes= */ rx,
                            /* txBytes= */ tx,
                            timestampMillis);
            mBuckets.add(bucket);
        }

        public void clearNetworkStats() {
            mBuckets.clear();
        }

        /** Returns the API method call count. */
        public int getMethodCallCount(String name) {
            return mMethodCallCount.getOrDefault(name, 0);
        }

        @Override
        @NonNull
        public RefinedStats querySummary(
                NetworkTemplate template, long start, long end, String callingPackage)
                throws RemoteException {
            increaseMethodCall("querySummary", 1);
            FakeNetworkStats result = new FakeNetworkStats();
            for (FakeNetworkStats.CustomBucket bucket : mBuckets) {
                // NOTE: the actual implementation calculates bucket ratio in the given time range
                //       instead of this simple time range checking.
                if (bucket.getStartTimeStamp() < start || bucket.getStartTimeStamp() > end) {
                    continue;
                }
                if (template.matches(bucket.getIdentity())) {
                    result.add(bucket);
                }
            }
            RefinedStats stats = new RefinedStats(start, end);
            stats.addNetworkStats(result.getNetworkStats());
            return stats;
        }

        private void increaseMethodCall(String methodName, int count) {
            mMethodCallCount.put(methodName, mMethodCallCount.getOrDefault(methodName, 0) + count);
        }
    }
}
