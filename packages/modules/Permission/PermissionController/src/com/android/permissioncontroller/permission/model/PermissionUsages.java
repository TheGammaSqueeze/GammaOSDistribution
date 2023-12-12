/*
 * Copyright (C) 2021 The Android Open Source Project
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

package com.android.permissioncontroller.permission.model;

import static android.Manifest.permission.CAMERA;
import static android.Manifest.permission.RECORD_AUDIO;

import android.app.AppOpsManager;
import android.app.AppOpsManager.HistoricalOps;
import android.app.AppOpsManager.HistoricalOpsRequest;
import android.app.AppOpsManager.HistoricalPackageOps;
import android.app.AppOpsManager.HistoricalUidOps;
import android.app.AppOpsManager.PackageOps;
import android.app.LoaderManager;
import android.app.LoaderManager.LoaderCallbacks;
import android.content.AsyncTaskLoader;
import android.content.Context;
import android.content.Loader;
import android.content.pm.PackageInfo;
import android.media.AudioManager;
import android.media.AudioRecordingConfiguration;
import android.os.Build;
import android.os.Bundle;
import android.os.Process;
import android.util.ArrayMap;
import android.util.ArraySet;
import android.util.Pair;
import android.util.SparseArray;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.annotation.RequiresApi;

import com.android.permissioncontroller.permission.model.AppPermissionUsage.Builder;
import com.android.permissioncontroller.permission.model.legacy.PermissionApps.PermissionApp;
import com.android.permissioncontroller.permission.model.legacy.PermissionGroup;
import com.android.permissioncontroller.permission.model.legacy.PermissionGroups;
import com.android.permissioncontroller.permission.utils.Utils;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicReference;

/**
 * Loads all permission usages for a set of apps and permission groups.
 */
@RequiresApi(Build.VERSION_CODES.S)
public final class PermissionUsages implements LoaderCallbacks<List<AppPermissionUsage>> {
    public static final int USAGE_FLAG_LAST = 1 << 0;
    public static final int USAGE_FLAG_HISTORICAL = 1 << 2;

    private final ArrayList<AppPermissionUsage> mUsages = new ArrayList<>();
    private final @NonNull Context mContext;

    private static final String KEY_FILTER_UID =  "KEY_FILTER_UID";
    private static final String KEY_FILTER_PACKAGE_NAME =  "KEY_FILTER_PACKAGE_NAME";
    private static final String KEY_FILTER_PERMISSION_GROUP =  "KEY_FILTER_PERMISSION_GROUP";
    private static final String KEY_FILTER_BEGIN_TIME_MILLIS =  "KEY_FILTER_BEGIN_TIME_MILLIS";
    private static final String KEY_FILTER_END_TIME_MILLIS =  "KEY_FILTER_END_TIME_MILLIS";
    private static final String KEY_USAGE_FLAGS =  "KEY_USAGE_FLAGS";
    private static final String KEY_GET_UI_INFO =  "KEY_GET_UI_INFO";
    private static final String KEY_GET_NON_PLATFORM_PERMISSIONS =
            "KEY_GET_NON_PLATFORM_PERMISSIONS";
    private static final String TELECOM_PACKAGE = "com.android.server.telecom";
    private static final int DEFAULT_REQUIRED_PERMISSION_FLAG = 3;

    // TODO: theianchen move them to SystemApi
    private static final String OPSTR_PHONE_CALL_MICROPHONE = "android:phone_call_microphone";
    private static final String OPSTR_PHONE_CALL_CAMERA = "android:phone_call_camera";
    public static final int HISTORY_FLAG_GET_ATTRIBUTION_CHAINS = 1 << 2;

    private @Nullable PermissionsUsagesChangeCallback mCallback;

    /**
     * Callback for when the permission usages has loaded or changed.
     */
    public interface PermissionsUsagesChangeCallback {
        /**
         * Called when the permission usages have loaded or changed.
         */
        void onPermissionUsagesChanged();
    }

    /**
     * Creates a new instance of {@link PermissionUsages}.
     */
    public PermissionUsages(@NonNull Context context) {
        mContext = context;
    }

    /**
     * Start the {@link Loader} to load the permission usages in the background. Loads without a uid
     * filter.
     */
    public void load(@Nullable String filterPackageName,
            @Nullable String[] filterPermissionGroups, long filterBeginTimeMillis,
            long filterEndTimeMillis, int usageFlags, @NonNull LoaderManager loaderManager,
            boolean getUiInfo, boolean getNonPlatformPermissions,
            @NonNull PermissionsUsagesChangeCallback callback, boolean sync) {
        load(Process.INVALID_UID, filterPackageName, filterPermissionGroups, filterBeginTimeMillis,
                filterEndTimeMillis, usageFlags, loaderManager, getUiInfo,
                getNonPlatformPermissions, callback, sync);
    }

