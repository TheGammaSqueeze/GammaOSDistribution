/*
 * Copyright (C) 2015 The Android Open Source Project
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
 * limitations under the License
 */

package com.android.traceur;


import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.UserManager;
import android.preference.PreferenceManager;
import android.provider.Settings;
import android.util.EventLog;
import android.util.Log;

public class StopTraceService extends TraceService {
    private static final String TAG = "Traceur";

    public StopTraceService() {
        super("StopTraceService");
        setIntentRedelivery(true);
    }

    /* If we stop a trace using this entrypoint, we must also reset the preference and the
     * Quick Settings UI, since this may be the only indication that the user wants to stop the
     * trace.
    */
    @Override
    public void onHandleIntent(Intent intent) {
        Context context = getApplicationContext();
        // Checks that developer options are enabled and the user is an admin before continuing.
        boolean developerOptionsEnabled =
                Settings.Global.getInt(context.getContentResolver(),
                        Settings.Global.DEVELOPMENT_SETTINGS_ENABLED, 0) != 0;
        if (!developerOptionsEnabled) {
            // Refer to b/204992293.
            EventLog.writeEvent(0x534e4554, "204992293", -1, "");
            return;
        }
        UserManager userManager = context.getSystemService(UserManager.class);
        boolean isAdminUser = userManager.isAdminUser();
        boolean debuggingDisallowed = userManager.hasUserRestriction(
                UserManager.DISALLOW_DEBUGGING_FEATURES);
        if (!isAdminUser || debuggingDisallowed) {
            return;
        }
        // Ensures that only intents that pertain to stopping a trace and need to be accessed from
        // outside Traceur are passed to TraceService through StopTraceService.
        String intentAction = intent.getAction();
        if (!intentAction.equals(TraceService.INTENT_ACTION_NOTIFY_SESSION_STOLEN) &&
            !intentAction.equals(TraceService.INTENT_ACTION_NOTIFY_SESSION_STOPPED)) {
            return;
        }
        SharedPreferences prefs = PreferenceManager.getDefaultSharedPreferences(context);
        boolean prefsTracingOn =
            prefs.getBoolean(context.getString(R.string.pref_key_tracing_on), false);

        // If the user thinks tracing is off and the trace processor agrees, we have no work to do.
        // We must still start a foreground service, but let's log as an FYI.
        if (!prefsTracingOn && !TraceUtils.isTracingOn()) {
            Log.i(TAG, "StopTraceService does not see a trace to stop.");
        }

        PreferenceManager.getDefaultSharedPreferences(context)
                .edit().putBoolean(context.getString(R.string.pref_key_tracing_on),
                        false).commit();
        context.sendBroadcast(new Intent(MainFragment.ACTION_REFRESH_TAGS));
        QsService.updateTile();
        super.onHandleIntent(intent);
    }
}
