/*
 * Copyright (C) 2020 The Android Open Source Project
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
package com.android.car.admin;

import static com.android.car.admin.CarDevicePolicyService.DEBUG;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.provider.Settings;
import android.util.Slog;
import android.widget.Button;

import com.android.car.CarLog;
import com.android.car.R;
import com.android.car.admin.ui.ManagedDeviceTextView;
import com.android.internal.annotations.VisibleForTesting;

/**
 * Shows a disclaimer dialog when a new user is added in a device that is managed by a device owner.
 *
 * <p>The dialog text will contain the message from
 * {@code ManagedDeviceTextView.getManagedDeviceText}.
 *
 * <p>The dialog contains two buttons: one to acknowlege the disclaimer; the other to launch
 * {@code Settings.ACTION_ENTERPRISE_PRIVACY_SETTINGS} for more details. Note: when
 * {@code Settings.ACTION_ENTERPRISE_PRIVACY_SETTINGS} is closed, the same dialog will be shown.
 *
 * <p>Clicking anywhere outside the dialog will dimiss the dialog.
 */
public final class NewUserDisclaimerActivity extends Activity {
    @VisibleForTesting
    static final String TAG = CarLog.tagFor(NewUserDisclaimerActivity.class);
    private static final int LEARN_MORE_RESULT_CODE = 1;
    private static final int NOTIFICATION_ID =
            NotificationHelper.NEW_USER_DISCLAIMER_NOTIFICATION_ID;

    private Button mAcceptButton;
    private AlertDialog mDialog;
    private boolean mLearnMoreLaunched;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setupAlertDialog();
    }

    @Override
    protected void onResume() {
        super.onResume();

        if (DEBUG) Slog.d(TAG, "showing UI");
        showAlertDialog();
        PerUserCarDevicePolicyService.getInstance(this).setShown();
    }

    private AlertDialog setupAlertDialog() {
        String managedByOrganizationText = ManagedDeviceTextView.getManagedDeviceText(this)
                .toString();
        String managedProfileText = getResources().getString(
                R.string.new_user_managed_device_text);

        mDialog = new AlertDialog.Builder(/* context= */ this,
                        com.android.internal.R.style.Theme_DeviceDefault_Dialog_Alert)
                .setTitle(R.string.new_user_managed_device_title)
                .setMessage(managedByOrganizationText + System.lineSeparator()
                        + System.lineSeparator() + managedProfileText)
                .setPositiveButton(R.string.new_user_managed_device_acceptance,
                    (d, which) -> onAccept())
                .setNegativeButton(R.string.new_user_managed_device_learn_more,
                    (d, which) -> onLearnMoreClicked())
                .setCancelable(false)
                .setOnDismissListener((d) -> onDialogDimissed())
                .create();

        return mDialog;
    }

    private void showAlertDialog() {
        if (mDialog == null) {
            setupAlertDialog();
        }
        mDialog.show();
    }

    private void onAccept() {
        if (DEBUG) Slog.d(TAG, "user accepted");

        PerUserCarDevicePolicyService.getInstance(this).setAcknowledged();
        setResult(RESULT_OK);
        finish();
    }

    private void onLearnMoreClicked() {
        mLearnMoreLaunched = true;
        startActivityForResult(new Intent(Settings.ACTION_ENTERPRISE_PRIVACY_SETTINGS),
                LEARN_MORE_RESULT_CODE);
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode != LEARN_MORE_RESULT_CODE) {
            if (DEBUG) Slog.w(TAG, "onActivityResult(), invalid request code: " + requestCode);
            return;
        }
        mLearnMoreLaunched = false;
    }

    private void onDialogDimissed() {
        if (mLearnMoreLaunched) {
            return;
        }
        finish();
    }

    static void showNotification(Context context) {
        PendingIntent pendingIntent = getPendingIntent(context, /* extraFlags= */ 0);

        Notification notification = NotificationHelper
                .newNotificationBuilder(context, NotificationManager.IMPORTANCE_DEFAULT)
                .setSmallIcon(R.drawable.car_ic_mode)
                .setContentTitle(context.getString(R.string.new_user_managed_notification_title))
                .setContentText(ManagedDeviceTextView.getManagedDeviceText(context))
                .setCategory(Notification.CATEGORY_CAR_INFORMATION)
                .setContentIntent(pendingIntent)
                .setOngoing(true)
                .build();

        if (DEBUG) {
            Slog.d(TAG, "Showing new managed notification (id " + NOTIFICATION_ID + " on user "
                    + context.getUserId());
        }
        context.getSystemService(NotificationManager.class).notify(NOTIFICATION_ID, notification);
    }

    static void cancelNotification(Context context) {
        if (DEBUG) {
            Slog.d(TAG, "Canceling notification " + NOTIFICATION_ID + " for user "
                    + context.getUserId());
        }
        context.getSystemService(NotificationManager.class).cancel(NOTIFICATION_ID);
        getPendingIntent(context, PendingIntent.FLAG_UPDATE_CURRENT).cancel();
    }

    @VisibleForTesting
    static PendingIntent getPendingIntent(Context context, int extraFlags) {
        return PendingIntent.getActivity(context, NOTIFICATION_ID,
                new Intent(context, NewUserDisclaimerActivity.class),
                PendingIntent.FLAG_IMMUTABLE | extraFlags);
    }

    @VisibleForTesting
    AlertDialog getDialog() {
        return mDialog;
    }
}
