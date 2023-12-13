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
 * limitations under the License.
 */

package android.voiceinteraction.service;

import static com.android.compatibility.common.util.SystemUtil.runWithShellPermissionIdentity;

import android.content.ComponentName;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.service.voice.AlwaysOnHotwordDetector;
import android.service.voice.VoiceInteractionService;
import android.util.Log;
import android.voiceinteraction.common.Utils;

import java.util.Collections;
import java.util.Locale;
import java.util.Set;

public class MainInteractionService extends VoiceInteractionService {
    static final String TAG = "MainInteractionService";
    private Intent mIntent;
    private boolean mReady = false;

    @Override
    public void onReady() {
        super.onReady();
        mReady = true;
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        Log.i(TAG, "onStartCommand received");
        mIntent = intent;

        if (mIntent == null || !mReady) {
            Log.wtf(TAG, "Can't start because either intent is null or onReady() "
                    + "is not called yet. mIntent = " + mIntent + ", mReady = " + mReady);
            return START_NOT_STICKY;
        }

        final int testEvent = mIntent.getIntExtra(Utils.KEY_TEST_EVENT, -1);
        if (testEvent == Utils.VIS_NORMAL_TEST) {
            maybeStart();
        } else if (testEvent == Utils.HOTWORD_DETECTION_SERVICE_TRIGGER_TEST) {
            runWithShellPermissionIdentity(() -> {
                callCreateAlwaysOnHotwordDetector();
            });
        }
        return START_NOT_STICKY;
    }

    private void maybeStart() {
        Bundle args = mIntent.getExtras();
        final String className = (args != null)
                ? args.getString(Utils.VOICE_INTERACTION_KEY_CLASS) : null;
        if (className == null) {
            Log.i(TAG, "Yay! about to start session with TestApp");
            if (isActiveService(this, new ComponentName(this, getClass()))) {
                // Call to verify onGetSupportedVoiceActions is available.
                onGetSupportedVoiceActions(Collections.emptySet());
                args = new Bundle();
                Intent intent = new Intent()
                        .setAction(Intent.ACTION_VIEW)
                        .addCategory(Intent.CATEGORY_VOICE)
                        .addCategory(Intent.CATEGORY_BROWSABLE)
                        .setData(Uri.parse("https://android.voiceinteraction.testapp"
                                + "/TestApp"));
                args.putParcelable("intent", intent);
                Log.v(TAG, "showSession(): " + args);
                showSession(args, 0);
            } else {
                Log.wtf(TAG, "**** Not starting MainInteractionService because" +
                        " it is not set as the current voice interaction service");
            }
        } else {
            showSession(args, 0);
        }
    }

    @Override
    public Set<String> onGetSupportedVoiceActions(Set<String> voiceActions) {
        Log.v(TAG, "onGetSupportedVoiceActions " + voiceActions);
        return super.onGetSupportedVoiceActions(voiceActions);
    }

    private void callCreateAlwaysOnHotwordDetector() {
        Log.i(TAG, "callCreateAlwaysOnHotwordDetector()");
        try {
            createAlwaysOnHotwordDetector(/* keyphrase */ "Hello Google",
                    Locale.forLanguageTag("en-US"), /* options */ null, /* sharedMemory */ null,
                    new AlwaysOnHotwordDetector.Callback() {
                        @Override
                        public void onAvailabilityChanged(int status) {
                            Log.i(TAG, "onAvailabilityChanged(" + status + ")");
                        }

                        @Override
                        public void onDetected(AlwaysOnHotwordDetector.EventPayload eventPayload) {
                            Log.i(TAG, "onDetected");
                        }

                        @Override
                        public void onError() {
                            Log.i(TAG, "onError");
                        }

                        @Override
                        public void onRecognitionPaused() {
                            Log.i(TAG, "onRecognitionPaused");
                        }

                        @Override
                        public void onRecognitionResumed() {
                            Log.i(TAG, "onRecognitionResumed");
                        }
                    });
        } catch (IllegalStateException e) {
            Log.w(TAG, "callCreateAlwaysOnHotwordDetector() exception: " + e);
            broadcastIntentWithResult(
                    Utils.HOTWORD_DETECTION_SERVICE_TRIGGER_RESULT_INTENT,
                    Utils.HOTWORD_DETECTION_SERVICE_TRIGGER_ILLEGAL_STATE_EXCEPTION);
        }
    }

    private void broadcastIntentWithResult(String intentName, int result) {
        Intent intent = new Intent(intentName)
                .addFlags(Intent.FLAG_RECEIVER_FOREGROUND | Intent.FLAG_RECEIVER_REGISTERED_ONLY)
                .putExtra(Utils.KEY_TEST_RESULT, result);
        Log.d(TAG, "broadcast intent = " + intent + ", result = " + result);
        sendBroadcast(intent);
    }
}
