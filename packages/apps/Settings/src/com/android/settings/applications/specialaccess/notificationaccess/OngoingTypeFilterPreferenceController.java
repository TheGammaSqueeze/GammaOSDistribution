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

package com.android.settings.applications.specialaccess.notificationaccess;

import static android.service.notification.NotificationListenerService.FLAG_FILTER_TYPE_ONGOING;

import android.content.Context;

public class OngoingTypeFilterPreferenceController extends TypeFilterPreferenceController {

    private static final String TAG = "OngoingFilterPrefCntlr";

    public OngoingTypeFilterPreferenceController(Context context, String key) {
        super(context, key);
    }

    @Override
    protected int getType() {
        return FLAG_FILTER_TYPE_ONGOING;
    }
}