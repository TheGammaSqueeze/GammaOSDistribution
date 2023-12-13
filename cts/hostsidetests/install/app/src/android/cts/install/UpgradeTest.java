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

package android.cts.install;

import static com.google.common.truth.Truth.assertThat;

import com.android.cts.install.lib.Install;
import com.android.cts.install.lib.TestApp;

import org.junit.Rule;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.junit.runners.Parameterized.Parameter;
import org.junit.runners.Parameterized.Parameters;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

@RunWith(Parameterized.class)
public final class UpgradeTest {
    @Parameter(0)
    public INSTALL_TYPE mInstallType;

    @Parameter(1)
    public boolean mStaged;

    @Parameter(2)
    public boolean mEnableRollback;

    @Parameters(name = "{0}_Staged{1}_Rollback{2}")
    public static Collection<Object[]> combinations() {
        boolean[] booleanValues = new boolean[]{true, false};
        List<Object[]> temp = new ArrayList<>();
        for (INSTALL_TYPE installType : INSTALL_TYPE.values()) {
            for (boolean staged : booleanValues) {
                for (boolean enableRollback : booleanValues) {
                    temp.add(new Object[]{installType, staged, enableRollback});
                }
            }
        }
        return temp;
    }

    @Rule
    public InstallRule mInstallRule = new InstallRule();

    @Rule
    public SessionRule mSessionRule = new SessionRule();

    private static final int VERSION_CODE_CURRENT = 2;
    private static final int VERSION_CODE_UPGRADE = 3;

    @Test
    public void cleanUp_phase() throws Exception {
        mInstallRule.cleanUp();
        mSessionRule.cleanUp();
    }

    /** Install the version {@link #VERSION_CODE_CURRENT} of the apps to be upgraded. */
    @Test
    public void arrange_phase() throws Exception {
        getParameterizedInstall(VERSION_CODE_CURRENT).commit();
    }

    @Test
    public void assert_postArrange_phase() {
        mInstallRule.assertPackageVersion(mInstallType, VERSION_CODE_CURRENT);
    }

    @Test
    public void action_phase() throws Exception {
        Install install = getParameterizedInstall(VERSION_CODE_UPGRADE);
        int sessionId = install.commit();
        mSessionRule.recordSessionId(sessionId);
    }

    @Test
    public void assert_phase() {
        mInstallRule.assertPackageVersion(mInstallType, VERSION_CODE_UPGRADE);
    }

    /** Confirms versions before staged samegrades applied. */
    @Test
    public void assert_preReboot_phase() throws Exception {
        assertThat(mSessionRule.retrieveSessionInfo().isStagedSessionReady()).isTrue();
        mInstallRule.assertPackageVersion(mInstallType, VERSION_CODE_CURRENT);
    }

    /** Confirms versions after staged samegrades applied. */
    @Test
    public void assert_postReboot_phase() throws Exception {
        assertThat(mSessionRule.retrieveSessionInfo().isStagedSessionApplied()).isTrue();
        mInstallRule.assertPackageVersion(mInstallType, VERSION_CODE_UPGRADE);
    }

    /** Gets parameterized {@link Install} of test packages with specific version. */
    private Install getParameterizedInstall(int versionCode) {
        List<TestApp> testApps = mInstallRule.getTestApps(mInstallType, versionCode);
        Install install = testApps.size() == 1
                ? Install.single(testApps.get(0))
                : Install.multi(testApps.toArray(new TestApp[testApps.size()]));
        if (mStaged) {
            install.setStaged();
        }
        if (mEnableRollback) {
            install.setEnableRollback();
        }
        return install;
    }
}
