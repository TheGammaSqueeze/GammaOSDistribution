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

package android.cts.statsdatom.appcompatstate;

import static com.android.os.AtomsProto.AppCompatStateChanged.State.LETTERBOXED_FOR_ASPECT_RATIO;
import static com.android.os.AtomsProto.AppCompatStateChanged.State.LETTERBOXED_FOR_FIXED_ORIENTATION;
import static com.android.os.AtomsProto.AppCompatStateChanged.State.LETTERBOXED_FOR_SIZE_COMPAT_MODE;
import static com.android.os.AtomsProto.AppCompatStateChanged.State.NOT_LETTERBOXED;
import static com.android.os.AtomsProto.AppCompatStateChanged.State.NOT_VISIBLE;

import static com.google.common.truth.Truth.assertThat;

import android.cts.statsdatom.lib.AtomTestUtils;
import android.cts.statsdatom.lib.ConfigUtils;
import android.cts.statsdatom.lib.DeviceUtils;
import android.cts.statsdatom.lib.ReportUtils;

import com.android.os.AtomsProto;
import com.android.os.AtomsProto.AppCompatStateChanged;
import com.android.os.StatsLog.EventMetricData;
import com.android.tradefed.build.IBuildInfo;
import com.android.tradefed.log.LogUtil.CLog;
import com.android.tradefed.testtype.DeviceTestCase;
import com.android.tradefed.testtype.IBuildReceiver;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import javax.annotation.Nullable;

/**
 * This test is for making sure that App Compat state changes log the desired atoms.
 *
 * <p>Build/Install/Run:
 * atest CtsStatsdAtomHostTestCases:AppCompatStateStatsTests
 */
// TODO(b/197223993): test click on size-compat restart button
public class AppCompatStateStatsTests extends DeviceTestCase implements IBuildReceiver {

    private static final String RESIZEABLE_ACTIVITY =
            "StatsdCtsForegroundActivity";
    private static final String NON_RESIZEABLE_PORTRAIT_ACTIVITY =
            "StatsdCtsNonResizeablePortraitActivity";
    private static final String MIN_ASPECT_RATIO_PORTRAIT_ACTIVITY =
            "StatsdCtsMinAspectRatioPortraitActivity";
    private static final String CMD_GET_STAY_ON = "settings get global stay_on_while_plugged_in";
    private static final String CMD_PUT_STAY_ON_TEMPLATE =
            "settings put global stay_on_while_plugged_in %d";
    private static final int ENABLE_STAY_ON_CODE = 7;
    private static final String CMD_GET_AVAILABLE_DEVICE_STATES =
            "cmd device_state print-states-simple";
    private static final String CMD_RESET_DEVICE_STATE = "cmd device_state state reset";
    private static final String CMD_PUT_DEVICE_STATE_TEMPLATE = "cmd device_state state %d";
    private static final int DEVICE_STATE_CLOSED = 0;
    private static final int DEVICE_STATE_OPENED = 2;
    private static final int ELAPSED_TIME_MILLIS_THRESHOLD = 100;
    private static final long ELAPSED_TIME_NANOS_THRESHOLD =
            ELAPSED_TIME_MILLIS_THRESHOLD * 1000000;

    private IBuildInfo mCtsBuild;
    private long mOriginalStayOnSetting;

    @Override
    protected void setUp() throws Exception {
        super.setUp();
        assertThat(mCtsBuild).isNotNull();
        mOriginalStayOnSetting = Long.parseLong(
                getDevice().executeShellCommand(CMD_GET_STAY_ON).trim());
        getDevice().executeShellCommand(
                String.format(CMD_PUT_STAY_ON_TEMPLATE, ENABLE_STAY_ON_CODE));
        getDevice().executeShellCommand(
                String.format(CMD_PUT_DEVICE_STATE_TEMPLATE, DEVICE_STATE_CLOSED));
        ConfigUtils.removeConfig(getDevice());
        ReportUtils.clearReports(getDevice());
        DeviceUtils.installStatsdTestApp(getDevice(), mCtsBuild);
        DeviceUtils.turnScreenOn(getDevice());
        Thread.sleep(AtomTestUtils.WAIT_TIME_LONG);
        ConfigUtils.uploadConfigForPushedAtomWithUid(getDevice(), DeviceUtils.STATSD_ATOM_TEST_PKG,
                AtomsProto.Atom.APP_COMPAT_STATE_CHANGED_FIELD_NUMBER, /*uidInAttributionChain=*/
                false);
    }

