/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed under the
 * License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */
package com.android.settings.enterprise;

import android.content.Context;

import androidx.preference.Preference;

import com.android.internal.annotations.VisibleForTesting;
import com.android.settings.core.PreferenceControllerMixin;
import com.android.settingslib.core.AbstractPreferenceController;

import java.util.Objects;

public class EnterprisePrivacyPreferenceController extends AbstractPreferenceController implements
        PreferenceControllerMixin {

    private static final String KEY_ENTERPRISE_PRIVACY = "enterprise_privacy";
    private final PrivacyPreferenceControllerHelper mPrivacyPreferenceControllerHelper;
    private final String mPreferenceKey;

    public EnterprisePrivacyPreferenceController(Context context) {
        this(Objects.requireNonNull(context), KEY_ENTERPRISE_PRIVACY);
    }

    public EnterprisePrivacyPreferenceController(Context context, String key) {
        this(Objects.requireNonNull(context), new PrivacyPreferenceControllerHelper(context), key);
    }

    @VisibleForTesting
    EnterprisePrivacyPreferenceController(Context context,
            PrivacyPreferenceControllerHelper privacyPreferenceControllerHelper, String key) {
        super(Objects.requireNonNull(context));
        mPrivacyPreferenceControllerHelper = Objects.requireNonNull(
                privacyPreferenceControllerHelper);
        this.mPreferenceKey = key;
    }

    @Override
    public void updateState(Preference preference) {
        mPrivacyPreferenceControllerHelper.updateState(preference);
    }

    @Override
    public boolean isAvailable() {
        return mPrivacyPreferenceControllerHelper.hasDeviceOwner()
                && !mPrivacyPreferenceControllerHelper.isFinancedDevice();
    }

    @Override
    public String getPreferenceKey() {
        return mPreferenceKey;
    }
}
