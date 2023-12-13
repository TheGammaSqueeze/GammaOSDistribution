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

import static com.android.car.settings.common.PreferenceController.AVAILABLE;
import static com.android.car.settings.common.PreferenceController.DISABLED_FOR_PROFILE;

import static org.mockito.Mockito.when;

import androidx.preference.Preference;

import com.android.car.settings.R;

import org.junit.Before;
import org.junit.Test;
import org.mockito.Mock;

public final class ImePreferenceControllerTest
        extends BaseEnterprisePrivacyPreferenceControllerTestCase {

    private ImePreferenceController mController;

    @Mock
    private Preference mPreference;

    @Before
    public void setUp() throws Exception {
        mController = new ImePreferenceController(mSpiedContext, mPreferenceKey,
                mFragmentController, mUxRestrictions, mEnterprisePrivacyFeatureProvider);
    }

    @Test
    public void testGetgetAvailabilityStatus_notSet() {
        mockHasDeviceAdminFeature();
        mockGetImeLabelIfOwnerSet(null);

        assertAvailability(mController.getAvailabilityStatus(), DISABLED_FOR_PROFILE);
    }

    @Test
    public void testGetgetAvailabilityStatus_set() {
        mockHasDeviceAdminFeature();
        mockGetImeLabelIfOwnerSet("Da Lablue");

        assertAvailability(mController.getAvailabilityStatus(), AVAILABLE);
    }

    @Test
    public void testUpdateState_set() {
        mockGetImeLabelIfOwnerSet("Da Lablue");

        mController.updateState(mPreference);

        String summary = mRealContext.getResources()
                .getString(R.string.enterprise_privacy_input_method_name, "Da Lablue");
        verifyPreferenceTitleNeverSet(mPreference);
        verifyPreferenceSummarySet(mPreference, summary);
        verifyPreferenceIconNeverSet(mPreference);
    }

    private void mockGetImeLabelIfOwnerSet(String label) {
        when(mEnterprisePrivacyFeatureProvider.getImeLabelIfOwnerSet()).thenReturn(label);
    }
}
