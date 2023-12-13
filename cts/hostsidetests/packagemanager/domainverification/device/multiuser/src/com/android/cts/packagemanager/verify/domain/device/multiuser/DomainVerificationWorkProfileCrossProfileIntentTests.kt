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

package com.android.cts.packagemanager.verify.domain.device.multiuser

import android.app.admin.DevicePolicyManager
import android.content.Intent
import android.content.IntentFilter
import com.android.bedstead.harrier.BedsteadJUnit4
import com.android.bedstead.harrier.DeviceState
import com.android.bedstead.harrier.annotations.EnsureHasWorkProfile
import com.android.bedstead.harrier.annotations.Postsubmit
import com.android.bedstead.harrier.annotations.RequireRunOnPrimaryUser
import com.android.bedstead.remotedpc.RemoteDpc.DPC_COMPONENT_NAME
import com.android.cts.packagemanager.verify.domain.java.DomainUtils.DOMAIN_1
import org.junit.After
import org.junit.Before
import org.junit.Test
import org.junit.runner.RunWith

@EnsureHasWorkProfile(forUser = DeviceState.UserType.PRIMARY_USER)
@RunWith(BedsteadJUnit4::class)
class DomainVerificationWorkProfileCrossProfileIntentTests :
    DomainVerificationWorkProfileTestsBase() {

    // The specific cross profile Intent test requires general app link policy to be disabled
    private var initialAppLinkPolicy: Boolean? = null

    @Before
    fun saveAndSetPolicy() {
        val manager = deviceState.getWorkDevicePolicyManager()
        initialAppLinkPolicy = manager.getAppLinkPolicy(DPC_COMPONENT_NAME)
        if (initialAppLinkPolicy != false) {
            manager.setAppLinkPolicy(DPC_COMPONENT_NAME, false)
        }

        val intentFilter = IntentFilter().apply {
            addAction(Intent.ACTION_VIEW)
            addCategory(Intent.CATEGORY_BROWSABLE)
            addCategory(Intent.CATEGORY_DEFAULT)
            addDataScheme("https")
            addDataAuthority(DOMAIN_1, null)
        }
        manager.addCrossProfileIntentFilter(
            DPC_COMPONENT_NAME,
            intentFilter,
            DevicePolicyManager.FLAG_PARENT_CAN_ACCESS_MANAGED
                    or DevicePolicyManager.FLAG_MANAGED_CAN_ACCESS_PARENT
        )
    }

    @After
    fun resetPolicy() {
        val manager = deviceState.getWorkDevicePolicyManager()
        if (initialAppLinkPolicy ?: return != manager.getAppLinkPolicy(DPC_COMPONENT_NAME)) {
            manager.setAppLinkPolicy(DPC_COMPONENT_NAME, initialAppLinkPolicy!!)
        }
        manager.clearCrossProfileIntentFilters(DPC_COMPONENT_NAME)
    }

    @RequireRunOnPrimaryUser
    @Postsubmit(reason = "New test")
    @Test
    override fun inPersonal_verifiedInOtherProfile() {
        verify(WORK_APP)

        // Specific configuration does allow parent -> managed
        assertResolvesTo(personalBrowsers + FORWARD_TO_MANAGED)
    }
}
