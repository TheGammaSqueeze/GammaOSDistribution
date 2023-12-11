/******************************************************************************
 *
 *  Copyright (C) 1999-2012 Broadcom Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/

/******************************************************************************
 *
 *  This file contains the Bluetooth Manager (BTM) API function external
 *  definitions.
 *
 ******************************************************************************/
#ifndef BTM_BLE_API_H
#define BTM_BLE_API_H

#include <base/callback_forward.h>
#include <hardware/bt_common_types.h>
#include <memory>
#include "bt_common.h"
#include "btm_api.h"
#include "btm_ble_api_types.h"
#include "osi/include/alarm.h"
#include "stack/btm/btm_ble_bgconn.h"

/*****************************************************************************
 *  EXTERNAL FUNCTION DECLARATIONS
 ****************************************************************************/
/*******************************************************************************
 *
 * Function         BTM_SecAddBleDevice
 *
 * Description      Add/modify device.  This function will be normally called
 *                  during host startup to restore all required information
 *                  for a LE device stored in the NVRAM.
 *
 * Parameters:      bd_addr          - BD address of the peer
 *                  bd_name          - Name of the peer device. NULL if unknown.
 *                  dev_type         - Remote device's device type.
 *                  addr_type        - LE device address type.
 *
 * Returns          true if added OK, else false
 *
 ******************************************************************************/
extern bool BTM_SecAddBleDevice(const RawAddress& bd_addr, BD_NAME bd_name,
                                tBT_DEVICE_TYPE dev_type,
                                tBLE_ADDR_TYPE addr_type);

/*******************************************************************************
 *
 * Function         BTM_SecAddBleKey
 *
 * Description      Add/modify LE device information.  This function will be
 *                  normally called during host startup to restore all required
 *                  information stored in the NVRAM.
 *
 * Parameters:      bd_addr          - BD address of the peer
 *                  p_le_key         - LE key values.
 *                  key_type         - LE SMP key type.
*
 * Returns          true if added OK, else false
 *
 ******************************************************************************/
extern bool BTM_SecAddBleKey(const RawAddress& bd_addr,
                             tBTM_LE_KEY_VALUE* p_le_key,
                             tBTM_LE_KEY_TYPE key_type);

/*******************************************************************************
 *
 * Function         BTM_BleObtainVendorCapabilities
 *
 * Description      This function is called to obatin vendor capabilties
 *
 * Parameters       p_cmn_vsc_cb - Returns the vednor capabilities
 *
 * Returns          void
 *
 ******************************************************************************/
extern void BTM_BleObtainVendorCapabilities(tBTM_BLE_VSC_CB* p_cmn_vsc_cb);

/**
 * This function is called to set scan parameters. |cb| is called with operation
 * status
 **/
extern void BTM_BleSetScanParams(uint8_t scan_phy, std::vector<uint32_t> scan_interval,
                                 std::vector<uint32_t> scan_window,
                                 tBLE_SCAN_MODE scan_type,
                                 base::Callback<void(uint8_t)> cb);

/*******************************************************************************
 *
 * Function         BTM_BleGetVendorCapabilities
 *
 * Description      This function reads local LE features
 *
 * Parameters       p_cmn_vsc_cb : Locala LE capability structure
 *
 * Returns          void
 *
 ******************************************************************************/
extern void BTM_BleGetVendorCapabilities(tBTM_BLE_VSC_CB* p_cmn_vsc_cb);

/*******************************************************************************
 *
 * Function         BTM_BleGetDynamicAudioBuffer
 *
 * Description      This function reads dynamic audio buffer
 *
 * Parameters       p_dynamic_audio_buffer_cb : Dynamic Audio Buffer structure
 *
 * Returns          void
 *
 ******************************************************************************/
extern void BTM_BleGetDynamicAudioBuffer(
    tBTM_BT_DYNAMIC_AUDIO_BUFFER_CB* p_dynamic_audio_buffer_cb);

/*******************************************************************************
 *
 * Function         BTM_BleSetStorageConfig
 *
 * Description      This function is called to setup storage configuration and
 *                  setup callbacks.
 *
 * Parameters       uint8_t batch_scan_full_max -Batch scan full maximum
                    uint8_t batch_scan_trunc_max - Batch scan truncated value
 maximum
                    uint8_t batch_scan_notify_threshold - Threshold value
                    cb - Setup callback
                    tBTM_BLE_SCAN_THRESHOLD_CBACK *p_thres_cback -Threshold
 callback
                    void *p_ref - Reference value
 *
 *
 ******************************************************************************/
extern void BTM_BleSetStorageConfig(
    uint8_t batch_scan_full_max, uint8_t batch_scan_trunc_max,
    uint8_t batch_scan_notify_threshold,
    base::Callback<void(uint8_t /* status */)> cb,
    tBTM_BLE_SCAN_THRESHOLD_CBACK* p_thres_cback, tBTM_BLE_REF_VALUE ref_value);

/* This function is called to enable batch scan */
extern void BTM_BleEnableBatchScan(
    tBTM_BLE_BATCH_SCAN_MODE scan_mode, uint32_t scan_interval,
    uint32_t scan_window, tBTM_BLE_DISCARD_RULE discard_rule,
    tBLE_ADDR_TYPE addr_type, base::Callback<void(uint8_t /* status */)> cb);

/* This function is called to disable batch scanning */
extern void BTM_BleDisableBatchScan(
    base::Callback<void(uint8_t /* status */)> cb);

/* This function is called to read batch scan reports */
extern void BTM_BleReadScanReports(tBLE_SCAN_MODE scan_mode,
                                   tBTM_BLE_SCAN_REP_CBACK cb);

/* This function is called to setup the callback for tracking */
extern void BTM_BleTrackAdvertiser(tBTM_BLE_TRACK_ADV_CBACK* p_track_cback,
                                   tBTM_BLE_REF_VALUE ref_value);

