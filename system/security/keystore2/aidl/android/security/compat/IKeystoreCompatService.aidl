/*
 * Copyright (C) 2020 The Android Open Source Project
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

package android.security.compat;

import android.hardware.security.keymint.IKeyMintDevice;
import android.hardware.security.keymint.SecurityLevel;
import android.hardware.security.secureclock.ISecureClock;
import android.hardware.security.sharedsecret.ISharedSecret;

/**
 * The compatibility service allows Keystore 2.0 to connect to legacy wrapper implementations that
 * it hosts itself without registering them as a service. Keystore 2.0 would not be allowed to
 * register a HAL service, so instead it registers this service which it can then connect to.
 * @hide
 */
interface IKeystoreCompatService {
    /**
     * Return an implementation of IKeyMintDevice, that it implemented by Keystore 2.0 itself
     * by means of Keymaster 4.1 or lower.
     */
    IKeyMintDevice getKeyMintDevice (SecurityLevel securityLevel);

    /**
     * Returns an implementation of ISecureClock, that is implemented by Keystore 2.0 itself
     * by means of Keymaster 4.x.
     */
    ISecureClock getSecureClock ();

    /**
     * Returns an implementation of ISharedSecret, that is implemented by Keystore 2.0 itself
     * by means of Keymaster 4.x.
     */
    ISharedSecret getSharedSecret (SecurityLevel securityLevel);
}
