/*
 * Copyright (C) 2015 The Android Open Source Project
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

package com.android.cts.devicepolicy;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import android.platform.test.annotations.FlakyTest;

import org.junit.Test;

/**
 * This class is used for tests that need to do something special before setting the device
 * owner, so they cannot use the regular DeviceOwnerTest class
 */
public class CustomDeviceOwnerTest extends BaseDevicePolicyTest {

    private static final String DEVICE_OWNER_PKG = "com.android.cts.deviceowner";
    private static final String DEVICE_OWNER_APK = "CtsDeviceOwnerApp.apk";
    private static final String DEVICE_OWNER_ADMIN
            = DEVICE_OWNER_PKG + ".BasicAdminReceiver";
    private static final String DEVICE_OWNER_ADMIN_COMPONENT
            = DEVICE_OWNER_PKG + "/" + DEVICE_OWNER_ADMIN;

    private static final String INTENT_RECEIVER_PKG = "com.android.cts.intent.receiver";
    private static final String INTENT_RECEIVER_APK = "CtsIntentReceiverApp.apk";

    @Override
    public void tearDown() throws Exception {
        getDevice().uninstallPackage(DEVICE_OWNER_PKG);

        super.tearDown();
    }

    @Test
    public void testOwnerChangedBroadcast() throws Exception {
        installAppAsUser(DEVICE_OWNER_APK, mDeviceOwnerUserId);
        try {
            installAppAsUser(INTENT_RECEIVER_APK, mDeviceOwnerUserId);

            String testClass = INTENT_RECEIVER_PKG + ".OwnerChangedBroadcastTest";

            // Running this test also gets the intent receiver app out of the stopped state, so it
            // can receive broadcast intents.
            runDeviceTestsAsUser(INTENT_RECEIVER_PKG, testClass,
                    "testOwnerChangedBroadcastNotReceived", mDeviceOwnerUserId);

            // Setting the device owner should send the owner changed broadcast.
            assertTrue(setDeviceOwner(DEVICE_OWNER_ADMIN_COMPONENT, mDeviceOwnerUserId,
                    /*expectFailure*/ false));

            // Wait broadcast idle to ensure the owner changed broadcast has been sent.
            waitForBroadcastIdle();

            runDeviceTestsAsUser(INTENT_RECEIVER_PKG, testClass,
                    "testOwnerChangedBroadcastReceived", mDeviceOwnerUserId);
        } finally {
            getDevice().uninstallPackage(INTENT_RECEIVER_PKG);
            assertTrue("Failed to remove device owner.",
                    removeAdmin(DEVICE_OWNER_ADMIN_COMPONENT, mDeviceOwnerUserId));
        }
    }

    @Test
    public void testCannotSetDeviceOwnerWhenSecondaryUserPresent() throws Exception {
        assumeSupportsMultiUser();
        int userId = -1;
        installAppAsUser(DEVICE_OWNER_APK, mDeviceOwnerUserId);
        try {
            userId = createUser();
            assertFalse(setDeviceOwner(DEVICE_OWNER_ADMIN_COMPONENT, mDeviceOwnerUserId,
                    /*expectFailure*/ true));
        } finally {
            removeUser(userId);
            // make sure we clean up in case we succeeded in setting the device owner
            removeAdmin(DEVICE_OWNER_ADMIN_COMPONENT, mDeviceOwnerUserId);
        }
    }

    @Test
    public void testIsProvisioningAllowed() throws Exception {
        // Must install the apk since the test runs in the DO apk.
        installAppAsUser(DEVICE_OWNER_APK, mDeviceOwnerUserId);
        try {
            // When CTS runs, setupwizard is complete. Expects it has to return false as DO can
            // only be provisioned before setupwizard is completed.

            runDeviceTestsAsUser(DEVICE_OWNER_PKG, ".PreDeviceOwnerTest",
                    "testIsProvisioningAllowedFalse", mDeviceOwnerUserId);
        } finally {
            getDevice().uninstallPackage(DEVICE_OWNER_PKG);
        }
    }
}
