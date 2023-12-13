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

import android.net.NetworkIdentity;
import android.net.NetworkStats;

import java.util.ArrayDeque;

/** A fake for {@link NetworkStats}. */
public class FakeNetworkStats {
    private final ArrayDeque<NetworkStats.Entry> mBuckets = new ArrayDeque<>();

    /** Adds the entry to the fake. */
    public void add(NetworkStats.Entry entry) {
        mBuckets.add(entry);
    }

    public NetworkStats getNetworkStats() {
        NetworkStats stats = new NetworkStats(/* elapsedRealtime= */ 0, /* initialSize= */ 0);
        mBuckets.forEach(stats::insertEntry);
        return stats;
    }

    /** A custom implementation of {@link NetworkStats.Entry} for testing purpose. */
    public static class CustomBucket extends NetworkStats.Entry {
        private final NetworkIdentity mIdentity;
        private final long mTimestampMillis;

        public CustomBucket(
                NetworkIdentity identity,
                int uid,
                int tag,
                long rxBytes,
                long txBytes,
                long timestampMillis) {
            mIdentity = identity;
            this.uid = uid;
            this.tag = tag;
            this.rxBytes = rxBytes;
            this.txBytes = txBytes;
            mTimestampMillis = timestampMillis;
        }

        public NetworkIdentity getIdentity() {
            return mIdentity;
        }

        // Named "getStartTimeStamp()" to match android.app.usage.NetworkStats.Bucket, which is
        // used in the upcoming version.
        public long getStartTimeStamp() {
            return mTimestampMillis;
        }
    }
}
