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

package com.android.managedprovisioning.task;

import static java.util.Objects.requireNonNull;

import android.annotation.UserIdInt;
import android.app.admin.DevicePolicyManager;
import android.app.admin.FullyManagedDeviceProvisioningParams;
import android.content.ComponentName;
import android.content.Context;
import android.stats.devicepolicy.DevicePolicyEnums;

import com.android.internal.annotations.VisibleForTesting;
import com.android.managedprovisioning.R;
import com.android.managedprovisioning.analytics.MetricsWriterFactory;
import com.android.managedprovisioning.analytics.ProvisioningAnalyticsTracker;
import com.android.managedprovisioning.common.IllegalProvisioningArgumentException;
import com.android.managedprovisioning.common.ManagedProvisioningSharedPreferences;
import com.android.managedprovisioning.common.ProvisionLogger;
import com.android.managedprovisioning.common.SettingsFacade;
import com.android.managedprovisioning.common.Utils;
import com.android.managedprovisioning.model.ProvisioningParams;
import com.android.managedprovisioning.task.nonrequiredapps.SystemAppsSnapshot;

/**
 * Task to provision a fully managed device.
 */
public class ProvisionFullyManagedDeviceTask extends AbstractProvisioningTask {
    private final DevicePolicyManager mDpm;
    private final Utils mUtils;
    private final SystemAppsSnapshot mSystemAppsSnapshot;

    public ProvisionFullyManagedDeviceTask(
            Context context,
            ProvisioningParams params,
            Callback callback) {
        this(
                new Utils(),
                context,
                new SystemAppsSnapshot(context),
                params,
                callback,
                new ProvisioningAnalyticsTracker(
                        MetricsWriterFactory.getMetricsWriter(context, new SettingsFacade()),
                        new ManagedProvisioningSharedPreferences(context)));
    }

    @VisibleForTesting
    ProvisionFullyManagedDeviceTask(
            Utils utils,
            Context context,
            SystemAppsSnapshot systemAppsSnapshot,
            ProvisioningParams params,
            Callback callback,
            ProvisioningAnalyticsTracker provisioningAnalyticsTracker) {
        super(context, params, callback, provisioningAnalyticsTracker);

        mDpm = requireNonNull(context.getSystemService(DevicePolicyManager.class));
        mUtils = requireNonNull(utils);
        mSystemAppsSnapshot = requireNonNull(systemAppsSnapshot);
    }

    @Override
    public void run(@UserIdInt int userId) {
        startTaskTimer();
        FullyManagedDeviceProvisioningParams params;

        try {
            params = buildManagedDeviceProvisioningParams(userId);
        } catch (IllegalProvisioningArgumentException e) {
            ProvisionLogger.loge("Failure provisioning managed device, failed to "
                    + "infer the device admin component name", e);
            error(/* resultCode= */ 0);
            return;
        }

        try {
            mDpm.provisionFullyManagedDevice(params);
        } catch (Exception e) {
            // Catching all Exceptions to allow Managed Provisioning to handle any failure
            // during provisioning properly and perform any necessary cleanup.
            ProvisionLogger.loge("Failure provisioning device owner", e);
            error(/* resultCode= */ 0);
            return;
        }

        maybeTakeSystemAppsSnapshots(userId, mProvisioningParams.leaveAllSystemAppsEnabled);

        stopTaskTimer();
        success();
    }

    private FullyManagedDeviceProvisioningParams buildManagedDeviceProvisioningParams(
            @UserIdInt int userId)
            throws IllegalProvisioningArgumentException {
        ComponentName adminComponent = mProvisioningParams.inferDeviceAdminComponentName(
                mUtils, mContext, userId);
        return new FullyManagedDeviceProvisioningParams.Builder(
                adminComponent,
                mContext.getResources().getString(
                        R.string.default_owned_device_username))
                .setLeaveAllSystemAppsEnabled(
                        mProvisioningParams.leaveAllSystemAppsEnabled)
                .setTimeZone(mProvisioningParams.timeZone)
                .setLocalTime(mProvisioningParams.localTime)
                .setLocale(mProvisioningParams.locale)
                // The device owner can grant sensors permissions if it has not opted
                // out of controlling them.
                .setDeviceOwnerCanGrantSensorsPermissions(
                        !mProvisioningParams.deviceOwnerPermissionGrantOptOut)
                .build();
    }

    private void maybeTakeSystemAppsSnapshots(
            @UserIdInt int userId, boolean leaveAllSystemAppsEnabled) {
        if (!leaveAllSystemAppsEnabled) {
            mSystemAppsSnapshot.takeNewSnapshot(userId);
        }
    }

    @Override
    protected int getMetricsCategory() {
        return DevicePolicyEnums.PROVISIONING_PROVISION_FULLY_MANAGED_DEVICE_TASK_MS;
    }
}
