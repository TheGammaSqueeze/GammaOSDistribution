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

package com.android.sts.common.util;

import android.os.Build;
import android.util.Log;

import androidx.test.InstrumentationRegistry;

import com.android.compatibility.common.util.ExtraBusinessLogicTestCase;
import com.android.compatibility.common.util.PropertyUtil;

import org.junit.Rule;
import org.junit.runner.Description;

import java.time.LocalDate;
import java.util.List;

/** The device-side implementation of StsLogic. */
public class StsExtraBusinessLogicTestCase extends ExtraBusinessLogicTestCase implements StsLogic {

    private LocalDate deviceSpl = null;
    private LocalDate kernelSpl = null;
    @Rule public DescriptionProvider descriptionProvider = new DescriptionProvider();

    protected StsExtraBusinessLogicTestCase() {
        mDependentOnBusinessLogic = false;
    }

    @Override
    public List<String> getExtraBusinessLogics() {
        // set in test/sts/tools/sts-tradefed/res/config/sts-base-dynamic-*.xml
        String stsDynamicPlan =
                InstrumentationRegistry.getArguments().getString("sts-dynamic-plan");
        return StsLogic.getExtraBusinessLogicForPlan(stsDynamicPlan);
    }

    @Override
    public Description getTestDescription() {
        return descriptionProvider.getDescription();
    }

    @Override
    public LocalDate getPlatformSpl() {
        if (deviceSpl == null) {
            deviceSpl = SplUtils.localDateFromSplString(Build.VERSION.SECURITY_PATCH);
        }
        return deviceSpl;
    }

    @Override
    public LocalDate getKernelSpl() {
        if (kernelSpl == null) {
            // set in:
            // test/sts/tools/sts-tradefed/src/com/android/tradefed/targetprep/multi/KernelSPL.java
            String kernelSplString =
                    PropertyUtil.getProperty("persist.sts.build_version_kernel_security_patch");
            if (kernelSplString == null) {
                return null;
            }
            kernelSpl = SplUtils.localDateFromSplString(kernelSplString);
        }
        return kernelSpl;
    }

    @Override
    public boolean shouldUseKernelSpl() {
        // set in test/sts/tools/sts-tradefed/res/config/sts-base-use-kernel-spl.xml
        String useKernelSplString =
                InstrumentationRegistry.getArguments().getString("sts-use-kernel-spl");
        return Boolean.parseBoolean(useKernelSplString);
    }

    /**
     * Specify the latest release bulletin. Control this from the command-line with the following:
     * --test-arg
     * com.android.tradefed.testtype.AndroidJUnitTest:instrumentation-arg:release-bulletin-spl:=2020-06
     */
    @Override
    public LocalDate getReleaseBulletinSpl() {
        // set manually with command-line args at runtime
        String releaseBulletinSpl =
                InstrumentationRegistry.getArguments().getString("release-bulletin-spl");
        if (releaseBulletinSpl == null) {
            return null;
        }
        // bulletin is released by month; add any day - only the year and month are compared.
        releaseBulletinSpl =
                String.format("%s-%02d", releaseBulletinSpl, SplUtils.Type.PARTIAL.day);
        return SplUtils.localDateFromSplString(releaseBulletinSpl);
    }

    @Override
    public void logInfo(String logTag, String format, Object... args) {
        Log.i(logTag, String.format(format, args));
    }

    @Override
    public void logDebug(String logTag, String format, Object... args) {
        Log.d(logTag, String.format(format, args));
    }

    @Override
    public void logWarn(String logTag, String format, Object... args) {
        Log.w(logTag, String.format(format, args));
    }

    @Override
    public void logError(String logTag, String format, Object... args) {
        Log.e(logTag, String.format(format, args));
    }
}
