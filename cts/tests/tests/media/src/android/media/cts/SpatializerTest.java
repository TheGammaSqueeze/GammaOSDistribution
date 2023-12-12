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

package android.media.cts;

import static org.junit.Assert.assertThrows;

import android.annotation.NonNull;
import android.content.Context;
import android.media.AudioAttributes;
import android.media.AudioDeviceAttributes;
import android.media.AudioDeviceInfo;
import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.Spatializer;
import android.util.Log;

import com.android.compatibility.common.util.CtsAndroidTestCase;
import com.android.internal.annotations.GuardedBy;

import org.junit.Assert;

import java.util.Arrays;
import java.util.List;
import java.util.concurrent.Executors;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.TimeUnit;

@NonMediaMainlineTest
public class SpatializerTest extends CtsAndroidTestCase {

    private AudioManager mAudioManager;
    private static final String TAG = "SpatializerTest";
    private static final int LISTENER_WAIT_TIMEOUT_MS = 3000;

    @Override
    protected void setUp() throws Exception {
        super.setUp();
        mAudioManager = (AudioManager) getContext().getSystemService(AudioManager.class);
    }

    @Override
    protected void tearDown() throws Exception {
        getInstrumentation().getUiAutomation().dropShellPermissionIdentity();
    }

    public void testGetSpatializer() throws Exception {
        Spatializer spat = mAudioManager.getSpatializer();
        assertNotNull("Spatializer shouldn't be null", spat);
    }

    public void testUnsupported() throws Exception {
        Spatializer spat = mAudioManager.getSpatializer();
        if (spat.getImmersiveAudioLevel() != Spatializer.SPATIALIZER_IMMERSIVE_LEVEL_NONE) {
            Log.i(TAG, "skipping testUnsupported, functionality supported");
            return;
        }
        assertFalse(spat.isEnabled());
        assertFalse(spat.isAvailable());
    }

    public void testSupportedDevices() throws Exception {
        Spatializer spat = mAudioManager.getSpatializer();
        if (spat.getImmersiveAudioLevel() == Spatializer.SPATIALIZER_IMMERSIVE_LEVEL_NONE) {
            Log.i(TAG, "skipping testSupportedDevices, functionality unsupported");
            return;
        }

        final AudioDeviceAttributes device = new AudioDeviceAttributes(
                AudioDeviceAttributes.ROLE_OUTPUT, AudioDeviceInfo.TYPE_BLUETOOTH_A2DP, "bla");
        // try to add/remove compatible device without permission, expect failure
        assertThrows("Able to call addCompatibleAudioDevice without permission",
                SecurityException.class,
                () -> spat.addCompatibleAudioDevice(device));
        assertThrows("Able to call removeCompatibleAudioDevice without permission",
                SecurityException.class,
                () -> spat.removeCompatibleAudioDevice(device));
        assertThrows("Able to call getCompatibleAudioDevice without permission",
                SecurityException.class,
                () -> spat.getCompatibleAudioDevices());

        // try again with permission, then add a device and remove it
        getInstrumentation().getUiAutomation()
                .adoptShellPermissionIdentity("android.permission.MODIFY_DEFAULT_AUDIO_EFFECTS");
        spat.addCompatibleAudioDevice(device);
        List<AudioDeviceAttributes> compatDevices = spat.getCompatibleAudioDevices();
        assertTrue("added device not in list of compatible devices",
                compatDevices.contains(device));
        spat.removeCompatibleAudioDevice(device);
        compatDevices = spat.getCompatibleAudioDevices();
        assertFalse("removed device still in list of compatible devices",
                compatDevices.contains(device));

        getInstrumentation().getUiAutomation().dropShellPermissionIdentity();
    }

