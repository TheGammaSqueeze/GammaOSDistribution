/*
 * Copyright (C) 2017 The Android Open Source Project
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

package com.android.settings.accessibility;

import static com.google.common.truth.Truth.assertThat;

import static org.mockito.ArgumentMatchers.any;
import static org.mockito.ArgumentMatchers.anyBoolean;
import static org.mockito.ArgumentMatchers.eq;
import static org.mockito.ArgumentMatchers.isNull;
import static org.mockito.Mockito.atLeast;
import static org.mockito.Mockito.doReturn;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

import static java.util.Collections.singletonList;

import android.accessibilityservice.AccessibilityServiceInfo;
import android.accessibilityservice.AccessibilityShortcutInfo;
import android.content.ComponentName;
import android.content.ContentResolver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.ActivityInfo;
import android.content.pm.ApplicationInfo;
import android.content.pm.ResolveInfo;
import android.content.pm.ServiceInfo;
import android.os.Build;
import android.os.Bundle;
import android.provider.Settings;
import android.view.accessibility.AccessibilityManager;

import androidx.fragment.app.FragmentActivity;
import androidx.preference.PreferenceManager;
import androidx.test.core.app.ApplicationProvider;

import com.android.internal.content.PackageMonitor;
import com.android.settings.R;
import com.android.settings.testutils.XmlTestUtils;
import com.android.settings.testutils.shadow.ShadowDeviceConfig;
import com.android.settings.testutils.shadow.ShadowFragment;
import com.android.settings.testutils.shadow.ShadowUserManager;
import com.android.settingslib.RestrictedPreference;
import com.android.settingslib.search.SearchIndexableRaw;

import org.junit.Before;
import org.junit.Rule;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.ArgumentCaptor;
import org.mockito.Mock;
import org.mockito.Mockito;
import org.mockito.Spy;
import org.mockito.junit.MockitoJUnit;
import org.mockito.junit.MockitoRule;
import org.robolectric.RobolectricTestRunner;
import org.robolectric.annotation.Config;
import org.robolectric.shadow.api.Shadow;
import org.robolectric.shadows.ShadowAccessibilityManager;
import org.xmlpull.v1.XmlPullParserException;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/** Test for {@link AccessibilitySettings}. */
@RunWith(RobolectricTestRunner.class)
public class AccessibilitySettingsTest {
    private static final String PACKAGE_NAME = "com.android.test";
    private static final String CLASS_NAME = PACKAGE_NAME + ".test_a11y_service";
    private static final ComponentName COMPONENT_NAME = new ComponentName(PACKAGE_NAME, CLASS_NAME);
    private static final int ON = 1;
    private static final int OFF = 0;
    private static final String EMPTY_STRING = "";
    private static final String DEFAULT_SUMMARY = "default summary";
    private static final String DEFAULT_DESCRIPTION = "default description";
    private static final String DEFAULT_LABEL = "default label";
    private static final Boolean SERVICE_ENABLED = true;
    private static final Boolean SERVICE_DISABLED = false;
    @Rule
    public final MockitoRule mocks = MockitoJUnit.rule();
    @Spy
    private final Context mContext = ApplicationProvider.getApplicationContext();
    @Spy
    private final AccessibilityServiceInfo mServiceInfo = getMockAccessibilityServiceInfo(
            PACKAGE_NAME, CLASS_NAME);
    @Spy
    private final AccessibilitySettings mFragment = new AccessibilitySettings();
    @Mock
    private AccessibilityShortcutInfo mShortcutInfo;
    @Mock
    private FragmentActivity mActivity;
    @Mock
    private ContentResolver mContentResolver;
    @Mock
    private PreferenceManager mPreferenceManager;
    private ShadowAccessibilityManager mShadowAccessibilityManager;

