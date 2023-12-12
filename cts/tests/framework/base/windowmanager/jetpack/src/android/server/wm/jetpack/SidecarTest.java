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

package android.server.wm.jetpack;

import static android.content.res.Configuration.ORIENTATION_LANDSCAPE;
import static android.content.res.Configuration.ORIENTATION_PORTRAIT;
import static android.server.wm.jetpack.utils.SidecarUtil.MINIMUM_SIDECAR_VERSION;
import static android.server.wm.jetpack.utils.SidecarUtil.assertEqualWindowLayoutInfo;
import static android.server.wm.jetpack.utils.SidecarUtil.assumeHasDisplayFeatures;
import static android.server.wm.jetpack.utils.SidecarUtil.assumeSidecarSupportedDevice;
import static android.server.wm.jetpack.utils.SidecarUtil.getSidecarInterface;
import static android.server.wm.jetpack.utils.SidecarUtil.isSidecarVersionValid;
import static android.server.wm.jetpack.utils.WindowManagerJetpackTestBase.assertNotBothDimensionsZero;
import static android.server.wm.jetpack.utils.WindowManagerJetpackTestBase.assertHasNonNegativeDimensions;
import static android.server.wm.jetpack.utils.WindowManagerJetpackTestBase.doesDisplayRotateForOrientation;
import static android.server.wm.jetpack.utils.WindowManagerJetpackTestBase.getActivityBounds;
import static android.server.wm.jetpack.utils.WindowManagerJetpackTestBase.getActivityWindowToken;
import static android.server.wm.jetpack.utils.WindowManagerJetpackTestBase.getMaximumActivityBounds;
import static android.server.wm.jetpack.utils.WindowManagerJetpackTestBase.setActivityOrientationActivityDoesNotHandleOrientationChanges;
import static android.server.wm.jetpack.utils.WindowManagerJetpackTestBase.setActivityOrientationActivityHandlesOrientationChanges;

import static com.google.common.truth.Truth.assertThat;

import static org.junit.Assert.assertFalse;
import static org.junit.Assume.assumeFalse;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;
import static org.junit.Assume.assumeTrue;

import android.content.pm.ActivityInfo;
import android.graphics.Rect;
import android.os.IBinder;
import android.platform.test.annotations.FlakyTest;
import android.platform.test.annotations.Presubmit;
import android.server.wm.jetpack.utils.WindowManagerJetpackTestBase;
import android.server.wm.jetpack.utils.SidecarCallbackCounter;
import android.server.wm.jetpack.utils.TestActivity;
import android.server.wm.jetpack.utils.TestConfigChangeHandlingActivity;
import android.server.wm.jetpack.utils.TestGetWindowLayoutInfoActivity;

import androidx.test.ext.junit.runners.AndroidJUnit4;
import androidx.test.filters.LargeTest;

import androidx.window.sidecar.SidecarDeviceState;
import androidx.window.sidecar.SidecarDisplayFeature;
import androidx.window.sidecar.SidecarInterface;
import androidx.window.sidecar.SidecarWindowLayoutInfo;

import com.google.common.collect.BoundType;
import com.google.common.collect.Range;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;

import java.util.List;

/**
 * Tests for the {@link androidx.window.sidecar} implementation provided on the device (and only
 * if one is available).
 *
 * Build/Install/Run:
 *     atest CtsWindowManagerJetpackTestCases:SidecarTest
 */
@LargeTest
@Presubmit
@RunWith(AndroidJUnit4.class)
public class SidecarTest extends WindowManagerJetpackTestBase {
    private static final String TAG = "SidecarTest";

    private TestActivity mActivity;
    private SidecarInterface mSidecarInterface;
    private IBinder mWindowToken;

    @Before
    @Override
    public void setUp() {
        super.setUp();
        assumeSidecarSupportedDevice(mContext);
        mActivity = (TestActivity) startActivityNewTask(TestActivity.class);
        mSidecarInterface = getSidecarInterface(mActivity);
        assertThat(mSidecarInterface).isNotNull();
        mWindowToken = getActivityWindowToken(mActivity);
        assertThat(mWindowToken).isNotNull();
    }