    @Override
    protected void tearDown() throws Exception {
        getDevice().executeShellCommand(
                String.format(CMD_PUT_STAY_ON_TEMPLATE, mOriginalStayOnSetting));
        getDevice().executeShellCommand(CMD_RESET_DEVICE_STATE);
        ConfigUtils.removeConfig(getDevice());
        ReportUtils.clearReports(getDevice());
        DeviceUtils.uninstallStatsdTestApp(getDevice());
        super.tearDown();
    }

    @Override
    public void setBuild(IBuildInfo buildInfo) {
        mCtsBuild = buildInfo;
    }

    public void testResizableActivityDeviceStateClosedToOpened() throws Exception {
        testAppCompatFlow(RESIZEABLE_ACTIVITY, /* switchToOpened= */ true,
                Arrays.asList(NOT_LETTERBOXED, NOT_VISIBLE));
    }

    public void testNonResizablePortraitActivityDeviceStateClosedToOpened() throws Exception {
        // The 1st option for expected states is for portrait devices and the 2nd option is for
        // landscape devices.
        testAppCompatFlow(NON_RESIZEABLE_PORTRAIT_ACTIVITY, /* switchToOpened= */ true,
                Arrays.asList(NOT_LETTERBOXED, LETTERBOXED_FOR_SIZE_COMPAT_MODE, NOT_VISIBLE),
                Arrays.asList(LETTERBOXED_FOR_FIXED_ORIENTATION, LETTERBOXED_FOR_SIZE_COMPAT_MODE,
                        NOT_VISIBLE));
    }

    public void testMinAspectRatioPortraitActivityDeviceStateClosedToOpened() throws Exception {
        // The 1st option for expected states is for portrait devices and the 2nd option is for
        // landscape devices.
        testAppCompatFlow(MIN_ASPECT_RATIO_PORTRAIT_ACTIVITY, /* switchToOpened= */ true,
                Arrays.asList(LETTERBOXED_FOR_ASPECT_RATIO, LETTERBOXED_FOR_SIZE_COMPAT_MODE,
                        NOT_VISIBLE), Arrays.asList(LETTERBOXED_FOR_FIXED_ORIENTATION,
                        LETTERBOXED_FOR_SIZE_COMPAT_MODE, NOT_VISIBLE));
    }

    public void testResizableActivityThenMinAspectRatioPortraitActivity() throws Exception {
        // The 1st option for expected states is for portrait devices and the 2nd option is for
        // landscape devices.
        testAppCompatFlow(RESIZEABLE_ACTIVITY,
                MIN_ASPECT_RATIO_PORTRAIT_ACTIVITY, /* switchToOpened= */ false,
                Arrays.asList(NOT_LETTERBOXED, LETTERBOXED_FOR_ASPECT_RATIO, NOT_VISIBLE),
                Arrays.asList(NOT_LETTERBOXED, LETTERBOXED_FOR_FIXED_ORIENTATION, NOT_VISIBLE));
    }

    public void testMinAspectRatioPortraitActivityThenResizableActivity() throws Exception {
        // The 1st option for expected states is for portrait devices and the 2nd option is for
        // landscape devices.
        testAppCompatFlow(MIN_ASPECT_RATIO_PORTRAIT_ACTIVITY,
                RESIZEABLE_ACTIVITY, /* switchToOpened= */ false,
                Arrays.asList(LETTERBOXED_FOR_ASPECT_RATIO, NOT_LETTERBOXED, NOT_VISIBLE),
                Arrays.asList(LETTERBOXED_FOR_FIXED_ORIENTATION, NOT_LETTERBOXED, NOT_VISIBLE));
    }

