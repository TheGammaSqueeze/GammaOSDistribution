/*
 * Copyright (c) 2020-2021, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of The Linux Foundation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

package com.qti.extphone;

import android.telephony.ImsiEncryptionInfo;

import com.qti.extphone.Token;
import com.qti.extphone.Client;
import com.qti.extphone.IDepersoResCallback;
import com.qti.extphone.IExtPhoneCallback;
import com.qti.extphone.NrConfig;
import com.qti.extphone.QtiImeiInfo;

interface IExtPhone {

    /**
    * Get value assigned to vendor property
    * @param - property name
    * @param - default value of property
    * @return - integer value assigned
    * Requires permission: android.Manifest.permission.READ_PRIVILEGED_PHONE_STATE
    */
    int getPropertyValueInt(String property, int def);

    /**
    * Get value assigned to vendor property
    * @param - property name
    * @param - default value of property
    * @return - boolean value assigned
    * Requires permission: android.Manifest.permission.READ_PRIVILEGED_PHONE_STATE
    */
    boolean getPropertyValueBool(String property, boolean def);

    /**
    * Get value assigned to vendor property
    * @param - property name
    * @param - default value of property
    * @return - string value assigned
    * Requires permission: android.Manifest.permission.READ_PRIVILEGED_PHONE_STATE
    */
    String getPropertyValueString(String property, String def);

    /**
    * Get current primary card slot Id.
    * @param - void
    * @return slot index
    * Requires permission: android.Manifest.permission.READ_PRIVILEGED_PHONE_STATE
    */
    int getCurrentPrimaryCardSlotId();

    /**
    * Returns ID of the slot in which PrimaryCarrier SIM card is present.
    * If none of the slots contains PrimaryCarrier SIM, this would return '-1'
    * Supported values: 0, 1, -1
    * Requires permission: android.Manifest.permission.READ_PRIVILEGED_PHONE_STATE
    */
    int getPrimaryCarrierSlotId();

    /**
    * Check if slotId has PrimaryCarrier SIM card present or not.
    * @param - slotId
    * @return true or false
    * Requires permission: android.Manifest.permission.READ_PRIVILEGED_PHONE_STATE
    */
    boolean isPrimaryCarrierSlotId(int slotId);

    /**
    * Set Primary card on given slot.
    * @param - slotId to be set as Primary Card.
    * @return void
    * Requires permission: android.Manifest.permission.MODIFY_PHONE_STATE
    */
    void setPrimaryCardOnSlot(int slotId);

    /**
    * Perform incremental scan using QCRIL hooks.
    * @param - slotId
    *          Range: 0 <= slotId < {@link TelephonyManager#getActiveModemCount()}
    * @return true if the request has successfully been sent to the modem, false otherwise.
    * Requires permission: android.Manifest.permission.MODIFY_PHONE_STATE
    */
    boolean performIncrementalScan(int slotId);

    /**
    * Abort incremental scan using QCRIL hooks.
    * @param - slotId
    *          Range: 0 <= slotId < {@link TelephonyManager#getActiveModemCount()}
    * @return true if the request has successfully been sent to the modem, false otherwise.
    * Requires permission: android.Manifest.permission.MODIFY_PHONE_STATE
    */
    boolean abortIncrementalScan(int slotId);

    /**
    * Check for Sms Prompt is Enabled or Not.
    * @return
    *        true - Sms Prompt is Enabled
    *        false - Sms prompt is Disabled
    * Requires permission: android.Manifest.permission.READ_PRIVILEGED_PHONE_STATE
    */
    boolean isSMSPromptEnabled();

    /**
    * Enable/Disable Sms prompt option.
    * @param - enabled
    *        true - to enable Sms prompt
    *        false - to disable Sms prompt
    * Requires Permission: android.Manifest.permission.MODIFY_PHONE_STATE
    */
    void setSMSPromptEnabled(boolean enabled);

    /**
    * supply pin to unlock sim locked on network.
    * @param - netpin - network pin to unlock the sim.
    * @param - type - PersoSubState for which the sim is locked onto.
    * @param - callback - callback to notify UI, whether the request was success or failure.
    * @param - phoneId - slot id on which the pin request is sent.
    * @return void
    * Requires permission: android.Manifest.permission.MODIFY_PHONE_STATE
    */
    void supplyIccDepersonalization(String netpin, String type, in IDepersoResCallback callback,
            int phoneId);

    /**
    * Async api
    * Requires permission: android.Manifest.permission.READ_PRIVILEGED_PHONE_STATE
    */
    Token queryNrIconType(int slotId, in Client client);

    /**
    * Enable/disable endc on a given slotId.
    * @param - slotId
    * @param - enabled
    *        true - to enable endc
    *        false - to disable endc
    *  @param - client registered with packagename to receive
    *         callbacks.
    * @return Integer Token to be used to compare with the response.
    * Requires permission: android.Manifest.permission.MODIFY_PHONE_STATE
    */
    Token enableEndc(int slotId, boolean enable, in Client client);

    /**
    * To query endc status on a given slotId.
    * @param - slotId
    * @param - client registered with packagename to receive
    *         callbacks.
    * @return Integer Token to be used to compare with the response.
    * Requires permission: android.Manifest.permission.READ_PRIVILEGED_PHONE_STATE
    */
    Token queryEndcStatus(int slotId, in Client client);

    /**
    * Async api
    * Requires permission: android.Manifest.permission.READ_PRIVILEGED_PHONE_STATE
    */
    Client registerCallback(String packageName, IExtPhoneCallback callback);

    /**
    * Async api
    * Requires permission: android.Manifest.permission.READ_PRIVILEGED_PHONE_STATE
    */
    void unRegisterCallback(IExtPhoneCallback callback);

    /**
    * Set nr config to NSA/SA/NSA+SA on a given slotId.
    * @param - slotId
    * @param - def
    *        NR_CONFIG_INVALID  - invalid config
    *        NR_CONFIG_COMBINED_SA_NSA - set to NSA+SA
    *        NR_CONFIG_NSA - set to NSA
    *        NR_CONFIG_SA - set to SA
    *  @param - client registered with packagename to receive
    *         callbacks.
    * @return Integer Token to be used to compare with the response.
    * Requires permission: android.Manifest.permission.MODIFY_PHONE_STATE
    */
    Token setNrConfig(int slotId, in NrConfig def, in Client client);

    /**
    * Query current nr config on a given slotId.
    * @param - slotId
    *  @param - client registered with packagename to receive
    *         callbacks.
    * @return Integer Token to be used to compare with the response.
    * Requires permission: android.Manifest.permission.READ_PRIVILEGED_PHONE_STATE
    */
    Token queryNrConfig(int slotId, in Client client);

    /**
    * Send a CDMA SMS message on a given slotId.
    * @param - slotId
    * @param - pdu contains the message to be sent
    *         callbacks.
    * @param expectMore more messages are expected to be sent or not
    * @return Integer Token to be used to compare with the response.
    * Requires permission: android.Manifest.permission.MODIFY_PHONE_STATE
    */
    Token sendCdmaSms(int slotId, in byte[] pdu, boolean expectMore, in Client client);

    /**
    * Get phone radio capability.
    * @param - slotId
    * @param - client registered with packagename to receive callbacks.
    * @return Integer Token to be used to compare with the response.
    * Requires permission: android.Manifest.permission.READ_PRIVILEGED_PHONE_STATE
    */
    Token getQtiRadioCapability(int slotId, in Client client);

    /**
    * Async api
    * @deprecated
    */
    Token enable5g(int slotId, in Client client);

    /**
    * Async api
    * @deprecated
    */
    Token disable5g(int slotId, in Client client);

    /**
    * Async api
    * @deprecated
    */
    Token queryNrBearerAllocation(int slotId, in Client client);

    /**
    * Async api
    * @deprecated
    */
    Token enable5gOnly(int slotId, in Client client);

    /**
    * Async api
    * @deprecated
    */
    Token query5gStatus(int slotId, in Client client);

    /**
    * Async api
    * a.k.a NR EN-DC and restrict-DCNR.
    * @deprecated
    */
    Token queryNrDcParam(int slotId, in Client client);

    /**
    * Async api
    * @deprecated
    */
    Token queryNrSignalStrength(int slotId, in Client client);

    /**
    * Async api
    * @deprecated
    */
    Token queryUpperLayerIndInfo(int slotId, in Client client);

    /**
    * Async api
    * @deprecated
    */
    Token query5gConfigInfo(int slotId, in Client client);

    /**
    * Send a CarrierInfoForImsiEncryption request.
    * @param - slotId
    * @param - pdu contains the message to be sent
    *         callbacks.
    * @param expectMore more messages are expected to be sent or not
    * @return Integer Token to be used to compare with the response.
    */
    Token setCarrierInfoForImsiEncryption(int slotId,
            in ImsiEncryptionInfo info, in Client client);

   /**
     * Query call forward status for the given reason.
     *
     * cfReason is one of CF_REASON_*
     * @param expectMore more messages are expected to be sent or not
     * @param - client registered with packagename to receive
     *         callbacks.
     */
    void queryCallForwardStatus(int slotId, int cfReason, int serviceClass, String number,
            boolean expectMore, in Client client);

    /**
     * Query the status of a facility lock state
     *
     * @param facility is the facility string code from TS 27.007 7.4
     *        (eg "AO" for BAOC, "SC" for SIM lock)
     * @param password is the password, or "" if not required
     * @param serviceClass is the TS 27.007 service class bit vector of services to query
     * @param appId is AID value, See ETSI 102.221 8.1 and 101.220 4, empty string if no value.
     *        This is only applicable in the case of Fixed Dialing Numbers (FDN) requests.
     * @param - client registered with packagename to receive
     *         callbacks.
     */
    void getFacilityLockForApp(int slotId, String facility, String password, int serviceClass,
            String appId, boolean expectMore, in Client client);

    /**
     * Check whether the smart DDS switch feature supported
     *
     * @return - boolean value indicating whether the smart DDS switch feature is available
     */
    boolean isSmartDdsSwitchFeatureAvailable();

    /**
     * Enable/disable the smart DDS switch
     *
     * @param - isEnabled is the switch on or off, true: on, false: off
     * @param - client registered with packagename to receive callbacks
     */
    void setSmartDdsSwitchToggle(boolean isEnabled, in Client client);

    boolean isFeatureSupported(int feature);

   /**
    * To get the IMEI information of all slots on device
    * @return
    *        QtiImeiInfo[], contains array imeiInfo(i.e slotId, IMEI string and type)
    * Requires Permission: android.Manifest.permission.READ_PRIVILEGED_PHONE_STATE
    */
    QtiImeiInfo[] getImeiInfo();

    /**
     * Request for smart DDS switch capability supported by modem.
     * @param - slotId slot ID
     * @return - Integer Token can be used to compare with the response.
     */
    Token getDdsSwitchCapability(int slotId, in Client client);

    /**
     * Inform modem if user enabled/disabled UI preference for data during voice call.
     * if its enabled then modem can send recommendations to switch DDS during
     * voice call on nonDDS.
     * @param - slotId slot ID
     * @param - userPreference true/false based on UI preference
     * @param - client registered with packagename to receive
     *         callbacks.
     * @return - Integer Token can be used to compare with the response.
     */
     Token sendUserPreferenceForDataDuringVoiceCall(int slotId,
             boolean userPreference, in Client client);

    /**
     * Request for epdg over cellular data (cellular IWLAN) feature is supported or not.
     *
     * @param - slotId slot ID
     * @return - boolean value indicates if the feature is supported or not
     */
     boolean isEpdgOverCellularDataSupported(int slotId);
}
