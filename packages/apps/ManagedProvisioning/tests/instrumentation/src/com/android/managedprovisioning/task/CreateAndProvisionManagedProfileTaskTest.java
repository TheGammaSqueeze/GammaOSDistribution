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

import static android.app.admin.DevicePolicyManager.ACTION_PROVISION_MANAGED_PROFILE;

import static com.google.common.truth.Truth.assertThat;

import static org.mockito.Matchers.any;
import static org.mockito.Matchers.anyInt;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.verifyNoMoreInteractions;
import static org.mockito.Mockito.when;

import android.app.admin.DevicePolicyManager;
import android.content.ComponentName;
import android.content.Context;
import android.content.res.Resources;
import android.os.UserHandle;

import androidx.test.filters.SmallTest;

import com.android.managedprovisioning.analytics.ProvisioningAnalyticsTracker;
import com.android.managedprovisioning.common.Utils;
import com.android.managedprovisioning.model.ProvisioningParams;
import com.android.managedprovisioning.task.interactacrossprofiles.CrossProfileAppsSnapshot;
import com.android.managedprovisioning.task.nonrequiredapps.SystemAppsSnapshot;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;

/**
 * Unit tests for {@link CreateAndProvisionManagedProfileTask}.
 */
@SmallTest
@RunWith(JUnit4.class)
public class CreateAndProvisionManagedProfileTaskTest {
    private static final int TEST_PARENT_USER_ID = 111;
    private static final int TEST_USER_ID = 123;
    private static final String TEST_DPC_PACKAGE_NAME = "com.test.dpc";
    private static final String OWNER_NAME = "ownerName";
    private static final ComponentName ADMIN = new ComponentName(
            TEST_DPC_PACKAGE_NAME, ".Receiver");
    private static final ProvisioningParams TEST_PARAMS = new ProvisioningParams.Builder()
            .setDeviceAdminComponentName(ADMIN)
            .setProvisioningAction(ACTION_PROVISION_MANAGED_PROFILE)
            .build();
    private static final ProvisioningParams LEAVE_SYSTEM_APPS_PARAMS =
            new ProvisioningParams.Builder()
                    .setDeviceAdminComponentName(ADMIN)
                    .setProvisioningAction(ACTION_PROVISION_MANAGED_PROFILE)
                    .setLeaveAllSystemAppsEnabled(true)
                    .build();

    @Mock private Context mContext;
    @Mock private DevicePolicyManager mDevicePolicyManager;
    @Mock private CrossProfileAppsSnapshot mCrossProfileAppsSnapshot;
    @Mock private SystemAppsSnapshot mSystemAppsSnapshot;
    @Mock private AbstractProvisioningTask.Callback mCallback;
    @Mock private Utils mUtils;
    @Mock private Resources mResources;

    @Before
    public void setUp() throws Exception {
        MockitoAnnotations.initMocks(this);
        when(mContext.getSystemServiceName(DevicePolicyManager.class))
                .thenReturn(Context.DEVICE_POLICY_SERVICE);
        when(mContext.getSystemService(DevicePolicyManager.class))
                .thenReturn(mDevicePolicyManager);
        when(mContext.getResources()).thenReturn(mResources);
        when(mResources.getString(anyInt())).thenReturn(OWNER_NAME);
        when(mUtils.findDeviceAdmin(TEST_DPC_PACKAGE_NAME, ADMIN, mContext, TEST_USER_ID))
                .thenReturn(ADMIN);
    }

    @Test
    public void testSuccess() throws Exception {
        CreateAndProvisionManagedProfileTask task = createProvisioningTask(TEST_PARAMS);
        when(mDevicePolicyManager.createAndProvisionManagedProfile(any()))
                .thenReturn(new UserHandle(TEST_USER_ID));

        task.run(TEST_PARENT_USER_ID);

        assertThat(task.getProfileUserId()).isEqualTo(TEST_USER_ID);
        verify(mCallback).onSuccess(task);
        verifyNoMoreInteractions(mCallback);
        verify(mSystemAppsSnapshot).takeNewSnapshot(TEST_USER_ID);
        verify(mCrossProfileAppsSnapshot).takeNewSnapshot(TEST_PARENT_USER_ID);
    }

    @Test
    public void testError() throws Exception {
        CreateAndProvisionManagedProfileTask task = createProvisioningTask(TEST_PARAMS);
        when(mDevicePolicyManager.createAndProvisionManagedProfile(any()))
                .thenReturn(null);

        task.run(TEST_PARENT_USER_ID);

        verify(mCallback).onError(task, 0);
        verifyNoMoreInteractions(mCallback);
        verifyNoMoreInteractions(mSystemAppsSnapshot);
        verifyNoMoreInteractions(mCrossProfileAppsSnapshot);
    }

    @Test
    public void testLeaveSystemAppsEnabled() throws Exception {
        CreateAndProvisionManagedProfileTask task = createProvisioningTask(
                LEAVE_SYSTEM_APPS_PARAMS);
        when(mDevicePolicyManager.createAndProvisionManagedProfile(any()))
                .thenReturn(new UserHandle(TEST_USER_ID));

        task.run(TEST_PARENT_USER_ID);

        assertThat(task.getProfileUserId()).isEqualTo(TEST_USER_ID);
        verify(mCallback).onSuccess(task);
        verifyNoMoreInteractions(mCallback);
        verifyNoMoreInteractions(mSystemAppsSnapshot);
        verify(mCrossProfileAppsSnapshot).takeNewSnapshot(TEST_PARENT_USER_ID);
    }

    private CreateAndProvisionManagedProfileTask createProvisioningTask(ProvisioningParams params) {
        return new CreateAndProvisionManagedProfileTask(
                mUtils,
                mContext,
                mSystemAppsSnapshot,
                mCrossProfileAppsSnapshot,
                params,
                mCallback,
                mock(ProvisioningAnalyticsTracker.class));
    }
}
