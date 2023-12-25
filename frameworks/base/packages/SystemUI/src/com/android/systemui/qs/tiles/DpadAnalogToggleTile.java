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

/** Quick settings tile: DpadAnalogToggle **/
public class DpadAnalogToggleTile extends QSTileImpl<BooleanState> {


    private static final int STATE_ONE = 0;
    private static final int STATE_TWO = 1;
    private int currentState = STATE_ONE;


    private final Icon mIcon = ResourceIcon.get(R.drawable.ic_qs_plus);
    private final Receiver mReceiver = new Receiver();

    @Inject
    public DpadAnalogToggleTile(
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
        mReceiver.init();
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
                sendShellCommand("/system/bin/setdpadanalogtoggle_on.sh");
                currentState = STATE_TWO;
                break;
            case STATE_TWO:
                sendShellCommand("/system/bin/setdpadanalogtoggle_off.sh");
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
        return "DPAD/Analog Swap";
    }

    @Override
    public int getMetricsCategory() {
        return VIEW_UNKNOWN;
    }

    @Override
    protected void handleUpdateState(BooleanState state, Object arg) {
        switch (currentState) {
            case STATE_ONE:
                state.label = "DPAD/Analog Swap Off";
                state.icon = ResourceIcon.get(R.drawable.ic_qs_plus);
                state.state = Tile.STATE_INACTIVE;
                break;
            case STATE_TWO:
                state.label = "DPAD/Analog Swap On";
                state.icon = ResourceIcon.get(R.drawable.ic_qs_circle);
                state.state = Tile.STATE_ACTIVE;
                break;
        }
    }

    private void sendShellCommand(String command) {
        try {
        Process process = Runtime.getRuntime().exec(command); // Execute the command directly
        OutputStream os = process.getOutputStream();
        os.write("exit\n".getBytes());
        os.flush();
        os.close();
        process.waitFor();
        } catch (Exception e) {
            e.printStackTrace();
        }
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
