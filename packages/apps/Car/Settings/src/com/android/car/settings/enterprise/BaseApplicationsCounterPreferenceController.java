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
package com.android.car.settings.enterprise;

import android.annotation.Nullable;
import android.car.drivingstate.CarUxRestrictions;
import android.content.Context;

import androidx.preference.Preference;

import com.android.car.settings.common.FragmentController;
import com.android.car.settings.enterprise.CallbackTranslator.AppsCounterCallbackTranslator;
import com.android.car.settings.enterprise.CallbackTranslator.Callback;
import com.android.car.settingslib.applications.ApplicationFeatureProvider;

/**
 * Base class for controllers that shows a number of apps in the Enterprise Privacy /
 * Managed Device Info screen.
 *
 * <p>The counter is calculated asynchronously.
 */
abstract class BaseApplicationsCounterPreferenceController<P extends Preference>
        extends BaseAsyncPreferenceController<P, Integer, AppsCounterCallbackTranslator> {

    protected BaseApplicationsCounterPreferenceController(Context context,
            String preferenceKey, FragmentController fragmentController,
            CarUxRestrictions uxRestrictions,
            @Nullable ApplicationFeatureProvider applicationFeatureProvider) {
        super(context, preferenceKey, fragmentController, uxRestrictions,
                applicationFeatureProvider);
    }

    @Override
    protected AppsCounterCallbackTranslator newCallbackTranslator(Callback<Integer> callback) {
        return new AppsCounterCallbackTranslator(callback);
    }

    @Override
    protected boolean isAvailable(Integer result) {
        return result > 0;
    }
}
