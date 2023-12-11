/*
 * Copyright (C) 2019 The Android Open Source Project
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
 * limitations under the License
 */

package android.server.wm;

import static android.app.AppOpsManager.MODE_ALLOWED;
import static android.app.AppOpsManager.MODE_ERRORED;
import static android.server.wm.UiDeviceUtils.pressHomeButton;
import static android.server.wm.WindowManagerState.STATE_INITIALIZING;
import static android.server.wm.backgroundactivity.appa.Components.APP_A_BACKGROUND_ACTIVITY;
import static android.server.wm.backgroundactivity.appa.Components.APP_A_FOREGROUND_ACTIVITY;
import static android.server.wm.backgroundactivity.appa.Components.APP_A_SECOND_BACKGROUND_ACTIVITY;
import static android.server.wm.backgroundactivity.appa.Components.APP_A_SEND_PENDING_INTENT_RECEIVER;
import static android.server.wm.backgroundactivity.appa.Components.APP_A_SIMPLE_ADMIN_RECEIVER;
import static android.server.wm.backgroundactivity.appa.Components.APP_A_START_ACTIVITY_RECEIVER;
import static android.server.wm.backgroundactivity.appa.Components.ForegroundActivity.ACTION_FINISH_ACTIVITY;
import static android.server.wm.backgroundactivity.appa.Components.ForegroundActivity.ACTION_LAUNCH_BACKGROUND_ACTIVITIES;
import static android.server.wm.backgroundactivity.appa.Components.ForegroundActivity.LAUNCH_BACKGROUND_ACTIVITY_EXTRA;
import static android.server.wm.backgroundactivity.appa.Components.ForegroundActivity.LAUNCH_INTENTS_EXTRA;
import static android.server.wm.backgroundactivity.appa.Components.ForegroundActivity.LAUNCH_SECOND_BACKGROUND_ACTIVITY_EXTRA;
import static android.server.wm.backgroundactivity.appa.Components.ForegroundActivity.RELAUNCH_FOREGROUND_ACTIVITY_EXTRA;
import static android.server.wm.backgroundactivity.appa.Components.ForegroundActivity.START_ACTIVITY_FROM_FG_ACTIVITY_DELAY_MS_EXTRA;
import static android.server.wm.backgroundactivity.appa.Components.ForegroundActivity.START_ACTIVITY_FROM_FG_ACTIVITY_NEW_TASK_EXTRA;
import static android.server.wm.backgroundactivity.appa.Components.SendPendingIntentReceiver.IS_BROADCAST_EXTRA;
import static android.server.wm.backgroundactivity.appa.Components.StartBackgroundActivityReceiver.START_ACTIVITY_DELAY_MS_EXTRA;
import static android.server.wm.backgroundactivity.appb.Components.APP_B_FOREGROUND_ACTIVITY;
import static android.server.wm.backgroundactivity.common.CommonComponents.EVENT_NOTIFIER_EXTRA;

import static com.android.compatibility.common.util.SystemUtil.runShellCommand;
import static com.android.compatibility.common.util.SystemUtil.runWithShellPermissionIdentity;

import static com.google.common.truth.Truth.assertThat;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;

import android.Manifest;
import android.app.UiAutomation;
import android.content.ComponentName;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.content.pm.UserInfo;
import android.os.ResultReceiver;
import android.os.UserManager;
import android.platform.test.annotations.Presubmit;
import android.platform.test.annotations.SystemUserOnly;
import android.server.wm.backgroundactivity.common.CommonComponents.Event;
import android.server.wm.backgroundactivity.common.EventReceiver;

import androidx.annotation.Nullable;
import androidx.test.filters.FlakyTest;
import androidx.test.platform.app.InstrumentationRegistry;

import com.android.compatibility.common.util.AppOpsUtils;

import org.junit.After;
import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;

import java.util.List;
import java.util.concurrent.TimeoutException;
import java.util.stream.Stream;

/**
 * This class covers all test cases for starting/blocking background activities.
 * As instrumentation tests started by shell are whitelisted to allow starting background activity,
 * tests can't be done in this app alone.
 * Hence, there are 2 extra apps, appA and appB. This class will send commands to appA/appB, for
 * example, send a broadcast to appA and ask it to start a background activity, and we will monitor
 * the result and see if it starts an activity successfully.
 */
@Presubmit
public class BackgroundActivityLaunchTest extends ActivityManagerTestBase {

    private static final int ACTIVITY_FOCUS_TIMEOUT_MS = 3000;
    private static final String APP_A_PACKAGE_NAME = APP_A_FOREGROUND_ACTIVITY.getPackageName();
    private static final long ACTIVITY_BG_START_GRACE_PERIOD_MS = 10 * 1000;
    private static final int ACTIVITY_START_TIMEOUT_MS = 5000;
    private static final int ACTIVITY_NOT_RESUMED_TIMEOUT_MS = 5000;

