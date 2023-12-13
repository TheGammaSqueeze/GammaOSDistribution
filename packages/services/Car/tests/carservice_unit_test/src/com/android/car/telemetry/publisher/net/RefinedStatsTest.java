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

package com.android.car.telemetry.publisher.net;

import static android.net.NetworkStats.TAG_NONE;

import static com.google.common.truth.Truth.assertThat;

import android.annotation.NonNull;
import android.car.test.mocks.AbstractExtendedMockitoTestCase;
import android.net.NetworkStats;
import android.os.PersistableBundle;

import com.android.internal.util.FastXmlSerializer;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.junit.MockitoJUnitRunner;

import java.io.StringWriter;

/**
 * Tests for {@link RefinedStats}. Some logic is acquired from {@link android.net.NetworkStatsTest}
 * in {@code FrameworksNetTests} test package.
 */
@RunWith(MockitoJUnitRunner.class)
public class RefinedStatsTest extends AbstractExtendedMockitoTestCase {
    private static final int UID_0 = 0;
    private static final int UID_1 = 1;
    private static final int UID_2 = 2;

    private static final int TAG_1 = 1;

    private RefinedStats mRefinedStats; // subject

    @Before
    public void setUp() throws Exception {
        mRefinedStats = new RefinedStats(/* startMillis= */ 10_000, /* endMillis= */ 20_000);
    }

    @Override
    protected void onSessionBuilder(@NonNull CustomMockitoSessionBuilder session) {}

    @Test
    public void testAddNetworkStats_toPersistableBundle() throws Exception {
        FakeNetworkStats stats = new FakeNetworkStats();
        stats.add(buildBucket(UID_0, TAG_1, /* rx= */ 4096, /* tx= */ 2048));
        stats.add(buildBucket(UID_1, TAG_NONE, /* rx= */ 4095, /* tx= */ 2047));
        stats.add(buildBucket(UID_0, TAG_1, /* rx= */ 10000, /* tx= */ 10000)); // merges with 1st

        mRefinedStats.addNetworkStats(stats.getNetworkStats());
        PersistableBundle result = mRefinedStats.toPersistableBundle();

        PersistableBundle expected = new PersistableBundle();
        expected.putLong("startMillis", 10_000);
        expected.putLong("endMillis", 20_000);
        expected.putInt("size", 2);
        expected.putIntArray("uid", new int[] {UID_0, UID_1});
        expected.putIntArray("tag", new int[] {TAG_1, TAG_NONE});
        expected.putLongArray("rxBytes", new long[] {14096, 4095});
        expected.putLongArray("txBytes", new long[] {12048, 2047});
        assertThat(bundleToXml(result)).isEqualTo(bundleToXml(expected));
    }

    @Test
    public void testIsEmpty() throws Exception {
        FakeNetworkStats stats = new FakeNetworkStats();
        stats.add(buildBucket(UID_0, TAG_NONE, /* rx= */ 256, /* tx= */ 256));

        assertThat(mRefinedStats.isEmpty()).isTrue();

        mRefinedStats.addNetworkStats(stats.getNetworkStats());
        assertThat(mRefinedStats.isEmpty()).isFalse();
    }

    @Test
    public void testSubtract() throws Exception {
        FakeNetworkStats stats = new FakeNetworkStats();
        stats.add(buildBucket(UID_1, TAG_NONE, /* rx= */ 4096, /* tx= */ 2048));
        stats.add(buildBucket(UID_1, TAG_1, /* rx= */ 4096, /* tx= */ 2048));
        // This one is not present in "other" below.
        stats.add(buildBucket(UID_2, TAG_NONE, /* rx= */ 4096, /* tx= */ 2048));
        mRefinedStats.addNetworkStats(stats.getNetworkStats());

        FakeNetworkStats stats2 = new FakeNetworkStats();
        stats2.add(buildBucket(UID_1, TAG_NONE, /* rx= */ 6, /* tx= */ 8));
        stats2.add(buildBucket(UID_1, TAG_1, /* rx= */ 99999, /* tx= */ 99999));
        // This one is not present in mRefinedStats.
        stats2.add(buildBucket(UID_0, TAG_1, /* rx= */ 6, /* tx= */ 8));
        stats2.add(buildBucket(UID_2, TAG_1, /* rx= */ 6, /* tx= */ 8));
        RefinedStats other = new RefinedStats(/* startMillis= */ 9_000, /* endMillis= */ 15_000);
        other.addNetworkStats(stats2.getNetworkStats());

        RefinedStats diff = RefinedStats.subtract(mRefinedStats, other);

        PersistableBundle expected = new PersistableBundle();
        expected.putLong("startMillis", 10_000);
        expected.putLong("endMillis", 20_000);
        expected.putInt("size", 3); // the same size as "mRefinedStats"
        expected.putIntArray("uid", new int[] {UID_1, UID_1, UID_2});
        expected.putIntArray("tag", new int[] {TAG_NONE, TAG_1, TAG_NONE});
        // Handles negative values too (hence 0).
        expected.putLongArray("rxBytes", new long[] {4090, 0, 4096});
        expected.putLongArray("txBytes", new long[] {2040, 0, 2048});
        assertThat(bundleToXml(diff.toPersistableBundle())).isEqualTo(bundleToXml(expected));
    }

    private static NetworkStats.Entry buildBucket(int uid, int tag, long rx, long tx) {
        return new NetworkStats.Entry(
                /* iface= */ null,
                uid,
                NetworkStats.SET_DEFAULT,
                tag,
                rx,
                rx,
                tx,
                tx,
                /* operations= */ 0);
    }

    /** Converts the bundle to a XML String for easy asserting equality. */
    private static String bundleToXml(PersistableBundle bundle) throws Exception {
        StringWriter writer = new StringWriter();
        FastXmlSerializer serializer = new FastXmlSerializer();
        serializer.setOutput(writer);
        bundle.saveToXml(serializer);
        serializer.flush();
        return writer.toString();
    }
}
