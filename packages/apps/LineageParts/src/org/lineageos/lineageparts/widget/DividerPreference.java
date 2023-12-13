/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed under the
 * License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

package org.lineageos.lineageparts.widget;

import android.content.Context;
import android.content.res.TypedArray;
import android.util.AttributeSet;

import androidx.preference.Preference;
import androidx.preference.PreferenceViewHolder;

import org.lineageos.lineageparts.R;

public class DividerPreference extends Preference {

    private Boolean mAllowAbove;
    private Boolean mAllowBelow;

    public DividerPreference(Context context, AttributeSet attrs) {
        super(context, attrs);
        TypedArray a = context.obtainStyledAttributes(attrs, R.styleable.DividerPreference, 0, 0);
        if (a.hasValue(R.styleable.DividerPreference_allowDividerAbove)) {
            mAllowAbove = a.getBoolean(R.styleable.DividerPreference_allowDividerAbove, false);
        }
        if (a.hasValue(R.styleable.DividerPreference_allowDividerBelow)) {
            mAllowBelow = a.getBoolean(R.styleable.DividerPreference_allowDividerBelow, false);
        }
        a.recycle();
    }

    public DividerPreference(Context context) {
        this(context, null);
    }

    public void setDividerAllowedAbove(boolean allowed) {
        mAllowAbove = allowed;
        notifyChanged();
    }

    public void setDividerAllowedBelow(boolean allowed) {
        mAllowBelow = allowed;
        notifyChanged();
    }

    @Override
    public void onBindViewHolder(PreferenceViewHolder holder) {
        super.onBindViewHolder(holder);
        if (mAllowAbove != null) {
            holder.setDividerAllowedAbove(mAllowAbove);
        }
        if (mAllowBelow != null) {
            holder.setDividerAllowedBelow(mAllowBelow);
        }
    }
}
