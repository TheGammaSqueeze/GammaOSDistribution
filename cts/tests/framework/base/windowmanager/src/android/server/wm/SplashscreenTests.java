/*
 * Copyright (C) 2017 The Android Open Source Project
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

import static android.app.UiModeManager.MODE_NIGHT_AUTO;
import static android.app.UiModeManager.MODE_NIGHT_CUSTOM;
import static android.app.UiModeManager.MODE_NIGHT_NO;
import static android.app.UiModeManager.MODE_NIGHT_YES;
import static android.app.WindowConfiguration.WINDOWING_MODE_FREEFORM;
import static android.app.WindowConfiguration.WINDOWING_MODE_FULLSCREEN;
import static android.content.Intent.ACTION_MAIN;
import static android.content.Intent.CATEGORY_HOME;
import static android.content.Intent.FLAG_ACTIVITY_NEW_TASK;
import static android.server.wm.CliIntentExtra.extraBool;
import static android.server.wm.CliIntentExtra.extraString;
import static android.server.wm.WindowManagerState.STATE_RESUMED;
import static android.server.wm.app.Components.HANDLE_SPLASH_SCREEN_EXIT_ACTIVITY;
import static android.server.wm.app.Components.HOME_ACTIVITY;
import static android.server.wm.app.Components.SPLASHSCREEN_ACTIVITY;
import static android.server.wm.app.Components.SPLASH_SCREEN_REPLACE_ICON_ACTIVITY;
import static android.server.wm.app.Components.SPLASH_SCREEN_REPLACE_THEME_ACTIVITY;
import static android.server.wm.app.Components.TestActivity.COMMAND_START_ACTIVITY;
import static android.server.wm.app.Components.TestActivity.EXTRA_INTENT;
import static android.server.wm.app.Components.TestStartingWindowKeys.CANCEL_HANDLE_EXIT;
import static android.server.wm.app.Components.TestStartingWindowKeys.CENTER_VIEW_IS_SURFACE_VIEW;
import static android.server.wm.app.Components.TestStartingWindowKeys.CONTAINS_BRANDING_VIEW;
import static android.server.wm.app.Components.TestStartingWindowKeys.CONTAINS_CENTER_VIEW;
import static android.server.wm.app.Components.TestStartingWindowKeys.DELAY_RESUME;
import static android.server.wm.app.Components.TestStartingWindowKeys.GET_NIGHT_MODE_ACTIVITY_CHANGED;
import static android.server.wm.app.Components.TestStartingWindowKeys.HANDLE_SPLASH_SCREEN_EXIT;
import static android.server.wm.app.Components.TestStartingWindowKeys.ICON_ANIMATION_DURATION;
import static android.server.wm.app.Components.TestStartingWindowKeys.ICON_ANIMATION_START;
import static android.server.wm.app.Components.TestStartingWindowKeys.ICON_BACKGROUND_COLOR;
import static android.server.wm.app.Components.TestStartingWindowKeys.OVERRIDE_THEME_COLOR;
import static android.server.wm.app.Components.TestStartingWindowKeys.OVERRIDE_THEME_COMPONENT;
import static android.server.wm.app.Components.TestStartingWindowKeys.OVERRIDE_THEME_ENABLED;
import static android.server.wm.app.Components.TestStartingWindowKeys.RECEIVE_SPLASH_SCREEN_EXIT;
import static android.server.wm.app.Components.TestStartingWindowKeys.REPLACE_ICON_EXIT;
import static android.server.wm.app.Components.TestStartingWindowKeys.REQUEST_HANDLE_EXIT_ON_CREATE;
import static android.server.wm.app.Components.TestStartingWindowKeys.REQUEST_HANDLE_EXIT_ON_RESUME;
import static android.server.wm.app.Components.TestStartingWindowKeys.REQUEST_SET_NIGHT_MODE_ON_CREATE;
import static android.view.Display.DEFAULT_DISPLAY;
import static android.view.WindowInsets.Type.captionBar;
import static android.view.WindowInsets.Type.statusBars;
import static android.view.WindowInsets.Type.systemBars;

import static org.hamcrest.MatcherAssert.assertThat;
import static org.hamcrest.Matchers.greaterThanOrEqualTo;
import static org.hamcrest.Matchers.lessThanOrEqualTo;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;
import static org.junit.Assume.assumeFalse;
import static org.junit.Assume.assumeTrue;

import android.app.UiModeManager;
import android.content.ComponentName;
import android.content.Intent;
import android.content.pm.LauncherApps;
import android.content.pm.ShortcutInfo;
import android.content.pm.ShortcutManager;
import android.content.res.Configuration;
import android.graphics.Bitmap;
import android.graphics.Color;
import android.graphics.Insets;
import android.graphics.Rect;
import android.os.Bundle;
import android.platform.test.annotations.Presubmit;
import android.view.WindowManager;
import android.view.WindowMetrics;

import androidx.core.graphics.ColorUtils;

import com.android.compatibility.common.util.TestUtils;

import org.junit.After;
import org.junit.Before;
import org.junit.Rule;
import org.junit.Test;

import java.util.Collections;
import java.util.function.Consumer;

/**
 * Build/Install/Run:
 * atest CtsWindowManagerDeviceTestCases:SplashscreenTests
 */