    /**
     * Test adding and removing a sidecar interface window layout change listener.
     */
    @Test
    public void testSidecarInterface_onWindowLayoutChangeListener() {
        // Set activity to portrait
        setActivityOrientationActivityDoesNotHandleOrientationChanges(mActivity,
                ORIENTATION_PORTRAIT);

        // Create the sidecar callback. onWindowLayoutChanged should only be called twice in this
        // test, not the third time when the orientation will change because the listener will be
        // removed.
        SidecarCallbackCounter sidecarCallback = new SidecarCallbackCounter(mWindowToken,
                2 /* expectedCallbackCount */);
        mSidecarInterface.setSidecarCallback(sidecarCallback);

        // Add window layout listener for mWindowToken - onWindowLayoutChanged should be called
        mSidecarInterface.onWindowLayoutChangeListenerAdded(mWindowToken);

        // Change the activity orientation - onWindowLayoutChanged should be called
        setActivityOrientationActivityDoesNotHandleOrientationChanges(mActivity,
                ORIENTATION_LANDSCAPE);

        // Remove the listener
        mSidecarInterface.onWindowLayoutChangeListenerRemoved(mWindowToken);

        // Change the activity orientation - onWindowLayoutChanged should NOT be called
        setActivityOrientationActivityDoesNotHandleOrientationChanges(mActivity,
                ORIENTATION_PORTRAIT);

        // Check that the countdown is zero
        sidecarCallback.assertZeroCount();
    }

    @Test
    public void testSidecarInterface_getWindowLayoutInfo() {
        assumeHasDisplayFeatures(mSidecarInterface, mWindowToken);

        // Layout must happen after launch
        assertThat(mActivity.waitForLayout()).isTrue();
        SidecarWindowLayoutInfo windowLayoutInfo = mSidecarInterface.getWindowLayoutInfo(
                mWindowToken);
        assertThat(windowLayoutInfo).isNotNull();

        for (SidecarDisplayFeature displayFeature : windowLayoutInfo.displayFeatures) {
            int featureType = displayFeature.getType();
            assertThat(featureType).isAtLeast(SidecarDisplayFeature.TYPE_FOLD);
            assertThat(featureType).isAtMost(SidecarDisplayFeature.TYPE_HINGE);

            Rect featureRect = displayFeature.getRect();
            // Feature cannot have negative area
            assertHasNonNegativeDimensions(featureRect);
            // Feature cannot have zero width and height, at most only one dimension can be zero
            assertNotBothDimensionsZero(featureRect);
            // Check that feature is within the activity bounds
            assertTrue(getActivityBounds(mActivity).contains(featureRect));
        }
    }

    @Test
    public void testSidecarInterface_getDeviceState() {
        SidecarDeviceState deviceState = mSidecarInterface.getDeviceState();
        assertThat(deviceState).isNotNull();

        assertThat(deviceState.posture).isIn(Range.range(
                SidecarDeviceState.POSTURE_UNKNOWN, BoundType.CLOSED,
                SidecarDeviceState.POSTURE_FLIPPED, BoundType.CLOSED));
    }

    @Test
    public void testSidecarInterface_onDeviceStateListenersChanged() {
        SidecarDeviceState deviceState1 = mSidecarInterface.getDeviceState();
        mSidecarInterface.onDeviceStateListenersChanged(false /* isEmpty */);
        SidecarDeviceState deviceState2 = mSidecarInterface.getDeviceState();
        mSidecarInterface.onDeviceStateListenersChanged(true /* isEmpty */);
        SidecarDeviceState deviceState3 = mSidecarInterface.getDeviceState();

        assertEquals(deviceState1.posture, deviceState2.posture);
        assertEquals(deviceState1.posture, deviceState3.posture);
    }

