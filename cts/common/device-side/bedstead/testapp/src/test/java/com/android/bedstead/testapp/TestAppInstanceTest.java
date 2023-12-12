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

package com.android.bedstead.testapp;

import static android.app.admin.DevicePolicyManager.OPERATION_SAFETY_REASON_DRIVING_DISTRACTION;
import static android.os.Build.VERSION_CODES.Q;
import static android.os.Build.VERSION_CODES.S;

import static com.android.eventlib.truth.EventLogsSubject.assertThat;

import static com.google.common.truth.Truth.assertThat;

import static org.testng.Assert.assertThrows;

import android.app.admin.DevicePolicyManager;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;

import com.android.bedstead.harrier.BedsteadJUnit4;
import com.android.bedstead.harrier.DeviceState;
import com.android.bedstead.harrier.annotations.RequireSdkVersion;
import com.android.bedstead.nene.TestApis;
import com.android.bedstead.nene.users.UserReference;
import com.android.bedstead.nene.utils.Poll;
import com.android.eventlib.EventLogs;
import com.android.eventlib.events.broadcastreceivers.BroadcastReceivedEvent;

import org.junit.ClassRule;
import org.junit.Ignore;
import org.junit.Rule;
import org.junit.Test;
import org.junit.runner.RunWith;

import java.time.Duration;

@RunWith(BedsteadJUnit4.class)
public class TestAppInstanceTest {

    @ClassRule
    @Rule
    public static final DeviceState sDeviceState = new DeviceState();

    private static final Context sContext = TestApis.context().instrumentedContext();
    private static final UserReference sUser = TestApis.users().instrumented();

    private static final TestAppProvider sTestAppProvider = new TestAppProvider();
    private static final TestApp sTestApp = sTestAppProvider.query()
            .whereActivities().isNotEmpty()
            .get();

    private static final String INTENT_ACTION = "com.android.bedstead.testapp.test_action";
    private static final IntentFilter INTENT_FILTER = new IntentFilter(INTENT_ACTION);
    private static final Intent INTENT = new Intent(INTENT_ACTION);
    private static final String INTENT_ACTION_2 = "com.android.bedstead.testapp.test_action2";
    private static final IntentFilter INTENT_FILTER_2 = new IntentFilter(INTENT_ACTION_2);
    private static final Intent INTENT_2 = new Intent(INTENT_ACTION_2);
    private static final Duration SHORT_TIMEOUT = Duration.ofSeconds(5);
    private TestAppProvider mTestAppProvider;

    @Test
    public void user_returnsUserReference() {
        TestAppInstance testAppInstance = sTestApp.instance(sUser);

        assertThat(testAppInstance.user()).isEqualTo(sUser);
    }

    @Test
    public void testApp_returnsTestApp() {
        TestAppInstance testAppInstance = sTestApp.instance(sUser);

        assertThat(testAppInstance.testApp()).isEqualTo(sTestApp);
    }

    @Test
    public void activities_any_returnsActivity() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            assertThat(testAppInstance.activities().any()).isNotNull();
        }
    }

    @Test
    public void uninstall_uninstalls() {
        TestAppInstance testAppInstance = sTestApp.install();

        testAppInstance.uninstall();

        assertThat(TestApis.packages().find(sTestApp.packageName())
                .installedOnUser(sUser)).isFalse();
    }

    @Test
    public void autoclose_uninstalls() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            // Intentionally empty
        }

        assertThat(TestApis.packages().find(sTestApp.packageName())
                .installedOnUser(sUser)).isFalse();
    }

    @Test
    public void keepAlive_notInstalled_throwsException() {
        TestAppInstance testAppInstance = sTestApp.instance(sUser);

        assertThrows(IllegalStateException.class, testAppInstance::keepAlive);
    }

    @Test
    @Ignore("b/203758521 Need to re-add support for killing processes")
    public void killProcess_keepAlive_processIsRunningAgain() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            testAppInstance.keepAlive();

