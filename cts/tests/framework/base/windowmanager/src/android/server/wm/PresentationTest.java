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
 * limitations under the License
 */

package android.server.wm;

import static com.google.common.truth.Truth.assertThat;

import static org.junit.Assert.assertTrue;

import android.content.Intent;
import android.platform.test.annotations.Presubmit;
import android.server.wm.app.Components;
import android.view.Display;

import org.junit.Test;

import java.util.List;

/**
 * Build/Install/Run:
 *     atest CtsWindowManagerDeviceTestCases:PresentationTest
 */
@Presubmit
public class PresentationTest extends MultiDisplayTestBase {

    // WindowManager.LayoutParams.TYPE_PRESENTATION
    private static final int TYPE_PRESENTATION = 2037;

    @Test
    public void testPresentationFollowsDisplayFlag() {
        for (Display display : mDm.getDisplays()) {
            launchPresentationActivity(display.getDisplayId());
            if ((display.getFlags() & Display.FLAG_PRESENTATION) != Display.FLAG_PRESENTATION) {
                assertNoPresentationDisplayed();
            } else {
                assertPresentationOnDisplayAndMatchesDisplayMetrics(display.getDisplayId());
            }
        }
    }

    @Test
    public void testPresentationAllowedOnPresentationDisplay() {
        WindowManagerState.DisplayContent display =
                createManagedVirtualDisplaySession()
                        .setPresentationDisplay(true)
                        .setPublicDisplay(true)
                        .createDisplay();

        assertThat(display.getFlags() & Display.FLAG_PRESENTATION)
                .isEqualTo(Display.FLAG_PRESENTATION);

        launchPresentationActivity(display.mId);
        assertPresentationOnDisplayAndMatchesDisplayMetrics(display.mId);
    }

    @Test
    public void testPresentationNotDismissAfterResizeDisplay() {
        final VirtualDisplaySession virtualDisplaySession = createManagedVirtualDisplaySession();
        WindowManagerState.DisplayContent display = virtualDisplaySession
                        .setPresentationDisplay(true)
                        .setPublicDisplay(true)
                        .setResizeDisplay(false) // resize only through resizeDisplay call
                        .createDisplay();

        assertThat(display.getFlags() & Display.FLAG_PRESENTATION)
                .isEqualTo(Display.FLAG_PRESENTATION);

        launchPresentationActivity(display.mId);
        assertPresentationOnDisplayAndMatchesDisplayMetrics(display.mId);

        virtualDisplaySession.resizeDisplay();

        assertTrue("Presentation must not dismiss on external public display even if"
                + "display resize", mWmState.waitForWithAmState(
                state -> isPresentationOnDisplay(state, display.mId),
                "Presentation window still shows"));
    }

    @Test
    public void testPresentationBlockedOnNonPresentationDisplay() {
        WindowManagerState.DisplayContent display =
                createManagedVirtualDisplaySession()
                        .setPresentationDisplay(false)
                        .createDisplay();

        assertThat(display.getFlags() & Display.FLAG_PRESENTATION).isEqualTo(0);
        launchPresentationActivity(display.mId);
        assertNoPresentationDisplayed();
    }

    private boolean isPresentationOnDisplay(WindowManagerState windowManagerState, int displayId) {
        final List<WindowManagerState.WindowState> states =
                windowManagerState.getMatchingWindowType(TYPE_PRESENTATION);
        for (WindowManagerState.WindowState ws : states) {
            if (ws.getDisplayId() == displayId) return true;
        }
        return false;
    }

    private void assertNoPresentationDisplayed() {
        final List<WindowManagerState.WindowState> presentationWindows =
                mWmState.getWindowsByPackageName(
                        Components.PRESENTATION_ACTIVITY.getPackageName(), TYPE_PRESENTATION);
        assertThat(presentationWindows).isEmpty();
    }

    private void assertPresentationOnDisplayAndMatchesDisplayMetrics(int displayId) {
        final List<WindowManagerState.WindowState> presentationWindows =
                mWmState.getWindowsByPackageName(
                        Components.PRESENTATION_ACTIVITY.getPackageName(), TYPE_PRESENTATION);
        assertThat(presentationWindows).hasSize(1);
        WindowManagerState.WindowState presentationWindowState = presentationWindows.get(0);
        assertThat(presentationWindowState.getDisplayId()).isEqualTo(displayId);

        WindowManagerState.DisplayContent display = mWmState.getDisplay(displayId);
        assertThat(display.getDisplayRect()).isEqualTo(
                presentationWindowState.mFullConfiguration.windowConfiguration.getBounds());
    }

    private void launchPresentationActivity(int displayId) {
        Intent intent = new Intent();
        intent.setComponent(Components.PRESENTATION_ACTIVITY);
        intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        intent.putExtra(Components.PresentationActivity.KEY_DISPLAY_ID, displayId);
        mContext.startActivity(intent);
        waitAndAssertTopResumedActivity(
                Components.PRESENTATION_ACTIVITY,
                Display.DEFAULT_DISPLAY,
                "Launched activity must be on top");
    }
}
