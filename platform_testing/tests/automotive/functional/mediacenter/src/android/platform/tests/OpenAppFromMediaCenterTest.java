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

package android.platform.tests;

import static junit.framework.Assert.assertFalse;
import static junit.framework.Assert.assertTrue;

import android.platform.helpers.AutoUtility;
import android.platform.helpers.IAutoHomeHelper;
import android.platform.helpers.IAutoMediaHelper;
import android.platform.helpers.HelperAccessor;
import android.platform.helpers.HomeHelperImpl;
import android.platform.test.option.StringOption;
import androidx.test.runner.AndroidJUnit4;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.junit.BeforeClass;
import org.junit.ClassRule;
import org.junit.Test;
import org.junit.runner.RunWith;

@RunWith(AndroidJUnit4.class)
public class OpenAppFromMediaCenterTest {
    private static final String BLUETOOTH_APP = "bluetooth-app";
    private static final String MEDIA_APPS = "media-apps";

    private static final String DEFAULT_MEDIA_APP = "Bluetooth Audio";
    private static final String DEFAULT_LIST_OF_MEDIA_APPS = "Bluetooth Audio, Radio";

    @ClassRule
    public static StringOption mMediaDefaultApp =
            new StringOption(BLUETOOTH_APP).setRequired(false);
    @ClassRule
    public static StringOption mMediaApps = new StringOption(MEDIA_APPS).setRequired(false);

    private HelperAccessor<IAutoMediaHelper> mMediaCenterHelper;
    private HelperAccessor<IAutoHomeHelper> mAutoHomeHelper;

    public OpenAppFromMediaCenterTest() {
        mMediaCenterHelper = new HelperAccessor<>(IAutoMediaHelper.class);
        mAutoHomeHelper = new HelperAccessor<>(IAutoHomeHelper.class);
    }

    @BeforeClass
    public static void exitSuw() {
        AutoUtility.exitSuw();
    }

    @Test
    public void testOpenMediaAppFromMediaWidget() {
        // Use preinstalled "Bluetooth Audio" app
        mAutoHomeHelper.get().openMediaWidget();
        assertTrue("Not a media app",
                mMediaCenterHelper.get().getMediaAppTitle().equals(getDefaultMediaAppName()));
    }

    @Test
    public void testMediaAppPresentInMediaGrid() {
        mAutoHomeHelper.get().openMediaWidget();
        mMediaCenterHelper.get().openMediaAppMenuItems();
        assertTrue("Incorrect Media apps in Grid",
                mMediaCenterHelper.get().areMediaAppsPresent(getExpectedMediaAppNames()));
    }

    private String getDefaultMediaAppName() {
        String mediaAppName = DEFAULT_MEDIA_APP;
        if (mMediaDefaultApp != null
                && mMediaDefaultApp.get() != null && !mMediaDefaultApp.get().isEmpty()) {
            mediaAppName = mMediaDefaultApp.get();
        }
        return mediaAppName;
    }

    private List<String> getExpectedMediaAppNames() {
        String mediaAppNames = DEFAULT_LIST_OF_MEDIA_APPS;
        if (mMediaApps != null && mMediaApps.get() != null && !mMediaApps.get().isEmpty()) {
            // Get list of media apps from String options if passed.
            mediaAppNames = mMediaApps.get();
        }
        String[] mediaAppNamesList = mediaAppNames.trim().split("\\s*,\\s*");
        return Arrays.asList(mediaAppNamesList);
    }
}
