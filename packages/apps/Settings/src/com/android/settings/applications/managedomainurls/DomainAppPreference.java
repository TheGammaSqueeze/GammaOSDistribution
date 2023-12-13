/*
 * Copyright (C) 2018 The Android Open Source Project
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

package com.android.settings.applications.managedomainurls;

import android.content.Context;
import android.content.pm.verify.domain.DomainVerificationManager;
import android.content.pm.verify.domain.DomainVerificationUserState;
import android.util.IconDrawableFactory;

import com.android.settings.R;
import com.android.settings.applications.intentpicker.IntentPickerUtils;
import com.android.settingslib.applications.ApplicationsState.AppEntry;
import com.android.settingslib.widget.AppPreference;

public class DomainAppPreference extends AppPreference {

    private final AppEntry mEntry;
    private final DomainVerificationManager mDomainVerificationManager;
    private final IconDrawableFactory mIconDrawableFactory;

    public DomainAppPreference(final Context context, IconDrawableFactory iconFactory,
            AppEntry entry) {
        super(context);
        mIconDrawableFactory = iconFactory;
        mDomainVerificationManager = context.getSystemService(DomainVerificationManager.class);
        mEntry = entry;
        mEntry.ensureLabel(getContext());

        setState();
    }

    public void reuse() {
        setState();
        notifyChanged();
    }

    public AppEntry getEntry() {
        return mEntry;
    }

    private void setState() {
        setTitle(mEntry.label);
        setIcon(mIconDrawableFactory.getBadgedIcon(mEntry.info));
        setSummary(getDomainsSummary(mEntry.info.packageName));
    }

    private CharSequence getDomainsSummary(String packageName) {
        return getContext().getText(isLinkHandlingAllowed(packageName)
                ? R.string.app_link_open_always : R.string.app_link_open_never);
    }

    private boolean isLinkHandlingAllowed(String packageName) {
        final DomainVerificationUserState userState =
                IntentPickerUtils.getDomainVerificationUserState(mDomainVerificationManager,
                        packageName);
        return userState == null ? false : userState.isLinkHandlingAllowed();
    }
}
