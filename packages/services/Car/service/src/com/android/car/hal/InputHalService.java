/*
 * Copyright (C) 2016 The Android Open Source Project
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
package com.android.car.hal;

import static android.car.CarOccupantZoneManager.DisplayTypeEnum;
import static android.hardware.automotive.vehicle.V2_0.RotaryInputType.ROTARY_INPUT_TYPE_AUDIO_VOLUME;
import static android.hardware.automotive.vehicle.V2_0.RotaryInputType.ROTARY_INPUT_TYPE_SYSTEM_NAVIGATION;
import static android.hardware.automotive.vehicle.V2_0.VehicleProperty.HW_CUSTOM_INPUT;
import static android.hardware.automotive.vehicle.V2_0.VehicleProperty.HW_KEY_INPUT;
import static android.hardware.automotive.vehicle.V2_0.VehicleProperty.HW_ROTARY_INPUT;

import static com.android.car.internal.ExcludeFromCodeCoverageGeneratedReport.DUMP_INFO;

import android.car.CarOccupantZoneManager;
import android.car.input.CarInputManager;
import android.car.input.CustomInputEvent;
import android.car.input.RotaryEvent;
import android.hardware.automotive.vehicle.V2_0.VehicleDisplay;
import android.hardware.automotive.vehicle.V2_0.VehicleHwKeyInputAction;
import android.hardware.automotive.vehicle.V2_0.VehiclePropConfig;
import android.hardware.automotive.vehicle.V2_0.VehiclePropValue;
import android.os.SystemClock;
import android.util.SparseArray;
import android.view.InputDevice;
import android.view.KeyEvent;

import com.android.car.CarLog;
import com.android.car.CarServiceUtils;
import com.android.car.internal.ExcludeFromCodeCoverageGeneratedReport;
import com.android.internal.annotations.GuardedBy;
import com.android.internal.annotations.VisibleForTesting;
import com.android.server.utils.Slogf;

import java.io.PrintWriter;
import java.util.Collection;
import java.util.List;
import java.util.concurrent.TimeUnit;
import java.util.function.LongSupplier;

/**
 * Translates HAL input events to higher-level semantic information.
 */
public class InputHalService extends HalServiceBase {

    private static final String TAG = CarLog.TAG_INPUT;

    private static final int[] SUPPORTED_PROPERTIES = new int[] {
            HW_KEY_INPUT,
            HW_ROTARY_INPUT,
            HW_CUSTOM_INPUT
    };

    private final VehicleHal mHal;

    /**
     * A function to retrieve the current system uptime in milliseconds - replaceable for testing.
     */
    private final LongSupplier mUptimeSupplier;

    /**
     * Interface used to act upon HAL incoming key events.
     */
    public interface InputListener {
        /** Called for key event */
        void onKeyEvent(KeyEvent event, int targetDisplay);
        /** Called for rotary event */
        void onRotaryEvent(RotaryEvent event, int targetDisplay);
        /** Called for OEM custom input event */
        void onCustomInputEvent(CustomInputEvent event);
    }

    /** The current press state of a key. */
    private static class KeyState {
        /** The timestamp (uptimeMillis) of the last ACTION_DOWN event for this key. */
        public long mLastKeyDownTimestamp = -1;
        /** The number of ACTION_DOWN events that have been sent for this keypress. */
        public int mRepeatCount = 0;
    }

    private final Object mLock = new Object();

    @GuardedBy("mLock")
    private boolean mKeyInputSupported;

    @GuardedBy("mLock")
    private boolean mRotaryInputSupported;

    @GuardedBy("mLock")
    private boolean mCustomInputSupported;

    @GuardedBy("mLock")
    private InputListener mListener;

    @GuardedBy("mKeyStates")
    private final SparseArray<KeyState> mKeyStates = new SparseArray<>();

    public InputHalService(VehicleHal hal) {
        this(hal, SystemClock::uptimeMillis);
    }

