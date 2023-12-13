/*
 * Copyright (C) 2022 The Android Open Source Project
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

package com.android.car.settings.common;

import android.content.Context;
import android.util.AttributeSet;
import android.widget.LinearLayout;

import androidx.preference.PreferenceViewHolder;

import com.android.settingslib.widget.FooterPreference;

/**
 * FooterPreference class that supports "Learn more" button, customized for Car.
 */
public final class CarFooterPreference extends FooterPreference {

    public CarFooterPreference(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    public CarFooterPreference(Context context) {
        this(context, null);
    }

    @Override
    public void onBindViewHolder(PreferenceViewHolder holder) {
        super.onBindViewHolder(holder);

        // Car-specific customizations, such as showing the "i" icon on the side.
        ((LinearLayout) holder.itemView).setOrientation(LinearLayout.HORIZONTAL);
    }
}