    private static final String TEST_PACKAGE_APP_A = "android.server.wm.backgroundactivity.appa";
    private static final String TEST_PACKAGE_APP_B = "android.server.wm.backgroundactivity.appb";
    public static final ComponentName APP_A_RELAUNCHING_ACTIVITY =
            new ComponentName(TEST_PACKAGE_APP_A,
                    "android.server.wm.backgroundactivity.appa.RelaunchingActivity");
    public static final ComponentName APP_A_PIP_ACTIVITY =
            new ComponentName(TEST_PACKAGE_APP_A,
                    "android.server.wm.backgroundactivity.appa.PipActivity");
    public static final ComponentName APP_A_VIRTUAL_DISPLAY_ACTIVITY =
            new ComponentName(TEST_PACKAGE_APP_A,
                    "android.server.wm.backgroundactivity.appa.VirtualDisplayActivity");
    private static final String SHELL_PACKAGE = "com.android.shell";

    /**
     * Tests can be executed as soon as the device has booted. When that happens the broadcast queue
     * is long and it takes some time to process the broadcast we just sent.
     */
    private static final int BROADCAST_DELIVERY_TIMEOUT_MS = 60000;

    @Override
    @Before
    public void setUp() throws Exception {
        // disable SAW appopp for AppA (it's granted autonatically when installed in CTS)
        AppOpsUtils.setOpMode(APP_A_PACKAGE_NAME, "android:system_alert_window", MODE_ERRORED);
        assertEquals(AppOpsUtils.getOpMode(APP_A_PACKAGE_NAME, "android:system_alert_window"),
                MODE_ERRORED);

        super.setUp();
        assertNull(mWmState.getTaskByActivity(APP_A_BACKGROUND_ACTIVITY));
        assertNull(mWmState.getTaskByActivity(APP_A_FOREGROUND_ACTIVITY));
        assertNull(mWmState.getTaskByActivity(APP_B_FOREGROUND_ACTIVITY));

        runShellCommand("cmd deviceidle tempwhitelist -d 100000 "
                + APP_A_FOREGROUND_ACTIVITY.getPackageName());
        runShellCommand("cmd deviceidle tempwhitelist -d 100000 "
                + APP_B_FOREGROUND_ACTIVITY.getPackageName());
    }

    @After
    public void tearDown() throws Exception {
        // We do this before anything else, because having an active device owner can prevent us
        // from being able to force stop apps. (b/142061276)
        runWithShellPermissionIdentity(() -> {
            runShellCommand("dpm remove-active-admin --user current "
                    + APP_A_SIMPLE_ADMIN_RECEIVER.flattenToString());
        });

        stopTestPackage(TEST_PACKAGE_APP_A);
        stopTestPackage(TEST_PACKAGE_APP_B);
        AppOpsUtils.reset(APP_A_PACKAGE_NAME);
        AppOpsUtils.reset(SHELL_PACKAGE);
    }

    @Test
    public void testBackgroundActivityBlocked() throws Exception {
        // Start AppA background activity and blocked
        Intent intent = new Intent();
        intent.setComponent(APP_A_START_ACTIVITY_RECEIVER);
        mContext.sendBroadcast(intent);
        boolean result = waitForActivityFocused(APP_A_BACKGROUND_ACTIVITY);
        assertFalse("Should not able to launch background activity", result);
        assertTaskStack(null, APP_A_BACKGROUND_ACTIVITY);
    }

    @Test
    public void testStartBgActivity_usingStartActivitiesFromBackgroundPermission()
            throws Exception {
        // Disable SAW app op for shell, since that can also allow starting activities from bg.
        AppOpsUtils.setOpMode(SHELL_PACKAGE, "android:system_alert_window", MODE_ERRORED);

        // Launch the activity via a shell command, this way the system doesn't have info on which
        // app launched the activity and thus won't use instrumentation privileges to launch it. But
        // the shell has the START_ACTIVITIES_FROM_BACKGROUND permission, so we expect it to
        // succeed.
        // See testBackgroundActivityBlocked() for a case where an app without the
        // START_ACTIVITIES_FROM_BACKGROUND permission is blocked from launching the activity from
        // the background.
        launchActivity(APP_A_BACKGROUND_ACTIVITY);

        // If the activity launches, it means the START_ACTIVITIES_FROM_BACKGROUND permission works.
        assertEquals("Launched activity should be at the top",
                ComponentNameUtils.getActivityName(APP_A_BACKGROUND_ACTIVITY),
                mWmState.getTopActivityName(0));
    }

