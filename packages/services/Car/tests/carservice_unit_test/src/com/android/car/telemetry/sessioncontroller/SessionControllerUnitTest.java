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

import static com.android.dx.mockito.inline.extended.ExtendedMockito.doNothing;
import static com.android.dx.mockito.inline.extended.ExtendedMockito.doReturn;

import static com.google.common.truth.Truth.assertThat;
import static com.google.common.truth.Truth.assertWithMessage;

import static org.mockito.Mockito.verify;

import android.car.AbstractExtendedMockitoCarServiceTestCase;
import android.car.hardware.power.CarPowerManager;
import android.content.Context;

import com.android.car.CarLocalServices;
import com.android.car.power.CarPowerManagementService;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.ArgumentCaptor;
import org.mockito.Captor;
import org.mockito.Mock;
import org.mockito.junit.MockitoJUnitRunner;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;


@RunWith(MockitoJUnitRunner.class)
public class SessionControllerUnitTest
        extends AbstractExtendedMockitoCarServiceTestCase {
    private static final int CALLBACK_TIMEOUT_SEC = 10;

    @Mock
    private Context mMockContext;
    @Mock
    private CarPowerManagementService mMockCarPowerManagementService;
    @Mock
    private CarPowerManager mMockCarPowerManager;
    @Captor
    private ArgumentCaptor<CarPowerStateListener> mPowerStateListenerCaptor;

    private SessionController mSessionController;

    private static final class TestSessionControllerCallback implements
            SessionController.SessionControllerCallback {
        public SessionAnnotation annotation;
        private final CountDownLatch mResponseLatch = new CountDownLatch(1);

        @Override
        public void onSessionStateChanged(SessionAnnotation annotation) {
            this.annotation = annotation;
            mResponseLatch.countDown();
        }

        private boolean awaitResponse(int waitTimeSec) throws InterruptedException {
            return mResponseLatch.await(waitTimeSec, TimeUnit.SECONDS);
        }
    }

    private final TestSessionControllerCallback mCallback = new TestSessionControllerCallback();


    @Override
    protected void onSessionBuilder(CustomMockitoSessionBuilder session) {
        session.spyStatic(CarLocalServices.class);
    }

    @Before
    public void setUp() {
        CarLocalServices.removeServiceForTest(CarPowerManagementService.class);
        CarLocalServices.addService(CarPowerManagementService.class,
                mMockCarPowerManagementService);
        doReturn(mMockCarPowerManager).when(
                () -> CarLocalServices.createCarPowerManager(mMockContext));
        mSessionController = new SessionController(mMockContext);
        verify(mMockCarPowerManager).setListener(mPowerStateListenerCaptor.capture());
        doNothing().when(mMockCarPowerManager).clearListener();
    }

    @After
    public void tearDown() {
        if (mSessionController != null) {
            mSessionController.release();
        }
    }

    @Test
    public void testRegisterCallback_stateChangeTriggersCallback()
            throws InterruptedException {
        mSessionController.registerCallback(mCallback);

        mPowerStateListenerCaptor.getValue().onStateChanged(CarPowerStateListener.ON);

        boolean gotResponse = mCallback.awaitResponse(CALLBACK_TIMEOUT_SEC);
        assertWithMessage("Failed to get the callback method called by SessionController on time")
                .that(gotResponse)
                .isTrue();
        assertThat(mCallback.annotation.sessionState).isEqualTo(
                SessionController.STATE_ENTER_DRIVING_SESSION);
        assertThat(mCallback.annotation.sessionId).isEqualTo(1);
    }

    @Test
    public void testGetSessionAnnotation_sessionOnSessionOffSequence() throws InterruptedException {
        mSessionController.registerCallback(mCallback);

        mPowerStateListenerCaptor.getValue().onStateChanged(CarPowerStateListener.ON);

        boolean gotResponse = mCallback.awaitResponse(CALLBACK_TIMEOUT_SEC);

        assertWithMessage("Failed to get the callback method called by SessionController on time")
                .that(gotResponse)
                .isTrue();
        assertThat(mCallback.annotation.sessionState).isEqualTo(
                SessionController.STATE_ENTER_DRIVING_SESSION);
        int sessionId = mCallback.annotation.sessionId;
        long currentTimeMillis = mCallback.annotation.createdAtMillis;
        long elapsedFromBootMillis = mCallback.annotation.createdAtSinceBootMillis;
        assertThat(sessionId).isEqualTo(1);
        // synchronous getSessionAnnotation() call after state change is expected to return
        // exactly the same annotation.
        assertThat(mSessionController.getSessionAnnotation()).isEqualTo(mCallback.annotation);

        // Emulate power state change
        mPowerStateListenerCaptor.getValue().onStateChanged(CarPowerStateListener.SHUTDOWN_PREPARE);
        gotResponse = mCallback.awaitResponse(CALLBACK_TIMEOUT_SEC);

        assertWithMessage("Failed to get the callback method called by SessionController on time")
                .that(gotResponse)
                .isTrue();

        assertThat(mCallback.annotation.sessionState).isEqualTo(
                SessionController.STATE_EXIT_DRIVING_SESSION);
        // session ID should remain to be the old ID when the session finishes.
        assertThat(mCallback.annotation.sessionId).isEqualTo(sessionId);
        // times should increase compared to when the session turned into ON state.
        assertThat(mCallback.annotation.createdAtSinceBootMillis).isAtLeast(elapsedFromBootMillis);
        assertThat(mCallback.annotation.createdAtMillis).isAtLeast(currentTimeMillis);
        // synchronous annotate call after state change is expected to return exactly the same
        // annotation.
        assertThat(mSessionController.getSessionAnnotation()).isEqualTo(mCallback.annotation);
    }

    @Test
    public void testGetSessionAnnotation_defaultState() {
        SessionAnnotation annotation = mSessionController.getSessionAnnotation();
        assertThat(annotation.sessionState).isEqualTo(SessionController.STATE_EXIT_DRIVING_SESSION);
        assertThat(annotation.sessionId).isEqualTo(0);
        assertThat(annotation.bootReason).isNull();
    }

    @Test
    public void testInitSession_triggersCallback() {
        doReturn(CarPowerStateListener.ON).when(mMockCarPowerManager).getPowerState();
        mSessionController.registerCallback(mCallback);

        mSessionController.initSession();

        assertThat(mCallback.annotation.sessionState).isEqualTo(
                SessionController.STATE_ENTER_DRIVING_SESSION);
    }

    @Test
    public void testGetSessionAnnotation_populatesBootReason() {
        assertThat(mSessionController.getSessionAnnotation().bootReason).isNull();

        mSessionController.initSession();

        // Indirect way of checking that SystemProperties.get(sys.boot.reason) is called because
        // the result of the call is @NonNull.
        assertThat(mSessionController.getSessionAnnotation().bootReason).isNotNull();
    }
}