/*******************************************************************************
 *
 * Function         BTM_BleWriteScanRsp
 *
 * Description      This function is called to write LE scan response.
 *
 * Parameters:      p_scan_rsp: scan response.
 *
 * Returns          status
 *
 ******************************************************************************/
extern void BTM_BleWriteScanRsp(uint8_t* data, uint8_t length,
                                tBTM_BLE_ADV_DATA_CMPL_CBACK* p_adv_data_cback);

/*******************************************************************************
 *
 * Function         BTM_BleObserve
 *
 * Description      This procedure keep the device listening for advertising
 *                  events from a broadcast device.
 *
 * Parameters       start: start or stop observe.
 *
 * Returns          void
 *
 ******************************************************************************/
extern tBTM_STATUS BTM_BleObserve(bool start, uint8_t duration,
                                  tBTM_INQ_RESULTS_CB* p_results_cb,
                                  tBTM_CMPL_CB* p_cmpl_cb);

/** Returns local device encryption root (ER) */
const Octet16& BTM_GetDeviceEncRoot();

/** Returns local device identity root (IR) */
extern const Octet16& BTM_GetDeviceIDRoot();

/** Return local device DHK. */
extern const Octet16& BTM_GetDeviceDHK();

/*******************************************************************************
 *
 * Function         BTM_SecurityGrant
 *
 * Description      This function is called to grant security process.
 *
 * Parameters       bd_addr - peer device bd address.
 *                  res     - result of the operation BTM_SUCCESS if success.
 *                            Otherwise, BTM_REPEATED_ATTEMPTS is too many
 *                            attempts.
 *
 * Returns          None
 *
 ******************************************************************************/
extern void BTM_SecurityGrant(const RawAddress& bd_addr, uint8_t res);

/*******************************************************************************
 *
 * Function         BTM_BlePasskeyReply
 *
 * Description      This function is called after Security Manager submitted
 *                  passkey request to the application.
 *
 * Parameters:      bd_addr - Address of the device for which passkey was
 *                            requested
 *                  res     - result of the operation SMP_SUCCESS if success
 *                  passkey - numeric value in the range of
 *                               BTM_MIN_PASSKEY_VAL(0) -
 *                               BTM_MAX_PASSKEY_VAL(999999(0xF423F)).
 *
 ******************************************************************************/
extern void BTM_BlePasskeyReply(const RawAddress& bd_addr, uint8_t res,
                                uint32_t passkey);

/*******************************************************************************
 *
 * Function         BTM_BleConfirmReply
 *
 * Description      This function is called after Security Manager submitted
 *                  numeric comparison request to the application.
 *
 * Parameters:      bd_addr      - Address of the device with which numeric
 *                                 comparison was requested
 *                  res          - comparison result BTM_SUCCESS if success
 *
 ******************************************************************************/
extern void BTM_BleConfirmReply(const RawAddress& bd_addr, uint8_t res);

/*******************************************************************************
 *
 * Function         BTM_LeOobDataReply
 *
 * Description      This function is called to provide the OOB data for
 *                  SMP in response to BTM_LE_OOB_REQ_EVT
 *
 * Parameters:      bd_addr     - Address of the peer device
 *                  res         - result of the operation SMP_SUCCESS if success
 *                  p_data      - simple pairing Randomizer  C.
 *
 ******************************************************************************/
extern void BTM_BleOobDataReply(const RawAddress& bd_addr, uint8_t res,
                                uint8_t len, uint8_t* p_data);

/*******************************************************************************
 *
 * Function         BTM_BleSecureConnectionOobDataReply
 *
 * Description      This function is called to provide the OOB data for
 *                  SMP in response to BTM_LE_OOB_REQ_EVT when secure connection
 *                  data is available
 *
 * Parameters:      bd_addr     - Address of the peer device
 *                  p_c         - pointer to Confirmation
 *                  p_r         - pointer to Randomizer.
 *
 ******************************************************************************/
extern void BTM_BleSecureConnectionOobDataReply(const RawAddress& bd_addr,
                                                uint8_t* p_c, uint8_t* p_r);

/*******************************************************************************
 *
 * Function         BTM_BleDataSignature
 *
 * Description      This function is called to sign the data using AES128 CMAC
 *                  algorith.
 *
 * Parameter        bd_addr: target device the data to be signed for.
 *                  p_text: singing data
 *                  len: length of the signing data
 *                  signature: output parameter where data signature is going to
 *                             be stored.
 *
 * Returns          true if signing sucessul, otherwise false.
 *
 ******************************************************************************/
extern bool BTM_BleDataSignature(const RawAddress& bd_addr, uint8_t* p_text,
                                 uint16_t len, BLE_SIGNATURE signature);

/*******************************************************************************
 *
 * Function         BTM_BleVerifySignature
 *
 * Description      This function is called to verify the data signature
 *
 * Parameter        bd_addr: target device the data to be signed for.
 *                  p_orig:  original data before signature.
 *                  len: length of the signing data
 *                  counter: counter used when doing data signing
 *                  p_comp: signature to be compared against.

 * Returns          true if signature verified correctly; otherwise false.
 *
 ******************************************************************************/
extern bool BTM_BleVerifySignature(const RawAddress& bd_addr, uint8_t* p_orig,
                                   uint16_t len, uint32_t counter,
                                   uint8_t* p_comp);

/*******************************************************************************
 *
 * Function         BTM_ReadConnectionAddr
 *
 * Description      Read the local device random address.
 *
 * Returns          void
 *
 ******************************************************************************/
extern void BTM_ReadConnectionAddr(const RawAddress& remote_bda,
                                   RawAddress& local_conn_addr,
                                   tBLE_ADDR_TYPE* p_addr_type);

/*******************************************************************************
 *
 * Function         BTM_IsBleConnection
 *
 * Description      This function is called to check if the connection handle
 *                  for an LE link
 *
 * Returns          true if connection is LE link, otherwise false.
 *
 ******************************************************************************/
extern bool BTM_IsBleConnection(uint16_t conn_handle);