    public void testHeadTrackingListener() throws Exception {
        Spatializer spat = mAudioManager.getSpatializer();
        if (spat.getImmersiveAudioLevel() == Spatializer.SPATIALIZER_IMMERSIVE_LEVEL_NONE) {
            Log.i(TAG, "skipping testHeadTrackingListener, functionality unsupported");
            return;
        }

        // try to call any head tracking method without permission
        assertThrows("Able to call getHeadTrackingMode without permission",
                SecurityException.class,
                () -> spat.getHeadTrackingMode());
        assertThrows("Able to call getDesiredHeadTrackingMode without permission",
                SecurityException.class,
                () -> spat.getDesiredHeadTrackingMode());
        assertThrows("Able to call getSupportedHeadTrackingModes without permission",
                SecurityException.class,
                () -> spat.getSupportedHeadTrackingModes());
        assertThrows("Able to call setDesiredHeadTrackingMode without permission",
                SecurityException.class,
                () -> spat.setDesiredHeadTrackingMode(
                        Spatializer.HEAD_TRACKING_MODE_RELATIVE_DEVICE));
        final MyHeadTrackingModeListener listener = new MyHeadTrackingModeListener();
        assertThrows("Able to call addOnHeadTrackingModeChangedListener without permission",
                SecurityException.class,
                () -> spat.addOnHeadTrackingModeChangedListener(Executors.newSingleThreadExecutor(),
                        listener));
        assertThrows("Able to call removeOnHeadTrackingModeChangedListener without permission",
                SecurityException.class,
                () -> spat.removeOnHeadTrackingModeChangedListener(listener));

        getInstrumentation().getUiAutomation()
                .adoptShellPermissionIdentity("android.permission.MODIFY_DEFAULT_AUDIO_EFFECTS");

        // argument validation
        assertThrows("Able to call addOnHeadTrackingModeChangedListener with null Executor",
                NullPointerException.class,
                () -> spat.addOnHeadTrackingModeChangedListener(null, listener));
        assertThrows("Able to call addOnHeadTrackingModeChangedListener with null listener",
                NullPointerException.class,
                () -> spat.addOnHeadTrackingModeChangedListener(Executors.newSingleThreadExecutor(),
                        null));
        assertThrows("Able to call removeOnHeadTrackingModeChangedListener with null listener",
                NullPointerException.class,
                () -> spat.removeOnHeadTrackingModeChangedListener(null));

        // test of functionality
        spat.setEnabled(true);
        List<Integer> supportedModes = spat.getSupportedHeadTrackingModes();
        Assert.assertNotNull("Invalid null list of tracking modes", supportedModes);
        Log.i(TAG, "Reported supported head tracking modes:"+ supportedModes);
        if (!supportedModes.contains(Spatializer.HEAD_TRACKING_MODE_RELATIVE_DEVICE)
                && !supportedModes.contains(Spatializer.HEAD_TRACKING_MODE_RELATIVE_WORLD)
                && !supportedModes.contains(Spatializer.HEAD_TRACKING_MODE_OTHER)) {
            // no head tracking is supported, verify it is correctly reported by the API
            assertEquals("When no head tracking mode supported, list of modes must be empty",
                    0, supportedModes.size());
            // TODO: to be enforced
            //assertEquals("Invalid mode when no head tracking mode supported",
            //        Spatializer.HEAD_TRACKING_MODE_UNSUPPORTED, spat.getHeadTrackingMode());
            Log.i(TAG, "no headtracking modes supported, stop test");
            return;
        }
        int trackingModeToUse;
        if (supportedModes.contains(Spatializer.HEAD_TRACKING_MODE_RELATIVE_DEVICE)) {
            trackingModeToUse = Spatializer.HEAD_TRACKING_MODE_RELATIVE_DEVICE;
        } else {
            trackingModeToUse = Spatializer.HEAD_TRACKING_MODE_RELATIVE_WORLD;
        }
        spat.setDesiredHeadTrackingMode(Spatializer.HEAD_TRACKING_MODE_DISABLED);
        spat.addOnHeadTrackingModeChangedListener(Executors.newSingleThreadExecutor(), listener);
        spat.setDesiredHeadTrackingMode(trackingModeToUse);
        Integer observedDesired = listener.getDesired();
        assertNotNull("No desired head tracking mode change reported", observedDesired);
        assertEquals("Wrong reported desired tracking mode", trackingModeToUse,
                observedDesired.intValue());
        assertEquals("Set desired mode not returned by getter", spat.getDesiredHeadTrackingMode(),
                trackingModeToUse);
        final int actualMode = spat.getHeadTrackingMode();
        // not failing test if modes differ, just logging
        if (trackingModeToUse != actualMode) {
            Log.i(TAG, "head tracking mode desired:" + trackingModeToUse + " actual mode:"
                    + actualMode);
        }
        spat.removeOnHeadTrackingModeChangedListener(listener);
    }