@Presubmit
@android.server.wm.annotation.Group1
public class SplashscreenTests extends ActivityManagerTestBase {

    private static final int CENTER_ICON_SIZE = 192;

    @Rule
    public final DumpOnFailure dumpOnFailure = new DumpOnFailure();

    @Before
    public void setUp() throws Exception {
        super.setUp();
        mWmState.setSanityCheckWithFocusedWindow(false);
        mWmState.waitForDisplayUnfrozen();
    }

    @After
    public void tearDown() {
        mWmState.setSanityCheckWithFocusedWindow(true);
    }

    private CommandSession.ActivitySession prepareTestLauncher() {
        createManagedHomeActivitySession(HOME_ACTIVITY);
        return createManagedActivityClientSession()
                .startActivity(new Intent(ACTION_MAIN)
                        .addCategory(CATEGORY_HOME)
                        .addFlags(FLAG_ACTIVITY_NEW_TASK)
                        .setComponent(HOME_ACTIVITY));
    }

    private void startActivityFromTestLauncher(CommandSession.ActivitySession homeActivity,
            ComponentName componentName, Consumer<Intent> fillExtra) {

        final Bundle data = new Bundle();
        final Intent startIntent = new Intent();
        startIntent.setComponent(componentName);
        startIntent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        fillExtra.accept(startIntent);
        data.putParcelable(EXTRA_INTENT, startIntent);
        homeActivity.sendCommand(COMMAND_START_ACTIVITY, data);
    }

    @Test
    public void testSplashscreenContent() {
        // TODO(b/192431448): Allow Automotive to skip this test until Splash Screen is properly
        // applied insets by system bars in AAOS.
        assumeFalse(isCar());

        launchActivityNoWait(SPLASHSCREEN_ACTIVITY, WINDOWING_MODE_FULLSCREEN);
        // The windowSplashScreenContent attribute is set to RED. We check that it is ignored.
        testSplashScreenColor(SPLASHSCREEN_ACTIVITY, Color.BLUE, Color.WHITE);
    }

    @Test
    public void testSplashscreenContent_FreeformWindow() {
        // TODO(b/192431448): Allow Automotive to skip this test until Splash Screen is properly
        // applied insets by system bars in AAOS.
        assumeFalse(isCar());
        assumeTrue(supportsFreeform());

        launchActivityNoWait(SPLASHSCREEN_ACTIVITY, WINDOWING_MODE_FREEFORM);
        // The windowSplashScreenContent attribute is set to RED. We check that it is ignored.
        testSplashScreenColor(SPLASHSCREEN_ACTIVITY, Color.BLUE, Color.WHITE);
    }

