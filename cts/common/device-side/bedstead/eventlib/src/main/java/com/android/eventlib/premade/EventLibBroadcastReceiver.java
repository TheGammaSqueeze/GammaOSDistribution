/*
 * Copyright (C) 2021 The Android Open Source Project
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

package com.android.eventlib.premade;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

import com.android.eventlib.events.broadcastreceivers.BroadcastReceivedEvent;

/**
 * A {@link BroadcastReceiver} which logs events when receiving broadcasts.
 */
public class EventLibBroadcastReceiver extends BroadcastReceiver {

    private String mOverrideBroadcastReceiverClassName;

    public void setOverrideBroadcastReceiverClassName(String overrideBroadcastReceiverClassName) {
        mOverrideBroadcastReceiverClassName = overrideBroadcastReceiverClassName;
    }

    /** Log a {@link BroadcastReceivedEvent}. */
    @Override
    public void onReceive(Context context, Intent intent) {
        BroadcastReceivedEvent.BroadcastReceivedEventLogger logger =
                BroadcastReceivedEvent.logger(this, context, intent);

        if (mOverrideBroadcastReceiverClassName != null) {
            logger.setBroadcastReceiver(mOverrideBroadcastReceiverClassName);
        }

        logger.log();
    }

}
