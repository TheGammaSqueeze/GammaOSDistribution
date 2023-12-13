/**
 * Copyright (c) 2020, The Android Open Source Project
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

package android.net.resolv.aidl;

/**
 * A private DNS validation result.
 *
 * {@hide}
 */
@JavaDerive(toString=true)
parcelable PrivateDnsValidationEventParcel {

    /** The ID of the network the validation was performed on. */
    int netId;

    /** The IP address for which validation was performed. */
    @utf8InCpp String ipAddress;

    /** The hostname for which validation was performed. */
    @utf8InCpp String hostname;

    /** The validation result. */
    int validation;
}
