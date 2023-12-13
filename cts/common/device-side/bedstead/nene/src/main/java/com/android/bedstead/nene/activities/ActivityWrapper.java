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

package com.android.bedstead.nene.activities;

import android.app.Activity;
import android.app.RemoteActivityImpl;
import android.os.UserHandle;

class ActivityWrapper extends RemoteActivityImpl implements NeneActivity {

    ActivityWrapper(Activity activity) {
        super(activity);
    }

    @Override
    public UserHandle getUser() {
        // Assuming if we have an Activity it's on the instrumented user
        return android.os.Process.myUserHandle();
    }
}
