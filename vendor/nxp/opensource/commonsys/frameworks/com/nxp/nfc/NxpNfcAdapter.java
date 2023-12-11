/*
 *
 *  The original Work has been changed by NXP.
 *
 *  Copyright 2013-2021 NXP
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */
package com.nxp.nfc;

import java.util.HashMap;
import java.util.Map;
import android.nfc.INfcAdapter;
import android.nfc.NfcAdapter;
import android.nfc.INfcAdapterExtras;
import android.os.IBinder;
import android.os.ServiceManager;

import java.io.IOException;
import android.os.UserHandle;
import android.os.RemoteException;
import android.annotation.SystemApi;
import android.annotation.RequiresPermission;

import android.util.Log;
import java.util.List;
public final class NxpNfcAdapter {
    private static final String TAG = "NXPNFC";
    private static int ALL_SE_ID_TYPE = 0x07;
    // Guarded by NfcAdapter.class
    static boolean sIsInitialized = false;

    /**
     * Flag for use with {@link #enableReaderMode(Activity, ReaderCallback, int,
     * Bundle)}. <p> Setting this flag enables polling for Nfc-Q(Quiet tag)
     * technology.
     */
    public static final int FLAG_READER_NFC_Q = 0x20;

    /**
     * The NfcAdapter object for each application context.
     * There is a 1-1 relationship between application context and
     * NfcAdapter object.
     */
    static HashMap<NfcAdapter, NxpNfcAdapter> sNfcAdapters = new HashMap(); //guard by NfcAdapter.class

    // Final after first constructor, except for
    // attemptDeadServiceRecovery() when NFC crashes - we accept a best effort
    // recovery
    private static INfcAdapter sService;
    private static INxpNfcAdapter sNxpService;

