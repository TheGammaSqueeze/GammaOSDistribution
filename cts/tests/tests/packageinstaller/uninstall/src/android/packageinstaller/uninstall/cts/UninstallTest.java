/*
 * Copyright (C) 2018 Google Inc.
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
package android.packageinstaller.uninstall.cts;

import static android.app.AppOpsManager.MODE_ALLOWED;
import static android.content.Intent.FLAG_ACTIVITY_CLEAR_TASK;
import static android.content.Intent.FLAG_ACTIVITY_NEW_TASK;
import static android.graphics.PixelFormat.TRANSLUCENT;
import static android.view.ViewGroup.LayoutParams.MATCH_PARENT;
import static android.view.WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;

import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Handler;
import android.os.Looper;
import android.platform.test.annotations.AppModeFull;
import android.platform.test.annotations.AsbSecurityTest;
import android.support.test.uiautomator.By;
import android.support.test.uiautomator.UiDevice;
import android.support.test.uiautomator.UiObject2;
import android.support.test.uiautomator.Until;
import android.util.Log;
import android.view.Gravity;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.WindowManager;
import android.view.WindowManager.LayoutParams;

import androidx.test.InstrumentationRegistry;
import androidx.test.runner.AndroidJUnit4;

import com.android.compatibility.common.util.AppOpsUtils;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

@RunWith(AndroidJUnit4.class)
@AppModeFull
public class UninstallTest {
    private static final String LOG_TAG = UninstallTest.class.getSimpleName();

    private static final String TEST_APK_PACKAGE_NAME = "android.packageinstaller.emptytestapp.cts";

    private static final long TIMEOUT_MS = 30000;
    private static final String APP_OP_STR = "REQUEST_DELETE_PACKAGES";

    private Context mContext;
    private UiDevice mUiDevice;

    @Before
    public void setup() throws Exception {
        mContext = InstrumentationRegistry.getTargetContext();

        // Unblock UI
        mUiDevice = UiDevice.getInstance(InstrumentationRegistry.getInstrumentation());
        if (!mUiDevice.isScreenOn()) {
            mUiDevice.wakeUp();
        }
        mUiDevice.executeShellCommand("wm dismiss-keyguard");
        AppOpsUtils.reset(mContext.getPackageName());
    }

    private void dumpWindowHierarchy() throws InterruptedException, IOException {
        ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
        mUiDevice.dumpWindowHierarchy(outputStream);
        String windowHierarchy = outputStream.toString(StandardCharsets.UTF_8.name());

        Log.w(LOG_TAG, "Window hierarchy:");
        for (String line : windowHierarchy.split("\n")) {
            Thread.sleep(10);
            Log.w(LOG_TAG, line);
        }
    }

    private void startUninstall() {
        Intent intent = new Intent(Intent.ACTION_UNINSTALL_PACKAGE);
        intent.setData(Uri.parse("package:" + TEST_APK_PACKAGE_NAME));
        intent.addFlags(FLAG_ACTIVITY_CLEAR_TASK | FLAG_ACTIVITY_NEW_TASK);
        Log.d(LOG_TAG, "sending uninstall intent ("  + intent + ") on user " + mContext.getUser());
        mContext.startActivity(intent);
    }

    @Test
    @AsbSecurityTest(cveBugId = 171221302)
    public void overlaysAreSuppressedWhenConfirmingUninstall() throws Exception {
        AppOpsUtils.setOpMode(mContext.getPackageName(), "SYSTEM_ALERT_WINDOW", MODE_ALLOWED);

        WindowManager windowManager = mContext.getSystemService(WindowManager.class);
        LayoutParams layoutParams = new LayoutParams(MATCH_PARENT, MATCH_PARENT,
                TYPE_APPLICATION_OVERLAY, 0, TRANSLUCENT);
        layoutParams.gravity = Gravity.CENTER_HORIZONTAL | Gravity.CENTER_VERTICAL;

        View[] overlay = new View[1];
        new Handler(Looper.getMainLooper()).post(() -> {
            overlay[0] = LayoutInflater.from(mContext).inflate(R.layout.overlay_activity,
                    null);
            windowManager.addView(overlay[0], layoutParams);
        });

        try {
            mUiDevice.wait(Until.findObject(By.res(mContext.getPackageName(),
                    "overlay_description")), TIMEOUT_MS);

            startUninstall();

            long start = System.currentTimeMillis();
            while (System.currentTimeMillis() - start < TIMEOUT_MS) {
                try {
                    assertNull(mUiDevice.findObject(By.res(mContext.getPackageName(),
                            "overlay_description")));
                    return;
                } catch (Throwable e) {
                    Thread.sleep(100);
                }
            }

            fail();
        } finally {
            windowManager.removeView(overlay[0]);
        }
    }

    @Test
    public void testUninstall() throws Exception {
        assertTrue("Package is not installed", isInstalled());

        startUninstall();

        if (mUiDevice.wait(Until.findObject(By.text("Do you want to uninstall this app?")),
                TIMEOUT_MS) == null) {
            dumpWindowHierarchy();
        }
        assertNotNull("Uninstall prompt not shown",
                mUiDevice.wait(Until.findObject(By.text("Do you want to uninstall this app?")),
                        TIMEOUT_MS));
        // The app's name should be shown to the user.
        assertNotNull(mUiDevice.findObject(By.text("Empty Test App")));

        // Confirm uninstall
        if (mContext.getPackageManager().hasSystemFeature(PackageManager.FEATURE_LEANBACK)) {
            UiObject2 clickableView = mUiDevice
                    .findObject(By.focusable(true).hasDescendant(By.text("OK")));
            if (!clickableView.isFocused()) {
                mUiDevice.pressKeyCode(KeyEvent.KEYCODE_DPAD_DOWN);
            }
            for (int i = 0; i < 100; i++) {
                if (clickableView.isFocused()) {
                    break;
                }
                Thread.sleep(100);
            }
            mUiDevice.pressKeyCode(KeyEvent.KEYCODE_DPAD_CENTER);
        } else {
            UiObject2 clickableView = mUiDevice.findObject(By.text("OK"));
            if (clickableView == null) {
              dumpWindowHierarchy();
              fail("OK button not shown");
            }
            clickableView.click();
        }

        for (int i = 0; i < 30; i++) {
            // We can't detect the confirmation Toast with UiAutomator, so we'll poll
            Thread.sleep(500);
            if (!isInstalled()) {
                break;
            }
        }
        assertFalse("Package wasn't uninstalled.", isInstalled());
        assertTrue(AppOpsUtils.allowedOperationLogged(mContext.getPackageName(), APP_OP_STR));
    }

    private boolean isInstalled() {
        Log.d(LOG_TAG, "Testing if package " + TEST_APK_PACKAGE_NAME + " is installed for user "
                + mContext.getUser());
        try {
            mContext.getPackageManager().getPackageInfo(TEST_APK_PACKAGE_NAME, /* flags= */ 0);
            return true;
        } catch (PackageManager.NameNotFoundException e) {
            Log.v(LOG_TAG, "Package " + TEST_APK_PACKAGE_NAME + " not installed for user "
                    + mContext.getUser() + ": " + e);
            return false;
        }
    }
}
