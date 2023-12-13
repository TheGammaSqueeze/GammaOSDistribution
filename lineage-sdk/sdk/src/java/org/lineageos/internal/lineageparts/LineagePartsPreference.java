/*
 * Copyright (C) 2016 The CyanogenMod Project
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
package org.lineageos.internal.lineageparts;

import android.content.Context;
import android.os.Bundle;
import android.util.AttributeSet;

import lineageos.preference.RemotePreference;

/**
 * A link to a remote preference screen which can be used with a minimum amount
 * of information. Supports summary updates asynchronously.
 */
public class LineagePartsPreference extends RemotePreference {

    private static final String TAG = "LineagePartsPreference";

    private final PartInfo mPart;

    private final Context mContext;

    public LineagePartsPreference(Context context, AttributeSet attrs,
                            int defStyle, int defStyleRes) {
        super(context, attrs, defStyle, defStyleRes);
        mContext = context;
        mPart = PartsList.get(context).getPartInfo(getKey());
        if (mPart == null) {
            throw new RuntimeException("Part not found: " + getKey());
        }

        updatePreference();
        setIntent(mPart.getIntentForActivity());
    }

    public LineagePartsPreference(Context context, AttributeSet attrs, int defStyle) {
        this(context, attrs, defStyle, 0);
    }

    public LineagePartsPreference(Context context, AttributeSet attrs) {
        this(context, attrs, androidx.preference.R.attr.preferenceStyle);
    }

    @Override
    public void onRemoteUpdated(Bundle bundle) {
        if (bundle.containsKey(PartsList.EXTRA_PART)) {
            PartInfo update = bundle.getParcelable(PartsList.EXTRA_PART);
            if (update != null) {
                mPart.updateFrom(update);
                updatePreference();
            }
        }
    }

    @Override
    protected String getRemoteKey(Bundle metaData) {
        // remote key is the same as ours
        return getKey();
    }

    private void updatePreference() {
        if (isAvailable() != mPart.isAvailable()) {
            setAvailable(mPart.isAvailable());
        }
        if (isAvailable()) {
            setTitle(mPart.getTitle());
            setSummary(mPart.getSummary());
        }
    }
}
