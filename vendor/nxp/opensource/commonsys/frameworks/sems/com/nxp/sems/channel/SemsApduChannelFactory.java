/*
 * Copyright 2019 NXP
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

package com.nxp.sems.channel;

import com.nxp.sems.channel.SemsOmapiApduChannel;
import android.content.Context;
import com.nxp.sems.SemsException;
import android.util.Log;

public class SemsApduChannelFactory {
  public static final byte OMAPI_CHANNEL = 0;
  public static final byte RAW_CHANNEL = 1;
  public static ISemsApduChannel mChannelFactory = null;
  public static final String TAG = "SEMS-SemsApduChannelFactory";

  public static ISemsApduChannel getInstance(byte type, Context context,
          byte terminalID) throws SemsException{
    if(mChannelFactory == null) {
      synchronized (SemsApduChannelFactory.class) {
        if(mChannelFactory == null) {
          Log.d(TAG, "SemsApduChannelFactory Initialization");
          mChannelFactory = (ISemsApduChannel) SemsApduChannelFactory.
                                 createApduChannel(type, context, terminalID);
        }
      }
    }
    return mChannelFactory;
  }

  private SemsApduChannelFactory() {}

  private static ISemsApduChannel createApduChannel(byte type, Context context,
                                           byte terminalID)
      throws SemsException {
    ISemsApduChannel mSemsApduChannel = null;
    if (type == OMAPI_CHANNEL) {
      mSemsApduChannel = SemsOmapiApduChannel.getInstance(terminalID, context);
    } else if (type == RAW_CHANNEL) {
      mSemsApduChannel = new SemsRawApduChannel();
    } else {
      throw new SemsException("Invalid APDU channel type");
    }
    return mSemsApduChannel;
  }
}
