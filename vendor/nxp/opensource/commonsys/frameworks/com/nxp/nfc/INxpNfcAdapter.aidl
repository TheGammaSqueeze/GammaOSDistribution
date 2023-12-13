 /*
  * Copyright 2015-2021 NXP
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
package com.nxp.nfc;

import com.nxp.nfc.INxpNfcAdapterExtras;
/**
 * @hide
 */
interface INxpNfcAdapter
{
    void DefaultRouteSet(int routeLoc, boolean fullPower, boolean lowPower, boolean noPower);
    void MifareDesfireRouteSet(int routeLoc, boolean fullPower, boolean lowPower, boolean noPower);
    void MifareCLTRouteSet(int routeLoc, boolean fullPower, boolean lowPower, boolean noPower);
    void NfcFRouteSet(int routeLoc, boolean fullPower, boolean lowPower, boolean noPower);
    int[] getActiveSecureElementList(String pkg);
    INxpNfcAdapterExtras getNxpNfcAdapterExtrasInterface();
    int mPOSSetReaderMode(String pkg, boolean on);
    boolean mPOSGetReaderMode(String pkg);
    void stopPoll(String pkg, int mode);
    void changeDiscoveryTech(IBinder binder, int pollTech, int listenTech);
    void startPoll(String pkg);
    byte[]  getFWVersion();
    byte[] readerPassThruMode(byte status, byte modulationTyp);
    byte[] transceiveAppData(in byte[] data);
    int setConfig(String configs , String pkg);
    int selectUicc(int uiccSlot);
    int getMaxAidRoutingTableSize();
    int getCommittedAidRoutingTableSize();
    int getSelectedUicc();
    int activateSeInterface();
    int deactivateSeInterface();
    int setFieldDetectMode(boolean mode);
    boolean isFieldDetectEnabled();
    int doWriteT4tData(in byte[] fileId, in byte[] data, int length);
    byte[] doReadT4tData(in byte[] fileId);
    int nfcSelfTest(int type);
    int configureSecureReader(boolean on, String readerType);
}
