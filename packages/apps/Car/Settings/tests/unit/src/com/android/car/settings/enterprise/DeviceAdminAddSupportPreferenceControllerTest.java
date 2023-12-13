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
package com.android.car.settings.enterprise;

import androidx.preference.Preference;

import com.android.car.settings.common.PreferenceController;

import org.junit.Before;
import org.junit.Test;
import org.mockito.Mock;

public final class DeviceAdminAddSupportPreferenceControllerTest extends
        BaseEnterprisePreferenceControllerTestCase {

    @Mock
    private Preference mPreference;

    private DeviceAdminAddSupportPreferenceController mController;

    @Before
    public void setController() {
        mController = new DeviceAdminAddSupportPreferenceController(mSpiedContext,
                mPreferenceKey, mFragmentController, mUxRestrictions);
        mController.setDeviceAdmin(mDefaultDeviceAdminInfo);
    }

    @Test
    public void testGetAvailabilityStatus_noAdmin() throws Exception {
        DeviceAdminAddSupportPreferenceController controller =
                new DeviceAdminAddSupportPreferenceController(mSpiedContext, mPreferenceKey,
                        mFragmentController, mUxRestrictions);

        assertAvailability(controller.getAvailabilityStatus(),
                PreferenceController.CONDITIONALLY_UNAVAILABLE);
    }

    @Test
    public void testGetAvailabilityStatus_nullMessage() {
        mockGetLongSupportMessageForUser(null);

        assertAvailability(mController.getAvailabilityStatus(),
                PreferenceController.CONDITIONALLY_UNAVAILABLE);
    }

    @Test
    public void testGetAvailabilityStatus_emptyMessage() {
        mockGetLongSupportMessageForUser("");

        assertAvailability(mController.getAvailabilityStatus(),
                PreferenceController.CONDITIONALLY_UNAVAILABLE);
    }

    @Test
    public void testGetAvailabilityStatus_validMessage() {
        mockGetLongSupportMessageForUser("WHAZZZZUP");

        assertAvailability(mController.getAvailabilityStatus(), PreferenceController.AVAILABLE);
    }

    @Test
    public void testUpdateState() {
        mockGetLongSupportMessageForUser("WHAZZZZUP");
        mController.setSupportMessage();

        mController.updateState(mPreference);

        verifyPreferenceTitleSet(mPreference, "WHAZZZZUP");
    }
}
