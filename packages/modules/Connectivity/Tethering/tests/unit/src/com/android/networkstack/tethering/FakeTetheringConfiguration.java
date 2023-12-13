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

package com.android.networkstack.tethering;

import android.content.Context;
import android.content.res.Resources;
import android.net.util.SharedLog;

/** FakeTetheringConfiguration is used to override static method for testing. */
public class FakeTetheringConfiguration extends TetheringConfiguration {
    FakeTetheringConfiguration(Context ctx, SharedLog log, int id) {
        super(ctx, log, id);
    }

    @Override
    protected String getDeviceConfigProperty(final String name) {
        return null;
    }

    @Override
    protected boolean isFeatureEnabled(Context ctx, String featureVersionFlag) {
        return false;
    }

    @Override
    protected Resources getResourcesForSubIdWrapper(Context ctx, int subId) {
        return ctx.getResources();
    }

    @Override
    protected String getSettingsValue(final String name) {
        if (mContentResolver == null) return null;

        return super.getSettingsValue(name);
    }
}
