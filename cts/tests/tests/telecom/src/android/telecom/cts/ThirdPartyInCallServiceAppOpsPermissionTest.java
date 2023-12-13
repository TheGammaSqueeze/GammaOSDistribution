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

package android.telecom.cts;

import static android.telecom.cts.TestUtils.TEST_PHONE_ACCOUNT_HANDLE;
import static android.telecom.cts.TestUtils.WAIT_FOR_STATE_CHANGE_TIMEOUT_MS;

import static com.android.compatibility.common.util.ShellIdentityUtils
        .invokeMethodWithShellPermissionsNoReturn;
import static com.android.compatibility.common.util.SystemUtil.runWithShellPermissionIdentity;

import android.app.AppOpsManager;
import android.app.UiModeManager;
import android.app.role.RoleManager;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.os.IBinder;
import android.os.RemoteException;
import android.telecom.TelecomManager;
import android.telecom.cts.thirdptyincallservice.CtsThirdPartyInCallService;
import android.telecom.cts.thirdptyincallservice.CtsThirdPartyInCallServiceControl;
import android.telecom.cts.thirdptyincallservice.ICtsThirdPartyInCallServiceControl;
import android.text.TextUtils;
import android.util.Log;

import java.util.List;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;

public class ThirdPartyInCallServiceAppOpsPermissionTest extends BaseTelecomTestWithMockServices {

    private static final String TAG = ThirdPartyInCallServiceAppOpsPermissionTest
            .class.getSimpleName();
    private static final String THIRD_PARITY_PACKAGE_NAME = CtsThirdPartyInCallService
            .class.getPackage().getName();
    private static final Uri TEST_URI = Uri.parse("tel:555-TEST");
    private Context mContext;
    private AppOpsManager mAppOpsManager;
    private PackageManager mPackageManager;
    private TelecomManager mTelecomManager;
    ICtsThirdPartyInCallServiceControl mICtsThirdPartyInCallServiceControl;
    private boolean mExpectedTearDownBindingStatus;

    @Override
    public void setUp() throws Exception {
        super.setUp();
        if (!mShouldTestTelecom) {
            return;
        }
        mContext = getInstrumentation().getContext();
        mAppOpsManager = mContext.getSystemService(AppOpsManager.class);
        mPackageManager = mContext.getPackageManager();
        mTelecomManager = mContext.getSystemService(TelecomManager.class);
        setupConnectionService(null, FLAG_REGISTER | FLAG_ENABLE);
        setUpControl();
        mICtsThirdPartyInCallServiceControl.resetLatchForServiceBound(false);
        mExpectedTearDownBindingStatus = true;
    }

    @Override
    public void tearDown() throws Exception {
        if (!mShouldTestTelecom) {
            return;
        }
        mICtsThirdPartyInCallServiceControl.resetCalls();
        super.tearDown();
        if (mExpectedTearDownBindingStatus) {
            assertBindStatus(/* true: bind, false: unbind */false, /* expected result */true);
        }
    }

    public void testWithoutAppOpsPermission() throws Exception {
        if (!mShouldTestTelecom) {
            return;
        }
        setInCallServiceAppOpsPermission(false);
        int previousCallCount = mICtsThirdPartyInCallServiceControl.getLocalCallCount();
        addAndVerifyNewIncomingCall(TEST_URI, null);
        assertBindStatus(/* true: bind, false: unbind */true, /* expected result */false);
        assertCallCount(previousCallCount);
        // Third Party InCallService hasn't been bound yet, unbound latch can be null when tearDown.
        mExpectedTearDownBindingStatus = false;
    }

    public void testWithAppOpsPermission() throws Exception {
        if (!mShouldTestTelecom) {
            return;
        }
        // Grant App Ops Permission
        setInCallServiceAppOpsPermission(true);

        int previousCallCount = mICtsThirdPartyInCallServiceControl.getLocalCallCount();
        addAndVerifyNewIncomingCall(TEST_URI, null);
        assertBindStatus(/* true: bind, false: unbind */true, /* expected result */true);
        assertCallCount(previousCallCount + 1);
        mICtsThirdPartyInCallServiceControl.resetLatchForServiceBound(true);

        // Revoke App Ops Permission
        setInCallServiceAppOpsPermission(false);
    }

    /**
     *
     * @param bind: check the status of InCallService bind latches.
     *             Values: true (bound latch), false (unbound latch).
     * @param success: whether the latch should have counted down.
     */
    private void assertBindStatus(boolean bind, boolean success) {
        waitUntilConditionIsTrueOrTimeout(new Condition() {
            @Override
            public Object expected() {
                return success;
            }

            @Override
            public Object actual() {
                try {
                    return mICtsThirdPartyInCallServiceControl.checkBindStatus(bind);
                } catch (RemoteException re) {
                    Log.e(TAG, "Remote exception when checking bind status: " + re);
                    return false;
                }
            }
        }, WAIT_FOR_STATE_CHANGE_TIMEOUT_MS, "Unable to " + (bind ? "Bind" : "Unbind")
                + " third party in call service");
    }

    private void assertCallCount(int expected) {
        waitUntilConditionIsTrueOrTimeout(new Condition() {
            @Override
            public Object expected() {
                return expected;
            }

            @Override
            public Object actual() {
                try {
                    return mICtsThirdPartyInCallServiceControl.getLocalCallCount();
                } catch (RemoteException re) {
                    Log.e(TAG, "Remote exception when getting local call count: " + re);
                    return -1;
                }
            }
         }, WAIT_FOR_STATE_CHANGE_TIMEOUT_MS,
                "Failed to match localCallCount and expected: " + expected);
    }

    private void setUpControl() throws InterruptedException {
        Intent bindIntent = new Intent(CtsThirdPartyInCallServiceControl.CONTROL_INTERFACE_ACTION);
        // mContext is android.telecom.cts, which doesn't include thirdptyincallservice.
        ComponentName controlComponentName =
              ComponentName.createRelative(
                    CtsThirdPartyInCallServiceControl.class.getPackage().getName(),
                            CtsThirdPartyInCallServiceControl.class.getName());

        bindIntent.setComponent(controlComponentName);
        final CountDownLatch bindLatch = new CountDownLatch(1);
        boolean success = mContext.bindService(bindIntent, new ServiceConnection() {
            @Override
            public void onServiceConnected(ComponentName name, IBinder service) {
                Log.i(TAG, "Service Connected: " + name);
                mICtsThirdPartyInCallServiceControl =
                        ICtsThirdPartyInCallServiceControl.Stub.asInterface(service);
                bindLatch.countDown();
            }

            @Override
            public void onServiceDisconnected(ComponentName name) {
                mICtsThirdPartyInCallServiceControl = null;
            }
        }, Context.BIND_AUTO_CREATE);
        if (!success) {
            fail("Failed to get control interface -- bind error");
        }
        bindLatch.await(WAIT_FOR_STATE_CHANGE_TIMEOUT_MS, TimeUnit.MILLISECONDS);
    }

    private void setInCallServiceAppOpsPermission(boolean allow)
            throws PackageManager.NameNotFoundException {
        int uid = mPackageManager.getApplicationInfo(THIRD_PARITY_PACKAGE_NAME, 0).uid;
        invokeMethodWithShellPermissionsNoReturn(mAppOpsManager,
              (appOpsMan) -> appOpsMan.setUidMode(AppOpsManager.OPSTR_MANAGE_ONGOING_CALLS,
                      uid, allow ? AppOpsManager.MODE_ALLOWED : AppOpsManager.opToDefaultMode(
                              AppOpsManager.OPSTR_MANAGE_ONGOING_CALLS)));
    }
}