    private NxpNfcAdapter() {
    }
    /**
     * Returns the NxpNfcAdapter for application context,
     * or throws if NFC is not available.
     * @hide
     */
    public static synchronized NxpNfcAdapter getNxpNfcAdapter(NfcAdapter adapter) {
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
            sNxpService = getNxpNfcAdapterInterface();
             if (sNxpService == null) {
                Log.e(TAG, "could not retrieve NXP NFC service");
                throw new UnsupportedOperationException();
            }
            sIsInitialized = true;
        }
        NxpNfcAdapter nxpAdapter = sNfcAdapters.get(adapter);
        if (nxpAdapter == null) {
            nxpAdapter = new NxpNfcAdapter();
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
     * NFC service dead - attempt best effort recovery
     * @hide
     */
    private static void attemptDeadServiceRecovery(Exception e) {
        Log.e(TAG, "Service dead - attempting to recover",e);
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
        sNxpService = getNxpNfcAdapterInterface();
        return;
    }
    /**
     * Set listen mode routing table configuration for Mifare Desfire Route.
     * routeLoc is parameter which fetch the text from UI and compare
     * <p>Requires {@link android.Manifest.permission#NFC} permission.
     *
     * @throws IOException If a failure occurred during Mifare Desfire Route
     * set.
     */
    public void MifareDesfireRouteSet(String routeLoc, boolean fullPower,
                                      boolean lowPower, boolean noPower)
        throws IOException {
      try {
        int seID = 0;
        boolean result = false;
        if (routeLoc.equals(NfcConstants.UICC_ID)) {
          seID = NfcConstants.UICC_ID_TYPE;
        } else if (routeLoc.equals(NfcConstants.UICC2_ID)) {
          seID = NfcConstants.UICC2_ID_TYPE;
        } else if (routeLoc.equals(NfcConstants.SMART_MX_ID)) {
          seID = NfcConstants.SMART_MX_ID_TYPE;
        } else if (routeLoc.equals(NfcConstants.HOST_ID)) {
          seID = NfcConstants.HOST_ID_TYPE;
        } else {
          Log.e(TAG, "confMifareDesfireProtoRoute: wrong default route ID");
          throw new IOException(
              "confMifareProtoRoute failed: Wrong default route ID");
        }
        Log.i(TAG, "calling Services");
        sNxpService.MifareDesfireRouteSet(seID, fullPower, lowPower, noPower);
      } catch (RemoteException e) {
        Log.e(TAG, "confMifareDesfireProtoRoute failed", e);
        attemptDeadServiceRecovery(e);
        throw new IOException("confMifareDesfireProtoRoute failed");
      }
    }
    /**
     * Set listen mode routing table configuration for MifareCLTRouteSet.
     * routeLoc is parameter which fetch the text from UI and compare
     * <p>Requires {@link android.Manifest.permission#NFC} permission.
     *
     * @throws IOException If a failure occurred during Mifare CLT Route set.
     */
    public void MifareCLTRouteSet(String routeLoc, boolean fullPower,
                                  boolean lowPower, boolean noPower)
        throws IOException {
      try {
        int seID = 0;
        boolean result = false;
        if (routeLoc.equals(NfcConstants.UICC_ID)) {
          seID = NfcConstants.UICC_ID_TYPE;
        } else if (routeLoc.equals(NfcConstants.UICC2_ID)) {
          seID = NfcConstants.UICC2_ID_TYPE;
        } else if (routeLoc.equals(NfcConstants.SMART_MX_ID)) {
          seID = NfcConstants.SMART_MX_ID_TYPE;
        } else if (routeLoc.equals(NfcConstants.HOST_ID)) {
          seID = NfcConstants.HOST_ID_TYPE;
        } else {
          Log.e(TAG, "confMifareCLT: wrong default route ID");
          throw new IOException("confMifareCLT failed: Wrong default route ID");
        }
        sNxpService.MifareCLTRouteSet(seID, fullPower, lowPower, noPower);
      } catch (RemoteException e) {
        Log.e(TAG, "confMifareCLT failed", e);
        attemptDeadServiceRecovery(e);
        throw new IOException("confMifareCLT failed");
      }
    }

     /**
      * Set listen mode routing table configuration for NfcFRouteSet.
      * routeLoc is parameter which fetch the text from UI and compare
      * <p>Requires {@link android.Manifest.permission#NFC} permission.
      *
      * @throws IOException If a failure occurred during Felica Techno Route set.
      */
     public void NfcFRouteSet(String routeLoc, boolean fullPower,
                                   boolean lowPower, boolean noPower)
         throws IOException {
       try {
         int seID = 0;
         boolean result = false;
         if (routeLoc.equals(NfcConstants.UICC_ID)) {
           seID = NfcConstants.UICC_ID_TYPE;
         } else if (routeLoc.equals(NfcConstants.UICC2_ID)) {
           seID = NfcConstants.UICC2_ID_TYPE;
         } else if (routeLoc.equals(NfcConstants.SMART_MX_ID)) {
           seID = NfcConstants.SMART_MX_ID_TYPE;
         } else if (routeLoc.equals(NfcConstants.HOST_ID)) {
           seID = NfcConstants.HOST_ID_TYPE;
         } else {
           Log.e(TAG, "confNfcF: wrong default route ID");
           throw new IOException("confNfcF failed: Wrong default route ID");
         }
         sNxpService.NfcFRouteSet(seID, fullPower, lowPower, noPower);
       } catch (RemoteException e) {
         Log.e(TAG, "confNfcF failed", e);
         attemptDeadServiceRecovery(e);
         throw new IOException("confNfcF failed");
       }
     }

    /**
     * @hide
     */
    public static INxpNfcAdapter getNxpNfcAdapterInterface() {
      if (sService == null) {
        throw new UnsupportedOperationException(
            "You need a reference from NfcAdapter to use the "
            + " NXP NFC APIs");
      }
      try {
        IBinder b = sService.getNfcAdapterVendorInterface("nxp");
        if (b == null) {
          return null;
        }
        return INxpNfcAdapter.Stub.asInterface(b);
      } catch (RemoteException e) {
        return null;
      }
    }

    /**
     * Change poll and listen technology
     * Generic API is use to disable polling and enable speicific listening
     * technology
     * @param binder,pollTech, listenTech.
     * @return void
     * @hide
     */
    public void changeDiscoveryTech(IBinder binder, int pollTech,
                                    int listenTech) throws IOException {
      try {
        sNxpService.changeDiscoveryTech(binder, pollTech, listenTech);
      } catch (RemoteException e) {
        Log.e(TAG, "changeDiscoveryTech failed", e);
      }
    }

    /**
     * This API is called by application to execute the analog self test
     * <p>Requires {@link android.Manifest.permission#NFC} permission.
     * <li>This api shall be called only Nfcservice is enabled.
     * </ul>
     * @param  type, type of the analog slef test
     * @return status
     * @throws IOException If a failure occurred during nfcSelfTest
     * @hide
     */
    public int nfcSelfTest(int type) throws IOException {
        int status = 0xFF;
        if (sNxpService == null) {
        throw new UnsupportedOperationException(
            "You need a context on NxpNfcAdapter to use the "
            + " NXP NFC extras APIs");
        }
        try {
            status = sNxpService.nfcSelfTest(type);
        } catch(RemoteException e) {
            Log.e(TAG, "RemoteException in nfcSelfTest(): ", e);
            e.printStackTrace();
            attemptDeadServiceRecovery(e);
            throw new IOException("RemoteException in nfcSelfTest()");
        }
        return status;
    }
    /**
     * @hide
     */
    public INxpNfcAdapterExtras getNxpNfcAdapterExtrasInterface() {
      if (sNxpService == null) {
        throw new UnsupportedOperationException(
            "You need a context on NxpNfcAdapter to use the "
            + " NXP NFC extras APIs");
      }
      try {
        return sNxpService.getNxpNfcAdapterExtrasInterface();
      } catch (RemoteException e) {
        Log.e(TAG, "getNxpNfcAdapterExtrasInterface failed", e);
        attemptDeadServiceRecovery(e);
        return null;
      } catch (Exception e) {
        e.printStackTrace();
        return null;
      }
    }

    /**
     * This is the first API to be called to start or stop the mPOS mode
     * <p>Requires {@link android.Manifest.permission#NFC} permission.
     * <li>This api shall be called only Nfcservice is enabled.
     * <li>This api shall be called only when there are no NFC transactions
     * ongoing
     * </ul>
     * @param  pkg package name of the caller
     * @param  on Sets/Resets the mPOS state.
     * @return whether the update of state is
     *          success or busy or fail.
     *          MPOS_STATUS_BUSY
     *          MPOS_STATUS_REJECTED
     *          MPOS_STATUS_SUCCESS
     * @throws IOException If a failure occurred during reader mode set or reset
     */
    @RequiresPermission(android.Manifest.permission.NFC)
    public int mPOSSetReaderMode(String pkg, boolean on) throws IOException {
      try {
        return sNxpService.mPOSSetReaderMode(pkg, on);
      } catch (RemoteException e) {
        Log.e(TAG, "RemoteException in mPOSSetReaderMode (int state): ", e);
        e.printStackTrace();
        attemptDeadServiceRecovery(e);
        throw new IOException(
            "RemoteException in mPOSSetReaderMode (int state)");
      }
    }

    /**
     * This is provides the info whether mPOS mode is activated or not
     * <p>Requires {@link android.Manifest.permission#NFC} permission.
     * <li>This api shall be called only Nfcservice is enabled.
     * <li>This api shall be called only when there are no NFC transactions ongoing
     * </ul>
     * @param  pkg package name of the caller
     * @return TRUE if reader mode is started
     *          FALSE if reader mode is not started
     * @throws IOException If a failure occurred during reader mode set or reset
     */
    @RequiresPermission(android.Manifest.permission.NFC)
    public boolean mPOSGetReaderMode(String pkg) throws IOException {
      try {
        return sNxpService.mPOSGetReaderMode(pkg);
      } catch (RemoteException e) {
        Log.e(TAG, "RemoteException in mPOSGetReaderMode (): ", e);
        e.printStackTrace();
        attemptDeadServiceRecovery(e);
        throw new IOException("RemoteException in mPOSGetReaderMode ()");
      }
    }

    /**
     * This is the first API to be called to configure the SCR mode
     * <p>Requires {@link android.Manifest.permission#NFC} permission.
     * <li>This api shall be called only Nfcservice is enabled.
     * <li>This api shall be called only when there are no NFC transactions
     * ongoing
     * </ul>
     * @param  on Sets/Resets the Secure Reader state.
     * @param  Requested reader type. e.g. Mifare Classic Reader("MFC")
     * @return whether the update of state is
     *          success or busy or fail or rejected.
     *          SCR_STATUS_BUSY
     *          SCR_STATUS_REJECTED
     *          SCR_STATUS_SUCCESS
     *          SCR_STATUS_FAILED
     * @throws IOException If a failure occurred during reader mode set or reset
     */
    @RequiresPermission(android.Manifest.permission.NFC)
    public int configureSecureReader(boolean on, String readerType)
        throws IOException {
      try {
        return sNxpService.configureSecureReader(on, readerType);
      } catch (RemoteException e) {
        Log.e(TAG, "RemoteException in configureSecureReader (int state): ", e);
        e.printStackTrace();
        attemptDeadServiceRecovery(e);
        throw new IOException(
            "RemoteException in configureSecureReader (int state)");
      }
    }

    /**
     * This API is called by application to stop RF discovery
     * <p>Requires {@link android.Manifest.permission#NFC} permission.
     * <li>This api shall be called only Nfcservice is enabled.
     * </ul>
     * @param  pkg package name of the caller
     * @param  mode
     *         LOW_POWER
     *         ULTRA_LOW_POWER
     * @return None
     * @throws IOException If a failure occurred during stop discovery
    */
    public void stopPoll(String pkg, int mode) throws IOException {
        try {
            sNxpService.stopPoll(pkg, mode);
        } catch(RemoteException e) {
            Log.e(TAG, "RemoteException in stopPoll(int mode): ", e);
            e.printStackTrace();
            attemptDeadServiceRecovery(e);
            throw new IOException("RemoteException in stopPoll(int mode)");
        }
    }

    /**
     * This API is called by application to start RF discovery
     * <p>Requires {@link android.Manifest.permission#NFC} permission.
     * <li>This api shall be called only Nfcservice is enabled.
     * </ul>
     * @param  pkg package name of the caller
     * @return None
     * @throws IOException If a failure occurred during start discovery
    */
    public void startPoll(String pkg) throws IOException {
        try {
            sNxpService.startPoll(pkg);
        } catch(RemoteException e) {
            Log.e(TAG, "RemoteException in startPoll(): ", e);
            e.printStackTrace();
            attemptDeadServiceRecovery(e);
            throw new IOException("RemoteException in startPoll()");
        }
    }

    /**
     * Get the Active Secure Element List
     * <p>Requires {@link android.Manifest.permission#NFC} permission.
     *
     * @throws IOException If a failure occurred during the
     * getActiveSecureElementList()
     */
    public String[] getActiveSecureElementList(String pkg) throws IOException {
      int[] activeSEList;
      String[] arr;
      try {
        Log.d(TAG, "getActiveSecureElementList-Enter");
        activeSEList = sNxpService.getActiveSecureElementList(pkg);
        if (activeSEList != null && activeSEList.length != 0) {
          arr = new String[activeSEList.length];
          for (int i = 0; i < activeSEList.length; i++) {
            Log.e(TAG,
                  "getActiveSecureElementList activeSE[i]" + activeSEList[i]);
            if (activeSEList[i] == NfcConstants.SMART_MX_ID_TYPE) {
              arr[i] = NfcConstants.SMART_MX_ID;
            } else if (activeSEList[i] == NfcConstants.UICC_ID_TYPE) {
              arr[i] = NfcConstants.UICC_ID;
            } else if (activeSEList[i] == NfcConstants.UICC2_ID_TYPE) {
              arr[i] = NfcConstants.UICC2_ID;
            } else {
              throw new IOException("No Secure Element Activeted");
            }
          }
        } else {
          arr = new String[0];
        }
        return arr;
      } catch (RemoteException e) {
        Log.e(TAG, "getActiveSecureElementList: failed", e);
        attemptDeadServiceRecovery(e);
        throw new IOException(
            "Failure in deselecting the selected Secure Element");
      }
    }

    /**
     * Set listen mode routing table configuration for Default Route.
     * routeLoc is parameter which fetch the text from UI and compare
     * * <p>Requires {@link android.Manifest.permission#NFC} permission.
     * @throws IOException If a failure occurred during Default Route Route set.
     */
    public void DefaultRouteSet(String routeLoc, boolean fullPower,
                                boolean lowPower, boolean noPower)
        throws IOException {
      try {
        int seID = 0;
        boolean result = false;
        if (routeLoc.equals(NfcConstants.UICC_ID)) {
          seID = NfcConstants.UICC_ID_TYPE;
        } else if (routeLoc.equals(NfcConstants.UICC2_ID)) {
          seID = NfcConstants.UICC2_ID_TYPE;
        } else if (routeLoc.equals(NfcConstants.SMART_MX_ID)) {
          seID = NfcConstants.SMART_MX_ID_TYPE;
        } else if (routeLoc.equals(NfcConstants.HOST_ID)) {
          seID = NfcConstants.HOST_ID_TYPE;
        } else {
          Log.e(TAG, "DefaultRouteSet: wrong default route ID");
          throw new IOException(
              "DefaultRouteSet failed: Wrong default route ID");
        }
        sNxpService.DefaultRouteSet(seID, fullPower, lowPower, noPower);
      } catch (RemoteException e) {
        Log.e(TAG, "confsetDefaultRoute failed", e);
        attemptDeadServiceRecovery(e);
        throw new IOException("confsetDefaultRoute failed");
      }
    }

    /**
     * This api is called by applications to get the maximum routing table for
     * AID registration The returned value doesn't provide the current remaining
     * size available for AID. This value depends on the size available in NFCC
     * and is constant. <p>Requires {@link android.Manifest.permission#NFC}
     * permission.
     * @return maximum routing table size for AID registration.
     * @throws  IOException if any exception occurs while retrieving the size.
     */
    public int getMaxAidRoutingTableSize() throws IOException{
        try{
            return sNxpService.getMaxAidRoutingTableSize();
        }catch(RemoteException e){
            e.printStackTrace();
            attemptDeadServiceRecovery(e);
            return 0x00;
        }
    }

    /**
     * This api is called by applications to get the size of AID data which is already committed
     * to routing table in NFCC.
     * <p>Requires {@link android.Manifest.permission#NFC} permission.
     * @return  occupied size of routing table for AID registrations.
     * @throws  IOException if any exception occurs while retrieving the size.
     */
    public int getCommittedAidRoutingTableSize() throws IOException{
        try{
            return sNxpService.getCommittedAidRoutingTableSize();
        }catch(RemoteException e){
            e.printStackTrace();
            attemptDeadServiceRecovery(e);
            return 0x00;
        }
    }

    /**
     * Get the current NFCC firware version.
     * @return 2 byte array with Major ver(0 index) adn Minor ver(1 index)
     */
    public byte[] getFwVersion() throws IOException {
      try {
        return sNxpService.getFWVersion();
      } catch (RemoteException e) {
        Log.e(TAG, "RemoteException in getFwVersion(): ", e);
        attemptDeadServiceRecovery(e);
        throw new IOException("RemoteException in getFwVersion()");
      }
    }

    public byte[] readerPassThruMode(byte status, byte modulationTyp)
        throws IOException {
      try {
        return sNxpService.readerPassThruMode(status, modulationTyp);
      } catch (RemoteException e) {
        Log.e(TAG, "Remote exception in readerPassThruMode(): ", e);
        throw new IOException("Remote exception in readerPassThruMode()");
      }
    }

    public byte[] transceiveAppData(byte[] data) throws IOException {
      try {
        return sNxpService.transceiveAppData(data);
      } catch (RemoteException e) {
        Log.e(TAG, "RemoteException in transceiveAppData(): ", e);
        throw new IOException("RemoteException in transceiveAppData()");
      }
    }
    /**
     * This api is called by applications to update the NFC configurations which
     * are already part of libnfc-nxp.conf and libnfc-brcm.conf <p>Requires
     * {@link android.Manifest.permission#NFC} permission.<ul> <li>This api
     * shall be called only Nfcservice is enabled. <li>This api shall be called
     * only when there are no NFC transactions ongoing
     * </ul>
     * @param  configs NFC Configuration to be updated.
     * @param  pkg package name of the caller
     * @return whether  the update of configuration is
     *          success or not.
     *          0xFF - failure
     *          0x00 - success
     * @throws  IOException if any exception occurs during setting the NFC
     * configuration.
     */
    public int setConfig(String configs, String pkg) throws IOException {
      try {
        return sNxpService.setConfig(configs, pkg);
      } catch (RemoteException e) {
        e.printStackTrace();
        attemptDeadServiceRecovery(e);
        return 0xFF;
      }
    }
    /**
     * This api is called by applications to select the UICC slot. Selected Slot
     * will be activated for all type of CE from UICC.
     * <p>Requires {@link android.Manifest.permission#NFC} permission.<ul>
     * <li>This api shall be called only Nfcservice is enabled.
     * </ul>
     * @param  uicc slot number to select
     * @return whether  the update of configuration is
     *          success or not.
     *          0xFF - failure
     *          0x00 - success
     * @throws  IOException if any exception occurs during setting the NFC
     * configuration.
     */
    public int selectUicc(int uiccSlot) throws IOException {
      try {
        return sNxpService.selectUicc(uiccSlot);
      } catch (RemoteException e) {
        e.printStackTrace();
        attemptDeadServiceRecovery(e);
        return 0xFF;
      }
    }
    /**
     * This api is called by applications to get Selected UICC slot. Selected
     * Slot will be used for all type of CE from UICC. <p>Requires {@link
     * android.Manifest.permission#NFC} permission.<ul> <li>This api shall be
     * called only Nfcservice is enabled.
     * </ul>
     * @param  uicc slot number to select
     * @return whether  the update of configuration is
     *          success or not.
     *          0xFF - failure
     *          0x00 - success
     * @throws  IOException if any exception occurs during setting the NFC
     * configuration.
     */
    public int getSelectedUicc() throws IOException {
      try {
        return sNxpService.getSelectedUicc();
      } catch (RemoteException e) {
        e.printStackTrace();
        attemptDeadServiceRecovery(e);
        return 0xFF;
      }
    }
    /**
     * This api is called by applications enable or disable field
     * detect feauture.
     * <p>Requires {@link android.Manifest.permission#NFC} permission.<ul>
     * <li>This api shall be called only Nfcservice is enabled.

     * </ul>
     * @param  Mode to Enable(true) and Disable(false)
     * @return whether  the update of configuration is
     *          success or not with reason.
     *          0x01  - NFC_IS_OFF,
     *          0x02  - NFC_BUSY_IN_MPOS
     *          0x03  - ERROR_UNKNOWN
     *          0x00  - SUCCESS
     * @throws  IOException if any exception occurs during setting the NFC configuration.
     */
    public int setFieldDetectMode(boolean mode) {
      try {
        return sNxpService.setFieldDetectMode(mode);
      } catch (RemoteException e) {
        e.printStackTrace();
        attemptDeadServiceRecovery(e);
        return 0x03; /*ERROR_UNKNOWN*/
      }
    }

    /**
     * This api is called by applications to check whether field
     * detect feature is enabled or not
     * <p>Requires {@link android.Manifest.permission#NFC} permission.<ul>
     * <li>This api shall be called only Nfcservice is enabled.

     * </ul>
     * @param  None
     * @return whether  the feature is enabled(true) disabled (false)
     *          success or not.
     *          Enabled  - true
     *          Disabled - false
     * @throws  IOException if any exception occurs during setting the NFC configuration.
     */
    public boolean isFieldDetectEnabled() {
      try {
        return sNxpService.isFieldDetectEnabled();
      } catch (RemoteException e) {
        e.printStackTrace();
        attemptDeadServiceRecovery(e);
        return false;
      }
    }

    /**
     * This api is called by applications to Activate Secure Element Interface.
     * <p>Requires {@link android.Manifest.permission#NFC} permission.<ul>
     * <li>This api shall be called only Nfcservice is enabled.
     * </ul>
     * @return whether  the update of configuration is
     *          success or not.
     *          0x03 - failure
     *          0x00 - success
     *          0xFF - Service Unavialable
     * @throws  IOException if any exception occurs during setting the NFC
     * configuration.
     */
    public int activateSeInterface() throws IOException {
      try {
        return sNxpService.activateSeInterface();
      } catch (RemoteException e) {
        e.printStackTrace();
        attemptDeadServiceRecovery(e);
        return 0xFF;
      }
    }
    /**
     * This api is called by applications to Deactivate Secure Element Interface.
     * <p>Requires {@link android.Manifest.permission#NFC} permission.<ul>
     * <li>This api shall be called only Nfcservice is enabled.
     * </ul>
     * @return whether  the update of configuration is
     *          success or not.
     *          0x03 - failure
     *          0x00 - success
     *          0xFF - Service Unavialable
     * @throws  IOException if any exception occurs during setting the NFC
     * configuration.
     */
    public int deactivateSeInterface() throws IOException {
      try {
        return sNxpService.deactivateSeInterface();
      } catch (RemoteException e) {
        e.printStackTrace();
        attemptDeadServiceRecovery(e);
        return 0xFF;
      }
    }

    /**
     * This API performs writes of T4T data to Nfcee.
     * @param fileId File Id to which to write
     * @param data data bytes to be written
     * @param length current data length
     * @return number of bytes written if success else negative number of
                error code listed as here .
                -1  STATUS_FAILED
                -2  ERROR_RF_ACTIVATED
                -3  ERROR_MPOS_ON
                -4  ERROR_NFC_NOT_ON
                -5  ERROR_INVALID_FILE_ID
                -6  ERROR_INVALID_LENGTH
                -7  ERROR_CONNECTION_FAILED
                -8  ERROR_EMPTY_PAYLOAD
                -9  ERROR_NDEF_VALIDATION_FAILED
     * <p>Requires {@link   android.Manifest.permission#NFC} permission.
     */
    public int doWriteT4tData(byte[] fileId, byte[] data, int length) {
      try {
        return sNxpService.doWriteT4tData(fileId, data, length);
      } catch (RemoteException e) {
        e.printStackTrace();
        attemptDeadServiceRecovery(e);
        return -1;
      }
    }

    /**
     * This API performs reading of T4T content of Nfcee.
     * @param fileId : File Id from which to read
     * @return read bytes :-Returns read message if success
     *                      Returns null if failed to read
     *                      Returns 0xFF if file is empty.
     * <p>Requires {@link   android.Manifest.permission#NFC} permission.
     */
    public byte[] doReadT4tData(byte[] fileId) {
      try {
        return sNxpService.doReadT4tData(fileId);
      } catch (RemoteException e) {
        e.printStackTrace();
        attemptDeadServiceRecovery(e);
        return null;
      }
    }
}