    @Test
    @FlakyTest(bugId = 155454710)
    public void testBackgroundActivityNotBlockedWithinGracePeriod() throws Exception {
        // Start AppA foreground activity
        Intent firstIntent = new Intent();
        firstIntent.setComponent(APP_A_FOREGROUND_ACTIVITY);
        firstIntent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        mContext.startActivity(firstIntent);
        boolean firstResult = waitForActivityFocused(APP_A_FOREGROUND_ACTIVITY);
        assertTrue("Not able to start foreground activity", firstResult);
        // Don't press home button to avoid stop app switches
        mContext.sendBroadcast(new Intent(ACTION_FINISH_ACTIVITY));
        mWmState.waitAndAssertActivityRemoved(APP_A_FOREGROUND_ACTIVITY);
        Intent secondIntent = new Intent();
        secondIntent.setComponent(APP_A_START_ACTIVITY_RECEIVER);

        mContext.sendBroadcast(secondIntent);
        boolean secondResult = waitForActivityFocused(APP_A_BACKGROUND_ACTIVITY);
        assertTrue("Should be able to launch background activity", secondResult);
    }

    @Test
    public void testBackgroundActivityNotBlockedWhenSystemAlertWindowGranted() throws Exception {
        // enable appopp for SAW for this test
        AppOpsUtils.setOpMode(APP_A_PACKAGE_NAME, "android:system_alert_window", MODE_ALLOWED);
        assertEquals(AppOpsUtils.getOpMode(APP_A_PACKAGE_NAME, "android:system_alert_window"),
                MODE_ALLOWED);

        // Start AppA background activity successfully as the package has SAW
        Intent intent = new Intent();
        intent.setComponent(APP_A_START_ACTIVITY_RECEIVER);
        mContext.sendBroadcast(intent);
        boolean result = waitForActivityFocused(APP_A_BACKGROUND_ACTIVITY);
        assertTrue("Not able to start foreground activity", result);
    }

    @Test
    public void testBackgroundActivityNotBlockedWhenForegroundActivityExists() throws Exception {
        // Start AppA foreground activity
        Intent intent = new Intent();
        intent.setComponent(APP_A_FOREGROUND_ACTIVITY);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        mContext.startActivity(intent);
        boolean result = waitForActivityFocused(APP_A_FOREGROUND_ACTIVITY);
        assertTrue("Not able to start foreground activity", result);
        assertTaskStack(new ComponentName[]{APP_A_FOREGROUND_ACTIVITY}, APP_A_FOREGROUND_ACTIVITY);

        // Start AppA background activity successfully as there's a foreground activity
        intent = new Intent();
        intent.setComponent(APP_A_START_ACTIVITY_RECEIVER);
        mContext.sendBroadcast(intent);
        result = waitForActivityFocused(APP_A_BACKGROUND_ACTIVITY);
        assertTrue("Not able to launch background activity", result);
        assertTaskStack(new ComponentName[]{APP_A_FOREGROUND_ACTIVITY}, APP_A_FOREGROUND_ACTIVITY);
        assertTaskStack(new ComponentName[]{APP_A_BACKGROUND_ACTIVITY}, APP_A_BACKGROUND_ACTIVITY);
    }

    @Test
    public void testActivityNotBlockedWhenForegroundActivityLaunch() throws Exception {
        // Start foreground activity, and foreground activity able to launch background activity
        // successfully
        Intent intent = new Intent();
        intent.setComponent(APP_A_FOREGROUND_ACTIVITY);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        intent.putExtra(LAUNCH_BACKGROUND_ACTIVITY_EXTRA, true);
        mContext.startActivity(intent);
        boolean result = waitForActivityFocused(APP_A_BACKGROUND_ACTIVITY);
        assertTrue("Not able to launch background activity", result);
        assertTaskStack(new ComponentName[]{APP_A_BACKGROUND_ACTIVITY, APP_A_FOREGROUND_ACTIVITY},
                APP_A_FOREGROUND_ACTIVITY);
    }

    @Test
    public void testActivityBroughtToTopOfTaskWhenLaunchedInTheBackground() throws Exception {
        // Start foreground activity, and foreground activity able to launch background activity
        // successfully
        Intent intent = new Intent();
        intent.setComponent(APP_A_FOREGROUND_ACTIVITY);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        mContext.startActivity(intent);
        boolean result = waitForActivityFocused(ACTIVITY_FOCUS_TIMEOUT_MS,
                APP_A_FOREGROUND_ACTIVITY);
        assertTrue("Not able to launch background activity", result);
        assertTaskStack(new ComponentName[]{APP_A_FOREGROUND_ACTIVITY}, APP_A_FOREGROUND_ACTIVITY);
        // We can't resume app switching after pressing home button, otherwise the grace period
        // will allow the starts.
        pressHomeAndWaitHomeResumed();

        mContext.sendBroadcast(getLaunchActivitiesBroadcast(APP_A_BACKGROUND_ACTIVITY));

        result = waitForActivityFocused(APP_A_FOREGROUND_ACTIVITY);
        assertFalse("Previously foreground Activity should not be able to make it focused", result);
        result = waitForActivityFocused(APP_A_BACKGROUND_ACTIVITY);
        assertFalse("Previously background Activity should not be able to make it focused", result);
        assertTaskStack(new ComponentName[] {APP_A_BACKGROUND_ACTIVITY, APP_A_FOREGROUND_ACTIVITY},
                APP_A_FOREGROUND_ACTIVITY);
    }

