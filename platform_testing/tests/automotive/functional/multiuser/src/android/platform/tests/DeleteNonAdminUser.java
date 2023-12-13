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

import android.os.SystemClock;
import android.platform.helpers.AutoConfigConstants;
import android.platform.helpers.AutoUtility;
import android.platform.helpers.HelperAccessor;
import android.platform.helpers.IAutoUserHelper;
import android.platform.helpers.IAutoSettingHelper;
import android.platform.helpers.MultiUserHelper;
import android.platform.scenario.multiuser.MultiUserConstants;
import androidx.test.runner.AndroidJUnit4;
import org.junit.After;
import org.junit.BeforeClass;
import org.junit.Test;
import org.junit.runner.RunWith;

/**
 * This test will create user through API and delete the same user from UI
 */
@RunWith(AndroidJUnit4.class)
public class DeleteNonAdminUser {

    private static final String userName = MultiUserConstants.SECONDARY_USER_NAME;
    private static final int WAIT_TIME = 10000;
    private final MultiUserHelper mMultiUserHelper = MultiUserHelper.getInstance();
    private HelperAccessor<IAutoUserHelper> mUsersHelper;
    private HelperAccessor<IAutoSettingHelper> mSettingHelper;
    private int mTargetUserId;

    public DeleteNonAdminUser() {
        mUsersHelper = new HelperAccessor<>(IAutoUserHelper.class);
        mSettingHelper = new HelperAccessor<>(IAutoSettingHelper.class);
    }

    @BeforeClass
    public static void exitSuw() {
        AutoUtility.exitSuw();
    }

    @After
    public void goBackToHomeScreen() {
        mSettingHelper.get().goBackToSettingsScreen();
    }

    @Test
    public void testRemoveUser() throws Exception {
        // create new user
        mTargetUserId = mMultiUserHelper.createUser(userName, false);
        SystemClock.sleep(WAIT_TIME);
        // make the new user admin and delete new user
        mSettingHelper.get().openSetting(AutoConfigConstants.PROFILE_ACCOUNT_SETTINGS);
        mUsersHelper.get().deleteUser(userName);
        // verify new user was deleted
        assertFalse(mUsersHelper.get().isUserPresent(userName));
    }
}