    private void testSplashScreenColor(ComponentName name, int primaryColor, int secondaryColor) {
        // Activity may not be launched yet even if app transition is in idle state.
        mWmState.waitForActivityState(name, STATE_RESUMED);
        mWmState.waitForAppTransitionIdleOnDisplay(DEFAULT_DISPLAY);
        boolean isFullscreen = mWmState.getTaskByActivity(name).isWindowingModeCompatible(
                WINDOWING_MODE_FULLSCREEN);

        final Bitmap image = takeScreenshot();
        final WindowMetrics windowMetrics = mWm.getMaximumWindowMetrics();
        final Rect stableBounds = new Rect(windowMetrics.getBounds());
        Insets statusBarInsets = windowMetrics.getWindowInsets().getInsetsIgnoringVisibility(
                statusBars());
        stableBounds.inset(windowMetrics.getWindowInsets().getInsetsIgnoringVisibility(
                systemBars() & ~captionBar()));
        WindowManagerState.WindowState startingWindow = mWmState.findFirstWindowWithType(
                WindowManager.LayoutParams.TYPE_APPLICATION_STARTING);

        Rect startingWindowBounds = startingWindow.getBounds();
        final Rect appBounds;
        if (startingWindowBounds != null) {
            appBounds = new Rect(startingWindowBounds);
        } else {
            appBounds = new Rect(startingWindow.getFrame());
        }

        Rect statusBarInsetsBounds = new Rect(statusBarInsets.left, 0,
                appBounds.right - statusBarInsets.right, statusBarInsets.top);

        assertFalse("Couldn't find splash screen bounds. Impossible to assert the colors",
                appBounds.isEmpty());

        // Use ratios to flexibly accommodate circular or not quite rectangular displays
        // Note: Color.BLACK is the pixel color outside of the display region

        int px = WindowManagerState.dpToPx(CENTER_ICON_SIZE,
                mContext.getResources().getConfiguration().densityDpi);
        Rect ignoreRect = new Rect(0, 0, px, px);
        ignoreRect.offsetTo(appBounds.centerX() - ignoreRect.width() / 2,
                appBounds.centerY() - ignoreRect.height() / 2);

        appBounds.intersect(stableBounds);
        assertColors(image, appBounds, primaryColor, 0.99f, secondaryColor, 0.02f, ignoreRect);
        if (isFullscreen && !statusBarInsetsBounds.isEmpty()) {
            assertColors(image, statusBarInsetsBounds, primaryColor, 0.80f, secondaryColor, 0.10f,
                    null);
        }
    }

    // For real devices, gamma correction might be applied on hardware driver, so the colors may
    // not exactly match.
    private static boolean isSimilarColor(int a, int b) {
        if (a == b) {
            return true;
        }
        return Math.abs(Color.alpha(a) - Color.alpha(b)) +
                Math.abs(Color.red(a) - Color.red(b)) +
                Math.abs(Color.green(a) - Color.green(b)) +
                Math.abs(Color.blue(a) - Color.blue(b)) < 10;
    }

