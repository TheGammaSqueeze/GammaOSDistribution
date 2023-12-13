/*
 * Copyright 2022 The Android Open Source Project
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

package com.android.car.ui.preference;

import android.content.Context;
import android.util.AttributeSet;
import android.view.View;

import androidx.preference.PreferenceViewHolder;

import com.android.car.ui.R;

/**
 * This class is the same as the base {@link CarUiSwitchPreference} class, except supports separate
 * distinguishing styling.
 */
public class CarUiPrimarySwitchPreference extends CarUiSwitchPreference {
    private View mItemView;

    public CarUiPrimarySwitchPreference(Context context,
            AttributeSet attrs,
            int defStyleAttr, int defStyleRes) {
        super(context, attrs, defStyleAttr, defStyleRes);
        init();
    }

    public CarUiPrimarySwitchPreference(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        init();
    }

    public CarUiPrimarySwitchPreference(Context context, AttributeSet attrs) {
        super(context, attrs);
        init();
    }

    public CarUiPrimarySwitchPreference(Context context) {
        super(context);
        init();
    }

    private void init() {
        setLayoutResource(R.layout.car_ui_preference_primary_switch);
    }

    @Override
    public void onBindViewHolder(PreferenceViewHolder holder) {
        super.onBindViewHolder(holder);
        mItemView = holder.itemView;
        mItemView.setActivated(isChecked());
    }

    @Override
    public void setChecked(boolean checked) {
        super.setChecked(checked);
        if (mItemView != null) {
            mItemView.setActivated(checked);
        }
    }
}
