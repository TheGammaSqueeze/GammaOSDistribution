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

package com.android.systemui.car.userswitcher;

import static com.google.common.truth.Truth.assertThat;

import static org.mockito.ArgumentMatchers.any;
import static org.mockito.ArgumentMatchers.eq;
import static org.mockito.Mockito.never;
import static org.mockito.Mockito.reset;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

import android.app.ActivityManager;
import android.content.pm.UserInfo;
import android.os.UserManager;
import android.test.suitebuilder.annotation.SmallTest;
import android.testing.AndroidTestingRunner;
import android.testing.TestableLooper;
import android.testing.TestableResources;
import android.view.IWindowManager;
import android.view.LayoutInflater;
import android.view.ViewGroup;
import android.widget.TextView;

import com.android.systemui.R;
import com.android.systemui.SysuiTestCase;
import com.android.systemui.car.CarSystemUiTest;
import com.android.systemui.car.window.OverlayViewGlobalStateController;
import com.android.systemui.util.concurrency.FakeExecutor;
import com.android.systemui.util.time.FakeSystemClock;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;

@CarSystemUiTest
@RunWith(AndroidTestingRunner.class)
@TestableLooper.RunWithLooper
@SmallTest
public class UserSwitchTransitionViewControllerTest extends SysuiTestCase {
    private static final int TEST_USER_1 = 100;
    private static final int TEST_USER_2 = 110;

    private UserSwitchTransitionViewController mCarUserSwitchingDialogController;
    private TestableResources mTestableResources;
    private FakeExecutor mExecutor;
    private FakeSystemClock mClock;
    private ViewGroup mViewGroup;
    @Mock
    private ActivityManager mMockActivityManager;
    @Mock
    private OverlayViewGlobalStateController mOverlayViewGlobalStateController;
    @Mock
    private IWindowManager mWindowManagerService;
    @Mock
    private UserManager mMockUserManager;

    @Before
    public void setUp() {
        MockitoAnnotations.initMocks(this);
        mTestableResources = mContext.getOrCreateTestableResources();
        mExecutor = new FakeExecutor(new FakeSystemClock());
        mCarUserSwitchingDialogController = new UserSwitchTransitionViewController(
                mContext,
                mTestableResources.getResources(),
                mExecutor,
                mMockActivityManager,
                mMockUserManager,
                mWindowManagerService,
                mOverlayViewGlobalStateController
        );

        mockGetUserInfo(TEST_USER_1);
        mockGetUserInfo(TEST_USER_2);
        mViewGroup = (ViewGroup) LayoutInflater.from(mContext).inflate(
                R.layout.sysui_overlay_window, /* root= */ null);
        mCarUserSwitchingDialogController.inflate(mViewGroup);
    }

    @Test
    public void onHandleShow_newUserSelected_showsDialog() {
        mCarUserSwitchingDialogController.handleShow(/* newUserId= */ TEST_USER_1);
        mExecutor.advanceClockToLast();
        mExecutor.runAllReady();

        verify(mOverlayViewGlobalStateController).showView(eq(mCarUserSwitchingDialogController),
                any());
    }

    @Test
    public void onHandleShow_showsDefaultLoadingMessage() {
        mCarUserSwitchingDialogController.handleShow(/* newUserId= */ TEST_USER_1);
        mExecutor.advanceClockToLast();
        mExecutor.runAllReady();

        TextView textView = mViewGroup.findViewById(R.id.user_loading);
        assertThat(textView.getText().toString()).isEqualTo(
                mTestableResources.getResources().getString(R.string.car_loading_profile));
    }

    @Test
    public void onHandleShow_showsUserSwitchingMessage() {
        String message = "Hello world!";
        when(mMockActivityManager.getSwitchingFromUserMessage()).thenReturn(message);

        mCarUserSwitchingDialogController.handleShow(/* newUserId= */ TEST_USER_1);
        mExecutor.advanceClockToLast();
        mExecutor.runAllReady();

        TextView textView = mViewGroup.findViewById(R.id.user_loading);
        assertThat(textView.getText().toString()).isEqualTo(message);
    }

