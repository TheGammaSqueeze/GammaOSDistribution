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

package com.android.car.telemetry.sessioncontroller;

import static android.car.hardware.power.CarPowerManager.CarPowerStateListener;

import android.annotation.IntDef;
import android.annotation.NonNull;
import android.car.hardware.power.CarPowerManager;
import android.content.Context;
import android.os.SystemClock;
import android.os.SystemProperties;

import com.android.car.CarLocalServices;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.util.ArrayList;

/**
 * SessionController tracks driving sessions and informs listeners when a session ends or a new
 * session starts. There can be only one ongoing driving session at a time. Definition of a driving
 * session is contained in the implementation of this class.
 */
public class SessionController {
    public static final int STATE_DEFAULT = 0;
    public static final int STATE_EXIT_DRIVING_SESSION = 1;
    public static final int STATE_ENTER_DRIVING_SESSION = 2;
    private static final String SYSTEM_BOOT_REASON = "sys.boot.reason";

    @IntDef(
            prefix = {"STATE_"},
            value = {
                    STATE_DEFAULT,
                    STATE_EXIT_DRIVING_SESSION,
                    STATE_ENTER_DRIVING_SESSION,
            })
    @Retention(RetentionPolicy.SOURCE)
    public @interface SessionControllerState {
    }

    private final Context mContext;
    private final CarPowerManager mCarPowerManager;
    private int mSessionId = 0;
    private int mSessionState = STATE_EXIT_DRIVING_SESSION;
    private long mStateChangedAtMillisSinceBoot; // uses SystemClock.elapsedRealtime();
    private long mStateChangedAtMillis; // unix time
    private String mBootReason;
    private final ArrayList<SessionControllerCallback> mSessionControllerListeners =
            new ArrayList<>();

    /**
     * Clients register {@link SessionControllerCallback} object with SessionController to receive
     * updates whenever a new driving session starts or the ongoing session ends.
     */
    public interface SessionControllerCallback {
        /**
         * {@link SessionController} uses this method to notify listeners that a session state
         * changed and provides additional information in the input.
         *
         * @param annotation Encapsulates all information relevant to session state change in a
         *                   {@link SessionAnnotation} object.
         */
        void onSessionStateChanged(SessionAnnotation annotation);
    }

    public SessionController(Context context) {
        mContext = context;
        mCarPowerManager = CarLocalServices.createCarPowerManager(mContext);
        mCarPowerManager.setListener(mCarPowerStateListener);
    }

    /**
     * Initializes session state in cases when power state is ON by the time boot has completed.
     * In particular, we need to handle a case when the system crashes during a drive.
     * Calling this method after boot will start a new session and it will trigger pulling of data.
     *
     * <p> It must be called each time during instantiation of CarTelemetryService.
     */
    public void initSession() {
        mBootReason = SystemProperties.get(SYSTEM_BOOT_REASON);
        // Read the current power state and handle it.
        mCarPowerStateListener.onStateChanged(mCarPowerManager.getPowerState());
    }

    /**
     * Returns relevant information about current session state. This information will include
     * whether the system is in driving session, when did the session state changed most recently,
     * etc. Please refer to the implementation of {@link SessionAnnotation} class to see what kinds
     * of information will be returned by the method.
     *
     * @return Session information contained in the returned instance of {@link SessionAnnotation}
     * class.
     */
    public SessionAnnotation getSessionAnnotation() {
        return new SessionAnnotation(
                mSessionId, mSessionState, mStateChangedAtMillisSinceBoot, mStateChangedAtMillis,
                mBootReason);
    }

    private void updateSessionState(@SessionControllerState int sessionState) {
        mStateChangedAtMillisSinceBoot = SystemClock.elapsedRealtime();
        mStateChangedAtMillis = System.currentTimeMillis();
        mSessionState = sessionState;
        if (sessionState == STATE_ENTER_DRIVING_SESSION) {
            mSessionId++;
        }
    }

    /**
     * A client uses this method to registers a callback and get informed about session state change
     * when it happens. All session state callback instances handled one at a time on the common
     * telemetry worker thread.
     *
     * @param callback An instance of {@link SessionControllerCallback} implementation.
     */
    public void registerCallback(@NonNull SessionControllerCallback callback) {
        if (!mSessionControllerListeners.contains(callback)) {
            mSessionControllerListeners.add(callback);
        }
    }

    /**
     * Removes provided instance of a listener from the callback list.
     *
     * @param callback An instance of {@link SessionControllerCallback} implementation.
     */
    public void unregisterCallback(@NonNull SessionControllerCallback callback) {
        mSessionControllerListeners.remove(callback);
    }

    private void notifySessionStateChange(@SessionControllerState int newSessionState) {
        if (mSessionState == newSessionState) {
            return;
        }
        updateSessionState(newSessionState);
        SessionAnnotation annotation = getSessionAnnotation();
        for (SessionControllerCallback listener : mSessionControllerListeners) {
            listener.onSessionStateChanged(annotation);
        }
    }

    private final CarPowerStateListener mCarPowerStateListener =
            new CarPowerStateListener() {
                @Override
                public void onStateChanged(int state) {
                    if (state == CarPowerStateListener.SHUTDOWN_PREPARE) {
                        notifySessionStateChange(STATE_EXIT_DRIVING_SESSION);
                    } else if (state == CarPowerStateListener.ON) {
                        notifySessionStateChange(STATE_ENTER_DRIVING_SESSION);
                    }
                }
            };

    /** Gracefully cleans up the class state when the car telemetry service is shutting down. */
    public void release() {
        mCarPowerManager.clearListener();
    }
}