    private void assertColors(Bitmap img, Rect bounds, int primaryColor, float expectedPrimaryRatio,
            int secondaryColor, float acceptableWrongRatio, Rect ignoreRect) {

        int primaryPixels = 0;
        int secondaryPixels = 0;
        int wrongPixels = 0;

        assertThat(bounds.top, greaterThanOrEqualTo(0));
        assertThat(bounds.left, greaterThanOrEqualTo(0));
        assertThat(bounds.right, lessThanOrEqualTo(img.getWidth()));
        assertThat(bounds.bottom, lessThanOrEqualTo(img.getHeight()));

        for (int x = bounds.left; x < bounds.right; x++) {
            for (int y = bounds.top; y < bounds.bottom; y++) {
                if (ignoreRect != null && ignoreRect.contains(x, y)) {
                    continue;
                }
                final int color = img.getPixel(x, y);
                if (isSimilarColor(primaryColor, color)) {
                    primaryPixels++;
                } else if (isSimilarColor(secondaryColor, color)) {
                    secondaryPixels++;
                } else {
                    wrongPixels++;
                }
            }
        }

        int totalPixels = bounds.width() * bounds.height();
        if (ignoreRect != null) {
            totalPixels -= ignoreRect.width() * ignoreRect.height();
        }

        final float primaryRatio = (float) primaryPixels / totalPixels;
        if (primaryRatio < expectedPrimaryRatio) {
            generateFailureImage(img, bounds, primaryColor, secondaryColor, ignoreRect);
            fail("Less than " + (expectedPrimaryRatio * 100.0f)
                    + "% of pixels have non-primary color primaryPixels=" + primaryPixels
                    + " secondaryPixels=" + secondaryPixels + " wrongPixels=" + wrongPixels);
        }
        // Some pixels might be covered by screen shape decorations, like rounded corners.
        // On circular displays, there is an antialiased edge.
        final float wrongRatio = (float) wrongPixels / totalPixels;
        if (wrongRatio > acceptableWrongRatio) {
            generateFailureImage(img, bounds, primaryColor, secondaryColor, ignoreRect);
            fail("More than " + (acceptableWrongRatio * 100.0f)
                    + "% of pixels have wrong color primaryPixels=" + primaryPixels
                    + " secondaryPixels=" + secondaryPixels + " wrongPixels="
                    + wrongPixels);
        }
    }

    private void generateFailureImage(Bitmap img, Rect bounds, int primaryColor,
            int secondaryColor, Rect ignoreRect) {

        // Create a bitmap with on the left the original image and on the right the result of the
        // test. The pixel marked in green have the right color, the transparent black one are
        // ignored and the wrong pixels have the original color.
        final int ignoredDebugColor = 0xEE000000;
        final int validDebugColor = 0x6600FF00;
        Bitmap result = Bitmap.createBitmap(img.getWidth() * 2, img.getHeight(),
                Bitmap.Config.ARGB_8888);

        // Execute the exact same logic applied in assertColor() to avoid bugs between the assertion
        // method and the failure method
        for (int x = bounds.left; x < bounds.right; x++) {
            for (int y = bounds.top; y < bounds.bottom; y++) {
                final int pixel = img.getPixel(x, y);
                if (ignoreRect != null && ignoreRect.contains(x, y)) {
                    markDebugPixel(pixel, result, x, y, ignoredDebugColor, 0.95f);
                    continue;
                }
                if (isSimilarColor(primaryColor, pixel)) {
                    markDebugPixel(pixel, result, x, y, validDebugColor, 0.8f);
                } else if (isSimilarColor(secondaryColor, pixel)) {
                    markDebugPixel(pixel, result, x, y, validDebugColor, 0.8f);
                } else {
                    markDebugPixel(pixel, result, x, y, Color.TRANSPARENT, 0.0f);
                }
            }
        }

        // Mark the pixels outside the bounds as ignored
        for (int x = 0; x < img.getWidth(); x++) {
            for (int y = 0; y < img.getHeight(); y++) {
                if (bounds.contains(x, y)) {
                    continue;
                }
                markDebugPixel(img.getPixel(x, y), result, x, y, ignoredDebugColor, 0.95f);
            }
        }
        dumpOnFailure.dumpOnFailure("splashscreen-color-check", result);
    }

    private void markDebugPixel(int pixel, Bitmap result, int x, int y, int color, float ratio) {
        int debugPixel = ColorUtils.blendARGB(pixel, color, ratio);
        result.setPixel(x, y, pixel);
        int debugOffsetX = result.getWidth() / 2;
        result.setPixel(x + debugOffsetX, y, debugPixel);
    }

    @Test
    public void testHandleExitAnimationOnCreate() throws Exception {
        assumeFalse(isLeanBack());
        launchRuntimeHandleExitAnimationActivity(true, false, false, true);
    }

    @Test
    public void testHandleExitAnimationOnResume() throws Exception {
        assumeFalse(isLeanBack());
        launchRuntimeHandleExitAnimationActivity(false, true, false, true);
    }

