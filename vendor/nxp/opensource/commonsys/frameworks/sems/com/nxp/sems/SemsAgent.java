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

import android.content.Context;
import android.util.Log;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

import com.nxp.sems.channel.ISemsApduChannel;
import com.nxp.sems.channel.SemsApduChannelFactory;
import com.nxp.sems.channel.SemsOmapiApduChannel;
import com.nxp.sems.SemsException;
import com.nxp.sems.SemsExecutor;
import com.nxp.sems.ISemsCallback;
import com.nxp.sems.SemsStatus;
import com.nxp.sems.SemsExecutionStatus;

public final class SemsAgent {
  public static final String TAG = "SEMS-SemsAgent";
  public static final byte SEMS_STATUS_SUCCESS = 0x00;
  public static final byte SEMS_STATUS_FAILED = 0x01;
  public static final byte SEMS_STATUS_BUSY = 0x02;
  public static final byte SEMS_STATUS_DENIED = 0x03;
  public static final byte SEMS_STATUS_UNKNOWN = 0x0F;
  public static final short major = 1;
  public static final short minor = 1;

  private static final byte DEFAULT_TERMINAL_ID = 1;
  private static SemsAgent sInstance;
  private static Context sContext = null;
  private static byte sTerminalID = DEFAULT_TERMINAL_ID;
  private ISemsApduChannel mSemsApduChannel = null;
  private SemsExecutor mExecutor = null;
  public static Object semsObj = new Object();
  public static boolean flagSemsObj = false;

  /**
   * Returns SemsAgent singleton object
   * <br/>
   * The Input caller application context,
   * @param void
   *
   * @return {@code SemsAgent}.
   */
  public static SemsAgent getInstance(Context context) throws SemsException {
    if (context == null) {
      throw new SemsException("Context information invalid/null");
    }
    if (sInstance == null) {
      synchronized (SemsAgent.class) { sInstance = new SemsAgent(); }
    }
    if (context != sContext) {
      sContext = context;
    }
    Log.d(TAG, "Sems Agent version " + major + "." + minor);
    return sInstance;
  }

  private SemsAgent() {}

  /**
   * Perform secure SEMS script execution
   * <br/>
   * inputScript : The Input secure script buffer in string format,
   * fileName : Output response storage file name
   * callback : Callback to be invoked once SEMS execution is done
   * @param void
   *
   * @return {@code status} 0 in SUCCESS, otherwise 1 in failure.
   */
  public int SemsExecuteScript(String inputScriptBuffer, String outputFilename,
                               ISemsCallback callback) throws SemsException {
    return SemsExecuteScript(inputScriptBuffer, outputFilename, callback,
                             DEFAULT_TERMINAL_ID);
  }

  /**
   * Perform secure SEMS script execution
   * <br/>
   * inputScript : The Input secure script buffer in string format,
   * fileName : Output response storage file name
   * callback : Callback to be invoked once SEMS execution is done
   * omapiTerminalId : OMAPI Terminal ID of secure element
   * @param void
   *
   * @return {@code status} 0 in SUCCESS, otherwise 1 in failure.
   */
  public int SemsExecuteScript(String inputScriptBuffer, String outputFilename,
                               ISemsCallback callback, byte omapiTerminalId)
      throws SemsException {
    sTerminalID = omapiTerminalId;
    if (inputScriptBuffer == null) {
      throw new SemsException("Invalid/Null Input script");
    }
    mSemsApduChannel = SemsApduChannelFactory.getInstance(
        SemsApduChannelFactory.OMAPI_CHANNEL, sContext, sTerminalID);
    mExecutor = SemsExecutor.getInstance(mSemsApduChannel, sContext);
    SemsStatus status =
        mExecutor.executeScript(inputScriptBuffer, outputFilename, callback);
    if (status == SemsStatus.SEMS_STATUS_SUCCESS) {
      return SEMS_STATUS_SUCCESS;
    } else {
      return SEMS_STATUS_FAILED;
    }
  }

  /**
   * Perform secure SEMS script execution synchronously
   * <br/>
   * inputScript : The Input secure script buffer in string format,
   * fileName : Output response storage file name
   * @param void
   *
   * @return {@code status} 0 in SUCCESS, otherwise
   *                        1 in SEMS status Failed
   *                        2 in SEMS status Busy
   *                        3 in SEMS status denied
   *                     0x0f in Unknown error.
   */
  public int SemsExecuteScript(String inputScriptBuffer, String outputFilename)
      throws SemsException {
    SemsExecutionStatus.mSemsExecutionStatus = SEMS_STATUS_FAILED;
    int status = SemsExecuteScript(inputScriptBuffer, outputFilename,
                                   new SemsExecutionStatus());
    if (status == SEMS_STATUS_SUCCESS) {
      synchronized (semsObj) {
        while (!flagSemsObj) {
          try {
            semsObj.wait();
          } catch (InterruptedException e) {
            Log.e(TAG, "Wait on SEMS script Execution failed");
          }
        }
        flagSemsObj = false;
      }

      return SemsExecutionStatus.mSemsExecutionStatus;
    } else {
      return SEMS_STATUS_FAILED;
    }
  }

  /**
   * Fetch output response APDU for SEMS script execution
   * <br/>
   * filename : File from current application space which stored
   * SEMS script execution response
   * @param String file name : From which response to be read
   *
   * @return {@code string}Response in string buffer.
   */
  public String SemsGetOutputData(String outputFilename) throws SemsException {
    try {
      SemsExecutor mExecutor =
          SemsExecutor.getInstance(null, sContext);
      return mExecutor.getSemsOutputResponse(outputFilename);
    } catch (Exception e) {
      throw new SemsException("Unable to fetch Sems response");
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
  public SemsGetLastExecStatus GetLastSemsExecuteStatus() throws SemsException {
    try {
      mSemsApduChannel = SemsApduChannelFactory.getInstance(
           SemsApduChannelFactory.OMAPI_CHANNEL, sContext, sTerminalID);
      mExecutor = SemsExecutor.getInstance(mSemsApduChannel, sContext);
      return mExecutor.getLastSemsExecuteStatus();
    } catch (Exception e) {
      throw new SemsException("Unable to get last sems execute status");
    }
  }
}
