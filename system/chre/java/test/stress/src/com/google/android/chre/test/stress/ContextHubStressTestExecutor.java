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
package com.google.android.chre.test.stress;

import android.app.Instrumentation;
import android.content.Context;
import android.hardware.location.ContextHubClient;
import android.hardware.location.ContextHubClientCallback;
import android.hardware.location.ContextHubInfo;
import android.hardware.location.ContextHubManager;
import android.hardware.location.ContextHubTransaction;
import android.hardware.location.NanoAppBinary;
import android.hardware.location.NanoAppMessage;
import android.net.wifi.WifiManager;
import android.util.Log;

import androidx.test.InstrumentationRegistry;

import com.google.android.chre.nanoapp.proto.ChreStressTest;
import com.google.android.chre.nanoapp.proto.ChreTestCommon;
import com.google.android.utils.chre.ChreTestUtil;
import com.google.protobuf.InvalidProtocolBufferException;

import org.junit.Assert;

import java.nio.charset.StandardCharsets;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicReference;

/**
 * A class that can execute the CHRE Stress test.
 */
public class ContextHubStressTestExecutor extends ContextHubClientCallback {
    private static final String TAG = "ContextHubStressTestExecutor";

    private final NanoAppBinary mNanoAppBinary;

    private final long mNanoAppId;

    private ContextHubClient mContextHubClient;

    private final AtomicReference<ChreTestCommon.TestResult> mTestResult =
            new AtomicReference<>();

    private final AtomicBoolean mChreReset = new AtomicBoolean(false);

    private final ContextHubManager mContextHubManager;

    private final ContextHubInfo mContextHubInfo;

    private CountDownLatch mCountDownLatch;

    // Set to true to have the test suite only load the nanoapp and start the test.
    // This can be useful for long-running stress tests, where we do not want to wait a fixed
    // time to wait for successful completion.
    private boolean mLoadAndStartOnly = false;

    private final AtomicBoolean mWifiScanMonitorTriggered = new AtomicBoolean(false);

    private final Instrumentation mInstrumentation = InstrumentationRegistry.getInstrumentation();

    public ContextHubStressTestExecutor(ContextHubManager manager, ContextHubInfo info,
            NanoAppBinary binary) {
        mNanoAppBinary = binary;
        mNanoAppId = mNanoAppBinary.getNanoAppId();
        mContextHubManager = manager;
        mContextHubInfo = info;
    }

    @Override
    public void onMessageFromNanoApp(ContextHubClient client, NanoAppMessage message) {
        if (message.getNanoAppId() == mNanoAppId) {
            Log.d(TAG, "Got message from nanoapp: " + message);
            boolean valid = false;
            switch (message.getMessageType()) {
                case ChreStressTest.MessageType.TEST_RESULT_VALUE: {
                    try {
                        mTestResult.set(
                                ChreTestCommon.TestResult.parseFrom(message.getMessageBody()));
                        valid = true;
                    } catch (InvalidProtocolBufferException e) {
                        Log.e(TAG, "Failed to parse message: " + e.getMessage());
                    }
                    break;
                }
                case ChreStressTest.MessageType.TEST_WIFI_SCAN_MONITOR_TRIGGERED_VALUE: {
                    mWifiScanMonitorTriggered.set(true);
                    valid = true;
                    break;
                }
                default: {
                    Log.e(TAG, "Unknown message type " + message.getMessageType());
                }
            }

            if (valid && mCountDownLatch != null) {
                mCountDownLatch.countDown();
            }
        }
    }

    @Override
    public void onHubReset(ContextHubClient client) {
        mChreReset.set(true);
        if (mCountDownLatch != null) {
            mCountDownLatch.countDown();
        }
    }

    /**
     * Should be invoked before run() is invoked to set up the test, e.g. in a @Before method.
     */
    public void init() {
        init(false /* loadAndStartOnly */, false /* unloadOnly */);
    }

    /**
     * Same version of init, but specifies mLoadAndStartOnly.
     *
     * @param loadAndStartOnly Sets mLoadAndStartOnly.
     */
    public void init(boolean loadAndStartOnly) {
        init(loadAndStartOnly, false /* unloadOnly */);
    }

    /**
     * Same version of init, but specifies mLoadAndStartOnly and unloadOnly.
     *
     * @param loadAndStartOnly Sets mLoadAndStartOnly.
     * @param unloadOnly       Set to true if the nanoapp is already loaded.
     */
    public void init(boolean loadAndStartOnly, boolean unloadOnly) {
        mLoadAndStartOnly = loadAndStartOnly;
        if (!unloadOnly) {
            ChreTestUtil.loadNanoAppAssertSuccess(mContextHubManager, mContextHubInfo,
                    mNanoAppBinary);
        }
        mContextHubClient = mContextHubManager.createClient(mContextHubInfo, this);
        Assert.assertTrue(mContextHubClient != null);
    }