    @Test
    @FlakyTest(bugId = 143522449)
    public void testActivityBlockedWhenLaunchedAfterHomePress() throws Exception {
        Intent intent = new Intent();
        intent.setComponent(APP_A_FOREGROUND_ACTIVITY);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        intent.putExtra(LAUNCH_BACKGROUND_ACTIVITY_EXTRA, true);
        intent.putExtra(START_ACTIVITY_FROM_FG_ACTIVITY_DELAY_MS_EXTRA, 2000);
        intent.putExtra(START_ACTIVITY_FROM_FG_ACTIVITY_NEW_TASK_EXTRA, true);
        mContext.startActivity(intent);
        boolean result = waitForActivityFocused(ACTIVITY_FOCUS_TIMEOUT_MS,
                APP_A_FOREGROUND_ACTIVITY);
        assertTrue("Not able to launch background activity", result);
        assertTaskStack(new ComponentName[]{APP_A_FOREGROUND_ACTIVITY}, APP_A_FOREGROUND_ACTIVITY);

        // We can't resume app switching after pressing home button, otherwise the grace period
        // will allow the starts.
        pressHomeAndWaitHomeResumed();

        result = waitForActivityFocused(APP_A_FOREGROUND_ACTIVITY);
        assertFalse("FG activity shouldn't be visible", result);
        result = waitForActivityFocused(APP_A_BACKGROUND_ACTIVITY);
        assertFalse("BG activity shouldn't be visible", result);
        assertTaskStack(new ComponentName[]{APP_A_FOREGROUND_ACTIVITY}, APP_A_FOREGROUND_ACTIVITY);
        assertTaskStack(null, APP_A_BACKGROUND_ACTIVITY);
    }

    @Test
    public void testActivityNotBlockedFromBgActivityInFgTask() {
        // Launch Activity A, B in the same task with different processes.
        final Intent intent = new Intent()
                .setComponent(APP_A_FOREGROUND_ACTIVITY)
                .addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        mContext.startActivity(intent);
        mWmState.waitForValidState(APP_A_FOREGROUND_ACTIVITY);
        mContext.sendBroadcast(getLaunchActivitiesBroadcast(APP_B_FOREGROUND_ACTIVITY));
        mWmState.waitForValidState(APP_B_FOREGROUND_ACTIVITY);
        assertTaskStack(new ComponentName[]{APP_B_FOREGROUND_ACTIVITY, APP_A_FOREGROUND_ACTIVITY},
                APP_A_FOREGROUND_ACTIVITY);

        // Refresh last-stop-app-switch-time by returning to home and then make the task foreground.
        pressHomeAndResumeAppSwitch();
        mContext.startActivity(intent);
        mWmState.waitForValidState(APP_B_FOREGROUND_ACTIVITY);
        // Though process A is in background, it is in a visible Task (top is B) so it should be
        // able to start activity successfully.
        mContext.sendBroadcast(new Intent(ACTION_LAUNCH_BACKGROUND_ACTIVITIES)
                .putExtra(LAUNCH_INTENTS_EXTRA, new Intent[]{ new Intent()
                        .setComponent(APP_A_BACKGROUND_ACTIVITY)
                        .addFlags(Intent.FLAG_ACTIVITY_NEW_TASK) }));
        mWmState.waitForValidState(APP_A_BACKGROUND_ACTIVITY);
        mWmState.assertFocusedActivity(
                "The background activity must be able to launch from a visible task",
                APP_A_BACKGROUND_ACTIVITY);
    }

