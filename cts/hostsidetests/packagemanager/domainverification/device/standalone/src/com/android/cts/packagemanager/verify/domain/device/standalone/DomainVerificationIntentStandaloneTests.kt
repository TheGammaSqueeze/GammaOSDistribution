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

package com.android.cts.packagemanager.verify.domain.device.standalone

import android.content.pm.verify.domain.DomainVerificationUserState
import android.os.Build
import com.android.compatibility.common.util.ApiLevelUtil
import com.android.compatibility.common.util.CtsDownstreamingTest
import com.android.compatibility.common.util.SystemUtil
import com.android.cts.packagemanager.verify.domain.android.DomainUtils.DECLARING_PKG_1_COMPONENT
import com.android.cts.packagemanager.verify.domain.android.DomainUtils.DECLARING_PKG_2_COMPONENT
import com.android.cts.packagemanager.verify.domain.android.DomainVerificationIntentTestBase
import com.android.cts.packagemanager.verify.domain.java.DomainUtils.DECLARING_PKG_NAME_1
import com.android.cts.packagemanager.verify.domain.java.DomainUtils.DECLARING_PKG_NAME_2
import com.android.cts.packagemanager.verify.domain.java.DomainUtils.DOMAIN_1
import com.android.cts.packagemanager.verify.domain.java.DomainUtils.DOMAIN_2
import com.google.common.truth.Truth.assertThat
import org.junit.Assume.assumeTrue
import org.junit.BeforeClass
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.Parameterized

@RunWith(Parameterized::class)
class DomainVerificationIntentStandaloneTests : DomainVerificationIntentTestBase(DOMAIN_1) {

    companion object {
        @JvmStatic
        @BeforeClass
        fun assumeAtLeastS() {
            assumeTrue(ApiLevelUtil.isAtLeast(Build.VERSION_CODES.S))
        }
    }

    @Test
    fun launchVerified() {
        setAppLinks(DECLARING_PKG_NAME_1, true, DOMAIN_1, DOMAIN_2)

        val hostToStateMap = manager.getDomainVerificationUserState(DECLARING_PKG_NAME_1)
            ?.hostToStateMap

        assertThat(hostToStateMap?.get(DOMAIN_1))
            .isEqualTo(DomainVerificationUserState.DOMAIN_STATE_VERIFIED)

        // The 2nd domain isn't marked as auto verify
        assertThat(hostToStateMap?.get(DOMAIN_2))
            .isEqualTo(DomainVerificationUserState.DOMAIN_STATE_NONE)

        assertResolvesTo(DECLARING_PKG_1_COMPONENT)

        setAppLinks(DECLARING_PKG_NAME_1, false, DOMAIN_1, DOMAIN_2)

        assertResolvesTo(browsers)
    }

    @Test
    fun launchSelected() {
        setAppLinks(DECLARING_PKG_NAME_1, false, DOMAIN_1, DOMAIN_2)
        setAppLinksUserSelection(DECLARING_PKG_NAME_1, userId, true, DOMAIN_1, DOMAIN_2)

        val hostToStateMap = manager.getDomainVerificationUserState(DECLARING_PKG_NAME_1)
            ?.hostToStateMap

        assertThat(hostToStateMap?.get(DOMAIN_1))
            .isEqualTo(DomainVerificationUserState.DOMAIN_STATE_SELECTED)
        assertThat(hostToStateMap?.get(DOMAIN_2))
            .isEqualTo(DomainVerificationUserState.DOMAIN_STATE_SELECTED)

        assertResolvesTo(DECLARING_PKG_1_COMPONENT)

        setAppLinksUserSelection(DECLARING_PKG_NAME_1, userId, false, DOMAIN_1, DOMAIN_2)

        assertResolvesTo(browsers)
    }

    @CtsDownstreamingTest
    @Test
    fun launchSelectedPreservedOnUpdate() {
        setAppLinks(DECLARING_PKG_NAME_1, false, DOMAIN_1, DOMAIN_2)
        setAppLinksUserSelection(DECLARING_PKG_NAME_1, userId, true, DOMAIN_1, DOMAIN_2)

        val hostToStateMapBefore = manager.getDomainVerificationUserState(DECLARING_PKG_NAME_1)
            ?.hostToStateMap

        assertThat(hostToStateMapBefore?.get(DOMAIN_1))
            .isEqualTo(DomainVerificationUserState.DOMAIN_STATE_SELECTED)
        assertThat(hostToStateMapBefore?.get(DOMAIN_2))
            .isEqualTo(DomainVerificationUserState.DOMAIN_STATE_SELECTED)

        assertResolvesTo(DECLARING_PKG_1_COMPONENT)

        assertThat(
            SystemUtil.runShellCommand(
                "pm install -r -t /data/local/tmp/CtsDomainVerificationTestDeclaringApp1.apk"
            ).trim()
        ).isEqualTo("Success")

        val hostToStateMapAfter = manager.getDomainVerificationUserState(DECLARING_PKG_NAME_1)
            ?.hostToStateMap

        assertThat(hostToStateMapAfter?.get(DOMAIN_1))
            .isEqualTo(DomainVerificationUserState.DOMAIN_STATE_SELECTED)
        assertThat(hostToStateMapAfter?.get(DOMAIN_2))
            .isEqualTo(DomainVerificationUserState.DOMAIN_STATE_SELECTED)

        assertResolvesTo(DECLARING_PKG_1_COMPONENT)
    }