//            testAppInstance.process().kill();

            Poll.forValue("running process", () -> sTestApp.pkg().runningProcess(sUser))
                    .toNotBeNull()
                    .errorOnFail()
                    .await();
        }
    }

    // We cannot test that after stopKeepAlive it does not restart, as we'd have to wait an
    // unbounded amount of time

    @Test
    @Ignore("b/203758521 need to re-add support for killing processes")
    public void stop_processIsNotRunning() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            testAppInstance.activities().any().start();

//            testAppInstance.stop();

            assertThat(sTestApp.pkg().runningProcesses()).isEmpty();
        }
    }

    @Test
    @Ignore("b/203758521 need to re-add support for killing processes")
    public void stop_previouslyCalledKeepAlive_processDoesNotRestart() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            testAppInstance.activities().any().start();
            testAppInstance.keepAlive();

//            testAppInstance.stop();

            assertThat(sTestApp.pkg().runningProcesses()).isEmpty();
        }
    }

    @Test
    public void process_isNotRunning_returnsNull() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            assertThat(testAppInstance.process()).isNull();
        }
    }

    @Test
    public void process_isRunning_isNotNull() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            testAppInstance.activities().any().start();

            Poll.forValue("TestApp process", testAppInstance::process)
                    .toNotBeNull()
                    .errorOnFail()
                    .await();
        }
    }

    @Test
    public void registerReceiver_receivesBroadcast() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            testAppInstance.registerReceiver(INTENT_FILTER);

            sContext.sendBroadcast(INTENT);

            assertThat(testAppInstance.events().broadcastReceived()
                    .whereIntent().action().isEqualTo(INTENT_ACTION))
                    .eventOccurred();
        }
    }

    @Test
    public void registerReceiver_multipleIntentFilters_receivesAllMatchingBroadcasts() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            testAppInstance.registerReceiver(INTENT_FILTER);
            testAppInstance.registerReceiver(INTENT_FILTER_2);

            sContext.sendBroadcast(INTENT);
            sContext.sendBroadcast(INTENT_2);

            assertThat(testAppInstance.events().broadcastReceived()
                    .whereIntent().action().isEqualTo(INTENT_ACTION))
                    .eventOccurred();
            assertThat(testAppInstance.events().broadcastReceived()
                    .whereIntent().action().isEqualTo(INTENT_ACTION_2))
                    .eventOccurred();
        }
    }

    @Test
    public void registerReceiver_processIsRunning() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {

            testAppInstance.registerReceiver(INTENT_FILTER);

            assertThat(sTestApp.pkg().runningProcess(sUser)).isNotNull();
        }
    }

    @Test
    @Ignore("b/203758521 need to re-add support for killing processes")
    public void stop_registeredReceiver_doesNotReceiveBroadcast() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            testAppInstance.registerReceiver(INTENT_FILTER);

//            testAppInstance.stop();
            sContext.sendBroadcast(INTENT);

            EventLogs<BroadcastReceivedEvent> logs =
                    BroadcastReceivedEvent.queryPackage(sTestApp.packageName())
                            .whereIntent().action().isEqualTo(INTENT_ACTION);
            assertThat(logs.poll(SHORT_TIMEOUT)).isNull();
        }
    }

    @Test
    public void unregisterReceiver_registeredReceiver_doesNotReceiveBroadcast() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            testAppInstance.registerReceiver(INTENT_FILTER);

            testAppInstance.unregisterReceiver(INTENT_FILTER);
            sContext.sendBroadcast(INTENT);

            EventLogs<BroadcastReceivedEvent> logs =
                    BroadcastReceivedEvent.queryPackage(sTestApp.packageName())
                            .whereIntent().action().isEqualTo(INTENT_ACTION);
            assertThat(logs.poll(SHORT_TIMEOUT)).isNull();
        }
    }

    @Test
    public void unregisterReceiver_doesNotUnregisterOtherReceivers() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            testAppInstance.registerReceiver(INTENT_FILTER);
            testAppInstance.registerReceiver(INTENT_FILTER_2);

            testAppInstance.unregisterReceiver(INTENT_FILTER);
            sContext.sendBroadcast(INTENT);
            sContext.sendBroadcast(INTENT_2);

            EventLogs<BroadcastReceivedEvent> logs =
                    BroadcastReceivedEvent.queryPackage(sTestApp.packageName())
                            .whereIntent().action().isEqualTo(INTENT_ACTION);
            EventLogs<BroadcastReceivedEvent> logs2 =
                    BroadcastReceivedEvent.queryPackage(sTestApp.packageName())
                            .whereIntent().action().isEqualTo(INTENT_ACTION_2);
            assertThat(logs.poll(SHORT_TIMEOUT)).isNull();
            assertThat(logs2.poll()).isNotNull();
        }
    }

    @Test
    public void keepAlive_processIsRunning() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {

            testAppInstance.keepAlive();

            assertThat(sTestApp.pkg().runningProcess(sUser)).isNotNull();
        }
    }

    @Test
    @Ignore("b/203758521 need to re-add support for killing processes")
    public void registerReceiver_appIsKilled_stillReceivesBroadcast() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            testAppInstance.registerReceiver(INTENT_FILTER);