    @VisibleForTesting
    InputHalService(VehicleHal hal, LongSupplier uptimeSupplier) {
        mHal = hal;
        mUptimeSupplier = uptimeSupplier;
    }

    /**
     * Sets the input event listener.
     */
    public void setInputListener(InputListener listener) {
        boolean keyInputSupported;
        boolean rotaryInputSupported;
        boolean customInputSupported;
        synchronized (mLock) {
            if (!mKeyInputSupported && !mRotaryInputSupported && !mCustomInputSupported) {
                Slogf.w(TAG, "input listener set while rotary and key input not supported");
                return;
            }
            mListener = listener;
            keyInputSupported = mKeyInputSupported;
            rotaryInputSupported = mRotaryInputSupported;
            customInputSupported = mCustomInputSupported;
        }
        if (keyInputSupported) {
            mHal.subscribeProperty(this, HW_KEY_INPUT);
        }
        if (rotaryInputSupported) {
            mHal.subscribeProperty(this, HW_ROTARY_INPUT);
        }
        if (customInputSupported) {
            mHal.subscribeProperty(this, HW_CUSTOM_INPUT);
        }
    }

    /** Returns whether {@code HW_KEY_INPUT} is supported. */
    public boolean isKeyInputSupported() {
        synchronized (mLock) {
            return mKeyInputSupported;
        }
    }

    /** Returns whether {@code HW_ROTARY_INPUT} is supported. */
    public boolean isRotaryInputSupported() {
        synchronized (mLock) {
            return mRotaryInputSupported;
        }
    }

    /** Returns whether {@code HW_CUSTOM_INPUT} is supported. */
    public boolean isCustomInputSupported() {
        synchronized (mLock) {
            return mCustomInputSupported;
        }
    }

    @Override
    public void init() {
    }

    @Override
    public void release() {
        synchronized (mLock) {
            mListener = null;
            mKeyInputSupported = false;
            mRotaryInputSupported = false;
            mCustomInputSupported = false;
        }
    }

    @Override
    public int[] getAllSupportedProperties() {
        return SUPPORTED_PROPERTIES;
    }

    @Override
    public void takeProperties(Collection<VehiclePropConfig> properties) {
        for (VehiclePropConfig property : properties) {
            switch (property.prop) {
                case HW_KEY_INPUT:
                    synchronized (mLock) {
                        mKeyInputSupported = true;
                    }
                    break;
                case HW_ROTARY_INPUT:
                    synchronized (mLock) {
                        mRotaryInputSupported = true;
                    }
                    break;
                case HW_CUSTOM_INPUT:
                    synchronized (mLock) {
                        mCustomInputSupported = true;
                    }
                    break;
            }
        }
    }

    @Override
    public void onHalEvents(List<VehiclePropValue> values) {
        InputListener listener;
        synchronized (mLock) {
            listener = mListener;
        }
        if (listener == null) {
            Slogf.w(TAG, "Input event while listener is null");
            return;
        }
        for (VehiclePropValue value : values) {
            switch (value.prop) {
                case HW_KEY_INPUT:
                    dispatchKeyInput(listener, value);
                    break;
                case HW_ROTARY_INPUT:
                    dispatchRotaryInput(listener, value);
                    break;
                case HW_CUSTOM_INPUT:
                    dispatchCustomInput(listener, value);
                    break;
                default:
                    Slogf.e(TAG, "Wrong event dispatched, prop:0x%x", value.prop);
                    break;
            }
        }
    }

    private void dispatchKeyInput(InputListener listener, VehiclePropValue value) {
        int action = (value.value.int32Values.get(0) == VehicleHwKeyInputAction.ACTION_DOWN)
                ? KeyEvent.ACTION_DOWN
                : KeyEvent.ACTION_UP;
        int code = value.value.int32Values.get(1);
        int vehicleDisplay = value.value.int32Values.get(2);
        int indentsCount = value.value.int32Values.size() < 4 ? 1 : value.value.int32Values.get(3);
        Slogf.d(TAG, "hal event code: %d, action: %d, display: %d, number of indents: %d",
                code, action, vehicleDisplay, indentsCount);
        while (indentsCount > 0) {
            indentsCount--;
            dispatchKeyEvent(listener, action, code, convertDisplayType(vehicleDisplay));
        }
    }

