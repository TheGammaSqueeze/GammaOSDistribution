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

package android.ext.services.displayhash;

import android.hardware.HardwareBuffer;
import android.os.Build;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.annotation.RequiresApi;
import androidx.annotation.Size;

@RequiresApi(Build.VERSION_CODES.S)
class ImageHashManager {
    static {
        System.loadLibrary("extservices_jni");
    }

    ImageHashManager() {}

    private static native byte[] nativeGenerateHash(HardwareBuffer hardwareBuffer,
            String hashAlgorithm);

    @Nullable
    @Size(8) byte[] generateHash(@NonNull HardwareBuffer hardwareBuffer, String hashAlgorithm) {
        return nativeGenerateHash(hardwareBuffer, hashAlgorithm);
    }
}
