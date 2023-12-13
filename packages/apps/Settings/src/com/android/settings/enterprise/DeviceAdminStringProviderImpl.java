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

package com.android.settings.enterprise;

import static java.util.Objects.requireNonNull;

import android.content.Context;

import com.android.settings.R;
import com.android.settingslib.enterprise.DeviceAdminStringProvider;

class DeviceAdminStringProviderImpl implements DeviceAdminStringProvider {
    private final Context mContext;

    DeviceAdminStringProviderImpl(Context context) {
        mContext = requireNonNull(context);
    }

    @Override
    public String getDefaultDisabledByPolicyTitle() {
        return mContext.getString(R.string.disabled_by_policy_title);
    }

    @Override
    public String getDisallowAdjustVolumeTitle() {
        return mContext.getString(R.string.disabled_by_policy_title_adjust_volume);
    }

    @Override
    public String getDisallowOutgoingCallsTitle() {
        return mContext.getString(R.string.disabled_by_policy_title_outgoing_calls);
    }

    @Override
    public String getDisallowSmsTitle() {
        return mContext.getString(R.string.disabled_by_policy_title_sms);
    }

    @Override
    public String getDisableCameraTitle() {
        return mContext.getString(R.string.disabled_by_policy_title_camera);
    }

    @Override
    public String getDisableScreenCaptureTitle() {
        return mContext.getString(R.string.disabled_by_policy_title_screen_capture);
    }

    @Override
    public String getSuspendPackagesTitle() {
        return mContext.getString(R.string.disabled_by_policy_title_suspend_packages);
    }

    @Override
    public String getDefaultDisabledByPolicyContent() {
        return mContext.getString(R.string.default_admin_support_msg);
    }

    @Override
    public String getLearnMoreHelpPageUrl() {
        return mContext.getString(R.string.help_url_action_disabled_by_it_admin);
    }

    @Override
    public String getDisabledByPolicyTitleForFinancedDevice() {
        return mContext.getString(R.string.disabled_by_policy_title_financed_device);
    }

    @Override
    public String getDisabledBiometricsParentConsentTitle() {
        return mContext.getString(R.string.disabled_by_policy_title_biometric_parental_consent);
    }

    @Override
    public String getDisabledBiometricsParentConsentContent() {
        return mContext.getString(R.string.disabled_by_policy_content_biometric_parental_consent);
    }
}
