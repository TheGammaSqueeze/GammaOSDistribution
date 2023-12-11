/*
 * Copyright 2019-2021 NXP
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

package com.nxp.sems;

import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.Vector;

import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.util.Log;
import com.nxp.sems.SemsTLV;
import com.nxp.sems.SemsUtil;
import com.nxp.sems.channel.ISemsApduChannel;
import com.nxp.sems.ISemsCallback;
import com.nxp.sems.SemsStatus;
import com.nxp.sems.SemsGetLastExecStatus;
import android.content.Context;

public class SemsExecutor {

  private static final byte[] clientVersion = {(byte)0x01, (byte)0x00};
  public static final String TAG = "SEMS-SemsExecutor";

  public static final byte SEMS_STATE_SELECT = 0;
  public static final byte SEMS_STATE_STORE_DATA = 1;
  public static final byte SEMS_STATE_CHECK_CERTIFICATE = 2;
  public static final byte SEMS_STATE_VERIFY_SIGNATURE = 3;
  public static final byte SEMS_STATE_SECURE_COMMAND_PROCESSING = 4;
  public static final byte SEMS_STATE_PROCESSING_COMPLETED = 5;

  public static final byte SEMS_CERTIFICATE_SIGNATURE_5F37_LEN = 64;
  public static final byte SEMS_CERTIFICATE_SIGNATURE_7F49_86_LEN = 67;

  private static ISemsApduChannel sChannel;
  private final byte basicChannel = 0x00;
  private String callerPackageName;
  private static String sRespOutlog;
  private byte[] AID_MEM;
  private String encryptedScriptDirectory = "";
  private String outDirectory = "";
  private String inputScript;
  private String outputScript;
  private ISemsCallback mSemsCallback;
  private static Context mContext;

  private int certIndex = -1;
  private byte[] rapduSelect;
  private byte[] response;
  private SemsTLV tlvRE42;
  private SemsTLV tlvRE45;
  private int linePointer;
  private boolean lsCommandSeen = false;
  private byte mState;
  private static SemsExecutor sSemsExecutor;
  /**
   * AID of the SEMS Application Instance.
   */
  private static final byte[] SEMS_APP_AID =
      SemsUtil.parseHexString("A00000015153454D5300000001");
  private static final byte[] SEMS_UPD_APP_AID =
      SemsUtil.parseHexString("A00000015153454D53FFFFFF01");

  private static final byte[] sw9000 = {(byte)0x90, (byte)0x00};
  private static final byte[] sw6F00 = {(byte)0x6F, (byte)0x00};
  private static final byte[] sw6985 = {(byte)0x69, (byte)0x85};
  private static final byte[] sw6987 = {(byte)0x69, (byte)0x87};
  private static final byte[] sw6A82 = {(byte)0x6A, (byte)0x82};

  private static final byte SemsResponse = 0x01;
  private static final byte SEResponse = 0x02;
  private static final byte ErrorResponse = 0x03;
  private static final byte SWResponse = 0x04;
  private static final byte SemsCertResponse = 0x05;
  private static final byte SemsAuthResponse = 0x06;

  /**
   * Returns SemsExecutor singleton object
   * <br/>
   * The Input caller application context,
   * The Input APDU channel information
   * @param void
   *
   * @return {@code SemsExecutor}.
   */
  public static SemsExecutor getInstance(ISemsApduChannel semsChannel,
                                         Context context) {
    sChannel = semsChannel;
    mContext = context;
    sRespOutlog = "";
    if (sSemsExecutor == null) {
      sSemsExecutor = new SemsExecutor();
    }
    return sSemsExecutor;
  }
  private SemsExecutor() {
    this.AID_MEM = SEMS_APP_AID;
  }

  /**
   * Logging the response APDU received during SEMS execution
   * <br/>
   * The Input type of response,
   * The Input status bytes
   * Agent to provide the SEMS Application with an identifier
   * @param void
   *
   * @return {@code true} if the SW returned is 9000, {@code false} otherwise.
   */
  private void putIntoLog(byte[] what, byte type) {
    byte[] data;

    /*Skip responses ending with SW '6310'*/
    if ((what[what.length - 2] == 0x63) && (what[what.length - 1] == 0x10)) {
      return;
    }

    switch (type) {
    case ErrorResponse:
      return;
    default:
      return;

    case SemsCertResponse:
      data = new byte[] {0x7F, 0x21};
      break;
    case SemsAuthResponse:
      data = new byte[] {0x60};
      break;
    case SemsResponse:
      data = new byte[] {0x40};
      break;
    }

    data = SemsTLV.make(0x61, SemsUtil.append(SemsTLV.make(0x43, data),
                                              SemsTLV.make(0x44, what)));
    sRespOutlog = sRespOutlog + SemsUtil.toHexString(data) + "\r\n";
  }

  /**
   * Set the current application directory & caller information
   * <br/>
   * The Input Logical channel,
   * The Input the AID to be selected
   * Agent to provide the SEMS Application with an identifier
   * @param void
   *
   * @return {@code true} if the SW returned is 9000, {@code false} otherwise.
   */
  private SemsStatus setDirectories() {
    SemsStatus status = SemsStatus.SEMS_STATUS_FAILED;
    PackageInfo pInfo;
    PackageManager pm = mContext.getPackageManager();
    String str = mContext.getPackageName();

    try {
      pInfo = pm.getPackageInfo(str, 0);
      str = pInfo.applicationInfo.dataDir;
      this.callerPackageName = pInfo.packageName;
      this.encryptedScriptDirectory = str;
      this.outDirectory = str;
      status = SemsStatus.SEMS_STATUS_SUCCESS;
    } catch (Exception e) {
      e.printStackTrace();
    }
    return status;
  }

  private static Path getPath(String dir, String file) {
    return (dir != null) ? FileSystems.getDefault().getPath(dir, file)
                         : FileSystems.getDefault().getPath(file);
  }
  /**
   * Write the content of String buffer to out file
   * <br/>
   * The Input Logical channel,
   * The Input the AID to be selected
   * Agent to provide the SEMS Application with an identifier
   * @param void
   *
   * @return {@code true} if the SW returned is 9000, {@code false} otherwise.
   */
  private byte[] writeScriptOutFile(String scriptOut) {
    Path p = getPath(outDirectory, scriptOut);
    try {
      Files.write(p, sRespOutlog.getBytes());
    } catch (IOException e) {
      Log.e(TAG, "IOException during writeScriptOutfile: ");
    }
    return sRespOutlog.getBytes();
  }

  /**
   * Write the content of String buffer to backup file
   * <br/>
   * The Input Logical channel,
   * The Input the AID to be selected
   * Agent to provide the SEMS Application with an identifier
   * @param void
   *
   * @return {@code true} if the SW returned is 9000, {@code false} otherwise.
   */
  private byte[] writeScriptInputFile(String filename, String scriptBuffer) {
    Path p = getPath(outDirectory, filename);
    try {
      Files.write(p, scriptBuffer.getBytes());
    } catch (IOException e) {
      Log.e(TAG, "IOException during writeScriptInputfile: ");
    }
    return scriptBuffer.getBytes();
  }

  /**
   * Read the file content to String format
   * <br/>
   * The Input path of the SEMS encrypted script stored,
   * Agent to provide the SEMS Application with an identifier
   * @param void
   *
   * @return {@code true} if the SW returned is 9000, {@code false} otherwise.
   */

  private String readScriptFile(String scriptIn) throws Exception {
    Path p = getPath(encryptedScriptDirectory, scriptIn);
    String script = "";
    Iterator<String> i;
    try {
      List<String> lines = Files.readAllLines(p, Charset.defaultCharset());
      i = lines.iterator();
      while (i.hasNext()) {
        String s = i.next();
        if (!s.startsWith("%%%")) {
          script += s;
        }
      }
    } catch (IOException e) {
      Log.e(TAG, "IOException during reading script: ");
      throw new Exception();
    }
    return script;
  }
  /**
   * Close the session with Application selected
   * <br/>
   * The Input Logical channel,
   * Agent to provide the SEMS Application with an identifier
   * @param void
   *
   * @return {@code true} if the SW returned is 9000, {@code false} otherwise.
   */
  protected void closeLogicalChannel(byte channel) { sChannel.close(); }

  /**
   * Select SEMS Application
   * <br/>
   * The Input the AID to be selected
   * Agent to provide the SEMS Application with an identifier
   * @param void
   *
   * @return {@code true} if the SW returned is 9000, {@code false} otherwise.
   */

  private byte[] selectSEMSApplet() {
    try {
      Log.d(TAG, "Select SEMS applet: ");
      return sChannel.open(AID_MEM);
    } catch (IOException e) {
      e.printStackTrace();
    }
    return null;
  }

  /**
   * Select the Application with mentioned AID
   * <br/>
   * The Input Logical channel,
   * The Input the AID to be selected
   * Agent to provide the SEMS Application with an identifier
   * @param void
   *
   * @return {@code true} if the SW returned is 9000, {@code false} otherwise.
   */
  private byte[] selectApplication(byte channel, byte[] AID) throws Exception{
    Log.d(TAG, "Select applet: ");
    return sChannel.open(AID);
  }

  /**
   * Performs store data operation of caller information.
   * <br/>
   * The Input SHA-1 digest of caller package name,
   * The STORE DATA APDU command is used by the SEMS Device
   * Agent to provide the SEMS Application with an identifier
   * of the caller (SP Device Application), e.g.
   * the digest value of the SP Device Application package name
   * @param void
   *
   * @return {@code true} if the SW returned is 9000, {@code false} otherwise.
   */
  private byte[] sendSHA1OfCallerPackage(byte channel, byte[] callerPackage) throws Exception{
    byte[] SHA1ofCallerPackage = SemsUtil.SHA1(callerPackage);
    final byte[] header = {(byte)0x80, (byte)0xE2, (byte)0x00, 0x00,
                           (byte)0x16, (byte)0x4F, (byte)0x14};
    Log.d(TAG, "Register Caller: ");
    return sChannel.transmit(SemsUtil.append(header, SHA1ofCallerPackage));
  }

  /**
   * Performs store data operation of caller information.
   * <br/>
   * The Input SHA-1 digest of caller package name,
   * The STORE DATA APDU command is used by the SEMS Device
   * Agent to provide the SEMS Application with an identifier
   * of the caller (SP Device Application), e.g.
   * the digest value of the SP Device Application package name
   * @param void
   *
   * @return {@code true} if the SW returned is 9000, {@code false} otherwise.
   */
  private byte[] sendAPCertificate(byte channel, byte[] APCert) {
    try {
      if (APCert.length < 255) {
        // One command
        byte[] header = {(byte)0x80, (byte)0xA0, (byte)0x01, (byte)0x00};
        byte[] len = new byte[1];
        len[0] = (byte)APCert.length;

        byte[] command = SemsUtil.append(SemsUtil.append(header, len), APCert);

        Log.d(TAG, "******* Processing LS Certificate 1/1 command");
        byte[] rapdu = sChannel.transmit(command);
        putIntoLog(rapdu, SemsCertResponse);
        return rapdu;
      } else {
        // Two commands
        byte[] rapdu;
        /* static length because of Brainpool curve*/
        int signAndPubKeyLen = SEMS_CERTIFICATE_SIGNATURE_5F37_LEN +
                SEMS_CERTIFICATE_SIGNATURE_7F49_86_LEN + 6;

        byte[] firstCommandData =
            Arrays.copyOfRange(APCert, 0, APCert.length - signAndPubKeyLen);
        byte[] secondCommandData = Arrays.copyOfRange(
            APCert, APCert.length - signAndPubKeyLen, APCert.length);

        byte[] firstHeader = {(byte)0x80, (byte)0xA0, (byte)0x01, (byte)0x00};
        byte[] secondHeader = {(byte)0x80, (byte)0xA0, (byte)0x00, (byte)0x00};

        byte[] firstLen = new byte[1];
        byte[] secondLen = new byte[1];

        firstLen[0] = (byte)firstCommandData.length;
        secondLen[0] = (byte)secondCommandData.length;

        byte[] firstCommand = SemsUtil.append(
            SemsUtil.append(firstHeader, firstLen), firstCommandData);
        byte[] secondCommand = SemsUtil.append(
            SemsUtil.append(secondHeader, secondLen), secondCommandData);

        Log.d(TAG, "******* Processing LS Certificate 1/2 command");
        rapdu = sChannel.transmit(firstCommand);
        if (SemsUtil.getSW(rapdu) != (short)0x9000) {
          putIntoLog(rapdu, SemsCertResponse);
          return Arrays.copyOfRange(rapdu, rapdu.length - 2, rapdu.length);
        }

        Log.d(TAG, "******* Processing LS Certificate 2/2 command");
        rapdu = sChannel.transmit(secondCommand);
        putIntoLog(rapdu, SemsCertResponse);

        return Arrays.copyOfRange(rapdu, rapdu.length - 2, rapdu.length);
      }
    } catch (IOException ie) {
      ie.printStackTrace();
    }
    return null;
  }

  /**
   * Performs store data operation of caller information.
   * <br/>
   * The Input SHA-1 digest of caller package name,
   * The STORE DATA APDU command is used by the SEMS Device
   * Agent to provide the SEMS Application with an identifier
   * of the caller (SP Device Application), e.g.
   * the digest value of the SP Device Application package name
   * @param void
   *
   * @return {@code true} if the SW returned is 9000, {@code false} otherwise.
   */
  private byte[] sendAuthenticationFrame(byte channel, byte[] authFrame) {
    byte[] authFrameHeader = {(byte)0x80, (byte)0xA0, (byte)0x00, (byte)0x00};
    byte[] authFrameLen = new byte[1];
    authFrameLen[0] = (byte)authFrame.length;
    byte[] authFrameCommand = SemsUtil.append(
        SemsUtil.append(authFrameHeader, authFrameLen), authFrame);
    Log.d(TAG, "******* Processing Authentication Frame command");
    try {
      return sChannel.transmit(authFrameCommand);
    } catch (IOException e) {
      e.printStackTrace();
    }
    return null;
  }

  /**
   * Performs store data operation of caller information.
   * <br/>
   * The Input SHA-1 digest of caller package name,
   * The STORE DATA APDU command is used by the SEMS Device
   * Agent to provide the SEMS Application with an identifier
   * of the caller (SP Device Application), e.g.
   * the digest value of the SP Device Application package name
   * @param void
   *
   * @return {@code true} if the SW returned is 9000, {@code false} otherwise.
   */
  private byte[] sendProcessScript(byte channel, byte[] data) {
    try {
      return sChannel.transmit(data);
    } catch (IOException e) {
      e.printStackTrace();
    }
    return null;
  }

  /**
   * Forward response of SEMS command to eSE
   * <br/>
   * The Input reponse received from SEMS applet,
   * The STORE DATA APDU command is used by the SEMS Device
   * Agent to provide the SEMS Application with an identifier
   * of the caller (SP Device Application), e.g.
   * the digest value of the SP Device Application package name
   * @param void
   *
   * @return {@code success} if the SW returned is 9000, {@code false}
   * otherwise.
   */
  private byte[] sendToSE(byte[] rapdu) {
    try {
      rapdu = sChannel.transmit(Arrays.copyOf(rapdu, rapdu.length - 2));
    } catch (IOException e) {
      e.printStackTrace();
    }
    putIntoLog(rapdu, SEResponse);
    return rapdu;
  }

  /**
   * Performs store data operation of caller information.
   * <br/>
   * The Input SHA-1 digest of caller package name,
   * The STORE DATA APDU command is used by the SEMS Device
   * Agent to provide the SEMS Application with an identifier
   * of the caller (SP Device Application), e.g.
   * the digest value of the SP Device Application package name
   * @param void
   *
   * @return {@code true} if the SW returned is 9000, {@code false} otherwise.
   */
  private byte[] sendProcessSEResponse(byte channel, byte[] rapdu) {
    byte[] processSEResponseHeader = {(byte)0x80, (byte)0xA2, (byte)0x80,
                                      (byte)0x00};
    byte[] processSEResponseLen = new byte[1];

    processSEResponseLen[0] = (byte)(rapdu.length);
    try {
      return sChannel.transmit(SemsUtil.append(
          SemsUtil.append(processSEResponseHeader, processSEResponseLen),
          rapdu));
    } catch (IOException e) {
      e.printStackTrace();
    }
    return null;
  }

  /**
   * Get output APDU response of script execution.
   * <br/>
   * Returns response APDU stored in application
   * context during previous SemsExecuteScript
   * @param fileName : Read response from fileName
   * mentioned
   *
   * @return Stored APDU Responses of previous execute
   * script.
   */
  public String getSemsOutputResponse(String fileName) throws Exception {
    SemsStatus status = SemsStatus.SEMS_STATUS_FAILED;
    Log.d(TAG, "******* Read response output APDU data");
    status = setDirectories();
    return readScriptFile(fileName);
  }

  /**
   * Performs secure SEMS script execution.
   * <br/>
   * The Input script path shall be provided,
   * output file name shall be provided,
   * IsemsCallback Interface shall be registered .
   * @param void
   *
   * @return {@code true} if the SW returned is 9000, {@code false} otherwise.
   */
  public SemsStatus executeScript(String scriptIn, String scriptOut,
                                    ISemsCallback callback) {
    SemsStatus status = SemsStatus.SEMS_STATUS_FAILED;
    this.inputScript = scriptIn;
    this.outputScript = scriptOut;
    this.mSemsCallback = callback;
    status = setDirectories();
    if (status == SemsStatus.SEMS_STATUS_SUCCESS) {
      writeScriptInputFile("encrypted_script.txt", scriptIn);
      new SemsAsyncExecutor().start();
    } else {
      Log.e(TAG, "Setting SEMS script path failed, package not found");
    }
    return status;
  }

  /**
   * Performs secure SEMS script execution.
   * <br/>
   * The Input script path shall be provided,
   * output file name shall be provided,
   * IsemsCallback Interface shall be registered
   * @param void
   *
   * @return {@code true} if the SW returned is 9000, {@code false} otherwise.
   */
  private void executeScript() {

    String scriptIn = this.inputScript;
    String scriptOut = this.outputScript;
    byte[] swReturned = sw9000;
    byte channelNumber = 0;
    SemsStatus status = SemsStatus.SEMS_STATUS_FAILED;
    mState = SEMS_STATE_SELECT;
    try {

      /*To handle If input is given as path
      String script = readScriptFile(scriptIn);*/
      String script = scriptIn;
      byte[] data = SemsUtil.parseHexString(script);
      if (data == null) {
        putIntoLog(sw6987, ErrorResponse);
        updateSemsStatus(sw6987);
        Log.e(TAG, ">>>>>>>>>> parseHexString returned NULL <<<<<<<<<<");
        return;
      }
      List<SemsTLV> scriptTlvs = SemsTLV.parse(data);

      byte[] rapdu;

      if ((scriptTlvs == null) || scriptTlvs.size() == 0) {
        putIntoLog(sw6987, ErrorResponse);
        updateSemsStatus(sw6987);
        Log.e(TAG, ">>>>>>>>>> Error : Script size 0 <<<<<<<<<<");
        return;
      }
      Log.d(TAG, "");
      Log.d(TAG, ">>>>>>>>>> Starting SEMS Execute Script <<<<<<<<<<");
      Log.d(TAG, "");

      try {
        /*start_execute_script:*/
        while (mState < SEMS_STATE_PROCESSING_COMPLETED) {
          /*
           * STEP 2A of executeScript - Select SEMS applet
           */
          switch (mState) {
          case SEMS_STATE_SELECT: {
            status = SelectSems();
            if (status != SemsStatus.SEMS_STATUS_SUCCESS) {
              closeLogicalChannel(channelNumber);
              updateSemsStatus(sw6987);
              return;
            }
          }
          // fall-through
          case SEMS_STATE_STORE_DATA: {
            /*
             * STEP 3 of executeScript - Sending SHA1 of Caller package
             */
            rapdu = sendSHA1OfCallerPackage(channelNumber,
                                            callerPackageName.getBytes());
            if (rapdu == null) {
              Log.e(TAG, "sendSHA1OfCallerPackage received incorrect rapdu");
              closeLogicalChannel(channelNumber);
              updateSemsStatus(rapdu);
              return;
            }
            if (SemsUtil.getSW(rapdu) != (short)0x9000) {
              closeLogicalChannel(channelNumber);
              updateSemsStatus(rapdu);
              return;
            }
          }
          // fall-through
          case SEMS_STATE_CHECK_CERTIFICATE: {
            /*
             * STEP 4 of executeScript - Searching for Certificate in Script
             * and Sending of Certificate
             */
            if (ProcessCertificateFrame(scriptTlvs) !=
                SemsStatus.SEMS_STATUS_SUCCESS) {
              return;
            }
          }
          // fall-through
          case SEMS_STATE_VERIFY_SIGNATURE: {
            /*
             * STEP 5 of executeScript - Authentication frame command
             */
            if (verifySignature(scriptTlvs) != SemsStatus.SEMS_STATUS_SUCCESS) {
              return;
            }
          }
          // fall-through
          case SEMS_STATE_SECURE_COMMAND_PROCESSING: {
            /*  STEP 6 of executeScript -Secure script commands*/
            status = SemsSecureCommandProcess(scriptTlvs);
            break;
          }
          }
        } /* End of restart_execute_script*/
        /*
         * STEP 9 of executeScript
         */
      } catch (Exception e) {
        e.printStackTrace();
        putIntoLog(sw6F00, ErrorResponse);
        closeLogicalChannel(channelNumber);
        updateSemsStatus(sw6F00);
        return;
      }
      putIntoLog(response, SWResponse);
      closeLogicalChannel(channelNumber);
      updateSemsStatus(response);
      return;
    }catch(Exception e) {
      putIntoLog(sw6987, ErrorResponse);
      updateSemsStatus(sw6987);
      Log.e(TAG, ">>>>>>>>>> Error : Invalid Script <<<<<<<<<<");
      return;
    } finally {
      /*Always write log file*/
      writeScriptOutFile(scriptOut);
    }
  }

  /**
   * Performs secure SEMS script execution.
   * <br/>
   * The SEMS secure command packets are forwarded to SEMS applet
   * based on the return SW next action is taken up.
   *
   * @param List<SemsTLV> parsed input TLV list
   *
   * @return {@code SEMS_STATE_SUCCESS} if processing is success, {@code false}
   * otherwise.
   */
  private SemsStatus SemsSecureCommandProcess(List<SemsTLV> scriptTlvs) throws Exception {
    SemsStatus stat = SemsStatus.SEMS_STATUS_FAILED;
    byte rapdu[] = sw6987;
    SemsTLV secureCommand;
    byte channelNumber = 0;
    short sw;
    lsCommandSeen = false;
    mState = SEMS_STATE_SECURE_COMMAND_PROCESSING;
    while (linePointer < scriptTlvs.size()) {
      /*
       * STEP 6 of executeScript - Searching for Secure Script Command
       */
      secureCommand = scriptTlvs.get(linePointer);
      linePointer++;
      if (secureCommand.getTLV()[0] == (byte)0x40) {
        /*
         * STEP 7 of executeScript - Secure Script Command Found
         */
        lsCommandSeen = true;

        if (secureCommand.getLength() > 4 /* DDD: was 32 */) {
          byte[] secCmd = secureCommand.getValue();

          rapdu = sendProcessScript(channelNumber, secCmd);
          if (rapdu == null) {
            Log.e(TAG, "sendProcessScript received incorrect rapdu");
            putIntoLog(sw6987, ErrorResponse);
            rapdu = sw6987;
            break;
          }
          sw = SemsUtil.getSW(rapdu);
          if (sw == (short)0x6310) {
            /*
             * STEP 8 of executeScript - Process SE Response
             */
            putIntoLog(rapdu, SemsResponse);

            if ((rapdu = sendToSE(rapdu)) == null) {
              putIntoLog(sw6987, ErrorResponse);
              rapdu = sw6987;
              break;
            }
            putIntoLog(rapdu, SEResponse);
            {
              rapdu = sendProcessSEResponse(channelNumber, rapdu);
              putIntoLog(rapdu, SemsResponse);

              while (SemsUtil.getSW(rapdu) == (short)0x6310) {

                if ((rapdu = sendToSE(rapdu)) == null) {
                  putIntoLog(sw6987, ErrorResponse);
                  rapdu = sw6987;
                  break;
                }
                putIntoLog(rapdu, SEResponse);
                rapdu = sendProcessSEResponse(channelNumber, rapdu);
                putIntoLog(rapdu, SemsResponse);
              }
            }
            if ((SemsUtil.getSW(rapdu) != (short)0x9000) &&
                (SemsUtil.getSW(rapdu) != (short)0x6300)) {
              putIntoLog(rapdu, ErrorResponse);
              break;
            }
          } else if (sw == (short)0x6320) {
            putIntoLog(rapdu, SemsResponse);
            closeLogicalChannel(channelNumber);
            AID_MEM = SemsUtil.getRDATA(rapdu);
            Log.d(TAG, "Received new AID need to switch");
            /*Strip already processed LS commands*/
            scriptTlvs.subList(0, linePointer).clear();
            linePointer = 0;
            Log.d(TAG, "Switch to new AID");
            if (scriptTlvs.size() > 0) {
              mState = SEMS_STATE_SELECT;
              Log.d(TAG, "Continue buffered script");
            } else {
              mState = SEMS_STATE_SECURE_COMMAND_PROCESSING;
              Log.d(TAG, "Finished buffered script");
              SemsStatus mstatus = SelectSems();
              if (mstatus == SemsStatus.SEMS_STATUS_SUCCESS) {
                Log.d(TAG, "Successful selection of SEMS update");
              } else if (mstatus == SemsStatus.SEMS_STATUS_FAILED) {
                Log.d(TAG, "Selection failed for SEMS update");
              }
              rapdu = rapduSelect;
            }
            /*continue restart_execute_script;*/
            break;
          } else if ((sw != (short)0x9000) && (sw != (short)0x6300)) {
            putIntoLog(rapdu, SemsResponse);
            break;
          } else {
            putIntoLog(rapdu, SemsResponse);
          }
        } else {
          Log.e(TAG, "Invalid length for secure command");
          putIntoLog(sw6987, ErrorResponse);
          rapdu = sw6987;
          break;
        }
      } else if (secureCommand.getTLV()[0] != (byte)0x60 &&
                 !(secureCommand.getTLV()[0] == (byte)0x7F &&
                   secureCommand.getTLV()[1] == (byte)0x21)) {
        Log.e(TAG, "Invalid tag found secure script");
        putIntoLog(sw6987, ErrorResponse);
        rapdu = sw6987;
        break;
      } else if (lsCommandSeen) {
        closeLogicalChannel(channelNumber);
        /* Consume already processed LS commands*/
        scriptTlvs.subList(0, linePointer - 1).clear();
        linePointer = 0;

        Log.d(TAG, "");
        Log.d(TAG, ">>>>>>> Executing new script...");
        Log.d(TAG, "");

        /* Re-select the LS Application. (FIXME: may be removed because
         * there may be an issue in the LS Applet)*/
        rapdu = selectApplication(channelNumber, AID_MEM);
        if(rapdu == null) {
          putIntoLog(sw6987, ErrorResponse);
          rapdu = sw6987;
          break;
        }
        mState = SEMS_STATE_STORE_DATA;
        break;
      }
    }
    sw = SemsUtil.getSW(rapdu);
    response = rapdu;
    if (sw == (short)0x9000 && mState == SEMS_STATE_SECURE_COMMAND_PROCESSING) {
      stat = SemsStatus.SEMS_STATUS_SUCCESS;
      mState = SEMS_STATE_PROCESSING_COMPLETED;
      Log.d(TAG, "Reached end of script processing");
    } else if (mState != SEMS_STATE_SECURE_COMMAND_PROCESSING) {
      Log.d(TAG, "Script processing shall continue");
    } else {
      mState = SEMS_STATE_PROCESSING_COMPLETED;
      Log.d(TAG, "Script execution failed");
    }
    return stat;
  }

  /**
   * Script certificate verification is handled
   * <br/>
   * The SEMS Device Agent looks for the first CERT.SP.AUT
   * certificate of which tags '42' and '45' match the
   * buffered tags '42' and '45' (see Figure B-2) returned
   *  by the SELECT command.
   * @param List<SemsTLV> parsed input TLV list
   *
   * @return {@code SEMS_STATE_SUCCESS} if processing is success, {@code false}
   * otherwise.
   */

  private SemsStatus ProcessCertificateFrame(List<SemsTLV> scriptTlvs) {

    List<SemsTLV> tlvs;
    byte channelNumber = 0;
    SemsTLV tlvSC42;
    SemsTLV tlvSC45;
    SemsTLV tlvCertInScript = null;
    byte[] APCert = null;
    SemsStatus stat = SemsStatus.SEMS_STATUS_FAILED;
    byte rapdu[];
    Log.d(TAG, "Check Mandatory fields in Certificate ");
    for (int i = 0; i < scriptTlvs.size(); i++) {

      if (scriptTlvs.get(i).getTag() == 0x7F21) {
        certIndex = i;
        tlvCertInScript = scriptTlvs.get(i);

        byte[] cert = tlvCertInScript.getTLV();
        tlvs = SemsTLV.parse(tlvCertInScript.getValue());
        tlvSC42 = SemsTLV.find(tlvs, 0x42);
        tlvSC45 = SemsTLV.find(tlvs, 0x45);

        /* Check that all mandatory tags are present. If not so, return
         6987.*/
        boolean isCertOK = true;
        if (isCertOK) {
          isCertOK = SemsTLV.find(tlvs, 0x93) != null;
        }
        if (isCertOK) {
          isCertOK = SemsTLV.find(tlvs, 0x42) != null;
        }
        if (isCertOK) {
          isCertOK = SemsTLV.find(tlvs, 0x5F20) != null;
        }
        if (isCertOK) {
          isCertOK = SemsTLV.find(tlvs, 0x95) != null;
        }
        if (isCertOK) {
          isCertOK = SemsTLV.find(tlvs, 0x45) != null;
        }
        if (isCertOK) {
          isCertOK = SemsTLV.find(tlvs, 0x53) != null;
        }
        if (isCertOK) {
          isCertOK = SemsTLV.find(tlvs, 0x5F37) != null;
        }
        if (isCertOK) {
          SemsTLV tlvSC7F49 = SemsTLV.find(tlvs, 0x7F49);
          isCertOK = tlvSC7F49 != null && tlvSC7F49.isConstructed() &&
                     SemsTLV.find(tlvSC7F49.getNodes(), 0x86) != null;
        }

        if (!isCertOK) {
          break;
        }

        if (tlvSC42 == null || tlvSC45 == null) {
          continue;
        }

        if (Arrays.equals(tlvRE42.getValue(), tlvSC42.getValue()) &&
            Arrays.equals(tlvRE45.getValue(), tlvSC45.getValue())) {
          /* Correct certificate found*/
          APCert = cert;
          stat = SemsStatus.SEMS_STATUS_SUCCESS;
          break;
        }
      } else if (scriptTlvs.get(i).getTag() == 0x60) {
        ;
      } else if (scriptTlvs.get(i).getTag() == 0x40) {
        Log.e(TAG, "Unexpected TAG 40 command found");
        break;
      } else {
        break;
      }
    }
    if (stat == SemsStatus.SEMS_STATUS_SUCCESS && APCert != null) {
      rapdu = sendAPCertificate(channelNumber, APCert);
      if (rapdu == null) {
        Log.e(TAG, "sendAPCertificate received incorrect rapdu");
        closeLogicalChannel(channelNumber);
        updateSemsStatus(rapdu);
        return SemsStatus.SEMS_STATUS_FAILED;
      }
      if (SemsUtil.getSW(rapdu) != (short)0x9000) {
        Log.e(TAG, "certificate frame command failed");
        putIntoLog(rapdu, ErrorResponse);
        closeLogicalChannel(channelNumber);
        updateSemsStatus(rapdu);
        stat = SemsStatus.SEMS_STATUS_FAILED;
      }
    } else {
      Log.e(TAG, "No valid certificate frame found");
      closeLogicalChannel(channelNumber);
      putIntoLog(sw6987, ErrorResponse);
      updateSemsStatus(sw6987);
    }
    Log.d(TAG, "Exit Certificate frame validation");
    return stat;
  }

  /**
   * Select SEMS application/SEMS updater on eSE
   * <br/>
   * The SEMS Device Agent selects either the SEMS
   * Application or the SEMS Updater. The SEMS Updater
   * is selected if the SEMS Application is not present
   * @param List<SemsTLV> parsed input TLV list
   *
   * @return {@code SEMS_STATE_SUCCESS} if processing is success, {@code false}
   * otherwise.
   */
  private SemsStatus SelectSems() throws Exception {
    byte channelNumber = 0;
    SemsTLV tlvRootEntityKeyID;
    List<SemsTLV> tlvs;
    SemsStatus stat = SemsStatus.SEMS_STATUS_FAILED;
    Log.d(TAG, "Select SEMS Application");
    rapduSelect = selectApplication(channelNumber, AID_MEM);
    if (rapduSelect == null) {
      Log.e(TAG, "SEMS-select failed");
      return stat;
    }
    if (SemsUtil.getSW(rapduSelect) != (short)0x9000) {
      if ((SemsUtil.getSW(rapduSelect) == (short)0x6999) ||
          (SemsUtil.getSW(rapduSelect) == (short)0x6A82)) {
        rapduSelect = selectApplication(channelNumber, SEMS_APP_AID);
        if (rapduSelect == null) {
          Log.e(TAG, "SEMS-select failed");
          return stat;
        }
        if ((SemsUtil.getSW(rapduSelect) == (short)0x6999) ||
            (SemsUtil.getSW(rapduSelect) == (short)0x6A82)) {
          rapduSelect = selectApplication(channelNumber, SEMS_UPD_APP_AID);
          if (rapduSelect == null) {
            Log.e(TAG, "SEMS-select failed");
            return stat;
          }
          if (SemsUtil.getSW(rapduSelect) == (short)0x9000) {
            AID_MEM = SEMS_UPD_APP_AID;
            stat = SemsStatus.SEMS_STATUS_SUCCESS;
          } else {
            Log.e(TAG, "SEMS/SEMS-updater not found");
            return stat;
          }
        } else {
          if (SemsUtil.getSW(rapduSelect) == (short)0x9000) {
            AID_MEM = SEMS_APP_AID;
            stat = SemsStatus.SEMS_STATUS_SUCCESS;
          } else {
            Log.e(TAG, "SEMS/SEMS-updater not found");
            return stat;
          }
        }
      } else {
        Log.e(TAG, "SEMS/SEMS-updater select failed");
        return stat;
      }
    } else {
      stat = SemsStatus.SEMS_STATUS_SUCCESS;
    }
    if (stat == SemsStatus.SEMS_STATUS_SUCCESS) {
      /*
       * STEP 2B of executeScript - retrieve TAG42 and TAG45
       */
      tlvs = SemsTLV.parse(SemsTLV.parse(rapduSelect).get(0).getValue());
      tlvRootEntityKeyID = SemsTLV.find(tlvs, 0x65);
      if (tlvRootEntityKeyID == null) {
        return SemsStatus.SEMS_STATUS_FAILED;
      }
      tlvs = SemsTLV.parse(tlvRootEntityKeyID.getValue());
      tlvRE42 = SemsTLV.find(tlvs, 0x42);
      tlvRE45 = SemsTLV.find(tlvs, 0x45);
    }
    Log.d(TAG, "Exit Select SEMS Application");
    return stat;
  }

  /**
   * SEMS Script Authentication frame
   * <br/>
   * SEMS Device Agent sends an Authentication
   * Frame in a PROCESS SCRIPT COMMAND APDU command
   * @param List<SemsTLV> parsed input TLV list
   *
   * @return {@code SEMS_STATE_SUCCESS} if processing is success, {@code false}
   * otherwise.
   */
  private SemsStatus verifySignature(List<SemsTLV> scriptTlvs) {
    byte channelNumber = 0;
    byte[] rapdu;
    SemsTLV authFrame;
    SemsStatus stat = SemsStatus.SEMS_STATUS_FAILED;

    linePointer = certIndex + 1;
    authFrame = scriptTlvs.get(linePointer);
    linePointer++;

    if (authFrame.getTag() != 0x60) {
      Log.e(TAG, "Authentication frame not found");
      closeLogicalChannel(channelNumber);
      putIntoLog(sw6987, ErrorResponse);
      updateSemsStatus(sw6987);
      return stat;
    }
    authFrame = SemsTLV.parse(authFrame.getValue()).get(0);
    rapdu = sendAuthenticationFrame(channelNumber, authFrame.getValue());
    if (rapdu == null) {
      Log.e(TAG, "sendAuthenticationFrame received incorrect rapdu");
      closeLogicalChannel(channelNumber);
      putIntoLog(sw6987, ErrorResponse);
      updateSemsStatus(sw6987);
      return stat;
    }
    putIntoLog(rapdu, SemsAuthResponse);

    if (SemsUtil.getSW(rapdu) == (short)0x6310) { // begin_perso cleanup
      int i = 0;

      if ((rapdu = sendToSE(rapdu)) == null) {
        putIntoLog(sw6987, ErrorResponse);
        closeLogicalChannel(channelNumber);
        updateSemsStatus(sw6987);
        return stat;
      }
      putIntoLog(rapdu, SEResponse);
      rapdu = sendProcessSEResponse(channelNumber, rapdu);
      putIntoLog(rapdu, SemsResponse);
      while (SemsUtil.getSW(rapdu) == (short)0x6310) {

        if ((rapdu = sendToSE(rapdu)) == null) {
          putIntoLog(sw6987, ErrorResponse);
          closeLogicalChannel(channelNumber);
          updateSemsStatus(sw6987);
          return stat;
        }
        putIntoLog(rapdu, SEResponse);
        rapdu = sendProcessSEResponse(channelNumber, rapdu);
        putIntoLog(rapdu, SemsResponse);

        i++;
      }
    } else if (SemsUtil.getSW(rapdu) != (short)0x9000) {
      Log.e(TAG, "Processing Authentication frame failed");
      putIntoLog(rapdu, SemsResponse);
      closeLogicalChannel(channelNumber);
      updateSemsStatus(rapdu);
      return stat;
    } else if (SemsUtil.getSW(rapdu) == (short)0x9000) {
      stat = SemsStatus.SEMS_STATUS_SUCCESS;
    }
    return stat;
  }

  class SemsAsyncExecutor extends Thread {
    public void run() { executeScript(); }
  }

  /**
   * Update the SEMS execution status to application
   * <br/>
   * Inform the registered SP application about the
   * SEMS execution status
   * @param List<SemsTLV> parsed input TLV list
   *
   * @return {@code SEMS_STATE_SUCCESS} if processing is success, {@code false}
   * otherwise.
   */
  void updateSemsStatus(byte[] status) {
    int respLen = 0;
    int updateStatus = 0x0F;
    if (status != null) {
      respLen = status.length;
      if (respLen >= 2) {
        if (status[respLen - 2] == (byte)0x90 && status[respLen - 1] == 0) {
          updateStatus = 0;
          Log.d(TAG, "Exit SEMS script execution success");
        } else if (status[respLen - 2] == (byte)0x69 &&
                   status[respLen - 1] == (byte)0x87) {
          updateStatus = 1;
          Log.d(
              TAG,
              "Exit SEMS script execution failed due to script processing error");
        } else if (status[respLen - 2] == (byte)0x6F &&
                   status[respLen - 1] == (byte)0x00) {
          updateStatus = 2;
          Log.d(TAG, "Exit SEMS script execution failed due to IO exception");
        } else {
          updateStatus = 3;
          Log.d(TAG, "Exit SEMS script execution failed due to unknown");
        }
      }
    }
    if (this.mSemsCallback != null) {
      this.mSemsCallback.onSemsComplete(updateStatus);
      this.mSemsCallback.onSemsComplete(updateStatus, sRespOutlog);
    }
  }
  /**
   * Retrieve the last SEMS execution status by sending GET DATA command
   * to SEMS applet
   * <br/>
   * @return {@code SemsGetLastExecStatus object}
   *      outScriptSignature : SEMS lib will provide the Authentication frame
   *             signature of the last executed script. Application can use this
   *             info to match with local SEMS script, useful in multiple application
   *             context.
   *      status:
   *      0x00 - Success, The input script has been completely executed
   *      0x01 - Failed, The input script execution was interrupted
   *             because of teardown
   */
  SemsGetLastExecStatus getLastSemsExecuteStatus() throws Exception {
    final byte GET_SEMS_STATUS = 0x46;
    final byte GET_AUTH_SIGNATURE = 0x47;
    byte channelNumber = 0;
    List<SemsTLV> tlvs;
    SemsTLV tlvSC46 , tlvSC47;
    byte[] rapdu;

    SemsGetLastExecStatus lastSemsExec = new SemsGetLastExecStatus();
    lastSemsExec.status = SemsAgent.SEMS_STATUS_FAILED;
    lastSemsExec.outScriptSignature = null;

    /* Frame packet to get status and authentication */
    byte[] getDataFrame = {(byte)0x80, (byte)0xCA, (byte)0x00, (byte)0x00, (byte)0x00};

    try {
        if (SelectSems() != SemsStatus.SEMS_STATUS_SUCCESS) {
          return lastSemsExec;
        }

        /******** Processing Authentication command ***********/
        getDataFrame[3] = GET_AUTH_SIGNATURE;
        rapdu = sChannel.transmit(getDataFrame);
        if((rapdu.length != 0) && SemsUtil.getSW(rapdu) == (short)0x9000) {
          tlvs = SemsTLV.parse(rapdu);
          if(tlvs.size() != 0) {
            tlvSC47 = SemsTLV.find(tlvs, GET_AUTH_SIGNATURE);
            if(tlvSC47 != null)
              lastSemsExec.outScriptSignature = Arrays.toString(tlvSC47.getValue());
          }
        }

        /******** Processing Status command ***********/
        getDataFrame[3] = GET_SEMS_STATUS;
        rapdu = sChannel.transmit(getDataFrame);
        if((rapdu.length != 0) && SemsUtil.getSW(rapdu) == (short)0x9000) {
          tlvs = SemsTLV.parse(rapdu);
          if(tlvs.size() != 0) {
            int statusByte = 0;
            tlvSC46 = SemsTLV.find(tlvs, GET_SEMS_STATUS);
            if((tlvSC46 != null) && (tlvSC46.getValue()[statusByte] == SemsAgent.SEMS_STATUS_SUCCESS)) {
              lastSemsExec.status = SemsAgent.SEMS_STATUS_SUCCESS;
            }
          }
        }

        Log.d(TAG, "******* Sems authentication signature : " + lastSemsExec.outScriptSignature);
        Log.d(TAG, "******* Sems status : " + lastSemsExec.status);

        /*Close the logical chanel*/
        closeLogicalChannel(channelNumber);
    } catch (IOException e) {
      closeLogicalChannel(channelNumber);
      e.printStackTrace();
    }
    return lastSemsExec;
  }
}