    @Test
    @FlakyTest(bugId = 130800326)
    @Ignore  // TODO(b/145981637): Make this test work
    public void testActivityBlockedWhenForegroundActivityRestartsItself() throws Exception {
        // Start AppA foreground activity
        Intent intent = new Intent();
        intent.setComponent(APP_A_FOREGROUND_ACTIVITY);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        intent.putExtra(RELAUNCH_FOREGROUND_ACTIVITY_EXTRA, true);
        mContext.startActivity(intent);
        boolean result = waitForActivityFocused(APP_A_FOREGROUND_ACTIVITY);
        assertTrue("Not able to start foreground activity", result);
        assertTaskStack(new ComponentName[]{APP_A_FOREGROUND_ACTIVITY}, APP_A_FOREGROUND_ACTIVITY);

        // The foreground activity will be paused but will attempt to restart itself in onPause()
        pressHomeAndResumeAppSwitch();

        result = waitForActivityFocused(APP_A_FOREGROUND_ACTIVITY);
        assertFalse("Previously foreground Activity should not be able to relaunch itself", result);
        assertTaskStack(new ComponentName[]{APP_A_FOREGROUND_ACTIVITY}, APP_A_FOREGROUND_ACTIVITY);
    }

    @Test
    public void testSecondActivityNotBlockedWhenForegroundActivityLaunch() throws Exception {
        // Start AppA foreground activity, which will immediately launch one activity
        // and then the second.
        Intent intent = new Intent();
        intent.setComponent(APP_A_FOREGROUND_ACTIVITY);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        intent.putExtra(LAUNCH_BACKGROUND_ACTIVITY_EXTRA, true);
        intent.putExtra(LAUNCH_SECOND_BACKGROUND_ACTIVITY_EXTRA, true);
        mContext.startActivity(intent);

        boolean result = waitForActivityFocused(APP_A_SECOND_BACKGROUND_ACTIVITY);
        assertTrue("Not able to launch second background activity", result);

        waitAndAssertActivityState(APP_A_BACKGROUND_ACTIVITY, STATE_INITIALIZING,
                "First activity should have been created");
        assertTaskStack(
                new ComponentName[]{APP_A_SECOND_BACKGROUND_ACTIVITY, APP_A_BACKGROUND_ACTIVITY,
                        APP_A_FOREGROUND_ACTIVITY}, APP_A_FOREGROUND_ACTIVITY);
    }

    @Test
    @FlakyTest(bugId = 143522449)
    public void testSecondActivityBlockedWhenBackgroundActivityLaunch() throws Exception {
        Intent baseActivityIntent = new Intent();
        baseActivityIntent.setComponent(APP_A_FOREGROUND_ACTIVITY);
        baseActivityIntent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        mContext.startActivity(baseActivityIntent);
        boolean result = waitForActivityFocused(APP_A_FOREGROUND_ACTIVITY);
        assertTrue("Not able to start foreground activity", result);
        assertTaskStack(new ComponentName[]{APP_A_FOREGROUND_ACTIVITY}, APP_A_FOREGROUND_ACTIVITY);
        // We can't resume app switching after pressing home button, otherwise the grace period
        // will allow the starts.
        pressHomeAndWaitHomeResumed();

        // The activity, now in the background, will attempt to start 2 activities in quick
        // succession
        mContext.sendBroadcast(getLaunchActivitiesBroadcast(APP_A_BACKGROUND_ACTIVITY,
                APP_A_SECOND_BACKGROUND_ACTIVITY));

        // There should be 2 activities in the background (not focused) INITIALIZING
        result = waitForActivityFocused(APP_A_BACKGROUND_ACTIVITY);
        assertFalse("Activity should not have been launched in the foreground", result);
        result = waitForActivityFocused(APP_A_SECOND_BACKGROUND_ACTIVITY);
        assertFalse("Second activity should not have been launched in the foreground", result);
        assertTaskStack(
                new ComponentName[]{APP_A_SECOND_BACKGROUND_ACTIVITY, APP_A_BACKGROUND_ACTIVITY,
                        APP_A_FOREGROUND_ACTIVITY}, APP_A_FOREGROUND_ACTIVITY);
    }

    @Test
    public void testPendingIntentActivityBlocked() throws Exception {
        // Cannot start activity by pending intent, as both appA and appB are in background
        sendPendingIntentActivity();
        boolean result = waitForActivityFocused(APP_A_BACKGROUND_ACTIVITY);
        assertFalse("Should not able to launch background activity", result);
        assertTaskStack(null, APP_A_BACKGROUND_ACTIVITY);
    }

    @Test
    @FlakyTest(bugId = 130800326)
    public void testPendingIntentActivityNotBlocked_appAIsForeground() throws Exception {
        // Start AppA foreground activity
        Intent intent = new Intent();
        intent.setComponent(APP_A_FOREGROUND_ACTIVITY);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        mContext.startActivity(intent);
        boolean result = waitForActivityFocused(APP_A_FOREGROUND_ACTIVITY);
        assertTrue("Not able to start foreground Activity", result);
        assertTaskStack(new ComponentName[]{APP_A_FOREGROUND_ACTIVITY}, APP_A_FOREGROUND_ACTIVITY);

        // Send pendingIntent from AppA to AppB, and the AppB launch the pending intent to start
        // activity in App A
        sendPendingIntentActivity();
        result = waitForActivityFocused(APP_A_BACKGROUND_ACTIVITY);
        assertTrue("Not able to launch background activity", result);
        assertTaskStack(new ComponentName[]{APP_A_FOREGROUND_ACTIVITY}, APP_A_FOREGROUND_ACTIVITY);
        assertTaskStack(new ComponentName[]{APP_A_BACKGROUND_ACTIVITY}, APP_A_BACKGROUND_ACTIVITY);
    }