    @Test
    public void testHandleExitAnimationCancel() throws Exception {
        assumeFalse(isLeanBack());
        launchRuntimeHandleExitAnimationActivity(true, false, true, false);
    }

    private void launchRuntimeHandleExitAnimationActivity(boolean extraOnCreate,
            boolean extraOnResume, boolean extraCancel, boolean expectResult) throws Exception {
        TestJournalProvider.TestJournalContainer.start();
        final CommandSession.ActivitySession homeActivity = prepareTestLauncher();
        startActivityFromTestLauncher(homeActivity, HANDLE_SPLASH_SCREEN_EXIT_ACTIVITY, intent -> {
            intent.putExtra(REQUEST_HANDLE_EXIT_ON_CREATE, extraOnCreate);
            intent.putExtra(REQUEST_HANDLE_EXIT_ON_RESUME, extraOnResume);
            intent.putExtra(CANCEL_HANDLE_EXIT, extraCancel);
        });

        mWmState.computeState(HANDLE_SPLASH_SCREEN_EXIT_ACTIVITY);
        mWmState.assertVisibility(HANDLE_SPLASH_SCREEN_EXIT_ACTIVITY, true);
        final TestJournalProvider.TestJournal journal =
                TestJournalProvider.TestJournalContainer.get(HANDLE_SPLASH_SCREEN_EXIT);
        if (expectResult) {
            TestUtils.waitUntil("Waiting for runtime onSplashScreenExit", 5 /* timeoutSecond */,
                    () -> journal.extras.getBoolean(RECEIVE_SPLASH_SCREEN_EXIT));
            assertTrue("No entry for CONTAINS_CENTER_VIEW",
                    journal.extras.containsKey(CONTAINS_CENTER_VIEW));
            assertTrue("No entry for CONTAINS_BRANDING_VIEW",
                    journal.extras.containsKey(CONTAINS_BRANDING_VIEW));
            assertTrue("Center View shouldn't be null", journal.extras.getBoolean(CONTAINS_CENTER_VIEW));
            assertTrue(journal.extras.getBoolean(CONTAINS_BRANDING_VIEW));
            assertEquals(Color.BLUE, journal.extras.getInt(ICON_BACKGROUND_COLOR, Color.YELLOW));
        }
    }

    @Test
    public void testSetApplicationNightMode() throws Exception {
        final UiModeManager uiModeManager = mContext.getSystemService(UiModeManager.class);
        assumeTrue(uiModeManager != null);
        final int systemNightMode = uiModeManager.getNightMode();
        final int testNightMode = (systemNightMode == MODE_NIGHT_AUTO
                || systemNightMode == MODE_NIGHT_CUSTOM) ? MODE_NIGHT_YES
                : systemNightMode == MODE_NIGHT_YES ? MODE_NIGHT_NO : MODE_NIGHT_YES;
        final int testConfigNightMode = testNightMode == MODE_NIGHT_YES
                ? Configuration.UI_MODE_NIGHT_YES
                : Configuration.UI_MODE_NIGHT_NO;
        final String nightModeNo = String.valueOf(testNightMode);

        TestJournalProvider.TestJournalContainer.start();
        launchActivity(HANDLE_SPLASH_SCREEN_EXIT_ACTIVITY,
                extraString(REQUEST_SET_NIGHT_MODE_ON_CREATE, nightModeNo));
        mWmState.computeState(HANDLE_SPLASH_SCREEN_EXIT_ACTIVITY);
        mWmState.assertVisibility(HANDLE_SPLASH_SCREEN_EXIT_ACTIVITY, true);
        final TestJournalProvider.TestJournal journal =
                TestJournalProvider.TestJournalContainer.get(HANDLE_SPLASH_SCREEN_EXIT);
        TestUtils.waitUntil("Waiting for night mode changed", 5 /* timeoutSecond */, () ->
                testConfigNightMode == journal.extras.getInt(GET_NIGHT_MODE_ACTIVITY_CHANGED));
        assertEquals(testConfigNightMode,
                journal.extras.getInt(GET_NIGHT_MODE_ACTIVITY_CHANGED));
    }

