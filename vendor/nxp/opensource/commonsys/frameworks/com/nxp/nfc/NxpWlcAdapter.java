/******************************************************************************
 *
 *  Copyright 2020 NXP
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
 ******************************************************************************/

package com.nxp.nfc;

import android.annotation.SystemApi;
import android.nfc.INfcAdapter;
import android.nfc.NfcAdapter;
import android.os.IBinder;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.util.Log;
import java.io.IOException;
import java.util.HashMap;

public final class NxpWlcAdapter {
  private static final String TAG = "NXPWLC";
  // Guarded by NfcAdapter.class
  static boolean sIsInitialized = false;
  /**
   * The NfcAdapter object for each application context.
   * There is a 1-1 relationship between application context and
   * NfcAdapter object.
   */
  static HashMap<NfcAdapter, NxpWlcAdapter> sNfcAdapters =
      new HashMap(); // guard by NfcAdapter.class
  // Final after first constructor, except for
  // attemptDeadServiceRecovery() when NFC crashes - we accept a best effort
  // recovery
  private static INfcAdapter sService;
  private static INxpWlcAdapter sNxpService;

  private NxpWlcAdapter() {}

  public static synchronized NxpWlcAdapter getNxpWlcAdapter(NfcAdapter adapter) {
    if (!sIsInitialized) {
      if (adapter == null) {
        Log.v(TAG, "could not find NFC support");
        throw new UnsupportedOperationException();
      }
      sService = getServiceInterface();
      if (sService == null) {
        Log.e(TAG, "could not retrieve NFC service");
        throw new UnsupportedOperationException();
      }
      sNxpService = getNxpWlcAdapterInterface();
      if (sNxpService == null) {
        Log.e(TAG, "could not retrieve NXP WLC service");
        throw new UnsupportedOperationException();
      }
      sIsInitialized = true;
    }
    NxpWlcAdapter nxpAdapter = sNfcAdapters.get(adapter);
    if (nxpAdapter == null) {
      nxpAdapter = new NxpWlcAdapter();
      sNfcAdapters.put(adapter, nxpAdapter);
    }
    return nxpAdapter;
  }

  /** get handle to NFC service interface */
  private static INfcAdapter getServiceInterface() {
    /* get a handle to NFC service */
    IBinder b = ServiceManager.getService("nfc");
    if (b == null) {
      return null;
    }
    return INfcAdapter.Stub.asInterface(b);
  }

  /**
   * @hide
   */
  public static INxpWlcAdapter getNxpWlcAdapterInterface() {
    if (sService == null) {
      throw new UnsupportedOperationException("You need a reference from NfcAdapter to use the "
          + " NXP NFC APIs");
    }
    try {
      IBinder b = sService.getNfcAdapterVendorInterface("wlc");
      if (b == null) {
        return null;
      }
      return INxpWlcAdapter.Stub.asInterface(b);
    } catch (RemoteException e) {
      return null;
    }
  }

  /**
   * NFC service dead - attempt best effort recovery
   * @hide
   */
  private static void attemptDeadServiceRecovery(Exception e) {
    Log.e(TAG, "Service dead - attempting to recover", e);
    INfcAdapter service = getServiceInterface();
    if (service == null) {
      Log.e(TAG, "could not retrieve NFC service during service recovery");
      // nothing more can be done now, sService is still stale, we'll hit
      // this recovery path again later
      return;
    }
    // assigning to sService is not thread-safe, but this is best-effort code
    // and on a well-behaved system should never happen
    sService = service;
    sNxpService = getNxpWlcAdapterInterface();
    return;
  }

  /**
   * This api is called by applications to Enable Wireless charging.
   * <p>Requires {@link android.Manifest.permission#NFC} permission.<ul>
   * <li>This api shall be called only after Nfcservice is enabled.
   * </ul>
   * @return none
   * @throws  IOException if any exception occurs during this operation
   */
  @SystemApi
  public void enableWlc(INxpWlcCallBack callback) throws IOException {
    try {
      sNxpService.enableWlc(callback);
    } catch (RemoteException e) {
      e.printStackTrace();
      attemptDeadServiceRecovery(e);
    }
  }

  /**
   * This api is called by applications to Disable Wireless charging.
   * <p>Requires {@link android.Manifest.permission#NFC} permission.<ul>
   * <li>This api shall be called only after Nfcservice is enabled.
   * </ul>
   * @return none
   * @throws  IOException if any exception occurs during this operation
   */
  @SystemApi
  public void disableWlc(INxpWlcCallBack callback) throws IOException {
    try {
      sNxpService.disableWlc(callback);
    } catch (RemoteException e) {
      e.printStackTrace();
      attemptDeadServiceRecovery(e);
    }
  }

  /**
   * This api is called by applications to check if wireless charging is enabled.
   * <p>Requires {@link android.Manifest.permission#NFC} permission.<ul>
   * <li>This api shall be called only after Nfcservice is enabled.
   * </ul>
   * @return true if WlcPolling is Enabled else false
   * @throws  IOException if any exception occurs during this operation
   */
  @SystemApi
  public boolean isWlcEnabled() throws IOException {
    try {
      return sNxpService.isWlcEnabled();
    } catch (RemoteException e) {
      e.printStackTrace();
      attemptDeadServiceRecovery(e);
      return false;
    }
  }
}