/*******************************************************************************
 *
 * Function         BTM_ReadRemoteConnectionAddr
 *
 * Description      Read the remote device address currently used.
 *
 * Returns          void
 *
 ******************************************************************************/
extern bool BTM_ReadRemoteConnectionAddr(const RawAddress& pseudo_addr,
                                         RawAddress& conn_addr,
                                         tBLE_ADDR_TYPE* p_addr_type);

/*******************************************************************************
 *
 * Function         BTM_BleLoadLocalKeys
 *
 * Description      Local local identity key, encryption root or sign counter.
 *
 * Parameters:      key_type: type of key, can be BTM_BLE_KEY_TYPE_ID,
 *                            BTM_BLE_KEY_TYPE_ER
 *                            or BTM_BLE_KEY_TYPE_COUNTER.
 *                  p_key: pointer to the key.
*
 * Returns          non2.
 *
 ******************************************************************************/
extern void BTM_BleLoadLocalKeys(uint8_t key_type, tBTM_BLE_LOCAL_KEYS* p_key);


/********************************************************
 *
 * Function         BTM_BleSetPrefConnParams
 *
 * Description      Set a peripheral's preferred connection parameters. When
 *                  any of the value does not want to be updated while others
 *                  do, use BTM_BLE_CONN_PARAM_UNDEF for the ones want to
 *                  leave untouched.
 *
 * Parameters:      bd_addr          - BD address of the peripheral
 *                  min_conn_int     - minimum preferred connection interval
 *                  max_conn_int     - maximum preferred connection interval
 *                  slave_latency    - preferred slave latency
 *                  supervision_tout - preferred supervision timeout
 *
 * Returns          void
 *
 ******************************************************************************/
extern void BTM_BleSetPrefConnParams(const RawAddress& bd_addr,
                                     uint16_t min_conn_int,
                                     uint16_t max_conn_int,
                                     uint16_t slave_latency,
                                     uint16_t supervision_tout);

/******************************************************************************
 *
 * Function         BTM_BleSetConnScanParams
 *
 * Description      Set scan parameters used in BLE connection request
 *
 * Parameters:      scan_interval    - scan interval
 *                  scan_window      - scan window
 *
 * Returns          void
 *
 ******************************************************************************/
extern void BTM_BleSetConnScanParams(uint32_t scan_interval,
                                     uint32_t scan_window);

/******************************************************************************
 *
 * Function         BTM_BleReadControllerFeatures
 *
 * Description      Reads BLE specific controller features
 *
 * Parameters:      tBTM_BLE_CTRL_FEATURES_CBACK : Callback to notify when
 *                  features are read
 *
 * Returns          void
 *
 ******************************************************************************/
extern void BTM_BleReadControllerFeatures(
    tBTM_BLE_CTRL_FEATURES_CBACK* p_vsc_cback);

/*******************************************************************************
 *
 * Function         BTM__BLEReadDiscoverability
 *
 * Description      This function is called to read the current LE
 *                  discoverability mode of the device.
 *
 * Returns          BTM_BLE_NON_DISCOVERABLE ,BTM_BLE_LIMITED_DISCOVERABLE or
 *                     BTM_BLE_GENRAL_DISCOVERABLE
 *
 ******************************************************************************/
uint16_t BTM_BleReadDiscoverability();

/*******************************************************************************
 *
 * Function         BTM__BLEReadConnectability
 *
 * Description      This function is called to read the current LE
 *                  connectibility mode of the device.
 *
 * Returns          BTM_BLE_NON_CONNECTABLE or BTM_BLE_CONNECTABLE
 *
 ******************************************************************************/
extern uint16_t BTM_BleReadConnectability();

/*******************************************************************************
 *
 * Function         BTM_ReadDevInfo
 *
 * Description      This function is called to read the device/address type
 *                  of BD address.
 *
 * Parameter        remote_bda: remote device address
 *                  p_dev_type: output parameter to read the device type.
 *                  p_addr_type: output parameter to read the address type.
 *
 ******************************************************************************/
extern void BTM_ReadDevInfo(const RawAddress& remote_bda,
                            tBT_DEVICE_TYPE* p_dev_type,
                            tBLE_ADDR_TYPE* p_addr_type);

/*******************************************************************************
 *
 * Function         BTM_ReadDevScanInfo
 *
 * Description      This function is called to read the device/address type
 *                  of BD address.
 *
 * Parameter        remote_bda: remote device address
 *                  p_dev_type: output parameter to read the device type.
 *                  p_addr_type: output parameter to read the address type.
 *
 ******************************************************************************/
extern void BTM_ReadDevScanInfo(const RawAddress& remote_bda,
                            tBT_DEVICE_TYPE* p_dev_type,
                            tBLE_ADDR_TYPE* p_addr_type);


/*******************************************************************************
 *
 * Function         BTM_ReadConnectedTransportAddress
 *
 * Description      This function is called to read the paired device/address
 *                  type of other device paired corresponding to the BD_address
 *
 * Parameter        remote_bda: remote device address, carry out the transport
 *                              address
 *                  transport: active transport
 *
 * Return           true if an active link is identified; false otherwise
 *
 ******************************************************************************/
extern bool BTM_ReadConnectedTransportAddress(RawAddress* remote_bda,
                                              tBT_TRANSPORT transport);

/*******************************************************************************
 *
 * Function         BTM_BleConfigPrivacy
 *
 * Description      This function is called to enable or disable the privacy in
 *                  the local device.
 *
 * Parameters       enable: true to enable it; false to disable it.
 *
 * Returns          bool    privacy mode set success; otherwise failed.
 *
 ******************************************************************************/
extern bool BTM_BleConfigPrivacy(bool enable);

/*******************************************************************************
 *
 * Function         BTM_BleLocalPrivacyEnabled
 *
 * Description        Checks if local device supports private address
 *
 * Returns          Return true if local privacy is enabled else false
 *
 ******************************************************************************/