    @Test
    fun verifiedOverSelected() {
        setAppLinksUserSelection(DECLARING_PKG_NAME_1, userId, true, DOMAIN_1, DOMAIN_2)

        assertResolvesTo(DECLARING_PKG_1_COMPONENT)

        setAppLinks(DECLARING_PKG_NAME_2, true, DOMAIN_1, DOMAIN_2)

        assertResolvesTo(DECLARING_PKG_2_COMPONENT)

        setAppLinks(DECLARING_PKG_NAME_2, false, DOMAIN_1, DOMAIN_2)

        // Assert that if 2 is approved and denied,
        // 1 will lose approval and must be re-enabled manually
        assertResolvesTo(browsers)
    }

    @Test
    fun selectedOverSelected() {
        setAppLinksUserSelection(DECLARING_PKG_NAME_1, userId, true, DOMAIN_1, DOMAIN_2)

        assertResolvesTo(DECLARING_PKG_1_COMPONENT)

        setAppLinksUserSelection(DECLARING_PKG_NAME_2, userId, true, DOMAIN_1, DOMAIN_2)

        assertResolvesTo(DECLARING_PKG_2_COMPONENT)

        setAppLinksUserSelection(DECLARING_PKG_NAME_2, userId, false, DOMAIN_1, DOMAIN_2)

        // Assert that if 2 is enabled and disabled,
        // 1 will lose approval and must be re-enabled manually
        assertResolvesTo(browsers)
    }

    @Test
    fun selectedOverVerifiedFails() {
        setAppLinks(DECLARING_PKG_NAME_1, true, DOMAIN_1, DOMAIN_2)

        assertResolvesTo(DECLARING_PKG_1_COMPONENT)

        setAppLinksUserSelection(DECLARING_PKG_NAME_2, userId, true, DOMAIN_1, DOMAIN_2)

        assertResolvesTo(DECLARING_PKG_1_COMPONENT)
    }

    @Test
    fun disableHandlingWhenVerified() {
        setAppLinks(DECLARING_PKG_NAME_1, true, DOMAIN_1, DOMAIN_2)

        assertResolvesTo(DECLARING_PKG_1_COMPONENT)

        setAppLinksAllowed(DECLARING_PKG_NAME_1, userId, false)

        assertResolvesTo(browsers)
    }

    @CtsDownstreamingTest
    @Test
    fun disableHandlingWhenVerifiedPreservedOnUpdate() {
        setAppLinks(DECLARING_PKG_NAME_1, true, DOMAIN_1, DOMAIN_2)

        assertResolvesTo(DECLARING_PKG_1_COMPONENT)

        setAppLinksAllowed(DECLARING_PKG_NAME_1, userId, false)

        assertResolvesTo(browsers)

        assertThat(
            SystemUtil.runShellCommand(
                "pm install -r -t /data/local/tmp/CtsDomainVerificationTestDeclaringApp1.apk"
            ).trim()
        ).isEqualTo("Success")

        assertResolvesTo(browsers)
    }

    @Test
    fun disableHandlingWhenSelected() {
        setAppLinksUserSelection(DECLARING_PKG_NAME_1, userId, true, DOMAIN_1, DOMAIN_2)

        assertResolvesTo(DECLARING_PKG_1_COMPONENT)

        setAppLinksAllowed(DECLARING_PKG_NAME_1, userId, false)

        assertResolvesTo(browsers)
    }

    @CtsDownstreamingTest
    @Test
    fun disableHandlingWhenSelectedPreservedOnUpdate() {
        setAppLinksUserSelection(DECLARING_PKG_NAME_1, userId, true, DOMAIN_1, DOMAIN_2)

        assertResolvesTo(DECLARING_PKG_1_COMPONENT)

        setAppLinksAllowed(DECLARING_PKG_NAME_1, userId, false)

        assertResolvesTo(browsers)

        assertThat(
            SystemUtil.runShellCommand(
                "pm install -r -t /data/local/tmp/CtsDomainVerificationTestDeclaringApp1.apk"
            ).trim()
        ).isEqualTo("Success")

        assertResolvesTo(browsers)
    }
}
