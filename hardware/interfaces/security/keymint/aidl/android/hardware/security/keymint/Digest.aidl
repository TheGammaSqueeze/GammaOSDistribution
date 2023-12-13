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

package android.hardware.security.keymint;

/**
 * Digests provided by keyMint implementations.
 * @hide
 */
@VintfStability
@Backing(type="int")
enum Digest {
    NONE = 0,
    MD5 = 1,
    SHA1 = 2,
    SHA_2_224 = 3,
    SHA_2_256 = 4,
    SHA_2_384 = 5,
    SHA_2_512 = 6,
}
