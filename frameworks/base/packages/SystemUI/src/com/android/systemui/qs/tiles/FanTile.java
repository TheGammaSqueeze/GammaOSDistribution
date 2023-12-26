/*
 * Copyright (C) 2016 The CyanogenMod Project
 * Copyright (c) 2017 The LineageOS Project
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

package com.android.systemui.qs.tiles;

import static com.android.internal.logging.MetricsLogger.VIEW_UNKNOWN;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.CountDownTimer;
import android.os.Handler;
import android.os.Looper;
import android.os.PowerManager;
import android.os.SystemClock;
import android.service.quicksettings.Tile;
import android.view.View;

import androidx.annotation.Nullable;

import com.android.internal.logging.MetricsLogger;
import com.android.systemui.R;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.qs.QSTile.BooleanState;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.qs.QSHost;
import com.android.systemui.qs.logging.QSLogger;
import com.android.systemui.qs.tileimpl.QSTileImpl;

import javax.inject.Inject;
import java.io.OutputStream;
import android.util.Log;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

/** Quick settings tile: Fan **/
public class FanTile extends QSTileImpl<BooleanState> {


    private static final int STATE_ONE = 0;
    private static final int STATE_TWO = 1;
    private static final int STATE_THREE = 2;
    private static final int STATE_FOUR = 3;
    private int currentState;


    private final Icon mIcon = ResourceIcon.get(R.drawable.ic_device_fan_on);
    private final Receiver mReceiver = new Receiver();

    @Inject
    public FanTile(
            QSHost host,
            @Background Looper backgroundLooper,
            @Main Handler mainHandler,
            FalsingManager falsingManager,
            MetricsLogger metricsLogger,
            StatusBarStateController statusBarStateController,
            ActivityStarter activityStarter,
            QSLogger qsLogger
    ) {
        super(host, backgroundLooper, mainHandler, falsingManager, metricsLogger,
                statusBarStateController, activityStarter, qsLogger);
	currentState = readFanControlValue(); // Initialize currentState based on FAN_CONTROL
        mReceiver.init();
    }

    private int readFanControlValue() {
        try {
            String commandOutput = sendShellCommand("od -An -t dI /data/rgp2xbox/FAN_CONTROL");
            return Integer.parseInt(commandOutput.trim());
        } catch (NumberFormatException e) {
            Log.e("DpadAnalogToggleTile", "Error parsing FAN_CONTROL value", e);
            return STATE_ONE; // default value if reading fails
        }
    }

    @Override
    public BooleanState newTileState() {
        return new BooleanState();
    }

    @Override
    protected void handleDestroy() {
        super.handleDestroy();
        mReceiver.destroy();
    }

    @Override
    public void handleSetListening(boolean listening) {
    }

    @Override
    protected void handleClick(@Nullable View view) {
        switch (currentState) {
            case STATE_ONE:
		sendShellCommand("/system/bin/setfanvalue_off.sh");
                currentState = STATE_TWO;
                break;
            case STATE_TWO:
                sendShellCommand("/system/bin/setfanvalue_auto.sh");
                currentState = STATE_THREE;
                break;
            case STATE_THREE:
                sendShellCommand("/system/bin/setfanvalue_cool.sh");
                currentState = STATE_FOUR;
                break;
            case STATE_FOUR:
                sendShellCommand("/system/bin/setfanvalue_max.sh");
                currentState = STATE_ONE;
                break;
        }
        refreshState();
    }

    @Override
    protected void handleLongClick(@Nullable View view) {
        refreshState();
    }

    @Override
    public Intent getLongClickIntent() {
        return null;
    }

    @Override
    public CharSequence getTileLabel() {
        return "Fan Speed";
    }

    @Override
    public int getMetricsCategory() {
        return VIEW_UNKNOWN;
    }

    @Override
    protected void handleUpdateState(BooleanState state, Object arg) {
        switch (currentState) {
            case STATE_ONE:
                state.label = "Fan Off";
                state.icon = ResourceIcon.get(R.drawable.ic_device_fan_off);
                state.state = Tile.STATE_INACTIVE;
                break;
            case STATE_TWO:
                state.label = "Fan Auto";
                state.icon = ResourceIcon.get(R.drawable.ic_device_fan_on);
                state.state = Tile.STATE_ACTIVE;
                break;
            case STATE_THREE:
                state.label = "Fan Cool";
                state.icon = ResourceIcon.get(R.drawable.ic_device_fan_on);
                state.state = Tile.STATE_ACTIVE;
                break;
            case STATE_FOUR:
                state.label = "Fan Max";
                state.icon = ResourceIcon.get(R.drawable.ic_device_fan_on);
                state.state = Tile.STATE_ACTIVE;
                break;
        }
    }

    private String sendShellCommand(String command) {
        StringBuilder output = new StringBuilder();
        Process process = null;
        BufferedReader reader = null;

        try {
            process = Runtime.getRuntime().exec(command); // Execute the command
            reader = new BufferedReader(new InputStreamReader(process.getInputStream()));

            String line;
            while ((line = reader.readLine()) != null) {
                output.append(line);
            }

            process.waitFor();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (reader != null) {
                try {
                    reader.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (process != null) {
                process.destroy();
            }
        }

        return output.toString();
    }

    private final class Receiver extends BroadcastReceiver {
        public void init() {
            // Register for Intent broadcasts for...
            IntentFilter filter = new IntentFilter();
            filter.addAction(Intent.ACTION_SCREEN_OFF);
            mContext.registerReceiver(this, filter, null, mHandler);
        }

        public void destroy() {
            mContext.unregisterReceiver(this);
        }

        @Override
        public void onReceive(Context context, Intent intent) {
            String action = intent.getAction();
            if (Intent.ACTION_SCREEN_OFF.equals(action)) {
                refreshState();
            }
        }
    }
}
