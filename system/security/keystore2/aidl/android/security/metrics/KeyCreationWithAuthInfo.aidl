/*
 * Copyright 2021, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package android.security.metrics;

import android.security.metrics.HardwareAuthenticatorType;
import android.security.metrics.SecurityLevel;

/**
 * Atom that encapsulates authentication related information in key creation events.
 * @hide
 */
@RustDerive(Clone=true, Eq=true, PartialEq=true, Ord=true, PartialOrd=true, Hash=true)
parcelable KeyCreationWithAuthInfo {
    HardwareAuthenticatorType user_auth_type;
    /**
     * Base 10 logarithm of time out in seconds.
     * Logarithm is taken in order to reduce the cardinaltiy.
     */
    int log10_auth_key_timeout_seconds;
    SecurityLevel security_level;
}