    public void testNonResizablePortraitActivitySwitchedToOpenedThenMinAspectRatioActivity()
            throws Exception {
        // The 1st and 2nd options for expected states are for portrait devices, the 3rd and 4th
        // options are for landscape devices, and the 5th and 6th options are for portrait
        // devices that unfold into landscape, there are two options for each type of device because
        // the NOT_VISIBLE state between visible states isn't always logged.
        testAppCompatFlow(NON_RESIZEABLE_PORTRAIT_ACTIVITY,
                MIN_ASPECT_RATIO_PORTRAIT_ACTIVITY, /* switchToOpened= */ true,
                Arrays.asList(NOT_LETTERBOXED, LETTERBOXED_FOR_SIZE_COMPAT_MODE, NOT_VISIBLE,
                        LETTERBOXED_FOR_ASPECT_RATIO, NOT_VISIBLE),
                Arrays.asList(NOT_LETTERBOXED, LETTERBOXED_FOR_SIZE_COMPAT_MODE,
                        LETTERBOXED_FOR_ASPECT_RATIO, NOT_VISIBLE),
                Arrays.asList(LETTERBOXED_FOR_FIXED_ORIENTATION, LETTERBOXED_FOR_SIZE_COMPAT_MODE,
                        NOT_VISIBLE, LETTERBOXED_FOR_FIXED_ORIENTATION, NOT_VISIBLE),
                Arrays.asList(LETTERBOXED_FOR_FIXED_ORIENTATION, LETTERBOXED_FOR_SIZE_COMPAT_MODE,
                        LETTERBOXED_FOR_FIXED_ORIENTATION, NOT_VISIBLE),
                Arrays.asList(NOT_LETTERBOXED, LETTERBOXED_FOR_SIZE_COMPAT_MODE, NOT_VISIBLE,
                        LETTERBOXED_FOR_FIXED_ORIENTATION, NOT_VISIBLE),
                Arrays.asList(NOT_LETTERBOXED, LETTERBOXED_FOR_SIZE_COMPAT_MODE,
                        LETTERBOXED_FOR_FIXED_ORIENTATION, NOT_VISIBLE));
    }

    private void testAppCompatFlow(String activity, boolean switchToOpened,
            List<AppCompatStateChanged.State>... expectedStatesOptions) throws Exception {
        testAppCompatFlow(activity, /* secondActivity= */ null, switchToOpened,
                expectedStatesOptions);
    }

    private void testAppCompatFlow(String activity, @Nullable String secondActivity,
            boolean switchToOpened, List<AppCompatStateChanged.State>... expectedStatesOptions)
            throws Exception {
        if (!isOpenedDeviceStateAvailable()) {
            CLog.i("Device doesn't support OPENED device state.");
            return;
        }

        try (AutoCloseable a1 = DeviceUtils.withActivity(getDevice(),
                DeviceUtils.STATSD_ATOM_TEST_PKG, activity, "action", "action.sleep_top")) {
            Thread.sleep(AtomTestUtils.WAIT_TIME_LONG);
            if (switchToOpened) {
                getDevice().executeShellCommand(
                        String.format(CMD_PUT_DEVICE_STATE_TEMPLATE, DEVICE_STATE_OPENED));
                Thread.sleep(AtomTestUtils.WAIT_TIME_LONG);
            }

            if (secondActivity != null) {
                try (AutoCloseable a2 = DeviceUtils.withActivity(getDevice(),
                        DeviceUtils.STATSD_ATOM_TEST_PKG, secondActivity, "action",
                        "action.sleep_top")) {
                    Thread.sleep(AtomTestUtils.WAIT_TIME_LONG);
                }
            }
        }
        Thread.sleep(AtomTestUtils.WAIT_TIME_LONG);

        assertThat(expectedStatesOptions).asList().contains(
                getAppCompatStatesForUid(DeviceUtils.getStatsdTestAppUid(getDevice())));
    }

    private List<AppCompatStateChanged.State> getAppCompatStatesForUid(int uid)
            throws Exception {
        ArrayList<AppCompatStateChanged.State> result = new ArrayList<>();
        long prevTimestampNanos = 0L;
        AppCompatStateChanged.State prevState = AppCompatStateChanged.State.UNKNOWN;
        AppCompatStateChanged.State prevAddedState = AppCompatStateChanged.State.UNKNOWN;
        for (EventMetricData data : ReportUtils.getEventMetricDataList(getDevice())) {
            AppCompatStateChanged appCompatStateChanged = data.getAtom().getAppCompatStateChanged();
            if (appCompatStateChanged.getUid() == uid) {
                AppCompatStateChanged.State curState = appCompatStateChanged.getState();
                assertThat(curState).isNotEqualTo(prevState);
                if (prevState != prevAddedState && (
                        (data.getElapsedTimestampNanos() - prevTimestampNanos)
                                > ELAPSED_TIME_NANOS_THRESHOLD)) {
                    result.add(prevState);
                    prevAddedState = prevState;
                }
                prevState = curState;
                prevTimestampNanos = data.getElapsedTimestampNanos();
            }
        }
        if (prevState != prevAddedState) {
            result.add(prevState);
        }
        return result;
    }

    private boolean isOpenedDeviceStateAvailable() throws Exception {
        return Arrays.stream(
                getDevice().executeShellCommand(CMD_GET_AVAILABLE_DEVICE_STATES).split(","))
                .map(Integer::valueOf)
                .anyMatch(state -> state == DEVICE_STATE_OPENED);
    }
}