extern bool BTM_BleLocalPrivacyEnabled(void);

/*******************************************************************************
 *
 * Function         BTM_BleEnableMixedPrivacyMode
 *
 * Description      This function is called to enabled Mixed mode if privacy 1.2
 *                  is applicable in controller.
 *
 * Parameters       mixed_on:  mixed mode to be used or not.
 *
 * Returns          void
 *
 ******************************************************************************/
extern void BTM_BleEnableMixedPrivacyMode(bool mixed_on);

/*******************************************************************************
 *
 * Function          BTM_BleMaxMultiAdvInstanceCount
 *
 * Description      Returns the maximum number of multi adv instances supported
 *                  by the controller.
 *
 * Returns          Max multi adv instance count
 *
 ******************************************************************************/
extern uint8_t BTM_BleMaxMultiAdvInstanceCount();

/*******************************************************************************
 *
 * Function         BTM_BleSetConnectableMode
 *
 * Description      This function is called to set BLE connectable mode for a
 *                  peripheral device.
 *
 * Parameters       connectable_mode:  directed connectable mode, or
 *                                     non-directed. It can be
 *                                     BTM_BLE_CONNECT_EVT,
 *                                     BTM_BLE_CONNECT_DIR_EVT or
 *                                     BTM_BLE_CONNECT_LO_DUTY_DIR_EVT
 *
 * Returns          BTM_ILLEGAL_VALUE if controller does not support BLE.
 *                  BTM_SUCCESS is status set successfully; otherwise failure.
 *
 ******************************************************************************/
extern tBTM_STATUS BTM_BleSetConnectableMode(
    tBTM_BLE_CONN_MODE connectable_mode);

/*******************************************************************************
 *
 * Function         BTM_BleTurnOnPrivacyOnRemote
 *
 * Description      This function is called to enable or disable the privacy on
 *                  the remote device.
 *
 * Parameters       bd_addr: remote device address.
 *                  privacy_on: true to enable it; false to disable it.
 *
 * Returns          void
 *
 ******************************************************************************/
extern void BTM_BleTurnOnPrivacyOnRemote(const RawAddress& bd_addr,
                                         bool privacy_on);

/*******************************************************************************
 *
 * Function         BTM_BleUpdateAdvFilterPolicy
 *
 * Description      This function update the filter policy of advertiser.
 *
 * Parameter        adv_policy: advertising filter policy
 *
 * Return           void
 ******************************************************************************/
extern void BTM_BleUpdateAdvFilterPolicy(tBTM_BLE_AFP adv_policy);

/*******************************************************************************
 *
 * Function         BTM_BleReceiverTest
 *
 * Description      This function is called to start the LE Receiver test
 *
 * Parameter       rx_freq - Frequency Range
 *               p_cmd_cmpl_cback - Command Complete callback
 *
 ******************************************************************************/
void BTM_BleReceiverTest(uint8_t rx_freq, tBTM_CMPL_CB* p_cmd_cmpl_cback);

/*******************************************************************************
 *
 * Function         BTM_BleTransmitterTest
 *
 * Description      This function is called to start the LE Transmitter test
 *
 * Parameter       tx_freq - Frequency Range
 *                       test_data_len - Length in bytes of payload data in each
 *                                       packet
 *                       packet_payload - Pattern to use in the payload
 *                       p_cmd_cmpl_cback - Command Complete callback
 *
 ******************************************************************************/
void BTM_BleTransmitterTest(uint8_t tx_freq, uint8_t test_data_len,
                            uint8_t packet_payload,
                            tBTM_CMPL_CB* p_cmd_cmpl_cback);

/*******************************************************************************
 *
 * Function         BTM_BleTestEnd
 *
 * Description     This function is called to stop the in-progress TX or RX test
 *
 * Parameter       p_cmd_cmpl_cback - Command complete callback
 *
 ******************************************************************************/
void BTM_BleTestEnd(tBTM_CMPL_CB* p_cmd_cmpl_cback);

/*******************************************************************************
 *
 * Function         BTM_UseLeLink
 *
 * Description      Select the underlying physical link to use.
 *
 * Returns          true to use LE, false use BR/EDR.
 *
 ******************************************************************************/
extern bool BTM_UseLeLink(const RawAddress& bd_addr);

/*******************************************************************************
 *
 * Function         BTM_BleStackEnable
 *
 * Description      Enable/Disable BLE functionality on stack regardless of
 *                  controller capability.
 *
 * Parameters:      enable: true to enable, false to disable.
 *
 * Returns          true if added OK, else false
 *
 ******************************************************************************/
extern tBTM_STATUS BTM_BleStackEnable(bool enable);

/*******************************************************************************
 *
 * Function         BTM_GetLeSecurityState
 *
 * Description      This function is called to get security mode 1 flags and
 *                  encryption key size for LE peer.
 *
 * Returns          bool    true if LE device is found, false otherwise.
 *
 ******************************************************************************/
extern bool BTM_GetLeSecurityState(const RawAddress& bd_addr,
                                   uint8_t* p_le_dev_sec_flags,
                                   uint8_t* p_le_key_size);

#if (BT_IOT_LOGGING_ENABLED == TRUE)
/*******************************************************************************
*
* Function         BTM_GetRemoteDeviceName
*
* Description      This function is called to get the dev name of remote device
*                  from NV
*
* Returns          true if success; otherwise failed.
*
*******************************************************************************/
extern bool BTM_GetRemoteDeviceName(const RawAddress& bda, BD_NAME bd_name);
#endif

/*******************************************************************************
 *
 * Function         BTM_GetRemoteQLLFeatures
 *
 * Description      This function is called to get remote QLL features
 *
 * Returns          true if feature value is available
 *
 *
 ******************************************************************************/
extern bool BTM_GetRemoteQLLFeatures(uint16_t handle, uint8_t* features);