    @Before
    public void setup() {
        mShadowAccessibilityManager = Shadow.extract(AccessibilityManager.getInstance(mContext));
        mShadowAccessibilityManager.setInstalledAccessibilityServiceList(new ArrayList<>());
        when(mFragment.getContext()).thenReturn(mContext);
        when(mFragment.getActivity()).thenReturn(mActivity);
        when(mActivity.getContentResolver()).thenReturn(mContentResolver);
        when(mFragment.getPreferenceManager()).thenReturn(mPreferenceManager);
        when(mFragment.getPreferenceManager().getContext()).thenReturn(mContext);
        mContext.setTheme(R.style.Theme_AppCompat);
    }

    @Test
    public void getNonIndexableKeys_existInXmlLayout() {
        final List<String> niks = AccessibilitySettings.SEARCH_INDEX_DATA_PROVIDER
                .getNonIndexableKeys(mContext);
        final List<String> keys =
                XmlTestUtils.getKeysFromPreferenceXml(mContext, R.xml.accessibility_settings);

        assertThat(keys).containsAtLeastElementsIn(niks);
    }

    @Test
    public void getRawDataToIndex_isNull() {
        final List<SearchIndexableRaw> indexableRawList =
                AccessibilitySettings.SEARCH_INDEX_DATA_PROVIDER.getRawDataToIndex(mContext, true);

        assertThat(indexableRawList).isNull();
    }

    @Test
    @Config(shadows = {ShadowDeviceConfig.class})
    public void isRampingRingerEnabled_settingsFlagOn_Enabled() {
        Settings.Global.putInt(
                mContext.getContentResolver(), Settings.Global.APPLY_RAMPING_RINGER, ON);
        assertThat(AccessibilitySettings.isRampingRingerEnabled(mContext)).isTrue();
    }

    @Test
    @Config(shadows = {ShadowDeviceConfig.class})
    public void isRampingRingerEnabled_settingsFlagOff_Disabled() {
        Settings.Global.putInt(
                mContext.getContentResolver(), Settings.Global.APPLY_RAMPING_RINGER, OFF);
        assertThat(AccessibilitySettings.isRampingRingerEnabled(mContext)).isFalse();
    }

    @Test
    public void getServiceSummary_serviceCrash_showsStopped() {
        mServiceInfo.crashed = true;

        final CharSequence summary = AccessibilitySettings.getServiceSummary(mContext,
                mServiceInfo, SERVICE_ENABLED);

        assertThat(summary).isEqualTo(
                mContext.getString(R.string.accessibility_summary_state_stopped));
    }

    @Test
    public void getServiceSummary_invisibleToggle_shortcutDisabled_showsOffSummary() {
        setInvisibleToggleFragmentType(mServiceInfo);
        doReturn(DEFAULT_SUMMARY).when(mServiceInfo).loadSummary(any());

        final CharSequence summary = AccessibilitySettings.getServiceSummary(mContext,
                mServiceInfo, SERVICE_ENABLED);

        assertThat(summary).isEqualTo(
                mContext.getString(R.string.preference_summary_default_combination,
                        mContext.getString(R.string.accessibility_summary_shortcut_disabled),
                        DEFAULT_SUMMARY));
    }

    @Test
    public void getServiceSummary_enableService_showsEnabled() {
        doReturn(EMPTY_STRING).when(mServiceInfo).loadSummary(any());

        final CharSequence summary = AccessibilitySettings.getServiceSummary(mContext,
                mServiceInfo, SERVICE_ENABLED);

        assertThat(summary).isEqualTo(
                mContext.getString(R.string.accessibility_summary_state_enabled));
    }

    @Test
    public void getServiceSummary_disableService_showsDisabled() {
        doReturn(EMPTY_STRING).when(mServiceInfo).loadSummary(any());

        final CharSequence summary = AccessibilitySettings.getServiceSummary(mContext,
                mServiceInfo, SERVICE_DISABLED);

        assertThat(summary).isEqualTo(
                mContext.getString(R.string.accessibility_summary_state_disabled));
    }

