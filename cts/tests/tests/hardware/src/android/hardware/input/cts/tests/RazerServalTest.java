/*
 * Copyright (C) 2019 The Android Open Source Project
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

package android.hardware.input.cts.tests;

import android.content.Intent;
import android.hardware.cts.R;
import android.server.wm.WindowManagerStateHelper;

import androidx.test.ext.junit.runners.AndroidJUnit4;
import androidx.test.filters.MediumTest;

import org.junit.Test;
import org.junit.runner.RunWith;

@MediumTest
@RunWith(AndroidJUnit4.class)
public class RazerServalTest extends InputHidTestCase {
    public RazerServalTest() {
        super(R.raw.razer_serval_register);
    }

    /**
     * Test all keys except the home key.
     */
    @Test
    public void testAllKeys() {
        testInputEvents(R.raw.razer_serval_keyeventtests);
    }

    @Test
    public void testAllMotions() {
        testInputEvents(R.raw.razer_serval_motioneventtests);
    }

    /**
     * We cannot test the home key using "testAllKeys" because the home key does not go to the
     * apps, and therefore cannot be received in InputCtsActivity.
     * Instead, we rely on the home button behavior check using the wm utils.
     */
    @Test
    public void testHomeKey() {
        testInputEvents(R.raw.razer_serval_homekey);
        WindowManagerStateHelper wmStateHelper = new WindowManagerStateHelper();
        // Put DUT on home screen
        Intent intent = new Intent();
        intent.addCategory(Intent.CATEGORY_HOME);
        intent.setAction(Intent.ACTION_MAIN);
        mActivityRule.getActivity().startActivity(intent);


        wmStateHelper.waitForHomeActivityVisible();
        wmStateHelper.assertHomeActivityVisible(true);
    }
}
