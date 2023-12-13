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

package android.jobscheduler.cts;

import android.app.job.JobInfo;
import android.app.job.JobParameters;
import android.content.ClipData;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.PersistableBundle;
import android.os.UserHandle;

import com.android.compatibility.common.util.BatteryUtils;
import com.android.compatibility.common.util.SystemUtil;

/**
 * Tests related to JobParameters objects.
 */
public class JobParametersTest extends BaseJobSchedulerTest {
    private static final int JOB_ID = JobParametersTest.class.hashCode();

    public void testClipData() throws Exception {
        final ClipData clipData = ClipData.newPlainText("test", "testText");
        final int grantFlags = Intent.FLAG_GRANT_READ_URI_PERMISSION;
        JobInfo ji = new JobInfo.Builder(JOB_ID, kJobServiceComponent)
                .setClipData(clipData, grantFlags)
                .build();

        kTestEnvironment.setExpectedExecutions(1);
        mJobScheduler.schedule(ji);
        runSatisfiedJob(JOB_ID);
        assertTrue("Job didn't fire immediately", kTestEnvironment.awaitExecution());

        JobParameters params = kTestEnvironment.getLastStartJobParameters();
        assertEquals(clipData.getItemCount(), params.getClipData().getItemCount());
        assertEquals(clipData.getItemAt(0).getText(), params.getClipData().getItemAt(0).getText());
        assertEquals(grantFlags, params.getClipGrantFlags());
    }

    public void testExtras() throws Exception {
        final PersistableBundle pb = new PersistableBundle();
        pb.putInt("random_key", 42);
        JobInfo ji = new JobInfo.Builder(JOB_ID, kJobServiceComponent)
                .setExtras(pb)
                .build();

        kTestEnvironment.setExpectedExecutions(1);
        mJobScheduler.schedule(ji);
        runSatisfiedJob(JOB_ID);
        assertTrue("Job didn't fire immediately", kTestEnvironment.awaitExecution());

        JobParameters params = kTestEnvironment.getLastStartJobParameters();
        final PersistableBundle extras = params.getExtras();
        assertNotNull(extras);
        assertEquals(1, extras.keySet().size());
        assertEquals(42, extras.getInt("random_key"));
    }

    public void testExpedited() throws Exception {
        JobInfo ji = new JobInfo.Builder(JOB_ID, kJobServiceComponent)
                .setExpedited(true)
                .build();

        kTestEnvironment.setExpectedExecutions(1);
        mJobScheduler.schedule(ji);
        runSatisfiedJob(JOB_ID);
        assertTrue("Job didn't fire immediately", kTestEnvironment.awaitExecution());

        JobParameters params = kTestEnvironment.getLastStartJobParameters();
        assertTrue(params.isExpeditedJob());

        ji = new JobInfo.Builder(JOB_ID, kJobServiceComponent)
                .setExpedited(false)
                .build();

        kTestEnvironment.setExpectedExecutions(1);
        mJobScheduler.schedule(ji);
        runSatisfiedJob(JOB_ID);
        assertTrue("Job didn't fire immediately", kTestEnvironment.awaitExecution());

        params = kTestEnvironment.getLastStartJobParameters();
        assertFalse(params.isExpeditedJob());
    }

    public void testJobId() throws Exception {
        JobInfo ji = new JobInfo.Builder(JOB_ID, kJobServiceComponent)
                .build();

        kTestEnvironment.setExpectedExecutions(1);
        mJobScheduler.schedule(ji);
        runSatisfiedJob(JOB_ID);
        assertTrue("Job didn't fire immediately", kTestEnvironment.awaitExecution());

        JobParameters params = kTestEnvironment.getLastStartJobParameters();
        assertEquals(JOB_ID, params.getJobId());
    }

    // JobParameters.getNetwork() tested in ConnectivityConstraintTest.

