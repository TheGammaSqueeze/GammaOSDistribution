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

package android.security.cts;

import static android.view.Display.DEFAULT_DISPLAY;
import static android.view.WindowManager.LayoutParams.TYPE_APPLICATION;

import android.Manifest;
import android.app.WallpaperManager;
import android.content.Context;
import android.graphics.Rect;
import android.hardware.display.DisplayManager;
import android.platform.test.annotations.AsbSecurityTest;
import android.view.Display;

import androidx.test.platform.app.InstrumentationRegistry;

import com.android.compatibility.common.util.CtsAndroidTestCase;

import org.junit.After;
import org.junit.Before;

public class WallpaperManagerTest extends CtsAndroidTestCase {

    @Before
    public void setUp() {
        InstrumentationRegistry
                .getInstrumentation()
                .getUiAutomation()
                .adoptShellPermissionIdentity(Manifest.permission.SET_WALLPAPER_HINTS);
    }

    @After
    public void tearDown() throws Exception {
        InstrumentationRegistry.getInstrumentation().getUiAutomation()
                .dropShellPermissionIdentity();
    }

    // b/204316511
    @AsbSecurityTest(cveBugId = 204316511)
    public void testSetDisplayPadding() {
        WallpaperManager wallpaperManager = WallpaperManager.getInstance(getContext());

        Rect validRect = new Rect(1, 1, 1, 1);
        // This should work, no exception expected
        wallpaperManager.setDisplayPadding(validRect);

        Rect negativeRect = new Rect(-1, 0 , 0, 0);
        try {
            wallpaperManager.setDisplayPadding(negativeRect);
            fail("setDisplayPadding should fail for a Rect with negative values");
        } catch (IllegalArgumentException e) {
            // Expected exception
        }

        DisplayManager dm = getContext().getSystemService(DisplayManager.class);
        Display primaryDisplay = dm.getDisplay(DEFAULT_DISPLAY);
        Context windowContext = getContext().createWindowContext(primaryDisplay,
                TYPE_APPLICATION, null);
        Display display = windowContext.getDisplay();

        Rect tooWideRect = new Rect(0, 0, display.getMaximumSizeDimension() + 1, 0);
        try {
            wallpaperManager.setDisplayPadding(tooWideRect);
            fail("setDisplayPadding should fail for a Rect width larger than "
                    + display.getMaximumSizeDimension());
        } catch (IllegalArgumentException e) {
            // Expected exception
        }

        Rect tooHighRect = new Rect(0, 0, 0, display.getMaximumSizeDimension() + 1);
        try {
            wallpaperManager.setDisplayPadding(tooHighRect);
            fail("setDisplayPadding should fail for a Rect height larger than "
                    + display.getMaximumSizeDimension());
        } catch (IllegalArgumentException e) {
            // Expected exception
        }
    }
}