    /**
     * Start the {@link Loader} to load the permission usages in the background. Loads only
     * permissions for the specified {@code filterUid}.
     */
    public void load(int filterUid, @Nullable String filterPackageName,
            @Nullable String[] filterPermissionGroups, long filterBeginTimeMillis,
            long filterEndTimeMillis, int usageFlags, @NonNull LoaderManager loaderManager,
            boolean getUiInfo, boolean getNonPlatformPermissions,
            @NonNull PermissionsUsagesChangeCallback callback, boolean sync) {
        mCallback = callback;
        final Bundle args = new Bundle();
        args.putInt(KEY_FILTER_UID, filterUid);
        args.putString(KEY_FILTER_PACKAGE_NAME, filterPackageName);
        args.putStringArray(KEY_FILTER_PERMISSION_GROUP, filterPermissionGroups);
        args.putLong(KEY_FILTER_BEGIN_TIME_MILLIS, filterBeginTimeMillis);
        args.putLong(KEY_FILTER_END_TIME_MILLIS, filterEndTimeMillis);
        args.putInt(KEY_USAGE_FLAGS, usageFlags);
        args.putBoolean(KEY_GET_UI_INFO, getUiInfo);
        args.putBoolean(KEY_GET_NON_PLATFORM_PERMISSIONS, getNonPlatformPermissions);
        if (sync) {
            final UsageLoader loader = new UsageLoader(mContext, args);
            final List<AppPermissionUsage> usages = loader.loadInBackground();
            onLoadFinished(loader, usages);
        } else {
            loaderManager.restartLoader(1, args, this);
        }
    }

    @Override
    public Loader<List<AppPermissionUsage>> onCreateLoader(int id, Bundle args) {
        return new UsageLoader(mContext, args);
    }

    @Override
    public void onLoadFinished(@NonNull Loader<List<AppPermissionUsage>> loader,
            List<AppPermissionUsage> usages) {
        mUsages.clear();
        mUsages.addAll(usages);
        if (mCallback != null) {
            mCallback.onPermissionUsagesChanged();
        }
    }

    @Override
    public void onLoaderReset(@NonNull Loader<List<AppPermissionUsage>> loader) {
        mUsages.clear();
        mCallback.onPermissionUsagesChanged();
    }

    /**
     * Return the usages that have already been loaded.
     */
    public @NonNull List<AppPermissionUsage> getUsages() {
        return mUsages;
    }

    /**
     * Stop the {@link Loader} from loading the usages.
     */
    public void stopLoader(@NonNull LoaderManager loaderManager) {
        loaderManager.destroyLoader(1);
    }

    private static final class UsageLoader extends AsyncTaskLoader<List<AppPermissionUsage>> {
        private final int mFilterUid;
        private @Nullable String mFilterPackageName;
        private @Nullable String[] mFilterPermissionGroups;
        private final long mFilterBeginTimeMillis;
        private final long mFilterEndTimeMillis;
        private final int mUsageFlags;
        private final boolean mGetUiInfo;
        private final boolean mGetNonPlatformPermissions;

        UsageLoader(@NonNull Context context, @NonNull Bundle args) {
            super(context);
            mFilterUid = args.getInt(KEY_FILTER_UID);
            mFilterPackageName = args.getString(KEY_FILTER_PACKAGE_NAME);
            mFilterPermissionGroups = args.getStringArray(KEY_FILTER_PERMISSION_GROUP);
            mFilterBeginTimeMillis = args.getLong(KEY_FILTER_BEGIN_TIME_MILLIS);
            mFilterEndTimeMillis = args.getLong(KEY_FILTER_END_TIME_MILLIS);
            mUsageFlags = args.getInt(KEY_USAGE_FLAGS);
            mGetUiInfo = args.getBoolean(KEY_GET_UI_INFO);
            mGetNonPlatformPermissions = args.getBoolean(KEY_GET_NON_PLATFORM_PERMISSIONS);
        }

        @Override
        protected void onStartLoading() {
            forceLoad();
        }

