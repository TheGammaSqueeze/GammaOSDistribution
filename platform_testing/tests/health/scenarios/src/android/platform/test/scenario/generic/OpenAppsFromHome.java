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

package android.platform.test.scenario.generic;

import android.os.SystemClock;
import android.platform.test.microbenchmark.Microbenchmark.NoMetricBefore;
import android.platform.test.option.IntegerOption;
import android.platform.test.option.StringOption;
import android.platform.test.rule.NaturalOrientationRule;
import android.platform.test.rule.UnlockScreenRule;
import android.platform.test.scenario.annotation.Scenario;

import com.android.launcher3.tapl.AllApps;
import com.android.launcher3.tapl.AppIcon;
import com.android.launcher3.tapl.LauncherInstrumentation;

import org.junit.AfterClass;
import org.junit.BeforeClass;
import org.junit.ClassRule;
import org.junit.Rule;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import java.io.IOException;
import java.util.concurrent.TimeUnit;

/**
 * Adds and Opens any application generically from home icon directly, based on the provided
 * options.
 */
@Scenario
@RunWith(JUnit4.class)
public class OpenAppsFromHome {

    // Class-level rules
    @ClassRule public static UnlockScreenRule unlockScreenRule = new UnlockScreenRule();

    @ClassRule public static NaturalOrientationRule orientationRule = new NaturalOrientationRule();

    private static LauncherInstrumentation sLauncher;
    private static AppIcon sAppIcon;

    @ClassRule
    public static StringOption sNameOption = new StringOption("app-name").setRequired(true);

    @Rule public StringOption mPkgOption = new StringOption("app-package-name").setRequired(true);

    @ClassRule
    public static IntegerOption delayTimeOption =
            new IntegerOption("delay-after-touching-sec").setRequired(false).setDefault(1);

    @BeforeClass
    public static void setup() throws IOException {
        sLauncher = new LauncherInstrumentation();
        final AllApps allApps = sLauncher.pressHome().switchToAllApps();
        allApps.getAppIcon(sNameOption.get()).dragToWorkspace(false, false);
        sAppIcon = sLauncher.getWorkspace().getWorkspaceAppIcon(sNameOption.get());
    }

    @NoMetricBefore
    public void openWorkspace() {
        sLauncher.pressHome();
    }

    @Test
    public void testOpenApps() {
        SystemClock.sleep(TimeUnit.SECONDS.toMillis(delayTimeOption.get()));
        sAppIcon.launch(mPkgOption.get());
    }

    @AfterClass
    public static void closeAppAndRemoveIcon() throws IOException {
        sLauncher.getDevice().executeShellCommand("pm clear com.google.android.apps.nexuslauncher");
        sLauncher.pressHome();
    }
}
