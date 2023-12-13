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

package android.security.cts;

import android.platform.test.annotations.AppModeFull;
import android.platform.test.annotations.AsbSecurityTest;
import com.android.tradefed.device.ITestDevice;
import com.android.tradefed.testtype.DeviceJUnit4ClassRunner;
import com.android.sts.common.tradefed.testtype.StsExtraBusinessLogicHostTestBase;
import org.junit.Assert;
import org.junit.Before;
import org.junit.runner.RunWith;
import org.junit.Test;

@RunWith(DeviceJUnit4ClassRunner.class)
public class CVE_2021_0586 extends StsExtraBusinessLogicHostTestBase {
    private static final String TEST_PKG = "android.security.cts.cve_2021_0586";
    private static final String TEST_CLASS = TEST_PKG + "." + "DeviceTest";
    private static final String TEST_APP = "CVE-2021-0586.apk";

    @Before
    public void setUp() throws Exception {
        ITestDevice device = getDevice();
        uninstallPackage(device, TEST_PKG);
        /* Wake up the screen */
        AdbUtils.runCommandLine("input keyevent KEYCODE_WAKEUP", device);
        AdbUtils.runCommandLine("input keyevent KEYCODE_MENU", device);
        AdbUtils.runCommandLine("input keyevent KEYCODE_HOME", device);
    }

    /**
     * b/182584940
     */
    @AppModeFull
    @AsbSecurityTest(cveBugId = 182584940)
    @Test
    public void testPocCVE_2021_0586() throws Exception {
        installPackage(TEST_APP);
        AdbUtils.runCommandLine("pm grant " + TEST_PKG + " android.permission.SYSTEM_ALERT_WINDOW",
                getDevice());
        Assert.assertTrue(runDeviceTests(TEST_PKG, TEST_CLASS, "testOverlayButtonPresence"));
    }
}
