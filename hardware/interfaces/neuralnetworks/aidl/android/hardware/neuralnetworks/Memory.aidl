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

package android.hardware.neuralnetworks;

import android.hardware.common.Ashmem;
import android.hardware.common.MappableFile;
import android.hardware.graphics.common.HardwareBuffer;

/**
 * The different types of memory that can be shared across processes.
 */
@VintfStability
union Memory {
    /**
     * Ashmem hidl_memory type from HIDL.
     */
    Ashmem ashmem;
    /**
     * File that can be mapped.
     */
    MappableFile mappableFile;
    /**
     * AIDL representation of AHardwareBuffer.
     */
    HardwareBuffer hardwareBuffer;
}
