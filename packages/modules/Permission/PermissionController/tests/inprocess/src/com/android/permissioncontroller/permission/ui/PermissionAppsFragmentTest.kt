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

package com.android.permissioncontroller.permission.ui

import android.content.Intent
import android.content.Intent.ACTION_MANAGE_PERMISSION_APPS
import android.content.Intent.EXTRA_PERMISSION_NAME
import android.permission.cts.PermissionUtils.install
import android.permission.cts.PermissionUtils.uninstallApp
import androidx.test.rule.ActivityTestRule
import com.android.compatibility.common.util.SystemUtil.eventually
import com.android.permissioncontroller.assertDoesNotHavePreference
import com.android.permissioncontroller.scrollToPreference
import com.android.permissioncontroller.wakeUpScreen
import org.junit.After
import org.junit.Assume
import org.junit.Before
import org.junit.Rule
import org.junit.Test

/**
 * Superclass of all tests for {@link PermissionAppsFragmentTest}.
 *
 * <p>Leave abstract to prevent the test runner from trying to run it
 *
 * Currently, none of the tests that extend [PermissionAppsFragmentTest] run on TV.
 * TODO(b/178576541): Adapt and run on TV.
 */
abstract class PermissionAppsFragmentTest(
    val userApk: String,
    val userPkg: String,
    val perm: String,
    val definerApk: String? = null,
    val definerPkg: String? = null
) : UiBaseTest() {
    val managePermissionsActivity = object : ActivityTestRule<ManagePermissionsActivity>(
            ManagePermissionsActivity::class.java) {
        override fun getActivityIntent() = Intent(ACTION_MANAGE_PERMISSION_APPS)
                .putExtra(EXTRA_PERMISSION_NAME, perm)

        override fun beforeActivityLaunched() {
            if (definerApk != null) {
                install(definerApk)
            }
        }
    }

    @Rule
    fun activityRule() = if (isTelevision) noOpTestRule else managePermissionsActivity

    @Before
    fun assumeNotTelevision() = Assume.assumeFalse(isTelevision)

    @Before
    fun wakeScreenUp() {
        wakeUpScreen()
    }

    @Test
    fun appAppearsWhenInstalled() {
        assertDoesNotHavePreference(userPkg)

        install(userApk)
        eventually {
            scrollToPreference(userPkg)
        }
    }

    @Test
    fun appDisappearsWhenUninstalled() {
        assertDoesNotHavePreference(userPkg)

        install(userApk)
        eventually {
            scrollToPreference(userPkg)
        }

        uninstallApp(userPkg)
        eventually {
            assertDoesNotHavePreference(userPkg)
        }
    }

    @After
    fun uninstallTestApp() {
        if (definerPkg != null) {
            uninstallApp(definerPkg)
        }
        uninstallApp(userPkg)
    }
}