    @Test
    public void testPendingIntentBroadcastActivityNotBlocked_appBIsForeground() throws Exception {
        // Start AppB foreground activity
        Intent intent = new Intent();
        intent.setComponent(APP_B_FOREGROUND_ACTIVITY);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        mContext.startActivity(intent);
        boolean result = waitForActivityFocused(APP_B_FOREGROUND_ACTIVITY);
        assertTrue("Not able to start foreground Activity", result);
        assertTaskStack(new ComponentName[]{APP_B_FOREGROUND_ACTIVITY}, APP_B_FOREGROUND_ACTIVITY);

        // Send pendingIntent from AppA to AppB, and the AppB launch the pending intent to start
        // activity in App A
        sendPendingIntentActivity();
        result = waitForActivityFocused(APP_A_BACKGROUND_ACTIVITY);
        assertTrue("Not able to launch background activity", result);
        assertTaskStack(new ComponentName[]{APP_A_BACKGROUND_ACTIVITY}, APP_A_BACKGROUND_ACTIVITY);
        assertTaskStack(new ComponentName[]{APP_B_FOREGROUND_ACTIVITY}, APP_B_FOREGROUND_ACTIVITY);
    }

    @Test
    public void testPendingIntentBroadcastTimeout_noDelay() throws Exception {
        assertPendingIntentBroadcastTimeoutTest(0, true);
    }

    @Test
    @FlakyTest(bugId = 141344170)
    public void testPendingIntentBroadcastTimeout_delay1s() throws Exception {
        assertPendingIntentBroadcastTimeoutTest(1000, true);
    }

    @Test
    public void testPendingIntentBroadcastTimeout_delay12s() throws Exception {
        assertPendingIntentBroadcastTimeoutTest(12000, false);
    }

    @Test
    public void testPendingIntentBroadcast_appBIsBackground() throws Exception {
        EventReceiver receiver = new EventReceiver(
                Event.APP_A_START_BACKGROUND_ACTIVITY_BROADCAST_RECEIVED);

        // Send pendingIntent from AppA to AppB, and the AppB launch the pending intent to start
        // activity in App A
        sendPendingIntentBroadcast(0, receiver.getNotifier());

        // Waits for final hoop in AppA to start looking for activity, otherwise it could succeed
        // if the broadcast took long time to get executed (which may happen after boot).
        receiver.waitForEventOrThrow(BROADCAST_DELIVERY_TIMEOUT_MS);
        boolean result = waitForActivityFocused(APP_A_BACKGROUND_ACTIVITY);
        assertFalse("Should not able to launch background activity", result);
        assertTaskStack(null, APP_A_BACKGROUND_ACTIVITY);
    }

    /**
     * Returns a list of alive users on the device
     */
    private List<UserInfo> getAliveUsers() {
        // Setting the CREATE_USERS permission in AndroidManifest.xml has no effect when the test
        // is run through the CTS harness, so instead adopt it as a shell permission. We use
        // the CREATE_USERS permission instead of MANAGE_USERS because the shell can never use
        // MANAGE_USERS.
        UiAutomation uiAutomation = InstrumentationRegistry.getInstrumentation().getUiAutomation();
        uiAutomation.adoptShellPermissionIdentity(Manifest.permission.CREATE_USERS);
        List<UserInfo> userList = mContext.getSystemService(UserManager.class)
                .getUsers(/* excludePartial= */ true,
                        /* excludeDying= */ true,
                        /* excludePreCreated= */ true);
        uiAutomation.dropShellPermissionIdentity();
        return userList;
    }

    /**
     * Removes the guest user from the device if present
     */
    private void removeGuestUser() {
        List<UserInfo> userList = getAliveUsers();
        for (UserInfo info : userList) {
            if (info.isGuest()) {
                removeUser(info.id);
                // Device is only allowed to have one alive guest user, so stop if it's found
                break;
            }
        }
    }

    /**
     * Removes a user from the device given their ID
     */
    private void removeUser(int userId) {
        executeShellCommand(String.format("pm remove-user %d", userId));
    }