/*******************************************************************************
 *
 * Function         BTM_QHS_Phy_supported
 *
 * Description      This function is called to determine if QHS phy can be used
 *
 * Parameter        connection handle
 *
 * Returns          bool true if qhs phy can be used
 *
 ******************************************************************************/
extern bool BTM_QHS_Phy_supported(uint16_t handle);

/*******************************************************************************
 *
 * Function         BTM_BleIsQHSPhySupported
 *
 * Description      This function is called to determine if QHS phy can be used
 *
 * Parameter        bda: BD address of the remote device
 *
 * Returns          bool true if qhs phy can be used, false otherwise
 *
 ******************************************************************************/
extern bool BTM_BleIsQHSPhySupported(const RawAddress& bda);

/*******************************************************************************
 *
 * Function         BTM_BleSecurityProcedureIsRunning
 *
 * Description      This function indicates if LE security procedure is
 *                  currently running with the peer.
 *
 * Returns          bool true if security procedure is running, false otherwise.
 *
 ******************************************************************************/
extern bool BTM_BleSecurityProcedureIsRunning(const RawAddress& bd_addr);

/*******************************************************************************
 *
 * Function         BTM_BleGetSupportedKeySize
 *
 * Description      This function gets the maximum encryption key size in bytes
 *                  the local device can suport.
 *                  record.
 *
 * Returns          the key size or 0 if the size can't be retrieved.
 *
 ******************************************************************************/
extern uint8_t BTM_BleGetSupportedKeySize(const RawAddress& bd_addr);

/*******************************************************************************
 *
 * Function         BTM_BleAdvFilterParamSetup
 *
 * Description      This function is called to setup the adv data payload filter
 *                  condition.
 *
 ******************************************************************************/
extern void BTM_BleAdvFilterParamSetup(
    int action, tBTM_BLE_PF_FILT_INDEX filt_index,
    std::unique_ptr<btgatt_filt_param_setup_t> p_filt_params,
    tBTM_BLE_PF_PARAM_CB cb);

/**
 * This functions are called to configure the adv data payload filter condition
 */
extern void BTM_LE_PF_set(tBTM_BLE_PF_FILT_INDEX filt_index,
                          std::vector<ApcfCommand> commands,
                          tBTM_BLE_PF_CFG_CBACK cb);
extern void BTM_LE_PF_clear(tBTM_BLE_PF_FILT_INDEX filt_index,
                            tBTM_BLE_PF_CFG_CBACK cb);

/*******************************************************************************
 *
 * Function         BTM_BleEnableDisableFilterFeature
 *
 * Description      Enable or disable the APCF feature
 *
 * Parameters       enable - true - enables APCF, false - disables APCF
 *
 ******************************************************************************/
extern void BTM_BleEnableDisableFilterFeature(
    uint8_t enable, tBTM_BLE_PF_STATUS_CBACK p_stat_cback);

/*******************************************************************************
 *
 * Function         BTM_BleGetEnergyInfo
 *
 * Description      This function obtains the energy info
 *
 * Parameters       p_ener_cback - Callback pointer
 *
 * Returns          status
 *
 ******************************************************************************/
extern tBTM_STATUS BTM_BleGetEnergyInfo(
    tBTM_BLE_ENERGY_INFO_CBACK* p_ener_cback);

/*******************************************************************************
 *
 * Function         BTM_SetBleDataLength
 *
 * Description      Set the maximum BLE transmission packet size
 *
 * Returns          BTM_SUCCESS if success; otherwise failed.
 *
 ******************************************************************************/
extern tBTM_STATUS BTM_SetBleDataLength(const RawAddress& bd_addr,
                                        uint16_t tx_pdu_length);

/*******************************************************************************
 *
 * Function         BTM_BleReadPhy
 *
 * Description      To read the current PHYs for specified LE connection
 *
 *
 * Returns          BTM_SUCCESS if success; otherwise failed.
 *
 ******************************************************************************/
extern void BTM_BleReadPhy(
    const RawAddress& bd_addr,
    base::Callback<void(uint8_t tx_phy, uint8_t rx_phy, uint8_t status)> cb);

/*******************************************************************************
 *
 * Function         BTM_BleSetDefaultPhy
 *
 * Description      To set preferred PHY for ensuing LE connections
 *
 *
 * Returns          BTM_SUCCESS if success; otherwise failed.
 *
 ******************************************************************************/
extern tBTM_STATUS BTM_BleSetDefaultPhy(uint8_t all_phys, uint8_t tx_phys,
                                        uint8_t rx_phys);

/*******************************************************************************
 *
 * Function         BTM_BleSetPhy
 *
 * Description      To set PHY preferences for specified LE connection
 *
 *
 * Returns          BTM_SUCCESS if success; otherwise failed.
 *
 ******************************************************************************/
extern void BTM_BleSetPhy(const RawAddress& bd_addr, uint8_t tx_phys,
                          uint8_t rx_phys, uint16_t phy_options);

extern void btm_ble_multi_adv_cleanup(void);

/*******************************************************************************
 *
 * Function         BTM_GetRemoteDeviceName
 *
 * Description      This function is called to get the dev name of remote device
 *                  from NV
 *
 * Returns          TRUE if success; otherwise failed.
 *
 ******************************************************************************/
extern bool BTM_GetRemoteDeviceName(const RawAddress& bd_addr, BD_NAME bdname);

/*******************************************************************************
 *
 * Function         BTM_BleSetCigParam
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_Set_CIG_Parameters for setting up cig parameters in
 *                  controller.
 *
 * Parameters       tBTM_BLE_ISO_SET_CIG_CMD_PARAM includes all parameters of the
 *                  HCI command.
 *                  Note: free memory allocated to this structure after returning.
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 ******************************************************************************/
extern uint8_t BTM_BleSetCigParam(tBTM_BLE_ISO_SET_CIG_CMD_PARAM* p_data);

