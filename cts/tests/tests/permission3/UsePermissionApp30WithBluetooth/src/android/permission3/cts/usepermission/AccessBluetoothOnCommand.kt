/*
 * Copyright (C) 2021 The Android Open Source Project
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
package android.permission3.cts.usepermission

import android.bluetooth.BluetoothManager
import android.bluetooth.le.BluetoothLeScanner
import android.bluetooth.le.ScanCallback
import android.bluetooth.le.ScanResult
import android.content.ContentProvider
import android.content.ContentValues
import android.content.Intent
import android.database.Cursor
import android.net.Uri
import android.os.Bundle
import android.os.SystemClock
import android.util.Base64
import android.util.Log
import java.util.concurrent.ConcurrentHashMap
import java.util.concurrent.atomic.AtomicInteger

private const val TAG = "AccessBluetoothOnCommand"

class AccessBluetoothOnCommand : ContentProvider() {

    private enum class Result {
        UNKNOWN, ERROR, EXCEPTION, EMPTY, FILTERED, FULL
    }

    override fun call(authority: String, method: String, arg: String?, extras: Bundle?): Bundle? {
        val res = Bundle()

        var scanner: BluetoothLeScanner? = null
        var scanCallback: ScanCallback? = null

        try {

            scanner = context!!.getSystemService(BluetoothManager::class.java)
                ?.adapter!!.bluetoothLeScanner

            val observedScans: MutableSet<String> = ConcurrentHashMap.newKeySet()
            val observedErrorCode = AtomicInteger(0)

            scanCallback = object : ScanCallback() {
                override fun onScanResult(callbackType: Int, result: ScanResult) {
                    Log.v(TAG, "onScanResult() - result = $result")
                    observedScans.add(Base64.encodeToString(result.scanRecord!!.bytes, 0))
                }

                override fun onBatchScanResults(results: List<ScanResult>) {
                    for (result in results) {
                        onScanResult(0, result)
                    }
                }

                override fun onScanFailed(errorCode: Int) {
                    Log.v(TAG, "onScanFailed() - errorCode = $errorCode")
                    observedErrorCode.set(errorCode)
                }
            }

            scanner.startScan(scanCallback)

            // Wait a few seconds to figure out what we actually observed
            SystemClock.sleep(3000)

            if (observedErrorCode.get() > 0) {
                res.putInt(Intent.EXTRA_INDEX, Result.ERROR.ordinal)
                return res
            }

            when (observedScans.size) {
                0 -> res.putInt(Intent.EXTRA_INDEX, Result.EMPTY.ordinal)
                1 -> res.putInt(Intent.EXTRA_INDEX, Result.FILTERED.ordinal)
                5 -> res.putInt(Intent.EXTRA_INDEX, Result.FULL.ordinal)
                else -> res.putInt(Intent.EXTRA_INDEX, Result.UNKNOWN.ordinal)
            }
        } catch (t: Throwable) {
            Log.v(TAG, "Failed to scan", t)
            res.putInt(Intent.EXTRA_INDEX, Result.EXCEPTION.ordinal)
        } finally {
            try {
                scanner!!.stopScan(scanCallback)
            } catch (e: Exception) {
            }
        }
        return res
    }

    override fun onCreate(): Boolean {
        return true
    }

    override fun query(
        uri: Uri,
        projection: Array<String>?,
        selection: String?,
        selectionArgs: Array<String>?,
        sortOrder: String?
    ): Cursor? {
        throw UnsupportedOperationException()
    }

    override fun getType(uri: Uri): String? {
        throw UnsupportedOperationException()
    }

    override fun insert(uri: Uri, values: ContentValues?): Uri? {
        throw UnsupportedOperationException()
    }

    override fun delete(uri: Uri, selection: String?, selectionArgs: Array<String>?): Int {
        throw UnsupportedOperationException()
    }

    override fun update(
        uri: Uri,
        values: ContentValues?,
        selection: String?,
        selectionArgs: Array<String>?
    ): Int {
        throw UnsupportedOperationException()
    }
}
