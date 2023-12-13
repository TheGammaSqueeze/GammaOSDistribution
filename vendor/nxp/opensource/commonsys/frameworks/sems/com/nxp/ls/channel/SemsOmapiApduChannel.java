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

package com.nxp.ls.channel;

import android.content.Context;
import android.se.omapi.*;
import java.util.concurrent.Executor;
import java.io.IOException;
import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.TimeoutException;
import android.se.omapi.SEService.OnConnectedListener;
import android.util.Log;
import com.nxp.ls.SemsException;
import android.os.Bundle;
import java.util.NoSuchElementException;

public class SemsOmapiApduChannel implements ISemsApduChannel {
  public static final String TAG = "SEMS-SemsApduChannel";
  private final long SERVICE_CONNECTION_TIME_OUT = 3000;
  private Object serviceMutex = new Object();
  private boolean mFlagServiceMutex = false;
  private Timer connectionTimer;
  private ServiceConnectionTimerTask mTimerTask =
      new ServiceConnectionTimerTask();
  private SynchronousExecutor mExecutor = new SynchronousExecutor();
  private boolean mbIsConnected = false;
  private static SEService seService = null;
  private static Session sSession = null;
  private static Channel sChannel;
  private static Context sContext;
  private static byte meSEIdx;
  private static SemsOmapiApduChannel sOmapiChannel = null;

  /**
   * Returns SemsOmapiApduChannel singleton object
   * <br/>
   * The Input caller application context,
   * @param void
   *
   * @return {@code SemsAgent}.
   */
  public static SemsOmapiApduChannel getInstance(byte eSEx, Context context)
      throws SemsException {
    meSEIdx = eSEx;
    sContext = context;
    boolean initRequired = false;
    if (sOmapiChannel == null || seService == null || sSession == null
     || sChannel == null) {
      initRequired = true;
    } else if (!seService.isConnected() || sSession.isClosed() ||
               !sChannel.isOpen()) {
      initRequired = true;
    }

    if (initRequired) {
      sSession = null;
      sOmapiChannel = new SemsOmapiApduChannel();
    } else {
      Log.d(TAG, "Already Initialized");
    }

    return sOmapiChannel;
  }
  private SemsOmapiApduChannel() throws SemsException {
    if (seService == null || sSession == null) {
      Log.d(TAG, " Initialize OMAPI APDU channel");
      bindSEService();
      Log.d(TAG, " openSession & get readers");
      getSession();
    } else {
      Log.d(TAG, " OMAPI session already initialized");
    }
  }

  private final OnConnectedListener mListener = new OnConnectedListener() {
    @Override
    public void onConnected() {
      Log.d(TAG, " OnConnectedListener successfully onConnected");
      synchronized (serviceMutex) {
        mbIsConnected = true;
        mFlagServiceMutex = true;
        serviceMutex.notify();
      }
    }
  };

  class SynchronousExecutor implements Executor {
    public void execute(Runnable r) {
      Log.d(TAG, " From SynchronousExecutor");
      r.run();
    }
  }

  private void bindSEService() {
    BindToSEService bindService = new BindToSEService();
    bindService.start();
  }

  private void getSession() throws SemsException {

    waitForConnection();
    if(seService == null){
      Log.d(TAG, "SeService connection failed shall retry");
      try{
        new Thread().sleep(500);
      } catch(Exception e) {
        Log.d(TAG, "Thread interruption exception received");
      }
      synchronized (serviceMutex) {
        mbIsConnected =  false;
      }
      bindSEService();
      waitForConnection();
    }
    Reader[] readers = seService.getReaders();
    if (readers.length > meSEIdx) {
      try {
        sSession = readers[meSEIdx].openSession();
      } catch (Exception e) {
        throw new SemsException(
            "Exception during ApduChannel session intialization");
      }
    } else {
      throw new SemsException("Terminal not available");
    }
  }
  /**
   * Open session with eSE and opens channel using 7816-4
   * manage channel command, perform application selection with
   * given AID
   * <br/>
   * The Input application AID,
   * @param void
   *
   * @return {@code selectResponse}.
   */
  public byte[] open(byte[] aid) throws IOException {
    if (sSession != null) {
      try {
        sChannel = sSession.openLogicalChannel(aid);
        return sChannel.getSelectResponse();
      } catch (NoSuchElementException e) {
        return new byte[] {(byte)0x6A, (byte)0x82};
      } catch (SecurityException e) {
        throw new IOException("Security Exception");
      } catch (Exception e) {
        { throw new IOException("Open APDU channel failed"); }
      }
    } else {
      throw new IOException("Session not initialized");
    }
  }

  /**
   * Performs transmit on the channel already opened
   * Raw APDU data information is passed as input
   * <br/>
   * The Input raw APDU data,
   * @param void
   *
   * @return {@code Response APDU}.
   */
  public byte[] transmit(byte[] buffer) throws IOException {
    byte[] resp = null;
    if (sChannel == null) {
      throw new IOException("Channel not initialized");
    }
    try {
      resp = sChannel.transmit(buffer);
    } catch (IOException e) {
      throw new IOException("transmit on APDU channel failed");
    }
    return resp;
  }

  /**
   * Close the channel opened previously
   * <br/>
   * The Input None,
   * @param void
   *
   * @return {@code 0}.
   */
  public void close() {
    if (sChannel != null) {
      sChannel.close();
    }
  }
  public boolean isOpen() { return sSession.isClosed() == true ? false : true; }
  class ServiceConnectionTimerTask extends TimerTask {
    @Override
    public void run() {
      synchronized (serviceMutex) {
        mFlagServiceMutex = true;
        serviceMutex.notifyAll();
      }
    }
  }

  private void waitForConnection() throws SemsException {
    synchronized (serviceMutex) {
      if (!mbIsConnected) {
        while (!mFlagServiceMutex) {
          try {
            serviceMutex.wait();
          } catch (InterruptedException e) {
            Log.e(TAG, "Connection to eSE interrupted");
          }
        }
        mFlagServiceMutex = false;
      }
      if (!mbIsConnected) {
        throw new SemsException("Service could not be connected after " +
                                SERVICE_CONNECTION_TIME_OUT + " ms");
      }
      if (connectionTimer != null) {
        connectionTimer.cancel();
      }
    }
  }

  class BindToSEService extends Thread {
    public void run() {
      connectionTimer = new Timer();
      connectionTimer.schedule(mTimerTask, SERVICE_CONNECTION_TIME_OUT);
      seService = new SEService(sContext, mExecutor, mListener);
      Log.d(TAG, "Bind to SE service");
    }
  }
}
