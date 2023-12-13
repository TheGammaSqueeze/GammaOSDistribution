/*
 * Copyright (C) 2016 The Android Open Source Project
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
package android.security.cts;

import android.app.Instrumentation;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.os.Process;
import android.os.RemoteException;
import android.platform.test.annotations.AsbSecurityTest;
import android.security.cts.IIsolatedService;
import android.security.cts.IsolatedService;
import android.util.Log;
import androidx.test.InstrumentationRegistry;
import com.android.internal.util.ArrayUtils;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;
import junit.framework.Assert;
import org.junit.Before;
import org.junit.After;

import androidx.test.runner.AndroidJUnit4;
import org.junit.runner.RunWith;
import org.junit.Test;

@RunWith(AndroidJUnit4.class)
public class IsolatedProcessTest {
    static final String TAG = IsolatedProcessTest.class.getSimpleName();

    private static final long BIND_SERVICE_TIMEOUT = 5000;

    // No service other than these should be visible to an isolated process
    private static final String[] SERVICES_ALLOWED_TO_ISOLATED_PROCESS = {
            "package",
            Context.ACTIVITY_SERVICE
    };
    // Arbitrary set of services to test accessibility from an isolated process
    private static final String[] RESTRICTED_SERVICES_TO_TEST = {
            Context.ALARM_SERVICE,
            Context.WINDOW_SERVICE,
            Context.POWER_SERVICE
    };

    private CountDownLatch mLatch;
    private IIsolatedService mService;
    private final ServiceConnection mServiceConnection = new ServiceConnection() {

        @Override
        public void onServiceDisconnected(ComponentName name) {
            Log.e(TAG, "Isolated service " + name + " died abruptly");
        }

        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            mService = IIsolatedService.Stub.asInterface(service);
            mLatch.countDown();
        }
    };

    private static Instrumentation getInstrumentation() {
        return InstrumentationRegistry.getInstrumentation();
    }

    @Before
    public void setUp() throws InterruptedException {
        mLatch = new CountDownLatch(1);
        Intent serviceIntent = new Intent(getInstrumentation().getContext(), IsolatedService.class);
        getInstrumentation().getContext().bindService(serviceIntent, mServiceConnection, Context.BIND_AUTO_CREATE);
        Assert.assertTrue("Timed out while waiting to bind to isolated service",
                mLatch.await(BIND_SERVICE_TIMEOUT, TimeUnit.MILLISECONDS));
    }

    @Test
    @AsbSecurityTest(cveBugId = 30202228)
    public void testGetCachedServicesFromIsolatedService() throws RemoteException {
        String[] cachedServices = mService.getCachedSystemServices();
        for (String serviceName : cachedServices) {
            Assert.assertTrue(serviceName + " should not be accessbible from an isolated process",
                    ArrayUtils.contains(SERVICES_ALLOWED_TO_ISOLATED_PROCESS, serviceName));
        }
    }

    @Test
    @AsbSecurityTest(cveBugId = 30202228)
    public void testGetServiceFromIsolatedService() throws RemoteException {
        for (String serviceName : RESTRICTED_SERVICES_TO_TEST) {
            IBinder service = mService.getSystemService(serviceName);
            Assert.assertNull(serviceName + " should not be accessible from an isolated process",
                    service);
        }
    }

    @Test
    public void testGetProcessIsIsolated() throws RemoteException {
        Assert.assertFalse(Process.isIsolated());
        Assert.assertTrue(mService.getProcessIsIsolated());
    }

    @After
    public void tearDown() {
        getInstrumentation().getContext().unbindService(mServiceConnection);
    }

}