    /**
     * @param timeout The amount of time to run the stress test.
     * @param unit    The unit for timeout.
     */
    public void runStressTest(long timeout, TimeUnit unit) {
        ChreStressTest.TestCommand.Feature[] features = {
                ChreStressTest.TestCommand.Feature.WIFI_ON_DEMAND_SCAN,
                ChreStressTest.TestCommand.Feature.GNSS_LOCATION,
                ChreStressTest.TestCommand.Feature.GNSS_MEASUREMENT,
                ChreStressTest.TestCommand.Feature.WWAN,
        };

        mTestResult.set(null);
        mCountDownLatch = new CountDownLatch(1);

        for (ChreStressTest.TestCommand.Feature feature : features) {
            sendTestMessage(feature, true /* start */);
        }

        if (!mLoadAndStartOnly) {
            try {
                mCountDownLatch.await(timeout, unit);
            } catch (InterruptedException e) {
                Assert.fail(e.getMessage());
            }

            checkTestFailure();

            for (ChreStressTest.TestCommand.Feature feature : features) {
                sendTestMessage(feature, false /* start */);
            }

            try {
                // Add a short delay to make sure the stop command did not cause issues.
                Thread.sleep(10000);
            } catch (InterruptedException e) {
                Assert.fail(e.getMessage());
            }
        }
    }

    /**
     * Sends a command to enable scan monitoring.
     */
    public void sendScanMonitorCommand() {
        sendTestMessage(ChreStressTest.TestCommand.Feature.WIFI_SCAN_MONITOR, true /* start */);
    }

    /**
     * A test to verify whether a scan monitor request persists through WLAN restarts.
     *
     * The test framework is expected to perform the following operations prior to running this
     * method.
     * 1. Load the nanoapp through init() (with loadAndStartOnly enabled)
     * 2. Invoke sendScanMonitorCommand
     * 3. Restart the WLAN.
     * 4. Keep the nanoapp loaded, and then run this test.
     * 5. Unload the nanoapp after this test ends.
     */
    public void runWifiScanMonitorRestartTest() {
        // Since the host connection may have reset, inform the nanoapp about this event.
        NanoAppMessage message = NanoAppMessage.createMessageToNanoApp(
                mNanoAppId, ChreStressTest.MessageType.TEST_HOST_RESTARTED_VALUE,
                new byte[0]);
        sendMessageToNanoApp(message);

        WifiManager manager = (WifiManager) mInstrumentation.getContext().getSystemService(
                Context.WIFI_SERVICE);
        Assert.assertNotNull(manager);

        mWifiScanMonitorTriggered.set(false);
        mCountDownLatch = new CountDownLatch(1);
        manager.startScan();

        try {
            mCountDownLatch.await(30, TimeUnit.SECONDS);
        } catch (InterruptedException e) {
            Assert.fail(e.getMessage());
        }
        Assert.assertTrue(mWifiScanMonitorTriggered.get());
        checkTestFailure();

        sendTestMessage(ChreStressTest.TestCommand.Feature.WIFI_SCAN_MONITOR, false /* start */);
    }

    /**
     * Cleans up the test, should be invoked in e.g. @After method.
     */
    public void deinit() {
        if (!mLoadAndStartOnly) {
            ChreTestUtil.unloadNanoApp(mContextHubManager, mContextHubInfo, mNanoAppId);
        }
        if (mContextHubClient != null) {
            mContextHubClient.close();
        }

        if (mChreReset.get()) {
            Assert.fail("CHRE reset during the test");
        }
    }

    /**
     * @param feature The feature to start testing for.
     * @param start   true to start the test, false to stop.
     */
    private void sendTestMessage(ChreStressTest.TestCommand.Feature feature, boolean start) {
        ChreStressTest.TestCommand testCommand = ChreStressTest.TestCommand.newBuilder()
                .setFeature(feature).setStart(start).build();

        NanoAppMessage message = NanoAppMessage.createMessageToNanoApp(
                mNanoAppId, ChreStressTest.MessageType.TEST_COMMAND_VALUE,
                testCommand.toByteArray());
        sendMessageToNanoApp(message);
    }

    private void sendMessageToNanoApp(NanoAppMessage message) {
        int result = mContextHubClient.sendMessageToNanoApp(message);
        if (result != ContextHubTransaction.RESULT_SUCCESS) {
            Assert.fail("Failed to send message: result = " + result);
        }
    }

    private void checkTestFailure() {
        if (mTestResult.get() != null
                && mTestResult.get().getCode() == ChreTestCommon.TestResult.Code.FAILED) {
            if (mTestResult.get().hasErrorMessage()) {
                Assert.fail(new String(mTestResult.get().getErrorMessage().toByteArray(),
                        StandardCharsets.UTF_8));
            } else {
                Assert.fail("Stress test failed");
            }
        }
    }
}