    public void testSpatializerOutput() throws Exception {
        Spatializer spat = mAudioManager.getSpatializer();
        if (spat.getImmersiveAudioLevel() == Spatializer.SPATIALIZER_IMMERSIVE_LEVEL_NONE) {
            Log.i(TAG, "skipping testSpatializerOutput, functionality unsupported");
            return;
        }

        // try to call any output method without permission
        assertThrows("Able to call getOutput without permission",
                SecurityException.class,
                () -> spat.getOutput());
        final MyOutputChangedListener listener = new MyOutputChangedListener();
        assertThrows("Able to call setOnSpatializerOutputChangedListener without permission",
                SecurityException.class,
                () -> spat.setOnSpatializerOutputChangedListener(
                        Executors.newSingleThreadExecutor(), listener));
        assertThrows("Able to call clearOnSpatializerOutputChangedListener with no listener",
                SecurityException.class,
                () -> spat.clearOnSpatializerOutputChangedListener());

        getInstrumentation().getUiAutomation()
                .adoptShellPermissionIdentity("android.permission.MODIFY_DEFAULT_AUDIO_EFFECTS");

        // argument validation
        assertThrows("Able to call setOnSpatializerOutputChangedListener with null Executor",
                NullPointerException.class,
                () -> spat.setOnSpatializerOutputChangedListener(null, listener));
        assertThrows("Able to call setOnSpatializerOutputChangedListener with null listener",
                NullPointerException.class,
                () -> spat.setOnSpatializerOutputChangedListener(
                        Executors.newSingleThreadExecutor(), null));

        spat.getOutput();
        // output doesn't change upon playback, so at this point only exercising
        // registering / clearing of output listener under permission
        spat.clearOnSpatializerOutputChangedListener(); // this is to clear the client listener ref
        spat.setOnSpatializerOutputChangedListener(Executors.newSingleThreadExecutor(), listener);
        spat.clearOnSpatializerOutputChangedListener();
        assertThrows("Able to call clearOnSpatializerOutputChangedListener with no listener",
                IllegalStateException.class,
                () -> spat.clearOnSpatializerOutputChangedListener());
    }

    public void testExercisePose() throws Exception {
        Spatializer spat = mAudioManager.getSpatializer();
        if (spat.getImmersiveAudioLevel() == Spatializer.SPATIALIZER_IMMERSIVE_LEVEL_NONE) {
            Log.i(TAG, "skipping testExercisePose, functionality unsupported");
            return;
        }

        // argument validation
        assertThrows("Able to call setGlobalTransform without a 6-float array",
                IllegalArgumentException.class,
                () -> spat.setGlobalTransform(new float[5]));
        assertThrows("Able to call setGlobalTransform without a null array",
                NullPointerException.class,
                () -> spat.setGlobalTransform(null));
        final MyPoseUpdatedListener listener = new MyPoseUpdatedListener();
        assertThrows("Able to call setOnHeadToSoundstagePoseUpdatedListener with null Executor",
                NullPointerException.class,
                () -> spat.setOnHeadToSoundstagePoseUpdatedListener(null, listener));
        assertThrows("Able to call setOnHeadToSoundstagePoseUpdatedListener with null listener",
                NullPointerException.class,
                () -> spat.setOnHeadToSoundstagePoseUpdatedListener(
                        Executors.newSingleThreadExecutor(), null));
        assertThrows("Able to call clearOnHeadToSoundstagePoseUpdatedListener with no listener",
                IllegalStateException.class,
                () -> spat.clearOnHeadToSoundstagePoseUpdatedListener());

        getInstrumentation().getUiAutomation()
                .adoptShellPermissionIdentity("android.permission.MODIFY_DEFAULT_AUDIO_EFFECTS");
        // TODO once headtracking is properly reported: check pose changes on recenter and transform
        spat.setOnHeadToSoundstagePoseUpdatedListener(
                Executors.newSingleThreadExecutor(), listener);
        // oneway call from client to AudioService, can't check for exception earlier
        spat.recenterHeadTracker();
        // oneway call from client to AudioService, can't check for exception earler
        spat.setGlobalTransform(new float[6]);
        spat.clearOnHeadToSoundstagePoseUpdatedListener();
    }

