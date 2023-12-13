/*
 * Copyright 2019 The Android Open Source Project
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

import static com.android.car.ui.core.CarUi.MIN_TARGET_API;

import android.annotation.TargetApi;
import android.content.Context;
import android.content.res.TypedArray;
import android.util.AttributeSet;

import androidx.annotation.Nullable;
import androidx.preference.MultiSelectListPreference;
import androidx.preference.Preference;
import androidx.preference.PreferenceViewHolder;

import com.android.car.ui.R;
import com.android.car.ui.utils.CarUiUtils;

import java.util.function.Consumer;

/**
 * This class extends the base {@link CarUiMultiSelectListPreference} class. Adds the drawable icon
 * to the preference.
 */
@SuppressWarnings("AndroidJdkLibsChecker")
@TargetApi(MIN_TARGET_API)
public class CarUiMultiSelectListPreference extends MultiSelectListPreference
        implements UxRestrictablePreference {

    private Consumer<Preference> mRestrictedClickListener;
    private boolean mUxRestricted = false;

    public CarUiMultiSelectListPreference(Context context) {
        this(context, null);
    }

    public CarUiMultiSelectListPreference(Context context, AttributeSet attrs) {
        this(context, attrs, R.attr.carUiPreferenceStyle);
    }

    public CarUiMultiSelectListPreference(Context context, AttributeSet attrs, int defStyle) {
        this(context, attrs, defStyle, R.style.Preference_CarUi_Preference);
    }

    public CarUiMultiSelectListPreference(Context context, AttributeSet attrs, int defStyleAttr,
            int defStyleRes) {
        super(context, attrs, defStyleAttr, defStyleRes);
        init(attrs, defStyleAttr, defStyleRes);
    }

    private void init(AttributeSet attrs, int defStyleAttr, int defStyleRes) {
        TypedArray a = getContext().obtainStyledAttributes(
                attrs,
                R.styleable.CarUiPreference,
                defStyleAttr,
                defStyleRes);

        mUxRestricted = a.getBoolean(R.styleable.CarUiPreference_car_ui_ux_restricted, false);
        a.recycle();
    }

    /**
     * This is to make getSelectedItems() visible from other classes in
     * com.android.car.ui.preference.
     */
    @Override
    protected boolean[] getSelectedItems() {
        return super.getSelectedItems();
    }

    @Override
    public void onAttached() {
        super.onAttached();

        boolean showChevron = getContext().getResources().getBoolean(
                R.bool.car_ui_preference_show_chevron);

        if (!showChevron) {
            return;
        }

        setWidgetLayoutResource(R.layout.car_ui_preference_chevron);
    }

    @Override
    public void onBindViewHolder(PreferenceViewHolder holder) {
        super.onBindViewHolder(holder);

        CarUiUtils.makeAllViewsUxRestricted(holder.itemView, isUxRestricted());
    }

    @Override
    @SuppressWarnings("RestrictTo")
    public void performClick() {
        if ((isEnabled() || isSelectable()) && isUxRestricted()) {
            if (mRestrictedClickListener != null) {
                mRestrictedClickListener.accept(this);
            }
        } else {
            super.performClick();
        }
    }

    @Override
    public void setUxRestricted(boolean restricted) {
        if (restricted != mUxRestricted) {
            mUxRestricted = restricted;
            notifyChanged();
        }
    }

    @Override
    public boolean isUxRestricted() {
        return mUxRestricted;
    }

    @Override
    public void setOnClickWhileRestrictedListener(@Nullable Consumer<Preference> listener) {
        mRestrictedClickListener = listener;
    }

    @Nullable
    @Override
    public Consumer<Preference> getOnClickWhileRestrictedListener() {
        return mRestrictedClickListener;
    }
}
