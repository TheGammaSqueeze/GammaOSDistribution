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

package com.android.settings.applications;

import static android.provider.DeviceConfig.NAMESPACE_APP_HIBERNATION;

import static com.android.settings.Utils.PROPERTY_APP_HIBERNATION_ENABLED;
import static com.android.settings.core.BasePreferenceController.AVAILABLE;

import static com.google.common.truth.Truth.assertThat;

import static org.mockito.ArgumentMatchers.anyInt;
import static org.mockito.ArgumentMatchers.anyLong;
import static org.mockito.ArgumentMatchers.anyString;
import static org.mockito.ArgumentMatchers.eq;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.spy;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

import android.app.usage.IUsageStatsManager;
import android.app.usage.UsageStats;
import android.app.usage.UsageStatsManager;
import android.apphibernation.AppHibernationManager;
import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.ParceledListSlice;
import android.content.res.Resources;
import android.os.Looper;
import android.os.RemoteException;
import android.provider.DeviceConfig;

import androidx.preference.Preference;
import androidx.preference.PreferenceManager;
import androidx.preference.PreferenceScreen;
import androidx.test.core.app.ApplicationProvider;
import androidx.test.ext.junit.runners.AndroidJUnit4;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;

import java.util.Arrays;

@RunWith(AndroidJUnit4.class)
public class HibernatedAppsPreferenceControllerTest {

    public static final String HIBERNATED_PACKAGE_NAME = "hibernated_package";
    public static final String AUTO_REVOKED_PACKAGE_NAME = "auto_revoked_package";
    public static final String PERMISSION = "permission";
    @Mock
    PackageManager mPackageManager;
    @Mock
    AppHibernationManager mAppHibernationManager;
    @Mock
    IUsageStatsManager mIUsageStatsManager;
    PreferenceScreen mPreferenceScreen;
    private static final String KEY = "key";
    private Context mContext;
    private HibernatedAppsPreferenceController mController;

    @Before
    public void setUp() {
        if (Looper.myLooper() == null) {
            Looper.prepare();
        }
        MockitoAnnotations.initMocks(this);
        DeviceConfig.setProperty(NAMESPACE_APP_HIBERNATION, PROPERTY_APP_HIBERNATION_ENABLED,
                "true", false);
        mContext = spy(ApplicationProvider.getApplicationContext());
        when(mContext.getPackageManager()).thenReturn(mPackageManager);
        when(mContext.getSystemService(AppHibernationManager.class))
                .thenReturn(mAppHibernationManager);
        when(mContext.getSystemService(UsageStatsManager.class)).thenReturn(
                new UsageStatsManager(mContext, mIUsageStatsManager));

        PreferenceManager manager = new PreferenceManager(mContext);
        mPreferenceScreen = manager.createPreferenceScreen(mContext);
        Preference preference = mock(Preference.class);
        when(preference.getKey()).thenReturn(KEY);
        mPreferenceScreen.addPreference(preference);

        mController = new HibernatedAppsPreferenceController(mContext, KEY,
                command -> command.run(), command -> command.run());
    }

    @Test
    public void getAvailabilityStatus_featureDisabled_shouldNotReturnAvailable() {
        DeviceConfig.setProperty(NAMESPACE_APP_HIBERNATION, PROPERTY_APP_HIBERNATION_ENABLED,
                "false", true);

        assertThat((mController).getAvailabilityStatus()).isNotEqualTo(AVAILABLE);
    }

    @Test
    public void getSummary_getsRightCountForHibernatedPackage() {
        final PackageInfo hibernatedPkg = getHibernatedPackage();
        when(mPackageManager.getInstalledPackages(anyInt())).thenReturn(
                Arrays.asList(hibernatedPkg, new PackageInfo()));
        when(mContext.getResources()).thenReturn(mock(Resources.class));

        mController.displayPreference(mPreferenceScreen);
        mController.onResume();

        verify(mContext.getResources()).getQuantityString(anyInt(), eq(1), eq(1));
    }

    @Test
    public void getSummary_getsRightCountForUnusedAutoRevokedPackage() {
        final PackageInfo autoRevokedPkg = getAutoRevokedPackage();
        when(mPackageManager.getInstalledPackages(anyInt())).thenReturn(
                Arrays.asList(autoRevokedPkg, new PackageInfo()));
        when(mContext.getResources()).thenReturn(mock(Resources.class));

        mController.displayPreference(mPreferenceScreen);
        mController.onResume();

        verify(mContext.getResources()).getQuantityString(anyInt(), eq(1), eq(1));
    }

    @Test
    public void getSummary_getsRightCountForUsedAutoRevokedPackage() {
        final PackageInfo usedAutoRevokedPkg = getAutoRevokedPackage();
        setAutoRevokedPackageUsageStats();
        when(mPackageManager.getInstalledPackages(anyInt())).thenReturn(
                Arrays.asList(usedAutoRevokedPkg, new PackageInfo()));
        when(mContext.getResources()).thenReturn(mock(Resources.class));

        mController.displayPreference(mPreferenceScreen);
        mController.onResume();

        verify(mContext.getResources()).getQuantityString(anyInt(), eq(0), eq(0));
    }

    private PackageInfo getHibernatedPackage() {
        final PackageInfo pi = new PackageInfo();
        pi.packageName = HIBERNATED_PACKAGE_NAME;
        pi.requestedPermissions = new String[] {PERMISSION};
        when(mAppHibernationManager.getHibernatingPackagesForUser())
                .thenReturn(Arrays.asList(pi.packageName));
        when(mPackageManager.getPermissionFlags(
                pi.requestedPermissions[0], pi.packageName, mContext.getUser()))
                .thenReturn(PackageManager.FLAG_PERMISSION_AUTO_REVOKED);
        return pi;
    }

    private PackageInfo getAutoRevokedPackage() {
        final PackageInfo pi = new PackageInfo();
        pi.packageName = AUTO_REVOKED_PACKAGE_NAME;
        pi.requestedPermissions = new String[] {PERMISSION};
        when(mPackageManager.getPermissionFlags(
                pi.requestedPermissions[0], pi.packageName, mContext.getUser()))
                .thenReturn(PackageManager.FLAG_PERMISSION_AUTO_REVOKED);
        return pi;
    }

    private void setAutoRevokedPackageUsageStats() {
        final UsageStats us = new UsageStats();
        us.mPackageName = AUTO_REVOKED_PACKAGE_NAME;
        us.mLastTimeVisible = System.currentTimeMillis();
        try {
            when(mIUsageStatsManager.queryUsageStats(
                    anyInt(), anyLong(), anyLong(), anyString(), anyInt()))
                    .thenReturn(new ParceledListSlice(Arrays.asList(us)));
        } catch (RemoteException e) {
            // no-op
        }
    }
}
