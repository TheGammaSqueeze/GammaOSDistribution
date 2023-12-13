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

package com.android.car.settings.location;

import android.car.drivingstate.CarUxRestrictions;
import android.content.Context;
import android.location.LocationManager;

import androidx.preference.PreferenceGroup;

import com.android.car.settings.common.FragmentController;
import com.android.car.settings.common.PreferenceController;

/**
 * Controller for displaying {@link AdasLocationSwitchSubMenuPreference} and a preference divider.
 */
public class AdasGroupPreferenceController extends PreferenceController<PreferenceGroup> {

    private final LocationManager mLocationManager;

    public AdasGroupPreferenceController(Context context, String preferenceKey,
            FragmentController fragmentController, CarUxRestrictions uxRestrictions) {
        super(context, preferenceKey, fragmentController, uxRestrictions);
        mLocationManager = context.getSystemService(LocationManager.class);
    }

    @Override
    protected Class<PreferenceGroup> getPreferenceType() {
        return PreferenceGroup.class;
    }

    @Override
    protected int getAvailabilityStatus() {
        return mLocationManager.isAdasGnssLocationEnabled() ? UNSUPPORTED_ON_DEVICE : AVAILABLE;
    }
}
