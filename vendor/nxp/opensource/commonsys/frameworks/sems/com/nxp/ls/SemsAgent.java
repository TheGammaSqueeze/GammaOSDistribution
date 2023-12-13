/*
 * Copyright 2020 NXP
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

package com.nxp.ls;

import android.content.Context;
import android.util.Log;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

import com.nxp.ls.channel.ISemsApduChannel;
import com.nxp.ls.channel.SemsApduChannelFactory;
import com.nxp.ls.channel.SemsOmapiApduChannel;
import com.nxp.ls.SemsException;
import com.nxp.ls.SemsExecutor;
import com.nxp.ls.ISemsCallback;
import com.nxp.ls.SemsStatus;

public final class SemsAgent {
  public static final String TAG = "SEMS-SemsAgent";
  public static final byte SEMS_STATUS_SUCCESS = 0x00;
  public static final byte SEMS_STATUS_FAILED = 0x01;
  public static final byte SEMS_STATUS_BUSY = 0x02;
  public static final byte SEMS_STATUS_DENIED = 0x03;
  public static final byte SEMS_STATUS_UNKNOWN = 0x0F;
  public static final short major = 0;
  public static final short minor = 6;

  private static final byte DEFAULT_TERMINAL_ID = 0;
  private static SemsAgent sInstance;
  private static Context sContext = null;
  private static byte sTerminalID = DEFAULT_TERMINAL_ID;
  private ISemsApduChannel mSemsApduChannel = null;
  private SemsExecutor mExecutor = null;

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
    synchronized (SemsAgent.class) {
      sInstance = new SemsAgent();
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
   * terminalID : Terminal ID of secure element
   * @param void
   *
   * @return {@code status} 0 in SUCCESS, otherwise 1 in failure.
   */
  public int SemsExecuteScript(String inputScriptBuffer, String outputFilename,
                               ISemsCallback callback, byte terminalID)
      throws SemsException {
    if (inputScriptBuffer == null) {
      throw new SemsException("Invalid/Null Input script");
    }
    sTerminalID = terminalID;
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
}
