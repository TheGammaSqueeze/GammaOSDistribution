package com.googlecode.android_scripting.facade.bluetooth;

import android.app.Service;
import android.bluetooth.le.BluetoothLeScanner;
import android.bluetooth.le.ScanCallback;
import android.bluetooth.le.ScanResult;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import com.googlecode.android_scripting.facade.EventFacade;
import com.googlecode.android_scripting.facade.FacadeManager;

import java.util.ArrayList;
import java.util.List;

public class ScanBroadcastReceiver extends BroadcastReceiver {
    private static final String TAG = "SL4A Bluetooth";
    public static final String ACTION_FOUND_SIDESTEP = "com.googlecode.android_scripting.ACTION_FOUND_SIDE_STEP";

    public ScanBroadcastReceiver() {
    }

    @Override
    public void onReceive(Context context, Intent intent) {
      Log.d(TAG, "Received Intent data.");
      Intent i = new Intent(ACTION_FOUND_SIDESTEP);
      i.putParcelableArrayListExtra(BluetoothLeScanner.EXTRA_LIST_SCAN_RESULT,
          intent.getParcelableArrayListExtra(BluetoothLeScanner.EXTRA_LIST_SCAN_RESULT));
      context.sendBroadcast(i);
    }

}