//            testApp.pkg().runningProcess(sUser).kill();
            Poll.forValue("running process", () -> sTestApp.pkg().runningProcess(sUser))
                    .toNotBeNull()
                    .errorOnFail()
                    .await();

            sContext.sendBroadcast(INTENT);

            EventLogs<BroadcastReceivedEvent> logs =
                    BroadcastReceivedEvent.queryPackage(sTestApp.packageName())
                            .whereIntent().action().isEqualTo(INTENT_ACTION);
            assertThat(logs.poll()).isNotNull();
        }
    }

    @Test
    @RequireSdkVersion(min = S, reason = "isSafeOperation only available on S+")
    public void devicePolicyManager_returnsUsableInstance() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            // Arbitrary call which does not require specific permissions to confirm no crash
            testAppInstance.devicePolicyManager()
                    .isSafeOperation(OPERATION_SAFETY_REASON_DRIVING_DISTRACTION);
        }
    }

    @Test
    public void userManager_returnsUsableInstance() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            // Arbitrary call which does not require specific permissions to confirm no crash
            testAppInstance.userManager().getUserProfiles();
        }
    }

    @Test
    @RequireSdkVersion(min = Q, reason = "Wifimanager API only available on Q+")
    public void wifiManager_returnsUsableInstance() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            // Arbitrary call which does not require specific permissions to confirm no crash
            testAppInstance.wifiManager().getMaxNumberOfNetworkSuggestionsPerApp();
        }
    }

    @Test
    public void hardwarePropertiesManager_returnsUsableInstance() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            // Arbitrary call - there are no methods on this service which don't require permissions
            assertThrows(SecurityException.class, () -> {
                testAppInstance.hardwarePropertiesManager().getCpuUsages();
            });
        }
    }

    @Test
    public void packageManager_returnsUsableInstance() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            assertThat(testAppInstance.packageManager().hasSystemFeature("")).isFalse();
        }
    }

    @Test
    public void crossProfileApps_returnsUsableInstance() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            assertThat(testAppInstance.crossProfileApps().getTargetUserProfiles()).isEmpty();
        }
    }

    @Test
    public void launcherApps_returnsUsableInstance() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            assertThat(testAppInstance.launcherApps().hasShortcutHostPermission()).isFalse();
        }
    }

    @Test
    public void accountManager_returnsUsableInstance() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            // Arbitrary call which does not require specific permissions to confirm no crash
            assertThat(testAppInstance.accountManager().getAccounts()).isNotNull();
        }
    }

    @Test
    public void context_returnsUsableInstance() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            assertThat(testAppInstance.context().getSystemServiceName(DevicePolicyManager.class))
                    .isEqualTo(Context.DEVICE_POLICY_SERVICE);
        }
    }

    @Test
    public void context_getContentResolver_returnsUsableInstance() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            // Arbitrary call which does not require specific permissions to confirm no crash
            assertThat(testAppInstance.context().getContentResolver().getPersistedUriPermissions())
                    .isNotNull();
        }
    }

    @Test
    public void keyChain_returnsUsableInstance() {
        try (TestAppInstance testAppInstance = sTestApp.install()) {
            assertThat(testAppInstance.keyChain().isKeyAlgorithmSupported("A")).isFalse();
        }
    }
}