    @Test
    public void getServiceSummary_enableServiceAndHasSummary_showsEnabledSummary() {
        final String service_enabled = mContext.getString(
                R.string.accessibility_summary_state_enabled);
        doReturn(DEFAULT_SUMMARY).when(mServiceInfo).loadSummary(any());

        final CharSequence summary = AccessibilitySettings.getServiceSummary(mContext,
                mServiceInfo, SERVICE_ENABLED);

        assertThat(summary).isEqualTo(
                mContext.getString(R.string.preference_summary_default_combination, service_enabled,
                        DEFAULT_SUMMARY));
    }

    @Test
    public void getServiceSummary_disableServiceAndHasSummary_showsCombineDisabledSummary() {
        final String service_disabled = mContext.getString(
                R.string.accessibility_summary_state_disabled);
        doReturn(DEFAULT_SUMMARY).when(mServiceInfo).loadSummary(any());

        final CharSequence summary = AccessibilitySettings.getServiceSummary(mContext,
                mServiceInfo, SERVICE_DISABLED);

        assertThat(summary).isEqualTo(
                mContext.getString(R.string.preference_summary_default_combination,
                        service_disabled, DEFAULT_SUMMARY));
    }

    @Test
    public void getServiceDescription_serviceCrash_showsStopped() {
        mServiceInfo.crashed = true;

        final CharSequence description = AccessibilitySettings.getServiceDescription(mContext,
                mServiceInfo, SERVICE_ENABLED);

        assertThat(description).isEqualTo(
                mContext.getString(R.string.accessibility_description_state_stopped));
    }

    @Test
    public void getServiceDescription_haveDescription_showsDescription() {
        doReturn(DEFAULT_DESCRIPTION).when(mServiceInfo).loadDescription(any());

        final CharSequence description = AccessibilitySettings.getServiceDescription(mContext,
                mServiceInfo, SERVICE_ENABLED);

        assertThat(description).isEqualTo(DEFAULT_DESCRIPTION);
    }

    @Test
    public void createAccessibilityServicePreferenceList_hasOneInfo_containsSameKey() {
        final String key = COMPONENT_NAME.flattenToString();
        final AccessibilitySettings.RestrictedPreferenceHelper helper =
                new AccessibilitySettings.RestrictedPreferenceHelper(mContext);
        final List<AccessibilityServiceInfo> infoList = new ArrayList<>(
                singletonList(mServiceInfo));

        final List<RestrictedPreference> preferenceList =
                helper.createAccessibilityServicePreferenceList(infoList);
        RestrictedPreference preference = preferenceList.get(0);

        assertThat(preference.getKey()).isEqualTo(key);
    }

    @Test
    public void createAccessibilityActivityPreferenceList_hasOneInfo_containsSameKey() {
        final String key = COMPONENT_NAME.flattenToString();
        final AccessibilitySettings.RestrictedPreferenceHelper helper =
                new AccessibilitySettings.RestrictedPreferenceHelper(mContext);
        setMockAccessibilityShortcutInfo(mShortcutInfo);
        final List<AccessibilityShortcutInfo> infoList = new ArrayList<>(
                singletonList(mShortcutInfo));

        final List<RestrictedPreference> preferenceList =
                helper.createAccessibilityActivityPreferenceList(infoList);
        RestrictedPreference preference = preferenceList.get(0);

        assertThat(preference.getKey()).isEqualTo(key);
    }

    @Test
    @Config(shadows = {ShadowFragment.class, ShadowUserManager.class})
    public void onCreate_haveRegisterToSpecificUrisAndActions() {
        final ArgumentCaptor<IntentFilter> captor = ArgumentCaptor.forClass(IntentFilter.class);
        final IntentFilter intentFilter;
        mFragment.onAttach(mContext);

        mFragment.onCreate(Bundle.EMPTY);

        verify(mContentResolver).registerContentObserver(
                eq(Settings.Secure.getUriFor(Settings.Secure.ACCESSIBILITY_BUTTON_TARGETS)),
                anyBoolean(),
                any(SettingsContentObserver.class));
        verify(mContentResolver).registerContentObserver(eq(Settings.Secure.getUriFor(
                Settings.Secure.ACCESSIBILITY_SHORTCUT_TARGET_SERVICE)), anyBoolean(),
                any(SettingsContentObserver.class));
        verify(mActivity, atLeast(1)).registerReceiver(any(PackageMonitor.class), captor.capture(),
                isNull(), any());
        intentFilter = captor.getAllValues().get(/* first time */ 0);
        assertThat(intentFilter.hasAction(Intent.ACTION_PACKAGE_ADDED)).isTrue();
        assertThat(intentFilter.hasAction(Intent.ACTION_PACKAGE_REMOVED)).isTrue();
    }

