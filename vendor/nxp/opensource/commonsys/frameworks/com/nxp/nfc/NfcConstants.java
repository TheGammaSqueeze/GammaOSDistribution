/*
*
*  The original Work has been changed by NXP Semiconductors.
*
*  Copyright (C) 2013-2020 NXP Semiconductors
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

import android.annotation.SdkConstant;
import android.annotation.SdkConstant.SdkConstantType;

/**
 * This class provides the constants ID types.
 */

public final class NfcConstants {
  /**
   * UICC ID to be able to select it as the default Secure Element
   */
  public static final String UICC_ID = "com.nxp.uicc.ID";

  /**
   *@hide
   */
  public static final int UICC_ID_TYPE = 2;

  /**
   * UICC2 ID to be able to select it as the default Secure Element
   */
  public static final String UICC2_ID = "com.nxp.uicc2.ID";

  /**
   *@hide
   */
  public static final int UICC2_ID_TYPE = 4;

  /**
   * eSE ID to be able to select it as the default Secure Element
   */
  public static final String SMART_MX_ID = "com.nxp.smart_mx.ID";

  /**
   *@hide
   */
  public static final int SMART_MX_ID_TYPE = 1;
  /**
   * UICC ID to be able to select it as the default Secure Element
   */

  /**
   * ID to be able to select all Secure Elements
   * @hide
   */
  public static final String ALL_SE_ID = "com.nxp.all_se.ID";

  /**
   *
   */
  public static final String HOST_ID = "com.nxp.host.ID";

  /**
   *@hide
   */
  public static final int HOST_ID_TYPE = 0;

  /**
   * fw version major number
   * @hide
   */
  static final byte PN553_FW_MAJOR_NUM = 1;

  /**
   * fw ROM code version
   * @hide
   */
  static final byte PN553_FW_ROM_VER = 0x11;

  /**
   * mpos mode status
   */
  public static final int MPOS_STATUS_SUCCESS = 0x00;

  public static final int MPOS_STATUS_BUSY = 0xEB;

  public static final int MPOS_STATUS_REJECTED = 0x01;

  /**
   * SCR mode status
   */
  public static final int SCR_STATUS_SUCCESS = 0x00;

  public static final int SCR_STATUS_BUSY = 0xEB;

  public static final int SCR_STATUS_REJECTED = 0x01;

  public static final int SCR_STATUS_FAILED = 0x03;

  /**
   * parameter for configuring RF poll
   */
  public static final int LOW_POWER = 0x00;

  public static final int ULTRA_LOW_POWER = 0x01;

  /**
   * Broadcast Action: Multiple card presented to emvco reader.
   */
  @SdkConstant(SdkConstantType.BROADCAST_INTENT_ACTION)
  public static final String ACTION_EMVCO_MULTIPLE_CARD_DETECTED =
      "com.nxp.action.EMVCO_MULTIPLE_CARD_DETECTED";

  /**
   * Broadcast Action: a transaction with a secure element has been detected.
   *
   * Always contains the extra field
   * {@link com.nxp.nfc.NfcConstants#EXTRA_AID} and {@link
   * com.nxp.nfc.NfcConstants#EXTRA_SOURCE}
   *
   */
  @SdkConstant(SdkConstantType.BROADCAST_INTENT_ACTION)
  public static final String ACTION_TRANSACTION_DETECTED =
      "com.nxp.action.TRANSACTION_DETECTED";

  /**
   * Mandatory byte array extra field in
   * {@link com.nxp.nfc.NfcConstants#ACTION_TRANSACTION_DETECTED}.
   * <p>
   * Contains the AID of the applet involved in the transaction.
   *
   */
  public static final String EXTRA_AID = "com.nxp.extra.AID";

  /**
   * Mandatory byte array extra field in
   * {@link com.nxp.nfc.NfcConstants#ACTION_TRANSACTION_DETECTED}.
   * <p>
   * Contains the extra data of the applet involved in the transaction.
   *
   */
  public static final String EXTRA_DATA = "com.nxp.extra.DATA";