    @Test
    @SystemUserOnly(reason = "Device owner must be SYSTEM user")
    public void testDeviceOwner() throws Exception {
        // Send pendingIntent from AppA to AppB, and the AppB launch the pending intent to start
        // activity in App A
        if (!mContext.getPackageManager().hasSystemFeature(PackageManager.FEATURE_DEVICE_ADMIN)) {
            return;
        }

        // Remove existing guest user. The device may already have a guest present if it is
        // configured with config_guestUserAutoCreated.
        //
        // In production flow the DO can only be created before device provisioning finishes
        // (e.g. during SUW), and we make sure the guest user in only created after the device
        // provision is finished. Ideally this test would use the provisioning flow and Device
        // Owner (DO) creation in a similar manner as that of production flow.
        removeGuestUser();

        String cmdResult = runShellCommand("dpm set-device-owner --user 0 "
                + APP_A_SIMPLE_ADMIN_RECEIVER.flattenToString());
        assertThat(cmdResult).contains("Success");
        EventReceiver receiver = new EventReceiver(
                Event.APP_A_START_BACKGROUND_ACTIVITY_BROADCAST_RECEIVED);
        Intent intent = new Intent();
        intent.setComponent(APP_A_START_ACTIVITY_RECEIVER);
        intent.putExtra(EVENT_NOTIFIER_EXTRA, receiver.getNotifier());

        mContext.sendBroadcast(intent);

        // Waits for final hoop in AppA to start looking for activity
        receiver.waitForEventOrThrow(BROADCAST_DELIVERY_TIMEOUT_MS);
        boolean result = waitForActivityFocused(APP_A_BACKGROUND_ACTIVITY);
        assertTrue("Not able to launch background activity", result);
        assertTaskStack(new ComponentName[]{APP_A_BACKGROUND_ACTIVITY}, APP_A_BACKGROUND_ACTIVITY);
    }

    @Test
    public void testAppCannotStartBgActivityAfterHomeButton() throws Exception {

        Intent intent = new Intent();
        intent.setComponent(APP_A_RELAUNCHING_ACTIVITY);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        mContext.startActivity(intent);

        assertTrue("Main activity not started", waitUntilForegroundChanged(
                TEST_PACKAGE_APP_A, true, ACTIVITY_START_TIMEOUT_MS));

        // Click home button, and test app activity onPause() will try to start a background
        // activity, but we expect this will be blocked BAL logic in system, as app cannot start
        // any background activity even within grace period after pressing home button.
        pressHomeAndWaitHomeResumed();

        assertActivityNotResumed();
    }

    // Check picture-in-picture(PIP) won't allow to start BAL after pressing home.
    @Test
    public void testPipCannotStartAfterHomeButton() throws Exception {

        Intent intent = new Intent();
        intent.setComponent(APP_A_PIP_ACTIVITY);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        mContext.startActivity(intent);

        assertTrue("Pip activity not started", waitUntilForegroundChanged(
                TEST_PACKAGE_APP_A, true, ACTIVITY_START_TIMEOUT_MS));

        // Click home button, and test app activity onPause() will trigger pip window,
        // test will will try to start background activity, but we expect the background activity
        // will be blocked even the app has a visible pip window, as we do not allow background
        // activity to be started after pressing home button.
        pressHomeAndWaitHomeResumed();

        assertActivityNotResumed();
    }

    // Check that a presentation on a virtual display won't allow BAL after pressing home.
    @Test
    public void testVirtualDisplayCannotStartAfterHomeButton() throws Exception {
        Intent intent = new Intent();
        intent.setComponent(APP_A_VIRTUAL_DISPLAY_ACTIVITY);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        mContext.startActivity(intent);

        assertTrue("VirtualDisplay activity not started", waitUntilForegroundChanged(
                TEST_PACKAGE_APP_A, true, ACTIVITY_START_TIMEOUT_MS));

        // Click home button, and test app activity onPause() will trigger which tries to launch
        // the background activity.
        pressHomeAndWaitHomeResumed();

        assertActivityNotResumed();
    }

    private void pressHomeAndWaitHomeResumed() {
        pressHomeButton();
        mWmState.waitForHomeActivityVisible();
    }

    private boolean checkPackageResumed(String pkg) {
        WindowManagerStateHelper helper = new WindowManagerStateHelper();
        helper.computeState();
        return ComponentName.unflattenFromString(
                helper.getFocusedActivity()).getPackageName().equals(pkg);
    }

    // Return true if the state of the package is changed to target state.
    private boolean waitUntilForegroundChanged(String targetPkg, boolean toBeResumed, int timeout)
            throws Exception {
        long startTime = System.currentTimeMillis();
        while (checkPackageResumed(targetPkg) != toBeResumed) {
            if (System.currentTimeMillis() - startTime < timeout) {
                Thread.sleep(100);
            } else {
                return false;
            }
        }
        return true;
    }