        @Override
        public @NonNull List<AppPermissionUsage> loadInBackground() {
            final List<PermissionGroup> groups = PermissionGroups.getPermissionGroups(
                    getContext(), this::isLoadInBackgroundCanceled, mGetUiInfo,
                    mGetNonPlatformPermissions, mFilterPermissionGroups, mFilterPackageName);
            if (groups.isEmpty()) {
                return Collections.emptyList();
            }

            final List<AppPermissionUsage> usages = new ArrayList<>();
            final ArraySet<String> opNames = new ArraySet<>();
            final ArrayMap<Pair<Integer, String>, AppPermissionUsage.Builder> usageBuilders =
                    new ArrayMap<>();

            final int groupCount = groups.size();
            boolean telecomMicAndCamAdded = false;
            for (int groupIdx = 0; groupIdx < groupCount; groupIdx++) {
                final PermissionGroup group = groups.get(groupIdx);
                // Filter out third party permissions
                if (!group.getDeclaringPackage().equals(Utils.OS_PKG)) {
                    continue;
                }

                groups.add(group);

                final List<PermissionApp> permissionApps = group.getPermissionApps().getApps();
                final int appCount = permissionApps.size();
                for (int appIdx = 0; appIdx < appCount; appIdx++) {
                    final PermissionApp permissionApp = permissionApps.get(appIdx);
                    if (mFilterUid != Process.INVALID_UID
                            && permissionApp.getAppInfo().uid != mFilterUid) {
                        continue;
                    }

                    final AppPermissionGroup appPermGroup = permissionApp.getPermissionGroup();
                    if (!Utils.shouldShowPermission(getContext(), appPermGroup)) {
                        continue;
                    }
                    final Pair<Integer, String> usageKey = Pair.create(permissionApp.getUid(),
                            permissionApp.getPackageName());
                    AppPermissionUsage.Builder usageBuilder = usageBuilders.get(usageKey);
                    if (usageBuilder == null) {
                        usageBuilder = new Builder(permissionApp);
                        usageBuilders.put(usageKey, usageBuilder);
                    }
                    usageBuilder.addGroup(appPermGroup);

                    // Since PermissionGroups.getPermissionGroups doesn't return
                    // Telecom PermissionApp entity with Microphone and Camera permission groups,
                    // we have to manually add those entries here.
                    if (!telecomMicAndCamAdded
                            && permissionApp.getPackageName().equals(TELECOM_PACKAGE)) {
                        PackageInfo telecomPackageInfo = appPermGroup.getApp();

                        String[] newReqPerms = Arrays.copyOf(
                                telecomPackageInfo.requestedPermissions,
                                telecomPackageInfo.requestedPermissions.length + 2);
                        newReqPerms[telecomPackageInfo.requestedPermissions.length] = RECORD_AUDIO;
                        newReqPerms[telecomPackageInfo.requestedPermissions.length + 1] = CAMERA;
                        telecomPackageInfo.requestedPermissions = newReqPerms;

                        int[] newReqPermsFlags = Arrays.copyOf(
                                telecomPackageInfo.requestedPermissionsFlags,
                                telecomPackageInfo.requestedPermissionsFlags.length + 2);
                        newReqPermsFlags[telecomPackageInfo.requestedPermissionsFlags.length] =
                                DEFAULT_REQUIRED_PERMISSION_FLAG;
                        newReqPermsFlags[telecomPackageInfo.requestedPermissionsFlags.length + 1] =
                                DEFAULT_REQUIRED_PERMISSION_FLAG;
                        telecomPackageInfo.requestedPermissionsFlags = newReqPermsFlags;

                        AppPermissionGroup micGroup = AppPermissionGroup.create(getContext(),
                                telecomPackageInfo, RECORD_AUDIO, false);
                        AppPermissionGroup camGroup = AppPermissionGroup.create(getContext(),
                                telecomPackageInfo, CAMERA, false);

                        if (micGroup != null) {
                            usageBuilder.addGroup(micGroup);
                        }

                        if (camGroup != null) {
                            usageBuilder.addGroup(camGroup);
                        }

                        telecomMicAndCamAdded = true;
                    }

                    final List<Permission> permissions = appPermGroup.getPermissions();
                    final int permCount = permissions.size();
                    for (int permIdx = 0; permIdx < permCount; permIdx++) {
                        final Permission permission = permissions.get(permIdx);
                        final String opName = permission.getAppOp();
                        if (opName != null) {
                            opNames.add(opName);
                        }
                    }
                }
            }

            if (usageBuilders.isEmpty()) {
                return Collections.emptyList();
            }

            final AppOpsManager appOpsManager = getContext().getSystemService(AppOpsManager.class);

            // Get last usage data and put in a map for a quick lookup.
            final ArrayMap<Pair<Integer, String>, PackageOps> lastUsages =
                    new ArrayMap<>(usageBuilders.size());
            opNames.add(OPSTR_PHONE_CALL_MICROPHONE);
            opNames.add(OPSTR_PHONE_CALL_CAMERA);
            final String[] opNamesArray = opNames.toArray(new String[opNames.size()]);
            if ((mUsageFlags & USAGE_FLAG_LAST) != 0) {
                final List<PackageOps> usageOps;
                if (mFilterPackageName != null || mFilterUid != Process.INVALID_UID) {
                    usageOps = appOpsManager.getOpsForPackage(mFilterUid, mFilterPackageName,
                            opNamesArray);
                } else {
                    usageOps = appOpsManager.getPackagesForOps(opNamesArray);
                }
                if (usageOps != null && !usageOps.isEmpty()) {
                    final int usageOpsCount = usageOps.size();
                    for (int i = 0; i < usageOpsCount; i++) {
                        final PackageOps usageOp = usageOps.get(i);
                        lastUsages.put(Pair.create(usageOp.getUid(), usageOp.getPackageName()),
                                usageOp);
                    }
                }
            }

            if (isLoadInBackgroundCanceled()) {
                return Collections.emptyList();
            }

            // Get historical usage data and put in a map for a quick lookup
            final ArrayMap<Pair<Integer, String>, HistoricalPackageOps> historicalUsages =
                    new ArrayMap<>(usageBuilders.size());
            if ((mUsageFlags & USAGE_FLAG_HISTORICAL) != 0) {
                final AtomicReference<HistoricalOps> historicalOpsRef = new AtomicReference<>();
                final CountDownLatch latch = new CountDownLatch(1);

                // query for discrete timeline data for location, mic and camera
                final HistoricalOpsRequest request = new HistoricalOpsRequest.Builder(
                        mFilterBeginTimeMillis, mFilterEndTimeMillis)
                        .setFlags(AppOpsManager.OP_FLAG_SELF
                                | AppOpsManager.OP_FLAG_TRUSTED_PROXIED)
                        .setHistoryFlags(AppOpsManager.HISTORY_FLAG_DISCRETE
                                | HISTORY_FLAG_GET_ATTRIBUTION_CHAINS)
                        .build();
                appOpsManager.getHistoricalOps(request, Runnable::run,
                        (HistoricalOps ops) -> {
                            historicalOpsRef.set(ops);
                            latch.countDown();
                        });
                try {
                    latch.await(5, TimeUnit.DAYS);
                } catch (InterruptedException ignored) { }

                final HistoricalOps historicalOps = historicalOpsRef.get();

                if (historicalOps != null) {
                    final int uidCount = historicalOps.getUidCount();
                    for (int i = 0; i < uidCount; i++) {
                        final HistoricalUidOps uidOps = historicalOps.getUidOpsAt(i);
                        final int packageCount = uidOps.getPackageCount();
                        for (int j = 0; j < packageCount; j++) {
                            final HistoricalPackageOps packageOps = uidOps.getPackageOpsAt(j);
                            historicalUsages.put(
                                    Pair.create(uidOps.getUid(), packageOps.getPackageName()),
                                    packageOps);
                        }
                    }
                }
            }

            // Get audio recording config
            List<AudioRecordingConfiguration> allRecordings = getContext()
                    .getSystemService(AudioManager.class).getActiveRecordingConfigurations();
            SparseArray<ArrayList<AudioRecordingConfiguration>> recordingsByUid =
                    new SparseArray<>();

            final int recordingsCount = allRecordings.size();
            for (int i = 0; i < recordingsCount; i++) {
                AudioRecordingConfiguration recording = allRecordings.get(i);

                ArrayList<AudioRecordingConfiguration> recordings = recordingsByUid.get(
                        recording.getClientUid());
                if (recordings == null) {
                    recordings = new ArrayList<>();
                    recordingsByUid.put(recording.getClientUid(), recordings);
                }
                recordings.add(recording);
            }

            // Construct the historical usages based on data we fetched
            final int builderCount = usageBuilders.size();
            for (int i = 0; i < builderCount; i++) {
                final Pair<Integer, String> key = usageBuilders.keyAt(i);
                final Builder usageBuilder = usageBuilders.valueAt(i);
                final PackageOps lastUsage = lastUsages.get(key);
                usageBuilder.setLastUsage(lastUsage);
                final HistoricalPackageOps historicalUsage = historicalUsages.get(key);

                usageBuilder.setHistoricalUsage(historicalUsage);
                usageBuilder.setRecordingConfiguration(recordingsByUid.get(key.first));
                usages.add(usageBuilder.build());
            }

            return usages;
        }
    }
}