    @Test
    public void testSetBackgroundColorActivity() {
        // TODO(b/192431448): Allow Automotive to skip this test until Splash Screen is properly
        // applied insets by system bars in AAOS.
        assumeFalse(isCar());

        launchActivityNoWait(SPLASH_SCREEN_REPLACE_ICON_ACTIVITY, WINDOWING_MODE_FULLSCREEN,
                extraBool(DELAY_RESUME, true));
        testSplashScreenColor(SPLASH_SCREEN_REPLACE_ICON_ACTIVITY, Color.BLUE, Color.WHITE);
    }

    @Test
    public void testSetBackgroundColorActivity_FreeformWindow() {
        // TODO(b/192431448): Allow Automotive to skip this test until Splash Screen is properly
        // applied insets by system bars in AAOS.
        assumeFalse(isCar());
        assumeTrue(supportsFreeform());

        launchActivityNoWait(SPLASH_SCREEN_REPLACE_ICON_ACTIVITY, WINDOWING_MODE_FREEFORM,
                extraBool(DELAY_RESUME, true));
        testSplashScreenColor(SPLASH_SCREEN_REPLACE_ICON_ACTIVITY, Color.BLUE, Color.WHITE);
    }

    @Test
    public void testHandleExitIconAnimatingActivity() throws Exception {
        assumeFalse(isLeanBack());
        final CommandSession.ActivitySession homeActivity = prepareTestLauncher();
        TestJournalProvider.TestJournalContainer.start();

        startActivityFromTestLauncher(homeActivity, SPLASH_SCREEN_REPLACE_ICON_ACTIVITY, intent -> {
            intent.putExtra(REQUEST_HANDLE_EXIT_ON_CREATE, true);
        });
        mWmState.computeState(SPLASH_SCREEN_REPLACE_ICON_ACTIVITY);
        mWmState.assertVisibility(SPLASH_SCREEN_REPLACE_ICON_ACTIVITY, true);
        final TestJournalProvider.TestJournal journal =
                TestJournalProvider.TestJournalContainer.get(REPLACE_ICON_EXIT);
        TestUtils.waitUntil("Waiting for runtime onSplashScreenExit", 5 /* timeoutSecond */,
                () -> journal.extras.getBoolean(RECEIVE_SPLASH_SCREEN_EXIT));
        assertTrue(journal.extras.getBoolean(CONTAINS_CENTER_VIEW));
        final long iconAnimationStart = journal.extras.getLong(ICON_ANIMATION_START);
        final long iconAnimationDuration = journal.extras.getLong(ICON_ANIMATION_DURATION);
        assertTrue(iconAnimationStart != 0);
        assertEquals(iconAnimationDuration, 500);
        assertFalse(journal.extras.getBoolean(CONTAINS_BRANDING_VIEW));
        assertTrue(journal.extras.getBoolean(CENTER_VIEW_IS_SURFACE_VIEW));
    }

    @Test
    public void testCancelHandleExitIconAnimatingActivity() {
        assumeFalse(isLeanBack());
        final CommandSession.ActivitySession homeActivity = prepareTestLauncher();
        TestJournalProvider.TestJournalContainer.start();
        startActivityFromTestLauncher(homeActivity, SPLASH_SCREEN_REPLACE_ICON_ACTIVITY, intent -> {
            intent.putExtra(REQUEST_HANDLE_EXIT_ON_CREATE, true);
            intent.putExtra(CANCEL_HANDLE_EXIT, true);
        });
        mWmState.waitForActivityState(SPLASH_SCREEN_REPLACE_ICON_ACTIVITY, STATE_RESUMED);
        mWmState.waitForAppTransitionIdleOnDisplay(DEFAULT_DISPLAY);

        final TestJournalProvider.TestJournal journal =
                TestJournalProvider.TestJournalContainer.get(REPLACE_ICON_EXIT);
        assertFalse(journal.extras.getBoolean(RECEIVE_SPLASH_SCREEN_EXIT));
    }