/*******************************************************************************
 *
 * Function         BTM_BleCreateCis
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_Create_CIS Command for establishing CIS connection.
 *
 * Parameters       tBTM_BLE_ISO_CREATE_CIS_CMD_PARAM includes all parameters of
 *                  the HCI command.
 *                  Note: free memory allocated to this structure after returning.
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 ******************************************************************************/
extern uint8_t BTM_BleCreateCis(tBTM_BLE_ISO_CREATE_CIS_CMD_PARAM* p_data,
                                tBTM_BLE_CIS_DISCONNECTED_CB* p_cb);

/*******************************************************************************
 *
 * Function         BTM_BleRemoveCig
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_Remove_CIG Command for removing all CIS associated
 *                  with CIG.
 *
 * Parameters       cig_id: CIG ID
 *                  tBTM_BLE_REMOVE_CIG_CMPL_CB: callback to be given on completion.
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 ******************************************************************************/
extern uint8_t BTM_BleRemoveCig(uint8_t cig_id, tBTM_BLE_REMOVE_CIG_CMPL_CB *p_cb);

/*******************************************************************************
 *
 * Function         BTM_BleSetIsoDataPath
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_Setup_ISO_Data_Path Command to setup cis/bis data path.
 *
 * Parameters       tBTM_BLE_SET_ISO_DATA_PATH_PARAM includes all parameters of
 *                  the HCI command.
 *                  Note: free memory allocated to this structure after returning.
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 ******************************************************************************/
extern uint8_t BTM_BleSetIsoDataPath(tBTM_BLE_SET_ISO_DATA_PATH_PARAM* p_data);

/**************************************************************************************
 *
 * Function         BTM_BleRemoveIsoDataPath
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_Remove_ISO_Data_Path Command to setup cis data path.
 *
 * Parameters       conn_handle: connection handle of CIS.
 *                  direction: direction for data path.
 *                  tBTM_BLE_REMOVE_ISO_DATA_PATH_CMPL_CB: callback on command complete
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 **************************************************************************************/
extern uint8_t BTM_BleRemoveIsoDataPath(uint16_t conn_handle, uint8_t direction,
                                        tBTM_BLE_REMOVE_ISO_DATA_PATH_CMPL_CB* p_cb);

/**************************************************************************************
 *
 * Function         BTM_BleRequestPeerSca
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_Request_Peer_SCA Command to fetch peer sca.
 *
 * Parameters       conn_handle: connection handle of the ACL.
 *                  tBTM_BLE_REQUEST_PEER_SCA_COMPLETE_CB: callback on HCI EVENT
 *                  HCI_LE_Request_Peer_SCA_Complete.
 *
 * Returns          void
 *
 **************************************************************************************/
extern void BTM_BleRequestPeerSca(uint16_t conn_handle,
                                  tBTM_BLE_REQUEST_PEER_SCA_COMPLETE_CB* p_cback);

/**************************************************************************************
 *
 * Function         BTM_BleReadIsoLinkQuality
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_Read_ISO_Link_Quality Command.
 *
 * Parameters       conn_handle: connection handle of CIS.
 *                  tBTM_BLE_READ_ISO_LINK_QLT_CB: callback on command complete
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 **************************************************************************************/
extern uint8_t BTM_BleReadIsoLinkQuality(uint16_t conn_handle,
                                         tBTM_BLE_READ_ISO_LINK_QLT_CB* p_cb);

/**************************************************************************************
 *
 * Function         BTM_BleReadIsoTxSync
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_Read_ISO_TX_Sync Command.
 *
 * Parameters       conn_handle: connection handle of CIS.
 *                  tBTM_BLE_READ_ISO_TX_SYNC_CB: callback on command complete
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 **************************************************************************************/
extern uint8_t BTM_BleReadIsoTxSync (uint16_t conn_handle,
                                     tBTM_BLE_READ_ISO_TX_SYNC_CB* p_cb);

/**************************************************************************************
 *
 * Function         BTM_BleAcceptCisRequest
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_Accept_CIS_Request Command.
 *
 * Parameters       conn_handle: connection handle of CIS.
 *                  tBTM_BLE_CIS_ESTABLISHED_CB: callback on CIS Established Event
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 **************************************************************************************/
extern uint8_t BTM_BleAcceptCisRequest (uint16_t conn_handle,
                                        tBTM_BLE_CIS_ESTABLISHED_CB* p_cb);

/**************************************************************************************
 *
 * Function         BTM_BleRejectCisRequest
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_Reject_CIS_Request Command to reject cis request.
 *
 * Parameters       conn_handle: connection handle of CIS.
 *                  reason: reason to reject cis connection
 *                  tBTM_BLE_REJECT_CIS_CB: callback on command complete
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 **************************************************************************************/
extern uint8_t BTM_BleRejectCisRequest (uint16_t conn_handle, uint8_t reason,
                                        tBTM_BLE_REJECT_CIS_CB* p_cb);

/**************************************************************************************
 *
 * Function         BTM_BleRejectCisRequest
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_Disconnect Command for cis disconnection.
 *
 * Parameters       conn_handle: connection handle of CIS.
 *                  reason: reason to reject cis connection
 *                  tBTM_BLE_REJECT_CIS_CB: callback on command complete
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 **************************************************************************************/
extern uint8_t BTM_BleIsoCisDisconnect(uint16_t conn_handle, uint8_t reason,
                                       tBTM_BLE_CIS_DISCONNECTED_CB* p_cb);

/**************************************************************************************
 *
 * Function         BTM_BleEnhancedReadTransmitPowerLevel
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_Enhanced_Read_Transmit_Power_Level
 *
 * Parameters       conn_handle: connection handle of ACL.
 *                  phy: LE ACL phy
 *                  tBTM_BLE_ENHANCED_READ_TRANSMIT_POWER_LEVEL_CB: callback on
 *                  command complete
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 **************************************************************************************/
extern void BTM_BleEnhancedReadTransmitPowerLevel (uint16_t conn_handle, uint8_t phy,
                                        tBTM_BLE_ENHANCED_READ_TRANSMIT_POWER_LEVEL_CB* p_cb);