    private void dispatchRotaryInput(InputListener listener, VehiclePropValue value) {
        int timeValuesIndex = 3;  // remaining values are time deltas in nanoseconds
        if (value.value.int32Values.size() < timeValuesIndex) {
            Slogf.e(TAG, "Wrong int32 array size for RotaryInput from vhal: %d",
                    value.value.int32Values.size());
            return;
        }
        int rotaryInputType = value.value.int32Values.get(0);
        int detentCount = value.value.int32Values.get(1);
        int vehicleDisplay = value.value.int32Values.get(2);
        long timestamp = value.timestamp;  // for first detent, uptime nanoseconds
        Slogf.d(TAG, "hal rotary input type: %d, number of detents: %d, display: %d",
                rotaryInputType, detentCount, vehicleDisplay);
        boolean clockwise = detentCount > 0;
        detentCount = Math.abs(detentCount);
        if (detentCount == 0) { // at least there should be one event
            Slogf.e(TAG, "Zero detentCount from vhal, ignore the event");
            return;
        }
        if (vehicleDisplay != VehicleDisplay.MAIN
                && vehicleDisplay != VehicleDisplay.INSTRUMENT_CLUSTER) {
            Slogf.e(TAG, "Wrong display type for RotaryInput from vhal: %d",
                    vehicleDisplay);
            return;
        }
        if (value.value.int32Values.size() != (timeValuesIndex + detentCount - 1)) {
            Slogf.e(TAG, "Wrong int32 array size for RotaryInput from vhal: %d",
                    value.value.int32Values.size());
            return;
        }
        int carInputManagerType;
        switch (rotaryInputType) {
            case ROTARY_INPUT_TYPE_SYSTEM_NAVIGATION:
                carInputManagerType = CarInputManager.INPUT_TYPE_ROTARY_NAVIGATION;
                break;
            case ROTARY_INPUT_TYPE_AUDIO_VOLUME:
                carInputManagerType = CarInputManager.INPUT_TYPE_ROTARY_VOLUME;
                break;
            default:
                Slogf.e(TAG, "Unknown rotary input type: %d", rotaryInputType);
                return;
        }

        long[] timestamps = new long[detentCount];
        // vhal returns elapsed time while rotary event is using uptime to be in line with KeyEvent.
        long uptimeToElapsedTimeDelta = CarServiceUtils.getUptimeToElapsedTimeDeltaInMillis();
        long startUptime = TimeUnit.NANOSECONDS.toMillis(timestamp) - uptimeToElapsedTimeDelta;
        timestamps[0] = startUptime;
        for (int i = 0; i < timestamps.length - 1; i++) {
            timestamps[i + 1] = timestamps[i] + TimeUnit.NANOSECONDS.toMillis(
                    value.value.int32Values.get(timeValuesIndex + i));
        }
        RotaryEvent event = new RotaryEvent(carInputManagerType, clockwise, timestamps);
        listener.onRotaryEvent(event, convertDisplayType(vehicleDisplay));
    }

    /**
     * Dispatches a KeyEvent using {@link #mUptimeSupplier} for the event time.
     *
     * @param listener listener to dispatch the event to
     * @param action action for the KeyEvent
     * @param code keycode for the KeyEvent
     * @param display target display the event is associated with
     */
    private void dispatchKeyEvent(InputListener listener, int action, int code,
            @DisplayTypeEnum int display) {
        dispatchKeyEvent(listener, action, code, display, mUptimeSupplier.getAsLong());
    }

