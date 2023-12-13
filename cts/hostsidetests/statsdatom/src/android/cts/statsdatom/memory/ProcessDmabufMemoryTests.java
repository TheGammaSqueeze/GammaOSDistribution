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

package android.cts.statsdatom.memory;

import static com.google.common.truth.Truth.assertThat;

import android.cts.statsdatom.lib.AtomTestUtils;
import android.cts.statsdatom.lib.ConfigUtils;
import android.cts.statsdatom.lib.DeviceUtils;
import android.cts.statsdatom.lib.ReportUtils;

import com.android.compatibility.common.util.PropertyUtil;
import com.android.os.AtomsProto;
import com.android.tradefed.build.IBuildInfo;
import com.android.tradefed.testtype.DeviceTestCase;
import com.android.tradefed.testtype.IBuildReceiver;
import com.android.tradefed.util.Pair;

import java.util.List;

public class ProcessDmabufMemoryTests extends DeviceTestCase implements IBuildReceiver {
    private IBuildInfo mCtsBuild;

    @Override
    protected void setUp() throws Exception {
        super.setUp();
        assertThat(mCtsBuild).isNotNull();
        ConfigUtils.removeConfig(getDevice());
        ReportUtils.clearReports(getDevice());
        DeviceUtils.installStatsdTestApp(getDevice(), mCtsBuild);
        Thread.sleep(AtomTestUtils.WAIT_TIME_LONG);
    }

    @Override
    protected void tearDown() throws Exception {
        ConfigUtils.removeConfig(getDevice());
        ReportUtils.clearReports(getDevice());
        DeviceUtils.uninstallStatsdTestApp(getDevice());
        super.tearDown();
    }

    @Override
    public void setBuild(IBuildInfo buildInfo) {
        mCtsBuild = buildInfo;
    }

    public void testProcessDmabufMemoryAtom() throws Exception {
        boolean supportsFds = DeviceUtils.isKernelGreaterEqual(getDevice(), Pair.create(5, 4))
                && PropertyUtil.getFirstApiLevel(getDevice()) >= 31
                && PropertyUtil.getVendorApiLevel(getDevice()) >= 31;

        List<AtomsProto.Atom> atoms = pullAsGaugeMetric();
        for (AtomsProto.Atom atom : atoms) {
            AtomsProto.ProcessDmabufMemory stats = atom.getProcessDmabufMemory();
            assertThat(stats.getProcessName()).isNotEmpty();
            assertThat(stats.getMappedDmabufKb()).isAtLeast(0);
            assertThat(stats.getMappedDmabufCount()).isAtLeast(0);
            if (supportsFds) {
                assertThat(stats.getRetainedDmabufKb()).isAtLeast(0);
                assertThat(stats.getRetainedDmabufCount()).isAtLeast(0);
            }
        }
    }

    private List<AtomsProto.Atom> pullAsGaugeMetric() throws Exception {
        ConfigUtils.uploadConfigForPulledAtom(getDevice(), DeviceUtils.STATSD_ATOM_TEST_PKG,
                AtomsProto.Atom.PROCESS_DMABUF_MEMORY_FIELD_NUMBER);
        AtomTestUtils.sendAppBreadcrumbReportedAtom(getDevice());
        Thread.sleep(AtomTestUtils.WAIT_TIME_LONG);
        return ReportUtils.getGaugeMetricAtoms(getDevice());
    }
}