/**************************************************************************************
 *
 * Function         BTM_BleReadRemoteTransmitPowerLevel
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_Read_Remote_Transmit_Power_Level.
 *
 * Parameters       conn_handle: connection handle of ACL.
 *                  phy: LE ACL phy
 *                  tBTM_BLE_READ_REMOTE_TX_POW_LEVEL_CB: callback on
 *                  command complete
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 **************************************************************************************/
extern uint8_t BTM_BleReadRemoteTransmitPowerLevel(uint16_t conn_handle, uint8_t phy,
                                        tBTM_BLE_READ_REMOTE_TX_POW_LEVEL_CB* p_cb);

/**************************************************************************************
 *
 * Function         BTM_BleSetPathLossReportingParams
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_Set_Path_Loss_Reporting_Parameters Command..
 *
 * Parameters       tBTM_BLE_SET_PATH_LOSS_REPORTING_PARAM includes all parameters of
 *                  the HCI command.
 *                  Note: free memory allocated to this structure after returning.
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 **************************************************************************************/
extern uint8_t BTM_BleSetPathLossReportingParams(
                                    tBTM_BLE_SET_PATH_LOSS_REPORTING_PARAM* param);

/**************************************************************************************
 *
 * Function         BTM_BleSetPathLossReportingEnable
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_Set_Path_Loss_Reporting_Enable.
 *
 * Parameters       conn_handle: connection handle of ACL.
 *                  enable: to enable reporting
 *                  tBTM_BLE_SET_PATH_LOSS_REPORTING_ENABLE_CB: callback on
 *                  command complete.
 *                  tBTM_BLE_PATH_LOSS_THRESHOLD_CB: callback on HCI Event.
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 **************************************************************************************/
extern uint8_t BTM_BleSetPathLossReportingEnable (uint16_t conn_handle,
                                                  uint8_t enable,
                                                  tBTM_BLE_SET_PATH_LOSS_REPORTING_ENABLE_CB* p_cb,
                                                  tBTM_BLE_PATH_LOSS_THRESHOLD_CB* p_event_cb);

/**************************************************************************************
 *
 * Function         BTM_BleSetTransmitPowerReportingEnable
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_Set_Transmit_Power_Reporting_Enable.
 *
 * Parameters       conn_handle: connection handle of ACL.
 *                  local_enable/remote_enable: to enable respective reporting
 *                  tBTM_BLE_SET_TRANSMIT_POWER_REPORTING_ENABLE_CB: callback on
 *                  command complete.
 *                  tBTM_BLE_TRANSMIT_POWER_REPORTING_EVENT_CB: callback on HCI Event.
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 **************************************************************************************/
extern uint8_t BTM_BleSetTransmitPowerReportingEnable(
                            uint16_t conn_handle,
                            uint8_t local_enable,
                            uint8_t remote_enable,
                            tBTM_BLE_SET_TRANSMIT_POWER_REPORTING_ENABLE_CB* p_cmd_cmpl,
                            tBTM_BLE_TRANSMIT_POWER_REPORTING_EVENT_CB* p_cb);

/**************************************************************************************
 *
 * Function         BTM_BleIsoTestEnd
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_ISO_Test_End .
 *
 * Parameters       conn_handle: connection handle of cis.
 *                  tBTM_BLE_ISO_TEST_END_CB: callback on
 *                  command complete.
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 **************************************************************************************/
extern uint8_t BTM_BleIsoTestEnd(uint16_t conn_handle, tBTM_BLE_ISO_TEST_END_CB* p_cb);

/**************************************************************************************
 *
 * Function         BTM_BleSetCigParametersTest
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_Set_CIG_Parameters_Test Command.
 *
 * Parameters       tBTM_BLE_SET_CIG_PARAM_TEST includes all parameters of
 *                  the HCI command.
 *                  Note: free memory allocated to this structure after returning.
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 **************************************************************************************/
extern uint8_t BTM_BleSetCigParametersTest(tBTM_BLE_SET_CIG_PARAM_TEST* param);

/**************************************************************************************
 *
 * Function         BTM_BleIsoReadTestCounters
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_ISO_Read_Test_Counters.
 *
 * Parameters       conn_handle: connection handle of ACL.
 *                  tBTM_BLE_ISO_READ_TEST_COUNTERS_CB: callback on
 *                  command complete.
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 **************************************************************************************/
extern uint8_t BTM_BleIsoReadTestCounters(uint16_t conn_handle,
                                          tBTM_BLE_ISO_READ_TEST_COUNTERS_CB* p_cb);

/**************************************************************************************
 *
 * Function         BTM_BleIsoReceiveTest
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_ISO_Receive_Test.
 *
 * Parameters       conn_handle: connection handle of cis.
 *                  tBTM_BLE_ISO_RECEIVE_TEST_CB: callback on command complete.
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 **************************************************************************************/
extern uint8_t BTM_BleIsoReceiveTest(uint16_t conn_handle, uint8_t payload_type,
                                     tBTM_BLE_ISO_RECEIVE_TEST_CB* p_cb);

/**************************************************************************************
 *
 * Function         BTM_BleIsoTransmitTest
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_ISO_Transmit_Test .
 *
 * Parameters       conn_handle: connection handle of cis.
 *                  tBTM_BLE_ISO_TRANSMIT_TEST_CB: callback on
 *                  command complete.
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 **************************************************************************************/
extern uint8_t BTM_BleIsoTransmitTest(uint16_t conn_handle, uint8_t payload_type,
                                      tBTM_BLE_ISO_TRANSMIT_TEST_CB* p_cb);

/**************************************************************************************
 *
 * Function         BTM_BleTransmitterTestV4
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_Transmitter_Test [v4] Command.
 *
 * Parameters       tBTM_BLE_TRANSMITTER_TEST_PARAM includes all parameters of
 *                  the HCI command.
 *                  Note: free memory allocated to this structure after returning.
 *
 * Returns          0x00 : HCI_SUCCESS if command/feature is supported in host
 *                        and controller.
 *                  0x11 : Unsupported Feature (HCI Error)
 *
 **************************************************************************************/