    private void assertActivityNotResumed() throws Exception {
        assertFalse("Test activity is resumed",
                waitUntilForegroundChanged(TEST_PACKAGE_APP_A, true,
                        ACTIVITY_NOT_RESUMED_TIMEOUT_MS));
    }

    private Intent getLaunchActivitiesBroadcast(ComponentName... componentNames) {
        Intent broadcastIntent = new Intent(ACTION_LAUNCH_BACKGROUND_ACTIVITIES);
        Intent[] intents = Stream.of(componentNames)
                .map(c -> {
                    Intent intent = new Intent();
                    intent.setComponent(c);
                    return intent;
                })
                .toArray(Intent[]::new);
        broadcastIntent.putExtra(LAUNCH_INTENTS_EXTRA, intents);
        return broadcastIntent;
    }

    private void pressHomeAndResumeAppSwitch() {
        // Press home key to ensure stopAppSwitches is called because the last-stop-app-switch-time
        // is a criteria of allowing background start.
        pressHomeButton();
        // Resume the stopped state (it won't affect last-stop-app-switch-time) so we don't need to
        // wait extra time to prevent the next launch from being delayed.
        resumeAppSwitches();
        mWmState.waitForHomeActivityVisible();
        // Resuming app switches again after home became visible because the previous call might
        // have raced with pressHomeButton().
        // TODO(b/155454710): Remove previous call after making sure all the tests don't depend on
        // the timing here.
        resumeAppSwitches();
    }

    private void assertTaskStack(ComponentName[] expectedComponents,
            ComponentName sourceComponent) {
        if (expectedComponents == null) {
            assertNull(mWmState.getTaskByActivity(sourceComponent));
            return;
        }
        List<WindowManagerState.Activity> actual = mWmState.getTaskByActivity(
                sourceComponent).mActivities;
        assertEquals(expectedComponents.length, actual.size());
        int size = expectedComponents.length;
        for (int i = 0; i < size; i++) {
            assertEquals(expectedComponents[i].flattenToShortString(), actual.get(i).getName());
        }
    }

    private void assertPendingIntentBroadcastTimeoutTest(int delayMs, boolean expectedResult)
            throws TimeoutException {
        // Start AppB foreground activity
        Intent intent = new Intent();
        intent.setComponent(APP_B_FOREGROUND_ACTIVITY);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        mContext.startActivity(intent);
        boolean result = waitForActivityFocused(APP_B_FOREGROUND_ACTIVITY);
        assertTrue("Not able to start foreground Activity", result);
        assertTaskStack(new ComponentName[]{APP_B_FOREGROUND_ACTIVITY}, APP_B_FOREGROUND_ACTIVITY);
        EventReceiver receiver = new EventReceiver(
                Event.APP_A_START_BACKGROUND_ACTIVITY_BROADCAST_RECEIVED);

        // Send pendingIntent from AppA to AppB, and the AppB launch the pending intent to start
        // activity in App A
        sendPendingIntentBroadcast(delayMs, receiver.getNotifier());

        // Waits for final hoop in AppA to start looking for activity
        receiver.waitForEventOrThrow(BROADCAST_DELIVERY_TIMEOUT_MS);
        result = waitForActivityFocused(ACTIVITY_FOCUS_TIMEOUT_MS + delayMs,
                APP_A_BACKGROUND_ACTIVITY);
        assertEquals(expectedResult, result);
        if (expectedResult) {
            assertTaskStack(new ComponentName[]{APP_A_BACKGROUND_ACTIVITY},
                    APP_A_BACKGROUND_ACTIVITY);
        } else {
            assertTaskStack(null, APP_A_BACKGROUND_ACTIVITY);
        }
    }

    private boolean waitForActivityFocused(ComponentName componentName) {
        return waitForActivityFocused(ACTIVITY_FOCUS_TIMEOUT_MS, componentName);
    }

    private void sendPendingIntentActivity() {
        Intent intent = new Intent();
        intent.setComponent(APP_A_SEND_PENDING_INTENT_RECEIVER);
        intent.putExtra(IS_BROADCAST_EXTRA, false);
        mContext.sendBroadcast(intent);
    }

    private void sendPendingIntentBroadcast(int delayMs, @Nullable ResultReceiver eventNotifier) {
        Intent intent = new Intent();
        intent.setComponent(APP_A_SEND_PENDING_INTENT_RECEIVER);
        intent.putExtra(IS_BROADCAST_EXTRA, true);
        if (delayMs > 0) {
            intent.putExtra(START_ACTIVITY_DELAY_MS_EXTRA, delayMs);
        }
        intent.putExtra(EVENT_NOTIFIER_EXTRA, eventNotifier);
        mContext.sendBroadcast(intent);
    }
}