    @Test
    @Config(shadows = {ShadowFragment.class, ShadowUserManager.class})
    public void onDestroy_unregisterObserverAndReceiver() {
        setupFragment();
        mFragment.onPause();
        mFragment.onStop();

        mFragment.onDestroy();

        verify(mContentResolver).unregisterContentObserver(any(SettingsContentObserver.class));
        verify(mActivity).unregisterReceiver(any(PackageMonitor.class));

    }

    @Test
    @Config(shadows = {ShadowFragment.class, ShadowUserManager.class})
    public void onContentChanged_updatePreferenceInForeground_preferenceUpdated() {
        setupFragment();
        mShadowAccessibilityManager.setInstalledAccessibilityServiceList(
                singletonList(mServiceInfo));

        mFragment.onContentChanged();

        RestrictedPreference preference = mFragment.getPreferenceScreen().findPreference(
                COMPONENT_NAME.flattenToString());

        assertThat(preference).isNotNull();

    }

    @Test
    @Config(shadows = {ShadowFragment.class, ShadowUserManager.class})
    public void onContentChanged_updatePreferenceInBackground_preferenceUpdated() {
        setupFragment();
        mFragment.onPause();
        mFragment.onStop();

        mShadowAccessibilityManager.setInstalledAccessibilityServiceList(
                singletonList(mServiceInfo));

        mFragment.onContentChanged();
        mFragment.onStart();

        RestrictedPreference preference = mFragment.getPreferenceScreen().findPreference(
                COMPONENT_NAME.flattenToString());

        assertThat(preference).isNotNull();

    }

    private AccessibilityServiceInfo getMockAccessibilityServiceInfo(String packageName,
            String className) {
        final ApplicationInfo applicationInfo = new ApplicationInfo();
        final ServiceInfo serviceInfo = new ServiceInfo();
        applicationInfo.packageName = packageName;
        serviceInfo.packageName = packageName;
        serviceInfo.name = className;
        serviceInfo.applicationInfo = applicationInfo;

        final ResolveInfo resolveInfo = new ResolveInfo();
        resolveInfo.serviceInfo = serviceInfo;
        try {
            final AccessibilityServiceInfo info = new AccessibilityServiceInfo(resolveInfo,
                    mContext);
            info.setComponentName(new ComponentName(packageName, className));
            return info;
        } catch (XmlPullParserException | IOException e) {
            // Do nothing
        }

        return null;
    }

    private void setMockAccessibilityShortcutInfo(AccessibilityShortcutInfo mockInfo) {
        final ActivityInfo activityInfo = Mockito.mock(ActivityInfo.class);
        when(mockInfo.getActivityInfo()).thenReturn(activityInfo);
        when(activityInfo.loadLabel(any())).thenReturn(DEFAULT_LABEL);
        when(mockInfo.loadSummary(any())).thenReturn(DEFAULT_SUMMARY);
        when(mockInfo.loadDescription(any())).thenReturn(DEFAULT_DESCRIPTION);
        when(mockInfo.getComponentName()).thenReturn(COMPONENT_NAME);
    }

    private void setInvisibleToggleFragmentType(AccessibilityServiceInfo info) {
        info.getResolveInfo().serviceInfo.applicationInfo.targetSdkVersion = Build.VERSION_CODES.R;
        info.flags |= AccessibilityServiceInfo.FLAG_REQUEST_ACCESSIBILITY_BUTTON;
    }

    private void setupFragment() {
        mFragment.onAttach(mContext);
        mFragment.onCreate(Bundle.EMPTY);
        mFragment.onStart();
        mFragment.onResume();
    }
}
