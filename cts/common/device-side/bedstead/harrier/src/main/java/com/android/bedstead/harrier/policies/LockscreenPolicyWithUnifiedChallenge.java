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

import static com.android.bedstead.harrier.annotations.enterprise.EnterprisePolicy.APPLIED_BY_DEVICE_OWNER;
import static com.android.bedstead.harrier.annotations.enterprise.EnterprisePolicy.APPLIED_BY_PROFILE_OWNER;
import static com.android.bedstead.harrier.annotations.enterprise.EnterprisePolicy.APPLIES_TO_OWN_USER;
import static com.android.bedstead.harrier.annotations.enterprise.EnterprisePolicy.APPLIES_TO_PARENT;

import android.app.admin.DevicePolicyManager;
import android.content.ComponentName;

import com.android.bedstead.harrier.annotations.enterprise.EnterprisePolicy;

/**
 * Lockscreen policies, e.g. password quality, length, history length, attempts before wipe.
 * Parent profile is affected only when work profile has unified challenge (i.e. no separate lock),
 * which is why this policy has to be specific to this case.
 *
 * <p>This is used by methods such as
 * {@link DevicePolicyManager#setPasswordQuality(ComponentName, int)}
 */
@EnterprisePolicy(dpc = {APPLIED_BY_DEVICE_OWNER | APPLIES_TO_OWN_USER,
        APPLIED_BY_PROFILE_OWNER | APPLIES_TO_OWN_USER | APPLIES_TO_PARENT})
public class LockscreenPolicyWithUnifiedChallenge {
}
