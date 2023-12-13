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

package com.android.settings.notification;

import android.content.ComponentName;
import android.content.Context;
import android.os.UserHandle;
import android.os.UserManager;
import android.provider.Settings;

import androidx.fragment.app.Fragment;

import com.android.settings.R;
import com.android.settings.core.TogglePreferenceController;

import com.google.common.annotations.VisibleForTesting;

public class NotificationAssistantPreferenceController extends TogglePreferenceController {
    private static final String TAG = "NASPreferenceController";
    private static final String KEY_NAS = "notification_assistant";

    private static final int AVAILABLE = 1;
    private final UserManager mUserManager;
    private Fragment mFragment;
    private int mUserId = UserHandle.myUserId();

    @VisibleForTesting
    protected NotificationBackend mNotificationBackend;

    public NotificationAssistantPreferenceController(Context context) {
        super(context, KEY_NAS);
        mUserManager = UserManager.get(context);
    }

    @Override
    public int getAvailabilityStatus() {
        return AVAILABLE;
    }

    @Override
    public boolean isChecked() {
        ComponentName acn = mNotificationBackend.getAllowedNotificationAssistant();
        ComponentName dcn = mNotificationBackend.getDefaultNotificationAssistant();
        return (acn != null && acn.equals(dcn));
    }

    @Override
    public boolean setChecked(boolean isChecked) {
        ComponentName cn = isChecked
                ? mNotificationBackend.getDefaultNotificationAssistant() : null;
        if (isChecked) {
            if (mFragment == null) {
                throw new IllegalStateException("No fragment to start activity");
            }
            showDialog(cn);
            return false;
        } else {
            setNotificationAssistantGranted(null);
            return true;
        }
    }

    @Override
    public int getSliceHighlightMenuRes() {
        return R.string.menu_key_notifications;
    }

    protected void setNotificationAssistantGranted(ComponentName cn) {
        if (Settings.Secure.getIntForUser(mContext.getContentResolver(),
                Settings.Secure.NAS_SETTINGS_UPDATED, 0, mUserId) == 0) {
            mNotificationBackend.setNASMigrationDoneAndResetDefault(mUserId, cn != null);
        }
        mNotificationBackend.setNotificationAssistantGranted(cn);
    }

    protected void showDialog(ComponentName cn) {
        NotificationAssistantDialogFragment dialogFragment =
                NotificationAssistantDialogFragment.newInstance(mFragment, cn);
        dialogFragment.show(mFragment.getFragmentManager(), TAG);
    }

    public void setFragment(Fragment fragment) {
        mFragment = fragment;
    }

    @VisibleForTesting
    void setBackend(NotificationBackend backend) {
        mNotificationBackend = backend;
    }
}