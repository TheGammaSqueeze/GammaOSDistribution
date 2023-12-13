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

import android.annotation.NonNull;
import android.net.INetworkStatsService;
import android.net.NetworkTemplate;
import android.os.RemoteException;

/** Proxy for {@link INetworkStatsService} to improve testability. */
public class NetworkStatsServiceProxy {
    private final INetworkStatsService mNetworkStatsService;

    /** Creates a proxy for the given manager. */
    public NetworkStatsServiceProxy(@NonNull INetworkStatsService networkStatsService) {
        mNetworkStatsService = networkStatsService;
    }

    /** Returns tagged and untagged (TAG_NONE) network stats summary per UID. */
    @NonNull
    public RefinedStats querySummary(
            @NonNull NetworkTemplate template, long start, long end, String callingPackage)
            throws RemoteException {
        RefinedStats result = new RefinedStats(start, end);
        // No need to close the session, it just resets the internal state.
        result.addNetworkStats(
                mNetworkStatsService
                        .openSessionForUsageStats(/* flags= */ 0, callingPackage)
                        .getSummaryForAllUid(template, start, end, /* includeTags= */ true));
        return result;
    }
}