  /**
   * Broadcast Action: a connectivity event coming from the UICC/ESE
   * has been detected.
   * <p>
   * Always contains the extra field
   * {@link com.nxp.nfc.NfcConstants#EXTRA_SOURCE}
   */
  @SdkConstant(SdkConstantType.BROADCAST_INTENT_ACTION)
  public static final String ACTION_CONNECTIVITY_EVENT_DETECTED =
      "com.nxp.action.CONNECTIVITY_EVENT_DETECTED";

  /**
   * Mandatory string extra field in
   * {@link com.nxp.nfc.NfcConstants#ACTION_TRANSACTION_DETECTED} and
   * {@link com.nxp.nfc.NfcConstants#ACTION_CONNECTIVITY_EVENT_DETECTED}.
   * <p>
   * Contains the event source (UICC/ESE) of the transaction.
   *
   */
  public static final String EXTRA_SOURCE = "com.nxp.extra.SOURCE";

  /**
   * Intent received when start reader request from app is successfully
   * processed.
   *
   */
  @SdkConstant(SdkConstantType.ACTIVITY_INTENT_ACTION)
  public static final String ACTION_NFC_MPOS_READER_MODE_START_SUCCESS =
      "com.nxp.nfc_extras.action.NFC_MPOS_READER_MODE_START_SUCCESS";

  @SdkConstant(SdkConstantType.ACTIVITY_INTENT_ACTION)
  public static final String ACTION_NFC_SECURE_READER_MODE_START_SUCCESS =
      "com.nxp.nfc_extras.action.NFC_SECURE_READER_MODE_START_SUCCESS";

  /**
   * Intent received when start reader request from app is failed to process.
   *
   */
  @SdkConstant(SdkConstantType.ACTIVITY_INTENT_ACTION)
  public static final String ACTION_NFC_MPOS_READER_MODE_START_FAIL =
      "com.nxp.nfc_extras.action.NFC_MPOS_READER_MODE_START_FAIL";

  @SdkConstant(SdkConstantType.ACTIVITY_INTENT_ACTION)
  public static final String ACTION_NFC_SECURE_READER_MODE_START_FAIL =
      "com.nxp.nfc_extras.action.NFC_SECURE_READER_MODE_START_FAIL";

  /**
   * Intent received when the Secure Reader needs to restart.
   *
   */
  @SdkConstant(SdkConstantType.ACTIVITY_INTENT_ACTION)
  public static final String ACTION_NFC_MPOS_READER_MODE_RESTART =
      "com.nxp.nfc_extras.action.NFC_MPOS_READER_MODE_RESTART";

  @SdkConstant(SdkConstantType.ACTIVITY_INTENT_ACTION)
  public static final String ACTION_NFC_SECURE_READER_MODE_RESTART =
      "com.nxp.nfc_extras.action.NFC_SECURE_READER_MODE_RESTART";

  /**
   * Intent received when reader is activated.
   *
   */
  @SdkConstant(SdkConstantType.ACTIVITY_INTENT_ACTION)
  public static final String ACTION_NFC_MPOS_READER_MODE_ACTIVATED =
      "com.nxp.nfc_extras.action.NFC_MPOS_READER_MODE_ACTIVATED";

  @SdkConstant(SdkConstantType.ACTIVITY_INTENT_ACTION)
  public static final String ACTION_NFC_SECURE_READER_MODE_TARGET_ACTIVATED =
      "com.nxp.nfc_extras.action.NFC_SECURE_READER_MODE_TARGET_ACTIVATED";

  /**
   * Intent received when the Secure Reader is disconnected from card.
   *
   */
  @SdkConstant(SdkConstantType.ACTIVITY_INTENT_ACTION)
  public static final String ACTION_NFC_MPOS_READER_MODE_STOP_SUCCESS =
      "com.nxp.nfc_extras.action.NFC_MPOS_READER_MODE_STOP_SUCCESS";

