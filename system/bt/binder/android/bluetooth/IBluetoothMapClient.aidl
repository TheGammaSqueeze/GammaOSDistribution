/*
 * Copyright 2016 The Android Open Source Project
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

package android.bluetooth;

import android.app.PendingIntent;
import android.bluetooth.BluetoothDevice;
import android.content.AttributionSource;
import android.net.Uri;

/**
 * System private API for Bluetooth MAP MCE service
 *
 * {@hide}
 */
interface IBluetoothMapClient {
    @JavaPassthrough(annotation="@android.annotation.RequiresPermission(allOf = { android.Manifest.permission.BLUETOOTH_CONNECT, android.Manifest.permission.BLUETOOTH_PRIVILEGED })")
    boolean connect(in BluetoothDevice device, in AttributionSource attributionSource);
    @JavaPassthrough(annotation="@android.annotation.RequiresPermission(allOf = { android.Manifest.permission.BLUETOOTH_CONNECT, android.Manifest.permission.BLUETOOTH_PRIVILEGED })")
    boolean disconnect(in BluetoothDevice device, in AttributionSource attributionSource);
    @JavaPassthrough(annotation="@android.annotation.RequiresPermission(android.Manifest.permission.BLUETOOTH_CONNECT)")
    boolean isConnected(in BluetoothDevice device, in AttributionSource attributionSource);
    @JavaPassthrough(annotation="@android.annotation.RequiresPermission(android.Manifest.permission.BLUETOOTH_CONNECT)")
    List<BluetoothDevice> getConnectedDevices(in AttributionSource attributionSource);
    @JavaPassthrough(annotation="@android.annotation.RequiresPermission(android.Manifest.permission.BLUETOOTH_CONNECT)")
    List<BluetoothDevice> getDevicesMatchingConnectionStates(in int[] states, in AttributionSource attributionSource);
    @JavaPassthrough(annotation="@android.annotation.RequiresPermission(android.Manifest.permission.BLUETOOTH_CONNECT)")
    int getConnectionState(in BluetoothDevice device, in AttributionSource attributionSource);
    @JavaPassthrough(annotation="@android.annotation.RequiresPermission(allOf = { android.Manifest.permission.BLUETOOTH_CONNECT, android.Manifest.permission.BLUETOOTH_PRIVILEGED })")
    boolean setConnectionPolicy(in BluetoothDevice device,in int connectionPolicy, in AttributionSource attributionSource);
    @JavaPassthrough(annotation="@android.annotation.RequiresPermission(allOf = { android.Manifest.permission.BLUETOOTH_CONNECT, android.Manifest.permission.BLUETOOTH_PRIVILEGED })")
    int getConnectionPolicy(in BluetoothDevice device, in AttributionSource attributionSource);
    @JavaPassthrough(annotation="@android.annotation.RequiresPermission(allOf = { android.Manifest.permission.BLUETOOTH_CONNECT, android.Manifest.permission.SEND_SMS })")
    boolean sendMessage(in BluetoothDevice device, in Uri[] contacts, in  String message, in PendingIntent sentIntent, in PendingIntent deliveryIntent, in AttributionSource attributionSource);
    @JavaPassthrough(annotation="@android.annotation.RequiresPermission(allOf = { android.Manifest.permission.BLUETOOTH_CONNECT, android.Manifest.permission.READ_SMS })")
    boolean getUnreadMessages(in BluetoothDevice device, in AttributionSource attributionSource);
    @JavaPassthrough(annotation="@android.annotation.RequiresPermission(android.Manifest.permission.BLUETOOTH_CONNECT)")
    int getSupportedFeatures(in BluetoothDevice device, in AttributionSource attributionSource);
    @JavaPassthrough(annotation="@android.annotation.RequiresPermission(allOf = { android.Manifest.permission.BLUETOOTH_CONNECT, android.Manifest.permission.READ_SMS })")
    boolean setMessageStatus(in BluetoothDevice device, in String handle, in int status, in AttributionSource attributionSource);
}