    public void testStopReason() throws Exception {
        verifyStopReason(new JobInfo.Builder(JOB_ID, kJobServiceComponent).build(),
                JobParameters.STOP_REASON_TIMEOUT,
                () -> SystemUtil.runShellCommand(getInstrumentation(),
                        "cmd jobscheduler timeout"
                                + " -u " + UserHandle.myUserId()
                                + " " + kJobServiceComponent.getPackageName()
                                + " " + JOB_ID));

        // In automotive device, always-on screen and endless battery charging are assumed.
        if (BatteryUtils.hasBattery() && !isAutomotiveDevice()) {
            BatteryUtils.runDumpsysBatterySetLevel(100);
            BatteryUtils.runDumpsysBatteryUnplug();
            verifyStopReason(new JobInfo.Builder(JOB_ID, kJobServiceComponent)
                            .setRequiresBatteryNotLow(true).build(),
                    JobParameters.STOP_REASON_CONSTRAINT_BATTERY_NOT_LOW,
                    () -> BatteryUtils.runDumpsysBatterySetLevel(5));

            BatteryUtils.runDumpsysBatterySetPluggedIn(true);
            BatteryUtils.runDumpsysBatterySetLevel(100);
            verifyStopReason(new JobInfo.Builder(JOB_ID, kJobServiceComponent)
                            .setRequiresCharging(true).build(),
                    JobParameters.STOP_REASON_CONSTRAINT_CHARGING,
                    BatteryUtils::runDumpsysBatteryUnplug);
        }

        setStorageStateLow(false);
        verifyStopReason(new JobInfo.Builder(JOB_ID, kJobServiceComponent)
                        .setRequiresStorageNotLow(true).build(),
                JobParameters.STOP_REASON_CONSTRAINT_STORAGE_NOT_LOW,
                () -> setStorageStateLow(true));
    }

    private void verifyStopReason(JobInfo ji, int stopReason, ExceptionRunnable stopCode)
            throws Exception {
        kTestEnvironment.setExpectedExecutions(1);
        kTestEnvironment.setContinueAfterStart();
        kTestEnvironment.setExpectedStopped();
        mJobScheduler.schedule(ji);
        runSatisfiedJob(ji.getId());
        assertTrue("Job didn't fire immediately", kTestEnvironment.awaitExecution());

        JobParameters params = kTestEnvironment.getLastStartJobParameters();
        assertEquals(JobParameters.STOP_REASON_UNDEFINED, params.getStopReason());

        stopCode.run();
        assertTrue("Job didn't stop immediately", kTestEnvironment.awaitStopped());
        params = kTestEnvironment.getLastStopJobParameters();
        assertEquals(stopReason, params.getStopReason());
    }

    public void testTransientExtras() throws Exception {
        final Bundle b = new Bundle();
        b.putBoolean("random_bool", true);
        JobInfo ji = new JobInfo.Builder(JOB_ID, kJobServiceComponent)
                .setTransientExtras(b)
                .build();

        kTestEnvironment.setExpectedExecutions(1);
        mJobScheduler.schedule(ji);
        runSatisfiedJob(JOB_ID);
        assertTrue("Job didn't fire immediately", kTestEnvironment.awaitExecution());

        JobParameters params = kTestEnvironment.getLastStartJobParameters();
        assertEquals(b.size(), params.getTransientExtras().size());
        for (String key : b.keySet()) {
            assertEquals(b.get(key), params.getTransientExtras().get(key));
        }
    }

    // JobParameters.getTriggeredContentAuthorities() tested in TriggerContentTest.
    // JobParameters.getTriggeredContentUris() tested in TriggerContentTest.
    // JobParameters.isOverrideDeadlineExpired() tested in TimingConstraintTest.

    private boolean isAutomotiveDevice() {
        return getContext().getPackageManager().hasSystemFeature(PackageManager.FEATURE_AUTOMOTIVE);
    }

    private interface ExceptionRunnable {
        void run() throws Exception;
    }
}