  @SdkConstant(SdkConstantType.ACTIVITY_INTENT_ACTION)
  public static final String ACTION_NFC_SECURE_READER_MODE_STOP_SUCCESS =
      "com.nxp.nfc_extras.action.NFC_SECURE_READER_MODE_STOP_SUCCESS";

  /**
   * Intent received when the Secure Reader is disconnected from card.
   *
   */
  @SdkConstant(SdkConstantType.ACTIVITY_INTENT_ACTION)
  public static final String ACTION_NFC_MPOS_READER_MODE_STOP_FAIL =
      "com.nxp.nfc_extras.action.NFC_MPOS_READER_MODE_STOP_FAIL";

  @SdkConstant(SdkConstantType.ACTIVITY_INTENT_ACTION)
  public static final String ACTION_NFC_SECURE_READER_MODE_STOP_FAIL =
      "com.nxp.nfc_extras.action.NFC_SECURE_READER_MODE_STOP_FAIL";

  /**
   * Intent received when the Secure Reader transcation is done.
   *
   */
  @SdkConstant(SdkConstantType.ACTIVITY_INTENT_ACTION)
  public static final String ACTION_NFC_MPOS_READER_MODE_REMOVE_CARD =
      "com.nxp.nfc_extras.action.NFC_MPOS_READER_MODE_REMOVE_CARD";

  /**
   * Intent received when the Secure Reader gets timeout.
   *
   */
  @SdkConstant(SdkConstantType.ACTIVITY_INTENT_ACTION)
  public static final String ACTION_NFC_MPOS_READER_MODE_TIMEOUT =
      "com.nxp.nfc_extras.action.NFC_MPOS_READER_MODE_TIMEOUT";

  @SdkConstant(SdkConstantType.ACTIVITY_INTENT_ACTION)
  public static final String ACTION_NFC_SECURE_READER_MODE_TIMEOUT =
      "com.nxp.nfc_extras.action.NFC_SECURE_READER_MODE_TIMEOUT";

  /**
   * Intent received when multiple cards detected during Secure reader operation.
   *
   */
  @SdkConstant(SdkConstantType.ACTIVITY_INTENT_ACTION)
  public static final String ACTION_NFC_MPOS_READER_MODE_MULTIPLE_TARGET_DETECTED =
      "com.nxp.nfc_extras.action.NFC_MPOS_READER_MODE_MULTIPLE_TARGET_DETECTED";

  public static final String ACTION_ROUTING_TABLE_FULL =
      "nfc.intent.action.AID_ROUTING_TABLE_FULL";

  public static final String PERMISSIONS_NFC = "android.permission.NFC";

  public static final String ACTION_CHECK_X509 =
      "org.simalliance.openmobileapi.service.ACTION_CHECK_X509";
  public static final String SET_PACKAGE_NAME =
      "org.simalliance.openmobileapi.service";
  public static final String EXTRA_SE_NAME =
      "org.simalliance.openmobileapi.service.EXTRA_SE_NAME";
  public static final String EXTRA_PKG =
      "org.simalliance.openmobileapi.service.extra.EXTRA_PKG";
  public static final String EXTRA_RESULT =
      "org.simalliance.openmobileapi.service.extra.EXTRA_RESULT";

  public static final String ACTION_CHECK_X509_RESULT =
      "org.simalliance.openmobileapi.service.ACTION_CHECK_X509_RESULT";

  /**
   * Indicates the states of an APDU service.
   * Service is enabled only when the commit to routing table is successful
   */
  public static final int SERVICE_STATE_DISABLED = 0;
  public static final int SERVICE_STATE_ENABLED = 1;
  public static final int SERVICE_STATE_ENABLING = 2;
  public static final int SERVICE_STATE_DISABLING = 3;
}
