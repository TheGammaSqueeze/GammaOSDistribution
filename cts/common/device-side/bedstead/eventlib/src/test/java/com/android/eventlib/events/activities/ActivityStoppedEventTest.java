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

package com.android.eventlib.events.activities;

import static com.google.common.truth.Truth.assertThat;

import android.content.Context;
import android.content.pm.ActivityInfo;

import com.android.activitycontext.ActivityContext;
import com.android.bedstead.nene.TestApis;
import com.android.eventlib.EventLogs;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

@RunWith(JUnit4.class)
public final class ActivityStoppedEventTest {

    private static final Context sContext = TestApis.context().instrumentedContext();

    private static final String ACTIVITY_CLASS_NAME = ActivityContext.class.getName();
    private static final ActivityInfo ACTIVITY_INFO = new ActivityInfo();
    {
        ACTIVITY_INFO.name = ACTIVITY_CLASS_NAME;
    }

    @Before
    public void setUp() {
        EventLogs.resetLogs();
    }

    @Test
    public void whereActivity_works() throws Exception {
        ActivityContext.runWithContext((activity) ->
                ActivityStoppedEvent.logger(activity, ACTIVITY_INFO)
                        .log());

        EventLogs<ActivityStoppedEvent> eventLogs =
                ActivityStoppedEvent.queryPackage(sContext.getPackageName())
                        .whereActivity().activityClass().className().isEqualTo(ACTIVITY_CLASS_NAME);

        assertThat(eventLogs.poll().activity().className()).isEqualTo(ACTIVITY_CLASS_NAME);
    }

    @Test
    public void whereActivity_skipsNonMatching() throws Exception {
        ActivityContext.runWithContext((activity) -> {
            ActivityStoppedEvent.logger(activity, ACTIVITY_INFO)
                    .log();
            ActivityStoppedEvent.logger(activity, ACTIVITY_INFO)
                    .log();
        });

        EventLogs<ActivityStoppedEvent> eventLogs =
                ActivityStoppedEvent.queryPackage(sContext.getPackageName())
                        .whereActivity().activityClass().className().isEqualTo(ACTIVITY_CLASS_NAME);

        assertThat(eventLogs.poll().activity().className()).isEqualTo(ACTIVITY_CLASS_NAME);
    }

}