    /**
     * Dispatches a KeyEvent.
     *
     * @param listener listener to dispatch the event to
     * @param action action for the KeyEvent
     * @param code keycode for the KeyEvent
     * @param display target display the event is associated with
     * @param eventTime uptime in milliseconds when the event occurred
     */
    private void dispatchKeyEvent(InputListener listener, int action, int code,
            @DisplayTypeEnum int display, long eventTime) {
        long downTime;
        int repeat;

        synchronized (mKeyStates) {
            KeyState state = mKeyStates.get(code);
            if (state == null) {
                state = new KeyState();
                mKeyStates.put(code, state);
            }

            if (action == KeyEvent.ACTION_DOWN) {
                downTime = eventTime;
                repeat = state.mRepeatCount++;
                state.mLastKeyDownTimestamp = eventTime;
            } else {
                // Handle key up events without any matching down event by setting the down time to
                // the event time. This shouldn't happen in practice - keys should be pressed
                // before they can be released! - but this protects us against HAL weirdness.
                downTime =
                        (state.mLastKeyDownTimestamp == -1)
                                ? eventTime
                                : state.mLastKeyDownTimestamp;
                repeat = 0;
                state.mRepeatCount = 0;
            }
        }

        KeyEvent event = new KeyEvent(
                downTime,
                eventTime,
                action,
                code,
                repeat,
                0 /* deviceId */,
                0 /* scancode */,
                0 /* flags */,
                InputDevice.SOURCE_CLASS_BUTTON);

        // event.displayId will be set in CarInputService#onKeyEvent
        listener.onKeyEvent(event, display);
    }

    private void dispatchCustomInput(InputListener listener, VehiclePropValue value) {
        Slogf.d(TAG, "Dispatching CustomInputEvent for listener: %s and value: %s",
                listener, value);
        int inputCode;
        int targetDisplayType;
        int repeatCounter;
        try {
            inputCode = value.value.int32Values.get(0);
            targetDisplayType = convertDisplayType(value.value.int32Values.get(1));
            repeatCounter = value.value.int32Values.get(2);
        } catch (IndexOutOfBoundsException e) {
            Slogf.e(TAG, "Invalid hal custom input event received", e);
            return;
        }
        CustomInputEvent event = new CustomInputEvent(inputCode, targetDisplayType, repeatCounter);
        listener.onCustomInputEvent(event);
    }

    /**
     * Converts the vehicle display type ({@link VehicleDisplay#MAIN} and
     * {@link VehicleDisplay#INSTRUMENT_CLUSTER}) to their corresponding types in
     * {@link CarOccupantZoneManager} ({@link CarOccupantZoneManager#DISPLAY_TYPE_MAIN} and
     * {@link CarOccupantZoneManager#DISPLAY_TYPE_INSTRUMENT_CLUSTER}).
     *
     * @param vehicleDisplayType the vehicle display type
     * @return the corresponding display type (defined in {@link CarOccupantZoneManager}) or
     * {@link CarOccupantZoneManager#DISPLAY_TYPE_UNKNOWN} if the value passed as parameter doesn't
     * correspond to a driver's display type
     *
     * @hide
     */
    @DisplayTypeEnum
    public static int convertDisplayType(int vehicleDisplayType) {
        switch (vehicleDisplayType) {
            case VehicleDisplay.MAIN:
                return CarOccupantZoneManager.DISPLAY_TYPE_MAIN;
            case VehicleDisplay.INSTRUMENT_CLUSTER:
                return CarOccupantZoneManager.DISPLAY_TYPE_INSTRUMENT_CLUSTER;
            default:
                return CarOccupantZoneManager.DISPLAY_TYPE_UNKNOWN;
        }
    }

    @Override
    @ExcludeFromCodeCoverageGeneratedReport(reason = DUMP_INFO)
    public void dump(PrintWriter writer) {
        writer.println("*Input HAL*");
        writer.println("mKeyInputSupported:" + mKeyInputSupported);
        writer.println("mRotaryInputSupported:" + mRotaryInputSupported);
    }
}
