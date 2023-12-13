/*
 * Copyright (C) 2020 Google Inc.
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

package com.android.car.carlauncher;

import static androidx.test.espresso.Espresso.onView;
import static androidx.test.espresso.assertion.ViewAssertions.matches;
import static androidx.test.espresso.matcher.ViewMatchers.isDisplayed;
import static androidx.test.espresso.matcher.ViewMatchers.withId;

import android.testing.TestableContext;

import androidx.lifecycle.Lifecycle;
import androidx.test.InstrumentationRegistry;
import androidx.test.core.app.ActivityScenario;
import androidx.test.ext.junit.runners.AndroidJUnit4;
import androidx.test.filters.SmallTest;

import org.junit.After;
import org.junit.Rule;
import org.junit.Test;
import org.junit.runner.RunWith;

@RunWith(AndroidJUnit4.class)
@SmallTest
public class CarLauncherTest {

    @Rule
    public TestableContext mContext = new TestableContext(InstrumentationRegistry.getContext());
    private ActivityScenario<CarLauncher> mActivityScenario;

    @After
    public void tearDown() {
        if (mActivityScenario != null) {
            mActivityScenario.close();
        }
    }

    @Test
    public void onResume_mapsCard_isVisible() {
        mActivityScenario = ActivityScenario.launch(CarLauncher.class);
        mActivityScenario.moveToState(Lifecycle.State.RESUMED);

        onView(withId(R.id.maps_card)).check(matches(isDisplayed()));
    }

    @Test
    public void onResume_assistiveCard_isVisible() {
        mActivityScenario = ActivityScenario.launch(CarLauncher.class);
        mActivityScenario.moveToState(Lifecycle.State.RESUMED);

        onView(withId(R.id.top_card)).check(matches(isDisplayed()));
    }

    @Test
    public void onResume_audioCard_isVisible() {
        mActivityScenario = ActivityScenario.launch(CarLauncher.class);
        mActivityScenario.moveToState(Lifecycle.State.RESUMED);

        onView(withId(R.id.bottom_card)).check(matches(isDisplayed()));
    }
}