    @Test
    public void onHandleShow_alreadyShowing_ignoresRequest() {
        mCarUserSwitchingDialogController.handleShow(/* newUserId= */ TEST_USER_1);
        mExecutor.advanceClockToLast();
        mExecutor.runAllReady();
        mCarUserSwitchingDialogController.handleShow(/* newUserId= */ TEST_USER_2);
        mExecutor.advanceClockToLast();
        mExecutor.runAllReady();

        // Verify that the request was processed only once.
        verify(mOverlayViewGlobalStateController).showView(eq(mCarUserSwitchingDialogController),
                any());
    }

    @Test
    public void onHandleShow_sameUserSelected_ignoresRequest() {
        mCarUserSwitchingDialogController.handleShow(/* newUserId= */ TEST_USER_1);
        mExecutor.advanceClockToLast();
        mExecutor.runAllReady();
        mCarUserSwitchingDialogController.handleHide();
        mExecutor.advanceClockToLast();
        mExecutor.runAllReady();
        mCarUserSwitchingDialogController.handleShow(/* newUserId= */ TEST_USER_1);
        mExecutor.advanceClockToLast();
        mExecutor.runAllReady();

        // Verify that the request was processed only once.
        verify(mOverlayViewGlobalStateController).showView(eq(mCarUserSwitchingDialogController),
                any());
    }

    @Test
    public void onHide_currentlyShowing_hidesDialog() {
        mCarUserSwitchingDialogController.handleShow(/* newUserId= */ TEST_USER_1);
        mExecutor.advanceClockToLast();
        mExecutor.runAllReady();
        mCarUserSwitchingDialogController.handleHide();
        mExecutor.advanceClockToLast();
        mExecutor.runAllReady();

        verify(mOverlayViewGlobalStateController).hideView(eq(mCarUserSwitchingDialogController),
                any());
    }

    @Test
    public void onHide_notShowing_ignoresRequest() {
        mCarUserSwitchingDialogController.handleShow(/* newUserId= */ TEST_USER_1);
        mExecutor.advanceClockToLast();
        mExecutor.runAllReady();
        mCarUserSwitchingDialogController.handleHide();
        mExecutor.advanceClockToLast();
        mExecutor.runAllReady();
        mCarUserSwitchingDialogController.handleHide();
        mExecutor.advanceClockToLast();
        mExecutor.runAllReady();

        // Verify that the request was processed only once.
        verify(mOverlayViewGlobalStateController).hideView(eq(mCarUserSwitchingDialogController),
                any());
    }

    @Test
    public void onWindowShownTimeoutPassed_viewNotHidden_hidesUserSwitchTransitionView() {
        mCarUserSwitchingDialogController.handleShow(/* newUserId= */ TEST_USER_1);
        mExecutor.advanceClockToLast();
        mExecutor.runAllReady();
        reset(mOverlayViewGlobalStateController);

        getContext().getMainThreadHandler().postDelayed(() -> {
            verify(mOverlayViewGlobalStateController).hideView(
                    eq(mCarUserSwitchingDialogController), any());
        }, mCarUserSwitchingDialogController.getWindowShownTimeoutMs() + 10);
    }

    @Test
    public void onWindowShownTimeoutPassed_viewHidden_doesNotHideUserSwitchTransitionViewAgain() {
        mCarUserSwitchingDialogController.handleShow(/* newUserId= */ TEST_USER_1);
        mExecutor.advanceClockToLast();
        mExecutor.runAllReady();
        mCarUserSwitchingDialogController.handleHide();
        mExecutor.advanceClockToLast();
        mExecutor.runAllReady();
        reset(mOverlayViewGlobalStateController);

        getContext().getMainThreadHandler().postDelayed(() -> {
            verify(mOverlayViewGlobalStateController, never()).hideView(
                    eq(mCarUserSwitchingDialogController), any());
        }, mCarUserSwitchingDialogController.getWindowShownTimeoutMs() + 10);
    }

    private void mockGetUserInfo(int userId) {
        when(mMockUserManager.getUserInfo(userId))
                .thenReturn(new UserInfo(userId, "USER_" + userId, /* flags= */ 0));
    }
}