    public void testEffectParameters() throws Exception {
        Spatializer spat = mAudioManager.getSpatializer();
        if (spat.getImmersiveAudioLevel() == Spatializer.SPATIALIZER_IMMERSIVE_LEVEL_NONE) {
            Log.i(TAG, "skipping testEffectParameters, functionality unsupported");
            return;
        }

        // argument validation
        assertThrows("Able to call setEffectParameter with null value",
                NullPointerException.class,
                () -> spat.setEffectParameter(0, null));
        assertThrows("Able to call getEffectParameter with null value",
                NullPointerException.class,
                () -> spat.getEffectParameter(0, null));

        // permission check
        byte[] val = new byte[4];
        assertThrows("Able to call setEffectParameter without permission",
                SecurityException.class,
                () -> spat.setEffectParameter(0, val));
        assertThrows("Able to call getEffectParameter without permission",
                SecurityException.class,
                () -> spat.getEffectParameter(0, val));
    }

    public void testSpatializerStateListenerManagement() throws Exception {
        final Spatializer spat = mAudioManager.getSpatializer();
        final MySpatStateListener stateListener = new MySpatStateListener();

        // add listener:
        // verify null arg checks
        assertThrows("null Executor allowed in addOnSpatializerStateChangedListener",
                NullPointerException.class,
                () -> spat.addOnSpatializerStateChangedListener(null, stateListener));
        assertThrows("null listener allowed in addOnSpatializerStateChangedListener",
                NullPointerException.class,
                () -> spat.addOnSpatializerStateChangedListener(
                        Executors.newSingleThreadExecutor(),null));

        spat.addOnSpatializerStateChangedListener(Executors.newSingleThreadExecutor(),
                stateListener);
        // verify double add
        assertThrows("duplicate listener allowed in addOnSpatializerStateChangedListener",
                IllegalArgumentException.class,
                () -> spat.addOnSpatializerStateChangedListener(Executors.newSingleThreadExecutor(),
                        stateListener));

        // remove listener:
        // verify null arg check
        assertThrows("null listener allowed in removeOnSpatializerStateChangedListener",
                NullPointerException.class,
                () -> spat.removeOnSpatializerStateChangedListener(null));

        // verify unregistered listener
        assertThrows("unregistered listener allowed in removeOnSpatializerStateChangedListener",
                IllegalArgumentException.class,
                () -> spat.removeOnSpatializerStateChangedListener(new MySpatStateListener()));

        spat.removeOnSpatializerStateChangedListener(stateListener);
        // verify double remove
        assertThrows("double listener removal allowed in removeOnSpatializerStateChangedListener",
                IllegalArgumentException.class,
                () -> spat.removeOnSpatializerStateChangedListener(stateListener));
    }

    public void testMinSpatializationCapabilities() throws Exception {
        Spatializer spat = mAudioManager.getSpatializer();
        if (spat.getImmersiveAudioLevel() == Spatializer.SPATIALIZER_IMMERSIVE_LEVEL_NONE) {
            Log.i(TAG, "skipping testMinSpatializationCapabilities, no Spatializer");
            return;
        }
        if (!spat.isAvailable()) {
            Log.i(TAG, "skipping testMinSpatializationCapabilities, Spatializer not available");
            return;
        }
        for (int sampleRate : new int[] { 44100, 4800 }) {
            AudioFormat minFormat = new AudioFormat.Builder()
                    .setSampleRate(sampleRate)
                    .setChannelMask(AudioFormat.CHANNEL_OUT_5POINT1)
                    .setEncoding(AudioFormat.ENCODING_PCM_16BIT)
                    .build();
            for (int usage : new int[] { AudioAttributes.USAGE_MEDIA,
                                         AudioAttributes.USAGE_GAME}) {
                AudioAttributes defAttr = new AudioAttributes.Builder()
                        .setUsage(usage)
                        .build();
                assertTrue("AudioAttributes usage:" + usage + " at " + sampleRate
                        + " should be virtualizeable", spat.canBeSpatialized(defAttr, minFormat));
            }
        }
    }