    @Test
    public void testShortcutChangeTheme() {
        // TODO(b/192431448): Allow Automotive to skip this test until Splash Screen is properly
        // applied insets by system bars in AAOS.
        assumeFalse(isCar());

        final LauncherApps launcherApps = mContext.getSystemService(LauncherApps.class);
        final ShortcutManager shortcutManager = mContext.getSystemService(ShortcutManager.class);
        assumeTrue(launcherApps != null && shortcutManager != null);

        final String shortCutId = "shortcut1";
        final ShortcutInfo.Builder b = new ShortcutInfo.Builder(
                mContext, shortCutId);
        final Intent i = new Intent(ACTION_MAIN)
                .setComponent(SPLASHSCREEN_ACTIVITY);
        final ShortcutInfo shortcut = b.setShortLabel("label")
                .setLongLabel("long label")
                .setIntent(i)
                .setStartingTheme(android.R.style.Theme_Black_NoTitleBar_Fullscreen)
                .build();
        try {
            shortcutManager.addDynamicShortcuts(Collections.singletonList(shortcut));
            runWithShellPermission(() -> launcherApps.startShortcut(shortcut, null, null));
            testSplashScreenColor(SPLASHSCREEN_ACTIVITY, Color.BLACK, Color.WHITE);
        } finally {
            shortcutManager.removeDynamicShortcuts(Collections.singletonList(shortCutId));
        }
    }

    private void waitAndAssertOverrideThemeColor(int expectedColor) {
        final ComponentName activity = SPLASH_SCREEN_REPLACE_THEME_ACTIVITY;
        final Bundle resultExtras = Condition.waitForResult(
                new Condition<Bundle>("splash screen theme color of " + activity)
                        .setResultSupplier(() -> TestJournalProvider.TestJournalContainer.get(
                                OVERRIDE_THEME_COMPONENT).extras)
                        .setResultValidator(extras -> extras.containsKey(OVERRIDE_THEME_COLOR)));
        if (resultExtras == null) {
            fail("No reported override theme color from " + activity);
        }
        if (expectedColor > 0) {
            assertEquals("Override theme color must match",
                    Integer.toHexString(expectedColor),
                    Integer.toHexString(resultExtras.getInt(OVERRIDE_THEME_COLOR)));
        }
        mWmState.waitForActivityRemoved(activity);
        separateTestJournal();
    }

    @Test
    public void testOverrideSplashscreenTheme() {
        assumeFalse(isLeanBack());
        final CommandSession.ActivitySession homeActivity = prepareTestLauncher();

        // Pre-launch the activity to ensure status is cleared on the device
        startActivityFromTestLauncher(homeActivity, SPLASH_SCREEN_REPLACE_THEME_ACTIVITY,
                intent -> {});
        waitAndAssertOverrideThemeColor(0 /* ignore */);

        // Launch the activity a first time, check that the splashscreen use the default theme,
        // and override the theme for the next launch
        startActivityFromTestLauncher(homeActivity, SPLASH_SCREEN_REPLACE_THEME_ACTIVITY,
                intent -> intent.putExtra(OVERRIDE_THEME_ENABLED, true));
        waitAndAssertOverrideThemeColor(Color.BLUE);

        // Launch the activity a second time, check that the theme has been overridden and reset
        // to the default theme
        startActivityFromTestLauncher(homeActivity, SPLASH_SCREEN_REPLACE_THEME_ACTIVITY,
                intent -> {});
        waitAndAssertOverrideThemeColor(Color.RED);

        // Launch the activity a third time just to check that the theme has indeed been reset.
        startActivityFromTestLauncher(homeActivity, SPLASH_SCREEN_REPLACE_THEME_ACTIVITY,
                intent -> {});
        waitAndAssertOverrideThemeColor(Color.BLUE);
    }
}
