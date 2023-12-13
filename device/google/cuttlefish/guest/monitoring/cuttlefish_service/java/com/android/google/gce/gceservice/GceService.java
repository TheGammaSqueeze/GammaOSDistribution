/*
 * Copyright (C) 2017 The Android Open Source Project
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
package com.android.google.gce.gceservice;

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.Service;
import android.bluetooth.BluetoothAdapter;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.res.Configuration;
import android.graphics.Point;
import android.net.ConnectivityManager;
import android.util.Log;
import android.os.IBinder;
import android.view.Display;
import android.view.WindowManager;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.util.List;

/**
 * Service is started by the BootCompletedReceiver at the end of Android Boot process.
 * Responsible for emitting final BOOT_COMPLETED message and continued configuration changes.
 */
public class GceService extends Service {
    private static final String LOG_TAG = "GceService";
    /* Intent sent by the BootCompletedReceiver upon receiving ACTION_BOOT_COMPLETED broadcast. */
    public static final String INTENT_ACTION_CONFIGURE = "com.android.google.gce.gceservice.CONFIGURE";
    public static final String INTENT_ACTION_NETWORK_CHANGED = "com.android.google.gce.gceservice.NETWORK_CHANGED";
    public static final String INTENT_ACTION_BLUETOOTH_CHANGED = "com.android.google.gce.gceservice.BLUETOOTH_CHANGED";
    private static final String NOTIFICATION_CHANNEL_ID = "cuttlefish-service";
    private static final String NOTIFICATION_CHANNEL_NAME = "Cuttlefish Service";
    private static final int NOTIFICATION_ID = 1;

    private final JobExecutor mExecutor = new JobExecutor();
    private final EventReporter mEventReporter = new EventReporter();
    private final GceBroadcastReceiver mBroadcastReceiver = new GceBroadcastReceiver();
    private final BluetoothChecker mBluetoothChecker = new BluetoothChecker();

    private ConnectivityChecker mConnChecker;
    private GceWifiManager mWifiManager = null;
    private String mMostRecentAction = null;
    private WindowManager mWindowManager;

    private int mPreviousRotation;
    private Point mPreviousScreenBounds;
    private int mPreviousDpi;


    public GceService() {}


    @Override
    public void onCreate() {
        try {
            super.onCreate();
            mEventReporter.reportBootStarted();
            registerBroadcastReceivers();

            mWindowManager = getSystemService(WindowManager.class);
            mConnChecker = new ConnectivityChecker(this, mEventReporter);
            mWifiManager = new GceWifiManager(this, mEventReporter, mExecutor);

            mPreviousRotation = getRotation();
            mPreviousScreenBounds = getScreenBounds();
            mPreviousDpi = getResources().getConfiguration().densityDpi;

            mExecutor.schedule(mWifiManager);
            mExecutor.schedule(mBluetoothChecker);
            mExecutor.schedule(mConnChecker);

            mExecutor.schedule(mEventReporter, mBluetoothChecker.getEnabled());

            NotificationManager notificationManager =
                    (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
            NotificationChannel channel =
                    new NotificationChannel(
                            NOTIFICATION_CHANNEL_ID,
                            NOTIFICATION_CHANNEL_NAME,
                            NotificationManager.IMPORTANCE_LOW);
            notificationManager.createNotificationChannel(channel);

        } catch (Exception e) {
            Log.e(LOG_TAG, "Exception caught", e);
        }
    }


    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }


    /** Register broadcast listeners.
     *
     * Certain intents can no longer be used to start a service or activity, but
     * can still be registered for, such as CONNECTIVITY_ACTION (Android N).
     */
    private void registerBroadcastReceivers() {
        IntentFilter filter = new IntentFilter();
        filter.addAction(ConnectivityManager.CONNECTIVITY_ACTION);
        filter.addAction(BluetoothAdapter.ACTION_STATE_CHANGED);
        this.registerReceiver(mBroadcastReceiver, filter);
    }

    private Point getScreenBounds() {
        Display display = mWindowManager.getDefaultDisplay();
        Point screenBounds = new Point();
        display.getRealSize(screenBounds);
        return screenBounds;
    }

    private int getRotation() {
      return mWindowManager.getDefaultDisplay().getRotation();
    }

    @Override
    public void onConfigurationChanged(Configuration config) {
        super.onConfigurationChanged(config);

        int rotation = getRotation();
        Point screenBounds = getScreenBounds();
        int dpi = config.densityDpi;
        // NOTE: We cannot rely on config.diff(previous config) here because
        // diff shows CONFIG_SCREEN_SIZE changes when changing between 3-button
        // and gesture navigation. We only care about the display bounds.
        if (rotation == mPreviousRotation &&
            screenBounds.equals(mPreviousScreenBounds) &&
            dpi == mPreviousDpi) {
            return;
        }

        int width = screenBounds.x;
        int height = screenBounds.y;
        mEventReporter.reportScreenChanged(width, height, dpi, rotation);

        mPreviousRotation = rotation;
        mPreviousScreenBounds = screenBounds;
        mPreviousDpi = dpi;
    }


    /** StartService entry point.
     */
    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        if (intent != null) {
            mMostRecentAction = intent.getAction();
        } else {
            Log.w(LOG_TAG, "Previous execution failed. Retrying.");
        }

        if (mMostRecentAction == null) {
            Log.e(LOG_TAG, "Missing intent action.");
        }

        Notification notification =
                new Notification.Builder(this, NOTIFICATION_CHANNEL_ID)
                        .setAutoCancel(true)
                        .setContentTitle("Cuttlefish service is running.")
                        .setSmallIcon(android.R.drawable.ic_dialog_info)
                        .setTimeoutAfter(10000)
                        .build();
        // Start in the Foreground (and do not stop) so that this service
        // continues running and reporting events without being killed.
        startForeground(NOTIFICATION_ID, notification);

        if (INTENT_ACTION_CONFIGURE.equals(mMostRecentAction)) {
            mExecutor.schedule(mConnChecker);
        } else if (INTENT_ACTION_NETWORK_CHANGED.equals(mMostRecentAction)) {
            mExecutor.schedule(mConnChecker);
        } else if (INTENT_ACTION_BLUETOOTH_CHANGED.equals(mMostRecentAction)) {
            mExecutor.schedule(mBluetoothChecker);
        }

        /* If anything goes wrong, make sure we receive intent again. */
        return Service.START_STICKY;
    }

    @Override
    public void onDestroy() {
        unregisterReceiver(mBroadcastReceiver);
    }

    /** Dump the virtual device state
     */
    @Override
    protected void dump(FileDescriptor fd, PrintWriter pw, String[] args) {
        pw.println("Virtual Device reporter:");
        List<String> messageList = mEventReporter.getMessageList();
        for (int i = 0; i < messageList.size(); i++) {
            pw.println("  " + messageList.get(i));
        }
        pw.println("");
        pw.println("Current system service state:");
        pw.println("  Network connected: " + mConnChecker.getConnected().isDone());
        pw.println("  WiFi configured: " + mWifiManager.getWifiReady().isDone());
        pw.println("  Bluetooth enabled: " + mBluetoothChecker.getEnabled().isDone());
        pw.println("");
    }
}
