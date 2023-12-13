/*
 * Copyright (C) 2019 The Android Open Source Project
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

package com.android.tv.twopanelsettings.slices;

import android.content.Context;
import android.text.TextUtils;
import android.util.AttributeSet;
import android.view.View;

import androidx.preference.PreferenceViewHolder;
import androidx.preference.SwitchPreference;
import androidx.slice.core.SliceActionImpl;

/**
 * Slices version of SwitchPreference.
 */
public class SliceSwitchPreference extends SwitchPreference implements HasSliceAction,
        HasCustomContentDescription {

    private int mActionId;
    protected SliceActionImpl mAction;
    private SliceActionImpl mFollowupSliceAction;
    private String mContentDescription;

    public SliceSwitchPreference(Context context, SliceActionImpl action) {
        super(context);
        mAction = action;
        update();
    }

    public SliceSwitchPreference(Context context, AttributeSet attrs, SliceActionImpl action) {
        super(context, attrs);
        mAction = action;
        update();
    }

    @Override
    public void onBindViewHolder(PreferenceViewHolder holder) {
        super.onBindViewHolder(holder);
        if (!TextUtils.isEmpty(mContentDescription)) {
            holder.itemView.setAccessibilityLiveRegion(View.ACCESSIBILITY_LIVE_REGION_POLITE);
            holder.itemView.setContentDescription(
                    CustomContentDescriptionUtil.getFullSwitchContentDescription(
                            getContext(), mContentDescription, this.isChecked()));
        }
    }

    @Override
    public int getActionId() {
        return mActionId;
    }

    @Override
    public void setActionId(int actionId) {
        mActionId = actionId;
    }

    public SliceSwitchPreference(Context context) {
        super(context);
    }

    public SliceSwitchPreference(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    @Override
    public SliceActionImpl getSliceAction() {
        return mAction;
    }

    @Override
    public void setSliceAction(SliceActionImpl sliceAction) {
        mAction = sliceAction;
    }

    @Override
    public SliceActionImpl getFollowupSliceAction() {
        return mFollowupSliceAction;
    }

    @Override
    public void setFollowupSliceAction(SliceActionImpl sliceAction) {
        mFollowupSliceAction = sliceAction;
    }

    private void update() {
        this.setChecked(mAction.isChecked());
    }

    /**
     * Sets the accessibility content description that will be read to the TalkBack users when they
     * focus on this preference.
     */
    public void setContentDescription(String contentDescription) {
        this.mContentDescription = contentDescription;
    }

    public String getContentDescription() {
        return this.mContentDescription;
    }

}