    /**
     * Tests that before an activity is attached to a window,
     * {@link SidecarInterface#getWindowLayoutInfo()} either returns the same value as it would
     * after the activity is attached to a window or throws an exception.
     */
    @Test
    public void testGetWindowLayoutInfo_activityNotAttachedToWindow_returnsCorrectValue() {
        assumeHasDisplayFeatures(mSidecarInterface, mWindowToken);

        // The value is verified inside TestGetWindowLayoutInfoActivity
        TestGetWindowLayoutInfoActivity.resetResumeCounter();
        TestGetWindowLayoutInfoActivity testGetWindowLayoutInfoActivity
                = (TestGetWindowLayoutInfoActivity) startActivityNewTask(
                        TestGetWindowLayoutInfoActivity.class);

        // Make sure the activity has gone through all states.
        assertThat(TestGetWindowLayoutInfoActivity.waitForOnResume()).isTrue();
        assertThat(testGetWindowLayoutInfoActivity.waitForLayout()).isTrue();
    }

    @Test
    public void testGetWindowLayoutInfo_configChanged_windowLayoutUpdates() {
        assumeHasDisplayFeatures(mSidecarInterface, mWindowToken);

        TestConfigChangeHandlingActivity configHandlingActivity
                = (TestConfigChangeHandlingActivity) startActivityNewTask(
                TestConfigChangeHandlingActivity.class);
        SidecarInterface sidecar = getSidecarInterface(configHandlingActivity);
        assertThat(sidecar).isNotNull();
        IBinder configHandlingActivityWindowToken = getActivityWindowToken(configHandlingActivity);
        assertThat(configHandlingActivityWindowToken).isNotNull();

        setActivityOrientationActivityHandlesOrientationChanges(configHandlingActivity,
                ORIENTATION_PORTRAIT);
        SidecarWindowLayoutInfo portraitWindowLayoutInfo =
                sidecar.getWindowLayoutInfo(configHandlingActivityWindowToken);
        final Rect portraitBounds = getActivityBounds(configHandlingActivity);
        final Rect portraitMaximumBounds = getMaximumActivityBounds(configHandlingActivity);

        setActivityOrientationActivityHandlesOrientationChanges(configHandlingActivity,
                ORIENTATION_LANDSCAPE);
        SidecarWindowLayoutInfo landscapeWindowLayoutInfo =
                sidecar.getWindowLayoutInfo(configHandlingActivityWindowToken);
        final Rect landscapeBounds = getActivityBounds(configHandlingActivity);
        final Rect landscapeMaximumBounds = getMaximumActivityBounds(configHandlingActivity);

        final boolean doesDisplayRotateForOrientation = doesDisplayRotateForOrientation(
                portraitMaximumBounds, landscapeMaximumBounds);
        assertEqualWindowLayoutInfo(portraitWindowLayoutInfo, landscapeWindowLayoutInfo,
                portraitBounds, landscapeBounds, doesDisplayRotateForOrientation);
    }

    @Test
    public void testGetWindowLayoutInfo_windowRecreated_windowLayoutUpdates() {
        assumeHasDisplayFeatures(mSidecarInterface, mWindowToken);

        setActivityOrientationActivityDoesNotHandleOrientationChanges(mActivity,
                ORIENTATION_PORTRAIT);
        SidecarWindowLayoutInfo portraitWindowLayoutInfo =
                mSidecarInterface.getWindowLayoutInfo(mWindowToken);
        final Rect portraitBounds = getActivityBounds(mActivity);
        final Rect portraitMaximumBounds = getMaximumActivityBounds(mActivity);

        setActivityOrientationActivityDoesNotHandleOrientationChanges(mActivity,
                ORIENTATION_LANDSCAPE);

        mWindowToken = getActivityWindowToken(mActivity);
        assertThat(mWindowToken).isNotNull();

        SidecarWindowLayoutInfo landscapeWindowLayoutInfo =
                mSidecarInterface.getWindowLayoutInfo(mWindowToken);
        final Rect landscapeBounds = getActivityBounds(mActivity);
        final Rect landscapeMaximumBounds = getMaximumActivityBounds(mActivity);

        final boolean doesDisplayRotateForOrientation = doesDisplayRotateForOrientation(
                portraitMaximumBounds, landscapeMaximumBounds);
        assertEqualWindowLayoutInfo(portraitWindowLayoutInfo, landscapeWindowLayoutInfo,
                portraitBounds, landscapeBounds, doesDisplayRotateForOrientation);
    }
}
