/*
 * Copyright (C) 2020 The Android Open Source Project
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

package com.android.car.notification;

import static com.google.common.truth.Truth.assertThat;

import static org.mockito.ArgumentMatchers.any;
import static org.mockito.ArgumentMatchers.anyInt;
import static org.mockito.ArgumentMatchers.anyString;
import static org.mockito.ArgumentMatchers.eq;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.when;

import android.app.KeyguardManager;
import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.Looper;
import android.os.UserHandle;
import android.service.notification.NotificationListenerService;
import android.service.notification.StatusBarNotification;
import android.testing.TestableContext;
import android.view.View;

import androidx.test.ext.junit.runners.AndroidJUnit4;
import androidx.test.platform.app.InstrumentationRegistry;

import com.android.car.notification.headsup.CarHeadsUpNotificationContainer;
import com.android.car.notification.utils.MockMessageNotificationBuilder;

import org.junit.Before;
import org.junit.Rule;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;

import java.util.HashMap;
import java.util.Map;

@RunWith(AndroidJUnit4.class)
public class CarHeadsUpNotificationManagerTest {
    private static final String PKG_1 = "package_1";
    private static final String PKG_2 = "package_2";
    private static final String OP_PKG = "OpPackage";
    private static final int ID = 1;
    private static final String TAG = "Tag";
    private static final int UID = 2;
    private static final int INITIAL_PID = 3;
    private static final String CHANNEL_ID = "CHANNEL_ID";
    private static final String CHANNEL_NAME = "CHANNEL_NAME";
    private static final String CONTENT_TITLE = "CONTENT_TITLE";
    private static final String OVERRIDE_GROUP_KEY = "OVERRIDE_GROUP_KEY";
    private static final String EXTRA_BIG_TEXT_VALUE = "EXTRA_BIG_TEXT";
    private static final String EXTRA_SUMMARY_TEXT_VALUE = "EXTRA_SUMMARY_TEXT";
    private static final long POST_TIME = 12345L;
    private static final UserHandle USER_HANDLE = new UserHandle(/* userId= */ 12);
    private static final NotificationChannel CHANNEL = new NotificationChannel(CHANNEL_ID,
            CHANNEL_NAME, NotificationManager.IMPORTANCE_HIGH);
    @Rule
    public final TestableContext mContext = new TestableContext(
            InstrumentationRegistry.getInstrumentation().getTargetContext()) {
        @Override
        public Context createApplicationContext(ApplicationInfo application, int flags) {
            return this;
        }
    };
    @Mock
    NotificationListenerService.RankingMap mRankingMapMock;
    @Mock
    NotificationListenerService.Ranking mRankingMock;
    @Mock
    NotificationClickHandlerFactory mClickHandlerFactory;
    @Mock
    NotificationDataManager mNotificationDataManager;
    @Mock
    PackageManager mPackageManager;
    @Mock
    CarHeadsUpNotificationContainer mCarHeadsUpNotificationContainer;
    @Mock
    KeyguardManager mKeyguardManager;
    private CarHeadsUpNotificationManager mManager;
    private AlertEntry mAlertEntryMessageHeadsUp;
    private AlertEntry mAlertEntryNavigationHeadsUp;
    private AlertEntry mAlertEntryCallHeadsUp;
    private AlertEntry mAlertEntryInboxHeadsUp;
    private AlertEntry mAlertEntryWarningHeadsUp;
    private AlertEntry mAlertEntryEmergencyHeadsUp;
    private AlertEntry mAlertEntryCarInformationHeadsUp;
    private Map<String, AlertEntry> mActiveNotifications;

    @Before
    public void setup() throws PackageManager.NameNotFoundException {
        MockitoAnnotations.initMocks(this);

        mContext.getOrCreateTestableResources().addOverride(
                R.bool.config_showNavigationHeadsup, /* value= */ true);
        ApplicationInfo applicationInfo = mock(ApplicationInfo.class);
        when(mPackageManager.getApplicationInfoAsUser(anyString(),
                eq(PackageManager.MATCH_UNINSTALLED_PACKAGES), anyInt())).thenReturn(
                applicationInfo);
        when(mPackageManager.getApplicationInfo(anyString(),
                eq(PackageManager.MATCH_UNINSTALLED_PACKAGES))).thenReturn(applicationInfo);
        when(mPackageManager.getResourcesForApplication(applicationInfo)).thenReturn(
                mContext.getResources());
        mContext.setMockPackageManager(mPackageManager);

        when(mKeyguardManager.isKeyguardLocked()).thenReturn(false);
        mContext.addMockSystemService(Context.KEYGUARD_SERVICE, mKeyguardManager);

        when(mClickHandlerFactory.getClickHandler(any())).thenReturn(v -> {
        });

        when(mRankingMock.getChannel()).thenReturn(CHANNEL);
        when(mRankingMapMock.getRanking(any(), any())).thenReturn(true);
        when(mRankingMock.getImportance()).thenReturn(NotificationManager.IMPORTANCE_HIGH);

        Notification mNotificationMessageHeadsUp = new MockMessageNotificationBuilder(mContext,
                CHANNEL_ID, android.R.drawable.sym_def_app_icon)
                .setContentTitle(CONTENT_TITLE)
                .setCategory(Notification.CATEGORY_MESSAGE)
                .setHasMessagingStyle(true)
                .setHasReplyAction(true)
                .setHasMarkAsRead(true)
                .build();
        Notification mNotificationNavigationHeadsUp = new MockMessageNotificationBuilder(mContext,
                CHANNEL_ID, android.R.drawable.sym_def_app_icon)
                .setContentTitle(CONTENT_TITLE)
                .setCategory(Notification.CATEGORY_NAVIGATION)
                .build();
        Notification mNotificationCallHeadsUp = new MockMessageNotificationBuilder(mContext,
                CHANNEL_ID, android.R.drawable.sym_def_app_icon)
                .setContentTitle(CONTENT_TITLE)
                .setCategory(Notification.CATEGORY_CALL)
                .build();
        Notification mNotificationWarningHeadsUp = new MockMessageNotificationBuilder(mContext,
                CHANNEL_ID, android.R.drawable.sym_def_app_icon)
                .setContentTitle(CONTENT_TITLE)
                .setCategory(Notification.CATEGORY_CAR_WARNING)
                .build();
        Notification mNotificationEmergencyHeadsUp = new MockMessageNotificationBuilder(mContext,
                CHANNEL_ID, android.R.drawable.sym_def_app_icon)
                .setContentTitle(CONTENT_TITLE)
                .setCategory(Notification.CATEGORY_CAR_EMERGENCY)
                .build();
        Notification mNotificationCarInformationHeadsUp = new MockMessageNotificationBuilder(
                mContext, CHANNEL_ID, android.R.drawable.sym_def_app_icon)
                .setContentTitle(CONTENT_TITLE)
                .setCategory(Notification.CATEGORY_CAR_INFORMATION)
                .build();

        Bundle bundle = new Bundle();
        bundle.putString(Notification.EXTRA_BIG_TEXT, EXTRA_BIG_TEXT_VALUE);
        bundle.putString(Notification.EXTRA_SUMMARY_TEXT, EXTRA_SUMMARY_TEXT_VALUE);
        Notification mNotificationBuilderInboxHeadsUp = new MockMessageNotificationBuilder(
                mContext, CHANNEL_ID, android.R.drawable.sym_def_app_icon)
                .setContentTitle(CONTENT_TITLE)
                .setCategory(Notification.CATEGORY_MESSAGE)
                .setExtras(bundle)
                .setHasMessagingStyle(true)
                .setHasReplyAction(true)
                .setHasMarkAsRead(true)
                .build();

        mAlertEntryMessageHeadsUp = new AlertEntry(
                new StatusBarNotification(PKG_1, OP_PKG, ID, TAG, UID, INITIAL_PID,
                        mNotificationMessageHeadsUp, USER_HANDLE, OVERRIDE_GROUP_KEY, POST_TIME));
        mAlertEntryNavigationHeadsUp = new AlertEntry(
                new StatusBarNotification(PKG_2, OP_PKG, ID, TAG, UID, INITIAL_PID,
                        mNotificationNavigationHeadsUp, USER_HANDLE, OVERRIDE_GROUP_KEY,
                        POST_TIME));
        mAlertEntryCallHeadsUp = new AlertEntry(
                new StatusBarNotification(PKG_1, OP_PKG, ID, TAG, UID, INITIAL_PID,
                        mNotificationCallHeadsUp, USER_HANDLE, OVERRIDE_GROUP_KEY, POST_TIME));
        mAlertEntryInboxHeadsUp = new AlertEntry(
                new StatusBarNotification(PKG_1, OP_PKG, ID, TAG, UID, INITIAL_PID,
                        mNotificationBuilderInboxHeadsUp, USER_HANDLE, OVERRIDE_GROUP_KEY,
                        POST_TIME));
        mAlertEntryWarningHeadsUp = new AlertEntry(
                new StatusBarNotification(PKG_1, OP_PKG, ID, TAG, UID, INITIAL_PID,
                        mNotificationWarningHeadsUp, USER_HANDLE, OVERRIDE_GROUP_KEY, POST_TIME));
        mAlertEntryEmergencyHeadsUp = new AlertEntry(
                new StatusBarNotification(PKG_1, OP_PKG, ID, TAG, UID, INITIAL_PID,
                        mNotificationEmergencyHeadsUp, USER_HANDLE, OVERRIDE_GROUP_KEY,
                        POST_TIME));
        mAlertEntryCarInformationHeadsUp = new AlertEntry(
                new StatusBarNotification(PKG_1, OP_PKG, ID, TAG, UID, INITIAL_PID,
                        mNotificationCarInformationHeadsUp, USER_HANDLE, OVERRIDE_GROUP_KEY,
                        POST_TIME));

        mActiveNotifications = new HashMap<>();

        mManager = new CarHeadsUpNotificationManager(mContext, mClickHandlerFactory,
                mCarHeadsUpNotificationContainer) {
            @Override
            protected NotificationListenerService.Ranking getRanking() {
                return mRankingMock;
            }
        };
        mManager.setNotificationDataManager(mNotificationDataManager);
    }

    @Test
    public void maybeShowHeadsUp_isNotImportant_returnsNull()
            throws PackageManager.NameNotFoundException {
        when(mRankingMock.getImportance()).thenReturn(NotificationManager.IMPORTANCE_DEFAULT);
        setPackageInfo(PKG_2, /* isSystem= */ false, /* isSignedWithPlatformKey= */ false);

        mManager.maybeShowHeadsUp(mAlertEntryNavigationHeadsUp, mRankingMapMock,
                mActiveNotifications);

        View notificationView = getNotificationView(mManager.getActiveHeadsUpNotifications().get(
                mAlertEntryNavigationHeadsUp.getKey()));
        assertThat(notificationView).isNull();
    }

    /**
     * Test that Heads up notification should be shown when notification is IMPORTANCE_HIGH.
     */
    @Test
    public void maybeShowHeadsUp_isImportanceHigh_returnsNotNull()
            throws PackageManager.NameNotFoundException {
        // This test fails if looper isn't forced to prepare due to Handler creation in {@link
        // HeadsUpEntry}.
        Looper.prepare();
        setPackageInfo(PKG_2, /* isSystem= */ false, /* isSignedWithPlatformKey= */ false);

        mManager.maybeShowHeadsUp(mAlertEntryNavigationHeadsUp, mRankingMapMock,
                mActiveNotifications);

        View notificationView = getNotificationView(mManager.getActiveHeadsUpNotifications().get(
                mAlertEntryNavigationHeadsUp.getKey()));
        assertThat(notificationView).isNotNull();
    }

    @Test
    public void getActiveHeadsUpNotifications_shouldReturnOne()
            throws PackageManager.NameNotFoundException {
        // This test fails if looper isn't forced to prepare due to Handler creation in {@link
        // HeadsUpEntry}.
        Looper.prepare();
        setPackageInfo(PKG_2, /* isSystem= */ false, /* isSignedWithPlatformKey= */ false);
        mManager.maybeShowHeadsUp(mAlertEntryNavigationHeadsUp, mRankingMapMock,
                mActiveNotifications);

        Map<String, HeadsUpEntry> activeHeadsUpNotifications =
                mManager.getActiveHeadsUpNotifications();

        assertThat(activeHeadsUpNotifications.size()).isEqualTo(1);
    }

    @Test
    public void getActiveHeadsUpNotifications_diffNotifications_shouldReturnTwo()
            throws PackageManager.NameNotFoundException {
        // This test fails if looper isn't forced to prepare due to Handler creation in {@link
        // HeadsUpEntry}.
        Looper.prepare();
        setPackageInfo(PKG_1, /* isSystem= */ false, /* isSignedWithPlatformKey= */ false);
        setPackageInfo(PKG_2, /* isSystem= */ false, /* isSignedWithPlatformKey= */ false);
        mManager.maybeShowHeadsUp(mAlertEntryCallHeadsUp, mRankingMapMock, mActiveNotifications);
        mManager.maybeShowHeadsUp(mAlertEntryNavigationHeadsUp, mRankingMapMock,
                mActiveNotifications);

        Map<String, HeadsUpEntry> activeHeadsUpNotifications =
                mManager.getActiveHeadsUpNotifications();

        assertThat(activeHeadsUpNotifications.size()).isEqualTo(2);
    }

    @Test
    public void getActiveHeadsUpNotifications_sameNotifications_shouldReturnOne()
            throws PackageManager.NameNotFoundException {
        // This test fails if looper isn't forced to prepare due to Handler creation in {@link
        // HeadsUpEntry}.
        Looper.prepare();
        setPackageInfo(PKG_1, /* isSystem= */ false, /* isSignedWithPlatformKey= */ false);
        mManager.maybeShowHeadsUp(mAlertEntryCallHeadsUp, mRankingMapMock, mActiveNotifications);
        mManager.maybeShowHeadsUp(mAlertEntryCallHeadsUp, mRankingMapMock, mActiveNotifications);

        Map<String, HeadsUpEntry> activeHeadsUpNotifications =
                mManager.getActiveHeadsUpNotifications();

        assertThat(activeHeadsUpNotifications.size()).isEqualTo(1);
    }

    @Test
    public void maybeShowHeadsUp_categoryCarInformation_returnsNull()
            throws PackageManager.NameNotFoundException {
        setPackageInfo(PKG_1, /* isSystem= */ false, /* isSignedWithPlatformKey= */ false);

        mManager.maybeShowHeadsUp(mAlertEntryCarInformationHeadsUp, mRankingMapMock,
                mActiveNotifications);

        View notificationView = getNotificationView(
                mManager.getActiveHeadsUpNotifications().get(
                        mAlertEntryCarInformationHeadsUp.getKey()));
        assertThat(notificationView).isNull();
    }

    @Test
    public void maybeShowHeadsUp_categoryMessage_returnsNotNull()
            throws PackageManager.NameNotFoundException {
        // This test fails if looper isn't forced to prepare due to Handler creation in {@link
        // HeadsUpEntry}.
        Looper.prepare();
        setPackageInfo(PKG_1, /* isSystem= */ false, /* isSignedWithPlatformKey= */ false);

        mManager.maybeShowHeadsUp(mAlertEntryMessageHeadsUp, mRankingMapMock,
                mActiveNotifications);

        View notificationView = getNotificationView(
                mManager.getActiveHeadsUpNotifications().get(
                        mAlertEntryMessageHeadsUp.getKey()));
        assertThat(notificationView).isNotNull();
    }

    @Test
    public void maybeShowHeadsUp_categoryCall_returnsNotNull()
            throws PackageManager.NameNotFoundException {
        // This test fails if looper isn't forced to prepare due to Handler creation in {@link
        // HeadsUpEntry}.
        Looper.prepare();
        setPackageInfo(PKG_1, /* isSystem= */ false, /* isSignedWithPlatformKey= */ false);

        mManager.maybeShowHeadsUp(mAlertEntryCallHeadsUp, mRankingMapMock, mActiveNotifications);

        View notificationView = getNotificationView(
                mManager.getActiveHeadsUpNotifications().get(mAlertEntryCallHeadsUp.getKey()));
        assertThat(notificationView).isNotNull();
    }

    @Test
    public void maybeShowHeadsUp_categoryNavigation_returnsNotNull()
            throws PackageManager.NameNotFoundException {
        // This test fails if looper isn't forced to prepare due to Handler creation in {@link
        // HeadsUpEntry}.
        Looper.prepare();
        setPackageInfo(PKG_1, /* isSystem= */ false, /* isSignedWithPlatformKey= */ false);

        mManager.maybeShowHeadsUp(mAlertEntryNavigationHeadsUp, mRankingMapMock,
                mActiveNotifications);

        View notificationView = getNotificationView(mManager.getActiveHeadsUpNotifications().get(
                mAlertEntryNavigationHeadsUp.getKey()));
        assertThat(notificationView).isNotNull();
    }

    @Test
    public void maybeShowHeadsUp_inboxHeadsUp_returnsNotNull()
            throws PackageManager.NameNotFoundException {
        // This test fails if looper isn't forced to prepare due to Handler creation in {@link
        // HeadsUpEntry}.
        Looper.prepare();
        setPackageInfo(PKG_1, /* isSystem= */ false, /* isSignedWithPlatformKey= */ false);

        mManager.maybeShowHeadsUp(mAlertEntryInboxHeadsUp, mRankingMapMock, mActiveNotifications);

        View notificationView = getNotificationView(
                mManager.getActiveHeadsUpNotifications().get(mAlertEntryInboxHeadsUp.getKey()));
        assertThat(notificationView).isNotNull();
    }

    @Test
    public void maybeShowHeadsUp_isSignedWithPlatformKey_returnsNotNull()
            throws PackageManager.NameNotFoundException {
        // This test fails if looper isn't forced to prepare due to Handler creation in {@link
        // HeadsUpEntry}.
        Looper.prepare();
        setPackageInfo(PKG_1, /* isSystem= */ false, /* isSignedWithPlatformKey= */ true);

        mManager.maybeShowHeadsUp(mAlertEntryCarInformationHeadsUp, mRankingMapMock,
                mActiveNotifications);

        View notificationView = getNotificationView(mManager.getActiveHeadsUpNotifications().get(
                mAlertEntryCarInformationHeadsUp.getKey()));
        assertThat(notificationView).isNotNull();
    }

    @Test
    public void maybeShowHeadsUp_isSystemApp_returnsNotNull()
            throws PackageManager.NameNotFoundException {
        // This test fails if looper isn't forced to prepare due to Handler creation in {@link
        // HeadsUpEntry}.
        Looper.prepare();
        setPackageInfo(PKG_1, /* isSystem= */ true, /* isSignedWithPlatformKey= */ false);

        mManager.maybeShowHeadsUp(mAlertEntryCarInformationHeadsUp, mRankingMapMock,
                mActiveNotifications);

        View notificationView = getNotificationView(mManager.getActiveHeadsUpNotifications().get(
                mAlertEntryCarInformationHeadsUp.getKey()));
        assertThat(notificationView).isNotNull();
    }

    @Test
    public void maybeShowHeadsUp_nonMutedNotification_headsUpShown()
            throws PackageManager.NameNotFoundException {
        // This test fails if looper isn't forced to prepare due to Handler creation in {@link
        // HeadsUpEntry}.
        Looper.prepare();
        when(mNotificationDataManager.isMessageNotificationMuted(any())).thenReturn(false);
        setPackageInfo(PKG_1, /* isSystem= */ false, /* isSignedWithPlatformKey= */ false);

        mManager.maybeShowHeadsUp(mAlertEntryInboxHeadsUp, mRankingMapMock, mActiveNotifications);

        View notificationView = getNotificationView(
                mManager.getActiveHeadsUpNotifications().get(mAlertEntryInboxHeadsUp.getKey()));
        assertThat(notificationView).isNotNull();
    }

    @Test
    public void maybeShowHeadsUp_mutedNotification_headsUpNotShown()
            throws PackageManager.NameNotFoundException {
        when(mNotificationDataManager.isMessageNotificationMuted(any())).thenReturn(true);
        setPackageInfo(PKG_1, /* isSystem= */ false, /* isSignedWithPlatformKey= */ false);

        mManager.maybeShowHeadsUp(mAlertEntryInboxHeadsUp, mRankingMapMock, mActiveNotifications);

        View notificationView = getNotificationView(
                mManager.getActiveHeadsUpNotifications().get(mAlertEntryInboxHeadsUp.getKey()));
        assertThat(notificationView).isNull();
    }

    private void setPackageInfo(String packageName, boolean isSystem,
            boolean isSignedWithPlatformKey) throws PackageManager.NameNotFoundException {
        PackageInfo packageInfo = mock(PackageInfo.class);
        ApplicationInfo applicationInfo = mock(ApplicationInfo.class);
        packageInfo.packageName = packageName;
        when(applicationInfo.isPrivilegedApp()).thenReturn(isSystem);
        when(applicationInfo.isSystemApp()).thenReturn(isSystem);
        when(applicationInfo.isSignedWithPlatformKey()).thenReturn(isSignedWithPlatformKey);
        packageInfo.applicationInfo = applicationInfo;
        when(mPackageManager.getPackageInfoAsUser(eq(packageName), anyInt(), anyInt())).thenReturn(
                packageInfo);
    }

    private View getNotificationView(HeadsUpEntry currentNotification) {
        return currentNotification == null ? null : currentNotification.getNotificationView();
    }
}