extern uint8_t BTM_BleTransmitterTestV4 (tBTM_BLE_TRANSMITTER_TEST_PARAM* param);

/*******************************************************************************
 *
 * Function         BTM_BleGetLTK
 *
 * Description      This function returns LTK of the LE connection.
 *
 * Parameter        bdaddr: remote device address.
 *
 * Returns         Octet16 (LTK)
 *
 ******************************************************************************/
extern Octet16 BTM_BleGetLTK(const RawAddress& bd_addr);

/* Below API's are used to parse parameters of HCI Events and then pass it to upper layer */
extern void btm_ble_set_cis_req_evt_cb(tBTM_BLE_CIS_REQ_EVT_CB* p_cb);
extern void btm_ble_cis_established_evt(uint8_t *param, uint16_t param_len);
extern void btm_ble_cis_request_evt(uint8_t *param, uint16_t param_len);
extern void btm_ble_peer_sca_cmpl_evt(uint8_t *param, uint16_t param_len);
extern void btm_ble_path_loss_threshold_evt(uint8_t *param, uint16_t param_len);
extern void btm_ble_transmit_power_reporting_event(uint8_t *param, uint16_t param_len);
extern void btm_ble_cis_disconnected(uint8_t status, uint16_t cis_handle, uint8_t reason);
extern bool btm_ble_is_cis_handle(uint16_t cis_handle);
using StartSyncCb =
               base::Callback<void(uint8_t /*status*/, uint16_t /*sync_handle*/,
                                   uint8_t /*advertising_sid*/, uint8_t /*address_type*/,
                                   RawAddress /*address*/, uint8_t /*phy*/, uint16_t /*interval*/)>;
using SyncReportCb =
                base::Callback<void(uint16_t /*sync_handle*/, int8_t /*tx_power*/, int8_t /*rssi*/,
                                    uint8_t /*status*/, std::vector<uint8_t> /*data*/)>;
using SyncLostCb = base::Callback<void(uint16_t /*sync_handle*/)>;

extern void btm_ble_periodic_adv_sync_established(uint8_t *param, uint16_t param_len);
extern void btm_ble_periodic_adv_report(uint8_t *param, uint16_t param_len);
extern void btm_ble_periodic_adv_sync_lost(uint8_t *param, uint16_t param_len);

extern void btm_ble_biginfo_adv_report_rcvd(uint8_t *param, uint16_t param_len);
extern void btm_ble_periodic_adv_sync_tx_rcvd(uint8_t *param, uint16_t param_len);
/*******************************************************************************
 *
 * Function         BTM_BleStartPeriodicSync
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_PERIODIC_ADVERTISING_CREATE_SYNC to synchronize to
 *                  PA train specified in input parameters.
 *
 * Parameters       PA train info corresponding to particualr PA train and
 *                  callbacks to sync established, pa report and sync lost events
 *
 * Returns          void
 *
 ******************************************************************************/
extern void BTM_BleStartPeriodicSync(uint8_t adv_sid, RawAddress address,
                                     uint16_t skip, uint16_t timeout,
                                     StartSyncCb syncCb,
                                     SyncReportCb reportCb,
                                     SyncLostCb lostCb);
/*******************************************************************************
 *
 * Function         BTM_BleStopPeriodicSync
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_PERIODIC_ADVERTISING_TERMINATE_SYNC to stop synchronising
 *                  to PA train.
 *
 * Parameters       sync handle
 *
 * Returns          void
 *
 ******************************************************************************/
extern void BTM_BleStopPeriodicSync(uint16_t handle);
/*******************************************************************************
 *
 * Function         BTM_BleCancelPeriodicSync
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_PERIODIC_ADVERTISING_CREATE_SYNC_CANCEL to
 *                  cancel pending sync to PA train.
 *
 * Parameters       adv sid, address corrosponds to PA train
 *
 * Returns          void
 *
 ******************************************************************************/
extern void BTM_BleCancelPeriodicSync(uint8_t adv_sid, RawAddress address);

using SyncTransferCb = base::Callback<void(uint8_t /*status*/, RawAddress)>;

/*******************************************************************************
 *
 * Function         BTM_BlePeriodicSyncTransfer
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_SET_PERIODIC_ADVERTISING_SYNC_TRANSFER to transfer
 *                  sync info of remote advertiser to connected remote device
 *
 * Parameters       PAST specific parameters
 *
 * Returns          void
 *
 ******************************************************************************/
void BTM_BlePeriodicSyncTransfer(RawAddress addr, uint16_t service_data,
                         uint16_t sync_handle, SyncTransferCb cb);
/*******************************************************************************
 *
 * Function         BTM_BlePeriodicSyncSetInfo
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_SET_PERIODIC_ADVERTISING_SET_INFO_TRANSFER to transfer
 *                  colocated advertiser sync info to connected remote device
 *
 * Parameters       PAST specific parameters
 *
 * Returns          void
 *
 ******************************************************************************/
void BTM_BlePeriodicSyncSetInfo(RawAddress addr, uint16_t service_data,
                         uint8_t adv_handle, SyncTransferCb cb);
/*******************************************************************************
 *
 * Function         BTM_BlePeriodicSyncTxParameters
 *
 * Description      This function is called to invoke HCI Command
 *                  HCI_LE_SET_PERIODIC_ADVERTISING_SYNC_TRANSFER_PARAMETERS,
 *                  this command is used to specify how BT SoC will process PA
 *                  sync information received from the remote device identified
 *                  by the addr.
 *
 * Parameters       HCI command  specific parameters
 *
 * Returns          void
 *
 ******************************************************************************/
void BTM_BlePeriodicSyncTxParameters(RawAddress addr, uint8_t mode,
                                     uint16_t skip, uint16_t timeout, StartSyncCb syncCb);

#endif
