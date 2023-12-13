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

package com.android.bedstead.harrier.policies;

import static android.app.admin.DevicePolicyManager.DELEGATION_APP_RESTRICTIONS;

import static com.android.bedstead.harrier.annotations.enterprise.EnterprisePolicy.APPLIED_BY_DEVICE_OWNER;
import static com.android.bedstead.harrier.annotations.enterprise.EnterprisePolicy.APPLIED_BY_PROFILE_OWNER;
import static com.android.bedstead.harrier.annotations.enterprise.EnterprisePolicy.APPLIES_IN_BACKGROUND;
import static com.android.bedstead.harrier.annotations.enterprise.EnterprisePolicy.APPLIES_TO_OWN_USER;
import static com.android.bedstead.harrier.annotations.enterprise.EnterprisePolicy.CAN_BE_DELEGATED;

import android.app.admin.DevicePolicyManager;
import android.content.ComponentName;
import android.os.Bundle;

import com.android.bedstead.harrier.annotations.enterprise.EnterprisePolicy;

/**
 * Policy for application restrictions.
 *
 * <p>This is used by methods such as
 * {@link DevicePolicyManager#setApplicationRestrictions(ComponentName, String, Bundle)} and
 * {@link DevicePolicyManager#getApplicationRestrictions(ComponentName, String)}.
 */
@EnterprisePolicy(
        dpc = {
            APPLIED_BY_DEVICE_OWNER | APPLIES_TO_OWN_USER | APPLIES_IN_BACKGROUND | CAN_BE_DELEGATED,
            APPLIED_BY_PROFILE_OWNER | APPLIES_TO_OWN_USER | CAN_BE_DELEGATED},
        delegatedScopes = DELEGATION_APP_RESTRICTIONS
        )
public final class ApplicationRestrictions {
}