    public void testVirtualizerEnabled() throws Exception {
        Spatializer spat = mAudioManager.getSpatializer();
        if (spat.getImmersiveAudioLevel() == Spatializer.SPATIALIZER_IMMERSIVE_LEVEL_NONE) {
            Log.i(TAG, "skipping testVirtualizerEnabled, no Spatializer");
            return;
        }
        boolean spatEnabled = spat.isEnabled();
        final MySpatStateListener stateListener = new MySpatStateListener();

        spat.addOnSpatializerStateChangedListener(Executors.newSingleThreadExecutor(),
                stateListener);
        getInstrumentation().getUiAutomation()
                .adoptShellPermissionIdentity("android.permission.MODIFY_DEFAULT_AUDIO_EFFECTS");
        spat.setEnabled(!spatEnabled);
        getInstrumentation().getUiAutomation().dropShellPermissionIdentity();
        assertEquals("VirtualizerStage enabled state differ",
                !spatEnabled, spat.isEnabled());
        Boolean enabled = stateListener.getEnabled();
        assertNotNull("VirtualizerStage state listener wasn't called", enabled);
        assertEquals("VirtualizerStage state listener didn't get expected value",
                !spatEnabled, enabled.booleanValue());
    }

    static class MySpatStateListener
            implements Spatializer.OnSpatializerStateChangedListener {

        private final LinkedBlockingQueue<Boolean> mEnabledQueue =
                new LinkedBlockingQueue<Boolean>(1);

        void reset() {
            mEnabledQueue.clear();
        }

        Boolean getEnabled() throws Exception {
            return mEnabledQueue.poll(LISTENER_WAIT_TIMEOUT_MS, TimeUnit.MILLISECONDS);
        }

        MySpatStateListener() {
            reset();
        }

        @Override
        public void onSpatializerEnabledChanged(Spatializer spat, boolean enabled) {
            Log.i(TAG, "onSpatializerEnabledChanged:" + enabled);
            mEnabledQueue.offer(enabled);
        }

        @Override
        public void onSpatializerAvailableChanged(@NonNull Spatializer spat, boolean available) {
            Log.i(TAG, "onSpatializerAvailableChanged:" + available);
        }
    }

    static class MyHeadTrackingModeListener implements Spatializer.OnHeadTrackingModeChangedListener
    {
        private final LinkedBlockingQueue<Integer> mDesiredQueue =
                new LinkedBlockingQueue<Integer>(1);
        private final LinkedBlockingQueue<Integer> mRealQueue =
                new LinkedBlockingQueue<Integer>(1);

        @Override
        public void onHeadTrackingModeChanged(Spatializer spatializer, int mode) {
            Log.i(TAG, "onHeadTrackingModeChanged:" + mode);
            mRealQueue.offer(mode);
        }

        @Override
        public void onDesiredHeadTrackingModeChanged(Spatializer spatializer, int mode) {
            Log.i(TAG, "onDesiredHeadTrackingModeChanged:" + mode);
            mDesiredQueue.offer(mode);
        }

        public Integer getDesired() throws Exception {
            return mDesiredQueue.poll(LISTENER_WAIT_TIMEOUT_MS, TimeUnit.MILLISECONDS);
        }
    }

    static class MyOutputChangedListener implements Spatializer.OnSpatializerOutputChangedListener
    {
        @Override
        public void onSpatializerOutputChanged(Spatializer spatializer, int output) {
            Log.i(TAG, "onSpatializerOutputChanged:" + output);
        }
    }

    static class MyPoseUpdatedListener implements Spatializer.OnHeadToSoundstagePoseUpdatedListener
    {
        @Override
        public void onHeadToSoundstagePoseUpdated(Spatializer spatializer, float[] pose) {
            Log.i(TAG, "onHeadToSoundstagePoseUpdated:" + Arrays.toString(pose));
        }
    }
}
