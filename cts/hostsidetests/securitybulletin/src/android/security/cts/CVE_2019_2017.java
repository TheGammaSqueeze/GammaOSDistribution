/*
 * Copyright (C) 2022 The Android Open Source Project
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

import android.platform.test.annotations.AsbSecurityTest;

import com.android.compatibility.common.util.CrashUtils;
import com.android.compatibility.common.util.CrashUtils.Config.BacktraceFilterPattern;
import com.android.tradefed.testtype.DeviceJUnit4ClassRunner;

import java.util.regex.Pattern;

import org.junit.runner.RunWith;
import org.junit.Test;

@RunWith(DeviceJUnit4ClassRunner.class)
public class CVE_2019_2017 extends SecurityTestCase {

    /**
     * b/121035711
     * Vulnerability Behaviour: SIGABRT in self
     * Vulnerable Library: libnfc-nci (As per AOSP code)
     * Vulnerable Function: rw_t2t_handle_tlv_detect_rsp (As per AOSP code)
     */
    @AsbSecurityTest(cveBugId = 121035711)
    @Test
    public void testPocCVE_2019_2017() throws Exception {
        AdbUtils.assumeHasNfc(getDevice());
        assumeIsSupportedNfcDevice(getDevice());
        pocPusher.only64();
        String signals[] = {CrashUtils.SIGABRT};
        String binaryName = "CVE-2019-2017";
        AdbUtils.pocConfig testConfig = new AdbUtils.pocConfig(binaryName, getDevice());
        testConfig.config = new CrashUtils.Config().setProcessPatterns(Pattern.compile(binaryName))
                .setBacktraceIncludes(new BacktraceFilterPattern("libnfc-nci",
                        "rw_t2t_handle_tlv_detect_rsp"));
        testConfig.config
                .setBacktraceExcludes(new BacktraceFilterPattern("libdl", "__cfi_slowpath"));
        testConfig.config.setSignals(signals);
        AdbUtils.runPocAssertNoCrashesNotVulnerable(testConfig);
    }
}
