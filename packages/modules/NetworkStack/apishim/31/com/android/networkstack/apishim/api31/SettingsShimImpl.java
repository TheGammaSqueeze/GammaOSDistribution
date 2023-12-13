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

package com.android.networkstack.apishim.api31;

import android.content.Context;
import android.os.Build;
import android.provider.Settings;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.android.networkstack.apishim.common.SettingsShim;
import com.android.networkstack.apishim.common.ShimUtils;

/**
 * Implementation of {@link SettingsShim} for API 31.
 */
public class SettingsShimImpl
        extends com.android.networkstack.apishim.api30.SettingsShimImpl {
    protected SettingsShimImpl() { }

    /**
     * Get a new instance of {@link SettingsShim}.
     */
    public static SettingsShim newInstance() {
        if (!ShimUtils.isReleaseOrDevelopmentApiAbove(Build.VERSION_CODES.R)) {
            return com.android.networkstack.apishim.api30.SettingsShimImpl
                    .newInstance();
        }
        return new SettingsShimImpl();
    }

    @Override
    public boolean checkAndNoteWriteSettingsOperation(@NonNull Context context, int uid,
            @NonNull String callingPackage, @Nullable String callingAttributionTag,
            boolean throwException) {
        return Settings.checkAndNoteWriteSettingsOperation(context, uid, callingPackage,
                callingAttributionTag, throwException);
    }
}
