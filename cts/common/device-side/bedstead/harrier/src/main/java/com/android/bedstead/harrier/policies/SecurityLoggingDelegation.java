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
import static com.android.bedstead.harrier.annotations.enterprise.EnterprisePolicy.APPLIES_TO_OWN_USER;

import android.app.admin.DevicePolicyManager;
import android.content.ComponentName;

import com.android.bedstead.harrier.annotations.enterprise.EnterprisePolicy;

import java.util.List;

/**
 * Policy for security logging delegation.
 *
 * <p>This is used for methods such as {@link
 * DevicePolicyManager#setDelegatedScopes(ComponentName, String, List)} with scope {@link
 * DevicePolicyManager#DELEGATION_SECURITY_LOGGING}.
 */
// TODO(b/198774281): COPE profile POs can call this too, but we need to add the flag.
@EnterprisePolicy(dpc = {APPLIED_BY_DEVICE_OWNER | APPLIES_TO_OWN_USER})
public final class SecurityLoggingDelegation {
}
